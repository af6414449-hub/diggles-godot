
/* Library Function - Single Match
    int __cdecl common_set_variable_in_environment_nolock<char>(char * const,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_set_variable_in_environment_nolock<char>(char *param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  char *pcVar5;
  char **ppcVar6;
  int iVar7;
  char *_Dst;
  errno_t eVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  
  if (param_1 == (char *)0x0) {
    piVar4 = __errno();
    *piVar4 = 0x16;
    return -1;
  }
  pcVar5 = (char *)FUN_006d0190(param_1,0x3d);
  pcVar11 = param_1;
  if ((pcVar5 == (char *)0x0) || (pcVar5 == param_1)) {
LAB_006ed265:
    piVar4 = __errno();
    *piVar4 = 0x16;
    goto LAB_006ed270;
  }
  cVar2 = pcVar5[1];
  ensure_current_environment_is_not_initial_environment_nolock<char>();
  iVar9 = 0;
  if (DAT_00769d20 == (int *)0x0) {
    if ((param_2 != 0) && (DAT_00769d24 != 0)) {
      ppcVar6 = common_get_or_create_environment_nolock<char>();
      if (ppcVar6 == (char **)0x0) goto LAB_006ed265;
      ensure_current_environment_is_not_initial_environment_nolock<char>();
      goto LAB_006ed122;
    }
    if (cVar2 == '\0') {
      iVar9 = 0;
      goto LAB_006ed273;
    }
    DAT_00769d20 = (int *)__calloc_base(1,4);
    FID_conflict__free((void *)0x0);
    if (DAT_00769d20 != (int *)0x0) {
      if (DAT_00769d24 == 0) {
        DAT_00769d24 = __calloc_base(1,4);
        FID_conflict__free((void *)0x0);
        if (DAT_00769d24 == 0) goto LAB_006ed270;
      }
      goto LAB_006ed122;
    }
  }
  else {
LAB_006ed122:
    piVar4 = DAT_00769d20;
    if (DAT_00769d20 != (int *)0x0) {
      iVar7 = find_in_environment_nolock<char>(param_1,(int)pcVar5 - (int)param_1);
      if ((-1 < iVar7) && (*piVar4 != 0)) {
        FID_conflict__free((void *)piVar4[iVar7]);
        if (cVar2 == '\0') {
          for (; piVar4[iVar7] != 0; iVar7 = iVar7 + 1) {
            piVar4[iVar7] = piVar4[iVar7 + 1];
          }
          piVar4 = (int *)__recalloc_base(piVar4,iVar7,4);
          FID_conflict__free((void *)0x0);
          if (piVar4 != (int *)0x0) {
LAB_006ed1ea:
            DAT_00769d20 = piVar4;
          }
        }
        else {
          pcVar11 = (char *)0x0;
          piVar4[iVar7] = (int)param_1;
        }
        if (param_2 != 0) {
          pcVar10 = param_1;
          do {
            cVar3 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar3 != '\0');
          _Dst = (char *)__calloc_base(pcVar10 + (2 - (int)(param_1 + 1)),1);
          if (_Dst != (char *)0x0) {
            eVar8 = _strcpy_s(_Dst,(rsize_t)(pcVar10 + (2 - (int)(param_1 + 1))),param_1);
            if (eVar8 != 0) {
                    /* WARNING: Subroutine does not return */
              __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            (pcVar5 + (int)(_Dst + (1 - (int)param_1)))[-1] = '\0';
            iVar7 = ___acrt_SetEnvironmentVariableA
                              (_Dst,-(uint)(cVar2 != '\0') &
                                    (uint)(pcVar5 + (int)(_Dst + (1 - (int)param_1))));
            if (iVar7 == 0) {
              piVar4 = __errno();
              iVar9 = -1;
              *piVar4 = 0x2a;
            }
          }
          FID_conflict__free(_Dst);
        }
        goto LAB_006ed273;
      }
      if (cVar2 == '\0') goto LAB_006ed273;
      uVar1 = -iVar7 + 2;
      if (((uint)-iVar7 <= uVar1) && (uVar1 < 0x3fffffff)) {
        piVar4 = (int *)__recalloc_base(piVar4,uVar1,4);
        FID_conflict__free((void *)0x0);
        if (piVar4 != (int *)0x0) {
          piVar4[-iVar7] = (int)param_1;
          piVar4[1 - iVar7] = 0;
          pcVar11 = (char *)0x0;
          goto LAB_006ed1ea;
        }
      }
    }
  }
LAB_006ed270:
  iVar9 = -1;
LAB_006ed273:
  FID_conflict__free(pcVar11);
  return iVar9;
}

