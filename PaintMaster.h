#include<windows.h>
#include"PaintMaster.c"
typedef struct PaintWindow;

extern PaintWindow initPaintWindow(UINT style, WNDPROC WndProc, 
    HINSTANCE hinstance, HICON hicon, 
    HCURSOR hcursor, HBRUSH hbrush, 
    LPCWSTR menuName,  LPCWSTR className);
extern HWND createBaseWindow(LPCWSTR className, LPCWSTR wName, HINSTANCE hinstance, HWND hwnd, int cmdshow); 

extern void initWNDCLASS(PaintWindow p);
extern void MSG_GETTER(MSG *msg, HWND hwnd);
////////////// HWND changer
extern void setBackgroundBrush(HWND hwnd, LONG newVal);
extern void setCursor(HWND hwnd, LONG newVal);
extern void setIcon(HWND hwnd, LONG newVal);
extern void setStyle(HWND hwnd, LONG newVal);
extern void setWNDPROC(HWND hwnd, LONG newVal);