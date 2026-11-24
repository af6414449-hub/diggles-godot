
/* Library Function - Multiple Matches With Same Base Name
    int (__cdecl*__cdecl __crt_fast_encode_pointer<int (__cdecl*)(void)>(int
   (__cdecl*const)(void)))(void)
    void (__cdecl** __cdecl __crt_fast_encode_pointer<void (__cdecl**)(void)>(void (__cdecl**
   const)(void)))(void)
   
   Library: Visual Studio 2019 Release */

uint __crt_fast_encode_pointer<>(uint param_1)

{
  byte bVar1;
  
  bVar1 = 0x20 - ((byte)DAT_0076700c & 0x1f) & 0x1f;
  return (param_1 >> bVar1 | param_1 << 0x20 - bVar1) ^ DAT_0076700c;
}

