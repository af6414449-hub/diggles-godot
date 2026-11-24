
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2019 Release */

int __cdecl _raise(int _SigNum)

{
  code *pcVar1;
  __crt_signal_action_t *p_Var2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char extraout_CL;
  byte bVar7;
  char cVar8;
  uint uVar9;
  int *piVar10;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007637e8,0x28);
  piVar10 = (int *)0x0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined1 *)(unaff_EBP + -0x19) = 1;
  iVar6 = *(int *)(unaff_EBP + 8);
  if (8 < iVar6) {
    if (iVar6 == 0xb) goto LAB_006e8f57;
    if ((iVar6 == 0xf) || ((0x14 < iVar6 && (iVar6 < 0x17)))) goto LAB_006e8f4c;
LAB_006e8f7b:
    piVar10 = __errno();
    *piVar10 = 0x16;
    FUN_006e510d();
LAB_006e8f65:
    iVar6 = -1;
    goto LAB_006e90d4;
  }
  if (iVar6 == 8) {
LAB_006e8f57:
    piVar10 = (int *)___acrt_getptd_noexit();
    *(int **)(unaff_EBP + -0x28) = piVar10;
    if (piVar10 == (int *)0x0) goto LAB_006e8f65;
    p_Var2 = siglookup(iVar6,(__crt_signal_action_t *)*piVar10);
    if (p_Var2 == (__crt_signal_action_t *)0x0) goto LAB_006e8f7b;
    p_Var2 = p_Var2 + 8;
    cVar8 = '\0';
    *(undefined1 *)(unaff_EBP + -0x19) = 0;
  }
  else {
    if (iVar6 != 2) {
      if (iVar6 == 4) goto LAB_006e8f57;
      if (iVar6 != 6) goto LAB_006e8f7b;
    }
LAB_006e8f4c:
    p_Var2 = (__crt_signal_action_t *)get_global_action_nolock(iVar6);
    cVar8 = extraout_CL;
  }
  *(__crt_signal_action_t **)(unaff_EBP + -0x24) = p_Var2;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  if (cVar8 != '\0') {
    ___acrt_lock(3);
    cVar8 = *(char *)(unaff_EBP + -0x19);
  }
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined1 *)(unaff_EBP + -0x1a) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (cVar8 == '\0') {
    uVar9 = **(uint **)(unaff_EBP + -0x24);
    cVar8 = '\0';
  }
  else {
    bVar7 = (byte)DAT_0076700c & 0x1f;
    uVar9 = DAT_0076700c ^ **(uint **)(unaff_EBP + -0x24);
    uVar9 = uVar9 >> bVar7 | uVar9 << 0x20 - bVar7;
    cVar8 = *(char *)(unaff_EBP + -0x19);
  }
  *(uint *)(unaff_EBP + -0x20) = uVar9;
  *(uint *)(unaff_EBP + -0x2c) = uVar9;
  *(bool *)(unaff_EBP + -0x1a) = uVar9 == 1;
  if (uVar9 != 1) {
    if (uVar9 == 0) {
      if (cVar8 != '\0') {
        ___acrt_unlock(3);
      }
      __exit(3);
      pcVar1 = (code *)swi(3);
      iVar6 = (*pcVar1)();
      return iVar6;
    }
    if (((iVar6 == 8) || (iVar6 == 0xb)) || (iVar6 == 4)) {
      *(int *)(unaff_EBP + -0x30) = piVar10[1];
      piVar10[1] = 0;
      if (iVar6 == 8) {
        puVar3 = (undefined4 *)FUN_006e8ef4();
        *(undefined4 *)(unaff_EBP + -0x34) = *puVar3;
        puVar3 = (undefined4 *)FUN_006e8ef4();
        *puVar3 = 0x8c;
        goto LAB_006e9023;
      }
    }
    else {
LAB_006e9023:
      if (iVar6 == 8) {
        iVar5 = *piVar10;
        for (iVar4 = iVar5 + 0x24; *(int *)(unaff_EBP + -0x38) = iVar4, iVar4 != iVar5 + 0x90;
            iVar4 = iVar4 + 0xc) {
          *(undefined4 *)(iVar4 + 8) = 0;
        }
        goto LAB_006e9053;
      }
    }
    **(uint **)(unaff_EBP + -0x24) = DAT_0076700c;
  }
LAB_006e9053:
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e9090();
  if (*(char *)(unaff_EBP + -0x1a) == '\0') {
    if (iVar6 == 8) {
      iVar5 = ___acrt_getptd();
      guard_check_icall(8,*(undefined4 *)(iVar5 + 8));
      (**(code **)(unaff_EBP + -0x20))();
    }
    else {
      guard_check_icall(iVar6);
      (**(code **)(unaff_EBP + -0x20))();
      if ((iVar6 != 0xb) && (iVar6 != 4)) goto LAB_006e90d2;
    }
    piVar10[1] = *(int *)(unaff_EBP + -0x30);
    if (iVar6 == 8) {
      iVar6 = ___acrt_getptd();
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(unaff_EBP + -0x34);
    }
  }
LAB_006e90d2:
  iVar6 = 0;
LAB_006e90d4:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar6;
}

