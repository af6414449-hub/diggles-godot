
undefined4 __thiscall FUN_004081d0(CActWalk_AutoRetry *this)

{
  undefined4 uVar1;
  
  if ((int *)this->i_20 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004081dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)this->i_20 + 4))();
    return uVar1;
  }
  return 1;
}

