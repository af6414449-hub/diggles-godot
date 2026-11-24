
/* Library Function - Single Match
    _string_is_alpha
   
   Library: Visual Studio 2019 Release */

undefined4 __cdecl string_is_alpha(int param_1,uint param_2)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = (uint)*(ushort *)(param_1 + uVar4 * 2);
      uVar5 = 0x103;
      puVar2 = ___pctype_func();
      iVar3 = ___acrt_locale_get_ctype_array_value(puVar2,uVar1,uVar5);
      if (iVar3 == 0) {
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_2);
  }
  return 1;
}

