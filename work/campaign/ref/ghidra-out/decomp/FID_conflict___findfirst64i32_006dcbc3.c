
/* Library Function - Multiple Matches With Different Base Names
    __findfirst32
    __findfirst32i64
    __findfirst64
    __findfirst64i32
   
   Library: Visual Studio 2019 Release */

intptr_t __cdecl FID_conflict___findfirst64i32(char *_Filename,_finddata32i64_t *_FindData)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = __acrt_get_utf8_acp_compatibility_codepage();
  iVar2 = common_find_first_narrow<struct__wfinddata64i32_t,struct__finddata64i32_t>
                    (_Filename,(_finddata64i32_t *)_FindData,uVar1);
  return iVar2;
}

