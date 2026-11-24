
undefined4 FUN_100185c0(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  bool bVar6;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar4 = &DAT_10043480;
  uVar5 = 0xc;
  piVar3 = param_2;
  do {
    if (*piVar3 != *piVar4) {
      piVar4 = &DAT_10043400;
      uVar5 = 0xc;
      piVar3 = param_2;
      do {
        if (*piVar3 != *piVar4) {
          piVar3 = &DAT_10043430;
          uVar5 = 0xc;
          do {
            if (*param_2 != *piVar3) {
              *param_3 = 0;
              return 0x80004002;
            }
            param_2 = param_2 + 1;
            piVar3 = piVar3 + 1;
            bVar6 = 3 < uVar5;
            uVar5 = uVar5 - 4;
          } while (bVar6);
          puVar1 = (undefined4 *)FUN_1003ff62(8);
          *puVar1 = Direct3D7Port::vftable;
          puVar1[1] = 0;
          iVar2 = FUN_10016760(puVar1,&DAT_10043430,param_3);
          if (iVar2 < 0) {
            FUN_100402ac(puVar1,8);
          }
          return 0;
        }
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
        bVar6 = 3 < uVar5;
        uVar5 = uVar5 - 4;
      } while (bVar6);
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      return 0;
    }
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
    bVar6 = 3 < uVar5;
    uVar5 = uVar5 - 4;
  } while (bVar6);
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}

