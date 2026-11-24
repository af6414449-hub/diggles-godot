
/* Library Function - Single Match
    struct __acrt_stdio_stream_mode __cdecl __acrt_stdio_parse_mode<char>(char const * const)
   
   Library: Visual Studio 2019 Release */

char * __cdecl __acrt_stdio_parse_mode<char>(char *param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint3 in_ECX;
  char *pcVar8;
  char *in_stack_00000008;
  undefined4 uStack_8;
  
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  *(undefined4 *)(param_1 + 4) = DAT_00769d5c;
  for (; cVar4 = *in_stack_00000008, cVar4 == ' '; in_stack_00000008 = in_stack_00000008 + 1) {
  }
  if (cVar4 == 'a') {
    param_1[0] = '\t';
    param_1[1] = '\x01';
    param_1[2] = '\0';
    param_1[3] = '\0';
LAB_006e5315:
    param_1[4] = '\x02';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  else {
    if (cVar4 != 'r') {
      if (cVar4 != 'w') {
        piVar5 = __errno();
        *piVar5 = 0x16;
        FUN_006e510d();
        return param_1;
      }
      param_1[0] = '\x01';
      param_1[1] = '\x03';
      param_1[2] = '\0';
      param_1[3] = '\0';
      goto LAB_006e5315;
    }
    param_1[4] = '\x01';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  pcVar8 = in_stack_00000008 + 1;
  uStack_8 = (uint)(in_ECX & 0xffff);
  bVar3 = false;
  bVar2 = false;
  cVar4 = '\x01';
  do {
    cVar1 = *pcVar8;
    if (cVar1 == '\0') break;
    if (cVar1 < 'T') {
      if (cVar1 == 'S') {
        if (bVar2) goto LAB_006e5386;
        *(uint *)param_1 = *(uint *)param_1 | 0x20;
LAB_006e539e:
        bVar2 = true;
        cVar4 = '\x01';
      }
      else if (cVar1 != ' ') {
        if (cVar1 == '+') {
          cVar4 = __acrt_stdio_parse_mode_plus
                            ((__acrt_stdio_stream_mode *)param_1,(bool *)((int)&uStack_8 + 2));
        }
        else if (cVar1 == ',') {
          bVar3 = true;
LAB_006e5386:
          cVar4 = '\0';
        }
        else if (cVar1 == 'D') {
          cVar4 = __acrt_stdio_parse_mode_D((__acrt_stdio_stream_mode *)param_1);
        }
        else {
          if (cVar1 != 'N') {
            if (cVar1 == 'R') {
              if (!bVar2) {
                *(uint *)param_1 = *(uint *)param_1 | 0x10;
                goto LAB_006e539e;
              }
              goto LAB_006e5386;
            }
            goto LAB_006e54ca;
          }
          *(uint *)param_1 = *(uint *)param_1 | 0x80;
          cVar4 = '\x01';
        }
      }
    }
    else if (cVar1 == 'T') {
      cVar4 = __acrt_stdio_parse_mode_T((__acrt_stdio_stream_mode *)param_1);
    }
    else if (cVar1 == 'b') {
      cVar4 = FID_conflict___acrt_stdio_parse_mode_b(param_1);
    }
    else if (cVar1 == 'c') {
      cVar4 = __acrt_stdio_parse_mode_c
                        ((__acrt_stdio_stream_mode *)param_1,(bool *)((int)&uStack_8 + 3));
    }
    else if (cVar1 == 'n') {
      cVar4 = __acrt_stdio_parse_mode_n
                        ((__acrt_stdio_stream_mode *)param_1,(bool *)((int)&uStack_8 + 3));
    }
    else if (cVar1 == 't') {
      cVar4 = FID_conflict___acrt_stdio_parse_mode_b(param_1);
    }
    else {
      if (cVar1 != 'x') goto LAB_006e54ca;
      cVar4 = __acrt_stdio_parse_mode_x((__acrt_stdio_stream_mode *)param_1);
    }
    pcVar8 = pcVar8 + (cVar4 != '\0');
  } while (cVar4 != '\0');
  if (!bVar3) goto LAB_006e5415;
  do {
    pcVar8 = pcVar8 + 1;
LAB_006e5415:
  } while (*pcVar8 == ' ');
  if (bVar3) {
    iVar6 = _strncmp(pcVar8,"ccs",3);
    if (iVar6 != 0) goto LAB_006e54ca;
    for (pcVar8 = pcVar8 + 3; *pcVar8 == ' '; pcVar8 = pcVar8 + 1) {
    }
    if (*pcVar8 != '=') goto LAB_006e54ca;
    do {
      pcVar8 = pcVar8 + 1;
    } while (*pcVar8 == ' ');
    iVar6 = 5;
    iVar7 = __strnicmp(pcVar8,"UTF-8",5);
    if (iVar7 == 0) {
      *(uint *)param_1 = *(uint *)param_1 | 0x40000;
    }
    else {
      iVar6 = 8;
      iVar7 = __strnicmp(pcVar8,"UTF-16LEUNICODE",8);
      if (iVar7 == 0) {
        *(uint *)param_1 = *(uint *)param_1 | 0x20000;
      }
      else {
        iVar6 = 7;
        iVar7 = __strnicmp(pcVar8,"UNICODE",7);
        if (iVar7 != 0) goto LAB_006e54ca;
        *(uint *)param_1 = *(uint *)param_1 | 0x10000;
      }
    }
    for (pcVar8 = pcVar8 + iVar6; cVar4 = *pcVar8, cVar4 == ' '; pcVar8 = pcVar8 + 1) {
    }
  }
  else {
    cVar4 = *pcVar8;
  }
  if (cVar4 == '\0') {
    param_1[8] = '\x01';
    return param_1;
  }
LAB_006e54ca:
  piVar5 = __errno();
  *piVar5 = 0x16;
  FUN_006e510d();
  return param_1;
}

