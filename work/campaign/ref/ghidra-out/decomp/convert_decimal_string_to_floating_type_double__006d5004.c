
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::convert_decimal_string_to_floating_type<double>(struct
   __crt_strtox::floating_point_string const &,double &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::convert_decimal_string_to_floating_type<double>
          (floating_point_string *param_1,double *param_2)

{
  SLD_STATUS SVar1;
  undefined4 in_ECX;
  double *local_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_c = param_2;
  _local_8 = CONCAT31((int3)((uint)in_ECX >> 8),1);
  SVar1 = convert_decimal_string_to_floating_type_common(param_1,(floating_point_value *)&local_c);
  return SVar1;
}

