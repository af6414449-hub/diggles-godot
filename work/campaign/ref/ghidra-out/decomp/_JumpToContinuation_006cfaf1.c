
/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
                    /* WARNING: Load size is inaccurate */
  ExceptionList = *ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x006cfb1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)param_1)();
  return;
}

