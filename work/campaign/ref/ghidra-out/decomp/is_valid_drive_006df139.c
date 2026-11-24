
/* Library Function - Single Match
    int __cdecl is_valid_drive(unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl is_valid_drive(uint param_1)

{
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  WCHAR local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_1 < 0x1b) {
    if (param_1 != 0) {
      local_10 = (short)param_1 + L'@';
      local_e = 0x3a;
      local_c = 0x5c;
      local_a = 0;
      GetDriveTypeW(&local_10);
    }
  }
  else {
    puVar1 = ___doserrno();
    *puVar1 = 0xf;
    piVar2 = __errno();
    *piVar2 = 0xd;
    FUN_006e510d();
  }
  iVar3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar3;
}

