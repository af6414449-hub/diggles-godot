
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::state_case_size(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::state_case_size(void)
   
   Library: Visual Studio 2019 Release */

bool state_case_size(void)

{
  output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
  oVar1;
  char cVar2;
  char *pcVar3;
  bool bVar4;
  int *piVar5;
  output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
  *in_ECX;
  undefined4 uStack_4;
  
  oVar1 = in_ECX[0x31];
  if (oVar1 == (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                )0x46) {
    if ((*(uint *)in_ECX & 8) == 0) {
      *(undefined4 *)(in_ECX + 0x1c) = 7;
      bVar4 = __crt_stdio_output::
              output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
              ::state_case_type(in_ECX);
      return bVar4;
    }
  }
  else if (oVar1 == (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                     )0x4e) {
    if ((*(uint *)in_ECX & 8) == 0) {
      *(undefined4 *)(in_ECX + 0x1c) = 8;
      goto LAB_006d36cd;
    }
  }
  else {
    if (*(int *)(in_ECX + 0x2c) != 0) {
LAB_006d36cd:
      piVar5 = __errno();
      *piVar5 = 0x16;
      FUN_006e510d();
      return false;
    }
    if ((char)oVar1 < 'k') {
      if (oVar1 == (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                    )0x6a) {
        *(undefined4 *)(in_ECX + 0x2c) = 5;
        return true;
      }
      if (oVar1 == (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                    )0x49) {
        pcVar3 = *(char **)(in_ECX + 0x10);
        cVar2 = *pcVar3;
        if ((cVar2 == '3') && (pcVar3[1] == '2')) {
          *(undefined4 *)(in_ECX + 0x2c) = 10;
          *(char **)(in_ECX + 0x10) = pcVar3 + 2;
          return true;
        }
        if ((cVar2 == '6') && (pcVar3[1] == '4')) {
          *(undefined4 *)(in_ECX + 0x2c) = 0xb;
          *(char **)(in_ECX + 0x10) = pcVar3 + 2;
          return true;
        }
        if ((((cVar2 != 'd') && (cVar2 != 'i')) && (cVar2 != 'o')) &&
           (((cVar2 != 'u' && (cVar2 != 'x')) && (cVar2 != 'X')))) {
          return true;
        }
        *(undefined4 *)(in_ECX + 0x2c) = 9;
        return true;
      }
      if (oVar1 == (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                    )0x4c) {
        *(undefined4 *)(in_ECX + 0x2c) = 8;
        return true;
      }
      if (oVar1 == (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                    )0x54) {
        *(undefined4 *)(in_ECX + 0x2c) = 0xd;
        return true;
      }
      if (oVar1 != (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                    )0x68) {
        return true;
      }
      if (**(char **)(in_ECX + 0x10) == 'h') {
        *(char **)(in_ECX + 0x10) = *(char **)(in_ECX + 0x10) + 1;
        uStack_4 = 1;
      }
      else {
        uStack_4 = 2;
      }
    }
    else {
      if (oVar1 != (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                    )0x6c) {
        if (oVar1 == (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                      )0x74) {
          *(undefined4 *)(in_ECX + 0x2c) = 7;
          return true;
        }
        if (oVar1 != (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                      )0x77) {
          if (oVar1 != (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                        )0x7a) {
            return true;
          }
          *(undefined4 *)(in_ECX + 0x2c) = 6;
          return true;
        }
        *(undefined4 *)(in_ECX + 0x2c) = 0xc;
        return true;
      }
      if (**(char **)(in_ECX + 0x10) == 'l') {
        *(char **)(in_ECX + 0x10) = *(char **)(in_ECX + 0x10) + 1;
        uStack_4 = 4;
      }
      else {
        uStack_4 = 3;
      }
    }
    *(undefined4 *)(in_ECX + 0x2c) = uStack_4;
  }
  return true;
}

