
/* public: static int __cdecl CSdlInformWindowHandle::GetDisplayIndex(struct SDL_Window *) */

int __cdecl CSdlInformWindowHandle::GetDisplayIndex(SDL_Window *param_1)

{
  int iVar1;
  
                    /* 0x142d0  136  ?GetDisplayIndex@CSdlInformWindowHandle@@SAHPAUSDL_Window@@@Z
                        */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
                    /* WARNING: Could not recover jumptable at 0x100142de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = SDL_GetWindowDisplayIndex();
  return iVar1;
}

