
/* Library Function - Single Match
    public: static void __cdecl __FrameHandler3::FrameUnwindToState(struct EHRegistrationNode *,void
   *,struct _s_FuncInfo const *,int)
   
   Library: Visual Studio 2019 Release */

void __cdecl
__FrameHandler3::FrameUnwindToState
          (EHRegistrationNode *param_1,void *param_2,_s_FuncInfo *param_3,int param_4)

{
  _s_FuncInfo *p_Var1;
  UnwindMapEntry *pUVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763128,0x10);
  iVar3 = GetCurrentState(*(EHRegistrationNode **)(unaff_EBP + 8),*(void **)(unaff_EBP + 0xc),
                          *(_s_FuncInfo **)(unaff_EBP + 0x10));
  *(int *)(unaff_EBP + -0x1c) = iVar3;
  iVar4 = ___vcrt_getptd();
  *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (iVar3 != *(int *)(unaff_EBP + 0x14)) {
    if ((iVar3 < 0) || (p_Var1 = *(_s_FuncInfo **)(unaff_EBP + 0x10), p_Var1->maxState <= iVar3))
    goto LAB_006d14d6;
    pUVar2 = p_Var1->pUnwindMap;
    iVar4 = pUVar2[iVar3].toState;
    *(int *)(unaff_EBP + -0x20) = iVar4;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pUVar2[iVar3].action != (action *)0x0) {
      SetState(*(EHRegistrationNode **)(unaff_EBP + 8),p_Var1,iVar4);
      __CallSettingFrame_12(p_Var1->pUnwindMap[iVar3].action,*(undefined4 *)(unaff_EBP + 8),0x103);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar3 = *(int *)(unaff_EBP + -0x20);
    *(int *)(unaff_EBP + -0x1c) = iVar3;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006d14c2();
  if (iVar3 == *(int *)(unaff_EBP + 0x14)) {
    SetState(*(EHRegistrationNode **)(unaff_EBP + 8),*(_s_FuncInfo **)(unaff_EBP + 0x10),iVar3);
    ExceptionList = *(void **)(unaff_EBP + -0x10);
    return;
  }
LAB_006d14d6:
                    /* WARNING: Subroutine does not return */
  _abort();
}

