
#include <stdlib.h>
#include <SDL.h>

int AUDIOIO_audioActive = 0;

void (*callback)(void *userdata, Uint8 *stream, int len);
short int (*AUDIOIO_produceSampleCallback)();

void AUDIOIO_callback(void *userdata, Uint8 *stream, int len) {
    int nSamples = len/4;
    short int *smpData = (short int *)stream;
    int i;

    for (i = 0; i < nSamples; i += 1) {
        short int x = AUDIOIO_produceSampleCallback();
        smpData[(i<<1) + 0] = x; // Left
        smpData[(i<<1) + 1] = x; // Right

    }
}

int AUDIOIO_init(int sampleRate, short int (*produceSampleCallback)()) {
    AUDIOIO_produceSampleCallback = produceSampleCallback;

    if ( SDL_Init(SDL_INIT_AUDIO) < 0 ) { //|SDL_INIT_VIDEO
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        return 0;
    }

    SDL_AudioSpec fmt;

    fmt.freq = sampleRate;  // Sample rate
    fmt.format = AUDIO_S16; // 16 bit singed
    fmt.channels = 2;       // Stereo
    fmt.samples = 512;      // Buffer size
    fmt.callback = AUDIOIO_callback;
    fmt.userdata = NULL;

    /* Open the audio device */
    if ( SDL_OpenAudio(&fmt, NULL) < 0 ) {
        fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void AUDIOIO_setAudioActive(int audioActive) {
    if (audioActive && !AUDIOIO_audioActive)
        SDL_PauseAudio(0);
    else if (!audioActive && AUDIOIO_audioActive)
        SDL_PauseAudio(1);
    AUDIOIO_audioActive = audioActive;
}

void AUDIOIO_exit() {
    SDL_CloseAudio();
    SDL_Quit();
}
