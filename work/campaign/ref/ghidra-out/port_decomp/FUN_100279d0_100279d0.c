
undefined4 FUN_100279d0(void)

{
  undefined4 *_Dst;
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  uVar1 = *(undefined4 *)(in_ECX + 0x1a24);
  _Dst = (undefined4 *)(in_ECX + 0x3e68);
  uVar2 = *(uint *)(in_ECX + 0x1a20);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,0x1438);
    if ((uVar2 != 0) && (uVar2 < 3)) {
      *(code **)(in_ECX + 0x3e7c) = FUN_10027850;
      *(int *)(in_ECX + 16000) = in_ECX;
      *_Dst = 0xac44;
      *(undefined4 *)(in_ECX + 0x3e6c) = uVar1;
      *(uint *)(in_ECX + 0x3e70) = uVar2;
      *(undefined4 *)(in_ECX + 0x3e74) = 1;
      *(undefined4 *)(in_ECX + 0x3e78) = 0;
      if ((0x200 < *(uint *)(in_ECX + 0x3e78)) || (*(uint *)(in_ECX + 0x3e78) == 0)) {
        *(undefined4 *)(in_ECX + 0x3e78) = 0x200;
      }
      *(undefined4 **)(in_ECX + 0x4284) = _Dst;
      *(undefined4 *)(in_ECX + 0x5288) = 0;
      *(undefined4 *)(in_ECX + 0x528c) = 0;
      return 1;
    }
  }
  if ((*(int *)(in_ECX + 0x52b0) != 0) &&
     (((undefined4 *)(in_ECX + 0x1a34) != (undefined4 *)0x0 &&
      (*(code **)(in_ECX + 0x1a40) != (code *)0x0)))) {
    (**(code **)(in_ECX + 0x1a40))(*(int *)(in_ECX + 0x52b0),*(undefined4 *)(in_ECX + 0x1a34));
  }
  return 0;
}

