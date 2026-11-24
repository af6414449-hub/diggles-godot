
void FUN_1002bbc0(uint param_1,int param_2)

{
  int iVar1;
  double *pdVar2;
  int iVar3;
  float *in_ECX;
  uint uVar4;
  float *in_EDX;
  float *pfVar5;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (param_2 == 4) {
    uVar4 = 0;
    if (3 < param_1) {
      iVar1 = (param_1 - 4 >> 2) + 1;
      uVar4 = iVar1 * 4;
      pfVar5 = in_EDX + 2;
      do {
        *in_ECX = pfVar5[-2];
        in_ECX[1] = pfVar5[-1];
        in_ECX[2] = *pfVar5;
        in_ECX[3] = pfVar5[1];
        in_ECX = in_ECX + 4;
        iVar1 = iVar1 + -1;
        pfVar5 = pfVar5 + 4;
      } while (iVar1 != 0);
    }
    if (uVar4 < param_1) {
      do {
        pfVar5 = in_EDX + uVar4;
        uVar4 = uVar4 + 1;
        *in_ECX = *pfVar5;
        in_ECX = in_ECX + 1;
      } while (uVar4 < param_1);
      return;
    }
  }
  else if (param_2 == 8) {
    if (((in_ECX != (float *)0x0) && (in_EDX != (float *)0x0)) && (uVar4 = 0, param_1 != 0)) {
      if ((7 < param_1) &&
         ((in_EDX + (param_1 - 1) * 2 < in_ECX || (in_ECX + (param_1 - 1) < in_EDX)))) {
        pdVar2 = (double *)(in_EDX + 8);
        do {
          uVar4 = uVar4 + 8;
          *(ulonglong *)in_ECX = CONCAT44((float)pdVar2[-3],(float)pdVar2[-4]);
          *(ulonglong *)(in_ECX + 2) = CONCAT44((float)pdVar2[-1],(float)pdVar2[-2]);
          *(ulonglong *)(in_ECX + 4) = CONCAT44((float)pdVar2[1],(float)*pdVar2);
          *(ulonglong *)(in_ECX + 6) = CONCAT44((float)pdVar2[3],(float)pdVar2[2]);
          in_ECX = in_ECX + 8;
          pdVar2 = pdVar2 + 8;
        } while (uVar4 < (param_1 & 0xfffffff8));
        if (param_1 <= uVar4) {
          return;
        }
      }
      if (3 < param_1 - uVar4) {
        iVar1 = uVar4 * 2;
        iVar3 = ((param_1 - uVar4) - 4 >> 2) + 1;
        uVar4 = uVar4 + iVar3 * 4;
        pdVar2 = (double *)(in_EDX + iVar1 + 4);
        do {
          *in_ECX = (float)pdVar2[-2];
          in_ECX[1] = (float)pdVar2[-1];
          in_ECX[2] = (float)*pdVar2;
          in_ECX[3] = (float)pdVar2[1];
          in_ECX = in_ECX + 4;
          iVar3 = iVar3 + -1;
          pdVar2 = pdVar2 + 4;
        } while (iVar3 != 0);
        if (param_1 <= uVar4) {
          return;
        }
      }
      do {
        iVar1 = uVar4 * 2;
        uVar4 = uVar4 + 1;
        *in_ECX = (float)*(double *)(in_EDX + iVar1);
        in_ECX = in_ECX + 1;
      } while (uVar4 < param_1);
      return;
    }
  }
  else {
    memset(in_ECX,0,param_1 * 4);
  }
  return;
}

