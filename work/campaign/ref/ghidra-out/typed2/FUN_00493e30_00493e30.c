
void FUN_00493e30(undefined4 param_1)

{
  CMap *pCVar1;
  undefined8 *in_ECX;
  undefined4 in_XMM2_Da;
  undefined4 in_XMM2_Db;
  
  pCVar1 = PTR_0077241c;
  if ((char)PTR_0077241c->mapFlags != '\0') {
    *in_ECX = CONCAT44(in_XMM2_Db,in_XMM2_Da);
    if ((((pCVar1->x0f + 0.0 <= *(float *)((int)in_ECX + 0xc)) &&
         (*(float *)((int)in_ECX + 0xc) < pCVar1->x1f - 0.0)) &&
        (pCVar1->y0f + 0.0 <= *(float *)(in_ECX + 2))) &&
       (*(float *)(in_ECX + 2) < pCVar1->y1f - 0.0)) {
      switch(*(undefined4 *)(in_ECX + 1)) {
      case 0:
        FUN_0049e760(param_1);
        return;
      case 1:
        FUN_004a07d0(param_1);
        return;
      case 2:
        FUN_004a1c50(param_1);
        return;
      case 3:
        FUN_004a2d30(param_1);
        return;
      case 4:
        FUN_004a3da0(param_1);
        return;
      case 6:
        FUN_004a5080(param_1);
        return;
      case 7:
        FUN_004a5ca0(param_1);
        return;
      case 8:
        FUN_004a66c0(param_1);
        return;
      case 9:
        FUN_004a7570(param_1);
        return;
      case 10:
        FUN_004a7eb0(param_1);
        return;
      case 0xb:
        FUN_004a8bb0(param_1);
        return;
      case 0xc:
        FUN_004a9810(param_1);
        return;
      case 0xd:
        FUN_004aa180(param_1);
        return;
      case 0xe:
        FUN_004ab4d0(param_1);
        return;
      case 0xf:
        FUN_004ac020(param_1);
        return;
      case 0x10:
        FUN_004acee0(param_1);
        return;
      case 0x11:
        FUN_004ada30(param_1);
        return;
      case 0x12:
        FUN_004af7e0(param_1);
        return;
      case 0x13:
        FUN_004b1480(param_1);
        return;
      case 0x14:
        FUN_004b2b50(param_1);
        return;
      case 0x15:
        FUN_004b35c0(param_1);
        return;
      case 0x16:
        FUN_004b3fd0(param_1);
        return;
      case 0x17:
        FUN_004b47c0(param_1);
        return;
      case 0x18:
        FUN_004b4ec0(param_1);
        return;
      case 0x19:
        FUN_004b5900(param_1);
        return;
      case 0x1a:
        FUN_004b6440(param_1);
        return;
      case 0x1b:
        FUN_004b81d0(param_1);
        return;
      case 0x1c:
        FUN_004b9150(param_1);
        return;
      case 0x1d:
        FUN_004b9dc0(param_1);
        return;
      case 0x1e:
        FUN_004bacb0(param_1);
        return;
      case 0x1f:
        FUN_004bbbd0(param_1);
        return;
      case 0x20:
        FUN_004bc2a0(param_1);
        return;
      case 0x21:
        FUN_004bd530(param_1);
        return;
      case 0x22:
        FUN_0049f790(param_1);
        return;
      case 0x23:
        FUN_004a4470(param_1);
        return;
      case 0x24:
        FUN_004be880(param_1);
        return;
      case 0x25:
        FUN_004bed80(param_1);
        return;
      case 0x26:
        FUN_004bf270(param_1);
        return;
      case 0x27:
        FUN_004bf760(param_1);
        return;
      case 0x28:
        FUN_004bfc30(param_1);
        break;
      case 0x29:
        FUN_004bcba0(param_1);
        return;
      case 0x2a:
        FUN_004b2020(param_1);
        return;
      }
    }
  }
  return;
}

