
/* Library Function - Single Match
    private: int __thiscall `anonymous namespace'::argument_list<char>::expand_if_necessary(void)
   
   Library: Visual Studio 2019 Release */

int __thiscall _anon_5F5C8891::argument_list<char>::expand_if_necessary(argument_list<char> *this)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(int *)(this + 4) == *(int *)(this + 8)) {
    if (*(int *)this == 0) {
      uVar2 = __calloc_base(4,4);
      *(undefined4 *)this = uVar2;
      FID_conflict__free((void *)0x0);
      iVar1 = *(int *)this;
      if (iVar1 != 0) {
        *(int *)(this + 4) = iVar1;
        *(int *)(this + 8) = iVar1 + 0x10;
        goto LAB_006ec67a;
      }
    }
    else {
      uVar3 = *(int *)(this + 8) - *(int *)this >> 2;
      if (uVar3 < 0x80000000) {
        iVar1 = __recalloc_base(*(undefined4 *)this,uVar3 * 2,4);
        if (iVar1 == 0) {
          iVar1 = 0xc;
        }
        else {
          *(int *)this = iVar1;
          *(uint *)(this + 4) = iVar1 + uVar3 * 4;
          *(uint *)(this + 8) = iVar1 + uVar3 * 8;
          iVar1 = 0;
        }
        FID_conflict__free((void *)0x0);
        return iVar1;
      }
    }
    iVar1 = 0xc;
  }
  else {
LAB_006ec67a:
    iVar1 = 0;
  }
  return iVar1;
}

