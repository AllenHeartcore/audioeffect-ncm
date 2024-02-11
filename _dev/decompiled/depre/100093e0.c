
undefined4 * __thiscall FUN_100093e0(void *this,byte param_1)

{
  _Mtx_internal_imp_t *p_Var1;
  void *pvVar2;
  code *pcVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *puVar6;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_100b6400;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  p_Var1 = (_Mtx_internal_imp_t *)((int)this + 4);
  local_8 = 0;
  *(undefined ***)this = audiofx::AudioEffectsImpl::vftable;
  iVar4 = __Mtx_lock(p_Var1);
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  FUN_1000ca90((int)this);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar4 = __Mtx_unlock((int)p_Var1);
  if (iVar4 != 0) {
    std::_Throw_C_error(iVar4);
  }
  if (0xf < *(uint *)((int)this + 0x2a4)) {
    pvVar2 = *(void **)((int)this + 0x290);
    pvVar5 = pvVar2;
    if ((0xfff < *(uint *)((int)this + 0x2a4) + 1) &&
       (pvVar5 = *(void **)((int)pvVar2 + -4), 0x1f < (uint)((int)pvVar2 + (-4 - (int)pvVar5))))
    goto LAB_10009525;
    FUN_10052444(pvVar5);
  }
  *(undefined4 *)((int)this + 0x2a0) = 0;
  *(undefined4 *)((int)this + 0x2a4) = 0xf;
  *(undefined *)((int)this + 0x290) = 0;
  if (0xf < *(uint *)((int)this + 0x288)) {
    pvVar2 = *(void **)((int)this + 0x274);
    pvVar5 = pvVar2;
    if ((0xfff < *(uint *)((int)this + 0x288) + 1) &&
       (pvVar5 = *(void **)((int)pvVar2 + -4), 0x1f < (uint)((int)pvVar2 + (-4 - (int)pvVar5)))) {
LAB_10009525:
      FUN_1007fad7();
      pcVar3 = (code *)swi(3);
      puVar6 = (undefined4 *)(*pcVar3)();
      return puVar6;
    }
    FUN_10052444(pvVar5);
  }
  *(undefined4 *)((int)this + 0x284) = 0;
  *(undefined4 *)((int)this + 0x288) = 0xf;
  *(undefined *)((int)this + 0x274) = 0;
  __Mtx_destroy_in_situ((int)p_Var1);
  if ((param_1 & 1) != 0) {
    FUN_10052444(this);
  }
  ExceptionList = local_10;
  return (undefined4 *)this;
}

