
/* Library Function - Single Match
    ___vcrt_getptd
   
   Library: Visual Studio 2019 Release */

void ___vcrt_getptd(void)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  
  iVar2 = ___vcrt_getptd_noexit();
  if (iVar2 != 0) {
    return;
  }
  iVar2 = ___acrt_get_sigabrt_handler();
  if (iVar2 != 0) {
    _raise(0x16);
  }
  if ((DAT_00767210 & 2) != 0) {
    BVar3 = IsProcessorFeaturePresent(0x17);
    if (BVar3 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)();
    }
    ___acrt_call_reportfault(3,0x40000015,1);
  }
  __exit(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

