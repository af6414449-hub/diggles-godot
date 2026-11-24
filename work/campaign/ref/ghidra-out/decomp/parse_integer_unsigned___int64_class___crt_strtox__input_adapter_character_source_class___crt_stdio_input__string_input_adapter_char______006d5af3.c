
/* WARNING: Removing unreachable block (ram,0x006d5cb5) */
/* Library Function - Single Match
    unsigned __int64 __cdecl __crt_strtox::parse_integer<unsigned __int64,class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::string_input_adapter<char>
   > >(struct __crt_locale_pointers * const,class __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::string_input_adapter<char> >,int,bool)
   
   Library: Visual Studio 2019 Release */

__uint64 __cdecl
__crt_strtox::
parse_integer<unsigned___int64,class___crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>_>
          (__crt_locale_pointers *param_1)

{
  ulonglong uVar1;
  char cVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  uint extraout_ECX;
  char cVar6;
  undefined4 unaff_EBX;
  int iVar7;
  undefined3 uVar8;
  int iVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  int in_stack_00000018;
  int in_stack_0000001c;
  undefined1 *in_stack_00000020;
  uint in_stack_00000028;
  byte in_stack_0000002c;
  undefined4 uVar13;
  int local_4c;
  undefined1 local_48 [8];
  char local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  char local_c;
  undefined3 uStack_b;
  uint local_8;
  
  cVar2 = validate();
  uVar10 = in_stack_00000028;
  if (cVar2 != '\0') {
    if ((in_stack_00000028 == 0) ||
       ((1 < (int)in_stack_00000028 && ((int)in_stack_00000028 < 0x25)))) {
      uVar13 = unaff_EBX;
      _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_4c,param_1);
      local_14 = 0;
      iVar9 = 0;
      local_3c = in_stack_00000018;
      local_38 = in_stack_0000001c;
      cVar2 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::
              get((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                   *)&stack0x00000008);
      iVar7 = CONCAT31((int3)((uint)unaff_EBX >> 8),cVar2);
      while( true ) {
        cVar6 = (char)iVar7;
        _local_c = CONCAT31(uStack_b,cVar6);
        iVar5 = __ischartype_l(cVar2,8,local_48);
        uVar8 = (undefined3)((uint)iVar7 >> 8);
        if (iVar5 == 0) break;
        cVar2 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                ::get((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                       *)&stack0x00000008);
        iVar7 = CONCAT31(uVar8,cVar2);
      }
      local_8 = (uint)in_stack_0000002c;
      if (cVar6 == '-') {
        local_8 = local_8 | 2;
LAB_006d5ba6:
        cVar2 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                ::get((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                       *)&stack0x00000008);
        iVar7 = CONCAT31(uVar8,cVar2);
        _local_c = CONCAT31(uStack_b,cVar2);
      }
      else if (cVar6 == '+') goto LAB_006d5ba6;
      local_18 = -1;
      if ((uVar10 == 0) || (uVar10 == 0x10)) {
        cVar2 = (char)iVar7;
        if ((byte)(cVar2 - 0x30U) < 10) {
          iVar5 = cVar2 + -0x30;
        }
        else if ((byte)(cVar2 + 0x9fU) < 0x1a) {
          iVar5 = cVar2 + -0x57;
        }
        else if ((byte)(cVar2 + 0xbfU) < 0x1a) {
          iVar5 = cVar2 + -0x37;
        }
        else {
          iVar5 = -1;
        }
        if (iVar5 == 0) {
          cVar2 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                  ::get((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                         *)&stack0x00000008);
          local_24 = CONCAT31(local_24._1_3_,cVar2);
          if ((cVar2 == 'x') || (cVar2 == 'X')) {
            if (uVar10 == 0) {
              uVar10 = 0x10;
            }
            cVar2 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                    ::get((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                           *)&stack0x00000008);
            _local_c = CONCAT31(uStack_b,cVar2);
          }
          else {
            if (uVar10 == 0) {
              uVar10 = 8;
            }
            input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::
            unget((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                   *)&stack0x00000008,cVar2);
          }
        }
        else if (uVar10 == 0) {
          uVar10 = 10;
        }
      }
      local_30 = (int)uVar10 >> 0x1f;
      local_34 = uVar10;
      uVar11 = __aulldvrm(0xffffffff,0xffffffff,uVar10,local_30);
      cVar2 = local_c;
      local_2c = extraout_ECX;
      local_28 = iVar7;
      while( true ) {
        uVar1 = CONCAT44(iVar9,local_14);
        local_20 = (undefined4)(uVar11 >> 0x20);
        local_1c = (undefined4)uVar11;
        if ((byte)(cVar2 - 0x30U) < 10) {
          local_10 = (int)cVar2 - 0x30;
        }
        else if ((byte)(cVar2 + 0x9fU) < 0x1a) {
          local_10 = (int)cVar2 - 0x57;
        }
        else if ((byte)(cVar2 + 0xbfU) < 0x1a) {
          local_10 = (int)cVar2 - 0x37;
        }
        else {
          local_10 = 0xffffffff;
        }
        if ((local_10 == 0xffffffff) || (uVar10 <= local_10)) break;
        if ((uVar1 < uVar11) ||
           ((uVar11 == uVar1 && ((local_24 = 0, local_28 != 0 || (local_10 <= local_2c)))))) {
          local_24 = 0;
          local_8 = local_8 | 8;
          lVar12 = __allmul(local_34,local_30,local_14,iVar9);
          uVar11 = CONCAT44(local_20,local_1c);
          uVar1 = lVar12 + CONCAT44(local_24,local_10);
        }
        else {
          local_8 = local_8 | 0xc;
        }
        iVar9 = (int)(uVar1 >> 0x20);
        local_14 = (int)uVar1;
        local_20 = (undefined4)(uVar11 >> 0x20);
        local_1c = (undefined4)uVar11;
        cVar2 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                ::get((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                       *)&stack0x00000008);
        uVar11 = CONCAT44(local_20,local_1c);
        _local_c = CONCAT31(uStack_b,cVar2);
      }
      input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::unget
                ((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                  *)&stack0x00000008,(char)_local_c);
      iVar7 = local_14;
      if ((local_8 & 8) == 0) {
        restore_state(local_3c,local_38);
        local_18 = 0;
        iVar9 = 0;
      }
      else {
        bVar3 = is_overflow_condition<unsigned___int64>(local_8,CONCAT44(uVar13,iVar9));
        if (bVar3) {
          piVar4 = __errno();
          *piVar4 = 0x22;
          if ((local_8 & 1) == 0) {
            iVar9 = -1;
            local_18 = -1;
          }
          else if ((local_8 & 2) == 0) {
            iVar9 = 0x7fffffff;
          }
          else {
            local_18 = 0;
            iVar9 = -0x80000000;
          }
        }
        else {
          local_18 = iVar7;
          if ((local_8 & 2) != 0) {
            local_18 = -iVar7;
            iVar9 = -(iVar9 + (uint)(iVar7 != 0));
          }
        }
      }
      if (local_40 != '\0') {
        *(uint *)(local_4c + 0x350) = *(uint *)(local_4c + 0x350) & 0xfffffffd;
      }
      goto LAB_006d5d98;
    }
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_006e510d();
  }
  local_18 = 0;
  iVar9 = 0;
LAB_006d5d98:
  if ((in_stack_00000020 != (undefined1 *)0x0) && (in_stack_00000018 == 0 && in_stack_0000001c == 0)
     ) {
    *in_stack_00000020 = 0;
  }
  return CONCAT44(iVar9,local_18);
}

