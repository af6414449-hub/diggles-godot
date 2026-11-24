
/* public: static class PostProcessOptionManager * __cdecl
   PostProcessOptionManager::GetInstance(void) */

PostProcessOptionManager * __cdecl PostProcessOptionManager::GetInstance(void)

{
                    /* 0x144a0  151  ?GetInstance@PostProcessOptionManager@@SAPAV1@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (s_instance == (PostProcessOptionManager *)0x0) {
    s_instance = (PostProcessOptionManager *)FUN_1003ff62(0x14);
    *(undefined4 *)s_instance = 0;
    *(undefined4 *)(s_instance + 4) = 0;
    *(undefined4 *)(s_instance + 8) = 0;
    *(undefined4 *)(s_instance + 0xc) = 0;
    *(undefined4 *)(s_instance + 0x10) = 0;
  }
  return s_instance;
}

