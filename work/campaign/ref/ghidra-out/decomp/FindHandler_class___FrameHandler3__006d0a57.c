
/* Library Function - Single Match
    void __cdecl FindHandler<class __FrameHandler3>(struct EHExceptionRecord *,struct
   EHRegistrationNode *,struct _CONTEXT *,void *,struct _s_FuncInfo const *,unsigned char,int,struct
   EHRegistrationNode *)
   
   Library: Visual Studio 2019 Release */

void __cdecl
FindHandler<class___FrameHandler3>
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  void *pvVar1;
  uchar uVar2;
  bool bVar3;
  int iVar4;
  _s_ESTypeList *p_Var5;
  _s_FuncInfo *p_Var6;
  int iVar7;
  __ehstate_t *p_Var8;
  _s_TryBlockMapEntry *p_Var9;
  int *piVar10;
  _s_TryBlockMapEntry local_6c;
  _s_HandlerType local_58;
  int *local_48;
  _s_FuncInfo *local_44 [2];
  _s_FuncInfo *local_3c;
  _s_FuncInfo *local_38;
  undefined4 local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  int local_24;
  uint local_20;
  HandlerType *local_1c;
  int local_18;
  _s_FuncInfo *local_14;
  void *local_10;
  _CONTEXT *local_c;
  char local_5;
  
  local_20 = local_20 & 0xffffff00;
  local_5 = '\0';
  local_10 = (void *)__FrameHandler3::GetCurrentState(param_2,param_4,param_5);
  if (((int)local_10 < -1) || (param_5->maxState <= (int)local_10)) goto LAB_006d0e07;
  if (((*(int *)param_1 != -0x1f928c9d) || (*(int *)(param_1 + 0x10) != 3)) ||
     ((((*(int *)(param_1 + 0x14) != 0x19930520 && (*(int *)(param_1 + 0x14) != 0x19930521)) &&
       (*(int *)(param_1 + 0x14) != 0x19930522)) || (iVar7 = 0, *(int *)(param_1 + 0x1c) != 0)))) {
    local_c = param_3;
    goto LAB_006d0baa;
  }
  iVar4 = ___vcrt_getptd();
  if (*(int *)(iVar4 + 0x10) == 0) {
    return;
  }
  iVar4 = ___vcrt_getptd();
  param_1 = *(EHExceptionRecord **)(iVar4 + 0x10);
  iVar4 = ___vcrt_getptd();
  local_20 = CONCAT31(local_20._1_3_,1);
  local_c = *(_CONTEXT **)(iVar4 + 0x14);
  if ((param_1 == (EHExceptionRecord *)0x0) ||
     ((((*(int *)param_1 == -0x1f928c9d && (*(int *)(param_1 + 0x10) == 3)) &&
       ((*(int *)(param_1 + 0x14) == 0x19930520 ||
        ((*(int *)(param_1 + 0x14) == 0x19930521 || (*(int *)(param_1 + 0x14) == 0x19930522)))))) &&
      (*(int *)(param_1 + 0x1c) == 0)))) goto LAB_006d0e07;
  iVar4 = ___vcrt_getptd();
  if (*(int *)(iVar4 + 0x1c) == 0) {
LAB_006d0baa:
    local_38 = param_5;
    local_34 = 0;
    if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
       ((*(int *)(param_1 + 0x14) == 0x19930520 ||
        ((*(int *)(param_1 + 0x14) == 0x19930521 || (*(int *)(param_1 + 0x14) == 0x19930522)))))) {
      if (param_5->nTryBlocks != 0) {
        __FrameHandler3::GetRangeOfTrysToCheck
                  ((TryBlockMap *)&local_48,(int)&local_38,local_10,(_s_FuncInfo *)param_4,
                   (int)param_5);
        local_30 = local_48;
        local_14 = local_44[0];
        if (local_44[0] < local_3c) {
          local_24 = (int)local_44[0] * 0x14;
          p_Var6 = local_44[0];
          do {
            pvVar1 = local_10;
            p_Var8 = (__ehstate_t *)(*(int *)(*local_30 + 0x10) + local_24);
            p_Var9 = &local_6c;
            local_14 = p_Var6;
            for (iVar7 = 5; iVar7 != 0; iVar7 = iVar7 + -1) {
              p_Var9->tryLow = *p_Var8;
              p_Var8 = p_Var8 + 1;
              p_Var9 = (_s_TryBlockMapEntry *)&p_Var9->tryHigh;
            }
            if (((local_6c.tryLow <= (int)pvVar1) && ((int)pvVar1 <= local_6c.tryHigh)) &&
               (local_18 = 0, local_6c.nCatches != 0)) {
              iVar7 = **(int **)(*(int *)(param_1 + 0x1c) + 0xc);
              local_28 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc) + 1;
              local_1c = local_6c.pHandlerArray;
              local_2c = iVar7;
              do {
                local_58.adjectives = local_1c->adjectives;
                local_58.pType = local_1c->pType;
                local_58.dispCatchObj = local_1c->dispCatchObj;
                local_58.addressOfHandler = local_1c->addressOfHandler;
                iVar4 = iVar7;
                piVar10 = local_28;
                p_Var6 = local_14;
                for (; local_14 = p_Var6, 0 < iVar4; iVar4 = iVar4 + -1) {
                  iVar7 = TypeMatchHelper<class___FrameHandler3>
                                    (&local_58,(_s_CatchableType *)*piVar10,
                                     *(_s_ThrowInfo **)(param_1 + 0x1c));
                  if (iVar7 != 0) {
                    local_5 = '\x01';
                    CatchIt<class___FrameHandler3>
                              (param_1,param_2,local_c,param_4,param_5,&local_58,
                               (_s_CatchableType *)*piVar10,&local_6c,param_7,param_8,
                               (uchar)local_20,param_6);
                    p_Var6 = local_14;
                    goto LAB_006d0ce5;
                  }
                  piVar10 = piVar10 + 1;
                  iVar7 = local_2c;
                  p_Var6 = local_14;
                }
                local_18 = local_18 + 1;
                local_1c = local_1c + 1;
              } while (local_18 != local_6c.nCatches);
            }
LAB_006d0ce5:
            p_Var6 = (_s_FuncInfo *)((int)&p_Var6->magicNumber_and_bbtFlags + 1);
            local_24 = local_24 + 0x14;
            local_14 = p_Var6;
          } while (p_Var6 < local_3c);
        }
      }
      if (param_6 != '\0') {
        ___DestructExceptionObject(param_1,1);
      }
      if (((local_5 == '\0') && (0x19930520 < (param_5->magicNumber_and_bbtFlags & 0x1fffffff))) &&
         ((param_5->pESTypeList != (ESTypeList *)0x0 ||
          ((((uint)param_5->EHFlags >> 2 & 1) != 0 && (param_7 == 0)))))) {
        if (((uint)param_5->EHFlags >> 2 & 1) != 0) {
          iVar7 = ___vcrt_getptd();
          *(EHExceptionRecord **)(iVar7 + 0x10) = param_1;
          iVar7 = ___vcrt_getptd();
          *(_CONTEXT **)(iVar7 + 0x14) = local_c;
          goto LAB_006d0da3;
        }
        uVar2 = IsInExceptionSpec(param_1,param_5->pESTypeList);
        if (uVar2 == '\0') goto LAB_006d0dc8;
      }
    }
    else if (param_5->nTryBlocks != 0) {
      if (param_6 != '\0') goto LAB_006d0e07;
      FindHandlerForForeignException<class___FrameHandler3>
                (param_1,param_2,local_c,param_4,param_5,(int)local_10,param_7,param_8);
    }
    iVar7 = ___vcrt_getptd();
    if (*(int *)(iVar7 + 0x1c) == 0) {
      return;
    }
  }
  else {
    iVar4 = ___vcrt_getptd();
    local_14 = *(_s_FuncInfo **)(iVar4 + 0x1c);
    iVar4 = ___vcrt_getptd();
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    uVar2 = IsInExceptionSpec(param_1,(_s_ESTypeList *)local_14);
    p_Var6 = local_14;
    if (uVar2 != '\0') goto LAB_006d0baa;
    param_5 = p_Var6;
    if (0 < (int)local_14->magicNumber_and_bbtFlags) {
      local_14 = (_s_FuncInfo *)0x0;
      do {
        bVar3 = type_info::operator==
                          (*(type_info **)((int)&local_14->maxState + p_Var6->maxState),
                           (type_info *)&std::bad_exception::RTTI_Type_Descriptor);
        if (bVar3) goto LAB_006d0da8;
        iVar7 = iVar7 + 1;
        local_14 = (_s_FuncInfo *)&local_14->pTryBlockMap;
      } while (iVar7 < (int)p_Var6->magicNumber_and_bbtFlags);
    }
LAB_006d0da3:
    terminate();
LAB_006d0da8:
    ___DestructExceptionObject(param_1,1);
    std::bad_exception::bad_exception((bad_exception *)local_44);
    __CxxThrowException_8(local_44,&DAT_0076320c);
LAB_006d0dc8:
    iVar7 = ___vcrt_getptd();
    *(EHExceptionRecord **)(iVar7 + 0x10) = param_1;
    iVar7 = ___vcrt_getptd();
    *(_CONTEXT **)(iVar7 + 0x14) = local_c;
    if (param_8 == (EHRegistrationNode *)0x0) {
      param_8 = param_2;
    }
    _UnwindNestedFrames(param_8,param_1);
    __FrameHandler3::FrameUnwindToEmptyState(param_2,param_4,param_5);
    p_Var5 = __FrameHandler3::getESTypes(param_5);
    FUN_006d1353(p_Var5);
  }
LAB_006d0e07:
                    /* WARNING: Subroutine does not return */
  _abort();
}

