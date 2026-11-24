
/* Library Function - Single Match
    __isctype_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __isctype_l(int _C,int _Type,_locale_t _Locale)

{
  undefined4 uVar1;
  int iVar2;
  int local_24;
  int *local_20 [2];
  char local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined4 local_10;
  undefined2 local_c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_24,(__crt_locale_pointers *)_Locale);
  if ((_C < -1) || (0xff < _C)) {
    if (*(short *)(*local_20[0] + (_C >> 8 & 0xffU) * 2) < 0) {
      local_12 = 0;
      uVar1 = 2;
      local_14 = (char)((uint)_C >> 8);
      local_13 = (char)_C;
    }
    else {
      local_13 = 0;
      uVar1 = 1;
      local_14 = (char)_C;
    }
    local_10 = 0;
    local_c = 0;
    iVar2 = ___acrt_GetStringTypeA(local_20,1,&local_14,uVar1,&local_10,local_20[0][2],1);
    if (iVar2 == 0) {
      if (local_18 != '\0') {
        *(uint *)(local_24 + 0x350) = *(uint *)(local_24 + 0x350) & 0xfffffffd;
      }
      goto LAB_006e8a32;
    }
  }
  if (local_18 != '\0') {
    *(uint *)(local_24 + 0x350) = *(uint *)(local_24 + 0x350) & 0xfffffffd;
  }
LAB_006e8a32:
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

