
void FUN_10011270(void)

{
  void *pvVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  void *_Dst;
  uint uVar5;
  size_t sVar6;
  uint uVar7;
  size_t sVar8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170af7);
  uVar7 = *(uint *)(in_ECX + 8);
  uVar3 = 1;
  if (uVar7 != 0) {
    uVar3 = uVar7;
  }
  for (; (uVar5 = uVar3 - uVar7, uVar5 == 0 || (uVar3 < 8)); uVar3 = uVar3 * 2) {
    if (0xfffffff - uVar3 < uVar3) {
      FUN_100113f0();
LAB_100113e0:
      FUN_10002a00();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  uVar7 = *(uint *)(in_ECX + 0xc) >> 2;
  if (0x3fffffff < uVar3) goto LAB_100113e0;
  uVar3 = uVar3 * 4;
  if (uVar3 < 0x1000) {
    if (uVar3 == 0) {
      _Dst = (void *)0x0;
    }
    else {
      _Dst = (void *)FUN_1003ff62(uVar3);
    }
  }
  else {
    if (uVar3 + 0x23 <= uVar3) goto LAB_100113e0;
    iVar4 = FUN_1003ff62(uVar3 + 0x23);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    _Dst = (void *)(iVar4 + 0x23U & 0xffffffe0);
    *(int *)((int)_Dst - 4) = iVar4;
  }
  sVar8 = uVar7 * 4;
  pvVar1 = (void *)(*(int *)(in_ECX + 4) + sVar8);
  sVar6 = (*(int *)(in_ECX + 8) * 4 - (int)pvVar1) + *(int *)(in_ECX + 4);
  memmove((void *)(sVar8 + (int)_Dst),pvVar1,sVar6);
  pvVar1 = (void *)(sVar6 + (int)(sVar8 + (int)_Dst));
  if (uVar5 < uVar7) {
    sVar6 = uVar5 * 4;
    memmove(pvVar1,*(void **)(in_ECX + 4),sVar6);
    pvVar1 = (void *)(sVar6 + *(int *)(in_ECX + 4));
    sVar8 = (*(int *)(in_ECX + 4) - (int)pvVar1) + sVar8;
    memmove(_Dst,pvVar1,sVar8);
    memset((void *)((int)_Dst + sVar8),0,sVar6);
  }
  else {
    memmove(pvVar1,*(void **)(in_ECX + 4),uVar7 * 4);
    memset((void *)((int)pvVar1 + sVar8),0,(uVar5 - uVar7) * 4);
    memset(_Dst,0,sVar8);
  }
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_10011040(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar5;
  *(void **)(in_ECX + 4) = _Dst;
  return;
}

