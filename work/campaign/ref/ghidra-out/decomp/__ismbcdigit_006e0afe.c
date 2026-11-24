
/* Library Function - Single Match
    __ismbcdigit
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

int __cdecl __ismbcdigit(uint _Ch)

{
  int iVar1;
  
  iVar1 = __ismbcdigit_l(_Ch,(_locale_t)0x0);
  return iVar1;
}

