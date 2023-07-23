/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetGPMetric(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x70,@272);
  }
  iVar1 = *(int *)(iRam00000000 + 0x4e4);
  if (iVar1 == 0x22) {
LAB_00010080:
    _DAT_cc008000 = 0;
    *(undefined4 *)(iRam00000000 + 0x20) = 0;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
  }
  else if (iVar1 < 0x22) {
    if (iVar1 < 0xb) {
      if (-1 < iVar1) goto LAB_00010080;
LAB_00010134:
      OSPanic(...data.0,0xac,@273);
    }
    else if (iVar1 < 0x1b) {
      _DAT_cc008000 = 0x23000000;
      *(undefined4 *)(iRam00000000 + 0xd54) = 0x23000000;
    }
    else {
      _DAT_cc008000 = 0x24000000;
      *(undefined4 *)(iRam00000000 + 0xd58) = 0x24000000;
    }
  }
  else if (0x23 < iVar1) goto LAB_00010134;
  iVar1 = *(int *)(iRam00000000 + 0x4e8);
  if (iVar1 == 0x15) {
LAB_00010188:
    _DAT_cc008000 = 0x67000000;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000000;
  }
  else {
    if (iVar1 < 0x15) {
      if (8 < iVar1) {
        if (iVar1 < 0x11) {
          *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f;
          _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
        }
        else {
          *(undefined2 *)(iRam00000000 + 6) = 0;
        }
        goto LAB_00010220;
      }
      if (-1 < iVar1) goto LAB_00010188;
    }
    else if (iVar1 < 0x17) goto LAB_00010220;
    OSPanic(...data.0,0xde,@274);
  }
LAB_00010220:
  *(undefined4 *)(iRam00000000 + 0x4e4) = param_1;
  switch(*(undefined4 *)(iRam00000000 + 0x4e4)) {
  case 0:
    _DAT_cc008000 = 0x273;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x273;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 1:
    _DAT_cc008000 = 0x14a;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x14a;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 2:
    _DAT_cc008000 = 0x16b;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x16b;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 3:
    _DAT_cc008000 = 0x84;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x84;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 4:
    _DAT_cc008000 = 0xc6;
    *(undefined4 *)(iRam00000000 + 0x20) = 0xc6;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 5:
    _DAT_cc008000 = 0x210;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x210;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 6:
    _DAT_cc008000 = 0x252;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x252;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 7:
    _DAT_cc008000 = 0x231;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x231;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 8:
    _DAT_cc008000 = 0x1ad;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x1ad;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 9:
    _DAT_cc008000 = 0x1ce;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x1ce;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 10:
    _DAT_cc008000 = 0x153;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x153;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 0xb:
    _DAT_cc008000 = 0x2300ae7f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300ae7f;
    break;
  case 0xc:
    _DAT_cc008000 = 0x23008e7f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x23008e7f;
    break;
  case 0xd:
    _DAT_cc008000 = 0x23009e7f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x23009e7f;
    break;
  case 0xe:
    _DAT_cc008000 = 0x23001e7f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x23001e7f;
    break;
  case 0xf:
    _DAT_cc008000 = 0x2300ac3f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300ac3f;
    break;
  case 0x10:
    _DAT_cc008000 = 0x2300ac7f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300ac7f;
    break;
  case 0x11:
    _DAT_cc008000 = 0x2300acbf;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300acbf;
    break;
  case 0x12:
    _DAT_cc008000 = 0x2300acff;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300acff;
    break;
  case 0x13:
    _DAT_cc008000 = 0x2300ad3f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300ad3f;
    break;
  case 0x14:
    _DAT_cc008000 = 0x2300ad7f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300ad7f;
    break;
  case 0x15:
    _DAT_cc008000 = 0x2300adbf;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300adbf;
    break;
  case 0x16:
    _DAT_cc008000 = 0x2300adff;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300adff;
    break;
  case 0x17:
    _DAT_cc008000 = 0x2300ae3f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300ae3f;
    break;
  case 0x18:
    _DAT_cc008000 = 0x2300a27f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300a27f;
    break;
  case 0x19:
    _DAT_cc008000 = 0x2300a67f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300a67f;
    break;
  case 0x1a:
    _DAT_cc008000 = 0x2300aa7f;
    *(undefined4 *)(iRam00000000 + 0xd54) = 0x2300aa7f;
    break;
  case 0x1b:
    _DAT_cc008000 = 0x2402c0c6;
    *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c0c6;
    break;
  case 0x1c:
    _DAT_cc008000 = 0x2402c16b;
    *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c16b;
    break;
  case 0x1d:
    _DAT_cc008000 = 0x2402c0e7;
    *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c0e7;
    break;
  case 0x1e:
    _DAT_cc008000 = 0x2402c108;
    *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c108;
    break;
  case 0x1f:
    _DAT_cc008000 = 0x2402c129;
    *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c129;
    break;
  case 0x20:
    _DAT_cc008000 = 0x2402c14a;
    *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c14a;
    break;
  case 0x21:
    _DAT_cc008000 = 0x2402c1ad;
    *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c1ad;
    break;
  case 0x22:
    _DAT_cc008000 = 0x21;
    *(undefined4 *)(iRam00000000 + 0x20) = 0x21;
    *(undefined *)(iRam00000000 + 0x10ce) = 1;
    break;
  case 0x23:
    break;
  default:
    OSPanic(...data.0,0x1e0,@273);
  }
  *(undefined4 *)(iRam00000000 + 0x4e8) = param_2;
  switch(*(undefined4 *)(iRam00000000 + 0x4e8)) {
  case 0:
    _DAT_cc008000 = 0x67000042;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000042;
    break;
  case 1:
    _DAT_cc008000 = 0x67000084;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000084;
    break;
  case 2:
    _DAT_cc008000 = 0x67000063;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000063;
    break;
  case 3:
    _DAT_cc008000 = 0x67000129;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000129;
    break;
  case 4:
    _DAT_cc008000 = 0x6700014b;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x6700014b;
    break;
  case 5:
    _DAT_cc008000 = 0x6700018d;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x6700018d;
    break;
  case 6:
    _DAT_cc008000 = 0x670001cf;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x670001cf;
    break;
  case 7:
    _DAT_cc008000 = 0x67000211;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000211;
    break;
  case 8:
    _DAT_cc008000 = 0x67000252;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000252;
    break;
  case 9:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x20;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 10:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x30;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 0xb:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x40;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 0xc:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x50;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 0xd:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x60;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 0xe:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x70;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 0xf:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x90;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 0x10:
    *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xffffff0f | 0x80;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x4ec);
    break;
  case 0x11:
    *(undefined2 *)(iRam00000000 + 6) = 2;
    break;
  case 0x12:
    *(undefined2 *)(iRam00000000 + 6) = 3;
    break;
  case 0x13:
    *(undefined2 *)(iRam00000000 + 6) = 4;
    break;
  case 0x14:
    *(undefined2 *)(iRam00000000 + 6) = 5;
    break;
  case 0x15:
    _DAT_cc008000 = 0x67000021;
    *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000021;
    break;
  case 0x16:
    break;
  default:
    OSPanic(...data.0,0x271,@274);
  }
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXReadGPMetric(uint *param_1,int *param_2)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)(iRam00000000 + 0x4f0) != '\0') {
    OSPanic(...data.0,0x28c,@341);
  }
  uVar2 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x42),*(undefined2 *)(iRam00000000 + 0x40));
  iVar3 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x4a),*(undefined2 *)(iRam00000000 + 0x48));
  iVar4 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x4e),*(undefined2 *)(iRam00000000 + 0x4c));
  iVar1 = *(int *)(iRam00000000 + 0x4e4);
  if (iVar1 == 10) {
    *param_1 = (uint)(CONCAT22(*(undefined2 *)(iRam00000000 + 0x46),
                               *(undefined2 *)(iRam00000000 + 0x44)) * 1000) / uVar2;
    goto LAB_00011104;
  }
  if (iVar1 < 10) {
    if (-1 < iVar1) {
LAB_000110d4:
      *param_1 = uVar2;
      goto LAB_00011104;
    }
  }
  else {
    if (iVar1 == 0x23) {
      *param_1 = 0;
      goto LAB_00011104;
    }
    if (iVar1 < 0x23) goto LAB_000110d4;
  }
  OSPanic(...data.0,0x2d5,@342);
  *param_1 = 0;
LAB_00011104:
  switch(*(undefined4 *)(iRam00000000 + 0x4e8)) {
  case 0:
    *param_2 = iVar4 << 2;
    break;
  case 1:
  case 2:
  case 3:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x15:
    *param_2 = iVar4;
    break;
  case 4:
    *param_2 = iVar3 + iVar4 * 2;
    break;
  case 5:
    *param_2 = iVar3 * 3 + iVar4 * 4;
    break;
  case 6:
    *param_2 = iVar3 * 5 + iVar4 * 6;
    break;
  case 7:
    *param_2 = iVar3 * 7 + iVar4 * 8;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    *param_2 = iVar3;
    break;
  case 0x16:
    *param_2 = 0;
    break;
  default:
    OSPanic(...data.0,0x310,@343);
    *param_2 = 0;
  }
  return;
}

void GXClearGPMetric(void)
{
  if (*(char *)(iRam00000000 + 0x4f0) != '\0') {
    OSPanic(...data.0,0x327,@346);
  }
  *(undefined2 *)(iRam00000000 + 4) = 4;
  return;
}

undefined4 GXReadGP0Metric(void)
{
  undefined auStack_8 [4];
  undefined4 local_4;
  
  GXReadGPMetric(&local_4,auStack_8);
  return local_4;
}

undefined4 GXReadGP1Metric(void)
{
  undefined4 local_8;
  undefined auStack_4 [4];
  
  GXReadGPMetric(auStack_4,&local_8);
  return local_8;
}

void GXReadMemMetric(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4
                    ,undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8
                    ,undefined4 *param_9,undefined4 *param_10)
{
  if (*(char *)(iRam00000000 + 0x4f0) != '\0') {
    OSPanic(...data.0,900,@350);
  }
  *param_1 = *(undefined4 *)(iRam00000000 + 0x32);
  *param_2 = *(undefined4 *)(iRam00000000 + 0x36);
  *param_3 = *(undefined4 *)(iRam00000000 + 0x3a);
  *param_4 = *(undefined4 *)(iRam00000000 + 0x3e);
  *param_5 = *(undefined4 *)(iRam00000000 + 0x42);
  *param_6 = *(undefined4 *)(iRam00000000 + 0x46);
  *param_7 = *(undefined4 *)(iRam00000000 + 0x4a);
  *param_8 = *(undefined4 *)(iRam00000000 + 0x4e);
  *param_9 = *(undefined4 *)(iRam00000000 + 0x52);
  *param_10 = *(undefined4 *)(iRam00000000 + 0x56);
  return;
}

void GXClearMemMetric(void)
{
  if (*(char *)(iRam00000000 + 0x4f0) != '\0') {
    OSPanic(...data.0,0x3bd,@352);
  }
  *(undefined2 *)(iRam00000000 + 0x32) = 0;
  *(undefined2 *)(iRam00000000 + 0x34) = 0;
  *(undefined2 *)(iRam00000000 + 0x36) = 0;
  *(undefined2 *)(iRam00000000 + 0x38) = 0;
  *(undefined2 *)(iRam00000000 + 0x3c) = 0;
  *(undefined2 *)(iRam00000000 + 0x3a) = 0;
  *(undefined2 *)(iRam00000000 + 0x40) = 0;
  *(undefined2 *)(iRam00000000 + 0x3e) = 0;
  *(undefined2 *)(iRam00000000 + 0x44) = 0;
  *(undefined2 *)(iRam00000000 + 0x42) = 0;
  *(undefined2 *)(iRam00000000 + 0x48) = 0;
  *(undefined2 *)(iRam00000000 + 0x46) = 0;
  *(undefined2 *)(iRam00000000 + 0x4c) = 0;
  *(undefined2 *)(iRam00000000 + 0x4a) = 0;
  *(undefined2 *)(iRam00000000 + 0x50) = 0;
  *(undefined2 *)(iRam00000000 + 0x4e) = 0;
  *(undefined2 *)(iRam00000000 + 0x54) = 0;
  *(undefined2 *)(iRam00000000 + 0x52) = 0;
  *(undefined2 *)(iRam00000000 + 0x58) = 0;
  *(undefined2 *)(iRam00000000 + 0x56) = 0;
  return;
}

void GXReadPixMetric(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,
                    undefined4 *param_6)
{
  if (*(char *)(iRam00000000 + 0x4f0) != '\0') {
    OSPanic(...data.0,0x3f5,@354);
  }
  *param_1 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x1a),*(undefined2 *)(iRam00000000 + 0x18)) <<
             2;
  *param_2 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x1e),*(undefined2 *)(iRam00000000 + 0x1c)) <<
             2;
  *param_3 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x22),*(undefined2 *)(iRam00000000 + 0x20)) <<
             2;
  *param_4 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x26),*(undefined2 *)(iRam00000000 + 0x24)) <<
             2;
  *param_5 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x2a),*(undefined2 *)(iRam00000000 + 0x28)) <<
             2;
  *param_6 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x2e),*(undefined2 *)(iRam00000000 + 0x2c));
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXClearPixMetric(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x421,@356);
  }
  *(undefined4 *)(iRam00000000 + 0xe24) = 0x57000000;
  _DAT_cc008000 = 0x57000aaa;
  *(undefined4 *)(iRam00000000 + 0xe24) = 0x57000aaa;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetVCacheMetric(uint param_1)
{
  if ((param_1 & 0xfffffff0) != 0) {
    OSPanic(...data.0,0x440,@380);
  }
  *(uint *)(iRam00000000 + 0x4ec) = *(uint *)(iRam00000000 + 0x4ec) & 0xfffffff0 | param_1;
  _DAT_cc008000 = 1;
  return;
}

void GXReadVCacheMetric(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)
{
  *param_1 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x52),*(undefined2 *)(iRam00000000 + 0x50));
  *param_2 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x56),*(undefined2 *)(iRam00000000 + 0x54));
  *param_3 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x5a),*(undefined2 *)(iRam00000000 + 0x58));
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXClearVCacheMetric(void)
{
  _DAT_cc008000 = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXInitXfRasMetric(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x48d,@398);
  }
  *(undefined4 *)(iRam00000000 + 0xd58) = 0x2402c022;
  _DAT_cc008000 = 0x31000;
  *(undefined4 *)(iRam00000000 + 0x20) = 0x31000;
  *(undefined *)(iRam00000000 + 0x10ce) = 1;
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

void GXReadXfRasMetric(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,
                      undefined4 *param_4)
{
  *param_3 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x42),*(undefined2 *)(iRam00000000 + 0x40));
  *param_4 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x46),*(undefined2 *)(iRam00000000 + 0x44));
  *param_1 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x4a),*(undefined2 *)(iRam00000000 + 0x48));
  *param_2 = CONCAT22(*(undefined2 *)(iRam00000000 + 0x4e),*(undefined2 *)(iRam00000000 + 0x4c));
  return;
}

ushort GXReadClksPerVtx(void)
{
  GXDrawDone();
  *(undefined2 *)(iRam00000000 + 0x62) = 0x1007;
  *(undefined2 *)(iRam00000000 + 0x60) = 0x1007;
  return *(ushort *)(iRam00000000 + 100) >> 8;
}
