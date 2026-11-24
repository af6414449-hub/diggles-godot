
/* Library Function - Single Match
    __findnext64i32
   
   Library: Visual Studio 2019 Release */

int __cdecl __findnext64i32(intptr_t _FindHandle,_finddata64i32_t *_FindData)

{
  uint uVar1;
  int iVar2;
  _wfinddata64i32_t local_238 [560];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  uVar1 = __acrt_get_utf8_acp_compatibility_codepage();
  iVar2 = common_find_next_wide<struct__wfinddata64i32_t>(_FindHandle,local_238);
  if (iVar2 != -1) {
    copy_wide_to_narrow_find_data<struct__wfinddata64i32_t,struct__finddata64i32_t>
              (local_238,_FindData,uVar1);
  }
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

