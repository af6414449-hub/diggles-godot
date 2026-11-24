
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10026a60(float *param_1,int param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  void *in_ECX;
  size_t sVar6;
  uint uVar7;
  int in_EDX;
  float *pfVar8;
  int iVar9;
  int local_431c;
  float *local_4310;
  size_t local_430c;
  float *local_4308;
  undefined1 *local_4304;
  int local_4300;
  uint local_42fc;
  undefined1 local_42f8 [2816];
  undefined1 local_37f8 [112];
  undefined1 local_3788 [16];
  float local_3778 [572];
  undefined1 local_2e88 [2464];
  undefined1 local_24e8 [8532];
  float local_394 [192];
  byte local_94;
  byte local_93;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  local_431c = 0;
  local_4310 = (float *)0x0;
  if ((((int)param_1 < 5) || (*(char *)((int)in_ECX + 0x1808) != -1)) ||
     (iVar3 = FUN_10021570(), iVar3 == 0)) {
LAB_10026b73:
    memset(in_ECX,0,0x1a0c);
    local_431c = FUN_100267d0((int)in_ECX + 0x1804,&local_4310);
    if ((local_4310 == (float *)0x0) || ((int)param_1 < (int)local_4310 + local_431c)) {
      *param_3 = local_431c;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    if ((*(byte *)(in_EDX + 2) & 2) == 0) {
      local_4308 = (float *)0x0;
    }
    else {
      local_430c = 4;
      local_4308 = (float *)1;
      if ((*(byte *)(in_EDX + 1) & 6) == 6) {
        local_4308 = (float *)4;
      }
    }
    iVar3 = FUN_10021630();
    local_4310 = (float *)((int)local_4308 + iVar3);
    if ((local_4310 != param_1) &&
       (((int)param_1 < (int)(local_4310 + 1) || (iVar3 = FUN_10021570(), iVar3 == 0)))) {
      local_4310 = (float *)0x0;
      goto LAB_10026b73;
    }
    if (local_4310 == (float *)0x0) goto LAB_10026b73;
  }
  local_4308 = (float *)(local_431c + in_EDX);
  *(float *)((int)in_ECX + 0x1808) = *local_4308;
  *param_3 = local_431c + (int)local_4310;
  param_3[1] = (((uint)*local_4308 & 0xc0000000) != 0xc0000000) + 1;
  param_3[2] = (*(uint *)(&DAT_1004590c + (*(byte *)((int)local_4308 + 2) >> 2 & 3) * 4) >>
               (~(*(byte *)((int)local_4308 + 1) >> 3) & 1)) >>
               (~(*(byte *)((int)local_4308 + 1) >> 4) & 1);
  sVar6 = 4 - (*(byte *)((int)local_4308 + 1) >> 1 & 3);
  param_3[3] = sVar6;
  param_3[4] = (uint)(byte)(&DAT_10046de9)
                           [(uint)(*(byte *)((int)local_4308 + 2) >> 4) +
                            ((*(byte *)((int)local_4308 + 1) >> 3 & 1) * 3 +
                            (*(byte *)((int)local_4308 + 1) >> 1 & 3)) * 0xf] * 2;
  pfVar8 = local_4308 + 1;
  iVar3 = (int)local_4310 * 8 + -0x20;
  local_430c = sVar6;
  if (((uint)*local_4308 & 0x100) == 0) {
    FUN_100214f0();
    sVar6 = param_3[3];
  }
  if (sVar6 != 3) {
    if (param_2 == 0) {
      if (((uint)*local_4308 & 0x600) == 0x600) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    FUN_100216f0(local_394);
    memset(local_3788,0,0x1200);
    local_4308 = local_394;
    iVar9 = 0;
    local_430c = 0;
    do {
      iVar4 = FUN_10021a60(local_394,param_3[3] | 1);
      pfVar8 = local_4308;
      iVar9 = iVar9 + iVar4;
      if (iVar9 == 0xc) {
        iVar9 = 0;
        uVar7 = (uint)local_94;
        iVar4 = (uint)local_93 * 0x48;
        memcpy(local_2e88 + iVar4,local_3788 + iVar4,(uVar7 - local_93) * 0x48);
        if (uVar7 != 0) {
          pfVar5 = local_3778;
          do {
            fVar1 = *pfVar8;
            fVar2 = pfVar8[3];
            pfVar8 = pfVar8 + 6;
            pfVar5[-4] = fVar1 * pfVar5[-4];
            pfVar5[-3] = fVar1 * pfVar5[-3];
            pfVar5[-2] = fVar1 * pfVar5[-2];
            pfVar5[-1] = fVar1 * pfVar5[-1];
            pfVar5[0x23c] = fVar2 * pfVar5[0x23c];
            pfVar5[0x23d] = fVar2 * pfVar5[0x23d];
            pfVar5[0x23e] = fVar2 * pfVar5[0x23e];
            pfVar5[0x23f] = fVar2 * pfVar5[0x23f];
            *pfVar5 = *pfVar5 * fVar1;
            pfVar5[1] = pfVar5[1] * fVar1;
            pfVar5[2] = pfVar5[2] * fVar1;
            pfVar5[3] = pfVar5[3] * fVar1;
            pfVar5[0x240] = fVar2 * pfVar5[0x240];
            pfVar5[0x241] = fVar2 * pfVar5[0x241];
            pfVar5[0x242] = fVar2 * pfVar5[0x242];
            pfVar5[0x243] = fVar2 * pfVar5[0x243];
            pfVar5[4] = fVar1 * pfVar5[4];
            pfVar5[0x244] = pfVar5[0x244] * fVar2;
            pfVar5[5] = fVar1 * pfVar5[5];
            pfVar5[0x245] = fVar2 * pfVar5[0x245];
            pfVar5[6] = fVar1 * pfVar5[6];
            pfVar5[7] = fVar1 * pfVar5[7];
            pfVar5[0x246] = pfVar5[0x246] * fVar2;
            pfVar5[0x247] = fVar2 * pfVar5[0x247];
            uVar7 = uVar7 - 1;
            pfVar5 = pfVar5 + 0x12;
          } while (uVar7 != 0);
        }
        FUN_100266f0(0xc,param_3[1],param_2,local_24e8);
        memset(local_3788,0,0x1200);
        param_2 = param_2 + param_3[1] * 0x600;
      }
      if (iVar3 < 0) goto LAB_100271f0;
      local_4308 = local_4308 + 1;
      local_430c = local_430c + 1;
    } while ((int)local_430c < 3);
    goto LAB_10027194;
  }
  local_4310 = (float *)FUN_10021c00(local_4308);
  if (((int)local_4310 < 0) || (iVar3 < 0)) {
LAB_100271f0:
    *(undefined1 *)((int)in_ECX + 0x1808) = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_430c = (int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3;
  pfVar5 = *(float **)((int)in_ECX + 0x1800);
  local_4308 = pfVar5;
  if ((int)local_4310 < (int)pfVar5) {
    local_4308 = local_4310;
  }
  iVar3 = (int)pfVar5 - (int)local_4310;
  if (iVar3 < 1) {
    iVar3 = 0;
  }
  memcpy(local_42f8,(void *)(iVar3 + 0x180c + (int)in_ECX),(size_t)local_4308);
  memcpy((undefined1 *)((int)local_4308 + (int)local_42f8),pfVar8,local_430c);
  local_4304 = local_42f8;
  local_42fc = (local_430c + (int)local_4308) * 8;
  local_4300 = 0;
  if (((int)local_4310 <= *(int *)((int)in_ECX + 0x1800)) && (param_2 != 0)) {
    iVar3 = param_3[1];
    local_430c = (int)in_ECX + 0x900;
    local_4308 = (float *)0x0;
    do {
      memset(local_3788,0,0x1200);
      FUN_10023da0(local_37f8 + iVar3 * (int)local_4308 * 0x1c,iVar3);
      FUN_100266f0(0x12,param_3[1],param_2,local_24e8);
      iVar3 = param_3[1];
      local_4308 = (float *)((int)local_4308 + 1);
      param_2 = param_2 + iVar3 * 0x900;
    } while ((int)local_4308 < (int)(((*(byte *)(in_EDX + 1 + local_431c) & 8) != 0) + 1));
  }
  uVar7 = local_4300 + 7U >> 3;
  sVar6 = (local_42fc >> 3) - uVar7;
  if ((int)sVar6 < 0x200) {
    if (0 < (int)sVar6) goto LAB_10026ee5;
  }
  else {
    uVar7 = (local_42fc >> 3) - 0x1ff;
    sVar6 = 0x1ff;
LAB_10026ee5:
    memcpy((void *)((int)in_ECX + 0x180c),local_42f8 + uVar7,sVar6);
  }
  *(size_t *)((int)in_ECX + 0x1800) = sVar6;
LAB_10027194:
  if ((*(byte *)((int)in_ECX + 0x1809) & 6) == 6) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

