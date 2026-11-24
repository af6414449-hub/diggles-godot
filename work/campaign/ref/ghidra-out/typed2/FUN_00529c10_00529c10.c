
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00529c10(ViWinRoot *this)

{
  byte bVar1;
  uint *puVar2;
  ViWinRoot *pVVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  char cVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  BOOL BVar14;
  int *piVar15;
  undefined4 *puVar16;
  int iVar17;
  char *pcVar18;
  int iVar19;
  uint uVar20;
  ViWinRoot *pVVar21;
  bool bVar22;
  float in_XMM0_Da;
  double dVar23;
  double dVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  _FILETIME local_b8;
  undefined8 local_b0;
  int *local_94;
  int *local_90;
  int *local_8c;
  int *local_88;
  int *local_84;
  int *local_80;
  int *local_7c;
  int *local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  ViWinRoot *local_68;
  int *local_64;
  _FILETIME local_60;
  char local_51;
  int *local_50;
  float local_4c;
  float local_48;
  ViWinRoot *local_44;
  uint local_40;
  undefined4 local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  piVar10 = DAT_00772400;
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_00702b60;
  local_1c = ExceptionList;
  local_24 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  this->i_44 = DAT_00772400[0x19];
  piVar10[0x2830] = -1;
  local_68 = this;
  puVar5 = &stack0xfffffffc;
  if (((char)piVar10[0x23] == '\0') &&
     (local_2c = *(int **)&this->field_0x110, puVar5 = &stack0xfffffffc, local_2c != (int *)0x0)) {
    piVar7 = (int *)FUN_006ba810();
    piVar7[1] = 4;
    *(undefined1 *)(piVar7 + 3) = 0;
    piVar7[2] = 0;
    *piVar7 = 1;
    local_14 = 0;
    local_28 = piVar7;
    cVar6 = FUN_006b97f0();
    if (cVar6 == '\0') {
      piVar10 = (int *)local_2c[8];
      local_2c[8] = (int)piVar7;
      *piVar7 = *piVar7 + 1;
      if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
        FUN_006ba940();
      }
      *(int *)(local_2c[8] + 8) = piVar7[2];
      FUN_00504ee0();
    }
    local_14 = 1;
    *piVar7 = *piVar7 + -1;
    piVar10 = DAT_00772400;
    puVar5 = puStack_20;
    if (*piVar7 == 0) {
      FUN_006ba940();
      piVar10 = DAT_00772400;
      puVar5 = puStack_20;
    }
  }
  puStack_20 = puVar5;
  local_14 = 0xffffffff;
  if (this->i_e4 != 0) {
    if (piVar10[0x2832] == 0) {
      iVar8 = 0;
    }
    else {
      local_28 = piVar10 + 0x2831;
      if (piVar10[0x2832] < 1) {
        iVar8 = 0;
      }
      else {
        puVar2 = (uint *)*local_28;
        local_28 = (int *)(DAT_0077244c + 0x488);
        if (*puVar2 < 0x2000) {
          piVar7 = local_28 + *puVar2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar7 = local_28;
          piVar10 = DAT_00772400;
        }
        iVar8 = *piVar7;
      }
    }
    if (iVar8 != *(int *)(this->i_e4 + 0xc0)) {
      *(int *)(this->i_e4 + 0xc0) = iVar8;
      if (iVar8 != 0) {
        if ((*(int *)(iVar8 + 0xe8) == 1) || (*(int *)(iVar8 + 0xe8) == 0xb)) {
          *(undefined4 *)(this->i_e4 + 0xc4) = 0;
        }
        else {
          *(undefined4 *)(this->i_e4 + 0xc4) = 1;
        }
      }
      *(undefined4 *)(this->i_e4 + 0x80) = 0xffffffff;
      FUN_00536190();
      FUN_00507d40();
      piVar10 = DAT_00772400;
    }
  }
  local_b0 = 0x7fffffffffffffff;
  if ((DAT_007683a8 == '\0') && ((char)piVar10[0x23] == '\0')) {
    if ((char)piVar10[0x2826] == '\0') {
      if (this->i_e8 == 0) {
        local_3c = 0;
        local_38 = (int *)0x0;
        *(undefined1 *)(DAT_0076a338 + 0x2840) = 1;
        local_44 = (ViWinRoot *)(this->i_18 - this->i_10);
        local_48 = (float)(this->i_14 - this->i_0c);
        uVar9 = FUN_004435d0(&stack0xffffff24,"Pause");
        FUN_00443730(uVar9);
        iVar8 = FUN_00518ed0(&local_48);
        this->i_e8 = iVar8;
        *(undefined4 *)(iVar8 + 0x28) = 2;
        *(undefined4 *)(this->i_e8 + 0x28) = 4;
        FUN_00526a80();
        FUN_00505ed0();
        iVar8 = FUN_00501450();
        if (*(int *)(iVar8 + 0x101fc) == 2) {
          iVar8 = FUN_00501450();
          *(undefined4 *)(iVar8 + 0x101fc) = 4;
        }
      }
      goto LAB_0052c148;
    }
    in_XMM0_Da = SUB84(ABS(*(double *)(piVar10 + 0x2824) - 1.0),0);
    if (0.2 < ABS(*(double *)(piVar10 + 0x2824) - 1.0)) {
      if (this->i_e8 == 0) {
        local_44 = (ViWinRoot *)(this->i_18 - this->i_10);
        local_48 = (float)(this->i_14 - this->i_0c);
        local_3c = 0;
        local_38 = (int *)0x0;
        uVar9 = FUN_004435d0(&stack0xffffff24,"Turbo");
        FUN_00443730(uVar9);
        iVar8 = FUN_00518ed0(&local_48);
        this->i_e8 = iVar8;
        *(undefined4 *)(iVar8 + 0x28) = 2;
        *(undefined4 *)(this->i_e8 + 0x28) = 4;
        FUN_00526a80();
        FUN_00505ed0();
        iVar8 = FUN_00501450();
        if (*(int *)(iVar8 + 0x101fc) == 2) {
          iVar8 = FUN_00501450();
          *(undefined4 *)(iVar8 + 0x101fc) = 4;
        }
      }
      uVar9 = FUN_004435d0();
      FUN_00443730(uVar9);
      local_14 = 2;
      piVar10 = (int *)FUN_006b9500(" x %.0f");
      local_14._0_1_ = 3;
      FUN_006b90d0(&local_28,*piVar10 + 0xc);
      local_14._0_1_ = 6;
      if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
        FUN_006ba940();
      }
      local_14._0_1_ = 8;
      if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
        FUN_006ba940();
      }
      local_14 = CONCAT31(local_14._1_3_,7);
      FUN_00504910();
      local_14 = 9;
      if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
        FUN_006ba940();
      }
      goto LAB_0052c148;
    }
  }
  local_28 = (int *)this->i_e8;
  if (local_28 != (int *)0x0) {
    if ((char)piVar10[0x24] == '\0') {
      *(undefined1 *)(DAT_0076a338 + 0x2840) = 0;
      local_28 = (int *)this->i_e8;
    }
    *(undefined1 *)((int)local_28 + 0x2d) = 1;
    iVar8 = FUN_00501450();
    if ((*(int **)(iVar8 + 0x81a0) != (int *)0x0) && (*(int **)(iVar8 + 0x81a0) == local_28)) {
      iVar8 = FUN_00501450();
      *(undefined4 *)(iVar8 + 0x81a0) = 0;
    }
    this->i_e8 = 0;
    iVar8 = FUN_00501450();
    if ((*(int *)(iVar8 + 0x101fc) == 4) && ((char)DAT_00772400[0x23] == '\0')) {
      iVar8 = FUN_00501450();
      *(undefined4 *)(iVar8 + 0x101fc) = 2;
    }
  }
  FUN_00529360();
  if (*(char *)((int)DAT_00772400 + 0x3c9) != '\0') goto LAB_0052c148;
  cVar6 = this->c_8d;
  if (cVar6 != '\0') {
                    /* WARNING: Load size is inaccurate */
    if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c94398) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c94398 == -1)) {
      iVar17 = DAT_00783650 * 0x40;
      _DAT_00c9439c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() MsgBox";
      *(int *)(&DAT_00773650 + iVar17) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_14 = 10;
    if (0 < *(int *)&this->field_0x88) {
      if (*(int *)&this->field_0x88 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_2c = (int *)**(undefined4 **)&this->field_0x84;
      if (local_2c != (int *)0x0) {
        *local_2c = *local_2c + 1;
      }
      local_14._0_1_ = 0xb;
      local_28 = local_2c;
      FUN_005112c0();
      FUN_0050a280();
      FUN_00505ed0();
      local_14 = CONCAT31(local_14._1_3_,0xc);
      if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
        FUN_006ba940();
      }
    }
    local_14 = 0xffffffff;
    FUN_0043fd30();
    cVar6 = this->c_8d;
  }
  piVar10 = DAT_00772400;
  if (((char)DAT_00772400[0x170] != '\0') && (cVar6 == '\0')) {
    this->c_8d = '\x01';
  }
  *(undefined4 *)&this->field_0x98 = 0;
  this->f_94 = 0.0;
  this->f_90 = 0.0;
  *(undefined4 *)&this->field_0xa4 = 0;
  this->f_a0 = 0.0;
  this->f_9c = 0.0;
  this->f_a8 = 1.0;
  if (((char)piVar10[0x164] == '\0') && ((char)piVar10[0x23] == '\0')) {
                    /* WARNING: Load size is inaccurate */
    if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943a0) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943a0 == -1)) {
      iVar17 = DAT_00783650 * 0x40;
      _DAT_00c943a4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() SeqControl";
      *(int *)(&DAT_00773650 + iVar17) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_14 = 0xd;
    cVar6 = FUN_00504960();
    piVar10 = DAT_00c3c9ac;
    if ((cVar6 != '\0') &&
       (local_28 = (int *)GetTickCount(), piVar10 = local_28, DAT_00c3c9ac != (int *)0x0)) {
      local_30 = (int *)0x3e4ccccd;
      iVar8 = FUN_004ecd40();
      if (*(char *)(iVar8 + 0x123) != '\0') {
        local_30 = (int *)0x3f800000;
      }
      local_30 = (int *)((float)local_30 + (float)local_30);
      in_XMM0_Da = *(float *)(DAT_0076a338 + 0x2814);
      FUN_0040b7e0();
      local_30 = (int *)((float)local_30 / in_XMM0_Da);
      iVar8 = FUN_004ecd40();
      piVar10 = local_28;
      if (*(int *)(iVar8 + 0x438) == 0) {
        iVar8 = FUN_004ecd40();
        if (*(char *)(iVar8 + 0x121) != '\0') {
          in_XMM0_Da = this->f_90 - (float)local_30;
          this->f_90 = in_XMM0_Da;
          iVar8 = FUN_00501450();
          *(undefined1 *)(iVar8 + 0x13) = 1;
        }
        iVar8 = FUN_004ecd40();
        if (*(char *)(iVar8 + 0x122) != '\0') {
          in_XMM0_Da = this->f_90 + (float)local_30;
          this->f_90 = in_XMM0_Da;
          iVar8 = FUN_00501450();
          *(undefined1 *)(iVar8 + 0x13) = 1;
        }
        iVar8 = FUN_004ecd40();
        if (*(char *)(iVar8 + 0x11f) != '\0') {
          in_XMM0_Da = this->f_94 - (float)local_30;
          this->f_94 = in_XMM0_Da;
          iVar8 = FUN_00501450();
          *(undefined1 *)(iVar8 + 0x13) = 1;
        }
        iVar8 = FUN_004ecd40();
        piVar10 = local_28;
        if (*(char *)(iVar8 + 0x120) != '\0') {
          in_XMM0_Da = (float)local_30 + this->f_94;
          this->f_94 = in_XMM0_Da;
          iVar8 = FUN_00501450();
          *(undefined1 *)(iVar8 + 0x13) = 1;
          piVar10 = local_28;
        }
      }
    }
    DAT_00c3c9ac = piVar10;
    local_14 = 0xffffffff;
    FUN_0043fd30();
  }
  iVar8 = FUN_00501450();
  if ((*(ViWinRoot **)(iVar8 + 0x8198) == this) &&
     (((iVar8 = FUN_00501450(), *(int *)(iVar8 + 0x81a4) == 0 ||
       (iVar8 = FUN_00501450(), *(ViWinRoot **)(iVar8 + 0x81a4) == this)) &&
      (this[1].field_0x1 == '\0')))) {
                    /* WARNING: Load size is inaccurate */
    if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943a8) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943a8 == -1)) {
      iVar17 = DAT_00783650 * 0x40;
      _DAT_00c943ac = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() Hovered";
      *(int *)(&DAT_00773650 + iVar17) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    piVar10 = DAT_00772400;
    local_14 = 0xe;
    local_28 = (int *)this->i_44;
    local_51 = '\0';
    iVar8 = DAT_00772400[0x2834];
    DAT_00772400[0x2833] = 0;
    piVar10[0x2836] = -1;
    if (iVar8 < 1) {
      if (*(char *)((int)piVar10 + 0x591) == '\0') {
        FUN_0055aa20();
        iVar8 = FUN_004796d0(DAT_00772400[0x72],DAT_00772400[0x73]);
        goto LAB_0052a50c;
      }
    }
    else {
      piVar7 = (int *)FUN_00407340();
      piVar10 = DAT_00772400;
      if (*piVar7 != 0) {
        piVar10 = (int *)FUN_0045f830();
        iVar8 = *piVar10;
LAB_0052a50c:
        piVar10 = DAT_00772400;
        DAT_00772400[0x2836] = iVar8;
      }
    }
    if ((local_51 != '\0') && (local_28 = piVar10 + 0x2836, piVar10[0x2836] == -1)) {
      if ((piVar10[0x2832] == 1) &&
         (local_2c = *(int **)piVar10[0x2831],
         (undefined1 *)((int)local_2c + -2) < (undefined1 *)0x1fff)) {
        local_34 = (int *)(DAT_0077244c + 0x488);
        if ((int)local_2c < 0x2000) {
          local_2c = local_34 + (int)local_2c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_2c = local_34;
          piVar10 = DAT_00772400;
        }
        this = local_68;
        local_2c = (int *)*local_2c;
        if (local_2c != (int *)0x0) {
          if ((uint)piVar10[0x19] < 8) {
            *local_28 = local_2c[piVar10[0x19] + 0xdf];
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar10 = DAT_00772400;
            *local_28 = local_2c[0xdf];
          }
          goto LAB_0052a5dd;
        }
      }
      *local_28 = -1;
    }
LAB_0052a5dd:
    local_28 = (int *)piVar10[0x2836];
    if (-1 < (int)local_28) {
      if (local_28 == (int *)0x7890) {
        piVar10[0x2833] = 1;
        uVar20 = 1;
        piVar10[0x2836] = -1;
      }
      else {
        iVar8 = FUN_005b78b0();
        piVar10 = DAT_00772400;
        local_2c = (int *)(iVar8 + 0xc008);
        if ((int)local_28 < *(int *)(iVar8 + 0xc00c)) {
          uVar20 = *(uint *)((int)local_28 * 0xd8 + *local_2c + 0x68);
          DAT_00772400[0x2833] = uVar20;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = DAT_00772400;
          uVar20 = *(uint *)(*local_2c + 0x68);
          DAT_00772400[0x2833] = uVar20;
        }
      }
      if ((int)uVar20 < 0) {
        piVar10[0x2836] = -1;
      }
      else if ((char)piVar10[0x164] != '\0') {
        local_28 = (int *)(DAT_0077244c + 0x488);
        if (0x1fff < uVar20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        cVar6 = FUN_005d09a0();
        piVar10 = DAT_00772400;
        if (cVar6 == '\0') {
          DAT_00772400[0x2833] = -1;
          piVar10[0x2836] = -1;
        }
      }
    }
    local_14 = 0xffffffff;
    FUN_0043fd30();
  }
  piVar10 = DAT_00772400;
  if ((0 < DAT_00772400[0x2834]) && (this[1].field_0x1 == '\0')) {
    DAT_00772400[0x2833] = DAT_00772400[0x2834];
  }
  if (((this->c_8d != '\0') && ((char)piVar10[0x24] == '\0')) || ((char)piVar10[0x164] != '\0')) {
                    /* WARNING: Load size is inaccurate */
    if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943b0) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943b0 == -1)) {
      iVar17 = DAT_00783650 * 0x40;
      _DAT_00c943b4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() ObjAction";
      *(int *)(&DAT_00773650 + iVar17) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_14 = 0xf;
    FUN_00530b90();
    FUN_0052f620();
    local_14 = 0xffffffff;
    FUN_0043fd30();
  }
  GetSystemTimeAsFileTime(&local_b8);
  FUN_00501450();
  GetSystemTimeAsFileTime(&local_60);
  piVar10 = (int *)&this->field_0x30;
  local_2c = piVar10;
  FUN_006b9200();
  pVVar21 = local_68;
  if (*(char *)((int)DAT_00772400 + 0x8b) == '\0') {
    if (((*(int *)&local_68->field_0xb0 != 0) && (*(int *)&local_68->field_0x10c != 0)) &&
       (local_68[1].field_0x1 == '\0')) {
                    /* WARNING: Load size is inaccurate */
      if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943c0) &&
         (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943c0 == -1)) {
        iVar17 = DAT_00783650 * 0x40;
        _DAT_00c943c4 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() ToolTip";
        *(int *)(&DAT_00773650 + iVar17) = iVar8;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa();
      }
      FUN_00405af0();
      local_14._0_1_ = 0x13;
      local_14._1_3_ = 0;
      local_28 = DAT_00772400;
      iVar8 = DAT_00772400[0x2833];
      if (iVar8 < 2) {
        if (0 < DAT_00772400[0x2832]) {
          if (DAT_00772400[0x2832] == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar8 = *(int *)local_28[0x2831];
          goto LAB_0052a8f7;
        }
      }
      else {
LAB_0052a8f7:
        if (iVar8 < 1) goto LAB_0052babb;
        puVar16 = (undefined4 *)FUN_00407340();
        piVar7 = (int *)*puVar16;
        local_30 = piVar7;
        if (piVar7 != (int *)0x0) {
          if ((piVar7[0x3a] == 1) || (piVar7[0x3a] == 0xb)) {
                    /* WARNING: Load size is inaccurate */
            if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943c8) &&
               (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943c8 == -1)) {
              iVar17 = DAT_00783650 * 0x40;
              _DAT_00c943cc = DAT_00783650;
              *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() Tooltip Gnome/Baby";
              *(int *)(&DAT_00773650 + iVar17) = iVar8;
              DAT_00783650 = DAT_00783650 + 1;
              FUN_006cebaa();
            }
            FUN_00405af0();
            local_14._0_1_ = 0x14;
            FUN_006b91c0();
            local_28 = (int *)FUN_005cd730();
            bVar22 = (int)local_28 < 0;
            if (bVar22) {
              uVar9 = FUN_004435d0();
              FUN_00443730(uVar9);
              local_14._0_1_ = 0x15;
              FUN_006b9290();
              local_14._0_1_ = 0x16;
              if ((local_44 != (ViWinRoot *)0x0) &&
                 (*(int *)local_44 = *(int *)local_44 + -1, *(int *)local_44 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x14;
              bVar22 = (int)local_28 < 0;
            }
            if (local_28 != (int *)0x0 && !bVar22) {
              uVar9 = FUN_004435d0();
              FUN_00443730(uVar9);
              local_14._0_1_ = 0x17;
              FUN_006b9290();
              local_14._0_1_ = 0x18;
              if ((local_44 != (ViWinRoot *)0x0) &&
                 (*(int *)local_44 = *(int *)local_44 + -1, *(int *)local_44 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x14;
            }
            if (local_28 == (int *)0x0) {
              uVar9 = FUN_004435d0();
              FUN_00443730(uVar9);
              local_14._0_1_ = 0x19;
              FUN_006b9290();
              local_14._0_1_ = 0x1a;
              if ((local_44 != (ViWinRoot *)0x0) &&
                 (*(int *)local_44 = *(int *)local_44 + -1, *(int *)local_44 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x14;
            }
            if (piVar7[0x3a] == 1) {
                    /* WARNING: Load size is inaccurate */
              if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943d0) &&
                 (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943d0 == -1)) {
                iVar17 = DAT_00783650 * 0x40;
                _DAT_00c943d4 = DAT_00783650;
                *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() Tooltip ProdGnome";
                *(int *)(&DAT_00773650 + iVar17) = iVar8;
                DAT_00783650 = DAT_00783650 + 1;
                FUN_006cebaa();
              }
              FUN_00405af0();
              local_14._0_1_ = 0x1b;
              uVar4 = (undefined1)local_14;
              local_14._0_1_ = 0x1b;
              if (*(int *)(piVar7[0xf9] + 0x34) < 1) {
                local_14._0_1_ = uVar4;
                FUN_006b9390();
              }
              else {
                in_XMM0_Da = (float)*(double *)(DAT_00772400 + 0x282c) -
                             *(float *)(piVar7[0xf9] + 0x38);
                uVar9 = FUN_004435d0(&local_38);
                FUN_00443730(uVar9);
                local_14._0_1_ = 0x1c;
                FUN_006b9500(&DAT_00721a8c);
                local_14._0_1_ = 0x1d;
                FUN_006b9290();
                local_14._0_1_ = 0x1e;
                if ((local_44 != (ViWinRoot *)0x0) &&
                   (*(int *)local_44 = *(int *)local_44 + -1, *(int *)local_44 == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x1f;
                if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x1b;
              }
              FUN_006b8f50();
              local_14._0_1_ = 0x20;
              FUN_005dae40();
              fVar25 = in_XMM0_Da * 100.0 + 0.9;
              DAT_00772dd8 = (int *)(int)ROUND(fVar25);
              local_44 = (ViWinRoot *)fVar25;
              local_38 = DAT_00772dd8;
              FUN_005dae40();
              fVar25 = fVar25 * 100.0 + 0.9;
              DAT_00772dd8 = (int *)(int)ROUND(fVar25);
              local_44 = (ViWinRoot *)fVar25;
              FUN_005dae40();
              fVar26 = fVar25 * 100.0 + 0.9;
              fVar25 = ROUND(fVar26);
              DAT_00772dd8 = (int *)(int)fVar25;
              local_44 = (ViWinRoot *)fVar26;
              FUN_005dae40();
              local_44 = (ViWinRoot *)(fVar26 * 100.0 + 0.9);
              DAT_00772dd8 = (int *)(int)ROUND((float)local_44);
              uVar9 = FUN_004435d0(&local_64,"HP:%d AL:%d NU:%d MO:%d",DAT_00772dd8,(int)fVar25);
              FUN_00443730(uVar9);
              local_14._0_1_ = 0x21;
              FUN_006b9500(&DAT_00721a8c);
              local_14._0_1_ = 0x22;
              FUN_006b91c0();
              local_14._0_1_ = 0x23;
              if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x24;
              if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x20;
              FUN_006b9290();
              local_14._0_1_ = 0x25;
              if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x14;
              FUN_0043fd30();
              piVar7 = local_30;
            }
            if (piVar7[0xfc] != 0) {
              FUN_005db960();
              local_14 = CONCAT31(local_14._1_3_,0x26);
              cVar6 = FUN_006b98f0();
              if (cVar6 != '\0') {
                FUN_006b9290();
              }
              local_14._0_1_ = 0x27;
              if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
                FUN_006ba940();
              }
            }
          }
          else {
            if (piVar7[0xf8] == 0) {
              uVar9 = FUN_004435d0();
              FUN_00443730(uVar9);
              local_14._0_1_ = 0x6f;
              FUN_006b91c0();
              local_14._0_1_ = 0x70;
              if ((local_44 != (ViWinRoot *)0x0) &&
                 (*(int *)local_44 = *(int *)local_44 + -1, *(int *)local_44 == 0)) {
                FUN_006ba940();
              }
              while( true ) {
                local_14._0_1_ = 0x13;
                iVar8 = *piVar10;
                if (*(int *)(iVar8 + 8) == -1) {
                  pcVar18 = (char *)(iVar8 + 0xc);
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  *(int *)(iVar8 + 8) = (int)pcVar18 - (iVar8 + 0xd);
                  iVar8 = *piVar10;
                }
                bVar1 = *(byte *)(*(int *)(iVar8 + 8) + 0xb + iVar8);
                if ((bVar1 != 0x5f) && (iVar8 = _isdigit((uint)bVar1), iVar8 == 0)) break;
                piVar7 = (int *)*piVar10;
                if (piVar7 != (int *)0x0) {
                  *piVar7 = *piVar7 + 1;
                }
                local_14._0_1_ = 0x71;
                iVar8 = *piVar10;
                if (*(int *)(iVar8 + 8) == -1) {
                  pcVar18 = (char *)(iVar8 + 0xc);
                  local_44 = (ViWinRoot *)(iVar8 + 0xd);
                  do {
                    cVar6 = *pcVar18;
                    pcVar18 = pcVar18 + 1;
                  } while (cVar6 != '\0');
                  *(int *)(iVar8 + 8) = (int)pcVar18 - (int)local_44;
                }
                local_50 = piVar7;
                FUN_006b9b20(&local_38);
                piVar15 = local_38;
                local_14._0_1_ = 0x72;
                piVar10 = (int *)*piVar10;
                *(int **)&local_68->field_0x30 = local_38;
                if (local_38 != (int *)0x0) {
                  *local_38 = *local_38 + 1;
                }
                if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
                  FUN_006ba940();
                }
                *(int *)(*(int *)&local_68->field_0x30 + 8) = piVar15[2];
                local_14._0_1_ = 0x73;
                *piVar15 = *piVar15 + -1;
                if (*piVar15 == 0) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x74;
                piVar10 = local_2c;
                if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
                  FUN_006ba940();
                  piVar10 = local_2c;
                }
              }
              piVar10 = (int *)FUN_005bbb20();
              local_28 = piVar10;
              local_34 = (int *)FUN_005be100();
              if ((local_34 != (int *)0xffffffff) &&
                 ((-1 < (int)local_34 && ((int)local_34 < piVar10[3])))) {
                if ((int *)piVar10[3] <= local_34) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_44 = (ViWinRoot *)((int)local_34 * 0x40);
                local_38 = *(int **)((int)&local_44->i_14 + local_28[2]);
                if (0.0 < (float)local_38) {
                  FUN_006b8f50();
                  local_14 = CONCAT31(local_14._1_3_,0x75);
                  if ((int)local_34 < local_28[3]) {
                    if ((int *)local_28[3] <= local_34) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    local_28 = *(int **)((int)&local_44->i_10 + local_28[2]);
                    if (local_28 != (int *)0x0) {
                      *local_28 = *local_28 + 1;
                    }
                  }
                  else {
                    local_28 = (int *)FUN_006ba810();
                    local_28[1] = 4;
                    *(undefined1 *)(local_28 + 3) = 0;
                    local_28[2] = 0;
                    *local_28 = 1;
                  }
                  piVar10 = local_28;
                  local_14 = CONCAT31(local_14._1_3_,0x76);
                  local_44 = (ViWinRoot *)FUN_005da0f0();
                  iVar8 = FUN_005da2f0();
                  if (iVar8 != -1) {
                    FUN_00430f90();
                    FUN_006b91c0();
                    piVar10 = local_28;
                  }
                  local_44 = (ViWinRoot *)((float)local_38 * 100.0 + 0.01);
                  DAT_00772dd8 = (int *)(int)ROUND((float)local_44);
                  FUN_006b9040(&local_2c," (%s - %i)");
                  FUN_006b9290();
                  local_14._0_1_ = 0x77;
                  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
                    FUN_006ba940();
                  }
                  local_14._0_1_ = 0x78;
                  if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
                    FUN_006ba940();
                  }
                  local_14._0_1_ = 0x13;
                }
              }
              goto LAB_0052ba85;
            }
                    /* WARNING: Load size is inaccurate */
            if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943d8) &&
               (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943d8 == -1)) {
              iVar17 = DAT_00783650 * 0x40;
              _DAT_00c943dc = DAT_00783650;
              *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() Tooltip Prod";
              *(int *)(&DAT_00773650 + iVar17) = iVar8;
              DAT_00783650 = DAT_00783650 + 1;
              FUN_006cebaa();
            }
            FUN_00405af0();
            if ((piVar7[0x3a] == 6) && ((piVar7[0xf4] & 0x4000U) == 0)) {
                    /* WARNING: Load size is inaccurate */
              if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943e0) &&
                 (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943e0 == -1)) {
                iVar17 = DAT_00783650 * 0x40;
                _DAT_00c943e4 = DAT_00783650;
                *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() Tooltip Prod Energy";
                *(int *)(&DAT_00773650 + iVar17) = iVar8;
                DAT_00783650 = DAT_00783650 + 1;
                FUN_006cebaa();
              }
              FUN_00405af0();
              local_14._0_1_ = 0x29;
              uVar9 = FUN_004435d0();
              FUN_00443730(uVar9);
              local_14._0_1_ = 0x2a;
              FUN_006b91c0();
              local_14._0_1_ = 0x2b;
              if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x29;
              local_40 = FUN_006b90d0(&local_50);
              local_14._0_1_ = 0x2c;
              uVar9 = FUN_004435d0();
              local_34 = (int *)FUN_00443730(uVar9);
              local_14._0_1_ = 0x2d;
              local_28 = (int *)FUN_006b90d0(&local_70," %.1f");
              local_14._0_1_ = 0x2e;
              uVar9 = FUN_004435d0();
              uVar9 = FUN_00443730(uVar9);
              local_14._0_1_ = 0x2f;
              uVar12 = FUN_006b90d0(&local_74," %.1f");
              local_14._0_1_ = 0x30;
              uVar13 = FUN_004435d0();
              uVar13 = FUN_00443730(uVar13);
              local_14._0_1_ = 0x31;
              FUN_006b95d0(uVar13);
              local_14._0_1_ = 0x32;
              FUN_006b9410(uVar12);
              local_14._0_1_ = 0x33;
              FUN_006b9500(&DAT_00721a8c);
              local_14._0_1_ = 0x34;
              FUN_006b9410(uVar9);
              local_14._0_1_ = 0x35;
              FUN_006b9410(local_28);
              local_14._0_1_ = 0x36;
              FUN_006b9500(&DAT_00721a8c);
              local_14._0_1_ = 0x37;
              FUN_006b9410(local_34);
              local_14._0_1_ = 0x38;
              FUN_006b9410(local_40);
              local_14._0_1_ = 0x39;
              FUN_006b9290();
              local_14._0_1_ = 0x3a;
              if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x3b;
              if ((local_78 != (int *)0x0) && (*local_78 = *local_78 + -1, *local_78 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x3c;
              if ((local_7c != (int *)0x0) && (*local_7c = *local_7c + -1, *local_7c == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x3d;
              if ((local_80 != (int *)0x0) && (*local_80 = *local_80 + -1, *local_80 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x3e;
              if ((local_84 != (int *)0x0) && (*local_84 = *local_84 + -1, *local_84 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x3f;
              if ((local_88 != (int *)0x0) && (*local_88 = *local_88 + -1, *local_88 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x40;
              if ((local_8c != (int *)0x0) && (*local_8c = *local_8c + -1, *local_8c == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x41;
              if ((local_90 != (int *)0x0) && (*local_90 = *local_90 + -1, *local_90 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x42;
              if ((local_94 != (int *)0x0) && (*local_94 = *local_94 + -1, *local_94 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x43;
              if ((local_74 != (int *)0x0) && (*local_74 = *local_74 + -1, *local_74 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x44;
              if ((local_6c != (int *)0x0) && (*local_6c = *local_6c + -1, *local_6c == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x45;
              if ((local_70 != (int *)0x0) && (*local_70 = *local_70 + -1, *local_70 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x46;
              if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x47;
              if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)) {
                FUN_006ba940();
              }
            }
            else {
                    /* WARNING: Load size is inaccurate */
              if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943e8) &&
                 (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943e8 == -1)) {
                iVar17 = DAT_00783650 * 0x40;
                _DAT_00c943ec = DAT_00783650;
                *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() Tooltip Prod Nonenergy"
                ;
                *(int *)(&DAT_00773650 + iVar17) = iVar8;
                DAT_00783650 = DAT_00783650 + 1;
                FUN_006cebaa();
              }
              FUN_00405af0();
              local_14._0_1_ = 0x48;
              uVar9 = FUN_004435d0();
              FUN_00443730(uVar9);
              local_14._0_1_ = 0x49;
              FUN_006b91c0();
              local_14._0_1_ = 0x4a;
              if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                FUN_006ba940();
              }
              local_14._0_1_ = 0x48;
              iVar8 = piVar7[0xf8];
              local_28 = (int *)&DAT_00000009;
              local_40 = 0;
              if (0 < *(int *)(iVar8 + 0x10)) {
                local_34 = (int *)0x0;
                do {
                  local_38 = (int *)(iVar8 + 0xc);
                  if (*(uint *)(iVar8 + 0x10) <= local_40) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar8 = local_30[0xf8];
                  }
                  if (0 < *(int *)(*local_38 + 0x10 + (int)local_34)) {
                    local_38 = (int *)(iVar8 + 0xc);
                    if (*(uint *)(iVar8 + 0x10) <= local_40) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      iVar8 = local_30[0xf8];
                    }
                    if (*(int *)((int)local_34 + *local_38 + 8) != 0) {
                      if (*(uint *)(iVar8 + 0x10) <= local_40) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      if (*(char *)(*(int *)(*(int *)((int)local_34 + *(int *)(iVar8 + 0xc) + 8) +
                                            0xc) + 0xc) != '_') {
                        if (4 < (int)local_28) {
                          iVar8 = *piVar10;
                          local_28 = (int *)0x0;
                          if (*(int *)(iVar8 + 8) == -1) {
                            pcVar18 = (char *)(iVar8 + 0xc);
                            do {
                              cVar6 = *pcVar18;
                              pcVar18 = pcVar18 + 1;
                            } while (cVar6 != '\0');
                            *(int *)(iVar8 + 8) = (int)pcVar18 - (iVar8 + 0xd);
                            iVar8 = *piVar10;
                          }
                          iVar8 = *(int *)(iVar8 + 8);
                          iVar17 = FUN_006b8df0();
                          *local_2c = iVar17;
                          *(undefined2 *)(iVar8 + 0xc + iVar17) = 10;
                          *(int *)(*local_2c + 8) = iVar8 + 1;
                          piVar10 = local_2c;
                        }
                        piVar7 = local_30;
                        local_38 = (int *)(local_30[0xf8] + 0xc);
                        if (*(uint *)(local_30[0xf8] + 0x10) <= local_40) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        uVar9 = FUN_004435d0();
                        local_38 = (int *)FUN_00443730(uVar9);
                        local_14._0_1_ = 0x4b;
                        if (*(uint *)(piVar7[0xf8] + 0x10) <= local_40) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        FUN_006b90d0(&local_50,"%s x%d ");
                        local_14._0_1_ = 0x4c;
                        FUN_006b9290();
                        local_14._0_1_ = 0x4d;
                        if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)
                           ) {
                          FUN_006ba940();
                        }
                        local_14._0_1_ = 0x4e;
                        if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)
                           ) {
                          FUN_006ba940();
                        }
                        local_14._0_1_ = 0x48;
                        local_28 = (int *)((int)local_28 + 1);
                      }
                    }
                  }
                  local_40 = local_40 + 1;
                  local_34 = local_34 + 7;
                  iVar8 = local_30[0xf8];
                } while ((int)local_40 < *(int *)(iVar8 + 0x10));
              }
              if (*(int *)(iVar8 + 0x1c) != 0) {
                FUN_006b9390();
                piVar7 = local_30;
                local_38 = *(int **)(local_30[0xf8] + 0x24);
                if (local_38 != (int *)0x0) {
                  BVar14 = IsBadReadPtr(local_38,0x10);
                  if (BVar14 == 0) {
                    if (local_38[2] == 0x616e4f62) {
                      if ((DAT_00768398 == '\0') || (local_38[0x37] != 0)) {
                        bVar22 = true;
                      }
                      else {
                        bVar22 = false;
                      }
                    }
                    else {
                      bVar22 = false;
                    }
                  }
                  else {
                    bVar22 = false;
                  }
                  if (bVar22) {
                    FUN_006b9500();
                    local_14._0_1_ = 0x4f;
                    FUN_006b9290();
                    local_14._0_1_ = 0x50;
                    if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                      FUN_006ba940();
                    }
                    local_14._0_1_ = 0x48;
                  }
                  else {
                    *(undefined4 *)(piVar7[0xf8] + 0x24) = 0;
                  }
                }
                switch(*(undefined4 *)(piVar7[0xf8] + 0x1c)) {
                case 1:
                  uVar9 = FUN_004435d0();
                  FUN_00443730(uVar9);
                  local_14._0_1_ = 0x51;
                  FUN_006b9290();
                  local_14 = CONCAT31(local_14._1_3_,0x52);
                  break;
                case 2:
                  uVar9 = FUN_004435d0();
                  FUN_00443730(uVar9);
                  local_14._0_1_ = 0x53;
                  FUN_006b9290();
                  local_14 = CONCAT31(local_14._1_3_,0x54);
                  break;
                case 3:
                  uVar9 = FUN_004435d0();
                  FUN_00443730(uVar9);
                  local_14._0_1_ = 0x55;
                  FUN_006b9290();
                  local_14 = CONCAT31(local_14._1_3_,0x56);
                  break;
                case 4:
                  uVar9 = FUN_004435d0();
                  FUN_00443730(uVar9);
                  local_14._0_1_ = 0x57;
                  FUN_006b9290();
                  local_14 = CONCAT31(local_14._1_3_,0x58);
                  break;
                case 5:
                  uVar9 = FUN_004435d0();
                  FUN_00443730(uVar9);
                  local_14._0_1_ = 0x59;
                  FUN_006b9290();
                  local_14 = CONCAT31(local_14._1_3_,0x5a);
                  break;
                case 6:
                  uVar9 = FUN_004435d0();
                  FUN_00443730(uVar9);
                  local_14._0_1_ = 0x5b;
                  FUN_006b9290();
                  local_14 = CONCAT31(local_14._1_3_,0x5c);
                  break;
                default:
                  goto switchD_0052afd6_default;
                }
                if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x48;
switchD_0052afd6_default:
                iVar8 = *(int *)(piVar7[0xf8] + 0x1c);
                if ((iVar8 == 2) || (iVar8 == 1)) {
                  piVar15 = *(int **)(piVar7[0xf8] + 0x10);
                  local_28 = (int *)0x0;
                  local_34 = piVar15;
                  if (0 < (int)piVar15) {
                    local_40 = 0;
                    do {
                      iVar8 = piVar7[0xf8];
                      if ((-1 < (int)local_28) && ((int)local_28 < *(int *)(iVar8 + 0x10))) {
                        local_38 = (int *)(iVar8 + 0xc);
                        if (*(int **)(iVar8 + 0x10) <= local_28) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          iVar8 = piVar7[0xf8];
                        }
                        iVar17 = *(int *)(*local_38 + 8 + local_40);
                        piVar15 = local_34;
                        piVar7 = local_30;
                        if ((iVar17 != 0) && (*(int *)(iVar17 + 8) == *(int *)(iVar8 + 0x48))) {
                          iVar8 = *piVar10;
                          if (*(int *)(iVar8 + 8) == -1) {
                            pcVar18 = (char *)(iVar8 + 0xc);
                            do {
                              cVar6 = *pcVar18;
                              pcVar18 = pcVar18 + 1;
                            } while (cVar6 != '\0');
                            *(int *)(iVar8 + 8) = (int)pcVar18 - (iVar8 + 0xd);
                            iVar8 = *piVar10;
                          }
                          iVar8 = *(int *)(iVar8 + 8);
                          iVar17 = FUN_006b8df0();
                          piVar7 = local_30;
                          *local_2c = iVar17;
                          *(undefined2 *)(iVar8 + 0xc + iVar17) = 0x20;
                          *(int *)(*local_2c + 8) = iVar8 + 1;
                          if (*(int **)(local_30[0xf8] + 0x10) <= local_28) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          }
                          uVar9 = FUN_004435d0();
                          FUN_00443730(uVar9);
                          piVar10 = local_2c;
                          local_14._0_1_ = 0x5d;
                          FUN_006b9290();
                          local_14._0_1_ = 0x5e;
                          if ((local_50 != (int *)0x0) &&
                             (*local_50 = *local_50 + -1, *local_50 == 0)) {
                            FUN_006ba940();
                          }
                          local_14._0_1_ = 0x48;
                          local_34 = (int *)0x0;
                          piVar15 = local_34;
                        }
                      }
                      local_40 = local_40 + 0x1c;
                      local_28 = (int *)((int)local_28 + 1);
                    } while ((int)local_28 < (int)piVar15);
                  }
                }
              }
              if (*(int *)(local_30[0xf8] + 300) != 0) {
                uVar9 = FUN_006b90d0(&local_6c);
                local_14._0_1_ = 0x5f;
                uVar12 = FUN_004435d0();
                uVar12 = FUN_00443730(uVar12);
                local_14._0_1_ = 0x60;
                FUN_006b95d0(uVar12);
                local_14._0_1_ = 0x61;
                FUN_006b9410(uVar9);
                local_14._0_1_ = 0x62;
                FUN_006b9500(&DAT_00721a8c);
                local_14._0_1_ = 99;
                FUN_006b9290();
                local_14._0_1_ = 100;
                if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x65;
                if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x66;
                if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x67;
                if ((local_70 != (int *)0x0) && (*local_70 = *local_70 + -1, *local_70 == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x68;
                if ((local_6c != (int *)0x0) && (*local_6c = *local_6c + -1, *local_6c == 0)) {
                  FUN_006ba940();
                }
                local_14._0_1_ = 0x48;
                cVar6 = FUN_005edcd0();
                if (cVar6 == '\0') {
                  uVar9 = FUN_004435d0();
                  uVar9 = FUN_00443730(uVar9);
                  local_14._0_1_ = 0x69;
                  FUN_006b95d0(uVar9);
                  local_14._0_1_ = 0x6a;
                  FUN_006b9500(&DAT_00721a8c);
                  local_14._0_1_ = 0x6b;
                  FUN_006b9290();
                  local_14._0_1_ = 0x6c;
                  if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                    FUN_006ba940();
                  }
                  local_14._0_1_ = 0x6d;
                  if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)) {
                    FUN_006ba940();
                  }
                  local_14._0_1_ = 0x6e;
                  if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)) {
                    FUN_006ba940();
                  }
                }
              }
            }
            FUN_0043fd30();
          }
          local_14._0_1_ = 0x13;
          FUN_0043fd30();
        }
LAB_0052ba85:
        iVar8 = FUN_006b8f20();
        pVVar21 = local_68;
        if (0 < iVar8) {
          FUN_006b9390();
          FUN_006b9290();
          pVVar21 = local_68;
        }
      }
LAB_0052babb:
      iVar8 = FUN_00501450();
      local_44 = *(ViWinRoot **)(iVar8 + 0x8198);
      if (((((local_44 != (ViWinRoot *)0x0) && (local_44 != pVVar21)) &&
           (local_44 != (ViWinRoot *)pVVar21->i_e4)) &&
          ((*(int *)&pVVar21->field_0xb0 == 0 || (cVar6 = FUN_005049a0(), cVar6 == '\0')))) &&
         (*(int *)&local_44->field_0x30 != -0xc)) {
        FUN_006b91c0();
      }
      iVar8 = FUN_006b8f20();
      if (iVar8 < 1) {
        FUN_006b8f20();
      }
      FUN_00504910();
      goto LAB_0052bb3c;
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c943b8) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00c943b8 == -1)) {
      iVar17 = DAT_00783650 * 0x40;
      _DAT_00c943bc = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar17) = "void ViWinRoot::Tick() Pause Tooltip";
      *(int *)(&DAT_00773650 + iVar17) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_14 = 0x10;
    uVar9 = FUN_004435d0();
    piVar11 = (int *)FUN_00443730(uVar9);
    local_14._0_1_ = 0x11;
    piVar7 = (int *)*piVar11;
    piVar15 = (int *)*piVar10;
    *piVar10 = (int)piVar7;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*piVar10 + 8) = *(undefined4 *)(*piVar11 + 8);
    local_14._0_1_ = 0x12;
    if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
      FUN_006ba940();
    }
    pVVar21 = local_68;
    local_14 = CONCAT31(local_14._1_3_,0x10);
    if (*(int *)&local_68->field_0x10c != 0) {
      FUN_00504910();
    }
LAB_0052bb3c:
    local_14 = 0xffffffff;
    FUN_0043fd30();
  }
  iVar8 = FUN_00501450();
  pVVar3 = local_68;
  local_28 = *(int **)(iVar8 + 0x101d4);
  iVar8 = *(int *)(iVar8 + 0x101d8);
  local_2c = (int *)pVVar21->i_0c;
  piVar10 = local_2c;
  if ((int)local_2c <= (int)local_28) {
    piVar10 = local_28;
  }
  piVar7 = (int *)pVVar21->i_14;
  if (((int)piVar10 <= pVVar21->i_14) && (piVar7 = local_28, (int)local_28 < local_68->i_0c)) {
    piVar7 = (int *)local_68->i_0c;
  }
  iVar17 = local_68->i_10;
  if (local_68->i_10 <= iVar8) {
    iVar17 = iVar8;
  }
  iVar19 = pVVar21->i_18;
  if ((iVar17 <= pVVar21->i_18) && (iVar19 = iVar8, iVar8 < local_68->i_10)) {
    iVar19 = local_68->i_10;
  }
  if ((local_28 != piVar7) || (iVar8 != iVar19)) {
    FUN_00501450();
    FUN_00501ec0();
  }
  FUN_006b9200();
  FUN_0052ee20();
  piVar10 = DAT_00772400;
  local_30 = (int *)DAT_00772400[0x169];
  DAT_00772400[0x2834] = -1;
  if ((pVVar3->f_90 != 0.0) || (pVVar3->f_94 != 0.0)) {
    local_60.dwHighDateTime = local_30[0x55];
    fVar25 = (float)local_30[0x56];
    local_44 = (ViWinRoot *)0x0;
    fVar26 = *(float *)(DAT_0076a338 + 0x2760) * (float)local_60.dwHighDateTime +
             *(float *)(DAT_0076a338 + 0x2770) * fVar25 + *(float *)(DAT_0076a338 + 0x2780) * 0.0 +
             *(float *)(DAT_0076a338 + 0x2790);
    fVar27 = ((float)local_30[0x57] - 1.0) * (float)piVar10[0x66] * 0.2 + 1.0;
    local_4c = pVVar3->f_90 * 50.0 * fVar27 +
               (*(float *)(DAT_0076a338 + 0x2764) * fVar25 +
                *(float *)(DAT_0076a338 + 0x2754) * (float)local_60.dwHighDateTime +
                *(float *)(DAT_0076a338 + 0x2774) * 0.0 + *(float *)(DAT_0076a338 + 0x2784)) /
               fVar26;
    local_48 = pVVar3->f_94 * 50.0 * fVar27 +
               (*(float *)(DAT_0076a338 + 0x2758) * (float)local_60.dwHighDateTime +
                *(float *)(DAT_0076a338 + 0x2768) * fVar25 + *(float *)(DAT_0076a338 + 0x2778) * 0.0
               + *(float *)(DAT_0076a338 + 0x2788)) / fVar26;
    puVar16 = (undefined4 *)FUN_00479150();
    uVar20 = pVVar3->i_44;
    local_28 = (int *)*puVar16;
    local_2c = (int *)puVar16[1];
    local_44 = (ViWinRoot *)(piVar10 + 0x28ca);
    if (uVar20 < 8) {
      pVVar21 = (ViWinRoot *)((int)&local_44->field_0x0 + uVar20 * 4 * 4);
      fVar25 = (float)local_60.dwHighDateTime;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar20 = pVVar3->i_44;
      fVar25 = (float)local_30[0x55];
      pVVar21 = local_44;
      piVar10 = DAT_00772400;
    }
    if ((float)(*(int *)&pVVar21->field_0x8 + 1) <= fVar25) {
LAB_0052be64:
      local_60.dwHighDateTime = (DWORD)(piVar10 + 0x28ca);
      if (uVar20 < 8) {
        local_60.dwHighDateTime = local_60.dwHighDateTime + uVar20 * 4 * 4;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar20 = pVVar3->i_44;
        piVar10 = DAT_00772400;
      }
      local_34 = (int *)local_60.dwHighDateTime;
      if (uVar20 < 8) {
        local_60.dwHighDateTime = (DWORD)(piVar10 + 0x28ca + uVar20 * 4);
      }
      else {
        local_60.dwHighDateTime = (DWORD)(piVar10 + 0x28ca);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = DAT_00772400;
      }
      fVar25 = (float)((local_34[2] + *(int *)local_60.dwHighDateTime) / 2);
      dVar24 = (double)(fVar25 - (float)local_28);
      dVar23 = (double)(fVar25 - (float)local_30[0x55]);
      if ((double)CONCAT44((uint)((ulonglong)dVar24 >> 0x20) & local_b0._4_4_,
                           SUB84(dVar24,0) & (uint)local_b0) <
          (double)CONCAT44((uint)((ulonglong)dVar23 >> 0x20) & local_b0._4_4_,
                           SUB84(dVar23,0) & (uint)local_b0)) {
        local_30[0x55] = (int)local_28;
      }
    }
    else {
      local_60.dwHighDateTime = (DWORD)(piVar10 + 0x28ca);
      if (uVar20 < 8) {
        piVar7 = (int *)(local_60.dwHighDateTime + uVar20 * 4 * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar20 = pVVar3->i_44;
        fVar25 = (float)local_30[0x55];
        piVar7 = (int *)local_60.dwHighDateTime;
        piVar10 = DAT_00772400;
      }
      if (fVar25 < (float)(*piVar7 + -1)) goto LAB_0052be64;
      iVar8 = FUN_0043d660();
      piVar10 = DAT_00772400;
      if (((float)local_28 < (float)(*(int *)(iVar8 + 8) + 1)) &&
         (piVar7 = (int *)FUN_0043d660(), piVar10 = DAT_00772400,
         (float)(*piVar7 + -1) <= (float)local_28)) {
        local_30[0x55] = (int)local_28;
        piVar10 = DAT_00772400;
      }
    }
    local_60.dwHighDateTime = (DWORD)(piVar10 + 0x28ca);
    if ((uint)pVVar3->i_44 < 8) {
      local_60.dwHighDateTime = local_60.dwHighDateTime + pVVar3->i_44 * 4 * 4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar10 = DAT_00772400;
    }
    fVar25 = (float)local_30[0x56];
    if (fVar25 < (float)(*(int *)(local_60.dwHighDateTime + 0xc) + 1)) {
      local_60.dwHighDateTime = (DWORD)(piVar10 + 0x28ca);
      if ((uint)pVVar3->i_44 < 8) {
        piVar7 = (int *)(local_60.dwHighDateTime + pVVar3->i_44 * 4 * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        fVar25 = (float)local_30[0x56];
        piVar7 = (int *)local_60.dwHighDateTime;
        piVar10 = DAT_00772400;
      }
      if ((float)(piVar7[1] + -1) <= fVar25) {
        iVar8 = FUN_0043d660();
        if (((float)local_2c < (float)(*(int *)(iVar8 + 0xc) + 1)) &&
           (iVar8 = FUN_0043d660(), (float)(*(int *)(iVar8 + 4) + -1) <= (float)local_2c)) {
          local_30[0x56] = (int)local_2c;
        }
        goto LAB_0052c0ca;
      }
    }
    uVar20 = pVVar3->i_44;
    local_60.dwHighDateTime = (DWORD)(piVar10 + 0x28ca);
    if (uVar20 < 8) {
      local_28 = (int *)(local_60.dwHighDateTime + uVar20 * 4 * 4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_28 = (int *)local_60.dwHighDateTime;
      uVar20 = pVVar3->i_44;
      piVar10 = DAT_00772400;
    }
    piVar10 = piVar10 + 0x28ca;
    if (uVar20 < 8) {
      piVar10 = piVar10 + uVar20 * 4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    fVar25 = (float)((piVar10[3] + local_28[1]) / 2);
    dVar24 = (double)(fVar25 - (float)local_2c);
    dVar23 = (double)(fVar25 - (float)local_30[0x56]);
    if ((double)CONCAT44((uint)((ulonglong)dVar24 >> 0x20) & local_b0._4_4_,
                         SUB84(dVar24,0) & (uint)local_b0) <
        (double)CONCAT44((uint)((ulonglong)dVar23 >> 0x20) & local_b0._4_4_,
                         SUB84(dVar23,0) & (uint)local_b0)) {
      local_30[0x56] = (int)local_2c;
    }
  }
LAB_0052c0ca:
  fVar25 = pVVar3->f_9c;
  if ((fVar25 != 0.0) || (pVVar3->f_a0 != 0.0)) {
    local_30[0x58] = (int)((float)local_30[0x58] - pVVar3->f_a0 * 0.005);
    local_30[0x59] = (int)(fVar25 * 0.005 + (float)local_30[0x59]);
  }
  if (pVVar3->f_a8 != 1.0) {
    local_30[0x57] = (int)(pVVar3->f_a8 * (float)local_30[0x57]);
  }
LAB_0052c148:
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
  return;
}

