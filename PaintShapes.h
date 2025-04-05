#include <windows.h>
#include"PaintShapes.c"

typedef struct RHOMBUS;
extern RECT initRect();
extern void drawRHOMBUS(HDC hdc, HWND hwnd, RHOMBUS rh, COLORREF colorref);
extern void drawText(HDC hdc, HWND hwnd, char ch[]);