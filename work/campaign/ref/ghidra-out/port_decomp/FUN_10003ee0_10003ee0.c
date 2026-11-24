
uint FUN_10003ee0(uint param_1)

{
  byte *in_ECX;
  uint uVar1;
  byte *in_EDX;
  bool bVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  uVar1 = param_1 - 4;
  if (3 < param_1) {
    do {
      if (*(int *)in_ECX != *(int *)in_EDX) goto LAB_10003f16;
      in_ECX = in_ECX + 4;
      in_EDX = in_EDX + 4;
      bVar2 = 3 < uVar1;
      uVar1 = uVar1 - 4;
    } while (bVar2);
  }
  if (uVar1 != 0xfffffffc) {
LAB_10003f16:
    bVar2 = *in_ECX < *in_EDX;
    if ((*in_ECX != *in_EDX) ||
       ((uVar1 != 0xfffffffd &&
        ((bVar2 = in_ECX[1] < in_EDX[1], in_ECX[1] != in_EDX[1] ||
         ((uVar1 != 0xfffffffe &&
          ((bVar2 = in_ECX[2] < in_EDX[2], in_ECX[2] != in_EDX[2] ||
           ((uVar1 != 0xffffffff && (bVar2 = in_ECX[3] < in_EDX[3], in_ECX[3] != in_EDX[3]))))))))))
       )) {
      return -(uint)bVar2 | 1;
    }
  }
  return 0;
}

