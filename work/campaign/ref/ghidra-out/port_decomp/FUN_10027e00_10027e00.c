
undefined4 FUN_10027e00(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  puVar1 = (undefined4 *)(in_ECX + 0x1a34);
  *(undefined1 *)(in_ECX + 0x1808) = 0;
  *(undefined4 *)(in_ECX + 0x1a20) = 0;
  *puVar1 = 0;
  *(code **)(in_ECX + 0x1a38) = FUN_10027490;
  *(code **)(in_ECX + 0x1a3c) = FUN_100274b0;
  *(code **)(in_ECX + 0x1a40) = FUN_100274d0;
  *(undefined4 *)(in_ECX + 0x1a24) = 0;
  *(code **)(in_ECX + 0x1a28) = FUN_1001ec50;
  *(code **)(in_ECX + 0x1a2c) = FUN_1001ec70;
  *(undefined4 *)(in_ECX + 0x1a30) = param_2;
  if ((*(int *)(in_ECX + 0x1a40) != 0) &&
     ((*(int *)(in_ECX + 0x1a38) != 0 || (*(int *)(in_ECX + 0x1a3c) != 0)))) {
    iVar2 = FUN_10027ab0(0);
    if (iVar2 != 0) {
      return 1;
    }
    if (((*(int *)(in_ECX + 0x52b0) != 0) && (puVar1 != (undefined4 *)0x0)) &&
       (*(code **)(in_ECX + 0x1a40) != (code *)0x0)) {
      (**(code **)(in_ECX + 0x1a40))(*(int *)(in_ECX + 0x52b0),*puVar1);
    }
  }
  return 0;
}

