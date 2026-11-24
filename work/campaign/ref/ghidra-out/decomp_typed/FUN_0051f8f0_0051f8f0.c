
void FUN_0051f8f0(void)

{
  int *piVar1;
  void *pvVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  char *_Mode;
  FILE *_File;
  DWORD DVar7;
  int iVar8;
  int this;
  int *piVar9;
  float fVar10;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar2 = ExceptionList;
  iVar8 = DAT_00772400;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00702195;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (this->i_44 == 0) {
    return;
  }
  ExceptionList = &local_10;
  if (*(char *)(DAT_00772400 + 0x590) != '\0') {
    if (this->c_88 == '\0') {
      fVar10 = this->f_84 - 10.5;
      this->f_84 = fVar10;
      if (fVar10 < 10.0) {
        this->c_88 = 1;
      }
    }
    else {
      fVar10 = this->f_84 + 20.5;
      this->f_84 = fVar10;
      if (240.0 < fVar10) {
        this->c_88 = 0;
      }
    }
    iVar6 = (int)fVar10;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (0xff < iVar6) {
      iVar6 = 0xff;
    }
    local_18 = (float)CONCAT13(0xff,CONCAT12((char)iVar6,0xa0a));
    *(float *)(this->i_54 + 0x48) = local_18;
  }
  this->i_7c = this->i_7c + 1;
  iVar6 = DAT_0077244c;
  if (this->i_7c < 0xb) {
    if (*(char *)(iVar8 + 0x590) == '\0') {
      ExceptionList = pvVar2;
      return;
    }
    FUN_00504ee0(uVar5);
    ExceptionList = local_10;
    return;
  }
  this->i_7c = 0;
  iVar8 = *(int *)(iVar6 + 0x84b5);
  local_18 = (float)iVar8;
  if (DAT_007683b6 != '\0') {
    _Mode = "a+";
    if (this->i_8c == 0) {
      _Mode = "w";
    }
    _File = _fopen("perfstats.xls",_Mode);
    if (_File != (FILE *)0x0) {
      DVar7 = GetTickCount();
      local_14 = (int *)((float)((double)(int)DVar7 +
                                *(double *)(&DAT_00737920 + ((int)DVar7 >> 0x1f) * -8)) / 1000.0);
      if (this->i_8c == 0) {
        _fputs("Nr \tRealTime \tGameTime \tFPS \tObjcnt Vis \tObjcnt All \tRjCnt \n",_File);
        *(int **)(this + 0x90) = local_14;
      }
      else {
        FUN_006b90d0(&local_14,"%i\t%f\t%f\t%8.4f\t%i\t%i\t%i\n",this->i_8c,
                     (double)((float)local_14 - this->f_90),
                     *(undefined8 *)(DAT_00772400 + 0xa088),(double)*(float *)(DAT_00772400 + 0x1a0)
                     ,*(undefined4 *)(DAT_00772400 + 0xa324),iVar8);
        piVar9 = local_14;
        _fputs((char *)(local_14 + 3),_File);
        local_8 = 0;
        if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
          FUN_006ba940();
        }
        local_8 = 0xffffffff;
      }
      _fclose(_File);
      this->i_8c = this->i_8c + 1;
    }
  }
  local_14 = (int *)FUN_006ba810();
  local_14[1] = 0x14;
  local_14[2] = -1;
  *(undefined1 *)(local_14 + 3) = 0;
  *local_14 = 1;
  local_8 = 1;
  if ((*(char *)(DAT_00772400 + 0x590) != '\0') && (this->c_80 != '\0')) {
    fVar10 = 0.0;
    uVar5 = 2;
    local_18 = 0.0;
    do {
      piVar9 = (int *)(DAT_0077244c + 0x488);
      if (uVar5 < 0x2000) {
        piVar9 = piVar9 + uVar5;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        fVar10 = local_18;
      }
      if ((*piVar9 != 0) && ((*(byte *)(*piVar9 + 0x3d0) & 1) != 0)) {
        fVar10 = fVar10 + 1.0;
        local_18 = fVar10;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x2000);
  }
  if (DAT_00772374 == 0) {
    fVar10 = (float)((((*(int *)(DAT_0077241c + 0x90) - *(int *)(DAT_0077241c + 0x88)) +
                      *(int *)(DAT_0077241c + 0x8c)) - *(int *)(DAT_0077241c + 0x84)) / 2);
  }
  else {
    fVar10 = (((float)(*(int *)(DAT_0077241c + 0x90) - *(int *)(DAT_0077241c + 0x88)) -
              (*(float *)(DAT_00772374 + 0x198) + *(float *)(DAT_00772374 + 0x198))) +
             ((float)(*(int *)(DAT_0077241c + 0x8c) - *(int *)(DAT_0077241c + 0x84)) -
             (*(float *)(DAT_00772374 + 0x194) + *(float *)(DAT_00772374 + 0x194)))) * 0.5;
  }
  FUN_004ce740();
  local_20 = (int *)((local_18 / fVar10) * 30.0);
  FUN_006b9040();
  local_1c = this->i_54;
  piVar9 = (int *)(local_1c + 0x20);
  cVar4 = FUN_006b97f0();
  piVar3 = local_14;
  if (cVar4 == '\0') {
    piVar1 = (int *)*piVar9;
    *piVar9 = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar9 + 8) = piVar3[2];
    FUN_00504ee0();
  }
  iVar8 = this->i_54;
  if ((float)local_20 <= 100.0) {
    uVar5 = *(uint *)(iVar8 + 0x24) & 0xffffffbf;
  }
  else {
    uVar5 = *(uint *)(iVar8 + 0x24) | 0x40;
  }
  if (uVar5 != *(uint *)(iVar8 + 0x24)) {
    *(uint *)(iVar8 + 0x24) = uVar5;
    FUN_00504ee0();
  }
  FUN_006b9040(&local_14,"objcnt: %d/%d",*(undefined4 *)(DAT_00772400 + 0xa324),(int)local_18);
  local_20 = *(int **)(this + 0x44);
  piVar9 = local_20 + 8;
  cVar4 = FUN_006b97f0();
  piVar3 = local_14;
  if (cVar4 == '\0') {
    piVar1 = (int *)*piVar9;
    *piVar9 = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar9 + 8) = piVar3[2];
    FUN_00504ee0();
  }
  FUN_006b9040(&local_14,"polycnt: %d",*(undefined4 *)(DAT_00772400 + 0x24));
  local_20 = *(int **)(this + 0x48);
  piVar9 = local_20 + 8;
  cVar4 = FUN_006b97f0();
  piVar3 = local_14;
  if (cVar4 == '\0') {
    piVar1 = (int *)*piVar9;
    *piVar9 = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar9 + 8) = piVar3[2];
    FUN_00504ee0();
  }
  DAT_007687b0 = *(float *)(DAT_00772400 + 0x1a0) * 0.1 + DAT_007687b0 * 0.9;
  FUN_006b9040();
  local_20 = *(int **)(this + 0x4c);
  piVar9 = local_20 + 8;
  cVar4 = FUN_006b97f0();
  piVar3 = local_14;
  if (cVar4 == '\0') {
    piVar1 = (int *)*piVar9;
    *piVar9 = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar9 + 8) = piVar3[2];
    FUN_00504ee0();
  }
  FUN_006b9040(&local_14,"rjcnt: %d",*(undefined4 *)(DAT_00772400 + 0x78));
  local_20 = *(int **)(this + 0x50);
  piVar9 = local_20 + 8;
  cVar4 = FUN_006b97f0();
  piVar3 = local_14;
  if (cVar4 == '\0') {
    piVar1 = (int *)*piVar9;
    *piVar9 = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar9 + 8) = piVar3[2];
    FUN_00504ee0();
  }
  iVar8 = *(int *)(DAT_0077241c + 0x20);
  FUN_006b9200();
  iVar6 = 0;
  piVar9 = (int *)(iVar8 + 0x6c);
  do {
    if (0 < *piVar9) {
      FUN_006b90d0(&local_20," %d=%d",iVar6,*piVar9);
      local_8._0_1_ = 2;
      FUN_006b9290();
      local_8._0_1_ = 3;
      if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    iVar6 = iVar6 + 1;
    piVar9 = piVar9 + 1;
  } while (iVar6 < 8);
  local_20 = *(int **)(this + 0x58);
  piVar9 = local_20 + 8;
  cVar4 = FUN_006b97f0();
  piVar3 = local_14;
  if (cVar4 == '\0') {
    piVar1 = (int *)*piVar9;
    *piVar9 = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar9 + 8) = piVar3[2];
    FUN_00504ee0();
  }
  iVar8 = FUN_00492250();
  FUN_006b9040(&local_14,"psrc: %d",*(undefined4 *)(iVar8 + 0xa51));
  local_20 = *(int **)(this + 0x5c);
  piVar9 = local_20 + 8;
  cVar4 = FUN_006b97f0();
  piVar3 = local_14;
  if (cVar4 == '\0') {
    piVar1 = (int *)*piVar9;
    *piVar9 = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*piVar9 + 8) = piVar3[2];
    FUN_00504ee0();
  }
  iVar8 = this->i_60;
  if (*(char *)(DAT_0076a338 + 0x101) == '\0') {
    local_18 = 0.0;
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         ((iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == 0 ||
          (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == iVar8)))) {
        local_18 = 1.4013e-45;
      }
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x819c) != iVar8) && (local_18 == 1.4013e-45)) {
        local_18 = 0.0;
      }
      FUN_00501450();
    }
    if (local_18 != *(float *)(iVar8 + 0x48)) {
      *(float *)(iVar8 + 0x48) = local_18;
      goto LAB_0052007f;
    }
  }
  else {
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) != 0)) {
        FUN_00501450();
      }
      FUN_00501450();
      FUN_00501450();
    }
    if (*(int *)(iVar8 + 0x48) != 5) {
      *(undefined4 *)(iVar8 + 0x48) = 5;
LAB_0052007f:
      FUN_00504ee0();
    }
  }
  iVar8 = this->i_64;
  if (DAT_00768369 == '\0') {
    local_18 = 0.0;
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         ((iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == 0 ||
          (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == iVar8)))) {
        local_18 = 1.4013e-45;
      }
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x819c) != iVar8) && (local_18 == 1.4013e-45)) {
        local_18 = 0.0;
      }
      FUN_00501450();
    }
    if (local_18 != *(float *)(iVar8 + 0x48)) {
      *(float *)(iVar8 + 0x48) = local_18;
      goto LAB_00520135;
    }
  }
  else {
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) != 0)) {
        FUN_00501450();
      }
      FUN_00501450();
      FUN_00501450();
    }
    if (*(int *)(iVar8 + 0x48) != 5) {
      *(undefined4 *)(iVar8 + 0x48) = 5;
LAB_00520135:
      FUN_00504ee0();
    }
  }
  iVar8 = this->i_68;
  if (DAT_00768370 == '\0') {
    local_18 = 0.0;
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         ((iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == 0 ||
          (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == iVar8)))) {
        local_18 = 1.4013e-45;
      }
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x819c) != iVar8) && (local_18 == 1.4013e-45)) {
        local_18 = 0.0;
      }
      FUN_00501450();
    }
    if (local_18 != *(float *)(iVar8 + 0x48)) {
      *(float *)(iVar8 + 0x48) = local_18;
      goto LAB_005201eb;
    }
  }
  else {
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) != 0)) {
        FUN_00501450();
      }
      FUN_00501450();
      FUN_00501450();
    }
    if (*(int *)(iVar8 + 0x48) != 5) {
      *(undefined4 *)(iVar8 + 0x48) = 5;
LAB_005201eb:
      FUN_00504ee0();
    }
  }
  iVar8 = this->i_6c;
  if (DAT_00768378 == '\0') {
    local_18 = 0.0;
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         ((iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == 0 ||
          (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == iVar8)))) {
        local_18 = 1.4013e-45;
      }
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x819c) != iVar8) && (local_18 == 1.4013e-45)) {
        local_18 = 0.0;
      }
      FUN_00501450();
    }
    if (local_18 != *(float *)(iVar8 + 0x48)) {
      *(float *)(iVar8 + 0x48) = local_18;
      goto LAB_005202a1;
    }
  }
  else {
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) != 0)) {
        FUN_00501450();
      }
      FUN_00501450();
      FUN_00501450();
    }
    if (*(int *)(iVar8 + 0x48) != 5) {
      *(undefined4 *)(iVar8 + 0x48) = 5;
LAB_005202a1:
      FUN_00504ee0();
    }
  }
  iVar8 = this->i_70;
  if (DAT_00768371 == '\0') {
    local_18 = 0.0;
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         ((iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == 0 ||
          (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == iVar8)))) {
        local_18 = 1.4013e-45;
      }
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x819c) != iVar8) && (local_18 == 1.4013e-45)) {
        local_18 = 0.0;
      }
      FUN_00501450();
    }
    if (local_18 != *(float *)(iVar8 + 0x48)) {
      *(float *)(iVar8 + 0x48) = local_18;
      goto LAB_00520357;
    }
  }
  else {
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) != 0)) {
        FUN_00501450();
      }
      FUN_00501450();
      FUN_00501450();
    }
    if (*(int *)(iVar8 + 0x48) != 5) {
      *(undefined4 *)(iVar8 + 0x48) = 5;
LAB_00520357:
      FUN_00504ee0();
    }
  }
  iVar8 = this->i_74;
  if (*(char *)(DAT_00772400 + 0x140) == '\0') {
    local_18 = 0.0;
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         ((iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == 0 ||
          (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) == iVar8)))) {
        local_18 = 1.4013e-45;
      }
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x819c) != iVar8) && (local_18 == 1.4013e-45)) {
        local_18 = 0.0;
      }
      FUN_00501450();
    }
    if (local_18 == *(float *)(iVar8 + 0x48)) goto LAB_00520419;
    *(float *)(iVar8 + 0x48) = local_18;
  }
  else {
    if (*(char *)(iVar8 + 0x2c) != '\0') {
      iVar6 = FUN_00501450();
      if ((*(int *)(iVar6 + 0x8198) == iVar8) &&
         (iVar6 = FUN_00501450(), *(int *)(iVar6 + 0x81a4) != 0)) {
        FUN_00501450();
      }
      FUN_00501450();
      FUN_00501450();
    }
    if (*(int *)(iVar8 + 0x48) == 5) goto LAB_00520419;
    *(undefined4 *)(iVar8 + 0x48) = 5;
  }
  FUN_00504ee0();
LAB_00520419:
  FUN_00504ee0();
  local_8 = 4;
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
    FUN_006ba940();
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}

