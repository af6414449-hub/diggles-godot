
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fac90(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  float *pfVar13;
  byte *pbVar14;
  int iVar15;
  int *in_ECX;
  uint uVar16;
  byte *pbVar17;
  undefined4 *puVar18;
  code *pcVar19;
  bool bVar20;
  undefined1 *puVar21;
  int local_58 [2];
  undefined4 *local_50;
  undefined1 *local_4c;
  undefined4 *local_48;
  undefined4 *local_44;
  float local_40;
  int *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined1 *local_18;
  char local_14;
  char local_13;
  char local_12;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00709cfd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = param_1;
  if ((((-1 < (int)param_1) && ((int)param_1 < PTR_0077241c->originX + in_ECX[0x1f])) &&
      (local_2c = param_2, -1 < (int)param_2)) &&
     ((int)param_2 < PTR_0077241c->originY + in_ECX[0x20])) {
    local_1c = param_2;
    local_20 = param_1;
    local_28 = (undefined4 *)0x1;
    local_12 = '\x01';
    local_13 = '\x01';
    local_11 = '\x01';
    local_14 = '\x01';
    puVar10 = (undefined4 *)(undefined1 *)0x1;
    local_3c = in_ECX;
    while (((piVar2 = local_3c, local_12 != '\0' || (local_13 != '\0')) ||
           ((local_11 != '\0' || (local_14 != '\0'))))) {
      local_38 = (undefined1 *)((int)puVar10 + 1);
      local_48 = (undefined4 *)((int)local_20 + -1);
      cVar7 = FUN_005fa8e0(local_48,local_1c,local_38,local_28);
      if (cVar7 == '\0') {
        local_11 = '\0';
        puVar21 = (undefined1 *)puVar10;
      }
      else {
        local_20 = local_48;
        puVar21 = local_38;
      }
      local_44 = (undefined4 *)((int)local_28 + 1);
      local_48 = (undefined4 *)((int)local_1c + -1);
      cVar7 = FUN_005fa8e0(local_20,local_48,puVar21,local_44);
      if (cVar7 == '\0') {
        local_12 = '\0';
      }
      else {
        local_1c = local_48;
        local_28 = local_44;
      }
      local_48 = (undefined4 *)((int)local_28 + 1);
      cVar7 = FUN_005fa8e0(local_20,local_1c,puVar21,local_48);
      if (cVar7 == '\0') {
        local_13 = '\0';
      }
      else {
        local_28 = local_48;
      }
      local_48 = (undefined4 *)(puVar21 + 1);
      cVar7 = FUN_005fa8e0(local_20,local_1c,local_48,local_28);
      puVar10 = local_48;
      in_ECX = piVar2;
      if (cVar7 == '\0') {
        local_14 = '\0';
        puVar10 = (undefined4 *)puVar21;
      }
    }
    in_ECX[0x16] = (int)local_20;
    in_ECX[0x17] = (int)local_1c;
    in_ECX[0x18] = (int)((int)local_20 + (int)puVar10);
    in_ECX[0x19] = (int)((int)local_28 + (int)local_1c);
    local_50 = (undefined4 *)0x0;
    local_4c = (undefined1 *)0x0;
    local_8 = 0;
    local_40 = (float)((int)local_2c << 2);
    local_44 = (undefined4 *)FUN_005fcdf0(local_40);
    local_38 = (undefined1 *)0x0;
    if (local_44 != (undefined4 *)0xffffffff) {
      iVar8 = FUN_0040c060(local_44);
      local_38 = *(undefined1 **)(iVar8 + 4);
    }
    local_18 = (undefined1 *)0x0;
    if (0 < in_ECX[3]) {
      bVar20 = in_ECX[3] != 0;
      local_1c = (undefined4 *)0x0;
      pcVar19 = RaiseException_exref;
LAB_005fae6b:
      if (!bVar20) {
        (*pcVar19)(0xc000008c,1,0,0);
      }
      local_20 = (undefined4 *)in_ECX[2];
      if (*(char *)((int)(local_1c + 5) + (int)local_20) != '\0') goto LAB_005fb44a;
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
        local_20 = (undefined4 *)in_ECX[2];
      }
      if ((int)local_40 < *(int *)((int)(local_1c + 8) + (int)local_20) + (int)local_38)
      goto LAB_005fb44a;
      local_34 = (undefined1 *)0x0;
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
        local_20 = (undefined4 *)in_ECX[2];
      }
      pcVar6 = RaiseException_exref;
      if (-1 < *(int *)((int)(local_1c + 0xb) + (int)local_20)) {
        if ((undefined1 *)in_ECX[3] <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_20 = (undefined4 *)in_ECX[2];
        }
        local_48 = *(undefined4 **)((int)(local_1c + 0xb) + (int)local_20);
        if ((undefined1 *)in_ECX[3] <= local_48) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_20 = (undefined4 *)in_ECX[2];
        }
        pcVar19 = pcVar6;
        if (*(char *)(local_20 + (int)local_48 * 0x19 + 5) == '\0') {
          local_34 = (undefined1 *)0xbf800000;
        }
        else {
          if ((undefined1 *)in_ECX[3] <= local_18) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_20 = (undefined4 *)in_ECX[2];
          }
          if (0.0 < *(float *)((int)(local_1c + 10) + (int)local_20)) {
            local_34 = (undefined1 *)in_ECX[3];
            if (local_34 <= local_18) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_34 = (undefined1 *)in_ECX[3];
              local_20 = (undefined4 *)in_ECX[2];
            }
            local_30 = (undefined4 *)((int)local_1c + (int)local_20);
            if (local_34 <= local_18) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_20 = (undefined4 *)in_ECX[2];
            }
            local_48 = *(undefined4 **)((int)(local_1c + 0xb) + (int)local_20);
            if ((undefined1 *)in_ECX[3] <= local_48) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_20 = (undefined4 *)in_ECX[2];
            }
            puVar21 = (undefined1 *)
                      (float)((local_20[(int)local_48 * 0x19 + 3] - *(int *)((int)local_30 + 0xc)) *
                              (local_20[(int)local_48 * 0x19 + 3] - *(int *)((int)local_30 + 0xc)) +
                             (local_20[(int)local_48 * 0x19 + 4] - *(int *)((int)local_30 + 0x10)) *
                             (local_20[(int)local_48 * 0x19 + 4] - *(int *)((int)local_30 + 0x10)));
            FUN_0040b7e0();
            pcVar19 = RaiseException_exref;
            local_34 = puVar21;
          }
        }
      }
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
        local_20 = (undefined4 *)in_ECX[2];
      }
      puVar10 = local_20;
      if (0.0 < *(float *)((int)(local_1c + 0x18) + (int)local_20)) {
        uVar9 = (int)local_24 - in_ECX[0x1f] / 2;
        uVar16 = (int)uVar9 >> 0x1f;
        if ((undefined1 *)in_ECX[3] <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = (undefined4 *)in_ECX[2];
        }
        pcVar19 = RaiseException_exref;
        if ((float)(int)(((uVar9 ^ uVar16) - uVar16) * 4) <
            *(float *)((int)(local_1c + 0x18) + (int)puVar10)) {
          local_34 = (undefined1 *)0xbf800000;
        }
      }
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
        puVar10 = (undefined4 *)in_ECX[2];
      }
      if ((float)local_34 < *(float *)((int)(local_1c + 10) + (int)puVar10)) goto LAB_005fb44a;
      local_14 = '\x01';
      local_28 = (undefined4 *)0x0;
      while( true ) {
        local_34 = (undefined1 *)in_ECX[3];
        if (local_34 <= local_18) {
          (*pcVar19)(0xc000008c,1,0,0);
          local_34 = (undefined1 *)in_ECX[3];
        }
        pcVar6 = RaiseException_exref;
        local_30 = (undefined4 *)in_ECX[2];
        if (*(int *)((int)local_1c + (int)((int)local_30 + 0x19)) <= (int)local_28)
        goto LAB_005fb1b1;
        if (local_34 <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_30 = (undefined4 *)in_ECX[2];
        }
        if (*(undefined4 **)((int)local_1c + (int)((int)local_30 + 0x19)) <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_48 = *(undefined4 **)
                    (*(int *)((int)local_1c + (int)((int)local_30 + 0x15)) + (int)local_28 * 4);
        if ((undefined1 *)in_ECX[1] <= local_48) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        pcVar19 = pcVar6;
        if (*(char *)(*in_ECX + 0xc + (int)local_48 * 0x10) == '\0') break;
        local_28 = (undefined4 *)((int)local_28 + 1);
      }
      local_14 = '\0';
LAB_005fb1b1:
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
      }
      if ((*(undefined4 **)((int)local_1c + in_ECX[2] + 0x50) != local_44) || (local_14 == '\0'))
      goto LAB_005fb44a;
      local_30 = (undefined4 *)FUN_005fdb70();
      if (local_4c <= local_30) {
        (*pcVar19)(0xc000008c,1,0,0);
      }
      local_50[(int)local_30 * 2] = local_18;
      local_34 = (undefined1 *)0x3f4ccccd;
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
      }
      iVar8 = in_ECX[2];
      local_48 = (undefined4 *)((int)local_1c + iVar8);
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
        iVar8 = in_ECX[2];
      }
      iVar15 = *(int *)((int)local_1c + iVar8 + 0x20);
      if (*(int *)((int)local_48 + 0x24) == iVar15 || *(int *)((int)local_48 + 0x24) - iVar15 < 0) {
LAB_005fb41e:
        if (local_4c <= local_30) {
          (*pcVar19)(0xc000008c,1,0,0);
        }
        local_50[(int)local_30 * 2 + 1] = local_34;
        goto LAB_005fb44a;
      }
      if ((undefined1 *)in_ECX[3] <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
        iVar8 = in_ECX[2];
      }
      if (*(float *)((int)local_1c + iVar8 + 0x44) != 0.0) {
        if ((undefined1 *)in_ECX[3] <= local_18) {
          (*pcVar19)(0xc000008c,1,0,0);
          iVar8 = in_ECX[2];
        }
        local_34 = *(undefined1 **)((int)local_1c + iVar8 + 0x44);
        goto LAB_005fb41e;
      }
      local_34 = (undefined1 *)in_ECX[3];
      if (local_34 <= local_18) {
        (*pcVar19)(0xc000008c,1,0,0);
        local_34 = (undefined1 *)in_ECX[3];
        iVar8 = in_ECX[2];
      }
      pcVar19 = RaiseException_exref;
      local_48 = (undefined4 *)((int)local_1c + iVar8);
      if (local_34 <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = in_ECX[2];
      }
      local_34 = (undefined1 *)((int)local_1c + iVar8);
      if ((undefined1 *)in_ECX[3] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = in_ECX[2];
      }
      local_34 = (undefined1 *)
                 ((1.0 / (float)(*(int *)((int)local_48 + 0x24) - *(int *)(local_34 + 0x20))) *
                 (float)((((int)local_40 - *(int *)((int)local_1c + iVar8 + 0x20)) - (int)local_38)
                        + 1));
      if ((float)local_34 < 1.0) goto LAB_005fb41e;
      if ((undefined1 *)in_ECX[3] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = in_ECX[2];
      }
      if (*(int *)((int)local_1c + iVar8 + 0x54) == -1) goto LAB_005fb41e;
      if (-1 < (int)local_4c) {
        if (0 < (int)local_4c) {
          local_4c = (undefined1 *)0x0;
        }
        goto LAB_005fba79;
      }
      local_40 = (float)-(int)local_4c;
      if (((uint)(local_4c + 0xf) & 0xfffffff0) == 0) goto LAB_005fba42;
      local_34 = (undefined1 *)0x0;
      local_1c = local_50;
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8._0_1_ = 1;
      if (local_1c == (undefined4 *)0x0) {
        puVar10 = (undefined4 *)FUN_006ba810(0x9b);
        goto LAB_005fba2d;
      }
      if (local_34 == (undefined1 *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = CONCAT31(local_8._1_3_,2);
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        iVar8 = FUN_006ba730();
        if (iVar8 == 0) {
          local_48 = (undefined4 *)local_1c[-2];
          local_44 = (undefined4 *)((int)local_48 + (int)local_1c);
          iVar8 = FUN_006ba730();
          puVar10 = local_1c;
          if (iVar8 != 0) goto LAB_005fb4d3;
          puVar11 = local_1c + -7;
          if (local_1c[-5] != 0) {
            *(undefined4 *)(local_1c[-5] + 4) = local_1c[-6];
          }
          if (local_1c[-6] != 0) {
            *(undefined4 *)(local_1c[-6] + 8) = local_1c[-5];
          }
          if (puVar11 == DAT_00c3c81c) {
            DAT_00c3c81c = (undefined4 *)local_1c[-6];
          }
          _memset(local_1c,-0x20202021,(size_t)local_48);
          bVar20 = DAT_0077248f == '\0';
          *puVar11 = 0xdfdfdfdf;
          puVar10[-1] = 0xdfdfdfdf;
          *local_44 = 0xdfdfdfdf;
          if ((((bVar20) || (DAT_00c1c788 == '\0')) || (puVar11 < DAT_00c3c7cc)) ||
             ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar11)) {
            FUN_006df631(puVar11);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_005fb4d3:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_1c,iVar8);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = local_8 & 0xffffff00;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_50 = (undefined4 *)0x0;
      }
      else {
        LOCK();
        _DAT_00c3c82c = _DAT_00c3c82c + 1;
        UNLOCK();
        local_20 = local_1c + -7;
        iVar8 = FUN_006ba730();
        if ((iVar8 != 0) || (iVar8 = FUN_006ba730(), puVar10 = local_20, iVar8 != 0)) {
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_1c,iVar8);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          goto LAB_005fb61f;
        }
        local_1c = (undefined4 *)(local_34 + 0x20);
        if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (local_20 < DAT_00c3c7cc)) ||
           ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_20)) {
          puVar10 = (undefined4 *)FUN_006df8de(local_20,local_1c);
          if (puVar10 != (undefined4 *)0x0) goto LAB_005fb9f8;
          FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_1c,local_20);
          MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
          goto LAB_005fb9f0;
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
        cVar7 = FUN_006c4d20(puVar10);
        if (cVar7 != '\0') {
          if (&DAT_00000040 < local_1c) {
            if (DAT_00c1c788 == '\0') {
              puVar10 = (undefined4 *)FUN_006ba810(0x1fd);
            }
            else {
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              if (((((undefined4 *)0x100 < local_1c) ||
                   (puVar10 = (undefined4 *)FUN_006c4b80(), puVar10 == (undefined4 *)0x0)) &&
                  (((undefined4 *)0x400 < local_1c ||
                   (puVar10 = (undefined4 *)FUN_006c4b80(), puVar10 == (undefined4 *)0x0)))) &&
                 (((undefined4 *)0x1000 < local_1c ||
                  (puVar10 = (undefined4 *)FUN_006c4b80(), puVar10 == (undefined4 *)0x0)))) {
                puVar10 = (undefined4 *)FUN_006c4530(local_1c);
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            uVar12 = local_20[1];
            uVar4 = local_20[2];
            uVar5 = local_20[3];
            *puVar10 = *local_20;
            puVar10[1] = uVar12;
            puVar10[2] = uVar4;
            puVar10[3] = uVar5;
            uVar12 = local_20[5];
            uVar4 = local_20[6];
            uVar5 = local_20[7];
            puVar10[4] = local_20[4];
            puVar10[5] = uVar12;
            puVar10[6] = uVar4;
            puVar10[7] = uVar5;
            uVar12 = local_20[9];
            uVar4 = local_20[10];
            uVar5 = local_20[0xb];
            puVar10[8] = local_20[8];
            puVar10[9] = uVar12;
            puVar10[10] = uVar4;
            puVar10[0xb] = uVar5;
            uVar12 = local_20[0xd];
            uVar4 = local_20[0xe];
            uVar5 = local_20[0xf];
            puVar10[0xc] = local_20[0xc];
            puVar10[0xd] = uVar12;
            puVar10[0xe] = uVar4;
            puVar10[0xf] = uVar5;
LAB_005fb778:
            FUN_006c4d70(local_20);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          }
          else {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          }
          goto LAB_005fb9f0;
        }
        cVar7 = FUN_006c4d20(puVar10);
        if (cVar7 == '\0') {
          cVar7 = FUN_006c4d20(puVar10);
          if (cVar7 == '\0') {
            cVar7 = FUN_006c4d20(puVar10);
            if (cVar7 == '\0') {
              puVar10 = (undefined4 *)FUN_006c4620(puVar10,local_1c);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            else {
              if ((undefined4 *)0x1000 < local_1c) {
                if (DAT_00c1c788 == '\0') {
                  puVar10 = (undefined4 *)FUN_006ba810(0x1fd);
                }
                else {
                  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                  puVar10 = (undefined4 *)FUN_006c4530(local_1c);
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                }
                FUN_006d2250(puVar10,local_20,0x1000);
                goto LAB_005fb778;
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            goto LAB_005fb9f0;
          }
          if (local_1c < (undefined4 *)0x401) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            goto LAB_005fb9f0;
          }
          if (DAT_00c1c788 == '\0') {
            local_28 = (undefined4 *)FUN_006ba810(0x1fd);
            puVar11 = local_28;
            for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
          }
          else {
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            if (local_1c < (undefined4 *)0x1001) {
              puVar11 = (undefined4 *)FUN_006c4b80();
              if (puVar11 == (undefined4 *)0x0) {
                local_28 = (undefined4 *)0x0;
                goto LAB_005fb8ee;
              }
            }
            else {
LAB_005fb8ee:
              puVar11 = (undefined4 *)FUN_006c4530(local_1c);
            }
            local_28 = puVar11;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
          }
        }
        else {
          if (local_1c < (undefined4 *)0x101) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            goto LAB_005fb9f0;
          }
          if (DAT_00c1c788 == '\0') {
            puVar11 = (undefined4 *)FUN_006ba810(0x1fd);
            local_28 = puVar11;
          }
          else {
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            if (local_1c < (undefined4 *)0x401) {
              local_28 = (undefined4 *)FUN_006c4b80();
              if (local_28 == (undefined4 *)0x0) {
                local_28 = (undefined4 *)0x0;
                goto LAB_005fb809;
              }
            }
            else {
LAB_005fb809:
              if (local_1c < (undefined4 *)0x1001) {
                local_28 = (undefined4 *)FUN_006c4b80();
                if (local_28 != (undefined4 *)0x0) goto LAB_005fb831;
                local_28 = (undefined4 *)0x0;
              }
              local_28 = (undefined4 *)FUN_006c4530(local_1c);
            }
LAB_005fb831:
            puVar11 = local_28;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          }
          for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar11 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar11 = puVar11 + 1;
          }
        }
        FUN_006c4d70(local_20);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
        puVar10 = local_28;
        in_ECX = local_3c;
LAB_005fb9f0:
        if (puVar10 == (undefined4 *)0x0) {
LAB_005fb61f:
          local_8 = (uint)local_8._1_3_ << 8;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_50 = (undefined4 *)0x0;
        }
        else {
LAB_005fb9f8:
          if (local_20 == DAT_00c3c81c) {
            DAT_00c3c81c = puVar10;
          }
          puVar10[5] = local_34;
          if (puVar10[1] != 0) {
            *(undefined4 **)(puVar10[1] + 8) = puVar10;
          }
          if (puVar10[2] != 0) {
            *(undefined4 **)(puVar10[2] + 4) = puVar10;
          }
          *(undefined4 *)((int)puVar10 + (int)(local_34 + 0x1c)) = 0xfab1ffcd;
          puVar10 = puVar10 + 7;
LAB_005fba2d:
          local_8 = (uint)local_8._1_3_ << 8;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_50 = puVar10;
        }
      }
LAB_005fba42:
      local_4c = local_4c + (int)local_40;
      if (local_40 == 1.4013e-45) {
        if (local_4c <= local_4c + -1) {
LAB_005fba5c:
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else if ((int)local_4c - (int)local_40 < 0) goto LAB_005fba5c;
LAB_005fba79:
      uVar12 = FUN_005fdb70();
      pfVar13 = (float *)FUN_0040c060(uVar12);
      *pfVar13 = (float)local_18;
      iVar8 = FUN_0040c060(uVar12);
      *(undefined4 *)(iVar8 + 4) = 0x3f8ccccd;
    }
LAB_005fbaa1:
    FUN_005fdf00(0,local_4c + -1);
    in_ECX[0xe] = 1;
    local_48 = (undefined4 *)0xffffffff;
    in_ECX[0xf] = 1;
    local_30 = (undefined4 *)0x1;
    local_34 = (undefined1 *)0x1;
    in_ECX[0x12] = (int)local_24;
    in_ECX[0x13] = (int)local_2c;
    in_ECX[0x15] = -1;
    FUN_006b9200(&PTR_0071ce50);
    in_ECX[0x1a] = 0;
    local_18 = (undefined1 *)0x0;
    if ((int)local_4c < 1) {
      puVar10 = (undefined4 *)0x1;
      puVar11 = local_2c;
    }
    else {
      do {
        puVar21 = local_18;
        uVar9 = FUN_0049c670();
        local_40 = (float)(uVar9 & 0x7fff) * 3.0517578e-05;
        if (local_4c <= puVar21) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_44 = (undefined4 *)local_50[(int)local_18 * 2];
        if ((undefined4 *)in_ECX[3] <= local_44) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        pbVar17 = &DAT_0072c634;
        pbVar14 = (byte *)(*(int *)((int)local_44 * 100 + 8 + in_ECX[2]) + 0xc);
        do {
          bVar1 = *pbVar14;
          bVar20 = bVar1 < *pbVar17;
          if (bVar1 != *pbVar17) {
LAB_005fbb90:
            uVar9 = -(uint)bVar20 | 1;
            goto LAB_005fbb95;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar14[1];
          bVar20 = bVar1 < pbVar17[1];
          if (bVar1 != pbVar17[1]) goto LAB_005fbb90;
          pbVar14 = pbVar14 + 2;
          pbVar17 = pbVar17 + 2;
        } while (bVar1 != 0);
        uVar9 = 0;
LAB_005fbb95:
        if (uVar9 == 0) {
          local_40 = 0.0;
        }
        if (local_4c <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if ((float)local_50[(int)local_18 * 2 + 1] < local_40) goto LAB_005fbed2;
        if (local_4c <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_20 = (undefined4 *)local_50[(int)local_18 * 2];
        if ((undefined4 *)in_ECX[3] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar8 = in_ECX[2];
        local_28 = (undefined4 *)((int)local_20 * 100);
        iVar15 = *(int *)(iVar8 + 0x30 + (int)local_28) + 8;
        local_30 = (undefined4 *)(((int)(iVar15 + (iVar15 >> 0x1f & 3U)) >> 2) + 1);
        local_1c = local_30;
        if ((undefined4 *)in_ECX[3] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = in_ECX[2];
        }
        iVar15 = *(int *)((int)local_28 + iVar8 + 0x34) + 8;
        local_34 = (undefined1 *)(((int)(iVar15 + (iVar15 >> 0x1f & 3U)) >> 2) + 1);
        if ((undefined4 *)in_ECX[3] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = in_ECX[2];
        }
        if (*(char *)((int)local_28 + iVar8 + 0x40) == '\0') {
          if ((undefined4 *)in_ECX[3] <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = in_ECX[2];
          }
          if (*(char *)((int)local_28 + iVar8 + 0x58) == '\0') goto LAB_005fbea3;
          iVar8 = FUN_005fc010(local_20);
          if (iVar8 == 3) {
            puVar21 = (undefined1 *)((int)local_24 + (int)local_30);
LAB_005fbe99:
            if (in_ECX[0x18] + 8 < (int)puVar21) goto LAB_005fbed2;
            goto LAB_005fbea3;
          }
          if (iVar8 == 2) {
            if (in_ECX[0x16] + -8 <= (int)local_24 - (int)local_30) goto LAB_005fbea3;
          }
          else {
            if (iVar8 != 1) goto LAB_005fbea3;
            if ((undefined4 *)in_ECX[3] <= local_20) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_005f7660(local_58);
            local_58[0] = (int)(local_58[0] + (local_58[0] >> 0x1f & 3U)) >> 2;
            puVar21 = (undefined1 *)((int)local_24 + local_58[0]);
            if (in_ECX[0x16] + -8 <= (int)puVar21) goto LAB_005fbe99;
          }
        }
        else {
          local_44 = local_2c;
          if ((undefined4 *)in_ECX[3] <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = in_ECX[2];
          }
          iVar15 = *(int *)((int)local_28 + iVar8 + 0x34);
          local_38 = (undefined1 *)(((int)(iVar15 + (iVar15 >> 0x1f & 3U)) >> 2) + 1);
          if ((undefined4 *)in_ECX[3] <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = in_ECX[2];
          }
          local_3c = *(int **)((int)local_28 + iVar8 + 0x5c);
          if (local_3c != (int *)0xffffffff) {
            if ((undefined4 *)in_ECX[3] <= local_20) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar8 = in_ECX[2];
            }
            local_40 = *(float *)((int)local_28 + iVar8 + 0x3c);
            if (local_40 != -NAN) {
              if ((uint)in_ECX[5] <= (uint)local_40) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_38 = (undefined1 *)((int)local_40 * 0x28);
              local_44 = (undefined4 *)(in_ECX[4] + (int)local_38);
              if (*(int **)((int)local_44 + 8) <= local_3c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_28 = (undefined4 *)((int)local_3c * 0x18);
              iVar8 = *(int *)(*(int *)((int)local_44 + 4) + 8 + (int)local_28);
              local_44 = (undefined4 *)(((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) + (int)local_2c);
              if ((uint)in_ECX[5] <= (uint)local_40) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_40 = (float)(in_ECX[4] + (int)local_38);
              if (*(int **)((int)local_40 + 8) <= local_3c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar8 = *(int *)(*(int *)((int)local_40 + 4) + 0x10 + (int)local_28);
              local_38 = (undefined1 *)(((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) + 1);
            }
          }
          local_40 = 0.0;
          do {
            if (0 < (int)local_40) goto LAB_005fbed2;
            cVar7 = FUN_005fa8e0(8,(undefined1 *)((int)local_44 + (int)local_40),
                                 in_ECX[0x1f] + -0x10,local_38);
            local_40 = (float)((int)local_40 + 1);
          } while (cVar7 == '\0');
          puVar10 = (undefined4 *)in_ECX[0x11];
          if ((int)local_2c < in_ECX[0x11]) {
            puVar10 = local_2c;
          }
          in_ECX[0x11] = (int)puVar10;
          in_ECX[0x1a] = (int)local_40 * 4 + -4;
LAB_005fbea3:
          cVar7 = FUN_005fa9a0(&param_1,&param_2,&local_1c,&local_34,1);
          if (cVar7 != '\0') {
            local_48 = local_20;
            if (-1 < (int)local_20) {
              if ((undefined4 *)in_ECX[3] <= local_20) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              puVar10 = local_20;
              local_44 = (undefined4 *)in_ECX[2];
              piVar2 = (int *)in_ECX[0x14];
              piVar3 = (int *)local_44[(int)local_20 * 0x19 + 2];
              in_ECX[0x14] = (int)piVar3;
              if (piVar3 != (int *)0x0) {
                *piVar3 = *piVar3 + 1;
              }
              if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
                FUN_006ba940();
              }
              *(undefined4 *)(in_ECX[0x14] + 8) =
                   *(undefined4 *)(local_44[(int)puVar10 * 0x19 + 2] + 8);
              local_24 = param_1;
              puVar10 = local_1c;
              puVar18 = local_20;
              puVar11 = param_2;
              goto LAB_005fbf6c;
            }
            local_24 = param_1;
            puVar10 = local_1c;
            puVar11 = param_2;
            break;
          }
          local_2c = param_2;
          local_24 = param_1;
          local_30 = local_1c;
        }
LAB_005fbed2:
        local_18 = local_18 + 1;
        puVar10 = local_30;
        puVar11 = local_2c;
      } while ((int)local_18 < (int)local_4c);
    }
    puVar18 = (undefined4 *)0xffffffff;
LAB_005fbf6c:
    in_ECX[0x15] = (int)puVar18;
    if ((int)local_48 < 0) {
      local_1c = (undefined4 *)0x1;
      local_34 = (undefined1 *)0x1;
      FUN_005fa9a0(&param_1,&param_2,&local_1c,&local_34,1);
      local_24 = param_1;
      puVar10 = local_1c;
      puVar11 = param_2;
    }
    in_ECX[0xe] = (int)puVar10;
    in_ECX[0xf] = (int)(local_34 + in_ECX[0x1a]);
    in_ECX[0x10] = (int)local_24;
    in_ECX[0x11] = (int)puVar11;
    local_8 = 5;
    if ((int)local_4c < 0) {
      FUN_004151e0(-(int)local_4c);
    }
    else if (0 < (int)local_4c) {
      local_4c = (undefined1 *)0x0;
    }
    if (local_50 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  ExceptionList = local_10;
  return;
LAB_005fb44a:
  local_18 = local_18 + 1;
  local_1c = local_1c + 0x19;
  bVar20 = local_18 < (undefined1 *)in_ECX[3];
  if (in_ECX[3] <= (int)local_18) goto LAB_005fbaa1;
  goto LAB_005fae6b;
}

