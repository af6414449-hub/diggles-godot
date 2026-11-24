
/* Library Function - Single Match
    _rand
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl _rand(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ___acrt_getptd();
  uVar2 = *(int *)(iVar1 + 0x18) * 0x343fd + 0x269ec3;
  *(uint *)(iVar1 + 0x18) = uVar2;
  return uVar2 >> 0x10 & 0x7fff;
}

