
void FUN_1001de50(uint param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint in_ECX;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  double dVar10;
  undefined1 auStack_1c0 [4];
  float *local_1bc;
  int *piStack_1b8;
  uint local_1b4;
  uint local_1b0;
  int iStack_1ac;
  int *piStack_1a8;
  undefined4 uStack_1a4;
  CHAR aCStack_1a0 [200];
  CHAR aCStack_d8 [204];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)auStack_1c0;
  local_1b4 = param_1;
  local_1b0 = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((DAT_1416ead1 == '\0') && (DAT_1416ead1 = '\x01', (*(byte *)(in_ECX + 0x1054) & 8) == 0)) {
    _controlfp(0x1000000,0x3000000);
  }
  if ((DAT_1416ead2 == '\0') && (DAT_1416ead2 = '\x01', (*(byte *)(in_ECX + 0x1054) & 8) == 0)) {
    MXCSR = MXCSR | 0x8040;
    local_1bc = (float *)MXCSR;
  }
  piStack_1a8 = (int *)((float)((double)(int)param_1 +
                               *(double *)(&DAT_10047c80 + ((int)param_1 >> 0x1f) * -8)) /
                       (float)((double)*(int *)(in_ECX + 0x1040) +
                              *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x1040) >> 0x1f) * -8))
                       );
  *(undefined8 *)(in_ECX + 0x10a0) = 0;
  dVar10 = (double)(float)piStack_1a8 + *(double *)(in_ECX + 0x1098);
  iStack_1ac = *(int *)(in_ECX + 0x1058);
  *(double *)(in_ECX + 0x1098) = dVar10;
  if (*(int *)(in_ECX + 0x1094) != 0) {
    if (*(int *)(in_ECX + 0x1094) == 2) {
      if (dVar10 < *(double *)(in_ECX + 0x1080)) {
        *(double *)(in_ECX + 0x1080) = dVar10;
      }
      dVar10 = *(double *)(in_ECX + 0x1088) * (dVar10 - *(double *)(in_ECX + 0x1080));
      libm_sse2_sin_precise();
      fVar7 = (float)(dVar10 * (double)*(float *)(in_ECX + 0x1070) +
                     (double)(*(float *)(in_ECX + 0x1068) + *(float *)(in_ECX + 0x1070)));
    }
    else {
      if (dVar10 < *(double *)(in_ECX + 0x1080)) {
        fVar7 = *(float *)(in_ECX + 0x1068);
        *(float *)(in_ECX + 0x1068) = *(float *)(in_ECX + 0x1090);
        *(double *)(in_ECX + 0x1080) = dVar10;
        dVar9 = (double)(1.0 - (*(float *)(in_ECX + 0x1090) - fVar7) / *(float *)(in_ECX + 0x1070))
                * *(double *)(in_ECX + 0x1078);
        *(double *)(in_ECX + 0x1078) = dVar9;
        *(float *)(in_ECX + 0x1070) = *(float *)(in_ECX + 0x106c) - *(float *)(in_ECX + 0x1090);
        *(double *)(in_ECX + 0x1088) = dVar9 + dVar10;
      }
      if (dVar10 < *(double *)(in_ECX + 0x1088) || dVar10 == *(double *)(in_ECX + 0x1088)) {
        fVar7 = (float)(((dVar10 - *(double *)(in_ECX + 0x1080)) / *(double *)(in_ECX + 0x1078)) *
                        (double)*(float *)(in_ECX + 0x1070) + (double)*(float *)(in_ECX + 0x1068));
        *(float *)(in_ECX + 0x1090) = fVar7;
      }
      else {
        fVar7 = *(float *)(in_ECX + 0x106c);
        *(undefined4 *)(in_ECX + 0x1094) = 0xffffffff;
      }
    }
    *(float *)(in_ECX + 0x1058) = fVar7;
  }
  uStack_1a4 = *(undefined4 *)(in_ECX + 0x1058);
  if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
  }
  if (*(char *)(in_ECX + 8) != '\0') {
    FUN_1001ec20(aCStack_1a0,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x88e);
    OutputDebugStringA(aCStack_1a0);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  local_1bc = (float *)0x0;
  if (0 < *(int *)(in_ECX + 0x14)) {
    piStack_1b8 = (int *)(in_ECX + 0x40);
    do {
      iVar3 = *piStack_1b8;
      pfVar4 = local_1bc;
      if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0x10) & 4) == 0)) {
        *(undefined4 *)(iVar3 + 0x158) = 0;
        if (0 < *(int *)(in_ECX + 0x1094)) {
          *(undefined4 *)(*piStack_1b8 + 0x158) = 1;
        }
        *(double *)(*piStack_1b8 + 0x58) =
             (double)(float)piStack_1a8 + *(double *)(*piStack_1b8 + 0x58);
        iVar3 = *piStack_1b8;
        *(double *)(iVar3 + 0x60) =
             (double)*(float *)(iVar3 + 0x50) * (double)(float)piStack_1a8 +
             *(double *)(iVar3 + 0x60);
        iVar3 = *piStack_1b8;
        if (0 < *(int *)(iVar3 + 0xf4)) {
          dVar10 = *(double *)(iVar3 + 0x58);
          if (*(int *)(iVar3 + 0xf4) == 2) {
            if (dVar10 < *(double *)(iVar3 + 0xe0)) {
              *(double *)(iVar3 + 0xe0) = dVar10;
            }
            libm_sse2_sin_precise();
          }
          else {
            if (dVar10 < *(double *)(iVar3 + 0xe0)) {
              fVar7 = *(float *)(iVar3 + 200);
              *(float *)(iVar3 + 200) = *(float *)(iVar3 + 0xf0);
              *(double *)(iVar3 + 0xe0) = dVar10;
              dVar9 = (double)(1.0 - (*(float *)(iVar3 + 0xf0) - fVar7) / *(float *)(iVar3 + 0xd0))
                      * *(double *)(iVar3 + 0xd8);
              *(double *)(iVar3 + 0xd8) = dVar9;
              *(float *)(iVar3 + 0xd0) = *(float *)(iVar3 + 0xcc) - *(float *)(iVar3 + 0xf0);
              *(double *)(iVar3 + 0xe8) = dVar9 + dVar10;
            }
            if (dVar10 < *(double *)(iVar3 + 0xe8) || dVar10 == *(double *)(iVar3 + 0xe8)) {
              *(float *)(iVar3 + 0xf0) =
                   (float)(((dVar10 - *(double *)(iVar3 + 0xe0)) / *(double *)(iVar3 + 0xd8)) *
                           (double)*(float *)(iVar3 + 0xd0) + (double)*(float *)(iVar3 + 200));
            }
            else {
              *(undefined4 *)(iVar3 + 0xf4) = 0xffffffff;
            }
          }
          FUN_10020110();
        }
        iVar3 = *piStack_1b8;
        if (0 < *(int *)(iVar3 + 0xc4)) {
          dVar10 = *(double *)(iVar3 + 0x58);
          if (*(int *)(iVar3 + 0xc4) == 2) {
            if (dVar10 < *(double *)(iVar3 + 0xb0)) {
              *(double *)(iVar3 + 0xb0) = dVar10;
            }
            dVar10 = *(double *)(iVar3 + 0xb8) * (dVar10 - *(double *)(iVar3 + 0xb0));
            libm_sse2_sin_precise();
            fVar7 = (float)(dVar10 * (double)*(float *)(iVar3 + 0xa0) +
                           (double)(*(float *)(iVar3 + 0xa0) + *(float *)(iVar3 + 0x98)));
          }
          else {
            if (dVar10 < *(double *)(iVar3 + 0xb0)) {
              fVar7 = *(float *)(iVar3 + 0x98);
              *(float *)(iVar3 + 0x98) = *(float *)(iVar3 + 0xc0);
              *(double *)(iVar3 + 0xb0) = dVar10;
              dVar9 = (double)(1.0 - (*(float *)(iVar3 + 0xc0) - fVar7) / *(float *)(iVar3 + 0xa0))
                      * *(double *)(iVar3 + 0xa8);
              *(double *)(iVar3 + 0xa8) = dVar9;
              *(float *)(iVar3 + 0xa0) = *(float *)(iVar3 + 0x9c) - *(float *)(iVar3 + 0xc0);
              *(double *)(iVar3 + 0xb8) = dVar9 + dVar10;
            }
            if (dVar10 < *(double *)(iVar3 + 0xb8) || dVar10 == *(double *)(iVar3 + 0xb8)) {
              fVar7 = (float)(((dVar10 - *(double *)(iVar3 + 0xb0)) / *(double *)(iVar3 + 0xa8)) *
                              (double)*(float *)(iVar3 + 0xa0) + (double)*(float *)(iVar3 + 0x98));
              *(float *)(iVar3 + 0xc0) = fVar7;
            }
            else {
              fVar7 = *(float *)(iVar3 + 0x9c);
              *(undefined4 *)(iVar3 + 0xc4) = 0xffffffff;
            }
          }
          *(float *)(*piStack_1b8 + 0x38) = fVar7;
          *(undefined4 *)(*piStack_1b8 + 0x158) = 1;
          FUN_10020780();
          *(undefined1 *)(in_ECX + 0x1cda8) = 1;
        }
        iVar3 = *piStack_1b8;
        pfVar4 = local_1bc;
        if (0 < *(int *)(iVar3 + 0x94)) {
          dVar10 = *(double *)(iVar3 + 0x58);
          if (*(int *)(iVar3 + 0x94) == 2) {
            if (dVar10 < *(double *)(iVar3 + 0x80)) {
              *(double *)(iVar3 + 0x80) = dVar10;
            }
            libm_sse2_sin_precise();
          }
          else {
            if (dVar10 < *(double *)(iVar3 + 0x80)) {
              fVar7 = *(float *)(iVar3 + 0x68);
              *(float *)(iVar3 + 0x68) = *(float *)(iVar3 + 0x90);
              *(double *)(iVar3 + 0x80) = dVar10;
              dVar9 = (double)(1.0 - (*(float *)(iVar3 + 0x90) - fVar7) / *(float *)(iVar3 + 0x70))
                      * *(double *)(iVar3 + 0x78);
              *(double *)(iVar3 + 0x78) = dVar9;
              *(float *)(iVar3 + 0x70) = *(float *)(iVar3 + 0x6c) - *(float *)(iVar3 + 0x90);
              *(double *)(iVar3 + 0x88) = dVar9 + dVar10;
            }
            if (dVar10 < *(double *)(iVar3 + 0x88) || dVar10 == *(double *)(iVar3 + 0x88)) {
              *(float *)(iVar3 + 0x90) =
                   (float)(((dVar10 - *(double *)(iVar3 + 0x80)) / *(double *)(iVar3 + 0x78)) *
                           (double)*(float *)(iVar3 + 0x70) + (double)*(float *)(iVar3 + 0x68));
            }
            else {
              *(undefined4 *)(iVar3 + 0x94) = 0xffffffff;
            }
          }
          pfVar4 = local_1bc;
          FUN_100202d0();
          *(undefined4 *)(*piStack_1b8 + 0x158) = 1;
        }
        iVar3 = *piStack_1b8;
        if (*(int *)(iVar3 + 0x124) != 0) {
          dVar10 = *(double *)(iVar3 + 0x58);
          if (*(int *)(iVar3 + 0x124) == 2) {
            if (dVar10 < *(double *)(iVar3 + 0x110)) {
              *(double *)(iVar3 + 0x110) = dVar10;
            }
          }
          else {
            if (dVar10 < *(double *)(iVar3 + 0x110)) {
              fVar7 = *(float *)(iVar3 + 0x120);
              fVar8 = *(float *)(iVar3 + 0xf8);
              *(float *)(iVar3 + 0xf8) = fVar7;
              *(double *)(iVar3 + 0x110) = dVar10;
              dVar9 = (double)(1.0 - (fVar7 - fVar8) / *(float *)(iVar3 + 0x100)) *
                      *(double *)(iVar3 + 0x108);
              *(double *)(iVar3 + 0x108) = dVar9;
              *(float *)(iVar3 + 0x100) = *(float *)(iVar3 + 0xfc) - fVar7;
              *(double *)(iVar3 + 0x118) = dVar9 + dVar10;
            }
            if (dVar10 < *(double *)(iVar3 + 0x118) || dVar10 == *(double *)(iVar3 + 0x118)) {
              *(float *)(iVar3 + 0x120) =
                   (float)(((dVar10 - *(double *)(iVar3 + 0x110)) / *(double *)(iVar3 + 0x108)) *
                           (double)*(float *)(iVar3 + 0x100) + (double)*(float *)(iVar3 + 0xf8));
            }
            else {
              *(undefined4 *)(iVar3 + 0x124) = 0xffffffff;
            }
          }
          if (*(int *)(*piStack_1b8 + 0x124) == -1) {
            *(undefined4 *)(*piStack_1b8 + 0x124) = 0;
            FUN_10020200(pfVar4,piStack_1b8);
          }
        }
        iVar3 = *piStack_1b8;
        if (*(int *)(iVar3 + 0x154) != 0) {
          dVar10 = *(double *)(iVar3 + 0x58);
          if (*(int *)(iVar3 + 0x154) == 2) {
            if (dVar10 < *(double *)(iVar3 + 0x140)) {
              *(double *)(iVar3 + 0x140) = dVar10;
            }
          }
          else {
            if (dVar10 < *(double *)(iVar3 + 0x140)) {
              fVar7 = *(float *)(iVar3 + 0x150);
              fVar8 = *(float *)(iVar3 + 0x128);
              *(float *)(iVar3 + 0x128) = fVar7;
              *(double *)(iVar3 + 0x140) = dVar10;
              dVar9 = (double)(1.0 - (fVar7 - fVar8) / *(float *)(iVar3 + 0x130)) *
                      *(double *)(iVar3 + 0x138);
              *(double *)(iVar3 + 0x138) = dVar9;
              *(float *)(iVar3 + 0x130) = *(float *)(iVar3 + 300) - fVar7;
              *(double *)(iVar3 + 0x148) = dVar9 + dVar10;
            }
            if (dVar10 < *(double *)(iVar3 + 0x148) || dVar10 == *(double *)(iVar3 + 0x148)) {
              *(float *)(iVar3 + 0x150) =
                   (float)(((dVar10 - *(double *)(iVar3 + 0x140)) / *(double *)(iVar3 + 0x138)) *
                           (double)*(float *)(iVar3 + 0x130) + (double)*(float *)(iVar3 + 0x128));
            }
            else {
              *(undefined4 *)(iVar3 + 0x154) = 0xffffffff;
            }
          }
          if (*(int *)(*piStack_1b8 + 0x154) == -1) {
            *(undefined4 *)(*piStack_1b8 + 0x154) = 0;
            FUN_100205c0();
          }
        }
      }
      local_1bc = (float *)((int)pfVar4 + 1);
      piStack_1b8 = piStack_1b8 + 1;
    } while ((int)local_1bc < *(int *)(in_ECX + 0x14));
  }
  if (*(char *)(in_ECX + 0x1cda8) != '\0') {
    FUN_1001dce0();
  }
  uVar1 = *(uint *)(in_ECX + 0x28);
  if (*(uint *)(in_ECX + 0x24) < uVar1) {
    *(uint *)(in_ECX + 0x24) = uVar1;
    free(*(void **)(in_ECX + 0x1c));
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(uint *)(in_ECX + 0x20) = uVar1 << 3;
    iVar3 = FUN_100402f0();
    *(int *)(in_ECX + 0x1c) = iVar3;
    *(uint *)(in_ECX + 0x18) = iVar3 + 0xfU & 0xfffffff0;
  }
  piStack_1a8 = (int *)(in_ECX + 0x18);
  FUN_1001d3b0(*(undefined4 *)(in_ECX + 0x2c),local_1b4,local_1b4,*piStack_1a8,0,
               (float)((double)*(int *)(in_ECX + 0x1040) +
                      *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x1040) >> 0x1f) * -8)),
               *(undefined4 *)(in_ECX + 0x1044));
  uVar1 = local_1b4;
  local_1bc = (float *)(in_ECX + 0x10c8);
  piStack_1b8 = (int *)0x8;
  do {
    if ((int *)*local_1bc != (int *)0x0) {
      (**(code **)(*(int *)*local_1bc + 8))
                (*(undefined4 *)(in_ECX + 0x2c),uVar1,*(undefined4 *)(in_ECX + 0x1044),
                 (float)((double)*(int *)(in_ECX + 0x1040) +
                        *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x1040) >> 0x1f) * -8)),
                 *(undefined8 *)(in_ECX + 0x1098));
    }
    local_1bc = local_1bc + 1;
    piStack_1b8 = (int *)((int)piStack_1b8 + -1);
  } while (piStack_1b8 != (int *)0x0);
  if (*(char *)(in_ECX + 8) != '\0') {
    *(undefined1 *)(in_ECX + 8) = 0;
    if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
    }
    FUN_1001b620(in_ECX + 0x2c,in_ECX + 0x18,local_1b4,iStack_1ac,uStack_1a4);
    if ((*(byte *)(in_ECX + 0x1054) & 2) != 0) {
      pfVar4 = (float *)(in_ECX + 0x10e8);
      *pfVar4 = 0.0;
      *(undefined4 *)(in_ECX + 0x10ec) = 0;
      *(undefined4 *)(in_ECX + 0x10f0) = 0;
      *(undefined4 *)(in_ECX + 0x10f4) = 0;
      *(undefined4 *)(in_ECX + 0x10f8) = 0;
      *(undefined4 *)(in_ECX + 0x10fc) = 0;
      *(undefined4 *)(in_ECX + 0x1100) = 0;
      *(undefined4 *)(in_ECX + 0x1104) = 0;
      if (0xff < local_1b4) {
        pfVar6 = (float *)(in_ECX + 0x1108);
        iStack_1ac = -0x1108 - in_ECX;
        piStack_1b8 = (int *)0x100;
        do {
          iVar3 = 0;
          *pfVar6 = 0.0;
          if (0 < *(int *)(in_ECX + 0x1044)) {
            local_1bc = (float *)(iStack_1ac + (int)pfVar6);
            do {
              fVar7 = *(float *)((int)local_1bc + *piStack_1a8);
              fVar8 = ABS(fVar7);
              if (*pfVar4 <= fVar8 && fVar8 != *pfVar4) {
                *pfVar4 = fVar8;
              }
              iVar3 = iVar3 + 1;
              pfVar4 = pfVar4 + 1;
              local_1bc = local_1bc + local_1b4;
              *pfVar6 = *pfVar6 + fVar7;
            } while (iVar3 < *(int *)(local_1b0 + 0x1044));
            pfVar4 = (float *)(local_1b0 + 0x10e8);
            in_ECX = local_1b0;
          }
          pfVar6 = pfVar6 + 1;
          piStack_1b8 = (int *)((int)piStack_1b8 + -1);
        } while (piStack_1b8 != (int *)0x0);
        __security_check_cookie(local_c ^ (uint)auStack_1c0);
        return;
      }
      local_1bc = (float *)(in_ECX + 0x1108);
      local_1b0 = 0;
      do {
        pfVar4 = (float *)(in_ECX + 0x10e8);
        iVar3 = 0;
        *local_1bc = 0.0;
        if (0 < *(int *)(in_ECX + 0x1044)) {
          iStack_1ac = local_1b4 * 4;
          iVar5 = local_1b0 % local_1b4 << 2;
          do {
            fVar7 = *(float *)(iVar5 + *(int *)(in_ECX + 0x18));
            fVar8 = ABS(fVar7);
            if (*pfVar4 <= fVar8 && fVar8 != *pfVar4) {
              *pfVar4 = fVar8;
            }
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + iStack_1ac;
            pfVar4 = pfVar4 + 1;
            *local_1bc = *local_1bc + fVar7;
          } while (iVar3 < *(int *)(in_ECX + 0x1044));
        }
        local_1b0 = local_1b0 + 1;
        local_1bc = local_1bc + 1;
      } while ((int)local_1b0 < 0x100);
    }
    __security_check_cookie(local_c ^ (uint)auStack_1c0);
    return;
  }
  FUN_1001ec20(aCStack_d8,"%s(%d): assert(%s) failed.\n",
               "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x894);
  OutputDebugStringA(aCStack_d8);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

