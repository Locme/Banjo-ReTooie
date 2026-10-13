#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void mlwave_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800388: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080038C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800390: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800394: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800398: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080039C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808003A0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x808003A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808003A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808003AC: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x808003B0: nop

    // 0x808003B4: bc1tl       L_808003F4
    if (c1cs) {
        // 0x808003B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808003F4;
    }
    goto skip_0;
    // 0x808003B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808003BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_808003C0:
    // 0x808003C0: jal         0x80800230
    // 0x808003C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mlwave_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808003C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808003C8: beql        $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x808003CC: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_808003DC;
    }
    goto skip_1;
    // 0x808003CC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x808003D0: b           L_808003F4
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003F4;
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003D8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_808003DC:
    // 0x808003DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808003E0: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x808003E4: nop

    // 0x808003E8: bc1fl       L_808003C0
    if (!c1cs) {
        // 0x808003EC: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_808003C0;
    }
    goto skip_2;
    // 0x808003EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x808003F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003F4:
    // 0x808003F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003F8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808003FC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800400: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800404: jr          $ra
    // 0x80800408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080040C: nop

;}
RECOMP_FUNC void ncpodfixpos_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000D4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808000D8: jal         0x8001B754
    // 0x808000DC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x808000DC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_808000C4_scinfobar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D0: lbu         $a1, 0x32($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X32);
    // 0x808000D4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x808000D8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E0: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x808000E4: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x808000E8: beq         $a1, $zero, L_808000F8
    if (ctx->r5 == 0) {
        // 0x808000EC: sh          $t6, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r14;
            goto L_808000F8;
    }
    // 0x808000EC: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x808000F0: jal         0x800E8C08
    // 0x808000F4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    func_800E8C08(rdram, ctx);
        goto after_0;
    // 0x808000F4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_0:
L_808000F8:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x80800000
    // 0x80800100: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    func_80800000_scinfobar(rdram, ctx);
        goto after_1;
    // 0x80800100: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    after_1:
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x808004F0
    // 0x8080010C: lh          $a1, 0x2C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2C);
    scinfobar_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080010C: lh          $a1, 0x2C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2C);
    after_2:
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: jal         0x80800510
    // 0x80800118: lh          $a1, 0x2E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2E);
    scinfobar_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800118: lh          $a1, 0x2E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2E);
    after_3:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x808003E8
    // 0x80800124: lh          $a1, 0x30($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X30);
    scinfobar_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800124: lh          $a1, 0x30($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X30);
    after_4:
    // 0x80800128: jal         0x808000B0
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B0_scinfobar(rdram, ctx);
        goto after_5;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_8009E130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E130: jr          $ra
    // 0x8009E134: addiu       $v0, $zero, 0xF4
    ctx->r2 = ADD32(0, 0XF4);
    return;
    // 0x8009E134: addiu       $v0, $zero, 0xF4
    ctx->r2 = ADD32(0, 0XF4);
;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880B0: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x800880B0);
    return;
    // 0x800880B4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800E3C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3C34: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3C38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3C3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3C40: jal         0x800CA668
    // 0x800E3C44: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA668(rdram, ctx);
        goto after_0;
    // 0x800E3C44: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3C50: jr          $ra
    // 0x800E3C54: nop

    return;
    // 0x800E3C54: nop

;}
RECOMP_FUNC void func_8001D1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1E0: addiu       $sp, $sp, -0xA90
    ctx->r29 = ADD32(ctx->r29, -0XA90);
    // 0x8001D1E4: sw          $s0, 0xA48($sp)
    MEM_W(0XA48, ctx->r29) = ctx->r16;
    // 0x8001D1E8: sw          $s1, 0xA4C($sp)
    MEM_W(0XA4C, ctx->r29) = ctx->r17;
    // 0x8001D1EC: sw          $s2, 0xA50($sp)
    MEM_W(0XA50, ctx->r29) = ctx->r18;
    // 0x8001D1F0: sw          $s3, 0xA54($sp)
    MEM_W(0XA54, ctx->r29) = ctx->r19;
    // 0x8001D1F4: sw          $s4, 0xA58($sp)
    MEM_W(0XA58, ctx->r29) = ctx->r20;
    // 0x8001D1F8: sw          $s5, 0xA5C($sp)
    MEM_W(0XA5C, ctx->r29) = ctx->r21;
    // 0x8001D1FC: sw          $s6, 0xA60($sp)
    MEM_W(0XA60, ctx->r29) = ctx->r22;
    // 0x8001D200: sw          $s7, 0xA64($sp)
    MEM_W(0XA64, ctx->r29) = ctx->r23;
    // 0x8001D204: sw          $ra, 0xA80($sp)
    MEM_W(0XA80, ctx->r29) = ctx->r31;
    // 0x8001D208: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8001D20C: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x8001D210: addiu       $s6, $s6, -0x38F0
    ctx->r22 = ADD32(ctx->r22, -0X38F0);
    // 0x8001D214: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8001D218: addiu       $t2, $sp, 0x548
    ctx->r10 = ADD32(ctx->r29, 0X548);
    // 0x8001D21C: addiu       $t1, $t2, 0x240
    ctx->r9 = ADD32(ctx->r10, 0X240);
L_8001D220:
    // 0x8001D220: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001D224: bne         $t2, $t1, L_8001D220
    if (ctx->r10 != ctx->r9) {
        // 0x8001D228: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_8001D220;
    }
    // 0x8001D228: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x8001D22C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x8001D230: addiu       $t1, $t2, 0x1C0
    ctx->r9 = ADD32(ctx->r10, 0X1C0);
L_8001D234:
    // 0x8001D234: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001D238: bne         $t2, $t1, L_8001D234
    if (ctx->r10 != ctx->r9) {
        // 0x8001D23C: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_8001D234;
    }
    // 0x8001D23C: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x8001D240: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8001D244: addiu       $t1, $t2, 0x60
    ctx->r9 = ADD32(ctx->r10, 0X60);
L_8001D248:
    // 0x8001D248: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001D24C: bne         $t2, $t1, L_8001D248
    if (ctx->r10 != ctx->r9) {
        // 0x8001D250: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_8001D248;
    }
    // 0x8001D250: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x8001D254: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8001D258: addiu       $t1, $t2, 0x20
    ctx->r9 = ADD32(ctx->r10, 0X20);
L_8001D25C:
    // 0x8001D25C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001D260: bne         $t2, $t1, L_8001D25C
    if (ctx->r10 != ctx->r9) {
        // 0x8001D264: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_8001D25C;
    }
    // 0x8001D264: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x8001D268: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8001D26C: sw          $t0, 0x9CC($sp)
    MEM_W(0X9CC, ctx->r29) = ctx->r8;
    // 0x8001D270: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x8001D274: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x8001D278: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x8001D27C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8001D280: addiu       $a3, $a3, 0x1772
    ctx->r7 = ADD32(ctx->r7, 0X1772);
    // 0x8001D284: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001D288: addiu       $t7, $t7, 0x17FF
    ctx->r15 = ADD32(ctx->r15, 0X17FF);
    // 0x8001D28C: addiu       $t8, $sp, 0x9C8
    ctx->r24 = ADD32(ctx->r29, 0X9C8);
    // 0x8001D290: jal         0x8001CA6C
    // 0x8001D294: addiu       $t9, $sp, 0x9CC
    ctx->r25 = ADD32(ctx->r29, 0X9CC);
    huft_build_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D294: addiu       $t9, $sp, 0x9CC
    ctx->r25 = ADD32(ctx->r29, 0X9CC);
    after_0:
    // 0x8001D298: addiu       $t0, $sp, 0x548
    ctx->r8 = ADD32(ctx->r29, 0X548);
    // 0x8001D29C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8001D2A0: addiu       $t2, $t0, 0x78
    ctx->r10 = ADD32(ctx->r8, 0X78);
L_8001D2A4:
    // 0x8001D2A4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8001D2A8: bne         $t0, $t2, L_8001D2A4
    if (ctx->r8 != ctx->r10) {
        // 0x8001D2AC: sw          $t1, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r9;
            goto L_8001D2A4;
    }
    // 0x8001D2AC: sw          $t1, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r9;
    // 0x8001D2B0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8001D2B4: sw          $t0, 0x9D4($sp)
    MEM_W(0X9D4, ctx->r29) = ctx->r8;
    // 0x8001D2B8: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x8001D2BC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8001D2C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8001D2C4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8001D2C8: addiu       $a3, $a3, 0x17B0
    ctx->r7 = ADD32(ctx->r7, 0X17B0);
    // 0x8001D2CC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001D2D0: addiu       $t7, $t7, 0x181E
    ctx->r15 = ADD32(ctx->r15, 0X181E);
    // 0x8001D2D4: addiu       $t8, $sp, 0x9D0
    ctx->r24 = ADD32(ctx->r29, 0X9D0);
    // 0x8001D2D8: jal         0x8001CA6C
    // 0x8001D2DC: addiu       $t9, $sp, 0x9D4
    ctx->r25 = ADD32(ctx->r29, 0X9D4);
    huft_build_recomp(rdram, ctx);
        goto after_1;
    // 0x8001D2DC: addiu       $t9, $sp, 0x9D4
    ctx->r25 = ADD32(ctx->r29, 0X9D4);
    after_1:
    // 0x8001D2E0: lw          $s0, 0xA48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA48);
    // 0x8001D2E4: lw          $s1, 0xA4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4C);
    // 0x8001D2E8: lw          $s2, 0xA50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA50);
    // 0x8001D2EC: lw          $s3, 0xA54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA54);
    // 0x8001D2F0: lw          $s4, 0xA58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA58);
    // 0x8001D2F4: lw          $s5, 0xA5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA5C);
    // 0x8001D2F8: lw          $s6, 0xA60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA60);
    // 0x8001D2FC: lw          $s7, 0xA64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XA64);
    // 0x8001D300: lw          $ra, 0xA80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA80);
    // 0x8001D304: jr          $ra
    // 0x8001D308: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
    return;
    // 0x8001D308: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
;}
RECOMP_FUNC void _plcamera_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087910: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x80087910);
    return;
    // 0x80087914: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80801428_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080142C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801430: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801434: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801438: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x8080143C: jal         0x8008CB3C
    // 0x80801440: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80801440: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_0:
    // 0x80801444: jal         0x80800000
    // 0x80801448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_1;
    // 0x80801448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080144C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801450: jal         0x8009B94C
    // 0x80801454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_2;
    // 0x80801454: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080145C: jal         0x800852B0
    // 0x80801460: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _baswim_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80801460: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801468: jal         0x8009BA9C
    // 0x8080146C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x8080146C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801470: jal         0x80800030
    // 0x80801474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_5;
    // 0x80801474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801478: jal         0x800A0024
    // 0x8080147C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0024(rdram, ctx);
        goto after_6;
    // 0x8080147C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801484: jal         0x80085298
    // 0x80801488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _baswim_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80801488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080148C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801494: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801498: jr          $ra
    // 0x8080149C: nop

    return;
    // 0x8080149C: nop

;}
RECOMP_FUNC void bashoessuck_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8080022C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800230: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800234: jal         0x80092BC4
    // 0x80800238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80092BC4(rdram, ctx);
        goto after_0;
    // 0x80800238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080023C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x800932CC
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800932CC(rdram, ctx);
        goto after_1;
    // 0x80800248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080024C: jal         0x80084E98
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800254: bne         $v0, $zero, L_80800294
    if (ctx->r2 != 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x8009BB18
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_3;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800264: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800268: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080026C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800270: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800274: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800278: jal         0x800EFA4C
    // 0x8080027C: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x8080027C: nop

    after_4:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x8009C914
    // 0x80800288: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    yaw_setIdeal(rdram, ctx);
        goto after_5;
    // 0x80800288: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8080028C: b           L_808004A8
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A8;
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800294:
    // 0x80800294: jal         0x80084E78
    // 0x80800298: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    _bamovespline_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800298: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_6:
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x80800000
    // 0x808002A4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    bashoessuck_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808002A4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_7:
    // 0x808002A8: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x808002AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x800932CC
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800932CC(rdram, ctx);
        goto after_8;
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x80085028
    // 0x808002C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _bashoes_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x808002C0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x808002C4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808002C8: jal         0x800EEAA4
    // 0x808002CC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EEAA4(rdram, ctx);
        goto after_10;
    // 0x808002CC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x808002D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002D4: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808002D8: jal         0x800EFA20
    // 0x808002DC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EFA20(rdram, ctx);
        goto after_11;
    // 0x808002DC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x808002E0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808002E4: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x808002E8: jal         0x800EFB24
    // 0x808002EC: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x808002EC: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_12:
    // 0x808002F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808002F4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808002F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800300: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800304: jal         0x800EFA4C
    // 0x80800308: nop

    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x80800308: nop

    after_13:
    // 0x8080030C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(596, 0X734) << 16);
    // 0x80800310: lwc1        $f4, 0x734($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(596, 0X734));
    // 0x80800314: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800318: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080031C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800320: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800324: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800328: bc1f        L_80800348
    if (!c1cs) {
        // 0x8080032C: nop
    
            goto L_80800348;
    }
    // 0x8080032C: nop

    // 0x80800330: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800334: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800338: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080033C: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x80800340: b           L_8080041C
    // 0x80800344: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
        goto L_8080041C;
    // 0x80800344: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
L_80800348:
    // 0x80800348: jal         0x800EFA4C
    // 0x8080034C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x8080034C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_14:
    // 0x80800350: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800354: jal         0x800F1EA4
    // 0x80800358: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    func_800F1EA4(rdram, ctx);
        goto after_15;
    // 0x80800358: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_15:
    // 0x8080035C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800360: jal         0x800F1C98
    // 0x80800364: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800F1C98(rdram, ctx);
        goto after_16;
    // 0x80800364: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_16:
    // 0x80800368: jal         0x80013AAC
    // 0x8080036C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013AAC(rdram, ctx);
        goto after_17;
    // 0x8080036C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_17:
    // 0x80800370: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x80800374: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80800378: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8080037C: jal         0x800EE97C
    // 0x80800380: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EE97C(rdram, ctx);
        goto after_18;
    // 0x80800380: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_18:
    // 0x80800384: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800388: jal         0x800F1C98
    // 0x8080038C: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_800F1C98(rdram, ctx);
        goto after_19;
    // 0x8080038C: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_19:
    // 0x80800390: jal         0x80013AAC
    // 0x80800394: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013AAC(rdram, ctx);
        goto after_20;
    // 0x80800394: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_20:
    // 0x80800398: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080039C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003A0: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808003A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808003A8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x808003AC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003B4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808003B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003BC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808003C0: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x808003C4: bc1f        L_808003D8
    if (!c1cs) {
        // 0x808003C8: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_808003D8;
    }
    // 0x808003C8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x808003CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003D0: nop

    // 0x808003D4: sub.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f12.fl;
L_808003D8:
    // 0x808003D8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x808003DC: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x808003E0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808003E4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808003E8: jal         0x800EF934
    // 0x808003EC: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    func_800EF934(rdram, ctx);
        goto after_21;
    // 0x808003EC: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    after_21:
    // 0x808003F0: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x808003F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808003F8: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x808003FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800400: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800404: nop

    // 0x80800408: bc1fl       L_80800420
    if (!c1cs) {
        // 0x8080040C: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80800420;
    }
    goto skip_0;
    // 0x8080040C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80800410: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800414: nop

    // 0x80800418: sub.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f2.fl;
L_8080041C:
    // 0x8080041C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80800420:
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: beql        $t6, $zero, L_80800458
    if (ctx->r14 == 0) {
        // 0x80800428: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800458;
    }
    goto skip_1;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080042C: jal         0x8009BB18
    // 0x80800430: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    func_8009BB18(rdram, ctx);
        goto after_22;
    // 0x80800430: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    after_22:
    // 0x80800434: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800438: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080043C: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80800440: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800444: nop

    // 0x80800448: bc1fl       L_80800458
    if (!c1cs) {
        // 0x8080044C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800458;
    }
    goto skip_2;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800450: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800458:
    // 0x80800458: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8080045C: jal         0x800932BC
    // 0x80800460: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    func_800932BC(rdram, ctx);
        goto after_23;
    // 0x80800460: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    after_23:
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x8009BF5C
    // 0x8080046C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    func_8009BF5C(rdram, ctx);
        goto after_24;
    // 0x8080046C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    after_24:
    // 0x80800470: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080047C: jal         0x8009C914
    // 0x80800480: nop

    yaw_setIdeal(rdram, ctx);
        goto after_25;
    // 0x80800480: nop

    after_25:
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: jal         0x8009C4CC
    // 0x8080048C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_26;
    // 0x8080048C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_26:
    // 0x80800490: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800494: bnel        $t7, $zero, L_808004A8
    if (ctx->r15 != 0) {
        // 0x80800498: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004A8;
    }
    goto skip_3;
    // 0x80800498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8080049C: jal         0x8009C974
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_27;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
L_808004A4:
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004A8:
    // 0x808004A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004AC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x808004B0: jr          $ra
    // 0x808004B4: nop

    return;
    // 0x808004B4: nop

;}
RECOMP_FUNC void func_8010A654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A654: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8010A658: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8010A65C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8010A660: sll         $t7, $v1, 28
    ctx->r15 = S32(ctx->r3 << 28);
    // 0x8010A664: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8010A668: beq         $a1, $zero, L_8010A684
    if (ctx->r5 == 0) {
        // 0x8010A66C: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8010A684;
    }
    // 0x8010A66C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8010A670: lbu         $t0, 0xB($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XB);
    // 0x8010A674: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x8010A678: sb          $t1, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r9;
    // 0x8010A67C: jr          $ra
    // 0x8010A680: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x8010A680: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8010A684:
    // 0x8010A684: lbu         $t2, 0xB($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XB);
    // 0x8010A688: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x8010A68C: sb          $t3, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r11;
    // 0x8010A690: jr          $ra
    // 0x8010A694: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010A694: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800D9004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9004: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D9008: lw          $t6, -0x389C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X389C);
    // 0x800D900C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D9010: lwc1        $f8, 0x5D1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5D1C);
    // 0x800D9014: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D9018: nop

    // 0x800D901C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D9020: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D9024: jr          $ra
    // 0x800D9028: nop

    return;
    // 0x800D9028: nop

;}
RECOMP_FUNC void func_80807FD8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807FE0: jal         0x80100094
    // 0x80807FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807FE8: sw          $zero, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = 0;
    // 0x80807FEC: sb          $zero, 0xA6($v0)
    MEM_B(0XA6, ctx->r2) = 0;
    // 0x80807FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807FF8: jr          $ra
    // 0x80807FFC: nop

    return;
    // 0x80807FFC: nop

;}
RECOMP_FUNC void chlinkpipefan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800530: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080053C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800540: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800544: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800548: jal         0x80106790
    // 0x8080054C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080054C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800550: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800554: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800558: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080055C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800560: lwc1        $f12, 0x54($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80800564: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    // 0x80800568: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080056C: jal         0x800F12D4
    // 0x80800570: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x80800570: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800574: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800578: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080057C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800580: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800584: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x80800588: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8080058C: beql        $at, $zero, L_8080062C
    if (ctx->r1 == 0) {
        // 0x80800590: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080062C;
    }
    goto skip_0;
    // 0x80800590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800594: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800598: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x8080059C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808005A0: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x808005A4: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x808005A8: nop

    // 0x808005AC: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x808005B0: beql        $v1, $zero, L_80800600
    if (ctx->r3 == 0) {
        // 0x808005B4: mfc1        $v1, $f6
        ctx->r3 = (int32_t)ctx->f6.u32l;
            goto L_80800600;
    }
    goto skip_1;
    // 0x808005B4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x808005B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808005C0: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x808005C4: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x808005C8: nop

    // 0x808005CC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x808005D0: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x808005D4: nop

    // 0x808005D8: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x808005DC: bne         $v1, $zero, L_808005F4
    if (ctx->r3 != 0) {
        // 0x808005E0: nop
    
            goto L_808005F4;
    }
    // 0x808005E0: nop

    // 0x808005E4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808005E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808005EC: b           L_8080060C
    // 0x808005F0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_8080060C;
    // 0x808005F0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_808005F4:
    // 0x808005F4: b           L_8080060C
    // 0x808005F8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_8080060C;
    // 0x808005F8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x808005FC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
L_80800600:
    // 0x80800600: nop

    // 0x80800604: bltz        $v1, L_808005F4
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800608: nop
    
            goto L_808005F4;
    }
    // 0x80800608: nop

L_8080060C:
    // 0x8080060C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800610: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80800614: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80800618:
    // 0x80800618: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8080061C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800620: bne         $at, $zero, L_80800618
    if (ctx->r1 != 0) {
        // 0x80800624: sb          $v1, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r3;
            goto L_80800618;
    }
    // 0x80800624: sb          $v1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r3;
    // 0x80800628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080062C:
    // 0x8080062C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800630: jr          $ra
    // 0x80800634: nop

    return;
    // 0x80800634: nop

;}
RECOMP_FUNC void func_800D35BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D35BC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D35C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D35C4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D35C8: jr          $ra
    // 0x800D35CC: lbu         $v0, -0x4A9E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4A9E);
    return;
    // 0x800D35CC: lbu         $v0, -0x4A9E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4A9E);
;}
RECOMP_FUNC void func_80801C0C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C14: jal         0x80800ECC
    // 0x80801C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801C18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801C1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801C20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801C24: jal         0x80801980
    // 0x80801C28: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_80801980_bstnt(rdram, ctx);
        goto after_1;
    // 0x80801C28: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80801C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C34: jr          $ra
    // 0x80801C38: nop

    return;
    // 0x80801C38: nop

;}
RECOMP_FUNC void bsdronesuckunder_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800154: jal         0x800852F0
    // 0x80800158: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x80800158: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x8080015C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: jal         0x80085300
    // 0x80800164: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _batimer_get(rdram, ctx);
        goto after_1;
    // 0x80800164: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x80800168: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800174: nop

    // 0x80800178: bc1t        L_80800190
    if (c1cs) {
        // 0x8080017C: nop
    
            goto L_80800190;
    }
    // 0x8080017C: nop

    // 0x80800180: jal         0x80800000
    // 0x80800184: nop

    func_80800000_bsdronesuckunder(rdram, ctx);
        goto after_2;
    // 0x80800184: nop

    after_2:
    // 0x80800188: b           L_8080019C
    // 0x8080018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080019C;
    // 0x8080018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800190:
    // 0x80800190: jal         0x8009BA9C
    // 0x80800194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_3;
    // 0x80800194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080019C:
    // 0x8080019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

    // 0x808001A8: nop

    // 0x808001AC: nop

;}
RECOMP_FUNC void basquash_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080011C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800120: lw          $t6, 0x11C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X11C);
    // 0x80800124: sb          $a1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r5;
    // 0x80800128: jal         0x80800008
    // 0x8080012C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800008_basquash(rdram, ctx);
        goto after_0;
    // 0x8080012C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void _bsdronexform_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831C8: syscall     50
    recomp_syscall_handler(rdram, ctx, 0x800831C8);
    return;
    // 0x800831CC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void gczoombox_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808033C0: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x808033C4: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x808033C8: jr          $ra
    // 0x808033CC: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x808033CC: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80102394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010239C: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x801023A0: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    // 0x801023A4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x801023A8: bgez        $t8, L_801023C8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801023AC: nop
    
            goto L_801023C8;
    }
    // 0x801023AC: nop

    // 0x801023B0: jal         0x8010108C
    // 0x801023B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x801023B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801023B8: jal         0x80101080
    // 0x801023BC: nop

    func_80101080(rdram, ctx);
        goto after_1;
    // 0x801023BC: nop

    after_1:
    // 0x801023C0: b           L_801023D8
    // 0x801023C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801023D8;
    // 0x801023C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801023C8:
    // 0x801023C8: jal         0x80100368
    // 0x801023CC: nop

    func_80100368(rdram, ctx);
        goto after_2;
    // 0x801023CC: nop

    after_2:
    // 0x801023D0: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x801023D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801023D8:
    // 0x801023D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801023DC: jr          $ra
    // 0x801023E0: nop

    return;
    // 0x801023E0: nop

;}
RECOMP_FUNC void func_80800480_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800484: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080048C: jal         0x8009EF28
    // 0x80800490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getX(rdram, ctx);
        goto after_0;
    // 0x80800490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800494: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800498: jal         0x800A4CA8
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_1;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x808004A8: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    // 0x808004AC: jal         0x800892E0
    // 0x808004B0: lui         $a3, 0x43AF
    ctx->r7 = S32(0X43AF << 16);
    _ncbafly_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808004B0: lui         $a3, 0x43AF
    ctx->r7 = S32(0X43AF << 16);
    after_2:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x800919F4
    // 0x808004BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bakey_held(rdram, ctx);
        goto after_3;
    // 0x808004BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808004C0: beq         $v0, $zero, L_808004F0
    if (ctx->r2 == 0) {
        // 0x808004C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F0;
    }
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808004D0: jal         0x8009C99C
    // 0x808004D4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_4;
    // 0x808004D4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_4:
    // 0x808004D8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808004DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808004E0: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x808004E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004E8: b           L_80800514
    // 0x808004EC: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
        goto L_80800514;
    // 0x808004EC: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
L_808004F0:
    // 0x808004F0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808004F4: jal         0x8009C99C
    // 0x808004F8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_5;
    // 0x808004F8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_5:
    // 0x808004FC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800500: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800504: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80800508: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080050C: nop

    // 0x80800510: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
L_80800514:
    // 0x80800514: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800518: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080051C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800520: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800524: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800528: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080052C: jal         0x800F10B4
    // 0x80800530: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800530: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x80800534: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800538: jal         0x8009C4CC
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_setIdeal(rdram, ctx);
        goto after_7;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800540: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800544: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800548: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080054C: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80800550: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800554: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800558: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080055C: jal         0x800F10B4
    // 0x80800560: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800560: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
    // 0x80800564: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800568: jal         0x80084C90
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800570: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8080057C: jal         0x8009C990
    // 0x80800580: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_10;
    // 0x80800580: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x80800584: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080058C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800590: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800594: jal         0x8009C914
    // 0x80800598: nop

    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x80800598: nop

    after_11:
    // 0x8080059C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808005A8: jr          $ra
    // 0x808005AC: nop

    return;
    // 0x808005AC: nop

;}
RECOMP_FUNC void func_800F69E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F69E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F69EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F69F0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F69F4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F69F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F69FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6A00: jal         0x8008E078
    // 0x800F6A04: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    player_isStable(rdram, ctx);
        goto after_0;
    // 0x800F6A04: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6A08: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6A0C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F6A10: beq         $t7, $zero, L_800F6A28
    if (ctx->r15 == 0) {
        // 0x800F6A14: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6A28;
    }
    // 0x800F6A14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6A18: jal         0x8009659C
    // 0x800F6A1C: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    func_8009659C(rdram, ctx);
        goto after_1;
    // 0x800F6A1C: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    after_1:
    // 0x800F6A20: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6A24: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800F6A28:
    // 0x800F6A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6A2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6A30: jr          $ra
    // 0x800F6A34: nop

    return;
    // 0x800F6A34: nop

;}
RECOMP_FUNC void func_800A235C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A235C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800A2360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2364: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A2368: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A236C: jal         0x800A1F0C
    // 0x800A2370: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800A1F0C(rdram, ctx);
        goto after_0;
    // 0x800A2370: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_0:
    // 0x800A2374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2378: jal         0x800A2314
    // 0x800A237C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800A2314(rdram, ctx);
        goto after_1;
    // 0x800A237C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x800A2380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2384: jal         0x80092B8C
    // 0x800A2388: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_80092B8C(rdram, ctx);
        goto after_2;
    // 0x800A2388: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_2:
    // 0x800A238C: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x800A2390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2394: jal         0x8009C128
    // 0x800A2398: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x800A2398: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_3:
    // 0x800A239C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x800A23A0: jal         0x800EF04C
    // 0x800A23A4: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x800A23A4: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_4:
    // 0x800A23A8: lw          $t6, 0xB4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XB4);
    // 0x800A23AC: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x800A23B0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x800A23B4: jal         0x800B3494
    // 0x800A23B8: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800B3494(rdram, ctx);
        goto after_5;
    // 0x800A23B8: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_5:
    // 0x800A23BC: lw          $t7, 0xB4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB4);
    // 0x800A23C0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x800A23C4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800A23C8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x800A23CC: jal         0x800B37A4
    // 0x800A23D0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    func_800B37A4(rdram, ctx);
        goto after_6;
    // 0x800A23D0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_6:
    // 0x800A23D4: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x800A23D8: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800A23DC: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x800A23E0: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800A23E4: beq         $at, $zero, L_800A2458
    if (ctx->r1 == 0) {
        // 0x800A23E8: nop
    
            goto L_800A2458;
    }
    // 0x800A23E8: nop

    // 0x800A23EC: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800A23F0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800A23F4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800A23F8: beq         $t9, $zero, L_800A2458
    if (ctx->r25 == 0) {
        // 0x800A23FC: nop
    
            goto L_800A2458;
    }
    // 0x800A23FC: nop

    // 0x800A2400: jal         0x800C8960
    // 0x800A2404: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    func_800C8960(rdram, ctx);
        goto after_7;
    // 0x800A2404: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_7:
    // 0x800A2408: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800A240C: jal         0x800A22C8
    // 0x800A2410: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800A22C8(rdram, ctx);
        goto after_8;
    // 0x800A2410: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_8:
    // 0x800A2414: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800A2418: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800A241C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800A2420: beq         $v1, $zero, L_800A2430
    if (ctx->r3 == 0) {
        // 0x800A2424: lw          $t0, 0x68($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X68);
            goto L_800A2430;
    }
    // 0x800A2424: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800A2428: b           L_800A2438
    // 0x800A242C: lwc1        $f0, 0x18($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X18);
        goto L_800A2438;
    // 0x800A242C: lwc1        $f0, 0x18($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X18);
L_800A2430:
    // 0x800A2430: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A2434: nop

L_800A2438:
    // 0x800A2438: lw          $t1, 0xB4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB4);
    // 0x800A243C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A2440: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x800A2444: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x800A2448: jal         0x800B36C0
    // 0x800A244C: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    func_800B36C0(rdram, ctx);
        goto after_9;
    // 0x800A244C: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    after_9:
    // 0x800A2450: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800A2454: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_800A2458:
    // 0x800A2458: beq         $v1, $zero, L_800A2520
    if (ctx->r3 == 0) {
        // 0x800A245C: lw          $a1, 0x68($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X68);
            goto L_800A2520;
    }
    // 0x800A245C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800A2460: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800A2464: jal         0x800EE830
    // 0x800A2468: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE830(rdram, ctx);
        goto after_10;
    // 0x800A2468: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_10:
    // 0x800A246C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800A2470: lw          $a1, 0xB4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB4);
    // 0x800A2474: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800A2478: jal         0x800EE830
    // 0x800A247C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800EE830(rdram, ctx);
        goto after_11;
    // 0x800A247C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_11:
    // 0x800A2480: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A2484: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A2488: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
L_800A248C:
    // 0x800A248C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800A2490: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A2494: addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // 0x800A2498: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800A249C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A24A0: beq         $at, $zero, L_800A24D0
    if (ctx->r1 == 0) {
        // 0x800A24A4: addiu       $t3, $a0, 0x28
        ctx->r11 = ADD32(ctx->r4, 0X28);
            goto L_800A24D0;
    }
    // 0x800A24A4: addiu       $t3, $a0, 0x28
    ctx->r11 = ADD32(ctx->r4, 0X28);
    // 0x800A24A8: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800A24AC: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800A24B0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A24B4: addu        $v0, $t4, $a2
    ctx->r2 = ADD32(ctx->r12, ctx->r6);
    // 0x800A24B8: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x800A24BC: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800A24C0: beql        $at, $zero, L_800A2504
    if (ctx->r1 == 0) {
        // 0x800A24C4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800A2504;
    }
    goto skip_0;
    // 0x800A24C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_0:
    // 0x800A24C8: b           L_800A2500
    // 0x800A24CC: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
        goto L_800A2500;
    // 0x800A24CC: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800A24D0:
    // 0x800A24D0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A24D4: beq         $at, $zero, L_800A2500
    if (ctx->r1 == 0) {
        // 0x800A24D8: addiu       $t6, $a0, -0x28
        ctx->r14 = ADD32(ctx->r4, -0X28);
            goto L_800A2500;
    }
    // 0x800A24D8: addiu       $t6, $a0, -0x28
    ctx->r14 = ADD32(ctx->r4, -0X28);
    // 0x800A24DC: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x800A24E0: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800A24E4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800A24E8: addu        $v0, $t7, $a2
    ctx->r2 = ADD32(ctx->r15, ctx->r6);
    // 0x800A24EC: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800A24F0: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A24F4: beql        $at, $zero, L_800A2504
    if (ctx->r1 == 0) {
        // 0x800A24F8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800A2504;
    }
    goto skip_1;
    // 0x800A24F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_1:
    // 0x800A24FC: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800A2500:
    // 0x800A2500: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800A2504:
    // 0x800A2504: bne         $a1, $a3, L_800A248C
    if (ctx->r5 != ctx->r7) {
        // 0x800A2508: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800A248C;
    }
    // 0x800A2508: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800A250C: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    // 0x800A2510: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800A2514: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800A2518: jal         0x800EE830
    // 0x800A251C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE830(rdram, ctx);
        goto after_12;
    // 0x800A251C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_12:
L_800A2520:
    // 0x800A2520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2528: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x800A252C: jr          $ra
    // 0x800A2530: nop

    return;
    // 0x800A2530: nop

;}
RECOMP_FUNC void func_800B8CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8CA8: jr          $ra
    // 0x800B8CAC: sb          $a0, -0x7D3C($at)
    MEM_B(-0X7D3C, ctx->r1) = ctx->r4;
    return;
    // 0x800B8CAC: sb          $a0, -0x7D3C($at)
    MEM_B(-0X7D3C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800A3048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A304C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3050: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A3054: jal         0x800D3E40
    // 0x800A3058: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x800A3058: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x800A305C: bne         $v0, $zero, L_800A3070
    if (ctx->r2 != 0) {
        // 0x800A3060: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800A3070;
    }
    // 0x800A3060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A3064: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A3068: b           L_800A30A8
    // 0x800A306C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A30A8;
    // 0x800A306C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3070:
    // 0x800A3070: jal         0x8008E40C
    // 0x800A3074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E40C(rdram, ctx);
        goto after_1;
    // 0x800A3074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A3078: beq         $v0, $zero, L_800A308C
    if (ctx->r2 == 0) {
        // 0x800A307C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_800A308C;
    }
    // 0x800A307C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A3080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3084: b           L_800A30A4
    // 0x800A3088: lwc1        $f0, 0x5560($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5560);
        goto L_800A30A4;
    // 0x800A3088: lwc1        $f0, 0x5560($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5560);
L_800A308C:
    // 0x800A308C: lw          $t7, 0xA0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA0);
    // 0x800A3090: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A3094: lbu         $t8, 0x29($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X29);
    // 0x800A3098: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A309C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A30A0: lwc1        $f0, -0x6B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B30);
L_800A30A4:
    // 0x800A30A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A30A8:
    // 0x800A30A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A30AC: jr          $ra
    // 0x800A30B0: nop

    return;
    // 0x800A30B0: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D58: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D58);
    return;
    // 0x80086D5C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800030_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: jr          $ra
    // 0x80800034: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800034: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800B5AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5ADC: jal         0x800888D0
    // 0x800B5AE0: nop

    _fxsparkle_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800B5AE0: nop

    after_0:
    // 0x800B5AE4: jal         0x800B4428
    // 0x800B5AE8: nop

    func_800B4428(rdram, ctx);
        goto after_1;
    // 0x800B5AE8: nop

    after_1:
    // 0x800B5AEC: jal         0x800B5B40
    // 0x800B5AF0: nop

    func_800B5B40(rdram, ctx);
        goto after_2;
    // 0x800B5AF0: nop

    after_2:
    // 0x800B5AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B5AFC: jr          $ra
    // 0x800B5B00: nop

    return;
    // 0x800B5B00: nop

;}
RECOMP_FUNC void func_800F27D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F27D4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F27D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F27DC: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x800F27E0: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x800F27E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800F27E8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800F27EC: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_800F27F0:
    // 0x800F27F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800F27F4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800F27F8: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800F27FC: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800F2800: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800F2804: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800F2808: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800F280C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F2810: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800F2814: beql        $a0, $t2, L_800F2898
    if (ctx->r4 == ctx->r10) {
        // 0x800F2818: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800F2898;
    }
    goto skip_0;
    // 0x800F2818: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x800F281C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800F2820:
    // 0x800F2820: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800F2824: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800F2828: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800F282C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800F2830: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800F2834: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800F2838: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800F283C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800F2840: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800F2844: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800F2848: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F284C: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800F2850: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800F2854: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800F2858: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800F285C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800F2860: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800F2864: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800F2868: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800F286C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800F2870: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800F2874: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F2878: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800F287C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800F2880: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800F2884: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800F2888: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800F288C: bnel        $a0, $t2, L_800F2820
    if (ctx->r4 != ctx->r10) {
        // 0x800F2890: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800F2820;
    }
    goto skip_1;
    // 0x800F2890: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x800F2894: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800F2898:
    // 0x800F2898: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800F289C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800F28A0: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800F28A4: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800F28A8: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800F28AC: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800F28B0: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800F28B4: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800F28B8: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800F28BC: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800F28C0: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F28C4: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800F28C8: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800F28CC: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800F28D0: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800F28D4: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800F28D8: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800F28DC: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800F28E0: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800F28E4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800F28E8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800F28EC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800F28F0: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800F28F4: bne         $at, $zero, L_800F27F0
    if (ctx->r1 != 0) {
        // 0x800F28F8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800F27F0;
    }
    // 0x800F28F8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800F28FC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800F2900: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800F2904: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_800F2908:
    // 0x800F2908: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F290C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800F2910: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800F2914: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x800F2918: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0XC);
    // 0x800F291C: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x800F2920: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x800F2924: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x800F2928: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x800F292C: bne         $a0, $v0, L_800F2908
    if (ctx->r4 != ctx->r2) {
        // 0x800F2930: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800F2908;
    }
    // 0x800F2930: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800F2934: jr          $ra
    // 0x800F2938: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800F2938: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _fxstep_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A38: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A38);
    return;
    // 0x80088A3C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void bsbeemain_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AD8: jal         0x80082838
    // 0x80800ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800AE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE4: jal         0x800845D8
    // 0x80800AE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800AE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800AEC: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    // 0x80800AF0: ori         $a2, $a2, 0x75F7
    ctx->r6 = ctx->r6 | 0X75F7;
    // 0x80800AF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AF8: jal         0x800845E0
    // 0x80800AFC: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800AFC: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    after_2:
    // 0x80800B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: nop

    return;
    // 0x80800B0C: nop

;}
RECOMP_FUNC void _chbouncycastle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EA0: syscall     255
    recomp_syscall_handler(rdram, ctx, 0x80085EA0);
    return;
    // 0x80085EA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _badata_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084728: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084728);
    return;
    // 0x8008472C: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void func_80102C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102C58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80102C5C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80102C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80102C64: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80102C68: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80102C6C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80102C70: lwc1        $f14, 0x50($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80102C74: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80102C78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80102C7C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80102C80: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80102C84: jal         0x800F1FF0
    // 0x80102C88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_0;
    // 0x80102C88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80102C8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80102C90: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80102C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80102C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80102C9C: jr          $ra
    // 0x80102CA0: nop

    return;
    // 0x80102CA0: nop

;}
RECOMP_FUNC void bsbfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080041C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1D48) << 16);
    // 0x80800420: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800424: jr          $ra
    // 0x80800428: lw          $v0, 0x1D48($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D48));
    return;
    // 0x80800428: lw          $v0, 0x1D48($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D48));
;}
RECOMP_FUNC void chsounder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1684, 0XBC) << 16);
    // 0x8080008C: jr          $ra
    // 0x80800090: addiu       $v0, $v0, 0xBC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1684, 0XBC));
    return;
    // 0x80800090: addiu       $v0, $v0, 0xBC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1684, 0XBC));
    // 0x80800094: nop

    // 0x80800098: nop

    // 0x8080009C: nop

;}
RECOMP_FUNC void func_80014EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014EC8: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x80014ECC: jr          $ra
    // 0x80014ED0: ori         $v0, $v0, 0x1D80
    ctx->r2 = ctx->r2 | 0X1D80;
    return;
    // 0x80014ED0: ori         $v0, $v0, 0x1D80
    ctx->r2 = ctx->r2 | 0X1D80;
;}
RECOMP_FUNC void _bawobble_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085478: syscall     162
    recomp_syscall_handler(rdram, ctx, 0x80085478);
    return;
    // 0x8008547C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bswasher_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084408: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x80084408);
    return;
    // 0x8008440C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_8080364C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080364C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803654: jal         0x801018A4
    // 0x80803658: nop

    func_801018A4(rdram, ctx);
        goto after_0;
    // 0x80803658: nop

    after_0:
    // 0x8080365C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803664: jr          $ra
    // 0x80803668: nop

    return;
    // 0x80803668: nop

;}
RECOMP_FUNC void func_8080007C_chfactorygoblin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800080: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x80800084: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800088: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x80800090: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80800094: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80800098: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8080009C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x808000A0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x808000A4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x808000A8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808000AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808000B8: jal         0x800DC128
    // 0x808000BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x808000BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x808000C0: addiu       $s7, $sp, 0x84
    ctx->r23 = ADD32(ctx->r29, 0X84);
    // 0x808000C4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808000C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808000CC: jal         0x800EE7F8
    // 0x808000D0: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000D0: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    after_1:
    // 0x808000D4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808000D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000DC: lwc1        $f4, 0x38($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X38);
    // 0x808000E0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808000E4: lw          $a1, 0x48($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X48);
    // 0x808000E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000EC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808000F0: jal         0x800EF1B8
    // 0x808000F4: nop

    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x808000F4: nop

    after_2:
    // 0x808000F8: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x808000FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800100: jal         0x800EE7F8
    // 0x80800104: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800104: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_3:
    // 0x80800108: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080010C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800110: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80800114: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800118: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080011C: jal         0x800B53A4
    // 0x80800120: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    func_800B53A4(rdram, ctx);
        goto after_4;
    // 0x80800120: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80800124: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800128: blez        $s4, L_808001BC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8080012C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808001BC;
    }
    // 0x8080012C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800130: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x80800134: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800138: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080013C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800140: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800144: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800148: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080014C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1152, 0X2E0) << 16);
    // 0x80800150: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800154: addiu       $s2, $s2, 0x2E0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1152, 0X2E0));
    // 0x80800158: addiu       $s0, $sp, 0x6C
    ctx->r16 = ADD32(ctx->r29, 0X6C);
    // 0x8080015C: div.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800160: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
L_80800164:
    // 0x80800164: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800170: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800174: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800178: jal         0x800EEB9C
    // 0x8080017C: nop

    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x8080017C: nop

    after_5:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x800EF04C
    // 0x80800188: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800188: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_6:
    // 0x8080018C: lwc1        $f6, 0x38($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X38);
    // 0x80800190: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80800194: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800198: mul.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8080019C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001A0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x808001A4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x808001A8: jal         0x800BABB8
    // 0x808001AC: nop

    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x808001AC: nop

    after_7:
    // 0x808001B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808001B4: bnel        $s1, $s4, L_80800164
    if (ctx->r17 != ctx->r20) {
        // 0x808001B8: mtc1        $s1, $f10
        ctx->f10.u32l = ctx->r17;
            goto L_80800164;
    }
    goto skip_0;
    // 0x808001B8: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    skip_0:
L_808001BC:
    // 0x808001BC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x808001C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808001C4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808001C8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808001CC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x808001D0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x808001D4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x808001D8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x808001DC: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x808001E0: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x808001E4: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x808001E8: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x808001EC: jr          $ra
    // 0x808001F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x808001F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x808001F4: nop

    // 0x808001F8: nop

    // 0x808001FC: nop

;}
RECOMP_FUNC void _bsbansack_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826D0: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826D0);
    return;
    // 0x800826D4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void babackpack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800324: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080032C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800330: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800334: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800338: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800340: jal         0x800DF738
    // 0x80800344: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DF738(rdram, ctx);
        goto after_0;
    // 0x80800344: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x80800348: jal         0x8080021C
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080021C_babackpack(rdram, ctx);
        goto after_1;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800350: jal         0x800DF818
    // 0x80800354: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_2;
    // 0x80800354: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800358: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8080035C: jal         0x80100AC4
    // 0x80800360: lbu         $a0, 0x8($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X8);
    func_80100AC4(rdram, ctx);
        goto after_3;
    // 0x80800360: lbu         $a0, 0x8($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X8);
    after_3:
    // 0x80800364: jal         0x800DF720
    // 0x80800368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_4;
    // 0x80800368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8080036C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80800370: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800374: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80800378: bne         $t9, $at, L_808003D0
    if (ctx->r25 != ctx->r1) {
        // 0x8080037C: nop
    
            goto L_808003D0;
    }
    // 0x8080037C: nop

    // 0x80800380: jal         0x8008CAC8
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_5;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800388: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x8080038C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800390: jal         0x8008B10C
    // 0x80800394: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    func_8008B10C(rdram, ctx);
        goto after_6;
    // 0x80800394: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    after_6:
    // 0x80800398: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8080039C: jal         0x8008B304
    // 0x808003A0: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    func_8008B304(rdram, ctx);
        goto after_7;
    // 0x808003A0: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    after_7:
    // 0x808003A4: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x808003A8: jal         0x8008B4D4
    // 0x808003AC: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    func_8008B4D4(rdram, ctx);
        goto after_8;
    // 0x808003AC: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    after_8:
    // 0x808003B0: jal         0x800DF41C
    // 0x808003B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_9;
    // 0x808003B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x808003B8: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: jal         0x800A0714
    // 0x808003C4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    func_800A0714(rdram, ctx);
        goto after_10;
    // 0x808003C4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_10:
    // 0x808003C8: b           L_808003E0
    // 0x808003CC: nop

        goto L_808003E0;
    // 0x808003CC: nop

L_808003D0:
    // 0x808003D0: jal         0x8008CA74
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CA74(rdram, ctx);
        goto after_11;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808003D8: jal         0x800DF41C
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_12;
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
L_808003E0:
    // 0x808003E0: jal         0x808000E0
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    babackpack_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808003E8: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x808003EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003F0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808003F4: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x808003F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808003FC: jal         0x800DE448
    // 0x80800400: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_800DE448(rdram, ctx);
        goto after_14;
    // 0x80800400: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_14:
    // 0x80800404: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x80800408: lbu         $t5, 0xA($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XA);
    // 0x8080040C: beql        $t5, $zero, L_80800424
    if (ctx->r13 == 0) {
        // 0x80800410: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800424;
    }
    goto skip_0;
    // 0x80800410: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800414: lbu         $t6, 0x9($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X9);
    // 0x80800418: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8080041C: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x80800420: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800424:
    // 0x80800424: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080042C: jr          $ra
    // 0x80800430: nop

    return;
    // 0x80800430: nop

;}
RECOMP_FUNC void func_808011E8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808011EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808011F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808011F8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808011FC: jal         0x80100094
    // 0x80801200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801204: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1840, 0X4D90) << 16);
    // 0x80801208: addiu       $t6, $t6, 0x4D90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1840, 0X4D90));
    // 0x8080120C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801210: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801214: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801218: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8080121C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80801220: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80801224: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80801228: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8080122C: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80801230: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80801234: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x80801238: lw          $at, 0x10($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X10);
    // 0x8080123C: sw          $at, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r1;
    // 0x80801240: lw          $t9, 0x14($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X14);
    // 0x80801244: sw          $t9, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r25;
    // 0x80801248: jal         0x80801350
    // 0x8080124C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80801350_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x8080124C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80801250: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    // 0x80801254: jal         0x80800114
    // 0x80801258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800114_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x80801258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080125C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80801260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801264: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801268: beq         $at, $zero, L_80801278
    if (ctx->r1 == 0) {
        // 0x8080126C: nop
    
            goto L_80801278;
    }
    // 0x8080126C: nop

    // 0x80801270: b           L_80801300
    // 0x80801274: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80801300;
    // 0x80801274: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80801278:
    // 0x80801278: jal         0x80800114
    // 0x8080127C: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    func_80800114_chcollballcontrol(rdram, ctx);
        goto after_3;
    // 0x8080127C: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    after_3:
    // 0x80801280: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80801284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801288: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080128C: beq         $at, $zero, L_8080129C
    if (ctx->r1 == 0) {
        // 0x80801290: nop
    
            goto L_8080129C;
    }
    // 0x80801290: nop

    // 0x80801294: b           L_80801300
    // 0x80801298: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80801300;
    // 0x80801298: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8080129C:
    // 0x8080129C: jal         0x80800114
    // 0x808012A0: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    func_80800114_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x808012A0: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    after_4:
    // 0x808012A4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x808012A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808012AC: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808012B0: beq         $at, $zero, L_808012C0
    if (ctx->r1 == 0) {
        // 0x808012B4: nop
    
            goto L_808012C0;
    }
    // 0x808012B4: nop

    // 0x808012B8: b           L_80801300
    // 0x808012BC: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80801300;
    // 0x808012BC: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_808012C0:
    // 0x808012C0: jal         0x80800114
    // 0x808012C4: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    func_80800114_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x808012C4: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    after_5:
    // 0x808012C8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x808012CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808012D0: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808012D4: beq         $at, $zero, L_808012E4
    if (ctx->r1 == 0) {
        // 0x808012D8: nop
    
            goto L_808012E4;
    }
    // 0x808012D8: nop

    // 0x808012DC: b           L_80801300
    // 0x808012E0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80801300;
    // 0x808012E0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_808012E4:
    // 0x808012E4: jal         0x80800114
    // 0x808012E8: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    func_80800114_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x808012E8: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    after_6:
    // 0x808012EC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x808012F0: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808012F4: beq         $at, $zero, L_80801300
    if (ctx->r1 == 0) {
        // 0x808012F8: nop
    
            goto L_80801300;
    }
    // 0x808012F8: nop

    // 0x808012FC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_80801300:
    // 0x80801300: bltz        $s0, L_8080131C
    if (SIGNED(ctx->r16) < 0) {
        // 0x80801304: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080131C;
    }
    // 0x80801304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801308: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080130C: jal         0x80108B04
    // 0x80801310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x80801310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80801314: b           L_80801340
    // 0x80801318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801340;
    // 0x80801318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080131C:
    // 0x8080131C: jal         0x80800114
    // 0x80801320: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    func_80800114_chcollballcontrol(rdram, ctx);
        goto after_8;
    // 0x80801320: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    after_8:
    // 0x80801324: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80801328: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080132C: beql        $at, $zero, L_80801340
    if (ctx->r1 == 0) {
        // 0x80801330: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801340;
    }
    goto skip_0;
    // 0x80801330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801334: jal         0x80801650
    // 0x80801338: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80801650_chcollballcontrol(rdram, ctx);
        goto after_9;
    // 0x80801338: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_9:
    // 0x8080133C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801340:
    // 0x80801340: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801344: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801348: jr          $ra
    // 0x8080134C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080134C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80020A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020A68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80020A6C: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80020A70: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80020A74: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80020A78: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80020A7C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80020A80: beq         $t8, $zero, L_80020AB8
    if (ctx->r24 == 0) {
        // 0x80020A84: nop
    
            goto L_80020AB8;
    }
    // 0x80020A84: nop

    // 0x80020A88: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80020A8C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80020A90: lbu         $t0, 0x44($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X44);
    // 0x80020A94: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80020A98: sb          $t1, 0x44($t9)
    MEM_B(0X44, ctx->r25) = ctx->r9;
    // 0x80020A9C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020AA0: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020AA4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80020AA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020AAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020AB0: jal         0x80026500
    // 0x80020AB4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80020AB4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_80020AB8:
    // 0x80020AB8: b           L_80020AC0
    // 0x80020ABC: nop

        goto L_80020AC0;
    // 0x80020ABC: nop

L_80020AC0:
    // 0x80020AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80020AC8: jr          $ra
    // 0x80020ACC: nop

    return;
    // 0x80020ACC: nop

;}
RECOMP_FUNC void susubgame_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080037C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800384: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800388: bne         $t6, $zero, L_80800398
    if (ctx->r14 != 0) {
        // 0x8080038C: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80800398;
    }
    // 0x8080038C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800390: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800394: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80800398:
    // 0x80800398: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8080039C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003A0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808003A4: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x808003A8: nop
    
            goto L_808003CC;
    }
    // 0x808003A8: nop

    // 0x808003AC: beq         $v0, $at, L_808003E0
    if (ctx->r2 == ctx->r1) {
        // 0x808003B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003E0;
    }
    // 0x808003B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003B4: beq         $v0, $at, L_808003D8
    if (ctx->r2 == ctx->r1) {
        // 0x808003B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003D8;
    }
    // 0x808003B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003BC: beql        $v0, $at, L_808003DC
    if (ctx->r2 == ctx->r1) {
        // 0x808003C0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808003DC;
    }
    goto skip_0;
    // 0x808003C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_0:
    // 0x808003C4: b           L_80800410
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800410;
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003CC:
    // 0x808003CC: jal         0x80800814
    // 0x808003D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800814_susubgame(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_808003D8:
    // 0x808003D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_808003DC:
    // 0x808003DC: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
L_808003E0:
    // 0x808003E0: jal         0x800F54E4
    // 0x808003E4: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808003E4: nop

    after_1:
    // 0x808003E8: jal         0x800A93E4
    // 0x808003EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A93E4(rdram, ctx);
        goto after_2;
    // 0x808003EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808003F0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808003F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808003FC: ori         $t9, $a3, 0x800
    ctx->r25 = ctx->r7 | 0X800;
    // 0x80800400: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80800404: jal         0x80089560
    // 0x80800408: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _ncpod_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800408: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080040C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800410:
    // 0x80800410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800414: jr          $ra
    // 0x80800418: nop

    return;
    // 0x80800418: nop

;}
RECOMP_FUNC void _gcmapsects_lagoonmid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FF0: syscall     664
    recomp_syscall_handler(rdram, ctx, 0x80087FF0);
    return;
    // 0x80087FF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsvan_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084158: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084158);
    return;
    // 0x8008415C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gczoombox_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B80: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B80);
    return;
    // 0x80087B84: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
