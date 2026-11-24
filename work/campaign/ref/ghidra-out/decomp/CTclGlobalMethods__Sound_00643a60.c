
undefined4
CTclGlobalMethods__Sound(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  char *pcVar9;
  FILE *_File;
  char *pcVar10;
  int iVar11;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  char *in_XMM0_Da;
  undefined8 uVar12;
  int local_74;
  undefined4 local_64;
  undefined4 local_60;
  char *local_5c;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  int *local_4c;
  undefined4 *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070db6d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7090) &&
     (FUN_006cebf4(&DAT_00ca7090,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7090 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca7094 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclGlobalMethods::Sound()";
    *(int *)(&DAT_00773650 + iVar11) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7090);
  }
  iVar11 = DAT_00ca7094;
  local_48 = &DAT_00ca7094;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7094 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (*(char *)(DAT_00772400 + 0x599) == '\0') {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8._0_1_ = 4;
  }
  else {
    if (param_3 < 2) {
      FUN_006bc8f0(1);
      local_8._0_1_ = 5;
      FUN_004297b0(0);
      local_8._0_1_ = 6;
      FUN_004297b0(0);
      if (local_58 != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      goto LAB_00643b92;
    }
    local_8._0_1_ = uVar2;
    if (local_50 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_58;
      }
    }
    else {
      if (local_54 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_58 + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 7;
    local_4c = piVar1;
    if (piVar1 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    iVar4 = __stricmp((char *)ppuVar5,"animsound");
    if (iVar4 != 0) {
      if (piVar1 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
      }
      iVar4 = __stricmp((char *)ppuVar5,"volume");
      if (iVar4 == 0) {
        piVar7 = (int *)FUN_004cfea0();
        if (param_3 == 3) {
          puVar6 = (undefined4 *)FUN_004295e0(2);
          local_1c = (int *)*puVar6;
          if (local_1c != (int *)0x0) {
            *local_1c = *local_1c + 1;
          }
          FUN_006baf80();
          *piVar7 = (int)in_XMM0_Da;
          FUN_006bad60();
        }
        uVar8 = FUN_006bad90();
        FUN_006bc670(uVar8);
LAB_00644551:
        FUN_006bad60();
      }
      else {
        if (piVar1 == (int *)0x0) {
          ppuVar5 = &PTR_0071ce50;
        }
        else {
          ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
        }
        iVar4 = __stricmp((char *)ppuVar5,"play");
        if (iVar4 == 0) {
          if (param_3 < 4) {
LAB_00643d9e:
            uVar8 = 3;
LAB_00643da0:
            FUN_006bc8f0(uVar8);
LAB_00643da8:
            if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
              TclFreeObj(piVar1);
            }
            FUN_00429650();
LAB_00643b92:
            FUN_006bc0d0();
            FUN_0043fd30();
            ExceptionList = local_10;
            return 1;
          }
          if (param_3 == 5) {
            puVar6 = &local_64;
            FUN_004295e0(4);
            puVar6 = (undefined4 *)FUN_006bafe0(puVar6);
            local_34 = (char *)puVar6[2];
            local_60 = puVar6[1];
            local_64 = *puVar6;
          }
          else {
            local_34 = (char *)0x41700000;
            local_60 = *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x158);
            local_64 = *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154);
          }
          local_5c = local_34;
          FUN_004295e0(2);
          uVar8 = FUN_006bafc0();
          FUN_004295e0(3);
          FUN_006baf80();
          FUN_004cfea0();
          iVar4 = FUN_004cff20(uVar8);
          if (iVar4 == -1) {
LAB_00643e63:
            puVar6 = (undefined4 *)FUN_004295e0(2);
            piVar7 = (int *)*puVar6;
            if (piVar7 != (int *)0x0) {
              *piVar7 = *piVar7 + 1;
            }
            FUN_006bc6a0("unknown sound",piVar7);
            goto LAB_00643da8;
          }
          FUN_004d1090();
          local_34 = (char *)((float)local_34 * 100.0);
          DAT_00772dd8 = (int)ROUND((float)local_34);
          FUN_004d19a0(iVar4,DAT_00772dd8,&local_64,extraout_ECX);
        }
        else {
          if (piVar1 == (int *)0x0) {
            ppuVar5 = &PTR_0071ce50;
          }
          else {
            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
          }
          iVar4 = __stricmp((char *)ppuVar5,"playglobal");
          if (iVar4 != 0) {
            if (piVar1 == (int *)0x0) {
              ppuVar5 = &PTR_0071ce50;
            }
            else {
              ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
            }
            iVar4 = __stricmp((char *)ppuVar5,"bind");
            if (iVar4 == 0) {
              if (param_3 < 4) goto LAB_00643d9e;
              local_34 = (char *)FUN_004cfea0();
              puVar6 = (undefined4 *)FUN_004295e0(2);
              local_18 = (int *)*puVar6;
              if (local_18 != (int *)0x0) {
                *local_18 = *local_18 + 1;
              }
              puVar6 = (undefined4 *)FUN_004295e0(3);
              piVar7 = (int *)*puVar6;
              if (piVar7 != (int *)0x0) {
                *piVar7 = *piVar7 + 1;
              }
              local_8._0_1_ = 0xb;
              local_1c = piVar7;
              pcVar9 = (char *)FUN_006bafc0();
              local_2c = pcVar9;
              local_30 = (char *)FUN_006bafc0();
              _File = _fopen(pcVar9,"rb");
              if (_File != (FILE *)0x0) {
                _fclose(_File);
                pcVar9 = local_34;
                FUN_004d0ce0(1);
                piVar7 = *(int **)(pcVar9 + 8);
                local_20 = (int *)((int)piVar7 - 1);
                if (piVar7 <= local_20) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_34 = (char *)((int)local_20 * 8);
                FUN_006b9200(local_30);
                if (*(int **)(pcVar9 + 8) <= local_20) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                FUN_006b9200(local_2c);
                FUN_006bad60();
                goto LAB_00644551;
              }
              if (piVar7 != (int *)0x0) {
                *piVar7 = *piVar7 + 1;
              }
              FUN_006bc6a0("can\'t find sample file.",piVar7);
              FUN_006bad60();
              FUN_006bad60();
              goto LAB_00643da8;
            }
            local_24 = local_24 & 0xffffff00;
            if (piVar1 == (int *)0x0) {
              ppuVar5 = &PTR_0071ce50;
            }
            else {
              ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
            }
            iVar4 = __stricmp((char *)ppuVar5,"animnoseq");
            if (iVar4 == 0) {
              local_24 = CONCAT31(local_24._1_3_,1);
            }
            else {
              if (piVar1 == (int *)0x0) {
                ppuVar5 = &PTR_0071ce50;
              }
              else {
                ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
              }
              iVar4 = __stricmp((char *)ppuVar5,"anim");
              if (iVar4 != 0) {
                if (piVar1 != (int *)0x0) {
                  *piVar1 = *piVar1 + 1;
                }
                FUN_006bc6a0("unknown sound option",piVar1);
                goto LAB_00643da8;
              }
            }
            if (param_3 < 5) {
              uVar8 = 4;
              goto LAB_00643da0;
            }
            puVar6 = (undefined4 *)FUN_004295e0(2);
            local_1c = (int *)*puVar6;
            if (local_1c != (int *)0x0) {
              *local_1c = *local_1c + 1;
            }
            local_8._0_1_ = 0xc;
            uVar8 = FUN_006bafc0();
            FUN_006b8fb0(uVar8);
            local_8._0_1_ = 0xd;
            cVar3 = FUN_00460fc0(&local_20,&local_44,&local_3c,&local_40);
            local_11 = cVar3 == '\0';
            local_8._0_1_ = 0xe;
            if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 7;
            FUN_006bad60();
            if (local_11 != '\0') {
              puVar6 = (undefined4 *)FUN_004295e0(2);
              piVar7 = (int *)*puVar6;
              if (piVar7 != (int *)0x0) {
                *piVar7 = *piVar7 + 1;
              }
              FUN_006bc6a0("can\'t find anim.",piVar7);
              goto LAB_00643da8;
            }
            puVar6 = (undefined4 *)FUN_004295e0(3);
            local_20 = (int *)*puVar6;
            if (local_20 != (int *)0x0) {
              *local_20 = *local_20 + 1;
            }
            local_3c = FUN_006baee0();
            FUN_006bad60();
            puVar6 = (undefined4 *)FUN_004295e0(4);
            piVar7 = (int *)*puVar6;
            if (piVar7 != (int *)0x0) {
              *piVar7 = *piVar7 + 1;
            }
            local_8._0_1_ = 0xf;
            local_1c = piVar7;
            uVar8 = FUN_006bafc0();
            FUN_004cfea0(uVar8);
            local_38 = FUN_004cff20(uVar8);
            if (local_38 == -1) {
              if (piVar7 != (int *)0x0) {
                *piVar7 = *piVar7 + 1;
              }
              pcVar9 = "unknown sound";
LAB_00644227:
              FUN_006bc6a0(pcVar9,piVar7);
              FUN_006bad60();
              goto LAB_00643da8;
            }
            local_34 = (char *)0x3f800000;
            local_30 = (char *)0x3f800000;
            pcVar9 = (char *)0x0;
            local_2c = (char *)0x0;
            local_28 = (char *)0x0;
            if (5 < param_3) {
              puVar6 = (undefined4 *)FUN_004295e0(5);
              local_20 = (int *)*puVar6;
              if (local_20 != (int *)0x0) {
                *local_20 = *local_20 + 1;
              }
              pcVar10 = (char *)FUN_006bafc0();
              FUN_006bad60();
              iVar4 = __stricmp(pcVar10,"any");
              local_18 = (int *)-(uint)(iVar4 != 0);
              iVar4 = __stricmp(pcVar10,"sand");
              if (iVar4 == 0) {
                local_18 = (int *)0x1;
              }
              iVar4 = __stricmp(pcVar10,"soil");
              if (iVar4 == 0) {
                local_18 = (int *)0x2;
              }
              iVar4 = __stricmp(pcVar10,"stone");
              if (iVar4 == 0) {
                local_18 = (int *)0x3;
              }
              iVar4 = __stricmp(pcVar10,"wood");
              if (iVar4 == 0) {
                local_18 = (int *)&DAT_00000004;
              }
              iVar4 = __stricmp(pcVar10,"metal");
              if (iVar4 == 0) {
                local_18 = (int *)&DAT_00000005;
              }
              iVar4 = __stricmp(pcVar10,"water");
              if (iVar4 == 0) {
                local_18 = (int *)0x6;
              }
              iVar4 = __stricmp(pcVar10,"lava");
              if ((iVar4 != 0) && (local_18 == (int *)0xffffffff)) {
                puVar6 = (undefined4 *)FUN_004295e0(5);
                piVar7 = (int *)*puVar6;
                if (piVar7 != (int *)0x0) {
                  *piVar7 = *piVar7 + 1;
                }
                pcVar9 = "invalid material";
                goto LAB_00644227;
              }
            }
            if (6 < param_3) {
              puVar6 = (undefined4 *)FUN_004295e0(6);
              local_20 = (int *)*puVar6;
              if (local_20 != (int *)0x0) {
                *local_20 = *local_20 + 1;
              }
              pcVar10 = (char *)FUN_006bafc0();
              FUN_006bad60();
              iVar4 = __stricmp(pcVar10,"any");
              local_18 = (int *)-(uint)(iVar4 != 0);
              iVar4 = __stricmp(pcVar10,"tunnel");
              if (iVar4 == 0) {
                local_18 = (int *)0x1;
              }
              iVar4 = __stricmp(pcVar10,"small");
              if (iVar4 == 0) {
                local_18 = (int *)0x2;
              }
              iVar4 = __stricmp(pcVar10,"medium");
              if (iVar4 == 0) {
                local_18 = (int *)0x3;
              }
              iVar4 = __stricmp(pcVar10,"big");
              if ((iVar4 != 0) && (local_18 == (int *)0xffffffff)) {
                puVar6 = (undefined4 *)FUN_004295e0(6);
                piVar7 = (int *)*puVar6;
                if (piVar7 != (int *)0x0) {
                  *piVar7 = *piVar7 + 1;
                }
                pcVar9 = "invalid room";
                goto LAB_00644227;
              }
            }
            if (7 < param_3) {
              puVar6 = (undefined4 *)FUN_004295e0(7);
              local_20 = (int *)*puVar6;
              if (local_20 != (int *)0x0) {
                *local_20 = *local_20 + 1;
              }
              FUN_006baf80();
              local_34 = pcVar9;
              FUN_006bad60();
            }
            if (8 < param_3) {
              puVar6 = (undefined4 *)FUN_004295e0(8);
              local_20 = (int *)*puVar6;
              if (local_20 != (int *)0x0) {
                *local_20 = *local_20 + 1;
              }
              FUN_006baf80();
              local_30 = pcVar9;
              FUN_006bad60();
            }
            if (9 < param_3) {
              puVar6 = (undefined4 *)FUN_004295e0(9);
              local_20 = (int *)*puVar6;
              if (local_20 != (int *)0x0) {
                *local_20 = *local_20 + 1;
              }
              FUN_006baf80();
              local_2c = pcVar9;
              FUN_006bad60();
            }
            if (10 < param_3) {
              puVar6 = (undefined4 *)FUN_004295e0(10);
              local_20 = (int *)*puVar6;
              if (local_20 != (int *)0x0) {
                *local_20 = *local_20 + 1;
              }
              FUN_006baf80();
              local_28 = pcVar9;
              FUN_006bad60();
            }
            FUN_004cf770(local_44,local_40,local_3c,local_38,local_34,local_30,local_2c,local_28,
                         local_24);
            goto LAB_00644551;
          }
          if (param_3 < 4) goto LAB_00643d9e;
          FUN_004295e0(2);
          uVar8 = FUN_006bafc0();
          FUN_004295e0(3);
          FUN_006baf80();
          local_34 = in_XMM0_Da;
          FUN_004cfea0();
          iVar4 = FUN_004cff20(uVar8);
          if (iVar4 == -1) goto LAB_00643e63;
          FUN_004d1090();
          FUN_004d1bb0(iVar4,extraout_ECX_00);
        }
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj(piVar1);
      }
      FUN_00429650();
      goto LAB_00644573;
    }
    if (param_3 == 3) {
      puVar6 = (undefined4 *)FUN_004295e0(2);
      local_1c = (int *)*puVar6;
      if (local_1c != (int *)0x0) {
        *local_1c = *local_1c + 1;
      }
      uVar2 = FUN_006baf10();
      *(undefined1 *)(DAT_00772400 + 0x95d8) = uVar2;
      FUN_006bad60();
    }
    piVar7 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(DAT_00772400 + 0x95d8));
    *piVar7 = *piVar7 + 1;
    iVar4 = *piVar7;
    if (local_74 != 0) {
      Tcl_SetObjResult(local_74,piVar7);
      iVar4 = *piVar7;
    }
    *piVar7 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar7);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    local_8._0_1_ = 8;
    FUN_004297b0(0);
    local_8._0_1_ = 9;
  }
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_00644573:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

