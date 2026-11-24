
/* Library Function - Single Match
    int __cdecl expand_argument_wildcards<char>(char * const,char * const,class `anonymous
   namespace'::argument_list<char> &)
   
   Library: Visual Studio 2019 Release */

int __cdecl
expand_argument_wildcards<char>(char *param_1,char *param_2,argument_list<char> *param_3)

{
  <lambda_28bda7af82a03b66c1cb3803a755f95d> <Var1;
  byte bVar2;
  uint uVar3;
  HANDLE hFindFile;
  char *pcVar4;
  BOOL BVar5;
  int iVar6;
  undefined4 local_29c;
  undefined4 local_298;
  void *local_294;
  undefined4 local_290;
  undefined4 local_28c;
  char local_288;
  int local_284;
  int local_280;
  uint local_27c;
  undefined4 local_278;
  undefined4 local_274;
  void *local_270;
  undefined4 local_26c;
  undefined4 local_268;
  char local_264;
  argument_list<char> *local_260;
  <lambda_28bda7af82a03b66c1cb3803a755f95d> local_259;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_260 = param_3;
  if (param_2 != param_1) {
    do {
      <Var1 = (<lambda_28bda7af82a03b66c1cb3803a755f95d>)*param_2;
      if (((<Var1 == (<lambda_28bda7af82a03b66c1cb3803a755f95d>)0x2f) ||
          (<Var1 == (<lambda_28bda7af82a03b66c1cb3803a755f95d>)0x5c)) ||
         (<Var1 == (<lambda_28bda7af82a03b66c1cb3803a755f95d>)0x3a)) break;
      param_2 = (char *)__mbsdec((uchar *)param_1,(uchar *)param_2);
    } while (param_2 != param_1);
  }
  local_259 = (<lambda_28bda7af82a03b66c1cb3803a755f95d>)*param_2;
  if ((local_259 == (<lambda_28bda7af82a03b66c1cb3803a755f95d>)0x3a) &&
     ((<lambda_28bda7af82a03b66c1cb3803a755f95d> *)param_2 !=
      (<lambda_28bda7af82a03b66c1cb3803a755f95d> *)(param_1 + 1))) {
    copy_and_add_argument_to_buffer<char>(param_1,(char *)0x0,0,local_260);
  }
  else {
    if (((local_259 == (<lambda_28bda7af82a03b66c1cb3803a755f95d>)0x2f) ||
        (local_259 == (<lambda_28bda7af82a03b66c1cb3803a755f95d>)0x5c)) ||
       (bVar2 = 0, local_259 == (<lambda_28bda7af82a03b66c1cb3803a755f95d>)0x3a)) {
      bVar2 = 1;
    }
    local_29c = 0;
    local_298 = 0;
    local_294 = (void *)0x0;
    local_27c = -(uint)bVar2 &
                (uint)((<lambda_28bda7af82a03b66c1cb3803a755f95d> *)param_2 + (1 - (int)param_1));
    local_290 = 0;
    local_28c = 0;
    local_288 = '\0';
    uVar3 = __acrt_get_utf8_acp_compatibility_codepage();
    iVar6 = __acrt_mbs_to_wcs_cp<struct___crt_win32_buffer_internal_dynamic_resizing>
                      (param_1,(__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>
                                *)&local_29c,uVar3);
    hFindFile = FindFirstFileExW((LPCWSTR)(~-(uint)(iVar6 != 0) & (uint)local_294),
                                 FindExInfoStandard,&local_258,FindExSearchNameMatch,(LPVOID)0x0,0);
    if (hFindFile == (HANDLE)0xffffffff) {
      copy_and_add_argument_to_buffer<char>(param_1,(char *)0x0,0,local_260);
    }
    else {
      local_280 = *(int *)(local_260 + 4) - *(int *)local_260 >> 2;
      do {
        local_278 = 0;
        local_274 = 0;
        local_270 = (void *)0x0;
        local_26c = 0;
        local_268 = 0;
        local_264 = '\0';
        uVar3 = __acrt_get_utf8_acp_compatibility_codepage();
        iVar6 = __acrt_convert_wcs_mbs_cp<wchar_t,char,class_<lambda_28bda7af82a03b66c1cb3803a755f95d>,struct___crt_win32_buffer_internal_dynamic_resizing>
                          (local_258.cFileName,
                           (__crt_win32_buffer<char,struct___crt_win32_buffer_internal_dynamic_resizing>
                            *)&local_278,&local_259,uVar3);
        pcVar4 = (char *)(~-(uint)(iVar6 != 0) & (uint)local_270);
        if (((*pcVar4 != '.') ||
            ((pcVar4[1] != '\0' && ((pcVar4[1] != '.' || (pcVar4[2] != '\0')))))) &&
           (local_284 = copy_and_add_argument_to_buffer<char>(pcVar4,param_1,local_27c,local_260),
           local_284 != 0)) {
          if (local_264 != '\0') {
            FID_conflict__free(local_270);
          }
          goto LAB_006ec63f;
        }
        if (local_264 != '\0') {
          FID_conflict__free(local_270);
        }
        BVar5 = FindNextFileW(hFindFile,&local_258);
      } while (BVar5 != 0);
      iVar6 = *(int *)(local_260 + 4) - *(int *)local_260 >> 2;
      if (local_280 != iVar6) {
        _qsort((void *)(*(int *)local_260 + local_280 * 4),iVar6 - local_280,4,FUN_006ec15d);
      }
LAB_006ec63f:
      FindClose(hFindFile);
    }
    if (local_288 != '\0') {
      FID_conflict__free(local_294);
    }
  }
  iVar6 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar6;
}

