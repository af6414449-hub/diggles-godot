
/* Library Function - Single Match
    __get_sys_err_msg
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

char * __cdecl __get_sys_err_msg(int m)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = (uint *)FUN_006ec054();
  if (*puVar1 <= (uint)m) {
    piVar2 = (int *)FUN_006ec054();
    m = *piVar2;
  }
  iVar3 = FUN_006ec04e();
  return *(char **)(iVar3 + m * 4);
}

