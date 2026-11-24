
/* Library Function - Single Match
    unsigned long __cdecl __crt_strtox::parse_integer<unsigned long,class
   __crt_strtox::c_string_character_source<wchar_t> >(struct __crt_locale_pointers * const,class
   __crt_strtox::c_string_character_source<wchar_t>,int,bool)
   
   Library: Visual Studio 2019 Release */

ulong __cdecl
__crt_strtox::parse_integer<unsigned_long,class___crt_strtox::c_string_character_source<wchar_t>_>
          (__crt_locale_pointers *param_1,wchar_t *param_2,undefined4 *param_3,uint param_4,
          byte param_5)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  wchar_t wVar8;
  uint uVar9;
  uint uVar10;
  int local_a4 [3];
  char local_98;
  wchar_t *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  int local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  bVar1 = c_string_character_source<char>::validate((c_string_character_source<char> *)&param_2);
  uVar6 = param_4;
  if (bVar1) {
    if ((param_4 == 0) || ((1 < (int)param_4 && ((int)param_4 < 0x25)))) {
      _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_a4,param_1);
      local_8 = 0;
      local_94 = param_2;
      do {
        wVar8 = *param_2;
        param_2 = param_2 + 1;
        iVar3 = _iswctype(wVar8,8);
      } while (iVar3 != 0);
      uVar7 = (uint)param_5;
      if (wVar8 == L'-') {
        uVar7 = uVar7 | 2;
LAB_006daf4b:
        wVar8 = *param_2;
        param_2 = param_2 + 1;
      }
      else if (wVar8 == L'+') goto LAB_006daf4b;
      uVar9 = (uint)(ushort)wVar8;
      local_90 = 0x3a;
      local_c = 0x660;
      local_10 = 0x66a;
      local_14 = 0x6f0;
      local_18 = 0x6fa;
      local_1c = 0x966;
      local_20 = 0x970;
      local_24 = 0x9e6;
      local_28 = 0x9f0;
      local_2c = 0xa66;
      local_30 = 0xa70;
      local_34 = 0xae6;
      local_38 = 0xaf0;
      local_3c = 0xb66;
      local_40 = 0xb70;
      local_44 = 0xc66;
      local_48 = 0xc70;
      local_4c = 0xce6;
      local_50 = 0xcf0;
      local_54 = 0xd66;
      local_58 = 0xd70;
      local_5c = 0xe50;
      local_60 = 0xe5a;
      local_64 = 0xed0;
      local_68 = 0xeda;
      local_6c = 0xf20;
      local_70 = 0xf2a;
      local_74 = 0x1040;
      local_78 = 0x104a;
      local_7c = 0x17e0;
      local_80 = 0x17ea;
      local_84 = 0x1810;
      local_88 = 0x181a;
      local_8c = 0xff1a;
      if ((uVar6 != 0) && (uVar6 != 0x10)) goto LAB_006db255;
      if ((ushort)wVar8 < 0x30) {
LAB_006db1e0:
        if (((uVar9 < 0x41) || (0x5a < uVar9)) && (0x19 < uVar9 - 0x61)) {
          iVar3 = -1;
        }
        else {
          uVar4 = uVar9;
          if (uVar9 - 0x61 < 0x1a) {
            uVar4 = uVar9 - 0x20;
          }
          iVar3 = uVar4 - 0x37;
        }
      }
      else {
        iVar3 = 0x30;
        if ((ushort)wVar8 < 0x3a) {
LAB_006db07a:
          iVar3 = uVar9 - iVar3;
        }
        else {
          if ((ushort)wVar8 < 0xff10) {
            if (((ushort)wVar8 < 0x660) ||
               ((iVar3 = local_c, 0x669 < (ushort)wVar8 &&
                ((iVar3 = 0x6f0, (ushort)wVar8 < 0x6f0 ||
                 ((0x6f9 < (ushort)wVar8 &&
                  ((iVar3 = 0x966, (ushort)wVar8 < 0x966 ||
                   ((0x96f < (ushort)wVar8 &&
                    ((iVar3 = 0x9e6, (ushort)wVar8 < 0x9e6 ||
                     ((0x9ef < (ushort)wVar8 &&
                      ((iVar3 = 0xa66, (ushort)wVar8 < 0xa66 ||
                       ((0xa6f < (ushort)wVar8 &&
                        ((iVar3 = 0xae6, (ushort)wVar8 < 0xae6 ||
                         ((0xaef < (ushort)wVar8 &&
                          ((iVar3 = 0xb66, (ushort)wVar8 < 0xb66 ||
                           ((0xb6f < (ushort)wVar8 &&
                            ((iVar3 = 0xc66, (ushort)wVar8 < 0xc66 ||
                             ((0xc6f < (ushort)wVar8 &&
                              ((iVar3 = 0xce6, (ushort)wVar8 < 0xce6 ||
                               ((0xcef < (ushort)wVar8 &&
                                ((iVar3 = 0xd66, (ushort)wVar8 < 0xd66 ||
                                 ((0xd6f < (ushort)wVar8 &&
                                  ((iVar3 = 0xe50, (ushort)wVar8 < 0xe50 ||
                                   ((0xe59 < (ushort)wVar8 &&
                                    ((iVar3 = 0xed0, (ushort)wVar8 < 0xed0 ||
                                     ((0xed9 < (ushort)wVar8 &&
                                      ((iVar3 = 0xf20, (ushort)wVar8 < 0xf20 ||
                                       ((0xf29 < (ushort)wVar8 &&
                                        ((iVar3 = 0x1040, (ushort)wVar8 < 0x1040 ||
                                         ((0x1049 < (ushort)wVar8 &&
                                          ((iVar3 = 0x17e0, (ushort)wVar8 < 0x17e0 ||
                                           ((0x17e9 < (ushort)wVar8 &&
                                            ((iVar3 = 0x1810, (ushort)wVar8 < 0x1810 ||
                                             (0x1819 < (ushort)wVar8))))))))))))))))))))))))))))))))
                             )))))))))))))))))))))))))))))) goto LAB_006db1e0;
            goto LAB_006db07a;
          }
          if ((ushort)wVar8 < 0xff1a) {
            iVar3 = uVar9 - 0xff10;
          }
          else {
            iVar3 = -1;
          }
        }
        if (iVar3 == -1) goto LAB_006db1e0;
      }
      if (iVar3 == 0) {
        wVar8 = *param_2;
        if ((wVar8 == L'x') || (wVar8 == L'X')) {
          if (uVar6 == 0) {
            uVar6 = 0x10;
            param_4 = 0x10;
          }
          uVar9 = (uint)(ushort)param_2[1];
          param_2 = param_2 + 2;
        }
        else {
          if (uVar6 == 0) {
            uVar6 = 8;
            param_4 = 8;
          }
          param_2 = param_2 + 1;
          c_string_character_source<wchar_t>::unget
                    ((c_string_character_source<wchar_t> *)&param_2,wVar8);
        }
      }
      else if (uVar6 == 0) {
        uVar6 = 10;
        param_4 = 10;
      }
LAB_006db255:
      uVar4 = (uint)(0xffffffff / (ulonglong)uVar6);
      do {
        wVar8 = (wchar_t)uVar9;
        if ((ushort)wVar8 < 0x30) {
LAB_006db3d7:
          if (((uVar9 < 0x41) || (0x5a < uVar9)) && (0x19 < uVar9 - 0x61)) {
            uVar5 = 0xffffffff;
          }
          else {
            if (uVar9 - 0x61 < 0x1a) {
              uVar9 = uVar9 - 0x20;
            }
            uVar5 = uVar9 - 0x37;
          }
        }
        else {
          iVar3 = 0x30;
          if ((ushort)wVar8 < 0x3a) {
LAB_006db272:
            uVar5 = uVar9 - iVar3;
          }
          else {
            iVar3 = 0xff10;
            if ((ushort)wVar8 < 0xff10) {
              if (((ushort)wVar8 < (ushort)(wchar_t)local_c) ||
                 ((iVar3 = local_c, (ushort)(wchar_t)local_10 <= (ushort)wVar8 &&
                  (((ushort)wVar8 < (ushort)(wchar_t)local_14 ||
                   ((iVar3 = local_14, (ushort)(wchar_t)local_18 <= (ushort)wVar8 &&
                    (((ushort)wVar8 < (ushort)(wchar_t)local_1c ||
                     ((iVar3 = local_1c, (ushort)(wchar_t)local_20 <= (ushort)wVar8 &&
                      (((ushort)wVar8 < (ushort)(wchar_t)local_24 ||
                       ((iVar3 = local_24, (ushort)(wchar_t)local_28 <= (ushort)wVar8 &&
                        (((ushort)wVar8 < (ushort)(wchar_t)local_2c ||
                         ((iVar3 = local_2c, (ushort)(wchar_t)local_30 <= (ushort)wVar8 &&
                          (((ushort)wVar8 < (ushort)(wchar_t)local_34 ||
                           ((iVar3 = local_34, (ushort)(wchar_t)local_38 <= (ushort)wVar8 &&
                            (((ushort)wVar8 < (ushort)(wchar_t)local_3c ||
                             ((iVar3 = local_3c, (ushort)(wchar_t)local_40 <= (ushort)wVar8 &&
                              (((ushort)wVar8 < (ushort)(wchar_t)local_44 ||
                               ((iVar3 = local_44, (ushort)(wchar_t)local_48 <= (ushort)wVar8 &&
                                (((ushort)wVar8 < (ushort)(wchar_t)local_4c ||
                                 ((iVar3 = local_4c, (ushort)(wchar_t)local_50 <= (ushort)wVar8 &&
                                  (((ushort)wVar8 < (ushort)(wchar_t)local_54 ||
                                   ((iVar3 = local_54, (ushort)(wchar_t)local_58 <= (ushort)wVar8 &&
                                    (((ushort)wVar8 < (ushort)(wchar_t)local_5c ||
                                     ((iVar3 = local_5c, (ushort)(wchar_t)local_60 <= (ushort)wVar8
                                      && (((ushort)wVar8 < (ushort)(wchar_t)local_64 ||
                                          ((iVar3 = local_64,
                                           (ushort)(wchar_t)local_68 <= (ushort)wVar8 &&
                                           (((ushort)wVar8 < (ushort)(wchar_t)local_6c ||
                                            ((iVar3 = local_6c,
                                             (ushort)(wchar_t)local_70 <= (ushort)wVar8 &&
                                             (((ushort)wVar8 < (ushort)(wchar_t)local_74 ||
                                              ((iVar3 = local_74,
                                               (ushort)(wchar_t)local_78 <= (ushort)wVar8 &&
                                               (((ushort)wVar8 < (ushort)(wchar_t)local_7c ||
                                                ((iVar3 = local_7c,
                                                 (ushort)(wchar_t)local_80 <= (ushort)wVar8 &&
                                                 (((ushort)wVar8 < (ushort)(wchar_t)local_84 ||
                                                  (iVar3 = local_84,
                                                  (ushort)(wchar_t)local_88 <= (ushort)wVar8))))))))
                                              ))))))))))))))))))))))))))))))))))))))))))))))))))))))
              goto LAB_006db3d7;
              goto LAB_006db272;
            }
            if ((ushort)wVar8 < (ushort)(wchar_t)local_8c) goto LAB_006db272;
            uVar5 = 0xffffffff;
          }
          if (uVar5 == 0xffffffff) goto LAB_006db3d7;
        }
        if ((uVar5 == 0xffffffff) || (param_4 <= uVar5)) goto LAB_006db43b;
        if ((local_8 < uVar4) ||
           ((local_8 == uVar4 && (uVar5 <= (uint)(0xffffffff % (ulonglong)uVar6))))) {
          uVar10 = 8;
          local_8 = local_8 * param_4 + uVar5;
        }
        else {
          uVar10 = 0xc;
        }
        uVar9 = (uint)(ushort)*param_2;
        param_2 = param_2 + 1;
        uVar7 = uVar7 | uVar10;
      } while( true );
    }
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  uVar6 = 0;
LAB_006daeeb:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_2;
  }
  return uVar6;
LAB_006db43b:
  c_string_character_source<wchar_t>::unget((c_string_character_source<wchar_t> *)&param_2,wVar8);
  uVar6 = local_8;
  if ((uVar7 & 8) == 0) {
    uVar6 = 0;
    param_2 = local_94;
  }
  else {
    bVar1 = is_overflow_condition<unsigned_long>(uVar7,local_8);
    if (bVar1) {
      piVar2 = __errno();
      *piVar2 = 0x22;
      if ((uVar7 & 1) == 0) {
        uVar6 = 0xffffffff;
      }
      else if ((uVar7 & 2) == 0) {
        uVar6 = 0x7fffffff;
      }
      else {
        uVar6 = 0x80000000;
      }
    }
    else if ((uVar7 & 2) != 0) {
      uVar6 = -uVar6;
    }
  }
  if (local_98 != '\0') {
    *(uint *)(local_a4[0] + 0x350) = *(uint *)(local_a4[0] + 0x350) & 0xfffffffd;
  }
  goto LAB_006daeeb;
}

