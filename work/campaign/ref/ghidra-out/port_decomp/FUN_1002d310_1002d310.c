
undefined4 FUN_1002d310(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  uVar1 = in_ECX[5];
  if (uVar1 < 0x400) {
    iVar3 = uVar1 + 1;
    uVar2 = in_ECX[uVar1 + 7];
  }
  else {
    iVar5 = in_ECX[3];
    if (iVar5 != 0) {
LAB_1002d3f7:
      in_ECX[3] = 0;
      uVar1 = in_ECX[4];
      in_ECX[6] = iVar5 * -8 + 0x20;
      in_ECX[0x407] =
           (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18) &
           ~(0xffffffffU >> ((char)iVar5 * '\b' & 0x1fU));
      return 1;
    }
    uVar1 = (*(code *)*in_ECX)(in_ECX[2],in_ECX + 7,0x1000);
    in_ECX[5] = 0;
    if (uVar1 == 0x1000) {
      uVar2 = in_ECX[7];
      iVar3 = 1;
    }
    else {
      uVar4 = uVar1 >> 2;
      iVar5 = uVar1 + uVar4 * -4;
      in_ECX[3] = iVar5;
      if (iVar5 != 0) {
        in_ECX[4] = in_ECX[uVar4 + 7];
      }
      if (uVar4 == 0) {
        in_ECX[5] = 0x400;
        if (iVar5 == 0) {
          in_ECX[6] = 0x20;
          return 0;
        }
        goto LAB_1002d3f7;
      }
      iVar5 = -uVar4;
      puVar6 = in_ECX + uVar4 + 6;
      puVar7 = in_ECX + 0x406;
      do {
        uVar2 = *puVar6;
        puVar6 = puVar6 + -1;
        *puVar7 = uVar2;
        puVar7 = puVar7 + -1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      in_ECX[5] = iVar5 + 0x400;
      iVar3 = iVar5 + 0x401;
      uVar2 = in_ECX[iVar5 + 0x407];
    }
  }
  in_ECX[0x407] = uVar2;
  in_ECX[5] = iVar3;
  uVar1 = in_ECX[0x407];
  in_ECX[0x407] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  in_ECX[6] = 0;
  return 1;
}

