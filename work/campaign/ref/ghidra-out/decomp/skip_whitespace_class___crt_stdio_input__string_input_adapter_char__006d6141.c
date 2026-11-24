
/* Library Function - Single Match
    int __cdecl __crt_stdio_input::skip_whitespace<class
   __crt_stdio_input::string_input_adapter,char>(class __crt_stdio_input::string_input_adapter<char>
   &,struct __crt_locale_pointers * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
__crt_stdio_input::skip_whitespace<class___crt_stdio_input::string_input_adapter,char>
          (string_input_adapter<char> *param_1,__crt_locale_pointers *param_2)

{
  uint uVar1;
  int iVar2;
  
  do {
    uVar1 = string_input_adapter<char>::get(param_1);
    if (uVar1 == 0xffffffff) {
      return -1;
    }
    iVar2 = __ischartype_l(uVar1 & 0xff,8,param_2);
  } while (iVar2 != 0);
  return uVar1;
}

