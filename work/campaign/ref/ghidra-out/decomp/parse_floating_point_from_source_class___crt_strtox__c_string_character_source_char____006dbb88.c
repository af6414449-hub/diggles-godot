
/* Library Function - Single Match
    enum __crt_strtox::floating_point_parse_result __cdecl
   __crt_strtox::parse_floating_point_from_source<class
   __crt_strtox::c_string_character_source<char> >(struct __crt_locale_pointers * const,class
   __crt_strtox::c_string_character_source<char> &,struct __crt_strtox::floating_point_string &)
   
   Library: Visual Studio 2019 Release */

floating_point_parse_result __cdecl
__crt_strtox::parse_floating_point_from_source<class___crt_strtox::c_string_character_source<char>_>
          (__crt_locale_pointers *param_1,c_string_character_source<char> *param_2,
          floating_point_string *param_3)

{
  byte *pbVar1;
  undefined1 uVar2;
  char *pcVar3;
  byte *pbVar4;
  bool bVar5;
  byte bVar6;
  int iVar7;
  floating_point_string *pfVar8;
  uint uVar9;
  char *pcVar10;
  floating_point_parse_result fVar11;
  byte bVar12;
  char cVar13;
  uint uVar14;
  floating_point_string *pfVar15;
  uint uVar16;
  floating_point_string *pfVar17;
  char *local_18;
  int local_10;
  byte local_9 [4];
  byte local_5;
  
  bVar5 = c_string_character_source<char>::validate(param_2);
  if (!bVar5) {
    return 7;
  }
  pcVar10 = *(char **)param_2;
  cVar13 = *pcVar10;
  pcVar3 = pcVar10;
  while( true ) {
    *(char **)param_2 = pcVar3 + 1;
    local_9[0] = cVar13;
    iVar7 = __ischartype_l(cVar13,8,param_1);
    if (iVar7 == 0) break;
    pcVar3 = *(char **)param_2;
    cVar13 = *pcVar3;
  }
  pfVar15 = param_3 + 0x308;
  *pfVar15 = (floating_point_string)(local_9[0] == 0x2d);
  if ((local_9[0] == 0x2d) || (bVar12 = local_9[0], local_9[0] == 0x2b)) {
    bVar12 = **(byte **)param_2;
    local_9[0] = bVar12;
    *(byte **)param_2 = *(byte **)param_2 + 1;
  }
  if ((bVar12 == 0x49) || (bVar12 == 0x69)) {
    fVar11 = parse_floating_point_possible_infinity<char,class___crt_strtox::c_string_character_source<char>,char_const*>
                       ((char *)local_9,param_2,pcVar10);
    return fVar11;
  }
  if ((bVar12 == 0x4e) || (bVar12 == 0x6e)) {
    fVar11 = parse_floating_point_possible_nan<char,class___crt_strtox::c_string_character_source<char>,char_const*>
                       ((char *)local_9,param_2,pcVar10);
    return fVar11;
  }
  local_10 = 0;
  local_5 = 0;
  local_18 = pcVar10;
  if (bVar12 == 0x30) {
    local_18 = *(char **)param_2;
    cVar13 = *local_18;
    *(char **)param_2 = local_18 + 1;
    if ((cVar13 == 'x') || (cVar13 == 'X')) {
      bVar12 = local_18[1];
      local_5 = 1;
      local_9[0] = bVar12;
      *(char **)param_2 = local_18 + 2;
    }
    else {
      c_string_character_source<char>::unget(param_2,cVar13);
      bVar12 = local_9[0];
      local_18 = pcVar10;
    }
  }
  uVar14 = (uint)bVar12;
  pfVar8 = param_3 + 8;
  if (bVar12 == 0x30) {
    uVar14 = 0x100;
    do {
      cVar13 = **(char **)param_2;
      uVar14 = CONCAT31((int3)(uVar14 >> 8),cVar13);
      local_9[0] = cVar13;
      *(char **)param_2 = *(char **)param_2 + 1;
    } while (cVar13 == '0');
  }
  uVar16 = ((local_5 == 0) - 1 & 6) + 9;
  pfVar17 = pfVar8;
  while( true ) {
    cVar13 = (char)uVar14;
    if ((byte)(cVar13 - 0x30U) < 10) {
      uVar9 = (int)cVar13 - 0x30;
    }
    else if ((byte)(cVar13 + 0x9fU) < 0x1a) {
      uVar9 = (int)cVar13 - 0x57;
    }
    else if ((byte)(cVar13 + 0xbfU) < 0x1a) {
      uVar9 = (int)cVar13 - 0x37;
    }
    else {
      uVar9 = 0xffffffff;
    }
    if (uVar16 < uVar9) break;
    if (pfVar17 != pfVar15) {
      *pfVar17 = SUB41(uVar9,0);
      pfVar17 = pfVar17 + 1;
    }
    local_10 = local_10 + 1;
    local_9[0] = **(undefined1 **)param_2;
    uVar14 = (uint)CONCAT11(1,local_9[0]);
    *(undefined1 **)param_2 = *(undefined1 **)param_2 + 1;
  }
  iVar7 = 0;
  if (cVar13 == *(char *)**(undefined4 **)(*(int *)param_1 + 0x88)) {
    local_9[0] = **(char **)param_2;
    pcVar10 = *(char **)param_2 + 1;
    uVar14 = CONCAT31((int3)(uVar14 >> 8),local_9[0]);
    *(char **)param_2 = pcVar10;
    if ((pfVar17 == pfVar8) && (local_9[0] == '0')) {
      uVar14 = 0x100;
      do {
        cVar13 = *pcVar10;
        uVar14 = CONCAT31((int3)(uVar14 >> 8),cVar13);
        local_10 = local_10 + -1;
        pcVar10 = pcVar10 + 1;
        local_9[0] = cVar13;
        *(char **)param_2 = pcVar10;
      } while (cVar13 == '0');
    }
    while( true ) {
      cVar13 = (char)uVar14;
      if ((byte)(cVar13 - 0x30U) < 10) {
        uVar9 = (int)cVar13 - 0x30;
      }
      else if ((byte)(cVar13 + 0x9fU) < 0x1a) {
        uVar9 = (int)cVar13 - 0x57;
      }
      else if ((byte)(cVar13 + 0xbfU) < 0x1a) {
        uVar9 = (int)cVar13 - 0x37;
      }
      else {
        uVar9 = 0xffffffff;
      }
      if (uVar16 < uVar9) break;
      if (pfVar17 != pfVar15) {
        *pfVar17 = SUB41(uVar9,0);
        pfVar17 = pfVar17 + 1;
      }
      uVar2 = **(undefined1 **)param_2;
      uVar14 = (uint)CONCAT11(1,uVar2);
      local_9[0] = uVar2;
      *(undefined1 **)param_2 = *(undefined1 **)param_2 + 1;
    }
  }
  if ((char)(uVar14 >> 8) == '\0') {
    c_string_character_source<char>::unget(param_2,local_9[0]);
    *(char **)param_2 = local_18;
    if (local_5 != 0) {
      return 2;
    }
    return 7;
  }
  c_string_character_source<char>::unget(param_2,local_9[0]);
  pbVar4 = *(byte **)param_2;
  bVar12 = *pbVar4;
  pbVar1 = pbVar4 + 1;
  bVar5 = false;
  *(byte **)param_2 = pbVar1;
  if (bVar12 == 0x45) {
LAB_006dbdc8:
    bVar6 = local_5 ^ 1;
  }
  else {
    if (bVar12 != 0x50) {
      if (bVar12 == 0x65) goto LAB_006dbdc8;
      bVar6 = 0;
      if (bVar12 != 0x70) goto LAB_006dbdcd;
    }
    bVar6 = local_5;
  }
LAB_006dbdcd:
  local_9[0] = bVar12;
  if (bVar6 != 0) {
    local_9[0] = *pbVar1;
    uVar14 = (uint)local_9[0] << 8;
    *(byte **)param_2 = pbVar4 + 2;
    if ((local_9[0] == 0x2b) || (uVar14 = (uint)CONCAT11(local_9[0],local_9[0]), local_9[0] == 0x2d)
       ) {
      local_9[0] = pbVar4[2];
      uVar14 = CONCAT31((int3)(uVar14 >> 8),local_9[0]);
      *(byte **)param_2 = pbVar4 + 3;
    }
    if ((char)uVar14 == '0') {
      bVar5 = true;
      do {
        local_9[0] = **(byte **)param_2;
        uVar14 = CONCAT31((int3)(uVar14 >> 8),local_9[0]);
        *(byte **)param_2 = *(byte **)param_2 + 1;
      } while (local_9[0] == 0x30);
    }
    while( true ) {
      cVar13 = (char)uVar14;
      if ((byte)(cVar13 - 0x30U) < 10) {
        uVar16 = (int)cVar13 - 0x30;
      }
      else if ((byte)(cVar13 + 0x9fU) < 0x1a) {
        uVar16 = (int)cVar13 - 0x57;
      }
      else if ((byte)(cVar13 + 0xbfU) < 0x1a) {
        uVar16 = (int)cVar13 - 0x37;
      }
      else {
        uVar16 = 0xffffffff;
      }
      if (9 < uVar16) goto LAB_006dbe6c;
      bVar5 = true;
      iVar7 = iVar7 * 10 + uVar16;
      if (0x1450 < iVar7) break;
      local_9[0] = **(byte **)param_2;
      bVar5 = true;
      uVar14 = CONCAT31((int3)(uVar14 >> 8),local_9[0]);
      *(byte **)param_2 = *(byte **)param_2 + 1;
    }
    iVar7 = 0x1451;
LAB_006dbe6c:
    while( true ) {
      cVar13 = (char)uVar14;
      if (((char)local_9[0] < '0') || ('9' < cVar13)) {
        if ((byte)(cVar13 + 0x9fU) < 0x1a) {
          uVar16 = (int)cVar13 - 0x57;
        }
        else if ((byte)(cVar13 + 0xbfU) < 0x1a) {
          uVar16 = (int)cVar13 - 0x37;
        }
        else {
          uVar16 = 0xffffffff;
        }
      }
      else {
        uVar16 = (int)cVar13 - 0x30;
      }
      if (9 < uVar16) break;
      local_9[0] = **(byte **)param_2;
      uVar14 = CONCAT31((int3)(uVar14 >> 8),local_9[0]);
      *(byte **)param_2 = *(byte **)param_2 + 1;
    }
    if ((char)(uVar14 >> 8) == '-') {
      iVar7 = -iVar7;
    }
    if (!bVar5) {
      c_string_character_source<char>::unget(param_2,local_9[0]);
      *(byte **)param_2 = pbVar4;
      local_9[0] = *pbVar4;
      *(byte **)param_2 = pbVar1;
    }
  }
  c_string_character_source<char>::unget(param_2,local_9[0]);
  if (pfVar17 != pfVar8) {
    do {
      if (pfVar17[-1] != (floating_point_string)0x0) break;
      pfVar17 = pfVar17 + -1;
    } while (pfVar17 != pfVar8);
    if (pfVar17 != pfVar8) {
      if (0x1450 < iVar7) {
        return 9;
      }
      if (-0x1451 < iVar7) {
        iVar7 = iVar7 + (((local_5 == 0) - 1 & 3) + 1) * local_10;
        if (0x1450 < iVar7) {
          return 9;
        }
        if (-0x1451 < iVar7) {
          *(int *)param_3 = iVar7;
          *(int *)(param_3 + 4) = (int)pfVar17 - (int)pfVar8;
          return (uint)local_5;
        }
      }
      return 8;
    }
  }
  return 2;
}

