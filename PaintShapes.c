#include<windows.h>

/*typedef struct{
    LONG right;
    LONG bottom;

    LONG left;
    LONG top;
} rect;*/
typedef struct{
    LONG x;
    LONG y;
    LONG sx;
    LONG sy;
} RHOMBUS;
typedef struct{
    LONG x;
    LONG y;
    LONG sx;
    LONG sy;
} ELLIPSE;
RECT initRect(LONG x, LONG y, LONG sizeX, LONG sizeY){
    RECT r;
    r.left = x;
    r.right = x+sizeX;
    r.top = y;
    r.bottom = y+sizeY;
    return r;
}
void drawText(HDC hdc, HWND hwnd, char ch[]){
    RECT r;
    GetClientRect(hwnd, &r);
    DrawText(hdc,ch, sizeof(ch)/sizeof(ch[0]), &r, DT_BOTTOM);
}
void drawRHOMBUS(HDC hdc, HWND hwnd, RHOMBUS rh, COLORREF color, int size){
    RHOMBUS e = rh;

    HPEN pen = CreatePen(PS_SOLID, size, color);
    SelectObject(hdc, pen);

    POINT coordinsates[5] = {{e.x+(e.sx/2),e.y}, //верхняя точка
                        {e.x,e.y+(e.sy/2)}, //левая точка
                        {e.x+(e.sx/2),e.y+e.sy}, //нижняя точка
                        {e.x+e.sx,e.y+(e.sy/2)}, //Правая точка
                        {e.x+(e.sx/2),e.y}};
    Polyline(hdc, coordinsates, 5);
}
void drawELLIPSE(HDC hdc, HWND hwnd, ELLIPSE el, COLORREF color, int size){
    ELLIPSE e = el;
    if(color != NULL||size != NULL){
        HPEN pen = CreatePen(PS_SOLID, size, color);
        SelectObject(hdc, pen);
        LONG FinalPointX = e.x+e.sx;
        LONG FinalPointY = e.y+e.sy;
        Arc(hdc,e.x,e.y,e.x+e.sx,e.y+e.sy,FinalPointX,FinalPointY,FinalPointX,FinalPointY);
        DeleteObject(pen);
    } else {
        HPEN pen = CreatePen(PS_SOLID, size, color);
        SelectObject(hdc, pen);
        LONG FinalPointX = e.x+e.sx;
        LONG FinalPointY = e.y+e.sy;
        Arc(hdc,e.x,e.y,e.x+e.sx,e.y+e.sy,FinalPointX,FinalPointY,FinalPointX,FinalPointY);
    }
}