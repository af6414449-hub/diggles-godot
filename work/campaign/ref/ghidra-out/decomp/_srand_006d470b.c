
/* Library Function - Single Match
    _srand
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl _srand(uint _Seed)

{
  int iVar1;
  
  iVar1 = ___acrt_getptd();
  *(uint *)(iVar1 + 0x18) = _Seed;
  return;
}

