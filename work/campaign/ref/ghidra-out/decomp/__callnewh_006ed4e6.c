
/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2019 Release */

int __cdecl __callnewh(size_t _Size)

{
  code *pcVar1;
  int iVar2;
  
  pcVar1 = (code *)__query_new_handler();
  if (pcVar1 != (code *)0x0) {
    guard_check_icall(_Size);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}

