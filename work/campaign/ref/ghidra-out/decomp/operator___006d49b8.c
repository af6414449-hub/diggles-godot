
/* Library Function - Single Match
    public: unsigned int __thiscall <lambda_5856287d7ecd2be6c9197bb4007c3f6e>::operator()(void)const
   
   
   Library: Visual Studio 2019 Release */

uint __thiscall
<lambda_5856287d7ecd2be6c9197bb4007c3f6e>::operator()
          (<lambda_5856287d7ecd2be6c9197bb4007c3f6e> *this)

{
  undefined4 uVar1;
  undefined1 uVar2;
  size_t sVar3;
  
  uVar1 = **(undefined4 **)this;
  uVar2 = ___acrt_stdio_begin_temporary_buffering_nolock(uVar1);
  sVar3 = __fwrite_nolock((void *)**(undefined4 **)(this + 4),**(size_t **)(this + 8),
                          **(size_t **)(this + 0xc),(FILE *)**(undefined4 **)this);
  ___acrt_stdio_end_temporary_buffering_nolock(uVar2,uVar1);
  return sVar3;
}

