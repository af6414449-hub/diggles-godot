
/* Library Function - Single Match
    void __cdecl BuildCatchObjectInternal<class __FrameHandler3>(struct EHExceptionRecord *,void
   *,struct _s_HandlerType const *,struct _s_CatchableType const *)
   
   Library: Visual Studio 2019 Release */

void __cdecl
BuildCatchObjectInternal<class___FrameHandler3>
          (EHExceptionRecord *param_1,void *param_2,_s_HandlerType *param_3,
          _s_CatchableType *param_4)

{
  _s_HandlerType *p_Var1;
  _s_CatchableType *p_Var2;
  EHExceptionRecord *pEVar3;
  int iVar4;
  void *pvVar5;
  int unaff_EBP;
  void *pvVar6;
  
  FUN_006cf3b0(&DAT_007631f0,8);
  p_Var1 = *(_s_HandlerType **)(unaff_EBP + 0x10);
  pvVar5 = *(void **)(unaff_EBP + 0xc);
  pvVar6 = pvVar5;
  if (-1 < (int)p_Var1->adjectives) {
    pvVar6 = (void *)((int)pvVar5 + p_Var1->dispCatchObj + 0xc);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  p_Var2 = *(_s_CatchableType **)(unaff_EBP + 0x14);
  pEVar3 = *(EHExceptionRecord **)(unaff_EBP + 8);
  iVar4 = BuildCatchObjectHelperInternal<class___FrameHandler3>(pEVar3,pvVar5,p_Var1,p_Var2);
  if (iVar4 == 1) {
    pvVar5 = (void *)___AdjustPointer(*(undefined4 *)(pEVar3 + 0x18),p_Var2 + 8);
    _CallMemberFunction1(pvVar6,*(void **)(p_Var2 + 0x18),pvVar5);
  }
  else if (iVar4 == 2) {
    pvVar5 = (void *)___AdjustPointer(*(undefined4 *)(pEVar3 + 0x18),p_Var2 + 8);
    _CallMemberFunction2(pvVar6,*(void **)(p_Var2 + 0x18),pvVar5,1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

