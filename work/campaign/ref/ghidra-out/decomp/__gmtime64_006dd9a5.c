
/* Library Function - Single Match
    __gmtime64
   
   Library: Visual Studio 2019 Release */

tm * __cdecl __gmtime64(__time64_t *_Time)

{
  tm *ptVar1;
  int iVar2;
  
  ptVar1 = ___getgmtimebuf();
  if (ptVar1 != (tm *)0x0) {
    iVar2 = common_gmtime_s<__int64>(ptVar1,_Time);
    ptVar1 = (tm *)(~-(uint)(iVar2 != 0) & (uint)ptVar1);
  }
  return ptVar1;
}

