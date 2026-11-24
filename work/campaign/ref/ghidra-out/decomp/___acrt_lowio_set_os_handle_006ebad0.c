
/* Library Function - Single Match
    ___acrt_lowio_set_os_handle
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_lowio_set_os_handle(uint param_1,HANDLE param_2)

{
  int iVar1;
  int *piVar2;
  ulong *puVar3;
  int iVar4;
  DWORD nStdHandle;
  
  if ((-1 < (int)param_1) && (param_1 < DAT_00769f80)) {
    iVar4 = (param_1 & 0x3f) * 0x38;
    if (*(int *)(iVar4 + 0x18 + (&DAT_00769d80)[(int)param_1 >> 6]) == -1) {
      iVar1 = FUN_006e1735();
      if (iVar1 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_006ebb35;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_006ebb35:
      *(HANDLE *)(iVar4 + 0x18 + (&DAT_00769d80)[(int)param_1 >> 6]) = param_2;
      return 0;
    }
  }
  piVar2 = __errno();
  *piVar2 = 9;
  puVar3 = ___doserrno();
  *puVar3 = 0;
  return 0xffffffff;
}

