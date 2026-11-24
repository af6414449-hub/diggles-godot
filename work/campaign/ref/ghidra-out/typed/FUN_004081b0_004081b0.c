
undefined4 __thiscall FUN_004081b0(CActWalk_AutoRetry *this)

{
  undefined4 uVar1;
  
  if ((int *)this->i_20 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004081be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)this->i_20 + 8))();
    return uVar1;
  }
  this->i_08 = 1;
  return 1;
}

