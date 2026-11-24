
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    bool __cdecl store_winword(struct __crt_locale_pointers * const,int,struct tm const *
   const,wchar_t * * const,unsigned int * const,struct __crt_lc_time_data const * const)
   
   Library: Visual Studio 2019 Release */

bool __cdecl
store_winword(__crt_locale_pointers *param_1,int param_2,tm *param_3,wchar_t **param_4,uint *param_5
             ,__crt_lc_time_data *param_6)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  wchar_t wVar9;
  wchar_t *pwVar10;
  wchar_t *pwVar11;
  undefined4 uVar12;
  undefined4 local_24;
  wchar_t *local_1c;
  short local_18;
  short local_16;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_2 == 0) {
    pwVar11 = *(wchar_t **)(param_6 + 0x154);
  }
  else if (param_2 == 1) {
    pwVar11 = *(wchar_t **)(param_6 + 0x158);
  }
  else {
    pwVar11 = *(wchar_t **)(param_6 + 0x15c);
  }
  if (*(int *)(param_6 + 0xac) != 1) {
    local_18 = (short)param_3->tm_year + 0x76c;
    local_16 = (short)param_3->tm_mon + 1;
    local_12 = (undefined2)param_3->tm_mday;
    local_10 = (undefined2)param_3->tm_hour;
    local_e = (undefined2)param_3->tm_min;
    local_c = (undefined2)param_3->tm_sec;
    local_a = 0;
    if (param_2 == 2) {
      iVar3 = ___acrt_GetTimeFormatEx_24(*(undefined4 *)(param_6 + 0x160),0,&local_18,pwVar11,0,0);
    }
    else {
      iVar3 = ___acrt_GetDateFormatEx_28(*(undefined4 *)(param_6 + 0x160),0,&local_18,pwVar11,0,0,0)
      ;
    }
    if (iVar3 != 0) {
      uVar4 = iVar3 * 2 + 8;
      uVar4 = -(uint)((uint)(iVar3 * 2) < uVar4) & uVar4;
      if (uVar4 == 0) {
        pwVar10 = (wchar_t *)0x0;
LAB_006eac57:
        if (pwVar10 != (wchar_t *)0x0) {
          if (param_2 == 2) {
            iVar3 = ___acrt_GetTimeFormatEx_24
                              (*(undefined4 *)(param_6 + 0x160),0,&local_18,pwVar11,pwVar10,iVar3);
          }
          else {
            iVar3 = ___acrt_GetDateFormatEx_28
                              (*(undefined4 *)(param_6 + 0x160),0,&local_18,pwVar11,pwVar10,iVar3,0)
            ;
          }
          iVar3 = iVar3 + -1;
          if (0 < iVar3) {
            uVar4 = *param_5;
            pwVar11 = pwVar10;
            do {
              if (uVar4 == 0) break;
              wVar9 = *pwVar11;
              pwVar11 = pwVar11 + 1;
              **param_4 = wVar9;
              *param_4 = *param_4 + 1;
              *param_5 = *param_5 - 1;
              iVar3 = iVar3 + -1;
              uVar4 = *param_5;
            } while (0 < iVar3);
          }
          __freea_crt(pwVar10);
          goto LAB_006eacc4;
        }
      }
      else if (uVar4 < 0x401) {
        puVar5 = (undefined4 *)&stack0xffffffc0;
        if (&stack0x00000000 != &DAT_00000040) {
LAB_006eac34:
          pwVar10 = (wchar_t *)(puVar5 + 2);
          goto LAB_006eac57;
        }
      }
      else {
        puVar5 = (undefined4 *)__malloc_base(uVar4);
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = 0xdddd;
          goto LAB_006eac34;
        }
      }
      __freea_crt(0);
    }
  }
LAB_006eaf59:
  do {
    wVar9 = *pwVar11;
    if ((wVar9 == L'\0') || (uVar4 = *param_5, uVar4 == 0)) goto LAB_006eacc4;
    local_24 = 0;
    uVar7 = 0;
    local_1c = pwVar11;
    do {
      uVar6 = uVar7;
      local_1c = local_1c + 1;
      uVar7 = uVar6 + 1;
    } while (*local_1c == wVar9);
    if ((ushort)wVar9 < 0x65) {
      if (wVar9 == L'd') {
        if (uVar6 == 0) {
          local_24 = 1;
        }
        else if (uVar6 != 1) {
          if (uVar6 == 2) {
            uVar12 = 0x61;
          }
          else {
            if (uVar6 != 3) goto LAB_006eaf20;
            uVar12 = 0x41;
          }
          goto LAB_006eaf38;
        }
        uVar12 = 100;
        goto LAB_006eaf38;
      }
      if (wVar9 == L'\'') {
        pwVar11 = pwVar11 + uVar7;
        if ((uVar7 & 1) != 0) {
          wVar9 = *pwVar11;
          if (wVar9 == L'\0') goto LAB_006eacc4;
          do {
            if ((uVar4 == 0) || (pwVar11 = pwVar11 + 1, wVar9 == L'\'')) break;
            **param_4 = wVar9;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
            wVar9 = *pwVar11;
            uVar4 = *param_5;
          } while (wVar9 != L'\0');
        }
        goto LAB_006eaf59;
      }
      if (wVar9 != L'A') {
        if (wVar9 == L'H') {
          if (uVar6 == 0) {
            local_24 = 1;
          }
          else if (uVar7 != 2) goto LAB_006eaf20;
          uVar12 = 0x48;
          goto LAB_006eaf38;
        }
        if (wVar9 == L'M') {
          if (uVar6 == 0) {
            local_24 = 1;
          }
          else if (uVar6 != 1) {
            if (uVar6 == 2) {
              uVar12 = 0x62;
            }
            else {
              if (uVar6 != 3) goto LAB_006eaf20;
              uVar12 = 0x42;
            }
            goto LAB_006eaf38;
          }
          uVar12 = 0x6d;
          goto LAB_006eaf38;
        }
        if (wVar9 != L'a') goto LAB_006eaf20;
      }
      iVar3 = __wcsicmp(pwVar11,L"am/pm");
      if (iVar3 == 0) {
        local_1c = pwVar11 + 5;
      }
      else {
        iVar3 = __wcsicmp(pwVar11,L"a/p");
        if (iVar3 == 0) {
          local_1c = pwVar11 + 3;
        }
      }
      uVar12 = 0x70;
    }
    else if (wVar9 == L'h') {
      if (uVar6 == 0) {
        local_24 = 1;
      }
      else if (uVar7 != 2) goto LAB_006eaf20;
      uVar12 = 0x49;
    }
    else if (wVar9 == L'm') {
      if (uVar6 == 0) {
        local_24 = 1;
      }
      else if (uVar7 != 2) goto LAB_006eaf20;
      uVar12 = 0x4d;
    }
    else if (wVar9 == L's') {
      if (uVar6 == 0) {
        local_24 = 1;
      }
      else if (uVar7 != 2) goto LAB_006eaf20;
      uVar12 = 0x53;
    }
    else {
      if (wVar9 == L't') {
        if (param_3->tm_hour < 0xc) {
          pwVar10 = *(wchar_t **)(param_6 + 0x14c);
        }
        else {
          pwVar10 = *(wchar_t **)(param_6 + 0x150);
        }
        pwVar11 = local_1c;
        if ((uVar7 == 1) && (uVar4 != 0)) {
          **param_4 = *pwVar10;
          *param_4 = *param_4 + 1;
          *param_5 = *param_5 - 1;
        }
        else {
          wVar9 = *pwVar10;
          while ((wVar9 != L'\0' && (uVar4 != 0))) {
            pwVar10 = pwVar10 + 1;
            **param_4 = wVar9;
            *param_4 = *param_4 + 1;
            *param_5 = *param_5 - 1;
            wVar9 = *pwVar10;
            uVar4 = *param_5;
          }
        }
        goto LAB_006eaf59;
      }
      if (wVar9 != L'y') {
LAB_006eaf20:
        **param_4 = wVar9;
        *param_4 = *param_4 + 1;
        *param_5 = *param_5 - 1;
        pwVar11 = pwVar11 + 1;
        goto LAB_006eaf59;
      }
      if (uVar6 == 1) {
        uVar12 = 0x79;
      }
      else {
        if (uVar6 != 3) goto LAB_006eaf20;
        uVar12 = 0x59;
      }
    }
LAB_006eaf38:
    cVar2 = FUN_006e9fed(param_1,uVar12,param_3,param_4,param_5,param_6,local_24);
    pwVar11 = local_1c;
  } while (cVar2 != '\0');
  piVar8 = __errno();
  *piVar8 = 0x16;
LAB_006eacc4:
  uVar1 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return (bool)uVar1;
}

