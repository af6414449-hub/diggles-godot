
/* Library Function - Single Match
    ___dcrt_multibyte_check_type
   
   Library: Visual Studio 2019 Release */

byte ___dcrt_multibyte_check_type(undefined4 param_1,int param_2,ushort param_3,byte param_4)

{
  int iVar1;
  undefined4 in_ECX;
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined2 uStack_6;
  
  if (*(int *)(*(int *)(param_2 + 4) + 8) != 0) {
    local_c = 0;
    uStack_6 = (undefined2)((uint)in_ECX >> 0x10);
    _local_8 = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
    iVar1 = ___acrt_GetStringTypeA
                      (param_2,1,&local_8,2,&local_c,*(undefined4 *)(*(int *)(param_2 + 4) + 4),1);
    if ((iVar1 != 0) && (local_c._2_2_ == 0)) {
      return ((ushort)local_c & param_3) == 0 ^ param_4;
    }
  }
  return 0;
}

