
void FUN_005a3fd0(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_ECX;
  uint uVar7;
  uint local_34;
  int local_1c;
  int local_18;
  uint local_14;
  
  if (param_1 < PTR_0077241c->x0_8) {
    param_1 = PTR_0077241c->x0_8;
  }
  if (param_2 < PTR_0077241c->y0_8) {
    param_2 = PTR_0077241c->y0_8;
  }
  if (PTR_0077241c->x1_8 < param_3) {
    param_3 = PTR_0077241c->x1_8;
  }
  if (PTR_0077241c->y1_8 < param_4) {
    param_4 = PTR_0077241c->y1_8;
  }
  if ((param_1 < param_3) && (param_2 < param_4)) {
    if ((param_5 & 0x40000) != 0) {
      FUN_005a3fd0(param_1,param_2,param_3,param_4,6);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x10);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x40);
      param_5 = param_5 & 0xffffffa9;
    }
    if ((param_5 & 0x10000) != 0) {
      FUN_005a3fd0(param_1 + -8,param_2 + -2,param_3 + 8,param_4 + 0x10,7);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,8);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x20);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x40);
      FUN_005a3fd0(param_1 + -0x10,param_2 + -0x10,param_3 + 0x10,param_4 + 0x10,0x100);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x400);
      param_5 = param_5 & 0xfffffa80;
    }
    if ((param_5 & 1) != 0) {
      *(int *)(in_ECX + 0x138) = *(int *)(in_ECX + 0x138) + 1;
      *(int *)(in_ECX + 0x16c) =
           *(int *)(in_ECX + 0x16c) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,2);
      param_5 = param_5 & 0xfffffff8;
    }
    if ((param_5 & 2) != 0) {
      *(int *)(in_ECX + 0x13c) = *(int *)(in_ECX + 0x13c) + 1;
      *(int *)(in_ECX + 0x170) =
           *(int *)(in_ECX + 0x170) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,4);
      param_5 = param_5 & 0xfffffffb;
    }
    if ((param_5 & 4) != 0) {
      *(int *)(in_ECX + 0x140) = *(int *)(in_ECX + 0x140) + 1;
      *(int *)(in_ECX + 0x174) =
           *(int *)(in_ECX + 0x174) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
    }
    if ((param_5 & 8) != 0) {
      *(int *)(in_ECX + 0x144) = *(int *)(in_ECX + 0x144) + 1;
      *(int *)(in_ECX + 0x178) =
           *(int *)(in_ECX + 0x178) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x10);
      param_5 = param_5 & 0xffffffe7;
    }
    if ((param_5 & 0x10) != 0) {
      *(int *)(in_ECX + 0x148) = *(int *)(in_ECX + 0x148) + 1;
      *(int *)(in_ECX + 0x17c) =
           *(int *)(in_ECX + 0x17c) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
    }
    if ((param_5 & 0x800) != 0) {
      *(int *)(in_ECX + 0x164) = *(int *)(in_ECX + 0x164) + 1;
      *(int *)(in_ECX + 0x198) =
           *(int *)(in_ECX + 0x198) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
    }
    if ((param_5 & 0x1000) != 0) {
      *(int *)(in_ECX + 0x168) = *(int *)(in_ECX + 0x168) + 1;
      *(int *)(in_ECX + 0x19c) =
           *(int *)(in_ECX + 0x19c) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
    }
    if ((param_5 & 0x20) != 0) {
      *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + 1;
      *(int *)(in_ECX + 0x180) =
           *(int *)(in_ECX + 0x180) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
      FUN_005a3fd0(param_1 + -8,param_2 + -8,param_3 + 8,param_4 + 8,0x400);
      param_5 = param_5 & 0xfffffbff;
    }
    if ((param_5 & 0x40) != 0) {
      *(int *)(in_ECX + 0x150) = *(int *)(in_ECX + 0x150) + 1;
      *(int *)(in_ECX + 0x184) =
           *(int *)(in_ECX + 0x184) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
    }
    if ((char)param_5 < '\0') {
      *(int *)(in_ECX + 0x154) = *(int *)(in_ECX + 0x154) + 1;
      *(int *)(in_ECX + 0x188) =
           *(int *)(in_ECX + 0x188) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
    }
    if ((param_5 & 0x100) != 0) {
      *(int *)(in_ECX + 0x158) = *(int *)(in_ECX + 0x158) + 1;
      *(int *)(in_ECX + 0x18c) =
           *(int *)(in_ECX + 0x18c) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x80);
      param_5 = param_5 & 0xffffff7f;
    }
    if ((param_5 & 0x200) != 0) {
      *(int *)(in_ECX + 0x15c) = *(int *)(in_ECX + 0x15c) + 1;
      *(int *)(in_ECX + 400) = *(int *)(in_ECX + 400) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
      FUN_005a3fd0(param_1,param_2,param_3,param_4,0x80);
      param_5 = param_5 & 0xffffff7f;
    }
    if ((param_5 & 0x400) != 0) {
      *(int *)(in_ECX + 0x160) = *(int *)(in_ECX + 0x160) + 1;
      *(int *)(in_ECX + 0x194) =
           *(int *)(in_ECX + 0x194) + (param_4 - param_2) * (param_3 - param_1);
      FUN_006c2340(param_1,param_2,param_3,param_4);
    }
    DAT_00c3c9bc = DAT_00c3c9bc + 1;
    if (200 < DAT_00c3c9bc) {
      DAT_00c3c9bc = 0;
      local_34 = 0;
      uVar7 = 0;
      local_14 = 1;
      do {
        if ((param_5 & local_14) != 0) {
          if (0xc < local_34) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_006c2d00();
          if (((int)local_34 < 0) || (0xc < (int)local_34)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_1c = 0;
          local_18 = 0;
          while( true ) {
            if (uVar7 < 0x91) {
              piVar6 = (int *)(in_ECX + 0x9c + uVar7);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar6 = (int *)(in_ECX + 0x9c);
            }
            if (piVar6[1] <= local_1c) break;
            local_1c = local_1c + 1;
            puVar1 = (undefined4 *)(*piVar6 + local_18);
            uVar2 = *puVar1;
            uVar3 = puVar1[1];
            uVar4 = puVar1[2];
            uVar5 = puVar1[3];
            local_18 = local_18 + 0x10;
            if (0x90 < uVar7) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_006c2340(uVar2,uVar3,uVar4,uVar5);
          }
          if (0xc < local_34) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_0049c5f0(0);
        }
        local_34 = local_34 + 1;
        local_14 = local_14 << 1 | (uint)((int)local_14 < 0);
        uVar7 = uVar7 + 0xc;
      } while ((int)uVar7 < 0x9c);
    }
  }
  return;
}

