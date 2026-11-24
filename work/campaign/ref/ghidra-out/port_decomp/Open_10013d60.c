
/* public: bool __thiscall CSdlWindow::Open(char const *,long,long,long,long,unsigned long,bool) */

bool __thiscall
CSdlWindow::Open(CSdlWindow *this,char *param_1,long param_2,long param_3,long param_4,long param_5,
                ulong param_6,bool param_7)

{
  CSdlWindowHandle *this_00;
  ulong uVar1;
  
                    /* 0x13d60  210  ?Open@CSdlWindow@@QAE_NPBDJJJJK_N@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *this = (CSdlWindow)0x0;
  this_00 = (CSdlWindowHandle *)FUN_1003ff62(4);
  uVar1 = 0x601;
  if (!param_7) {
    uVar1 = 0x604;
  }
  *(undefined4 *)this_00 = 0;
  *(CSdlWindowHandle **)(this + 4) = this_00;
  CSdlWindowHandle::Create(this_00,param_1,param_2,param_3,param_4,param_5,uVar1);
  this[1] = (CSdlWindow)0x1;
  return true;
}

