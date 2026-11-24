
/* Library Function - Single Match
    struct __acrt_stdio_stream_mode __cdecl __acrt_stdio_parse_mode<wchar_t>(wchar_t const * const)
   
   Library: Visual Studio 2019 Release */

wchar_t * __cdecl __acrt_stdio_parse_mode<wchar_t>(wchar_t *param_1)

{
  short sVar1;
  wchar_t wVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  uint in_ECX;
  wchar_t *pwVar8;
  short *in_stack_00000008;
  undefined4 uStack_8;
  
  param_1[0] = L'\0';
  param_1[1] = L'\0';
  param_1[2] = L'\0';
  param_1[3] = L'\0';
  param_1[4] = L'\0';
  param_1[5] = L'\0';
  *(undefined4 *)(param_1 + 2) = DAT_00769d5c;
  sVar1 = *in_stack_00000008;
  while (sVar1 == 0x20) {
    in_stack_00000008 = in_stack_00000008 + 1;
    sVar1 = *in_stack_00000008;
  }
  if (sVar1 == 0x61) {
    param_1[0] = L'ĉ';
    param_1[1] = L'\0';
LAB_006e5549:
    param_1[2] = L'\x02';
    param_1[3] = L'\0';
  }
  else {
    if (sVar1 != 0x72) {
      uStack_8 = in_ECX;
      if (sVar1 != 0x77) goto LAB_006e5735;
      param_1[0] = L'́';
      param_1[1] = L'\0';
      goto LAB_006e5549;
    }
    param_1[2] = L'\x01';
    param_1[3] = L'\0';
  }
  pwVar8 = in_stack_00000008 + 1;
  cVar5 = '\x01';
  uStack_8 = in_ECX & 0xffff;
  bVar4 = false;
  bVar3 = false;
  do {
    wVar2 = *pwVar8;
    if (wVar2 == L'\0') break;
    if ((ushort)wVar2 < 0x54) {
      if (wVar2 == L'S') {
        if (bVar3) goto LAB_006e55b7;
        *(uint *)param_1 = *(uint *)param_1 | 0x20;
LAB_006e55cf:
        bVar3 = true;
        cVar5 = '\x01';
      }
      else if (wVar2 != L' ') {
        if (wVar2 == L'+') {
          cVar5 = __acrt_stdio_parse_mode_plus
                            ((__acrt_stdio_stream_mode *)param_1,(bool *)((int)&uStack_8 + 2));
        }
        else if (wVar2 == L',') {
          bVar4 = true;
LAB_006e55b7:
          cVar5 = '\0';
        }
        else if (wVar2 == L'D') {
          cVar5 = __acrt_stdio_parse_mode_D((__acrt_stdio_stream_mode *)param_1);
        }
        else {
          if (wVar2 != L'N') {
            if (wVar2 == L'R') {
              if (!bVar3) {
                *(uint *)param_1 = *(uint *)param_1 | 0x10;
                goto LAB_006e55cf;
              }
              goto LAB_006e55b7;
            }
            goto LAB_006e5735;
          }
          *(uint *)param_1 = *(uint *)param_1 | 0x80;
          cVar5 = '\x01';
        }
      }
    }
    else if (wVar2 == L'T') {
      cVar5 = __acrt_stdio_parse_mode_T((__acrt_stdio_stream_mode *)param_1);
    }
    else if (wVar2 == L'b') {
      cVar5 = FID_conflict___acrt_stdio_parse_mode_b(param_1);
    }
    else if (wVar2 == L'c') {
      cVar5 = __acrt_stdio_parse_mode_c
                        ((__acrt_stdio_stream_mode *)param_1,(bool *)((int)&uStack_8 + 3));
    }
    else if (wVar2 == L'n') {
      cVar5 = __acrt_stdio_parse_mode_n
                        ((__acrt_stdio_stream_mode *)param_1,(bool *)((int)&uStack_8 + 3));
    }
    else if (wVar2 == L't') {
      cVar5 = FID_conflict___acrt_stdio_parse_mode_b(param_1);
    }
    else {
      if (wVar2 != L'x') goto LAB_006e5735;
      cVar5 = __acrt_stdio_parse_mode_x((__acrt_stdio_stream_mode *)param_1);
    }
    pwVar8 = (wchar_t *)((int)pwVar8 + (-(uint)(cVar5 != '\0') & 2));
  } while (cVar5 != '\0');
  if (bVar4) {
    pwVar8 = pwVar8 + 1;
  }
  for (; *pwVar8 == L' '; pwVar8 = pwVar8 + 1) {
  }
  if (bVar4) {
    iVar6 = _wcsncmp(pwVar8,L"ccs",3);
    if (iVar6 != 0) goto LAB_006e5735;
    pwVar8 = pwVar8 + 3;
    wVar2 = *pwVar8;
    while (wVar2 == L' ') {
      pwVar8 = pwVar8 + 1;
      wVar2 = *pwVar8;
    }
    if (wVar2 != L'=') goto LAB_006e5735;
    do {
      pwVar8 = pwVar8 + 1;
    } while (*pwVar8 == L' ');
    iVar6 = __wcsnicmp(pwVar8,L"UTF-8",5);
    if (iVar6 == 0) {
      *(uint *)param_1 = *(uint *)param_1 | 0x40000;
      iVar6 = 10;
    }
    else {
      iVar6 = __wcsnicmp(pwVar8,L"UTF-16LEUNICODE",8);
      if (iVar6 == 0) {
        *(uint *)param_1 = *(uint *)param_1 | 0x20000;
        iVar6 = 0x10;
      }
      else {
        iVar6 = __wcsnicmp(pwVar8,L"UNICODE",7);
        if (iVar6 != 0) goto LAB_006e5735;
        *(uint *)param_1 = *(uint *)param_1 | 0x10000;
        iVar6 = 0xe;
      }
    }
    pwVar8 = (wchar_t *)((int)pwVar8 + iVar6);
    wVar2 = *pwVar8;
    while (wVar2 == L' ') {
      pwVar8 = pwVar8 + 1;
      wVar2 = *pwVar8;
    }
  }
  else {
    wVar2 = *pwVar8;
  }
  if (wVar2 == L'\0') {
    *(undefined1 *)(param_1 + 4) = 1;
    return param_1;
  }
LAB_006e5735:
  piVar7 = __errno();
  *piVar7 = 0x16;
  FUN_006e510d();
  return param_1;
}

