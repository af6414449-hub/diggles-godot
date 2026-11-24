
void FUN_10035570(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 uint *param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *in_ECX;
  code *in_EDX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_10;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  iVar4 = 0;
  uVar6 = 0x2a;
  local_c4 = 0;
  local_c8 = 0;
  local_c0 = 0;
  do {
    iVar3 = (*in_ECX)(param_2,&local_10,4);
    uVar2 = local_10;
    if (iVar3 != 4) {
LAB_10035664:
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    uVar1 = local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 | (local_10 & 0xff00) << 8;
    uVar7 = uVar6 + 4;
    uVar5 = iVar4 + (uint)(0xfffffffb < uVar6);
    switch(local_10 & 0x7f) {
    default:
      goto switchD_10035658_caseD_1;
    case 2:
      if (uVar1 < 4) goto LAB_10035664;
      break;
    case 3:
      local_c8 = uVar1;
      local_c4 = uVar5;
      local_c0 = uVar7;
      goto switchD_10035658_caseD_1;
    case 4:
      if (uVar1 < 8) goto LAB_10035664;
      break;
    case 5:
      if (uVar1 < 0x18c) goto LAB_10035664;
      break;
    case 6:
      if (uVar1 < 0x20) goto LAB_10035664;
switchD_10035658_caseD_1:
      if (uVar1 != 0) break;
      goto LAB_100356c6;
    }
    iVar4 = (*in_EDX)(param_2,uVar1,1);
    if (iVar4 == 0) {
      iVar4 = uVar5 + CARRY4(uVar1,uVar7);
      goto LAB_100356ea;
    }
LAB_100356c6:
    uVar6 = uVar7 + uVar1;
    iVar4 = uVar5 + CARRY4(uVar7,uVar1);
    if ((char)uVar2 < '\0') {
LAB_100356ea:
      *param_5 = local_c0;
      param_5[1] = local_c4;
      *param_6 = local_c8;
      *param_4 = uVar7 + uVar1;
      param_4[1] = iVar4;
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

