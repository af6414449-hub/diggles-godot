
/* Library Function - Single Match
    public: int __thiscall <lambda_0bd0bd1e46f8138169959d81163ebf0c>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

int __thiscall
<lambda_0bd0bd1e46f8138169959d81163ebf0c>::operator()
          (<lambda_0bd0bd1e46f8138169959d81163ebf0c> *this)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  size_t sVar4;
  
  uVar2 = **(undefined4 **)this;
  uVar3 = ___acrt_stdio_begin_temporary_buffering_nolock(uVar2);
  sVar4 = __fwrite_nolock((void *)**(undefined4 **)(this + 4),1,**(size_t **)(this + 8),
                          (FILE *)**(undefined4 **)this);
  sVar1 = **(size_t **)(this + 8);
  ___acrt_stdio_end_temporary_buffering_nolock(uVar3,uVar2);
  return (sVar4 == sVar1) - 1;
}

