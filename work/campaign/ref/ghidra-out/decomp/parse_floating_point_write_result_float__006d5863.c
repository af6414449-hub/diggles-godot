
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point_write_result<float>(enum
   __crt_strtox::floating_point_parse_result,struct __crt_strtox::floating_point_string const
   &,float * const)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::parse_floating_point_write_result<float>
          (floating_point_parse_result param_1,floating_point_string *param_2,float *param_3)

{
  SLD_STATUS SVar1;
  float fVar2;
  
  switch(param_1) {
  case 0:
    SVar1 = convert_decimal_string_to_floating_type<float>(param_2,param_3);
    break;
  case 1:
    SVar1 = convert_hexadecimal_string_to_floating_type<float>(param_2,param_3);
    break;
  case 2:
    fVar2 = (float)(-(uint)(param_2[0x308] != (floating_point_string)0x0) & 0x80000000);
    goto LAB_006d58b2;
  case 3:
    fVar2 = (float)(((param_2[0x308] == (floating_point_string)0x0) - 1 & 0x80000000) + 0x7f800000 |
                   (uint)*param_3 & 0x7f800000);
    goto LAB_006d58e9;
  case 4:
    fVar2 = (float)(((param_2[0x308] == (floating_point_string)0x0) - 1 & 0x80000000) + 0x7fffffff);
LAB_006d58b2:
    *param_3 = fVar2;
LAB_006d58b7:
    SVar1 = 0;
    break;
  case 5:
    fVar2 = (float)(((param_2[0x308] == (floating_point_string)0x0) - 1 & 0x80000000) + 0x7f800000 |
                    (uint)*param_3 & 0x7f800000 | 1);
LAB_006d58e9:
    *param_3 = fVar2;
    goto LAB_006d58b7;
  case 6:
    *param_3 = -NAN;
    goto LAB_006d58b7;
  case 7:
    *param_3 = 0.0;
  default:
    SVar1 = 1;
    break;
  case 8:
    SVar1 = 2;
    *param_3 = (float)(-(uint)(param_2[0x308] != (floating_point_string)0x0) & 0x80000000);
    break;
  case 9:
    SVar1 = 3;
    *param_3 = (float)(((param_2[0x308] == (floating_point_string)0x0) - 1 & 0x80000000) +
                       0x7f800000 | (uint)*param_3 & 0x7f800000);
  }
  return SVar1;
}

