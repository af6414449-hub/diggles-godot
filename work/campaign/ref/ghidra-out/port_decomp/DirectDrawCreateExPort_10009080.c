
/* long __stdcall DirectDrawCreateExPort(struct _GUID *,void * *,struct _GUID const &,struct
   IUnknown *) */

long DirectDrawCreateExPort(_GUID *param_1,void **param_2,_GUID *param_3,IUnknown *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_14 [16];
  
                    /* 0x9080  117  ?DirectDrawCreateExPort@@YGJPAU_GUID@@PAPAXABU1@PAUIUnknown@@@Z
                        */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (param_4 != (IUnknown *)0x0) {
    return -0x7ff8ffa9;
  }
  puVar3 = &DAT_10043400;
  uVar4 = 0xc;
  do {
    if (param_3->Data1 != *puVar3) {
      *param_2 = (void *)0x0;
      return -0x7ff8ffa9;
    }
    param_3 = (_GUID *)&param_3->Data2;
    puVar3 = puVar3 + 1;
    bVar5 = 3 < uVar4;
    uVar4 = uVar4 - 4;
  } while (bVar5);
  puVar1 = (undefined4 *)FUN_1003ff62(8);
  *puVar1 = DirectDraw7Port::vftable;
  puVar1[1] = 0;
  iVar2 = FUN_100185c0(puVar1,&DAT_10043400,param_2);
  if (-1 < iVar2) {
    return 0;
  }
  FUN_100402ac(puVar1,8);
  FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
}

