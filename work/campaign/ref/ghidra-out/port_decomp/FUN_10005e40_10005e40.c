
void FUN_10005e40(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 in_EDX;
  uint uVar5;
  undefined4 in_stack_fffffeb0;
  undefined4 uVar6;
  undefined4 in_stack_fffffec4;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  int *piVar15;
  int local_f4;
  undefined4 local_ec;
  undefined1 local_e8 [44];
  undefined1 local_bc [24];
  undefined1 local_a4 [48];
  undefined1 local_74 [12];
  undefined8 local_68;
  int local_60;
  int local_5c [5];
  undefined4 local_48;
  undefined4 uStack_44;
  float fStack_40;
  float fStack_3c;
  undefined1 local_30 [8];
  undefined1 local_28 [4];
  undefined1 local_24 [12];
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = 0xff;
  uStack_7 = 0xffffff;
  puStack_c = &LAB_10041919;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (in_ECX[0x19] == 0) {
    FUN_100052e0("Call SetWindow with a valid Win32 window handle");
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_24,(ThrowInfo *)&DAT_1004a25c);
  }
  local_ec = 0;
  (**(code **)(*(int *)in_ECX[2] + 0x84))((int *)in_ECX[2],1,&local_ec,0);
  piVar15 = (int *)in_ECX[7];
  if (piVar15 != (int *)0x0) {
    in_ECX[7] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x10];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x10] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x11];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x11] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[8];
  if (piVar15 != (int *)0x0) {
    in_ECX[8] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x13];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x13] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[5];
  if (piVar15 != (int *)0x0) {
    in_ECX[5] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0xf];
  if (piVar15 != (int *)0x0) {
    in_ECX[0xf] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[6];
  if (piVar15 != (int *)0x0) {
    in_ECX[6] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x12];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x12] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  (**(code **)(*(int *)in_ECX[2] + 0x1bc))((int *)in_ECX[2]);
  local_f4 = in_ECX[0x15];
  if ((*(byte *)(in_ECX + 0x20) & 7) != 0) {
    if (local_f4 == 0x1d) {
      local_f4 = 0x1c;
    }
    else if (local_f4 == 0x5b) {
      local_f4 = 0x57;
    }
    else if (local_f4 == 0x5d) {
      local_f4 = 0x58;
    }
  }
  iVar1 = in_ECX[0x1d];
  iVar4 = in_ECX[0x1e];
  iVar9 = in_ECX[0x1b];
  iVar2 = in_ECX[0x1c];
  if (in_ECX[3] == 0) {
    FUN_100077a0(iVar1 - iVar9,iVar4 - iVar2,local_f4);
    iVar3 = (**(code **)(*(int *)*in_ECX + 0x20))((int *)*in_ECX,in_ECX[0x19],2);
    if (iVar3 < 0) goto LAB_10006728;
  }
  in_ECX[0x32] = 1;
  in_ECX[0x33] = 0;
  if ((char)in_ECX[0x34] != '\0') {
    *(undefined1 *)(in_ECX + 0x34) = 0;
    uVar5 = 1;
    do {
      iVar3 = (**(code **)(*(int *)in_ECX[1] + 0x78))((int *)in_ECX[1],in_ECX[0x15],uVar5,&local_18)
      ;
      if (iVar3 < 0) break;
      if (local_18 != 0) {
        in_ECX[0x32] = uVar5;
        in_ECX[0x33] = local_18 + -1;
        *(undefined1 *)(in_ECX + 0x34) = 1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x21);
  }
  if ((in_ECX[0x23] == 0) || ((char)in_ECX[0x31] != '\0')) {
    FUN_10007410(local_f4);
    if (DisplayModeManager::s_instance == (DisplayModeManager *)0x0) {
      DisplayModeManager::s_instance = (DisplayModeManager *)FUN_1003ff62(0xc);
      *(undefined8 *)DisplayModeManager::s_instance = 0;
      *(undefined4 *)(DisplayModeManager::s_instance + 8) = 0;
    }
    iVar3 = FUN_100078b0(iVar1 - iVar9,iVar4 - iVar2,
                         *(undefined4 *)(DisplayModeManager::s_instance + 4));
    in_ECX[0x2c] = iVar3;
    iVar1 = in_ECX[0x24];
    piVar15 = (int *)(iVar1 + iVar3 * 0x1c);
    iVar4 = piVar15[1];
    iVar9 = piVar15[2];
    iVar2 = piVar15[3];
    in_ECX[0x25] = *piVar15;
    in_ECX[0x26] = iVar4;
    in_ECX[0x27] = iVar9;
    in_ECX[0x28] = iVar2;
    *(undefined8 *)(in_ECX + 0x29) = *(undefined8 *)(iVar1 + 0x10 + iVar3 * 0x1c);
    in_ECX[0x2b] = *(int *)(iVar1 + 0x18 + iVar3 * 0x1c);
    *(undefined1 *)(in_ECX + 0x31) = 0;
  }
  iVar1 = in_ECX[0x25];
  local_18 = in_ECX[0x26];
  local_68 = *(undefined8 *)(in_ECX + 0x29);
  in_ECX[0x1d] = in_ECX[0x25];
  local_60 = in_ECX[0x2b];
  in_ECX[0x1e] = in_ECX[0x26];
  in_ECX[0x1c] = 0;
  in_ECX[0x1b] = 0;
  uVar8 = 0x1000615f;
  iVar3 = (**(code **)(*(int *)in_ECX[3] + 0x34))
                    ((int *)in_ECX[3],in_ECX[0x17],iVar1,local_18,local_f4,(in_ECX[0x20] & 2U) << 10
                    );
  if ((iVar3 != -0x7785fffb) && (iVar3 != -0x7785fff9)) {
    if (-1 < iVar3) {
      piVar15 = (int *)in_ECX[5];
      piVar12 = (int *)in_ECX[3];
      if (piVar15 != (int *)0x0) {
        in_ECX[5] = 0;
        (**(code **)(*piVar15 + 8))(piVar15);
      }
      iVar3 = (**(code **)(*piVar12 + 0x24))(piVar12,0,&DAT_10044798,in_ECX + 5);
      if (-1 < iVar3) {
        local_5c[0] = local_f4;
        local_5c[1] = 4;
        local_5c[2] = 0;
        local_8 = 3;
        uStack_7 = 0;
        piVar15 = (int *)in_ECX[7];
        piVar12 = (int *)in_ECX[1];
        if (piVar15 != (int *)0x0) {
          in_ECX[7] = 0;
          (**(code **)(*piVar15 + 8))(piVar15);
        }
        iVar3 = (**(code **)(*piVar12 + 0x24))(piVar12,in_ECX[5],local_5c,in_ECX + 7);
        if (-1 < iVar3) {
          FUN_100050b0(in_ECX[0x15],iVar1,local_18,in_stack_fffffec4,uVar8,0x28,0,0,in_ECX[0x32],
                       in_ECX[0x33],extraout_ECX);
          local_8 = 4;
          piVar15 = (int *)in_ECX[0xf];
          piVar12 = (int *)in_ECX[1];
          if (piVar15 != (int *)0x0) {
            in_ECX[0xf] = 0;
            (**(code **)(*piVar15 + 8))(piVar15);
          }
          piVar15 = in_ECX + 0xf;
          uVar8 = 0;
          puVar13 = local_e8;
          iVar3 = (**(code **)(*piVar12 + 0x14))(piVar12,puVar13,0,piVar15);
          if (-1 < iVar3) {
            FUN_10005190(((char)in_ECX[0x34] != '\0') * '\x02' + '\x04',local_f4,puVar13,uVar8,
                         piVar15);
            local_8 = 5;
            piVar15 = (int *)in_ECX[0x10];
            piVar12 = (int *)in_ECX[1];
            if (piVar15 != (int *)0x0) {
              in_ECX[0x10] = 0;
              (**(code **)(*piVar15 + 8))(piVar15);
            }
            piVar15 = in_ECX + 0x10;
            puVar14 = &uStack_44;
            iVar4 = in_ECX[0xf];
            uVar8 = 0x100062d6;
            iVar3 = (**(code **)(*piVar12 + 0x24))(piVar12,iVar4,puVar14,piVar15);
            if (-1 < iVar3) {
              iVar9 = (uint)((char)in_ECX[0x34] != '\0') * 2 + 4;
              piVar7 = (int *)0x10006300;
              FUN_10005120(iVar9,local_f4,uVar8,piVar12,iVar4,puVar14,piVar15);
              local_8 = 6;
              piVar15 = (int *)in_ECX[0x11];
              piVar12 = (int *)in_ECX[1];
              if (piVar15 != (int *)0x0) {
                in_ECX[0x11] = 0;
                (**(code **)(*piVar15 + 8))(piVar15);
              }
              iVar3 = (**(code **)(*piVar12 + 0x1c))(piVar12,in_ECX[0xf],local_bc,in_ECX + 0x11);
              if (-1 < iVar3) {
                iVar4 = in_ECX[0x16];
                uVar8 = extraout_ECX_00;
                if (iVar4 != 0) {
                  uVar10 = 0x48;
                  uVar8 = 0x10006371;
                  FUN_100050b0(0x27,iVar1,local_18,piVar7,iVar9,0x48,0,0,in_ECX[0x32],in_ECX[0x33],
                               extraout_ECX_00);
                  local_8 = 7;
                  piVar15 = (int *)in_ECX[0x12];
                  piVar12 = (int *)in_ECX[1];
                  if (piVar15 != (int *)0x0) {
                    in_ECX[0x12] = 0;
                    (**(code **)(*piVar15 + 8))(piVar15);
                  }
                  (**(code **)(*piVar12 + 0x14))(piVar12,local_a4,0,in_ECX + 0x12);
                  uVar11 = 0x100063a6;
                  FUN_10005440();
                  iVar4 = (uint)((char)in_ECX[0x34] != '\0') * 2 + 3;
                  uVar6 = 0x100063c6;
                  FUN_10005210(iVar4,0x28,piVar7,iVar9,uVar10,uVar11);
                  local_8 = 8;
                  piVar15 = in_ECX + 0x13;
                  piVar12 = (int *)*piVar15;
                  piVar7 = (int *)in_ECX[1];
                  if (piVar12 != (int *)0x0) {
                    *piVar15 = 0;
                    (**(code **)(*piVar12 + 8))(piVar12);
                  }
                  iVar9 = in_ECX[0x12];
                  (**(code **)(*piVar7 + 0x28))(piVar7,iVar9,local_30,piVar15);
                  uVar10 = 0x10006403;
                  FUN_10005440();
                  FUN_10005120(((char)in_ECX[0x34] != '\0') * '\x02' + '\x04',0x29,in_stack_fffffeb0
                               ,uVar8,uVar6,iVar4,uVar10);
                  local_8 = 9;
                  piVar15 = (int *)in_ECX[1];
                  iVar4 = in_ECX[0x12];
                  iVar2 = *piVar15;
                  uVar8 = FUN_10007b50();
                  (**(code **)(iVar2 + 0x1c))(piVar15,iVar4,local_74,uVar8);
                  FUN_10005440();
                  iVar4 = in_ECX[0x16];
                  uVar8 = extraout_ECX_01;
                }
                local_8 = 3;
                if (iVar4 != 0) {
                  FUN_100050b0(iVar4,iVar1,local_18,piVar7,iVar9,0x40,0,0,1,0,uVar8);
                  local_8 = 10;
                  piVar15 = (int *)in_ECX[6];
                  piVar12 = (int *)in_ECX[1];
                  if (piVar15 != (int *)0x0) {
                    in_ECX[6] = 0;
                    (**(code **)(*piVar15 + 8))(piVar15);
                  }
                  (**(code **)(*piVar12 + 0x14))(piVar12,local_a4,0,in_ECX + 6);
                  FUN_10005440();
                  local_48 = 0;
                  uStack_44 = 3;
                  fStack_40 = 0.0;
                  fStack_3c = 0.0;
                  local_8 = 0xb;
                  piVar15 = (int *)in_ECX[8];
                  piVar12 = (int *)in_ECX[1];
                  if (piVar15 != (int *)0x0) {
                    in_ECX[8] = 0;
                    (**(code **)(*piVar15 + 8))(piVar15);
                  }
                  (**(code **)(*piVar12 + 0x28))(piVar12,in_ECX[6],&local_48,in_ECX + 8);
                  FUN_10005440();
                }
                local_8 = 3;
                local_48 = 0;
                uStack_44 = 0;
                fStack_40 = (float)((double)iVar1 +
                                   *(double *)(&DAT_10047c80 + (iVar1 >> 0x1f) * -8));
                fStack_3c = (float)((double)local_18 +
                                   *(double *)(&DAT_10047c80 + (local_18 >> 0x1f) * -8));
                in_ECX[9] = 0;
                in_ECX[10] = 0;
                in_ECX[0xb] = (int)fStack_40;
                in_ECX[0xc] = (int)fStack_3c;
                in_ECX[0xd] = 0;
                in_ECX[0xe] = 0x3f800000;
                (**(code **)(*(int *)in_ECX[2] + 0xb0))((int *)in_ECX[2],1,in_ECX + 9);
                OutputDebugStringA(s_CreateWindowSizeDependentResourc_10050060);
                goto LAB_100066f2;
              }
            }
          }
        }
      }
    }
LAB_10006728:
    FUN_100053a0(iVar3);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_28,(ThrowInfo *)&DAT_1004a24c);
  }
  OutputDebugStringA("DX Device was lost! \n");
  if ((undefined4 *)in_ECX[0x21] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x21])();
  }
  piVar15 = (int *)in_ECX[8];
  if (piVar15 != (int *)0x0) {
    in_ECX[8] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x13];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x13] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[7];
  if (piVar15 != (int *)0x0) {
    in_ECX[7] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x10];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x10] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x11];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x11] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[5];
  if (piVar15 != (int *)0x0) {
    in_ECX[5] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0xf];
  if (piVar15 != (int *)0x0) {
    in_ECX[0xf] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[6];
  if (piVar15 != (int *)0x0) {
    in_ECX[6] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[0x12];
  if (piVar15 != (int *)0x0) {
    in_ECX[0x12] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[3];
  if (piVar15 != (int *)0x0) {
    in_ECX[3] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[2];
  if (piVar15 != (int *)0x0) {
    in_ECX[2] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[4];
  if (piVar15 != (int *)0x0) {
    in_ECX[4] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)in_ECX[1];
  if (piVar15 != (int *)0x0) {
    in_ECX[1] = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  piVar15 = (int *)*in_ECX;
  if (piVar15 != (int *)0x0) {
    *in_ECX = 0;
    (**(code **)(*piVar15 + 8))(piVar15);
  }
  FUN_10005840();
  FUN_10005e40();
  if ((int *)in_ECX[0x21] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x21] + 4))();
  }
LAB_100066f2:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

