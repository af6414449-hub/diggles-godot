
undefined4 FUN_10009340(void)

{
  uint in_ECX;
  undefined1 local_10 [12];
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if (0x202 < in_ECX) {
    if (in_ECX == 0x204) {
switchD_10009372_caseD_1c4:
      return 0x20;
    }
    if (in_ECX == 0x2c2) {
      return 0x24;
    }
    if (in_ECX == 0x2c4) {
      return 0x28;
    }
switchD_10009372_caseD_103:
    FUN_100092e0("unknown vertex format");
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_10,(ThrowInfo *)&DAT_1004a2f4);
  }
  if (in_ECX != 0x202) {
    switch(in_ECX) {
    case 0x102:
      return 0x14;
    default:
      goto switchD_10009372_caseD_103;
    case 0x104:
      return 0x18;
    case 0x1c2:
      break;
    case 0x1c4:
      goto switchD_10009372_caseD_1c4;
    }
  }
  return 0x1c;
}

