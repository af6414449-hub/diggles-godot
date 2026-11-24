
/* public: void __thiscall ScreenResolutionManager::Update(void) */

void __thiscall ScreenResolutionManager::Update(ScreenResolutionManager *this)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  undefined4 in_EDX;
  undefined1 local_34 [16];
  void *local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
                    /* 0x12740  273  ?Update@ScreenResolutionManager@@QAEXXZ */
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_10042607;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffff0);
  piVar7 = DAT_10050c64;
  uVar8 = *(uint *)(this + 8);
  if (*(uint *)(this + 0xc) != uVar8) {
    this[0x1d] = (ScreenResolutionManager)0x1;
    *(uint *)(this + 0xc) = uVar8;
    if (piVar7 == (int *)0x0) {
      local_24 = (void *)FUN_1003ff62(0xcbc);
      local_14 = 0;
      memset(local_24,0,0xcbc);
      piVar7 = (int *)FUN_1000e160();
      local_14 = 0xffffffff;
      uVar8 = *(uint *)(this + 0xc);
      DAT_10050c64 = piVar7;
    }
    iVar2 = *piVar7;
    if (((int)uVar8 < 0) || (*(uint *)(iVar2 + 0x8c) <= uVar8)) {
      FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_34,(ThrowInfo *)&DAT_1004a24c);
    }
    if (uVar8 != *(uint *)(iVar2 + 0xb0)) {
      *(uint *)(iVar2 + 0xb0) = uVar8;
      iVar3 = *(int *)(iVar2 + 0x90);
      puVar1 = (undefined4 *)(iVar3 + uVar8 * 0x1c);
      uVar4 = puVar1[1];
      uVar5 = puVar1[2];
      uVar6 = puVar1[3];
      *(undefined4 *)(iVar2 + 0x94) = *puVar1;
      *(undefined4 *)(iVar2 + 0x98) = uVar4;
      *(undefined4 *)(iVar2 + 0x9c) = uVar5;
      *(undefined4 *)(iVar2 + 0xa0) = uVar6;
      *(undefined8 *)(iVar2 + 0xa4) = *(undefined8 *)(iVar3 + 0x10 + uVar8 * 0x1c);
      *(undefined4 *)(iVar2 + 0xac) = *(undefined4 *)(iVar3 + 0x18 + uVar8 * 0x1c);
    }
  }
  ExceptionList = local_1c;
  return;
}

