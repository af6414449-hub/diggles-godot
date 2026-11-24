
/* Library Function - Single Match
    ___acrt_fp_strflt_to_string
   
   Library: Visual Studio 2019 Release */

int ___acrt_fp_strflt_to_string(char *param_1,uint param_2,int param_3,int param_4)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    *param_1 = '\0';
    iVar5 = param_3;
    if (param_3 < 1) {
      iVar5 = 0;
    }
    if (param_2 <= iVar5 + 1U) {
      piVar1 = __errno();
      iVar5 = 0x22;
      goto LAB_006efeeb;
    }
    if (param_4 != 0) {
      pcVar2 = param_1 + 1;
      pcVar4 = *(char **)(param_4 + 8);
      *param_1 = '0';
      if (0 < param_3) {
        do {
          cVar3 = *pcVar4;
          if (cVar3 == '\0') {
            cVar3 = '0';
          }
          else {
            pcVar4 = pcVar4 + 1;
          }
          *pcVar2 = cVar3;
          pcVar2 = pcVar2 + 1;
          param_3 = param_3 + -1;
        } while (0 < param_3);
      }
      *pcVar2 = '\0';
      if ((-1 < param_3) && ('4' < *pcVar4)) {
        while( true ) {
          pcVar2 = pcVar2 + -1;
          if (*pcVar2 != '9') break;
          *pcVar2 = '0';
        }
        *pcVar2 = *pcVar2 + '\x01';
      }
      if (*param_1 == '1') {
        *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + 1;
      }
      else {
        pcVar2 = param_1 + 1;
        do {
          cVar3 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar3 != '\0');
        FUN_006d1b90(param_1,param_1 + 1,pcVar2 + (1 - (int)(param_1 + 2)));
      }
      return 0;
    }
  }
  piVar1 = __errno();
  iVar5 = 0x16;
LAB_006efeeb:
  *piVar1 = iVar5;
  FUN_006e510d();
  return iVar5;
}

