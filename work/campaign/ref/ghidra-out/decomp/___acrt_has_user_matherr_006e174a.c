
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___acrt_has_user_matherr
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___acrt_has_user_matherr(void)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = (byte)DAT_0076700c & 0x1f;
  uVar1 = (DAT_0076700c ^ _DAT_00769d4c) >> bVar2 | (DAT_0076700c ^ _DAT_00769d4c) << 0x20 - bVar2;
  return CONCAT31((int3)(uVar1 >> 8),uVar1 != 0);
}

