
byte FUN_005ab220(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  float in_XMM2_Da;
  float in_XMM3_Da;
  
  DAT_00772dd8 = (int)ROUND(in_XMM3_Da);
  if (((((int)ROUND(in_XMM2_Da) < PTR_0077241c->cellX0 + 1) ||
       (PTR_0077241c->cellX1 + -1 <= (int)ROUND(in_XMM2_Da))) ||
      (DAT_00772dd8 < PTR_0077241c->cellY0 + 1)) ||
     ((PTR_0077241c->cellY1 + -1 <= DAT_00772dd8 || (param_1 < 0)))) {
    return 0;
  }
  iVar3 = FUN_00592f10(PTR_0077241c);
  pbVar4 = (byte *)(iVar3 + 0x34);
  if (param_1 < 8) {
    pbVar4 = pbVar4 + param_1;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  bVar1 = *pbVar4;
  iVar3 = FUN_00592f10(PTR_0077241c);
  pbVar4 = (byte *)(iVar3 + 0x34);
  if (param_1 < 8) {
    pbVar4 = pbVar4 + param_1;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  bVar2 = *pbVar4;
  if (*pbVar4 <= bVar1) {
    bVar2 = bVar1;
  }
  iVar3 = FUN_00592f10(PTR_0077241c);
  pbVar4 = (byte *)(iVar3 + 0x34);
  if (param_1 < 8) {
    pbVar4 = pbVar4 + param_1;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  bVar1 = *pbVar4;
  if (*pbVar4 <= bVar2) {
    bVar1 = bVar2;
  }
  iVar3 = FUN_00592f10(PTR_0077241c);
  if (param_1 < 8) {
    bVar2 = ((byte *)(iVar3 + 0x34))[param_1];
    if (bVar2 <= bVar1) {
      bVar2 = bVar1;
    }
    return bVar2;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  bVar2 = *(byte *)(iVar3 + 0x34);
  if (bVar2 <= bVar1) {
    bVar2 = bVar1;
  }
  return bVar2;
}

