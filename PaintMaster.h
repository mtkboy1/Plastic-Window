#include<windows.h>
#include"PaintMaster.c"
typedef struct PaintWindow;

extern PaintWindow initPaintWindow(UINT style, WNDPROC WndProc, 
    HINSTANCE hinstance, HICON hicon, 
    HCURSOR hcursor, HBRUSH hbrush, 
    LPCWSTR menuName,  LPCWSTR className);
extern HWND createBaseWindow(LPCWSTR className, LPCWSTR wName, HINSTANCE hinstance); 

extern void initWNDCLASS(PaintWindow p);
////////////// HWND changer
extern void setBackgroundBrush(HWND hwnd, LONG newVal);
extern void setCursor(HWND hwnd, LONG newVal);
extern void setIcon(HWND hwnd, LONG newVal);
extern void setStyle(HWND hwnd, LONG newVal);
extern void setWNDPROC(HWND hwnd, LONG newVal);
extern void initWNDCLASS(PaintWindow p);