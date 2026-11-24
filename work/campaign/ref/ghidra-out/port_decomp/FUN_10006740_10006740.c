
void FUN_10006740(void)

{
  int *piVar1;
  int *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  OutputDebugStringA("DX Device was lost! \n");
  if ((undefined4 *)in_ECX[0x21] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x21])();
  }
  piVar1 = (int *)in_ECX[8];
  if (piVar1 != (int *)0x0) {
    in_ECX[8] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x13];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x13] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[7];
  if (piVar1 != (int *)0x0) {
    in_ECX[7] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x10];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x10] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x11];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x11] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[5];
  if (piVar1 != (int *)0x0) {
    in_ECX[5] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0xf];
  if (piVar1 != (int *)0x0) {
    in_ECX[0xf] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[6];
  if (piVar1 != (int *)0x0) {
    in_ECX[6] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[0x12];
  if (piVar1 != (int *)0x0) {
    in_ECX[0x12] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[3];
  if (piVar1 != (int *)0x0) {
    in_ECX[3] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    in_ECX[2] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[4];
  if (piVar1 != (int *)0x0) {
    in_ECX[4] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[1];
  if (piVar1 != (int *)0x0) {
    in_ECX[1] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    *in_ECX = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_10005840();
  FUN_10005e40();
  if ((int *)in_ECX[0x21] != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x10006897. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)in_ECX[0x21] + 4))();
    return;
  }
  return;
}

