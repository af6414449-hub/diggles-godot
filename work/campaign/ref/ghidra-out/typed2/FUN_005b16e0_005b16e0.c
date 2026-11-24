
undefined4 * FUN_005b16e0(void)

{
  undefined4 *puVar1;
  CMap *pCVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (DAT_00772434 == (undefined4 *)0x0) {
    DAT_00772434 = (undefined4 *)FUN_006ba810(0x11);
    pCVar2 = PTR_0077241c;
    if (DAT_00772434 == (undefined4 *)0x0) {
      DAT_00772434 = (undefined4 *)0x0;
    }
    else {
      DAT_00772434[2] = 0;
      DAT_00772434[1] = 0;
      *DAT_00772434 = 0;
      DAT_00772434[3] = 0;
      DAT_00772434[4] = 0;
      DAT_00772434[5] = 0;
      DAT_00772434[6] = 0;
      DAT_00772434[7] = 1;
      puVar4 = (undefined4 *)DAT_00772434[2];
      if (puVar4 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*puVar4;
        if (puVar1 != (undefined4 *)0x0) {
          if (DAT_00772434 == puVar1) {
LAB_005b1771:
            *puVar4 = *DAT_00772434;
            *DAT_00772434 = 0;
          }
          else {
            puVar4 = (undefined4 *)0x0;
            do {
              puVar3 = puVar1;
              if (puVar3 == DAT_00772434) goto LAB_005b1771;
              puVar1 = (undefined4 *)*puVar3;
              puVar4 = puVar3;
            } while ((undefined4 *)*puVar3 != (undefined4 *)0x0);
          }
        }
        DAT_00772434[2] = 0;
        puVar4 = (undefined4 *)0x0;
        *DAT_00772434 = 0;
      }
      if (pCVar2 != (CMap *)0x0) {
        if (puVar4 != (undefined4 *)0x0) {
          puVar1 = (undefined4 *)*puVar4;
          if (puVar1 != (undefined4 *)0x0) {
            if (DAT_00772434 == puVar1) {
LAB_005b17ae:
              *puVar4 = *DAT_00772434;
              *DAT_00772434 = 0;
            }
            else {
              puVar4 = (undefined4 *)0x0;
              do {
                puVar3 = puVar1;
                if (puVar3 == DAT_00772434) goto LAB_005b17ae;
                puVar1 = (undefined4 *)*puVar3;
                puVar4 = puVar3;
              } while ((undefined4 *)*puVar3 != (undefined4 *)0x0);
            }
          }
          DAT_00772434[2] = 0;
          *DAT_00772434 = 0;
        }
        *DAT_00772434 = *(undefined4 *)pCVar2;
        *(undefined4 **)pCVar2 = DAT_00772434;
        DAT_00772434[2] = pCVar2;
        return DAT_00772434;
      }
    }
  }
  return DAT_00772434;
}

