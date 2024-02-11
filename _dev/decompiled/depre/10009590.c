
/* public: static class audiofx::AudioEffects * __cdecl audiofx::AudioEffects::Create(void) */

AudioEffects * __cdecl audiofx::AudioEffects::Create(void)

{
  undefined4 *puVar1;
  
                    /* 0x9590  17  ?Create@AudioEffects@audiofx@@SAPAV12@XZ */
  puVar1 = (undefined4 *)FUN_10052414(0x2cc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = AudioEffectsImpl::vftable;
    __Mtx_init_in_situ(puVar1 + 1,2);
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
    puVar1[0x10] = 0;
    *(undefined *)(puVar1 + 0x11) = 0;
    puVar1[0x12] = 0xffffffff;
    puVar1[0x13] = 0x800;
    puVar1[0x14] = 0xffffffff;
    puVar1[0x15] = 0xffffffff;
    puVar1[0x16] = 2;
    puVar1[0xa1] = 0;
    puVar1[0xa2] = 0xf;
    *(undefined *)(puVar1 + 0x9d) = 0;
    puVar1[0xa8] = 0;
    puVar1[0xa9] = 0xf;
    *(undefined *)(puVar1 + 0xa4) = 0;
    puVar1[0xb1] = 0;
    puVar1[0xb2] = 0xffffffff;
    *(undefined *)((int)puVar1 + 0x5d) = 0;
    puVar1[0x18] = 0;
    puVar1[0x19] = 0x3f800000;
    puVar1[0xab] = 0;
    puVar1[0xac] = 0x3ca3d70a;
    puVar1[0xad] = 0x3d23d70a;
    puVar1[0xae] = 0;
    puVar1[0xb0] = 0x42480000;
    *(undefined *)(puVar1 + 0xaf) = 1;
    FUN_1000cb50((int)puVar1);
    return (AudioEffects *)puVar1;
  }
  return (AudioEffects *)0x0;
}

