
/* Library Function - Single Match
    void __cdecl tzset_from_system_nolock(void)
   
   Library: Visual Studio 2019 Release */

void __cdecl tzset_from_system_nolock(void)

{
  long lVar1;
  int *piVar2;
  errno_t eVar3;
  DWORD DVar4;
  UINT UVar5;
  int iVar6;
  long local_14;
  int local_10;
  int local_c;
  long local_8;
  
  piVar2 = (int *)FUN_006e9368();
  local_8 = 0;
  local_10 = 0;
  local_14 = 0;
  eVar3 = __get_timezone(&local_8);
  if (eVar3 == 0) {
    eVar3 = __get_daylight(&local_10);
    if (eVar3 == 0) {
      eVar3 = __get_dstbias(&local_14);
      if (eVar3 == 0) {
        FID_conflict__free(DAT_00769b58);
        DAT_00769b58 = (void *)0x0;
        DVar4 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00769b68);
        if (DVar4 != 0xffffffff) {
          local_8 = DAT_00769b68 * 0x3c;
          local_10 = 1;
          DAT_00769b60 = 1;
          if (DAT_00769bae != 0) {
            local_8 = DAT_00769bbc * 0x3c + local_8;
          }
          if ((DAT_00769c02 == 0) || (DAT_00769c10 == 0)) {
            local_14 = 0;
            local_10 = 0;
          }
          else {
            local_14 = (DAT_00769c10 - DAT_00769bbc) * 0x3c;
          }
          UVar5 = ____lc_codepage_func();
          iVar6 = ___acrt_WideCharToMultiByte
                            (UVar5,0,&DAT_00769b6c,0xffffffff,*piVar2,0x3f,0,&local_c);
          if ((iVar6 == 0) || (local_c != 0)) {
            *(undefined1 *)*piVar2 = 0;
          }
          else {
            *(undefined1 *)(*piVar2 + 0x3f) = 0;
          }
          iVar6 = ___acrt_WideCharToMultiByte
                            (UVar5,0,&DAT_00769bc0,0xffffffff,piVar2[1],0x3f,0,&local_c);
          if ((iVar6 == 0) || (local_c != 0)) {
            *(undefined1 *)piVar2[1] = 0;
          }
          else {
            *(undefined1 *)(piVar2[1] + 0x3f) = 0;
          }
        }
        lVar1 = local_8;
        piVar2 = (int *)FUN_006e9362();
        iVar6 = local_10;
        *piVar2 = lVar1;
        piVar2 = (int *)FUN_006e9356();
        lVar1 = local_14;
        *piVar2 = iVar6;
        piVar2 = (int *)FUN_006e935c();
        *piVar2 = lVar1;
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

