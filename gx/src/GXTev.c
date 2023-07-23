void GXSetTevOp(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 10;
  uVar1 = 5;
  if (cRam00000000 != '\0') {
    OSPanic(@16,0x76,...data.0);
  }
  if (param_1 != 0) {
    uVar2 = 0;
    uVar1 = 0;
  }
  if (param_2 == 2) {
    GXSetTevColorIn(param_1,uVar2,0xc,8,0xf);
    GXSetTevAlphaIn(param_1,7,4,uVar1,7);
    goto LAB_000101a0;
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      GXSetTevColorIn(param_1,0xf,8,uVar2,0xf);
      GXSetTevAlphaIn(param_1,7,4,uVar1,7);
      goto LAB_000101a0;
    }
    if (-1 < param_2) {
      GXSetTevColorIn(param_1,uVar2,8,9,0xf);
      GXSetTevAlphaIn(param_1,7,7,7,uVar1);
      goto LAB_000101a0;
    }
  }
  else {
    if (param_2 == 4) {
      GXSetTevColorIn(param_1,0xf,0xf,0xf,uVar2);
      GXSetTevAlphaIn(param_1,7,7,7,uVar1);
      goto LAB_000101a0;
    }
    if (param_2 < 4) {
      GXSetTevColorIn(param_1,0xf,0xf,0xf,8);
      GXSetTevAlphaIn(param_1,7,7,7,4);
      goto LAB_000101a0;
    }
  }
  OSPanic(@16,0x93,@18);
LAB_000101a0:
  GXSetTevColorOp(param_1,0,0,0,1,0);
  GXSetTevAlphaOp(param_1,0,0,0,1,0);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevColorIn(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0xe9,@20);
  }
  if (0xf < param_1) {
    OSPanic(@16,0xea,@21);
  }
  if (0xf < (int)param_2) {
    OSPanic(@16,0xeb,@22);
  }
  if (0xf < (int)param_3) {
    OSPanic(@16,0xec,@22);
  }
  if (0xf < (int)param_4) {
    OSPanic(@16,0xed,@22);
  }
  if (0xf < (int)param_5) {
    OSPanic(@16,0xee,@22);
  }
  puVar1 = (uint *)(iRam00000000 + param_1 * 4 + 0x130);
  if ((param_2 & 0xfffffff0) != 0) {
    OSPanic(@16,0xf1,@23);
  }
  *puVar1 = *puVar1 & 0xffff0fff | param_2 << 0xc;
  if ((param_3 & 0xfffffff0) != 0) {
    OSPanic(@16,0xf2,@23);
  }
  *puVar1 = *puVar1 & 0xfffff0ff | param_3 << 8;
  if ((param_4 & 0xfffffff0) != 0) {
    OSPanic(@16,0xf3,@23);
  }
  *puVar1 = *puVar1 & 0xffffff0f | param_4 << 4;
  if ((param_5 & 0xfffffff0) != 0) {
    OSPanic(@16,0xf4,@23);
  }
  *puVar1 = *puVar1 & 0xfffffff0 | param_5;
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevAlphaIn(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x10c,@25);
  }
  if (0xf < param_1) {
    OSPanic(@16,0x10d,@26);
  }
  if (7 < (int)param_2) {
    OSPanic(@16,0x10e,@22);
  }
  if (7 < (int)param_3) {
    OSPanic(@16,0x10f,@22);
  }
  if (7 < (int)param_4) {
    OSPanic(@16,0x110,@22);
  }
  if (7 < (int)param_5) {
    OSPanic(@16,0x111,@22);
  }
  puVar1 = (uint *)(iRam00000000 + param_1 * 4 + 0x170);
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(@16,0x114,@23);
  }
  *puVar1 = *puVar1 & 0xffff1fff | param_2 << 0xd;
  if ((param_3 & 0xfffffff8) != 0) {
    OSPanic(@16,0x115,@23);
  }
  *puVar1 = *puVar1 & 0xffffe3ff | param_3 << 10;
  if ((param_4 & 0xfffffff8) != 0) {
    OSPanic(@16,0x116,@23);
  }
  *puVar1 = *puVar1 & 0xfffffc7f | param_4 << 7;
  if ((param_5 & 0xfffffff8) != 0) {
    OSPanic(@16,0x117,@23);
  }
  *puVar1 = *puVar1 & 0xffffff8f | param_5 << 4;
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010660) */
/* WARNING: Removing unreachable block (ram,0x000106fc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevColorOp(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x132,@31);
  }
  if (0xf < param_1) {
    OSPanic(@16,0x133,@21);
  }
  puVar1 = (uint *)(iRam00000000 + param_1 * 4 + 0x130);
  *puVar1 = (param_2 & 1) << 0x12 | *puVar1 & 0xfffbffff;
  if ((int)param_2 < 2) {
    if ((param_4 & 0xfffffffc) != 0) {
      OSPanic(@16,0x13d,@23);
    }
    *puVar1 = *puVar1 & 0xffcfffff | param_4 << 0x14;
    if ((param_3 & 0xfffffffc) != 0) {
      OSPanic(@16,0x13e,@23);
    }
    *puVar1 = *puVar1 & 0xfffcffff | param_3 << 0x10;
  }
  else {
    *puVar1 = (param_2 & 6) << 0x13 | *puVar1 & 0xffcfffff;
    *puVar1 = *puVar1 & 0xfffcffff | 0x30000;
  }
  if ((param_5 & 0xfe) != 0) {
    OSPanic(@16,0x144,@23);
  }
  *puVar1 = *puVar1 & 0xfff7ffff | (param_5 & 0xff) << 0x13;
  if ((param_6 & 0xfffffffc) != 0) {
    OSPanic(@16,0x145,@23);
  }
  *puVar1 = *puVar1 & 0xff3fffff | param_6 << 0x16;
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010868) */
/* WARNING: Removing unreachable block (ram,0x00010904) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevAlphaOp(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x15e,@36);
  }
  if (0xf < param_1) {
    OSPanic(@16,0x15f,@26);
  }
  puVar1 = (uint *)(iRam00000000 + param_1 * 4 + 0x170);
  *puVar1 = (param_2 & 1) << 0x12 | *puVar1 & 0xfffbffff;
  if ((int)param_2 < 2) {
    if ((param_4 & 0xfffffffc) != 0) {
      OSPanic(@16,0x169,@23);
    }
    *puVar1 = *puVar1 & 0xffcfffff | param_4 << 0x14;
    if ((param_3 & 0xfffffffc) != 0) {
      OSPanic(@16,0x16a,@23);
    }
    *puVar1 = *puVar1 & 0xfffcffff | param_3 << 0x10;
  }
  else {
    *puVar1 = (param_2 & 6) << 0x13 | *puVar1 & 0xffcfffff;
    *puVar1 = *puVar1 & 0xfffcffff | 0x30000;
  }
  if ((param_5 & 0xfe) != 0) {
    OSPanic(@16,0x170,@23);
  }
  *puVar1 = *puVar1 & 0xfff7ffff | (param_5 & 0xff) << 0x13;
  if ((param_6 & 0xfffffffc) != 0) {
    OSPanic(@16,0x171,@23);
  }
  *puVar1 = *puVar1 & 0xff3fffff | param_6 << 0x16;
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010ac8) */
/* WARNING: Removing unreachable block (ram,0x00010a38) */
/* WARNING: Removing unreachable block (ram,0x00010a64) */
/* WARNING: Removing unreachable block (ram,0x00010af4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevColor(int param_1,byte *param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x186,@38);
  }
  bVar1 = *param_2;
  bVar2 = param_2[3];
  if ((param_1 * 2 + 0xe0U & 0xffffff00) != 0) {
    OSPanic(@16,0x18b,@23);
  }
  uVar5 = (param_1 * 2 + 0xe0) * 0x1000000;
  bVar3 = param_2[2];
  bVar4 = param_2[1];
  if ((param_1 * 2 + 0xe1U & 0xffffff00) != 0) {
    OSPanic(@16,400,@23);
  }
  uVar6 = (param_1 * 2 + 0xe1) * 0x1000000;
  _DAT_cc008000 = uVar6 | (uint)bVar4 << 0xc | (uint)bVar3;
  *(uint *)(iRam00000000 + (uVar5 >> 0x16) + 0xcc8) = uVar5 | (uint)bVar2 << 0xc | (uint)bVar1;
  *(uint *)(iRam00000000 + (uVar6 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(uint *)(iRam00000000 + (uVar6 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(uint *)(iRam00000000 + (uVar6 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010d94) */
/* WARNING: Removing unreachable block (ram,0x00010cfc) */
/* WARNING: Removing unreachable block (ram,0x00010d2c) */
/* WARNING: Removing unreachable block (ram,0x00010dc4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevColorS10(int param_1,short *param_2)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  
  if ((*param_2 < -0x400) || (0x3ff < *param_2)) {
    OSPanic(@16,0x1ab,@40);
  }
  if ((param_2[1] < -0x400) || (0x3ff < param_2[1])) {
    OSPanic(@16,0x1ac,@40);
  }
  if ((param_2[2] < -0x400) || (0x3ff < param_2[2])) {
    OSPanic(@16,0x1ad,@40);
  }
  if ((param_2[3] < -0x400) || (0x3ff < param_2[3])) {
    OSPanic(@16,0x1ae,@40);
  }
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x1b0,@41);
  }
  sVar1 = *param_2;
  sVar2 = param_2[3];
  if ((param_1 * 2 + 0xe0U & 0xffffff00) != 0) {
    OSPanic(@16,0x1b5,@23);
  }
  uVar5 = (param_1 * 2 + 0xe0) * 0x1000000;
  sVar3 = param_2[2];
  sVar4 = param_2[1];
  if ((param_1 * 2 + 0xe1U & 0xffffff00) != 0) {
    OSPanic(@16,0x1ba,@23);
  }
  uVar6 = (param_1 * 2 + 0xe1) * 0x1000000;
  _DAT_cc008000 = uVar6 | ((int)sVar4 & 0x7ffU) << 0xc | (int)sVar3 & 0x7ffU;
  *(uint *)(iRam00000000 + (uVar5 >> 0x16) + 0xcc8) =
       uVar5 | ((int)sVar2 & 0x7ffU) << 0xc | (int)sVar1 & 0x7ffU;
  *(uint *)(iRam00000000 + (uVar6 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(uint *)(iRam00000000 + (uVar6 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(uint *)(iRam00000000 + (uVar6 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010fb0) */
/* WARNING: Removing unreachable block (ram,0x00010f18) */
/* WARNING: Removing unreachable block (ram,0x00010f44) */
/* WARNING: Removing unreachable block (ram,0x00010fdc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevKColor(int param_1,byte *param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x1e1,@43);
  }
  bVar1 = *param_2;
  bVar2 = param_2[3];
  if ((param_1 * 2 + 0xe0U & 0xffffff00) != 0) {
    OSPanic(@16,0x1e7,@23);
  }
  uVar5 = (param_1 * 2 + 0xe0) * 0x1000000;
  bVar3 = param_2[2];
  bVar4 = param_2[1];
  if ((param_1 * 2 + 0xe1U & 0xffffff00) != 0) {
    OSPanic(@16,0x1ed,@23);
  }
  uVar6 = (param_1 * 2 + 0xe1) * 0x1000000;
  _DAT_cc008000 = uVar6 | (uint)bVar4 << 0xc | (uint)bVar3 | 0x800000;
  *(uint *)(iRam00000000 + (uVar5 >> 0x16) + 0xcc8) =
       uVar5 | (uint)bVar2 << 0xc | (uint)bVar1 | 0x800000;
  *(uint *)(iRam00000000 + (uVar6 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevKColorSel(uint param_1,uint param_2)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x208,@48);
  }
  if (0xf < (int)param_1) {
    OSPanic(@16,0x209,@49);
  }
  puVar1 = (uint *)(iRam00000000 + ((int)param_1 >> 1) * 4 + 0x1b0);
  if ((param_1 & 1) == 0) {
    if ((param_2 & 0xffffffe0) != 0) {
      OSPanic(@16,0x210,@23);
    }
    *puVar1 = *puVar1 & 0xfffffe0f | param_2 << 4;
  }
  else {
    if ((param_2 & 0xffffffe0) != 0) {
      OSPanic(@16,0x20e,@23);
    }
    *puVar1 = *puVar1 & 0xfff83fff | param_2 << 0xe;
  }
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevKAlphaSel(uint param_1,uint param_2)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x229,@54);
  }
  if (0xf < (int)param_1) {
    OSPanic(@16,0x22a,@49);
  }
  puVar1 = (uint *)(iRam00000000 + ((int)param_1 >> 1) * 4 + 0x1b0);
  if ((param_1 & 1) == 0) {
    if ((param_2 & 0xffffffe0) != 0) {
      OSPanic(@16,0x231,@23);
    }
    *puVar1 = *puVar1 & 0xffffc1ff | param_2 << 9;
  }
  else {
    if ((param_2 & 0xffffffe0) != 0) {
      OSPanic(@16,0x22f,@23);
    }
    *puVar1 = *puVar1 & 0xff07ffff | param_2 << 0x13;
  }
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevSwapMode(int param_1,uint param_2,uint param_3)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x24e,@56);
  }
  if (0xf < param_1) {
    OSPanic(@16,0x24f,@57);
  }
  puVar1 = (uint *)(iRam00000000 + param_1 * 4 + 0x170);
  if ((param_2 & 0xfffffffc) != 0) {
    OSPanic(@16,0x252,@23);
  }
  *puVar1 = *puVar1 & 0xfffffffc | param_2;
  if ((param_3 & 0xfffffffc) != 0) {
    OSPanic(@16,0x253,@23);
  }
  *puVar1 = *puVar1 & 0xfffffff3 | param_3 << 2;
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevSwapModeTable(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)
{
  uint *puVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x272,@59);
  }
  if (3 < param_1) {
    OSPanic(@16,0x273,@60);
  }
  puVar1 = (uint *)(iRam00000000 + param_1 * 8 + 0x1b0);
  if ((param_2 & 0xfffffffc) != 0) {
    OSPanic(@16,0x276,@23);
  }
  *puVar1 = *puVar1 & 0xfffffffc | param_2;
  if ((param_3 & 0xfffffffc) != 0) {
    OSPanic(@16,0x277,@23);
  }
  *puVar1 = *puVar1 & 0xfffffff3 | param_3 << 2;
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  puVar1 = (uint *)(iRam00000000 + (param_1 * 2 + 1) * 4 + 0x1b0);
  if ((param_4 & 0xfffffffc) != 0) {
    OSPanic(@16,0x27b,@23);
  }
  *puVar1 = *puVar1 & 0xfffffffc | param_4;
  if ((param_5 & 0xfffffffc) != 0) {
    OSPanic(@16,0x27c,@23);
  }
  *puVar1 = *puVar1 & 0xfffffff3 | param_5 << 2;
  _DAT_cc008000 = *puVar1;
  *(uint *)(iRam00000000 + (*puVar1 >> 0x16 & 0x3fc) + 0xcc8) = *puVar1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXSetTevClampMode(void)
{
  OSPanic(@16,0x294,@62);
  return;
}

/* WARNING: Removing unreachable block (ram,0x0001166c) */
/* WARNING: Removing unreachable block (ram,0x00011694) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetAlphaCompare(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x2b6,@64);
  }
  if ((param_1 & 0xfffffff8) != 0) {
    OSPanic(@16,0x2ba,@23);
  }
  if ((param_4 & 0xfffffff8) != 0) {
    OSPanic(@16,699,@23);
  }
  if ((param_3 & 0xfffffffc) != 0) {
    OSPanic(@16,700,@23);
  }
  _DAT_cc008000 =
       (((param_5 & 0xff) << 8 | param_2 & 0xff | (param_1 & 0xffc7) << 0x10 | param_4 << 0x13) &
        0xff3fffff | param_3 << 0x16) & 0xffffff | 0xf3000000;
  *(uint *)(iRam00000000 + 0x1094) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x0001184c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetZTexture(uint param_1,int param_2,uint param_3)
{
  uint uVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x2d5,@71);
  }
  if ((param_3 & 0xff000000) != 0) {
    OSPanic(@16,0x2d8,@23);
  }
  if (param_2 == 0x13) {
    uVar1 = 1;
  }
  else {
    if (param_2 < 0x13) {
      if (param_2 == 0x11) {
        uVar1 = 0;
        goto LAB_00011844;
      }
    }
    else if (param_2 == 0x16) {
      uVar1 = 2;
      goto LAB_00011844;
    }
    OSPanic(@16,0x2e1,@72);
    uVar1 = 2;
  }
LAB_00011844:
  if ((param_1 & 0xfffffffc) != 0) {
    OSPanic(@16,0x2e5,@23);
  }
  _DAT_cc008000 = uVar1 | (param_1 & 0x3fffff) << 2 | 0xf5000000;
  *(uint *)(iRam00000000 + 0x1098) = param_3 & 0xffffff | 0xf4000000;
  *(uint *)(iRam00000000 + 0x109c) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00011ad8) */
/* WARNING: Removing unreachable block (ram,0x00011c00) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevOrder(uint param_1,uint param_2,uint param_3,int param_4)
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x30b,@81);
  }
  if (0xf < (int)param_1) {
    OSPanic(@16,0x30c,@21);
  }
  puVar3 = (uint *)(iRam00000000 +
                   (((int)param_1 >> 1) + (uint)((int)param_1 < 0 && (param_1 & 1) != 0)) * 4 +
                   0x100);
  *(uint *)(iRam00000000 + param_1 * 4 + 0x49c) = param_3;
  uVar2 = param_3 & 0xfffffeff;
  if (7 < uVar2) {
    uVar2 = 0;
  }
  if ((int)param_2 < 8) {
    *(uint *)(iRam00000000 + 0x4e0) = *(uint *)(iRam00000000 + 0x4e0) | 1 << (param_1 & 0x3f);
  }
  else {
    param_2 = 0;
    *(uint *)(iRam00000000 + 0x4e0) = *(uint *)(iRam00000000 + 0x4e0) & ~(1 << (param_1 & 0x3f));
  }
  if ((param_1 & 1) == 0) {
    if ((uVar2 & 0xfffffff8) != 0) {
      OSPanic(@16,0x328,@23);
    }
    *puVar3 = *puVar3 & 0xfffffff8 | uVar2;
    if ((param_2 & 0xfffffff8) != 0) {
      OSPanic(@16,0x329,@23);
    }
    *puVar3 = *puVar3 & 0xffffffc7 | param_2 << 3;
    if (param_4 == 0xff) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(c2r$73 + param_4 * 4);
    }
    if ((uVar2 & 0xfffffff8) != 0) {
      OSPanic(@16,0x32b,@23);
    }
    if (param_4 == 0xff) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)(c2r$73 + param_4 * 4);
    }
    *puVar3 = *puVar3 & 0xfffffc7f | iVar1 << 7;
    iVar1 = 0;
    if ((param_3 != 0xff) && ((param_3 & 0x100) == 0)) {
      iVar1 = 1;
    }
    *puVar3 = *puVar3 & 0xffffffbf | iVar1 << 6;
  }
  else {
    if ((uVar2 & 0xfffffff8) != 0) {
      OSPanic(@16,800,@23);
    }
    *puVar3 = *puVar3 & 0xffff8fff | uVar2 << 0xc;
    if ((param_2 & 0xfffffff8) != 0) {
      OSPanic(@16,0x321,@23);
    }
    *puVar3 = *puVar3 & 0xfffc7fff | param_2 << 0xf;
    if (param_4 == 0xff) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(c2r$73 + param_4 * 4);
    }
    if ((uVar2 & 0xfffffff8) != 0) {
      OSPanic(@16,0x323,@23);
    }
    if (param_4 == 0xff) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)(c2r$73 + param_4 * 4);
    }
    *puVar3 = *puVar3 & 0xffc7ffff | iVar1 << 0x13;
    iVar1 = 0;
    if ((param_3 != 0xff) && ((param_3 & 0x100) == 0)) {
      iVar1 = 1;
    }
    *puVar3 = *puVar3 & 0xfffbffff | iVar1 << 0x12;
  }
  _DAT_cc008000 = *puVar3;
  *(uint *)(iRam00000000 + (*puVar3 >> 0x16 & 0x3fc) + 0xcc8) = *puVar3;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 1;
  return;
}

void GXSetNumTevStages(byte param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@16,0x33d,@83);
  }
  if (param_1 != 0) {
    if (param_1 < 0x11) goto LAB_00011d04;
  }
  OSPanic(@16,0x33f,@84);
LAB_00011d04:
  if ((param_1 - 1 & 0xfffffff0) != 0) {
    OSPanic(@16,0x340,@23);
  }
  *(uint *)(iRam00000000 + 0x204) =
       *(uint *)(iRam00000000 + 0x204) & 0xffffc3ff | (param_1 - 1) * 0x400;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 4;
  return;
}
