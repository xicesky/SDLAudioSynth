
#ifndef AUDIOIO_H
#define AUDIOIO_H

int AUDIOIO_init(int sampleRate, short int (*produceSampleCallback)());
void AUDIOIO_setAudioActive(int audioActive);
void AUDIOIO_exit();

#endif
