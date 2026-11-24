
/* WARNING: Removing unreachable block (ram,0x0055ba7e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055b510(void)

{
  int *piVar1;
  void *_Dst;
  size_t _Size;
  uint uVar2;
  uint uVar3;
  CMap *this;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 extraout_ECX;
  uint *puVar9;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 *puVar10;
  bool bVar11;
  undefined8 uVar12;
  undefined8 local_2c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar8 = DAT_00772400;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00705670;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar12 = 0;
  local_2c = 0;
  *(undefined8 *)(DAT_00772400 + 0xa088) = 0;
  FUN_00565850(uVar3);
  FUN_0043e3c0();
  *(undefined8 *)(iVar8 + 0xa080) = uVar12;
  FUN_0055a060();
  if (DAT_0076a274 == (CMap *)0x0) {
    this = (CMap *)FUN_006ba810(0x26);
    local_8 = 0;
    if (this == (CMap *)0x0) {
      this = (CMap *)0x0;
    }
    else {
      FUN_00424cc0(this);
    }
    local_8 = 0xffffffff;
    DAT_0076a274 = this;
  }
  FUN_00427610(DAT_0076a274);
  FUN_00429970();
  FUN_004313c0();
  FUN_00431420();
  FUN_00432390();
  CProdPlannerMgr__Reset();
  FUN_005d2920();
  iVar4 = FUN_005b78b0();
  piVar1 = (int *)(iVar4 + 0xc008);
  FUN_005b9170(extraout_ECX);
  uVar3 = 0;
  local_18 = 0x2fff;
  local_14 = 0;
  do {
    if (uVar3 < 0x3000) {
      puVar9 = (uint *)(iVar4 + 4) + uVar3;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = (uint *)(iVar4 + 4);
    }
    *puVar9 = local_18;
    if (((int)uVar3 < 0) || (*(int *)(iVar4 + 0xc00c) <= (int)uVar3)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      FUN_005b7250();
      if (-1 < (int)uVar3) goto LAB_0055b672;
LAB_0055b688:
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)(*piVar1 + 0x74) = 0xffffffff;
      if (-1 < (int)uVar3) goto LAB_0055b6ab;
LAB_0055b6be:
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)(*piVar1 + 0x6c) = 0;
      if (-1 < (int)uVar3) goto LAB_0055b6e1;
LAB_0055b6ec:
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar5 = *piVar1;
    }
    else {
      FUN_005b7250();
LAB_0055b672:
      if (*(int *)(iVar4 + 0xc00c) <= (int)uVar3) goto LAB_0055b688;
      *(undefined4 *)(*piVar1 + 0x74 + local_14) = 0xffffffff;
LAB_0055b6ab:
      if (*(int *)(iVar4 + 0xc00c) <= (int)uVar3) goto LAB_0055b6be;
      *(undefined4 *)(*piVar1 + 0x6c + local_14) = 0;
LAB_0055b6e1:
      if (*(int *)(iVar4 + 0xc00c) <= (int)uVar3) goto LAB_0055b6ec;
      iVar5 = *piVar1 + local_14;
    }
    local_14 = local_14 + 0xd8;
    local_18 = local_18 - 1;
    *(uint *)(iVar5 + 100) = uVar3;
    uVar3 = uVar3 + 1;
  } while (local_18 < 0x80000000);
  *(undefined4 *)(iVar4 + 0xc004) = 0x2fff;
  FUN_00592d70();
  FUN_00592d20();
  FUN_005641c0(2,2);
  FUN_0057d980();
  FUN_0057cb60();
  puVar6 = (undefined4 *)FUN_004d2000();
  *puVar6 = 0;
  FUN_005ee9d0();
  FUN_005eec60();
  iVar4 = DAT_0077246c;
  if (DAT_0077246c != 0) {
    local_8 = 1;
    FUN_00415170(0);
    if (*(int *)(iVar4 + 0x11) != 0) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_00442750();
    FUN_006cecd8(iVar4,0x19);
    DAT_0077246c = 0;
  }
  CMap__Shut(PTR_0077241c);
  FUN_00492250();
  FUN_00492d00();
  if (DAT_00772448 == (undefined4 *)0x0) {
    DAT_00772448 = (undefined4 *)FUN_006ba810(0x1e);
    if (DAT_00772448 == (undefined4 *)0x0) {
      DAT_00772448 = (undefined4 *)0x0;
    }
    else {
      *DAT_00772448 = 0;
      DAT_00772448[1] = 0;
    }
  }
  FUN_005b9ad0(0);
  FUN_00492250();
  FUN_00492d00();
  FUN_00492250();
  FUN_00492540();
  if (DAT_0076a33c == (undefined4 *)0x0) {
    DAT_0076a33c = (undefined4 *)FUN_006ba810(0x1e2);
    if (DAT_0076a33c == (undefined4 *)0x0) {
      DAT_0076a33c = (undefined4 *)0x0;
    }
    else {
      *DAT_0076a33c = 0;
      DAT_0076a33c[1] = 0;
    }
  }
  puVar6 = DAT_0076a33c;
  iVar4 = DAT_0076a33c[1];
  if (-1 < iVar4) {
    if (0 < iVar4) {
      DAT_0076a33c[1] = DAT_0076a33c[1] - iVar4;
    }
    goto LAB_0055ba91;
  }
  if ((iVar4 + 0xfU & 0xfffffff0) != 0) {
    _Dst = (void *)*DAT_0076a33c;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8 = 2;
    if (_Dst == (void *)0x0) {
      uVar7 = FUN_006ba810(0x9b);
      local_8 = 0xffffffff;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    else {
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8 = CONCAT31(local_8._1_3_,3);
      LOCK();
      _DAT_00c3c818 = _DAT_00c3c818 + 1;
      UNLOCK();
      puVar10 = (undefined4 *)((int)_Dst + -0x1c);
      iVar5 = FUN_006ba730();
      if (iVar5 == 0) {
        _Size = *(size_t *)((int)_Dst + -8);
        iVar5 = FUN_006ba730();
        if (iVar5 != 0) goto LAB_0055b94d;
        if (*(int *)((int)_Dst + -0x14) != 0) {
          *(undefined4 *)(*(int *)((int)_Dst + -0x14) + 4) = *(undefined4 *)((int)_Dst + -0x18);
        }
        if (*(int *)((int)_Dst + -0x18) != 0) {
          *(undefined4 *)(*(int *)((int)_Dst + -0x18) + 8) = *(undefined4 *)((int)_Dst + -0x14);
        }
        if (puVar10 == DAT_00c3c81c) {
          DAT_00c3c81c = *(undefined4 **)((int)_Dst + -0x18);
        }
        _memset(_Dst,-0x20202021,_Size);
        bVar11 = DAT_0077248f == '\0';
        *puVar10 = 0xdfdfdfdf;
        *(undefined4 *)((int)_Dst + -4) = 0xdfdfdfdf;
        *(undefined4 *)(_Size + 0x1c + (int)puVar10) = 0xdfdfdfdf;
        if ((((bVar11) || (DAT_00c1c788 == '\0')) || (puVar10 < DAT_00c3c7cc)) ||
           ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar10)) {
          FUN_006df631(puVar10);
        }
        else {
          FUN_006b8c20();
        }
      }
      else {
LAB_0055b94d:
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",_Dst,iVar5);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8 = 0xffffffff;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      uVar7 = 0;
    }
    *puVar6 = uVar7;
  }
  uVar2 = puVar6[1];
  uVar3 = uVar2 + -iVar4;
  puVar6[1] = uVar3;
  if (-iVar4 == 1) {
    if (uVar2 < uVar3) goto LAB_0055ba91;
  }
  else if (-1 < (int)uVar2) goto LAB_0055ba91;
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
LAB_0055ba91:
  *(undefined8 *)(iVar8 + 0xa088) = 0;
  FUN_00565850();
  FUN_0043e3c0();
  *(undefined8 *)(iVar8 + 0xa080) = local_2c;
  FUN_0047de00(extraout_ECX_00);
  FUN_0047e050(extraout_ECX_01);
  *(undefined1 *)(iVar8 + 0x88) = 0;
  iVar8 = FUN_00501450();
  if ((*(int *)(iVar8 + 0x8194) != 0) &&
     (iVar8 = *(int *)(*(int *)(iVar8 + 0x8194) + 0xdc), iVar8 != 0)) {
    *(undefined1 *)(iVar8 + 0x6c) = 0;
    *(undefined4 *)(iVar8 + 0x70) = 0;
    *(undefined4 *)(iVar8 + 0x84) = 0;
    *(undefined4 *)(iVar8 + 0x88) = 0x3f800000;
    *(undefined4 *)(iVar8 + 0x44) = 1;
    *(undefined4 *)(iVar8 + 0x7c) = 0xffffffff;
    *(undefined4 *)(iVar8 + 0x80) = 0xffffffff;
    *(undefined4 *)(iVar8 + 0x68) = 0xffffffff;
    FUN_0051bfb0(0);
    FUN_0051bcb0(0);
    FUN_0051bc40(0);
  }
  ExceptionList = local_10;
  return;
}

