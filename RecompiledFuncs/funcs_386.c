#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800128_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: addiu       $a1, $zero, 0xA21
    ctx->r5 = ADD32(0, 0XA21);
    // 0x80800134: jal         0x80800000
    // 0x80800138: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    func_80800000_chdrawbridgeswitches(rdram, ctx);
        goto after_0;
    // 0x80800138: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_0:
    // 0x8080013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void func_80800618_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080061C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800628: jal         0x80102424
    // 0x8080062C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080062C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800630: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800634: addiu       $at, $zero, 0x3A3
    ctx->r1 = ADD32(0, 0X3A3);
    // 0x80800638: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080063C: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x80800640: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80800644: beq         $t7, $at, L_80800660
    if (ctx->r15 == ctx->r1) {
        // 0x80800648: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1092, 0X1508) << 16);
            goto L_80800660;
    }
    // 0x80800648: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1092, 0X1508) << 16);
    // 0x8080064C: addiu       $at, $zero, 0x3A4
    ctx->r1 = ADD32(0, 0X3A4);
    // 0x80800650: beq         $t7, $at, L_80800670
    if (ctx->r15 == ctx->r1) {
        // 0x80800654: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800670;
    }
    // 0x80800654: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800658: b           L_80800694
    // 0x8080065C: nop

        goto L_80800694;
    // 0x8080065C: nop

L_80800660:
    // 0x80800660: jal         0x800EE7F8
    // 0x80800664: addiu       $a1, $a1, 0x1508
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1092, 0X1508));
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800664: addiu       $a1, $a1, 0x1508
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1092, 0X1508));
    after_1:
    // 0x80800668: b           L_80800694
    // 0x8080066C: nop

        goto L_80800694;
    // 0x8080066C: nop

L_80800670:
    // 0x80800670: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1092, 0X1514) << 16);
    // 0x80800674: jal         0x800EE7F8
    // 0x80800678: addiu       $a1, $a1, 0x1514
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1092, 0X1514));
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800678: addiu       $a1, $a1, 0x1514
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1092, 0X1514));
    after_2:
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: jal         0x801020DC
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801020DC(rdram, ctx);
        goto after_3;
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x80101DAC
    // 0x80800690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80101DAC(rdram, ctx);
        goto after_4;
    // 0x80800690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80800694:
    // 0x80800694: jal         0x80088848
    // 0x80800698: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800698: nop

    after_5:
    // 0x8080069C: bne         $v0, $zero, L_808006DC
    if (ctx->r2 != 0) {
        // 0x808006A0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1092, 0X1298) << 16);
            goto L_808006DC;
    }
    // 0x808006A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X1298) << 16);
    // 0x808006A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808006A8: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x808006AC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x808006B0: jal         0x800DC178
    // 0x808006B4: lwc1        $f14, 0x1298($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X1298));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808006B4: lwc1        $f14, 0x1298($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X1298));
    after_6:
    // 0x808006B8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808006BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808006C4: jal         0x800DC178
    // 0x808006C8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808006C8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x808006CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006D4: jal         0x800EF1B8
    // 0x808006D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x808006D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
L_808006DC:
    // 0x808006DC: jal         0x80103014
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_9;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006F0: jr          $ra
    // 0x808006F4: nop

    return;
    // 0x808006F4: nop

;}
RECOMP_FUNC void func_80802500_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802500: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802508: jal         0x80100094
    // 0x8080250C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080250C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802510: lbu         $t6, 0x12B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12B);
    // 0x80802514: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802518: beql        $t6, $zero, L_80802530
    if (ctx->r14 == 0) {
        // 0x8080251C: sb          $zero, 0x12B($v1)
        MEM_B(0X12B, ctx->r3) = 0;
            goto L_80802530;
    }
    goto skip_0;
    // 0x8080251C: sb          $zero, 0x12B($v1)
    MEM_B(0X12B, ctx->r3) = 0;
    skip_0:
    // 0x80802520: jal         0x80085710
    // 0x80802524: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80802524: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802528: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080252C: sb          $zero, 0x12B($v1)
    MEM_B(0X12B, ctx->r3) = 0;
L_80802530:
    // 0x80802530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802538: jr          $ra
    // 0x8080253C: nop

    return;
    // 0x8080253C: nop

;}
RECOMP_FUNC void chscorepoints_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002A0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808002A4: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x808002A8: or          $t7, $a3, $zero
    ctx->r15 = ctx->r7 | 0;
    // 0x808002AC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x808002B0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808002B4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x808002B8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808002C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808002C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002CC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808002D4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808002D8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808002DC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808002E0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808002E4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808002E8: jal         0x800EFA4C
    // 0x808002EC: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x808002EC: nop

    after_0:
    // 0x808002F0: addiu       $a0, $zero, 0x14E
    ctx->r4 = ADD32(0, 0X14E);
    // 0x808002F4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808002F8: jal         0x80108474
    // 0x808002FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808002FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800300: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800304: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800308: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080030C: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
    // 0x80800310: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80800314: sw          $a0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r4;
    // 0x80800318: jal         0x800D3DA4
    // 0x8080031C: sw          $t0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r8;
    func_800D3DA4(rdram, ctx);
        goto after_2;
    // 0x8080031C: sw          $t0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r8;
    after_2:
    // 0x80800320: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800324: addiu       $t1, $v0, 0xC29
    ctx->r9 = ADD32(ctx->r2, 0XC29);
    // 0x80800328: sw          $t1, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r9;
    // 0x8080032C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800330: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800334: jr          $ra
    // 0x80800338: nop

    return;
    // 0x80800338: nop

;}
RECOMP_FUNC void bapulse_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x80800050: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800054: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800058: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8080005C: lw          $t7, 0xE8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XE8);
    // 0x80800060: swc1        $f12, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f12.u32l;
    // 0x80800064: lw          $t8, 0xE8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XE8);
    // 0x80800068: jr          $ra
    // 0x8080006C: swc1        $f14, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f14.u32l;
    return;
    // 0x8080006C: swc1        $f14, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_800CDFA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDFA8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800CDFAC: addiu       $v1, $v1, -0x5090
    ctx->r3 = ADD32(ctx->r3, -0X5090);
    // 0x800CDFB0: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800CDFB4: lbu         $t7, 0x80($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X80);
    // 0x800CDFB8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800CDFBC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800CDFC0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CDFC4: jr          $ra
    // 0x800CDFC8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    return;
    // 0x800CDFC8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800CDFCC: nop

;}
RECOMP_FUNC void _bsbflip_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082930: syscall     21
    recomp_syscall_handler(rdram, ctx, 0x80082930);
    return;
    // 0x80082934: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800FDC58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_800FDC58");
    // 0x800FDC58: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800FDC5C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800FDC60: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FDC64: addiu       $s1, $s1, 0x59C0
    ctx->r17 = ADD32(ctx->r17, 0X59C0);
    // 0x800FDC68: lbu         $t7, 0x41($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X41);
    // 0x800FDC6C: lbu         $t6, 0xF($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XF);
    // 0x800FDC70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FDC74: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800FDC78: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800FDC7C: bne         $t7, $zero, L_800FE3D8
    if (ctx->r15 != 0) {
        // 0x800FDC80: sw          $t6, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r14;
            goto L_800FE3D8;
    }
    // 0x800FDC80: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x800FDC84: lbu         $t8, 0x16($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X16);
    // 0x800FDC88: beql        $t8, $zero, L_800FE3DC
    if (ctx->r24 == 0) {
        // 0x800FDC8C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800FE3DC;
    }
    goto skip_0;
    // 0x800FDC8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800FDC90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FDC94: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800FDC98: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800FDC9C: nop

    // 0x800FDCA0: bc1f        L_800FDCBC
    if (!c1cs) {
        // 0x800FDCA4: nop
    
            goto L_800FDCBC;
    }
    // 0x800FDCA4: nop

    // 0x800FDCA8: jal         0x800D8FF8
    // 0x800FDCAC: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800FDCAC: nop

    after_0:
    // 0x800FDCB0: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800FDCB4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800FDCB8: swc1        $f10, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f10.u32l;
L_800FDCBC:
    // 0x800FDCBC: jal         0x80090200
    // 0x800FDCC0: nop

    func_80090200(rdram, ctx);
        goto after_1;
    // 0x800FDCC0: nop

    after_1:
    // 0x800FDCC4: beql        $v0, $zero, L_800FE3DC
    if (ctx->r2 == 0) {
        // 0x800FDCC8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800FE3DC;
    }
    goto skip_1;
    // 0x800FDCC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800FDCCC: jal         0x8008FF94
    // 0x800FDCD0: nop

    func_8008FF94(rdram, ctx);
        goto after_2;
    // 0x800FDCD0: nop

    after_2:
    // 0x800FDCD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FDCD8: bne         $v0, $at, L_800FDCE8
    if (ctx->r2 != ctx->r1) {
        // 0x800FDCDC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800FDCE8;
    }
    // 0x800FDCDC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800FDCE0: b           L_800FDCEC
    // 0x800FDCE4: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
        goto L_800FDCEC;
    // 0x800FDCE4: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
L_800FDCE8:
    // 0x800FDCE8: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
L_800FDCEC:
    // 0x800FDCEC: lbu         $t0, 0x17($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X17);
    // 0x800FDCF0: bne         $t0, $zero, L_800FE0F4
    if (ctx->r8 != 0) {
        // 0x800FDCF4: nop
    
            goto L_800FE0F4;
    }
    // 0x800FDCF4: nop

    // 0x800FDCF8: lh          $v0, 0x22($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X22);
    // 0x800FDCFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FDD00: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800FDD04: beq         $v0, $at, L_800FDD28
    if (ctx->r2 == ctx->r1) {
        // 0x800FDD08: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_800FDD28;
    }
    // 0x800FDD08: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800FDD0C: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x800FDD10: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800FDD14: addiu       $t2, $t2, 0x3E84
    ctx->r10 = ADD32(ctx->r10, 0X3E84);
    // 0x800FDD18: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800FDD1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDD20: b           L_800FDD30
    // 0x800FDD24: sw          $t3, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r11;
        goto L_800FDD30;
    // 0x800FDD24: sw          $t3, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r11;
L_800FDD28:
    // 0x800FDD28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDD2C: sw          $zero, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = 0;
L_800FDD30:
    // 0x800FDD30: jal         0x8008FE68
    // 0x800FDD34: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_8008FE68(rdram, ctx);
        goto after_3;
    // 0x800FDD34: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_3:
    // 0x800FDD38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FDD3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDD40: addiu       $v0, $v0, 0x5A3F
    ctx->r2 = ADD32(ctx->r2, 0X5A3F);
    // 0x800FDD44: addiu       $v1, $v1, 0x5A3C
    ctx->r3 = ADD32(ctx->r3, 0X5A3C);
L_800FDD48:
    // 0x800FDD48: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FDD4C: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800FDD50: bne         $at, $zero, L_800FDD48
    if (ctx->r1 != 0) {
        // 0x800FDD54: sb          $zero, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = 0;
            goto L_800FDD48;
    }
    // 0x800FDD54: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x800FDD58: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FDD5C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800FDD60: addiu       $a2, $a2, 0x59EC
    ctx->r6 = ADD32(ctx->r6, 0X59EC);
    // 0x800FDD64: addiu       $a1, $a1, 0x59E8
    ctx->r5 = ADD32(ctx->r5, 0X59E8);
    // 0x800FDD68: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800FDD6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800FDD70: jal         0x800CCEF4
    // 0x800FDD74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800CCEF4(rdram, ctx);
        goto after_4;
    // 0x800FDD74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x800FDD78: beql        $v0, $zero, L_800FDFF8
    if (ctx->r2 == 0) {
        // 0x800FDD7C: lh          $t7, 0x20($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X20);
            goto L_800FDFF8;
    }
    goto skip_2;
    // 0x800FDD7C: lh          $t7, 0x20($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X20);
    skip_2:
    // 0x800FDD80: jal         0x800CBBE0
    // 0x800FDD84: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    func_800CBBE0(rdram, ctx);
        goto after_5;
    // 0x800FDD84: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    after_5:
    // 0x800FDD88: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FDD8C: jal         0x800CBC00
    // 0x800FDD90: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    func_800CBC00(rdram, ctx);
        goto after_6;
    // 0x800FDD90: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    after_6:
    // 0x800FDD94: bne         $v0, $zero, L_800FDDBC
    if (ctx->r2 != 0) {
        // 0x800FDD98: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_800FDDBC;
    }
    // 0x800FDD98: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800FDD9C: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x800FDDA0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800FDDA4: addiu       $t5, $t5, 0x3E84
    ctx->r13 = ADD32(ctx->r13, 0X3E84);
    // 0x800FDDA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800FDDAC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800FDDB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDDB4: b           L_800FDFF4
    // 0x800FDDB8: sw          $t6, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r14;
        goto L_800FDFF4;
    // 0x800FDDB8: sw          $t6, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r14;
L_800FDDBC:
    // 0x800FDDBC: jal         0x800CBBE0
    // 0x800FDDC0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    func_800CBBE0(rdram, ctx);
        goto after_7;
    // 0x800FDDC0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    after_7:
    // 0x800FDDC4: sltiu       $at, $v0, 0x12
    ctx->r1 = ctx->r2 < 0X12 ? 1 : 0;
    // 0x800FDDC8: beq         $at, $zero, L_800FDFF4
    if (ctx->r1 == 0) {
        // 0x800FDDCC: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800FDFF4;
    }
    // 0x800FDDCC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800FDDD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FDDD4: addu        $at, $at, $t7
    gpr jr_addend_800FDDDC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800FDDD8: lw          $t7, 0x61C8($at)
    ctx->r15 = ADD32(ctx->r1, 0X61C8);
    // 0x800FDDDC: jr          $t7
    // 0x800FDDE0: nop

    switch (jr_addend_800FDDDC >> 2) {
        case 0: goto L_800FDDE4; break;
        case 1: goto L_800FDE1C; break;
        case 2: goto L_800FDFF4; break;
        case 3: goto L_800FDFF4; break;
        case 4: goto L_800FDFF4; break;
        case 5: goto L_800FDFF4; break;
        case 6: goto L_800FDFF4; break;
        case 7: goto L_800FDE54; break;
        case 8: goto L_800FDE64; break;
        case 9: goto L_800FDE70; break;
        case 10: goto L_800FDFF4; break;
        case 11: goto L_800FDFF4; break;
        case 12: goto L_800FDEA8; break;
        case 13: goto L_800FDEC8; break;
        case 14: goto L_800FDED8; break;
        case 15: goto L_800FDF04; break;
        case 16: goto L_800FDF3C; break;
        case 17: goto L_800FDFA4; break;
        default: switch_error(__func__, 0x800FDDDC, 0x801261C8);
    }
    // 0x800FDDE0: nop

L_800FDDE4:
    // 0x800FDDE4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDDE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FDDEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDDF0: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDDF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDDF8: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x800FDDFC: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800FDE00: jal         0x800FCFB0
    // 0x800FDE04: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_8;
    // 0x800FDE04: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x800FDE08: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800FDE0C: addiu       $t8, $t8, 0x3FC8
    ctx->r24 = ADD32(ctx->r24, 0X3FC8);
    // 0x800FDE10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDE14: b           L_800FDFF4
    // 0x800FDE18: sw          $t8, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r24;
        goto L_800FDFF4;
    // 0x800FDE18: sw          $t8, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r24;
L_800FDE1C:
    // 0x800FDE1C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDE20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FDE24: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDE28: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDE2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDE30: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x800FDE34: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800FDE38: jal         0x800FCFB0
    // 0x800FDE3C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_9;
    // 0x800FDE3C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x800FDE40: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800FDE44: addiu       $t9, $t9, 0x3FC8
    ctx->r25 = ADD32(ctx->r25, 0X3FC8);
    // 0x800FDE48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDE4C: b           L_800FDFF4
    // 0x800FDE50: sw          $t9, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r25;
        goto L_800FDFF4;
    // 0x800FDE50: sw          $t9, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r25;
L_800FDE54:
    // 0x800FDE54: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800FDE58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDE5C: b           L_800FDFF4
    // 0x800FDE60: sb          $t0, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = ctx->r8;
        goto L_800FDFF4;
    // 0x800FDE60: sb          $t0, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = ctx->r8;
L_800FDE64:
    // 0x800FDE64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDE68: b           L_800FDFF4
    // 0x800FDE6C: sb          $zero, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = 0;
        goto L_800FDFF4;
    // 0x800FDE6C: sb          $zero, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = 0;
L_800FDE70:
    // 0x800FDE70: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDE74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FDE78: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDE7C: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDE80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDE84: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x800FDE88: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800FDE8C: jal         0x800FCFB0
    // 0x800FDE90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_10;
    // 0x800FDE90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x800FDE94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800FDE98: addiu       $t1, $t1, 0x4064
    ctx->r9 = ADD32(ctx->r9, 0X4064);
    // 0x800FDE9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDEA0: b           L_800FDFF4
    // 0x800FDEA4: sw          $t1, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r9;
        goto L_800FDFF4;
    // 0x800FDEA4: sw          $t1, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r9;
L_800FDEA8:
    // 0x800FDEA8: jal         0x800DA298
    // 0x800FDEAC: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x800FDEAC: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_11:
    // 0x800FDEB0: beq         $v0, $zero, L_800FDFF4
    if (ctx->r2 == 0) {
        // 0x800FDEB4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800FDFF4;
    }
    // 0x800FDEB4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800FDEB8: addiu       $t2, $t2, 0x41CC
    ctx->r10 = ADD32(ctx->r10, 0X41CC);
    // 0x800FDEBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDEC0: b           L_800FDFF4
    // 0x800FDEC4: sw          $t2, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r10;
        goto L_800FDFF4;
    // 0x800FDEC4: sw          $t2, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r10;
L_800FDEC8:
    // 0x800FDEC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800FDECC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDED0: b           L_800FDFF4
    // 0x800FDED4: swc1        $f6, 0x5A44($at)
    MEM_W(0X5A44, ctx->r1) = ctx->f6.u32l;
        goto L_800FDFF4;
    // 0x800FDED4: swc1        $f6, 0x5A44($at)
    MEM_W(0X5A44, ctx->r1) = ctx->f6.u32l;
L_800FDED8:
    // 0x800FDED8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDEDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FDEE0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDEE4: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDEE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDEEC: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x800FDEF0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800FDEF4: jal         0x800FCFB0
    // 0x800FDEF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_12;
    // 0x800FDEF8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x800FDEFC: b           L_800FDFF8
    // 0x800FDF00: lh          $t7, 0x20($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X20);
        goto L_800FDFF8;
    // 0x800FDF00: lh          $t7, 0x20($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X20);
L_800FDF04:
    // 0x800FDF04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDF08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FDF0C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDF10: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDF18: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x800FDF1C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800FDF20: jal         0x800FCFB0
    // 0x800FDF24: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_13;
    // 0x800FDF24: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x800FDF28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800FDF2C: addiu       $t3, $t3, 0x419C
    ctx->r11 = ADD32(ctx->r11, 0X419C);
    // 0x800FDF30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDF34: b           L_800FDFF4
    // 0x800FDF38: sw          $t3, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r11;
        goto L_800FDFF4;
    // 0x800FDF38: sw          $t3, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r11;
L_800FDF3C:
    // 0x800FDF3C: jal         0x800DA298
    // 0x800FDF40: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x800FDF40: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_14:
    // 0x800FDF44: beq         $v0, $zero, L_800FDF90
    if (ctx->r2 == 0) {
        // 0x800FDF48: nop
    
            goto L_800FDF90;
    }
    // 0x800FDF48: nop

    // 0x800FDF4C: jal         0x800DA298
    // 0x800FDF50: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x800FDF50: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_15:
    // 0x800FDF54: bne         $v0, $zero, L_800FDF90
    if (ctx->r2 != 0) {
        // 0x800FDF58: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FDF90;
    }
    // 0x800FDF58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDF5C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDF60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FDF64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDF68: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDF6C: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x800FDF70: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800FDF74: jal         0x800FCFB0
    // 0x800FDF78: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_16;
    // 0x800FDF78: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x800FDF7C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800FDF80: addiu       $t4, $t4, 0x4010
    ctx->r12 = ADD32(ctx->r12, 0X4010);
    // 0x800FDF84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDF88: b           L_800FDFF4
    // 0x800FDF8C: sw          $t4, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r12;
        goto L_800FDFF4;
    // 0x800FDF8C: sw          $t4, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r12;
L_800FDF90:
    // 0x800FDF90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800FDF94: addiu       $t5, $t5, 0x4124
    ctx->r13 = ADD32(ctx->r13, 0X4124);
    // 0x800FDF98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDF9C: b           L_800FDFF4
    // 0x800FDFA0: sw          $t5, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r13;
        goto L_800FDFF4;
    // 0x800FDFA0: sw          $t5, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r13;
L_800FDFA4:
    // 0x800FDFA4: jal         0x800DA298
    // 0x800FDFA8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x800FDFA8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_17:
    // 0x800FDFAC: beql        $v0, $zero, L_800FDFF8
    if (ctx->r2 == 0) {
        // 0x800FDFB0: lh          $t7, 0x20($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X20);
            goto L_800FDFF8;
    }
    goto skip_3;
    // 0x800FDFB0: lh          $t7, 0x20($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X20);
    skip_3:
    // 0x800FDFB4: jal         0x800DA298
    // 0x800FDFB8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_18;
    // 0x800FDFB8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_18:
    // 0x800FDFBC: bne         $v0, $zero, L_800FDFF4
    if (ctx->r2 != 0) {
        // 0x800FDFC0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FDFF4;
    }
    // 0x800FDFC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDFC4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDFC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FDFCC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDFD0: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDFD4: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x800FDFD8: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800FDFDC: jal         0x800FCFB0
    // 0x800FDFE0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_19;
    // 0x800FDFE0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_19:
    // 0x800FDFE4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800FDFE8: addiu       $t6, $t6, 0x4010
    ctx->r14 = ADD32(ctx->r14, 0X4010);
    // 0x800FDFEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDFF0: sw          $t6, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r14;
L_800FDFF4:
    // 0x800FDFF4: lh          $t7, 0x20($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X20);
L_800FDFF8:
    // 0x800FDFF8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x800FDFFC: beq         $t7, $zero, L_800FE00C
    if (ctx->r15 == 0) {
        // 0x800FE000: nop
    
            goto L_800FE00C;
    }
    // 0x800FE000: nop

    // 0x800FE004: jal         0x800FD2A0
    // 0x800FE008: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    func_800FD2A0(rdram, ctx);
        goto after_20;
    // 0x800FE008: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_20:
L_800FE00C:
    // 0x800FE00C: jal         0x800FDBB8
    // 0x800FE010: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_800FDBB8(rdram, ctx);
        goto after_21;
    // 0x800FE010: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_21:
    // 0x800FE014: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FE018: lw          $t8, 0x5A40($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5A40);
    // 0x800FE01C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FE020: addiu       $s0, $s0, 0x5A20
    ctx->r16 = ADD32(ctx->r16, 0X5A20);
    // 0x800FE024: blez        $t8, L_800FE0F4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800FE028: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800FE0F4;
    }
    // 0x800FE028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800FE02C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800FE030:
    // 0x800FE030: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800FE034: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FE038: addiu       $t9, $t9, 0x5A3C
    ctx->r25 = ADD32(ctx->r25, 0X5A3C);
    // 0x800FE03C: beq         $a0, $zero, L_800FE0D8
    if (ctx->r4 == 0) {
        // 0x800FE040: addu        $v1, $a3, $t9
        ctx->r3 = ADD32(ctx->r7, ctx->r25);
            goto L_800FE0D8;
    }
    // 0x800FE040: addu        $v1, $a3, $t9
    ctx->r3 = ADD32(ctx->r7, ctx->r25);
    // 0x800FE044: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x800FE048: beq         $t0, $zero, L_800FE06C
    if (ctx->r8 == 0) {
        // 0x800FE04C: nop
    
            goto L_800FE06C;
    }
    // 0x800FE04C: nop

    // 0x800FE050: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800FE054: jal         0x800FCCD4
    // 0x800FE058: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_800FCCD4(rdram, ctx);
        goto after_22;
    // 0x800FE058: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_22:
    // 0x800FE05C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE060: bne         $v0, $zero, L_800FE0D8
    if (ctx->r2 != 0) {
        // 0x800FE064: lw          $a3, 0x54($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X54);
            goto L_800FE0D8;
    }
    // 0x800FE064: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800FE068: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800FE06C:
    // 0x800FE06C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FE070: lwc1        $f4, 0x6210($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6210);
    // 0x800FE074: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800FE078: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FE07C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800FE080: addiu       $t3, $t3, 0x5A30
    ctx->r11 = ADD32(ctx->r11, 0X5A30);
    // 0x800FE084: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800FE088: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800FE08C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800FE090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FE094: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800FE098: jal         0x800FCAE0
    // 0x800FE09C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_800FCAE0(rdram, ctx);
        goto after_23;
    // 0x800FE09C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_23:
    // 0x800FE0A0: jal         0x800FCA90
    // 0x800FE0A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FCA90(rdram, ctx);
        goto after_24;
    // 0x800FE0A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_24:
    // 0x800FE0A8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE0AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800FE0B0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800FE0B4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800FE0B8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800FE0BC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800FE0C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FE0C4: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800FE0C8: lw          $t6, 0x5A40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5A40);
    // 0x800FE0CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE0D0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800FE0D4: sw          $t7, 0x5A40($at)
    MEM_W(0X5A40, ctx->r1) = ctx->r15;
L_800FE0D8:
    // 0x800FE0D8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800FE0DC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800FE0E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FE0E4: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800FE0E8: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800FE0EC: bne         $a3, $at, L_800FE030
    if (ctx->r7 != ctx->r1) {
        // 0x800FE0F0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800FE030;
    }
    // 0x800FE0F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800FE0F4:
    // 0x800FE0F4: jal         0x800FE914
    // 0x800FE0F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800FE914(rdram, ctx);
        goto after_25;
    // 0x800FE0F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_25:
    // 0x800FE0FC: lbu         $t0, 0x17($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X17);
    // 0x800FE100: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FE104: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FE108: bnel        $t0, $zero, L_800FE3DC
    if (ctx->r8 != 0) {
        // 0x800FE10C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800FE3DC;
    }
    goto skip_4;
    // 0x800FE10C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800FE110: lw          $v1, 0x5A04($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5A04);
    // 0x800FE114: lw          $t1, 0x5A08($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5A08);
    // 0x800FE118: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800FE11C: bnel        $t1, $v1, L_800FE14C
    if (ctx->r9 != ctx->r3) {
        // 0x800FE120: lbu         $v0, 0xF($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0XF);
            goto L_800FE14C;
    }
    goto skip_5;
    // 0x800FE120: lbu         $v0, 0xF($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XF);
    skip_5:
    // 0x800FE124: lbu         $t3, 0x10($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X10);
    // 0x800FE128: bnel        $t2, $t3, L_800FE14C
    if (ctx->r10 != ctx->r11) {
        // 0x800FE12C: lbu         $v0, 0xF($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0XF);
            goto L_800FE14C;
    }
    goto skip_6;
    // 0x800FE12C: lbu         $v0, 0xF($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XF);
    skip_6:
    // 0x800FE130: lbu         $t4, 0xF($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XF);
    // 0x800FE134: bnel        $t4, $zero, L_800FE14C
    if (ctx->r12 != 0) {
        // 0x800FE138: lbu         $v0, 0xF($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0XF);
            goto L_800FE14C;
    }
    goto skip_7;
    // 0x800FE138: lbu         $v0, 0xF($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XF);
    skip_7:
    // 0x800FE13C: lbu         $t5, 0x18($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18);
    // 0x800FE140: beql        $t5, $zero, L_800FE314
    if (ctx->r13 == 0) {
        // 0x800FE144: lbu         $t2, 0x14($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X14);
            goto L_800FE314;
    }
    goto skip_8;
    // 0x800FE144: lbu         $t2, 0x14($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X14);
    skip_8:
    // 0x800FE148: lbu         $v0, 0xF($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XF);
L_800FE14C:
    // 0x800FE14C: bne         $v0, $zero, L_800FE15C
    if (ctx->r2 != 0) {
        // 0x800FE150: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800FE15C;
    }
    // 0x800FE150: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800FE154: b           L_800FE184
    // 0x800FE158: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800FE184;
    // 0x800FE158: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800FE15C:
    // 0x800FE15C: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800FE160: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE164: sb          $t6, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r14;
    // 0x800FE168: beq         $a0, $at, L_800FE184
    if (ctx->r4 == ctx->r1) {
        // 0x800FE16C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800FE184;
    }
    // 0x800FE16C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800FE170: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x800FE174: jal         0x800FC97C
    // 0x800FE178: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800FC97C(rdram, ctx);
        goto after_26;
    // 0x800FE178: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_26:
    // 0x800FE17C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FE180: lw          $v1, 0x5A04($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5A04);
L_800FE184:
    // 0x800FE184: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800FE188: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE18C: sw          $v1, 0x5A08($at)
    MEM_W(0X5A08, ctx->r1) = ctx->r3;
    // 0x800FE190: beq         $v1, $zero, L_800FE308
    if (ctx->r3 == 0) {
        // 0x800FE194: sb          $t7, 0x10($s1)
        MEM_B(0X10, ctx->r17) = ctx->r15;
            goto L_800FE308;
    }
    // 0x800FE194: sb          $t7, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r15;
    // 0x800FE198: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800FE19C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE1A0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800FE1A4: beql        $a0, $at, L_800FE30C
    if (ctx->r4 == ctx->r1) {
        // 0x800FE1A8: lbu         $t1, 0xF($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0XF);
            goto L_800FE30C;
    }
    goto skip_9;
    // 0x800FE1A8: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
    skip_9:
    // 0x800FE1AC: beql        $t8, $zero, L_800FE264
    if (ctx->r24 == 0) {
        // 0x800FE1B0: mtc1        $s0, $f10
        ctx->f10.u32l = ctx->r16;
            goto L_800FE264;
    }
    goto skip_10;
    // 0x800FE1B0: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    skip_10:
    // 0x800FE1B4: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x800FE1B8: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800FE1BC: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FE1C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FE1C4: jal         0x800FCDE0
    // 0x800FE1C8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800FCDE0(rdram, ctx);
        goto after_27;
    // 0x800FE1C8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_27:
    // 0x800FE1CC: bne         $v0, $zero, L_800FE1DC
    if (ctx->r2 != 0) {
        // 0x800FE1D0: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_800FE1DC;
    }
    // 0x800FE1D0: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FE1D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800FE1D8: sb          $t9, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r25;
L_800FE1DC:
    // 0x800FE1DC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800FE1E0: lw          $t0, 0x5A04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5A04);
    // 0x800FE1E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE1E8: lui         $t1, 0x393
    ctx->r9 = S32(0X393 << 16);
    // 0x800FE1EC: lh          $v0, 0xA($t0)
    ctx->r2 = MEM_H(ctx->r8, 0XA);
    // 0x800FE1F0: ori         $t1, $t1, 0x8700
    ctx->r9 = ctx->r9 | 0X8700;
    // 0x800FE1F4: beql        $v0, $at, L_800FE30C
    if (ctx->r2 == ctx->r1) {
        // 0x800FE1F8: lbu         $t1, 0xF($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0XF);
            goto L_800FE30C;
    }
    goto skip_11;
    // 0x800FE1F8: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
    skip_11:
    // 0x800FE1FC: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800FE200: mflo        $t2
    ctx->r10 = lo;
    // 0x800FE204: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800FE208: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800FE20C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FE210: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FE214: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800FE218: bne         $v0, $zero, L_800FE224
    if (ctx->r2 != 0) {
        // 0x800FE21C: nop
    
            goto L_800FE224;
    }
    // 0x800FE21C: nop

    // 0x800FE220: break       7
    do_break(2148524576);
L_800FE224:
    // 0x800FE224: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE228: bne         $v0, $at, L_800FE23C
    if (ctx->r2 != ctx->r1) {
        // 0x800FE22C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800FE23C;
    }
    // 0x800FE22C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FE230: bne         $t1, $at, L_800FE23C
    if (ctx->r9 != ctx->r1) {
        // 0x800FE234: nop
    
            goto L_800FE23C;
    }
    // 0x800FE234: nop

    // 0x800FE238: break       6
    do_break(2148524600);
L_800FE23C:
    // 0x800FE23C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800FE240: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800FE244: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800FE248: jal         0x800FCED0
    // 0x800FE24C: nop

    func_800FCED0(rdram, ctx);
        goto after_28;
    // 0x800FE24C: nop

    after_28:
    // 0x800FE250: bne         $v0, $zero, L_800FE308
    if (ctx->r2 != 0) {
        // 0x800FE254: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800FE308;
    }
    // 0x800FE254: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800FE258: b           L_800FE308
    // 0x800FE25C: sb          $t4, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r12;
        goto L_800FE308;
    // 0x800FE25C: sb          $t4, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r12;
    // 0x800FE260: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
L_800FE264:
    // 0x800FE264: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800FE268: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FE26C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FE270: jal         0x800FCDE0
    // 0x800FE274: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800FCDE0(rdram, ctx);
        goto after_29;
    // 0x800FE274: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_29:
    // 0x800FE278: bne         $v0, $zero, L_800FE288
    if (ctx->r2 != 0) {
        // 0x800FE27C: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_800FE288;
    }
    // 0x800FE27C: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FE280: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800FE284: sb          $t5, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r13;
L_800FE288:
    // 0x800FE288: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FE28C: lw          $t6, 0x5A04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5A04);
    // 0x800FE290: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE294: lui         $t7, 0x393
    ctx->r15 = S32(0X393 << 16);
    // 0x800FE298: lh          $v0, 0x8($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X8);
    // 0x800FE29C: ori         $t7, $t7, 0x8700
    ctx->r15 = ctx->r15 | 0X8700;
    // 0x800FE2A0: beql        $v0, $at, L_800FE30C
    if (ctx->r2 == ctx->r1) {
        // 0x800FE2A4: lbu         $t1, 0xF($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0XF);
            goto L_800FE30C;
    }
    goto skip_12;
    // 0x800FE2A4: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
    skip_12:
    // 0x800FE2A8: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800FE2AC: mflo        $t8
    ctx->r24 = lo;
    // 0x800FE2B0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800FE2B4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800FE2B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FE2BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FE2C0: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800FE2C4: bne         $v0, $zero, L_800FE2D0
    if (ctx->r2 != 0) {
        // 0x800FE2C8: nop
    
            goto L_800FE2D0;
    }
    // 0x800FE2C8: nop

    // 0x800FE2CC: break       7
    do_break(2148524748);
L_800FE2D0:
    // 0x800FE2D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE2D4: bne         $v0, $at, L_800FE2E8
    if (ctx->r2 != ctx->r1) {
        // 0x800FE2D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800FE2E8;
    }
    // 0x800FE2D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800FE2DC: bne         $t7, $at, L_800FE2E8
    if (ctx->r15 != ctx->r1) {
        // 0x800FE2E0: nop
    
            goto L_800FE2E8;
    }
    // 0x800FE2E0: nop

    // 0x800FE2E4: break       6
    do_break(2148524772);
L_800FE2E8:
    // 0x800FE2E8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800FE2EC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800FE2F0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800FE2F4: jal         0x800FCED0
    // 0x800FE2F8: nop

    func_800FCED0(rdram, ctx);
        goto after_30;
    // 0x800FE2F8: nop

    after_30:
    // 0x800FE2FC: bne         $v0, $zero, L_800FE308
    if (ctx->r2 != 0) {
        // 0x800FE300: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800FE308;
    }
    // 0x800FE300: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800FE304: sb          $t0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r8;
L_800FE308:
    // 0x800FE308: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
L_800FE30C:
    // 0x800FE30C: sb          $t1, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r9;
    // 0x800FE310: lbu         $t2, 0x14($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X14);
L_800FE314:
    // 0x800FE314: beql        $t2, $zero, L_800FE3DC
    if (ctx->r10 == 0) {
        // 0x800FE318: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800FE3DC;
    }
    goto skip_13;
    // 0x800FE318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x800FE31C: lbu         $t3, 0x13($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X13);
    // 0x800FE320: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800FE324: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE328: beq         $t3, $zero, L_800FE388
    if (ctx->r11 == 0) {
        // 0x800FE32C: nop
    
            goto L_800FE388;
    }
    // 0x800FE32C: nop

    // 0x800FE330: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE334: beq         $a0, $at, L_800FE344
    if (ctx->r4 == ctx->r1) {
        // 0x800FE338: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_800FE344;
    }
    // 0x800FE338: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800FE33C: jal         0x800FC934
    // 0x800FE340: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800FC934(rdram, ctx);
        goto after_31;
    // 0x800FE340: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_31:
L_800FE344:
    // 0x800FE344: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FE348: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FE34C: addiu       $s0, $s0, 0x5A2C
    ctx->r16 = ADD32(ctx->r16, 0X5A2C);
    // 0x800FE350: addiu       $v0, $v0, 0x5A20
    ctx->r2 = ADD32(ctx->r2, 0X5A20);
    // 0x800FE354: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_800FE358:
    // 0x800FE358: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800FE35C: beql        $a0, $zero, L_800FE378
    if (ctx->r4 == 0) {
        // 0x800FE360: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800FE378;
    }
    goto skip_14;
    // 0x800FE360: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_14:
    // 0x800FE364: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800FE368: jal         0x800FC934
    // 0x800FE36C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800FC934(rdram, ctx);
        goto after_32;
    // 0x800FE36C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_32:
    // 0x800FE370: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE374: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800FE378:
    // 0x800FE378: bnel        $v0, $s0, L_800FE358
    if (ctx->r2 != ctx->r16) {
        // 0x800FE37C: lw          $a0, 0x0($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X0);
            goto L_800FE358;
    }
    goto skip_15;
    // 0x800FE37C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    skip_15:
    // 0x800FE380: b           L_800FE3D8
    // 0x800FE384: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
        goto L_800FE3D8;
    // 0x800FE384: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
L_800FE388:
    // 0x800FE388: beq         $a0, $at, L_800FE398
    if (ctx->r4 == ctx->r1) {
        // 0x800FE38C: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_800FE398;
    }
    // 0x800FE38C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800FE390: jal         0x800FC934
    // 0x800FE394: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800FC934(rdram, ctx);
        goto after_33;
    // 0x800FE394: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_33:
L_800FE398:
    // 0x800FE398: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FE39C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FE3A0: addiu       $s0, $s0, 0x5A2C
    ctx->r16 = ADD32(ctx->r16, 0X5A2C);
    // 0x800FE3A4: addiu       $v0, $v0, 0x5A20
    ctx->r2 = ADD32(ctx->r2, 0X5A20);
    // 0x800FE3A8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_800FE3AC:
    // 0x800FE3AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800FE3B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800FE3B4: beql        $a0, $zero, L_800FE3CC
    if (ctx->r4 == 0) {
        // 0x800FE3B8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800FE3CC;
    }
    goto skip_16;
    // 0x800FE3B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_16:
    // 0x800FE3BC: jal         0x800FC934
    // 0x800FE3C0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800FC934(rdram, ctx);
        goto after_34;
    // 0x800FE3C0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_34:
    // 0x800FE3C4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE3C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800FE3CC:
    // 0x800FE3CC: bnel        $v0, $s0, L_800FE3AC
    if (ctx->r2 != ctx->r16) {
        // 0x800FE3D0: lw          $a0, 0x0($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X0);
            goto L_800FE3AC;
    }
    goto skip_17;
    // 0x800FE3D0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    skip_17:
    // 0x800FE3D4: sb          $zero, 0x14($s1)
    MEM_B(0X14, ctx->r17) = 0;
L_800FE3D8:
    // 0x800FE3D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800FE3DC:
    // 0x800FE3DC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE3E0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800FE3E4: jr          $ra
    // 0x800FE3E8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800FE3E8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void cadbfunc_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A64: jal         0x80800A1C
    // 0x80800A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800A1C_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A6C: bne         $v0, $zero, L_80800A7C
    if (ctx->r2 != 0) {
        // 0x80800A70: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800A7C;
    }
    // 0x80800A70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800A74: b           L_80800A8C
    // 0x80800A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A8C;
    // 0x80800A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A7C:
    // 0x80800A7C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800A80: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800A84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A88: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80800A8C:
    // 0x80800A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A94: jr          $ra
    // 0x80800A98: nop

    return;
    // 0x80800A98: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A590: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A590);
    return;
    // 0x8008A594: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808007D8_ncpod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007DC: andi        $t6, $a1, 0x10
    ctx->r14 = ctx->r5 & 0X10;
    // 0x808007E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E4: beq         $t6, $zero, L_808007FC
    if (ctx->r14 == 0) {
        // 0x808007E8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808007FC;
    }
    // 0x808007E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007EC: jal         0x80800000
    // 0x808007F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_ncpod(rdram, ctx);
        goto after_0;
    // 0x808007F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007F4: b           L_8080080C
    // 0x808007F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
        goto L_8080080C;
    // 0x808007F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_808007FC:
    // 0x808007FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800800: jal         0x80800038
    // 0x80800804: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800038_ncpod(rdram, ctx);
        goto after_1;
    // 0x80800804: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800808: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8080080C:
    // 0x8080080C: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x80800810: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x80800814: beq         $t7, $zero, L_8080084C
    if (ctx->r15 == 0) {
        // 0x80800818: sll         $t8, $a1, 13
        ctx->r24 = S32(ctx->r5 << 13);
            goto L_8080084C;
    }
    // 0x80800818: sll         $t8, $a1, 13
    ctx->r24 = S32(ctx->r5 << 13);
    // 0x8080081C: bgez        $t8, L_8080082C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800820: sll         $t9, $a1, 14
        ctx->r25 = S32(ctx->r5 << 14);
            goto L_8080082C;
    }
    // 0x80800820: sll         $t9, $a1, 14
    ctx->r25 = S32(ctx->r5 << 14);
    // 0x80800824: b           L_80800840
    // 0x80800828: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_80800840;
    // 0x80800828: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8080082C:
    // 0x8080082C: bgez        $t9, L_8080083C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800830: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_8080083C;
    }
    // 0x80800830: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800834: b           L_80800840
    // 0x80800838: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_80800840;
    // 0x80800838: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8080083C:
    // 0x8080083C: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
L_80800840:
    // 0x80800840: jal         0x80015178
    // 0x80800844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80015178(rdram, ctx);
        goto after_2;
    // 0x80800844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800848: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8080084C:
    // 0x8080084C: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
    // 0x80800850: beq         $t1, $zero, L_80800880
    if (ctx->r9 == 0) {
        // 0x80800854: andi        $t3, $a1, 0x2000
        ctx->r11 = ctx->r5 & 0X2000;
            goto L_80800880;
    }
    // 0x80800854: andi        $t3, $a1, 0x2000
    ctx->r11 = ctx->r5 & 0X2000;
    // 0x80800858: andi        $t2, $a1, 0x4000
    ctx->r10 = ctx->r5 & 0X4000;
    // 0x8080085C: beq         $t2, $zero, L_8080086C
    if (ctx->r10 == 0) {
        // 0x80800860: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080086C;
    }
    // 0x80800860: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800864: b           L_80800870
    // 0x80800868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80800870;
    // 0x80800868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8080086C:
    // 0x8080086C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800870:
    // 0x80800870: jal         0x808008AC
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800878: b           L_808008A0
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008A0;
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800880:
    // 0x80800880: beq         $t3, $zero, L_80800890
    if (ctx->r11 == 0) {
        // 0x80800884: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800890;
    }
    // 0x80800884: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800888: b           L_80800894
    // 0x8080088C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80800894;
    // 0x8080088C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80800890:
    // 0x80800890: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800894:
    // 0x80800894: jal         0x808008AC
    // 0x80800898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ncpod_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x80800898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080089C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008A0:
    // 0x808008A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008A4: jr          $ra
    // 0x808008A8: nop

    return;
    // 0x808008A8: nop

;}
RECOMP_FUNC void func_8010C500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C508: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x8010C50C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010C510: addiu       $a0, $a0, 0x6F50
    ctx->r4 = ADD32(ctx->r4, 0X6F50);
    // 0x8010C514: srl         $v1, $v0, 25
    ctx->r3 = S32(U32(ctx->r2) >> 25);
    // 0x8010C518: bne         $v1, $zero, L_8010C528
    if (ctx->r3 != 0) {
        // 0x8010C51C: addiu       $a1, $v1, -0x1
        ctx->r5 = ADD32(ctx->r3, -0X1);
            goto L_8010C528;
    }
    // 0x8010C51C: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x8010C520: b           L_8010C540
    // 0x8010C524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010C540;
    // 0x8010C524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C528:
    // 0x8010C528: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x8010C52C: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x8010C530: jal         0x800CC338
    // 0x8010C534: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x8010C534: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x8010C538: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8010C53C: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
L_8010C540:
    // 0x8010C540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C548: jr          $ra
    // 0x8010C54C: nop

    return;
    // 0x8010C54C: nop

;}
RECOMP_FUNC void func_800E39D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E39D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E39DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800E39E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E39E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E39E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E39EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E39F0: jal         0x800CA628
    // 0x800E39F4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA628(rdram, ctx);
        goto after_0;
    // 0x800E39F4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E39F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E39FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3A00: jr          $ra
    // 0x800E3A04: nop

    return;
    // 0x800E3A04: nop

;}
RECOMP_FUNC void func_80801080_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801084: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080108C: beq         $a1, $at, L_808010E0
    if (ctx->r5 == ctx->r1) {
        // 0x80801090: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808010E0;
    }
    // 0x80801090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801094: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80801098: beq         $a1, $at, L_80801134
    if (ctx->r5 == ctx->r1) {
        // 0x8080109C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80801134;
    }
    // 0x8080109C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808010A0: beq         $a1, $at, L_8080119C
    if (ctx->r5 == ctx->r1) {
        // 0x808010A4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8080119C;
    }
    // 0x808010A4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808010A8: beq         $a1, $at, L_808010C0
    if (ctx->r5 == ctx->r1) {
        // 0x808010AC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808010C0;
    }
    // 0x808010AC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808010B0: beq         $a1, $at, L_80801124
    if (ctx->r5 == ctx->r1) {
        // 0x808010B4: nop
    
            goto L_80801124;
    }
    // 0x808010B4: nop

    // 0x808010B8: b           L_808011B8
    // 0x808010BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808011B8;
    // 0x808010BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808010C0:
    // 0x808010C0: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808010C4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808010C8: beql        $t7, $zero, L_808011B8
    if (ctx->r15 == 0) {
        // 0x808010CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808011B8;
    }
    goto skip_0;
    // 0x808010CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808010D0: jal         0x808004C0
    // 0x808010D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808004C0_chsilo(rdram, ctx);
        goto after_0;
    // 0x808010D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808010D8: b           L_808011B8
    // 0x808010DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011B8;
    // 0x808010DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010E0:
    // 0x808010E0: jal         0x801015D0
    // 0x808010E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x808010E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808010E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808010EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808010F0: lw          $t8, 0x64($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X64);
    // 0x808010F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808010F8: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x808010FC: bgez        $t0, L_80801114
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801100: nop
    
            goto L_80801114;
    }
    // 0x80801100: nop

    // 0x80801104: jal         0x800DF744
    // 0x80801108: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80801108: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8080110C: b           L_808011B8
    // 0x80801110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011B8;
    // 0x80801110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801114:
    // 0x80801114: jal         0x800DF744
    // 0x80801118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80801118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080111C: b           L_808011B8
    // 0x80801120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011B8;
    // 0x80801120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801124:
    // 0x80801124: jal         0x8080087C
    // 0x80801128: nop

    func_8080087C_chsilo(rdram, ctx);
        goto after_4;
    // 0x80801128: nop

    after_4:
    // 0x8080112C: b           L_808011B8
    // 0x80801130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011B8;
    // 0x80801130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801134:
    // 0x80801134: jal         0x80101080
    // 0x80801138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_5;
    // 0x80801138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_5:
    // 0x8080113C: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x80801140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801144: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801148: beq         $a2, $zero, L_8080117C
    if (ctx->r6 == 0) {
        // 0x8080114C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080117C;
    }
    // 0x8080114C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801150: beq         $a2, $at, L_8080118C
    if (ctx->r6 == ctx->r1) {
        // 0x80801154: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080118C;
    }
    // 0x80801154: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801158: bne         $a2, $at, L_808011B4
    if (ctx->r6 != ctx->r1) {
        // 0x8080115C: lh          $a1, 0x20($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X20);
            goto L_808011B4;
    }
    // 0x8080115C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80801160: jal         0x808002E8
    // 0x80801164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002E8_chsilo(rdram, ctx);
        goto after_6;
    // 0x80801164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_6:
    // 0x80801168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080116C: jal         0x808004C0
    // 0x80801170: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808004C0_chsilo(rdram, ctx);
        goto after_7;
    // 0x80801170: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_7:
    // 0x80801174: b           L_808011B8
    // 0x80801178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011B8;
    // 0x80801178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080117C:
    // 0x8080117C: jal         0x80800238
    // 0x80801180: nop

    func_80800238_chsilo(rdram, ctx);
        goto after_8;
    // 0x80801180: nop

    after_8:
    // 0x80801184: b           L_808011B8
    // 0x80801188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011B8;
    // 0x80801188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080118C:
    // 0x8080118C: jal         0x808004C0
    // 0x80801190: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808004C0_chsilo(rdram, ctx);
        goto after_9;
    // 0x80801190: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_9:
    // 0x80801194: b           L_808011B8
    // 0x80801198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011B8;
    // 0x80801198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080119C:
    // 0x8080119C: lbu         $t1, 0x74($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X74);
    // 0x808011A0: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x808011A4: b           L_808011B4
    // 0x808011A8: sb          $t2, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r10;
        goto L_808011B4;
    // 0x808011A8: sb          $t2, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r10;
    // 0x808011AC: b           L_808011B8
    // 0x808011B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808011B8;
    // 0x808011B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011B4:
    // 0x808011B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011B8:
    // 0x808011B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011C0: jr          $ra
    // 0x808011C4: nop

    return;
    // 0x808011C4: nop

;}
RECOMP_FUNC void func_808003C0_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C8: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x808003CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808003D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808003D4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808003D8: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x808003DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808003E0: jal         0x800D0B68
    // 0x808003E4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x808003E4: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_0:
    // 0x808003E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808003EC: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x808003F0: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x808003F4: lbu         $t2, 0x65($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X65);
    // 0x808003F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800400: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x80800404: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800408: sb          $t4, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r12;
    // 0x8080040C: lw          $t5, 0x64($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X64);
    // 0x80800410: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x80800414: bltz        $t7, L_8080042C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800418: nop
    
            goto L_8080042C;
    }
    // 0x80800418: nop

    // 0x8080041C: jal         0x80800314
    // 0x80800420: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800314_chblackeye(rdram, ctx);
        goto after_1;
    // 0x80800420: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80800424: b           L_80800438
    // 0x80800428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800438;
    // 0x80800428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080042C:
    // 0x8080042C: jal         0x80800314
    // 0x80800430: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800314_chblackeye(rdram, ctx);
        goto after_2;
    // 0x80800430: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800438:
    // 0x80800438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E20: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E20);
    return;
    // 0x80082E24: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_8080054C_gsworldDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080054C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800550: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800554: jr          $ra
    // 0x80800558: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80800558: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_800DC264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC26C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800DC270: jal         0x800DC1AC
    // 0x800DC274: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_800DC1AC(rdram, ctx);
        goto after_0;
    // 0x800DC274: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800DC278: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800DC27C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800DC280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC288: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800DC28C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800DC290: jr          $ra
    // 0x800DC294: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x800DC294: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
;}
RECOMP_FUNC void func_800E24CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E24CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E24D0: jr          $ra
    // 0x800E24D4: sb          $a0, -0x2B6D($at)
    MEM_B(-0X2B6D, ctx->r1) = ctx->r4;
    return;
    // 0x800E24D4: sb          $a0, -0x2B6D($at)
    MEM_B(-0X2B6D, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8010C93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C93C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8010C940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C948: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8010C94C: jal         0x8010C878
    // 0x8010C950: nop

    func_8010C878(rdram, ctx);
        goto after_0;
    // 0x8010C950: nop

    after_0:
    // 0x8010C954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C95C: jr          $ra
    // 0x8010C960: nop

    return;
    // 0x8010C960: nop

;}
RECOMP_FUNC void func_80091E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E6C: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x80091E70: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x80091E74: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80091E78: jr          $ra
    // 0x80091E7C: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
    return;
    // 0x80091E7C: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_80103964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010396C: lhu         $a1, 0x14($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X14);
    // 0x80103970: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80103974: beq         $a1, $zero, L_80103984
    if (ctx->r5 == 0) {
        // 0x80103978: nop
    
            goto L_80103984;
    }
    // 0x80103978: nop

    // 0x8010397C: bne         $a1, $at, L_8010398C
    if (ctx->r5 != ctx->r1) {
        // 0x80103980: nop
    
            goto L_8010398C;
    }
    // 0x80103980: nop

L_80103984:
    // 0x80103984: b           L_80103994
    // 0x80103988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103994;
    // 0x80103988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010398C:
    // 0x8010398C: jal         0x800D674C
    // 0x80103990: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80103990: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_80103994:
    // 0x80103994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010399C: jr          $ra
    // 0x801039A0: nop

    return;
    // 0x801039A0: nop

;}
RECOMP_FUNC void gldbstring_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080015C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800164: jal         0x800D721C
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D721C(rdram, ctx);
        goto after_0;
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: jal         0x800D70F8
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_1;
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800178: jal         0x800D6CEC
    // 0x8080017C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800D6CEC(rdram, ctx);
        goto after_2;
    // 0x8080017C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void func_808029C8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808029CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808029D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808029D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808029D8: jal         0x80100094
    // 0x808029DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808029DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808029E0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808029E4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808029E8: jal         0x800EE7F8
    // 0x808029EC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808029EC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_1:
    // 0x808029F0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808029F4: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808029F8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808029FC: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80802A00: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802A04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802A08: jal         0x800EE7F8
    // 0x80802A0C: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80802A0C: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80802A10: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80802A14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802A18: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802A1C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80802A20: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80802A24: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80802A28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80802A2C: jal         0x800EF1B8
    // 0x80802A30: nop

    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80802A30: nop

    after_3:
    // 0x80802A34: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802A38: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802A3C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A30) << 16);
    // 0x80802A40: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80802A44: lwc1        $f6, -0x65D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A30));
    // 0x80802A48: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80802A4C: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802A50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802A54: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80802A58: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802A5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802A60: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A34) << 16);
    // 0x80802A64: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80802A68: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80802A6C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80802A70: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80802A74: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80802A78: lwc1        $f8, -0x65CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A34));
    // 0x80802A7C: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80802A80: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80802A84: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802A88: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802A8C: jal         0x80088090
    // 0x80802A90: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80802A90: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80802A94: jal         0x80088098
    // 0x80802A98: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80802A98: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80802A9C: jal         0x800880A0
    // 0x80802AA0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80802AA0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x80802AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802AA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802AAC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80802AB0: jr          $ra
    // 0x80802AB4: nop

    return;
    // 0x80802AB4: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1C8: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1C8);
    return;
    // 0x8008A1CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800CEA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEA68: jal         0x800CE3E0
    // 0x800CEA6C: nop

    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CEA6C: nop

    after_0:
    // 0x800CEA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEA74: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CEA78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEA7C: jr          $ra
    // 0x800CEA80: nop

    return;
    // 0x800CEA80: nop

;}
RECOMP_FUNC void func_808011B8_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808011BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808011C0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1676, 0X4304) << 16);
    // 0x808011C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011C8: addiu       $t6, $t6, 0x4304
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1676, 0X4304));
    // 0x808011CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808011D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808011D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808011D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808011DC: jal         0x800BBCB8
    // 0x808011E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808011E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808011E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808011EC: jr          $ra
    // 0x808011F0: nop

    return;
    // 0x808011F0: nop

;}
RECOMP_FUNC void func_800E729C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E729C: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800E72A0: beq         $v0, $zero, L_800E72D8
    if (ctx->r2 == 0) {
        // 0x800E72A4: nop
    
            goto L_800E72D8;
    }
    // 0x800E72A4: nop

    // 0x800E72A8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E72AC: beq         $v0, $t6, L_800E72D8
    if (ctx->r2 == ctx->r14) {
        // 0x800E72B0: nop
    
            goto L_800E72D8;
    }
    // 0x800E72B0: nop

    // 0x800E72B4: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_800E72B8:
    // 0x800E72B8: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x800E72BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800E72C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E72C4: beq         $v0, $zero, L_800E72D8
    if (ctx->r2 == 0) {
        // 0x800E72C8: nop
    
            goto L_800E72D8;
    }
    // 0x800E72C8: nop

    // 0x800E72CC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800E72D0: bnel        $v0, $t7, L_800E72B8
    if (ctx->r2 != ctx->r15) {
        // 0x800E72D4: sb          $v0, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r2;
            goto L_800E72B8;
    }
    goto skip_0;
    // 0x800E72D4: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    skip_0:
L_800E72D8:
    // 0x800E72D8: jr          $ra
    // 0x800E72DC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    return;
    // 0x800E72DC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
;}
RECOMP_FUNC void func_80801A34_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A3C: jal         0x8080187C
    // 0x80801A40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080187C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801A40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A44: jal         0x8080179C
    // 0x80801A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsfirstp_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A54: jr          $ra
    // 0x80801A58: nop

    return;
    // 0x80801A58: nop

;}
RECOMP_FUNC void func_80093370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093370: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093374: jr          $ra
    // 0x80093378: sb          $a1, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r5;
    return;
    // 0x80093378: sb          $a1, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void yaw_setVelocityUnbounded(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C9BC: lw          $t6, 0xF8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C9C0: jr          $ra
    // 0x8009C9C4: swc1        $f12, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009C9C4: swc1        $f12, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bstaxi_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E00: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E00);
    return;
    // 0x80083E04: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8010D254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010D258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D25C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010D260: jal         0x800EE7F8
    // 0x8010D264: addiu       $a1, $a1, 0x6F50
    ctx->r5 = ADD32(ctx->r5, 0X6F50);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010D264: addiu       $a1, $a1, 0x6F50
    ctx->r5 = ADD32(ctx->r5, 0X6F50);
    after_0:
    // 0x8010D268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D26C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010D270: jr          $ra
    // 0x8010D274: nop

    return;
    // 0x8010D274: nop

;}
RECOMP_FUNC void func_808002F4_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800300: jal         0x80100094
    // 0x80800304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800304: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800308: beq         $v0, $zero, L_80800318
    if (ctx->r2 == 0) {
        // 0x8080030C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800318;
    }
    // 0x8080030C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800310: jal         0x800897C8
    // 0x80800314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800318:
    // 0x80800318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080031C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800320: jr          $ra
    // 0x80800324: nop

    return;
    // 0x80800324: nop

;}
RECOMP_FUNC void _chfactorytoxicpools_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086268: syscall     295
    recomp_syscall_handler(rdram, ctx, 0x80086268);
    return;
    // 0x8008626C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chtimetable_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1592, 0X7CC) << 16);
    // 0x808006D0: jr          $ra
    // 0x808006D4: addiu       $v0, $v0, 0x7CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1592, 0X7CC));
    return;
    // 0x808006D4: addiu       $v0, $v0, 0x7CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1592, 0X7CC));
    // 0x808006D8: nop

    // 0x808006DC: nop

;}
RECOMP_FUNC void _gccollectDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088038: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088038);
    return;
    // 0x8008803C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800FCDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCDE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FCDE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCDE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FCDEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FCDF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FCDF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FCDF8: jal         0x800FB5F8
    // 0x800FCDFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCDFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FCE00: bne         $v0, $zero, L_800FCE10
    if (ctx->r2 != 0) {
        // 0x800FCE04: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800FCE10;
    }
    // 0x800FCE04: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800FCE08: b           L_800FCEBC
    // 0x800FCE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FCEBC;
    // 0x800FCE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FCE10:
    // 0x800FCE10: lbu         $t6, 0x32($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X32);
    // 0x800FCE14: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FCE18: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800FCE1C: beq         $t6, $zero, L_800FCE38
    if (ctx->r14 == 0) {
        // 0x800FCE20: addiu       $t9, $t9, 0x57D0
        ctx->r25 = ADD32(ctx->r25, 0X57D0);
            goto L_800FCE38;
    }
    // 0x800FCE20: addiu       $t9, $t9, 0x57D0
    ctx->r25 = ADD32(ctx->r25, 0X57D0);
    // 0x800FCE24: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x800FCE28: bnel        $t7, $t8, L_800FCE3C
    if (ctx->r15 != ctx->r24) {
        // 0x800FCE2C: subu        $s0, $s1, $t9
        ctx->r16 = SUB32(ctx->r17, ctx->r25);
            goto L_800FCE3C;
    }
    goto skip_0;
    // 0x800FCE2C: subu        $s0, $s1, $t9
    ctx->r16 = SUB32(ctx->r17, ctx->r25);
    skip_0:
    // 0x800FCE30: b           L_800FCEBC
    // 0x800FCE34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800FCEBC;
    // 0x800FCE34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FCE38:
    // 0x800FCE38: subu        $s0, $s1, $t9
    ctx->r16 = SUB32(ctx->r17, ctx->r25);
L_800FCE3C:
    // 0x800FCE3C: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FCE40: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x800FCE44: mflo        $s0
    ctx->r16 = lo;
    // 0x800FCE48: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800FCE4C: jal         0x80017108
    // 0x800FCE50: nop

    func_80017108(rdram, ctx);
        goto after_1;
    // 0x800FCE50: nop

    after_1:
    // 0x800FCE54: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800FCE58: bnel        $v0, $t1, L_800FCEB0
    if (ctx->r2 != ctx->r9) {
        // 0x800FCE5C: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_800FCEB0;
    }
    goto skip_1;
    // 0x800FCE5C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800FCE60: jal         0x80017210
    // 0x800FCE64: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_80017210(rdram, ctx);
        goto after_2;
    // 0x800FCE64: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x800FCE68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FCE6C: beql        $v0, $at, L_800FCE84
    if (ctx->r2 == ctx->r1) {
        // 0x800FCE70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FCE84;
    }
    goto skip_2;
    // 0x800FCE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x800FCE74: jal         0x800177C4
    // 0x800FCE78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800177C4(rdram, ctx);
        goto after_3;
    // 0x800FCE78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800FCE7C: beq         $v0, $zero, L_800FCEAC
    if (ctx->r2 == 0) {
        // 0x800FCE80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FCEAC;
    }
    // 0x800FCE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FCE84:
    // 0x800FCE84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800FCE88: jal         0x800178C4
    // 0x800FCE8C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800178C4(rdram, ctx);
        goto after_4;
    // 0x800FCE8C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x800FCE90: beq         $v0, $zero, L_800FCEAC
    if (ctx->r2 == 0) {
        // 0x800FCE94: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_800FCEAC;
    }
    // 0x800FCE94: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800FCE98: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800FCE9C: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    // 0x800FCEA0: sb          $t3, 0x32($s1)
    MEM_B(0X32, ctx->r17) = ctx->r11;
    // 0x800FCEA4: b           L_800FCEBC
    // 0x800FCEA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800FCEBC;
    // 0x800FCEA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FCEAC:
    // 0x800FCEAC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_800FCEB0:
    // 0x800FCEB0: sb          $zero, 0x32($s1)
    MEM_B(0X32, ctx->r17) = 0;
    // 0x800FCEB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FCEB8: sw          $t4, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r12;
L_800FCEBC:
    // 0x800FCEBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCEC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FCEC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FCEC8: jr          $ra
    // 0x800FCECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FCECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_53(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D68: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D68);
    return;
    // 0x80082D6C: addi        $t0, $zero, 0xD4
    ctx->r8 = ADD32(0, 0XD4);
;}
RECOMP_FUNC void func_800C3058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C305C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3060: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3064: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3068: beq         $t6, $zero, L_800C30A8
    if (ctx->r14 == 0) {
        // 0x800C306C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C30A8;
    }
    // 0x800C306C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3070: jal         0x800C1414
    // 0x800C3074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C3078: lw          $t7, 0x78($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X78);
    // 0x800C307C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3084: sll         $t9, $t7, 28
    ctx->r25 = S32(ctx->r15 << 28);
    // 0x800C3088: bltz        $t9, L_800C30A0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800C308C: sh          $a1, 0x5A($v0)
        MEM_H(0X5A, ctx->r2) = ctx->r5;
            goto L_800C30A0;
    }
    // 0x800C308C: sh          $a1, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r5;
    // 0x800C3090: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3094: sh          $a1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r5;
    // 0x800C3098: sh          $a1, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r5;
    // 0x800C309C: swc1        $f4, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f4.u32l;
L_800C30A0:
    // 0x800C30A0: jal         0x800C13A0
    // 0x800C30A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13A0(rdram, ctx);
        goto after_1;
    // 0x800C30A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
L_800C30A8:
    // 0x800C30A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C30AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C30B0: jr          $ra
    // 0x800C30B4: nop

    return;
    // 0x800C30B4: nop

;}
RECOMP_FUNC void func_800EE748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE748: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800EE74C: lbu         $t6, 0x5483($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5483);
    // 0x800EE750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EE754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE758: beql        $t6, $zero, L_800EE76C
    if (ctx->r14 == 0) {
        // 0x800EE75C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EE76C;
    }
    goto skip_0;
    // 0x800EE75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EE760: jal         0x80088CD0
    // 0x800EE764: nop

    _idbounce_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x800EE764: nop

    after_0:
    // 0x800EE768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EE76C:
    // 0x800EE76C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EE770: jr          $ra
    // 0x800EE774: nop

    return;
    // 0x800EE774: nop

    // 0x800EE778: nop

    // 0x800EE77C: nop

;}
RECOMP_FUNC void ncpod_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C94: jal         0x80110024
    // 0x80800C98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800C98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800C9C: jal         0x800895D0
    // 0x80800CA0: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    _ncpoddialog_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800CA0: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_1:
    // 0x80800CA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CA8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800CAC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB0: jal         0x80089618
    // 0x80800CB4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _ncpoddialog_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800CB4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CC0: jr          $ra
    // 0x80800CC4: nop

    return;
    // 0x80800CC4: nop

;}
RECOMP_FUNC void babee_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x808002D8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x808002DC: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x808002E0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002E4: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x808002E8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808002EC: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002F0: mflo        $t7
    ctx->r15 = lo;
    // 0x808002F4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x808002F8: swc1        $f12, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f12.u32l;
    // 0x808002FC: lbu         $t9, 0x1C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1C);
    // 0x80800300: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800304: mflo        $t0
    ctx->r8 = lo;
    // 0x80800308: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8080030C: swc1        $f14, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f14.u32l;
    // 0x80800310: lbu         $t2, 0x1C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1C);
    // 0x80800314: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80800318: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080031C: mflo        $t3
    ctx->r11 = lo;
    // 0x80800320: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80800324: jr          $ra
    // 0x80800328: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
    return;
    // 0x80800328: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80800140_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: jal         0x80101080
    // 0x8080014C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x8080014C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800150: jal         0x80106790
    // 0x80800154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800158: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800160: lui         $a1, 0x44E1
    ctx->r5 = S32(0X44E1 << 16);
    // 0x80800164: jal         0x80086688
    // 0x80800168: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800168: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    after_2:
    // 0x8080016C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800170: lui         $a1, 0xC4AF
    ctx->r5 = S32(0XC4AF << 16);
    // 0x80800174: jal         0x80086690
    // 0x80800178: lui         $a2, 0xC496
    ctx->r6 = S32(0XC496 << 16);
    _chexploder_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800178: lui         $a2, 0xC496
    ctx->r6 = S32(0XC496 << 16);
    after_3:
    // 0x8080017C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800180: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800184: jal         0x800866D0
    // 0x80800188: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x80800188: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_4:
    // 0x8080018C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800190: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1380, 0X660) << 16);
    // 0x80800194: addiu       $a2, $a2, 0x660
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1380, 0X660));
    // 0x80800198: jal         0x80089D18
    // 0x8080019C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080019C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_5:
    // 0x808001A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808001A4: jal         0x800BF744
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_6;
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void chcrackarchwall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1888, 0X144) << 16);
    // 0x808000E0: jr          $ra
    // 0x808000E4: addiu       $v0, $v0, 0x144
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1888, 0X144));
    return;
    // 0x808000E4: addiu       $v0, $v0, 0x144
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1888, 0X144));
    // 0x808000E8: nop

    // 0x808000EC: nop

;}
RECOMP_FUNC void suexpressmorph_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080071C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800724: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80800728: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8080072C: jal         0x808006D8
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    suexpressmorph_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800734: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800738: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8080073C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3170, 0X1320) << 16);
    // 0x80800740: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x80800744: addiu       $a1, $a1, 0x1320
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3170, 0X1320));
    // 0x80800748: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080074C: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800750: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x80800754: sb          $t8, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r24;
    // 0x80800758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080075C: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80800760: mflo        $t1
    ctx->r9 = lo;
    // 0x80800764: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80800768: lbu         $t0, 0x7($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X7);
    // 0x8080076C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80800770: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
    // 0x80800774: blez        $t0, L_808007B8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800778: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_808007B8;
    }
    // 0x80800778: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8080077C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800780: nop

    // 0x80800784: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80800788:
    // 0x80800788: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8080078C: lh          $t4, 0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X2);
    // 0x80800790: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800794: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800798: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080079C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808007A0: mflo        $t5
    ctx->r13 = lo;
    // 0x808007A4: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x808007A8: lbu         $t7, 0x7($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X7);
    // 0x808007AC: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808007B0: bnel        $at, $zero, L_80800788
    if (ctx->r1 != 0) {
        // 0x808007B4: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80800788;
    }
    goto skip_0;
    // 0x808007B4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_0:
L_808007B8:
    // 0x808007B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

    // 0x808007C8: nop

    // 0x808007CC: nop

;}
RECOMP_FUNC void _gcsectionskip_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AD0: syscall     653
    recomp_syscall_handler(rdram, ctx, 0x80087AD0);
    return;
    // 0x80087AD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801B00_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801B08: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801B14: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(932, 0X2DBC) << 16);
    // 0x80801B18: addiu       $t7, $t7, 0x2DBC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(932, 0X2DBC));
    // 0x80801B1C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801B20: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80801B24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801B2C: jal         0x800BBCB8
    // 0x80801B30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801B30: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80801B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B3C: jr          $ra
    // 0x80801B40: nop

    return;
    // 0x80801B40: nop

;}
RECOMP_FUNC void bskazmove_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BD0: bne         $a1, $at, L_80800C20
    if (ctx->r5 != ctx->r1) {
        // 0x80800BD4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800C20;
    }
    // 0x80800BD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BD8: jal         0x8009EF10
    // 0x80800BDC: nop

    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80800BDC: nop

    after_0:
    // 0x80800BE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BE4: bnel        $v0, $at, L_80800C24
    if (ctx->r2 != ctx->r1) {
        // 0x80800BE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C24;
    }
    goto skip_0;
    // 0x80800BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800BEC: jal         0x8009EF1C
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bastick_getZonePosition(rdram, ctx);
        goto after_1;
    // 0x80800BF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800BF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(260, 0XC64) << 16);
    // 0x80800BF8: lwc1        $f4, 0xC64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(260, 0XC64));
    // 0x80800BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C00: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C04: nop

    // 0x80800C08: bc1fl       L_80800C24
    if (!c1cs) {
        // 0x80800C0C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C24;
    }
    goto skip_1;
    // 0x80800C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80800C10: jal         0x800962B0
    // 0x80800C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800962B0(rdram, ctx);
        goto after_2;
    // 0x80800C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800C18: b           L_80800C30
    // 0x80800C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C30;
    // 0x80800C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C20:
    // 0x80800C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800C24:
    // 0x80800C24: jal         0x800962B0
    // 0x80800C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800962B0(rdram, ctx);
        goto after_3;
    // 0x80800C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C30:
    // 0x80800C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C34: jr          $ra
    // 0x80800C38: nop

    return;
    // 0x80800C38: nop

;}
RECOMP_FUNC void func_8080569C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080569C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808056A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808056A4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x808056A8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x808056AC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x808056B0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x808056B4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808056B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808056BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808056C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808056C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808056C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808056CC: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808056D0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x808056D4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808056D8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x808056DC: beq         $v0, $zero, L_80805700
    if (ctx->r2 == 0) {
        // 0x808056E0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80805700;
    }
    // 0x808056E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808056E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808056E8: beq         $v0, $at, L_80805724
    if (ctx->r2 == ctx->r1) {
        // 0x808056EC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80805724;
    }
    // 0x808056EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808056F0: beq         $v0, $at, L_808058D8
    if (ctx->r2 == ctx->r1) {
        // 0x808056F4: nop
    
            goto L_808058D8;
    }
    // 0x808056F4: nop

    // 0x808056F8: b           L_808058F8
    // 0x808056FC: nop

        goto L_808058F8;
    // 0x808056FC: nop

L_80805700:
    // 0x80805700: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80805704:
    // 0x80805704: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805708: jal         0x80805BA0
    // 0x8080570C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80805BA0_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080570C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80805710: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80805714: bnel        $s1, $s0, L_80805704
    if (ctx->r17 != ctx->r16) {
        // 0x80805718: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80805704;
    }
    goto skip_0;
    // 0x80805718: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x8080571C: b           L_8080592C
    // 0x80805720: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8080592C;
    // 0x80805720: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80805724:
    // 0x80805724: jal         0x80088360
    // 0x80805728: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80805728: nop

    after_1:
    // 0x8080572C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80805730: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80805734: jal         0x80100094
    // 0x80805738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80805738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080573C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80805740: blez        $s7, L_8080588C
    if (SIGNED(ctx->r23) <= 0) {
        // 0x80805744: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8080588C;
    }
    // 0x80805744: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80805748: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080574C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80805750: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80805754: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80805758: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8080575C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80805760:
    // 0x80805760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805764: jal         0x80016068
    // 0x80805768: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80016068(rdram, ctx);
        goto after_3;
    // 0x80805768: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x8080576C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805770: jal         0x80015E80
    // 0x80805774: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80015E80(rdram, ctx);
        goto after_4;
    // 0x80805774: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_4:
    // 0x80805778: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8080577C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80805780: beq         $v0, $zero, L_808057BC
    if (ctx->r2 == 0) {
        // 0x80805784: nop
    
            goto L_808057BC;
    }
    // 0x80805784: nop

    // 0x80805788: beq         $v0, $s4, L_808057A0
    if (ctx->r2 == ctx->r20) {
        // 0x8080578C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_808057A0;
    }
    // 0x8080578C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80805790: beq         $v0, $fp, L_8080585C
    if (ctx->r2 == ctx->r30) {
        // 0x80805794: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8080585C;
    }
    // 0x80805794: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80805798: b           L_80805880
    // 0x8080579C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80805880;
    // 0x8080579C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808057A0:
    // 0x808057A0: addu        $a0, $s5, $t7
    ctx->r4 = ADD32(ctx->r21, ctx->r15);
    // 0x808057A4: jal         0x800D9078
    // 0x808057A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x808057A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_5:
    // 0x808057AC: beql        $v0, $zero, L_80805880
    if (ctx->r2 == 0) {
        // 0x808057B0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80805880;
    }
    goto skip_1;
    // 0x808057B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x808057B4: b           L_8080587C
    // 0x808057B8: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
        goto L_8080587C;
    // 0x808057B8: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
L_808057BC:
    // 0x808057BC: bne         $s4, $t8, L_808057EC
    if (ctx->r20 != ctx->r24) {
        // 0x808057C0: lwc1        $f0, 0x58($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
            goto L_808057EC;
    }
    // 0x808057C0: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808057C4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808057C8: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
    // 0x808057CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808057D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808057D4: jal         0x80087DF0
    // 0x808057D8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    _gcnewoption_entrypoint_43(rdram, ctx);
        goto after_6;
    // 0x808057D8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_6:
    // 0x808057DC: jal         0x80803CC0
    // 0x808057E0: nop

    func_80803CC0_chgameselect(rdram, ctx);
        goto after_7;
    // 0x808057E0: nop

    after_7:
    // 0x808057E4: b           L_80805880
    // 0x808057E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80805880;
    // 0x808057E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808057EC:
    // 0x808057EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D68) << 16);
    // 0x808057F0: lwc1        $f4, 0x7D68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D68));
    // 0x808057F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808057F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808057FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80805800: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80805804: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80805808: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D6C) << 16);
    // 0x8080580C: bc1f        L_80805828
    if (!c1cs) {
        // 0x80805810: nop
    
            goto L_80805828;
    }
    // 0x80805810: nop

    // 0x80805814: jal         0x808062EC
    // 0x80805818: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    func_808062EC_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80805818: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    after_8:
    // 0x8080581C: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x80805820: b           L_8080587C
    // 0x80805824: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
        goto L_8080587C;
    // 0x80805824: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
L_80805828:
    // 0x80805828: lwc1        $f6, 0x7D6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D6C));
    // 0x8080582C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80805830: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805834: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80805838: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080583C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80805840: bc1fl       L_80805880
    if (!c1cs) {
        // 0x80805844: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80805880;
    }
    goto skip_2;
    // 0x80805844: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80805848: jal         0x808062EC
    // 0x8080584C: addu        $s0, $s5, $t1
    ctx->r16 = ADD32(ctx->r21, ctx->r9);
    func_808062EC_chgameselect(rdram, ctx);
        goto after_9;
    // 0x8080584C: addu        $s0, $s5, $t1
    ctx->r16 = ADD32(ctx->r21, ctx->r9);
    after_9:
    // 0x80805850: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x80805854: b           L_8080587C
    // 0x80805858: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
        goto L_8080587C;
    // 0x80805858: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
L_8080585C:
    // 0x8080585C: bne         $s4, $t2, L_8080587C
    if (ctx->r20 != ctx->r10) {
        // 0x80805860: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080587C;
    }
    // 0x80805860: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80805864: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80805868: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080586C: jal         0x80087DF0
    // 0x80805870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcnewoption_entrypoint_43(rdram, ctx);
        goto after_10;
    // 0x80805870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80805874: jal         0x80803CE0
    // 0x80805878: nop

    func_80803CE0_chgameselect(rdram, ctx);
        goto after_11;
    // 0x80805878: nop

    after_11:
L_8080587C:
    // 0x8080587C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80805880:
    // 0x80805880: bne         $s1, $s7, L_80805760
    if (ctx->r17 != ctx->r23) {
        // 0x80805884: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80805760;
    }
    // 0x80805884: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80805888: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8080588C:
    // 0x8080588C: blez        $s7, L_808058B0
    if (SIGNED(ctx->r23) <= 0) {
        // 0x80805890: addiu       $fp, $zero, 0x2
        ctx->r30 = ADD32(0, 0X2);
            goto L_808058B0;
    }
    // 0x80805890: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80805894: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
L_80805898:
    // 0x80805898: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x8080589C: bne         $fp, $t3, L_808058B0
    if (ctx->r30 != ctx->r11) {
        // 0x808058A0: nop
    
            goto L_808058B0;
    }
    // 0x808058A0: nop

    // 0x808058A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808058A8: bne         $s1, $s7, L_80805898
    if (ctx->r17 != ctx->r23) {
        // 0x808058AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80805898;
    }
    // 0x808058AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808058B0:
    // 0x808058B0: bne         $s1, $s7, L_80805928
    if (ctx->r17 != ctx->r23) {
        // 0x808058B4: lw          $t4, 0x80($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X80);
            goto L_80805928;
    }
    // 0x808058B4: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x808058B8: jal         0x80802F8C
    // 0x808058BC: lw          $a0, 0x30($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X30);
    func_80802F8C_chgameselect(rdram, ctx);
        goto after_12;
    // 0x808058BC: lw          $a0, 0x30($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X30);
    after_12:
    // 0x808058C0: beq         $v0, $zero, L_80805928
    if (ctx->r2 == 0) {
        // 0x808058C4: lw          $t5, 0x80($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X80);
            goto L_80805928;
    }
    // 0x808058C4: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x808058C8: lbu         $t7, 0x65($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X65);
    // 0x808058CC: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808058D0: b           L_80805928
    // 0x808058D4: sb          $t8, 0x65($t5)
    MEM_B(0X65, ctx->r13) = ctx->r24;
        goto L_80805928;
    // 0x808058D4: sb          $t8, 0x65($t5)
    MEM_B(0X65, ctx->r13) = ctx->r24;
L_808058D8:
    // 0x808058D8: jal         0x80087E00
    // 0x808058DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_45(rdram, ctx);
        goto after_13;
    // 0x808058DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x808058E0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x808058E4: addiu       $a1, $v0, 0x1E
    ctx->r5 = ADD32(ctx->r2, 0X1E);
    // 0x808058E8: jal         0x808026C8
    // 0x808058EC: lw          $a0, 0x24($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X24);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_14;
    // 0x808058EC: lw          $a0, 0x24($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X24);
    after_14:
    // 0x808058F0: b           L_8080592C
    // 0x808058F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8080592C;
    // 0x808058F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808058F8:
    // 0x808058F8: jal         0x80015FA0
    // 0x808058FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015FA0(rdram, ctx);
        goto after_15;
    // 0x808058FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80805900: beq         $v0, $zero, L_80805928
    if (ctx->r2 == 0) {
        // 0x80805904: lw          $t0, 0x80($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X80);
            goto L_80805928;
    }
    // 0x80805904: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80805908: jal         0x80802F8C
    // 0x8080590C: lw          $a0, 0x30($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X30);
    func_80802F8C_chgameselect(rdram, ctx);
        goto after_16;
    // 0x8080590C: lw          $a0, 0x30($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X30);
    after_16:
    // 0x80805910: beql        $v0, $zero, L_8080592C
    if (ctx->r2 == 0) {
        // 0x80805914: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8080592C;
    }
    goto skip_3;
    // 0x80805914: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x80805918: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x8080591C: lbu         $t2, 0x65($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X65);
    // 0x80805920: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80805924: sb          $t3, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r11;
L_80805928:
    // 0x80805928: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8080592C:
    // 0x8080592C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80805930: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80805934: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80805938: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080593C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80805940: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80805944: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80805948: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8080594C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80805950: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80805954: jr          $ra
    // 0x80805958: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80805958: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
