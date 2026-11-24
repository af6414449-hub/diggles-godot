
undefined4 FUN_004081b0(void)

{
  undefined4 uVar1;
  int this;
  
  if (*(int **)(this + 0x20) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004081be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(this + 0x20) + 8))();
    return uVar1;
  }
  this->i_08 = 1;
  return 1;
}

