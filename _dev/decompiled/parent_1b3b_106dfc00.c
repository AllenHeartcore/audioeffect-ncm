
int __cdecl FUN_106dfc00(uint **param_1,int param_2)

{
  uint *puVar1;
  uint **ppuVar2;
  byte bVar3;
  undefined2 uVar4;
  uint *puVar5;
  char cVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  uint *puVar19;
  uint *local_3c;
  uint local_34;
  int local_30;
  undefined4 local_2c;
  uint *local_28;
  uint *local_24;
  undefined2 local_20;
  undefined local_1e;
  undefined local_1d;
  uint *local_1c;
  uint local_18;
  uint *local_14;
  uint *local_10;
  uint *local_c;
  uint local_8;
  
  if ((((param_1 == (uint **)0x0) || (puVar7 = param_1[7], puVar7 == (uint *)0x0)) ||
      (param_1[3] == (uint *)0x0)) || ((*param_1 == (uint *)0x0 && (param_1[1] != (uint *)0x0)))) {
    return -2;
  }
  if (*puVar7 == 0xb) {
    *puVar7 = 0xc;
  }
  local_24 = param_1[3];
  puVar5 = param_1[1];
  uVar16 = puVar7[0xf];
  local_28 = param_1[4];
  uVar17 = puVar7[0xe];
  puVar19 = *param_1;
  local_30 = 0;
  uVar12 = *puVar7;
  if (uVar12 < 0x1f) {
    puVar9 = puVar7 + 0x15;
    puVar1 = puVar7 + 0x16;
    puVar15 = puVar5;
    local_1c = local_28;
    local_18 = uVar16;
    local_14 = puVar19;
    local_10 = puVar5;
    local_c = puVar7;
    local_8 = uVar17;
    do {
      uVar13 = uVar16;
      switch((&switchD_106dfc91::switchdataD_106e1290)[uVar12]) {
      case (undefined *)0x106dfc98:
        puVar18 = puVar7 + 2;
        uVar12 = local_8;
        if (*puVar18 == 0) {
          *puVar7 = 0xc;
        }
        else {
          while (local_8 = uVar12, uVar16 < 0x10) {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
            puVar19 = (uint *)((int)puVar19 + 1);
            uVar16 = uVar16 + 8;
            puVar7 = local_c;
            local_18 = uVar16;
            local_14 = puVar19;
            local_10 = puVar15;
            uVar12 = uVar17;
          }
          if (((*puVar18 & 2) == 0) || (uVar17 != 0x8b1f)) {
            puVar7[4] = 0;
            if (puVar7[8] != 0) {
              *(undefined4 *)(puVar7[8] + 0x30) = 0xffffffff;
            }
            uVar13 = uVar17;
            if (((*(byte *)(puVar7 + 2) & 1) == 0) ||
               (puVar7 = local_c, uVar13 = uVar12,
               ((uVar17 >> 8) + (uVar17 & 0xff) * 0x100) % 0x1f != 0)) {
              param_1[6] = (uint *)"incorrect header check";
              *puVar7 = 0x1d;
              uVar17 = uVar13;
            }
            else {
              if (((byte)uVar12 & 0xf) != 8) goto LAB_106dfd79;
              local_8 = uVar12 >> 4;
              uVar16 = uVar16 - 4;
              uVar17 = (local_8 & 0xf) + 8;
              local_18 = uVar16;
              if (local_c[9] == 0) {
                local_c[9] = uVar17;
              }
              else if (local_c[9] < uVar17) {
                param_1[6] = (uint *)"invalid window size";
                *local_c = 0x1d;
                uVar17 = local_8;
                break;
              }
              local_c[5] = 1 << (sbyte)uVar17;
              puVar7 = (uint *)FUN_106e20a0(0,(byte *)0x0,0);
              local_c[6] = (uint)puVar7;
              param_1[0xc] = puVar7;
              *local_c = ~(local_8 >> 8) & 2 | 9;
              uVar16 = 0;
              local_8 = 0;
              local_18 = 0;
              puVar7 = local_c;
              uVar17 = 0;
            }
          }
          else {
            uVar17 = FUN_106e2310(0,(uint *)0x0,0);
            local_c[6] = uVar17;
            local_20 = 0x8b1f;
            uVar17 = FUN_106e2310(local_c[6],(uint *)&local_20,2);
            local_8 = 0;
            uVar16 = 0;
            local_18 = 0;
            local_c[6] = uVar17;
            *local_c = 1;
            puVar7 = local_c;
            uVar17 = 0;
          }
        }
        break;
      case (undefined *)0x106dfe26:
        uVar12 = uVar17;
        while (uVar16 < 0x10) {
          if (puVar15 == (uint *)0x0) goto LAB_106e117f;
          puVar15 = (uint *)((int)puVar15 + -1);
          uVar12 = uVar12 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
          puVar19 = (uint *)((int)puVar19 + 1);
          uVar16 = uVar16 + 8;
          puVar7 = local_c;
          local_18 = uVar16;
          local_14 = puVar19;
          local_10 = puVar15;
          local_8 = uVar12;
        }
        puVar7[4] = uVar12;
        if ((char)uVar12 == '\b') {
          if ((uVar12 & 0xe000) == 0) {
            if ((uint *)puVar7[8] != (uint *)0x0) {
              *(uint *)puVar7[8] = uVar12 >> 8 & 1;
            }
            if ((puVar7[4] & 0x200) != 0) {
              local_20 = (undefined2)uVar12;
              uVar17 = FUN_106e2310(puVar7[6],(uint *)&local_20,2);
              local_c[6] = uVar17;
              puVar7 = local_c;
            }
            uVar17 = 0;
            *puVar7 = 2;
            local_8 = 0;
            uVar16 = 0;
            do {
              if (puVar15 == (uint *)0x0) goto LAB_106e117f;
              puVar15 = (uint *)((int)puVar15 + -1);
              uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
              puVar19 = (uint *)((int)puVar19 + 1);
              uVar16 = uVar16 + 8;
              puVar7 = local_c;
              local_14 = puVar19;
              local_10 = puVar15;
              local_8 = uVar17;
joined_r0x106dfecf:
            } while (uVar16 < 0x20);
            if (puVar7[8] != 0) {
              *(uint *)(puVar7[8] + 4) = uVar17;
            }
            if ((puVar7[4] & 0x200) != 0) {
              local_20 = (undefined2)uVar17;
              local_1e = (undefined)(uVar17 >> 0x10);
              local_1d = (undefined)(uVar17 >> 0x18);
              uVar17 = FUN_106e2310(puVar7[6],(uint *)&local_20,4);
              local_c[6] = uVar17;
              puVar7 = local_c;
            }
            uVar17 = 0;
            *puVar7 = 3;
            local_8 = 0;
            uVar16 = 0;
            do {
              if (puVar15 == (uint *)0x0) goto LAB_106e117f;
              puVar15 = (uint *)((int)puVar15 + -1);
              uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
              puVar19 = (uint *)((int)puVar19 + 1);
              uVar16 = uVar16 + 8;
              puVar7 = local_c;
              local_14 = puVar19;
              local_10 = puVar15;
              local_8 = uVar17;
joined_r0x106dff4d:
            } while (uVar16 < 0x10);
            if (puVar7[8] != 0) {
              *(uint *)(puVar7[8] + 8) = uVar17 & 0xff;
              *(uint *)(local_c[8] + 0xc) = uVar17 >> 8;
              puVar7 = local_c;
            }
            if ((puVar7[4] & 0x200) != 0) {
              local_20 = (undefined2)uVar17;
              uVar17 = FUN_106e2310(puVar7[6],(uint *)&local_20,2);
              local_c[6] = uVar17;
              puVar7 = local_c;
            }
            uVar17 = 0;
            *puVar7 = 4;
            uVar16 = 0;
            local_8 = 0;
            local_18 = 0;
            goto switchD_106dfc91_caseD_106dffce;
          }
          param_1[6] = (uint *)"unknown header flags set";
          *puVar7 = 0x1d;
          uVar17 = uVar12;
        }
        else {
LAB_106dfd79:
          param_1[6] = (uint *)"unknown compression method";
          *puVar7 = 0x1d;
          uVar17 = uVar12;
        }
        break;
      case (undefined *)0x106dfecc:
        goto joined_r0x106dfecf;
      case (undefined *)0x106dff4a:
        goto joined_r0x106dff4d;
      case (undefined *)0x106dffce:
switchD_106dfc91_caseD_106dffce:
        if ((puVar7[4] & 0x400) == 0) {
          if (puVar7[8] != 0) {
            *(undefined4 *)(puVar7[8] + 0x10) = 0;
          }
        }
        else {
          for (; uVar16 < 0x10; uVar16 = uVar16 + 8) {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
            puVar19 = (uint *)((int)puVar19 + 1);
            puVar7 = local_c;
            local_14 = puVar19;
            local_10 = puVar15;
            local_8 = uVar17;
          }
          puVar7[0x10] = uVar17;
          if (puVar7[8] != 0) {
            *(uint *)(puVar7[8] + 0x14) = uVar17;
          }
          if ((puVar7[4] & 0x200) != 0) {
            local_20 = (undefined2)uVar17;
            uVar17 = FUN_106e2310(puVar7[6],(uint *)&local_20,2);
            local_c[6] = uVar17;
            puVar7 = local_c;
          }
          uVar16 = 0;
          local_8 = 0;
          local_18 = 0;
        }
        *puVar7 = 5;
      case (undefined *)0x106e005f:
        if ((puVar7[4] & 0x400) == 0) {
LAB_106e00fc:
          puVar7[0x10] = 0;
          *puVar7 = 6;
switchD_106dfc91_caseD_106e0109:
          uVar13 = local_18;
          if ((puVar7[4] & 0x800) == 0) {
            uVar13 = uVar16;
            if (puVar7[8] != 0) {
              *(undefined4 *)(puVar7[8] + 0x1c) = 0;
            }
LAB_106e01a7:
            puVar7[0x10] = 0;
            *puVar7 = 7;
switchD_106dfc91_caseD_106e01b4:
            uVar12 = local_18;
            if ((puVar7[4] & 0x1000) == 0) {
              uVar12 = uVar13;
              if (puVar7[8] != 0) {
                *(undefined4 *)(puVar7[8] + 0x24) = 0;
              }
LAB_106e0257:
              *puVar7 = 8;
              uVar17 = local_8;
              uVar16 = uVar12;
switchD_106dfc91_caseD_106e0260:
              if ((puVar7[4] & 0x200) != 0) {
                while (uVar16 < 0x10) {
                  if (puVar15 == (uint *)0x0) goto LAB_106e117f;
                  puVar15 = (uint *)((int)puVar15 + -1);
                  uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
                  puVar19 = (uint *)((int)puVar19 + 1);
                  uVar16 = uVar16 + 8;
                  puVar7 = local_c;
                  local_18 = uVar16;
                  local_14 = puVar19;
                  local_10 = puVar15;
                  local_8 = uVar17;
                }
                if (uVar17 != *(ushort *)(puVar7 + 6)) {
                  param_1[6] = (uint *)"header crc mismatch";
                  *puVar7 = 0x1d;
                  break;
                }
                uVar16 = 0;
                local_8 = 0;
                local_18 = 0;
              }
              if (puVar7[8] != 0) {
                *(uint *)(puVar7[8] + 0x2c) = (int)puVar7[4] >> 9 & 1;
                *(undefined4 *)(puVar7[8] + 0x30) = 1;
              }
              puVar7 = (uint *)FUN_106e2310(0,(uint *)0x0,0);
              local_c[6] = (uint)puVar7;
              param_1[0xc] = puVar7;
              *local_c = 0xb;
              puVar7 = local_c;
              uVar17 = local_8;
              break;
            }
            uVar16 = uVar13;
            if (puVar15 != (uint *)0x0) {
              puVar18 = (uint *)0x0;
              do {
                cVar6 = *(char *)((int)puVar18 + (int)puVar19);
                puVar18 = (uint *)((int)puVar18 + 1);
                uVar17 = puVar7[8];
                if (((uVar17 != 0) && (*(int *)(uVar17 + 0x24) != 0)) &&
                   (puVar7[0x10] < *(uint *)(uVar17 + 0x28))) {
                  *(char *)(*(int *)(uVar17 + 0x24) + puVar7[0x10]) = cVar6;
                  puVar7[0x10] = puVar7[0x10] + 1;
                  puVar15 = local_10;
                }
              } while ((cVar6 != '\0') && (puVar18 < puVar15));
              if ((puVar7[4] & 0x200) != 0) {
                uVar17 = FUN_106e2310(puVar7[6],puVar19,(uint)puVar18);
                local_c[6] = uVar17;
                puVar7 = local_c;
              }
              puVar15 = (uint *)((int)puVar15 - (int)puVar18);
              puVar19 = (uint *)((int)puVar19 + (int)puVar18);
              uVar16 = uVar12;
              local_14 = puVar19;
              local_10 = puVar15;
              if (cVar6 == '\0') goto LAB_106e0257;
            }
          }
          else if (puVar15 != (uint *)0x0) {
            puVar18 = (uint *)0x0;
            do {
              cVar6 = *(char *)((int)puVar18 + (int)puVar19);
              puVar18 = (uint *)((int)puVar18 + 1);
              uVar17 = puVar7[8];
              if (((uVar17 != 0) && (*(int *)(uVar17 + 0x1c) != 0)) &&
                 (puVar7[0x10] < *(uint *)(uVar17 + 0x20))) {
                *(char *)(*(int *)(uVar17 + 0x1c) + puVar7[0x10]) = cVar6;
                puVar7[0x10] = puVar7[0x10] + 1;
                puVar15 = local_10;
              }
            } while ((cVar6 != '\0') && (puVar18 < puVar15));
            if ((puVar7[4] & 0x200) != 0) {
              uVar17 = FUN_106e2310(puVar7[6],puVar19,(uint)puVar18);
              local_c[6] = uVar17;
              puVar7 = local_c;
            }
            puVar15 = (uint *)((int)puVar15 - (int)puVar18);
            puVar19 = (uint *)((int)puVar19 + (int)puVar18);
            uVar16 = uVar13;
            local_14 = puVar19;
            local_10 = puVar15;
            if (cVar6 == '\0') goto LAB_106e01a7;
          }
        }
        else {
          puVar18 = (uint *)puVar7[0x10];
          puVar14 = puVar18;
          if (puVar15 < puVar18) {
            puVar14 = puVar15;
          }
          if (puVar14 != (uint *)0x0) {
            uVar17 = puVar7[8];
            if ((uVar17 != 0) && (puVar19 = local_14, *(int *)(uVar17 + 0x10) != 0)) {
              iVar8 = *(int *)(uVar17 + 0x14) - (int)puVar18;
              puVar7 = puVar14;
              if (*(undefined **)(uVar17 + 0x18) < (undefined *)(iVar8 + (int)puVar14)) {
                puVar7 = (uint *)(*(undefined **)(uVar17 + 0x18) + -iVar8);
              }
              FID_conflict__memcpy
                        ((void *)(iVar8 + *(int *)(uVar17 + 0x10)),local_14,(size_t)puVar7);
              puVar7 = local_c;
            }
            if ((puVar7[4] & 0x200) != 0) {
              uVar17 = FUN_106e2310(puVar7[6],puVar19,(uint)puVar14);
              local_c[6] = uVar17;
              puVar7 = local_c;
            }
            puVar15 = (uint *)((int)puVar15 - (int)puVar14);
            puVar19 = (uint *)((int)puVar19 + (int)puVar14);
            puVar7[0x10] = puVar7[0x10] - (int)puVar14;
            local_14 = puVar19;
            local_10 = puVar15;
          }
          if (puVar7[0x10] == 0) goto LAB_106e00fc;
        }
LAB_106e117f:
        puVar7 = local_c;
        param_1[3] = local_24;
        param_1[4] = local_1c;
        param_1[1] = local_10;
        *param_1 = local_14;
        local_c[0xf] = uVar16;
        local_c[0xe] = local_8;
        if (((local_c[10] == 0) && ((0x19 < (int)*local_c || (local_28 == param_1[4])))) ||
           (iVar8 = FUN_106e1670((int)param_1,(int)local_28), iVar8 == 0)) {
          puVar19 = param_1[1];
          uVar17 = (int)local_28 - (int)param_1[4];
          param_1[2] = (uint *)((int)param_1[2] + ((int)puVar5 - (int)puVar19));
          param_1[5] = (uint *)((int)param_1[5] + uVar17);
          puVar7[7] = puVar7[7] + uVar17;
          if ((puVar7[2] != 0) && (uVar17 != 0)) {
            if (puVar7[4] == 0) {
              puVar9 = (uint *)FUN_106e20a0(puVar7[6],(byte *)(uint *)((int)param_1[3] - uVar17),
                                            uVar17);
            }
            else {
              puVar9 = (uint *)FUN_106e2310(puVar7[6],(uint *)((int)param_1[3] - uVar17),uVar17);
            }
            puVar7[6] = (uint)puVar9;
            param_1[0xc] = puVar9;
          }
          uVar12 = *puVar7;
          if ((uVar12 == 0x13) || (uVar12 == 0xe)) {
            iVar8 = 0x100;
          }
          else {
            iVar8 = 0;
          }
          iVar10 = 0;
          if (uVar12 == 0xb) {
            iVar10 = 0x80;
          }
          param_1[0xb] = (uint *)(iVar10 + (-(uint)(puVar7[1] != 0) & 0x40) + iVar8 + puVar7[0xf]);
          if ((((int)puVar5 - (int)puVar19 != 0) || (uVar17 != 0)) && (param_2 != 4)) {
            return local_30;
          }
          if (local_30 == 0) {
            local_30 = -5;
          }
          return local_30;
        }
        *puVar7 = 0x1e;
switchD_106dfc91_caseD_106e11c9:
        return -4;
      case (undefined *)0x106e0109:
        goto switchD_106dfc91_caseD_106e0109;
      case (undefined *)0x106e01b4:
        goto switchD_106dfc91_caseD_106e01b4;
      case (undefined *)0x106e0260:
        goto switchD_106dfc91_caseD_106e0260;
      case (undefined *)0x106e0305:
        for (; uVar16 < 0x20; uVar16 = uVar16 + 8) {
          if (puVar15 == (uint *)0x0) goto LAB_106e117f;
          puVar15 = (uint *)((int)puVar15 + -1);
          uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
          puVar19 = (uint *)((int)puVar19 + 1);
          local_14 = puVar19;
          local_10 = puVar15;
          local_8 = uVar17;
        }
        puVar7 = (uint *)((uVar17 >> 8 & 0xff00) + ((uVar17 & 0xff00) + uVar17 * 0x10000) * 0x100 +
                         (uVar17 >> 0x18));
        local_c[6] = (uint)puVar7;
        param_1[0xc] = puVar7;
        uVar17 = 0;
        local_8 = 0;
        uVar16 = 0;
        *local_c = 10;
        puVar7 = local_c;
      case (undefined *)0x106e0370:
        if (puVar7[3] == 0) {
          param_1[3] = local_24;
          param_1[4] = local_1c;
          *param_1 = puVar19;
          param_1[1] = puVar15;
          local_c[0xf] = uVar16;
          local_c[0xe] = uVar17;
          return 2;
        }
        puVar7 = (uint *)FUN_106e20a0(0,(byte *)0x0,0);
        local_c[6] = (uint)puVar7;
        param_1[0xc] = puVar7;
        *local_c = 0xb;
        puVar7 = local_c;
        uVar17 = local_8;
switchD_106dfc91_caseD_106e039d:
        if ((param_2 == 5) || (param_2 == 6)) goto LAB_106e117f;
switchD_106dfc91_caseD_106e03b2:
        if (puVar7[1] != 0) {
          uVar17 = uVar17 >> (sbyte)(uVar16 & 7);
          uVar16 = uVar16 - (uVar16 & 7);
          *local_c = 0x1a;
          puVar7 = local_c;
          local_18 = uVar16;
          local_8 = uVar17;
          break;
        }
        for (; uVar16 < 3; uVar16 = uVar16 + 8) {
          if (puVar15 == (uint *)0x0) goto LAB_106e117f;
          puVar15 = (uint *)((int)puVar15 + -1);
          uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
          puVar19 = (uint *)((int)puVar19 + 1);
          puVar7 = local_c;
          local_14 = puVar19;
          local_10 = puVar15;
          local_8 = uVar17;
        }
        puVar7[1] = uVar17 & 1;
        switch(uVar17 >> 1 & 3) {
        case 0:
          local_8 = uVar17 >> 3;
          uVar16 = uVar16 - 3;
          *puVar7 = 0xd;
          uVar17 = local_8;
          local_18 = uVar16;
          goto LAB_106e06ed;
        case 1:
          puVar7[0x13] = (uint)&DAT_1096fe48;
          puVar7[0x15] = 9;
          puVar7[0x14] = (uint)&DAT_10970648;
          puVar7[0x16] = 5;
          *puVar7 = 0x13;
          if (param_2 == 6) {
            local_8 = uVar17 >> 3;
            uVar16 = uVar16 - 3;
            goto LAB_106e117f;
          }
          break;
        case 2:
          local_8 = uVar17 >> 3;
          uVar16 = uVar16 - 3;
          *puVar7 = 0x10;
          uVar17 = local_8;
          local_18 = uVar16;
          goto LAB_106e06ed;
        case 3:
          param_1[6] = (uint *)"invalid block type";
          *puVar7 = 0x1d;
        }
        uVar17 = uVar17 >> 3;
        uVar16 = uVar16 - 3;
        local_18 = uVar16;
        local_8 = uVar17;
        break;
      case (undefined *)0x106e039d:
        goto switchD_106dfc91_caseD_106e039d;
      case (undefined *)0x106e03b2:
        goto switchD_106dfc91_caseD_106e03b2;
      case (undefined *)0x106e04a7:
        local_8 = uVar17 >> (sbyte)(uVar16 & 7);
        for (uVar16 = uVar16 - (uVar16 & 7); local_18 = uVar16, uVar16 < 0x20; uVar16 = uVar16 + 8)
        {
          if (puVar15 == (uint *)0x0) goto LAB_106e117f;
          puVar15 = (uint *)((int)puVar15 + -1);
          local_8 = local_8 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
          puVar19 = (uint *)((int)puVar19 + 1);
          local_14 = puVar19;
          local_10 = puVar15;
        }
        if ((local_8 & 0xffff) == ~local_8 >> 0x10) {
          uVar17 = 0;
          uVar16 = 0;
          local_c[0x10] = local_8 & 0xffff;
          local_8 = 0;
          local_18 = 0;
          *local_c = 0xe;
          puVar7 = local_c;
          if (param_2 != 6) goto switchD_106dfc91_caseD_106e0535;
          goto LAB_106e117f;
        }
        param_1[6] = (uint *)"invalid stored block lengths";
        *local_c = 0x1d;
        puVar7 = local_c;
        uVar17 = local_8;
        break;
      case (undefined *)0x106e0535:
switchD_106dfc91_caseD_106e0535:
        *puVar7 = 0xf;
      case (undefined *)0x106e053b:
        puVar18 = (uint *)puVar7[0x10];
        if (puVar18 == (uint *)0x0) {
LAB_106e0c73:
          *puVar7 = 0xb;
          break;
        }
        if (puVar15 < puVar18) {
          puVar18 = puVar15;
        }
        if (local_1c < puVar18) {
          puVar18 = local_1c;
        }
        if (puVar18 != (uint *)0x0) {
          FID_conflict__memcpy(local_24,puVar19,(size_t)puVar18);
          puVar15 = (uint *)((int)puVar15 - (int)puVar18);
          local_1c = (uint *)((int)local_1c - (int)puVar18);
          puVar19 = (uint *)((int)puVar19 + (int)puVar18);
          local_24 = (uint *)((int)local_24 + (int)puVar18);
          local_c[0x10] = local_c[0x10] - (int)puVar18;
          puVar7 = local_c;
          uVar17 = local_8;
          local_14 = puVar19;
          local_10 = puVar15;
          break;
        }
        goto LAB_106e117f;
      case (undefined *)0x106e0588:
        for (; uVar16 < 0xe; uVar16 = uVar16 + 8) {
          if (puVar15 == (uint *)0x0) goto LAB_106e117f;
          puVar15 = (uint *)((int)puVar15 + -1);
          uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
          puVar19 = (uint *)((int)puVar19 + 1);
          puVar7 = local_c;
          local_14 = puVar19;
          local_10 = puVar15;
          local_8 = uVar17;
        }
        uVar16 = uVar16 - 0xe;
        puVar7[0x18] = (uVar17 & 0x1f) + 0x101;
        uVar12 = uVar17 >> 10;
        puVar7[0x19] = (uVar17 >> 5 & 0x1f) + 1;
        uVar17 = uVar17 >> 0xe;
        puVar7[0x17] = (uVar12 & 0xf) + 4;
        local_18 = uVar16;
        local_8 = uVar17;
        if ((puVar7[0x18] < 0x11f) && (puVar7[0x19] < 0x1f)) {
          puVar7[0x1a] = 0;
          *puVar7 = 0x11;
          goto switchD_106dfc91_caseD_106e060e;
        }
        param_1[6] = (uint *)"too many length or distance symbols";
        *puVar7 = 0x1d;
        break;
      case (undefined *)0x106e060e:
switchD_106dfc91_caseD_106e060e:
        puVar18 = puVar19;
        if (puVar7[0x1a] < puVar7[0x17]) {
          do {
            for (; puVar19 = local_14, local_14 = puVar19, uVar16 < 3; uVar16 = uVar16 + 8) {
              if (puVar15 == (uint *)0x0) goto LAB_106e117f;
              puVar15 = (uint *)((int)puVar15 + -1);
              local_8 = uVar17 + ((uint)*(byte *)puVar18 << ((byte)uVar16 & 0x1f));
              puVar18 = (uint *)((int)puVar18 + 1);
              uVar17 = local_8;
              local_14 = puVar18;
              local_10 = puVar15;
            }
            local_8 = uVar17 >> 3;
            uVar16 = uVar16 - 3;
            *(ushort *)
             ((int)local_c + (uint)*(ushort *)(&DAT_109706c8 + local_c[0x1a] * 2) * 2 + 0x70) =
                 (ushort)uVar17 & 7;
            local_c[0x1a] = local_c[0x1a] + 1;
            puVar7 = local_c;
            local_18 = uVar16;
            uVar17 = local_8;
            puVar18 = puVar19;
          } while (local_c[0x1a] < local_c[0x17]);
        }
        uVar17 = puVar7[0x1a];
        while (uVar17 < 0x13) {
          *(undefined2 *)
           ((int)puVar7 + (uint)*(ushort *)(&DAT_109706c8 + puVar7[0x1a] * 2) * 2 + 0x70) = 0;
          puVar7[0x1a] = puVar7[0x1a] + 1;
          uVar17 = puVar7[0x1a];
        }
        local_c[0x13] = (uint)(puVar7 + 0x14c);
        puVar7[0x1b] = (uint)(puVar7 + 0x14c);
        local_c[0x15] = 7;
        local_30 = FUN_106e4080(0,(int)(local_c + 0x1c),0x13,(int *)(puVar7 + 0x1b),local_c + 0x15,
                                (ushort *)(local_c + 0xbc));
        puVar7 = local_c;
        if (local_30 == 0) {
          local_c[0x1a] = 0;
          *local_c = 0x12;
          goto switchD_106dfc91_caseD_106e0723;
        }
        param_1[6] = (uint *)"invalid code lengths set";
LAB_106e06e4:
        *puVar7 = 0x1d;
        uVar17 = local_8;
        break;
      case (undefined *)0x106e0723:
switchD_106dfc91_caseD_106e0723:
        local_34 = puVar7[0x1a];
        if (local_34 < puVar7[0x19] + puVar7[0x18]) {
          do {
            uVar17 = *(uint *)(local_c[0x13] + ((1 << ((byte)*puVar9 & 0x1f)) - 1U & local_8) * 4);
            if (uVar16 < (uVar17 >> 8 & 0xff)) {
              do {
                if (puVar15 == (uint *)0x0) goto LAB_106e117f;
                local_8 = local_8 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
                puVar15 = (uint *)((int)puVar15 + -1);
                puVar19 = (uint *)((int)puVar19 + 1);
                uVar16 = uVar16 + 8;
                uVar17 = *(uint *)(local_c[0x13] +
                                  ((1 << ((byte)*puVar9 & 0x1f)) - 1U & local_8) * 4);
                local_14 = puVar19;
                local_10 = puVar15;
              } while (uVar16 < (uVar17 >> 8 & 0xff));
            }
            local_2c._2_2_ = (short)(uVar17 >> 0x10);
            bVar11 = (byte)(uVar17 >> 8);
            puVar7 = local_c;
            if (uVar17 >> 0x10 < 0x10) {
              for (; uVar16 < (uVar17 >> 8 & 0xff); uVar16 = uVar16 + 8) {
                if (puVar15 == (uint *)0x0) goto LAB_106e117f;
                puVar15 = (uint *)((int)puVar15 + -1);
                local_8 = local_8 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
                puVar19 = (uint *)((int)puVar19 + 1);
                local_14 = puVar19;
                local_10 = puVar15;
              }
              local_8 = local_8 >> (bVar11 & 0x1f);
              *(short *)((int)local_c + local_34 * 2 + 0x70) = local_2c._2_2_;
              local_c[0x1a] = local_c[0x1a] + 1;
              local_18 = uVar16 - (uVar17 >> 8 & 0xff);
            }
            else {
              if (local_2c._2_2_ == 0x10) {
                uVar12 = uVar17 >> 8 & 0xff;
                if (uVar16 < uVar12 + 2) {
                  do {
                    if (puVar15 == (uint *)0x0) goto LAB_106e117f;
                    puVar15 = (uint *)((int)puVar15 + -1);
                    local_8 = local_8 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
                    puVar19 = (uint *)((int)puVar19 + 1);
                    uVar16 = uVar16 + 8;
                    local_14 = puVar19;
                    local_10 = puVar15;
                  } while (uVar16 < uVar12 + 2);
                }
                uVar17 = local_8 >> (bVar11 & 0x1f);
                uVar16 = uVar16 - uVar12;
                if (local_34 == 0) {
                  param_1[6] = (uint *)"invalid bit length repeat";
                  *local_c = 0x1d;
                  local_18 = uVar16;
                  local_8 = uVar17;
                  goto LAB_106e06ed;
                }
                uVar4 = *(undefined2 *)((int)local_c + local_34 * 2 + 0x6e);
                local_8 = uVar17 >> 2;
                local_2c = (uVar17 & 3) + 3;
                uVar16 = uVar16 - 2;
              }
              else {
                uVar17 = uVar17 >> 8 & 0xff;
                if (local_2c._2_2_ == 0x11) {
                  if (uVar16 < uVar17 + 3) {
                    do {
                      if (puVar15 == (uint *)0x0) goto LAB_106e117f;
                      puVar15 = (uint *)((int)puVar15 + -1);
                      local_8 = local_8 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
                      puVar19 = (uint *)((int)puVar19 + 1);
                      uVar16 = uVar16 + 8;
                      local_14 = puVar19;
                      local_10 = puVar15;
                    } while (uVar16 < uVar17 + 3);
                  }
                  local_8 = local_8 >> (bVar11 & 0x1f);
                  local_2c = (local_8 & 7) + 3;
                  local_8 = local_8 >> 3;
                  iVar8 = -3;
                }
                else {
                  if (uVar16 < uVar17 + 7) {
                    do {
                      if (puVar15 == (uint *)0x0) goto LAB_106e117f;
                      puVar15 = (uint *)((int)puVar15 + -1);
                      local_8 = local_8 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
                      puVar19 = (uint *)((int)puVar19 + 1);
                      uVar16 = uVar16 + 8;
                      local_14 = puVar19;
                      local_10 = puVar15;
                    } while (uVar16 < uVar17 + 7);
                  }
                  local_8 = local_8 >> (bVar11 & 0x1f);
                  local_2c = (local_8 & 0x7f) + 0xb;
                  local_8 = local_8 >> 7;
                  iVar8 = -7;
                }
                uVar4 = 0;
                uVar16 = uVar16 + (iVar8 - uVar17);
              }
              puVar15 = local_10;
              local_18 = uVar16;
              if (local_c[0x19] + local_c[0x18] < local_2c + local_34) {
                param_1[6] = (uint *)"invalid bit length repeat";
                *local_c = 0x1d;
                uVar17 = local_8;
                goto LAB_106e06ed;
              }
              for (; local_2c != 0; local_2c = local_2c + -1) {
                *(undefined2 *)((int)local_c + local_c[0x1a] * 2 + 0x70) = uVar4;
                local_c[0x1a] = local_c[0x1a] + 1;
                puVar19 = local_14;
              }
            }
            local_34 = local_c[0x1a];
            uVar16 = local_18;
          } while (local_34 < local_c[0x19] + local_c[0x18]);
        }
        uVar17 = local_8;
        if (*puVar7 != 0x1d) {
          if (*(short *)(puVar7 + 0x9c) == 0) {
            param_1[6] = (uint *)"invalid code -- missing end-of-block";
          }
          else {
            puVar7[0x15] = 9;
            ppuVar2 = (uint **)(puVar7 + 0x1b);
            puVar7[0x13] = (uint)(puVar7 + 0x14c);
            *ppuVar2 = puVar7 + 0x14c;
            local_30 = FUN_106e4080(1,(int)(puVar7 + 0x1c),puVar7[0x18],(int *)ppuVar2,puVar7 + 0x15
                                    ,(ushort *)(puVar7 + 0xbc));
            if (local_30 == 0) {
              local_c[0x16] = 6;
              local_c[0x14] = (uint)*ppuVar2;
              local_30 = FUN_106e4080(2,(int)local_c + (local_c[0x18] + 0x38) * 2,local_c[0x19],
                                      (int *)ppuVar2,local_c + 0x16,(ushort *)(local_c + 0xbc));
              puVar7 = local_c;
              if (local_30 == 0) {
                *local_c = 0x13;
                uVar17 = local_8;
                if (param_2 != 6) goto switchD_106dfc91_caseD_106e0a72;
                goto LAB_106e117f;
              }
              param_1[6] = (uint *)"invalid distances set";
            }
            else {
              param_1[6] = (uint *)"invalid literal/lengths set";
              puVar7 = local_c;
            }
          }
          goto LAB_106e06e4;
        }
        break;
      case (undefined *)0x106e0a72:
switchD_106dfc91_caseD_106e0a72:
        *puVar7 = 0x14;
      case (undefined *)0x106e0a78:
        if ((&DAT_00000005 < puVar15) && ((uint *)0x101 < local_1c)) {
          param_1[3] = local_24;
          param_1[4] = local_1c;
          *param_1 = local_14;
          param_1[1] = puVar15;
          puVar7[0xe] = uVar17;
          puVar7[0xf] = uVar16;
          FUN_106e4520((int *)param_1,(uint)local_28);
          local_24 = param_1[3];
          puVar19 = *param_1;
          puVar15 = param_1[1];
          local_1c = param_1[4];
          uVar17 = local_c[0xe];
          uVar16 = local_c[0xf];
          puVar7 = local_c;
          local_18 = uVar16;
          local_14 = puVar19;
          local_10 = puVar15;
          local_8 = uVar17;
          if (*local_c == 0xb) {
            local_c[0x6f1] = 0xffffffff;
          }
          break;
        }
        puVar7[0x6f1] = 0;
        uVar12 = *(uint *)(puVar7[0x13] + ((1 << ((byte)*puVar9 & 0x1f)) - 1U & uVar17) * 4);
        if (uVar16 < (uVar12 >> 8 & 0xff)) {
          do {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
            puVar19 = (uint *)((int)puVar19 + 1);
            uVar16 = uVar16 + 8;
            uVar12 = *(uint *)(local_c[0x13] + ((1 << ((byte)*puVar9 & 0x1f)) - 1U & uVar17) * 4);
            local_14 = puVar19;
            local_10 = puVar15;
            local_8 = uVar17;
          } while (uVar16 < (uVar12 >> 8 & 0xff));
        }
        cVar6 = (char)uVar12;
        uVar13 = uVar12;
        if ((cVar6 != '\0') && ((uVar12 & 0xf0) == 0)) {
          bVar11 = (byte)(uVar12 >> 8);
          uVar13 = *(uint *)(puVar7[0x13] +
                            ((((1 << (cVar6 + bVar11 & 0x1f)) - 1U & local_8) >> (bVar11 & 0x1f)) +
                            (uVar12 >> 0x10)) * 4);
          uVar17 = uVar16;
          if (uVar16 < (uVar13 >> 8 & 0xff) + (uVar12 >> 8 & 0xff)) {
            do {
              uVar16 = uVar17;
              if (local_10 == (uint *)0x0) goto LAB_106e117f;
              local_10 = (uint *)((int)local_10 + -1);
              uVar16 = uVar17 + 8;
              bVar3 = *(byte *)local_14;
              local_14 = (uint *)((int)local_14 + 1);
              local_8 = local_8 + ((uint)bVar3 << ((byte)uVar17 & 0x1f));
              uVar13 = *(uint *)(local_c[0x13] +
                                ((((1 << (cVar6 + bVar11 & 0x1f)) - 1U & local_8) >> (bVar11 & 0x1f)
                                 ) + (uVar12 >> 0x10)) * 4);
              uVar17 = uVar16;
            } while (uVar16 < (uVar13 >> 8 & 0xff) + (uVar12 >> 8 & 0xff));
          }
          uVar12 = uVar12 >> 8 & 0xff;
          uVar17 = local_8 >> (bVar11 & 0x1f);
          uVar16 = uVar16 - uVar12;
          local_c[0x6f1] = uVar12;
          puVar15 = local_10;
        }
        uVar12 = uVar13 >> 8 & 0xff;
        uVar17 = uVar17 >> ((byte)(uVar13 >> 8) & 0x1f);
        uVar16 = uVar16 - uVar12;
        local_c[0x6f1] = local_c[0x6f1] + uVar12;
        local_c[0x10] = uVar13 >> 0x10;
        puVar7 = local_c;
        puVar19 = local_14;
        local_18 = uVar16;
        local_8 = uVar17;
        if ((char)uVar13 == '\0') {
          *local_c = 0x19;
          break;
        }
        if ((uVar13 & 0x20) != 0) {
          local_c[0x6f1] = 0xffffffff;
          goto LAB_106e0c73;
        }
        if ((uVar13 & 0x40) != 0) {
          param_1[6] = (uint *)"invalid literal/length code";
          *local_c = 0x1d;
          break;
        }
        *local_c = 0x15;
        local_c[0x12] = uVar13 & 0xf;
switchD_106dfc91_caseD_106e0ca6:
        uVar12 = puVar7[0x12];
        if (uVar12 != 0) {
          for (; uVar16 < uVar12; uVar16 = uVar16 + 8) {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
            puVar19 = (uint *)((int)puVar19 + 1);
            local_14 = puVar19;
            local_10 = puVar15;
            local_8 = uVar17;
          }
          local_c[0x10] = local_c[0x10] + ((1 << ((byte)uVar12 & 0x1f)) - 1U & uVar17);
          uVar17 = uVar17 >> ((byte)uVar12 & 0x1f);
          uVar16 = uVar16 - uVar12;
          local_c[0x6f1] = local_c[0x6f1] + uVar12;
          puVar7 = local_c;
          local_8 = uVar17;
        }
        puVar7[0x6f2] = puVar7[0x10];
        *puVar7 = 0x16;
switchD_106dfc91_caseD_106e0d0f:
        uVar12 = *(uint *)(puVar7[0x14] + ((1 << ((byte)*puVar1 & 0x1f)) - 1U & uVar17) * 4);
        if (uVar16 < (uVar12 >> 8 & 0xff)) {
          do {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
            puVar19 = (uint *)((int)puVar19 + 1);
            uVar16 = uVar16 + 8;
            uVar12 = *(uint *)(local_c[0x14] + ((1 << ((byte)*puVar1 & 0x1f)) - 1U & uVar17) * 4);
            local_14 = puVar19;
            local_10 = puVar15;
            local_8 = uVar17;
          } while (uVar16 < (uVar12 >> 8 & 0xff));
        }
        if ((uVar12 & 0xf0) == 0) {
          bVar11 = (byte)(uVar12 >> 8);
          uVar13 = *(uint *)(puVar7[0x14] +
                            ((((1 << ((char)uVar12 + bVar11 & 0x1f)) - 1U & local_8) >>
                             (bVar11 & 0x1f)) + (uVar12 >> 0x10)) * 4);
          uVar17 = uVar16;
          if (uVar16 < (uVar13 >> 8 & 0xff) + (uVar12 >> 8 & 0xff)) {
            do {
              uVar16 = uVar17;
              if (local_10 == (uint *)0x0) goto LAB_106e117f;
              local_10 = (uint *)((int)local_10 + -1);
              uVar16 = uVar17 + 8;
              bVar3 = *(byte *)local_14;
              local_14 = (uint *)((int)local_14 + 1);
              local_8 = local_8 + ((uint)bVar3 << ((byte)uVar17 & 0x1f));
              uVar13 = *(uint *)(local_c[0x14] +
                                ((((1 << ((char)uVar12 + bVar11 & 0x1f)) - 1U & local_8) >>
                                 (bVar11 & 0x1f)) + (uVar12 >> 0x10)) * 4);
              uVar17 = uVar16;
            } while (uVar16 < (uVar13 >> 8 & 0xff) + (uVar12 >> 8 & 0xff));
          }
          uVar12 = uVar12 >> 8 & 0xff;
          uVar16 = uVar16 - uVar12;
          uVar17 = local_8 >> (bVar11 & 0x1f);
          local_c[0x6f1] = local_c[0x6f1] + uVar12;
          uVar12 = uVar13;
        }
        uVar13 = uVar12 >> 8 & 0xff;
        local_c[0x6f1] = local_c[0x6f1] + uVar13;
        uVar16 = uVar16 - uVar13;
        uVar17 = uVar17 >> ((byte)(uVar12 >> 8) & 0x1f);
        puVar7 = local_c;
        puVar15 = local_10;
        puVar19 = local_14;
        local_18 = uVar16;
        local_8 = uVar17;
        if ((uVar12 & 0x40) != 0) {
          param_1[6] = (uint *)"invalid distance code";
          *local_c = 0x1d;
          break;
        }
        local_c[0x11] = uVar12 >> 0x10;
        local_c[0x12] = uVar12 & 0xf;
        *local_c = 0x17;
switchD_106dfc91_caseD_106e0e96:
        uVar12 = puVar7[0x12];
        if (uVar12 != 0) {
          for (; uVar16 < uVar12; uVar16 = uVar16 + 8) {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
            puVar19 = (uint *)((int)puVar19 + 1);
            local_14 = puVar19;
            local_10 = puVar15;
            local_8 = uVar17;
          }
          local_c[0x11] = local_c[0x11] + ((1 << ((byte)uVar12 & 0x1f)) - 1U & uVar17);
          uVar17 = uVar17 >> ((byte)uVar12 & 0x1f);
          uVar16 = uVar16 - uVar12;
          local_c[0x6f1] = local_c[0x6f1] + uVar12;
          puVar7 = local_c;
          local_18 = uVar16;
          local_8 = uVar17;
        }
        *puVar7 = 0x18;
switchD_106dfc91_caseD_106e0ef9:
        if (local_1c != (uint *)0x0) {
          uVar12 = puVar7[0x11];
          if ((uint)((int)local_28 - (int)local_1c) < uVar12) {
            puVar18 = (uint *)(uVar12 - ((int)local_28 - (int)local_1c));
            if (((uint *)puVar7[0xb] < puVar18) && (puVar7[0x6f0] != 0)) {
              param_1[6] = (uint *)"invalid distance too far back";
              *puVar7 = 0x1d;
              break;
            }
            if ((uint *)puVar7[0xc] < puVar18) {
              puVar18 = (uint *)((int)puVar18 - puVar7[0xc]);
              local_2c = (puVar7[0xd] + puVar7[10]) - (int)puVar18;
            }
            else {
              local_2c = (puVar7[0xd] - (int)puVar18) + puVar7[0xc];
            }
            local_3c = (uint *)puVar7[0x10];
            if (local_3c < puVar18) {
              puVar18 = local_3c;
            }
          }
          else {
            local_2c = (int)local_24 - uVar12;
            puVar18 = (uint *)puVar7[0x10];
            local_3c = puVar18;
          }
          if (local_1c < puVar18) {
            puVar18 = local_1c;
          }
          local_1c = (uint *)((int)local_1c - (int)puVar18);
          puVar7[0x10] = (int)local_3c - (int)puVar18;
          local_2c = local_2c - (int)local_24;
          do {
            *(undefined *)local_24 = *(undefined *)(local_2c + (int)local_24);
            local_24 = (uint *)((int)local_24 + 1);
            puVar18 = (uint *)((int)puVar18 + -1);
          } while (puVar18 != (uint *)0x0);
          puVar7 = local_c;
          puVar15 = local_10;
          puVar19 = local_14;
          if (local_c[0x10] == 0) {
            *local_c = 0x14;
          }
          break;
        }
        goto LAB_106e117f;
      case (undefined *)0x106e0ca6:
        goto switchD_106dfc91_caseD_106e0ca6;
      case (undefined *)0x106e0d0f:
        goto switchD_106dfc91_caseD_106e0d0f;
      case (undefined *)0x106e0e96:
        goto switchD_106dfc91_caseD_106e0e96;
      case (undefined *)0x106e0ef9:
        goto switchD_106dfc91_caseD_106e0ef9;
      case (undefined *)0x106e0fca:
        if (local_1c == (uint *)0x0) goto LAB_106e117f;
        local_1c = (uint *)((int)local_1c + -1);
        *(undefined *)local_24 = *(undefined *)(puVar7 + 0x10);
        *puVar7 = 0x14;
        puVar19 = local_14;
        local_24 = (uint *)((int)local_24 + 1);
        break;
      case (undefined *)0x106e0ff0:
        puVar18 = puVar19;
        if (puVar7[2] != 0) {
          while (puVar19 = local_14, local_14 = puVar19, uVar16 < 0x20) {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar18 << ((byte)uVar16 & 0x1f));
            puVar18 = (uint *)((int)puVar18 + 1);
            uVar16 = uVar16 + 8;
            puVar7 = local_c;
            local_18 = uVar16;
            local_14 = puVar18;
            local_10 = puVar15;
            local_8 = uVar17;
          }
          uVar12 = (int)local_28 - (int)local_1c;
          param_1[5] = (uint *)((int)param_1[5] + uVar12);
          puVar7[7] = puVar7[7] + uVar12;
          if (uVar12 != 0) {
            if (puVar7[4] == 0) {
              puVar7 = (uint *)FUN_106e20a0(puVar7[6],(byte *)(uint *)((int)local_24 - uVar12),
                                            uVar12);
            }
            else {
              puVar7 = (uint *)FUN_106e2310(puVar7[6],(uint *)((int)local_24 - uVar12),uVar12);
            }
            local_c[6] = (uint)puVar7;
            param_1[0xc] = puVar7;
            puVar7 = local_c;
            uVar17 = local_8;
          }
          local_28 = local_1c;
          uVar12 = uVar17;
          if (puVar7[4] == 0) {
            uVar12 = ((uVar17 & 0xff00) + uVar17 * 0x10000) * 0x100 + (uVar17 >> 8 & 0xff00) +
                     (uVar17 >> 0x18);
          }
          if (uVar12 != puVar7[6]) {
            param_1[6] = (uint *)"incorrect data check";
            *puVar7 = 0x1d;
            break;
          }
          uVar17 = 0;
          uVar16 = 0;
          local_8 = 0;
          local_18 = 0;
        }
        *puVar7 = 0x1b;
      case (undefined *)0x106e10d8:
        if ((puVar7[2] != 0) && (puVar7[4] != 0)) {
          while (uVar16 < 0x20) {
            if (puVar15 == (uint *)0x0) goto LAB_106e117f;
            puVar15 = (uint *)((int)puVar15 + -1);
            uVar17 = uVar17 + ((uint)*(byte *)puVar19 << ((byte)uVar16 & 0x1f));
            puVar19 = (uint *)((int)puVar19 + 1);
            uVar16 = uVar16 + 8;
            puVar7 = local_c;
            local_18 = uVar16;
            local_14 = puVar19;
            local_10 = puVar15;
            local_8 = uVar17;
          }
          if (uVar17 != puVar7[7]) {
            param_1[6] = (uint *)"incorrect length check";
            *puVar7 = 0x1d;
            break;
          }
          local_8 = 0;
          uVar16 = 0;
        }
        *puVar7 = 0x1c;
switchD_106dfc91_caseD_106e116c:
        local_30 = 1;
        goto LAB_106e117f;
      case (undefined *)0x106e116c:
        goto switchD_106dfc91_caseD_106e116c;
      case (undefined *)0x106e1175:
        local_30 = -3;
        goto LAB_106e117f;
      case (undefined *)0x106e11c9:
        goto switchD_106dfc91_caseD_106e11c9;
      }
LAB_106e06ed:
      uVar12 = *puVar7;
    } while (uVar12 < 0x1f);
  }
  return -2;
}

