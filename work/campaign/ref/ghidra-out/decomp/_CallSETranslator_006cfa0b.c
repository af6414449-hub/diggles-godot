
/* Library Function - Single Match
    int __cdecl _CallSETranslator(struct EHExceptionRecord *,struct EHRegistrationNode *,void *,void
   *,struct _s_FuncInfo const *,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2019 Release */

int __cdecl
_CallSETranslator(EHExceptionRecord *param_1,EHRegistrationNode *param_2,void *param_3,void *param_4
                 ,_s_FuncInfo *param_5,int param_6,EHRegistrationNode *param_7)

{
  int iVar1;
  undefined4 *local_44;
  code *local_40;
  uint local_3c;
  _s_FuncInfo *local_38;
  EHRegistrationNode *local_34;
  int local_30;
  EHRegistrationNode *local_2c;
  undefined1 *local_28;
  undefined1 *local_24;
  int local_20;
  EHExceptionRecord *local_1c;
  void *local_18;
  code *local_14;
  code *local_10;
  int local_c;
  code *local_8;
  
  local_24 = &stack0xfffffffc;
  local_28 = &stack0xffffffb8;
  if (param_1 == (EHExceptionRecord *)0x123) {
    *(undefined4 *)param_2 = 0x6cfac5;
    local_c = 1;
  }
  else {
    local_40 = __TranslatorGuardHandler;
    local_3c = DAT_0076700c ^ (uint)&local_44;
    local_38 = param_5;
    local_34 = param_2;
    local_30 = param_6;
    local_2c = param_7;
    local_20 = 0;
    local_44 = (undefined4 *)ExceptionList;
    ExceptionList = &local_44;
    local_c = 1;
    local_1c = param_1;
    local_18 = param_3;
    iVar1 = ___vcrt_getptd();
    local_8 = *(code **)(iVar1 + 8);
    local_10 = guard_check_icall;
    guard_check_icall();
    local_14 = local_8;
    (*local_8)(*(undefined4 *)param_1,&local_1c);
    local_c = 0;
    if (local_20 != 0) {
                    /* WARNING: Load size is inaccurate */
      *local_44 = *ExceptionList;
    }
    ExceptionList = local_44;
  }
  return local_c;
}

