                             //
                             // .text 
                             // SHT_PROGBITS  [0x0 - 0xbe3]
                             // ram:00010000-ram:00010be3
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCFlashInvalidate()
             undefined         r3:1           <RETURN>
                             DCFlashInvalidate                               XREF[2]:     Entry Point(*), 
                                                                                          _elfSectionHeaders::00000034(*)  
        00010000 7c 70 fa a6     mfspr      r3,DBSR
        00010004 60 63 04 00     ori        r3,r3,0x400
        00010008 7c 70 fb a6     mtspr      DBSR,r3
        0001000c 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCEnable()
             undefined         r3:1           <RETURN>
                             DCEnable                                        XREF[2]:     Entry Point(*), 
                                                                                          __OSCacheInit:00010b80(c)  
        00010010 7c 00 04 ac     sync       0x0
        00010014 7c 70 fa a6     mfspr      r3,DBSR
        00010018 60 63 40 00     ori        r3,r3,0x4000
        0001001c 7c 70 fb a6     mtspr      DBSR,r3
        00010020 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCDisable()
             undefined         r3:1           <RETURN>
                             DCDisable                                       XREF[1]:     Entry Point(*)  
        00010024 7c 00 04 ac     sync       0x0
        00010028 7c 70 fa a6     mfspr      r3,DBSR
        0001002c 54 63 04 a0     rlwinm     r3,r3,0x0,0x12,0x10
        00010030 7c 70 fb a6     mtspr      DBSR,r3
        00010034 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCFreeze()
             undefined         r3:1           <RETURN>
                             DCFreeze                                        XREF[1]:     Entry Point(*)  
        00010038 7c 00 04 ac     sync       0x0
        0001003c 7c 70 fa a6     mfspr      r3,DBSR
        00010040 60 63 10 00     ori        r3,r3,0x1000
        00010044 7c 70 fb a6     mtspr      DBSR,r3
        00010048 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCUnfreeze()
             undefined         r3:1           <RETURN>
                             DCUnfreeze                                      XREF[1]:     Entry Point(*)  
        0001004c 7c 70 fa a6     mfspr      r3,DBSR
        00010050 54 63 05 24     rlwinm     r3,r3,0x0,0x14,0x12
        00010054 7c 70 fb a6     mtspr      DBSR,r3
        00010058 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCTouchLoad()
             undefined         r3:1           <RETURN>
                             DCTouchLoad                                     XREF[1]:     Entry Point(*)  
        0001005c 7c 00 1a 2c     dcbt       0,r3
        00010060 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCBlockZero()
             undefined         r3:1           <RETURN>
                             DCBlockZero                                     XREF[1]:     Entry Point(*)  
        00010064 7c 00 1f ec     dcbz       0,r3
        00010068 4e 80 00 20     blr

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCBlockStore()
             undefined         r3:1           <RETURN>
                             DCBlockStore                                    XREF[1]:     Entry Point(*)  
        0001006c 7c 00 18 6c     dcbst      0,r3
        00010070 4e 80 00 20     blr

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCBlockFlush()
             undefined         r3:1           <RETURN>
                             DCBlockFlush                                    XREF[1]:     Entry Point(*)  
        00010074 7c 00 18 ac     dcbf       0,r3
        00010078 4e 80 00 20     blr

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCBlockInvalidate()
             undefined         r3:1           <RETURN>
                             DCBlockInvalidate                               XREF[1]:     Entry Point(*)  
        0001007c 7c 00 1b ac     dcbi       0,r3
        00010080 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCInvalidateRange()
             undefined         r3:1           <RETURN>
                             DCInvalidateRange                               XREF[1]:     Entry Point(*)  
        00010084 28 04 00 00     cmplwi     r4,0x0
        00010088 4c 81 00 20     blelr
        0001008c 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        00010090 41 82 00 08     beq        LAB_00010098
        00010094 38 84 00 20     addi       r4,r4,0x20
                             LAB_00010098                                    XREF[1]:     00010090(j)  
        00010098 38 84 00 1f     addi       r4,r4,0x1f
        0001009c 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        000100a0 7c 89 03 a6     mtspr      CTR,r4
                             LAB_000100a4                                    XREF[1]:     000100ac(j)  
        000100a4 7c 00 1b ac     dcbi       0,r3
        000100a8 38 63 00 20     addi       r3,r3,0x20
        000100ac 42 00 ff f8     bdnz       LAB_000100a4
        000100b0 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCFlushRange()
             undefined         r3:1           <RETURN>
                             DCFlushRange                                    XREF[1]:     Entry Point(*)  
        000100b4 28 04 00 00     cmplwi     r4,0x0
        000100b8 4c 81 00 20     blelr
        000100bc 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        000100c0 41 82 00 08     beq        LAB_000100c8
        000100c4 38 84 00 20     addi       r4,r4,0x20
                             LAB_000100c8                                    XREF[1]:     000100c0(j)  
        000100c8 38 84 00 1f     addi       r4,r4,0x1f
        000100cc 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        000100d0 7c 89 03 a6     mtspr      CTR,r4
                             LAB_000100d4                                    XREF[1]:     000100dc(j)  
        000100d4 7c 00 18 ac     dcbf       0,r3
        000100d8 38 63 00 20     addi       r3,r3,0x20
        000100dc 42 00 ff f8     bdnz       LAB_000100d4
        000100e0 44 00 00 02     sc         0x0
        000100e4 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCStoreRange()
             undefined         r3:1           <RETURN>
                             DCStoreRange                                    XREF[1]:     Entry Point(*)  
        000100e8 28 04 00 00     cmplwi     r4,0x0
        000100ec 4c 81 00 20     blelr
        000100f0 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        000100f4 41 82 00 08     beq        LAB_000100fc
        000100f8 38 84 00 20     addi       r4,r4,0x20
                             LAB_000100fc                                    XREF[1]:     000100f4(j)  
        000100fc 38 84 00 1f     addi       r4,r4,0x1f
        00010100 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        00010104 7c 89 03 a6     mtspr      CTR,r4
                             LAB_00010108                                    XREF[1]:     00010110(j)  
        00010108 7c 00 18 6c     dcbst      0,r3
        0001010c 38 63 00 20     addi       r3,r3,0x20
        00010110 42 00 ff f8     bdnz       LAB_00010108
        00010114 44 00 00 02     sc         0x0
        00010118 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCFlushRangeNoSync()
             undefined         r3:1           <RETURN>
                             DCFlushRangeNoSync                              XREF[1]:     Entry Point(*)  
        0001011c 28 04 00 00     cmplwi     r4,0x0
        00010120 4c 81 00 20     blelr
        00010124 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        00010128 41 82 00 08     beq        LAB_00010130
        0001012c 38 84 00 20     addi       r4,r4,0x20
                             LAB_00010130                                    XREF[1]:     00010128(j)  
        00010130 38 84 00 1f     addi       r4,r4,0x1f
        00010134 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        00010138 7c 89 03 a6     mtspr      CTR,r4
                             LAB_0001013c                                    XREF[1]:     00010144(j)  
        0001013c 7c 00 18 ac     dcbf       0,r3
        00010140 38 63 00 20     addi       r3,r3,0x20
        00010144 42 00 ff f8     bdnz       LAB_0001013c
        00010148 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCStoreRangeNoSync()
             undefined         r3:1           <RETURN>
                             DCStoreRangeNoSync                              XREF[1]:     Entry Point(*)  
        0001014c 28 04 00 00     cmplwi     r4,0x0
        00010150 4c 81 00 20     blelr
        00010154 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        00010158 41 82 00 08     beq        LAB_00010160
        0001015c 38 84 00 20     addi       r4,r4,0x20
                             LAB_00010160                                    XREF[1]:     00010158(j)  
        00010160 38 84 00 1f     addi       r4,r4,0x1f
        00010164 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        00010168 7c 89 03 a6     mtspr      CTR,r4
                             LAB_0001016c                                    XREF[1]:     00010174(j)  
        0001016c 7c 00 18 6c     dcbst      0,r3
        00010170 38 63 00 20     addi       r3,r3,0x20
        00010174 42 00 ff f8     bdnz       LAB_0001016c
        00010178 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCZeroRange()
             undefined         r3:1           <RETURN>
                             DCZeroRange                                     XREF[1]:     Entry Point(*)  
        0001017c 28 04 00 00     cmplwi     r4,0x0
        00010180 4c 81 00 20     blelr
        00010184 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        00010188 41 82 00 08     beq        LAB_00010190
        0001018c 38 84 00 20     addi       r4,r4,0x20
                             LAB_00010190                                    XREF[1]:     00010188(j)  
        00010190 38 84 00 1f     addi       r4,r4,0x1f
        00010194 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        00010198 7c 89 03 a6     mtspr      CTR,r4
                             LAB_0001019c                                    XREF[1]:     000101a4(j)  
        0001019c 7c 00 1f ec     dcbz       0,r3
        000101a0 38 63 00 20     addi       r3,r3,0x20
        000101a4 42 00 ff f8     bdnz       LAB_0001019c
        000101a8 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined DCTouchRange()
             undefined         r3:1           <RETURN>
                             DCTouchRange                                    XREF[1]:     Entry Point(*)  
        000101ac 28 04 00 00     cmplwi     r4,0x0
        000101b0 4c 81 00 20     blelr
        000101b4 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        000101b8 41 82 00 08     beq        LAB_000101c0
        000101bc 38 84 00 20     addi       r4,r4,0x20
                             LAB_000101c0                                    XREF[1]:     000101b8(j)  
        000101c0 38 84 00 1f     addi       r4,r4,0x1f
        000101c4 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        000101c8 7c 89 03 a6     mtspr      CTR,r4
                             LAB_000101cc                                    XREF[1]:     000101d4(j)  
        000101cc 7c 00 1a 2c     dcbt       0,r3
        000101d0 38 63 00 20     addi       r3,r3,0x20
        000101d4 42 00 ff f8     bdnz       LAB_000101cc
        000101d8 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICInvalidateRange()
             undefined         r3:1           <RETURN>
                             ICInvalidateRange                               XREF[1]:     Entry Point(*)  
        000101dc 28 04 00 00     cmplwi     r4,0x0
        000101e0 4c 81 00 20     blelr
        000101e4 54 65 06 ff     rlwinm.    r5,r3,0x0,0x1b,0x1f
        000101e8 41 82 00 08     beq        LAB_000101f0
        000101ec 38 84 00 20     addi       r4,r4,0x20
                             LAB_000101f0                                    XREF[1]:     000101e8(j)  
        000101f0 38 84 00 1f     addi       r4,r4,0x1f
        000101f4 54 84 d9 7e     rlwinm     r4,r4,0x1b,0x5,0x1f
        000101f8 7c 89 03 a6     mtspr      CTR,r4
                             LAB_000101fc                                    XREF[1]:     00010204(j)  
        000101fc 7c 00 1f ac     icbi       0,r3
        00010200 38 63 00 20     addi       r3,r3,0x20
        00010204 42 00 ff f8     bdnz       LAB_000101fc
        00010208 7c 00 04 ac     sync       0x0
        0001020c 4c 00 01 2c     isync
        00010210 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICFlashInvalidate()
             undefined         r3:1           <RETURN>
                             ICFlashInvalidate                               XREF[1]:     Entry Point(*)  
        00010214 7c 70 fa a6     mfspr      r3,DBSR
        00010218 60 63 08 00     ori        r3,r3,0x800
        0001021c 7c 70 fb a6     mtspr      DBSR,r3
        00010220 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICEnable()
             undefined         r3:1           <RETURN>
                             ICEnable                                        XREF[2]:     Entry Point(*), 
                                                                                          __OSCacheInit:00010b60(c)  
        00010224 4c 00 01 2c     isync
        00010228 7c 70 fa a6     mfspr      r3,DBSR
        0001022c 60 63 80 00     ori        r3,r3,0x8000
        00010230 7c 70 fb a6     mtspr      DBSR,r3
        00010234 4e 80 00 20     blr

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICDisable()
             undefined         r3:1           <RETURN>
                             ICDisable                                       XREF[1]:     Entry Point(*)  
        00010238 4c 00 01 2c     isync
        0001023c 7c 70 fa a6     mfspr      r3,DBSR
        00010240 54 63 04 5e     rlwinm     r3,r3,0x0,0x11,0xf
        00010244 7c 70 fb a6     mtspr      DBSR,r3
        00010248 4e 80 00 20     blr

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICFreeze()
             undefined         r3:1           <RETURN>
                             ICFreeze                                        XREF[1]:     Entry Point(*)  
        0001024c 4c 00 01 2c     isync
        00010250 7c 70 fa a6     mfspr      r3,DBSR
        00010254 60 63 20 00     ori        r3,r3,0x2000
        00010258 7c 70 fb a6     mtspr      DBSR,r3
        0001025c 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICUnfreeze()
             undefined         r3:1           <RETURN>
                             ICUnfreeze                                      XREF[1]:     Entry Point(*)  
        00010260 7c 70 fa a6     mfspr      r3,DBSR
        00010264 54 63 04 e2     rlwinm     r3,r3,0x0,0x13,0x11
        00010268 7c 70 fb a6     mtspr      DBSR,r3
        0001026c 4e 80 00 20     blr

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICBlockInvalidate()
             undefined         r3:1           <RETURN>
                             ICBlockInvalidate                               XREF[1]:     Entry Point(*)  
        00010270 7c 00 1f ac     icbi       0,r3
        00010274 4e 80 00 20     blr

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined ICSync()
             undefined         r3:1           <RETURN>
                             ICSync                                          XREF[1]:     Entry Point(*)  
        00010278 4c 00 01 2c     isync
        0001027c 4e 80 00 20     blr



                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __LCEnable()
             undefined         r3:1           <RETURN>
                             __LCEnable                                      XREF[1]:     LCEnable:00010364(c)  
        00010280 7c a0 00 a6     mfmsr      r5
        00010284 60 a5 10 00     ori        r5,r5,0x1000
        00010288 7c a0 01 24     mtmsr      r5,0
        0001028c 3c 60 80 00     lis        r3,-0x8000
        00010290 38 80 04 00     li         r4,0x400
        00010294 7c 89 03 a6     mtspr      CTR,r4
                             LAB_00010298                                    XREF[1]:     000102a4(j)  
        00010298 7c 00 1a 2c     dcbt       0,r3
        0001029c 7c 00 18 6c     dcbst      0,r3
        000102a0 38 63 00 20     addi       r3,r3,0x20
        000102a4 42 00 ff f4     bdnz       LAB_00010298
        000102a8 7c 98 e2 a6     mfspr      r4,spr398
        000102ac 64 84 10 0f     oris       r4,r4,0x100f
        000102b0 7c 98 e3 a6     mtspr      spr398,r4
        000102b4 60 00 00 00     ori        r0,r0,0x0
        000102b8 60 00 00 00     ori        r0,r0,0x0
        000102bc 60 00 00 00     ori        r0,r0,0x0
        000102c0 60 00 00 00     ori        r0,r0,0x0
        000102c4 60 00 00 00     ori        r0,r0,0x0
        000102c8 60 00 00 00     ori        r0,r0,0x0
        000102cc 60 00 00 00     ori        r0,r0,0x0
        000102d0 60 00 00 00     ori        r0,r0,0x0
        000102d4 60 00 00 00     ori        r0,r0,0x0
        000102d8 60 00 00 00     ori        r0,r0,0x0
        000102dc 60 00 00 00     ori        r0,r0,0x0
        000102e0 60 00 00 00     ori        r0,r0,0x0
        000102e4 3c 60 e0 00     lis        r3,-0x2000
        000102e8 60 63 00 02     ori        r3,r3,0x2
        000102ec 7c 7f 83 a6     mtspr      DBAT3L,r3
        000102f0 60 63 01 fe     ori        r3,r3,0x1fe
        000102f4 7c 7e 83 a6     mtspr      DBAT3U,r3
        000102f8 4c 00 01 2c     isync
        000102fc 3c 60 e0 00     lis        r3,-0x2000
        00010300 38 c0 02 00     li         r6,0x200
        00010304 7c c9 03 a6     mtspr      CTR,r6
        00010308 38 c0 00 00     li         r6,0x0
        0001030c 10              ??         10h
        0001030d 06              ??         06h
        0001030e 1f              ??         1Fh
        0001030f ec              ??         ECh
        00010310 38              ??         38h    8
        00010311 63              ??         63h    c
        00010312 00              ??         00h
        00010313 20              ??         20h     
        00010314 42              ??         42h    B
        00010315 00              ??         00h
        00010316 ff              ??         FFh
        00010317 f8              ??         F8h
        00010318 60              ??         60h    `
        00010319 00              ??         00h
        0001031a 00              ??         00h
        0001031b 00              ??         00h
        0001031c 60              ??         60h    `
        0001031d 00              ??         00h
        0001031e 00              ??         00h
        0001031f 00              ??         00h
        00010320 60              ??         60h    `
        00010321 00              ??         00h
        00010322 00              ??         00h
        00010323 00              ??         00h
        00010324 60              ??         60h    `
        00010325 00              ??         00h
        00010326 00              ??         00h
        00010327 00              ??         00h
        00010328 60              ??         60h    `
        00010329 00              ??         00h
        0001032a 00              ??         00h
        0001032b 00              ??         00h
        0001032c 60              ??         60h    `
        0001032d 00              ??         00h
        0001032e 00              ??         00h
        0001032f 00              ??         00h
        00010330 60              ??         60h    `
        00010331 00              ??         00h
        00010332 00              ??         00h
        00010333 00              ??         00h
        00010334 60              ??         60h    `
        00010335 00              ??         00h
        00010336 00              ??         00h
        00010337 00              ??         00h
        00010338 60              ??         60h    `
        00010339 00              ??         00h
        0001033a 00              ??         00h
        0001033b 00              ??         00h
        0001033c 60              ??         60h    `
        0001033d 00              ??         00h
        0001033e 00              ??         00h
        0001033f 00              ??         00h
        00010340 60              ??         60h    `
        00010341 00              ??         00h
        00010342 00              ??         00h
        00010343 00              ??         00h
        00010344 60              ??         60h    `
        00010345 00              ??         00h
        00010346 00              ??         00h
        00010347 00              ??         00h
        00010348 4e              ??         4Eh    N
        00010349 80              ??         80h
        0001034a 00              ??         00h
        0001034b 20              ??         20h     
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCEnable()
             undefined         r3:1           <RETURN>
             undefined4        Stack[0x4]:4   local_res4                              XREF[2]:     00010350(W), 
                                                                                                   00010370(R)  
             undefined4        Stack[-0x4]:4  local_4                                 XREF[2]:     00010358(W), 
                                                                                                   00010374(R)  
             undefined4        Stack[-0x10]:4 local_10                                XREF[1]:     00010354(W)  
                             LCEnable                                        XREF[3]:     Entry Point(*), 
                                                                                          LCAlloc:000104e8(c), 
                                                                                          LCAllocNoInvalidate:000105b0(c)  
        0001034c 7c 08 02 a6     mfspr      r0,LR
        00010350 90 01 00 04     stw        r0,local_res4(r1)
        00010354 94 21 ff f0     stwu       r1,local_10(r1)
        00010358 93 e1 00 0c     stw        r31,local_4(r1)
        0001035c 48 00 0c a5     bl         <EXTERNAL>::OSDisableInterrupts                  undefined OSDisableInterrupts()
        00010360 7c 7f 1b 78     or         r31,r3,r3
        00010364 4b ff ff 1d     bl         __LCEnable                                       undefined __LCEnable()
        00010368 7f e3 fb 78     or         r3,r31,r31
        0001036c 48 00 0c 99     bl         <EXTERNAL>::OSRestoreInterrupts                  undefined OSRestoreInterrupts()
        00010370 80 01 00 14     lwz        r0,local_res4(r1)
        00010374 83 e1 00 0c     lwz        r31,local_4(r1)
        00010378 38 21 00 10     addi       r1,r1,0x10
        0001037c 7c 08 03 a6     mtspr      LR,r0
        00010380 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCDisable()
             undefined         r3:1           <RETURN>
                             LCDisable                                       XREF[1]:     Entry Point(*)  
        00010384 3c 60 e0 00     lis        r3,-0x2000
        00010388 38 80 02 00     li         r4,0x200
        0001038c 7c 89 03 a6     mtspr      CTR,r4
                             LAB_00010390                                    XREF[1]:     00010398(j)  
        00010390 7c 00 1b ac     dcbi       0,r3
        00010394 38 63 00 20     addi       r3,r3,0x20
        00010398 42 00 ff f8     bdnz       LAB_00010390
        0001039c 7c 98 e2 a6     mfspr      r4,spr398
        000103a0 54 84 01 04     rlwinm     r4,r4,0x0,0x4,0x2
        000103a4 7c 98 e3 a6     mtspr      spr398,r4
        000103a8 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCAllocTags()
             undefined         r3:1           <RETURN>
                             LCAllocTags                                     XREF[3]:     Entry Point(*), 
                                                                                          LCAlloc:000104f8(c), 
                                                                                          LCAllocNoInvalidate:000105c0(c)  
        000103c0 7c c8 02 a6     mfspr      r6,LR
        000103c4 28 05 00 00     cmplwi     r5,0x0
        000103c8 40 81 00 30     ble        LAB_000103f8
        000103cc 7c a9 03 a6     mtspr      CTR,r5
        000103d0 2c 03 00 00     cmpwi      r3,0x0
        000103d4 41 82 00 18     beq        LAB_000103ec
        000103d8 7c 00 23 ac     dcbi       0,r4
        000103dc 10              ??         10h
        000103dd 00              ??         00h
        000103de 27              ??         27h    '
        000103df ec              ??         ECh
        000103e0 38              ??         38h    8
        000103e1 84              ??         84h
        000103e2 00              ??         00h
        000103e3 20              ??         20h     
        000103e4 42              ??         42h    B
        000103e5 00              ??         00h
        000103e6 ff              ??         FFh
        000103e7 f4              ??         F4h
        000103e8 48              ??         48h    H
        000103e9 00              ??         00h
        000103ea 00              ??         00h
        000103eb 10              ??         10h
                             LAB_000103ec                                    XREF[1]:     LCAllocTags:000103d4(j)  
        000103ec 10              ??         10h
        000103ed 00              ??         00h
        000103ee 27              ??         27h    '
        000103ef ec              ??         ECh
        000103f0 38              ??         38h    8
        000103f1 84              ??         84h
        000103f2 00              ??         00h
        000103f3 20              ??         20h     
        000103f4 42              ??         42h    B
        000103f5 00              ??         00h
        000103f6 ff              ??         FFh
        000103f7 f8              ??         F8h
                             LAB_000103f8                                    XREF[1]:     000103c8(j)  
        000103f8 7c c8 03 a6     mtspr      LR,r6
        000103fc 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCLoadBlocks()
             undefined         r3:1           <RETURN>
                             LCLoadBlocks                                    XREF[3]:     Entry Point(*), 
                                                                                          LCLoadData:00010690(c), 
                                                                                          LCLoadData:000106a8(c)  
        00010400 54 a6 f6 fe     rlwinm     r6,r5,0x1e,0x1b,0x1f
        00010404 54 84 01 3e     rlwinm     r4,r4,0x0,0x4,0x1f
        00010408 7c c6 23 78     or         r6,r6,r4
        0001040c 7c da e3 a6     mtspr      spr39a,r6
        00010410 54 a6 17 3a     rlwinm     r6,r5,0x2,0x1c,0x1d
        00010414 7c c6 1b 78     or         r6,r6,r3
        00010418 60 c6 00 12     ori        r6,r6,0x12
        0001041c 7c db e3 a6     mtspr      spr39b,r6
        00010420 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCStoreBlocks()
             undefined         r3:1           <RETURN>
                             LCStoreBlocks                                   XREF[3]:     Entry Point(*), 
                                                                                          LCStoreData:00010790(c), 
                                                                                          LCStoreData:000107a8(c)  
        00010424 54 a6 f6 fe     rlwinm     r6,r5,0x1e,0x1b,0x1f
        00010428 54 63 01 3e     rlwinm     r3,r3,0x0,0x4,0x1f
        0001042c 7c c6 1b 78     or         r6,r6,r3
        00010430 7c da e3 a6     mtspr      spr39a,r6
        00010434 54 a6 17 3a     rlwinm     r6,r5,0x2,0x1c,0x1d
        00010438 7c c6 23 78     or         r6,r6,r4
        0001043c 60 c6 00 02     ori        r6,r6,0x2
        00010440 7c db e3 a6     mtspr      spr39b,r6
        00010444 4e 80 00 20     blr

void LCAlloc(uint param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = PPCMfhid2();
  if ((param_1 & 0x1f) != 0) {
    OSPanic(...data.0,0x530,@29);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x532,@30);
  }
  if ((uVar1 & 0x10000000) == 0) {
    LCEnable();
  }
  LCAllocTags(1,param_1,param_2 >> 5);
  return;
}

void LCAllocNoInvalidate(uint param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = PPCMfhid2();
  if ((param_1 & 0x1f) != 0) {
    OSPanic(...data.0,0x55f,@34);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x561,@35);
  }
  if ((uVar1 & 0x10000000) == 0) {
    LCEnable();
  }
  LCAllocTags(0,param_1,param_2 >> 5);
  return;
}

uint LCLoadData(uint param_1,uint param_2,int param_3)
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_3 + 0x1fU >> 5;
  uVar1 = uVar2 + 0x7f;
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x59b,@44);
  }
  if ((param_1 & 0x1f) != 0) {
    OSPanic(...data.0,0x59d,@45);
  }
  while (uVar2 != 0) {
    if (uVar2 < 0x80) {
      LCLoadBlocks(param_1,param_2,uVar2);
      uVar2 = 0;
    }
    else {
      LCLoadBlocks(param_1,param_2,0);
      uVar2 = uVar2 - 0x80;
      param_1 = param_1 + 0x1000;
      param_2 = param_2 + 0x1000;
    }
  }
  return uVar1 >> 7;
}

uint LCStoreData(uint param_1,uint param_2,int param_3)
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_3 + 0x1fU >> 5;
  uVar1 = uVar2 + 0x7f;
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x5df,@54);
  }
  if ((param_1 & 0x1f) != 0) {
    OSPanic(...data.0,0x5e1,@55);
  }
  while (uVar2 != 0) {
    if (uVar2 < 0x80) {
      LCStoreBlocks(param_1,param_2,uVar2);
      uVar2 = 0;
    }
    else {
      LCStoreBlocks(param_1,param_2,0);
      uVar2 = uVar2 - 0x80;
      param_1 = param_1 + 0x1000;
      param_2 = param_2 + 0x1000;
    }
  }
  return uVar1 >> 7;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCQueueLength()
             undefined         r3:1           <RETURN>
                             LCQueueLength                                   XREF[1]:     Entry Point(*)  
        000107d8 7c 98 e2 a6     mfspr      r4,spr398
        000107dc 54 83 47 3e     rlwinm     r3,r4,0x8,0x1c,0x1f
        000107e0 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCQueueWait()
             undefined         r3:1           <RETURN>
                             LCQueueWait                                     XREF[1]:     Entry Point(*)  
        000107e4 38 63 00 01     addi       r3,r3,0x1
                             LAB_000107e8                                    XREF[1]:     000107f4(j)  
        000107e8 7c 98 e2 a6     mfspr      r4,spr398
        000107ec 54 84 47 3e     rlwinm     r4,r4,0x8,0x1c,0x1f
        000107f0 7d 04 18 00     cmpw       cr2,r4,r3
        000107f4 40 88 ff f4     bge        cr2,LAB_000107e8
        000107f8 4e 80 00 20     blr


                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined LCFlushQueue()
             undefined         r3:1           <RETURN>
             undefined4        Stack[0x4]:4   local_res4                              XREF[2]:     00010800(W), 
                                                                                                   00010834(R)  
             undefined4        Stack[-0x8]:4  local_8                                 XREF[2,2]:   0001080c(W), 
                                                                                                   00010828(R), 
                                                                                                   00010814(R), 
                                                                                                   0001081c(W)  
             undefined4        Stack[-0x10]:4 local_10                                XREF[1]:     00010804(W)  
                             LCFlushQueue                                    XREF[1]:     Entry Point(*)  
        000107fc 7c 08 02 a6     mfspr      r0,LR
        00010800 90 01 00 04     stw        r0,local_res4(r1)
        00010804 94 21 ff f0     stwu       r1,local_10(r1)
        00010808 38 00 00 00     li         r0,0x0
        0001080c 90 01 00 08     stw        r0,local_8(r1)
        00010810 38 60 00 01     li         r3,0x1
        00010814 88 01 00 0b     lbz        r0,local_8+0x3(r1)
        00010818 50 60 07 fe     rlwimi     r0,r3,0x0,0x1f,0x1f
        0001081c 98 01 00 0b     stb        r0,local_8+0x3(r1)
        00010820 38 60 00 00     li         r3,0x0
        00010824 48 00 07 ed     bl         <EXTERNAL>::PPCMtdmaU                            undefined PPCMtdmaU()
        00010828 80 61 00 08     lwz        r3,local_8(r1)
        0001082c 48 00 07 e9     bl         <EXTERNAL>::PPCMtdmaL                            undefined PPCMtdmaL()
        00010830 48 00 07 e9     bl         <EXTERNAL>::PPCSync                              undefined PPCSync()
        00010834 80 01 00 14     lwz        r0,local_res4(r1)
        00010838 38 21 00 10     addi       r1,r1,0x10
        0001083c 7c 08 03 a6     mtspr      LR,r0
        00010840 4e 80 00 20     blr

void L2Init(void)
{
  undefined4 uVar1;
  
  uVar1 = PPCMfmsr();
  sync(0);
  PPCMtmsr(0x30);
  sync(0);
  L2Disable();
  L2GlobalInvalidate();
  PPCMtmsr(uVar1);
  return;
}

void L2Enable(void)
{
  uint uVar1;
  
  uVar1 = PPCMfl2cr();
  PPCMtl2cr(uVar1 & 0xffdfffff | 0x80000000);
  return;
}

void L2Disable(void)
{
  uint uVar1;
  
  sync(0);
  uVar1 = PPCMfl2cr();
  PPCMtl2cr(uVar1 & 0x7fffffff);
  sync(0);
  return;
}

void L2GlobalInvalidate(void)
{
  uint uVar1;
  
  L2Disable();
  uVar1 = PPCMfl2cr();
  PPCMtl2cr(uVar1 | 0x200000);
  do {
    uVar1 = PPCMfl2cr();
  } while ((uVar1 & 1) != 0);
  uVar1 = PPCMfl2cr();
  PPCMtl2cr(uVar1 & 0xffdfffff);
  while (uVar1 = PPCMfl2cr(), (uVar1 & 1) != 0) {
    DBPrintf(@70);
  }
  return;
}

void L2SetDataOnly(int param_1)
{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = PPCMfl2cr();
    PPCMtl2cr(uVar1 & 0xffbfffff);
  }
  else {
    uVar1 = PPCMfl2cr();
    PPCMtl2cr(uVar1 | 0x400000);
  }
  return;
}

void L2SetWriteThrough(int param_1)
{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = PPCMfl2cr();
    PPCMtl2cr(uVar1 & 0xfff7ffff);
  }
  else {
    uVar1 = PPCMfl2cr();
    PPCMtl2cr(uVar1 | 0x80000);
  }
  return;
}

void DMAErrorHandler(undefined4 param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = PPCMfhid2();
  OSReport(@91);
  OSReport(@92,uVar1,*(undefined4 *)(param_2 + 0x19c));
  if (((uVar1 & 0xf00000) == 0) || ((*(uint *)(param_2 + 0x19c) & 0x200000) == 0)) {
    OSReport(@93);
    OSDumpContext(param_2);
    PPCHalt();
  }
  OSReport(@94);
  OSReport(@95);
  if ((uVar1 & 0x800000) != 0) {
    OSReport(@96);
  }
  if ((uVar1 & 0x400000) != 0) {
    OSReport(@97);
  }
  if ((uVar1 & 0x200000) != 0) {
    OSReport(@98);
  }
  if ((uVar1 & 0x100000) != 0) {
    OSReport(@99);
  }
  PPCMthid2(uVar1);
  return;
}

void __OSCacheInit(void)
{
  uint uVar1;
  
  uVar1 = PPCMfhid0();
  if ((uVar1 & 0x8000) == 0) {
    ICEnable();
    DBPrintf(@107);
  }
  uVar1 = PPCMfhid0();
  if ((uVar1 & 0x4000) == 0) {
    DCEnable();
    DBPrintf(@108);
  }
  uVar1 = PPCMfl2cr();
  if ((uVar1 & 0x80000000) == 0) {
    L2Init();
    L2Enable();
    DBPrintf(@109);
  }
  OSSetErrorHandler(1,DMAErrorHandler);
  DBPrintf(@110);
  return;
}
