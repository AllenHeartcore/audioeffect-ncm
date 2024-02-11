
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __fastcall FUN_1015bbe0(uint *param_1,undefined4 param_2,int **param_3)

{
  void **ppvVar1;
  void **ppvVar2;
  int *piVar3;
  code *pcVar4;
  uint *puVar5;
  undefined4 uVar6;
  int iVar7;
  int **ppiVar8;
  uint _Size;
  uint *local_4048;
  undefined4 local_4044;
  int **local_403c;
  int local_4038;
  undefined4 local_4028;
  undefined4 local_4024;
  undefined4 local_4020;
  int local_400c;
  int *local_4008 [4096];
  uint local_8;
  
  local_8 = DAT_10a76ad0 ^ (uint)&stack0xfffffffc;
  local_4028 = 0;
  local_4024 = 0;
  local_4020 = 0;
  local_4048 = (uint *)0x0;
  local_4044 = 0;
  iVar7 = FUN_106e1370((int)&local_4048,0xfffffff1,"1.2.5",0x3c);
  puVar5 = param_1;
  uVar6 = param_2;
  if (iVar7 == 0) {
    do {
      local_4044 = uVar6;
      local_4048 = puVar5;
      local_403c = local_4008;
      local_4038 = 0x4000;
      local_400c = FUN_106dfc00(&local_4048,0);
      if (local_400c == 2) {
        local_400c = -3;
      }
      if (param_3 != (int **)0x0) {
        ppvVar2 = (void **)param_3[5];
        _Size = 0x4000 - local_4038;
        ppiVar8 = param_3;
        if ((void **)0xf < ppvVar2) {
          ppiVar8 = (int **)*param_3;
        }
        if (ppiVar8 <= local_4008) {
          ppiVar8 = param_3;
          if ((void **)0xf < ppvVar2) {
            ppiVar8 = (int **)*param_3;
          }
          if (local_4008 < (int **)((int)param_3[4] + (int)ppiVar8)) {
            if (ppvVar2 < (void **)0x10) {
              FUN_10015a80(param_3,param_3,(int)local_4008 - (int)param_3,_Size);
            }
            else {
              FUN_10015a80(param_3,param_3,(int)local_4008 - (int)*param_3,_Size);
            }
            goto LAB_1015bd98;
          }
        }
        piVar3 = param_3[4];
        if (-(int)piVar3 - 1U <= _Size) {
LAB_1015bdd3:
          FUN_106f03c1("string too long");
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        if (_Size != 0) {
          ppvVar1 = (void **)((int)piVar3 + _Size);
          if (ppvVar1 == (void **)0xffffffff) goto LAB_1015bdd3;
          if (ppvVar2 < ppvVar1) {
            FUN_1000abe0(param_3,ppvVar1,piVar3);
            if (ppvVar1 != (void **)0x0) {
LAB_1015bd45:
              ppiVar8 = param_3;
              if ((int *)0xf < param_3[5]) {
                ppiVar8 = (int **)*param_3;
              }
              if (_Size != 0) {
                FID_conflict__memcpy((void *)((int)param_3[4] + (int)ppiVar8),local_4008,_Size);
              }
              param_3[4] = (int *)ppvVar1;
              ppiVar8 = param_3;
              if ((int *)0xf < param_3[5]) {
                ppiVar8 = (int **)*param_3;
              }
              *(undefined *)((int)ppiVar8 + (int)ppvVar1) = 0;
            }
          }
          else {
            if (ppvVar1 != (void **)0x0) goto LAB_1015bd45;
            param_3[4] = (int *)0x0;
            if (ppvVar2 < (void **)0x10) {
              *(undefined *)param_3 = 0;
            }
            else {
              *(undefined *)*param_3 = 0;
            }
          }
        }
      }
LAB_1015bd98:
      puVar5 = local_4048;
      uVar6 = local_4044;
    } while (local_4038 == 0);
    FUN_106e1320((int)&local_4048);
  }
  FUN_10704e34(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

