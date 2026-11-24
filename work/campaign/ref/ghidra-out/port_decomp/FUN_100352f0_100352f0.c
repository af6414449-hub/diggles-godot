
undefined8 FUN_100352f0(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  bool bVar4;
  uint local_14;
  int local_10;
  uint local_c;
  uint uStack_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_10 = param_2;
  local_14 = param_1;
  local_c = 0;
  uStack_8 = 0;
  if ((param_2 != 0) || (param_2 = uStack_8, uStack_8 = local_c, param_1 != 0)) {
    param_2 = 0;
    uStack_8 = 0;
    do {
      uVar2 = *(uint *)(in_ECX + 0x48);
      if (uVar2 == 0) {
        while( true ) {
          iVar3 = FUN_10034760(in_ECX + 0x30);
          if (iVar3 == 0) goto LAB_1003536e;
          iVar3 = FUN_10035130();
          if (iVar3 == 0) break;
          if (iVar3 != -0x81) goto LAB_1003536e;
        }
      }
      else {
        if ((local_10 == 0) && (local_14 < uVar2)) {
          bVar4 = CARRY4(uStack_8,local_14);
          uStack_8 = uStack_8 + local_14;
          param_2 = param_2 + bVar4;
          *(uint *)(in_ECX + 0x48) = uVar2 - local_14;
          break;
        }
        bVar4 = CARRY4(uStack_8,uVar2);
        uStack_8 = uStack_8 + uVar2;
        *(undefined4 *)(in_ECX + 0x48) = 0;
        param_2 = param_2 + bVar4;
        bVar4 = local_14 < uVar2;
        local_14 = local_14 - uVar2;
        local_10 = local_10 - (uint)bVar4;
      }
    } while ((local_10 != 0) || (local_14 != 0));
  }
LAB_1003536e:
  puVar1 = (uint *)(in_ECX + 0x90);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uStack_8;
  *(int *)(in_ECX + 0x94) = *(int *)(in_ECX + 0x94) + param_2 + (uint)CARRY4(uVar2,uStack_8);
  return CONCAT44(param_2,uStack_8);
}

