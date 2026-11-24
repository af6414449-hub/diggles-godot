
/* Library Function - Single Match
    __Wcsftime_l
   
   Library: Visual Studio 2019 Release */

int __Wcsftime_l(ushort *param_1,int param_2,ushort *param_3,int param_4,int param_5,
                __crt_locale_pointers *param_6)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  ushort uVar5;
  int iVar6;
  ushort *puVar7;
  int local_2c;
  int local_28 [2];
  char local_20;
  ushort *local_1c;
  uint local_18;
  uint local_14;
  ushort *local_10;
  int local_c [2];
  
  if ((param_1 == (ushort *)0x0) || (param_2 == 0)) {
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_006e510d();
    return 0;
  }
  *param_1 = 0;
  if (param_3 == (ushort *)0x0) {
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_006e510d();
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_2c,param_6);
  if (param_5 == 0) {
    param_5 = *(int *)(local_28[0] + 0x9c);
  }
  iVar6 = 0;
  local_10 = param_1;
  local_c[0] = param_2;
  if (param_2 != 0) {
    do {
      uVar2 = local_14;
      uVar5 = *param_3;
      local_18 = (uint)uVar5;
      local_1c = param_3;
      if (uVar5 == 0) break;
      if (uVar5 == 0x25) {
        if (param_4 == 0) goto LAB_006eb0d8;
        puVar7 = param_3 + 1;
        local_14 = local_14 & 0xffffff00;
        uVar5 = *puVar7;
        if (uVar5 == 0x23) {
          puVar7 = param_3 + 2;
          local_14 = CONCAT31(SUB43(uVar2,1),1);
          uVar5 = *puVar7;
        }
        if ((uVar5 == 0x45) || (uVar5 == 0x4f)) {
          puVar7 = puVar7 + 1;
          uVar5 = *puVar7;
        }
        cVar3 = FUN_006e9fed(local_28,uVar5,param_4,&local_10,local_c,param_5,local_14);
        if (cVar3 == '\0') {
          if (local_c[0] == 0) goto LAB_006eb0bc;
          bVar1 = true;
          goto LAB_006eb0be;
        }
      }
      else {
        *local_10 = uVar5;
        local_10 = local_10 + 1;
        local_c[0] = local_c[0] + -1;
        puVar7 = param_3;
      }
      param_3 = puVar7 + 1;
    } while (local_c[0] != 0);
    if (local_c[0] != 0) {
      *local_10 = 0;
      iVar6 = param_2 - local_c[0];
      goto LAB_006eb0e8;
    }
  }
LAB_006eb0bc:
  bVar1 = false;
LAB_006eb0be:
  *param_1 = 0;
  if ((bVar1) || (local_c[0] != 0)) {
LAB_006eb0d8:
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_006e510d();
  }
  else {
    piVar4 = __errno();
    *piVar4 = 0x22;
  }
LAB_006eb0e8:
  if (local_20 != '\0') {
    *(uint *)(local_2c + 0x350) = *(uint *)(local_2c + 0x350) & 0xfffffffd;
  }
  return iVar6;
}

