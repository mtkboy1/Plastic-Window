#include <windows.h>
#include<wingdi.h>
#include"PaintShapes.h"
#include "PaintMaster.h"
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprev, LPSTR lp, int cmdshow){
    HWND wmain;
    char *class = "Hi";
    MSG msg;
    PaintWindow p;
    p = initPaintWindow((UINT) NULL, WinProc, hinstance, NULL, NULL, NULL, NULL, NULL);
    initWNDCLASS(p);
   /*if (!RegisterClass(&cls)) {
        MessageBox(NULL, "Cannot register class", "Error", MB_OK);
        return 0;
    }*/
    wmain = createBaseWindow(NULL, "Hello",hinstance);
    if (!wmain) {
        MessageBox(NULL, "Cannot create main window", "Error", MB_OK);
        return 0;
    }
    ShowWindow(wmain, cmdshow);
    while(GetMessage(&msg,wmain,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
void create(){

}
LRESULT CALLBACK WinProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam){
    static xs;
    HDC hdc;
    PAINTSTRUCT ps;
    RECT r;
    RECT tex;
    
    switch (umsg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        DestroyWindow(hwnd);
        break;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        r = initRect(0,0,50,50);
        DrawFocusRect(hdc,&r);
        EndPaint(hwnd, &ps);
        break;
    case WM_SIZE:
        hdc = BeginPaint(hwnd, &ps);
        xs+=1;
        r = initRect(xs,100,50,50);
        DrawFocusRect(hdc,&r);
        drawText(hdc, hwnd, "HUY");

        ELLIPSE ell;
        ell.sx = 100;
        ell.sy = 100;
        ell.x = 100;
        ell.y = 100;

        drawELLIPSE(hdc,hwnd,ell);
        EndPaint(hwnd, &ps);
        break;
    default:
        return DefWindowProc(hwnd, umsg, wparam, lparam);
    }
    return 0;
    //CallBack_OnPaint(umsg, &create);
}