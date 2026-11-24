
void thunk_FUN_00445570(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)*in_ECX;
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    *in_ECX = *puVar1;
    puVar4 = (undefined4 *)puVar1[2];
    if (puVar4 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*puVar4;
      if (puVar2 != (undefined4 *)0x0) {
        if (puVar1 == puVar2) {
LAB_004455a5:
          *puVar4 = *puVar1;
        }
        else {
          puVar4 = (undefined4 *)0x0;
          do {
            puVar3 = puVar2;
            if (puVar3 == puVar1) goto LAB_004455a5;
            puVar2 = (undefined4 *)*puVar3;
            puVar4 = puVar3;
          } while ((undefined4 *)*puVar3 != (undefined4 *)0x0);
        }
      }
      puVar1[2] = 0;
      *puVar1 = 0;
    }
    puVar1 = (undefined4 *)*in_ECX;
  } while( true );
}

