
/* Library Function - Single Match
    public: char * __thiscall <lambda_b37934c380d97b75fd242ea49540127a>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

char * __thiscall
<lambda_b37934c380d97b75fd242ea49540127a>::operator()
          (<lambda_b37934c380d97b75fd242ea49540127a> *this)

{
  int iVar1;
  pthreadlocinfo ptVar2;
  wchar_t *pwVar3;
  errno_t eVar4;
  wchar_t *_Memory;
  localeinfo_struct local_14;
  int local_c;
  size_t local_8;
  
  pwVar3 = (wchar_t *)call_wsetlocale(**(undefined4 **)this,**(undefined4 **)(this + 4));
  if (pwVar3 != (wchar_t *)0x0) {
    local_c = ___acrt_getptd();
    local_14.locinfo = *(pthreadlocinfo *)(local_c + 0x4c);
    local_14.mbcinfo = *(pthreadmbcinfo *)(local_c + 0x48);
    local_8 = 0;
    eVar4 = __wcstombs_s_l(&local_8,(char *)0x0,0,pwVar3,0,&local_14);
    if (eVar4 == 0) {
      _Memory = (wchar_t *)__malloc_base(local_8 + 4);
      if (_Memory != (wchar_t *)0x0) {
        eVar4 = __wcstombs_s_l((size_t *)0x0,(char *)(_Memory + 2),local_8,pwVar3,0xffffffff,
                               &local_14);
        ptVar2 = local_14.locinfo;
        if (eVar4 == 0) {
          pwVar3 = (local_14.locinfo)->lc_category[**(int **)this + 1].wlocale;
          if (pwVar3 != (wchar_t *)0x0) {
            LOCK();
            iVar1 = *(int *)pwVar3;
            *(int *)pwVar3 = iVar1 + -1;
            UNLOCK();
            if (iVar1 + -1 == 0) {
              FID_conflict__free((local_14.locinfo)->lc_category[**(int **)this + 1].wlocale);
              ptVar2->lc_category[**(int **)this + 1].wlocale = (wchar_t *)0x0;
            }
          }
          if ((((*(byte *)(local_c + 0x350) & 2) == 0) && (((byte)DAT_007673b0 & 1) == 0)) &&
             (pwVar3 = ptVar2->lc_category[**(int **)this + 1].wlocale, pwVar3 != (wchar_t *)0x0)) {
            LOCK();
            iVar1 = *(int *)pwVar3;
            *(int *)pwVar3 = *(int *)pwVar3 + -1;
            UNLOCK();
            if (iVar1 == 1) {
              FID_conflict__free(ptVar2->lc_category[**(int **)this + 1].wlocale);
              ptVar2->lc_category[**(int **)this + 1].wlocale = (wchar_t *)0x0;
            }
          }
          *(uint *)_Memory = ptVar2->lc_time_cp;
          ptVar2->lc_category[**(int **)this + 1].wlocale = _Memory;
          ptVar2->lc_category[**(int **)this].wrefcount = (int *)(_Memory + 2);
          return (char *)(_Memory + 2);
        }
        if ((eVar4 == 0x16) || (eVar4 == 0x22)) goto LAB_006df553;
        FID_conflict__free(_Memory);
      }
    }
    else if ((eVar4 == 0x16) || (eVar4 == 0x22)) {
LAB_006df553:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  return (char *)0x0;
}

