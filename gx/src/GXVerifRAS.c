/* WARNING: Removing unreachable block (ram,0x00010180) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXVerifySU(void)
{
  uint uVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  pcVar2 = ppcRam00000000[0x352];
  iVar5 = ((uint)ppcRam00000000[0x353] >> 0xc & 0x7ff) + ((uint)ppcRam00000000[0x38b] & 0x3ff) * -2;
  pcVar3 = ppcRam00000000[0x38b];
  iVar4 = ((uint)ppcRam00000000[0x353] & 0x7ff) - ((uint)ppcRam00000000[0x38b] >> 9 & 0x7fe);
  if (((int)(((uint)ppcRam00000000[0x352] >> 0xc & 0x7ff) +
            ((uint)ppcRam00000000[0x38b] & 0x3ff) * -2) < 0) &&
     (___gxvWarnings <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_sprintf,0);
    (**ppcRam00000000)(___gxvWarnings,2,&__gxvDummyStr);
  }
  if (((int)(((uint)pcVar2 & 0x7ff) - ((uint)pcVar3 >> 9 & 0x7fe)) < 0) &&
     (___gxVerif <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015014,0);
    (**ppcRam00000000)(___gxVerif,3,&__gxvDummyStr);
  }
  uVar1 = (uint)ppcRam00000000[0x375] & 7;
  if (uVar1 != 3) {
    if (2 < uVar1) {
      if (5 < uVar1) {
        return;
      }
      if ((0x2cf < iVar5) && ((int)_sprintf <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015018,0x2cf,&@47);
        (**ppcRam00000000)(_sprintf,4,&__gxvDummyStr);
      }
      if (iVar4 < 0x240) {
        return;
      }
      if ((int)ppcRam00000000[1] < (int)_DAT_00015014) {
        return;
      }
      sprintf(&__gxvDummyStr,_DAT_0001501c,0x23f,&@47);
      (**ppcRam00000000)(_DAT_00015014,5,&__gxvDummyStr);
      return;
    }
    if (1 < uVar1) {
      if ((0x27f < iVar5) && ((int)_sprintf <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015018,0x27f,...data.0);
        (**ppcRam00000000)(_sprintf,4,&__gxvDummyStr);
      }
      if (iVar4 < 0x108) {
        return;
      }
      if ((int)ppcRam00000000[1] < (int)_DAT_00015014) {
        return;
      }
      sprintf(&__gxvDummyStr,_DAT_0001501c,0x107,...data.0);
      (**ppcRam00000000)(_DAT_00015014,5,&__gxvDummyStr);
      return;
    }
  }
  if ((0x27f < iVar5) && ((int)_sprintf <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_00015018,0x27f,&@48);
    (**ppcRam00000000)(_sprintf,4,&__gxvDummyStr);
  }
  if ((0x20f < iVar4) && ((int)_DAT_00015014 <= (int)ppcRam00000000[1])) {
    sprintf(&__gxvDummyStr,_DAT_0001501c,0x20f,&@48);
    (**ppcRam00000000)(_DAT_00015014,5,&__gxvDummyStr);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXVerifyBUMP(void)
{
  uint uVar1;
  code *pcVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = (uint)ppcRam00000000[0x332] >> 0x10 & 7;
  uVar1 = (uint)ppcRam00000000[0x332] & 0xf;
  pcVar3 = ppcRam00000000[0x332];
  for (uVar6 = 0; uVar6 < ((uint)pcVar3 >> 10 & 0xf) + 1; uVar6 = uVar6 + 1) {
    pcVar2 = ppcRam00000000[uVar6 + 0x342];
    uVar4 = (uint)pcVar2 >> 9 & 0xf;
    if (0 < (int)ppcRam00000000[1]) {
      if (((uint)ppcRam00000000[uVar6 + 0x342] & 0xff000000) == 0xff000000) {
        if (_DAT_0001501c <= (int)ppcRam00000000[1]) {
          sprintf(&__gxvDummyStr,_DAT_00015024,uVar6);
          (**ppcRam00000000)(_DAT_0001501c,7,&__gxvDummyStr);
        }
      }
      if ((((((uint)ppcRam00000000[uVar6 + 0x342] >> 7 & 3) != 0) || (uVar4 != 0)) &&
          (uVar7 <= ((uint)ppcRam00000000[uVar6 + 0x342] & 3))) &&
         (_DAT_00015020 <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015028,uVar6);
        (**ppcRam00000000)(_DAT_00015020,8,&__gxvDummyStr);
      }
      if (((uVar4 != 0) &&
          (((iVar5 = ((uint)pcVar2 >> 9 & 3) - 1,
            ((uint)ppcRam00000000[iVar5 * 3 + 0x338] & 0xff000000) == 0xff000000 ||
            (((uint)ppcRam00000000[iVar5 * 3 + 0x339] & 0xff000000) == 0xff000000)) ||
           (((uint)ppcRam00000000[iVar5 * 3 + 0x33a] & 0xff000000) == 0xff000000)))) &&
         ((int)_DAT_00015024 <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_0001502c,iVar5,uVar6);
        (**ppcRam00000000)(_DAT_00015024,9,&__gxvDummyStr);
      }
    }
  }
  if (0 < (int)ppcRam00000000[1]) {
    if (((uVar7 != 0) && (((uint)ppcRam00000000[0x359] & 0xff000000) == 0xff000000)) &&
       ((int)_DAT_00015028 <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_00015028,10,_DAT_00015030);
    }
    if (((uVar7 != 0) && (((uint)ppcRam00000000[0x357] & 0xff000000) == 0xff000000)) &&
       ((int)_DAT_0001502c <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015034,0,1);
      (**ppcRam00000000)(_DAT_0001502c,0xb,&__gxvDummyStr);
    }
    if (((2 < uVar7) && (((uint)ppcRam00000000[0x358] & 0xff000000) == 0xff000000)) &&
       ((int)_DAT_0001502c <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015034,2,3);
      (**ppcRam00000000)(_DAT_0001502c,0xb,&__gxvDummyStr);
    }
    if (((uVar7 != 0) && (uVar1 <= ((uint)ppcRam00000000[0x359] >> 3 & 7))) &&
       (_DAT_00015030 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015038,0);
      (**ppcRam00000000)(_DAT_00015030,0xc,&__gxvDummyStr);
    }
    if (((1 < uVar7) && (uVar1 <= ((uint)ppcRam00000000[0x359] >> 9 & 7))) &&
       (_DAT_00015030 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015038,1);
      (**ppcRam00000000)(_DAT_00015030,0xc,&__gxvDummyStr);
    }
    if (((2 < uVar7) && (uVar1 <= ((uint)ppcRam00000000[0x359] >> 0xf & 7))) &&
       (_DAT_00015030 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015038,2);
      (**ppcRam00000000)(_DAT_00015030,0xc,&__gxvDummyStr);
    }
    if (((3 < uVar7) && (uVar1 <= ((uint)ppcRam00000000[0x359] >> 0x15 & 7))) &&
       (_DAT_00015030 <= (int)ppcRam00000000[1])) {
      sprintf(&__gxvDummyStr,_DAT_00015038,3);
      (**ppcRam00000000)(_DAT_00015030,0xc,&__gxvDummyStr);
    }
    if (((uVar7 != 0) && (((uint)ppcRam00000000[0x342] >> 0x14 & 1) != 0)) &&
       ((int)_DAT_00015034 <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_00015034,0xd,_DAT_0001503c);
    }
    if (((uVar7 != 0) && (((uint)ppcRam00000000[0x342] >> 7 & 3) != 0)) &&
       ((int)_DAT_00015038 <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_00015038,0xe,_DAT_00015040);
    }
    if (((((uint)ppcRam00000000[0x341] & 0xff000000) == 0xff000000) &&
        ((uVar1 != 0 || (uVar7 != 0)))) && (_DAT_0001503c <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_0001503c,0xf,_DAT_00015044);
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXVerifyTEX(void)
{
  bool bVar1;
  bool bVar2;
  code *pcVar3;
  code *pcVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  uint unaff_r29;
  uint uVar8;
  uint unaff_r31;
  int local_68 [8];
  int local_48 [9];
  
  pcVar3 = ppcRam00000000[0x332];
  pcVar4 = ppcRam00000000[0x332];
  uVar7 = ((uint)ppcRam00000000[0x332] >> 10 & 0xf) + 1;
  for (uVar8 = 0; uVar8 < 8; uVar8 = uVar8 + 1) {
    local_48[uVar8] = 0;
    local_68[uVar8] = 0;
  }
  uVar8 = 0;
  do {
    if (uVar7 + ((uint)pcVar3 >> 0x10 & 7) <= uVar8) {
      return;
    }
    if (uVar8 < uVar7) {
      if (0 < (int)ppcRam00000000[1]) {
        if (((uint)ppcRam00000000[(uVar8 >> 1) + 0x35a] & 0xff000000) == 0xff000000) {
          if (_DAT_00015040 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015048,uVar8);
            (**ppcRam00000000)(_DAT_00015040,0x10,&__gxvDummyStr);
          }
        }
        if ((uVar8 & 1) == 0) {
          unaff_r29 = (uint)ppcRam00000000[(uVar8 >> 1) + 0x35a] >> 6 & 1;
          if (((unaff_r29 != 0) &&
              (((uint)pcVar4 & 0xf) <= ((uint)ppcRam00000000[(uVar8 >> 1) + 0x35a] >> 3 & 7))) &&
             (_DAT_00015044 <= (int)ppcRam00000000[1])) {
            sprintf(&__gxvDummyStr,_DAT_0001504c,uVar8);
            (**ppcRam00000000)(_DAT_00015044,0x11,&__gxvDummyStr);
          }
          pcVar5 = ppcRam00000000[(uVar8 >> 1) + 0x35a];
        }
        else {
          unaff_r29 = (uint)ppcRam00000000[(uVar8 >> 1) + 0x35a] >> 0x12 & 1;
          if (unaff_r29 != 0) {
            if ((((uint)pcVar4 & 0xf) <= ((uint)ppcRam00000000[(uVar8 >> 1) + 0x35a] >> 0xf & 7)) &&
               (_DAT_00015044 <= (int)ppcRam00000000[1])) {
              sprintf(&__gxvDummyStr,_DAT_0001504c,uVar8);
              (**ppcRam00000000)(_DAT_00015044,0x11,&__gxvDummyStr);
            }
          }
          pcVar5 = (code *)((uint)ppcRam00000000[(uVar8 >> 1) + 0x35a] >> 0xc);
        }
        unaff_r31 = (uint)pcVar5 & 7;
        if (((unaff_r29 != 0) && (local_68[unaff_r31] != 0)) &&
           ((int)_DAT_00015048 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015050,uVar8);
          (**ppcRam00000000)(_DAT_00015048,0x12,&__gxvDummyStr);
        }
        if (unaff_r29 != 0) {
          local_48[unaff_r31] = 1;
        }
      }
    }
    else {
      unaff_r29 = 1;
      if (uVar8 == uVar7) {
        unaff_r31 = (uint)ppcRam00000000[0x359] & 7;
      }
      else if (uVar8 - uVar7 == 1) {
        unaff_r31 = (uint)ppcRam00000000[0x359] >> 6 & 7;
      }
      else if (uVar8 - uVar7 == 2) {
        unaff_r31 = (uint)ppcRam00000000[0x359] >> 0xc & 7;
      }
      else {
        unaff_r31 = (uint)ppcRam00000000[0x359] >> 0x12 & 7;
      }
      if ((local_48[unaff_r31] != 0) && ((int)_DAT_00015048 <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015050,uVar8);
        (**ppcRam00000000)(_DAT_00015048,0x12,&__gxvDummyStr);
      }
      local_68[unaff_r31] = 1;
    }
    if (unaff_r29 != 0) {
      if (0 < (int)ppcRam00000000[1]) {
        if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] &
            0xff000000) == 0xff000000) {
LAB_00011100:
          if ((int)_DAT_0001504c <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015054,unaff_r31);
            (**ppcRam00000000)(_DAT_0001504c,0x13,&__gxvDummyStr);
          }
        }
        else {
          if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b6] &
              0xff000000) == 0xff000000) goto LAB_00011100;
          if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] &
              0xff000000) == 0xff000000) goto LAB_00011100;
          if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3be] &
              0xff000000) == 0xff000000) goto LAB_00011100;
          if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3c2] &
              0xff000000) == 0xff000000) goto LAB_00011100;
        }
        if (((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3be] >> 0x15
              & 1) == 0) &&
            (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3c6] &
             0xff000000) == 0xff000000)) && ((int)_DAT_00015050 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015058,unaff_r31);
          (**ppcRam00000000)(_DAT_00015050,0x14,&__gxvDummyStr);
        }
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 0x14 &
             0xf) == 8) ||
           (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 0x14 &
            0xf) == 9)) {
LAB_000112a4:
          if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ca] &
              0xff000000) == 0xff000000) {
            if ((int)_DAT_00015054 <= (int)ppcRam00000000[1]) {
              sprintf(&__gxvDummyStr,_DAT_0001505c,unaff_r31);
              (**ppcRam00000000)(_DAT_00015054,0x15,&__gxvDummyStr);
            }
          }
        }
        else if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >>
                  0x14 & 0xf) == 10) goto LAB_000112a4;
        if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] & 0x3ff)
            == 0xffffffff) {
          bVar1 = true;
        }
        else {
          for (uVar6 = 1;
              (uVar6 & ((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba]
                       & 0x3ff) + 1) == 0; uVar6 = uVar6 << 1) {
          }
          bVar1 = uVar6 == ((uint)ppcRam00000000
                                  [(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] & 0x3ff)
                           + 1;
        }
        if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 10 &
            0x3ff) == 0xffffffff) {
          bVar2 = true;
        }
        else {
          for (uVar6 = 1;
              (uVar6 & ((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba]
                        >> 10 & 0x3ff) + 1) == 0; uVar6 = uVar6 << 1) {
          }
          bVar2 = uVar6 == ((uint)ppcRam00000000
                                  [(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 10 &
                           0x3ff) + 1;
        }
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 & 3)
             != 0) && (!bVar1)) {
          if ((int)_DAT_00015058 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015060,@305,unaff_r31);
            (**ppcRam00000000)(_DAT_00015058,0x16,&__gxvDummyStr);
          }
        }
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 & 3)
             != 0) && (!bVar2)) {
          if ((int)_DAT_00015058 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015060,@306,unaff_r31);
            (**ppcRam00000000)(_DAT_00015058,0x16,&__gxvDummyStr);
          }
        }
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] & 3) != 0
            ) && (!bVar1)) {
          if ((int)_DAT_0001505c <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015064,&@307,unaff_r31);
            (**ppcRam00000000)(_DAT_0001505c,0x17,&__gxvDummyStr);
          }
        }
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 2 & 3)
             != 0) && (!bVar2)) {
          if ((int)_DAT_0001505c <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015064,&@308,unaff_r31);
            (**ppcRam00000000)(_DAT_0001505c,0x17,&__gxvDummyStr);
          }
        }
        if (((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 & 3
              ) != 0) &&
            ((((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >>
                 0x14 & 0xf) == 8 ||
               (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >>
                 0x14 & 0xf) == 9)) ||
              (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 0x14
               & 0xf) == 10)) &&
             ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 &
               7) != 1 &&
              (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 &
               7) != 5)))))) && ((int)_DAT_00015060 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015068,unaff_r31);
          (**ppcRam00000000)(_DAT_00015060,0x18,&__gxvDummyStr);
        }
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b6] >> 8 &
             0xff) < ((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b6] &
                     0xff)) && ((int)_DAT_00015064 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_0001506c,unaff_r31);
          (**ppcRam00000000)(_DAT_00015064,0x19,&__gxvDummyStr);
        }
        uVar6 = 0;
        while( true ) {
          if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 10 &
              0x3ff) + 1 <
              ((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] & 0x3ff)
              + 1) {
            pcVar5 = ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba];
          }
          else {
            pcVar5 = (code *)((uint)ppcRam00000000
                                    [(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 10);
          }
          if (((uint)pcVar5 & 0x3ff) + 1 >> (uVar6 & 0x3f) == 0) break;
          uVar6 = uVar6 + 1;
        }
        if ((uVar6 - 1) * 0x10 <
            ((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b6] >> 8 &
            0xff)) {
          if ((int)_DAT_00015068 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015070,unaff_r31);
            (**ppcRam00000000)(_DAT_00015068,0x1a,&__gxvDummyStr);
          }
        }
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 0x15 &
             1) != 0) &&
           (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 8 & 1)
            != 0)) {
          if ((int)_DAT_0001506c <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015074,unaff_r31);
            (**ppcRam00000000)(_DAT_0001506c,0x1b,&__gxvDummyStr);
          }
        }
        if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 0x13 &
            3) != 0) {
          if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 &
               3) != 0) &&
             (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 & 7
              ) == 6)) {
            if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 4
                 & 1) == 1) &&
               ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >>
                  0x14 & 0xf) != 8 &&
                (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >>
                  0x14 & 0xf) != 9)))) {
              if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >>
                   0x14 & 0xf) != 10) {
                if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >>
                     8 & 1) == 0) {
                  if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2]
                       >> 0x15 & 1) == 0) goto LAB_00011cf4;
                }
              }
            }
          }
          if ((int)_DAT_00015070 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015078,unaff_r31);
            (**ppcRam00000000)(_DAT_00015070,0x1c,&__gxvDummyStr);
          }
        }
      }
LAB_00011cf4:
      if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 0x12 & 1)
          != 0) {
        if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 5 & 7)
            == 4) {
          if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 4 & 1
              ) != 1) goto LAB_00011d74;
        }
        else {
LAB_00011d74:
          if ((int)_DAT_00015074 <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_0001507c,unaff_r31);
            (**ppcRam00000000)(_DAT_00015074,0x1d,&__gxvDummyStr);
          }
        }
        if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 0x11 &
            1) != 0) {
          if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 0x14
               & 0xf) == 1) &&
             (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 0x13
              & 3) == 0)) goto LAB_00011ebc;
        }
        if ((int)_DAT_00015078 <= (int)ppcRam00000000[1]) {
          sprintf(&__gxvDummyStr,_DAT_00015080,unaff_r31);
          (**ppcRam00000000)(_DAT_00015078,0x1e,&__gxvDummyStr);
        }
      }
LAB_00011ebc:
      if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 0x11 & 1)
          != 0) {
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 0x14 &
             0xf) == 8) ||
           (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >> 0x14 &
            0xf) == 9)) {
LAB_00011f68:
          if ((int)_DAT_0001507c <= (int)ppcRam00000000[1]) {
            sprintf(&__gxvDummyStr,_DAT_00015084,unaff_r31);
            (**ppcRam00000000)(_DAT_0001507c,0x1f,&__gxvDummyStr);
          }
        }
        else if (((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3ba] >>
                  0x14 & 0xf) == 10) goto LAB_00011f68;
        if ((((uint)ppcRam00000000[(unaff_r31 & 3) + (unaff_r31 & 0x1ffffffc) * 8 + 0x3b2] >> 0x12 &
             1) == 0) && ((int)_DAT_00015078 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015080,unaff_r31);
          (**ppcRam00000000)(_DAT_00015078,0x1e,&__gxvDummyStr);
        }
      }
    }
    uVar8 = uVar8 + 1;
  } while( true );
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXVerifyTEV(void)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_r29;
  uint uVar5;
  int local_60 [4];
  int local_50 [4];
  uint local_40 [4];
  uint local_30 [5];
  
  uVar3 = (uint)ppcRam00000000[0x332] >> 10 & 0xf;
  uVar4 = (uint)ppcRam00000000[0x332] >> 4 & 7;
  for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {
    local_30[uVar5] = 0;
    local_40[uVar5] = 0;
    local_50[uVar5] = 0;
    local_60[uVar5] = 0;
  }
  uVar5 = 0;
  do {
    if (uVar3 + 1 <= uVar5) {
      uVar4 = 0;
      while( true ) {
        if (3 < uVar4) break;
        if (local_50[uVar4] != 0) {
          ppcRam00000000[uVar4 * 2 + 0x413] =
               (code *)((uint)ppcRam00000000[uVar4 * 2 + 0x413] & 0xffffff | 0xff000000);
        }
        if (local_60[uVar4] != 0) {
          ppcRam00000000[uVar4 * 2 + 0x412] =
               (code *)((uint)ppcRam00000000[uVar4 * 2 + 0x412] & 0xffffff | 0xff000000);
        }
        uVar4 = uVar4 + 1;
      }
      if ((((uint)ppcRam00000000[0x427] >> 2 & 3) != 0) && (0 < (int)ppcRam00000000[1])) {
        if ((((uint)ppcRam00000000[0x426] & 0xff000000) == 0xff000000) &&
           ((int)_DAT_000150a0 <= (int)ppcRam00000000[1])) {
          (**ppcRam00000000)(_DAT_000150a0,0x28,_DAT_000150a8);
        }
        if ((unaff_r29 == 0) && ((int)_DAT_000150a4 <= (int)ppcRam00000000[1])) {
          (**ppcRam00000000)(_DAT_000150a4,0x29,_DAT_000150ac);
        }
      }
      if (1 < (int)ppcRam00000000[1]) {
        if (((uint)ppcRam00000000[uVar3 * 2 + 0x3f2] >> 0x16 & 3) != 0) {
          if (_DAT_000150a8 <= (int)ppcRam00000000[1]) {
            (**ppcRam00000000)(_DAT_000150a8,0x2a,_DAT_000150b0);
          }
        }
        if ((((uint)ppcRam00000000[uVar3 * 2 + 0x3f3] >> 0x16 & 3) != 0) &&
           (_DAT_000150ac <= (int)ppcRam00000000[1])) {
          (**ppcRam00000000)(_DAT_000150ac,0x2b,_DAT_000150b4);
        }
      }
      if (2 < (int)ppcRam00000000[1]) {
        if (((uint)ppcRam00000000[uVar3 * 2 + 0x3f2] >> 0x13 & 1) == 0) {
          if (_DAT_000150b0 <= (int)ppcRam00000000[1]) {
            (**ppcRam00000000)(_DAT_000150b0,0x2c,_DAT_000150b8);
          }
        }
        if ((((uint)ppcRam00000000[uVar3 * 2 + 0x3f3] >> 0x13 & 1) == 0) &&
           (_DAT_000150b4 <= (int)ppcRam00000000[1])) {
          (**ppcRam00000000)(_DAT_000150b4,0x2d,_DAT_000150bc);
        }
      }
      if (1 < (int)ppcRam00000000[1]) {
        if ((((uint)ppcRam00000000[0x375] >> 6 & 1) != 0) &&
           ((((((uint)ppcRam00000000[0x425] >> 0x16 & 3) != 0 ||
              (((uint)ppcRam00000000[0x425] >> 0x10 & 7) != 7)) ||
             (((uint)ppcRam00000000[0x425] >> 0x13 & 7) != 7)) &&
            (_DAT_000150b8 <= (int)ppcRam00000000[1])))) {
          (**ppcRam00000000)(_DAT_000150b8,0x2e,_DAT_000150c0);
        }
      }
      return;
    }
    if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xff000000) == 0xff000000) {
LAB_00012164:
      if (_DAT_00015080 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_00015088,uVar5);
        (**ppcRam00000000)(_DAT_00015080,0x20,&__gxvDummyStr);
      }
    }
    else if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] & 0xff000000) == 0xff000000)
    goto LAB_00012164;
    if ((uVar5 & 1) == 0) {
      uVar1 = (uint)ppcRam00000000[(uVar5 >> 1) + 0x35a] >> 7;
    }
    else {
      uVar1 = (uint)ppcRam00000000[(uVar5 >> 1) + 0x35a] >> 0x13;
    }
    if ((((uVar1 & 7) == 0) && (uVar4 == 0)) || (((uVar1 & 7) == 1 && (uVar4 < 2)))) {
      if (_DAT_00015084 <= (int)ppcRam00000000[1]) {
        sprintf(&__gxvDummyStr,_DAT_0001508c,uVar5);
        (**ppcRam00000000)(_DAT_00015084,0x21,&__gxvDummyStr);
      }
    }
    if ((uVar5 & 1) == 0) {
      uVar1 = (uint)ppcRam00000000[(uVar5 >> 1) + 0x35a] >> 6;
    }
    else {
      uVar1 = (uint)ppcRam00000000[(uVar5 >> 1) + 0x35a] >> 0x12;
    }
    unaff_r29 = uVar1 & 1;
    if (0 < (int)ppcRam00000000[1]) {
      if ((unaff_r29 == 0) &&
         ((((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xc & 0xf) == 8 ||
          (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xc & 0xf) == 9)))) {
        if ((int)_DAT_00015088 <= (int)ppcRam00000000[1]) {
          sprintf(&__gxvDummyStr,_DAT_00015090,&@517,uVar5);
          (**ppcRam00000000)(_DAT_00015088,0x22,&__gxvDummyStr);
        }
      }
      if ((unaff_r29 == 0) &&
         (((((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 8 & 0xf) == 8 ||
           (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 8 & 0xf) == 9)) &&
          ((int)_DAT_00015088 <= (int)ppcRam00000000[1])))) {
        sprintf(&__gxvDummyStr,_DAT_00015090,&@518,uVar5);
        (**ppcRam00000000)(_DAT_00015088,0x22,&__gxvDummyStr);
      }
      if (((unaff_r29 == 0) &&
          ((((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 4 & 0xf) == 8 ||
           (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 4 & 0xf) == 9)))) &&
         ((int)_DAT_00015088 <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015090,&@519,uVar5);
        (**ppcRam00000000)(_DAT_00015088,0x22,&__gxvDummyStr);
      }
      if (unaff_r29 == 0) {
        if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xf) != 8) {
          if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xf) != 9) goto LAB_000125ec;
        }
        if ((int)_DAT_00015088 <= (int)ppcRam00000000[1]) {
          sprintf(&__gxvDummyStr,_DAT_00015090,&@520,uVar5);
          (**ppcRam00000000)(_DAT_00015088,0x22,&__gxvDummyStr);
        }
      }
LAB_000125ec:
      if (unaff_r29 == 0) {
        if ((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xd & 7) == 4) &&
           ((int)_DAT_0001508c <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015094,&@517,uVar5);
          (**ppcRam00000000)(_DAT_0001508c,0x23,&__gxvDummyStr);
        }
      }
      if (unaff_r29 == 0) {
        if ((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 10 & 7) == 4) &&
           ((int)_DAT_0001508c <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_00015094,&@518,uVar5);
          (**ppcRam00000000)(_DAT_0001508c,0x23,&__gxvDummyStr);
        }
      }
      if (((unaff_r29 == 0) && (((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 7 & 7) == 4)) &&
         ((int)_DAT_0001508c <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015094,&@519,uVar5);
        (**ppcRam00000000)(_DAT_0001508c,0x23,&__gxvDummyStr);
      }
      if (((unaff_r29 == 0) && (((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 4 & 7) == 4)) &&
         ((int)_DAT_0001508c <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_00015094,&@520,uVar5);
        (**ppcRam00000000)(_DAT_0001508c,0x23,&__gxvDummyStr);
      }
      if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xc & 0xf) < 8) {
        if (((uint)ppcRam00000000
                   [((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xc & 0xf ^ 1) + 0x412] & 0xff000000
            ) == 0xff000000) {
          if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xc & 1) == 0) {
            iVar2 = *(int *)((int)local_50 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xb & 0x1c)
                            );
          }
          else {
            iVar2 = *(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xb & 0x1c)
                            );
          }
          if ((iVar2 == 0) && ((int)_DAT_00015090 <= (int)ppcRam00000000[1])) {
            sprintf(&__gxvDummyStr,_DAT_00015098,&@517,uVar5,
                    *(undefined4 *)
                     ((int)&TevRegNames + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 10 & 0x3c)));
            (**ppcRam00000000)(_DAT_00015090,0x24,&__gxvDummyStr);
          }
        }
      }
      if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 8 & 0xf) < 8) {
        if (((uint)ppcRam00000000[((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 8 & 0xf ^ 1) + 0x412]
            & 0xff000000) == 0xff000000) {
          if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 8 & 1) == 0) {
            iVar2 = *(int *)((int)local_50 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 7 & 0x1c));
          }
          else {
            iVar2 = *(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 7 & 0x1c));
          }
          if ((iVar2 == 0) && ((int)_DAT_00015090 <= (int)ppcRam00000000[1])) {
            sprintf(&__gxvDummyStr,_DAT_00015098,&@518,uVar5,
                    *(undefined4 *)
                     ((int)&TevRegNames + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 6 & 0x3c)));
            (**ppcRam00000000)(_DAT_00015090,0x24,&__gxvDummyStr);
          }
        }
      }
      if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 4 & 0xf) < 8) {
        if (((uint)ppcRam00000000[((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 4 & 0xf ^ 1) + 0x412]
            & 0xff000000) == 0xff000000) {
          if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 4 & 1) == 0) {
            iVar2 = *(int *)((int)local_50 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 3 & 0x1c));
          }
          else {
            iVar2 = *(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 3 & 0x1c));
          }
          if ((iVar2 == 0) && ((int)_DAT_00015090 <= (int)ppcRam00000000[1])) {
            sprintf(&__gxvDummyStr,_DAT_00015098,&@519,uVar5,
                    *(undefined4 *)
                     ((int)&TevRegNames + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 2 & 0x3c)));
            (**ppcRam00000000)(_DAT_00015090,0x24,&__gxvDummyStr);
          }
        }
      }
      if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xf) < 8) {
        if (((uint)ppcRam00000000[((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xf ^ 1) + 0x412] &
            0xff000000) == 0xff000000) {
          if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 1) == 0) {
            iVar2 = *(int *)((int)local_50 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xe) * 2);
          }
          else {
            iVar2 = *(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xe) * 2);
          }
          if ((iVar2 == 0) && ((int)_DAT_00015090 <= (int)ppcRam00000000[1])) {
            sprintf(&__gxvDummyStr,_DAT_00015098,&@520,uVar5,
                    (&TevRegNames)[(uint)ppcRam00000000[uVar5 * 2 + 0x3f2] & 0xf]);
            (**ppcRam00000000)(_DAT_00015090,0x24,&__gxvDummyStr);
          }
        }
      }
      if ((((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xd & 7) < 4) &&
           (((uint)ppcRam00000000[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xc & 0xe) + 0x412] &
            0xff000000) == 0xff000000)) &&
          (*(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xb & 0x1c)) == 0))
         && ((int)_DAT_00015094 <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_0001509c,&@517,uVar5,
                (&TevRegNames)[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xc & 0xe) + 1]);
        (**ppcRam00000000)(_DAT_00015094,0x25,&__gxvDummyStr);
      }
      if (((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 10 & 7) < 4) &&
          (((uint)ppcRam00000000[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 9 & 0xe) + 0x412] &
           0xff000000) == 0xff000000)) &&
         ((*(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 8 & 0x1c)) == 0 &&
          ((int)_DAT_00015094 <= (int)ppcRam00000000[1])))) {
        sprintf(&__gxvDummyStr,_DAT_0001509c,&@518,uVar5,
                (&TevRegNames)[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 9 & 0xe) + 1]);
        (**ppcRam00000000)(_DAT_00015094,0x25,&__gxvDummyStr);
      }
      if (((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 7 & 7) < 4) &&
          (((uint)ppcRam00000000[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 6 & 0xe) + 0x412] &
           0xff000000) == 0xff000000)) &&
         ((*(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 5 & 0x1c)) == 0 &&
          ((int)_DAT_00015094 <= (int)ppcRam00000000[1])))) {
        sprintf(&__gxvDummyStr,_DAT_0001509c,&@519,uVar5,
                (&TevRegNames)[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 6 & 0xe) + 1]);
        (**ppcRam00000000)(_DAT_00015094,0x25,&__gxvDummyStr);
      }
      if ((((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 4 & 7) < 4) &&
           (((uint)ppcRam00000000[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 3 & 0xe) + 0x412] &
            0xff000000) == 0xff000000)) &&
          (*(int *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 2 & 0x1c)) == 0)) &&
         ((int)_DAT_00015094 <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_0001509c,&@520,uVar5,
                (&TevRegNames)[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 3 & 0xe) + 1]);
        (**ppcRam00000000)(_DAT_00015094,0x25,&__gxvDummyStr);
      }
    }
    if (2 < (int)ppcRam00000000[1]) {
      if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xc & 0xf) < 8) {
        if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xc & 1) == 0) {
          iVar2 = *(int *)((int)local_30 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xb & 0x1c));
        }
        else {
          iVar2 = *(int *)((int)local_40 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0xb & 0x1c));
        }
        if ((iVar2 != 0) && ((int)_DAT_00015098 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_000150a0,&@517,uVar5,
                  *(undefined4 *)
                   ((int)&TevRegNames + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 10 & 0x3c)));
          (**ppcRam00000000)(_DAT_00015098,0x26,&__gxvDummyStr);
        }
      }
      if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 8 & 0xf) < 8) {
        if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 8 & 1) == 0) {
          iVar2 = *(int *)((int)local_30 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 7 & 0x1c));
        }
        else {
          iVar2 = *(int *)((int)local_40 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 7 & 0x1c));
        }
        if ((iVar2 != 0) && ((int)_DAT_00015098 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_000150a0,&@518,uVar5,
                  *(undefined4 *)
                   ((int)&TevRegNames + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 6 & 0x3c)));
          (**ppcRam00000000)(_DAT_00015098,0x26,&__gxvDummyStr);
        }
      }
      if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 4 & 0xf) < 8) {
        if (((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 4 & 1) == 0) {
          iVar2 = *(int *)((int)local_30 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 3 & 0x1c));
        }
        else {
          iVar2 = *(int *)((int)local_40 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 3 & 0x1c));
        }
        if ((iVar2 != 0) && ((int)_DAT_00015098 <= (int)ppcRam00000000[1])) {
          sprintf(&__gxvDummyStr,_DAT_000150a0,&@519,uVar5,
                  *(undefined4 *)
                   ((int)&TevRegNames + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 2 & 0x3c)));
          (**ppcRam00000000)(_DAT_00015098,0x26,&__gxvDummyStr);
        }
      }
      if (((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xd & 7) < 4) &&
          (*(int *)((int)local_40 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xb & 0x1c)) != 0))
         && ((int)_DAT_0001509c <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_000150a4,&@517,uVar5,
                (&TevRegNames)[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0xc & 0xe) + 1]);
        (**ppcRam00000000)(_DAT_0001509c,0x27,&__gxvDummyStr);
      }
      if (((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 10 & 7) < 4) &&
          (*(int *)((int)local_40 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 8 & 0x1c)) != 0)) &&
         ((int)_DAT_0001509c <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_000150a4,&@518,uVar5,
                (&TevRegNames)[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 9 & 0xe) + 1]);
        (**ppcRam00000000)(_DAT_0001509c,0x27,&__gxvDummyStr);
      }
      if (((((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 7 & 7) < 4) &&
          (*(int *)((int)local_40 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 5 & 0x1c)) != 0)) &&
         ((int)_DAT_0001509c <= (int)ppcRam00000000[1])) {
        sprintf(&__gxvDummyStr,_DAT_000150a4,&@519,uVar5,
                (&TevRegNames)[((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 6 & 0xe) + 1]);
        (**ppcRam00000000)(_DAT_0001509c,0x27,&__gxvDummyStr);
      }
    }
    *(undefined4 *)((int)local_50 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0x14 & 0xc)) = 1;
    *(undefined4 *)((int)local_60 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0x14 & 0xc)) = 1;
    *(uint *)((int)local_30 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0x14 & 0xc)) =
         (uint)(((uint)ppcRam00000000[uVar5 * 2 + 0x3f2] >> 0x13 & 1) == 0);
    *(uint *)((int)local_40 + ((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0x14 & 0xc)) =
         (uint)(((uint)ppcRam00000000[uVar5 * 2 + 0x3f3] >> 0x13 & 1) == 0);
    uVar5 = uVar5 + 1;
  } while( true );
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXVerifyPE(void)
{
  uint uVar1;
  
  if (0 < (int)ppcRam00000000[1]) {
    if (((((uint)ppcRam00000000[0x373] & 1) != 0) && (((uint)ppcRam00000000[0x373] >> 1 & 1) != 0))
       && (_DAT_000150bc <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_000150bc,0x2f,_DAT_000150c4);
    }
  }
  if (1 < (int)ppcRam00000000[1]) {
    if (((uint)ppcRam00000000[0x332] >> 9 & 1) != 0) {
      if (((uint)ppcRam00000000[0x375] & 7) != 2) {
        if (_DAT_000150c4 <= (int)ppcRam00000000[1]) {
          (**ppcRam00000000)(_DAT_000150c4,0x31,_DAT_000150cc);
        }
      }
    }
    if (((((uint)ppcRam00000000[0x332] >> 9 & 1) == 0) && (((uint)ppcRam00000000[0x375] & 7) == 2))
       && (_DAT_000150c8 <= (int)ppcRam00000000[1])) {
      (**ppcRam00000000)(_DAT_000150c8,0x32,_DAT_000150d0);
    }
  }
  if (2 < (int)ppcRam00000000[1]) {
    for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
      if (((((uint)ppcRam00000000[uVar1 + 0x333] >> 0xc & 0xf) <
            ((uint)ppcRam00000000[uVar1 + 0x333] >> 4 & 0xf)) ||
          (((uint)ppcRam00000000[uVar1 + 0x333] >> 0x14 & 0xf) <
           ((uint)ppcRam00000000[uVar1 + 0x333] >> 0xc & 0xf))) &&
         ((((uint)ppcRam00000000[0x375] & 7) == 2 && (_DAT_000150cc <= (int)ppcRam00000000[1])))) {
        sprintf(&__gxvDummyStr,_DAT_000150d4,uVar1);
        (**ppcRam00000000)(_DAT_000150cc,0x33,&__gxvDummyStr);
      }
    }
  }
  return;
}
