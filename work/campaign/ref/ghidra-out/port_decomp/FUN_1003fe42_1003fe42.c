
void FUN_1003fe42(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10050898);
  DAT_10050000 = DAT_10050000 + 1;
  *param_1 = DAT_10050000;
  *(int *)(*(int *)((int)ThreadLocalStoragePointer + _tls_index * 4) + 4) = DAT_10050000;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10050898);
  __Init_thread_notify();
  return;
}

