
/* Library Function - Single Match
    struct HINSTANCE__ * __cdecl try_get_first_available_module(enum `anonymous
   namespace'::module_id const * const,enum `anonymous namespace'::module_id const * const)
   
   Library: Visual Studio 2019 Release */

HINSTANCE__ * __cdecl try_get_first_available_module(module_id *param_1,module_id *param_2)

{
  int *piVar1;
  LPCWSTR lpLibFileName;
  HINSTANCE__ *hLibModule;
  DWORD DVar2;
  int iVar3;
  
  do {
    if (param_1 == param_2) {
      return (HINSTANCE__ *)0x0;
    }
    piVar1 = &DAT_00769f88 + *param_1;
    hLibModule = (HINSTANCE__ *)*piVar1;
    if (hLibModule == (HINSTANCE__ *)0x0) {
      lpLibFileName = (LPCWSTR)(&PTR_u_api_ms_win_core_datetime_l1_1_1_00717ae0)[*param_1];
      hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);
      if (hLibModule == (HMODULE)0x0) {
        DVar2 = GetLastError();
        if (((DVar2 == 0x57) && (iVar3 = _wcsncmp(lpLibFileName,L"api-ms-",7), iVar3 != 0)) &&
           (iVar3 = _wcsncmp(lpLibFileName,L"ext-ms-",7), iVar3 != 0)) {
          hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0);
        }
        else {
          hLibModule = (HMODULE)0x0;
        }
        if (hLibModule == (HMODULE)0x0) {
          LOCK();
          *piVar1 = -1;
          UNLOCK();
          goto LAB_006e7eb3;
        }
      }
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = (int)hLibModule;
      UNLOCK();
      if (iVar3 != 0) {
        FreeLibrary(hLibModule);
      }
LAB_006e7eaf:
      if (hLibModule != (HINSTANCE__ *)0x0) {
        return hLibModule;
      }
    }
    else if (hLibModule != (HINSTANCE__ *)0xffffffff) goto LAB_006e7eaf;
LAB_006e7eb3:
    param_1 = param_1 + 1;
  } while( true );
}

