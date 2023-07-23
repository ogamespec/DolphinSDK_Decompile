void __GXGetTexTileShift(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  switch(param_1) {
  case 0:
  case 8:
  case 0xe:
  case 0x20:
  case 0x30:
    *param_2 = 3;
    *param_3 = 3;
    break;
  case 1:
  case 2:
  case 9:
  case 0x11:
  case 0x22:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x39:
  case 0x3a:
    *param_2 = 3;
    *param_3 = 2;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 10:
  case 0x13:
  case 0x16:
  case 0x23:
  case 0x2b:
  case 0x2c:
  case 0x3c:
    *param_2 = 2;
    *param_3 = 2;
    break;
  default:
    *param_3 = 0;
    *param_2 = 0;
    OSPanic(...data.0,0x19b,@37,&@38);
  }
  return;
}

int GXGetTexBufferSize(uint param_1,uint param_2,int param_3,char param_4,byte param_5)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_34;
  uint local_30 [3];
  
  if (0x400 < (param_1 & 0xffff)) {
    OSPanic(...data.0,0x1ab,@56,@57);
  }
  if (0x400 < (param_2 & 0xffff)) {
    OSPanic(...data.0,0x1ac,@58,@57);
  }
  __GXGetTexTileShift(param_3,local_30,&local_34);
  if ((param_3 == 6) || (param_3 == 0x16)) {
    iVar3 = 0x40;
  }
  else {
    iVar3 = 0x20;
  }
  if (param_4 == '\x01') {
    if ((param_1 & 0xffff) != 1 << (0x1fU - LZCOUNT(param_1 & 0xffff) & 0x3f)) {
      OSPanic(...data.0,0x1be,@59,@57);
    }
    if ((param_2 & 0xffff) != 1 << (0x1fU - LZCOUNT(param_2 & 0xffff) & 0x3f)) {
      OSPanic(...data.0,0x1c1,@60,@57);
    }
    iVar2 = 0;
    uVar1 = 0;
    while ((uVar1 < param_5 &&
           ((iVar2 = iVar2 + iVar3 * ((int)((param_1 & 0xffff) + (1 << (local_30[0] & 0x3f)) + -1)
                                     >> (local_30[0] & 0x3f)) *
                                     ((int)((param_2 & 0xffff) + (1 << (local_34 & 0x3f)) + -1) >>
                                     (local_34 & 0x3f)), (param_1 & 0xffff) != 1 ||
            ((param_2 & 0xffff) != 1))))) {
      if ((param_1 & 0xffff) < 2) {
        param_1 = 1;
      }
      else {
        param_1 = param_1 >> 1 & 0x7fff;
      }
      if ((param_2 & 0xffff) < 2) {
        param_2 = 1;
      }
      else {
        param_2 = param_2 >> 1 & 0x7fff;
      }
      uVar1 = uVar1 + 1;
    }
  }
  else {
    iVar2 = iVar3 * ((int)((param_1 & 0xffff) + (1 << (local_30[0] & 0x3f)) + -1) >>
                    (local_30[0] & 0x3f)) *
                    ((int)((param_2 & 0xffff) + (1 << (local_34 & 0x3f)) + -1) >> (local_34 & 0x3f))
    ;
  }
  return iVar2;
}

void __GetImageTileCount(int param_1,ushort param_2,ushort param_3,int *param_4,int *param_5,
                        undefined4 *param_6)
{
  undefined4 uVar1;
  uint local_1c;
  uint local_18 [3];
  
  __GXGetTexTileShift(param_1,local_18,&local_1c);
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (param_3 == 0) {
    param_3 = 1;
  }
  *param_4 = (int)((uint)param_2 + (1 << (local_18[0] & 0x3f)) + -1) >> (local_18[0] & 0x3f);
  *param_5 = (int)((uint)param_3 + (1 << (local_1c & 0x3f)) + -1) >> (local_1c & 0x3f);
  if ((param_1 == 6) || (param_1 == 0x16)) {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  *param_6 = uVar1;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010678) */
/* WARNING: Removing unreachable block (ram,0x0001073c) */
void GXInitTexObj(uint *param_1,uint param_2,ushort param_3,ushort param_4,uint param_5,uint param_6
                 ,uint param_7,char param_8)
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x214,@97);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x216,@98);
  }
  if (0x400 < param_3) {
    OSPanic(...data.0,0x217,@56,@99);
  }
  if (0x400 < param_4) {
    OSPanic(...data.0,0x218,@58,@99);
  }
  if ((param_5 & 0x20) != 0) {
    OSPanic(...data.0,0x21a,@37,@99);
  }
  if (((param_6 != 0) || (param_8 != '\0')) &&
     ((uint)param_3 != 1 << (0x1fU - LZCOUNT((uint)param_3) & 0x3f))) {
    OSPanic(...data.0,0x224,@59,@99);
  }
  if (((param_7 != 0) || (param_8 != '\0')) &&
     ((uint)param_4 != 1 << (0x1fU - LZCOUNT((uint)param_4) & 0x3f))) {
    OSPanic(...data.0,0x229,@60,@99);
  }
  memset(param_1,0,0x20);
  if ((param_6 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x237,@100);
  }
  *param_1 = *param_1 & 0xfffffffc | param_6;
  if ((param_7 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x238,@100);
  }
  *param_1 = *param_1 & 0xfffffff3 | param_7 << 2;
  *param_1 = *param_1 & 0xffffffef | 0x10;
  if (param_8 == '\0') {
    *param_1 = *param_1 & 0xffffff1f | 0x80;
  }
  else {
    *(byte *)((int)param_1 + 0x1f) = *(byte *)((int)param_1 + 0x1f) | 1;
    if (((param_5 == 8) || (param_5 == 9)) || (param_5 == 10)) {
      *param_1 = *param_1 & 0xffffff1f | 0xa0;
    }
    else {
      *param_1 = *param_1 & 0xffffff1f | 0xc0;
    }
    uVar1 = param_4;
    if (param_4 < param_3) {
      uVar1 = param_3;
    }
    param_1[1] = ((int)(@101 * (float)((double)CONCAT44(0x43300000,0x1f - LZCOUNT((uint)uVar1)) -
                                      @106)) & 0xffU) << 8 | param_1[1] & 0xffff00ff;
  }
  param_1[5] = param_5;
  if ((param_3 - 1 & 0xfffffc00) != 0) {
    OSPanic(...data.0,0x265,@100);
  }
  param_1[2] = param_1[2] & 0xfffffc00 | param_3 - 1;
  if ((param_4 - 1 & 0xfffffc00) != 0) {
    OSPanic(...data.0,0x266,@100);
  }
  param_1[2] = param_1[2] & 0xfff003ff | (param_4 - 1) * 0x400;
  param_1[2] = (param_5 & 0xf) << 0x14 | param_1[2] & 0xff0fffff;
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x26d,@102,@99,@103);
  }
  if ((param_2 >> 5 & 0x1e00000) != 0) {
    OSPanic(...data.0,0x26f,@100);
  }
  param_1[3] = param_1[3] & 0xffe00000 | param_2 >> 5 & 0x1ffffff;
  switch(param_5 & 0xf) {
  case 0:
  case 8:
    *(undefined *)((int)param_1 + 0x1e) = 1;
    iVar3 = 3;
    iVar2 = 3;
    break;
  case 1:
  case 2:
  case 9:
    *(undefined *)((int)param_1 + 0x1e) = 2;
    iVar3 = 3;
    iVar2 = 2;
    break;
  case 3:
  case 4:
  case 5:
  case 10:
    *(undefined *)((int)param_1 + 0x1e) = 2;
    iVar3 = 2;
    iVar2 = 2;
    break;
  case 6:
    *(undefined *)((int)param_1 + 0x1e) = 3;
    iVar3 = 2;
    iVar2 = 2;
    break;
  default:
    OSPanic(...data.0,0x29a,@37,@104);
    *(undefined *)((int)param_1 + 0x1e) = 2;
    iVar3 = 2;
    iVar2 = 2;
    break;
  case 0xe:
    *(undefined *)((int)param_1 + 0x1e) = 0;
    iVar3 = 3;
    iVar2 = 3;
  }
  *(ushort *)(param_1 + 7) =
       (short)((int)((uint)param_3 + (1 << iVar3) + -1) >> iVar3) *
       (short)((int)((uint)param_4 + (1 << iVar2) + -1) >> iVar2) & 0x7fff;
  *(byte *)((int)param_1 + 0x1f) = *(byte *)((int)param_1 + 0x1f) | 2;
  return;
}

void GXInitTexObjCI(int param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined param_8,
                   undefined4 param_9)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x2c0,@97);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x2c2,@110);
  }
  GXInitTexObj(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  *(byte *)(param_1 + 0x1f) = *(byte *)(param_1 + 0x1f) & 0xfd;
  *(undefined4 *)(param_1 + 0x18) = param_9;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010c8c) */
/* WARNING: Removing unreachable block (ram,0x00010a68) */
/* WARNING: Removing unreachable block (ram,0x00010b5c) */
/* WARNING: Removing unreachable block (ram,0x00010cbc) */
/* WARNING: Removing unreachable block (ram,0x00010aa8) */
void GXInitTexObjLOD(undefined8 param_1,double param_2,double param_3,undefined4 param_4,
                    undefined4 param_5,int param_6,uint param_7,uint param_8,uint param_9)
{
  uint *puVar1;
  uint uVar2;
  double dVar3;
  double extraout_f1;
  double dVar4;
  undefined8 uVar5;
  
  uVar5 = _savefpr_29();
  puVar1 = (uint *)((ulonglong)uVar5 >> 0x20);
  uVar2 = (uint)uVar5;
  dVar4 = extraout_f1;
  if (puVar1 == (uint *)0x0) {
    OSPanic(...data.0,0x2e7,@97);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x2e9,@127);
  }
  if ((double)@128 <= param_3) {
    if ((double)@129 <= param_3) {
      param_3 = (double)@130;
    }
  }
  else {
    param_3 = (double)@128;
  }
  *puVar1 = ((int)((double)@131 * param_3) & 0xffU) << 9 | *puVar1 & 0xfffe01ff;
  *puVar1 = *puVar1 & 0xffffffef | (uint)(param_6 == 1) << 4;
  if (5 < uVar2) {
    OSPanic(...data.0,0x2f6,@132);
  }
  if ((*(byte *)((int)&GX2HWFiltConv + uVar2) & 0xf8) != 0) {
    OSPanic(...data.0,0x2f7,@100);
  }
  *puVar1 = *puVar1 & 0xffffff1f | (uint)*(byte *)((int)&GX2HWFiltConv + uVar2) << 5;
  *puVar1 = *puVar1 & 0xfffffeff | (uint)((param_8 & 0xff) == 0) << 8;
  *puVar1 = *puVar1 & 0xfffdffff;
  *puVar1 = *puVar1 & 0xfffbffff;
  if ((param_9 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x2fb,@100);
  }
  *puVar1 = *puVar1 & 0xffe7ffff | param_9 << 0x13;
  if ((param_7 & 0xfe) != 0) {
    OSPanic(...data.0,0x2fc,@100);
  }
  *puVar1 = *puVar1 & 0xffdfffff | (param_7 & 0xff) << 0x15;
  if ((double)@133 <= dVar4) {
    if ((double)@134 < dVar4) {
      dVar4 = (double)@134;
    }
  }
  else {
    dVar4 = (double)@133;
  }
  if ((double)@133 <= param_2) {
    if ((double)@134 < param_2) {
      param_2 = (double)@134;
    }
  }
  else {
    param_2 = (double)@133;
  }
  dVar3 = (double)@101;
  puVar1[1] = puVar1[1] & 0xffffff00 | (int)((double)@101 * dVar4) & 0xffU;
  puVar1[1] = ((int)(dVar3 * param_2) & 0xffU) << 8 | puVar1[1] & 0xffff00ff;
  _restfpr_29();
  return;
}

void GXInitTexObjData(int param_1,uint param_2)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x31e,@97);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,800,@137);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x323,@102,@138,@103);
  }
  if ((param_2 >> 5 & 0x1e00000) != 0) {
    OSPanic(...data.0,0x326,@100);
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffe00000 | param_2 >> 5 & 0x1ffffff;
  return;
}

void GXInitTexObjWrapMode(uint *param_1,uint param_2,uint param_3)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x338,@97);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x33a,@140);
  }
  if ((param_2 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x33c,@100);
  }
  *param_1 = *param_1 & 0xfffffffc | param_2;
  if ((param_3 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x33d,@100);
  }
  *param_1 = *param_1 & 0xfffffff3 | param_3 << 2;
  return;
}

void GXInitTexObjTlut(int param_1,undefined4 param_2)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x34e,@97);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x350,@142);
  }
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}

void GXInitTexObjUserData(int param_1,undefined4 param_2)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x363,@97);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x364,@144);
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}

undefined4 GXGetTexObjUserData(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x36a,@97);
  }
  return *(undefined4 *)(param_1 + 0x10);
}

void GXGetTexObjAll(uint *param_1,int *param_2,short *param_3,short *param_4,uint *param_5,
                   uint *param_6,uint *param_7,undefined4 param_8)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x37e,@97);
  }
  *param_2 = (param_1[3] & 0x1fffff) << 5;
  *param_3 = ((ushort)param_1[2] & 0x3ff) + 1;
  *param_4 = ((ushort)(param_1[2] >> 10) & 0x3ff) + 1;
  *param_5 = param_1[5];
  *param_6 = *param_1 & 3;
  *param_7 = *param_1 >> 2 & 3;
  *(bool *)param_8 = (*(byte *)((int)param_1 + 0x1f) & 1) == 1;
  return;
}

int GXGetTexObjData(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x38b,@97);
  }
  return (*(uint *)(param_1 + 0xc) & 0x1fffff) << 5;
}

int GXGetTexObjWidth(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x391,@97);
  }
  return (*(uint *)(param_1 + 8) & 0x3ff) + 1;
}

int GXGetTexObjHeight(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x397,@97);
  }
  return (*(uint *)(param_1 + 8) >> 10 & 0x3ff) + 1;
}

undefined4 GXGetTexObjFmt(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x39d,@97);
  }
  return *(undefined4 *)(param_1 + 0x14);
}

uint GXGetTexObjWrapS(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x3a3,@97);
  }
  return *param_1 & 3;
}


uint GXGetTexObjWrapT(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x3a9,@97);
  }
  return *param_1 >> 2 & 3;
}

bool GXGetTexObjMipMap(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x3af,@97);
  }
  return (*(byte *)(param_1 + 0x1f) & 1) == 1;
}

void GXGetTexObjLODAll(uint *param_1,uint *param_2,uint *param_3,float *param_4,float *param_5,
                      float *param_6,byte *param_7,undefined4 param_8,uint *param_9)
{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x3c5,@97);
  }
  *param_2 = (uint)*(byte *)((int)&HW2GXFiltConv + (*param_1 >> 5 & 7));
  *param_3 = *param_1 >> 4 & 1;
  *param_4 = (float)((double)CONCAT44(0x43300000,param_1[1] & 0xff) - @106) * @157;
  *param_5 = (float)((double)CONCAT44(0x43300000,param_1[1] >> 8 & 0xff) - @106) * @157;
  uVar1 = (ushort)(*param_1 >> 9);
  uVar2 = uVar1 & 0xff;
  if ((*param_1 >> 9 & 0x80) != 0) {
    uVar2 = -(uVar1 & 0x7f);
  }
  *param_6 = @131 * (float)((double)CONCAT44(0x43300000,(int)(short)uVar2 ^ 0x80000000) - @160);
  *param_7 = (byte)(*param_1 >> 0x15) & 1;
  *(bool *)param_8 = (*param_1 >> 8 & 1) == 0;
  *param_9 = *param_1 >> 0x13 & 3;
  return;
}

undefined GXGetTexObjMinFilt(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x3d7,@97);
  }
  return *(undefined *)((int)&HW2GXFiltConv + (*param_1 >> 5 & 7));
}

uint GXGetTexObjMagFilt(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x3de,@97);
  }
  return *param_1 >> 4 & 1;
}

double GXGetTexObjMinLOD(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x3e4,@97);
  }
  return (double)((float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 4) & 0xff) - @106) * @157)
  ;
}

double GXGetTexObjMaxLOD(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x3ea,@97);
  }
  return (double)((float)((double)CONCAT44(0x43300000,*(uint *)(param_1 + 4) >> 8 & 0xff) - @106) *
                 @157);
}

double GXGetTexObjLODBias(uint *param_1)
{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x3f1,@97);
  }
  uVar1 = (ushort)(*param_1 >> 9);
  uVar2 = uVar1 & 0xff;
  if ((*param_1 >> 9 & 0x80) != 0) {
    uVar2 = -(uVar1 & 0x7f);
  }
  return (double)(@131 * (float)((double)CONCAT44(0x43300000,(int)(short)uVar2 ^ 0x80000000) - @160) );
}

uint GXGetTexObjBiasClamp(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x3fa,@97);
  }
  return *param_1 >> 0x15 & 1;
}

bool GXGetTexObjEdgeLOD(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x400,@97);
  }
  return (*param_1 >> 8 & 1) == 0;
}

uint GXGetTexObjMaxAniso(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x406,@97);
  }
  return *param_1 >> 0x13 & 3;
}

undefined4 GXGetTexObjTlut(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x40c,@97);
  }
  return *(undefined4 *)(param_1 + 0x18);
}

/* WARNING: Removing unreachable block (ram,0x00011a50) */
/* WARNING: Removing unreachable block (ram,0x000119d8) */
/* WARNING: Removing unreachable block (ram,0x00011960) */
/* WARNING: Removing unreachable block (ram,0x00011924) */
/* WARNING: Removing unreachable block (ram,0x0001199c) */
/* WARNING: Removing unreachable block (ram,0x00011a14) */
/* WARNING: Removing unreachable block (ram,0x00011c18) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadTexObjPreLoaded(uint *param_1,uint *param_2,int param_3)
{
  int iVar1;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x423,@97);
  }
  if (param_2 == (uint *)0x0) {
    OSPanic(...data.0,0x423,@178);
  }
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x425,@179);
  }
  if (7 < param_3) {
    OSPanic(...data.0,0x426,@180,@181);
  }
  *param_1 = *param_1 & 0xffffff | (uint)*(byte *)((int)&GXTexMode0Ids + param_3) << 0x18;
  param_1[1] = param_1[1] & 0xffffff | (uint)*(byte *)((int)&GXTexMode1Ids + param_3) << 0x18;
  param_1[2] = param_1[2] & 0xffffff | (uint)*(byte *)((int)&GXTexImage0Ids + param_3) << 0x18;
  *param_2 = *param_2 & 0xffffff | (uint)*(byte *)((int)&GXTexImage1Ids + param_3) << 0x18;
  param_2[1] = param_2[1] & 0xffffff | (uint)*(byte *)((int)&GXTexImage2Ids + param_3) << 0x18;
  param_1[3] = param_1[3] & 0xffffff | (uint)*(byte *)((int)&GXTexImage3Ids + param_3) << 0x18;
  *(uint *)(iRam00000000 + (*param_1 >> 0x16 & 0x3fc) + 0xcc8) = *param_1;
  *(uint *)(iRam00000000 + (param_1[1] >> 0x16 & 0x3fc) + 0xcc8) = param_1[1];
  *(uint *)(iRam00000000 + (param_1[2] >> 0x16 & 0x3fc) + 0xcc8) = param_1[2];
  *(uint *)(iRam00000000 + (*param_2 >> 0x16 & 0x3fc) + 0xcc8) = *param_2;
  *(uint *)(iRam00000000 + (param_2[1] >> 0x16 & 0x3fc) + 0xcc8) = param_2[1];
  _DAT_cc008000 = param_1[3];
  *(uint *)(iRam00000000 + (param_1[3] >> 0x16 & 0x3fc) + 0xcc8) = param_1[3];
  if ((*(byte *)((int)param_1 + 0x1f) & 2) == 0) {
    if (*(int *)(iRam00000000 + 0x414) == 0) {
      OSPanic(...data.0,0x438,@182,@183);
    }
    iVar1 = (**(code **)(iRam00000000 + 0x414))(param_1[6]);
    if (iVar1 == 0) {
      OSPanic(...data.0,0x43a,@184,@183);
    }
    *(uint *)(iVar1 + 4) =
         *(uint *)(iVar1 + 4) & 0xffffff | (uint)*(byte *)((int)&GXTexTlutIds + param_3) << 0x18;
    _DAT_cc008000 = *(uint *)(iVar1 + 4);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iVar1 + 4) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iVar1 + 4);
  }
  *(uint *)(iRam00000000 + param_3 * 4 + 0x45c) = param_1[2];
  *(uint *)(iRam00000000 + param_3 * 4 + 0x47c) = *param_1;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 1;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXLoadTexObj(undefined4 param_1,int param_2)
{
  int iVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x457,@186);
  }
  if (7 < param_2) {
    OSPanic(...data.0,0x458,@180,@181);
  }
  if (*(int *)(iRam00000000 + 0x410) == 0) {
    OSPanic(...data.0,0x45d,@182,@181);
  }
  iVar1 = (**(code **)(iRam00000000 + 0x410))(param_1,param_2);
  if (iVar1 == 0) {
    OSPanic(...data.0,0x45f,@184,@181);
  }
  GXLoadTexObjPreLoaded(param_1,iVar1,param_2);
  return;
}

void GXInitTlutObj(uint *param_1,uint param_2,uint param_3,ushort param_4)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x477,@188);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x478,@189);
  }
  if (0x4000 < param_4) {
    OSPanic(...data.0,0x47b,@190,@191);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x47d,@102,@191,&@192);
  }
  *param_1 = 0;
  if ((param_3 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x480,@100);
  }
  *param_1 = *param_1 & 0xfffff3ff | param_3 << 10;
  if ((param_2 >> 5 & 0x1e00000) != 0) {
    OSPanic(...data.0,0x481,@100);
  }
  param_1[1] = param_1[1] & 0xffe00000 | param_2 >> 5 & 0x1ffffff;
  param_1[1] = param_1[1] & 0xffffff | 0x64000000;
  *(ushort *)(param_1 + 2) = param_4;
  return;
}

void GXGetTlutObjAll(uint *param_1,int *param_2,uint *param_3,undefined2 *param_4)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x497,@188);
  }
  *param_2 = (param_1[1] & 0x1fffff) << 5;
  *param_3 = *param_1 >> 10 & 3;
  *param_4 = *(undefined2 *)(param_1 + 2);
  return;
}

int GXGetTlutObjData(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x4a0,@188);
  }
  return (*(uint *)(param_1 + 4) & 0x1fffff) << 5;
}

uint GXGetTlutObjFmt(uint *param_1)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x4a7,@188);
  }
  return *param_1 >> 10 & 3;
}

undefined2 GXGetTlutObjNumEntries(int param_1)
{
  if (param_1 == 0) {
    OSPanic(...data.0,0x4ae,@188);
  }
  return *(undefined2 *)(param_1 + 8);
}

/* WARNING: Removing unreachable block (ram,0x000121b8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXLoadTlut(uint *param_1,undefined4 param_2)
{
  uint uVar1;
  uint *puVar2;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x4c9,@188);
  }
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x4cb,@198);
  }
  if (*(int *)(iRam00000000 + 0x414) == 0) {
    OSPanic(...data.0,0x4cc,@182,@199);
  }
  puVar2 = (uint *)(**(code **)(iRam00000000 + 0x414))(param_2);
  if (puVar2 == (uint *)0x0) {
    OSPanic(...data.0,0x4ce,@184,@199);
  }
  __GXFlushTextureState();
  *(uint *)(iRam00000000 + (param_1[1] >> 0x16 & 0x3fc) + 0xcc8) = param_1[1];
  _DAT_cc008000 = *puVar2;
  *(uint *)(iRam00000000 + (*puVar2 >> 0x16 & 0x3fc) + 0xcc8) = *puVar2;
  __GXFlushTextureState();
  *param_1 = *param_1 & 0xfffffc00 | *puVar2 & 0x3ff;
  uVar1 = param_1[1];
  puVar2[1] = *param_1;
  puVar2[2] = uVar1;
  puVar2[3] = param_1[2];
  return;
}

void GXInitTexCacheRegion
               (uint *param_1,undefined param_2,uint param_3,int param_4,uint param_5,int param_6)
{
  uint unaff_r29;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x4fd,@178);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x4ff,@212);
  }
  if ((param_3 & 0x1f) != 0) {
    OSPanic(...data.0,0x501,@102,@213,@214);
  }
  if ((param_5 & 0x1f) != 0) {
    OSPanic(...data.0,0x503,@102,@213,@215);
  }
  if (param_4 == 1) {
    unaff_r29 = 4;
  }
  else if (param_4 < 1) {
    if (param_4 < 0) {
LAB_00012300:
      OSPanic(...data.0,0x50b,@216,@213,@214);
    }
    else {
      unaff_r29 = 3;
    }
  }
  else {
    if (2 < param_4) goto LAB_00012300;
    unaff_r29 = 5;
  }
  *param_1 = 0;
  if ((param_3 >> 5 & 0x7ff8000) != 0) {
    OSPanic(...data.0,0x510,@100);
  }
  *param_1 = *param_1 & 0xffff8000 | param_3 >> 5;
  if ((unaff_r29 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x511,@100);
  }
  *param_1 = *param_1 & 0xfffc7fff | unaff_r29 << 0xf;
  if ((unaff_r29 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x512,@100);
  }
  *param_1 = *param_1 & 0xffe3ffff | unaff_r29 << 0x12;
  *param_1 = *param_1 & 0xffdfffff;
  if (param_6 == 2) {
    unaff_r29 = 5;
    goto LAB_00012428;
  }
  if (param_6 < 2) {
    if (param_6 == 0) {
      unaff_r29 = 3;
      goto LAB_00012428;
    }
    if (-1 < param_6) {
      unaff_r29 = 4;
      goto LAB_00012428;
    }
  }
  else if (param_6 < 4) {
    unaff_r29 = 0;
    goto LAB_00012428;
  }
  OSPanic(...data.0,0x51b,@216,@213,@215);
LAB_00012428:
  param_1[1] = 0;
  if ((param_5 >> 5 & 0x7ff8000) != 0) {
    OSPanic(...data.0,0x520,@100);
  }
  param_1[1] = param_1[1] & 0xffff8000 | param_5 >> 5;
  if ((unaff_r29 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x521,@100);
  }
  param_1[1] = param_1[1] & 0xfffc7fff | unaff_r29 << 0xf;
  if ((unaff_r29 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x522,@100);
  }
  param_1[1] = param_1[1] & 0xffe3ffff | unaff_r29 << 0x12;
  *(undefined *)(param_1 + 3) = param_2;
  *(undefined *)((int)param_1 + 0xd) = 1;
  return;
}

void GXInitTexPreLoadRegion(uint *param_1,uint param_2,uint param_3,uint param_4,uint param_5)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x53f,@178);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x541,@218);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x543,@102,@219,@214);
  }
  if ((param_4 & 0x1f) != 0) {
    OSPanic(...data.0,0x545,@102,@219,@215);
  }
  if ((param_3 & 0x1f) != 0) {
    OSPanic(...data.0,0x547,@102,@219,@220);
  }
  if ((param_5 & 0x1f) != 0) {
    OSPanic(...data.0,0x549,@102,@219,@221);
  }
  *param_1 = 0;
  if ((param_2 >> 5 & 0x7ff8000) != 0) {
    OSPanic(...data.0,0x54d,@100);
  }
  *param_1 = *param_1 & 0xffff8000 | param_2 >> 5;
  *param_1 = *param_1 & 0xfffc7fff;
  *param_1 = *param_1 & 0xffe3ffff;
  *param_1 = *param_1 & 0xffdfffff | 0x200000;
  param_1[1] = 0;
  if ((param_4 >> 5 & 0x7ff8000) != 0) {
    OSPanic(...data.0,0x553,@100);
  }
  param_1[1] = param_1[1] & 0xffff8000 | param_4 >> 5;
  param_1[1] = param_1[1] & 0xfffc7fff;
  param_1[1] = param_1[1] & 0xffe3ffff;
  *(undefined *)(param_1 + 3) = 0;
  *(undefined *)((int)param_1 + 0xd) = 0;
  *(short *)(param_1 + 2) = (short)(param_3 >> 5);
  *(short *)((int)param_1 + 10) = (short)(param_5 >> 5);
  return;
}

void GXGetTexRegionAll(uint *param_1,undefined *param_2,undefined *param_3,int *param_4,int *param_5
                      ,int *param_6,int *param_7)
{
  uint uVar1;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x572,@178);
  }
  *param_4 = (*param_1 & 0x7fff) << 5;
  *param_6 = (param_1[1] & 0x7fff) << 5;
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    *param_5 = (uint)*(ushort *)(param_1 + 2) << 5;
    *param_7 = (uint)*(ushort *)((int)param_1 + 10) << 5;
    goto LAB_00012818;
  }
  uVar1 = *param_1 >> 0xf & 7;
  if (uVar1 == 4) {
    *param_5 = 0x20000;
  }
  else if (uVar1 < 4) {
    if (uVar1 < 3) {
LAB_00012798:
      *param_5 = 0;
    }
    else {
      *param_5 = 0x8000;
    }
  }
  else {
    if (5 < uVar1) goto LAB_00012798;
    *param_5 = 0x80000;
  }
  uVar1 = param_1[1] >> 0xf & 7;
  if (uVar1 == 4) {
    *param_7 = 0x20000;
  }
  else {
    if (uVar1 < 4) {
      if (2 < uVar1) {
        *param_7 = 0x8000;
        goto LAB_00012818;
      }
    }
    else if (uVar1 < 6) {
      *param_7 = 0x80000;
      goto LAB_00012818;
    }
    *param_7 = 0;
  }
LAB_00012818:
  *param_3 = *(undefined *)(param_1 + 3);
  *param_2 = *(undefined *)((int)param_1 + 0xd);
  return;
}

void GXInitTlutRegion(uint *param_1,uint param_2,uint param_3)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x5a5,@237);
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x5a7,@238);
  }
  if ((param_2 & 0x1ff) != 0) {
    OSPanic(...data.0,0x5a8,@239,@240);
  }
  if (0x400 < (int)param_3) {
    OSPanic(...data.0,0x5a9,@241,@240);
  }
  *param_1 = 0;
  if ((param_2 - 0x80000 >> 9 & 0x7ffc00) != 0) {
    OSPanic(...data.0,0x5ad,@100);
  }
  *param_1 = *param_1 & 0xfffffc00 | param_2 - 0x80000 >> 9;
  if ((param_3 & 0xfffff800) != 0) {
    OSPanic(...data.0,0x5ae,@100);
  }
  *param_1 = *param_1 & 0xffe003ff | param_3 << 10;
  *param_1 = *param_1 & 0xffffff | 0x65000000;
  return;
}

void GXGetTlutRegionAll(uint *param_1,int *param_2,uint *param_3)
{
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x5c3,@237);
  }
  *param_2 = (*param_1 & 0x3ff) * 0x200 + 0x80000;
  *param_3 = *param_1 >> 10 & 0x7ff;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00012ae0) */
/* WARNING: Removing unreachable block (ram,0x00012b68) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXInvalidateTexRegion(uint *param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint unaff_r28;
  
  if (param_1 == (uint *)0x0) {
    OSPanic(...data.0,0x5da,@178);
  }
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x5dc,@260);
  }
  iVar5 = (*param_1 >> 0xf & 7) - 1;
  iVar4 = (*param_1 >> 0x12 & 7) - 1;
  iVar6 = (param_1[1] >> 0xf & 7) - 1;
  iVar3 = (param_1[1] >> 0x12 & 7) - 1;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  uVar7 = iVar5 + iVar4;
  if (*(char *)(param_1 + 3) != '\0') {
    uVar7 = iVar6 + iVar3 + -2 + uVar7;
  }
  uVar1 = *param_1;
  if ((uVar7 & 0xfffffff0) != 0) {
    OSPanic(...data.0,0x5ee,@100);
  }
  uVar7 = uVar1 >> 6 & 0x1ff | (uVar7 & 0x7fff) << 9 | 0x66000000;
  if (iVar6 != 0) {
    uVar1 = iVar6 + iVar3;
    if (*(char *)(param_1 + 3) != '\0') {
      uVar1 = iVar5 + iVar4 + -2 + uVar1;
    }
    uVar2 = param_1[1];
    if ((uVar1 & 0xfffffff0) != 0) {
      OSPanic(...data.0,0x5fa,@100);
    }
    unaff_r28 = uVar2 >> 6 & 0x1ff | (uVar1 & 0x7fff) << 9 | 0x66000000;
  }
  __GXFlushTextureState();
  _DAT_cc008000 = uVar7;
  *(uint *)(iRam00000000 + 0xe60) = uVar7;
  if (iVar6 != 0) {
    _DAT_cc008000 = unaff_r28;
    *(uint *)(iRam00000000 + (unaff_r28 >> 0x16 & 0x3fc) + 0xcc8) = unaff_r28;
  }
  __GXFlushTextureState();
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXInvalidateTexAll(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x60c,@262);
  }
  __GXFlushTextureState();
  *(undefined4 *)(iRam00000000 + 0xe60) = 0x66001000;
  _DAT_cc008000 = 0x66001100;
  *(undefined4 *)(iRam00000000 + 0xe60) = 0x66001100;
  __GXFlushTextureState();
  return;
}

undefined4 GXSetTexRegionCallback(undefined4 param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(iRam00000000 + 0x410);
  *(undefined4 *)(iRam00000000 + 0x410) = param_1;
  return uVar1;
}

/* WARNING: Removing unreachable block (ram,0x00012e34) */
/* WARNING: Removing unreachable block (ram,0x00012dfc) */
/* WARNING: Removing unreachable block (ram,0x00012e6c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXPreLoadEntireTexture(int param_1,uint *param_2)
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined auStack_60 [4];
  int local_5c;
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  char local_44;
  char local_43;
  
  if (param_1 == 0) {
    OSPanic(...data.0,0x64d,@97);
  }
  if (param_2 == (uint *)0x0) {
    OSPanic(...data.0,0x64d,@178);
  }
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x64f,@305);
  }
  local_43 = (*(byte *)(param_1 + 0x1f) & 1) == 1;
  local_44 = (*(uint *)(param_1 + 8) >> 0x14 & 0xf) == 6;
  uVar7 = *(uint *)(param_1 + 0xc) & 0x1fffff;
  uVar12 = uVar7 | 0x60000000;
  uVar2 = *param_2;
  uVar11 = uVar2 & 0x7fff | 0x61000000;
  uVar3 = param_2[1];
  uVar10 = uVar3 & 0x7fff | 0x62000000;
  if ((*(ushort *)(param_1 + 0x1c) & 0x8000) != 0) {
    OSPanic(...data.0,0x669,@100);
  }
  uVar1 = *(ushort *)(param_1 + 0x1c);
  if ((*(byte *)(param_1 + 0x1e) & 0xfc) != 0) {
    OSPanic(...data.0,0x66a,@100);
  }
  uVar14 = uVar1 & 0xfffe7fff | 0x63000000 | (uint)*(byte *)(param_1 + 0x1e) << 0xf;
  uVar5 = 0;
  uVar9 = (uint)*(ushort *)(param_1 + 0x1c);
  if (local_43 == '\0') {
    uVar6 = uVar9;
    uVar8 = uVar9;
    if (uVar9 == 0) {
      uVar6 = 1;
      uVar8 = 1;
    }
  }
  else {
    local_48 = (*(uint *)(param_1 + 8) & 0x3ff) + 1;
    local_4c = (*(uint *)(param_1 + 8) >> 10 & 0x3ff) + 1;
    uVar5 = local_4c;
    if (local_4c < local_48) {
      uVar5 = local_48;
    }
    uVar5 = 0x1fU - LZCOUNT(uVar5) & 0xffff;
    uVar8 = 0;
    uVar6 = 0;
    uVar4 = uVar9;
    for (uVar13 = 0; uVar13 < uVar5; uVar13 = uVar13 + 1) {
      if ((uVar13 & 1) == 0) {
        if (uVar4 == 0) {
          uVar4 = 1;
        }
        uVar8 = uVar8 + uVar4;
      }
      else {
        if (uVar4 == 0) {
          uVar4 = 1;
        }
        uVar6 = uVar6 + uVar4;
      }
      __GetImageTileCount(*(undefined4 *)(param_1 + 0x14),local_48 >> (uVar13 + 1 & 0x3f) & 0xffff,
                          local_4c >> (uVar13 + 1 & 0x3f) & 0xffff,&local_58,&local_5c,auStack_60);
      uVar4 = local_58 * local_5c;
    }
  }
  if (local_44 == '\0') {
    if (local_43 == '\0') {
      if (*(ushort *)((int)param_2 + 10) < *(ushort *)(param_2 + 2)) {
        if (*(ushort *)(param_2 + 2) < uVar8) {
          OSPanic(...data.0,0x6a3,@306);
        }
      }
      else if (*(ushort *)((int)param_2 + 10) < uVar6) {
        OSPanic(...data.0,0x6a5,@307);
      }
    }
    else if (*(ushort *)((int)param_2 + 10) < *(ushort *)(param_2 + 2)) {
      if (*(ushort *)(param_2 + 2) < uVar8) {
        OSPanic(...data.0,0x699,@306);
      }
      if (*(ushort *)((int)param_2 + 10) < uVar6) {
        OSPanic(...data.0,0x69a,@307);
      }
    }
    else {
      if (*(ushort *)((int)param_2 + 10) < uVar8) {
        OSPanic(...data.0,0x69d,@307);
      }
      if (*(ushort *)(param_2 + 2) < uVar6) {
        OSPanic(...data.0,0x69e,@306);
      }
    }
  }
  else {
    if (local_43 == '\0') {
      uVar6 = 0;
    }
    if ((uint)*(ushort *)(param_2 + 2) < uVar8 + uVar6) {
      OSPanic(...data.0,0x693,@306);
    }
    if ((uint)*(ushort *)((int)param_2 + 10) < uVar8 + uVar6) {
      OSPanic(...data.0,0x694,@307);
    }
  }
  __GXFlushTextureState();
  *(uint *)(iRam00000000 + 0xe48) = uVar12;
  *(uint *)(iRam00000000 + 0xe4c) = uVar11;
  *(uint *)(iRam00000000 + 0xe50) = uVar10;
  _DAT_cc008000 = uVar14;
  *(uint *)(iRam00000000 + 0xe54) = uVar14;
  if (uVar5 != 0) {
    local_54 = uVar3 & 0x7fff;
    local_50 = uVar2 & 0x7fff;
    for (uVar6 = 0; uVar6 < uVar5; uVar6 = uVar6 + 1) {
      if (local_44 == '\0') {
        uVar7 = uVar7 + uVar9;
        if ((uVar6 & 1) == 0) {
          local_50 = local_50 + uVar9;
        }
        else {
          local_54 = local_54 + uVar9;
        }
      }
      else {
        uVar7 = uVar7 + uVar9 * 2;
        local_50 = local_50 + uVar9;
        local_54 = local_54 + uVar9;
      }
      uVar2 = local_54;
      if ((uVar6 & 1) != 0) {
        uVar2 = local_50;
      }
      uVar3 = local_50;
      if ((uVar6 & 1) != 0) {
        uVar3 = local_54;
      }
      __GetImageTileCount(*(undefined4 *)(param_1 + 0x14),local_48 >> (uVar6 + 1 & 0x3f) & 0xffff,
                          local_4c >> (uVar6 + 1 & 0x3f) & 0xffff,&local_58,&local_5c,auStack_60);
      uVar9 = local_58 * local_5c;
      if ((uVar7 & 0xffe00000) != 0) {
        OSPanic(...data.0,0x6d6,@100);
      }
      uVar12 = uVar12 & 0xffe00000 | uVar7;
      if ((uVar2 & 0xffff8000) != 0) {
        OSPanic(...data.0,0x6d7,@100);
      }
      uVar11 = uVar11 & 0xffff8000 | uVar2;
      if ((uVar3 & 0xffff8000) != 0) {
        OSPanic(...data.0,0x6d8,@100);
      }
      uVar10 = uVar10 & 0xffff8000 | uVar3;
      if ((uVar9 & 0xffff8000) != 0) {
        OSPanic(...data.0,0x6d9,@100);
      }
      uVar14 = uVar14 & 0xffff8000 | uVar9;
      *(uint *)(iRam00000000 + (uVar12 >> 0x16 & 0x3fc) + 0xcc8) = uVar12;
      *(uint *)(iRam00000000 + (uVar11 >> 0x16 & 0x3fc) + 0xcc8) = uVar11;
      *(uint *)(iRam00000000 + (uVar10 >> 0x16 & 0x3fc) + 0xcc8) = uVar10;
      _DAT_cc008000 = uVar14;
      *(uint *)(iRam00000000 + (uVar14 >> 0x16 & 0x3fc) + 0xcc8) = uVar14;
    }
  }
  __GXFlushTextureState();
  return;
}

/* WARNING: Removing unreachable block (ram,0x000134b8) */
/* WARNING: Removing unreachable block (ram,0x00013508) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTexCoordScaleManually(uint param_1,byte param_2,int param_3,int param_4)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x6f6,@311);
  }
  if (7 < (int)param_1) {
    OSPanic(...data.0,0x6f8,@312,@313);
  }
  *(uint *)(iRam00000000 + 0x4dc) =
       *(uint *)(iRam00000000 + 0x4dc) & ~(1 << (param_1 & 0x3f)) |
       (uint)param_2 << (param_1 & 0x3f);
  if (param_2 != 0) {
    *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) =
         *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) & 0xffff0000 | param_3 - 1U & 0xffff;
    *(uint *)(iRam00000000 + param_1 * 4 + 0xd8) =
         *(uint *)(iRam00000000 + param_1 * 4 + 0xd8) & 0xffff0000 | param_4 - 1U & 0xffff;
    *(undefined4 *)
     (iRam00000000 + (*(uint *)(iRam00000000 + param_1 * 4 + 0xb8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xb8);
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xd8);
    *(undefined4 *)
     (iRam00000000 + (*(uint *)(iRam00000000 + param_1 * 4 + 0xd8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xd8);
    *(undefined2 *)(iRam00000000 + 2) = 0;
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTexCoordCylWrap(uint param_1,uint param_2,uint param_3)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x718,@317);
  }
  if (7 < (int)param_1) {
    OSPanic(...data.0,0x71a,@312,@318);
  }
  if ((param_2 & 0xfe) != 0) {
    OSPanic(...data.0,0x71c,@100);
  }
  *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) =
       *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) & 0xfffdffff | (param_2 & 0xff) << 0x11;
  if ((param_3 & 0xfe) != 0) {
    OSPanic(...data.0,0x71d,@100);
  }
  *(uint *)(iRam00000000 + param_1 * 4 + 0xd8) =
       *(uint *)(iRam00000000 + param_1 * 4 + 0xd8) & 0xfffdffff | (param_3 & 0xff) << 0x11;
  if ((*(uint *)(iRam00000000 + 0x4dc) & 1 << (param_1 & 0x3f)) != 0) {
    *(undefined4 *)
     (iRam00000000 + (*(uint *)(iRam00000000 + param_1 * 4 + 0xb8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xb8);
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xd8);
    *(undefined4 *)
     (iRam00000000 + (*(uint *)(iRam00000000 + param_1 * 4 + 0xd8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xd8);
    *(undefined2 *)(iRam00000000 + 2) = 0;
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTexCoordBias(uint param_1,uint param_2,uint param_3)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x737,@322);
  }
  if (7 < (int)param_1) {
    OSPanic(...data.0,0x739,@312,@323);
  }
  if ((param_2 & 0xfe) != 0) {
    OSPanic(...data.0,0x73b,@100);
  }
  *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) =
       *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) & 0xfffeffff | (param_2 & 0xff) << 0x10;
  if ((param_3 & 0xfe) != 0) {
    OSPanic(...data.0,0x73c,@100);
  }
  *(uint *)(iRam00000000 + param_1 * 4 + 0xd8) =
       *(uint *)(iRam00000000 + param_1 * 4 + 0xd8) & 0xfffeffff | (param_3 & 0xff) << 0x10;
  if ((*(uint *)(iRam00000000 + 0x4dc) & 1 << (param_1 & 0x3f)) != 0) {
    *(undefined4 *)
     (iRam00000000 + (*(uint *)(iRam00000000 + param_1 * 4 + 0xb8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xb8);
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xd8);
    *(undefined4 *)
     (iRam00000000 + (*(uint *)(iRam00000000 + param_1 * 4 + 0xd8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xd8);
    *(undefined2 *)(iRam00000000 + 2) = 0;
  }
  return;
}

/* WARNING: Removing unreachable block (ram,0x00013a08) */
/* WARNING: Removing unreachable block (ram,0x00013a4c) */
/* WARNING: Removing unreachable block (ram,0x00013ad8) */
/* WARNING: Removing unreachable block (ram,0x00013b20) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __SetSURegs(int param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = *(uint *)(iRam00000000 + param_1 * 4 + 0x45c);
  *(uint *)(iRam00000000 + param_2 * 4 + 0xb8) =
       *(uint *)(iRam00000000 + param_2 * 4 + 0xb8) & 0xffff0000 |
       *(uint *)(iRam00000000 + param_1 * 4 + 0x45c) & 0x3ff;
  *(uint *)(iRam00000000 + param_2 * 4 + 0xd8) =
       *(uint *)(iRam00000000 + param_2 * 4 + 0xd8) & 0xffff0000 | uVar1 >> 10 & 0x3ff;
  uVar1 = *(uint *)(iRam00000000 + param_1 * 4 + 0x47c);
  *(uint *)(iRam00000000 + param_2 * 4 + 0xb8) =
       *(uint *)(iRam00000000 + param_2 * 4 + 0xb8) & 0xfffeffff |
       (uint)((*(uint *)(iRam00000000 + param_1 * 4 + 0x47c) & 3) == 1) << 0x10;
  *(uint *)(iRam00000000 + param_2 * 4 + 0xd8) =
       *(uint *)(iRam00000000 + param_2 * 4 + 0xd8) & 0xfffeffff |
       (uint)((uVar1 >> 2 & 3) == 1) << 0x10;
  *(undefined4 *)
   (iRam00000000 + (*(uint *)(iRam00000000 + param_2 * 4 + 0xb8) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + param_2 * 4 + 0xb8);
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + param_2 * 4 + 0xd8);
  *(undefined4 *)
   (iRam00000000 + (*(uint *)(iRam00000000 + param_2 * 4 + 0xd8) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + param_2 * 4 + 0xd8);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void __GXSetSUTexRegs(void)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint unaff_r29;
  uint unaff_r30;
  uint uVar5;
  
  if (*(int *)(iRam00000000 + 0x4dc) != 0xff) {
    uVar2 = *(uint *)(iRam00000000 + 0x204);
    uVar3 = *(uint *)(iRam00000000 + 0x204);
    for (uVar5 = 0; uVar5 < (uVar3 >> 0x10 & 7); uVar5 = uVar5 + 1) {
      if (uVar5 == 2) {
        unaff_r29 = *(uint *)(iRam00000000 + 0x120) >> 0xc & 7;
        unaff_r30 = *(uint *)(iRam00000000 + 0x120) >> 0xf & 7;
      }
      else if ((int)uVar5 < 2) {
        if (uVar5 == 0) {
          unaff_r29 = *(uint *)(iRam00000000 + 0x120) & 7;
          unaff_r30 = *(uint *)(iRam00000000 + 0x120) >> 3 & 7;
        }
        else if (-1 < (int)uVar5) {
          unaff_r29 = *(uint *)(iRam00000000 + 0x120) >> 6 & 7;
          unaff_r30 = *(uint *)(iRam00000000 + 0x120) >> 9 & 7;
        }
      }
      else if ((int)uVar5 < 4) {
        unaff_r29 = *(uint *)(iRam00000000 + 0x120) >> 0x12 & 7;
        unaff_r30 = *(uint *)(iRam00000000 + 0x120) >> 0x15 & 7;
      }
      if ((*(uint *)(iRam00000000 + 0x4dc) & 1 << (unaff_r30 & 0x3f)) == 0) {
        __SetSURegs(unaff_r29,unaff_r30);
      }
    }
    for (uVar3 = 0; uVar3 < (uVar2 >> 10 & 0xf) + 1; uVar3 = uVar3 + 1) {
      puVar4 = (uint *)(iRam00000000 + (uVar3 & 0x7ffffffe) * 2 + 0x100);
      uVar5 = *(uint *)(iRam00000000 + uVar3 * 4 + 0x49c) & 0xfffffeff;
      if ((uVar3 & 1) == 0) {
        uVar1 = *puVar4 >> 3;
      }
      else {
        uVar1 = *puVar4 >> 0xf;
      }
      if (((uVar5 != 0xff) && ((*(uint *)(iRam00000000 + 0x4dc) & 1 << (uVar1 & 7)) == 0)) &&
         ((*(uint *)(iRam00000000 + 0x4e0) & 1 << (uVar3 & 0x3f)) != 0)) {
        __SetSURegs(uVar5,uVar1 & 7);
      }
    }
  }
  return;
}

void __GXGetSUTexSize(int param_1,short *param_2,short *param_3)
{
  *param_2 = (short)*(undefined4 *)(iRam00000000 + param_1 * 4 + 0xb8) + 1;
  *param_3 = (short)*(undefined4 *)(iRam00000000 + param_1 * 4 + 0xd8) + 1;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXSetTmemConfig(int param_1)
{
  if (param_1 != 1) {
    *(undefined4 *)(iRam00000000 + 0xef8) = 0x8c0d8000;
    *(undefined4 *)(iRam00000000 + 0xf08) = 0x900dc000;
    *(undefined4 *)(iRam00000000 + 0xefc) = 0x8d0d8400;
    *(undefined4 *)(iRam00000000 + 0xf0c) = 0x910dc400;
    *(undefined4 *)(iRam00000000 + 0xf00) = 0x8e0d8800;
    *(undefined4 *)(iRam00000000 + 0xf10) = 0x920dc800;
    *(undefined4 *)(iRam00000000 + 0xf04) = 0x8f0d8c00;
    *(undefined4 *)(iRam00000000 + 0xf14) = 0x930dcc00;
    *(undefined4 *)(iRam00000000 + 0xf78) = 0xac0d9000;
    *(undefined4 *)(iRam00000000 + 0xf88) = 0xb00dd000;
    *(undefined4 *)(iRam00000000 + 0xf7c) = 0xad0d9400;
    *(undefined4 *)(iRam00000000 + 0xf8c) = 0xb10dd400;
    *(undefined4 *)(iRam00000000 + 0xf80) = 0xae0d9800;
    *(undefined4 *)(iRam00000000 + 0xf90) = 0xb20dd800;
    *(undefined4 *)(iRam00000000 + 0xf84) = 0xaf0d9c00;
    _DAT_cc008000 = 0xb30ddc00;
    *(undefined4 *)(iRam00000000 + 0xf94) = 0xb30ddc00;
    return;
  }
  *(undefined4 *)(iRam00000000 + 0xef8) = 0x8c0d8000;
  *(undefined4 *)(iRam00000000 + 0xf08) = 0x900dc000;
  *(undefined4 *)(iRam00000000 + 0xefc) = 0x8d0d8800;
  *(undefined4 *)(iRam00000000 + 0xf0c) = 0x910dc800;
  *(undefined4 *)(iRam00000000 + 0xf00) = 0x8e0d9000;
  *(undefined4 *)(iRam00000000 + 0xf10) = 0x920dd000;
  *(undefined4 *)(iRam00000000 + 0xf04) = 0x8f0d9800;
  *(undefined4 *)(iRam00000000 + 0xf14) = 0x930dd800;
  *(undefined4 *)(iRam00000000 + 0xf78) = 0xac0da000;
  *(undefined4 *)(iRam00000000 + 0xf88) = 0xb00de000;
  *(undefined4 *)(iRam00000000 + 0xf7c) = 0xad0da800;
  *(undefined4 *)(iRam00000000 + 0xf8c) = 0xb10de800;
  *(undefined4 *)(iRam00000000 + 0xf80) = 0xae0db000;
  *(undefined4 *)(iRam00000000 + 0xf90) = 0xb20df000;
  *(undefined4 *)(iRam00000000 + 0xf84) = 0xaf0db800;
  _DAT_cc008000 = 0xb30df800;
  *(undefined4 *)(iRam00000000 + 0xf94) = 0xb30df800;
  return;
}
