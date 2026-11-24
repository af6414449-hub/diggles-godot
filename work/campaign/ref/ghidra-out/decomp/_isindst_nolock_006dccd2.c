
/* Library Function - Single Match
    int __cdecl _isindst_nolock(struct tm * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl _isindst_nolock(tm *param_1)

{
  errno_t eVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_20;
  uint local_1c;
  int local_8;
  
  uVar4 = 0;
  local_8 = 0;
  eVar1 = __get_daylight(&local_8);
  if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  if (local_8 == 0) {
LAB_006dcedd:
    iVar2 = 0;
  }
  else {
    iVar2 = param_1->tm_year;
    if ((iVar2 != DAT_007670e8) || (iVar2 != DAT_007670f4)) {
      if (DAT_00769b60 == 0) {
        cvtdate(0,1,iVar2,(iVar2 < 0x6b) + 3,(0x6a < iVar2) + 1,0,0,2,0,0,0);
        cvtdate(1,1,param_1->tm_year,(0x6a < iVar2) + 10,(uint)(iVar2 < 0x6b) * 4 + 1,0,0,2,0,0,0);
      }
      else {
        if (DAT_00769c00 != 0) {
          local_1c = (uint)DAT_00769c06;
          uVar3 = 0;
          local_20 = 0;
        }
        else {
          local_20 = (uint)DAT_00769c04;
          uVar3 = (uint)DAT_00769c06;
          local_1c = 0;
        }
        cvtdate(0,(uint)(DAT_00769c00 == 0),iVar2,(uint)DAT_00769c02,uVar3,local_20,local_1c,
                (uint)DAT_00769c08,(uint)DAT_00769c0a,(uint)DAT_00769c0c,(uint)DAT_00769c0e);
        if (DAT_00769bac != 0) {
          uVar3 = 0;
          uVar6 = 0;
          uVar4 = (uint)DAT_00769bb2;
        }
        else {
          uVar3 = (uint)DAT_00769bb2;
          uVar6 = (uint)DAT_00769bb0;
        }
        cvtdate(1,(uint)(DAT_00769bac == 0),param_1->tm_year,(uint)DAT_00769bae,uVar3,uVar6,uVar4,
                (uint)DAT_00769bb4,(uint)DAT_00769bb6,(uint)DAT_00769bb8,(uint)DAT_00769bba);
      }
    }
    iVar2 = param_1->tm_yday;
    if (DAT_007670ec < DAT_007670f8) {
      if ((iVar2 < DAT_007670ec) || (DAT_007670f8 < iVar2)) goto LAB_006dcedd;
      if ((iVar2 <= DAT_007670ec) || (DAT_007670f8 <= iVar2)) {
LAB_006dceaf:
        iVar5 = ((param_1->tm_hour * 0x3c + param_1->tm_min) * 0x3c + param_1->tm_sec) * 1000;
        if (iVar2 == DAT_007670ec) {
          return (uint)(DAT_007670f0 <= iVar5);
        }
        return (uint)(iVar5 < DAT_007670fc);
      }
    }
    else if ((DAT_007670f8 <= iVar2) && (iVar2 <= DAT_007670ec)) {
      if ((iVar2 <= DAT_007670f8) || (DAT_007670ec <= iVar2)) goto LAB_006dceaf;
      goto LAB_006dcedd;
    }
    iVar2 = 1;
  }
  return iVar2;
}

