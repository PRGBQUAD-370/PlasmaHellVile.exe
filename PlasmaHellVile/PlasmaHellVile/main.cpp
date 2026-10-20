#include "PlasmaHellVile.h"

VOID 
WINAPI 
Initialize 
( VOID ) 
{

    HMODULE hModUser32 = LoadLibraryW ( L"user32.dll" );
    BOOL ( WINAPI * SetProcessDPIAware )(VOID) = (BOOL ( WINAPI* )(VOID))GetProcAddress ( hModUser32, "SetProcessDPIAware" );
    if ( SetProcessDPIAware ) SetProcessDPIAware ( );
    FreeLibrary ( hModUser32 );

}

INT
WINAPI
wWinMain (
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pszCmdLine,
    _In_ INT nShowCmd
)
{
    UNREFERENCED_PARAMETER ( hInstance );
    UNREFERENCED_PARAMETER ( hPrevInstance );
    UNREFERENCED_PARAMETER ( pszCmdLine );
    UNREFERENCED_PARAMETER ( nShowCmd );

    Initialize ( );

    if (MessageBoxW ( NULL, L"This is a PlasmaHellVile.exe,\r\nRun?", L"PlasmaHellVile.exe by PRGBQUAD-370", MB_YESNO | MB_ICONWARNING ) != IDYES) {
        ExitProcess ( 0 );
    }
    else {

        if (MessageBoxW ( NULL, L"Are you sure?", L"PlasmaHellVile.exe -Final Warning", MB_YESNO | MB_ICONWARNING ) != IDYES) {
            ExitProcess ( 0 );
        }
        else

            Sleep ( 1000 );

        HANDLE hThread1 = CreateThread ( NULL, NULL, shader1, NULL, NULL, NULL );
        sound1 ( );
        TerminateThread ( hThread1, NULL );
        CloseHandle ( hThread1 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread2 = CreateThread ( NULL, NULL, SlowRGBShader, NULL, NULL, NULL );
        sound2 ( );
        TerminateThread ( hThread2, NULL );
        CloseHandle ( hThread2 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread3 = CreateThread ( NULL, NULL, UpwardTrain, NULL, NULL, NULL );
        sound3 ( );
        TerminateThread ( hThread3, NULL );
        CloseHandle ( hThread3 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread4 = CreateThread ( NULL, NULL, shader2, NULL, NULL, NULL );
        sound4 ( );
        TerminateThread ( hThread4, NULL );
        CloseHandle ( hThread4 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread5 = CreateThread ( NULL, NULL, shader3, NULL, NULL, NULL );
        sound5 ( );
        TerminateThread ( hThread5, NULL );
        CloseHandle ( hThread5 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread6 = CreateThread ( NULL, NULL, shader4, NULL, NULL, NULL );
        sound6 ( );
        TerminateThread ( hThread6, NULL );
        CloseHandle ( hThread6 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread7 = CreateThread ( NULL, NULL, shader5, NULL, NULL, NULL );
        sound7 ( );
        TerminateThread ( hThread7, NULL );
        CloseHandle ( hThread7 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread8 = CreateThread ( NULL, NULL, shader6, NULL, NULL, NULL );
        sound8 ( );
        TerminateThread ( hThread8, NULL );
        CloseHandle ( hThread8 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread9 = CreateThread ( NULL, NULL, shader7, NULL, NULL, NULL );
        sound9 ( );
        TerminateThread ( hThread9, NULL );
        CloseHandle ( hThread9 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread10 = CreateThread ( NULL, NULL, shader8, NULL, NULL, NULL );
        sound10 ( );
        TerminateThread ( hThread10, NULL );
        CloseHandle ( hThread10 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread11 = CreateThread ( NULL, NULL, shader9, NULL, NULL, NULL );
        sound11 ( );
        TerminateThread ( hThread11, NULL );
        CloseHandle ( hThread11 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread12 = CreateThread ( NULL, NULL, shader10, NULL, NULL, NULL );
        sound12 ( );
        TerminateThread ( hThread12, NULL );
        CloseHandle ( hThread12 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );
        HANDLE hThread13 = CreateThread ( NULL, NULL, profect, NULL, NULL, NULL );
        sound13 ( );
        TerminateThread ( hThread13, NULL );
        CloseHandle ( hThread13 );
        RedrawWindow ( NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN | RDW_UPDATENOW );
        Sleep ( 100 );

        return 0x00;

    }
}