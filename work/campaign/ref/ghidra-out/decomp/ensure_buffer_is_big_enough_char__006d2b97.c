
/* Library Function - Single Match
    public: bool __thiscall
   __crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>(unsigned int)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>
          (formatting_buffer *this,uint param_1)

{
  uint uVar1;
  int *piVar2;
  bool bVar3;
  formatting_buffer *local_8;
  
  local_8 = this;
  if (param_1 < 0x80000000) {
    uVar1 = param_1 * 2;
    if (((*(int *)(this + 0x404) == 0) && (uVar1 < 0x401)) || (uVar1 <= *(uint *)(this + 0x400))) {
      bVar3 = true;
    }
    else {
      local_8 = (formatting_buffer *)__malloc_base(uVar1);
      bVar3 = local_8 != (formatting_buffer *)0x0;
      if (bVar3) {
        __crt_unique_heap_ptr<char,struct___crt_internal_free_policy>::operator=
                  ((__crt_unique_heap_ptr<char,struct___crt_internal_free_policy> *)(this + 0x404),
                   (__crt_unique_heap_ptr<char,struct___crt_internal_free_policy> *)&local_8);
        *(uint *)(this + 0x400) = uVar1;
      }
      FID_conflict__free(local_8);
    }
  }
  else {
    piVar2 = __errno();
    *piVar2 = 0xc;
    bVar3 = false;
  }
  return bVar3;
}

