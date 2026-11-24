
char __thiscall FUN_004c8480(CSceneRenderer *this)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  undefined4 *puVar15;
  CMap *this_00;
  char cVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  char cVar21;
  int iVar20;
  uint uVar22;
  void *pvVar23;
  int *piVar24;
  ushort uVar25;
  char *pcVar26;
  int *piVar27;
  char cStack00000007;
  int iStack00000008;
  void *local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fea65;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar16 = FUN_004c8220(this);
  if (cVar16 != '\0') {
    if (this->flag3 == '\0') {
      iVar20 = FUN_00592f10(PTR_0077241c);
      uVar25 = *(ushort *)(iVar20 + 0x18) & 3;
      iVar20 = FUN_00592f10(PTR_0077241c);
      uVar17 = *(ushort *)(iVar20 + 0x18) & 3;
      iVar20 = FUN_00592f10(PTR_0077241c);
      uVar18 = *(ushort *)(iVar20 + 0x18) & 3;
      iVar20 = FUN_00592f10(PTR_0077241c);
      uVar19 = *(ushort *)(iVar20 + 0x18) & 3;
      if ((((uVar25 == 3) || (uVar17 == 3)) || (uVar18 == 3)) || (uVar19 == 3)) {
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar16 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar1 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar2 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar3 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar4 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar5 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar6 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar7 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar8 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar9 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar10 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar11 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar12 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar13 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar14 = *pcVar26;
        uVar22 = *(uint *)this;
        iVar20 = FUN_00592f10(PTR_0077241c);
        pcVar26 = (char *)(iVar20 + 0x34);
        if (uVar22 < 8) {
          pcVar26 = pcVar26 + uVar22;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar21 = cVar5;
        if (((uVar25 == 3) &&
            ((((cVar16 != '\0' || (cVar1 != '\0')) ||
              ((cVar2 != '\0' || ((cVar4 != '\0' || (cVar5 != '\0')))))) ||
             ((cVar21 = '\0', cVar6 != '\0' ||
              (((cVar8 != '\0' || (cVar9 != '\0')) || (cVar10 != '\0')))))))) ||
           (((uVar17 == 3 &&
             ((((cVar1 != '\0' || (cVar2 != '\0')) ||
               (((cVar3 != '\0' || ((cVar21 != '\0' || (cVar6 != '\0')))) || (cVar7 != '\0')))) ||
              (((cVar9 != '\0' || (cVar10 != '\0')) || (cVar11 != '\0')))))) ||
            (((uVar18 == 3 &&
              (((((cVar4 != '\0' || (cVar21 != '\0')) ||
                 ((cVar6 != '\0' || ((cVar8 != '\0' || (cVar9 != '\0')))))) || (cVar10 != '\0')) ||
               (((cVar12 != '\0' || (cVar13 != '\0')) || (cVar14 != '\0')))))) ||
             ((uVar19 == 3 &&
              (((cVar5 != '\0' || (cVar6 != '\0')) ||
               (((cVar7 != '\0' || ((cVar9 != '\0' || (cVar10 != '\0')))) ||
                ((cVar11 != '\0' || (((cVar13 != '\0' || (cVar14 != '\0')) || (*pcVar26 != '\0')))))
                ))))))))))) {
          this->flag3 = '\x01';
        }
      }
    }
    this_00 = PTR_0077241c;
    this->statC = this->statC + 1;
    iVar20 = FUN_00592f10(this_00);
    uVar17 = *(ushort *)(iVar20 + 4);
    if (uVar17 == 0xffff) {
      local_24 = (void *)FUN_004ca830(this);
      cStack00000007 = *(char *)((int)local_24 + 0x18);
      if ((cStack00000007 == '\0') && (*(char *)((int)local_24 + 0x14) == '\0')) {
        this->statD = this->statD + 1;
      }
    }
    else {
      uVar22 = (uint)uVar17;
      if ((int)uVar22 < this->holeCount) {
        local_24 = (void *)((int)this->holesData + uVar22 * 0x1c);
        pvVar23 = (void *)((int)this->holesData + uVar22 * 0x1c);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        local_24 = this->holesData;
        if ((int)(uint)uVar17 < this->holeCount) {
          pvVar23 = (void *)((int)local_24 + (uint)uVar17 * 0x1c);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pvVar23 = this->holesData;
        }
      }
      *(int *)((int)pvVar23 + 0x18) = this->holeTail;
      this->statE = this->statE + 1;
      cStack00000007 = '\0';
    }
    piVar27 = (int *)((int)local_24 + 8);
    uVar22 = 0;
    iStack00000008 = 0;
    do {
      if (uVar22 < 3) {
        piVar24 = (int *)(iStack00000008 + (int)piVar27);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar24 = piVar27;
      }
      if (*piVar24 != 0) {
        if (uVar22 < 3) {
          piVar24 = (int *)((int)piVar27 + iStack00000008);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar24 = piVar27;
        }
        puVar15 = (undefined4 *)*piVar24;
        if (puVar15 != (undefined4 *)0x0) {
          LOCK();
          puVar15[1] = puVar15[1] + 1;
          UNLOCK();
        }
        local_8 = 0;
        FUN_0044d010();
        local_8 = 1;
        if (puVar15 != (undefined4 *)0x0) {
          LOCK();
          puVar15[1] = puVar15[1] + 1;
          UNLOCK();
        }
        FUN_00450720(puVar15);
        local_8 = 0xffffffff;
        if (puVar15 != (undefined4 *)0x0) {
          LOCK();
          iVar20 = puVar15[1] + -1;
          puVar15[1] = iVar20;
          UNLOCK();
          if (iVar20 == 0) {
            (**(code **)*puVar15)(1);
          }
        }
      }
      uVar22 = uVar22 + 1;
      iStack00000008 = iStack00000008 + 4;
    } while ((int)uVar22 < 3);
    if (uVar17 == 0xffff) {
      if ((cStack00000007 == '\0') && (*(char *)((int)local_24 + 0x14) == '\0')) {
        FUN_004c8ee0(this);
      }
      if (local_24 != (void *)0x0) {
        local_8 = 2;
        _eh_vector_destructor_iterator_(piVar27,4,3,FUN_00406f00);
        FUN_006cecd8(local_24,0x1c);
      }
    }
    ExceptionList = local_10;
    return cStack00000007;
  }
  ExceptionList = local_10;
  return '\0';
}

