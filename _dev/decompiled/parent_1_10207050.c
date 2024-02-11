
void __cdecl FUN_10207050(int param_1,int param_2,int **param_3,char param_4)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int **ppiVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  void **ppvVar8;
  int ****ppppiVar9;
  undefined4 ***pppuVar10;
  bool bVar11;
  undefined auStack_16c [4];
  void *local_168 [6];
  void *local_150 [6];
  void *local_138 [6];
  int local_120 [44];
  uint local_70;
  int ****local_6c [5];
  undefined4 ***local_58;
  undefined local_54;
  undefined4 uStack_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 ***local_34 [4];
  uint local_24;
  uint local_20;
  uint local_1c;
  void *local_14;
  undefined *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_10832245;
  local_14 = ExceptionList;
  local_1c = DAT_10a76ad0 ^ (uint)auStack_16c;
  uVar3 = DAT_10a76ad0 ^ (uint)&stack0xfffffe88;
  ExceptionList = &local_14;
  bVar11 = false;
  local_70 = 0;
  if (param_4 == '\0') {
    ppiVar4 = (int **)FUN_100455d0();
    (**(code **)(**ppiVar4 + 0x18))(1,uVar3);
    iVar5 = FUN_103a6f00();
    if (iVar5 < 1) {
      puVar6 = FUN_103a6090(local_120,"audio_effect.cpp",0xf2,0);
      local_c = 0;
      local_70 = 1;
      FUN_100124b0(puVar6 + 2,"Switch Off AudioEffect.");
    }
    bVar11 = 0 < iVar5;
  }
  else if (param_3[4] == (int *)0x0) {
    iVar5 = FUN_103a6f00();
    if (iVar5 < 1) {
      puVar6 = FUN_103a6090(local_120,"audio_effect.cpp",0xf6,0);
      local_c = 1;
      local_70 = 2;
      FUN_100124b0(puVar6 + 2,"Set AudioEffect  Failed. Path Empty.");
    }
    bVar11 = iVar5 >= 1;
  }
  else {
    if (param_1 - 1U < 2) {
      FUN_100161e0((undefined2 *)local_6c);
      local_c = 3;
      if (param_2 == 1) {
        cVar2 = FUN_103a94b0(2,local_6c);
        if (cVar2 != '\0') {
          ppiVar4 = (int **)FUN_103a40d0((undefined2 *)local_150,param_3);
          local_c = CONCAT31(local_c._1_3_,4);
          FUN_103a3ed0(local_6c,ppiVar4);
          ppvVar8 = local_150;
          goto LAB_10207229;
        }
      }
      else if (param_2 == 2) {
        cVar2 = FUN_1006a790(0,(int **)local_6c);
        if (cVar2 != '\0') {
          ppiVar4 = (int **)FUN_103a40d0((undefined2 *)local_138,param_3);
          local_c = CONCAT31(local_c._1_3_,5);
          FUN_103a3ed0(local_6c,ppiVar4);
          ppvVar8 = local_138;
          goto LAB_10207229;
        }
      }
      else if (param_2 == 3) {
        ppiVar4 = (int **)FUN_103a3e10(local_168,param_3);
        local_c = CONCAT31(local_c._1_3_,6);
        FUN_103a3ed0(local_6c,ppiVar4);
        ppvVar8 = local_168;
LAB_10207229:
        local_c = CONCAT31(local_c._1_3_,3);
        FUN_10016280(ppvVar8);
      }
      bVar1 = FUN_103ab6a0(local_6c);
      if (bVar1) {
        local_20 = 0xf;
        local_24 = 0;
        local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
        local_c._0_1_ = 8;
        cVar2 = FUN_103ac270(local_6c,local_34);
        if (cVar2 == '\0') {
          iVar5 = FUN_103a6f00();
          if (iVar5 < 1) {
            puVar6 = FUN_103a6090(local_120,"audio_effect.cpp",0x115,0);
            local_c = CONCAT31(local_c._1_3_,9);
            local_70 = 0x10;
            FUN_100124b0(puVar6 + 2,"SetAudioEffectParam failed. read effect file error.");
          }
          local_c = 8;
          if (iVar5 < 1) {
            FUN_103a63d0(local_120);
          }
        }
        else {
          local_40 = 0xf;
          local_44 = 0;
          local_54 = 0;
          local_c = CONCAT31(local_c._1_3_,10);
          pppuVar10 = local_34;
          if (0xf < local_20) {
            pppuVar10 = local_34[0];
          }
          local_70 = 1;
          iVar5 = FUN_1015be70((char *)pppuVar10,local_24,(int **)&local_54,&local_70);
          if (iVar5 == 0) {
            if (local_70 == 1) {
              pppuVar10 = (undefined4 ***)&local_54;
              goto LAB_10207511;
            }
            if (local_70 != 2) goto LAB_1020750a;
            local_70 = 0;
            local_38 = 0;
            local_3c = 0;
            FUN_107c3e80(&local_70,&local_38,&local_3c);
            if ((param_1 == 1) && (5 < (int)local_70)) {
              ppiVar4 = (int **)FUN_100455d0();
              (**(code **)(**ppiVar4 + 0x84))();
              ppiVar4 = (int **)FUN_100455d0();
              (**(code **)(**ppiVar4 + 0x74))(1);
              ppiVar4 = (int **)FUN_100455d0();
              pppuVar10 = &local_58;
              if (0xf < local_44) {
                pppuVar10 = local_58;
              }
              (**(code **)(**ppiVar4 + 0x78))(pppuVar10,uStack_48);
              ppiVar4 = (int **)FUN_100455d0();
              (**(code **)(**ppiVar4 + 0x88))();
            }
            else {
              ppiVar4 = (int **)FUN_100455d0();
              (**(code **)(**ppiVar4 + 0x84))();
              ppiVar4 = (int **)FUN_100455d0();
              (**(code **)(**ppiVar4 + 0x6c))(1);
              ppiVar4 = (int **)FUN_100455d0();
              pppuVar10 = &local_58;
              if (0xf < local_44) {
                pppuVar10 = local_58;
              }
              (**(code **)(**ppiVar4 + 0x70))(pppuVar10,uStack_48);
              ppiVar4 = (int **)FUN_100455d0();
              (**(code **)(**ppiVar4 + 0x88))();
            }
          }
          else {
LAB_1020750a:
            pppuVar10 = local_34;
LAB_10207511:
            FUN_10206e00(pppuVar10);
          }
          FUN_1000a6d0((void **)&local_54);
        }
        FUN_1000a6d0(local_34);
      }
      else {
        iVar5 = FUN_103a6f00();
        if (iVar5 < 1) {
          puVar6 = FUN_103a6090(local_120,"audio_effect.cpp",0x110,0);
          local_c = CONCAT31(local_c._1_3_,7);
          bVar11 = true;
          local_70 = 8;
          ppppiVar9 = (int ****)local_6c;
          if ((undefined4 ***)0x7 < local_58) {
            ppppiVar9 = local_6c[0];
          }
          piVar7 = FUN_100124b0(puVar6 + 2,"SetAudioEffectParam failed. path not exist:");
          FUN_103a6800(piVar7,(int **)ppppiVar9);
        }
        local_c = 3;
        if (bVar11) {
          FUN_103a63d0(local_120);
        }
      }
      local_c = 0xffffffff;
      FUN_10016280(local_6c);
      goto LAB_102075a6;
    }
    iVar5 = FUN_103a6f00();
    if (iVar5 < 1) {
      puVar6 = FUN_103a6090(local_120,"audio_effect.cpp",0xfa,0);
      local_c = 2;
      local_70 = 4;
      FUN_100124b0(puVar6 + 2,"Set AudioEffect  Failed.  Error Type.");
    }
    bVar11 = iVar5 >= 1;
  }
  local_c = 0xffffffff;
  if (!bVar11) {
    FUN_103a63d0(local_120);
  }
LAB_102075a6:
  ExceptionList = local_14;
  FUN_10704e34(local_1c ^ (uint)auStack_16c);
  return;
}

