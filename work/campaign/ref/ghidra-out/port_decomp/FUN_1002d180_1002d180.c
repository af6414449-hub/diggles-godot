
void FUN_1002d180(uint param_1)

{
  int iVar1;
  float *pfVar2;
  float *in_ECX;
  uint uVar3;
  float *in_EDX;
  int iVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (((in_ECX != (float *)0x0) && (in_EDX != (float *)0x0)) && (uVar3 = 0, param_1 != 0)) {
    if ((7 < param_1) && ((in_EDX + (param_1 - 1) < in_ECX || (in_ECX + (param_1 - 1) < in_EDX)))) {
      pfVar2 = in_EDX + 4;
      do {
        uVar3 = uVar3 + 8;
        *(ulonglong *)in_ECX =
             CONCAT44((float)(int)((ulonglong)*(undefined8 *)(pfVar2 + -4) >> 0x20) * 4.656613e-10,
                      (float)(int)*(undefined8 *)(pfVar2 + -4) * 4.656613e-10);
        *(ulonglong *)(in_ECX + 2) =
             CONCAT44((float)(int)((ulonglong)*(undefined8 *)(pfVar2 + -2) >> 0x20) * 4.656613e-10,
                      (float)(int)*(undefined8 *)(pfVar2 + -2) * 4.656613e-10);
        *(ulonglong *)(in_ECX + 4) =
             CONCAT44((float)(int)((ulonglong)*(undefined8 *)pfVar2 >> 0x20) * 4.656613e-10,
                      (float)(int)*(undefined8 *)pfVar2 * 4.656613e-10);
        *(ulonglong *)(in_ECX + 6) =
             CONCAT44((float)(int)((ulonglong)*(undefined8 *)(pfVar2 + 2) >> 0x20) * 4.656613e-10,
                      (float)(int)*(undefined8 *)(pfVar2 + 2) * 4.656613e-10);
        in_ECX = in_ECX + 8;
        pfVar2 = pfVar2 + 8;
      } while (uVar3 < (param_1 & 0xfffffff8));
      if (param_1 <= uVar3) {
        return;
      }
    }
    if (3 < param_1 - uVar3) {
      iVar1 = uVar3 + 2;
      iVar4 = ((param_1 - uVar3) - 4 >> 2) + 1;
      uVar3 = uVar3 + iVar4 * 4;
      pfVar2 = in_EDX + iVar1;
      do {
        *in_ECX = (float)(int)pfVar2[-2] * 4.656613e-10;
        in_ECX[1] = (float)(int)pfVar2[-1] * 4.656613e-10;
        in_ECX[2] = (float)(int)*pfVar2 * 4.656613e-10;
        in_ECX[3] = (float)(int)pfVar2[1] * 4.656613e-10;
        in_ECX = in_ECX + 4;
        iVar4 = iVar4 + -1;
        pfVar2 = pfVar2 + 4;
      } while (iVar4 != 0);
      if (param_1 <= uVar3) {
        return;
      }
    }
    do {
      pfVar2 = in_EDX + uVar3;
      uVar3 = uVar3 + 1;
      *in_ECX = (float)(int)*pfVar2 * 4.656613e-10;
      in_ECX = in_ECX + 1;
    } while (uVar3 < param_1);
  }
  return;
}

