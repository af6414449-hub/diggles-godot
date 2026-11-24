
/* Library Function - Single Match
    struct __crt_multibyte_data * __cdecl update_thread_multibyte_data_internal(struct __acrt_ptd *
   const,struct __crt_multibyte_data * * const)
   
   Library: Visual Studio 2019 Release */

__crt_multibyte_data * __cdecl
update_thread_multibyte_data_internal(__acrt_ptd *param_1,__crt_multibyte_data **param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  __crt_multibyte_data *p_Var4;
  int unaff_EBP;
  int *_Memory;
  
  FUN_006cf3b0(&DAT_007638a8,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  iVar2 = *(int *)(unaff_EBP + 8);
  if (((*(uint *)(iVar2 + 0x350) & DAT_007673b0) == 0) || (*(int *)(iVar2 + 0x4c) == 0)) {
    ___acrt_lock(5);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    _Memory = *(int **)(iVar2 + 0x48);
    *(int **)(unaff_EBP + -0x1c) = _Memory;
    puVar3 = *(undefined4 **)(unaff_EBP + 0xc);
    if (_Memory != (int *)*puVar3) {
      if (_Memory != (int *)0x0) {
        LOCK();
        iVar1 = *_Memory;
        *_Memory = iVar1 + -1;
        UNLOCK();
        if ((iVar1 + -1 == 0) && (_Memory != (int *)&DAT_007673b8)) {
          FID_conflict__free(_Memory);
        }
      }
      _Memory = (int *)*puVar3;
      *(int **)(iVar2 + 0x48) = _Memory;
      *(int **)(unaff_EBP + -0x1c) = _Memory;
      LOCK();
      *_Memory = *_Memory + 1;
      UNLOCK();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006ecc9c();
  }
  else {
    _Memory = *(int **)(iVar2 + 0x48);
  }
  if (_Memory != (int *)0x0) {
    p_Var4 = (__crt_multibyte_data *)FUN_006ecca5();
    return p_Var4;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}

