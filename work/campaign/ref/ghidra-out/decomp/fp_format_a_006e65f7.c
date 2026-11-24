
/* Library Function - Single Match
    int __cdecl fp_format_a(double const * const,char *,unsigned int,char * const,unsigned
   int,int,bool,unsigned int,struct __crt_locale_pointers * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
fp_format_a(double *param_1,char *param_2,uint param_3,char *param_4,uint param_5,int param_6,
           bool param_7,uint param_8,__crt_locale_pointers *param_9)

{
  char *pcVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar11;
  bool bVar12;
  int local_3c;
  int local_38;
  char local_30;
  char *local_28;
  int local_20;
  uint local_18;
  uint local_14;
  char *local_10;
  int local_c;
  char local_5;
  
  if (param_6 < 0) {
    param_6 = 0;
  }
  *param_2 = '\0';
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_3c,param_9);
  if (param_6 + 0xbU < param_3) {
    uVar7 = *(uint *)((int)param_1 + 4);
    if ((uVar7 >> 0x14 & 0x7ff) == 0x7ff) {
      iVar5 = fp_format_e(param_1,param_2,param_3,param_4,param_5,param_6,false,param_8,
                          (__crt_locale_pointers *)0x0);
      if (iVar5 == 0) {
        pcVar6 = (char *)FUN_006cfeb0(param_2,0x65);
        if (pcVar6 != (char *)0x0) {
          *pcVar6 = !param_7 * ' ' + 'P';
          pcVar6[3] = '\0';
        }
        iVar5 = 0;
      }
      else {
        *param_2 = '\0';
      }
    }
    else {
      if (((int)uVar7 < 1) && ((int)uVar7 < 0)) {
        *param_2 = '-';
        param_2 = param_2 + 1;
        uVar7 = *(uint *)((int)param_1 + 4);
      }
      local_28 = param_2 + 1;
      local_5 = !param_7;
      local_14 = 0x3ff;
      local_20 = (uint)(byte)local_5 * 0x20 + 7;
      if ((uVar7 & 0x7ff00000) == 0) {
        *param_2 = '0';
        if (*(int *)param_1 == 0 && ((ulonglong)*param_1 & 0xfffff00000000) == 0) {
          local_14 = 0;
        }
        else {
          local_14 = 0x3fe;
        }
      }
      else {
        *param_2 = '1';
      }
      pcVar6 = param_2 + 2;
      if (param_6 == 0) {
        cVar9 = '\0';
      }
      else {
        cVar9 = *(char *)**(undefined4 **)(local_38 + 0x88);
      }
      *local_28 = cVar9;
      if ((((ulonglong)*param_1 & 0xfffff00000000) != 0) ||
         (local_18 = 0, local_10 = pcVar6, *(int *)param_1 != 0)) {
        local_c = 0x30;
        local_18 = 0xf0000;
        local_10 = (char *)0;
        do {
          if (param_6 < 1) break;
          sVar2 = __aullshr();
          uVar7 = (uint)(ushort)(sVar2 + 0x30);
          if (0x39 < uVar7) {
            uVar7 = uVar7 + local_20;
          }
          local_10 = (char *)((uint)local_10 >> 4 | local_18 << 0x1c);
          *pcVar6 = (char)uVar7;
          pcVar6 = pcVar6 + 1;
          local_18 = local_18 >> 4;
          local_c = local_c + -4;
          param_6 = param_6 - 1;
        } while (-1 < (short)local_c);
        local_10 = pcVar6;
        if ((-1 < (short)local_c) && (uVar3 = __aullshr(), pcVar1 = pcVar6, 8 < uVar3)) {
          while( true ) {
            pcVar8 = pcVar1 + -1;
            cVar9 = *pcVar8;
            if ((cVar9 != 'f') && (cVar9 != 'F')) break;
            *pcVar8 = '0';
            pcVar1 = pcVar8;
          }
          if (pcVar8 == local_28) {
            pcVar1[-2] = pcVar1[-2] + '\x01';
          }
          else {
            if (cVar9 == '9') {
              cVar9 = (char)local_20 + ':';
            }
            else {
              cVar9 = cVar9 + '\x01';
            }
            *pcVar8 = cVar9;
          }
        }
      }
      if (0 < param_6) {
        _memset(pcVar6,0x30,param_6);
        pcVar6 = pcVar6 + param_6;
        local_10 = pcVar6;
      }
      if (*local_28 == '\0') {
        local_10 = local_28;
        pcVar6 = local_28;
      }
      *pcVar6 = local_5 * ' ' + 'P';
      uVar7 = __aullshr();
      uVar10 = (uVar7 & 0x7ff) - local_14;
      uVar7 = (uint)((uVar7 & 0x7ff) < local_14);
      iVar5 = -uVar7;
      pcVar6 = local_10 + 2;
      if (uVar7 == 0) {
        iVar11 = CONCAT31((int3)((uint)param_1 >> 8),0x2b);
      }
      else {
        bVar12 = uVar10 != 0;
        uVar10 = -uVar10;
        iVar5 = -(iVar5 + (uint)bVar12);
        iVar11 = 0x2d;
      }
      local_10[1] = (char)iVar11;
      *pcVar6 = '0';
      local_28 = pcVar6;
      if ((-1 < iVar5) && ((iVar11 = 1000, 0 < iVar5 || (999 < uVar10)))) {
        iVar11 = 1000;
        cVar9 = __alldvrm(uVar10,iVar5,1000,0);
        iVar5 = 1000;
        *local_28 = cVar9 + '0';
        pcVar6 = local_28 + 1;
        uVar10 = extraout_ECX;
        local_20 = extraout_EDX;
      }
      if ((pcVar6 != local_28) || ((-1 < iVar5 && ((0 < iVar5 || (99 < uVar10)))))) {
        cVar9 = __alldvrm(uVar10,iVar5,100,0);
        *pcVar6 = cVar9 + '0';
        pcVar6 = pcVar6 + 1;
        uVar10 = extraout_ECX_00;
        iVar5 = iVar11;
        local_20 = extraout_EDX_00;
      }
      if ((pcVar6 != local_28) || ((-1 < iVar5 && ((0 < iVar5 || (9 < uVar10)))))) {
        cVar9 = __alldvrm(uVar10,iVar5,10,0);
        *pcVar6 = cVar9 + '0';
        pcVar6 = pcVar6 + 1;
        uVar10 = extraout_ECX_01;
      }
      *pcVar6 = (char)uVar10 + '0';
      pcVar6[1] = '\0';
      iVar5 = 0;
    }
  }
  else {
    piVar4 = __errno();
    iVar5 = 0x22;
    *piVar4 = 0x22;
    FUN_006e510d();
  }
  if (local_30 != '\0') {
    *(uint *)(local_3c + 0x350) = *(uint *)(local_3c + 0x350) & 0xfffffffd;
  }
  return iVar5;
}

