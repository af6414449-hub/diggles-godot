
/* public: void __thiscall CSdlWindowHandle::MoveWindow(int,int)const  */

BOOL CSdlWindowHandle::MoveWindow(HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint)

{
  BOOL BVar1;
  undefined4 *in_ECX;
  
                    /* 0x14240  205  ?MoveWindow@CSdlWindowHandle@@QBEXHH@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  BVar1 = SDL_SetWindowPosition(*in_ECX,hWnd,X);
  return BVar1;
}

