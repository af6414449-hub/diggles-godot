
/* Library Function - Single Match
    int __cdecl BuildCatchObjectHelperInternal<class __FrameHandler3>(struct EHExceptionRecord
   *,void *,struct _s_HandlerType const *,struct _s_CatchableType const *)
   
   Library: Visual Studio 2019 Release */

int __cdecl
BuildCatchObjectHelperInternal<class___FrameHandler3>
          (EHExceptionRecord *param_1,void *param_2,_s_HandlerType *param_3,
          _s_CatchableType *param_4)

{
  uint *puVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_EBP;
  int *piVar7;
  
  FUN_006cf3b0(&DAT_007631d0,0x10);
  iVar6 = 0;
  puVar1 = *(uint **)(unaff_EBP + 0x10);
  if (((puVar1[1] == 0) || (*(char *)(puVar1[1] + 8) == '\0')) ||
     ((puVar1[2] == 0 && (-1 < (int)*puVar1)))) {
    iVar6 = 0;
    goto LAB_006d0928;
  }
  uVar2 = *puVar1;
  piVar7 = *(int **)(unaff_EBP + 0xc);
  if (-1 < (int)uVar2) {
    piVar7 = (int *)((int)piVar7 + puVar1[2] + 0xc);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar4 = DAT_00769a98;
  pbVar3 = *(byte **)(unaff_EBP + 0x14);
  if ((((char)uVar2 < '\0') && ((*pbVar3 & 0x10) != 0)) &&
     (*(int *)(unaff_EBP + -0x1c) = DAT_00769a98, iVar4 != 0)) {
    guard_check_icall();
    iVar4 = (**(code **)(unaff_EBP + -0x1c))();
LAB_006d0877:
    if ((iVar4 == 0) || (piVar7 == (int *)0x0)) {
LAB_006d0938:
                    /* WARNING: Subroutine does not return */
      _abort();
    }
    *piVar7 = iVar4;
LAB_006d08c7:
    iVar4 = ___AdjustPointer(iVar4,pbVar3 + 8);
    *piVar7 = iVar4;
  }
  else {
    iVar4 = *(int *)(unaff_EBP + 8);
    if ((uVar2 & 8) != 0) {
      iVar4 = *(int *)(iVar4 + 0x18);
      goto LAB_006d0877;
    }
    if ((*pbVar3 & 1) != 0) {
      if ((*(int *)(iVar4 + 0x18) == 0) || (piVar7 == (int *)0x0)) goto LAB_006d0938;
      FUN_006d1b90(piVar7,*(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(pbVar3 + 0x14));
      if ((*(int *)(pbVar3 + 0x14) != 4) || (*piVar7 == 0)) goto LAB_006d0912;
      iVar4 = *piVar7;
      goto LAB_006d08c7;
    }
    iVar4 = *(int *)(iVar4 + 0x18);
    if (*(int *)(pbVar3 + 0x18) == 0) {
      if ((iVar4 == 0) || (piVar7 == (int *)0x0)) goto LAB_006d0938;
      uVar5 = ___AdjustPointer(iVar4,pbVar3 + 8,*(undefined4 *)(pbVar3 + 0x14));
      FUN_006d1b90(piVar7,uVar5);
    }
    else {
      if ((iVar4 == 0) || (piVar7 == (int *)0x0)) goto LAB_006d0938;
      iVar6 = ((*pbVar3 & 4) != 0) + 1;
      *(int *)(unaff_EBP + -0x20) = iVar6;
    }
  }
LAB_006d0912:
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
LAB_006d0928:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar6;
}

