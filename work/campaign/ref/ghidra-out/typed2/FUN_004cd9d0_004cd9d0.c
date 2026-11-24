
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cd9d0(CSceneRenderer *this)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  undefined **ppuVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  int *piVar10;
  bool bVar11;
  int in_stack_00000004;
  uint *in_stack_00000008;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 local_474;
  undefined4 local_470;
  undefined4 local_464;
  void *local_460;
  undefined **local_44c;
  undefined8 local_444;
  undefined8 local_43c;
  int *local_434;
  int local_430;
  CSceneRenderer *local_42c;
  uint *local_428;
  int *local_424;
  int *local_420;
  int local_41c;
  int local_418;
  undefined1 local_414 [1024];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006febb1;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_428 = in_stack_00000008;
  local_474 = 0;
  local_470 = 0;
  local_464 = 0;
  local_460 = (void *)0x0;
  local_8 = 0;
  local_42c = this;
  local_434 = (int *)FUN_006ba810(0x19,local_14);
  local_434[1] = 0x14;
  local_434[2] = -1;
  *(undefined1 *)(local_434 + 3) = 0;
  *local_434 = 1;
  local_44c = CTimeInc::vftable;
  local_444 = 0;
  local_41c = 0;
  local_43c = 0;
  local_430 = in_stack_00000004 + 0x41;
  local_8._0_1_ = 2;
  local_418 = 0;
  piVar10 = local_434;
  do {
    FUN_0043ffe0(local_414,"ground/Gnd_%c%c%c.tga",local_430,(local_418 + 1) / 10 + 0x30,
                 (local_418 + 1) % 10 + 0x30);
    local_420 = (int *)FUN_004402c0();
    local_8._0_1_ = 3;
    piVar2 = (int *)*local_420;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_434 = piVar2;
    if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
      FUN_006ba940();
    }
    piVar2[2] = *(int *)(*local_420 + 8);
    local_8._0_1_ = 4;
    if ((local_424 != (int *)0x0) && (*local_424 = *local_424 + -1, *local_424 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 2;
    pbVar9 = (byte *)(piVar2 + 3);
    ppuVar4 = &PTR_0071ce50;
    do {
      bVar1 = *pbVar9;
      bVar11 = bVar1 < *(byte *)ppuVar4;
      if (bVar1 != *(byte *)ppuVar4) {
LAB_004cdb68:
        uVar5 = -(uint)bVar11 | 1;
        goto LAB_004cdb6d;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar9[1];
      bVar11 = bVar1 < *(byte *)((int)ppuVar4 + 1);
      if (bVar1 != *(byte *)((int)ppuVar4 + 1)) goto LAB_004cdb68;
      pbVar9 = pbVar9 + 2;
      ppuVar4 = (undefined **)((int)ppuVar4 + 2);
    } while (bVar1 != 0);
    uVar5 = 0;
LAB_004cdb6d:
    if (uVar5 == 0) {
      if (2 < local_418) break;
    }
    else {
      FUN_00449180();
      cVar3 = FUN_006c0370(piVar2 + 3);
      if (cVar3 != '\0') {
        FUN_00449180();
        uVar5 = this->textureCount;
        _DAT_0077234c = _DAT_0077234c + (int)local_43c;
        local_41c = local_41c + 1;
        if ((uVar5 + 0x10 & 0xfffffff0) != (uVar5 + 0xf & 0xfffffff0)) {
          pvVar6 = (void *)FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                        ,0x9b);
          uVar5 = this->textureCount;
          this->textures = pvVar6;
        }
        uVar7 = uVar5 + 1;
        this->textureCount = uVar7;
        if (uVar7 <= uVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar7 = this->textureCount;
        }
        uVar5 = *local_428;
        if (uVar7 <= uVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        pvVar6 = local_42c->textures;
        puVar13 = &local_474;
        uVar12 = 1;
        FUN_0044d010(1,puVar13);
        uVar12 = FUN_0044c110(uVar12,puVar13);
        *(undefined4 *)((int)pvVar6 + uVar5 * 4) = uVar12;
        *local_428 = *local_428 + 1;
        this = local_42c;
      }
    }
    local_418 = local_418 + 1;
    piVar10 = piVar2;
  } while (local_418 < 0xf);
  local_8 = CONCAT31(local_8._1_3_,5);
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  pvVar6 = local_460;
  local_8 = 6;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  if (pvVar6 != (void *)0x0) {
    LOCK();
    _DAT_00c3c818 = _DAT_00c3c818 + 1;
    UNLOCK();
    puVar13 = (undefined4 *)((int)pvVar6 + -0x1c);
    iVar8 = FUN_006ba730();
    if (iVar8 == 0) {
      local_424 = *(int **)((int)pvVar6 + -8);
      local_420 = (int *)((int)(local_424 + 7) + (int)puVar13);
      iVar8 = FUN_006ba730();
      if (iVar8 == 0) {
        if (*(int *)((int)pvVar6 + -0x14) != 0) {
          *(undefined4 *)(*(int *)((int)pvVar6 + -0x14) + 4) = *(undefined4 *)((int)pvVar6 + -0x18);
        }
        if (*(int *)((int)pvVar6 + -0x18) != 0) {
          *(undefined4 *)(*(int *)((int)pvVar6 + -0x18) + 8) = *(undefined4 *)((int)pvVar6 + -0x14);
        }
        if (puVar13 == DAT_00c3c81c) {
          DAT_00c3c81c = *(undefined4 **)((int)pvVar6 + -0x18);
        }
        _memset(pvVar6,-0x20202021,(size_t)local_424);
        bVar11 = DAT_0077248f == '\0';
        *puVar13 = 0xdfdfdfdf;
        *(undefined4 *)((int)pvVar6 + -4) = 0xdfdfdfdf;
        *local_420 = -0x20202021;
        if ((((bVar11) || (DAT_00c1c788 == '\0')) || (puVar13 < DAT_00c3c7cc)) ||
           ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar13)) {
          FUN_006df631(puVar13);
        }
        else {
          FUN_006b8c20();
        }
        goto LAB_004cddf2;
      }
    }
    if (DAT_00c3c7d4 != (FILE *)0x0) {
      FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pvVar6,iVar8);
      _fflush(DAT_00c3c7d4);
    }
    if (DAT_00c3c828 != '\0') {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
LAB_004cddf2:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

