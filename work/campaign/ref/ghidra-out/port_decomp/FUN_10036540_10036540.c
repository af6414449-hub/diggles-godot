
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x1003658a) */

void FUN_10036540(undefined4 param_1,undefined4 param_2,code **param_3,undefined4 param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 *puVar6;
  code **ppcVar7;
  uint *puVar8;
  int iVar9;
  void *_Dst;
  undefined4 *puVar10;
  code *pcVar11;
  undefined1 auStack_113b4 [4];
  uint uStack_113b0;
  code **ppcStack_113ac;
  undefined4 uStack_113a8;
  uint uStack_113a4;
  undefined4 uStack_113a0;
  code *pcStack_1139c;
  code *pcStack_11398;
  code *pcStack_11394;
  code *pcStack_11388;
  code *pcStack_11384;
  code **ppcStack_11380;
  undefined4 uStack_11378;
  undefined4 uStack_11374;
  undefined4 uStack_11370;
  undefined4 uStack_1136c;
  undefined4 uStack_11368;
  undefined4 auStack_11360 [144];
  undefined4 uStack_11120;
  undefined8 local_11f8;
  undefined4 local_11f0;
  undefined4 local_11ec;
  undefined4 local_11e0;
  int local_11dc;
  undefined4 local_11d4;
  undefined4 local_11d0;
  byte local_11cc;
  undefined1 local_11cb;
  undefined4 local_11c8;
  undefined4 local_11c4;
  ushort local_11c0;
  int local_11b0;
  int local_11ac;
  undefined1 local_11a8 [4144];
  undefined4 local_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined8 local_168;
  undefined4 local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150 [72];
  undefined4 local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  uint local_14;
  
  local_14 = DAT_1005000c ^ (uint)auStack_113b4;
  ppcStack_113ac = param_3;
  uStack_113a8 = param_4;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if (DAT_1416eae0 == 0) {
    puVar6 = (undefined4 *)cpuid(0x80000001);
    local_30 = *puVar6;
    uStack_2c = puVar6[1];
    uStack_24 = puVar6[2];
    uStack_28 = puVar6[3];
    DAT_10051098 = 1;
    DAT_1416dec0 = 1;
    DAT_1416eae0 = 1;
    DAT_1005109c = uStack_28 >> 5 & 1;
  }
  iVar3 = FUN_10036390();
  if (iVar3 == 0) {
LAB_10036a1b:
    __security_check_cookie(local_14 ^ (uint)auStack_113b4);
    return;
  }
  uStack_113a0 = 0;
  pcStack_1139c = FUN_10035510;
  pcStack_11398 = FUN_10035530;
  pcStack_11394 = FUN_10035550;
  if ((local_11c0 & 0xf) == 0) {
    uVar4 = (uint)(local_11c0 >> 4);
  }
  else {
    uVar4 = (local_11c0 >> 4) + 1;
  }
  uStack_113b0 = local_11cc * uVar4 * 0x40;
  uVar4 = uStack_113b0 + 0x1130;
  if (local_11dc == 1) {
    uVar4 = uStack_113b0 + 0x112c0;
  }
  uStack_113a4 = uVar4;
  memset(&pcStack_11388,0,0x10190);
  if (local_11dc == 1) {
    uStack_11374 = local_154;
    uStack_1136c = local_154;
    uStack_11378 = local_158;
    uStack_11370 = local_158;
    uStack_11368 = local_160;
    pcStack_11388 = FUN_1001ec50;
    pcStack_11384 = FUN_1001ec70;
    ppcStack_11380 = ppcStack_113ac;
    puVar6 = local_150;
    puVar10 = auStack_11360;
    for (iVar3 = 0x48; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar10 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar10 = puVar10 + 1;
    }
    uStack_11120 = 0;
    uVar4 = uStack_113a4;
  }
  pcVar11 = FUN_10035530;
  local_11f0 = 0x2a;
  local_11ec = 0;
  local_11f8 = 0;
  uStack_113a4 = 0;
  if (local_11ac == 0) {
    pcVar5 = FUN_10035510;
  }
  else {
    ppcVar7 = ppcStack_113ac;
    if (local_11dc == 1) {
      ppcVar7 = &pcStack_11388;
    }
    iVar3 = FUN_10035570(0,ppcVar7,uStack_113a8,&local_11f0,&local_11f8,&uStack_113a4,&uStack_113a0)
    ;
    if (iVar3 == 0) goto LAB_10036a1b;
    uVar4 = uVar4 + uStack_113a4;
    pcVar5 = pcStack_1139c;
    pcVar11 = pcStack_11398;
  }
  if (pcVar5 == (code *)0x0) {
    if (pcVar11 == (code *)0x0) goto LAB_10036a1b;
    puVar6 = (undefined4 *)(*pcVar11)(0,uVar4,uStack_113a0);
  }
  else {
    puVar6 = (undefined4 *)(*pcVar5)(uVar4,uStack_113a0);
  }
  if (puVar6 == (undefined4 *)0x0) goto LAB_10036a1b;
  memset(puVar6,0,0x10f0);
  memcpy(puVar6 + 0x2f,local_11a8,0x102c);
  *puVar6 = local_11e0;
  puVar6[1] = local_11d4;
  *(ushort *)((int)puVar6 + 0x1e) = local_11c0;
  puVar6[6] = local_11d0;
  *(byte *)(puVar6 + 7) = local_11cc;
  *(undefined1 *)((int)puVar6 + 0x1d) = local_11cb;
  puVar6[9] = local_11c4;
  puVar6[8] = local_11c8;
  uVar4 = (int)puVar6 + 0x1127U & 0xffffffc0;
  puVar6[10] = local_11dc;
  puVar6[0x2b] = uVar4;
  puVar6[2] = uStack_113a0;
  puVar6[3] = pcStack_1139c;
  puVar6[4] = pcStack_11398;
  puVar6[5] = pcStack_11394;
  if (local_11dc == 1) {
    _Dst = (void *)(uStack_113a4 + uVar4 + uStack_113b0);
    memcpy(_Dst,&pcStack_11388,0x10190);
    puVar6[0x31] = _Dst;
    puVar6[0x2d] = _Dst;
    puVar6[0x2f] = FUN_10035d80;
    puVar6[0x30] = FUN_10035fe0;
  }
  puVar6[0x26] = local_11f0;
  puVar6[0x27] = local_11ec;
  if (local_11dc != 1) {
    if ((int)local_11f8 == 0 && local_11f8._4_4_ == 0) goto LAB_10036a43;
    puVar6[0x2c] = puVar6[0x2b] + uStack_113b0;
    puVar6[0xb] = uStack_113a4 / 0x12;
    if ((code *)puVar6[0x30] == FUN_10035fe0) {
      iVar3 = FUN_10035fe0();
    }
    else {
      iVar3 = (*(code *)puVar6[0x30])(puVar6[0x31],(int)local_11f8,0);
    }
    if (iVar3 != 0) {
      if ((code *)puVar6[0x2f] == FUN_10035d80) {
        uVar4 = FUN_10035d80();
      }
      else {
        uVar4 = (*(code *)puVar6[0x2f])(puVar6[0x31],puVar6[0x2c],uStack_113a4);
      }
      if (uVar4 == uStack_113a4) {
        uStack_113b0 = 0;
        if (puVar6[0xb] != 0) {
          iVar3 = 0;
          do {
            puVar8 = (uint *)(puVar6[0x2c] + iVar3);
            uVar4 = puVar8[1];
            uVar2 = *puVar8;
            *puVar8 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
                      uVar4 << 0x18;
            puVar8[1] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                        uVar2 << 0x18;
            iVar9 = puVar6[0x2c] + iVar3;
            uVar4 = *(uint *)(iVar9 + 0xc);
            uVar2 = *(uint *)(iVar9 + 8);
            *(uint *)(iVar9 + 8) =
                 uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
            *(uint *)(iVar9 + 0xc) =
                 uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
            uVar1 = *(undefined2 *)(puVar6[0x2c] + 0x10 + iVar3);
            *(ushort *)(puVar6[0x2c] + 0x10 + iVar3) =
                 CONCAT11((char)uVar1,(char)((ushort)uVar1 >> 8));
            uStack_113b0 = uStack_113b0 + 1;
            iVar3 = iVar3 + 0x12;
          } while (uStack_113b0 < (uint)puVar6[0xb]);
        }
      }
      else {
        puVar6[0x2c] = 0;
        puVar6[0xb] = 0;
      }
      if ((code *)puVar6[0x30] == FUN_10035fe0) {
        iVar3 = FUN_10035fe0();
      }
      else {
        iVar3 = (*(code *)puVar6[0x30])(puVar6[0x31],puVar6[0x26],0);
      }
      if (iVar3 == 0) {
LAB_10036a09:
        if (pcStack_11394 != (code *)0x0) {
          (*pcStack_11394)(puVar6,uStack_113a0);
        }
        goto LAB_10036a1b;
      }
      goto LAB_10036a43;
    }
  }
  puVar6[0xb] = 0;
  puVar6[0x2c] = 0;
LAB_10036a43:
  if (local_11b0 == 0) {
    puVar6[0xc] = local_178;
    puVar6[0xd] = uStack_174;
    puVar6[0xe] = uStack_170;
    puVar6[0xf] = uStack_16c;
    *(undefined8 *)(puVar6 + 0x10) = local_168;
    iVar3 = FUN_10035130();
    while (iVar3 != 0) {
      if ((iVar3 != -0x81) || (iVar3 = FUN_10034760(puVar6 + 0xc), iVar3 == 0)) goto LAB_10036a09;
      iVar3 = FUN_10035130();
    }
  }
  __security_check_cookie(local_14 ^ (uint)auStack_113b4);
  return;
}

