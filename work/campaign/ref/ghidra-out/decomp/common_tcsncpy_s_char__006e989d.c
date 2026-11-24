
/* Library Function - Single Match
    int __cdecl common_tcsncpy_s<char>(char * const,unsigned int,char const * const,unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl common_tcsncpy_s<char>(char *param_1,uint param_2,char *param_3,uint param_4)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  
  if (param_4 == 0) {
    if (param_1 == (char *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_006e98d3:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = '\0';
          return 0;
        }
        if (param_3 != (char *)0x0) {
          uVar3 = param_4;
          pcVar4 = param_1;
          uVar5 = param_2;
          if (param_4 == 0xffffffff) {
            do {
              cVar1 = pcVar4[(int)param_3 - (int)param_1];
              *pcVar4 = cVar1;
              pcVar4 = pcVar4 + 1;
              if (cVar1 == '\0') break;
              uVar5 = uVar5 - 1;
            } while (uVar5 != 0);
          }
          else {
            do {
              cVar1 = pcVar4[(int)param_3 - (int)param_1];
              *pcVar4 = cVar1;
              pcVar4 = pcVar4 + 1;
              if ((cVar1 == '\0') || (uVar5 = uVar5 - 1, uVar5 == 0)) break;
              uVar3 = uVar3 - 1;
            } while (uVar3 != 0);
            if (uVar3 == 0) {
              *pcVar4 = '\0';
            }
          }
          if (uVar5 != 0) {
            return 0;
          }
          if (param_4 == 0xffffffff) {
            param_1[param_2 - 1] = '\0';
            return 0x50;
          }
          *param_1 = '\0';
          piVar2 = __errno();
          iVar6 = 0x22;
          goto LAB_006e98c1;
        }
        *param_1 = '\0';
      }
    }
  }
  else if (param_1 != (char *)0x0) goto LAB_006e98d3;
  piVar2 = __errno();
  iVar6 = 0x16;
LAB_006e98c1:
  *piVar2 = iVar6;
  FUN_006e510d();
  return iVar6;
}

