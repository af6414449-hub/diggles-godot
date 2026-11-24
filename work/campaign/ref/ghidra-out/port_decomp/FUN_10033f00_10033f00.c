
undefined4 FUN_10033f00(uint param_1,char param_2,int param_3,byte param_4,int *param_5,int param_6)

{
  int iVar1;
  uint in_EDX;
  int *piVar2;
  uint local_20;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_20 = 0;
  if (param_1 != 0) {
    piVar2 = (int *)(param_6 + -0x7c);
    do {
      if (param_2 == '\0') {
        piVar2[0x1f] = 0;
      }
      else {
        iVar1 = FUN_1002d470(piVar2 + 0x1f);
        if (iVar1 == 0) {
          return 0;
        }
      }
      if (in_EDX < 0x18) {
        iVar1 = 0;
        switch(param_3) {
        case 0x20:
          iVar1 = piVar2[-1] * param_5[0x1f];
        case 0x1f:
          iVar1 = iVar1 + param_5[0x1e] * *piVar2;
        case 0x1e:
          iVar1 = iVar1 + piVar2[1] * param_5[0x1d];
        case 0x1d:
          iVar1 = iVar1 + piVar2[2] * param_5[0x1c];
        case 0x1c:
          iVar1 = iVar1 + piVar2[3] * param_5[0x1b];
        case 0x1b:
          iVar1 = iVar1 + piVar2[4] * param_5[0x1a];
        case 0x1a:
          iVar1 = iVar1 + piVar2[5] * param_5[0x19];
        case 0x19:
          iVar1 = iVar1 + piVar2[6] * param_5[0x18];
        case 0x18:
          iVar1 = iVar1 + piVar2[7] * param_5[0x17];
        case 0x17:
          iVar1 = iVar1 + piVar2[8] * param_5[0x16];
        case 0x16:
          iVar1 = iVar1 + piVar2[9] * param_5[0x15];
        case 0x15:
          iVar1 = iVar1 + piVar2[10] * param_5[0x14];
        case 0x14:
          iVar1 = iVar1 + piVar2[0xb] * param_5[0x13];
        case 0x13:
          iVar1 = iVar1 + piVar2[0xc] * param_5[0x12];
        case 0x12:
          iVar1 = iVar1 + piVar2[0xd] * param_5[0x11];
        case 0x11:
          iVar1 = iVar1 + piVar2[0xe] * param_5[0x10];
        case 0x10:
          iVar1 = iVar1 + piVar2[0xf] * param_5[0xf];
        case 0xf:
          iVar1 = iVar1 + piVar2[0x10] * param_5[0xe];
        case 0xe:
          iVar1 = iVar1 + piVar2[0x11] * param_5[0xd];
        case 0xd:
          iVar1 = iVar1 + piVar2[0x12] * param_5[0xc];
        case 0xc:
          iVar1 = iVar1 + piVar2[0x13] * param_5[0xb];
        case 0xb:
          iVar1 = iVar1 + piVar2[0x14] * param_5[10];
        case 10:
          iVar1 = iVar1 + piVar2[0x15] * param_5[9];
        case 9:
          iVar1 = iVar1 + piVar2[0x16] * param_5[8];
        case 8:
          iVar1 = iVar1 + piVar2[0x17] * param_5[7];
        case 7:
          iVar1 = iVar1 + piVar2[0x18] * param_5[6];
        case 6:
          iVar1 = iVar1 + piVar2[0x19] * param_5[5];
        case 5:
          iVar1 = iVar1 + piVar2[0x1a] * param_5[4];
        case 4:
          iVar1 = iVar1 + piVar2[0x1b] * param_5[3];
        case 3:
          iVar1 = iVar1 + piVar2[0x1c] * param_5[2];
        case 2:
          iVar1 = iVar1 + piVar2[0x1d] * param_5[1];
        case 1:
          iVar1 = iVar1 + piVar2[0x1e] * *param_5;
        default:
          piVar2[0x1f] = piVar2[0x1f] + (iVar1 >> (param_4 & 0x1f));
        }
      }
      else {
        if (((((param_3 != 8) && (param_3 != 7)) && (param_3 != 3)) &&
            (((param_3 != 6 && (param_3 != 5)) &&
             ((param_3 != 4 && ((param_3 != 0xc && (param_3 != 2)))))))) &&
           ((param_3 != 1 &&
            ((((param_3 != 10 && (param_3 != 9)) && (param_3 != 0xb)) && (iVar1 = 0, 1 < param_3))))
           )) {
          do {
            iVar1 = iVar1 + 2;
          } while (iVar1 < param_3 + -1);
        }
        iVar1 = __allshr();
        piVar2[0x1f] = piVar2[0x1f] + iVar1;
      }
      piVar2 = piVar2 + 1;
      local_20 = local_20 + 1;
    } while (local_20 < param_1);
  }
  return 1;
}

