
/* Library Function - Single Match
    ___std_exception_destroy
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___std_exception_destroy(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_006df631(*param_1);
  }
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}

