
/* public: class CSdlWindowHandle * __thiscall CSdlWindow::GetSdlWndHandle(void)const  */

CSdlWindowHandle * __thiscall CSdlWindow::GetSdlWndHandle(CSdlWindow *this)

{
                    /* 0x13cd0  171  ?GetSdlWndHandle@CSdlWindow@@QBEPAVCSdlWindowHandle@@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170b87);
  return *(CSdlWindowHandle **)(this + 4);
}

