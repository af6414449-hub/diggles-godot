
/* Library Function - Single Match
    _parse_bcp47
   
   Library: Visual Studio 2019 Release */

void __cdecl parse_bcp47(void *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  uint uVar2;
  char cVar3;
  size_t sVar4;
  undefined1 *puVar5;
  wchar_t *pwVar6;
  uint uVar7;
  wchar_t *local_44;
  size_t local_40;
  size_t *local_3c;
  undefined1 local_38 [4];
  size_t local_34 [2];
  undefined1 local_2c [12];
  undefined1 local_20 [12];
  undefined1 local_14 [12];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_44 = param_2;
  _memset(param_1,0,0x1ca);
  local_40 = 0;
  uVar2 = 0;
  local_3c = local_34;
  do {
    uVar7 = uVar2;
    if (3 < uVar7) goto LAB_006e2edb;
    if (local_40 == 2) {
      pwVar6 = local_44;
      do {
        wVar1 = *pwVar6;
        pwVar6 = pwVar6 + 1;
      } while (wVar1 != L'\0');
      sVar4 = (int)pwVar6 - (int)(local_44 + 1) >> 1;
    }
    else {
      sVar4 = _wcscspn(local_44,L"-_.");
    }
    local_3c[-1] = (size_t)local_44;
    *local_3c = sVar4;
    local_3c[1] = local_40;
    wVar1 = local_44[sVar4];
    if (wVar1 == L'-') {
LAB_006e2db7:
      local_40 = 0;
    }
    else if (wVar1 == L'.') {
      local_40 = 2;
    }
    else {
      if (wVar1 == L'_') goto LAB_006e2db7;
      local_40 = 1;
    }
    local_44 = local_44 + sVar4 + 1;
    uVar2 = uVar7 + 1;
    local_3c = local_3c + 3;
  } while (local_40 != 1);
  if (uVar7 == 0) {
    parse_bcp47_language(param_1,local_38);
  }
  else {
    if (uVar7 == 1) {
      cVar3 = parse_bcp47_language(param_1,local_38);
      if (((cVar3 == '\0') || (cVar3 = parse_bcp47_script(param_1,local_2c), cVar3 != '\0')) ||
         (cVar3 = parse_bcp47_region(param_1,local_2c), cVar3 != '\0')) goto LAB_006e2edb;
      puVar5 = local_2c;
    }
    else if (uVar7 == 2) {
      cVar3 = parse_bcp47_language(param_1,local_38);
      if ((cVar3 == '\0') ||
         (((cVar3 = parse_bcp47_script(param_1,local_2c), cVar3 != '\0' &&
           ((cVar3 = parse_bcp47_region(param_1,local_20), cVar3 != '\0' ||
            (cVar3 = parse_bcp47_code_page(param_1,local_20), cVar3 != '\0')))) ||
          (cVar3 = parse_bcp47_region(param_1,local_2c), cVar3 == '\0')))) goto LAB_006e2edb;
      puVar5 = local_20;
    }
    else {
      if (((uVar7 != 3) || (cVar3 = parse_bcp47_language(param_1,local_38), cVar3 == '\0')) ||
         ((cVar3 = parse_bcp47_script(param_1,local_2c), cVar3 == '\0' ||
          (cVar3 = parse_bcp47_region(param_1,local_20), cVar3 == '\0')))) goto LAB_006e2edb;
      puVar5 = local_14;
    }
    parse_bcp47_code_page(param_1,puVar5);
  }
LAB_006e2edb:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

