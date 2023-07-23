void __GXSetDirtyState(void)
{
  if ((*(uint *)(iRam00000000 + 0x4f4) & 1) != 0) {
    __GXSetSUTexRegs();
  }
  if ((*(uint *)(iRam00000000 + 0x4f4) & 2) != 0) {
    __GXUpdateBPMask();
  }
  if ((*(uint *)(iRam00000000 + 0x4f4) & 4) != 0) {
    __GXSetGenMode();
  }
  if ((*(uint *)(iRam00000000 + 0x4f4) & 8) != 0) {
    __GXSetVCD();
  }
  if ((*(uint *)(iRam00000000 + 0x4f4) & 0x10) != 0) {
    __GXSetVAT();
  }
  *(undefined4 *)(iRam00000000 + 0x4f4) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXBegin(undefined4 param_1,int param_2,undefined2 param_3)
{
  if (7 < param_2) {
    OSPanic(...data.0,0x15a,@25);
  }
  if (piRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x15b,@26);
  }
  if (*(int *)((int)piRam00000000 + 0x4f4) != 0) {
    __GXSetDirtyState();
  }
  if (*(char *)((int)piRam00000000 + 0x4f0) == '\0') {
    __GXVerifyState(param_2);
  }
  piRam00000000 = (int *)CONCAT13(1,piRam00000000._1_3_);
  if (*piRam00000000 == 0) {
    __GXSendFlushPrim();
  }
  _DAT_cc008000 = param_3;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXSendFlushPrim(void)
{
  uint uVar1;
  
  _DAT_cc008000 = CONCAT22(*(undefined2 *)(iRam00000000 + 4),DAT_cc008000_2);
  for (uVar1 = 0; uVar1 < (uint)*(ushort *)(iRam00000000 + 4) * (uint)*(ushort *)(iRam00000000 + 6);
      uVar1 = uVar1 + 4) {
    _DAT_cc008000 = 0;
  }
  *(undefined2 *)(iRam00000000 + 2) = 1;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010220) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetLineWidth(uint param_1,uint param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1ab,@34);
  }
  *(uint *)(iRam00000000 + 0x7c) = *(uint *)(iRam00000000 + 0x7c) & 0xffffff00 | param_1 & 0xff;
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x1ad,@35);
  }
  *(uint *)(iRam00000000 + 0x7c) = *(uint *)(iRam00000000 + 0x7c) & 0xfff8ffff | param_2 << 0x10;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x7c);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x7c) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x7c);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXGetLineWidth(undefined *param_1,uint *param_2)
{
  if ((param_1 == (undefined *)0x0) || (param_2 == (uint *)0x0)) {
    OSPanic(...data.0,0x1c2,@37);
  }
  *param_1 = (char)*(undefined4 *)(iRam00000000 + 0x7c);
  *param_2 = *(uint *)(iRam00000000 + 0x7c) >> 0x10 & 7;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000103a0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetPointSize(uint param_1,uint param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1d7,@39);
  }
  *(uint *)(iRam00000000 + 0x7c) =
       (param_1 & 0xff) << 8 | *(uint *)(iRam00000000 + 0x7c) & 0xffff00ff;
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x1d9,@35);
  }
  *(uint *)(iRam00000000 + 0x7c) = *(uint *)(iRam00000000 + 0x7c) & 0xffc7ffff | param_2 << 0x13;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x7c);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x7c) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x7c);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXGetPointSize(undefined *param_1,uint *param_2)
{
  if ((param_1 == (undefined *)0x0) || (param_2 == (uint *)0x0)) {
    OSPanic(...data.0,0x1ee,@37);
  }
  *param_1 = (char)((uint)*(undefined4 *)(iRam00000000 + 0x7c) >> 8);
  *param_2 = *(uint *)(iRam00000000 + 0x7c) >> 0x13 & 7;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXEnableTexOffsets(int param_1,uint param_2,uint param_3)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x204,@42);
  }
  if (7 < param_1) {
    OSPanic(...data.0,0x206,@43);
  }
  if ((param_2 & 0xfe) != 0) {
    OSPanic(...data.0,0x208,@35);
  }
  *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) =
       *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) & 0xfffbffff | (param_2 & 0xff) << 0x12;
  if ((param_3 & 0xfe) != 0) {
    OSPanic(...data.0,0x209,@35);
  }
  *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) =
       *(uint *)(iRam00000000 + param_1 * 4 + 0xb8) & 0xfff7ffff | (param_3 & 0xff) << 0x13;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xb8);
  *(undefined4 *)
   (iRam00000000 + (*(uint *)(iRam00000000 + param_1 * 4 + 0xb8) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + param_1 * 4 + 0xb8);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXSetCullMode(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x220,@49);
  }
  if (param_1 == 2) {
    param_1 = 1;
  }
  else if (((int)param_1 < 2) && (0 < (int)param_1)) {
    param_1 = 2;
  }
  if ((param_1 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x228,@35);
  }
  *(uint *)(iRam00000000 + 0x204) = *(uint *)(iRam00000000 + 0x204) & 0xffff3fff | param_1 << 0xe;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 4;
  return;
}

void GXGetCullMode(uint *param_1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(iRam00000000 + 0x204) >> 0xe & 3;
  if (uVar1 == 2) {
    *param_1 = 1;
  }
  else if ((uVar1 < 2) && (uVar1 != 0)) {
    *param_1 = 2;
  }
  else {
    *param_1 = uVar1;
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetCoPlanar(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x24d,@56);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x24f,@35);
  }
  *(uint *)(iRam00000000 + 0x204) =
       *(uint *)(iRam00000000 + 0x204) & 0xfff7ffff | (param_1 & 0xff) << 0x13;
  *(undefined4 *)(iRam00000000 + 0x10c0) = 0xfe080000;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x204);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x204) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x204);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXSetGenMode(void)
{
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x204);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x204) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x204);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}
