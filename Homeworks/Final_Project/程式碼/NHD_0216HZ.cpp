#include "mbed.h"
#include <cstdarg>
#include "headers/NHD_0216HZ.h"
// #include <chrono>
// using namespace std::chrono_literals;

NHD_0216HZ::NHD_0216HZ(PinName SPI_CS, PinName SPI_MOSI, PinName SPI_SCLK)
    : _SPI_CS(SPI_CS), _SPI_MOSI(SPI_MOSI), _SPI_SCLK(SPI_SCLK) {
    _SPI_CS = 0;
}

void NHD_0216HZ::shift_out(int data) {
    _SPI_CS = 0;
    for (int i = 0; i < 8; i++) {
        _SPI_MOSI = (data & (0x80 >> i)) ? 1 : 0;
        _SPI_SCLK = 0;
        wait_us(1);
        _SPI_SCLK = 1;
    }
    _SPI_MOSI = 0;
    _SPI_CS = 1;
}

void NHD_0216HZ::write_4bit(int data, int mode) {
    shift_out((data & 0xF0) | ENABLE | mode);
    wait_us(1);
    shift_out((data & 0xF0) | mode);
    shift_out(((data << 4) & 0xF0) | ENABLE | mode);
    wait_us(1);
    shift_out(((data << 4) & 0xF0) | mode);
}

void NHD_0216HZ::write_cmd(int cmd) {
    write_4bit(cmd, COMMAND_MODE);
}

void NHD_0216HZ::write_data(char c) {
    write_4bit(c, DATA_MODE);
}

void NHD_0216HZ::init_lcd(void) {
    ThisThread::sleep_for(2000);

    shift_out(0x33);
    ThisThread::sleep_for(37);
    shift_out(0x32);
    ThisThread::sleep_for(37);
    write_cmd(0x28);
    ThisThread::sleep_for(37);
    write_cmd(0x0C);
    ThisThread::sleep_for(37);
    write_cmd(0x06);
    ThisThread::sleep_for(1000);
    write_cmd(0x01);
    ThisThread::sleep_for(37);
    set_cursor(0, 0);
}


void NHD_0216HZ::printf(const char *format, ...) {
    va_list v;
    char buffer[17];
    va_start(v, format);
    vsnprintf(buffer, sizeof(buffer), format, v);

    char *b = buffer;
    for (int i = 0; i < 16 && *b; i++) {
        write_data(*b++);
    }

    va_end(v);
}

void NHD_0216HZ::set_cursor(int column, int row) {
    int addr = column + (row ? 0x40 : 0x00);
    write_cmd(0x80 | addr);
}

void NHD_0216HZ::clr_lcd(void) {
    write_cmd(0x01); // clear display
    ThisThread::sleep_for(2); // 等待LCD清除螢幕
}
