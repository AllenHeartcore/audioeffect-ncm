
undefined4 * __fastcall FUN_10205980(undefined4 *param_1)

{
  int **ppiVar1;
  uint in_stack_ffffffc8;
  int *piVar2;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10831e98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar2 = (int *)(in_stack_ffffffc8 & 0xffffff00);
  FUN_1000a8e0(&stack0xffffffc8,(int **)"audioeffect",(void **)0xb);
  FUN_10207da0(param_1,piVar2);
  local_8 = 0;
  *param_1 = plugin::AudioEffect::vftable;
  param_1[9] = 0;
  ppiVar1 = (int **)FUN_100455d0();
  (**(code **)(**ppiVar1 + 0x84))();
  ExceptionList = local_10;
  return param_1;
}

