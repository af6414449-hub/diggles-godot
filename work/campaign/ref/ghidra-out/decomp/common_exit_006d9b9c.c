
/* Library Function - Single Match
    void __cdecl common_exit(int,enum _crt_exit_cleanup_mode,enum _crt_exit_return_mode)
   
   Library: Visual Studio 2019 Release */

void __cdecl common_exit(int param_1,_crt_exit_cleanup_mode param_2,_crt_exit_return_mode param_3)

{
  code *pcVar1;
  char cVar2;
  _crt_exit_cleanup_mode *local_1c;
  _crt_exit_return_mode *local_18;
  undefined1 *local_14;
  undefined4 local_10;
  undefined4 local_c;
  __crt_seh_guarded_call<void> local_6;
  undefined1 local_5;
  
  if (param_3 == 0) {
    cVar2 = ___scrt_is_managed_app();
    if (cVar2 != '\0') {
      try_cor_exit_process(param_1);
    }
  }
  local_1c = &param_2;
  local_5 = 0;
  local_18 = &param_3;
  local_14 = &local_5;
  local_c = 2;
  local_10 = 2;
  __crt_seh_guarded_call<void>::
  operator()<class_<lambda_03b1d95aef87969028cfba75ccab2455>,class_<lambda_6e4b09c48022b2350581041d5f6b0c4c>&,class_<lambda_22bdf7517842c4b3e53723af5aa32b9e>_>
            (&local_6,(<lambda_03b1d95aef87969028cfba75ccab2455> *)&local_10,
             (<lambda_6e4b09c48022b2350581041d5f6b0c4c> *)&local_1c,
             (<lambda_22bdf7517842c4b3e53723af5aa32b9e> *)&local_c);
  if (param_3 != 0) {
    return;
  }
  exit_or_terminate_process(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

