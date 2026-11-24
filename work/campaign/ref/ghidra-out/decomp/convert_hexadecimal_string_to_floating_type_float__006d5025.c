
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::convert_hexadecimal_string_to_floating_type<float>(struct
   __crt_strtox::floating_point_string const &,float &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::convert_hexadecimal_string_to_floating_type<float>
          (floating_point_string *param_1,float *param_2)

{
  SLD_STATUS SVar1;
  float *local_c;
  undefined4 local_8;
  
  local_c = param_2;
  local_8 = 0;
  SVar1 = convert_hexadecimal_string_to_floating_type_common
                    (param_1,(floating_point_value *)&local_c);
  return SVar1;
}

