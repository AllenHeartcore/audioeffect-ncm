
AudioEffects ** __fastcall FUN_10045380(AudioEffects **param_1)

{
  AudioEffects *pAVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_10810ae1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = (AudioEffects *)0x0;
  param_1[1] = (AudioEffects *)0x0;
  param_1[2] = (AudioEffects *)audiofx::AudioEffectLogger::vftable;
  local_8 = 0;
  pAVar1 = audiofx::AudioEffects::Create();
  *param_1 = pAVar1;
  puVar2 = (undefined4 *)FUN_10705677(0x38);
  local_8._0_1_ = 1;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    FUN_103a7580((LPCRITICAL_SECTION)(puVar2 + 1));
    local_8 = CONCAT31(local_8._1_3_,2);
    *(undefined8 *)(puVar2 + 8) = 0x3ff0000000000000;
    *(undefined2 *)(puVar2 + 10) = 0;
    *(undefined8 *)(puVar2 + 0xc) = 0x3ff0000000000000;
    puVar3 = FUN_1075dea0();
    *puVar2 = puVar3;
    param_1[1] = (AudioEffects *)puVar2;
    ExceptionList = local_10;
    return param_1;
  }
  param_1[1] = (AudioEffects *)0x0;
  ExceptionList = local_10;
  return param_1;
}

