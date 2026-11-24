
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CDXExecBuf__Render(void)

{
  float fVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  LPCRITICAL_SECTION p_Var6;
  undefined4 *puVar7;
  void *pvVar8;
  float fVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  PostProcessOptionManager *this;
  int iVar17;
  int *piVar18;
  int this;
  char *pcVar19;
  undefined **ppuVar20;
  char *pcVar21;
  int *piVar22;
  code *pcVar23;
  bool bVar24;
  undefined8 uVar25;
  PostEffectOption PVar26;
  int local_44;
  int local_40;
  float local_3c;
  int local_38;
  int *local_34;
  int local_28;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fc69d;
  local_10 = ExceptionList;
  uVar10 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppuVar20 = &PTR_0071ce50;
  pbVar11 = (byte *)(*(int *)(DAT_00772400 + 0xa3fc) + 0xc);
  do {
    bVar2 = *pbVar11;
    bVar24 = bVar2 < *(byte *)ppuVar20;
    if (bVar2 != *(byte *)ppuVar20) {
LAB_00452953:
      uVar12 = -(uint)bVar24 | 1;
      goto LAB_00452958;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar11[1];
    bVar24 = bVar2 < *(byte *)((int)ppuVar20 + 1);
    if (bVar2 != *(byte *)((int)ppuVar20 + 1)) goto LAB_00452953;
    pbVar11 = pbVar11 + 2;
    ppuVar20 = (undefined **)((int)ppuVar20 + 2);
  } while (bVar2 != 0);
  uVar12 = 0;
LAB_00452958:
  if (uVar12 != 0) {
    FUN_00451600((int *)(DAT_00772400 + 0xa3fc));
    FUN_006b9200(&PTR_0071ce50);
  }
  iVar4 = DAT_0076a338;
  this->i_804c = 0;
  this->i_8050 = 0;
  this->i_8054 = 0;
  pvVar8 = ThreadLocalStoragePointer;
  if (*(char *)(iVar4 + 0x101) != '\0') {
    FUN_00450dc0();
    __controlfp(0x300,0x100);
    ExceptionList = local_10;
    return;
  }
  this->s_06 = 1;
                    /* WARNING: Load size is inaccurate */
  iVar4 = *pvVar8;
  if ((*(int *)(iVar4 + 4) < DAT_00c86b98) &&
     (FUN_006cebf4(&DAT_00c86b98,uVar10), iVar14 = DAT_00783650, DAT_00c86b98 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    _DAT_00c86b9c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "CDXExecBuf::Render()";
    *(int *)(&DAT_00773650 + iVar13) = iVar14;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c86b98);
  }
  FUN_00405af0(&DAT_00c86b9c);
  local_8 = 0;
  iVar14 = FUN_0044d010();
  iVar13 = FUN_0045a470();
  FUN_0045e120(0);
  *(undefined4 *)(iVar13 + 0x1e58) = 0;
  *(undefined4 *)(iVar13 + 0x1e5c) = 0;
  *(undefined4 *)(iVar13 + 0x1e60) = 0;
  *(undefined4 *)(iVar13 + 0x1e64) = 0;
  *(undefined4 *)(iVar13 + 0x1bfc) = 0xffffffff;
  *(undefined4 *)(iVar13 + 0x1c4c) = 0xffffffff;
  FUN_0045ece0();
  local_40 = 0;
  local_44 = 0;
  iVar15 = (**(code **)(**(int **)(iVar14 + 0x80) + 0x3c))(1,this + 0x800c);
  if (*(int *)(iVar14 + 0x8c) != iVar15) {
    *(int *)(iVar14 + 0x8c) = iVar15;
  }
  local_3c = 0.0;
  *(int *)(DAT_00772400 + 0x7c) = *(int *)(DAT_00772400 + 0x7c) + this->i_08;
  local_18 = DAT_007683d0;
  if (0 < this->i_08) {
    piVar22 = (int *)(this + 0xc);
    do {
      fVar9 = local_3c;
      if ((*(int *)(iVar4 + 4) < DAT_00c86ba0) &&
         (FUN_006cebf4(&DAT_00c86ba0), iVar15 = DAT_00783650, DAT_00c86ba0 == -1)) {
        iVar16 = DAT_00783650 * 0x40;
        DAT_00c86ba4 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar16) = "CDXExecBuf::Render() Per-Job";
        *(int *)(&DAT_00773650 + iVar16) = iVar15;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c86ba0);
      }
      iVar16 = DAT_00c86ba4;
      uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00c86ba4 * 0x40);
      iVar15 = FUN_0043fcc0();
      *(undefined4 *)(iVar15 + *(int *)(iVar15 + 0x8000) * 4) = uVar5;
      *(int *)(iVar15 + 0x8000) = *(int *)(iVar15 + 0x8000) + 1;
      iVar15 = (&DAT_00773654)[iVar16 * 0x10];
      if (iVar15 == 0) {
        uVar25 = FUN_006bd180();
        iVar15 = (&DAT_00773654)[iVar16 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar16 * 0x10) = uVar25;
      }
      (&DAT_00773654)[iVar16 * 0x10] = iVar15 + 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      if ((uint)local_3c < 0x2000) {
        piVar18 = piVar22 + (int)local_3c;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar18 = piVar22;
      }
      if (*(char *)(*piVar18 + 0x55) == '\0') {
        if (*(char *)(DAT_0076a338 + 0x2839) == '\0') {
          if ((uint)local_3c < 0x2000) {
            piVar18 = piVar22 + (int)local_3c;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar18 = piVar22;
          }
          if (*(int *)(*piVar18 + 0x3c) != 0) {
            if ((uint)local_3c < 0x2000) {
              piVar18 = piVar22 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar18 = piVar22;
            }
            if (*(int *)(*piVar18 + 0x40) == 0) {
              local_34 = (int *)0x0;
            }
            else if ((uint)local_3c < 0x2000) {
              local_34 = (int *)FUN_00449d40();
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_34 = (int *)FUN_00449d40();
            }
            if ((uint)local_3c < 0x2000) {
              local_28 = FUN_00449d40();
              iVar15 = *(int *)(*(int *)(piVar22[(int)local_3c] + 0x44) + 0x14);
              piVar18 = piVar22 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_28 = FUN_00449d40();
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar15 = *(int *)(*(int *)(*piVar22 + 0x44) + 0x14);
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar18 = piVar22;
            }
            if (*(int *)(*(int *)(*piVar18 + 0x44) + 0x10) != 0) {
              if ((uint)local_3c < 0x2000) {
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar18 = piVar22;
              }
              iVar17 = *(int *)(*piVar18 + 0x44);
              iVar16 = *(int *)(iVar17 + 0x10);
              while (0 < iVar16) {
                iVar16 = iVar16 + -1;
                *(int *)(iVar17 + 0x10) = iVar16;
                if ((iVar16 == 0) && (*(int *)(iVar17 + 0x14) != 0)) {
                  if ((int *)**(int **)(iVar17 + 0x14) != (int *)0x0) {
                    (**(code **)(*(int *)**(int **)(iVar17 + 0x14) + 0x18))();
                    iVar16 = *(int *)(iVar17 + 0x10);
                  }
                  *(undefined4 *)(iVar17 + 0xc) = 0;
                }
              }
            }
            local_38 = 0;
            if (iVar15 == 0) {
              if (0x1fff < (uint)local_3c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_38 = FUN_0045feb0();
            }
            if ((*(int *)(iVar4 + 4) < DAT_00c86ba8) &&
               (FUN_006cebf4(&DAT_00c86ba8), iVar16 = DAT_00783650, DAT_00c86ba8 == -1)) {
              iVar17 = DAT_00783650 * 0x40;
              DAT_00c86bac = DAT_00783650;
              *(char **)(&DAT_0077368c + iVar17) = "CDXExecBuf::Render() Stateswitch";
              *(int *)(&DAT_00773650 + iVar17) = iVar16;
              DAT_00783650 = DAT_00783650 + 1;
              FUN_006cebaa(&DAT_00c86ba8);
            }
            iVar17 = DAT_00c86bac;
            uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bac * 0x40);
            iVar16 = FUN_0043fcc0();
            *(undefined4 *)(iVar16 + *(int *)(iVar16 + 0x8000) * 4) = uVar5;
            *(int *)(iVar16 + 0x8000) = *(int *)(iVar16 + 0x8000) + 1;
            iVar16 = (&DAT_00773654)[iVar17 * 0x10];
            if (iVar16 == 0) {
              uVar25 = FUN_006bd180();
              iVar16 = (&DAT_00773654)[iVar17 * 0x10];
              *(undefined8 *)(&DAT_00773658 + iVar17 * 0x10) = uVar25;
            }
            (&DAT_00773654)[iVar17 * 0x10] = iVar16 + 1;
            pcVar23 = RaiseException_exref;
            local_8 = CONCAT31(local_8._1_3_,2);
            if ((uint)local_3c < 0x2000) {
              FUN_0045e120(*(undefined4 *)(piVar22[(int)local_3c] + 0x10));
              piVar18 = piVar22 + (int)local_3c;
              pcVar23 = RaiseException_exref;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              FUN_0045e120(*(undefined4 *)(*piVar22 + 0x10));
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar18 = piVar22;
            }
            uVar10 = *(uint *)(*piVar18 + 0x14);
            if (0xff < uVar10) {
              uVar10 = 0xff;
            }
            uVar10 = uVar10 | ((uVar10 << 8 | uVar10) << 8 | uVar10) << 8;
            *(uint *)(iVar13 + 0x1bfc) = uVar10;
            *(uint *)(iVar13 + 0x1c4c) = uVar10;
            if (local_28 != 0) {
              *(int *)(iVar13 + 0x1e58) = local_28;
            }
            *(int **)(iVar13 + 0x1e5c) = local_34;
            FUN_0045e240();
            local_8 = CONCAT31(local_8._1_3_,1);
            FUN_0043fd30();
            if ((local_28 != local_40) && (local_40 = local_28, local_28 != 0)) {
              this->i_804c = this->i_804c + 1;
              this->i_8050 = this->i_8050 + *(int *)(local_28 + 0x84);
            }
            if ((local_34 != (int *)local_44) && (local_44 = (int)local_34, local_34 != (int *)0x0))
            {
              this->i_804c = this->i_804c + 1;
              this->i_8050 = this->i_8050 + *(int *)((int)local_34 + 0x84)
              ;
            }
            if ((uint)local_3c < 0x2000) {
              piVar18 = piVar22 + (int)local_3c;
            }
            else {
              (*pcVar23)(0xc000008c,1,0,0);
              piVar18 = piVar22;
            }
            if (*(int *)(*piVar18 + 0x44) != 0) {
              if ((uint)local_3c < 0x2000) {
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                (*pcVar23)(0xc000008c,1,0,0);
                piVar18 = piVar22;
              }
              if (*(char *)(*(int *)(*piVar18 + 0x44) + 8) == '\0') {
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  (*pcVar23)(0xc000008c,1,0,0);
                  piVar18 = piVar22;
                }
                if (*(char *)(*(int *)(*piVar18 + 0x44) + 0x30) == '\0') {
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    (*pcVar23)(0xc000008c,1,0,0);
                    piVar18 = piVar22;
                  }
                  *(undefined1 *)(*(int *)(*piVar18 + 0x44) + 0x30) = 1;
                  _DAT_0076a2d0 = _DAT_0076a2d0 + 1;
                }
                else {
                  _DAT_0076a2cc = _DAT_0076a2cc + 1;
                }
              }
              else {
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  (*pcVar23)(0xc000008c,1,0,0);
                  piVar18 = piVar22;
                }
                if (*(char *)(*(int *)(*piVar18 + 0x44) + 0x30) == '\0') {
                  if ((uint)local_3c < 0x2000) {
                    *(undefined1 *)(*(int *)(piVar22[(int)local_3c] + 0x44) + 0x30) = 1;
                    _DAT_0076a2d8 = _DAT_0076a2d8 + 1;
                  }
                  else {
                    (*pcVar23)(0xc000008c,1,0,0);
                    *(undefined1 *)(*(int *)(*piVar22 + 0x44) + 0x30) = 1;
                    _DAT_0076a2d8 = _DAT_0076a2d8 + 1;
                  }
                }
                else {
                  _DAT_0076a2d4 = _DAT_0076a2d4 + 1;
                }
              }
              if ((uint)local_3c < 0x2000) {
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                (*pcVar23)(0xc000008c,1,0,0);
                piVar18 = piVar22;
              }
              if (*(int *)(*(int *)(*piVar18 + 0x44) + 0x28) == 0) {
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  (*pcVar23)(0xc000008c,1,0,0);
                  piVar18 = piVar22;
                }
                pcVar21 = &DAT_007728c0;
                pcVar19 = (char *)(*(int *)(*piVar18 + 0x50) + 0xc);
                do {
                  cVar3 = *pcVar19;
                  pcVar19 = pcVar19 + 1;
                  *pcVar21 = cVar3;
                  pcVar21 = pcVar21 + 1;
                } while (cVar3 != '\0');
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  (*pcVar23)(0xc000008c,1,0,0);
                  piVar18 = piVar22;
                }
                this->i_8054 =
                     this->i_8054 + *(int *)(*(int *)(*piVar18 + 0x44) + 0x24) / 3;
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  (*pcVar23)(0xc000008c,1,0,0);
                  piVar18 = piVar22;
                }
                iVar16 = *(int *)(*(int *)(*piVar18 + 0x44) + 0x24);
                iVar16 = (int)((ulonglong)((longlong)iVar16 * 0x55555555) >> 0x20) - iVar16;
                local_18 = local_18 + ((iVar16 >> 1) - (iVar16 >> 0x1f));
                if (iVar15 == 0) {
                  if ((*(int *)(iVar4 + 4) < DAT_00c86bc0) &&
                     (FUN_006cebf4(&DAT_00c86bc0), iVar16 = DAT_00783650, DAT_00c86bc0 == -1)) {
                    iVar17 = DAT_00783650 * 0x40;
                    DAT_00c86bc4 = DAT_00783650;
                    *(char **)(&DAT_0077368c + iVar17) = "CDXExecBuf::Render() DrawPrimitive";
                    *(int *)(&DAT_00773650 + iVar17) = iVar16;
                    DAT_00783650 = DAT_00783650 + 1;
                    FUN_006cebaa(&DAT_00c86bc0);
                  }
                  iVar17 = DAT_00c86bc4;
                  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bc4 * 0x40);
                  iVar16 = FUN_0043fcc0();
                  *(undefined4 *)(iVar16 + *(int *)(iVar16 + 0x8000) * 4) = uVar5;
                  *(int *)(iVar16 + 0x8000) = *(int *)(iVar16 + 0x8000) + 1;
                  iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                  if (iVar16 == 0) {
                    uVar25 = FUN_006bd180();
                    iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                    *(undefined8 *)(&DAT_00773658 + iVar17 * 0x10) = uVar25;
                  }
                  (&DAT_00773654)[iVar17 * 0x10] = iVar16 + 1;
                  local_8._0_1_ = 5;
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = piVar22;
                  }
                  iVar16 = (**(code **)(**(int **)(iVar14 + 0x80) + 0x2c))
                                     (*(undefined4 *)(*piVar18 + 0xc),
                                      *(undefined4 *)(*(int *)(*piVar18 + 0x44) + 0x20),local_38,
                                      *(undefined4 *)(*(int *)(*piVar18 + 0x44) + 0x24),0);
                  if (*(int *)(iVar14 + 0x8c) != iVar16) {
                    *(int *)(iVar14 + 0x8c) = iVar16;
                  }
                }
                else {
                  if ((*(int *)(iVar4 + 4) < DAT_00c86bc8) &&
                     (FUN_006cebf4(&DAT_00c86bc8), iVar16 = DAT_00783650, DAT_00c86bc8 == -1)) {
                    iVar17 = DAT_00783650 * 0x40;
                    DAT_00c86bcc = DAT_00783650;
                    *(char **)(&DAT_0077368c + iVar17) = "CDXExecBuf::Render() DrawVB";
                    *(int *)(&DAT_00773650 + iVar17) = iVar16;
                    DAT_00783650 = DAT_00783650 + 1;
                    FUN_006cebaa(&DAT_00c86bc8);
                  }
                  iVar17 = DAT_00c86bcc;
                  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bcc * 0x40);
                  iVar16 = FUN_0043fcc0();
                  *(undefined4 *)(iVar16 + *(int *)(iVar16 + 0x8000) * 4) = uVar5;
                  *(int *)(iVar16 + 0x8000) = *(int *)(iVar16 + 0x8000) + 1;
                  iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                  if (iVar16 == 0) {
                    uVar25 = FUN_006bd180();
                    iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                    *(undefined8 *)(&DAT_00773658 + iVar17 * 0x10) = uVar25;
                  }
                  (&DAT_00773654)[iVar17 * 0x10] = iVar16 + 1;
                  local_8._0_1_ = 6;
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = piVar22;
                  }
                  iVar16 = (**(code **)(**(int **)(iVar14 + 0x80) + 0x50))
                                     (*(undefined4 *)(*piVar18 + 0xc),
                                      **(undefined4 **)(*(int *)(*piVar18 + 0x44) + 0x14),0,
                                      *(undefined4 *)(*(int *)(*piVar18 + 0x44) + 0x24),0);
                  if (*(int *)(iVar14 + 0x8c) != iVar16) {
                    *(int *)(iVar14 + 0x8c) = iVar16;
                  }
                }
                local_8 = CONCAT31(local_8._1_3_,1);
                FUN_0043fd30();
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar18 = piVar22;
                }
                if (*(int *)(*piVar18 + 0x3c) != 0) {
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = (int *)(*(int *)(piVar22[(int)local_3c] + 0x3c) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    iVar16 = *(int *)(piVar22[(int)local_3c] + 0x3c);
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = (int *)(*(int *)(*piVar22 + 0x3c) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar16 = *(int *)(*piVar22 + 0x3c);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = piVar22;
                  }
                  *(int *)(iVar16 + 0x2c) =
                       *(int *)(iVar16 + 0x2c) + *(int *)(*(int *)(*piVar18 + 0x44) + 0x24) / 3;
                }
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar18 = piVar22;
                }
                if (*(int *)(*piVar18 + 0x40) != 0) {
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = (int *)(*(int *)(piVar22[(int)local_3c] + 0x40) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    iVar16 = *(int *)(piVar22[(int)local_3c] + 0x40);
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = (int *)(*(int *)(*piVar22 + 0x40) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar16 = *(int *)(*piVar22 + 0x40);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = piVar22;
                  }
                  *(int *)(iVar16 + 0x2c) =
                       *(int *)(iVar16 + 0x2c) + *(int *)(*(int *)(*piVar18 + 0x44) + 0x24) / 3;
                }
              }
              else {
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  (*pcVar23)(0xc000008c,1,0,0);
                  piVar18 = piVar22;
                }
                this->i_8054 =
                     this->i_8054 + *(int *)(*(int *)(*piVar18 + 0x44) + 0x2c) / 3;
                if ((uint)local_3c < 0x2000) {
                  iVar16 = *(int *)(*(int *)(piVar22[(int)local_3c] + 0x44) + 0x2c);
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  (*pcVar23)(0xc000008c,1,0,0);
                  iVar16 = *(int *)(*(int *)(*piVar22 + 0x44) + 0x2c);
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar18 = piVar22;
                }
                local_18 = local_18 - iVar16 / 3;
                if (*(int *)(*piVar18 + 0x3c) != 0) {
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = (int *)(*(int *)(piVar22[(int)local_3c] + 0x3c) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    iVar16 = *(int *)(piVar22[(int)local_3c] + 0x3c);
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = (int *)(*(int *)(*piVar22 + 0x3c) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar16 = *(int *)(*piVar22 + 0x3c);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = piVar22;
                  }
                  *(int *)(iVar16 + 0x2c) =
                       *(int *)(iVar16 + 0x2c) + *(int *)(*(int *)(*piVar18 + 0x44) + 0x2c) / 3;
                }
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar18 = piVar22;
                }
                if (*(int *)(*piVar18 + 0x40) != 0) {
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = (int *)(*(int *)(piVar22[(int)local_3c] + 0x40) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    iVar16 = *(int *)(piVar22[(int)local_3c] + 0x40);
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = (int *)(*(int *)(*piVar22 + 0x40) + 0x28);
                    *piVar18 = *piVar18 + 1;
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar16 = *(int *)(*piVar22 + 0x40);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = piVar22;
                  }
                  *(int *)(iVar16 + 0x2c) =
                       *(int *)(iVar16 + 0x2c) + *(int *)(*(int *)(*piVar18 + 0x44) + 0x2c) / 3;
                }
                if ((uint)local_3c < 0x2000) {
                  piVar18 = piVar22 + (int)local_3c;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar18 = piVar22;
                }
                pcVar21 = &DAT_007728c0;
                pcVar19 = (char *)(*(int *)(*piVar18 + 0x50) + 0xc);
                do {
                  cVar3 = *pcVar19;
                  pcVar19 = pcVar19 + 1;
                  *pcVar21 = cVar3;
                  pcVar21 = pcVar21 + 1;
                } while (cVar3 != '\0');
                if (iVar15 == 0) {
                  if ((*(int *)(iVar4 + 4) < DAT_00c86bb0) &&
                     (FUN_006cebf4(&DAT_00c86bb0), iVar16 = DAT_00783650, DAT_00c86bb0 == -1)) {
                    iVar17 = DAT_00783650 * 0x40;
                    DAT_00c86bb4 = DAT_00783650;
                    *(char **)(&DAT_0077368c + iVar17) = "CDXExecBuf::Render() DrawIndexedPrimitive"
                    ;
                    *(int *)(&DAT_00773650 + iVar17) = iVar16;
                    DAT_00783650 = DAT_00783650 + 1;
                    FUN_006cebaa(&DAT_00c86bb0);
                  }
                  iVar17 = DAT_00c86bb4;
                  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bb4 * 0x40);
                  iVar16 = FUN_0043fcc0();
                  *(undefined4 *)(iVar16 + *(int *)(iVar16 + 0x8000) * 4) = uVar5;
                  *(int *)(iVar16 + 0x8000) = *(int *)(iVar16 + 0x8000) + 1;
                  iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                  if (iVar16 == 0) {
                    uVar25 = FUN_006bd180();
                    iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                    *(undefined8 *)(&DAT_00773658 + iVar17 * 0x10) = uVar25;
                  }
                  (&DAT_00773654)[iVar17 * 0x10] = iVar16 + 1;
                  local_8._0_1_ = 3;
                  if ((uint)local_3c < 0x2000) {
                    local_34 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    local_34 = piVar22;
                  }
                  iVar16 = (**(code **)(**(int **)(iVar14 + 0x80) + 0x54))
                                     (*(undefined4 *)(*local_34 + 0xc),
                                      *(undefined4 *)(*(int *)(*local_34 + 0x44) + 0x20),local_38,
                                      *(undefined4 *)(*(int *)(*local_34 + 0x44) + 0x24),
                                      *(undefined4 *)(*(int *)(*local_34 + 0x44) + 0x28),
                                      *(undefined4 *)(*(int *)(*local_34 + 0x44) + 0x2c),0);
                  if (*(int *)(iVar14 + 0x8c) != iVar16) {
                    *(int *)(iVar14 + 0x8c) = iVar16;
                  }
                }
                else {
                  if ((*(int *)(iVar4 + 4) < DAT_00c86bb8) &&
                     (FUN_006cebf4(&DAT_00c86bb8), iVar16 = DAT_00783650, DAT_00c86bb8 == -1)) {
                    iVar17 = DAT_00783650 * 0x40;
                    DAT_00c86bbc = DAT_00783650;
                    *(char **)(&DAT_0077368c + iVar17) = "CDXExecBuf::Render() DrawIndexedVB";
                    *(int *)(&DAT_00773650 + iVar17) = iVar16;
                    DAT_00783650 = DAT_00783650 + 1;
                    FUN_006cebaa(&DAT_00c86bb8);
                  }
                  iVar17 = DAT_00c86bbc;
                  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00c86bbc * 0x40);
                  iVar16 = FUN_0043fcc0();
                  *(undefined4 *)(iVar16 + *(int *)(iVar16 + 0x8000) * 4) = uVar5;
                  *(int *)(iVar16 + 0x8000) = *(int *)(iVar16 + 0x8000) + 1;
                  iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                  if (iVar16 == 0) {
                    uVar25 = FUN_006bd180();
                    iVar16 = (&DAT_00773654)[iVar17 * 0x10];
                    *(undefined8 *)(&DAT_00773658 + iVar17 * 0x10) = uVar25;
                  }
                  (&DAT_00773654)[iVar17 * 0x10] = iVar16 + 1;
                  local_8._0_1_ = 4;
                  if ((uint)local_3c < 0x2000) {
                    piVar18 = piVar22 + (int)local_3c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar18 = piVar22;
                  }
                  iVar16 = (**(code **)(**(int **)(iVar14 + 0x80) + 0x4c))
                                     (*(undefined4 *)(*piVar18 + 0xc),
                                      **(undefined4 **)(*(int *)(*piVar18 + 0x44) + 0x14),0,
                                      *(undefined4 *)(*(int *)(*piVar18 + 0x44) + 0x24),
                                      *(undefined4 *)(*(int *)(*piVar18 + 0x44) + 0x28),
                                      *(undefined4 *)(*(int *)(*piVar18 + 0x44) + 0x2c),0);
                  if (*(int *)(iVar14 + 0x8c) != iVar16) {
                    *(int *)(iVar14 + 0x8c) = iVar16;
                  }
                }
                local_8 = CONCAT31(local_8._1_3_,1);
                FUN_0043fd30();
              }
              DAT_007728c0 = 0;
            }
            if (iVar15 == 0) {
              if ((uint)local_3c < 0x2000) {
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar18 = piVar22;
              }
              iVar15 = *(int *)(*piVar18 + 0x44);
              piVar18 = (int *)(iVar15 + 0x10);
              *piVar18 = *piVar18 + -1;
              if ((*piVar18 == 0) && (*(int **)(iVar15 + 0x14) != (int *)0x0)) {
                piVar18 = (int *)**(int **)(iVar15 + 0x14);
                if (piVar18 != (int *)0x0) {
                  (**(code **)(*piVar18 + 0x18))();
                }
                *(undefined4 *)(iVar15 + 0xc) = 0;
              }
            }
            if ((uint)local_3c < 0x2000) {
              piVar18 = piVar22 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar18 = piVar22;
            }
            p_Var6 = *(LPCRITICAL_SECTION *)(*piVar18 + 0x3c);
            if (p_Var6[2].RecursionCount == 0) {
              *(undefined1 *)&p_Var6[1].OwningThread = 0;
            }
            else {
              EnterCriticalSection(p_Var6);
              *(undefined1 *)&p_Var6[1].OwningThread = 0;
              *(undefined1 *)&p_Var6[1].DebugInfo = 0;
              LeaveCriticalSection(p_Var6);
            }
            if ((uint)local_3c < 0x2000) {
              piVar18 = piVar22 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar18 = piVar22;
            }
            if (*(int *)(*piVar18 + 0x40) != 0) {
              if ((uint)local_3c < 0x2000) {
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar18 = piVar22;
              }
              p_Var6 = *(LPCRITICAL_SECTION *)(*piVar18 + 0x40);
              if (p_Var6[2].RecursionCount == 0) {
                *(undefined1 *)&p_Var6[1].OwningThread = 0;
              }
              else {
                EnterCriticalSection(p_Var6);
                *(undefined1 *)&p_Var6[1].OwningThread = 0;
                *(undefined1 *)&p_Var6[1].DebugInfo = 0;
                LeaveCriticalSection(p_Var6);
              }
            }
            if (local_18 < 1) {
              local_18 = DAT_007683d0;
              Sleep(0);
            }
          }
        }
        if (*(char *)(DAT_0076a338 + 0x19f19) != '\0') {
          if ((uint)local_3c < 0x2000) {
            piVar18 = piVar22 + (int)local_3c;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar18 = piVar22;
          }
          if (*(int *)(*(int *)(*piVar18 + 0x44) + 0x20) == 0x1c2) {
            local_38 = 0;
            iVar15 = 0;
            while( true ) {
              if ((uint)local_3c < 0x2000) {
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar18 = piVar22;
              }
              if (*(int *)(*(int *)(*piVar18 + 0x44) + 0x24) <= local_38) break;
              if ((uint)local_3c < 0x2000) {
                *(undefined4 *)
                 (*(int *)(*(int *)(piVar22[(int)local_3c] + 0x44) + 0xc) + 0xc + iVar15) =
                     0xff00ff00;
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                *(undefined4 *)(*(int *)(*(int *)(*piVar22 + 0x44) + 0xc) + 0xc + iVar15) =
                     0xff00ff00;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar18 = piVar22;
              }
              local_38 = local_38 + 1;
              *(undefined4 *)(*(int *)(*(int *)(*piVar18 + 0x44) + 0xc) + 0x10 + iVar15) =
                   0xff00ff00;
              iVar15 = iVar15 + 0x1c;
            }
          }
          if ((uint)local_3c < 0x2000) {
            piVar18 = piVar22 + (int)local_3c;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar18 = piVar22;
          }
          if (*(int *)(*(int *)(*piVar18 + 0x44) + 0x20) == 0x2c2) {
            local_38 = 0;
            iVar15 = 0;
            while( true ) {
              if ((uint)local_3c < 0x2000) {
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar18 = piVar22;
              }
              if (*(int *)(*(int *)(*piVar18 + 0x44) + 0x24) <= local_38) break;
              if ((uint)local_3c < 0x2000) {
                *(undefined4 *)
                 (*(int *)(*(int *)(piVar22[(int)local_3c] + 0x44) + 0xc) + 0xc + iVar15) =
                     0xff00ff00;
                piVar18 = piVar22 + (int)local_3c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                *(undefined4 *)(*(int *)(*(int *)(*piVar22 + 0x44) + 0xc) + 0xc + iVar15) =
                     0xff00ff00;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar18 = piVar22;
              }
              local_38 = local_38 + 1;
              *(undefined4 *)(*(int *)(*(int *)(*piVar18 + 0x44) + 0xc) + 0x10 + iVar15) =
                   0xff00ff00;
              iVar15 = iVar15 + 0x24;
            }
          }
        }
        if ((uint)local_3c < 0x2000) {
          piVar18 = piVar22 + (int)local_3c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar18 = piVar22;
        }
        puVar7 = (undefined4 *)*piVar18;
        *piVar18 = 0;
        if (puVar7 != (undefined4 *)0x0) {
          LOCK();
          iVar15 = puVar7[1] + -1;
          puVar7[1] = iVar15;
          UNLOCK();
          if (iVar15 == 0) {
            (**(code **)*puVar7)(1);
          }
        }
      }
      else {
        fVar1 = *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c);
        local_3c = 1.0;
        if (1.0 <= fVar1) {
          local_3c = fVar1;
        }
        if (2.5 < local_3c) {
          local_3c = 2.5;
        }
        if (*(int *)(iVar14 + 0x84) != 0) {
          PVar26 = 1;
          this = PostProcessOptionManager::GetInstance();
          iVar15 = PostProcessOptionManager::GetModeSet(this,PVar26);
          if ((iVar15 != 0) &&
             (((*(char *)(DAT_00772400 + 0x8c) == '\0' && (*(char *)(DAT_00772400 + 0x8f) != '\0'))
              || (*(char *)(DAT_00772400 + 0x90) != '\0')))) {
            (**(code **)(**(int **)(iVar14 + 0x84) + 0x14))(local_3c);
          }
        }
      }
      local_8 = local_8 & 0xffffff00;
      FUN_0043fd30();
      local_3c = (float)((int)fVar9 + 1);
    } while ((int)local_3c < this->i_08);
  }
  __controlfp(0x300,0x100);
  *(undefined4 *)(iVar13 + 0x1e58) = 0;
  *(undefined4 *)(iVar13 + 0x1e5c) = 0;
  FUN_0045ece0();
  this->s_06 = 0x100;
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

