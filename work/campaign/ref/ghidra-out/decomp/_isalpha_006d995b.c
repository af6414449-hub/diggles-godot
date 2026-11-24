
/* Library Function - Single Match
    _isalpha
   
   Library: Visual Studio 2019 Release */

int __cdecl _isalpha(int _C)

{
  int iVar1;
  
  if (DAT_00769d54 != 0) {
    iVar1 = __isalpha_l(_C,(_locale_t)0x0);
    return iVar1;
  }
  iVar1 = ___acrt_locale_get_ctype_array_value(PTR_DAT_00767218,_C,0x103);
  return iVar1;
}

