
void __thiscall FUN_00523700(ViWinProduction *this)

{
  ViWinProduction *pVVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  uVar3 = 0;
  uVar2 = 1;
  uVar4 = 20000000;
  uVar6 = 0;
  pVVar1 = this;
  FUN_00501450(this,1,0,20000000,0);
  FUN_005028a0(pVVar1,uVar2,uVar3,uVar4,uVar6);
  uVar3 = 1;
  uVar2 = 1;
  puVar5 = &DAT_00989680;
  uVar4 = 0;
  FUN_00501450(this,1,1,&DAT_00989680,0);
  FUN_005028a0(this,uVar2,uVar3,puVar5,uVar4);
  FUN_00524ca0();
  return;
}

