
/* Library Function - Single Match
    _unexpected
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl unexpected(void)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = ___vcrt_getptd();
  pcVar1 = *(code **)(iVar2 + 4);
  if (pcVar1 != (code *)0x0) {
    guard_check_icall();
    (*pcVar1)();
  }
  terminate();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

