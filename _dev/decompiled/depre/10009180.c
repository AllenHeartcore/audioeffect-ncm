
undefined4 * __fastcall FUN_10009180(undefined4 *param_1)

{
  *param_1 = audiofx::AudioEffectsImpl::vftable;
  __Mtx_init_in_situ(param_1 + 1,2);
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *(undefined *)(param_1 + 0x11) = 0;
  param_1[0x12] = 0xffffffff;
  param_1[0x13] = 0x800;
  param_1[0x14] = 0xffffffff;
  param_1[0x15] = 0xffffffff;
  param_1[0x16] = 2;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0xf;
  *(undefined *)(param_1 + 0x9d) = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0xf;
  *(undefined *)(param_1 + 0xa4) = 0;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0xffffffff;
  *(undefined *)((int)param_1 + 0x5d) = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0x3f800000;
  param_1[0xab] = 0;
  param_1[0xac] = 0x3ca3d70a;
  param_1[0xad] = 0x3d23d70a;
  param_1[0xae] = 0;
  param_1[0xb0] = 0x42480000;
  *(undefined *)(param_1 + 0xaf) = 1;
  FUN_1000cb50((int)param_1);
  return param_1;
}

