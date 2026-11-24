
/* WARNING: Removing unreachable block (ram,0x004cd561) */
/* WARNING: Removing unreachable block (ram,0x004cd578) */
/* WARNING: Removing unreachable block (ram,0x004cd5dd) */
/* WARNING: Removing unreachable block (ram,0x004cd5e4) */
/* WARNING: Removing unreachable block (ram,0x004cd5ea) */
/* WARNING: Removing unreachable block (ram,0x004cd5f1) */
/* WARNING: Removing unreachable block (ram,0x004cd5f7) */
/* WARNING: Removing unreachable block (ram,0x004cd5ff) */
/* WARNING: Removing unreachable block (ram,0x004cd607) */
/* WARNING: Removing unreachable block (ram,0x004cd639) */
/* WARNING: Removing unreachable block (ram,0x004cd642) */
/* WARNING: Removing unreachable block (ram,0x004cd64c) */
/* WARNING: Removing unreachable block (ram,0x004cd660) */
/* WARNING: Removing unreachable block (ram,0x004cd657) */
/* WARNING: Removing unreachable block (ram,0x004cd593) */
/* WARNING: Removing unreachable block (ram,0x004cd59d) */
/* WARNING: Removing unreachable block (ram,0x004cd5ba) */
/* WARNING: Removing unreachable block (ram,0x004cd5c7) */
/* WARNING: Removing unreachable block (ram,0x004cd844) */
/* WARNING: Removing unreachable block (ram,0x004cd85b) */
/* WARNING: Removing unreachable block (ram,0x004cd8c0) */
/* WARNING: Removing unreachable block (ram,0x004cd8c7) */
/* WARNING: Removing unreachable block (ram,0x004cd8cd) */
/* WARNING: Removing unreachable block (ram,0x004cd8d4) */
/* WARNING: Removing unreachable block (ram,0x004cd8da) */
/* WARNING: Removing unreachable block (ram,0x004cd8e2) */
/* WARNING: Removing unreachable block (ram,0x004cd8ea) */
/* WARNING: Removing unreachable block (ram,0x004cd91c) */
/* WARNING: Removing unreachable block (ram,0x004cd925) */
/* WARNING: Removing unreachable block (ram,0x004cd92f) */
/* WARNING: Removing unreachable block (ram,0x004cd943) */
/* WARNING: Removing unreachable block (ram,0x004cd93a) */
/* WARNING: Removing unreachable block (ram,0x004cd876) */
/* WARNING: Removing unreachable block (ram,0x004cd880) */
/* WARNING: Removing unreachable block (ram,0x004cd89d) */
/* WARNING: Removing unreachable block (ram,0x004cd8aa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004cd020(CSceneRenderer *this)

{
  byte *pbVar1;
  char cVar2;
  char cVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  char cVar13;
  uint uVar12;
  byte *pbVar14;
  int *piVar15;
  undefined4 *puVar16;
  bool bVar17;
  undefined3 uStack00000004;
  undefined3 uStack00000008;
  int *in_stack_0000000c;
  undefined3 uStack00000010;
  char cStack00000013;
  int *in_stack_00000014;
  undefined4 uVar18;
  int local_a8;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_6c;
  void *local_68;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  undefined **local_44;
  undefined8 local_3c;
  undefined8 local_34;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  CSceneRenderer *local_1c;
  byte *local_18;
  byte *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006feb5b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar12 = 1 << ((uint)_uStack00000004 & 0x1f) | 1 << ((uint)_uStack00000008 & 0x1f) |
           1 << ((uint)in_stack_0000000c & 0x1f) | 1 << ((uint)_uStack00000010 & 0x1f);
  local_1c = this;
  if ((int)uVar12 < 7) {
    local_14 = (byte *)in_stack_0000000c;
    local_18 = (byte *)_uStack00000008;
    if (((uVar12 == 1) || (uVar12 == 2)) || (uVar12 == 4)) {
      uVar18 = FUN_004cd9d0(this);
      ExceptionList = local_10;
      return uVar18;
    }
  }
  else {
    piVar5 = (int *)0x0;
    if (_uStack00000004 != (int *)0x2) {
      piVar5 = _uStack00000004;
    }
    local_18 = (byte *)(int *)0x0;
    if (_uStack00000008 != (int *)0x2) {
      local_18 = (byte *)_uStack00000008;
    }
    local_14 = (byte *)(int *)0x0;
    if (in_stack_0000000c != (int *)0x2) {
      local_14 = (byte *)in_stack_0000000c;
    }
    _uStack00000004 = piVar5;
    if (_uStack00000010 == (int *)0x2) {
      _uStack00000010 = (int *)0x0;
    }
  }
  FUN_006b8f50(DAT_0076700c ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  cVar13 = (char)_uStack00000004 + 'A';
  cVar11 = cVar13;
  if (local_18 != (byte *)_uStack00000004) {
    cVar11 = (char)local_18 + 'A';
  }
  local_18 = (byte *)(uint)(local_18 != (byte *)_uStack00000004);
  if (local_14 != (byte *)_uStack00000004) {
    cVar11 = (char)local_14 + 'A';
  }
  local_14 = (byte *)(uint)(local_14 != (byte *)_uStack00000004);
  if (_uStack00000010 != _uStack00000004) {
    cVar11 = (char)_uStack00000010 + 'A';
  }
  uVar12 = (uint)(_uStack00000010 != _uStack00000004);
  cVar2 = cVar11;
  cVar3 = cVar13;
  if (cVar11 < cVar13) {
    local_18 = (byte *)(1 - (int)local_18);
    local_14 = (byte *)(1 - (int)local_14);
    uVar12 = 1 - uVar12;
    cVar2 = cVar13;
    cVar3 = cVar11;
  }
  _uStack00000008 = (int *)CONCAT13(cVar3,uStack00000008);
  _uStack00000004 = (int *)CONCAT13(cVar2,uStack00000004);
  FUN_006b9040(&stack0x0000000c,"ground/Msk_%c%c%c%c01.tga",(cVar11 < cVar13) + 'A',local_18 + 0x41,
               (int)local_14 + 0x41,uVar12 + 0x41);
  local_7c = 0;
  local_78 = 0;
  local_6c = 0;
  local_68 = (void *)0x0;
  local_44 = CTimeInc::vftable;
  local_3c = 0;
  local_34 = 0;
  local_8._0_1_ = 4;
  FUN_00449180();
  piVar5 = in_stack_0000000c;
  FUN_004402c0();
  piVar15 = local_2c;
  local_8._0_1_ = 5;
  cVar11 = FUN_006c0370(local_2c + 3);
  if (cVar11 == '\0') {
    FUN_00449180();
    _DAT_0077234c = _DAT_0077234c + (int)local_34;
    local_14 = (byte *)0x0;
  }
  else {
    local_14 = (byte *)0x0;
    FUN_006b9040(&stack0x0000000c,"ground/Gnd_%c%c%c.tga",(int)cVar3,0x30,0x31);
    FUN_00449180();
    piVar5 = in_stack_0000000c;
    piVar6 = (int *)FUN_004402c0();
    local_8._0_1_ = 8;
    cVar11 = FUN_006c0370(*piVar6 + 0xc);
    _uStack00000010 = (int *)CONCAT13(cVar11,uStack00000010);
    local_8._0_1_ = 9;
    if ((_uStack00000008 != (int *)0x0) &&
       (*_uStack00000008 = *_uStack00000008 + -1, *_uStack00000008 == 0)) {
      FUN_006ba940();
      cVar11 = cStack00000013;
    }
    local_8._0_1_ = 5;
    if (cVar11 != '\0') {
      FUN_00449180();
      _DAT_0077234c = _DAT_0077234c + (int)local_34;
      FUN_006b9040(&stack0x0000000c,"ground/Gnd_%c%02d.tga",(int)cVar2,1);
      FUN_00449180();
      piVar5 = in_stack_0000000c;
      piVar6 = (int *)FUN_004402c0();
      local_8._0_1_ = 10;
      cVar11 = FUN_006c0370(*piVar6 + 0xc);
      _uStack00000010 = (int *)CONCAT13(cVar11,uStack00000010);
      local_8._0_1_ = 0xb;
      if ((_uStack00000004 != (int *)0x0) &&
         (*_uStack00000004 = *_uStack00000004 + -1, *_uStack00000004 == 0)) {
        FUN_006ba940();
        cVar11 = cStack00000013;
      }
      local_8._0_1_ = 5;
      if (cVar11 != '\0') {
        FUN_00449180();
        local_54 = 3;
        _DAT_0077234c = _DAT_0077234c + (int)local_34;
        local_50 = 3;
        _uStack00000010 = (int *)0x3;
        if (local_a8 != 0) {
          _uStack00000010 = (int *)0x4;
        }
        if (local_58 != 0) {
          local_50 = 4;
        }
        if (local_80 != 0) {
          local_54 = 4;
        }
        pbVar14 = (byte *)0x0;
        local_18 = (byte *)0x0;
        _uStack00000004 = (int *)0x0;
        local_14 = (byte *)0x0;
        FUN_00449180();
        local_28 = 0x1000;
        do {
          pbVar1 = local_14 + (int)_uStack00000010;
          uVar12 = (uint)*local_14;
          local_48 = (uint)pbVar14[2];
          pbVar7 = (byte *)((int)local_68 + (int)_uStack00000004);
          local_24 = 0xff - uVar12;
          iVar10 = *pbVar7 * uVar12 + (uint)*pbVar14 * local_24;
          iVar10 = iVar10 + (iVar10 >> 0x1f & 0xffU);
          local_4c = iVar10 >> 8;
          iVar8 = pbVar7[1] * uVar12 + (uint)pbVar14[1] * local_24;
          iVar8 = iVar8 + (iVar8 >> 0x1f & 0xffU);
          local_20 = iVar8 >> 8;
          iVar9 = pbVar7[2] * uVar12 + local_48 * local_24;
          *pbVar7 = (byte)((uint)iVar10 >> 8);
          *(char *)((int)local_68 + (int)_uStack00000004 + 1) = (char)((uint)iVar8 >> 8);
          *(char *)((int)local_68 + (int)_uStack00000004 + 2) =
               (char)((iVar9 >> 0x1f & 0xffU) + iVar9 >> 8);
          _uStack00000004 = (int *)((int)_uStack00000004 + local_50);
          pbVar14 = local_18 + local_54;
          local_28 = local_28 + -1;
          local_18 = pbVar14;
          local_14 = pbVar1;
        } while (local_28 != 0);
        _uStack00000010 = (int *)uVar12;
        FUN_00449180();
        _DAT_00772348 = _DAT_00772348 + (int)local_34;
        local_14 = (byte *)0x1;
        FUN_004ce570(local_1c);
        _uStack00000010 = (int *)(local_1c->textureCount - 1);
        if ((uint)local_1c->textureCount <= _uStack00000010) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        _uStack00000010 = (int *)((int)local_1c->textures + (int)_uStack00000010 * 4);
        puVar16 = &local_7c;
        uVar18 = 1;
        FUN_0044d010(1,puVar16);
        iVar10 = FUN_0044c110(uVar18,puVar16);
        *_uStack00000010 = iVar10;
        *in_stack_00000014 = *in_stack_00000014 + 1;
        piVar5 = in_stack_0000000c;
        piVar15 = local_2c;
      }
    }
  }
  local_8._0_1_ = 0xc;
  if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd;
  _uStack00000010 = (int *)0x0;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  pvVar4 = local_68;
  local_8 = CONCAT31(local_8._1_3_,0xe);
  _uStack00000010 = (int *)local_68;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  if (pvVar4 != (void *)0x0) {
    LOCK();
    _DAT_00c3c818 = _DAT_00c3c818 + 1;
    UNLOCK();
    puVar16 = (undefined4 *)((int)pvVar4 + -0x1c);
    iVar10 = FUN_006ba730();
    if (iVar10 == 0) {
      in_stack_00000014 = *(int **)((int)pvVar4 + -8);
      piVar15 = in_stack_00000014 + 7;
      iVar10 = FUN_006ba730();
      if (iVar10 == 0) {
        if (*(int *)((int)pvVar4 + -0x14) != 0) {
          *(undefined4 *)(*(int *)((int)pvVar4 + -0x14) + 4) = *(undefined4 *)((int)pvVar4 + -0x18);
        }
        if (*(int *)((int)pvVar4 + -0x18) != 0) {
          *(undefined4 *)(*(int *)((int)pvVar4 + -0x18) + 8) = *(undefined4 *)((int)pvVar4 + -0x14);
        }
        if (puVar16 == DAT_00c3c81c) {
          DAT_00c3c81c = *(undefined4 **)((int)pvVar4 + -0x18);
        }
        _memset(_uStack00000010,-0x20202021,(size_t)in_stack_00000014);
        bVar17 = DAT_0077248f == '\0';
        *puVar16 = 0xdfdfdfdf;
        *(undefined4 *)((int)pvVar4 + -4) = 0xdfdfdfdf;
        *(undefined4 *)((int)piVar15 + (int)puVar16) = 0xdfdfdfdf;
        if ((((bVar17) || (DAT_00c1c788 == '\0')) || (puVar16 < DAT_00c3c7cc)) ||
           ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar16)) {
          FUN_006df631(puVar16);
        }
        else {
          FUN_006b8c20();
        }
        goto LAB_004cd7df;
      }
    }
    if (DAT_00c3c7d4 != (FILE *)0x0) {
      FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",_uStack00000010,iVar10);
      _fflush(DAT_00c3c7d4);
    }
    if (DAT_00c3c828 != '\0') {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
LAB_004cd7df:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_7c = 0;
  local_78 = 0;
  local_6c = 0;
  local_68 = (void *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0xf);
  _uStack00000010 = (int *)0x0;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_8 = 0x10;
  if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return local_14;
}

