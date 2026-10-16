#include "PlasmaHellVile.h"

VOID
WINAPI
sound1
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 44100, 44100, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 44100 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ((((t / 4) * (((t >> 12) ^ (t >> 12) - 2) % 11) | (t >> 13)) & 127) + ((t / 12) * ((0x98646363 >> ((t >> 11) & 28)) & 15) & 128));

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound2
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 8000 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) (t * ((t & 4096 ? t % 65536 < 59392 ? 7 : t & 7 : 16) ^ (1 & t >> 14)) >> (3 & t >> (t & 2048 ? 2 : 10 ) ) & 128 );

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound3
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 44100, 44100, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 44100 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ( ( t * ( t << 1 ^ ( t << 1 ) + ( t >> 7 ) & t >> 12 | t >> 4 - ( 1 ^ 7 & t >> 19 ) | t >> 7 ) ) );

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound4
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 44100, 44100, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 44100 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ( t * ( t >> ( t >> 13 & t ) ) );

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound5
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 48000, 48000, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 48000 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ((((t * (t & 16384 ? 7 : 5) * (3 - (3 & t >> 9) + (3 & t >> ((~t + 1) >> 20 & 1 ? 8 : 11))) >> (3 & (~t + 1) >> (t & ((~t + 1) & 57344 ? 4096 : 6144) ? 2 : 16)) | ((~t + 1) & 24576 ? (3 * t >> 5) % 192 : (t >> 4) % 192) | (t >> 20 & 1 ? t >> 4 : t >> (((~t + 1) >> 18 & 1) + 2))) & 255) >> 1) - (t >> 18 & 1 ? (((~t + 1) >> 1) * (t & 16384 ? 7 : 5) >> ((~t + 1) >> 10 & 3) & t >> 4 & 255) >> 1 : ((~t + 1) >> 2) * (t & 16384 ? 7 : 5) >> ((~t + 1) >> 10 & 3) & (t >> 4 & 255) >> 1) + (128 & (40000 / (1 + (t & ((~t + 1) & 28672 ? 4095 : 2047))))) + ((t >> 18 & 3) & ((~(t * (t ^ t % 9) & 255 & (~(t >> (t >> 11 & 31 ? ((~t + 1) & 14336 ? 5 : 4) - !((~t + 1) & 28672) - !((~t + 1) & 122880) : 6)) + 1) << 2 & 255) + 1) >> 2)) + 128);

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound6
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 44100, 44100, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 44100 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ( t & t >> 6 | t << 1 + t >> 5 | t << 3 | t >> 3 | t >> 2 | t << 1 );

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound7
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 16000, 16000, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 16000 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) (9 * t & t >> 4 | 5 * t & t >> 7 | 3 * t & t >> 10 | t * (t >> 8) & 64);

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound8
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 22050, 22050, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 22050 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ( ( t >> 8 | t << 2 ) + ( t >> 4 | t << 2 | t >> 3 ) | t >> 2 | t << 5 );

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound9
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 11025 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ( t >> 9 & 2 * t & 10 * t | t >> 5 & 6 * t );

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound10
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 44100, 44100, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 44100 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ( ( t & t >> 12 ) * ( t >> 4 | t >> 8 ) );

    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound11
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 48000, 48000, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 48000 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        unsigned x = (unsigned)(t * 8000ULL / 44100);
        buffer[t] = (BYTE) (9 * x & x >> 4 | 5 * x & x >> 7 | 3 * x & x >> 10);
    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound12
( )
{

    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 48000, 48000, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 48000 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        unsigned x = t / 6;
        buffer[t] = (BYTE) ( x * ( ( x & 4096 ? x % 65536 < 59392 ? 7 : x & 7 : 16 ) + ( 1 & x >> 14 ) ) >> ( 3 & 0-x >> ( x & 2048 ? 2 : 10 ) )| x >> (x & 16384 ? x & 4096 ? 10 : 3 : 2 ) );
    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );

}

VOID
WINAPI
sound13
( )
{
    HWAVEOUT hWaveOut = NULL;
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 48000, 48000, 1, 8, 0 };
    if (waveOutOpen ( &hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL ) != MMSYSERR_NOERROR) return;
    const DWORD bufferSize = 48000 * 30;
    char* buffer = (char*)HeapAlloc ( GetProcessHeap ( ), HEAP_ZERO_MEMORY, bufferSize );
    if (!buffer) { waveOutClose ( hWaveOut ); return; }
    for (DWORD t = 0; t < bufferSize; ++t) {
        buffer[t] = (BYTE) ( ( ( t >> 16 & 3 ) ? ( t * ( t >> 10 & ( ( t >> 16 ) + 1 ) ) ) : ( t * ( 42 & t >> 10 ) ) ) >> 1 + ( ( t >> 17 & 3 ) ? ( ( t & t >> 12 ) * ( t >> 4 | t >> 8 ) ) : ( t * 5 & t >> 7 | t * 3 & t >> 10 ) ) >> 2 | t >> (t >> 18 & 7 ) );
    }
    WAVEHDR header = { 0 };
    header.lpData = buffer;
    header.dwBufferLength = bufferSize;
    waveOutPrepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutWrite ( hWaveOut, &header, sizeof ( WAVEHDR ) );
    waveOutUnprepareHeader ( hWaveOut, &header, sizeof ( WAVEHDR ) ); Sleep ( 30000 );
    waveOutClose ( hWaveOut );
    HeapFree ( GetProcessHeap ( ), 0, buffer );
}
