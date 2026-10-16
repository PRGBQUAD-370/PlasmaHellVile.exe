#include "PlasmaHellVile.h"

DWORD
WINAPI
shader1 ( LPVOID lpParam )
{

    HDC hdcScreen = GetDC ( NULL );
    if (!hdcScreen) return 1;
    int width = GetSystemMetrics ( SM_CXSCREEN );
    int height = GetSystemMetrics ( SM_CYSCREEN );
    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFOHEADER );
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    RGBQUAD* pPixels = nullptr;
    HBITMAP hBitmap = CreateDIBSection ( hdcScreen, &bmi, DIB_RGB_COLORS,
        (void**)&pPixels, nullptr, 0 );
    if (!hBitmap || !pPixels) {
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HDC hdcMem = CreateCompatibleDC ( hdcScreen );
    if (!hdcMem) {
        DeleteObject ( hBitmap );
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HGDIOBJ oldBmp = SelectObject ( hdcMem, hBitmap );
    const DWORD startTime = GetTickCount ( );
    while (TRUE) {
        float time = (GetTickCount ( ) - startTime) * 0.001f;
        for (int y = 0; y < height; ++y) {
            float fy = y * 0.015f;
            for (int x = 0; x < width; ++x) {
                float fx = x * 0.015f;

                float v = sinf ( fx + time );
                v += sinf ( fy + time * 1.3f );
                v += sinf ( (fx + fy) * 0.5f + time * 0.7f );
                v += sinf ( sqrtf ( fx * fx + fy * fy ) + time * 0.5f );

                v = (v + 4.0f) * 0.125f;
                float hue = v * 6.28318f + time * 1.5f;

                RGBQUAD& p = pPixels[y * width + x];
                p.rgbRed = (BYTE)(sinf ( hue ) * 127.0f + 128.0f);
                p.rgbGreen = (BYTE)(sinf ( hue + 2.094f ) * 127.0f + 128.0f);
                p.rgbBlue = (BYTE)(sinf ( hue + 4.189f ) * 127.0f + 128.0f);
                p.rgbReserved = 255;
            }
        }
        BitBlt ( hdcScreen, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY );
    }

    SelectObject ( hdcMem, oldBmp );
    DeleteDC ( hdcMem );
    DeleteObject ( hBitmap );
    ReleaseDC ( NULL, hdcScreen );
    return 0x00;

}

DWORD
WINAPI
SlowRGBShader
( LPVOID lpParam )
{

    HDC hdc = GetDC ( NULL );
    RECT rect;
    GetClientRect ( GetDesktopWindow ( ), &rect );
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            COLORREF color = RGB ( x % 256, y % 256, (x + y) % 256 );
            SetPixel ( hdc, x, y, color );
        }
    }

    ReleaseDC ( NULL, hdc );
    return 0x00;

}

DWORD
WINAPI
UpwardTrain
( LPVOID lpParam )
{

    int w = GetSystemMetrics ( 0 );
    int h = GetSystemMetrics ( 1 );
    while (1) {
        HDC hdc = GetDC ( 0 );
        BitBlt ( hdc, -30, 0, w, h, hdc, -30, 0, SRCCOPY );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, -30, SRCERASE );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, h - 30, SRCERASE );
        ReleaseDC ( 0, hdc );

    }

    return 0x00;

}

DWORD 
WINAPI 
shader2 
( LPVOID lpParam ) 
{

    HDC hdcScreen = GetDC ( 0 ), hdcMem = CreateCompatibleDC ( hdcScreen );
    INT w = GetSystemMetrics ( 0 ), h = GetSystemMetrics ( 1 );
    BITMAPINFO bmi = { 0 };
    PRGBQUAD rgbScreen = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFO );
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;
    HBITMAP hbmTemp = CreateDIBSection ( hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL );
    SelectObject ( hdcMem, hbmTemp );
    for (;;) {
        hdcScreen = GetDC ( 0 );
        BitBlt ( hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCERASE );
        for (INT i = 0; i < w * h; i++) {
            INT x = i % w, y = i / w;
            rgbScreen[i].r = 0;
            rgbScreen[i].g = 0;
            rgbScreen[i].b = (BYTE)(x ^ y);
            rgbScreen[i].Reserved = 0;
        }

        BitBlt ( hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCERASE );
        ReleaseDC ( NULL, hdcScreen ); DeleteDC ( hdcScreen );
    }
    return 0x00;
}

DWORD
WINAPI
shader3
( LPVOID lpParam )
{

    HDC hdcScreen = GetDC ( NULL );
    if (!hdcScreen) return 1;
    int w = GetSystemMetrics ( SM_CXSCREEN );
    int h = GetSystemMetrics ( SM_CYSCREEN );
    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFOHEADER );
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = -h;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    PRGBQUAD pPixels = nullptr;
    HBITMAP hBitmap = CreateDIBSection ( hdcScreen, &bmi, DIB_RGB_COLORS,
        (void**)&pPixels, nullptr, 0 );
    if (!hBitmap || !pPixels) {
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HDC hdcMem = CreateCompatibleDC ( hdcScreen );
    if (!hdcMem) {
        DeleteObject ( hBitmap );
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HGDIOBJ oldBmp = SelectObject ( hdcMem, hBitmap );
    for (;;) {
        BitBlt ( hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY );
        for (int y = 0; y < h; y += 2) {
            int shift = (rand ( ) % 80) - 40;
            if (shift == 0) continue;

            for (int x = 0; x < w; ++x) {
                int srcX = x - shift;
                if (srcX < 0) srcX = 0;
                if (srcX >= w) srcX = w - 1;
                pPixels[y * w + x] = pPixels[y * w + srcX];
            }
        }
        for (int i = 0; i < (w * h) / 40; ++i) {
            int idx = rand ( ) % (w * h);
            pPixels[idx].r = (BYTE)(rand ( ) % 256);
            pPixels[idx].g = (BYTE)(rand ( ) % 256);
            pPixels[idx].b = (BYTE)(rand ( ) % 256);
        }
        BitBlt ( hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCINVERT );
    }

    SelectObject ( hdcMem, oldBmp );
    DeleteDC ( hdcMem );
    DeleteObject ( hBitmap );
    ReleaseDC ( NULL, hdcScreen );
    return 0x00;

}

DWORD
WINAPI
shader4
( LPVOID lpParam )
{

    HDC hdcScreen = GetDC ( NULL );
    if (!hdcScreen) return 1;
    int w = GetSystemMetrics ( SM_CXSCREEN );
    int h = GetSystemMetrics ( SM_CYSCREEN );
    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFOHEADER );
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = -h;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    PRGBQUAD pPixels = nullptr;
    HBITMAP hBitmap = CreateDIBSection ( hdcScreen, &bmi, DIB_RGB_COLORS, (void**)&pPixels, nullptr, 0 );
    if (!hBitmap || !pPixels) {
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HDC hdcMem = CreateCompatibleDC ( hdcScreen );
    if (!hdcMem) {
        DeleteObject ( hBitmap );
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HGDIOBJ oldBmp = SelectObject ( hdcMem, hBitmap );
    int offset = 0;
    const int bandHeight = 28;
    for (;;) {
        for (int y = 0; y < h; ++y) {
            int band = ((y + offset) / bandHeight) % 10;

            BYTE r = 0, g = 0, b = 0;
            switch (band) {
            case 0: r = 255; g = 0;   b = 0;   break;
            case 1: r = 255; g = 128; b = 0;   break;
            case 2: r = 255; g = 255; b = 0;   break;
            case 3: r = 0;   g = 255; b = 0;   break;
            case 4: r = 0;   g = 255; b = 128; break;
            case 5: r = 0;   g = 255; b = 255; break;
            case 6: r = 0;   g = 128; b = 255; break;
            case 7: r = 0;   g = 0;   b = 255; break;
            case 8: r = 128; g = 0;   b = 255; break;
            default:r = 255; g = 0;   b = 255; break;
            }
            for (int x = 0; x < w; ++x) {
                PRGBQUAD p = &pPixels[y * w + x];
                p->b = r;
                p->g = g;
                p->r = b;
                p->Reserved = 255;
            }
        }
        BitBlt ( hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCCOPY );

        offset += 8;
        if (offset > 1000000) offset = 0;

    }

    SelectObject ( hdcMem, oldBmp );
    DeleteDC ( hdcMem );
    DeleteObject ( hBitmap );
    ReleaseDC ( NULL, hdcScreen );
    return 0x00;

}

DWORD
WINAPI
shader5
( LPVOID lpParam )
{

    HDC hdcScreen = GetDC ( NULL );
    if (!hdcScreen) return 1;
    int width = GetSystemMetrics ( SM_CXSCREEN );
    int height = GetSystemMetrics ( SM_CYSCREEN );
    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFOHEADER );
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    PRGBQUAD pPixels = nullptr;
    HBITMAP hBitmap = CreateDIBSection ( hdcScreen, &bmi, DIB_RGB_COLORS,
        (void**)&pPixels, nullptr, 0 );
    if (!hBitmap || !pPixels) {
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HDC hdcMem = CreateCompatibleDC ( hdcScreen );
    if (!hdcMem) {
        DeleteObject ( hBitmap );
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    HGDIOBJ oldBmp = SelectObject ( hdcMem, hBitmap );
    while (TRUE) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                PRGBQUAD p = &pPixels[y * width + x];
                p->b = (BYTE)(x % 256);
                p->g = (BYTE)(y % 256);
                p->r = (BYTE)((x + y) % 256);
                p->Reserved = 255;
            }
        }
        BitBlt ( hdcScreen, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY );
    }

    SelectObject ( hdcMem, oldBmp );
    DeleteDC ( hdcMem );
    DeleteObject ( hBitmap );
    ReleaseDC ( NULL, hdcScreen );
    return 0x00;

}

DWORD
WINAPI
shader6
( LPVOID lpParam )
{

    HDC hdcScreen = GetDC ( NULL );
    if (!hdcScreen) return 1;
    HDC hdcMem = CreateCompatibleDC ( hdcScreen );
    if (!hdcMem) {
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }
    const INT w = GetSystemMetrics ( SM_CXSCREEN );
    const INT h = GetSystemMetrics ( SM_CYSCREEN );
    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFOHEADER );
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    PRGBQUAD rgbScreen = NULL;
    HBITMAP hbm = CreateDIBSection ( hdcScreen, &bmi, DIB_RGB_COLORS,
        (void**)&rgbScreen, NULL, 0 );
    ReleaseDC ( NULL, hdcScreen );
    if (!hbm || !rgbScreen) {
        DeleteDC ( hdcMem );
        return 1;
    }
    SelectObject ( hdcMem, hbm );
    for (;;) {
        hdcScreen = GetDC ( NULL );
        if (!hdcScreen) continue;
        for (INT i = 0; i < w * h; ++i) {
            const INT x = i % w;
            const INT y = i / w;
            rgbScreen[i].rgb = (x ^ y);
        }
        BitBlt ( hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCERASE );
        ReleaseDC ( NULL, hdcScreen );
    }

    DeleteObject ( hbm );
    DeleteDC ( hdcMem );
    return 0x00;

}

DWORD
WINAPI
shader7
( LPVOID lpParam )
{

    HDC hdcScreen = GetDC ( NULL );
    if (!hdcScreen) return 1;

    int width = GetSystemMetrics ( SM_CXSCREEN );
    int height = GetSystemMetrics ( SM_CYSCREEN );

    BITMAPINFO bmi = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFOHEADER );
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    RGBQUAD* pPixels = nullptr;
    HBITMAP hBitmap = CreateDIBSection ( hdcScreen, &bmi, DIB_RGB_COLORS,
        (void**)&pPixels, nullptr, 0 );
    if (!hBitmap || !pPixels) {
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }

    HDC hdcMem = CreateCompatibleDC ( hdcScreen );
    if (!hdcMem) {
        DeleteObject ( hBitmap );
        ReleaseDC ( NULL, hdcScreen );
        return 1;
    }

    HGDIOBJ oldBmp = SelectObject ( hdcMem, hBitmap );

    const DWORD startTime = GetTickCount ( );
    const int size = 48;

    while (TRUE) {

        float time = (GetTickCount ( ) - startTime) * 0.001f;
        int offsetX = (int)(time * 60.0f);
        int offsetY = (int)(time * 40.0f);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int cx = (x + offsetX) / size;
                int cy = (y + offsetY) / size;
                bool checker = ((cx + cy) & 1) == 0;

                float hue = time * 0.8f + (checker ? 0.0f : 3.14f);
                BYTE r = (BYTE)(sinf ( hue ) * 127.0f + 128.0f);
                BYTE g = (BYTE)(sinf ( hue + 2.094f ) * 127.0f + 128.0f);
                BYTE b = (BYTE)(sinf ( hue + 4.189f ) * 127.0f + 128.0f);

                RGBQUAD& p = pPixels[y * width + x];
                p.rgbRed = r;
                p.rgbGreen = g;
                p.rgbBlue = b;
                p.rgbReserved = 255;
            }
        }

        BitBlt ( hdcScreen, 0, 0, width, height, hdcMem, 0, 0, SRCCOPY );
    }

    SelectObject ( hdcMem, oldBmp );
    DeleteDC ( hdcMem );
    DeleteObject ( hBitmap );
    ReleaseDC ( NULL, hdcScreen );
    return 0x00;

}

DWORD WINAPI shader8 ( LPVOID lpParam ) {
    const INT w = GetSystemMetrics ( SM_CXSCREEN );
    const INT h = GetSystemMetrics ( SM_CYSCREEN );
    _RGBQUAD* data = (_RGBQUAD*)VirtualAlloc ( NULL, (w * h + w) * sizeof ( _RGBQUAD ),
        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );
    if (!data) return 1;
    for (;;) {
        HDC desk = GetDC ( NULL );
        if (!desk) continue;

        HDC hdcdc = CreateCompatibleDC ( desk );
        if (!hdcdc) {
            ReleaseDC ( NULL, desk );
            continue;
        }
        HBITMAP hbm = CreateBitmap ( w, h, 1, 32, data );
        if (!hbm) {
            DeleteDC ( hdcdc );
            ReleaseDC ( NULL, desk );
            continue;
        }
        SelectObject ( hdcdc, hbm );
        BitBlt ( hdcdc, 0, 0, w, h, desk, 0, 0, SRCERASE );
        GetBitmapBits ( hbm, w * h * 4, data );
        for (INT i = 0; i < w * h; i++) {
            const INT x = i % w;
            const INT y = i / h;
            const INT t = y ^ y | x;
            data[i].rgb = ((x & y & t) & 0xFF) << 16;
        }
        SetBitmapBits ( hbm, w * h * 4, data );
        BitBlt ( desk, 0, 0, w, h, hdcdc, 0, 0, SRCERASE );
        DeleteObject ( hbm );
        DeleteDC ( hdcdc );
        ReleaseDC ( NULL, desk );
    }
    VirtualFree ( data, 0, MEM_RELEASE );
    return 0x00;
}

DWORD WINAPI shader9 ( LPVOID lpParam ) {
    HDC hdcScreen = GetDC ( 0 ), hdcMem = CreateCompatibleDC ( hdcScreen );
    INT w = GetSystemMetrics ( 0 ), h = GetSystemMetrics ( 1 );
    BITMAPINFO bmi = { 0 };
    PRGBQUAD rgbScreen = { 0 };
    bmi.bmiHeader.biSize = sizeof ( BITMAPINFO );
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;
    HBITMAP hbmTemp = CreateDIBSection ( hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL );
    SelectObject ( hdcMem, hbmTemp );
    for (;;) {
        hdcScreen = GetDC ( 0 );
        BitBlt ( hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCERASE );
        for (INT i = 0; i < w * h; i++) {
            INT x = i % w, y = i / w;
            rgbScreen[i].rgb = (x ^ y);
        }
        BitBlt ( hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCERASE );
        ReleaseDC ( NULL, hdcScreen ); DeleteDC ( hdcScreen );
    }
    return 0x00;
}

DWORD WINAPI shader10 ( LPVOID lpParam ) {
    int time = GetTickCount ( );
    int w = GetSystemMetrics ( 0 ), h = GetSystemMetrics ( 1 );
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc ( 0, (w * h + w) * sizeof ( RGBQUAD ), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC ( NULL );
        HDC hdcdc = CreateCompatibleDC ( desk );
        HBITMAP hbm = CreateBitmap ( w, h, 1, 32, data );
        SelectObject ( hdcdc, hbm );
        BitBlt ( hdcdc, 0, 0, w, h, desk, 0, 0, SRCERASE );
        GetBitmapBits ( hbm, 4 * h * w, data );
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount ( ) - time) > 10)
            byte = rand ( ) % 0xff;
        for (int i = 0; w * h > i; ++i) {
            if (!(i % h) && !(rand ( ) % 110))
                v = rand ( ) % 24;
            *((BYTE*)data + 4 * i + v) -= 5;
        }
        SetBitmapBits ( hbm, w * h * 4, data );
        BitBlt ( desk, 0, 0, w, h, hdcdc, 0, 0, SRCERASE );
        DeleteObject ( hbm );
        DeleteObject ( hdcdc );
        DeleteObject ( desk );
    }
    return 0x00;
}

DWORD 
WINAPI 
profect 
( LPVOID lpParam ) 
{

    int w = GetSystemMetrics ( 0 );
    int h = GetSystemMetrics ( 1 );
    while (1) {
        HDC hdc = GetDC ( 0 );
        BitBlt ( hdc, 0, 0, w, h, hdc, -30, 0, SRCERASE );
        BitBlt ( hdc, 0, 0, w, h, hdc, w - 30, 0, SRCERASE );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, -30, SRCERASE );
        BitBlt ( hdc, 0, 0, w, h, hdc, 0, h - 30, SRCERASE );
        ReleaseDC ( 0, hdc );
    }
    return 0x00;
}