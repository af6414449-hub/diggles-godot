
void FUN_10023da0(int param_1,int param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 *_Dst;
  int iVar6;
  int in_ECX;
  undefined4 *puVar7;
  int in_EDX;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  uint uVar13;
  int local_24;
  char *local_20;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  local_20 = (char *)0x0;
  if (0 < param_2) {
    iVar11 = param_1;
    do {
      uVar4 = *(ushort *)(iVar11 + 4);
      iVar10 = *(int *)(in_EDX + 4);
      FUN_10022250(in_EDX,iVar11,in_EDX + 0x1d7c,local_20);
      FUN_10022500(iVar11,in_EDX + 0x1d7c,(uint)uVar4 + iVar10);
      local_20 = (char *)((int)local_20 + 1);
      iVar11 = iVar11 + 0x1c;
    } while ((int)local_20 < param_2);
  }
  if ((*(byte *)(in_ECX + 0x180b) & 0x10) == 0) {
    if ((*(byte *)(in_ECX + 0x180b) & 0xe0) == 0x60) {
      FUN_10022a90();
    }
  }
  else {
    FUN_10022f20(param_1,in_ECX + 0x1808);
  }
  if (0 < param_2) {
    local_24 = 0;
    local_20 = (char *)(param_1 + 0xe);
    iVar11 = in_EDX + 0xb7c;
    do {
      iVar10 = 0;
      if (local_20[-2] != '\0') {
        iVar10 = 2;
      }
      iVar10 = iVar10 << ((byte)(((*(byte *)(in_ECX + 0x1809) >> 4 & 1) +
                                 (*(byte *)(in_ECX + 0x1809) >> 3 & 1)) * '\x03' +
                                (*(byte *)(in_ECX + 0x180a) >> 2 & 3)) == '\x02');
      if (*local_20 != '\0') {
        pbVar12 = (byte *)((uint)(byte)local_20[-1] + *(int *)(local_20 + -0xe));
        puVar7 = (undefined4 *)(in_EDX + 0x1e1c);
        _Dst = (undefined4 *)((local_24 + iVar10) * 0x48 + 0xb7c + in_EDX);
        bVar2 = *pbVar12;
        puVar8 = _Dst;
        while (uVar5 = (uint)bVar2, uVar13 = uVar5, uVar5 != 0) {
          do {
            *puVar7 = *puVar8;
            puVar7[1] = puVar8[uVar5];
            puVar1 = puVar8 + uVar5 * 2;
            puVar8 = puVar8 + 1;
            puVar7[2] = *puVar1;
            puVar7 = puVar7 + 3;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
          puVar8 = puVar8 + uVar5 * 2;
          pbVar12 = pbVar12 + 3;
          bVar2 = *pbVar12;
        }
        memcpy(_Dst,(void *)(in_EDX + 0x1e1c),(int)puVar7 - (in_EDX + 0x1e1c) & 0xfffffffc);
      }
      FUN_100230a0();
      cVar3 = local_20[-3];
      if (iVar10 != 0) {
        FUN_10023220(&DAT_10046e60,iVar10);
      }
      if (cVar3 == '\x02') {
        FUN_10023b00();
      }
      else {
        iVar9 = 0;
        if (cVar3 == '\x03') {
          iVar9 = 0x48;
        }
        FUN_10023220(&DAT_10046e60 + iVar9,0x20 - iVar10);
      }
      iVar10 = iVar11 + 0x48;
      iVar9 = 0x10;
      do {
        iVar6 = 1;
        do {
          *(uint *)(iVar10 + iVar6 * 4) = *(uint *)(iVar10 + iVar6 * 4) ^ 0x80000000;
          iVar6 = iVar6 + 2;
        } while (iVar6 < 0x12);
        iVar10 = iVar10 + 0x90;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      local_24 = local_24 + 0x20;
      iVar11 = iVar11 + 0x900;
      local_20 = local_20 + 0x1c;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

