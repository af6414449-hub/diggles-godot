
/* Library Function - Single Match
    ___acrt_AppPolicyGetThreadInitializationTypeInternal@4
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_AppPolicyGetThreadInitializationTypeInternal_4(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (code *)try_get_function(0x1d,"AppPolicyGetThreadInitializationType",
                                    (module_id *)&DAT_00718118,
                                    (module_id *)"AppPolicyGetThreadInitializationType");
  if (pcVar1 == (code *)0x0) {
    uVar2 = 0xc0000225;
  }
  else {
    guard_check_icall(0xfffffffa,param_1);
    uVar2 = (*pcVar1)();
  }
  return uVar2;
}

