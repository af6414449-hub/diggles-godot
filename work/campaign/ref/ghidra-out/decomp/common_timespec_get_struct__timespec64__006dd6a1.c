
/* Library Function - Single Match
    int __cdecl common_timespec_get<struct _timespec64>(struct _timespec64 * const,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_timespec_get<struct__timespec64>(_timespec64 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  undefined8 uVar3;
  uint local_c;
  
  if (param_1 == (_timespec64 *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else if (param_2 == 1) {
    local_c = 0;
    ___acrt_GetSystemTimePreciseAsFileTime_4(&local_c);
    iVar2 = -0x19db1de - (uint)(local_c < 0xd53e8000);
    if ((iVar2 < 0x483f079) && ((iVar2 < 0x483f078 || (local_c + 0x2ac18000 < 0xdd478000)))) {
      uVar3 = __alldvrm(local_c + 0x2ac18000,iVar2,&DAT_00989680,0);
      *(undefined8 *)param_1 = uVar3;
      *(int *)(param_1 + 8) = extraout_ECX * 100;
      return 1;
    }
  }
  return 0;
}

