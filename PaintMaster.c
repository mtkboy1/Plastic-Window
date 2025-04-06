#include<windows.h>
typedef struct{ //Конструктор окна
    UINT style;
    WNDPROC wndProc;
    HINSTANCE hinstance;
    HICON hicon;
    HCURSOR hcursor;
    HBRUSH hbrush;
    LPCWSTR menuName;
    LPCWSTR className;
} PaintWindow;

PaintWindow initPaintWindow(UINT style, WNDPROC WndProc, 
    HINSTANCE hinstance, HICON hicon, 
    HCURSOR hcursor, HBRUSH hbrush, 
    LPCWSTR menuName, LPCWSTR className){
    PaintWindow window;
    window.hinstance = hinstance;
    window.wndProc = WndProc;
    if(hicon==NULL){
        window.hicon = LoadIcon(NULL, IDI_WINLOGO);
    } else window.hicon = hicon;
    if(hcursor==NULL){
        window.hcursor = LoadCursor(NULL, IDC_ARROW);
    } else window.hcursor = hcursor;
    if(hbrush==NULL){
        window.hbrush = (HBRUSH)(COLOR_WINDOW - 4);
    } else window.hbrush = hbrush;
    if(menuName==NULL){
        window.menuName = NULL;
    } else window.menuName = menuName;
    window.style = CS_HREDRAW|CS_VREDRAW;
    if(className==NULL){
        window.className = "NULL";
    } else window.className = className;
    return window;
}

HWND createBaseWindow(LPCWSTR className, LPCWSTR wName, HINSTANCE hinstance){
    HWND window;
    if(className==NULL){
        window = CreateWindow("NULL", wName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hinstance, NULL);
    } else {
        window = CreateWindow(className, wName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hinstance, NULL);
    }
    return window;
}

void initWNDCLASS(PaintWindow p, HWND hwnd){
    WNDCLASS wndclass;
    wndclass.lpfnWndProc = p.wndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = p.hinstance;
    wndclass.hbrBackground = p.hbrush;
    wndclass.hCursor = p.hcursor;
    wndclass.hIcon = p.hicon;
    wndclass.lpfnWndProc = p.wndProc;
    wndclass.lpszClassName = p.className;
    wndclass.lpszMenuName = NULL;
    wndclass.style = p.style;
    if (!RegisterClass(&wndclass)) {
        MessageBox(NULL, "Cannot register class", "Error", MB_OK);
        return 0;
    }
    ShowWindow(hwnd, 0);
}
void MSG_GETTER(MSG *msg, HWND hwnd){
    while(GetMessage(&msg,hwnd,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void setBackgroundBrush(HWND hwnd, LONG newVal){
    SetClassLong(hwnd,GCL_HBRBACKGROUND, newVal);
}
void setCursor(HWND hwnd, LONG newVal){
    SetClassLong(hwnd,GCL_HCURSOR, newVal);
}
void setsetIcon(HWND hwnd, LONG newVal){
    SetClassLong(hwnd,GCL_HICON, newVal);
}
void setStyle(HWND hwnd, LONG newVal){
    SetClassLong(hwnd,GCL_STYLE, newVal);
}
void setWNDPROC(HWND hwnd, LONG newVal){
    SetClassLong(hwnd,GCL_WNDPROC, newVal);
}