
/* Library Function - Single Match
    unsigned char __cdecl IsInExceptionSpec(struct EHExceptionRecord *,struct _s_ESTypeList const *)
   
   Library: Visual Studio 2019 Release */

uchar __cdecl IsInExceptionSpec(EHExceptionRecord *param_1,_s_ESTypeList *param_2)

{
  int *piVar1;
  int iVar2;
  HandlerType *pHVar3;
  int iVar4;
  int *piVar5;
  uchar uVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  if (param_2 == (_s_ESTypeList *)0x0) {
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  iVar7 = param_2->nCount;
  uVar6 = '\0';
  if (0 < iVar7) {
    local_8 = 0;
    piVar1 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
    iVar2 = *piVar1;
    uVar6 = '\0';
    do {
      if (0 < iVar2) {
        pHVar3 = param_2->pTypeArray;
        local_c = iVar2;
        piVar5 = piVar1;
        do {
          piVar5 = piVar5 + 1;
          iVar4 = TypeMatchHelper<class___FrameHandler3>
                            ((_s_HandlerType *)((int)&pHVar3->adjectives + local_8),
                             (_s_CatchableType *)*piVar5,*(_s_ThrowInfo **)(param_1 + 0x1c));
          if (iVar4 != 0) {
            uVar6 = '\x01';
            break;
          }
          local_c = local_c + -1;
        } while (0 < local_c);
      }
      local_8 = local_8 + 0x10;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  return uVar6;
}

