
void __fastcall FUN_10009290(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  code *pcVar3;
  int iVar4;
  void *pvVar5;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100b63e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = param_1 + 1;
  *param_1 = audiofx::AudioEffectsImpl::vftable;
  iVar4 = __Mtx_lock((_Mtx_internal_imp_t *)puVar1);
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  FUN_1000ca90((int)param_1);
  local_8 = 0;
  iVar4 = __Mtx_unlock((int)puVar1);
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  if (0xf < (uint)param_1[0xa9]) {
    pvVar2 = (void *)param_1[0xa4];
    pvVar5 = pvVar2;
    if ((0xfff < param_1[0xa9] + 1) &&
       (pvVar5 = *(void **)((int)pvVar2 + -4), 0x1f < (uint)((int)pvVar2 + (-4 - (int)pvVar5))))
    goto LAB_100093b9;
    FUN_10052444(pvVar5);
  }
  param_1[0xa8] = 0;
  param_1[0xa9] = 0xf;
  *(undefined *)(param_1 + 0xa4) = 0;
  if (0xf < (uint)param_1[0xa2]) {
    pvVar2 = (void *)param_1[0x9d];
    pvVar5 = pvVar2;
    if ((0xfff < param_1[0xa2] + 1) &&
       (pvVar5 = *(void **)((int)pvVar2 + -4), 0x1f < (uint)((int)pvVar2 + (-4 - (int)pvVar5)))) {
LAB_100093b9:
      FUN_1007fad7();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_10052444(pvVar5);
  }
  param_1[0xa1] = 0;
  param_1[0xa2] = 0xf;
  *(undefined *)(param_1 + 0x9d) = 0;
  __Mtx_destroy_in_situ((int)puVar1);
  ExceptionList = local_10;
  return;
}

