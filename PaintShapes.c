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
void drawRHOMBUS(HDC hdc, HWND hwnd, RHOMBUS rh, COLORREF colorref){
    RHOMBUS e = rh;
    LONG x = e.x;
    LONG y = e.y;
    LONG sizeX = e.sx/e.sy;
    LONG sizeY = e.sy/e.sx;
    COLORREF color = colorref;
    if(e.sx>e.sy){
        while(y<e.y+e.sy){
            for(LONG XC=e.x-(sizeX/2)+1; XC<e.x+(sizeX/2)+1; XC++){
                SetPixel(hdc,XC,y,color);
            }
            if(y<e.y+((e.sy)/2)){
                sizeX+=e.sx/e.sy+1;
            } else {
                sizeX-=e.sx/e.sy+1;
            }
            y+=1;
        }
    } else {
        while(x<e.x+e.sx){
            for(LONG YC=e.y-(sizeY/2); YC<e.y+(sizeY/2); YC++){
                SetPixel(hdc,YC,y,color);
            }
            sizeY+=e.sy/e.sx;
            x+=1;
        }
    }
}