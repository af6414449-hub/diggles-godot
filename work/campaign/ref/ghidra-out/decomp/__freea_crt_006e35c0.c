
/* Library Function - Single Match
    __freea_crt
   
   Library: Visual Studio 2019 Release */

void __freea_crt(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + -8) == 0xdddd)) {
    FID_conflict__free((int *)(param_1 + -8));
  }
  return;
}

