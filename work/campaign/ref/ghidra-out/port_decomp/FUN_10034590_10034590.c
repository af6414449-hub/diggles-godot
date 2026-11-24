
undefined4 FUN_10034590(uint param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int in_EDX;
  uint uVar2;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_a;
  byte local_6;
  char local_5;
  
  local_10 = in_EDX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  iVar1 = FUN_1002d650(&local_5);
  if ((iVar1 != 0) && ((local_5 == '\0' || (local_5 == '\x01')))) {
    param_5 = param_5 + param_2 * 4;
    iVar1 = FUN_1002d650(&local_6);
    if ((iVar1 != 0) && (local_6 < 9)) {
      local_18 = 1 << (local_6 & 0x1f);
      param_1 = param_1 / local_18;
      if (param_2 < param_1) {
        uVar2 = param_1 - param_2;
        do {
          local_a = local_a & 0xffffff00;
          if (local_5 == '\0') {
            iVar1 = FUN_1002d650(&local_a);
            if (iVar1 == 0) {
              return 0;
            }
            if ((char)local_a != '\x0f') {
LAB_10034685:
              if ((char)local_a != -1) goto LAB_100346ca;
            }
LAB_10034689:
            local_14 = local_14 & 0xffffff00;
            iVar1 = FUN_1002d650(&local_14);
            if (iVar1 == 0) {
              return 0;
            }
            iVar1 = FUN_10033f00(uVar2,local_14,param_2,param_3,param_4,param_5);
          }
          else {
            if (local_5 == '\x01') {
              iVar1 = FUN_1002d650(&local_a);
              if (iVar1 == 0) {
                return 0;
              }
              if ((char)local_a != '\x1f') goto LAB_10034685;
              goto LAB_10034689;
            }
LAB_100346ca:
            if ((DAT_1416dec0 == 0) || (0xb < param_2 - 1)) {
              iVar1 = FUN_1002dc90(uVar2,local_a,param_2,param_3,param_4,param_5);
            }
            else if ((uint)(local_10 + param_3) < 0x21) {
              iVar1 = FUN_100308b0(local_a,param_2,param_3,param_4);
            }
            else {
              iVar1 = FUN_10032fe0();
            }
          }
          if (iVar1 == 0) {
            return 0;
          }
          param_5 = param_5 + uVar2 * 4;
          if (local_18 == 1) {
            return 1;
          }
          local_18 = local_18 - 1;
          if (local_6 != 0) {
            uVar2 = param_1;
          }
        } while( true );
      }
    }
  }
  return 0;
}

