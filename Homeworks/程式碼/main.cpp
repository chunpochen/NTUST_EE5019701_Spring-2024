#include "mbed.h"
#include "headers/song_def.h"
#include "headers/song.h"
#include "headers/NHD_0216HZ.h"
#include <string>
using namespace std;

#define BUTTON_1 D2 // 切歌
#define BUTTON_2 D3 // 撥放 & 暫停

#define RED_LED D6
#define GREEN_LED D7
#define SPEAKER D9
#define SPI_CS D10
#define SPI_MOSI D11
#define SPI_SCLK D13
#define UART_TX D1
#define UART_RX D0

Song allsongs[] = {
    SYMPHONY_NO40,
    WALTZ_NO2,
    NOCTRUNE_IN_E_FLAT
};

volatile int song_index = 0;
volatile bool playing = false;
volatile bool wait_for_new_song = false;
string lcd_text[2];
volatile int k = 0; 
volatile float Volume = 0.0f;

// Define the mutex
Mutex lcd_mutex;

// Define the threads
Thread t1;
Thread t2;
Thread t3;

// Define ticker
Ticker timer;

// Define the LCD display and the Serial
NHD_0216HZ lcd(SPI_CS, SPI_MOSI, SPI_SCLK);
Serial pc(UART_TX, UART_RX);

// Define other inputs and outputs
AnalogIn volume(A0);
DigitalIn switch_song(BUTTON_1);
DigitalIn control_playback(BUTTON_2);
DigitalOut red(RED_LED);
DigitalOut green(GREEN_LED);
PwmOut speaker(SPEAKER);
 
// Display the song name on the LCD and the RGB LEDs
void update_lcd_leds_thread() {
    while (1) {
        lcd_mutex.lock();
        lcd.clr_lcd();
        lcd.set_cursor(0, 0);
        lcd.printf(lcd_text[0].c_str());
        // ThisThread::sleep_for(500);
        lcd.set_cursor(0, 1);
        lcd.printf(lcd_text[1].c_str());
        lcd_mutex.unlock();

        red = playing;
        green = !playing;

        ThisThread::sleep_for(500);
    }
}

// Adjust the volume of the speaker 
void adjust_volume() {
    while (1) {
        if (!playing) { 
            Volume = 0.1f * volume.read();
        }
        else {
            speaker = 0;
        }
        ThisThread::sleep_for(500);
    }
}

// Define the ticker ISR
void timer_ISR() {
    if (!playing) {
        if (k < allsongs[song_index].length) {
            // Set the PWM duty cycle to zero if there is a sound pause
            if (*(allsongs[song_index].note + k) == No) speaker = 0;
            // Set the PWM period, which determines the note of the sound
            else {
                speaker.period(0.001f * (*(allsongs[song_index].note + k)));
                speaker = Volume;
            }

            k++;

            // Set the time for the next ticker interrupt
            timer.attach(&timer_ISR, ((*(allsongs[song_index].beat + k) / 3.0f) + (allsongs[song_index].tempo / 2.0f)));
        } else {
            // If the musical piece is finished, stop playing
            playing = false;
            k = 0;
            speaker = 0;
        }
    }
}

// Define switch song handler
void switch_song_handler() {
    song_index = (song_index + 1) % 3;
    lcd_mutex.lock();
    lcd_text[0] = allsongs[song_index].name1;
    lcd_text[1] = allsongs[song_index].name2;
    lcd_mutex.unlock();
    wait_for_new_song = true;
}

// Define control playback handler
void control_playback_handler() {
    if (wait_for_new_song) {
        k = 0;
        playing = true;
        wait_for_new_song = false;
        timer.attach(&timer_ISR, 0.1f);  // Initialize the time ticker
    } else {
        if(playing) {
            playing = false;
            speaker = 0; 
        }
        else {
            playing = true;
            timer.attach(&timer_ISR, 0.1f);
        }
    }
}

void polling_loop() {
    bool pressed_switch_song = false;
    bool pressed_control_playback = false;
    while (1) {
        if (switch_song && !pressed_switch_song) {
            switch_song_handler();
            pressed_switch_song = true;
        }
        if (!switch_song) {
            pressed_switch_song = false;
        }
        if (control_playback && !pressed_control_playback) {
            control_playback_handler();
            pressed_control_playback = true;
        }
        if (!control_playback) {
            pressed_control_playback = false;
        }
        ThisThread::sleep_for(500);
    }
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main() {
    // Initialize and clear the LCD display
    lcd.init_lcd();
    lcd.clr_lcd();

    // Initialize pc 9600 bd
    pc.baud(9600);

    // // Set initial LCD text to the first song
    // lcd_text[0] = allsongs[0].name1;
    // lcd_text[1] = allsongs[0].name2;


    // red = 1;
    // green = 0;

    // Start all threads
    t1.start(update_lcd_leds_thread);
    t2.start(adjust_volume);
    t3.start(polling_loop);

    // Initialize the interrupt handler 
    pc.printf("Choose a song:\r\n");
    for (int i = 0; i < 3; i++) {
        pc.printf("     %d  -  %s %s\r\n", i, allsongs[i].name1.c_str(), allsongs[i].name2.c_str());
    }
    pc.printf("Press Button 1 to switch songs.\r\n");
    pc.printf("Press Button 2 to confirm and play/pause the song.\r\n");

    // Wait for timer interrupt
    while (1) {
        __WFI();
    }
}
