
undefined4 FUN_10028900(uint param_1,int param_2)

{
  int iVar1;
  code *in_ECX;
  bool bVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (param_2 != 0) goto LAB_10028930;
  do {
    if (param_1 == 0) {
      return 1;
    }
    do {
      if ((param_2 == 0) && (param_1 < 0x80000000)) {
        iVar1 = (*in_ECX)();
        if (iVar1 != 0) {
          return 1;
        }
        return 0;
      }
LAB_10028930:
      iVar1 = (*in_ECX)();
      if (iVar1 == 0) {
        return 0;
      }
      bVar2 = 0x7ffffffe < param_1;
      param_1 = param_1 + 0x80000001;
      param_2 = param_2 + -1 + (uint)bVar2;
    } while (param_2 != 0);
  } while( true );
}

