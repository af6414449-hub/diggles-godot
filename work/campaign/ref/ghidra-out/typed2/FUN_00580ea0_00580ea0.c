
byte FUN_00580ea0(void)

{
  byte *pbVar1;
  int *in_ECX;
  int in_EDX;
  byte bVar2;
  byte bVar3;
  
  if ((((in_ECX[1] < PTR_0077241c->cellY0) || (PTR_0077241c->cellY1 <= in_ECX[3])) ||
      (*in_ECX < PTR_0077241c->cellX0)) || (PTR_0077241c->cellX1 <= in_ECX[2])) {
    return 0;
  }
  if (-1 < in_EDX) {
    FUN_00592f10(PTR_0077241c);
    pbVar1 = (byte *)FUN_00423700(in_EDX);
    bVar2 = *pbVar1;
    if (bVar2 < 0xe3) {
      FUN_00592f10(PTR_0077241c);
      pbVar1 = (byte *)FUN_00423700(in_EDX);
      bVar3 = *pbVar1;
      if ((bVar3 <= bVar2) || (bVar3 < 0xe3)) {
        if (bVar3 <= bVar2) {
          bVar3 = bVar2;
        }
        FUN_00592f10(PTR_0077241c);
        pbVar1 = (byte *)FUN_00423700(in_EDX);
        bVar2 = *pbVar1;
        if ((bVar2 <= bVar3) || (bVar2 < 0xe3)) {
          if (bVar2 <= bVar3) {
            bVar2 = bVar3;
          }
          FUN_00592f10(PTR_0077241c);
          pbVar1 = (byte *)FUN_00423700(in_EDX);
          bVar3 = *pbVar1;
          if ((bVar3 <= bVar2) || (bVar3 < 0xe3)) {
            if (bVar3 <= bVar2) {
              bVar3 = bVar2;
            }
            FUN_00592f10(PTR_0077241c);
            pbVar1 = (byte *)FUN_00423700(in_EDX);
            bVar2 = *pbVar1;
            if ((bVar2 <= bVar3) || (bVar2 < 0xe3)) {
              if (bVar2 <= bVar3) {
                bVar2 = bVar3;
              }
              FUN_00592f10(PTR_0077241c);
              pbVar1 = (byte *)FUN_00423700(in_EDX);
              bVar3 = *pbVar1;
              if ((bVar3 <= bVar2) || (bVar3 < 0xe3)) {
                if (bVar3 <= bVar2) {
                  bVar3 = bVar2;
                }
                FUN_00592f10(PTR_0077241c);
                pbVar1 = (byte *)FUN_00423700(in_EDX);
                bVar2 = *pbVar1;
                if ((bVar2 <= bVar3) || (bVar2 < 0xe3)) {
                  if (bVar2 <= bVar3) {
                    bVar2 = bVar3;
                  }
                  return bVar2;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0xff;
}

