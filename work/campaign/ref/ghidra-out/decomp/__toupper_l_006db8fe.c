
/* Library Function - Single Match
    __toupper_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __toupper_l(int _C,_locale_t _Locale)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_20;
  localeinfo_struct local_1c;
  char local_14;
  uint local_10;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  if (_C == -1) {
    return -1;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_20,(__crt_locale_pointers *)_Locale);
  if ((uint)_C < 0x100) {
    bVar1 = (local_1c.locinfo)->pcumap[_C & 0xff];
    if (local_14 == '\0') {
      return (uint)bVar1;
    }
    *(uint *)(local_20 + 0x350) = *(uint *)(local_20 + 0x350) & 0xfffffffd;
    return (uint)bVar1;
  }
  local_6 = 0;
  if (1 < (int)(local_1c.locinfo)->lc_codepage) {
    local_10 = _C >> 8;
    iVar2 = __isleadbyte_l(local_10 & 0xff,&local_1c);
    if (iVar2 != 0) {
      local_6 = 0;
      uVar4 = 2;
      local_8 = (char)local_10;
      local_7 = (char)_C;
      goto LAB_006db9a3;
    }
  }
  piVar3 = __errno();
  *piVar3 = 0x2a;
  uVar4 = 1;
  local_7 = 0;
  local_8 = (char)_C;
LAB_006db9a3:
  local_c = 0;
  local_a = 0;
  iVar2 = ___acrt_LCMapStringA
                    (&local_1c,(local_1c.locinfo)->locale_name[2],0x200,&local_8,uVar4,&local_c,3,
                     (local_1c.locinfo)->lc_collate_cp,1);
  if (iVar2 != 0) {
    _C = (int)(byte)local_c;
    if (iVar2 != 1) {
      _C = (int)CONCAT11((byte)local_c,local_c._1_1_);
    }
  }
  if (local_14 != '\0') {
    *(uint *)(local_20 + 0x350) = *(uint *)(local_20 + 0x350) & 0xfffffffd;
  }
  return _C;
}

