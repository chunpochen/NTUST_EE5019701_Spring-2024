#ifndef SONG_DEF
#define SONG_DEF

#include "song.h"
#include <string>
using namespace std;

// Define the frequency of basic music notes
#define So__1      5.102
#define Si__1      4.059

#define Do         3.822
#define DoD        3.608
#define Re         3.405
#define ReD        3.214
#define Mi         3.033
#define Fa         2.863
#define FaD        2.702
#define So         2.551
#define SoD        2.407
#define La         2.272
#define LaD        2.145
#define Si         2.024

#define Do_2       1.911
#define DoD_2      1.803
#define Re_2       1.702
#define ReD_2      1.607
#define Mi_2       1.516
#define Fa_2       1.431
#define FaD_2      1.351
#define So_2       1.275
#define SoD_2      1.204
#define La_2       1.136
#define LaD_2      1.073
#define Si_2       1.012

#define Do_3       0.955
#define DoD_3      0.901
#define Re_3       0.853
#define No         0

// Define the beat length (e.g. whole note, half note)
#define b0     1
#define b1     0.5
#define b2     0.25
#define b3     0.125
#define b4     0.075

// Define the musical piece

// Symphony No. 40 - Mozart 
float Symphony_No40_note[] = {ReD_2, No, Re_2, No, Re_2, No, ReD_2, No, Re_2, No, Re_2, No, ReD_2, No, Re_2, No, Re_2, No, LaD_2, No, No, LaD_2, No, La_2, No, So_2, No, So_2, No, Fa_2, No, ReD_2, No, ReD_2, No, Re_2, No, Do_2, No, Do_2, No, No, Re_2, No, Do_2, No, Do_2, No, Re_2, No, Do_2, No, Do_2, No, Re_2, No, Do_2, No, Do_2, No, La_2, No, No, La_2, No, So_2, No, FaD_2, No, FaD_2, No, ReD_2, No, Re_2, No, Re_2, No, Do_2, No, LaD, No, LaD, No, No, LaD_2, No, La_2, No, La_2, No, Do_3, No, FaD_2, No, La_2, No, So_2, No, Re_2, No, No, LaD_2, No, La_2, No, La_2, No, Do_3, No, FaD_2, No, La_2, No, So_2, No, LaD_2, No, La_2, No, So_2, Fa_2, No, ReD_2, No, No, FaD_2, No, So_2, No, La_2, No, LaD_2, No, Do_3, No, LaD_2, No, La_2, No, So_2, No, FaD_2, No, No, DoD_3, No, Re_3, No, No, DoD_3, No, Re_3, No, No, DoD_3, No, Re_3, No, DoD_3, No, Re_3, No, DoD_3, No, Re_3, Re_3, No, No};
float Symphony_No40_beat[] = {b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b1, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b1, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b1, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b1, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b1, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b1, b3, b3, b3, b3, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, b2, b3, b3, b3, b3, b1, b2, b2, b2, b2, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b2, b2, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b2, b2, b3, b3, b3, b3, b1, b1};
float Symphony_No40_tempo = 0.1;

// Waltz No. 2 - Shostakovich
float Waltz_No2_note [] = {So,So,So, ReD,ReD,Re, Do,Do,Do, No,Do,Re, ReD,Do,ReD, So,So,SoD, So,So,So, Fa,Fa,Fa, No,Fa,Fa,Fa, Re,Re,Do, Si__1,Si__1,Si__1, Si__1,So__1,Si__1, Re,Si__1,Re, Fa,So,SoD, FaD,FaD,FaD, So,So,So, ReD_2,ReD_2,ReD_2, Re_2,Re_2,Do_2, LaD,LaD,SoD, Fa,Fa,Fa, Re_2,Re_2,Re_2, Do_2,Do_2,LaD, No,LaD,LaD,LaD, So,So,So, No,ReD,No,Fa,No, So,No,So,No,Fa,No,So,No,SoD,No, Fa,No,Fa,No,ReD,No,Fa,No,So,No, ReD,No,No,So,No, No,Do_2,No,Re_2,No, ReD_2,No,ReD_2,No,Re_2,No,ReD_2,No,Fa_2,No, Re_2,No,Re_2,No,Do_2,No,Re_2,No,ReD_2,No, Do_2,Do_2,Do_2, No,No,No};
float Waltz_No2_beat [] = {b1,b1,b1, b1,b1,b1,   b1,b1,b1, b1,b1,b1, b1,b1,b1,   b1,b1,b1,  b1,b1,b1, b1,b1,b1, b4,b1,b1,b1, b1,b1,b1, b1,b1,b1,          b1,b1,b1,          b1,b1,b1,    b1,b1,b1,  b1,b1,b1,    b1,b1,b1, b1,b1,b1,          b1,b1,b1,       b1,b1,b1,    b1,b1,b1, b1,b1,b1,       b1,b1,b1,      b4,b1,b1,b1,    b1,b1,b1, b1,b2,b2,b2,b2,  b2,b3,b3,b3,b3,b3,b3,b3,b3,b3,  b2,b2,b3,b3,b3,b3,b3,b3,b3,b3,  b2,b2,b1,b2,b2,  b1,b2,b2,b2,b2,     b2,b2,b3,b3,b3,b3,b3,b3,b3,b3,              b2,b2,b3,b3,b3,b3,b3,b3,b3,b3,            b1,b1,b1,    b1,b1,b1};
float Waltz_No2_tempo = 0.1;

// Nocturne in E flat - Chopin
float Nocturne_in_E_flat_note [] = {LaD, So_2,So_2,So_2, So_2,Fa_2,So_2, Fa_2,Fa_2,Fa_2, ReD_2,ReD_2,LaD, So_2,So_2,Do_2, Do_3,Do_3,So_2, LaD_2,LaD_2,LaD_2, SoD_2,SoD_2,So_2, Fa_2,Fa_2,Fa_2, So_2,So_2,Re_2, ReD_2,ReD_2,ReD_2, Do_2,Do_2,Do_2, LaD,Re_3,Do_3, LaD_2,SoD_2,So_2,SoD_2,Do_2,Re_2, ReD_2,ReD_2,ReD_2, No,No,LaD, So_2,So_2,So_2, Fa_2,So_2,Fa_2,Mi_2,Fa_2,So_2, Fa_2,ReD_2,ReD_2, ReD_2,Fa_2,ReD_2,Re_2,ReD_2,Fa_2, So_2,Si,Do_2,DoD_2,Do_2,Fa_2, Mi_2,SoD_2,So_2,DoD_3,Do_3,So_2, LaD_2,LaD_2,LaD_2 ,SoD_2,SoD_2,So_2, Fa_2,Fa_2,Mi_2,Fa_2, So_2,So_2,Re_2, ReD_2,ReD_2,ReD_2, Do_2,Do_2,Do_2, LaD,Re_3,Do_3,LaD_2,SoD_2,So_2,SoD_2,Do_2,Re_2, ReD_2,ReD_2,ReD_2, No,No,No};
float Nocturne_in_E_flat_beat [] = {b0,  b0,b0,b0,          b0,b0,b0,      b0,b0,b0,      b0,b0,b0,       b0,b0,b0,       b0,b0,b0,        b0,b0,b0,           b0,b0,b0,       b0,b0,b0,       b0,b0,b0,       b0,b0,b0,          b0,b0,b0,       b0,b0,b0,       b1,b1,b1,b1,b1,b1,b1,b1,b1,      b0,b0,b0,          b0,b0,b0,  b0,b0,b0,       b1,b1,b1,b1,b1,b1,              b0,b0,b0,         b1,b1,b1,b1,b1,b1,                   b1,b1,b1,b1,b1,b1,            b1,b1,b1,b1,b1,b1,             b0,b0,b0,         b0,b0,b0,        b0,b0,b1,b1,          b0,b0,b0,       b0,b0,b0,           b0,b0,b0,      b1,b1,b1,b1,b1,b1,                              b0,b0,b0,           b0,b0,b0};
float Nocturne_in_E_flat_tempo = 0.31;

// Creating the musical piece
Song SYMPHONY_NO40 = Song(string("Symphony No. 40 "), string("- Mozart"), &Symphony_No40_note[0], &Symphony_No40_beat[0], Symphony_No40_tempo, 168);
Song WALTZ_NO2 = Song(string("Waltz No. 2 "), string("- Shostakovich"), &Waltz_No2_note [0], &Waltz_No2_beat [0], Waltz_No2_tempo, 135);
Song NOCTRUNE_IN_E_FLAT = Song(string("Nocturne in E "), string("- Chopin"), &Nocturne_in_E_flat_note [0], &Nocturne_in_E_flat_beat [0], Nocturne_in_E_flat_tempo, 116);


#endif
