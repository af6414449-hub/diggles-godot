
undefined * FUN_10004b20(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_1005003c);
  puVar2 = (undefined1 *)(**(code **)(*(int *)*puVar1 + 0x10))();
  switch(*puVar2) {
  case 0x44:
  case 0x47:
  case 100:
  case 0x67:
    return &DAT_10044564;
  case 0x45:
  case 0x65:
    return &DAT_10044560;
  default:
    return (undefined *)0x0;
  case 0x50:
  case 0x70:
    return &DAT_10044568;
  case 0x52:
  case 0x72:
    return &DAT_1004456c;
  }
}

