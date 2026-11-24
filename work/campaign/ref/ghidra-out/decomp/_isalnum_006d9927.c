
/* Library Function - Single Match
    _isalnum
   
   Library: Visual Studio 2019 Release */

int __cdecl _isalnum(int _C)

{
  int iVar1;
  
  if (DAT_00769d54 != 0) {
    iVar1 = __isalnum_l(_C,(_locale_t)0x0);
    return iVar1;
  }
  iVar1 = ___acrt_locale_get_ctype_array_value(PTR_DAT_00767218,_C,0x107);
  return iVar1;
}

