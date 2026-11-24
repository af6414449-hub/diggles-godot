
/* Library Function - Single Match
    public: int __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::process(void)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_stdio_output::
output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
::process(output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
          *this)

{
  output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
  oVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  
  bVar2 = __crt_strtox::c_string_character_source<char>::validate
                    ((c_string_character_source<char> *)(this + 0x448));
  if (bVar2) {
    if (*(int *)(this + 0x10) != 0) {
LAB_006d3336:
      do {
        *(int *)(this + 0x450) = *(int *)(this + 0x450) + 1;
        if (*(int *)(this + 0x450) == 2) {
          return *(int *)(this + 0x18);
        }
        *(undefined4 *)(this + 0x38) = 0;
        *(undefined4 *)(this + 0x1c) = 0;
LAB_006d3323:
        oVar1 = **(output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                   **)(this + 0x10);
        this[0x31] = oVar1;
        if (oVar1 != (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                      )0x0) {
          *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
          if (*(int *)(this + 0x18) < 0) goto LAB_006d3336;
          iVar5 = find_next_state(this[0x31],*(undefined4 *)(this + 0x1c));
          *(int *)(this + 0x1c) = iVar5;
          if (iVar5 == 8) break;
          switch(iVar5) {
          case 0:
            cVar3 = state_case_normal(this);
            break;
          case 1:
            *(undefined4 *)(this + 0x28) = 0xffffffff;
            *(undefined4 *)(this + 0x24) = 0;
            this[0x30] = (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                          )0x0;
            *(undefined4 *)(this + 0x20) = 0;
            *(undefined4 *)(this + 0x2c) = 0;
            this[0x3c] = (output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                          )0x0;
            goto LAB_006d3323;
          case 2:
            cVar3 = state_case_flag();
            break;
          case 3:
            cVar3 = state_case_width();
            break;
          case 4:
            goto switchD_006d32c6_caseD_4;
          case 5:
            cVar3 = state_case_precision();
            break;
          case 6:
            cVar3 = state_case_size();
            break;
          case 7:
            cVar3 = state_case_type(this);
            break;
          default:
            goto LAB_006d3290;
          }
          if (cVar3 == '\0') {
            return -1;
          }
          goto LAB_006d3323;
        }
        *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
      } while( true );
    }
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_006e510d();
  }
LAB_006d3290:
  return -1;
switchD_006d32c6_caseD_4:
  *(undefined4 *)(this + 0x28) = 0;
  goto LAB_006d3323;
}

