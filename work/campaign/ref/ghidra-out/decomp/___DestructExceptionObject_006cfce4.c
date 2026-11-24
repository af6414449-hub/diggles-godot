
/* Library Function - Single Match
    ___DestructExceptionObject
   
   Library: Visual Studio 2019 Release */

void ___DestructExceptionObject(void)

{
  int *piVar1;
  byte *pbVar2;
  void *pvVar3;
  code *pcVar4;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763108,8);
  piVar1 = *(int **)(unaff_EBP + 8);
  if ((((piVar1 != (int *)0x0) && (*piVar1 == -0x1f928c9d)) && (piVar1[4] == 3)) &&
     ((((piVar1[5] == 0x19930520 || (piVar1[5] == 0x19930521)) || (piVar1[5] == 0x19930522)) &&
      (pbVar2 = (byte *)piVar1[7], pbVar2 != (byte *)0x0)))) {
    pvVar3 = *(void **)(pbVar2 + 4);
    if (pvVar3 == (void *)0x0) {
      if (((*pbVar2 & 0x10) != 0) && (piVar1 = *(int **)piVar1[6], piVar1 != (int *)0x0)) {
        pcVar4 = *(code **)(*piVar1 + 8);
        guard_check_icall(piVar1);
        (*pcVar4)();
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -4) = 0;
      _CallMemberFunction0((void *)piVar1[6],pvVar3);
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

