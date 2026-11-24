
undefined4 FUN_00566870(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int in_ECX;
  
  if (param_3 == 0) {
    return 1;
  }
  if ((((PTR_0077241c->cellX0 + 1 <= param_1) && (param_1 < PTR_0077241c->cellX1 + -1)) &&
      (PTR_0077241c->cellY0 + 1 <= param_2)) &&
     ((param_2 < PTR_0077241c->cellY1 + -1 && (((param_2 + -1) / 2 & (param_1 + -1) / 2 & 1U) == 0))
     )) {
    iVar2 = FUN_00592f10(PTR_0077241c);
    if ((*(uint *)(iVar2 + 8) >> ((byte)(*(int *)(in_ECX + 0x11c) << 2) & 0x1f) & 8) == 0) {
      uVar1 = *(ushort *)(iVar2 + 0x18);
      pcVar3 = (char *)FUN_00423700(*(int *)(in_ECX + 0x11c));
      if ((((uVar1 & 3) != 0) && ((uVar1 & 3) != 3)) || (*pcVar3 == '\0')) {
        if (PTR_0077241c->cellY1 <= param_2 + 1) {
          return 1;
        }
        puVar4 = (undefined4 *)FUN_00592f10(PTR_0077241c);
        if ((((uint)puVar4[2] >> ((byte)(*(int *)(in_ECX + 0x11c) << 2) & 0x1f) & 8) == 0) &&
           (pbVar5 = (byte *)FUN_004093b0(*puVar4), 1 < *pbVar5)) {
          puVar4 = (undefined4 *)FUN_00592f10(PTR_0077241c);
          pbVar5 = (byte *)FUN_004093b0(*puVar4);
          if (1 < *pbVar5) {
            puVar4 = (undefined4 *)FUN_00592f10(PTR_0077241c);
            pbVar5 = (byte *)FUN_004093b0(*puVar4);
            if (1 < *pbVar5) {
              puVar4 = (undefined4 *)FUN_00592f10(PTR_0077241c);
              pbVar5 = (byte *)FUN_004093b0(*puVar4);
              if (1 < *pbVar5) {
                puVar4 = (undefined4 *)FUN_00592f10(PTR_0077241c);
                pbVar5 = (byte *)FUN_004093b0(*puVar4);
                if (1 < *pbVar5) {
                  puVar4 = (undefined4 *)FUN_00592f10(PTR_0077241c);
                  pbVar5 = (byte *)FUN_004093b0(*puVar4);
                  if (1 < *pbVar5) {
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

