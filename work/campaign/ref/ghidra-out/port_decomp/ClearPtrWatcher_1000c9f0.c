
/* void __cdecl PStdUtils::ClearPtrWatcher(void) */

void __cdecl PStdUtils::ClearPtrWatcher(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
                    /* 0xc9f0  104  ?ClearPtrWatcher@PStdUtils@@YAXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar4 = DAT_10051090;
  if (DAT_10051094 != 0) {
    cVar1 = *(char *)((int)*(int **)(DAT_10051090 + 4) + 0xd);
    piVar3 = *(int **)(DAT_10051090 + 4);
    while (cVar1 == '\0') {
      FUN_1000cab0(&DAT_10051090,piVar3[2]);
      piVar2 = (int *)*piVar3;
      FUN_100402ac(piVar3,0x14);
      piVar3 = piVar2;
      cVar1 = *(char *)((int)piVar2 + 0xd);
    }
    *(int *)(iVar4 + 4) = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(iVar4 + 8) = iVar4;
    DAT_10051094 = 0;
  }
  return;
}

