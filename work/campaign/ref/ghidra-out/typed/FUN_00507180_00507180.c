
undefined1 __thiscall FUN_00507180(ViWinBigInfo *this)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  ViWinBigInfo *pVVar4;
  undefined1 uVar5;
  undefined4 *in_stack_00000004;
  int local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00700db5;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar3 = in_stack_00000004[2];
  if ((iVar3 != DAT_007723cc) && (iVar3 != DAT_007723d0)) {
    if ((iVar3 != DAT_00772388) || (in_stack_00000004[6] != this->i_64)) {
      piVar1 = in_stack_00000004 + 1;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      local_8 = 1;
      if (in_stack_00000004[2] == DAT_007723e8) {
        pVVar4 = (ViWinBigInfo *)in_stack_00000004[6];
        if ((pVVar4 == (ViWinBigInfo *)this->i_50) || (pVVar4 == (ViWinBigInfo *)this->i_4c)) {
          FUN_005340b0();
          FUN_00533bb0();
          pVVar4 = (ViWinBigInfo *)in_stack_00000004[6];
        }
        if (pVVar4 == this) {
          FUN_00533d10();
        }
      }
      else {
        if (in_stack_00000004[2] != DAT_007723ac) {
LAB_005072f7:
          if (in_stack_00000004 != (undefined4 *)0x0) {
            LOCK();
            iVar3 = *piVar1;
            *piVar1 = iVar3 + -1;
            UNLOCK();
            if (iVar3 + -1 == 0) {
              (**(code **)*in_stack_00000004)(1,uVar2);
            }
          }
          uVar5 = 0;
          goto LAB_0050720c;
        }
        iVar3 = this->i_44;
        if ((in_stack_00000004[6] == iVar3) && (iVar3 != 0)) {
          local_1c = -*(int *)(iVar3 + 100);
          local_18 = *(int *)(this->i_50 + 0x10);
          FUN_00504a70(&local_1c);
        }
        else {
          iVar3 = this->i_48;
          if ((in_stack_00000004[6] != iVar3) || (iVar3 == 0)) goto LAB_005072f7;
          local_1c = *(int *)(this->i_50 + 0xc);
          local_18 = -*(int *)(iVar3 + 0x68);
          FUN_00504a70(&local_1c);
        }
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar3 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
      uVar5 = 1;
      goto LAB_0050720c;
    }
    iVar3 = FUN_00501450();
    *(undefined4 *)(iVar3 + 0x81a0) = 0;
    if (this->c_1c != '\0') {
      FUN_00504ee0();
      this->c_1c = '\0';
    }
    FUN_006b9200(&PTR_0071ce50);
  }
  uVar5 = 1;
LAB_0050720c:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = in_stack_00000004 + 1;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar3 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar5;
}

