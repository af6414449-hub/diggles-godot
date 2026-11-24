
/* Library Function - Single Match
    public: static struct std::pair<class __FrameHandler3::TryBlockMap::iterator,class
   __FrameHandler3::TryBlockMap::iterator> __cdecl __FrameHandler3::GetRangeOfTrysToCheck(class
   __FrameHandler3::TryBlockMap &,int,void *,struct _s_FuncInfo const *,int)
   
   Library: Visual Studio 2019 Release */

void __cdecl
__FrameHandler3::GetRangeOfTrysToCheck
          (TryBlockMap *param_1,int param_2,void *param_3,_s_FuncInfo *param_4,int param_5)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int in_stack_00000018;
  uint local_8;
  
  uVar1 = *(uint *)(param_5 + 0xc);
  uVar3 = uVar1;
  uVar4 = uVar1;
  if (-1 < in_stack_00000018) {
    piVar2 = (int *)(uVar1 * 0x14 + *(int *)(param_5 + 0x10) + 8);
    local_8 = uVar1;
    do {
      if (uVar3 == 0xffffffff) goto LAB_006cf9a7;
      uVar3 = uVar3 - 1;
      if (((piVar2[-6] < (int)param_3) && ((int)param_3 <= piVar2[-5])) || (uVar3 == 0xffffffff)) {
        in_stack_00000018 = in_stack_00000018 + -1;
        uVar4 = local_8;
        local_8 = uVar3;
      }
      piVar2 = piVar2 + -5;
    } while (-1 < in_stack_00000018);
  }
  if ((uVar4 <= uVar1) && (uVar3 + 1 <= uVar4)) {
    *(uint *)(param_1 + 0xc) = uVar4;
    *(int *)param_1 = param_2;
    *(uint *)(param_1 + 4) = uVar3 + 1;
    *(int *)(param_1 + 8) = param_2;
    return;
  }
LAB_006cf9a7:
                    /* WARNING: Subroutine does not return */
  _abort();
}

