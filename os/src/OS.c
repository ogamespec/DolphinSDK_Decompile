undefined4 __OSIsDebuggerPresent(void)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)OSPhysicalToCached(0x40);
  return *puVar1;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSInitFPRs()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             __OSInitFPRs
        00010028 c8 0d fe 8c     lfd        f0,-0x174(r13)=>ZeroF                            = ??
        0001002c fc 20 00 90     fmr        f1,f0
        00010030 fc 40 00 90     fmr        f2,f0
        00010034 fc 60 00 90     fmr        f3,f0
        00010038 fc 80 00 90     fmr        f4,f0
        0001003c fc a0 00 90     fmr        f5,f0
        00010040 fc c0 00 90     fmr        f6,f0
        00010044 fc e0 00 90     fmr        f7,f0
        00010048 fd 00 00 90     fmr        f8,f0
        0001004c fd 20 00 90     fmr        f9,f0
        00010050 fd 40 00 90     fmr        f10,f0
        00010054 fd 60 00 90     fmr        f11,f0
        00010058 fd 80 00 90     fmr        f12,f0
        0001005c fd a0 00 90     fmr        f13,f0
        00010060 fd c0 00 90     fmr        f14,f0
        00010064 fd e0 00 90     fmr        f15,f0
        00010068 fe 00 00 90     fmr        f16,f0
        0001006c fe 20 00 90     fmr        f17,f0
        00010070 fe 40 00 90     fmr        f18,f0
        00010074 fe 60 00 90     fmr        f19,f0
        00010078 fe 80 00 90     fmr        f20,f0
        0001007c fe a0 00 90     fmr        f21,f0
        00010080 fe c0 00 90     fmr        f22,f0
        00010084 fe e0 00 90     fmr        f23,f0
        00010088 ff 00 00 90     fmr        f24,f0
        0001008c ff 20 00 90     fmr        f25,f0
        00010090 ff 40 00 90     fmr        f26,f0
        00010094 ff 60 00 90     fmr        f27,f0
        00010098 ff 80 00 90     fmr        f28,f0
        0001009c ff a0 00 90     fmr        f29,f0
        000100a0 ff c0 00 90     fmr        f30,f0
        000100a4 ff e0 00 90     fmr        f31,f0
        000100a8 4e 80 00 20     blr

void DisableWriteGatherPipe(void)
{
  uint uVar1;
  
  uVar1 = PPCMfhid2();
  PPCMthid2(uVar1 & 0xbfffffff);
  return;
}

undefined4 OSGetConsoleType(void)
{
  undefined4 uVar1;
  
  if ((BootInfo == 0) || (*(int *)(BootInfo + 0x2c) == 0)) {
    uVar1 = 0x10000002;
  }
  else {
    uVar1 = *(undefined4 *)(BootInfo + 0x2c);
  }
  return uVar1;
}

void ClearArena(void)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  void *pvVar6;
  
  iVar2 = OSGetResetCode();
  uVar1 = _DAT_812fdff0;
  pvVar4 = _DAT_812fdfec;
  if (iVar2 == -0x80000000) {
    if (_DAT_812fdff0 == 0) {
      iVar2 = OSGetArenaHi();
      iVar3 = OSGetArenaLo();
      pvVar4 = (void *)OSGetArenaLo();
      memset(pvVar4,0,iVar2 - iVar3);
    }
    else {
      if (_DAT_812fdfec == (void *)0x0) {
        OSPanic(&@22,0x23f,...data.0);
      }
      uVar5 = OSGetArenaLo();
      if (uVar5 < uVar1) {
        uVar5 = OSGetArenaHi();
        if (uVar1 < uVar5) {
          iVar2 = OSGetArenaLo();
          pvVar6 = (void *)OSGetArenaLo();
          memset(pvVar6,0,uVar1 - iVar2);
          pvVar6 = (void *)OSGetArenaHi();
          if (pvVar4 < pvVar6) {
            iVar2 = OSGetArenaHi();
            memset(pvVar4,0,iVar2 - (int)pvVar4);
          }
        }
        else {
          iVar2 = OSGetArenaHi();
          iVar3 = OSGetArenaLo();
          pvVar4 = (void *)OSGetArenaLo();
          memset(pvVar4,0,iVar2 - iVar3);
        }
      }
    }
  }
  else {
    iVar2 = OSGetArenaHi();
    iVar3 = OSGetArenaLo();
    pvVar4 = (void *)OSGetArenaLo();
    memset(pvVar4,0,iVar2 - iVar3);
  }
  return;
}

void OSInit(void)
{
  undefined uVar1;
  undefined8 uVar2;
  uint uVar3;
  int *piVar4;
  undefined *puVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  
  uVar2 = CONCAT44(__OSStartTime._0_4_,__OSStartTime._4_4_);
  if (AreWeInitialized != 0) goto LAB_000105f4;
  AreWeInitialized = 1;
  __OSStartTime = __OSGetSystemTime();
  OSDisableInterrupts();
  BootInfo = OSPhysicalToCached(0);
  BI2DebugFlag = (uint *)0x0;
  uRam00000000 = 0;
  piVar4 = (int *)OSPhysicalToCached(0xf4);
  iVar9 = *piVar4;
  if (iVar9 == 0) {
    if (*(int *)(BootInfo + 0x34) != 0) {
      pbVar6 = (byte *)OSPhysicalToCached(0x30e8);
      BI2DebugFlagHolder = (uint)*pbVar6;
      BI2DebugFlag = &BI2DebugFlagHolder;
      OSPhysicalToCached(0x30e9);
    }
  }
  else {
    BI2DebugFlag = (uint *)(iVar9 + 0xc);
    uRam00000000 = *(undefined4 *)(iVar9 + 0x24);
    uVar3 = *BI2DebugFlag;
    puVar5 = (undefined *)OSPhysicalToCached(0x30e8);
    *puVar5 = (char)uVar3;
    uVar1 = (undefined)uRam00000000;
    puVar5 = (undefined *)OSPhysicalToCached(0x30e9);
    *puVar5 = uVar1;
  }
  uRam00000000 = 1;
  if (*(int *)(BootInfo + 0x30) == 0) {
    puVar5 = &__ArenaLo;
  }
  else {
    puVar5 = *(undefined **)(BootInfo + 0x30);
  }
  OSSetArenaLo(puVar5);
  if (((*(int *)(BootInfo + 0x30) == 0) && (BI2DebugFlag != (uint *)0x0)) && (*BI2DebugFlag < 2)) {
    OSSetArenaLo(&_stack_addr);
  }
  if (*(int *)(BootInfo + 0x34) == 0) {
    puVar5 = &__ArenaHi;
  }
  else {
    puVar5 = *(undefined **)(BootInfo + 0x34);
  }
  OSSetArenaHi(puVar5);
  OSExceptionInit();
  __OSInitSystemCall();
  OSInitAlarm();
  __OSModuleInit();
  __OSInterruptInit();
  __OSSetInterruptHandler(0x16,&__OSResetSWInterruptHandler);
  __OSContextInit();
  __OSCacheInit();
  EXIInit();
  SIInit();
  __OSInitSram();
  __OSThreadInit();
  __OSInitAudioSystem();
  DisableWriteGatherPipe();
  if (BootInfo == 0) {
    OSPanic(&@22,0x2d5,@53);
  }
  if ((*(uint *)(BootInfo + 0x2c) & 0x10000000) == 0) {
    *(undefined4 *)(BootInfo + 0x2c) = 1;
  }
  else {
    *(undefined4 *)(BootInfo + 0x2c) = 0x10000004;
  }
  *(uint *)(BootInfo + 0x2c) = *(int *)(BootInfo + 0x2c) + (_DAT_cc00302c >> 0x1c);
  if (__OSInIPL == 0) {
    __OSInitMemoryProtection();
  }
  OSReport(@54);
  OSReport(@55,@56,@57);
  OSReport(@58);
  uVar3 = OSGetConsoleType();
  if ((uVar3 & 0x10000000) == 0) {
    OSReport(@59,uVar3);
  }
  else if (uVar3 == 0x10000002) {
    OSReport(@62);
  }
  else if ((int)uVar3 < 0x10000002) {
    if (uVar3 == 0x10000000) {
      OSReport(@60);
    }
    else {
      if ((int)uVar3 < 0x10000000) goto LAB_00010580;
      OSReport(@61);
    }
  }
  else if ((int)uVar3 < 0x10000004) {
    OSReport(@63);
  }
  else {
LAB_00010580:
    OSReport(@64,uVar3 + 0xeffffffd);
  }
  OSReport(@65,*(uint *)(BootInfo + 0x28) >> 0x14);
  uVar7 = OSGetArenaHi();
  uVar8 = OSGetArenaLo();
  OSReport(@66,uVar8,uVar7);
  if ((BI2DebugFlag != (uint *)0x0) && (1 < *BI2DebugFlag)) {
    EnableMetroTRKInterrupts();
  }
  ClearArena();
  OSEnableInterrupts();
  uVar2 = __OSStartTime;
LAB_000105f4:
  __OSStartTime._0_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
  __OSStartTime._4_4_ = (undefined4)uVar2;
  return;
}

void OSExceptionInit(void)
{
  uint uVar1;
  int *__dest;
  int iVar2;
  void *__dest_00;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = ___OSEVSetNumber;
  __dest = (int *)OSPhysicalToCached(0x60);
  if (*__dest == 0) {
    DBPrintf(@109);
    memcpy(__dest,__OSDBIntegrator,0x24);
    DCFlushRangeNoSync(__dest,0x24);
    sync(0);
    ICInvalidateRange(__dest,0x24);
  }
  for (uVar5 = 0; (uVar5 & 0xff) < 0xf; uVar5 = uVar5 + 1) {
    if (((BI2DebugFlag == (uint *)0x0) || (*BI2DebugFlag < 2)) ||
       (iVar2 = __DBIsExceptionMarked(uVar5), iVar2 == 0)) {
      ___OSEVSetNumber = uVar1 | uVar5 & 0xff;
      iVar2 = __DBIsExceptionMarked(uVar5);
      if (iVar2 == 0) {
        pcVar3 = __DBVECTOR;
        for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 4) {
          *(undefined4 *)pcVar3 = 0x60000000;
          pcVar3 = (code *)((int)pcVar3 + 4);
        }
      }
      else {
        DBPrintf(@111,uVar5 & 0xff);
        memcpy(__DBVECTOR,__OSDBJump,4);
      }
      __dest_00 = (void *)OSPhysicalToCached(*(undefined4 *)
                                              (__OSExceptionLocations + (uVar5 & 0xff) * 4));
      memcpy(__dest_00,OSExceptionVector,0x98);
      DCFlushRangeNoSync(__dest_00,0x98);
      sync(0);
      ICInvalidateRange(__dest_00,0x98);
    }
    else {
      DBPrintf(@110,uVar5 & 0xff);
    }
  }
  OSExceptionTable = OSPhysicalToCached(0x3000);
  for (uVar5 = 0; (uVar5 & 0xff) < 0xf; uVar5 = uVar5 + 1) {
    __OSSetExceptionHandler(uVar5,OSDefaultExceptionHandler);
  }
  ___OSEVSetNumber = uVar1;
  DBPrintf(@112);
  return;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSDBIntegrator()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             __OSDBINTSTART                                  XREF[5]:     Entry Point(*), 
                             __OSDBIntegrator                                             OSExceptionInit:000106b8(*), 
                                                                                          OSExceptionInit:000106c0(*), 
                                                                                          OSExceptionInit:000106dc(*), 
                                                                                          OSExceptionInit:000106fc(*)  
        00010898 38 a0 00 40     li         r5,0x40
        0001089c 7c 68 02 a6     mfspr      r3,LR
        000108a0 90 65 00 0c     stw        r3,0xc(r5)=>DAT_0000004c
        000108a4 80 65 00 08     lwz        r3,0x8(r5)=>DAT_00000048
        000108a8 64 63 80 00     oris       r3,r3,0x8000
        000108ac 7c 68 03 a6     mtspr      LR,r3
        000108b0 38 60 00 30     li         r3,0x30
        000108b4 7c 60 01 24     mtmsr      r3,0
        000108b8 4e 80 00 20     blr
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSDBJump()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             __OSDBINTEND                                    XREF[4]:     Entry Point(*), 
                             __OSDBJUMPSTART                                              OSExceptionInit:00010790(*), 
                             __OSDBJump                                                   OSExceptionInit:00010798(*), 
                                                                                          OSExceptionInit:000107d4(*)  
        000108bc 48 00 00 63     bla        SUB_00000060


undefined4 __OSSetExceptionHandler(byte param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  if (0xe < param_1) {
    OSPanic(&@22,0x410,@114);
  }
  uVar1 = *(undefined4 *)(OSExceptionTable + (uint)param_1 * 4);
  *(undefined4 *)(OSExceptionTable + (uint)param_1 * 4) = param_2;
  return uVar1;
}

undefined4 __OSGetExceptionHandler(byte param_1)
{
  if (0xe < param_1) {
    OSPanic(&@22,0x427,@116);
  }
  return *(undefined4 *)(OSExceptionTable + (uint)param_1 * 4);
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSExceptionVector()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             __OSEVStart                                     XREF[3]:     Entry Point(*), 
                             OSExceptionVector                                            OSExceptionInit:0001067c(*), 
                                                                                          OSExceptionInit:00010808(*)  
        000109bc 7c 90 43 a6     mtspr      SPRG0,r4
        000109c0 80 80 00 c0     lwz        r4,0xc0(0)
        000109c4 90 64 00 0c     stw        r3,0xc(r4)
        000109c8 7c 70 42 a6     mfspr      r3,SPRG0
        000109cc 90 64 00 10     stw        r3,0x10(r4)
        000109d0 90 a4 00 14     stw        r5,0x14(r4)
        000109d4 a0 64 01 a2     lhz        r3,0x1a2(r4)
        000109d8 60 63 00 02     ori        r3,r3,0x2
        000109dc b0 64 01 a2     sth        r3,0x1a2(r4)
        000109e0 7c 60 00 26     mfcr       r3
        000109e4 90 64 00 80     stw        r3,0x80(r4)
        000109e8 7c 68 02 a6     mfspr      r3,LR
        000109ec 90 64 00 84     stw        r3,0x84(r4)
        000109f0 7c 69 02 a6     mfspr      r3,CTR
        000109f4 90 64 00 88     stw        r3,0x88(r4)
        000109f8 7c 61 02 a6     mfspr      r3,XER
        000109fc 90 64 00 8c     stw        r3,0x8c(r4)
        00010a00 7c 7a 02 a6     mfspr      r3,SRR0
        00010a04 90 64 01 98     stw        r3,0x198(r4)
        00010a08 7c 7b 02 a6     mfspr      r3,SRR1
        00010a0c 90 64 01 9c     stw        r3,0x19c(r4)
        00010a10 7c 65 1b 78     or         r5,r3,r3
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __DBVECTOR()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             __DBVECTOR                                      XREF[3]:     Entry Point(*), 
                                                                                          OSExceptionInit:00010788(*), 
                                                                                          OSExceptionInit:000107c4(W)  
        00010a14 60 00 00 00     ori        r0,r0,0x0
        00010a18 7c 60 00 a6     mfmsr      r3
        00010a1c 60 63 00 30     ori        r3,r3,0x30
        00010a20 7c 7b 03 a6     mtspr      SRR1,r3
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSEVSetNumber()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             __OSEVSetNumber                                 XREF[4]:     Entry Point(*), 
                                                                                          OSExceptionInit:0001066c(R), 
                                                                                          OSExceptionInit:00010760(W), 
                                                                                          OSExceptionInit:00010874(W)  
        00010a24 38 60 00 00     li         r3,0x0
        00010a28 80 80 00 d4     lwz        r4,0xd4(0)
        00010a2c 54 a5 07 bd     rlwinm.    r5,r5,0x0,0x1e,0x1e
        00010a30 40 82 00 14     bne        LAB_00010a44
        00010a34 3c a0 00 01     lis        r5,0x1
        00010a38 38 a5 0a 58     addi       r5,r5,0xa58
        00010a3c 7c ba 03 a6     mtspr      SRR0,r5
        00010a40 4c 00 00 64     rfi
                             LAB_00010a44                                    XREF[1]:     00010a30(j)  
        00010a44 54 65 15 ba     rlwinm     r5,r3,0x2,0x16,0x1d
        00010a48 80 a5 30 00     lwz        r5,0x3000(r5)
        00010a4c 7c ba 03 a6     mtspr      SRR0,r5
        00010a50 4c 00 00 64     rfi
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSEVEnd()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             __OSEVEnd                                       XREF[1]:     Entry Point(*)  
        00010a54 60 00 00 00     ori        r0,r0,0x0


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined OSDefaultExceptionHandler()
                               assume r13 = 0x1101c
             undefined         r3:1           <RETURN>
                             OSDefaultExceptionHandler                       XREF[2]:     Entry Point(*), 
                                                                                          OSExceptionInit:0001085c(*)  
        00010a58 90 04 00 00     stw        r0,0x0(r4)
        00010a5c 90 24 00 04     stw        r1,0x4(r4)
        00010a60 90 44 00 08     stw        r2,0x8(r4)
        00010a64 bc c4 00 18     stmw       r6,0x18(r4)=>_SDA_BASE_                          = ??
        00010a68 7c 11 e2 a6     mfspr      r0,spr391
        00010a6c 90 04 01 a8     stw        r0,0x1a8(r4)
        00010a70 7c 12 e2 a6     mfspr      r0,spr392
        00010a74 90 04 01 ac     stw        r0,0x1ac(r4)
        00010a78 7c 13 e2 a6     mfspr      r0,spr393
        00010a7c 90 04 01 b0     stw        r0,0x1b0(r4)
        00010a80 7c 14 e2 a6     mfspr      r0,spr394
        00010a84 90 04 01 b4     stw        r0,0x1b4(r4)
        00010a88 7c 15 e2 a6     mfspr      r0,spr395
        00010a8c 90 04 01 b8     stw        r0,0x1b8(r4)
        00010a90 7c 16 e2 a6     mfspr      r0,spr396
        00010a94 90 04 01 bc     stw        r0,0x1bc(r4)
        00010a98 7c 17 e2 a6     mfspr      r0,spr397
        00010a9c 90 04 01 c0     stw        r0,0x1c0(r4)
        00010aa0 7c b2 02 a6     mfspr      r5,DSISR
        00010aa4 7c d3 02 a6     mfspr      r6,DAR
        00010aa8 48 00 06 a0     b          <EXTERNAL>::__OSUnhandledException               undefined __OSUnhandledException()
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)


undefined4 __OSPSInit(void)
{
  uint uVar1;
  
  uVar1 = PPCMfhid2();
  PPCMthid2(uVar1 | 0xa0000000);
  ICFlashInvalidate();
  sync(0);
  return 0;
}

uint __OSGetDIConfig(void)
{
  return _DAT_cc006024 & 0xff;
}
