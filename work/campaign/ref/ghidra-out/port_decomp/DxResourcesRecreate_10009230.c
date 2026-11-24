
/* void __cdecl DxResourcesRecreate(int,int,int,int) */

void __cdecl DxResourcesRecreate(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  void *_Dst;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x9230  118  ?DxResourcesRecreate@@YAXHHHH@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041aa7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar2 = DAT_10050c64;
  iVar1 = *DAT_10050c64;
  *(int *)(iVar1 + 0xbc) = param_3;
  *(int *)(iVar1 + 0xc0) = param_4;
  *(undefined1 *)(*piVar2 + 0xc4) = 1;
  FUN_10010060(param_1,param_2);
  ExceptionList = local_10;
  return;
}

