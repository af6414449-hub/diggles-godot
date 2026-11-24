
void FUN_1003fe8c(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10050898);
  do {
    if (*param_1 == 0) {
      *param_1 = -1;
LAB_1003fed3:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10050898);
      return;
    }
    if (*param_1 != -1) {
      *(undefined4 *)(*(int *)((int)ThreadLocalStoragePointer + _tls_index * 4) + 4) = DAT_10050000;
      goto LAB_1003fed3;
    }
    __Init_thread_wait(100);
  } while( true );
}

