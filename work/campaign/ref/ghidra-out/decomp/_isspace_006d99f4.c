
/* Library Function - Single Match
    _isspace
   
   Library: Visual Studio 2019 Release */

int __cdecl _isspace(int _C)

{
  int iVar1;
  
  if (DAT_00769d54 != 0) {
    iVar1 = __isspace_l(_C,(_locale_t)0x0);
    return iVar1;
  }
  iVar1 = ___acrt_locale_get_ctype_array_value(PTR_DAT_00767218,_C,8);
  return iVar1;
}

