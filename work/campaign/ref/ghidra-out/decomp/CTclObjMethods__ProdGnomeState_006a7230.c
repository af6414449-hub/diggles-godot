
undefined4
CTclObjMethods__ProdGnomeState(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined **_Str1;
  int *piVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  undefined1 local_48 [12];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int *local_30;
  uint local_2c;
  int local_28;
  undefined4 *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007123ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c88) &&
     (FUN_006cebf4(&DAT_00ca7c88,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7c88 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca7c8c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::ProdGnomeState()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c88);
  }
  iVar2 = DAT_00ca7c8c;
  local_24 = &DAT_00ca7c8c;
  uVar3 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c8c * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar3;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_18 = (int *)FUN_005c71c0(param_4,3,1);
  if (local_18 == (int *)0x0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8._0_1_ = 4;
  }
  else {
    puVar5 = (undefined4 *)local_18[0xf9];
    if (puVar5 != (undefined4 *)0x0) {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        if (local_2c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_2c < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_30 = local_30 + 2;
      }
      if (*local_30 == 0) {
        _Str1 = &PTR_0071ce50;
      }
      else {
        _Str1 = (undefined **)Tcl_GetStringFromObj(*local_30,0);
      }
      local_11 = '\0';
      iVar1 = __stricmp((char *)_Str1,"unknown");
      if (iVar1 == 0) {
        local_11 = '\x01';
        if (param_3 == 3) {
          FUN_005ebdf0();
          goto LAB_006a749c;
        }
        FUN_006bc8f0(2);
      }
      iVar1 = __stricmp((char *)_Str1,"idle");
      if (iVar1 == 0) {
        local_11 = '\x01';
        if (param_3 == 3) {
          *(undefined1 *)(puVar5 + 1) = 1;
          goto LAB_006a749c;
        }
        FUN_006bc8f0(2);
      }
      iVar1 = __stricmp((char *)_Str1,"sparetime");
      if (iVar1 == 0) {
        local_11 = '\x01';
        if (param_3 == 3) {
          FUN_005ebe50();
          goto LAB_006a749c;
        }
        FUN_006bc8f0(2);
      }
      iVar1 = __stricmp((char *)_Str1,"walk");
      if (iVar1 == 0) {
        local_11 = '\x01';
        if (param_3 == 4) {
          puVar5 = &local_3c;
          FUN_004295e0(3);
          FUN_006bafe0(puVar5);
          FUN_005ebeb0(local_18 + 3,&local_3c);
          goto LAB_006a749c;
        }
        if (param_3 == 5) {
          puVar9 = local_48;
          FUN_004295e0(3);
          FUN_006bafe0(puVar9);
          puVar5 = &local_3c;
          FUN_004295e0(4);
          FUN_006bafe0(puVar5);
          FUN_005ebeb0(local_48,&local_3c);
          goto LAB_006a749c;
        }
        FUN_006bc8f0(4);
      }
      iVar1 = __stricmp((char *)_Str1,"guard");
      if (iVar1 == 0) {
        local_11 = '\x01';
        if (param_3 == 4) {
          puVar4 = &local_3c;
          FUN_004295e0(3);
          FUN_006bafe0(puVar4);
          *(undefined1 *)(puVar5 + 1) = 0;
          *puVar5 = 0;
          puVar5[10] = 0xffffffff;
          puVar5[0xb] = 0xffffffff;
          puVar5[0xc] = 0xffffffff;
          puVar5[6] = 0;
          puVar5[5] = 0;
          puVar5[4] = 0;
          puVar5[3] = 4;
          puVar5[7] = local_3c;
          puVar5[8] = local_38;
          puVar5[9] = local_34;
          goto LAB_006a749c;
        }
        FUN_006bc8f0(3);
      }
      iVar1 = __stricmp((char *)_Str1,"fight");
      if (iVar1 == 0) {
        local_11 = '\x01';
        iVar2 = FUN_005c71c0(param_4,4,3);
        iVar1 = DAT_0077244c;
        if (iVar2 != 0) {
          uVar6 = *(uint *)(iVar2 + 0xdc);
          *(undefined1 *)(puVar5 + 1) = 0;
          piVar7 = (int *)(iVar1 + 0x488);
          *puVar5 = 0;
          puVar5[3] = 0;
          puVar5[10] = 0xffffffff;
          puVar5[0xb] = 0xffffffff;
          puVar5[0xc] = 0xffffffff;
          puVar5[6] = 0;
          puVar5[5] = 0;
          puVar5[4] = 0;
          puVar5[9] = 0;
          puVar5[8] = 0;
          puVar5[7] = 0;
          if (uVar6 < 0x2000) {
            piVar7 = piVar7 + uVar6;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar1 = *piVar7;
          puVar5[3] = 5;
          puVar5[7] = *(undefined4 *)(iVar1 + 0xc);
          puVar5[8] = *(undefined4 *)(iVar1 + 0x10);
          puVar5[9] = *(undefined4 *)(iVar1 + 0x14);
          puVar5[10] = uVar6;
          goto LAB_006a749c;
        }
      }
      iVar1 = __stricmp((char *)_Str1,"build");
      if (iVar1 == 0) {
        local_11 = '\x01';
        local_20 = FUN_005c71c0(param_4,5,3);
        if (local_20 != 0) {
          FUN_004295e0(4);
          uVar3 = FUN_006bafc0();
          FUN_006b8fb0(uVar3);
          local_1c = FUN_00601f90(&local_18);
          local_8._0_1_ = 7;
          if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 2;
          if (local_1c != 0) {
            FUN_005ebf40(*(undefined4 *)(local_20 + 0xdc),*(undefined4 *)(local_1c + 8));
            goto LAB_006a749c;
          }
          puVar4 = (undefined4 *)FUN_004295e0(4);
          piVar7 = (int *)*puVar4;
          if (piVar7 != (int *)0x0) {
            *piVar7 = *piVar7 + 1;
          }
          FUN_006bc6a0("unknown class",piVar7);
        }
      }
      iVar1 = __stricmp((char *)_Str1,"invent");
      if (iVar1 == 0) {
        local_11 = '\x01';
        local_1c = FUN_005c71c0(param_4,5,3);
        if (local_1c != 0) {
          FUN_004295e0(4);
          uVar3 = FUN_006bafc0();
          FUN_006b8fb0(uVar3);
          local_20 = FUN_00601f90(&local_18);
          local_8._0_1_ = 8;
          if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 2;
          if (local_20 != 0) {
            FUN_005ebfe0(*(undefined4 *)(local_1c + 0xdc),*(undefined4 *)(local_20 + 8));
            goto LAB_006a749c;
          }
          puVar4 = (undefined4 *)FUN_004295e0(4);
          piVar7 = (int *)*puVar4;
          if (piVar7 != (int *)0x0) {
            *piVar7 = *piVar7 + 1;
          }
          FUN_006bc6a0("unknown class",piVar7);
        }
      }
      iVar1 = __stricmp((char *)_Str1,"putdown");
      if (iVar1 == 0) {
        local_11 = '\x01';
        iVar2 = FUN_005c71c0(param_4,4,3);
        iVar1 = DAT_0077244c;
        if (iVar2 == 0) goto LAB_006a7917;
        uVar6 = *(uint *)(iVar2 + 0xdc);
        *(undefined1 *)(puVar5 + 1) = 0;
        piVar7 = (int *)(iVar1 + 0x488);
        *puVar5 = 0;
        puVar5[3] = 0;
        puVar5[10] = 0xffffffff;
        puVar5[0xb] = 0xffffffff;
        puVar5[0xc] = 0xffffffff;
        puVar5[6] = 0;
        puVar5[5] = 0;
        puVar5[4] = 0;
        puVar5[9] = 0;
        puVar5[8] = 0;
        puVar5[7] = 0;
        if (uVar6 < 0x2000) {
          piVar7 = piVar7 + uVar6;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar1 = *piVar7;
        puVar5[3] = 9;
LAB_006a78f1:
        puVar5[10] = uVar6;
        puVar5[0xc] = *(undefined4 *)(*(int *)(iVar1 + 0xd4) + 8);
        puVar5[7] = *(undefined4 *)(iVar1 + 0xc);
        puVar5[8] = *(undefined4 *)(iVar1 + 0x10);
        puVar5[9] = *(undefined4 *)(iVar1 + 0x14);
LAB_006a749c:
        FUN_00429650();
        FUN_006bc0d0();
        FUN_0043fd30();
        ExceptionList = local_10;
        return 0;
      }
LAB_006a7917:
      iVar1 = __stricmp((char *)_Str1,"pickup");
      if (iVar1 == 0) {
        local_11 = '\x01';
        iVar2 = FUN_005c71c0(param_4,4,3);
        iVar1 = DAT_0077244c;
        if (iVar2 != 0) {
          uVar6 = *(uint *)(iVar2 + 0xdc);
          *(undefined1 *)(puVar5 + 1) = 0;
          *puVar5 = 0;
          puVar5[3] = 0;
          puVar5[10] = 0xffffffff;
          puVar5[0xb] = 0xffffffff;
          puVar5[0xc] = 0xffffffff;
          puVar5[6] = 0;
          puVar5[5] = 0;
          puVar5[4] = 0;
          puVar5[9] = 0;
          puVar5[8] = 0;
          puVar5[7] = 0;
          if (uVar6 < 0x2000) {
            iVar1 = ((int *)(iVar1 + 0x488))[uVar6];
            puVar5[3] = 8;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar1 = *(int *)(iVar1 + 0x488);
            puVar5[3] = 8;
          }
          goto LAB_006a78f1;
        }
      }
      iVar1 = __stricmp((char *)_Str1,"pack");
      if (iVar1 == 0) {
        local_11 = '\x01';
        iVar1 = FUN_005c71c0(param_4,4,3);
        if (iVar1 != 0) {
          FUN_005ec080(*(undefined4 *)(iVar1 + 0xdc));
          goto LAB_006a749c;
        }
      }
      iVar1 = __stricmp((char *)_Str1,"unpack");
      if (iVar1 == 0) {
        local_11 = '\x01';
        local_20 = FUN_005c71c0(param_4,5,3);
        if (local_20 != 0) {
          puVar9 = local_48;
          FUN_004295e0(4);
          uVar3 = FUN_006bafe0(puVar9);
          FUN_005ec140(*(undefined4 *)(local_20 + 0xdc),uVar3);
          goto LAB_006a749c;
        }
      }
      iVar1 = __stricmp((char *)_Str1,"transport");
      if (iVar1 == 0) {
        local_11 = '\x01';
        local_20 = FUN_005c71c0(param_4,5,3);
        if (local_20 != 0) {
          puVar9 = local_48;
          FUN_004295e0(4);
          uVar3 = FUN_006bafe0(puVar9);
          FUN_005ec210(*(undefined4 *)(local_20 + 0xdc),uVar3);
          goto LAB_006a749c;
        }
      }
      iVar1 = __stricmp((char *)_Str1,"harvest");
      if (iVar1 == 0) {
        local_11 = '\x01';
        iVar1 = FUN_005c71c0(param_4,4,3);
        if (iVar1 != 0) {
          FUN_005ec2e0(*(undefined4 *)(iVar1 + 0xdc));
          goto LAB_006a749c;
        }
      }
      iVar1 = __stricmp((char *)_Str1,"dig");
      if (iVar1 == 0) {
        local_11 = '\x01';
        if (param_3 == 4) {
          puVar9 = local_48;
          FUN_004295e0(3);
          FUN_006bafe0(puVar9);
          FUN_005ec3a0(local_48);
          goto LAB_006a749c;
        }
        FUN_006bc8f0(3);
      }
      iVar1 = __stricmp((char *)_Str1,"explore");
      if (iVar1 == 0) {
        if (param_3 == 4) {
          puVar4 = &local_3c;
          FUN_004295e0(3);
          FUN_006bafe0(puVar4);
          puVar5[7] = local_3c;
          puVar5[8] = local_38;
          *(undefined1 *)(puVar5 + 1) = 0;
          *puVar5 = 0;
          puVar5[10] = 0xffffffff;
          puVar5[0xb] = 0xffffffff;
          puVar5[0xc] = 0xffffffff;
          puVar5[6] = 0;
          puVar5[5] = 0;
          puVar5[4] = 0;
          puVar5[3] = 0xf;
          puVar5[9] = local_34;
          goto LAB_006a749c;
        }
        FUN_006bc8f0(3);
      }
      else if (local_11 == '\0') {
        puVar5 = (undefined4 *)FUN_004295e0(2);
        piVar7 = (int *)*puVar5;
        if (piVar7 != (int *)0x0) {
          *piVar7 = *piVar7 + 1;
        }
        FUN_006bc6a0("unknown state",piVar7);
      }
      FUN_00429650();
      goto LAB_006a7c39;
    }
    FUN_006bc6a0("not a gnome",0);
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8._0_1_ = 6;
  }
  FUN_004297b0(0);
  if (local_30 != (int *)0x0) {
    FUN_006ba940();
  }
LAB_006a7c39:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

