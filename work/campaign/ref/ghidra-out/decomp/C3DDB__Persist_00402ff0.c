
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void C3DDB__Persist(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  uint *puVar6;
  undefined4 uVar7;
  long _Offset;
  LPVOID lpTlsValue;
  undefined4 *in_ECX;
  uint *dwMinimumWorkingSetSize;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined8 uVar12;
  uint **lpMinimumWorkingSetSize;
  uint **lpMaximumWorkingSetSize;
  uint *local_44;
  int *local_40;
  uint *local_3c;
  uint *local_38;
  int *local_34;
  int *local_30;
  FILE *local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  uint *local_1c;
  int local_18;
  short local_14 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f94f1;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_28 = *ThreadLocalStoragePointer;
  if ((*(int *)(local_28 + 4) < DAT_00c3ca1c) &&
     (FUN_006cebf4(&DAT_00c3ca1c,uVar2), iVar3 = DAT_00783650, DAT_00c3ca1c == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00c3ca20 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc)";
    *(int *)(&DAT_00773650 + iVar9) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c3ca1c);
  }
  iVar9 = DAT_00c3ca20;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00c3ca20 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar12;
  }
  puVar10 = param_1;
  (&DAT_00773654)[iVar9 * 0x10] = iVar3 + 1;
  local_8 = 0;
  if (*(char *)(param_1 + 1) == '\0') {
    if ((*(int *)(local_28 + 4) < DAT_00c3ca24) &&
       (FUN_006cebf4(&DAT_00c3ca24,uVar2), iVar3 = DAT_00783650, DAT_00c3ca24 == -1)) {
      iVar9 = DAT_00783650 * 0x40;
      _DAT_00c3ca28 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Mapping";
      *(int *)(&DAT_00773650 + iVar9) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00c3ca24);
    }
    FUN_00405af0(&DAT_00c3ca28);
    piVar11 = (int *)puVar10[4];
    if (piVar11 != (int *)0x0) {
      *piVar11 = *piVar11 + 1;
    }
    pvVar4 = CreateFileA((LPCSTR)(piVar11 + 3),0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                         (HANDLE)0x0);
    in_ECX[1] = pvVar4;
    DVar5 = GetFileSize(pvVar4,(LPDWORD)0x0);
    lpMaximumWorkingSetSize = &local_38;
    lpMinimumWorkingSetSize = &local_3c;
    pvVar4 = GetCurrentProcess();
    GetProcessWorkingSetSize
              (pvVar4,(PSIZE_T)lpMinimumWorkingSetSize,(PSIZE_T)lpMaximumWorkingSetSize);
    puVar6 = (uint *)((int)local_38 + DVar5 / 0x14);
    dwMinimumWorkingSetSize = (uint *)((int)local_3c + DVar5 / 0x14);
    local_3c = dwMinimumWorkingSetSize;
    local_38 = puVar6;
    pvVar4 = GetCurrentProcess();
    SetProcessWorkingSetSize(pvVar4,(SIZE_T)dwMinimumWorkingSetSize,(SIZE_T)puVar6);
    pvVar4 = CreateFileMappingA((HANDLE)in_ECX[1],(LPSECURITY_ATTRIBUTES)0x0,2,0,0,(LPCSTR)0x0);
    *in_ECX = pvVar4;
    DAT_0076a250 = MapViewOfFile(pvVar4,4,0,0,0);
    in_ECX[2] = DAT_0076a250;
    GetLastError();
    if (DAT_0076a250 == (LPVOID)0x0) {
      MessageBoxA((HWND)0x0,(LPCSTR)(piVar11 + 3),"MemMapped File failed!",0);
      local_8 = CONCAT31(local_8._1_3_,1);
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
        FUN_006ba940();
      }
      FUN_0043fd30();
    }
    else {
      local_8 = CONCAT31(local_8._1_3_,2);
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
        FUN_006ba940();
      }
      FUN_0043fd30();
      if ((*(int *)(local_28 + 4) < DAT_00c3ca2c) &&
         (FUN_006cebf4(&DAT_00c3ca2c), iVar3 = DAT_00783650, DAT_00c3ca2c == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        _DAT_00c3ca30 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Header";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca2c);
      }
      FUN_00405af0(&DAT_00c3ca30);
      puVar10 = param_1;
      local_8._0_1_ = 3;
      local_3c = (uint *)FUN_006ba590(&local_38);
      local_8._0_1_ = 4;
      piVar11 = in_ECX + 3;
      piVar8 = (int *)*local_3c;
      piVar1 = (int *)*piVar11;
      *piVar11 = (int)piVar8;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_006ba940();
      }
      *(undefined4 *)(*piVar11 + 8) = *(undefined4 *)(*local_3c + 8);
      local_8._0_1_ = 5;
      if ((local_38 != (uint *)0x0) && (*local_38 = *local_38 - 1, *local_38 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 3;
      local_3c = (uint *)FUN_006ba590(&local_38);
      local_8._0_1_ = 6;
      piVar8 = (int *)*local_3c;
      piVar1 = (int *)*piVar11;
      *piVar11 = (int)piVar8;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_006ba940();
      }
      *(undefined4 *)(*piVar11 + 8) = *(undefined4 *)(*local_3c + 8);
      local_8._0_1_ = 7;
      if ((local_38 != (uint *)0x0) && (*local_38 = *local_38 - 1, *local_38 == 0)) {
        FUN_006ba940();
      }
      FUN_00445d30(&DAT_00b83658,"DB Load");
      local_8._0_1_ = 0;
      FUN_0043fd30();
      FUN_006b95d0(piVar11);
      local_8._0_1_ = 8;
      FUN_006b9500(&DAT_0071c880);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
        FUN_006ba940();
      }
      piVar11 = local_30;
      local_2c = _fopen((char *)(local_30 + 3),"w");
      if (local_2c != (FILE *)0x0) {
        uVar7 = FUN_006de91d(*puVar10);
        FUN_00405ab0(local_2c,"Header %d\n",uVar7);
      }
      if ((*(int *)(local_28 + 4) < DAT_00c3ca34) &&
         (FUN_006cebf4(&DAT_00c3ca34), iVar3 = DAT_00783650, DAT_00c3ca34 == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        _DAT_00c3ca38 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Materials";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca34);
      }
      FUN_00405af0(&DAT_00c3ca38);
      local_8._0_1_ = 0xc;
      _fread(local_14,2,1,(FILE *)*puVar10);
      local_3c = (uint *)0x0;
      local_44 = (uint *)FUN_006ba810(0x2f1);
      local_8._0_1_ = 0xd;
      if (local_44 == (uint *)0x0) {
        local_3c = (uint *)0x0;
      }
      else {
        *local_44 = (int)local_14[0];
        local_3c = local_44 + 1;
        _eh_vector_constructor_iterator_(local_3c,0xc,(int)local_14[0],FUN_00402100,FUN_004021b0);
      }
      local_8 = CONCAT31(local_8._1_3_,0xc);
      iVar3 = (int)local_14[0];
      in_ECX[4] = local_3c;
      in_ECX[5] = iVar3;
      in_ECX[6] = iVar3;
      DAT_0076a254 = DAT_0076a254 + iVar3 * 0xc;
      local_3c = (uint *)0x0;
      if (0 < iVar3) {
        local_34 = (int *)0x0;
        do {
          if ((int)in_ECX[5] <= (int)local_3c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_00402220(puVar10);
          iVar3 = (int)local_14[0];
          local_3c = (uint *)((int)local_3c + 1);
          local_34 = local_34 + 3;
        } while ((int)local_3c < iVar3);
      }
      FUN_00445d30(&DAT_00b83658,"DB %d Materials",iVar3);
      FUN_0043fd30();
      if (local_2c != (FILE *)0x0) {
        uVar7 = FUN_006de91d(*puVar10);
        FUN_00405ab0(local_2c,"Materials %d\n",uVar7);
      }
      if ((*(int *)(local_28 + 4) < DAT_00c3ca3c) &&
         (FUN_006cebf4(&DAT_00c3ca3c), iVar3 = DAT_00783650, DAT_00c3ca3c == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca40 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Meshes";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca3c);
      }
      local_3c = (uint *)(DAT_00c3ca40 * 0x40);
      local_44 = (uint *)&DAT_00c3ca40;
      uVar2 = local_3c[0x1dcd94];
      iVar3 = FUN_0043fcc0();
      puVar6 = local_3c;
      *(uint *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
      *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
      uVar2 = local_3c[0x1dcd95];
      if (uVar2 == 0) {
        uVar12 = FUN_006bd180();
        uVar2 = puVar6[0x1dcd95];
        *(undefined8 *)(puVar6 + 0x1dcd96) = uVar12;
      }
      puVar10 = param_1;
      puVar6[0x1dcd95] = uVar2 + 1;
      local_8._0_1_ = 0xe;
      _fread(&local_20,4,1,(FILE *)*param_1);
      uVar2 = -(uint)((int)((ulonglong)local_20 * 0xe8 >> 0x20) != 0) |
              (uint)((ulonglong)local_20 * 0xe8);
      local_38 = (uint *)FUN_006c4e10(-(uint)(0xfffffffb < uVar2) | uVar2 + 4);
      local_8._0_1_ = 0xf;
      if (local_38 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_38 = local_20;
        local_3c = local_38 + 1;
        _eh_vector_constructor_iterator_(local_3c,0xe8,local_20,FUN_00402510,FUN_004025b0);
        puVar6 = local_3c;
      }
      local_8._0_1_ = 0xe;
      in_ECX[0xd] = puVar6;
      in_ECX[0xe] = local_20;
      in_ECX[0xf] = local_20;
      DAT_0076a254 = DAT_0076a254 + local_20 * 0xe8;
      local_24 = (int *)0x0;
      if (0 < (int)local_20) {
        local_3c = (uint *)0x0;
        do {
          if (((int)local_24 < 0) || ((int)in_ECX[0xe] <= (int)local_24)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_00402640(puVar10);
          iVar3 = DAT_00772400;
          if (((uint)local_24 & 3) == 0) {
            *(int *)(DAT_00772400 + 0x5b8) = *(int *)(DAT_00772400 + 0x5b8) + 1;
            iVar9 = *(int *)(iVar3 + 0x5bc);
            if (*(int *)(iVar3 + 0x5bc) <= *(int *)(iVar3 + 0x5b8)) {
              iVar9 = *(int *)(iVar3 + 0x5b8);
            }
            *(int *)(iVar3 + 0x5bc) = iVar9;
            if ((*(int *)(iVar3 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
              DVar5 = GetTickCount();
              if (DAT_007687c0 == 0xffffffff) {
                DAT_007687c0 = DVar5;
              }
              if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar5) {
                DAT_007687c0 = DVar5;
                FUN_00479c10(0,1);
                Sleep(1);
              }
            }
          }
          local_24 = (int *)((int)local_24 + 1);
          local_3c = local_3c + 0x3a;
        } while ((int)local_24 < (int)local_20);
      }
      FUN_00445d30(&DAT_00b83658,"DB %d Meshes",local_20);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0043fd30();
      if (local_2c != (FILE *)0x0) {
        uVar7 = FUN_006de91d(*puVar10);
        FUN_00405ab0(local_2c,"Meshes %d\n",uVar7);
      }
      if ((*(int *)(local_28 + 4) < DAT_00c3ca44) &&
         (FUN_006cebf4(&DAT_00c3ca44), iVar3 = DAT_00783650, DAT_00c3ca44 == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca48 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Objects";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca44);
      }
      local_34 = (int *)(DAT_00c3ca48 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = *(uint *)(&DAT_00773650 + (int)local_34);
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = *(int *)((int)&DAT_00773654 + (int)local_34);
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = *(int *)((int)&DAT_00773654 + (int)local_34);
        *(undefined8 *)((int)&DAT_00773658 + (int)local_34) = uVar12;
      }
      *(int *)((int)&DAT_00773654 + (int)local_34) = iVar3 + 1;
      local_8._0_1_ = 0x10;
      _fread(local_14,2,1,(FILE *)*puVar10);
      local_3c = (uint *)0x0;
      local_44 = (uint *)FUN_006ba810(0x30c);
      local_8._0_1_ = 0x11;
      if (local_44 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *local_44 = (int)local_14[0];
        local_3c = local_44 + 1;
        _eh_vector_constructor_iterator_(local_3c,0x10,(int)local_14[0],FUN_00402bb0,FUN_00402c10);
        puVar6 = local_3c;
      }
      local_8._0_1_ = 0x10;
      iVar3 = (int)local_14[0];
      in_ECX[0x10] = puVar6;
      DAT_0076a254 = DAT_0076a254 + iVar3 * 0x10;
      in_ECX[0x11] = iVar3;
      in_ECX[0x12] = iVar3;
      local_20 = 0;
      if (0 < iVar3) {
        local_34 = (int *)0x0;
        do {
          if ((int)local_20 < (int)in_ECX[0x11]) {
            local_24 = (int *)(in_ECX[0x10] + (int)local_34);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = (int *)in_ECX[0x10];
          }
          if (*(char *)(puVar10 + 1) == '\0') {
            local_3c = (uint *)FUN_006ba590(&local_44);
            local_8._0_1_ = 0x14;
            piVar11 = (int *)*local_3c;
            piVar8 = (int *)*local_24;
            *local_24 = (int)piVar11;
            if (piVar11 != (int *)0x0) {
              *piVar11 = *piVar11 + 1;
            }
            if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
              FUN_006ba940();
            }
            *(undefined4 *)(*local_24 + 8) = *(undefined4 *)(*local_3c + 8);
            local_8._0_1_ = 0x15;
            if ((local_44 != (uint *)0x0) && (*local_44 = *local_44 - 1, *local_44 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 0x10;
            _fread(&local_18,2,1,(FILE *)*puVar10);
            local_24[1] = (int)(short)local_18;
            puVar6 = (uint *)FUN_006ba810(0x153);
            iVar3 = local_24[1];
            local_24[2] = (int)puVar6;
            local_24[3] = iVar3;
            DAT_0076a254 = DAT_0076a254 + iVar3 * 4;
            local_3c = puVar6;
          }
          else {
            piVar11 = (int *)*local_24;
            if (piVar11 != (int *)0x0) {
              *piVar11 = *piVar11 + 1;
            }
            local_8._0_1_ = 0x12;
            local_3c = (uint *)piVar11[2];
            if (local_3c == (uint *)0xffffffff) {
              piVar8 = piVar11 + 3;
              do {
                iVar3 = *piVar8;
                piVar8 = (int *)((int)piVar8 + 1);
              } while ((char)iVar3 != '\0');
              local_3c = (uint *)((int)piVar8 - ((int)piVar11 + 0xd));
              piVar11[2] = (int)local_3c;
            }
            local_38 = (uint *)(piVar11 + 3);
            local_1c = local_3c;
            _fwrite(&local_1c,4,1,(FILE *)*param_1);
            FUN_006ba670(local_38,local_3c);
            local_8._0_1_ = 0x13;
            if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
              FUN_006ba940();
            }
            puVar10 = param_1;
            local_8._0_1_ = 0x10;
            local_3c = (uint *)(uint)*(ushort *)(local_24 + 1);
            _fwrite(&local_3c,2,1,(FILE *)*param_1);
            puVar6 = (uint *)local_24[2];
            iVar3 = local_24[1];
          }
          FUN_006ba670(puVar6,iVar3 * 4);
          iVar3 = DAT_00772400;
          if ((local_20 & 3) == 0) {
            *(int *)(DAT_00772400 + 0x5b8) = *(int *)(DAT_00772400 + 0x5b8) + 1;
            iVar9 = *(int *)(iVar3 + 0x5bc);
            if (*(int *)(iVar3 + 0x5bc) <= *(int *)(iVar3 + 0x5b8)) {
              iVar9 = *(int *)(iVar3 + 0x5b8);
            }
            *(int *)(iVar3 + 0x5bc) = iVar9;
            if ((*(int *)(iVar3 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
              DVar5 = GetTickCount();
              if (DAT_007687c0 == 0xffffffff) {
                DAT_007687c0 = DVar5;
              }
              if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar5) {
                DAT_007687c0 = DVar5;
                FUN_00479c10(0,1);
                Sleep(1);
              }
            }
          }
          local_20 = local_20 + 1;
          local_34 = (int *)((int)local_34 + 0x10);
        } while ((int)local_20 < (int)local_14[0]);
        iVar3 = (int)local_14[0];
        piVar11 = local_30;
      }
      FUN_00445d30(&DAT_00b83658,"DB %d Objects",iVar3);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0043fd30();
      if (local_2c != (FILE *)0x0) {
        uVar7 = FUN_006de91d(*puVar10);
        FUN_00405ab0(local_2c,"Objects %d\n",uVar7);
      }
      if ((*(int *)(local_28 + 4) < DAT_00c3ca4c) &&
         (FUN_006cebf4(&DAT_00c3ca4c), iVar3 = DAT_00783650, DAT_00c3ca4c == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca50 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Anims";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca4c);
      }
      local_34 = (int *)(DAT_00c3ca50 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = *(uint *)(&DAT_00773650 + (int)local_34);
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = *(int *)((int)&DAT_00773654 + (int)local_34);
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = *(int *)((int)&DAT_00773654 + (int)local_34);
        *(undefined8 *)((int)&DAT_00773658 + (int)local_34) = uVar12;
      }
      *(int *)((int)&DAT_00773654 + (int)local_34) = iVar3 + 1;
      local_8._0_1_ = 0x16;
      _fread(local_14,2,1,(FILE *)*puVar10);
      local_44 = (uint *)0x0;
      puVar6 = (uint *)FUN_006ba810(0x31a);
      local_8._0_1_ = 0x17;
      if (puVar6 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
      }
      else {
        *puVar6 = (int)local_14[0];
        local_44 = puVar6 + 1;
        _eh_vector_constructor_iterator_(local_44,0x3c,(int)local_14[0],FUN_00402820,FUN_00402920);
        puVar6 = local_44;
      }
      local_8._0_1_ = 0x16;
      iVar3 = (int)local_14[0];
      in_ECX[0x13] = puVar6;
      in_ECX[0x14] = iVar3;
      in_ECX[0x15] = iVar3;
      DAT_0076a254 = DAT_0076a254 + iVar3 * 0x3c;
      local_24 = (int *)0x0;
      if (0 < iVar3) {
        local_34 = (int *)0x0;
        do {
          if ((int)in_ECX[0x14] <= (int)local_24) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_004029a0(puVar10);
          iVar3 = DAT_00772400;
          if (((uint)local_24 & 3) == 0) {
            *(int *)(DAT_00772400 + 0x5b8) = *(int *)(DAT_00772400 + 0x5b8) + 1;
            iVar9 = *(int *)(iVar3 + 0x5bc);
            if (*(int *)(iVar3 + 0x5bc) <= *(int *)(iVar3 + 0x5b8)) {
              iVar9 = *(int *)(iVar3 + 0x5b8);
            }
            *(int *)(iVar3 + 0x5bc) = iVar9;
            if ((*(int *)(iVar3 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
              DVar5 = GetTickCount();
              if (DAT_007687c0 == 0xffffffff) {
                DAT_007687c0 = DVar5;
              }
              if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar5) {
                DAT_007687c0 = DVar5;
                FUN_00479c10(0,1);
                Sleep(1);
              }
            }
          }
          iVar3 = (int)local_14[0];
          local_24 = (int *)((int)local_24 + 1);
          local_34 = (int *)((int)local_34 + 0x3c);
        } while ((int)local_24 < iVar3);
      }
      FUN_00445d30(&DAT_00b83658,"DB %d Anims",iVar3);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0043fd30();
      if (local_2c != (FILE *)0x0) {
        uVar7 = FUN_006de91d(*puVar10);
        FUN_00405ab0(local_2c,"Anims %d\n",uVar7);
      }
      if ((*(int *)(local_28 + 4) < DAT_00c3ca54) &&
         (FUN_006cebf4(&DAT_00c3ca54), iVar3 = DAT_00783650, DAT_00c3ca54 == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca58 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Shadows";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca54);
      }
      local_34 = (int *)(DAT_00c3ca58 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = *(uint *)(&DAT_00773650 + (int)local_34);
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = *(int *)((int)&DAT_00773654 + (int)local_34);
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = *(int *)((int)&DAT_00773654 + (int)local_34);
        *(undefined8 *)((int)&DAT_00773658 + (int)local_34) = uVar12;
      }
      *(int *)((int)&DAT_00773654 + (int)local_34) = iVar3 + 1;
      local_8 = CONCAT31(local_8._1_3_,0x18);
      _fread(local_14,2,1,(FILE *)*puVar10);
      iVar3 = (int)local_14[0];
      uVar7 = FUN_006c4e10(iVar3 * 8);
      puVar10 = param_1;
      DAT_0076a254 = DAT_0076a254 + iVar3 * 8;
      in_ECX[7] = uVar7;
      iVar3 = (int)local_14[0];
      in_ECX[8] = iVar3;
      in_ECX[9] = iVar3;
      local_24 = (int *)0x0;
      if (0 < iVar3) {
        do {
          if ((int)local_24 < (int)in_ECX[8]) {
            local_3c = (uint *)(in_ECX[7] + (int)local_24 * 8);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_3c = (uint *)in_ECX[7];
          }
          if (*(char *)(puVar10 + 1) == '\0') {
            iVar3 = FUN_006de91d(*puVar10);
            *local_3c = iVar3 + (int)DAT_0076a250;
            local_3c[1] = 0x400;
            _fseek((FILE *)*puVar10,0x400,1);
            _DAT_0076a30c = _DAT_0076a30c + 0x400;
          }
          iVar3 = DAT_00772400;
          if (((uint)local_24 & 3) == 0) {
            *(int *)(DAT_00772400 + 0x5b8) = *(int *)(DAT_00772400 + 0x5b8) + 1;
            iVar9 = *(int *)(iVar3 + 0x5bc);
            if (*(int *)(iVar3 + 0x5bc) <= *(int *)(iVar3 + 0x5b8)) {
              iVar9 = *(int *)(iVar3 + 0x5b8);
            }
            *(int *)(iVar3 + 0x5bc) = iVar9;
            if ((*(int *)(iVar3 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
              DVar5 = GetTickCount();
              if (DAT_007687c0 == 0xffffffff) {
                DAT_007687c0 = DVar5;
              }
              if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar5) {
                DAT_007687c0 = DVar5;
                FUN_00479c10(0,1);
                Sleep(1);
              }
            }
          }
          iVar3 = (int)local_14[0];
          local_24 = (int *)((int)local_24 + 1);
        } while ((int)local_24 < iVar3);
      }
      FUN_00445d30(&DAT_00b83658,"DB %d Shadows",iVar3);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0043fd30();
      if (local_2c != (FILE *)0x0) {
        uVar7 = FUN_006de91d(*puVar10);
        FUN_00405ab0(local_2c,"Shadows %d\n",uVar7);
      }
      if ((*(int *)(local_28 + 4) < DAT_00c3ca5c) &&
         (FUN_006cebf4(&DAT_00c3ca5c), iVar3 = DAT_00783650, DAT_00c3ca5c == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca60 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) CMaps";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca5c);
      }
      local_34 = (int *)(DAT_00c3ca60 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = local_34[0x1dcd94];
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = local_34[0x1dcd95];
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = local_34[0x1dcd95];
        *(undefined8 *)(local_34 + 0x1dcd96) = uVar12;
      }
      local_34[0x1dcd95] = iVar3 + 1;
      local_8 = CONCAT31(local_8._1_3_,0x19);
      _fread(local_14,2,1,(FILE *)*puVar10);
      iVar3 = (int)local_14[0];
      uVar7 = FUN_006c4e10(iVar3 * 0x18);
      puVar10 = param_1;
      iVar9 = (int)local_14[0];
      DAT_0076a254 = DAT_0076a254 + iVar3 * 0x18;
      in_ECX[10] = uVar7;
      in_ECX[0xb] = iVar9;
      in_ECX[0xc] = iVar9;
      local_38 = (uint *)0x0;
      if (0 < iVar9) {
        local_3c = (uint *)0x0;
        do {
          if ((int)local_38 < (int)in_ECX[0xb]) {
            piVar11 = (int *)(in_ECX[10] + (int)local_3c);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)in_ECX[10];
          }
          local_34 = piVar11;
          if (*(char *)(puVar10 + 1) == '\0') {
            _fread(&local_18,2,1,(FILE *)*puVar10);
            piVar11[2] = (int)(short)local_18;
            _fread(&local_1c,2,1,(FILE *)*puVar10);
            piVar11[3] = (int)(short)local_1c;
            _fread(&local_20,2,1,(FILE *)*puVar10);
            piVar11[4] = (int)(short)local_20;
            _fread(&local_24,2,1,(FILE *)*puVar10);
            piVar11[5] = (int)(short)local_24;
            iVar9 = FUN_006de91d(*puVar10);
            iVar3 = piVar11[3];
            local_44 = (uint *)local_34[2];
            *local_34 = iVar9 + (int)DAT_0076a250;
            local_34[1] = (int)local_44 * iVar3;
            _fseek((FILE *)*puVar10,(int)local_44 * iVar3,1);
            _DAT_0076a308 = _DAT_0076a308 + local_34[2] * local_34[3];
          }
          local_38 = (uint *)((int)local_38 + 1);
          local_3c = local_3c + 6;
        } while ((int)local_38 < (int)local_14[0]);
        iVar9 = (int)local_14[0];
        piVar11 = local_30;
      }
      FUN_00445d30(&DAT_00b83658,"DB %d CMaps",iVar9);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0043fd30();
      puVar10 = param_1;
      if (local_2c != (FILE *)0x0) {
        uVar7 = FUN_006de91d(*param_1);
        FUN_00405ab0(local_2c,"CMaps %d\n",uVar7);
      }
      if ((*(int *)(local_28 + 4) < DAT_00c3ca64) &&
         (FUN_006cebf4(&DAT_00c3ca64), iVar3 = DAT_00783650, DAT_00c3ca64 == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca68 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) Lst Count&Init";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca64);
      }
      param_1 = (int *)(DAT_00c3ca68 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = *(uint *)(&DAT_00773650 + (int)param_1);
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
        *(undefined8 *)((int)&DAT_00773658 + (int)param_1) = uVar12;
      }
      *(int *)((int)&DAT_00773654 + (int)param_1) = iVar3 + 1;
      local_8 = CONCAT31(local_8._1_3_,0x1a);
      _fread(&param_1,2,1,(FILE *)*puVar10);
      iVar3 = (int)(short)param_1;
      local_18 = iVar3 + 0x10000;
      if (-1 < iVar3) {
        local_18 = iVar3;
      }
      _fread(&param_1,2,1,(FILE *)*puVar10);
      piVar8 = (int *)(int)(short)param_1;
      local_24 = piVar8 + 0x4000;
      if (-1 < (int)piVar8) {
        local_24 = piVar8;
      }
      _fread(&param_1,2,1,(FILE *)*puVar10);
      uVar2 = (uint)(short)param_1;
      local_20 = uVar2 + 0x10000;
      if (-1 < (int)uVar2) {
        local_20 = uVar2;
      }
      _fread(&param_1,2,1,(FILE *)*puVar10);
      puVar6 = (uint *)(int)(short)param_1;
      local_1c = puVar6 + 0x4000;
      if (-1 < (int)puVar6) {
        local_1c = puVar6;
      }
      _fread(&param_1,4,1,(FILE *)*puVar10);
      in_ECX[0x1f] = local_24;
      in_ECX[0x24] = local_20;
      in_ECX[0x29] = local_1c;
      in_ECX[0x1a] = local_18;
      uVar2 = (int)param_1 + 0x10000;
      if (-1 < (int)param_1) {
        uVar2 = (uint)param_1;
      }
      in_ECX[0x2c] = uVar2;
      uVar7 = FUN_006ba810(0x355);
      in_ECX[0x18] = uVar7;
      in_ECX[0x19] = local_18;
      uVar7 = FUN_006ba810(0x356);
      in_ECX[0x16] = uVar7;
      in_ECX[0x17] = local_18;
      uVar7 = FUN_006ba810(0x357);
      in_ECX[0x1d] = uVar7;
      in_ECX[0x1e] = local_24;
      uVar7 = FUN_006ba810(0x358);
      in_ECX[0x1b] = uVar7;
      in_ECX[0x1c] = local_24;
      uVar7 = FUN_006ba810(0x359);
      in_ECX[0x22] = uVar7;
      in_ECX[0x23] = local_20;
      uVar7 = FUN_006ba810(0x35a);
      in_ECX[0x20] = uVar7;
      in_ECX[0x21] = local_20;
      iVar3 = FUN_006ba810(0x35b);
      local_34 = in_ECX + 0x27;
      *local_34 = iVar3;
      in_ECX[0x28] = local_1c;
      uVar7 = FUN_006ba810(0x35c);
      in_ECX[0x25] = uVar7;
      in_ECX[0x26] = local_1c;
      local_3c = (uint *)0x0;
      if (0 < local_18) {
        do {
          _fread(&param_1,2,1,(FILE *)*puVar10);
          local_44 = (uint *)((uint)param_1 & 0xffff);
          if ((int)local_3c < (int)in_ECX[0x19]) {
            piVar11 = (int *)(in_ECX[0x18] + (int)local_3c * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)in_ECX[0x18];
          }
          local_3c = (uint *)((int)local_3c + 1);
          *piVar11 = (int)(short)local_44;
          piVar11 = local_30;
        } while ((int)local_3c < local_18);
      }
      if (0 < (int)local_24) {
        iVar3 = 0;
        do {
          _fread(&param_1,2,1,(FILE *)*puVar10);
          local_44 = (uint *)((uint)param_1 & 0xffff);
          if (iVar3 < (int)in_ECX[0x1e]) {
            piVar11 = (int *)(in_ECX[0x1d] + iVar3 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)in_ECX[0x1d];
          }
          iVar3 = iVar3 + 1;
          *piVar11 = (int)(short)local_44;
          piVar11 = local_30;
        } while (iVar3 < (int)local_24);
      }
      if (0 < (int)local_20) {
        iVar3 = 0;
        do {
          _fread(&param_1,2,1,(FILE *)*puVar10);
          local_44 = (uint *)((uint)param_1 & 0xffff);
          if (iVar3 < (int)in_ECX[0x23]) {
            piVar11 = (int *)(in_ECX[0x22] + iVar3 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)in_ECX[0x22];
          }
          iVar3 = iVar3 + 1;
          *piVar11 = (int)(short)local_44;
          piVar11 = local_30;
        } while (iVar3 < (int)local_20);
      }
      local_3c = (uint *)0x0;
      if (0 < (int)local_1c) {
        do {
          _fread(&param_1,2,1,(FILE *)*puVar10);
          local_44 = (uint *)((uint)param_1 & 0xffff);
          if ((int)local_3c < (int)in_ECX[0x28]) {
            piVar11 = (int *)(in_ECX[0x27] + (int)local_3c * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)in_ECX[0x27];
          }
          local_3c = (uint *)((int)local_3c + 1);
          *piVar11 = (int)(short)local_44;
          piVar11 = local_30;
        } while ((int)local_3c < (int)local_1c);
      }
      iVar3 = FUN_006de91d(*puVar10);
      in_ECX[0x2b] = in_ECX[0x2c];
      in_ECX[0x2a] = in_ECX[2] + iVar3;
      _fseek((FILE *)*puVar10,in_ECX[0x2c] * 0x14,1);
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0043fd30();
      if ((*(int *)(local_28 + 4) < DAT_00c3ca6c) &&
         (FUN_006cebf4(&DAT_00c3ca6c), iVar3 = DAT_00783650, DAT_00c3ca6c == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca70 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) IdxLst map";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca6c);
      }
      param_1 = (int *)(DAT_00c3ca70 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = param_1[0x1dcd94];
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = param_1[0x1dcd95];
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = param_1[0x1dcd95];
        *(undefined8 *)(param_1 + 0x1dcd96) = uVar12;
      }
      param_1[0x1dcd95] = iVar3 + 1;
      if (0 < local_18) {
        iVar3 = 0;
        do {
          param_1 = (int *)FUN_006de91d(*puVar10);
          if (iVar3 < (int)in_ECX[0x17]) {
            *(int *)(in_ECX[0x16] + iVar3 * 4) = in_ECX[2] + (int)param_1;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(int *)in_ECX[0x16] = in_ECX[2] + (int)param_1;
          }
          local_3c = in_ECX + 0x18;
          if (iVar3 < (int)in_ECX[0x19]) {
            iVar9 = *(int *)(*local_3c + iVar3 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar9 = *(int *)*local_3c;
          }
          param_1 = in_ECX + 0x18;
          _fseek((FILE *)*puVar10,iVar9 * 2,1);
          if (iVar3 < param_1[1]) {
            piVar11 = (int *)(*param_1 + iVar3 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)*param_1;
          }
          iVar3 = iVar3 + 1;
          DAT_0076a304 = DAT_0076a304 + *piVar11 * 2;
          piVar11 = local_30;
        } while (iVar3 < local_18);
      }
      FUN_0043fd30();
      if ((*(int *)(local_28 + 4) < DAT_00c3ca74) &&
         (FUN_006cebf4(&DAT_00c3ca74), iVar3 = DAT_00783650, DAT_00c3ca74 == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca78 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) UVLst map";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca74);
      }
      param_1 = (int *)(DAT_00c3ca78 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = *(uint *)(&DAT_00773650 + (int)param_1);
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
        *(undefined8 *)((int)&DAT_00773658 + (int)param_1) = uVar12;
      }
      *(int *)((int)&DAT_00773654 + (int)param_1) = iVar3 + 1;
      param_1 = (int *)0x0;
      if (0 < (int)local_24) {
        do {
          if ((int)in_ECX[0x1e] <= (int)param_1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_3c = (uint *)FUN_006de91d(*puVar10);
          if ((int)param_1 < (int)in_ECX[0x1c]) {
            *(int *)(in_ECX[0x1b] + (int)param_1 * 4) = in_ECX[2] + (int)local_3c;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(int *)in_ECX[0x1b] = in_ECX[2] + (int)local_3c;
          }
          if ((int)param_1 < (int)in_ECX[0x1e]) {
            iVar3 = *(int *)(in_ECX[0x1d] + (int)param_1 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)in_ECX[0x1d];
          }
          _fseek((FILE *)*puVar10,iVar3 << 3,1);
          if ((int)param_1 < (int)in_ECX[0x1e]) {
            piVar11 = (int *)(in_ECX[0x1d] + (int)param_1 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)in_ECX[0x1d];
          }
          param_1 = (int *)((int)param_1 + 1);
          DAT_0076a300 = DAT_0076a300 + *piVar11 * 8;
          piVar11 = local_30;
        } while ((int)param_1 < (int)local_24);
      }
      FUN_0043fd30();
      if ((*(int *)(local_28 + 4) < DAT_00c3ca7c) &&
         (FUN_006cebf4(&DAT_00c3ca7c), iVar3 = DAT_00783650, DAT_00c3ca7c == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca80 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) VLst map";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca7c);
      }
      param_1 = (int *)(DAT_00c3ca80 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = *(uint *)(&DAT_00773650 + (int)param_1);
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
        *(undefined8 *)((int)&DAT_00773658 + (int)param_1) = uVar12;
      }
      *(int *)((int)&DAT_00773654 + (int)param_1) = iVar3 + 1;
      local_38 = (uint *)0x0;
      if (0 < (int)local_20) {
        do {
          if ((int)local_38 < (int)in_ECX[0x23]) {
            iVar3 = *(int *)(in_ECX[0x22] + (int)local_38 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)in_ECX[0x22];
          }
          param_1 = (int *)(iVar3 * 6);
          local_3c = (uint *)FUN_006de91d(*puVar10);
          if ((int)local_38 < (int)in_ECX[0x21]) {
            piVar8 = (int *)(in_ECX[0x20] + (int)local_38 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar8 = (int *)in_ECX[0x20];
          }
          *piVar8 = in_ECX[2] + (int)local_3c;
          _fseek((FILE *)*puVar10,(long)param_1,1);
          local_38 = (uint *)((int)local_38 + 1);
          _DAT_0076a2fc = _DAT_0076a2fc + (int)param_1;
        } while ((int)local_38 < (int)local_20);
      }
      FUN_0043fd30();
      if ((*(int *)(local_28 + 4) < DAT_00c3ca84) &&
         (FUN_006cebf4(&DAT_00c3ca84), iVar3 = DAT_00783650, DAT_00c3ca84 == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca88 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) NLst map";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca84);
      }
      param_1 = (int *)(DAT_00c3ca88 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      puVar6 = (uint *)TlsGetValue(DAT_00767960);
      if (puVar6 == (uint *)0x0) {
        local_3c = (uint *)FUN_006ba810(0x18);
        if (local_3c == (uint *)0x0) {
          local_3c = (uint *)0x0;
        }
        else {
          local_3c[0x2000] = 0;
        }
        TlsSetValue(DAT_00767960,local_3c);
        puVar6 = local_3c;
      }
      puVar6[puVar6[0x2000]] = *(uint *)(&DAT_00773650 + (int)param_1);
      puVar6[0x2000] = puVar6[0x2000] + 1;
      iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = *(int *)((int)&DAT_00773654 + (int)param_1);
        *(undefined8 *)((int)&DAT_00773658 + (int)param_1) = uVar12;
      }
      *(int *)((int)&DAT_00773654 + (int)param_1) = iVar3 + 1;
      if (0 < (int)local_1c) {
        iVar3 = 0;
        do {
          param_1 = (int *)FUN_006de91d(*puVar10);
          if (iVar3 < (int)in_ECX[0x26]) {
            *(int *)(in_ECX[0x25] + iVar3 * 4) = in_ECX[2] + (int)param_1;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(int *)in_ECX[0x25] = in_ECX[2] + (int)param_1;
          }
          if (iVar3 < local_34[1]) {
            _Offset = *(long *)(*local_34 + iVar3 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            _Offset = *(long *)*local_34;
          }
          _fseek((FILE *)*puVar10,_Offset,1);
          if (iVar3 < (int)in_ECX[0x28]) {
            piVar11 = (int *)(in_ECX[0x27] + iVar3 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = (int *)in_ECX[0x27];
          }
          iVar3 = iVar3 + 1;
          _DAT_0076a2f8 = _DAT_0076a2f8 + *piVar11;
          piVar11 = local_30;
        } while (iVar3 < (int)local_1c);
      }
      FUN_0043fd30();
      if ((*(int *)(local_28 + 4) < DAT_00c3ca8c) &&
         (FUN_006cebf4(&DAT_00c3ca8c), iVar3 = DAT_00783650, DAT_00c3ca8c == -1)) {
        iVar9 = DAT_00783650 * 0x40;
        DAT_00c3ca90 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar9) = "C3DDB::Persist(CUniArc& arc) FollowMesh";
        *(int *)(&DAT_00773650 + iVar9) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c3ca8c);
      }
      param_1 = (int *)(DAT_00c3ca90 << 6);
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      lpTlsValue = TlsGetValue(DAT_00767960);
      if (lpTlsValue == (LPVOID)0x0) {
        lpTlsValue = (LPVOID)FUN_006ba810(0x18);
        if (lpTlsValue == (LPVOID)0x0) {
          lpTlsValue = (LPVOID)0x0;
        }
        else {
          *(undefined4 *)((int)lpTlsValue + 0x8000) = 0;
        }
        TlsSetValue(DAT_00767960,lpTlsValue);
      }
      puVar10 = param_1;
      *(int *)((int)lpTlsValue + *(int *)((int)lpTlsValue + 0x8000) * 4) = param_1[0x1dcd94];
      *(int *)((int)lpTlsValue + 0x8000) = *(int *)((int)lpTlsValue + 0x8000) + 1;
      iVar3 = param_1[0x1dcd95];
      if (iVar3 == 0) {
        uVar12 = FUN_006bd180();
        iVar3 = puVar10[0x1dcd95];
        *(undefined8 *)(puVar10 + 0x1dcd96) = uVar12;
      }
      puVar10[0x1dcd95] = iVar3 + 1;
      local_8 = CONCAT31(local_8._1_3_,0x1b);
      FUN_00405490();
      FUN_0043fd30();
      if (local_2c != (FILE *)0x0) {
        _fclose(local_2c);
      }
      FUN_00445d30(&DAT_00b83658,"DB FollowMesh");
      local_8 = CONCAT31(local_8._1_3_,0x1c);
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
        FUN_006ba940();
      }
    }
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

