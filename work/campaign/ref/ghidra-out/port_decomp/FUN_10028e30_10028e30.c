
/* WARNING: Removing unreachable block (ram,0x1002995d) */
/* WARNING: Removing unreachable block (ram,0x10029a17) */

void FUN_10028e30(void)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  char cVar8;
  undefined4 *in_ECX;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  longlong lVar18;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  undefined4 local_bc;
  uint uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined4 uStack_a0;
  undefined8 local_9c;
  char local_94 [16];
  uint local_84;
  uint local_80;
  uint local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined2 local_36;
  undefined4 local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  char local_2c [16];
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  iVar2 = (*(code *)*in_ECX)(in_ECX[3],&local_64,4);
  uVar12 = 0;
  if (iVar2 != 4) goto LAB_100297b9;
  cVar8 = (char)(local_64 >> 8);
  if ((local_64 & 0xff) == 0x52) {
    if (((cVar8 != 'I') || (local_64._2_1_ != 'F')) || (local_64._3_1_ != 'F')) goto LAB_100297b9;
    uVar7 = in_ECX[3];
    in_ECX[8] = 0;
    pcVar3 = (code *)*in_ECX;
    uVar6 = 4;
LAB_10028f25:
    uVar4 = (*pcVar3)(uVar7,&local_5c,4);
    if ((uVar4 != 4) ||
       ((((local_5c >> 0x10) << 8 | local_5c >> 8 & 0xff) << 8 | local_5c & 0xff) < 0x24))
    goto LAB_100297b9;
    uVar5 = (*(code *)*in_ECX)(in_ECX[3],&local_60,4);
    local_1c = uVar5 + uVar4 + uVar6;
    local_18 = uVar12 + CARRY4(uVar4,uVar6) + (uint)CARRY4(uVar5,uVar4 + uVar6);
    if ((uVar5 != 4) ||
       (((((char)local_60 != 'W' || ((char)(local_60 >> 8) != 'A')) || (local_60._2_1_ != 'V')) ||
        (local_60._3_1_ != 'E')))) goto LAB_100297b9;
  }
  else {
    if (((((local_64 & 0xff) != 0x72) || (cVar8 != 'i')) || (local_64._2_1_ != 'f')) ||
       (local_64._3_1_ != 'f')) goto LAB_100297b9;
    in_ECX[8] = 1;
    uVar4 = (*(code *)*in_ECX)(in_ECX[3],&local_1c,0xc);
    uVar6 = uVar4 + 4;
    uVar12 = (uint)(0xfffffffb < uVar4);
    if (uVar4 != 0xc) goto LAB_100297b9;
    iVar2 = 0;
    do {
      if (*(char *)((int)&local_1c + iVar2) != (&DAT_10043b34)[iVar2]) goto LAB_100297b9;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xc);
    pcVar3 = (code *)*in_ECX;
    uVar7 = in_ECX[3];
    if (in_ECX[8] == 0) goto LAB_10028f25;
    uVar4 = (*pcVar3)(uVar7,&local_18,8);
    if (uVar4 != 8) goto LAB_100297b9;
    uVar5 = (local_14 << 8 | local_18 >> 0x18) << 8;
    uVar13 = (uVar5 | local_18 >> 0x10 & 0xff) << 8;
    uVar5 = (((local_14 >> 0x18) << 8 | (local_14 << 8) >> 0x18) << 8 | uVar5 >> 0x18) << 8 |
            uVar13 >> 0x18;
    local_74 = CONCAT44(uVar5,(uint)local_74);
    if ((uVar5 == 0) && (((uVar13 | local_18 >> 8 & 0xff) << 8 | local_18 & 0xff) < 0x50))
    goto LAB_100297b9;
    uVar5 = (*(code *)*in_ECX)(in_ECX[3],local_2c,0x10);
    local_1c = uVar5 + uVar4 + uVar6;
    local_18 = uVar12 + CARRY4(uVar4,uVar6) + (uint)CARRY4(uVar5,uVar4 + uVar6);
    if (uVar5 != 0x10) goto LAB_100297b9;
    iVar2 = 0;
    do {
      if (local_2c[iVar2] != (&DAT_10043f60)[iVar2]) goto LAB_100297b9;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x10);
  }
  piVar9 = in_ECX + 8;
  iVar2 = FUN_10028a30(in_ECX[3],*piVar9,&local_1c,&local_bc);
  if (((iVar2 == 0) || (uStack_b8 == 0)) ||
     ((0x5dc00 < uStack_b8 ||
      (((local_bc._2_2_ == 0 || (0x100 < local_bc._2_2_)) ||
       ((uStack_b0._2_2_ == 0 || ((0x40 < uStack_b0._2_2_ || ((short)uStack_b0 == 0))))))))))
  goto LAB_100297b9;
  uVar12 = local_bc;
  if ((short)local_bc == -2) {
    uVar12 = uStack_a4;
  }
  local_d0 = uVar12 & 0xffff;
  local_6c = 0;
  local_c8 = 0;
  local_74 = 0;
  iVar2 = FUN_10028780(*piVar9,&local_1c,local_94);
  if (iVar2 != 0) goto LAB_100297b9;
  local_c0 = local_74._4_4_;
  local_c4 = (uint)local_74;
  do {
    uVar5 = local_1c;
    uVar4 = local_80;
    uVar6 = local_84;
    local_5c = local_c8;
    local_60 = local_18;
    local_d8 = local_1c;
    if (local_c8 == 0) {
      in_ECX[0x1a] = local_1c;
      in_ECX[0x1b] = local_18;
    }
    uVar13 = local_84;
    if (*piVar9 == 0) {
      if (local_94[0] == 'd') {
        if (((local_94[1] == 'a') && (local_94[2] == 't')) && (local_94[3] == 'a')) {
          local_c8 = 1;
          local_c4 = local_84;
          local_c0 = local_80;
        }
      }
      else if ((((local_94[0] == 'f') && (local_94[1] == 'a')) && (local_94[2] == 'c')) &&
              (local_94[3] == 't')) {
        uVar13 = (*(code *)*in_ECX)(in_ECX[3],(int)&local_74 + 4,4);
        local_d8 = uVar5 + uVar13;
        local_60 = local_60 + CARRY4(uVar5,uVar13);
        if (uVar13 != 4) goto LAB_100297b9;
        uVar4 = (uVar4 - 1) + (uint)(3 < uVar6);
        if (local_5c == 0) {
          in_ECX[0x1a] = local_d8;
          in_ECX[0x1b] = local_60;
        }
        uVar13 = uVar6 - 4;
        if (*(short *)(in_ECX + 0x15) == 2) {
          local_6c = local_74 >> 0x20;
          local_c8 = local_5c;
        }
        else {
          local_c8 = local_5c;
          local_6c = 0;
        }
      }
    }
    else {
      iVar2 = 0;
      do {
        if (local_94[iVar2] != (&DAT_100438b0)[iVar2]) goto LAB_100293eb;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x10);
      local_c8 = 1;
      local_c4 = local_84;
      local_c0 = local_80;
LAB_100293eb:
      iVar2 = 0;
      do {
        if (local_94[iVar2] != (&DAT_10043d50)[iVar2]) goto LAB_1002944a;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x10);
      uVar13 = (*(code *)*in_ECX)(in_ECX[3],&local_6c,8);
      local_d8 = uVar5 + uVar13;
      local_60 = local_60 + CARRY4(uVar5,uVar13);
      if (uVar13 != 8) goto LAB_100297b9;
      uVar13 = uVar6 - 8;
      uVar4 = (uVar4 - 1) + (uint)(7 < uVar6);
      if (local_c8 == 0) {
        in_ECX[0x1a] = local_d8;
        in_ECX[0x1b] = local_60;
      }
    }
LAB_1002944a:
    if (*piVar9 == 0) {
      if ((local_94[0] == 's') &&
         (((local_94[1] == 'm' && (local_94[2] == 'p')) && (local_94[3] == 'l')))) {
        bVar14 = true;
      }
      else {
        bVar14 = false;
      }
      if ((bVar14) && ((uVar4 != 0 || (0x23 < uVar13)))) {
        uVar6 = (*(code *)*in_ECX)(in_ECX[3],&local_58,0x24);
        bVar14 = CARRY4(local_d8,uVar6);
        local_d8 = local_d8 + uVar6;
        local_60 = local_60 + bVar14;
        bVar14 = uVar13 < uVar6;
        uVar13 = uVar13 - uVar6;
        uVar4 = uVar4 - bVar14;
        local_5c = uVar4;
        if (uVar6 == 0x24) {
          in_ECX[0x21] = local_58;
          in_ECX[0x22] = CONCAT31(CONCAT21(CONCAT11(local_51,local_52),local_53),local_54);
          in_ECX[0x23] = CONCAT31(CONCAT21(CONCAT11(local_4d,local_4e),local_4f),local_50);
          in_ECX[0x24] = CONCAT31(CONCAT21(CONCAT11(local_49,local_4a),local_4b),local_4c);
          in_ECX[0x25] = CONCAT31(CONCAT21(CONCAT11(local_45,local_46),local_47),local_48);
          in_ECX[0x26] = CONCAT31(CONCAT21(CONCAT11(local_41,local_42),local_43),local_44);
          in_ECX[0x27] = CONCAT31(CONCAT21(CONCAT11(local_3d,local_3e),local_3f),local_40);
          iVar2 = CONCAT31(CONCAT21(CONCAT11(local_39,local_3a),local_3b),local_3c);
          in_ECX[0x28] = iVar2;
          in_ECX[0x29] = CONCAT31(CONCAT21(local_36,local_37),local_38);
          bVar14 = false;
          if (iVar2 != 0) {
            puVar10 = in_ECX + 0x2b;
            do {
              uVar4 = local_5c;
              if (bVar14) break;
              uVar6 = (*(code *)*in_ECX)(in_ECX[3],&local_34,0x18);
              bVar14 = CARRY4(local_d8,uVar6);
              local_d8 = local_d8 + uVar6;
              local_60 = local_60 + bVar14;
              bVar14 = uVar13 < uVar6;
              uVar13 = uVar13 - uVar6;
              uVar4 = local_5c - bVar14;
              local_5c = uVar4;
              if (uVar6 != 0x18) break;
              puVar10[-1] = local_34;
              *puVar10 = CONCAT31(CONCAT21(CONCAT11(local_2d,local_2e),local_2f),local_30);
              puVar10[1] = CONCAT31(CONCAT21(CONCAT11(local_2c[3],local_2c[2]),local_2c[1]),
                                    local_2c[0]);
              puVar10[2] = CONCAT31(CONCAT21(CONCAT11(local_2c[7],local_2c[6]),local_2c[5]),
                                    local_2c[4]);
              puVar10[3] = CONCAT31(CONCAT21(CONCAT11(local_2c[0xb],local_2c[10]),local_2c[9]),
                                    local_2c[8]);
              puVar10[4] = CONCAT31(CONCAT21(CONCAT11(local_2c[0xf],local_2c[0xe]),local_2c[0xd]),
                                    local_2c[0xc]);
              bVar14 = true;
              puVar10 = puVar10 + 6;
            } while (1 < (uint)in_ECX[0x28]);
          }
        }
      }
    }
    else {
      iVar2 = 0;
      while ((local_94[iVar2] == (&DAT_100438c0)[iVar2] &&
             (local_94[iVar2 + 1] == (&DAT_100438c1)[iVar2]))) {
        if ((local_94[iVar2 + 2] != (&DAT_100438c2)[iVar2]) ||
           ((local_94[iVar2 + 3] != (&DAT_100438c3)[iVar2] || (iVar2 = iVar2 + 4, 0xf < iVar2))))
        break;
      }
    }
    uVar6 = uVar13 + local_7c;
    iVar11 = uVar4 + CARRY4(uVar13,local_7c);
    iVar2 = FUN_10028900(uVar6,iVar11);
    if (iVar2 == 0) {
      if (local_c8 != 0) goto LAB_10029832;
      goto LAB_100297b9;
    }
    local_1c = local_d8 + uVar6;
    local_18 = local_60 + iVar11 + (uint)CARRY4(local_d8,uVar6);
    if (local_c8 == 0) {
      in_ECX[0x1a] = local_1c;
      in_ECX[0x1b] = local_18;
    }
    iVar2 = FUN_10028780(*piVar9,&local_1c,local_94);
  } while (iVar2 == 0);
  if (local_c8 == 0) goto LAB_100297b9;
LAB_10029832:
  iVar2 = FUN_10028980(in_ECX[0x1a],in_ECX[0x1b]);
  if (iVar2 == 0) goto LAB_100297b9;
  in_ECX[0x13] = uStack_b8;
  *(ushort *)(in_ECX + 0x14) = local_bc._2_2_;
  in_ECX[9] = local_bc;
  in_ECX[10] = uStack_b8;
  in_ECX[0xb] = uStack_b4;
  in_ECX[0xc] = uStack_b0;
  *(ushort *)((int)in_ECX + 0x52) = uStack_b0._2_2_;
  sVar1 = (short)uVar12;
  *(short *)(in_ECX + 0x15) = sVar1;
  in_ECX[0x1c] = local_c4;
  in_ECX[0xd] = local_ac;
  in_ECX[0xe] = uStack_a8;
  in_ECX[0xf] = uStack_a4;
  in_ECX[0x10] = uStack_a0;
  in_ECX[0x1d] = local_c0;
  *(undefined8 *)(in_ECX + 0x11) = local_9c;
  in_ECX[0x18] = local_c4;
  in_ECX[0x19] = local_c0;
  if ((int)local_6c == 0 && local_6c._4_4_ == 0) {
    uVar7 = FUN_10028d70();
    uVar15 = __aulldiv(local_c4,local_c0,uVar7,0);
    sVar1 = *(short *)(in_ECX + 0x15);
    *(undefined8 *)(in_ECX + 0x16) = uVar15;
    if (sVar1 == 2) {
      uVar16 = __aulldiv(local_c4,local_c0,uStack_b0 & 0xffff,0);
      uVar17 = __allmul(uStack_b0 & 0xffff,0,uVar16);
      if (uVar17 < CONCAT44(local_c0,local_c4)) {
        uVar16 = uVar16 + 1;
      }
      uVar12 = (uint)local_bc._2_2_ * 6;
      lVar18 = (uVar16 & 0xffffffff) * (ulonglong)uVar12;
      uVar6 = (uint)lVar18;
      uVar4 = local_c4 - uVar6;
      uVar15 = __aulldiv(uVar4 * 2,
                         ((local_c0 -
                          ((int)(uVar16 >> 0x20) * uVar12 + (int)((ulonglong)lVar18 >> 0x20))) -
                         (uint)(local_c4 < uVar6)) * 2 | uVar4 >> 0x1f,(uint)local_bc._2_2_,0);
      *(undefined8 *)(in_ECX + 0x16) = uVar15;
    }
    else {
      if (sVar1 != 0x11) goto LAB_100298d2;
      uVar15 = __aulldiv(local_c4,local_c0,uStack_b0 & 0xffff,0);
      local_64 = (uint)((ulonglong)uVar15 >> 0x20);
      local_d4 = (uint)uVar15;
      uVar16 = __allmul(uStack_b0 & 0xffff,0,uVar15);
      if (uVar16 < CONCAT44(local_c0,local_c4)) {
        bVar14 = 0xfffffffe < local_d4;
        local_d4 = local_d4 + 1;
        local_64 = local_64 + bVar14;
      }
      uVar12 = (uint)local_bc._2_2_ * 4;
      lVar18 = (ulonglong)local_d4 * (ulonglong)uVar12;
      uVar6 = (uint)lVar18;
      uVar4 = local_c4 - uVar6;
      lVar18 = __aulldiv(uVar4 * 2,
                         ((local_c0 - (local_64 * uVar12 + (int)((ulonglong)lVar18 >> 0x20))) -
                         (uint)(local_c4 < uVar6)) * 2 | uVar4 >> 0x1f,(uint)local_bc._2_2_,0);
      *(longlong *)(in_ECX + 0x16) = lVar18 + CONCAT44(local_64,local_d4);
    }
  }
  else {
    in_ECX[0x16] = (int)local_6c;
    in_ECX[0x17] = local_6c._4_4_;
    if (local_d0 != 2) {
LAB_100298d2:
      if (sVar1 != 0x11) goto LAB_100298e3;
    }
  }
  if (2 < *(ushort *)(in_ECX + 0x14)) {
LAB_100297b9:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_100298e3:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

