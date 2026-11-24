
undefined4
CTclGlobalMethods__LGSetStartTemplatePro
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined3 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  code *pcVar13;
  int *piVar14;
  undefined8 uVar15;
  int local_a8;
  int local_80;
  int *local_7c;
  uint local_78;
  int local_74;
  int *local_70;
  int *local_6c;
  uint local_68;
  undefined4 *local_64;
  uint local_60;
  int local_5c;
  int *local_58;
  int local_54;
  uint local_50;
  int *local_4c;
  int *local_48;
  uint local_44;
  int local_40;
  int *local_3c;
  int local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  char local_25;
  uint local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e724;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = 0;
  local_2c = 0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7210) &&
     (FUN_006cebf4(&DAT_00ca7210,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca7210 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00ca7214 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "TCL:CTclGlobalMethods::LGSetStartTemplatePro()";
    *(int *)(&DAT_00773650 + iVar12) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7210);
  }
  iVar12 = DAT_00ca7214;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7214 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar8;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar5 == 0) {
    uVar15 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  iVar5 = (int)param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  param_3 = (int *)CONCAT13(1,param_3._0_3_);
  if (1 < iVar5) {
    if (local_5c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_64;
      if (local_60 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar11 = local_64;
      }
    }
    else {
      if (local_60 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_64 + 1;
    }
    piVar10 = (int *)*puVar11;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
      Tcl_GetBooleanFromObj(0,piVar10,&local_30);
      *piVar10 = *piVar10 + -1;
      if (*piVar10 < 1) {
        TclFreeObj(piVar10);
      }
    }
  }
  if (iVar5 == 3) {
    if (local_5c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_64;
      if (local_60 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar11 = local_64;
      }
    }
    else {
      if (local_60 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_64 + 2;
    }
    piVar10 = (int *)*puVar11;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
      iVar5 = Tcl_GetBooleanFromObj(0,piVar10,&local_58);
      if (iVar5 == 1) {
        param_3 = (int *)((uint)param_3 & 0xffffff);
      }
      else {
        param_3 = (int *)CONCAT13(local_58 != (int *)0x0,param_3._0_3_);
      }
      *piVar10 = *piVar10 + -1;
      if (*piVar10 < 1) {
        TclFreeObj(piVar10);
      }
      goto LAB_0065116b;
    }
    param_3 = (int *)((uint)param_3 & 0xffffff);
    local_24 = *(int *)(DAT_00772400 + 100);
    local_34 = FUN_0058a820();
    iVar5 = FUN_005f8080();
LAB_0065118b:
    *(undefined4 *)(iVar5 + 0x54) = 0xffffffff;
  }
  else {
LAB_0065116b:
    local_24 = *(int *)(DAT_00772400 + 100);
    local_34 = FUN_0058a820();
    iVar5 = FUN_005f8080();
    if (param_3._3_1_ == '\0') goto LAB_0065118b;
  }
  local_58 = (int *)(iVar5 + 0x44);
  local_6c = (int *)(iVar5 + 0x38);
  local_4c = (int *)(iVar5 + 0x40);
  local_80 = *local_4c << 2;
  local_78 = (*local_6c + *local_4c) * 4;
  local_7c = (int *)(*(int *)(iVar5 + 0x44) << 2);
  local_74 = (*(int *)(iVar5 + 0x3c) + *(int *)(iVar5 + 0x44)) * 4;
  local_20 = local_7c;
  FUN_00583ac0(&local_80,1);
  local_68 = local_68 & 0xffffff00;
  local_38 = -1;
  local_14 = 0;
  local_18 = 0;
  if (((*(int *)(iVar5 + 0x88) != 0) && (*(int *)(iVar5 + 0x8c) != 0)) &&
     (*(int *)(iVar5 + 0x90) != 0)) {
    *(uint *)(iVar5 + 0x8c) = *(uint *)(iVar5 + 0x8c) & 0xfffffffc;
    *(uint *)(iVar5 + 0x90) = *(uint *)(iVar5 + 0x90) & 0xfffffffc;
    iVar12 = 0;
    FUN_005f7a90(&local_14,&local_18);
    local_24 = local_24 << 2;
    while (iVar12 < 4) {
      iVar6 = FUN_00592f10(PTR_0077241c);
      uVar7 = *(uint *)(iVar6 + 8) >> ((byte)local_24 & 0x1f);
      if (((uVar7 & 8) == 0) && ((uVar7 & 0xf) != 0)) {
        uVar8 = FUN_005f7980(&local_3c,1);
        local_8 = CONCAT31(local_8._1_3_,3);
        local_2c = local_2c | 1;
        local_1c = local_2c;
        cVar4 = FUN_0058a510(uVar8,(local_14 - local_80) + *(int *)(iVar5 + 0x8c),
                             (local_18 - (int)local_20) + *(int *)(iVar5 + 0x90));
        local_25 = '\x01';
        if (cVar4 == '\0') goto LAB_006512d7;
      }
      else {
LAB_006512d7:
        local_25 = '\0';
      }
      local_8 = 2;
      if ((local_2c & 1) != 0) {
        local_2c = local_2c & 0xfffffffe;
        local_8._1_3_ = 0;
        uVar3 = local_8._1_3_;
        local_8._0_1_ = 4;
        local_8._1_3_ = 0;
        if ((local_3c != (int *)0x0) &&
           (*local_3c = *local_3c + -1, uVar3 = local_8._1_3_, *local_3c == 0)) {
          FUN_006ba940();
          uVar3 = local_8._1_3_;
        }
        local_8._1_3_ = uVar3;
        local_8 = CONCAT31(local_8._1_3_,2);
      }
      if (local_25 != '\0') {
        local_68 = CONCAT31(local_68._1_3_,1);
        local_38 = *(int *)(iVar5 + 0x88);
        break;
      }
      switch(*(int *)(iVar5 + 0x88)) {
      case 1:
        local_18 = local_18 - 4;
        iVar12 = iVar12 + 1;
        break;
      case 2:
        local_18 = local_18 + 4;
        iVar12 = iVar12 + 1;
        break;
      case 4:
        local_14 = local_14 - 4;
        iVar12 = iVar12 + 1;
        break;
      case 8:
        local_14 = local_14 + 4;
      default:
        iVar12 = iVar12 + 1;
      }
    }
  }
  FUN_005f7a90(&local_14,&local_18);
  uVar7 = (local_14 ^ (int)local_14 >> 0x1f) - ((int)local_14 >> 0x1f);
  local_24 = (local_18 ^ (int)local_18 >> 0x1f) - ((int)local_18 >> 0x1f);
  local_1c = uVar7;
  if ((((char)local_68 == '\0') || (param_3._3_1_ == '\0')) || (*(int *)(iVar5 + 0x54) == -1)) {
    *(undefined4 *)(iVar5 + 0x54) = 0xffffffff;
    if ((char)local_68 == '\0') {
      FUN_006b9200("nodigmark");
    }
  }
  else {
    FUN_005fc0a0(local_38,local_24 + 4 + uVar7);
    local_7c = (int *)(*local_58 << 2);
    local_74 = (*(int *)(iVar5 + 0x3c) + *local_58) * 4;
    local_80 = *local_4c << 2;
    local_78 = (*local_6c + *local_4c) * 4;
    local_40 = local_74;
    local_3c = local_7c;
    local_18 = local_78;
    FUN_00583ac0(&local_80,0);
    iVar12 = (*(int *)(iVar5 + 0x8c) - local_80) + uVar7;
    if ((iVar12 < 5) ||
       (pcVar13 = RaiseException_exref, (int)((local_18 - local_80) + -4) <= iVar12)) {
      uVar8 = FUN_005f7980(&local_20,0);
      iVar12 = local_34;
      local_8 = CONCAT31(local_8._1_3_,5);
      param_3 = (int *)FUN_00583080(uVar8);
      pcVar13 = RaiseException_exref;
      if ((param_3 != (int *)0xffffffff) && (0 < *(int *)(iVar12 + 0x198))) {
        if (*(int *)(iVar12 + 0x198) == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        **(uint **)(local_34 + 0x194) = (uint)param_3;
      }
      local_8._0_1_ = 6;
      if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,2);
    }
    local_14 = FUN_005f93d0(iVar5 + 0x50);
    if (local_14 != 0xffffffff) {
      local_50 = 4;
      iVar12 = FUN_005fdcc0(local_14);
      local_18 = ((local_18 - *(int *)(iVar12 + 0x30)) - local_80) - 4;
      iVar12 = FUN_005fdcc0(local_14);
      piVar10 = (int *)(*(int *)(iVar5 + 0x68) + 4);
      local_40 = ((local_40 - *(int *)(iVar12 + 0x34)) - (int)local_3c) + -4;
      local_3c = piVar10;
      switch(local_38) {
      case 1:
        local_40 = local_40 + (-4 - local_24);
        break;
      case 2:
        local_3c = (int *)((int)piVar10 + local_24 + 4);
        break;
      case 4:
        local_18 = local_18 + (-4 - local_1c);
        break;
      case 8:
        local_50 = local_1c + 8;
      }
      local_24 = 0;
      do {
        if (3 < (int)local_24) goto LAB_00651ac4;
        iVar12 = _rand();
        iVar12 = iVar12 * ((int)((local_18 - local_50) + ((int)(local_18 - local_50) >> 0x1f & 3U))
                          >> 2);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 0x7fff;
        }
        local_44 = local_50 + (iVar12 >> 0xf) * 4;
        iVar12 = _rand();
        iVar12 = iVar12 * ((int)((local_40 - (int)local_3c) +
                                (local_40 - (int)local_3c >> 0x1f & 3U)) >> 2);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 0x7fff;
        }
        local_48 = local_3c + (iVar12 >> 0xf);
        if (local_24 == 0) {
          local_48 = local_3c;
          uVar7 = *(uint *)(iVar5 + 0xc);
          if (uVar7 <= local_14) {
            (*pcVar13)(0xc000008c,1,0,0);
            uVar7 = *(uint *)(iVar5 + 0xc);
          }
          param_3 = *(int **)(iVar5 + 8);
          local_1c = local_14 * 100;
          iVar12 = *(int *)((int)param_3 + 0x30U + local_1c);
          local_20 = (int *)((int)(iVar12 + (iVar12 >> 0x1f & 3U)) >> 2);
          if (uVar7 <= local_14) {
            (*pcVar13)(0xc000008c,1,0,0);
          }
          FUN_005f7660(&local_78);
          iVar12 = FUN_005fc010(local_14);
          if (iVar12 == 1) {
            local_44 = ((*(int *)(iVar5 + 0x48) -
                        ((int)(local_78 + ((int)local_78 >> 0x1f & 3U)) >> 2)) - *local_4c) * 4;
          }
          else if (iVar12 == 2) {
            local_44 = ((*(int *)(iVar5 + 0x48) - *local_4c) - (int)local_20) * 4 - 8;
          }
          else if (iVar12 == 3) {
            local_44 = (*(int *)(iVar5 + 0x48) - *local_4c) * 4 + 8;
          }
          uVar7 = local_18;
          if ((int)(local_44 & 0xfffffffc) <= (int)local_18) {
            uVar7 = local_44 & 0xfffffffc;
          }
          local_44 = uVar7 & 0xfffffffc;
          if ((int)local_44 < (int)local_50) {
            local_44 = local_50;
          }
        }
        pcVar13 = RaiseException_exref;
        if (*(uint *)(iVar5 + 0xc) <= local_14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_38 = local_14 * 100;
        param_3 = (int *)(*(int *)(iVar5 + 8) + local_38);
        local_1c = FUN_005f8080();
        *(uint *)((int)param_3 + 0x48) = local_44;
        *(int **)((int)param_3 + 0x4c) = local_48;
        param_3 = *(int **)((int)param_3 + 0x3c);
        if (param_3 == (int *)0xffffffff) {
          uVar8 = FUN_006b9500(&DAT_0072555c);
          local_8._0_1_ = 7;
          uVar7 = local_44;
          piVar10 = local_48;
          FUN_0058a820(uVar8,local_44,local_48);
          cVar4 = FUN_0058a510(uVar8,uVar7,piVar10);
          param_3 = (int *)CONCAT13(cVar4,param_3._0_3_);
          local_8._0_1_ = 8;
          if ((local_70 != (int *)0x0) && (*local_70 = *local_70 + -1, *local_70 == 0)) {
            FUN_006ba940();
            cVar4 = param_3._3_1_;
          }
          local_8 = CONCAT31(local_8._1_3_,2);
        }
        else {
          if (*(uint *)(local_1c + 0x14) <= param_3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar4 = FUN_005f7d10(local_44,local_48);
          param_3 = (int *)CONCAT13(cVar4,param_3._0_3_);
        }
        if (cVar4 != '\0') {
          if (*(uint *)(iVar5 + 0xc) <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_1c = *(uint *)(local_38 + 0x3c + *(int *)(iVar5 + 8));
          if (local_1c != 0xffffffff) {
            local_2c = 0;
            local_20 = (int *)(local_1c * 0x28);
            local_54 = 0;
            while( true ) {
              if (*(uint *)(iVar5 + 0x14) <= local_1c) {
                (*pcVar13)(0xc000008c,1,0,0);
              }
              iVar12 = *(int *)(iVar5 + 0x10);
              if (*(int *)(iVar12 + 0x10 + (int)local_20) <= (int)local_2c) break;
              if (*(uint *)(iVar5 + 0x14) <= local_1c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar12 = *(int *)(iVar5 + 0x10);
              }
              local_30 = (int *)((int)local_20 + iVar12 + 0xc);
              if ((uint)local_30[1] <= local_2c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              piVar10 = (int *)(*local_30 + local_54);
              iVar1 = *piVar10;
              iVar12 = piVar10[1];
              iVar9 = piVar10[2];
              iVar6 = piVar10[3];
              if (*(uint *)(iVar5 + 0x14) <= local_1c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_30 = (int *)((int)local_20 + *(int *)(iVar5 + 0x10) + 0xc);
              if ((uint)local_30[1] <= local_2c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar2 = local_34;
              if (*(int *)(*local_30 + 0x10 + local_54) == 0) {
                iVar12 = iVar12 + (int)local_48;
                iVar6 = iVar6 + (int)local_48;
                iVar1 = iVar1 + local_44;
                iVar9 = iVar9 + local_44;
                FUN_0058f500(1);
                piVar10 = (int *)(*(int *)(iVar2 + 0x17c) + -0x10 + *(int *)(iVar2 + 0x180) * 0x10);
                *piVar10 = iVar1;
                piVar10[1] = iVar12;
                piVar10[2] = iVar9;
                piVar10[3] = iVar6;
              }
              local_2c = local_2c + 1;
              local_54 = local_54 + 0x14;
              pcVar13 = RaiseException_exref;
            }
            if (*(uint *)(iVar5 + 0xc) <= local_14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar12 = *(int *)(iVar5 + 8);
            if (*(char *)(local_38 + 0x40 + iVar12) != '\0') {
              local_1c = 0;
              if (*(uint *)(iVar5 + 0xc) <= local_14) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar12 = *(int *)(iVar5 + 8);
              }
              local_20 = *(int **)(local_38 + 0x34 + iVar12);
              if (*(uint *)(iVar5 + 0xc) <= local_14) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar12 = *(int *)(iVar5 + 8);
              }
              param_3 = *(int **)(local_38 + 0x5c + iVar12);
              if (param_3 != (int *)0xffffffff) {
                local_30 = *(int **)(iVar5 + 0x54);
                if (*(int **)(iVar5 + 0xc) <= local_30) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar12 = *(int *)(iVar5 + 8);
                }
                local_24 = *(uint *)((int)local_30 * 100 + 0x3c + iVar12);
                if (local_24 != 0xffffffff) {
                  if (*(uint *)(iVar5 + 0x14) <= local_24) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  local_70 = (int *)(local_24 * 0x28);
                  local_30 = (int *)(*(int *)(iVar5 + 0x10) + (int)local_70);
                  if ((uint)local_30[2] <= param_3) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  local_20 = (int *)((int)param_3 * 0x18);
                  local_1c = *(uint *)(local_30[1] + 8 + (int)local_20);
                  if (*(uint *)(iVar5 + 0x14) <= local_24) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  local_30 = (int *)(*(int *)(iVar5 + 0x10) + (int)local_70);
                  if ((uint)local_30[2] <= param_3) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  local_20 = *(int **)((int)local_20 + local_30[1] + 0x10);
                }
              }
              iVar1 = local_34;
              iVar12 = local_1c + (int)local_48;
              iVar6 = *local_6c;
              iVar9 = (int)local_20 + local_1c + (int)local_48;
              FUN_0058f500(1);
              puVar11 = (undefined4 *)
                        (*(int *)(iVar1 + 0x17c) + -0x10 + *(int *)(iVar1 + 0x180) * 0x10);
              *puVar11 = 0;
              puVar11[1] = iVar12;
              puVar11[2] = iVar6 << 2;
              puVar11[3] = iVar9;
              break;
            }
          }
          cVar4 = param_3._3_1_;
        }
        local_24 = local_24 + 1;
        pcVar13 = RaiseException_exref;
      } while (cVar4 == '\0');
      FUN_005fc3b0(local_68);
    }
  }
LAB_00651ac4:
  param_3 = (int *)FUN_006ba810(0x19);
  param_3[1] = 0x14;
  param_3[2] = -1;
  *(undefined1 *)(param_3 + 3) = 0;
  *param_3 = 1;
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_006b9040(&param_3,"%i %i %i %i %s",*local_4c,*local_58,*local_6c,*(int *)(iVar5 + 0x3c),
               *(int *)(iVar5 + 0x50) + 0xc);
  piVar10 = param_3;
  if (param_3 + 3 == (int *)0x0) {
    piVar14 = (int *)0x0;
  }
  else {
    piVar14 = (int *)Tcl_NewStringObj(param_3 + 3,0xffffffff);
    *piVar14 = *piVar14 + 1;
  }
  if (local_a8 == 0) {
    if (piVar14 == (int *)0x0) goto LAB_00651b7a;
  }
  else {
    if (piVar14 == (int *)0x0) {
      Tcl_ResetResult(local_a8);
      goto LAB_00651b7a;
    }
    Tcl_SetObjResult(local_a8,piVar14);
  }
  *piVar14 = *piVar14 + -1;
  if (*piVar14 < 1) {
    TclFreeObj(piVar14);
  }
LAB_00651b7a:
  local_8._0_1_ = 10;
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xb;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  FUN_004297b0(0);
  if (local_64 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

