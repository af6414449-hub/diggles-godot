
/* Library Function - Single Match
    bool __cdecl copy_wide_to_narrow_find_data<struct _wfinddata64i32_t,struct
   _finddata64i32_t>(struct _wfinddata64i32_t const &,struct _finddata64i32_t &,unsigned int)
   
   Library: Visual Studio 2019 Release */

bool __cdecl
copy_wide_to_narrow_find_data<struct__wfinddata64i32_t,struct__finddata64i32_t>
          (_wfinddata64i32_t *param_1,_finddata64i32_t *param_2,uint param_3)

{
  int iVar1;
  errno_t eVar2;
  bool bVar3;
  undefined4 local_1c;
  undefined4 local_18;
  char *local_14;
  undefined4 local_10;
  undefined4 local_c;
  char local_8;
  
  bVar3 = false;
  local_1c = 0;
  local_18 = 0;
  local_14 = (char *)0x0;
  local_10 = 0;
  local_c = 0;
  local_8 = '\0';
  iVar1 = __acrt_wcs_to_mbs_cp<struct___crt_win32_buffer_internal_dynamic_resizing>
                    ((wchar_t *)(param_1 + 0x24),
                     (__crt_win32_buffer<char,struct___crt_win32_buffer_internal_dynamic_resizing> *
                     )&local_1c,param_3);
  if (iVar1 == 0) {
    eVar2 = _strcpy_s(param_2->name,0x104,local_14);
    if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    bVar3 = true;
    param_2->attrib = *(uint *)param_1;
    *(undefined4 *)&param_2->time_create = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)((int)&param_2->time_create + 4) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)&param_2->time_access = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)((int)&param_2->time_access + 4) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)&param_2->time_write = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)((int)&param_2->time_write + 4) = *(undefined4 *)(param_1 + 0x1c);
    param_2->size = *(_fsize_t *)(param_1 + 0x20);
  }
  if (local_8 != '\0') {
    FID_conflict__free(local_14);
  }
  return bVar3;
}

