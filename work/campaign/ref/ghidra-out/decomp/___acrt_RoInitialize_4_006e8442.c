
/* Library Function - Single Match
    ___acrt_RoInitialize@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___acrt_RoInitialize_4(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (code *)try_get_function(0x1a,"RoInitialize",(module_id *)&DAT_007180c4,
                                    (module_id *)"RoInitialize");
  if (pcVar1 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    guard_check_icall(param_1);
    uVar2 = (*pcVar1)();
  }
  return uVar2;
}

