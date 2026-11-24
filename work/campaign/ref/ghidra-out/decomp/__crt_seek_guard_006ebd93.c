
/* Library Function - Single Match
    public: __thiscall __crt_seek_guard::__crt_seek_guard(int,__int64)
   
   Library: Visual Studio 2019 Release */

__crt_seek_guard * __thiscall
__crt_seek_guard::__crt_seek_guard(__crt_seek_guard *this,int param_1,__int64 param_2)

{
  uint uVar1;
  int iVar2;
  int unaff_EDI;
  longlong lVar3;
  uint in_stack_00000008;
  
  iVar2 = param_1;
  lVar3 = __lseeki64_nolock(param_1,0x100000000,unaff_EDI);
  *(longlong *)this = lVar3;
  lVar3 = __lseeki64_nolock(param_1,0x200000000,iVar2);
  iVar2 = (int)((ulonglong)lVar3 >> 0x20);
  uVar1 = (uint)lVar3;
  *(uint *)(this + 8) = uVar1;
  *(int *)(this + 0x18) = param_1;
  *(uint *)(this + 0x14) = ((int)param_2 - iVar2) - (uint)(in_stack_00000008 < uVar1);
  *(int *)(this + 0xc) = iVar2;
  *(uint *)(this + 0x10) = in_stack_00000008 - uVar1;
  return this;
}

