
/* Library Function - Single Match
    struct HINSTANCE__ * __cdecl try_get_first_available_module(enum `anonymous
   namespace'::module_id const * const,enum `anonymous namespace'::module_id const * const)
   
   Library: Visual Studio 2019 Release */

HINSTANCE__ * __cdecl try_get_first_available_module(module_id *param_1,module_id *param_2)

{
  int *piVar1;
  HINSTANCE__ *pHVar2;
  LPCWSTR lpLibFileName;
  HMODULE hLibModule;
  DWORD DVar3;
  int iVar4;
  
  do {
    if (param_1 == param_2) {
      return (HINSTANCE__ *)0x0;
    }
    piVar1 = (int *)(&DAT_00769b1c + *param_1 * 4);
    pHVar2 = (HINSTANCE__ *)*piVar1;
    if (pHVar2 == (HINSTANCE__ *)0x0) {
      lpLibFileName = (LPCWSTR)(&PTR_u_api_ms_win_core_fibers_l1_1_1_00716174)[*param_1];
      hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0x800);
      if ((hLibModule != (HMODULE)0x0) ||
         (((DVar3 = GetLastError(), DVar3 == 0x57 &&
           (iVar4 = _wcsncmp(lpLibFileName,L"api-ms-",7), iVar4 != 0)) &&
          (hLibModule = LoadLibraryExW(lpLibFileName,(HANDLE)0x0,0), hLibModule != (HMODULE)0x0))))
      {
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = (int)hLibModule;
        UNLOCK();
        if (iVar4 == 0) {
          return hLibModule;
        }
        FreeLibrary(hLibModule);
        return hLibModule;
      }
      LOCK();
      *piVar1 = -1;
      UNLOCK();
    }
    else if (pHVar2 != (HINSTANCE__ *)0xffffffff) {
      return pHVar2;
    }
    param_1 = param_1 + 1;
  } while( true );
}

