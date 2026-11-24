
/* Library Function - Single Match
    public: int __thiscall <lambda_f03950bc5685219e0bcd2087efbe011e>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

int __thiscall
<lambda_f03950bc5685219e0bcd2087efbe011e>::operator()
          (<lambda_f03950bc5685219e0bcd2087efbe011e> *this)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  sbyte sVar5;
  uint uVar6;
  uint *puVar7;
  uint *_Memory;
  uint *puVar8;
  uint *puVar9;
  
  uVar1 = DAT_0076700c;
  puVar8 = (uint *)**(int **)this;
  if (puVar8 == (uint *)0x0) {
    iVar2 = -1;
  }
  else {
    uVar6 = DAT_0076700c & 0x1f;
    sVar5 = (sbyte)uVar6;
    _Memory = (uint *)((*puVar8 ^ DAT_0076700c) >> sVar5 | (*puVar8 ^ DAT_0076700c) << 0x20 - sVar5)
    ;
    puVar8 = (uint *)((puVar8[1] ^ DAT_0076700c) >> sVar5 |
                     (puVar8[1] ^ DAT_0076700c) << 0x20 - sVar5);
    if ((_Memory != (uint *)0x0) &&
       (uVar3 = DAT_0076700c, puVar9 = puVar8, _Memory != (uint *)0xffffffff)) {
      while (puVar8 = puVar8 + -1, _Memory <= puVar8) {
        if (*puVar8 != uVar1) {
          uVar3 = *puVar8 ^ uVar3;
          *puVar8 = uVar1;
          guard_check_icall();
          (*(code *)(uVar3 >> (sbyte)uVar6 | uVar3 << 0x20 - (sbyte)uVar6))();
          uVar6 = DAT_0076700c & 0x1f;
          uVar3 = *(uint *)**(int **)this ^ DAT_0076700c;
          sVar5 = (sbyte)uVar6;
          puVar7 = (uint *)(uVar3 >> sVar5 | uVar3 << 0x20 - sVar5);
          uVar3 = ((uint *)**(int **)this)[1] ^ DAT_0076700c;
          puVar4 = (uint *)(uVar3 >> sVar5 | uVar3 << 0x20 - sVar5);
          uVar3 = DAT_0076700c;
          if ((puVar7 != _Memory) || (puVar4 != puVar9)) {
            puVar8 = puVar4;
            puVar9 = puVar4;
            _Memory = puVar7;
          }
        }
      }
      if (_Memory != (uint *)0xffffffff) {
        FID_conflict__free(_Memory);
        uVar3 = DAT_0076700c;
      }
      *(uint *)**(undefined4 **)this = uVar3;
      *(uint *)(**(int **)this + 4) = uVar3;
      *(uint *)(**(int **)this + 8) = uVar3;
    }
    iVar2 = 0;
  }
  return iVar2;
}

