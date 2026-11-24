
void FUN_005392c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  CMap *pCVar3;
  undefined4 *puVar4;
  undefined4 *in_ECX;
  undefined4 *puVar5;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00703248;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005044d0(DAT_0076700c ^ (uint)&stack0xfffffffc);
  puVar1 = in_ECX + 0x12;
  *in_ECX = ViWinSmallMap::vftable;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  *puVar1 = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x3f] = 0;
  pCVar3 = PTR_0077241c;
  local_8 = 6;
  in_ECX[10] = 2;
  in_ECX[0x46] = 0;
  in_ECX[0x47] = 0;
  puVar5 = (undefined4 *)in_ECX[0x14];
  if (puVar5 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar5;
    if (puVar2 != (undefined4 *)0x0) {
      if (puVar1 == puVar2) {
LAB_0053947e:
        *puVar5 = *puVar1;
        *puVar1 = 0;
      }
      else {
        puVar5 = (undefined4 *)0x0;
        do {
          puVar4 = puVar2;
          if (puVar4 == puVar1) goto LAB_0053947e;
          puVar2 = (undefined4 *)*puVar4;
          puVar5 = puVar4;
        } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
      }
    }
    in_ECX[0x14] = 0;
    puVar5 = (undefined4 *)0x0;
    *puVar1 = 0;
  }
  if (pCVar3 != (CMap *)0x0) {
    if (puVar5 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*puVar5;
      if (puVar2 != (undefined4 *)0x0) {
        if (puVar1 == puVar2) {
LAB_005394be:
          *puVar5 = *puVar1;
          *puVar1 = 0;
        }
        else {
          puVar5 = (undefined4 *)0x0;
          do {
            puVar4 = puVar2;
            if (puVar4 == puVar1) goto LAB_005394be;
            puVar2 = (undefined4 *)*puVar4;
            puVar5 = puVar4;
          } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
        }
      }
      in_ECX[0x14] = 0;
      *puVar1 = 0;
    }
    *puVar1 = *(undefined4 *)pCVar3;
    *(undefined4 **)pCVar3 = puVar1;
    in_ECX[0x14] = pCVar3;
  }
  uStack_1c = 0x8a;
  uStack_18 = 0x8a;
  FUN_004fee10(&uStack_1c);
  in_ECX[0x1a] = in_ECX[0x3e];
  in_ECX[0x1b] = in_ECX[0x3e] * in_ECX[0x3d];
  in_ECX[0x1e] = in_ECX[0x3f];
  in_ECX[0x19] = in_ECX[0x3d];
  in_ECX[0x22] = 0xff000000;
  in_ECX[0x1f] = 0xff0000;
  in_ECX[0x20] = 0xff00;
  in_ECX[0x21] = 0xff;
  in_ECX[0x1d] = 4;
  in_ECX[0x2d] = 0x40800000;
  in_ECX[0x23] = 0xc47a0000;
  in_ECX[0x24] = 0xc47a0000;
  in_ECX[0x25] = 0xc47a0000;
  in_ECX[0x26] = 0xc47a0000;
  in_ECX[0x27] = 0xc47a0000;
  *(undefined2 *)((int)in_ECX + 0xb1) = 0x101;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 1;
  in_ECX[0x2b] = 1;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x11] = 0;
  ExceptionList = local_10;
  return;
}

