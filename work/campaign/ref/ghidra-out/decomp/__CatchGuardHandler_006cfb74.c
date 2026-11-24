
/* Library Function - Single Match
    __CatchGuardHandler
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __CatchGuardHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3)

{
  __security_check_cookie(*(uint *)(param_2 + 8) ^ (uint)param_2);
  __InternalCxxFrameHandler<class___FrameHandler3>
            (param_1,*(EHRegistrationNode **)(param_2 + 0x10),param_3,(void *)0x0,
             *(_s_FuncInfo **)(param_2 + 0xc),*(int *)(param_2 + 0x14),param_2,'\0');
  return;
}

