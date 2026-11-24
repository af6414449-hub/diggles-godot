
/* Library Function - Single Match
    int __cdecl setmbcp_internal(int,bool,struct __acrt_ptd * const,struct __crt_multibyte_data * *
   const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
setmbcp_internal(int param_1,bool param_2,__acrt_ptd *param_3,__crt_multibyte_data **param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  __acrt_ptd **local_18;
  __crt_multibyte_data ***local_14;
  int local_10;
  undefined4 local_c;
  __crt_seh_guarded_call<void> local_5;
  
  update_thread_multibyte_data_internal(param_3,param_4);
  local_10 = getSystemCP(param_1);
  if (local_10 == *(int *)(*(int *)(param_3 + 0x48) + 4)) {
    return 0;
  }
  puVar2 = (undefined4 *)__malloc_base(0x220);
  if (puVar2 != (undefined4 *)0x0) {
    puVar6 = *(undefined4 **)(param_3 + 0x48);
    puVar5 = puVar2;
    for (iVar4 = 0x88; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    *puVar2 = 0;
    iVar4 = __setmbcp_nolock(local_10,puVar2);
    if (iVar4 != -1) {
      if (!param_2) {
        ___acrt_set_locale_changed();
      }
      piVar3 = *(int **)(param_3 + 0x48);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if ((iVar1 == 1) && (*(undefined **)(param_3 + 0x48) != &DAT_007673b8)) {
        FID_conflict__free(*(void **)(param_3 + 0x48));
      }
      *puVar2 = 1;
      puVar6 = (undefined4 *)0x0;
      *(undefined4 **)(param_3 + 0x48) = puVar2;
      if ((((byte)param_3[0x350] & 2) == 0) && (((byte)DAT_007673b0 & 1) == 0)) {
        local_18 = &param_3;
        local_14 = &param_4;
        local_10 = 5;
        local_c = 5;
        __crt_seh_guarded_call<void>::
        operator()<class_<lambda_ceb1ee4838e85a9d631eb091e2fbe199>,class_<lambda_ae742caa10f662c28703da3d2ea5e57e>&,class_<lambda_cd08b5d6af4937fe54fc07d0c9bf6b37>_>
                  (&local_5,(<lambda_ceb1ee4838e85a9d631eb091e2fbe199> *)&local_c,
                   (<lambda_ae742caa10f662c28703da3d2ea5e57e> *)&local_18,
                   (<lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> *)&local_10);
        if (param_2) {
          PTR_DAT_007672d4 = *param_4;
        }
      }
      goto LAB_006ecb7b;
    }
    piVar3 = __errno();
    *piVar3 = 0x16;
  }
  iVar4 = -1;
  puVar6 = puVar2;
LAB_006ecb7b:
  FID_conflict__free(puVar6);
  return iVar4;
}

