
/* Library Function - Single Match
    ___ascii_wcsnicmp
   
   Library: Visual Studio 2019 Release */

int ___ascii_wcsnicmp(ushort *param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    do {
      uVar1 = (uint)*param_1;
      if (uVar1 - 0x41 < 0x1a) {
        uVar1 = uVar1 + 0x20;
      }
      uVar2 = (uint)*param_2;
      param_1 = param_1 + 1;
      if (uVar2 - 0x41 < 0x1a) {
        uVar2 = uVar2 + 0x20;
      }
      param_2 = param_2 + 1;
    } while (((uVar1 - uVar2 == 0) && (uVar1 != 0)) && (param_3 = param_3 + -1, param_3 != 0));
    return uVar1 - uVar2;
  }
  return 0;
}

