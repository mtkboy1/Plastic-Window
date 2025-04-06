#include <windows.h>
#include"PaintShapes.c"

typedef struct RHOMBUS;
extern RECT initRect();
extern void drawRHOMBUS(HDC hdc, HWND hwnd, RHOMBUS rh, COLORREF color, int size);
extern void drawELLIPSE(HDC hdc, HWND hwnd, ELLIPSE el, COLORREF color, int size);
extern void drawText(HDC hdc, HWND hwnd, char ch[]);