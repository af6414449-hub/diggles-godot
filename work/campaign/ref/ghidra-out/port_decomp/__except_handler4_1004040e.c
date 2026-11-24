
/* Library Function - Single Match
    __except_handler4
   
   Library: Visual Studio 2019 Release */

void __except_handler4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = __filter_x86_sse2_floating_point_exception_default(*param_1);
  *param_1 = uVar1;
  except_handler4_common(&DAT_1005000c,__security_check_cookie,param_1,param_2,param_3,param_4);
  return;
}

