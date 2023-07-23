void GetVertState(void)
{
  GXGetVtxDescv(vcd);
  GXGetVtxAttrFmtv(3,vat);
  GXClearVtxDesc();
  GXSetVtxDesc(9,1);
  GXSetVtxDesc(10,1);
  GXSetVtxAttrFmt(3,9,1,4,0);
  GXSetVtxAttrFmt(3,10,0,4,0);
  return;
}

void RestoreVertState(void)
{
  GXSetVtxDescv(vcd);
  GXSetVtxAttrFmtv(3,vat);
  return;
}

void vsub(int param_1,int param_2,int param_3)
{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < 3; uVar1 = uVar1 + 1) {
    *(float *)(param_3 + uVar1 * 4) =
         *(float *)(param_2 + uVar1 * 4) - *(float *)(param_1 + uVar1 * 4);
  }
  return;
}

void vcross(float *param_1,float *param_2,float *param_3)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = param_1[2];
  fVar2 = *param_2;
  fVar3 = *param_1;
  fVar4 = param_2[2];
  fVar5 = *param_1;
  fVar6 = param_2[1];
  fVar7 = param_1[1];
  fVar8 = *param_2;
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = fVar1 * fVar2 - fVar3 * fVar4;
  param_3[2] = fVar5 * fVar6 - fVar7 * fVar8;
  return;
}

void normalize(float *param_1)
{
  double dVar1;
  
  dVar1 = (double)sqrtf__Ff((double)(param_1[2] * param_1[2] +
                                    *param_1 * *param_1 + param_1[1] * param_1[1]));
  if ((double)@100 == dVar1) {
    OSPanic(...data.0,0x89,@102);
  }
  *param_1 = (float)((double)*param_1 / dVar1);
  param_1[1] = (float)((double)param_1[1] / dVar1);
  param_1[2] = (float)((double)param_1[2] / dVar1);
  return;
}

void myvertex(float *param_1,float *param_2)
{
  GXPosition3f32((double)*param_1,(double)param_1[1],(double)param_1[2]);
  GXNormal3f32((double)*param_2,(double)param_2[1],(double)param_2[2]);
  return;
}

void DumpTriangle(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  GXBegin(0x90,3,3);
  myvertex(param_1,param_1);
  myvertex(param_2,param_2);
  myvertex(param_3,param_3);
  GXEnd();
  return;
}

void Subdivide(uint param_1,int param_2,int param_3,int param_4)
{
  uint uVar1;
  float local_40 [11];
  
  if ((param_1 & 0xff) == 0) {
    DumpTriangle(param_2,param_3,param_4);
  }
  else {
    for (uVar1 = 0; uVar1 < 3; uVar1 = uVar1 + 1) {
      local_40[uVar1 + 6] = *(float *)(param_2 + uVar1 * 4) + *(float *)(param_3 + uVar1 * 4);
      local_40[uVar1 + 3] = *(float *)(param_3 + uVar1 * 4) + *(float *)(param_4 + uVar1 * 4);
      local_40[uVar1] = *(float *)(param_4 + uVar1 * 4) + *(float *)(param_2 + uVar1 * 4);
    }
    normalize(local_40 + 6);
    normalize(local_40 + 3);
    normalize(local_40);
    Subdivide(param_1 - 1,param_2,local_40 + 6,local_40);
    Subdivide(param_1 - 1,param_3,local_40 + 3,local_40 + 6);
    Subdivide(param_1 - 1,param_4,local_40,local_40 + 3);
    Subdivide(param_1 - 1,local_40 + 6,local_40 + 3,local_40);
  }
  return;
}

void SubDivTriangle(undefined param_1,uint param_2,int param_3,int param_4)
{
  Subdivide(param_1,param_3 + (uint)*(byte *)(param_4 + (param_2 & 0xff) * 3) * 0xc,
            param_3 + (uint)*(byte *)(param_4 + (param_2 & 0xff) * 3 + 1) * 0xc,
            param_3 + (uint)*(byte *)(param_4 + (param_2 & 0xff) * 3 + 2) * 0xc);
  return;
}

void GXDrawCylinder(void)
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  float local_354 [100];
  float local_1c4 [101];
  undefined4 local_30;
  uint uStack_2c;
  undefined4 local_28;
  uint uStack_24;
  
  bVar1 = _savefpr_29();
  dVar6 = (double)@143;
  dVar5 = -dVar6;
  if (99 < bVar1) {
    OSPanic(...data.0,0xd8,@144);
  }
  GetVertState();
  for (uVar2 = 0; (int)uVar2 <= (int)(uint)bVar1; uVar2 = uVar2 + 1) {
    uStack_24 = uVar2 ^ 0x80000000;
    local_28 = 0x43300000;
    uStack_2c = (uint)bVar1;
    local_30 = 0x43300000;
    fVar7 = (@145 * @146 * (float)((double)CONCAT44(0x43300000,uStack_24) - @149)) /
            (float)((double)CONCAT44(0x43300000,uStack_2c) - @151);
    dVar4 = (double)fVar7;
    fVar7 = cosf(fVar7);
    local_1c4[uVar2] = fVar7;
    fVar7 = sinf((float)dVar4);
    local_354[uVar2] = fVar7;
  }
  GXBegin(0x98,3,(bVar1 + 1) * 2);
  for (iVar3 = 0; iVar3 <= (int)(uint)bVar1; iVar3 = iVar3 + 1) {
    GXPosition3f32((double)local_1c4[iVar3],(double)local_354[iVar3],dVar5);
    GXNormal3f32((double)local_1c4[iVar3],(double)local_354[iVar3],(double)@100);
    GXPosition3f32((double)local_1c4[iVar3],(double)local_354[iVar3],dVar6);
    GXNormal3f32((double)local_1c4[iVar3],(double)local_354[iVar3],(double)@100);
  }
  GXEnd();
  GXBegin(0xa0,3,bVar1 + 2);
  GXPosition3f32((double)@100,(double)@100,dVar6);
  GXNormal3f32((double)@100,(double)@100,(double)@143);
  for (iVar3 = 0; iVar3 <= (int)(uint)bVar1; iVar3 = iVar3 + 1) {
    GXPosition3f32((double)local_1c4[iVar3],-(double)local_354[iVar3],dVar6);
    GXNormal3f32((double)@100,(double)@100,(double)@143);
  }
  GXEnd();
  GXBegin(0xa0,3,bVar1 + 2);
  GXPosition3f32((double)@100,(double)@100,dVar5);
  GXNormal3f32((double)@100,(double)@100,(double)@147);
  for (iVar3 = 0; iVar3 <= (int)(uint)bVar1; iVar3 = iVar3 + 1) {
    GXPosition3f32((double)local_1c4[iVar3],(double)local_354[iVar3],dVar5);
    GXNormal3f32((double)@100,(double)@100,(double)@147);
  }
  GXEnd();
  RestoreVertState();
  _restfpr_29();
  return;
}

void GXDrawTorus(void)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  double extraout_f1;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  undefined8 uVar13;
  float fVar14;
  int local_c8 [2];
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  uint uStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  
  uVar13 = _savefpr_23();
  uVar1 = (uint)((ulonglong)uVar13 >> 0x20);
  uVar2 = (uint)uVar13;
  dVar12 = (double)@172;
  dVar9 = extraout_f1;
  if ((double)@143 <= extraout_f1) {
    OSPanic(...data.0,0x13c,@173);
  }
  dVar6 = (double)(float)((double)@143 - dVar9);
  GXGetVtxDesc(0xd,local_c8);
  GetVertState();
  if (local_c8[0] != 0) {
    GXSetVtxDesc(0xd,1);
    GXSetVtxAttrFmt(3,0xd,1,4,0);
  }
  for (iVar5 = 0; iVar5 < (int)(uVar1 & 0xff); iVar5 = iVar5 + 1) {
    GXBegin(0x98,3,((uVar2 & 0xff) + 1) * 2);
    for (uVar4 = 0; (int)uVar4 <= (int)(uVar2 & 0xff); uVar4 = uVar4 + 1) {
      for (iVar3 = 1; -1 < iVar3; iVar3 = iVar3 + -1) {
        uStack_64 = (iVar5 + iVar3) - ((iVar5 + iVar3) / (int)(uVar1 & 0xff)) * (uVar1 & 0xff) ^
                    0x80000000;
        local_68 = 0x43300000;
        dVar11 = (double)(float)((double)CONCAT44(0x43300000,uStack_64) - @149);
        uStack_6c = uVar4 - ((int)uVar4 / (int)(uVar2 & 0xff)) * (uVar2 & 0xff) ^ 0x80000000;
        local_70 = 0x43300000;
        dVar10 = (double)(float)((double)CONCAT44(0x43300000,uStack_6c) - @149);
        uStack_74 = uVar2 & 0xff;
        local_78 = 0x43300000;
        fVar14 = cosf((float)(dVar10 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_74) - @151));
        dVar7 = (double)fVar14;
        uStack_7c = uVar1 & 0xff;
        local_80 = 0x43300000;
        fVar14 = cosf((float)(dVar11 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_7c) - @151));
        dVar8 = (double)(float)((double)(float)(dVar6 - (double)(float)(dVar9 * (double)fVar14)) *
                               dVar7);
        uStack_84 = uVar2 & 0xff;
        local_88 = 0x43300000;
        fVar14 = sinf((float)(dVar10 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_84) - @151));
        dVar7 = (double)fVar14;
        uStack_8c = uVar1 & 0xff;
        local_90 = 0x43300000;
        fVar14 = cosf((float)(dVar11 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_8c) - @151));
        dVar7 = (double)(float)((double)(float)(dVar6 - (double)(float)(dVar9 * (double)fVar14)) *
                               dVar7);
        uStack_94 = uVar1 & 0xff;
        local_98 = 0x43300000;
        fVar14 = sinf((float)(dVar11 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_94) - @151));
        GXPosition3f32(dVar8,dVar7,(double)(float)(dVar9 * (double)fVar14));
        uStack_9c = uVar1 & 0xff;
        local_a0 = 0x43300000;
        fVar14 = cosf((float)(dVar11 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_9c) - @151));
        dVar7 = (double)fVar14;
        uStack_a4 = uVar2 & 0xff;
        local_a8 = 0x43300000;
        fVar14 = cosf((float)(dVar10 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_a4) - @151));
        dVar8 = (double)(float)(-(double)fVar14 * dVar7);
        uStack_ac = uVar1 & 0xff;
        local_b0 = 0x43300000;
        fVar14 = cosf((float)(dVar11 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_ac) - @151));
        dVar7 = (double)fVar14;
        uStack_b4 = uVar2 & 0xff;
        local_b8 = 0x43300000;
        fVar14 = sinf((float)(dVar10 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_b4) - @151));
        dVar7 = (double)(float)(-(double)fVar14 * dVar7);
        uStack_bc = uVar1 & 0xff;
        local_c0 = 0x43300000;
        fVar14 = sinf((float)(dVar11 * dVar12) /
                      (float)((double)CONCAT44(0x43300000,uStack_bc) - @151));
        GXNormal3f32(dVar8,dVar7,(double)fVar14);
        if (local_c8[0] != 0) {
          uStack_bc = iVar5 + iVar3 ^ 0x80000000;
          local_c0 = 0x43300000;
          uStack_b4 = uVar1 & 0xff;
          local_b8 = 0x43300000;
          uStack_ac = uVar4 ^ 0x80000000;
          local_b0 = 0x43300000;
          uStack_a4 = uVar2 & 0xff;
          local_a8 = 0x43300000;
          GXTexCoord2f32((double)((float)((double)CONCAT44(0x43300000,uStack_bc) - @149) /
                                 (float)((double)CONCAT44(0x43300000,uStack_b4) - @151)),
                         (double)((float)((double)CONCAT44(0x43300000,uStack_ac) - @149) /
                                 (float)((double)CONCAT44(0x43300000,uStack_a4) - @151)));
        }
      }
    }
    GXEnd();
  }
  RestoreVertState();
  _restfpr_23();
  return;
}

void GXDrawSphere(void)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 uVar14;
  float fVar15;
  int local_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  
  uVar14 = _savefpr_20();
  uVar1 = (uint)((ulonglong)uVar14 >> 0x20);
  uVar2 = (uint)uVar14;
  dVar13 = (double)@143;
  uStack_74 = uVar1 & 0xff;
  local_78 = 0x43300000;
  dVar9 = (double)(@145 / (float)((double)CONCAT44(0x43300000,uStack_74) - @151));
  uStack_7c = uVar2 & 0xff;
  local_80 = 0x43300000;
  dVar6 = (double)(@172 / (float)((double)CONCAT44(0x43300000,uStack_7c) - @151));
  GXGetVtxDesc(0xd,&local_94);
  GetVertState();
  if (local_94 != 0) {
    GXSetVtxDesc(0xd,1);
    GXSetVtxAttrFmt(3,0xd,1,4,0);
  }
  for (uVar4 = 0; (int)uVar4 < (int)(uVar1 & 0xff); uVar4 = uVar4 + 1) {
    uStack_7c = uVar4 ^ 0x80000000;
    local_80 = 0x43300000;
    fVar15 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_7c) - @149) * dVar9);
    dVar10 = (double)fVar15;
    dVar8 = (double)(float)(dVar10 + dVar9);
    fVar15 = sinf(fVar15);
    dVar12 = (double)(float)(dVar13 * (double)fVar15);
    fVar15 = sinf((float)dVar8);
    dVar11 = (double)(float)(dVar13 * (double)fVar15);
    fVar15 = cosf((float)dVar10);
    dVar10 = (double)(float)(dVar13 * (double)fVar15);
    fVar15 = cosf((float)dVar8);
    dVar8 = (double)(float)(dVar13 * (double)fVar15);
    GXBegin((double)fVar15,0x98,3,((uVar2 & 0xff) + 1) * 2);
    for (uVar3 = 0; (int)uVar3 <= (int)(uVar2 & 0xff); uVar3 = uVar3 + 1) {
      uStack_7c = uVar3 ^ 0x80000000;
      local_80 = 0x43300000;
      fVar15 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_7c) - @149) * dVar6);
      dVar7 = (double)fVar15;
      fVar15 = cosf(fVar15);
      dVar5 = (double)fVar15;
      fVar15 = sinf((float)dVar7);
      dVar7 = (double)fVar15;
      GXPosition3f32((double)(float)(dVar5 * dVar11),(double)(float)(dVar7 * dVar11),dVar8);
      GXNormal3f32((double)(float)((double)(float)(dVar5 * dVar11) / dVar13),
                   (double)(float)((double)(float)(dVar7 * dVar11) / dVar13),
                   (double)(float)(dVar8 / dVar13));
      if (local_94 != 0) {
        uStack_7c = uVar3 ^ 0x80000000;
        local_80 = 0x43300000;
        uStack_74 = uVar2 & 0xff;
        local_78 = 0x43300000;
        uStack_84 = uVar4 + 1 ^ 0x80000000;
        local_88 = 0x43300000;
        uStack_8c = uVar1 & 0xff;
        local_90 = 0x43300000;
        GXTexCoord2f32((double)((float)((double)CONCAT44(0x43300000,uStack_7c) - @149) /
                               (float)((double)CONCAT44(0x43300000,uStack_74) - @151)),
                       (double)((float)((double)CONCAT44(0x43300000,uStack_84) - @149) /
                               (float)((double)CONCAT44(0x43300000,uStack_8c) - @151)));
      }
      GXPosition3f32((double)(float)(dVar5 * dVar12),(double)(float)(dVar7 * dVar12),dVar10);
      GXNormal3f32((double)(float)((double)(float)(dVar5 * dVar12) / dVar13),
                   (double)(float)((double)(float)(dVar7 * dVar12) / dVar13),
                   (double)(float)(dVar10 / dVar13));
      if (local_94 != 0) {
        uStack_8c = uVar3 ^ 0x80000000;
        local_90 = 0x43300000;
        uStack_84 = uVar2 & 0xff;
        local_88 = 0x43300000;
        uStack_7c = uVar4 ^ 0x80000000;
        local_80 = 0x43300000;
        uStack_74 = uVar1 & 0xff;
        local_78 = 0x43300000;
        GXTexCoord2f32((double)((float)((double)CONCAT44(0x43300000,uStack_8c) - @149) /
                               (float)((double)CONCAT44(0x43300000,uStack_84) - @151)),
                       (double)((float)((double)CONCAT44(0x43300000,uStack_7c) - @149) /
                               (float)((double)CONCAT44(0x43300000,uStack_74) - @151)));
      }
    }
    GXEnd();
  }
  RestoreVertState();
  _restfpr_20();
  return;
}

void GXDrawCubeFace(undefined8 param_1,double param_2,double param_3,double param_4,double param_5,
                   double param_6,double param_7,double param_8)
{
  int iVar1;
  int iVar2;
  double extraout_f1;
  double dVar3;
  double dVar4;
  undefined8 uVar5;
  float param_9;
  
  uVar5 = _savefpr_23();
  iVar1 = (int)((ulonglong)uVar5 >> 0x20);
  iVar2 = (int)uVar5;
  dVar4 = (double)param_9;
  dVar3 = extraout_f1;
  GXPosition3f32((double)(@225 * (float)(param_7 + (double)(float)(extraout_f1 + param_4))),
                 (double)(@225 * (float)(param_8 + (double)(float)(param_2 + param_5))),
                 (double)(@225 * (float)(dVar4 + (double)(float)(param_3 + param_6))));
  GXNormal3f32(dVar3,param_2,param_3);
  if (iVar1 != 0) {
    GXNormal3f32(param_4,param_5,param_6);
    GXNormal3f32(param_7,param_8,dVar4);
  }
  if (iVar2 != 0) {
    GXTexCoord2s8(1,1);
  }
  GXPosition3f32((double)(@225 * (float)(param_7 + (double)(float)(dVar3 - param_4))),
                 (double)(@225 * (float)(param_8 + (double)(float)(param_2 - param_5))),
                 (double)(@225 * (float)(dVar4 + (double)(float)(param_3 - param_6))));
  GXNormal3f32(dVar3,param_2,param_3);
  if (iVar1 != 0) {
    GXNormal3f32(param_4,param_5,param_6);
    GXNormal3f32(param_7,param_8,dVar4);
  }
  if (iVar2 != 0) {
    GXTexCoord2s8(0,1);
  }
  GXPosition3f32((double)(@225 * (float)((double)(float)(dVar3 - param_4) - param_7)),
                 (double)(@225 * (float)((double)(float)(param_2 - param_5) - param_8)),
                 (double)(@225 * (float)((double)(float)(param_3 - param_6) - dVar4)));
  GXNormal3f32(dVar3,param_2,param_3);
  if (iVar1 != 0) {
    GXNormal3f32(param_4,param_5,param_6);
    GXNormal3f32(param_7,param_8,dVar4);
  }
  if (iVar2 != 0) {
    GXTexCoord2s8(0,0);
  }
  GXPosition3f32((double)(@225 * (float)((double)(float)(dVar3 + param_4) - param_7)),
                 (double)(@225 * (float)((double)(float)(param_2 + param_5) - param_8)),
                 (double)(@225 * (float)((double)(float)(param_3 + param_6) - dVar4)));
  GXNormal3f32(dVar3,param_2,param_3);
  if (iVar1 != 0) {
    GXNormal3f32(param_4,param_5,param_6);
    GXNormal3f32(param_7,param_8,dVar4);
  }
  if (iVar2 != 0) {
    GXTexCoord2s8(1,0);
  }
  _restfpr_23();
  return;
}

void GXDrawCube(void)
{
  int local_8;
  int local_4;
  
  GXGetVtxDesc(0x19,&local_4);
  GXGetVtxDesc(0xd,&local_8);
  GetVertState();
  if (local_4 != 0) {
    GXSetVtxDesc(0x19,1);
    GXSetVtxAttrFmt(3,0x19,1,4,0);
  }
  if (local_8 != 0) {
    GXSetVtxDesc(0xd,1);
    GXSetVtxAttrFmt(3,0xd,1,1,0);
  }
  GXBegin(0x80,3,0x18);
  GXDrawCubeFace((double)@147,(double)@100,(double)@100,(double)@100,(double)@100,(double)@147,
                 (double)@100,(double)@143,local_4,local_8);
  GXDrawCubeFace((double)@143,(double)@100,(double)@100,(double)@100,(double)@143,(double)@100,
                 (double)@100,(double)@100,local_4,local_8);
  GXDrawCubeFace((double)@100,(double)@147,(double)@100,(double)@147,(double)@100,(double)@100,
                 (double)@100,(double)@100,local_4,local_8);
  GXDrawCubeFace((double)@100,(double)@143,(double)@100,(double)@100,(double)@100,(double)@143,
                 (double)@147,(double)@100,local_4,local_8);
  GXDrawCubeFace((double)@100,(double)@100,(double)@147,(double)@100,(double)@147,(double)@100,
                 (double)@143,(double)@100,local_4,local_8);
  GXDrawCubeFace((double)@100,(double)@100,(double)@143,(double)@143,(double)@100,(double)@100,
                 (double)@100,(double)@147,local_4,local_8);
  GXEnd();
  RestoreVertState();
  return;
}

void GXDrawDodeca(void)
{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined auStack_40 [12];
  undefined auStack_34 [12];
  undefined auStack_28 [20];
  
  GetVertState();
  for (uVar4 = 0; uVar4 < 0xc; uVar4 = uVar4 + 1) {
    iVar1 = *(int *)(polygons + uVar4 * 0x14);
    puVar3 = verts + *(int *)(polygons + uVar4 * 0x14 + 4) * 0xc;
    iVar2 = *(int *)(polygons + uVar4 * 0x14 + 8);
    vsub(puVar3,verts + iVar2 * 0xc,auStack_28);
    vsub(puVar3,verts + iVar1 * 0xc,auStack_34);
    vcross(auStack_28,auStack_34,auStack_40);
    normalize(auStack_40);
    GXBegin(0xa0,3,5);
    myvertex(verts + *(int *)(polygons + uVar4 * 0x14 + 0x10) * 0xc,auStack_40);
    myvertex(verts + *(int *)(polygons + uVar4 * 0x14 + 0xc) * 0xc,auStack_40);
    myvertex(verts + iVar2 * 0xc,auStack_40);
    myvertex(puVar3,auStack_40);
    myvertex(verts + iVar1 * 0xc,auStack_40);
    GXEnd();
  }
  RestoreVertState();
  return;
}

void GXDrawOctahedron(void)
{
  uint uVar1;
  
  GetVertState();
  for (uVar1 = 7; -1 < (int)uVar1; uVar1 = uVar1 - 1) {
    SubDivTriangle(0,uVar1 & 0xff,odata,ondex);
  }
  RestoreVertState();
  return;
}

void GXDrawIcosahedron(void)
{
  uint uVar1;
  
  GetVertState();
  for (uVar1 = 0x13; -1 < (int)uVar1; uVar1 = uVar1 - 1) {
    SubDivTriangle(0,uVar1 & 0xff,idata,index);
  }
  RestoreVertState();
  return;
}

void GXDrawSphere1(undefined param_1)
{
  uint uVar1;
  
  GetVertState();
  for (uVar1 = 0x13; -1 < (int)uVar1; uVar1 = uVar1 - 1) {
    SubDivTriangle(param_1,uVar1 & 0xff,idata,index);
  }
  RestoreVertState();
  return;
}

undefined4 CmpNormal32(int param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (2 < uVar1) {
      return 1;
    }
    if (*(float *)(param_1 + uVar1 * 4) != *(float *)(param_2 + uVar1 * 4)) break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}

void AddNormal(undefined4 *param_1)
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    if (nrm_cnt <= uVar1) {
      iVar2 = nrm_cnt * 3;
      *(undefined4 *)(nrm_tab + nrm_cnt * 0xc) = *param_1;
      *(undefined4 *)(nrm_tab + (iVar2 + 1) * 4) = param_1[1];
      *(undefined4 *)(nrm_tab + (iVar2 + 2) * 4) = param_1[2];
      nrm_cnt = nrm_cnt + 1;
      return;
    }
    iVar2 = CmpNormal32(param_1,nrm_tab + uVar1 * 0xc);
    if (iVar2 != 0) break;
    uVar1 = uVar1 + 1;
  }
  return;
}

void SubdivideNrm(uint param_1,int param_2,int param_3,int param_4)
{
  uint uVar1;
  float local_40 [11];
  
  if ((param_1 & 0xff) == 0) {
    AddNormal(param_2);
    AddNormal(param_3);
    AddNormal(param_4);
  }
  else {
    for (uVar1 = 0; uVar1 < 3; uVar1 = uVar1 + 1) {
      local_40[uVar1 + 6] = *(float *)(param_2 + uVar1 * 4) + *(float *)(param_3 + uVar1 * 4);
      local_40[uVar1 + 3] = *(float *)(param_3 + uVar1 * 4) + *(float *)(param_4 + uVar1 * 4);
      local_40[uVar1] = *(float *)(param_4 + uVar1 * 4) + *(float *)(param_2 + uVar1 * 4);
    }
    normalize(local_40 + 6);
    normalize(local_40 + 3);
    normalize(local_40);
    SubdivideNrm(param_1 - 1,param_2,local_40 + 6,local_40);
    SubdivideNrm(param_1 - 1,param_3,local_40 + 3,local_40 + 6);
    SubdivideNrm(param_1 - 1,param_4,local_40,local_40 + 3);
    SubdivideNrm(param_1 - 1,local_40 + 6,local_40 + 3,local_40);
  }
  return;
}

void SubDivNrm(undefined param_1,uint param_2,int param_3,int param_4)
{
  SubdivideNrm(param_1,param_3 + (uint)*(byte *)(param_4 + (param_2 & 0xff) * 3) * 0xc,
               param_3 + (uint)*(byte *)(param_4 + (param_2 & 0xff) * 3 + 1) * 0xc,
               param_3 + (uint)*(byte *)(param_4 + (param_2 & 0xff) * 3 + 2) * 0xc);
  return;
}

undefined4 GXGenNormalTable(undefined param_1,undefined4 param_2)
{
  uint uVar1;
  
  nrm_cnt = 0;
  nrm_tab = param_2;
  for (uVar1 = 7; -1 < (int)uVar1; uVar1 = uVar1 - 1) {
    SubDivNrm(param_1,uVar1 & 0xff,odata,ondex);
  }
  return nrm_cnt;
}
