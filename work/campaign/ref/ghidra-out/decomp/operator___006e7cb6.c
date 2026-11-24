
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    public: int __thiscall <lambda_29d3c280b90b41c2ae070ffca879996a>::operator()(wchar_t *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __thiscall
<lambda_29d3c280b90b41c2ae070ffca879996a>::operator()
          (<lambda_29d3c280b90b41c2ae070ffca879996a> *this,wchar_t *param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = DAT_0076700c ^ _DAT_0076a060;
  bVar2 = (byte)DAT_0076700c & 0x1f;
  guard_check_icall(param_1,0,0);
  iVar1 = (*(code *)(uVar3 >> bVar2 | uVar3 << 0x20 - bVar2))();
  return iVar1;
}

