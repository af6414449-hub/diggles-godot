
void FUN_10042e80(void)

{
  uint *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10042780;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_1001ab50(DAT_1005000c ^ (uint)&stack0xfffffffc);
  FUN_1001aff0();
  uVar2 = 0;
  do {
    if (*(int **)((int)&DAT_100521d8 + uVar2) != (int *)0x0) {
      (**(code **)(**(int **)((int)&DAT_100521d8 + uVar2) + 0x20))(1);
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x20);
  uVar2 = 0;
  if (DAT_1006ceb0 != 0) {
    do {
      free(*(void **)((int)DAT_1006ceac + uVar2 * 4));
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_1006ceb0);
  }
  free(DAT_1006ceac);
  if (DAT_10051148 != (void *)0x0) {
    puVar1 = (uint *)((int)DAT_10051148 + -4);
    local_8 = CONCAT31(local_8._1_3_,1);
    _eh_vector_destructor_iterator_(DAT_10051148,0xc,*puVar1,FUN_1001acb0);
    FUN_100402e2(puVar1,*puVar1 * 0xc + 4);
  }
  free(DAT_1005114c);
  free(DAT_10051140);
  free(DAT_1005112c);
  ExceptionList = local_10;
  return;
}

