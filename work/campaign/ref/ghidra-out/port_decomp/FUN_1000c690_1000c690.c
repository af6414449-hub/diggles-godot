
void FUN_1000c690(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *in_ECX;
  uint uVar5;
  uint *in_EDX;
  uint *puVar6;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b79);
  if (in_ECX != in_EDX) {
    puVar6 = in_ECX + 6;
    do {
      FUN_1000aec0();
      uVar2 = *puVar6;
      if (0xf < uVar2) {
        uVar3 = puVar6[-5];
        uVar5 = uVar2 + 1;
        uVar4 = uVar3;
        if (0xfff < uVar5) {
          uVar4 = *(uint *)(uVar3 - 4);
          uVar5 = uVar2 + 0x24;
          if (0x1f < (uVar3 - uVar4) - 4) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_100402ac(uVar4,uVar5);
      }
      puVar6[-1] = 0;
      *puVar6 = 0xf;
      *(undefined1 *)(puVar6 + -5) = 0;
      puVar1 = puVar6 + 4;
      puVar6 = puVar6 + 10;
    } while (puVar1 != in_EDX);
  }
  return;
}

