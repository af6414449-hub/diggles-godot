
void __thiscall FUN_0050a510(ViWinClickPicBox *this)

{
  undefined4 *puVar1;
  int *in_stack_00000004;
  undefined4 local_8;
  
  local_8 = 0;
  if (*(int *)(*in_stack_00000004 + 8) != 0) {
    FUN_004ff430(*in_stack_00000004 + 0xc,&local_8);
  }
  puVar1 = *(undefined4 **)&this[1].field_0x16;
  FUN_004ff900(puVar1,in_stack_00000004[2],in_stack_00000004[3],*puVar1,puVar1[1],0,0,1);
  return;
}

