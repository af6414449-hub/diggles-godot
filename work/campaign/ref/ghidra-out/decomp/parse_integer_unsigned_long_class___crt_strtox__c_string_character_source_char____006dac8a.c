
/* Library Function - Single Match
    unsigned long __cdecl __crt_strtox::parse_integer<unsigned long,class
   __crt_strtox::c_string_character_source<char> >(struct __crt_locale_pointers * const,class
   __crt_strtox::c_string_character_source<char>,int,bool)
   
   Library: Visual Studio 2019 Release */

ulong __cdecl
__crt_strtox::parse_integer<unsigned_long,class___crt_strtox::c_string_character_source<char>_>
          (__crt_locale_pointers *param_1,char *param_2,undefined4 *param_3,uint param_4,
          byte param_5)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int local_2c;
  undefined1 local_28 [8];
  char local_20;
  char *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  char local_8;
  undefined3 uStack_7;
  
  bVar2 = c_string_character_source<char>::validate((c_string_character_source<char> *)&param_2);
  uVar7 = param_4;
  if (bVar2) {
    if ((param_4 == 0) || ((1 < (int)param_4 && ((int)param_4 < 0x25)))) {
      _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_2c,param_1);
      local_10 = 0;
      local_1c = param_2;
      do {
        cVar6 = *param_2;
        param_2 = param_2 + 1;
        _local_8 = CONCAT31(uStack_7,cVar6);
        iVar4 = __ischartype_l(cVar6,8,local_28);
      } while (iVar4 != 0);
      local_c = (uint)param_5;
      if (cVar6 == '-') {
        local_c = local_c | 2;
LAB_006dad29:
        cVar6 = *param_2;
        param_2 = param_2 + 1;
        _local_8 = CONCAT31(uStack_7,cVar6);
      }
      else if (cVar6 == '+') goto LAB_006dad29;
      if ((uVar7 == 0) || (uVar7 == 0x10)) {
        if ((byte)(cVar6 - 0x30U) < 10) {
          iVar4 = cVar6 + -0x30;
        }
        else if ((byte)(cVar6 + 0x9fU) < 0x1a) {
          iVar4 = cVar6 + -0x57;
        }
        else if ((byte)(cVar6 + 0xbfU) < 0x1a) {
          iVar4 = cVar6 + -0x37;
        }
        else {
          iVar4 = -1;
        }
        if (iVar4 == 0) {
          cVar1 = *param_2;
          local_14 = CONCAT31(local_14._1_3_,cVar1);
          if ((cVar1 == 'x') || (cVar1 == 'X')) {
            if (uVar7 == 0) {
              uVar7 = 0x10;
            }
            cVar6 = param_2[1];
            param_2 = param_2 + 2;
            _local_8 = CONCAT31(uStack_7,cVar6);
          }
          else {
            if (uVar7 == 0) {
              uVar7 = 8;
            }
            param_2 = param_2 + 1;
            c_string_character_source<char>::unget
                      ((c_string_character_source<char> *)&param_2,cVar1);
          }
        }
        else if (uVar7 == 0) {
          uVar7 = 10;
        }
      }
      local_14 = (uint)(0xffffffff / (ulonglong)uVar7);
      local_18 = (uint)(0xffffffff % (ulonglong)uVar7);
      while( true ) {
        if ((byte)(cVar6 - 0x30U) < 10) {
          uVar5 = (int)cVar6 - 0x30;
        }
        else if ((byte)(cVar6 + 0x9fU) < 0x1a) {
          uVar5 = (int)cVar6 - 0x57;
        }
        else if ((byte)(cVar6 + 0xbfU) < 0x1a) {
          uVar5 = (int)cVar6 - 0x37;
        }
        else {
          uVar5 = 0xffffffff;
        }
        if ((uVar5 == 0xffffffff) || (uVar7 <= uVar5)) break;
        if ((local_10 < local_14) || ((local_10 == local_14 && (uVar5 <= local_18)))) {
          uVar8 = 8;
          local_10 = local_10 * uVar7 + uVar5;
        }
        else {
          uVar8 = 0xc;
        }
        cVar6 = *param_2;
        param_2 = param_2 + 1;
        _local_8 = CONCAT31(uStack_7,cVar6);
        local_c = local_c | uVar8;
      }
      c_string_character_source<char>::unget
                ((c_string_character_source<char> *)&param_2,(char)_local_8);
      uVar5 = local_c;
      uVar7 = local_10;
      if ((local_c & 8) == 0) {
        uVar7 = 0;
        param_2 = local_1c;
      }
      else {
        bVar2 = is_overflow_condition<unsigned_long>(local_c,local_10);
        if (bVar2) {
          piVar3 = __errno();
          *piVar3 = 0x22;
          if ((uVar5 & 1) == 0) {
            uVar7 = 0xffffffff;
          }
          else if ((uVar5 & 2) == 0) {
            uVar7 = 0x7fffffff;
          }
          else {
            uVar7 = 0x80000000;
          }
        }
        else if ((uVar5 & 2) != 0) {
          uVar7 = -uVar7;
        }
      }
      if (local_20 != '\0') {
        *(uint *)(local_2c + 0x350) = *(uint *)(local_2c + 0x350) & 0xfffffffd;
      }
      goto LAB_006dacc3;
    }
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
  }
  uVar7 = 0;
LAB_006dacc3:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_2;
  }
  return uVar7;
}

