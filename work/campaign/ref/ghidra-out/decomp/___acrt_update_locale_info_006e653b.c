
/* Library Function - Single Match
    ___acrt_update_locale_info
   
   Library: Visual Studio 2019 Release */

void ___acrt_update_locale_info(int param_1,int *param_2)

{
  int iVar1;
  
  if ((*param_2 != DAT_00769d78) && ((*(uint *)(param_1 + 0x350) & DAT_007673b0) == 0)) {
    iVar1 = ___acrt_update_thread_locale_data();
    *param_2 = iVar1;
  }
  return;
}

