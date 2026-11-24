
undefined1 FUN_0050c2b0(undefined4 *param_1)

{
  uint uVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *this;
  code *pcVar7;
  float fVar8;
  int *piVar9;
  undefined4 uVar10;
  int local_28;
  int *local_24;
  float local_20;
  int local_1c;
  float local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar5 = DAT_00772378;
  puStack_c = &LAB_0070134d;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_11 = (char)this[0x1b];
  if (*(char *)(DAT_00772400 + 0x3c9) == '\0') {
    iVar6 = param_1[2];
    if ((iVar6 < 0) || (*(int *)(DAT_00772378 + 0xc) <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar9 = *(int **)(iVar5 + 8);
    }
    else {
      piVar9 = (int *)(*(int *)(DAT_00772378 + 8) + iVar6 * 4);
    }
    if (*(int *)(*piVar9 + 8) == 0) {
      this->c_1b =
           ABS((float)this[0x17] - (float)(int)param_1[10]) +
           ABS((float)this[0x16] - (float)(int)param_1[9]) < 20.0;
    }
    iVar5 = FUN_00501450(uVar4);
    if ((*(int **)(iVar5 + 0x8198) == this) &&
       ((iVar5 = FUN_00501450(), *(int *)(iVar5 + 0x81a4) == 0 ||
        (iVar5 = FUN_00501450(), *(int **)(iVar5 + 0x81a4) == this)))) {
      cVar2 = (char)this[0x1b];
    }
    else {
      this->c_1b = 0;
      cVar2 = '\0';
    }
    if ((*(char *)((int)this + 0x55) != '\0') || ((char)this[0x15] != '\0')) {
      this->c_1b = 0;
      cVar2 = '\0';
    }
    if (cVar2 != local_11) {
      FUN_00504ee0();
    }
    pcVar7 = GetAsyncKeyState_exref;
    if ((param_1[2] == DAT_00772388) && (param_1[6] == this[0x3a])) {
      if ((*(int *)(DAT_00772400 + 0xa0c8) != 0) &&
         (local_18 = 0.0, 0 < *(int *)(DAT_00772400 + 0xa0c8))) {
        do {
          iVar5 = FUN_005e3690(local_18);
          if ((*(int *)(iVar5 + 0x3e0) != 0) || (*(int *)(iVar5 + 0x3e4) != 0)) {
            *(uint *)(iVar5 + 0x3d0) = *(uint *)(iVar5 + 0x3d0) ^ 0x800000;
            (**(code **)(*this + 0x24))();
          }
          local_18 = (float)((int)local_18 + 1);
        } while ((int)local_18 < *(int *)(DAT_00772400 + 0xa0c8));
      }
      local_11 = 1;
      goto LAB_0050ca94;
    }
    local_11 = '\0';
    uVar3 = GetAsyncKeyState(0x21);
    if ((uVar3 & 1) != 0) {
      FUN_0050c1d0();
      FUN_0050c240();
      local_11 = '\x01';
    }
    uVar3 = GetAsyncKeyState(0x22);
    if ((uVar3 & 1) != 0) {
      FUN_0050c1d0();
      FUN_0050c240();
      local_11 = '\x01';
    }
    uVar3 = GetAsyncKeyState(0x2d);
    if ((((uVar3 & 1) != 0) && (this[0x3a] != 0)) &&
       (iVar5 = 0, pcVar7 = GetAsyncKeyState_exref, 0 < *(int *)(DAT_00772400 + 0xa0c8))) {
      do {
        iVar6 = FUN_005e3690(iVar5);
        if ((iVar6 != 0) && ((*(int *)(iVar6 + 0x3e0) != 0 || (*(int *)(iVar6 + 0x3e4) != 0)))) {
          *(uint *)(iVar6 + 0x3d0) = *(uint *)(iVar6 + 0x3d0) & 0xff7fffff;
          FUN_00504ee0();
          (**(code **)(*this + 0x24))();
        }
        iVar5 = iVar5 + 1;
        pcVar7 = GetAsyncKeyState_exref;
      } while (iVar5 < *(int *)(DAT_00772400 + 0xa0c8));
    }
    uVar4 = (*pcVar7)(0x2e);
    if ((((uVar4 & 1) != 0) && (this[0x3a] != 0)) &&
       (iVar5 = 0, 0 < *(int *)(DAT_00772400 + 0xa0c8))) {
      do {
        iVar6 = FUN_005e3690(iVar5);
        if ((iVar6 != 0) && ((*(int *)(iVar6 + 0x3e0) != 0 || (*(int *)(iVar6 + 0x3e4) != 0)))) {
          *(uint *)(iVar6 + 0x3d0) = *(uint *)(iVar6 + 0x3d0) | 0x800000;
          FUN_00504ee0();
          (**(code **)(*this + 0x24))();
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(DAT_00772400 + 0xa0c8));
    }
    iVar6 = DAT_00772400;
    iVar5 = param_1[2];
    cVar2 = local_11;
    if ((iVar5 == DAT_007723c4) &&
       (ABS((float)this[0x17] - (float)(int)param_1[10]) +
        ABS((float)this[0x16] - (float)(int)param_1[9]) < 20.0)) {
      fVar8 = (float)this[0x12] + 0.083333336;
      this[0x12] = (int)fVar8;
      if (fVar8 != -1.0) {
        while (fVar8 < 0.0) {
          fVar8 = (float)this[0x12] + 1.0;
          this[0x12] = (int)fVar8;
        }
      }
      while (1.0 <= fVar8) {
        fVar8 = (float)this[0x12] - 1.0;
        this[0x12] = (int)fVar8;
      }
      fVar8 = (float)this[0x13] + 0.083333336;
      this[0x13] = (int)fVar8;
      if (fVar8 != -1.0) {
        while (fVar8 < 0.0) {
          fVar8 = (float)this[0x13] + 1.0;
          this[0x13] = (int)fVar8;
        }
      }
      while (1.0 <= fVar8) {
        fVar8 = (float)this[0x13] - 1.0;
        this[0x13] = (int)fVar8;
      }
      iVar5 = param_1[2];
      cVar2 = '\x01';
    }
    if ((iVar5 != DAT_007723cc) ||
       (20.0 <= ABS((float)this[0x17] - (float)(int)param_1[10]) +
                ABS((float)this[0x16] - (float)(int)param_1[9]))) {
      if (cVar2 == '\0') {
        if (iVar5 == DAT_007723c4) {
          *(undefined1 *)((int)this + 0x55) = 1;
          fVar8 = (float)FUN_00501450();
          local_20 = fVar8;
          local_24 = (int *)FUN_0042f510();
          if (*(int **)((int)fVar8 + 0xc) <= local_24) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(int **)(*(int *)((int)fVar8 + 8) + (int)local_24 * 4) = this;
          local_11 = 1;
          *(int **)((int)local_20 + 0x81a4) = this;
          goto LAB_0050ca94;
        }
        if (iVar5 == DAT_007723c8) {
          uVar10 = 0;
          *(undefined1 *)((int)this + 0x55) = 0;
          FUN_00501450(0);
          FUN_00501f80(uVar10);
          local_11 = 1;
          goto LAB_0050ca94;
        }
        if (iVar5 == DAT_007723a0) {
          if (param_1[6] == this[0x1c]) {
            this->c_15 = 1;
            local_11 = 1;
            goto LAB_0050ca94;
          }
          if (param_1[6] == this[0x1d]) {
            *(undefined1 *)((int)this + 0x55) = 1;
            local_11 = 1;
            goto LAB_0050ca94;
          }
        }
        if ((iVar5 == DAT_00772388) || (iVar5 == DAT_0077239c)) {
          if (param_1[6] == this[0x1c]) {
            this->c_15 = 0;
            local_11 = 1;
            goto LAB_0050ca94;
          }
          if (param_1[6] == this[0x1d]) {
            *(undefined1 *)((int)this + 0x55) = 0;
            local_11 = 1;
            goto LAB_0050ca94;
          }
        }
        iVar5 = FUN_004ed740();
        if (iVar5 == 0) {
          local_11 = 1;
          goto LAB_0050ca94;
        }
        goto LAB_0050ca8f;
      }
    }
    else {
      fVar8 = (float)this[0x12] + 0.9166667;
      this[0x12] = (int)fVar8;
      if (fVar8 != -1.0) {
        while (fVar8 < 0.0) {
          fVar8 = (float)this[0x12] + 1.0;
          this[0x12] = (int)fVar8;
        }
      }
      while (1.0 <= fVar8) {
        fVar8 = (float)this[0x12] - 1.0;
        this[0x12] = (int)fVar8;
      }
      fVar8 = (float)this[0x13] + 0.9166667;
      this[0x13] = (int)fVar8;
      if (fVar8 != -1.0) {
        while (fVar8 < 0.0) {
          fVar8 = (float)this[0x13] + 1.0;
          this[0x13] = (int)fVar8;
        }
      }
      while (1.0 <= fVar8) {
        fVar8 = (float)this[0x13] - 1.0;
        this[0x13] = (int)fVar8;
      }
    }
    local_18 = (float)this[0x12];
    local_20 = (float)this[0x13] - local_18;
    if (local_20 < 0.0) {
      local_20 = local_20 + 1.0;
    }
    uVar4 = 0;
    if (0 < *(int *)(iVar6 + 0xa0c8)) {
      do {
        local_24 = (int *)(iVar6 + 0xa0c4);
        if ((-1 < (int)uVar4) && ((int)uVar4 < (int)*(uint *)(iVar6 + 0xa0c8))) {
          if (*(uint *)(iVar6 + 0xa0c8) <= uVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = DAT_00772400;
          }
          uVar1 = *(uint *)(*local_24 + uVar4 * 4);
          local_24 = (int *)(DAT_0077244c + 0x488);
          if (uVar1 < 0x2000) {
            piVar9 = local_24 + uVar1;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar9 = local_24;
            iVar6 = DAT_00772400;
          }
          iVar5 = *piVar9;
          if ((iVar5 != 0) && ((*(int *)(iVar5 + 0xe8) == 1 || (*(int *)(iVar5 + 0xe8) == 0xb)))) {
            *(float *)(iVar5 + 0x354) = local_18 * 12.0;
            *(float *)(iVar5 + 0x358) = local_20 * 12.0;
          }
        }
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < *(int *)(iVar6 + 0xa0c8));
      local_18 = (float)this[0x12];
    }
    local_20 = (float)this[0x18] + 10.0;
    fVar8 = (local_18 + local_18) * 3.1415927 - 1.5707964;
    local_18 = fVar8;
    FUN_004089f0();
    local_28 = (int)(float)this[0x16] + -0xe + (int)(fVar8 * local_20);
    fVar8 = local_18;
    FUN_004089d0();
    local_24 = (int *)((int)(float)this[0x17] + -0xe + (int)(fVar8 * local_20));
    FUN_00504a70(&local_28);
    local_20 = (float)this[0x18] + 10.0;
    piVar9 = (int *)(((float)this[0x13] + (float)this[0x13]) * 3.1415927 - 1.5707964);
    local_24 = piVar9;
    FUN_004089f0();
    local_1c = (int)(float)this[0x16] + -0xe + (int)((float)piVar9 * local_20);
    piVar9 = local_24;
    FUN_004089d0();
    local_18 = (float)((int)(float)this[0x17] + -0xe + (int)((float)piVar9 * local_20));
    FUN_00504a70(&local_1c);
    FUN_00504ee0();
    local_11 = 1;
  }
  else {
LAB_0050ca8f:
    local_11 = 0;
  }
LAB_0050ca94:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = param_1[1] + -1;
    param_1[1] = iVar5;
    UNLOCK();
    if ((iVar5 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
      ExceptionList = local_10;
      return local_11;
    }
  }
  ExceptionList = local_10;
  return local_11;
}

