
/* private: void __thiscall CSdlWindowHandle::Create(char const *,long,long,long,long,unsigned long)
    */

void __thiscall
CSdlWindowHandle::Create
          (CSdlWindowHandle *this,char *param_1,long param_2,long param_3,long param_4,long param_5,
          ulong param_6)

{
  int iVar1;
  undefined1 local_14 [12];
  CSdlWindowHandle *local_8;
  
  local_8 = this;
                    /* 0x13ee0  109  ?Create@CSdlWindowHandle@@AAEXPBDJJJJK@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = SDL_CreateWindow(param_1,param_2,param_3,param_4,param_5,param_6);
  *(int *)local_8 = iVar1;
  FUN_100028b0(&DAT_1416eea0,0x40,"SDL_CreateWindow -> (%d, %d, %d, %d) \n",param_2,param_3,param_4,
               param_5);
  OutputDebugStringA(&DAT_1416eea0);
  if (*(int *)local_8 != 0) {
    return;
  }
  FUN_100052e0("SDL window creation failed");
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a25c);
}

