
/* Library Function - Single Match
    ___acrt_errno_map_os_error
   
   Library: Visual Studio 2019 Release */

void ___acrt_errno_map_os_error(ulong param_1)

{
  ulong *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = ___doserrno();
  *puVar1 = param_1;
  iVar2 = FID_conflict____acrt_errno_from_os_error(param_1);
  piVar3 = __errno();
  *piVar3 = iVar2;
  return;
}

