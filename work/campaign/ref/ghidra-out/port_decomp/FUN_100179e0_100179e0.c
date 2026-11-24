
undefined4 FUN_100179e0(int *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  bool bVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar2 = &DAT_10043480;
  uVar3 = 0xc;
  piVar1 = param_2;
  do {
    if (*piVar1 != *piVar2) {
      piVar2 = &DAT_10043450;
      uVar3 = 0xc;
      piVar1 = param_2;
      do {
        if (*piVar1 != *piVar2) {
          piVar1 = &DAT_100437f0;
          uVar3 = 0xc;
          do {
            if (*param_2 != *piVar1) {
              *param_3 = 0;
              return 0x80004002;
            }
            param_2 = param_2 + 1;
            piVar1 = piVar1 + 1;
            bVar4 = 3 < uVar3;
            uVar3 = uVar3 - 4;
          } while (bVar4);
          *param_3 = -(uint)(param_1 != (int *)0x0) & (uint)(param_1 + 1);
          (**(code **)(*param_1 + 4))(param_1);
          return 0;
        }
        piVar1 = piVar1 + 1;
        piVar2 = piVar2 + 1;
        bVar4 = 3 < uVar3;
        uVar3 = uVar3 - 4;
      } while (bVar4);
      *param_3 = (uint)param_1;
      (**(code **)(*param_1 + 4))(param_1);
      return 0;
    }
    piVar1 = piVar1 + 1;
    piVar2 = piVar2 + 1;
    bVar4 = 3 < uVar3;
    uVar3 = uVar3 - 4;
  } while (bVar4);
  *param_3 = (uint)param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}

