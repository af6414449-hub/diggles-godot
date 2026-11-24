
/* Library Function - Single Match
    unsigned int __cdecl __crt_mbstring::return_illegal_sequence(struct _Mbstatet *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl __crt_mbstring::return_illegal_sequence(_Mbstatet *param_1)

{
  int *piVar1;
  
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  piVar1 = __errno();
  *piVar1 = 0x2a;
  return 0xffffffff;
}

