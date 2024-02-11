
void __thiscall FUN_1000abe0(void *this,void **param_1,void *param_2)

{
  uint uVar1;
  code *pcVar2;
  void *_Src;
  uint uVar3;
  void **ppvVar4;
  void **ppvVar5;
  
  ppvVar4 = (void **)((uint)param_1 | 0xf);
  ppvVar5 = param_1;
  if (ppvVar4 != (void **)0xffffffff) {
    uVar1 = *(uint *)((int)this + 0x14);
    uVar3 = uVar1 >> 1;
    ppvVar5 = ppvVar4;
    if (((uint)ppvVar4 / 3 < uVar3) && (ppvVar5 = (void **)(uVar3 + uVar1), -uVar3 - 2 < uVar1)) {
      ppvVar5 = (void **)0xfffffffe;
    }
  }
  param_1 = (void **)0x0;
  if (((int)ppvVar5 + 1U != 0) &&
     (param_1 = (void **)FUN_10705677((int)ppvVar5 + 1U), param_1 == (void **)0x0)) {
    FUN_106f033e();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (param_2 != (void *)0x0) {
    _Src = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      _Src = *this;
    }
    if (param_2 != (void *)0x0) {
      FID_conflict__memcpy(param_1,_Src,(size_t)param_2);
    }
  }
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    FID_conflict__free(*this);
  }
  *(undefined *)this = 0;
  *(void ***)this = param_1;
  *(void ***)((int)this + 0x14) = ppvVar5;
  *(void **)((int)this + 0x10) = param_2;
  if ((void **)0xf < ppvVar5) {
    this = param_1;
  }
  *(undefined *)((int)this + (int)param_2) = 0;
  return;
}

