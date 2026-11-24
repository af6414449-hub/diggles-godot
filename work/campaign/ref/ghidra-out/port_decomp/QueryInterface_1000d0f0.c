
/* public: virtual long __stdcall CPlayer::QueryInterface(struct _GUID const &,void * *) */

long CPlayer::QueryInterface(_GUID *param_1,void **param_2)

{
  HRESULT HVar1;
  void **in_stack_0000000c;
  
                    /* 0xd0f0  218  ?QueryInterface@CPlayer@@UAGJABU_GUID@@PAPAX@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  HVar1 = QISearch(param_1,(LPCQITAB)&PTR_DAT_10045068,(IID *)param_2,in_stack_0000000c);
  return HVar1;
}

