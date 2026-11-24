
/* Library Function - Single Match
    _mbstowcs_s
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl
_mbstowcs_s(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,char *_SrcBuf,
           size_t _MaxCount)

{
  errno_t eVar1;
  
  eVar1 = __mbstowcs_s_l(_PtNumOfCharConverted,_DstBuf,_SizeInWords,_SrcBuf,_MaxCount,(_locale_t)0x0
                        );
  return eVar1;
}

