
/* Library Function - Single Match
    __except_handler4
   
   Library: Visual Studio 2019 Release */

undefined4 __except_handler4(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  BOOL BVar5;
  undefined4 uVar6;
  int iVar7;
  int *local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  uint local_c;
  char local_5;
  
  local_5 = '\0';
  local_10 = 1;
  iVar3 = __filter_x86_sse2_floating_point_exception_default(*param_1);
  *param_1 = iVar3;
  iVar3 = param_2 + 0x10;
  local_c = *(uint *)(param_2 + 8) ^ DAT_0076700c;
  local_14 = iVar3;
  _ValidateLocalCookies(local_c,iVar3);
  ___except_validate_context_record(param_3);
  iVar7 = *(int *)(param_2 + 0xc);
  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {
    local_20 = param_1;
    local_1c = param_3;
    *(int ***)(param_2 + -4) = &local_20;
    if (iVar7 == -2) {
      return local_10;
    }
    do {
      iVar4 = iVar7 * 3 + 4;
      iVar1 = *(int *)(local_c + iVar4 * 4);
      local_18 = local_c + iVar4 * 4;
      if (*(int *)(local_18 + 4) != 0) {
        iVar4 = _EH4_CallFilterFunc(*(int *)(local_18 + 4),iVar3);
        local_5 = '\x01';
        if (iVar4 < 0) {
          local_10 = 0;
          goto LAB_006d00f4;
        }
        if (0 < iVar4) {
          if ((*param_1 == -0x1f928c9d) &&
             (BVar5 = __IsNonwritableInCurrentImage((PBYTE)&PTR____DestructExceptionObject_007157b8)
             , BVar5 != 0)) {
            guard_check_icall(param_1,1);
            ___DestructExceptionObject();
            iVar3 = local_14;
          }
          _EH4_GlobalUnwind2(param_2,param_1);
          if (*(int *)(param_2 + 0xc) != iVar7) {
            _EH4_LocalUnwind(param_2,iVar7,iVar3,&DAT_0076700c);
          }
          *(int *)(param_2 + 0xc) = iVar1;
          _ValidateLocalCookies(local_c,iVar3);
          _EH4_TransferToHandler(*(undefined4 *)(local_18 + 8),iVar3);
          pcVar2 = (code *)swi(3);
          uVar6 = (*pcVar2)();
          return uVar6;
        }
      }
      iVar7 = iVar1;
    } while (iVar1 != -2);
    if (local_5 == '\0') {
      return local_10;
    }
  }
  else {
    if (iVar7 == -2) {
      return local_10;
    }
    _EH4_LocalUnwind(param_2,0xfffffffe,iVar3,&DAT_0076700c);
  }
LAB_006d00f4:
  _ValidateLocalCookies(local_c,iVar3);
  return local_10;
}

