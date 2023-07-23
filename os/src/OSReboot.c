                             //
                             // .text 
                             // SHT_PROGBITS  [0x0 - 0x397]
                             // ram:00010000-ram:00010397
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined Run()
                               assume r13 = 0x10540
             undefined         r3:1           <RETURN>
             undefined4        Stack[0x4]:4   local_res4                              XREF[1]:     00010004(W)  
             undefined4        Stack[-0x4]:4  local_4                                 XREF[1]:     0001000c(W)  
             undefined4        Stack[-0x18]:4 local_18                                XREF[1]:     00010008(W)  
                             Run                                             XREF[2]:     __OSReboot:0001025c(c), 
                                                                                          _elfSectionHeaders::00000034(*)  
        00010000 7c 08 02 a6     mfspr      r0,LR
        00010004 90 01 00 04     stw        r0,local_res4(r1)
        00010008 94 21 ff e8     stwu       r1,local_18(r1)
        0001000c 93 e1 00 14     stw        r31,local_4(r1)
        00010010 7c 7f 1b 78     or         r31,r3,r3
        00010014 48 00 0f ed     bl         <EXTERNAL>::OSDisableInterrupts                  undefined OSDisableInterrupts()
        00010018 48 00 0f ed     bl         <EXTERNAL>::ICFlashInvalidate                    undefined ICFlashInvalidate()
        0001001c 7c 00 04 ac     sync       0x0
        00010020 4c 00 01 2c     isync
        00010024 7f e8 03 a6     mtspr      LR,r31
        00010028 4e 80 00 20     blr


undefined4 ReadApploader(undefined4 param_1,undefined4 param_2,int param_3)
{
  undefined4 uVar1;
  undefined auStack_34 [12];
  int local_28;
  
  do {
  } while (Prepared == 0);
  uVar1 = DVDReadAbsAsyncForBS(auStack_34,param_1,param_2,param_3 + 0x2440,0);
  do {
    while( true ) {
      do {
      } while (local_28 == 1);
      if (0 < local_28) break;
      if (local_28 == -1) goto LAB_000100b0;
      if (-2 < local_28) {
        return uVar1;
      }
LAB_000100c0:
      OSPanic(...data.0,0xb4,@31);
      uVar1 = 0;
    }
    if (0xb < local_28) goto LAB_000100c0;
LAB_000100b0:
    uVar1 = __OSDoHotReset(_DAT_817ffffc);
  } while( true );
}

void Callback(void)
{
  Prepared = 1;
  return;
}

void __OSReboot(undefined4 param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  undefined auStack_2d8 [712];
  
  if (param_2 == 1) {
    OSReport(@38);
  }
  OSDisableInterrupts();
  _DAT_817ffff8 = 0;
  DAT_800030e2 = 1;
  _DAT_812fdff0 = SaveStart;
  _DAT_812fdfec = SaveEnd;
  _DAT_817ffffc = param_1;
  OSClearContext(auStack_2d8);
  OSSetCurrentContext(auStack_2d8);
  DVDInit();
  DVDSetAutoInvalidation(1);
  __DVDPrepareResetAsync(Callback);
  iVar2 = DVDCheckDisk();
  if (iVar2 == 0) {
    __OSDoHotReset(_DAT_817ffffc);
  }
  __OSMaskInterrupts(0xffffffe0);
  __OSUnmaskInterrupts(0x400);
  OSEnableInterrupts();
  ReadApploader(Header,0x20,0);
  if (Header._24_4_ == 0) {
    OSPanic(...data.0,0x101,@39);
  }
  uVar1 = Header._24_4_ + 0x1f & 0xffffffe0;
  ReadApploader(0x81300000,uVar1,Header._20_4_ + 0x20);
  ICInvalidateRange(0x81300000,uVar1);
  Run(0x81300000);
  return;
}

void OSSetSaveRegion(uint param_1,uint param_2)
{
  if ((param_1 < 0x80700000) && (param_1 != 0)) {
    OSPanic(...data.0,0x112,@41);
  }
  if ((0x81200000 < param_2) && (param_2 != 0)) {
    OSPanic(...data.0,0x113,@42);
  }
  if ((param_1 == 0) != (param_2 == 0)) {
    OSPanic(...data.0,0x114,@43);
  }
  SaveStart = param_1;
  SaveEnd = param_2;
  return;
}

void OSGetSaveRegion(undefined4 *param_1,undefined4 *param_2)
{
  *param_1 = SaveStart;
  *param_2 = SaveEnd;
  return;
}
