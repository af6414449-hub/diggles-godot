
undefined4 CTclGlobalMethods__AdaptiveSound(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  char *_Str1;
  undefined **ppuVar8;
  int iVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  undefined8 uVar13;
  undefined1 *puVar14;
  int local_48;
  float local_38;
  float local_34;
  int *local_2c;
  uint local_28;
  int local_24;
  undefined **local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070dafd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7088) &&
     (FUN_006cebf4(), iVar2 = DAT_00783650, DAT_00ca7088 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca708c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::AdaptiveSound()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar3 = DAT_00ca708c;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca708c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar13 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (*(char *)(DAT_00772400 + 0x59a) == '\0') {
    local_8._0_1_ = 3;
    FUN_004297b0();
    local_8._0_1_ = 4;
LAB_00642e4c:
    FUN_004297b0();
    if (local_2c != (int *)0x0) {
      FUN_006ba940();
    }
LAB_00642e62:
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  if (param_3 < 2) {
    FUN_006bc8f0();
    local_8._0_1_ = 5;
    FUN_004297b0();
    local_8._0_1_ = 6;
    FUN_004297b0();
    if (local_2c != (int *)0x0) {
      FUN_006ba940();
    }
    goto LAB_00643053;
  }
  local_8._0_1_ = uVar1;
  if (local_24 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar6 = local_2c + 1;
  }
  if (*piVar6 == 0) {
    local_14 = &PTR_0071ce50;
  }
  else {
    local_14 = (undefined **)Tcl_GetStringFromObj();
  }
  iVar2 = FUN_004cfea0();
  iVar3 = FUN_004d1090();
  iVar4 = __stricmp((char *)local_14,"basevol");
  if (iVar4 == 0) {
    if (param_3 == 3) {
      FUN_004295e0();
      uVar5 = FUN_006baee0();
      *(undefined4 *)(iVar2 + 0x20) = uVar5;
    }
    piVar6 = (int *)Tcl_NewIntObj();
    *piVar6 = *piVar6 + 1;
    iVar2 = *piVar6;
    if (local_48 != 0) {
      Tcl_SetObjResult();
      iVar2 = *piVar6;
    }
    *piVar6 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj();
    }
    local_8._0_1_ = 7;
    FUN_004297b0();
    local_8._0_1_ = 8;
    goto LAB_00642e4c;
  }
  iVar4 = __stricmp((char *)local_14,"volfact");
  if (iVar4 == 0) {
    if (param_3 == 3) {
      FUN_004295e0();
      uVar5 = FUN_006baee0();
      *(undefined4 *)(iVar2 + 0x24) = uVar5;
    }
    piVar6 = (int *)Tcl_NewIntObj();
    *piVar6 = *piVar6 + 1;
    FUN_006bc670();
    FUN_006bad60();
    FUN_00429650();
    goto LAB_00642e62;
  }
  iVar4 = __stricmp((char *)local_14,"start");
  if (iVar4 == 0) {
    if (param_3 == 2) {
      *(undefined1 *)(iVar2 + 0x1c) = 1;
      FUN_00429650();
      goto LAB_00642e62;
    }
    goto LAB_00643043;
  }
  iVar4 = __stricmp((char *)local_14,"markerenable");
  if (iVar4 == 0) {
    *(undefined1 *)(iVar3 + 0x18) = 1;
    FUN_00429650();
    goto LAB_00642e62;
  }
  iVar4 = __stricmp((char *)local_14,"markerdisable");
  if (iVar4 == 0) {
    *(undefined1 *)(iVar3 + 0x18) = 0;
    FUN_00429650();
    goto LAB_00642e62;
  }
  iVar4 = __stricmp((char *)local_14,"stop");
  if (iVar4 == 0) {
    if (param_3 == 2) {
      *(undefined1 *)(iVar2 + 0x1c) = 0;
      FUN_00429650();
      goto LAB_00642e62;
    }
LAB_00643043:
    FUN_006bc8f0();
  }
  else {
    iVar4 = __stricmp((char *)local_14,"addtheme");
    if (iVar4 == 0) {
      if (param_3 == 3) {
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004cffa0();
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"setfightstream");
    if (iVar4 == 0) {
      if (param_3 == 4) {
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004295e0();
        FUN_006bafc0();
        uVar7 = FUN_004cffa0();
        if (*(uint *)(iVar2 + 0x10) <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006b9200();
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"setintrostream");
    if (iVar4 == 0) {
      if (param_3 != 4) {
        FUN_006bc8f0();
      }
      FUN_004295e0();
      FUN_006bafc0();
      FUN_004295e0();
      FUN_006bafc0();
      FUN_004d0070();
      FUN_00429650();
      goto LAB_00642e62;
    }
    iVar4 = __stricmp((char *)local_14,"addstandardstream");
    if (iVar4 == 0) {
      if (param_3 == 4) {
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004d00c0();
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"changemode");
    if (iVar4 == 0) {
      if (param_3 == 3) {
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004d0290();
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"changetheme");
    if (iVar4 == 0) {
      if (param_3 == 3) {
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004d0160();
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"changethemenow");
    if (iVar4 == 0) {
      if (param_3 == 3) {
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004d01d0();
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"primary");
    if (iVar4 == 0) {
      if (param_3 == 3) {
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004d02f0();
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"marker");
    if (iVar4 == 0) {
      if (3 < param_3) {
        FUN_004d1090();
        FUN_004295e0();
        FUN_006bafc0();
        FUN_004295e0();
        FUN_006bafe0();
        if (param_3 == 5) {
          FUN_004295e0();
          FUN_006baf80();
        }
        FUN_004d13c0(local_38);
        FUN_00429650();
        goto LAB_00642e62;
      }
      goto LAB_00643043;
    }
    iVar4 = __stricmp((char *)local_14,"markerobj");
    if (iVar4 != 0) {
      iVar4 = __stricmp((char *)local_14,"delmarker");
      if (iVar4 == 0) {
        if (2 < param_3) {
          FUN_004295e0();
          FUN_006bafe0();
          uVar7 = FUN_004d10f0();
          if (uVar7 != 0xffffffff) {
            if (*(uint *)(iVar3 + 0x14) <= uVar7) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            fVar11 = *(float *)(*(int *)(iVar3 + 0x10) + 8 + uVar7 * 0x18) - local_34;
            fVar12 = *(float *)(*(int *)(iVar3 + 0x10) + 4 + uVar7 * 0x18) - local_38;
            fVar11 = fVar11 * fVar11 + fVar12 * fVar12;
            FUN_0040b7e0();
            if (fVar11 < 1.0) {
              FUN_004d1cb0();
            }
          }
          FUN_00429650();
          goto LAB_00642e62;
        }
      }
      else {
        iVar4 = __stricmp((char *)local_14,"delmarkerobj");
        if (iVar4 == 0) {
          if (param_3 == 3) {
            piVar6 = (int *)Tcl_NewIntObj();
            *piVar6 = *piVar6 + 1;
            local_8._0_1_ = 10;
            iVar2 = FUN_005c7050();
            local_8._0_1_ = 2;
            FUN_006bad60();
            if (iVar2 != 0) {
              iVar2 = *(int *)(iVar2 + 0xdc);
              uVar7 = 0;
              ppuVar8 = *(undefined ***)(iVar3 + 0x14);
              if (0 < (int)ppuVar8) {
                iVar4 = 0;
                local_14 = ppuVar8;
                do {
                  if (*(uint *)(iVar3 + 0x14) <= uVar7) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    ppuVar8 = local_14;
                  }
                  if (*(int *)(iVar4 + *(int *)(iVar3 + 0x10)) == iVar2) {
                    if ((*(uint *)(iVar3 + 0x14) <= uVar7) &&
                       (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0),
                       *(uint *)(iVar3 + 0x14) <= uVar7)) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    local_8._0_1_ = 0xb;
                    piVar6 = *(int **)(*(int *)(iVar3 + 0x10) + 0x14 + iVar4);
                    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
                      FUN_006ba940();
                    }
                    local_8._0_1_ = 2;
                    iVar9 = *(int *)(iVar3 + 0x14);
                    if ((int)uVar7 < iVar9 + -1) {
                      FUN_006d1b90();
                      iVar9 = *(int *)(iVar3 + 0x14);
                    }
                    uVar7 = uVar7 - 1;
                    *(int *)(iVar3 + 0x14) = iVar9 + -1;
                    iVar4 = iVar4 + -0x18;
                    ppuVar8 = (undefined **)((int)local_14 + -1);
                    local_14 = ppuVar8;
                  }
                  uVar7 = uVar7 + 1;
                  iVar4 = iVar4 + 0x18;
                } while ((int)uVar7 < (int)ppuVar8);
              }
              FUN_00429650();
              goto LAB_00642e62;
            }
            goto LAB_0064304e;
          }
        }
        else {
          iVar3 = __stricmp((char *)local_14,"markerfind");
          if (iVar3 == 0) {
            if (2 < param_3) {
              FUN_004295e0();
              FUN_006bafe0();
              iVar2 = FUN_004d10f0();
              FUN_006bb910();
              if (iVar2 != -1) {
                FUN_004cfa60();
                FUN_006badc0();
                FUN_006bb930();
                FUN_006bad60();
                FUN_004cfa60();
                FUN_006bad90();
                FUN_006bb930();
                FUN_006bad60();
                iVar2 = FUN_004cfa60();
                if (*(int *)(iVar2 + 0x14) == -0xc) {
                  piVar6 = (int *)0x0;
                }
                else {
                  piVar6 = (int *)Tcl_NewStringObj();
                  *piVar6 = *piVar6 + 1;
                }
                FUN_006bb930();
                if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
                  TclFreeObj();
                }
              }
              FUN_006bc670();
              FUN_006bad60();
              FUN_00429650();
              goto LAB_00642e62;
            }
          }
          else {
            iVar3 = __stricmp((char *)local_14,"fight");
            if (iVar3 != 0) {
              iVar3 = __stricmp((char *)local_14,"autofight");
              if (iVar3 == 0) {
                if (param_3 != 3) goto LAB_00643043;
                FUN_004d1090();
                FUN_004295e0();
                FUN_006bafc0();
LAB_0064396d:
                FUN_004d0360();
              }
              else {
                iVar3 = __stricmp((char *)local_14,"autofightpos");
                if (iVar3 == 0) {
                  if (param_3 != 3) goto LAB_00643043;
                  FUN_004d1090();
                  puVar14 = &stack0xffffff9c;
                  FUN_004295e0(2);
                  FUN_006bafe0(puVar14);
                  iVar2 = FUN_004d10f0();
                  if (iVar2 != -1) {
                    FUN_004cfa60();
                    goto LAB_0064396d;
                  }
                }
                else {
                  iVar3 = __stricmp((char *)local_14,"normal");
                  if (iVar3 != 0) goto LAB_0064304e;
                  if (*(char *)(iVar2 + 0x1c) != '\0') {
                    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x18);
                    *(undefined4 *)(iVar2 + 0x40) = 1;
                    FUN_00429650();
                    goto LAB_00642e62;
                  }
                }
              }
              FUN_00429650();
              goto LAB_00642e62;
            }
            if (param_3 == 3) {
              FUN_004295e0();
              _Str1 = (char *)FUN_006bafc0();
              if (*(char *)(iVar2 + 0x1c) != '\0') {
                uVar7 = *(uint *)(iVar2 + 0x10);
                uVar10 = 0;
                if (0 < (int)uVar7) {
                  iVar3 = 0;
                  do {
                    if (*(uint *)(iVar2 + 0x10) <= uVar10) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    iVar4 = __stricmp(_Str1,(char *)(*(int *)(iVar3 + *(int *)(iVar2 + 0xc)) + 0xc))
                    ;
                    if (iVar4 == 0) goto LAB_00643925;
                    uVar10 = uVar10 + 1;
                    iVar3 = iVar3 + 0x18;
                  } while ((int)uVar10 < (int)uVar7);
                }
                if (uVar10 != uVar7) {
LAB_00643925:
                  *(uint *)(iVar2 + 0x44) = uVar10;
                  *(undefined4 *)(iVar2 + 0x40) = 2;
                }
              }
              FUN_00429650();
              goto LAB_00642e62;
            }
          }
        }
      }
      goto LAB_00643043;
    }
    if (param_3 != 3) goto LAB_00643043;
    piVar6 = (int *)Tcl_NewIntObj();
    *piVar6 = *piVar6 + 1;
    local_8._0_1_ = 9;
    iVar2 = FUN_005c7050();
    local_8._0_1_ = 2;
    FUN_006bad60();
    if (iVar2 != 0) {
      FUN_004295e0();
      FUN_006bafc0();
      uVar5 = *(undefined4 *)(iVar2 + 0xdc);
      FUN_004d1eb0();
      uVar7 = *(uint *)(iVar3 + 0x14) - 1;
      if (*(uint *)(iVar3 + 0x14) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar2 = uVar7 * 0x18;
      FUN_006b9200();
      if (*(uint *)(iVar3 + 0x14) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)(iVar3 + 0x10);
      *(undefined4 *)(iVar4 + 0xc + iVar2) = 0;
      *(undefined4 *)(iVar4 + 8 + iVar2) = 0;
      *(undefined4 *)(iVar4 + 4 + iVar2) = 0;
      if (*(uint *)(iVar3 + 0x14) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(iVar2 + *(int *)(iVar3 + 0x10)) = uVar5;
      if (*(uint *)(iVar3 + 0x14) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(*(int *)(iVar3 + 0x10) + 0x10 + iVar2) = 0x42480000;
      FUN_00429650();
      goto LAB_00642e62;
    }
  }
LAB_0064304e:
  FUN_00429650();
LAB_00643053:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

