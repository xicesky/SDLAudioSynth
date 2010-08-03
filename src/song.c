
#define SAMPLE_RATE 44100

// Beats per minute
#define TEMPO           (160 * 4)
#define VOICES          4

// VTables: Beat (for shuffling)
int vtbtbl[4] = { -400, -200, 200, 400 };
VTable vt_beat = {
    4,
    vtbtbl,
};

Instrument instr[VOICES] = {
    // Attack, Decay, Signal, Volume, ModSingal, ModFreq, ModAmount
    { 410, 17640, SIGNAL_SAW, 256, SIGNAL_SIN, 10240, 128 },//    { 410, 8820, SIGNAL_SAW, 256 },
    { 410, 22000, SIGNAL_RECT, 320, SIGNAL_ZERO, 1024, 1024 },
    { 41, 2210, SIGNAL_NOISE, 512, SIGNAL_ZERO, 0, 0 },
    { 410, 600, SIGNAL_RECT, 1024, SIGNAL_ZERO, 0, 0 }
};
Voice voice[VOICES];

#define PATTERN_LEN 16
#define NPATTERNS 10

int pattern[NPATTERNS][PATTERN_LEN] = {
{ // A moll arp. [0]
      0,   3,   7,  12,
      3,   7,  12,  15,
      7,  12,  15,  19,
     12,  15,  19,  24,
},
{ // C dur arp. [1]
      3,   7,  10,  15,
      7,  10,  15,  19,
     10,  15,  19,  22,
     15,  19,  22,  27
},
{ // A moll bass [2]
    -12, -99, -99, -99,
    -12, -99, -24, -99,
    -12, -99, -99, -99,
    -12, -99, -24, -99,
},
{ // C dur bass [3]
     -9, -99, -99, -99,
     -9, -99, -21, -99,
     -9, -99, -99, -99,
     -9, -99, -21, -99
},
{ // Really cheap snare [4]
    -99, -99,   0, -99,
    -99, -99,   0, -99,
    -99, -99,   0, -99,
    -99, -99,   0, -99,
},
{ // Really cheap b.d. [5]
    -24, -99, -99, -99,
    -24, -99, -99, -99,
    -24, -99, -99, -99,
    -24, -99, -99, -99,
},
{ // F dur arp. [6] c -7
     -4,   0,   3,   8,
      0,   3,   8,  12,
      3,   8,  12,  15,
      8,  12,  15,  20
},
{ // G dur arp. [7] f +2
     -2,   2,   5,  10,
      2,   5,  10,  14,
      5,  10,  14,  17,
     10,  14,  17,  22
},
{ // Unused pattern [8]
    -99, -99, -99, -99,
    -99, -99, -99, -99,
    -99, -99, -99, -99,
    -99, -99, -99, -99,
},
{ // Unused pattern [9]
    -99, -99, -99, -99,
    -99, -99, -99, -99,
    -99, -99, -99, -99,
    -99, -99, -99, -99,
},
};

#define SONG_LEN 8
int song[SONG_LEN][VOICES] = {
    { 0, 2, 4, 5 },
    { 1, 3, 4, 5 },
    { 0, 2, 4, 5 },
    { 1, 3, 4, 5 },
    { 0, 2, 4, 5 },
    { 1, 3, 4, 5 },
    { 6, 2, 4, 5 },
    { 7, 3, 4, 5 },
};
