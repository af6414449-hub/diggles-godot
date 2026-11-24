
/* public: void __thiscall DisplayIndexManager::SetDisplayIndex(int,int,int) */

void __thiscall
DisplayIndexManager::SetDisplayIndex(DisplayIndexManager *this,int param_1,int param_2,int param_3)

{
                    /* 0x8bd0  240  ?SetDisplayIndex@DisplayIndexManager@@QAEXHHH@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (param_1 != *(int *)this) {
    FUN_100028b0(&DAT_1416edd0,0x40,"Display index was changed from %d to %d \n",*(int *)this,
                 param_1);
    OutputDebugStringA(&DAT_1416edd0);
    *(int *)(this + 0xc) = param_2;
    *(int *)this = param_1;
    *(int *)(this + 0x10) = param_3;
  }
  return;
}

