
uint __thiscall FUN_005aff40(KNetSessionMgr *this)

{
  undefined1 *puVar1;
  uint uVar2;
  uint in_stack_00000004;
  
  puVar1 = &this[1].field_0x14;
  if (in_stack_00000004 < 8) {
    puVar1 = puVar1 + in_stack_00000004 * 0x60;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  uVar2 = FUN_005ae3b0(*(undefined4 *)(puVar1 + 8),"Hangup");
  return uVar2 & 0xffffff00;
}

