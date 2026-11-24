
/* Library Function - Single Match
    _qsort
   
   Library: Visual Studio 2019 Release */

void __cdecl
_qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,_PtFuncCompare *_PtFuncCompare)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *local_114;
  int local_110;
  char *local_108;
  char *local_100;
  char *local_fc;
  undefined4 auStack_f8 [30];
  undefined4 auStack_80 [30];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_108 = (char *)_Base;
  if ((((_Base == (void *)0x0) && (_NumOfElements != 0)) || (_SizeOfElements == 0)) ||
     (_PtFuncCompare == (_PtFuncCompare *)0x0)) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
  }
  else {
    local_110 = 0;
    if (1 < _NumOfElements) {
      local_100 = (char *)((_NumOfElements - 1) * _SizeOfElements + (int)_Base);
LAB_006da082:
      while (uVar1 = (uint)((int)local_100 - (int)local_108) / _SizeOfElements + 1, 8 < uVar1) {
        pcVar8 = local_108 + (uVar1 >> 1) * _SizeOfElements;
        pcVar7 = local_108;
        pcVar5 = pcVar8;
        guard_check_icall();
        iVar4 = (*_PtFuncCompare)(pcVar7,pcVar5);
        if (0 < iVar4) {
          swap(local_108,pcVar8,_SizeOfElements);
        }
        pcVar7 = local_108;
        pcVar5 = local_100;
        guard_check_icall();
        iVar4 = (*_PtFuncCompare)(pcVar7,pcVar5);
        if (0 < iVar4) {
          swap(local_108,local_100,_SizeOfElements);
        }
        pcVar7 = pcVar8;
        pcVar5 = local_100;
        guard_check_icall();
        iVar4 = (*_PtFuncCompare)(pcVar7,pcVar5);
        local_114 = local_108;
        local_fc = local_100;
        if (0 < iVar4) {
          swap(pcVar8,local_100,_SizeOfElements);
        }
LAB_006da220:
        if (local_114 < pcVar8) {
          do {
            local_114 = local_114 + _SizeOfElements;
            if (pcVar8 <= local_114) goto LAB_006da261;
            pcVar7 = local_114;
            pcVar5 = pcVar8;
            guard_check_icall();
            iVar4 = (*_PtFuncCompare)(pcVar7,pcVar5);
          } while (iVar4 < 1);
          pcVar7 = local_fc;
          if (pcVar8 <= local_114) goto LAB_006da261;
        }
        else {
LAB_006da261:
          do {
            local_114 = local_114 + _SizeOfElements;
            pcVar7 = local_fc;
            if (local_100 < local_114) break;
            pcVar7 = local_114;
            pcVar5 = pcVar8;
            guard_check_icall();
            iVar4 = (*_PtFuncCompare)(pcVar7,pcVar5);
            pcVar7 = local_fc;
          } while (iVar4 < 1);
        }
        do {
          local_fc = pcVar7;
          pcVar7 = local_fc + -_SizeOfElements;
          if (pcVar7 <= pcVar8) break;
          pcVar5 = pcVar7;
          pcVar9 = pcVar8;
          guard_check_icall();
          iVar4 = (*_PtFuncCompare)(pcVar5,pcVar9);
        } while (0 < iVar4);
        if (local_114 <= pcVar7) {
          pcVar5 = pcVar7;
          sVar6 = _SizeOfElements;
          if (pcVar7 != local_114) {
            do {
              pcVar9 = pcVar5 + 1;
              cVar2 = pcVar9[(int)(local_114 + (-1 - (int)pcVar7))];
              pcVar9[(int)(local_114 + (-1 - (int)pcVar7))] = *pcVar5;
              *pcVar5 = cVar2;
              sVar6 = sVar6 - 1;
              pcVar5 = pcVar9;
            } while (sVar6 != 0);
          }
          local_fc = pcVar7;
          if (pcVar8 == pcVar7) {
            pcVar8 = local_114;
          }
          goto LAB_006da220;
        }
        if (pcVar8 < local_fc) {
          do {
            local_fc = local_fc + -_SizeOfElements;
            if (local_fc <= pcVar8) goto LAB_006da381;
            pcVar7 = local_fc;
            pcVar5 = pcVar8;
            guard_check_icall();
            iVar4 = (*_PtFuncCompare)(pcVar7,pcVar5);
          } while (iVar4 == 0);
          if (local_fc <= pcVar8) goto LAB_006da381;
        }
        else {
LAB_006da381:
          do {
            local_fc = local_fc + -_SizeOfElements;
            if (local_fc <= local_108) break;
            pcVar7 = local_fc;
            pcVar5 = pcVar8;
            guard_check_icall();
            iVar4 = (*_PtFuncCompare)(pcVar7,pcVar5);
          } while (iVar4 == 0);
        }
        if ((int)local_fc - (int)local_108 < (int)local_100 - (int)local_114) goto LAB_006da407;
        if (local_108 < local_fc) {
          auStack_80[local_110] = local_108;
          auStack_f8[local_110] = local_fc;
          local_110 = local_110 + 1;
        }
        local_108 = local_114;
        if (local_100 <= local_114) goto LAB_006da145;
      }
      if (local_108 < local_100) {
        pcVar8 = local_108 + _SizeOfElements;
        pcVar7 = pcVar8;
        local_fc = local_108;
        do {
          for (; pcVar7 <= local_100; pcVar7 = pcVar7 + _SizeOfElements) {
            pcVar5 = pcVar7;
            pcVar9 = local_fc;
            guard_check_icall();
            iVar4 = (*_PtFuncCompare)(pcVar5,pcVar9);
            if (0 < iVar4) {
              local_fc = pcVar7;
            }
          }
          if (local_fc != local_100) {
            pcVar7 = local_100;
            sVar6 = _SizeOfElements;
            do {
              cVar2 = pcVar7[(int)local_fc - (int)local_100];
              (pcVar7 + 1)[((int)local_fc - (int)local_100) + -1] = *pcVar7;
              *pcVar7 = cVar2;
              sVar6 = sVar6 - 1;
              pcVar7 = pcVar7 + 1;
            } while (sVar6 != 0);
          }
          local_100 = local_100 + -_SizeOfElements;
          pcVar7 = pcVar8;
          local_fc = local_108;
        } while (local_108 < local_100);
      }
      goto LAB_006da145;
    }
  }
LAB_006da04e:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
LAB_006da407:
  if (local_114 < local_100) {
    auStack_80[local_110] = local_114;
    auStack_f8[local_110] = local_100;
    local_110 = local_110 + 1;
  }
  local_100 = local_fc;
  if (local_fc <= local_108) {
LAB_006da145:
    iVar4 = local_110 + -1;
    if (0 < local_110) {
      local_108 = (char *)auStack_80[iVar4];
      local_110 = iVar4;
      local_100 = (char *)auStack_f8[iVar4];
      goto LAB_006da082;
    }
    goto LAB_006da04e;
  }
  goto LAB_006da082;
}

