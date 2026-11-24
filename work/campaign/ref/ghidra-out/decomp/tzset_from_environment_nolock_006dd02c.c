
/* Library Function - Single Match
    void __cdecl tzset_from_environment_nolock(char *)
   
   Library: Visual Studio 2019 Release */

void __cdecl tzset_from_environment_nolock(char *param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  undefined4 *puVar4;
  errno_t eVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  int *piVar10;
  uint *puVar11;
  byte *pbVar12;
  char *pcVar13;
  int iVar14;
  bool bVar15;
  uint local_c;
  long local_8;
  
  puVar4 = (undefined4 *)FUN_006e9368();
  local_8 = 0;
  local_c = 0;
  eVar5 = __get_timezone(&local_8);
  if ((eVar5 == 0) && (eVar5 = __get_daylight((int *)&local_c), eVar5 == 0)) {
    pbVar6 = (byte *)param_1;
    pbVar12 = DAT_00769b58;
    if (DAT_00769b58 != (byte *)0x0) {
      do {
        bVar1 = *pbVar6;
        bVar15 = bVar1 < *pbVar12;
        if (bVar1 != *pbVar12) {
LAB_006dd09d:
          uVar7 = -(uint)bVar15 | 1;
          goto LAB_006dd0a2;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar15 = bVar1 < pbVar12[1];
        if (bVar1 != pbVar12[1]) goto LAB_006dd09d;
        pbVar6 = pbVar6 + 2;
        pbVar12 = pbVar12 + 2;
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_006dd0a2:
      if (uVar7 == 0) {
        return;
      }
    }
    FID_conflict__free(DAT_00769b58);
    pcVar13 = param_1;
    do {
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    DAT_00769b58 = (byte *)__malloc_base(pcVar13 + (1 - (int)(param_1 + 1)));
    FID_conflict__free((void *)0x0);
    if (DAT_00769b58 == (byte *)0x0) {
      return;
    }
    pcVar13 = param_1;
    do {
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    eVar5 = _strcpy_s((char *)DAT_00769b58,(rsize_t)(pcVar13 + (1 - (int)(param_1 + 1))),param_1);
    if (eVar5 == 0) {
      iVar14 = 3;
      iVar8 = FUN_006e9950(*puVar4,0x40,param_1,3);
      if (iVar8 == 0) {
        do {
          if (*param_1 == '\0') break;
          param_1 = param_1 + 1;
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        cVar2 = *param_1;
        if (cVar2 == '-') {
          param_1 = param_1 + 1;
        }
        lVar9 = _atol(param_1);
        local_8 = lVar9 * 0xe10;
        for (; (cVar3 = *param_1, cVar3 == '+' || ((byte)(cVar3 - 0x30U) < 10));
            param_1 = param_1 + 1) {
        }
        if (cVar3 == ':') {
          param_1 = param_1 + 1;
          lVar9 = _atol(param_1);
          local_8 = local_8 + lVar9 * 0x3c;
          cVar3 = *param_1;
          while (('/' < cVar3 && (cVar3 < ':'))) {
            param_1 = param_1 + 1;
            cVar3 = *param_1;
          }
          if (cVar3 == ':') {
            param_1 = param_1 + 1;
            lVar9 = _atol(param_1);
            local_8 = local_8 + lVar9;
            for (; ('/' < *param_1 && (*param_1 < ':')); param_1 = param_1 + 1) {
            }
          }
        }
        if (cVar2 == '-') {
          local_8 = -local_8;
        }
        local_c = (uint)(*param_1 != '\0');
        if (*param_1 == '\0') {
          *(undefined1 *)puVar4[1] = 0;
        }
        else {
          iVar14 = FUN_006e9950((undefined1 *)puVar4[1],0x40,param_1,3);
          if (iVar14 != 0) goto LAB_006dd1fa;
        }
        lVar9 = local_8;
        piVar10 = (int *)FUN_006e9362();
        uVar7 = local_c;
        *piVar10 = lVar9;
        puVar11 = (uint *)FUN_006e9356();
        *puVar11 = uVar7;
        return;
      }
    }
  }
LAB_006dd1fa:
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

