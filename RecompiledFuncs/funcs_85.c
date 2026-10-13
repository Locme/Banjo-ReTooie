#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800DE8_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DF0: jal         0x808001E0
    // 0x80800DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DF8: jal         0x800839C8
    // 0x80800DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E08: jr          $ra
    // 0x80800E0C: nop

    return;
    // 0x80800E0C: nop

;}
RECOMP_FUNC void func_80110888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110888: jr          $ra
    // 0x8011088C: lbu         $v0, 0x71($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X71);
    return;
    // 0x8011088C: lbu         $v0, 0x71($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X71);
;}
RECOMP_FUNC void func_80801278_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801278: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080127C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801280: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801284: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801288: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080128C: jal         0x80100094
    // 0x80801290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801294: jal         0x800D8FF8
    // 0x80801298: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801298: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x8080129C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808012A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808012A4: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x808012A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012AC: jal         0x80089F78
    // 0x808012B0: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808012B0: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808012B4: beql        $v0, $zero, L_808013E4
    if (ctx->r2 == 0) {
        // 0x808012B8: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_0;
    // 0x808012B8: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_0:
    // 0x808012BC: lh          $t6, 0x18($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X18);
    // 0x808012C0: bnel        $t6, $zero, L_808013A4
    if (ctx->r14 != 0) {
        // 0x808012C4: lw          $t5, 0x64($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X64);
            goto L_808013A4;
    }
    goto skip_1;
    // 0x808012C4: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x808012C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808012CC: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x808012D0: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x808012D4: nop

    // 0x808012D8: bc1fl       L_808013E4
    if (!c1cs) {
        // 0x808012DC: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_2;
    // 0x808012DC: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_2:
    // 0x808012E0: jal         0x800C0638
    // 0x808012E4: nop

    func_800C0638(rdram, ctx);
        goto after_3;
    // 0x808012E4: nop

    after_3:
    // 0x808012E8: bnel        $v0, $zero, L_808013E4
    if (ctx->r2 != 0) {
        // 0x808012EC: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_3;
    // 0x808012EC: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_3:
    // 0x808012F0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808012F4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808012F8: bltzl       $t9, L_80801334
    if (SIGNED(ctx->r25) < 0) {
        // 0x808012FC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80801334;
    }
    goto skip_4;
    // 0x808012FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_4:
    // 0x80801300: jal         0x8010D248
    // 0x80801304: nop

    func_8010D248(rdram, ctx);
        goto after_4;
    // 0x80801304: nop

    after_4:
    // 0x80801308: beql        $v0, $zero, L_808013E4
    if (ctx->r2 == 0) {
        // 0x8080130C: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_5;
    // 0x8080130C: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_5:
    // 0x80801310: jal         0x8010C500
    // 0x80801314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_5;
    // 0x80801314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801318: beql        $v0, $zero, L_808013E4
    if (ctx->r2 == 0) {
        // 0x8080131C: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_6;
    // 0x8080131C: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_6:
    // 0x80801320: jal         0x80089EF8
    // 0x80801324: nop

    _suchase_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80801324: nop

    after_6:
    // 0x80801328: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8080132C: bne         $v0, $t0, L_808013E0
    if (ctx->r2 != ctx->r8) {
        // 0x80801330: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808013E0;
    }
    // 0x80801330: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80801334:
    // 0x80801334: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801338: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080133C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801340: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801344: jal         0x800DC178
    // 0x80801348: sh          $t1, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r9;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80801348: sh          $t1, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r9;
    after_7:
    // 0x8080134C: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80801350: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80801354: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080135C: srl         $t2, $a1, 10
    ctx->r10 = S32(U32(ctx->r5) >> 10);
    // 0x80801360: beq         $t2, $at, L_80801370
    if (ctx->r10 == ctx->r1) {
        // 0x80801364: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80801370;
    }
    // 0x80801364: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801368: bnel        $t2, $at, L_808013E4
    if (ctx->r10 != ctx->r1) {
        // 0x8080136C: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_7;
    // 0x8080136C: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_7:
L_80801370:
    // 0x80801370: jal         0x80801160
    // 0x80801374: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_8;
    // 0x80801374: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80801378: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080137C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801380: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801384: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801388: jal         0x800DC178
    // 0x8080138C: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x8080138C: nop

    after_9:
    // 0x80801390: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801394: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80801398: b           L_808013E0
    // 0x8080139C: sh          $t4, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r12;
        goto L_808013E0;
    // 0x8080139C: sh          $t4, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r12;
    // 0x808013A0: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_808013A4:
    // 0x808013A4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x808013A8: bltzl       $t7, L_808013E4
    if (SIGNED(ctx->r15) < 0) {
        // 0x808013AC: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_8;
    // 0x808013AC: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_8:
    // 0x808013B0: jal         0x8010C500
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_10;
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808013B8: beql        $v0, $zero, L_808013D8
    if (ctx->r2 == 0) {
        // 0x808013BC: sh          $zero, 0x18($s1)
        MEM_H(0X18, ctx->r17) = 0;
            goto L_808013D8;
    }
    goto skip_9;
    // 0x808013BC: sh          $zero, 0x18($s1)
    MEM_H(0X18, ctx->r17) = 0;
    skip_9:
    // 0x808013C0: jal         0x80089EF8
    // 0x808013C4: nop

    _suchase_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x808013C4: nop

    after_11:
    // 0x808013C8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808013CC: beql        $v0, $t8, L_808013E4
    if (ctx->r2 == ctx->r24) {
        // 0x808013D0: lh          $t9, 0x18($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X18);
            goto L_808013E4;
    }
    goto skip_10;
    // 0x808013D0: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    skip_10:
    // 0x808013D4: sh          $zero, 0x18($s1)
    MEM_H(0X18, ctx->r17) = 0;
L_808013D8:
    // 0x808013D8: jal         0x80801C7C
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C7C_chfactoryrobot(rdram, ctx);
        goto after_12;
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808013E0:
    // 0x808013E0: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
L_808013E4:
    // 0x808013E4: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x808013E8: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808013EC: beql        $t9, $zero, L_80801404
    if (ctx->r25 == 0) {
        // 0x808013F0: lh          $t0, 0x6($s1)
        ctx->r8 = MEM_H(ctx->r17, 0X6);
            goto L_80801404;
    }
    goto skip_11;
    // 0x808013F0: lh          $t0, 0x6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X6);
    skip_11:
    // 0x808013F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808013F8: b           L_80801414
    // 0x808013FC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
        goto L_80801414;
    // 0x808013FC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801400: lh          $t0, 0x6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X6);
L_80801404:
    // 0x80801404: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80801408: nop

    // 0x8080140C: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801410: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
L_80801414:
    // 0x80801414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801418: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080141C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80801420: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801424: jal         0x800F15F8
    // 0x80801428: nop

    func_800F15F8(rdram, ctx);
        goto after_13;
    // 0x80801428: nop

    after_13:
    // 0x8080142C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801430: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801434: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80801438: nop

    // 0x8080143C: bc1t        L_808017D8
    if (c1cs) {
        // 0x80801440: nop
    
            goto L_808017D8;
    }
    // 0x80801440: nop

    // 0x80801444: lh          $t1, 0x18($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X18);
    // 0x80801448: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x8080144C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80801450: beq         $t1, $zero, L_80801604
    if (ctx->r9 == 0) {
        // 0x80801454: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80801604;
    }
    // 0x80801454: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80801458: jal         0x8008FE94
    // 0x8080145C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8008FE94(rdram, ctx);
        goto after_14;
    // 0x8080145C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_14:
    // 0x80801460: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80801464: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080146C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80801470: bgez        $t4, L_808014F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80801474: nop
    
            goto L_808014F8;
    }
    // 0x80801474: nop

    // 0x80801478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080147C: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80801480: jal         0x80089BF0
    // 0x80801484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_15;
    // 0x80801484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80801488: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8080148C: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80801490: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801494: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801498: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8080149C: nop

    // 0x808014A0: bc1f        L_808014E8
    if (!c1cs) {
        // 0x808014A4: nop
    
            goto L_808014E8;
    }
    // 0x808014A4: nop

    // 0x808014A8: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808014AC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808014B0: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x808014B4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808014B8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808014BC: jal         0x800EEB9C
    // 0x808014C0: nop

    func_800EEB9C(rdram, ctx);
        goto after_16;
    // 0x808014C0: nop

    after_16:
    // 0x808014C4: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808014C8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808014CC: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x808014D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808014D4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x808014D8: jal         0x800F0D50
    // 0x808014DC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_800F0D50(rdram, ctx);
        goto after_17;
    // 0x808014DC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_17:
    // 0x808014E0: b           L_808015C8
    // 0x808014E4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
        goto L_808015C8;
    // 0x808014E4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_808014E8:
    // 0x808014E8: jal         0x800EFD24
    // 0x808014EC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_18;
    // 0x808014EC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_18:
    // 0x808014F0: b           L_808015C8
    // 0x808014F4: nop

        goto L_808015C8;
    // 0x808014F4: nop

L_808014F8:
    // 0x808014F8: jal         0x80102D78
    // 0x808014FC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102D78(rdram, ctx);
        goto after_19;
    // 0x808014FC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_19:
    // 0x80801500: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80801504: jal         0x80089F78
    // 0x80801508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80801508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080150C: beq         $v0, $zero, L_80801544
    if (ctx->r2 == 0) {
        // 0x80801510: lwc1        $f0, 0x48($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80801544;
    }
    // 0x80801510: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801514: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801518: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080151C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801520: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801524: addiu       $t5, $zero, 0x5000
    ctx->r13 = ADD32(0, 0X5000);
    // 0x80801528: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8080152C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801530: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    // 0x80801534: jal         0x80089F90
    // 0x80801538: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_21;
    // 0x80801538: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x8080153C: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801540: swc1        $f18, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f18.u32l;
L_80801544:
    // 0x80801544: jal         0x800D8FF8
    // 0x80801548: nop

    func_800D8FF8(rdram, ctx);
        goto after_22;
    // 0x80801548: nop

    after_22:
    // 0x8080154C: jal         0x800D8FF8
    // 0x80801550: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_23;
    // 0x80801550: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x80801554: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080155C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801560: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801564: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801568: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080156C: lwc1        $f12, 0x2C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80801570: lwc1        $f14, 0x30($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80801574: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801578: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x8080157C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801580: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80801584: jal         0x800F1FF0
    // 0x80801588: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_24;
    // 0x80801588: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x8080158C: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x80801590: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801594: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80801598: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080159C: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x808015A0: jal         0x800EEB9C
    // 0x808015A4: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    func_800EEB9C(rdram, ctx);
        goto after_25;
    // 0x808015A4: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    after_25:
    // 0x808015A8: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808015AC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808015B0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x808015B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808015B8: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x808015BC: jal         0x800F0D50
    // 0x808015C0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F0D50(rdram, ctx);
        goto after_26;
    // 0x808015C0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_26:
    // 0x808015C4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_808015C8:
    // 0x808015C8: jal         0x80801954
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801954_chfactoryrobot(rdram, ctx);
        goto after_27;
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808015D0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808015D4: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x808015D8: ori         $a1, $a1, 0x4427
    ctx->r5 = ctx->r5 | 0X4427;
    // 0x808015DC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808015E0: bgez        $t8, L_808015F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808015E4: nop
    
            goto L_808015F4;
    }
    // 0x808015E4: nop

    // 0x808015E8: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x808015EC: b           L_808015F4
    // 0x808015F0: ori         $a1, $a1, 0x4027
    ctx->r5 = ctx->r5 | 0X4027;
        goto L_808015F4;
    // 0x808015F0: ori         $a1, $a1, 0x4027
    ctx->r5 = ctx->r5 | 0X4027;
L_808015F4:
    // 0x808015F4: jal         0x8010B990
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_28;
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808015FC: b           L_808017E4
    // 0x80801600: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
        goto L_808017E4;
    // 0x80801600: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
L_80801604:
    // 0x80801604: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80801608: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8080160C: lhu         $t0, 0x12($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X12);
    // 0x80801610: srl         $t1, $t0, 1
    ctx->r9 = S32(U32(ctx->r8) >> 1);
    // 0x80801614: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80801618: jal         0x8001210C
    // 0x8080161C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    func_8001210C(rdram, ctx);
        goto after_29;
    // 0x8080161C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_29:
    // 0x80801620: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80801624: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27C4) << 16);
    // 0x80801628: bne         $v0, $t3, L_80801650
    if (ctx->r2 != ctx->r11) {
        // 0x8080162C: nop
    
            goto L_80801650;
    }
    // 0x8080162C: nop

    // 0x80801630: jal         0x800DC298
    // 0x80801634: lwc1        $f12, 0x27C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27C4));
    func_800DC298(rdram, ctx);
        goto after_30;
    // 0x80801634: lwc1        $f12, 0x27C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27C4));
    after_30:
    // 0x80801638: beq         $v0, $zero, L_80801650
    if (ctx->r2 == 0) {
        // 0x8080163C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1140, 0X27C8) << 16);
            goto L_80801650;
    }
    // 0x8080163C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27C8) << 16);
    // 0x80801640: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801644: jal         0x800DC178
    // 0x80801648: lwc1        $f14, 0x27C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27C8));
    func_800DC178(rdram, ctx);
        goto after_31;
    // 0x80801648: lwc1        $f14, 0x27C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27C8));
    after_31:
    // 0x8080164C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80801650:
    // 0x80801650: jal         0x80801954
    // 0x80801654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801954_chfactoryrobot(rdram, ctx);
        goto after_32;
    // 0x80801654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80801658: jal         0x800D9078
    // 0x8080165C: addiu       $a0, $s1, 0x24
    ctx->r4 = ADD32(ctx->r17, 0X24);
    func_800D9078(rdram, ctx);
        goto after_33;
    // 0x8080165C: addiu       $a0, $s1, 0x24
    ctx->r4 = ADD32(ctx->r17, 0X24);
    after_33:
    // 0x80801660: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801664: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80801668: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x8080166C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801670: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80801674: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801678: bc1fl       L_808017D0
    if (!c1cs) {
        // 0x8080167C: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808017D0;
    }
    goto skip_12;
    // 0x8080167C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_12:
    // 0x80801680: jal         0x800EEB40
    // 0x80801684: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800EEB40(rdram, ctx);
        goto after_34;
    // 0x80801684: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_34:
    // 0x80801688: lui         $at, 0x45C8
    ctx->r1 = S32(0X45C8 << 16);
    // 0x8080168C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801690: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801698: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080169C: nop

    // 0x808016A0: bc1f        L_808017A4
    if (!c1cs) {
        // 0x808016A4: nop
    
            goto L_808017A4;
    }
    // 0x808016A4: nop

    // 0x808016A8: jal         0x80102D78
    // 0x808016AC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80102D78(rdram, ctx);
        goto after_35;
    // 0x808016AC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_35:
    // 0x808016B0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808016B4: jal         0x80089F78
    // 0x808016B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_36;
    // 0x808016B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x808016BC: beq         $v0, $zero, L_808016F4
    if (ctx->r2 == 0) {
        // 0x808016C0: lwc1        $f0, 0x3C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_808016F4;
    }
    // 0x808016C0: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808016C4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808016C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808016CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808016D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808016D4: addiu       $t4, $zero, 0x5000
    ctx->r12 = ADD32(0, 0X5000);
    // 0x808016D8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808016DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E0: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    // 0x808016E4: jal         0x80089F90
    // 0x808016E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_37;
    // 0x808016E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_37:
    // 0x808016EC: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808016F0: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
L_808016F4:
    // 0x808016F4: jal         0x800D8FF8
    // 0x808016F8: nop

    func_800D8FF8(rdram, ctx);
        goto after_38;
    // 0x808016F8: nop

    after_38:
    // 0x808016FC: jal         0x800D8FF8
    // 0x80801700: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_39;
    // 0x80801700: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x80801704: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801708: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080170C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801710: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80801714: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801718: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080171C: lwc1        $f12, 0x2C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80801720: lwc1        $f14, 0x30($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80801724: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801728: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x8080172C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801730: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80801734: jal         0x800F1FF0
    // 0x80801738: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_40;
    // 0x80801738: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_40:
    // 0x8080173C: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x80801740: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801744: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80801748: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080174C: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80801750: jal         0x800EEB9C
    // 0x80801754: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    func_800EEB9C(rdram, ctx);
        goto after_41;
    // 0x80801754: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    after_41:
    // 0x80801758: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080175C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801760: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80801764: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801768: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x8080176C: jal         0x800F0D50
    // 0x80801770: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_800F0D50(rdram, ctx);
        goto after_42;
    // 0x80801770: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_42:
    // 0x80801774: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x80801778: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8080177C: ori         $a1, $a1, 0x4427
    ctx->r5 = ctx->r5 | 0X4427;
    // 0x80801780: jal         0x8010B990
    // 0x80801784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_43;
    // 0x80801784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80801788: andi        $t5, $v0, 0x26
    ctx->r13 = ctx->r2 & 0X26;
    // 0x8080178C: beql        $t5, $zero, L_808017E4
    if (ctx->r13 == 0) {
        // 0x80801790: lwc1        $f16, 0x24($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
            goto L_808017E4;
    }
    goto skip_13;
    // 0x80801790: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    skip_13:
    // 0x80801794: jal         0x80801C7C
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C7C_chfactoryrobot(rdram, ctx);
        goto after_44;
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x8080179C: b           L_808017E4
    // 0x808017A0: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
        goto L_808017E4;
    // 0x808017A0: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
L_808017A4:
    // 0x808017A4: jal         0x80801C7C
    // 0x808017A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C7C_chfactoryrobot(rdram, ctx);
        goto after_45;
    // 0x808017A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x808017AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808017B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808017B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808017B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808017BC: jal         0x800DC178
    // 0x808017C0: nop

    func_800DC178(rdram, ctx);
        goto after_46;
    // 0x808017C0: nop

    after_46:
    // 0x808017C4: b           L_808017E0
    // 0x808017C8: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
        goto L_808017E0;
    // 0x808017C8: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x808017CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_808017D0:
    // 0x808017D0: b           L_808017E0
    // 0x808017D4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
        goto L_808017E0;
    // 0x808017D4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
L_808017D8:
    // 0x808017D8: jal         0x80104580
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104580(rdram, ctx);
        goto after_47;
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
L_808017E0:
    // 0x808017E0: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
L_808017E4:
    // 0x808017E4: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808017E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27CC) << 16);
    // 0x808017EC: lwc1        $f4, 0x27CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27CC));
    // 0x808017F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808017F4: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808017F8: lui         $a2, 0x43D2
    ctx->r6 = S32(0X43D2 << 16);
    // 0x808017FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801800: jal         0x800F12D4
    // 0x80801804: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_48;
    // 0x80801804: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_48:
    // 0x80801808: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8080180C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27D0) << 16);
    // 0x80801810: lwc1        $f6, 0x27D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27D0));
    // 0x80801814: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080181C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801820: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80801824: swc1        $f16, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f16.u32l;
    // 0x80801828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080182C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801830: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801834: jr          $ra
    // 0x80801838: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80801838: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800EE040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EE044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EE048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EE04C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EE050: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EE054: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800EE058: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x800EE05C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EE060: bnel        $a2, $zero, L_800EE07C
    if (ctx->r6 != 0) {
        // 0x800EE064: lwc1        $f4, 0x28($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
            goto L_800EE07C;
    }
    goto skip_0;
    // 0x800EE064: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x800EE068: jal         0x800C2E04
    // 0x800EE06C: nop

    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x800EE06C: nop

    after_0:
    // 0x800EE070: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800EE074: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800EE078: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
L_800EE07C:
    // 0x800EE07C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800EE080: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800EE084: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EE088: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800EE08C: jal         0x800C301C
    // 0x800EE090: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C301C(rdram, ctx);
        goto after_1;
    // 0x800EE090: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800EE094: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800EE098: jal         0x800C330C
    // 0x800EE09C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x800EE09C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x800EE0A0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800EE0A4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EE0A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EE0AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EE0B0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EE0B4: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800EE0B8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800EE0BC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EE0C0: jal         0x800C31DC
    // 0x800EE0C4: nop

    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x800EE0C4: nop

    after_3:
    // 0x800EE0C8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800EE0CC: jal         0x800C3058
    // 0x800EE0D0: addiu       $a1, $zero, 0x7D00
    ctx->r5 = ADD32(0, 0X7D00);
    func_800C3058(rdram, ctx);
        goto after_4;
    // 0x800EE0D0: addiu       $a1, $zero, 0x7D00
    ctx->r5 = ADD32(0, 0X7D00);
    after_4:
    // 0x800EE0D4: jal         0x800C3BDC
    // 0x800EE0D8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x800EE0D8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_5:
    // 0x800EE0DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EE0E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EE0E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EE0E8: jr          $ra
    // 0x800EE0EC: nop

    return;
    // 0x800EE0EC: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085818: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085818);
    return;
    // 0x8008581C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void sucoasterfly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: jal         0x80802128
    // 0x808000D4: nop

    func_80802128_sucoasterfly(rdram, ctx);
        goto after_0;
    // 0x808000D4: nop

    after_0:
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x8080004C: andi        $t7, $t6, 0xFFFC
    ctx->r15 = ctx->r14 & 0XFFFC;
    // 0x80800050: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800054: jr          $ra
    // 0x80800058: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
    return;
    // 0x80800058: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void _gldbDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888A8: syscall     708
    recomp_syscall_handler(rdram, ctx, 0x800888A8);
    return;
    // 0x800888AC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800544_chbosskogsdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800548: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080054C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800550: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800558: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080055C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800560: beq         $t6, $at, L_8080058C
    if (ctx->r14 == ctx->r1) {
        // 0x80800564: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080058C;
    }
    // 0x80800564: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800568: beq         $t6, $at, L_808005DC
    if (ctx->r14 == ctx->r1) {
        // 0x8080056C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005DC;
    }
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800574: beq         $t6, $at, L_80800700
    if (ctx->r14 == ctx->r1) {
        // 0x80800578: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800700;
    }
    // 0x80800578: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080057C: beql        $t6, $at, L_80800704
    if (ctx->r14 == ctx->r1) {
        // 0x80800580: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800704;
    }
    goto skip_0;
    // 0x80800580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800584: b           L_80800704
    // 0x80800588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800704;
    // 0x80800588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080058C:
    // 0x8080058C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800590: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8080059C: bgez        $t9, L_808005CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808005A0: nop
    
            goto L_808005CC;
    }
    // 0x808005A0: nop

    // 0x808005A4: jal         0x80102424
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808005AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2292, 0X994) << 16);
    // 0x808005B0: addiu       $a2, $a2, 0x994
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2292, 0X994));
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B8: jal         0x80089D18
    // 0x808005BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808005BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808005C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808005C4: b           L_80800700
    // 0x808005C8: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_80800700;
    // 0x808005C8: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_808005CC:
    // 0x808005CC: jal         0x80103110
    // 0x808005D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x808005D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808005D4: b           L_80800704
    // 0x808005D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800704;
    // 0x808005D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005DC:
    // 0x808005DC: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x808005E0: jal         0x80101E14
    // 0x808005E4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x808005E4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_3:
    // 0x808005E8: beq         $v0, $zero, L_8080060C
    if (ctx->r2 == 0) {
        // 0x808005EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080060C;
    }
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2292, 0X988) << 16);
    // 0x808005F4: addiu       $a2, $a2, 0x988
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2292, 0X988));
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: jal         0x80089D18
    // 0x80800600: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800600: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800604: b           L_80800654
    // 0x80800608: nop

        goto L_80800654;
    // 0x80800608: nop

L_8080060C:
    // 0x8080060C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800610: jal         0x80101E14
    // 0x80800614: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80800614: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_5:
    // 0x80800618: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x8080061C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800654;
    }
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800620: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800624: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2292, 0X9A0) << 16);
    // 0x80800628: addiu       $a2, $a2, 0x9A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2292, 0X9A0));
    // 0x8080062C: jal         0x80089D18
    // 0x80800630: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800630: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_6:
    // 0x80800634: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2292, 0X9B0) << 16);
    // 0x80800638: addiu       $t0, $t0, 0x9B0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2292, 0X9B0));
    // 0x8080063C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800640: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800644: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080064C: jal         0x800BBCB8
    // 0x80800650: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x80800650: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_7:
L_80800654:
    // 0x80800654: jal         0x80101F24
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_8;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080065C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2292, 0X8A8) << 16);
    // 0x80800660: lwc1        $f6, 0x8A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2292, 0X8A8));
    // 0x80800664: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800668: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080066C: nop

    // 0x80800670: bc1f        L_808006DC
    if (!c1cs) {
        // 0x80800674: nop
    
            goto L_808006DC;
    }
    // 0x80800674: nop

    // 0x80800678: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080067C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800680: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800684: lui         $a1, 0xC377
    ctx->r5 = S32(0XC377 << 16);
    // 0x80800688: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080068C: lui         $a3, 0x44D7
    ctx->r7 = S32(0X44D7 << 16);
    // 0x80800690: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800694: jal         0x800EFA4C
    // 0x80800698: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80800698: nop

    after_9:
    // 0x8080069C: jal         0x800D8FF8
    // 0x808006A0: nop

    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x808006A0: nop

    after_10:
    // 0x808006A4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808006A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006AC: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808006B0: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2292, 0X8B0) << 16);
    // 0x808006B4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808006B8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808006BC: addiu       $t1, $t1, 0x8B0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2292, 0X8B0));
    // 0x808006C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808006C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808006C8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808006CC: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x808006D0: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x808006D4: jal         0x800BBCB8
    // 0x808006D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800BBCB8(rdram, ctx);
        goto after_11;
    // 0x808006D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_11:
L_808006DC:
    // 0x808006DC: jal         0x80101DDC
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_12;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808006E4: beq         $v0, $zero, L_80800700
    if (ctx->r2 == 0) {
        // 0x808006E8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800700;
    }
    // 0x808006E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808006EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006F8: jal         0x80102424
    // 0x808006FC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x808006FC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_13:
L_80800700:
    // 0x80800700: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800704:
    // 0x80800704: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800708: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080070C: jr          $ra
    // 0x80800710: nop

    return;
    // 0x80800710: nop

;}
RECOMP_FUNC void func_808009A0_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A8: jal         0x80800198
    // 0x808009AC: nop

    func_80800198_bsmumswim(rdram, ctx);
        goto after_0;
    // 0x808009AC: nop

    after_0:
    // 0x808009B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B8: jr          $ra
    // 0x808009BC: nop

    return;
    // 0x808009BC: nop

;}
RECOMP_FUNC void func_8080006C_chfactorylinkgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800070: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800074: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080007C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800080: beq         $a1, $at, L_808000F4
    if (ctx->r5 == ctx->r1) {
        // 0x80800084: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808000F4;
    }
    // 0x80800084: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800088: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080008C: bne         $a1, $at, L_80800104
    if (ctx->r5 != ctx->r1) {
        // 0x80800090: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800104;
    }
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800094: lbu         $a0, 0x79($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X79);
    // 0x80800098: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8080009C: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x808000A0: jal         0x800DA544
    // 0x808000A4: addiu       $a0, $t6, 0x1C0
    ctx->r4 = ADD32(ctx->r14, 0X1C0);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x808000A4: addiu       $a0, $t6, 0x1C0
    ctx->r4 = ADD32(ctx->r14, 0X1C0);
    after_0:
    // 0x808000A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000AC: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x808000B0: jal         0x80086E20
    // 0x808000B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _chskeletonexplode_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808000B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x808000B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2316, 0X244) << 16);
    // 0x808000BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000C0: addiu       $a2, $a2, 0x244
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2316, 0X244));
    // 0x808000C4: jal         0x80089D18
    // 0x808000C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808000C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808000CC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2316, 0X200) << 16);
    // 0x808000D0: addiu       $t7, $t7, 0x200
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2316, 0X200));
    // 0x808000D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808000E4: jal         0x800BBCB8
    // 0x808000E8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x808000E8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x808000EC: b           L_80800104
    // 0x808000F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800104;
    // 0x808000F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000F4:
    // 0x808000F4: jal         0x800FFAB0
    // 0x808000F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808000F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x808000FC: b           L_80800104
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800104;
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800104:
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800108: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080010C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void _bskazeggass_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083338: syscall     55
    recomp_syscall_handler(rdram, ctx, 0x80083338);
    return;
    // 0x8008333C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gcmapDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088110: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x80088110);
    return;
    // 0x80088114: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _ncbadolly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089360: syscall     775
    recomp_syscall_handler(rdram, ctx, 0x80089360);
    return;
    // 0x80089364: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void subaddiebounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: jal         0x800D8FF8
    // 0x808001C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001C8: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x808001CC: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808001D0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x808001D4: nop

    // 0x808001D8: bc1tl       L_80800200
    if (c1cs) {
        // 0x808001DC: lwc1        $f12, 0x2C($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
            goto L_80800200;
    }
    goto skip_0;
    // 0x808001DC: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    skip_0:
    // 0x808001E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001E4: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001EC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808001F0: nop

    // 0x808001F4: bc1f        L_80800254
    if (!c1cs) {
        // 0x808001F8: nop
    
            goto L_80800254;
    }
    // 0x808001F8: nop

    // 0x808001FC: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
L_80800200:
    // 0x80800200: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80800204: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80800208: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8080020C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80800210: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800214: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80800218: nop

    // 0x8080021C: bc1fl       L_80800240
    if (!c1cs) {
        // 0x80800220: lwc1        $f6, 0x34($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
            goto L_80800240;
    }
    goto skip_1;
    // 0x80800220: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    skip_1:
    // 0x80800224: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800228: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800230: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80800234: b           L_80800254
    // 0x80800238: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
        goto L_80800254;
    // 0x80800238: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x8080023C: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
L_80800240:
    // 0x80800240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800244: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800248: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x8080024C: b           L_80800254
    // 0x80800250: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
        goto L_80800254;
    // 0x80800250: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
L_80800254:
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

    // 0x80800264: nop

    // 0x80800268: nop

    // 0x8080026C: nop

;}
RECOMP_FUNC void func_8080007C_ncbaglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800084: jal         0x80112550
    // 0x80800088: nop

    func_80112550(rdram, ctx);
        goto after_0;
    // 0x80800088: nop

    after_0:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_80800E20_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800E24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E2C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800E30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E38: lwc1        $f14, 0x28($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80800E3C: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80800E40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800E44: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800E48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E4C: jal         0x800F10B4
    // 0x80800E50: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800E50: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800E54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1150) << 16);
    // 0x80800E58: lwc1        $f6, 0x1150($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1150));
    // 0x80800E5C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800E60: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800E64: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800E68: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800E6C: bc1fl       L_80800E98
    if (!c1cs) {
        // 0x80800E70: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80800E98;
    }
    goto skip_0;
    // 0x80800E70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80800E74: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800E78: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800E7C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800E80: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800E84: jal         0x800F10B4
    // 0x80800E88: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800E88: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800E8C: b           L_80800F0C
    // 0x80800E90: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80800F0C;
    // 0x80800E90: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800E94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80800E98:
    // 0x80800E98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800E9C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800EA0: nop

    // 0x80800EA4: bc1fl       L_80800EE0
    if (!c1cs) {
        // 0x80800EA8: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80800EE0;
    }
    goto skip_1;
    // 0x80800EA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x80800EAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1154) << 16);
    // 0x80800EB0: lwc1        $f14, 0x1154($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1154));
    // 0x80800EB4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800EB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800EBC: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800EC0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800EC4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800EC8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800ECC: jal         0x800F10B4
    // 0x80800ED0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800ED0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80800ED4: b           L_80800F0C
    // 0x80800ED8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80800F0C;
    // 0x80800ED8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800EDC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80800EE0:
    // 0x80800EE0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800EE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800EE8: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800EEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800EF0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800EF4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800EF8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800EFC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800F00: jal         0x800F10B4
    // 0x80800F04: nop

    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800F04: nop

    after_3:
    // 0x80800F08: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80800F0C:
    // 0x80800F0C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800F10: jal         0x800F15F8
    // 0x80800F14: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x80800F14: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_4:
    // 0x80800F18: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F28: jr          $ra
    // 0x80800F2C: nop

    return;
    // 0x80800F2C: nop

;}
RECOMP_FUNC void func_80116088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116088: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011608C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80116090: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80116094: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80116098: jal         0x801107B0
    // 0x8011609C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_801107B0(rdram, ctx);
        goto after_0;
    // 0x8011609C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x801160A0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801160A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801160A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801160AC: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x801160B0: jal         0x800F1E6C
    // 0x801160B4: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800F1E6C(rdram, ctx);
        goto after_1;
    // 0x801160B4: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_1:
    // 0x801160B8: beq         $v0, $zero, L_801160CC
    if (ctx->r2 == 0) {
        // 0x801160BC: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_801160CC;
    }
    // 0x801160BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801160C0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801160C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801160C8: sb          $t7, 0x2C($t9)
    MEM_B(0X2C, ctx->r25) = ctx->r15;
L_801160CC:
    // 0x801160CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801160D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801160D4: jr          $ra
    // 0x801160D8: nop

    return;
    // 0x801160D8: nop

;}
RECOMP_FUNC void ncbapan_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080011C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800120: jal         0x80800028
    // 0x80800124: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80800028_ncbapan(rdram, ctx);
        goto after_0;
    // 0x80800124: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x801107F0
    // 0x80800130: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x80800130: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80800134: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800138: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8080013C: jal         0x800EFB24
    // 0x80800140: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80800140: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x80800144: jal         0x800EEF94
    // 0x80800148: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x80800148: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x8080014C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800150: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800154: jal         0x800F1A88
    // 0x80800158: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F1A88(rdram, ctx);
        goto after_4;
    // 0x80800158: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800164: jal         0x80113978
    // 0x80800168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80113978(rdram, ctx);
        goto after_5;
    // 0x80800168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: jal         0x80115358
    // 0x80800174: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80115358(rdram, ctx);
        goto after_6;
    // 0x80800174: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800178: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x80115750
    // 0x80800184: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80115750(rdram, ctx);
        goto after_7;
    // 0x80800184: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800188: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x80112C3C
    // 0x80800194: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80112C3C(rdram, ctx);
        goto after_8;
    // 0x80800194: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800198: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080019C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808001A0: nop

    // 0x808001A4: bc1tl       L_808001B8
    if (c1cs) {
        // 0x808001A8: lw          $t7, 0x38($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X38);
            goto L_808001B8;
    }
    goto skip_0;
    // 0x808001A8: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x808001AC: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x808001B0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x808001B4: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
L_808001B8:
    // 0x808001B8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808001BC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808001C0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x808001C4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C8: jal         0x800EEBF0
    // 0x808001CC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_800EEBF0(rdram, ctx);
        goto after_9;
    // 0x808001CC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x808001D0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808001D4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808001D8: jal         0x800EE780
    // 0x808001DC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800EE780(rdram, ctx);
        goto after_10;
    // 0x808001DC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x80111FD4
    // 0x808001E8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80111FD4(rdram, ctx);
        goto after_11;
    // 0x808001E8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x808001EC: beql        $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x808001F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    goto skip_1;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808001F4: jal         0x801138A0
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_12;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001FC: bne         $v0, $zero, L_80800214
    if (ctx->r2 != 0) {
        // 0x80800200: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800214;
    }
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x80115580
    // 0x80800208: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80115580(rdram, ctx);
        goto after_13;
    // 0x80800208: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_13:
    // 0x8080020C: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800210: nop
    
            goto L_8080022C;
    }
    // 0x80800210: nop

L_80800214:
    // 0x80800214: jal         0x801138F4
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_14;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080021C: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800220: nop
    
            goto L_8080022C;
    }
    // 0x80800220: nop

    // 0x80800224: jal         0x80110F44
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_15;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_8080022C:
    // 0x8080022C: jal         0x80800048
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800048_ncbapan(rdram, ctx);
        goto after_16;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800238:
    // 0x80800238: jal         0x80800008
    // 0x8080023C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80800008_ncbapan(rdram, ctx);
        goto after_17;
    // 0x8080023C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_17:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800248: jal         0x80110A68
    // 0x8080024C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_80110A68(rdram, ctx);
        goto after_18;
    // 0x8080024C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_18:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x80110790
    // 0x80800258: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80110790(rdram, ctx);
        goto after_19;
    // 0x80800258: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_19:
    // 0x8080025C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void func_80800DB0_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DB8: jal         0x80090A2C
    // 0x80800DBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80800DBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DC0: jal         0x80800198
    // 0x80800DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bssnowball_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: nop

    return;
    // 0x80800DD4: nop

;}
RECOMP_FUNC void func_808003B8_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C0: jal         0x800897C8
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082568: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082568);
    return;
    // 0x8008256C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808000DC_chboggykidshome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: jal         0x800897C8
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void func_80800C60_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C68: jal         0x800F54E4
    // 0x80800C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C70: jal         0x800F56AC
    // 0x80800C74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F56AC(rdram, ctx);
        goto after_1;
    // 0x80800C74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800C78: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800C7C: bne         $v0, $at, L_80800C8C
    if (ctx->r2 != ctx->r1) {
        // 0x80800C80: nop
    
            goto L_80800C8C;
    }
    // 0x80800C80: nop

    // 0x80800C84: b           L_80800CC8
    // 0x80800C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800CC8;
    // 0x80800C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C8C:
    // 0x80800C8C: jal         0x800DA298
    // 0x80800C90: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800C90: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_2:
    // 0x80800C94: beq         $v0, $zero, L_80800CB8
    if (ctx->r2 == 0) {
        // 0x80800C98: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800CB8;
    }
    // 0x80800C98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CA0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1860, 0X1340) << 16);
    // 0x80800CA4: addiu       $a2, $a2, 0x1340
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X1340));
    // 0x80800CA8: jal         0x8008A1E8
    // 0x80800CAC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800CAC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x80800CB0: b           L_80800CCC
    // 0x80800CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800CCC;
    // 0x80800CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CB8:
    // 0x80800CB8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1860, 0X1324) << 16);
    // 0x80800CBC: addiu       $a2, $a2, 0x1324
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1860, 0X1324));
    // 0x80800CC0: jal         0x8008A1E8
    // 0x80800CC4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800CC4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_4:
L_80800CC8:
    // 0x80800CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CCC:
    // 0x80800CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CD0: jr          $ra
    // 0x80800CD4: nop

    return;
    // 0x80800CD4: nop

;}
RECOMP_FUNC void func_800B5884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5884: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B5888: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B588C: addiu       $v0, $v0, -0x7EBC
    ctx->r2 = ADD32(ctx->r2, -0X7EBC);
    // 0x800B5890: addiu       $v1, $v1, 0x7F34
    ctx->r3 = ADD32(ctx->r3, 0X7F34);
L_800B5894:
    // 0x800B5894: lbu         $t8, 0x14($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X14);
    // 0x800B5898: lbu         $t0, 0x20($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X20);
    // 0x800B589C: lbu         $t2, 0x2C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2C);
    // 0x800B58A0: lbu         $t6, 0x8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X8);
    // 0x800B58A4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x800B58A8: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x800B58AC: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x800B58B0: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x800B58B4: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x800B58B8: sb          $t3, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r11;
    // 0x800B58BC: sb          $t1, -0x10($v1)
    MEM_B(-0X10, ctx->r3) = ctx->r9;
    // 0x800B58C0: sb          $t9, -0x1C($v1)
    MEM_B(-0X1C, ctx->r3) = ctx->r25;
    // 0x800B58C4: bne         $v1, $v0, L_800B5894
    if (ctx->r3 != ctx->r2) {
        // 0x800B58C8: sb          $t7, -0x28($v1)
        MEM_B(-0X28, ctx->r3) = ctx->r15;
            goto L_800B5894;
    }
    // 0x800B58C8: sb          $t7, -0x28($v1)
    MEM_B(-0X28, ctx->r3) = ctx->r15;
    // 0x800B58CC: jr          $ra
    // 0x800B58D0: nop

    return;
    // 0x800B58D0: nop

;}
RECOMP_FUNC void func_80016734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016734: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016738: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001673C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016740: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80016744: addiu       $a1, $a1, -0x64C8
    ctx->r5 = ADD32(ctx->r5, -0X64C8);
    // 0x80016748: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    // 0x8001674C: jal         0x8002E070
    // 0x80016750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80016750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80016754: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016758: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001675C: addiu       $a1, $a1, -0x64C4
    ctx->r5 = ADD32(ctx->r5, -0X64C4);
    // 0x80016760: addiu       $a0, $a0, -0x6488
    ctx->r4 = ADD32(ctx->r4, -0X6488);
    // 0x80016764: jal         0x8002E070
    // 0x80016768: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80016768: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8001676C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80016770: addiu       $t6, $t6, -0x6090
    ctx->r14 = ADD32(ctx->r14, -0X6090);
    // 0x80016774: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016778: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001677C: lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // 0x80016780: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80016784: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80016788: addiu       $a3, $a3, 0x66DC
    ctx->r7 = ADD32(ctx->r7, 0X66DC);
    // 0x8001678C: addiu       $a1, $a1, -0x62A8
    ctx->r5 = ADD32(ctx->r5, -0X62A8);
    // 0x80016790: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    // 0x80016794: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80016798: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8001679C: jal         0x8001DCB0
    // 0x800167A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DCB0(rdram, ctx);
        goto after_2;
    // 0x800167A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x800167A4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800167A8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800167AC: addiu       $a2, $a2, -0x64C8
    ctx->r6 = ADD32(ctx->r6, -0X64C8);
    // 0x800167B0: addiu       $a1, $a1, -0x64A0
    ctx->r5 = ADD32(ctx->r5, -0X64A0);
    // 0x800167B4: jal         0x8002F7E0
    // 0x800167B8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800167B8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x800167BC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800167C0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800167C4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800167C8: addiu       $a2, $a2, -0x6470
    ctx->r6 = ADD32(ctx->r6, -0X6470);
    // 0x800167CC: addiu       $a1, $a1, -0x6298
    ctx->r5 = ADD32(ctx->r5, -0X6298);
    // 0x800167D0: jal         0x800301E0
    // 0x800167D4: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    osContInit_recomp(rdram, ctx);
        goto after_4;
    // 0x800167D4: addiu       $a0, $a0, -0x64A0
    ctx->r4 = ADD32(ctx->r4, -0X64A0);
    after_4:
    // 0x800167D8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800167DC: jal         0x8002E510
    // 0x800167E0: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    osStartThread_recomp(rdram, ctx);
        goto after_5;
    // 0x800167E0: addiu       $a0, $a0, -0x6458
    ctx->r4 = ADD32(ctx->r4, -0X6458);
    after_5:
    // 0x800167E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800167E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800167EC: jr          $ra
    // 0x800167F0: nop

    return;
    // 0x800167F0: nop

;}
RECOMP_FUNC void func_8080008C_chfactoryliftdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800098: lhu         $a1, 0x76($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X76);
    // 0x8080009C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A0: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x808000A4: addiu       $a1, $t6, 0xC
    ctx->r5 = ADD32(ctx->r14, 0XC);
    // 0x808000A8: jal         0x80085840
    // 0x808000AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _chswitch_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808000AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80109EEC
    // 0x808000B8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_1;
    // 0x808000B8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x808000BC: jal         0x80105010
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105010(rdram, ctx);
        goto after_2;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000C4: jal         0x800DA298
    // 0x808000C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808000C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808000CC: beql        $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000E0;
    }
    goto skip_0;
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000D4: jal         0x8010A570
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E0:
    // 0x808000E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F20: jal         0x800839B8
    // 0x80801F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801F28: jal         0x8080061C
    // 0x80801F2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80801F2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F38: jr          $ra
    // 0x80801F3C: nop

    return;
    // 0x80801F3C: nop

;}
RECOMP_FUNC void _glglobaldata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885B8: syscall     694
    recomp_syscall_handler(rdram, ctx, 0x800885B8);
    return;
    // 0x800885BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080000C_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800018: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800024: jal         0x800BA3FC
    // 0x80800028: addiu       $a1, $zero, 0x9EA
    ctx->r5 = ADD32(0, 0X9EA);
    func_800BA3FC(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $zero, 0x9EA
    ctx->r5 = ADD32(0, 0X9EA);
    after_0:
    // 0x8080002C: addiu       $t6, $zero, -0xFA
    ctx->r14 = ADD32(0, -0XFA);
    // 0x80800030: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080003C: addiu       $a2, $zero, -0xFA
    ctx->r6 = ADD32(0, -0XFA);
    // 0x80800040: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800044: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800048: jal         0x800BA450
    // 0x8080004C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800BA450(rdram, ctx);
        goto after_1;
    // 0x8080004C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x80800050: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800054: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800058: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080005C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800060: jal         0x800BA594
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA594(rdram, ctx);
        goto after_2;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x800BA75C
    // 0x80800070: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800BA75C(rdram, ctx);
        goto after_3;
    // 0x80800070: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800074: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X1160) << 16);
    // 0x80800078: lwc1        $f0, 0x1160($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X1160));
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800084: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800088: jal         0x800BA7FC
    // 0x8080008C: nop

    func_800BA7FC(rdram, ctx);
        goto after_4;
    // 0x8080008C: nop

    after_4:
    // 0x80800090: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x80800094: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000A4: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x808000A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808000AC: jal         0x800BA834
    // 0x808000B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BA834(rdram, ctx);
        goto after_5;
    // 0x808000B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1576, 0X1164) << 16);
    // 0x808000B8: lwc1        $f0, 0x1164($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1576, 0X1164));
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000C8: jal         0x800BA8F8
    // 0x808000CC: nop

    func_800BA8F8(rdram, ctx);
        goto after_6;
    // 0x808000CC: nop

    after_6:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x800BA5A8
    // 0x808000D8: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_800BA5A8(rdram, ctx);
        goto after_7;
    // 0x808000D8: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_7:
    // 0x808000DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000F0: jal         0x800BA7C4
    // 0x808000F4: nop

    func_800BA7C4(rdram, ctx);
        goto after_8;
    // 0x808000F4: nop

    after_8:
    // 0x808000F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808000FC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_800D59C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D59C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D59C4: lw          $t6, -0x4700($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4700);
    // 0x800D59C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D59CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D59D0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D59D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D59D8: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D59DC: jal         0x8001E210
    // 0x800D59E0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x800D59E0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800D59E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D59E8: lw          $v0, -0x4BC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BC0);
    // 0x800D59EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D59F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D59F4: sll         $t8, $v0, 26
    ctx->r24 = S32(ctx->r2 << 26);
    // 0x800D59F8: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x800D59FC: jr          $ra
    // 0x800D5A00: andi        $v0, $t9, 0x1
    ctx->r2 = ctx->r25 & 0X1;
    return;
    // 0x800D5A00: andi        $v0, $t9, 0x1
    ctx->r2 = ctx->r25 & 0X1;
;}
RECOMP_FUNC void func_800B5450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5450: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800B5454: lw          $a2, 0x7F10($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7F10);
    // 0x800B5458: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B545C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5460: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800B5464: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B5468: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B546C: beq         $a0, $t6, L_800B54A8
    if (ctx->r4 == ctx->r14) {
        // 0x800B5470: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800B54A8;
    }
    // 0x800B5470: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800B5474: addiu       $a3, $a3, 0x7F18
    ctx->r7 = ADD32(ctx->r7, 0X7F18);
    // 0x800B5478: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800B547C: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x800B5480: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x800B5484: blez        $a0, L_800B54A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B5488: nop
    
            goto L_800B54A8;
    }
    // 0x800B5488: nop

    // 0x800B548C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
L_800B5490:
    // 0x800B5490: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B5494: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B5498: beq         $a1, $t8, L_800B54A8
    if (ctx->r5 == ctx->r24) {
        // 0x800B549C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800B54A8;
    }
    // 0x800B549C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B54A0: bnel        $at, $zero, L_800B5490
    if (ctx->r1 != 0) {
        // 0x800B54A4: lw          $t8, 0x4($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X4);
            goto L_800B5490;
    }
    goto skip_0;
    // 0x800B54A4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    skip_0:
L_800B54A8:
    // 0x800B54A8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800B54AC: addiu       $a3, $a3, 0x7F18
    ctx->r7 = ADD32(ctx->r7, 0X7F18);
    // 0x800B54B0: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800B54B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B54B8: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B54BC: beql        $v1, $t9, L_800B5528
    if (ctx->r3 == ctx->r25) {
        // 0x800B54C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B5528;
    }
    goto skip_1;
    // 0x800B54C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800B54C4: jal         0x800BA2C4
    // 0x800B54C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_800BA2C4(rdram, ctx);
        goto after_0;
    // 0x800B54C8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B54CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800B54D0: addiu       $a3, $a3, 0x7F18
    ctx->r7 = ADD32(ctx->r7, 0X7F18);
    // 0x800B54D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800B54D8: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x800B54DC: addiu       $v1, $v1, 0x7F10
    ctx->r3 = ADD32(ctx->r3, 0X7F10);
    // 0x800B54E0: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x800B54E4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800B54E8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800B54EC: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x800B54F0: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x800B54F4: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800B54F8: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800B54FC: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800B5500: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800B5504: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B5508: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x800B550C: lh          $a1, 0x0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X0);
    // 0x800B5510: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800B5514: jal         0x8001B208
    // 0x800B5518: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    heap_realloc(rdram, ctx);
        goto after_1;
    // 0x800B5518: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
    // 0x800B551C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5520: sw          $v0, 0x7F10($at)
    MEM_W(0X7F10, ctx->r1) = ctx->r2;
    // 0x800B5524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B5528:
    // 0x800B5528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B552C: jr          $ra
    // 0x800B5530: nop

    return;
    // 0x800B5530: nop

;}
RECOMP_FUNC void _bsbabykaz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827D8: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827D8);
    return;
    // 0x800827DC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800008_ncbapan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80112524
    // 0x80800014: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800014: nop

    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014A8: jal         0x808000D4
    // 0x808014AC: nop

    bstaxi_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808014AC: nop

    after_0:
    // 0x808014B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014B8: jr          $ra
    // 0x808014BC: nop

    return;
    // 0x808014BC: nop

;}
RECOMP_FUNC void func_80802128_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080212C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802134: jal         0x80100094
    // 0x80802138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080213C: beq         $v0, $zero, L_8080214C
    if (ctx->r2 == 0) {
        // 0x80802140: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080214C;
    }
    // 0x80802140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802144: jal         0x800897C8
    // 0x80802148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80802148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8080214C:
    // 0x8080214C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802154: jr          $ra
    // 0x80802158: nop

    return;
    // 0x80802158: nop

;}
RECOMP_FUNC void bschokedie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C8: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D0: jal         0x8008CB10
    // 0x808000D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808000D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x808000D8: beql        $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000DC: lui         $a1, 0x3F14
        ctx->r5 = S32(0X3F14 << 16);
            goto L_808000EC;
    }
    goto skip_0;
    // 0x808000DC: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    skip_0:
    // 0x808000E0: jal         0x80090A2C
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000E8: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
L_808000EC:
    // 0x808000EC: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    // 0x808000F0: jal         0x8008CB10
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000F8: beql        $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000FC: lui         $a1, 0x3D4C
        ctx->r5 = S32(0X3D4C << 16);
            goto L_8080010C;
    }
    goto skip_1;
    // 0x808000FC: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    skip_1:
    // 0x80800100: jal         0x8009514C
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_3;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800108: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
L_8080010C:
    // 0x8080010C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800110: jal         0x8008CB10
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800118: beq         $v0, $zero, L_80800130
    if (ctx->r2 == 0) {
        // 0x8080011C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800130;
    }
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: addiu       $a1, $zero, 0x574
    ctx->r5 = ADD32(0, 0X574);
    // 0x80800124: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800128: jal         0x8009DF18
    // 0x8080012C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x8080012C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_5:
L_80800130:
    // 0x80800130: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800134: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800138: jal         0x8008CB10
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800140: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x80800144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800158;
    }
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: addiu       $a1, $zero, 0x575
    ctx->r5 = ADD32(0, 0X575);
    // 0x8080014C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800150: jal         0x8009DF18
    // 0x80800154: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x80800154: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_7:
L_80800158:
    // 0x80800158: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080015C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800160: jal         0x8008CB10
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800168: beq         $v0, $zero, L_80800180
    if (ctx->r2 == 0) {
        // 0x8080016C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800180;
    }
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: addiu       $a1, $zero, 0x576
    ctx->r5 = ADD32(0, 0X576);
    // 0x80800174: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800178: jal         0x8009DF18
    // 0x8080017C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_9;
    // 0x8080017C: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_9:
L_80800180:
    // 0x80800180: lui         $a1, 0x3F28
    ctx->r5 = S32(0X3F28 << 16);
    // 0x80800184: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80800188: jal         0x8008CB10
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800190: beq         $v0, $zero, L_808001A8
    if (ctx->r2 == 0) {
        // 0x80800194: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A8;
    }
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: addiu       $a1, $zero, 0x577
    ctx->r5 = ADD32(0, 0X577);
    // 0x8080019C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001A0: jal         0x8009DF18
    // 0x808001A4: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_11;
    // 0x808001A4: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_11:
L_808001A8:
    // 0x808001A8: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808001AC: ori         $a1, $a1, 0x930C
    ctx->r5 = ctx->r5 | 0X930C;
    // 0x808001B0: jal         0x8008CB10
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_12;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001B8: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D4;
    }
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808001C4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808001C8: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808001CC: jal         0x8009DF94
    // 0x808001D0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_13;
    // 0x808001D0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_13:
L_808001D4:
    // 0x808001D4: lui         $a1, 0x3F4A
    ctx->r5 = S32(0X3F4A << 16);
    // 0x808001D8: ori         $a1, $a1, 0x275
    ctx->r5 = ctx->r5 | 0X275;
    // 0x808001DC: jal         0x8008CB10
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_14;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001E4: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800200;
    }
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808001F0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808001F4: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808001F8: jal         0x8009DF94
    // 0x808001FC: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DF94(rdram, ctx);
        goto after_15;
    // 0x808001FC: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_15:
L_80800200:
    // 0x80800200: lui         $a1, 0x3F6D
    ctx->r5 = S32(0X3F6D << 16);
    // 0x80800204: ori         $a1, $a1, 0xD97F
    ctx->r5 = ctx->r5 | 0XD97F;
    // 0x80800208: jal         0x8008CB10
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_16;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800210: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800214: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080022C;
    }
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x8080021C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800220: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80800224: jal         0x8009DF94
    // 0x80800228: addiu       $a3, $zero, 0x2328
    ctx->r7 = ADD32(0, 0X2328);
    func_8009DF94(rdram, ctx);
        goto after_17;
    // 0x80800228: addiu       $a3, $zero, 0x2328
    ctx->r7 = ADD32(0, 0X2328);
    after_17:
L_8080022C:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x800852F0
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_18;
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800238: beql        $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x8080023C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080024C;
    }
    goto skip_2;
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800240: jal         0x80085200
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080024C:
    // 0x8080024C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void func_808005C0_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: jr          $ra
    // 0x808005C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808005C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800CEB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEB80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEB84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEB88: jal         0x800CE3E0
    // 0x800CEB8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CEB8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CEB90: lb          $t6, 0x12($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X12);
    // 0x800CEB94: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEB9C: beql        $t6, $zero, L_800CEBD0
    if (ctx->r14 == 0) {
        // 0x800CEBA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CEBD0;
    }
    goto skip_0;
    // 0x800CEBA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800CEBA4: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x800CEBA8: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CEBAC: beql        $at, $zero, L_800CEBD0
    if (ctx->r1 == 0) {
        // 0x800CEBB0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CEBD0;
    }
    goto skip_1;
    // 0x800CEBB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800CEBB4: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800CEBB8: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CEBBC: bnel        $at, $zero, L_800CEBD0
    if (ctx->r1 != 0) {
        // 0x800CEBC0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CEBD0;
    }
    goto skip_2;
    // 0x800CEBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800CEBC4: b           L_800CEBD0
    // 0x800CEBC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CEBD0;
    // 0x800CEBC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CEBCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CEBD0:
    // 0x800CEBD0: jr          $ra
    // 0x800CEBD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CEBD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808000C4_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: jal         0x800D8FF8
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000D8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808000DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000E0: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808000E4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000E8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000F0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x808000FC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800100: bne         $t7, $at, L_8080012C
    if (ctx->r15 != ctx->r1) {
        // 0x80800104: swc1        $f10, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
            goto L_8080012C;
    }
    // 0x80800104: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x80800108: jal         0x8010B990
    // 0x8080010C: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x8080010C: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    after_1:
    // 0x80800110: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x80800114: beq         $t8, $zero, L_80800124
    if (ctx->r24 == 0) {
        // 0x80800118: nop
    
            goto L_80800124;
    }
    // 0x80800118: nop

    // 0x8080011C: jal         0x808002E0
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002E0_chweldarbossfireball(rdram, ctx);
        goto after_2;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80800124:
    // 0x80800124: jal         0x80800404
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800404_chweldarbossfireball(rdram, ctx);
        goto after_3;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8080012C:
    // 0x8080012C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80800130: beql        $a0, $zero, L_8080016C
    if (ctx->r4 == 0) {
        // 0x80800134: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080016C;
    }
    goto skip_0;
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800138: jal         0x800C8CB8
    // 0x8080013C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x8080013C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800140: jal         0x8001210C
    // 0x80800144: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_5;
    // 0x80800144: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800148: beq         $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x8080014C: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1376, 0X468) << 16);
            goto L_8080015C;
    }
    // 0x8080014C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1376, 0X468) << 16);
    // 0x80800150: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1376, 0X474) << 16);
    // 0x80800154: b           L_80800160
    // 0x80800158: addiu       $a1, $a1, 0x474
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1376, 0X474));
        goto L_80800160;
    // 0x80800158: addiu       $a1, $a1, 0x474
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1376, 0X474));
L_8080015C:
    // 0x8080015C: addiu       $a1, $a1, 0x468
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1376, 0X468));
L_80800160:
    // 0x80800160: jal         0x800C8E84
    // 0x80800164: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800C8E84(rdram, ctx);
        goto after_6;
    // 0x80800164: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_6:
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080016C:
    // 0x8080016C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_800F9354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F935C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F9360: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F9364: jal         0x800F54E4
    // 0x800F9368: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800F9368: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F936C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800F9370: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F9374: jal         0x800F5410
    // 0x800F9378: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x800F9378: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    after_1:
    // 0x800F937C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9380: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800F9384: beq         $v0, $v1, L_800F93A0
    if (ctx->r2 == ctx->r3) {
        // 0x800F9388: sw          $v0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r2;
            goto L_800F93A0;
    }
    // 0x800F9388: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800F938C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800F9390: beq         $v0, $at, L_800F93B0
    if (ctx->r2 == ctx->r1) {
        // 0x800F9394: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_800F93B0;
    }
    // 0x800F9394: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800F9398: b           L_800F93B8
    // 0x800F939C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F93B8;
    // 0x800F939C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F93A0:
    // 0x800F93A0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800F93A4: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x800F93A8: b           L_800F93B4
    // 0x800F93AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_800F93B4;
    // 0x800F93AC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_800F93B0:
    // 0x800F93B0: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
L_800F93B4:
    // 0x800F93B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F93B8:
    // 0x800F93B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F93BC: jr          $ra
    // 0x800F93C0: nop

    return;
    // 0x800F93C0: nop

;}
RECOMP_FUNC void func_800B4354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B4358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B435C: jal         0x800B3EDC
    // 0x800B4360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B3EDC(rdram, ctx);
        goto after_0;
    // 0x800B4360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800B4364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B436C: jr          $ra
    // 0x800B4370: nop

    return;
    // 0x800B4370: nop

;}
RECOMP_FUNC void bababykaz_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001E8: jal         0x800EA068
    // 0x808001EC: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x808001EC: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_0:
    // 0x808001F0: bnel        $v0, $zero, L_80800204
    if (ctx->r2 != 0) {
        // 0x808001F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001F8: jal         0x800C77DC
    // 0x808001FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C77DC(rdram, ctx);
        goto after_1;
    // 0x808001FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800204:
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_8080064C_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800654: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800658: jal         0x80100094
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800660: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800664: jal         0x800A16BC
    // 0x80800668: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A16BC(rdram, ctx);
        goto after_1;
    // 0x80800668: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080066C: jal         0x800CEAA8
    // 0x80800670: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_2;
    // 0x80800670: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800674: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x80800678: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800684;
    }
    // 0x80800678: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080067C: jal         0x800CE88C
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_3;
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80800684:
    // 0x80800684: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800688: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080068C: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    // 0x80800690: jal         0x8008A2B0
    // 0x80800694: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800694: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800698: beq         $v0, $zero, L_808006A8
    if (ctx->r2 == 0) {
        // 0x8080069C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808006A8;
    }
    // 0x8080069C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808006A0: jal         0x8008A2C0
    // 0x808006A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808006A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
L_808006A8:
    // 0x808006A8: jal         0x800FDC28
    // 0x808006AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_6;
    // 0x808006AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x808006B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006B8: jr          $ra
    // 0x808006BC: nop

    return;
    // 0x808006BC: nop

;}
RECOMP_FUNC void func_808000FC_chfairgroundworker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800100: addiu       $at, $zero, 0xB6
    ctx->r1 = ADD32(0, 0XB6);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080010C: bne         $a1, $at, L_80800120
    if (ctx->r5 != ctx->r1) {
        // 0x80800110: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800120;
    }
    // 0x80800110: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800114: jal         0x8080013C
    // 0x80800118: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8080013C_chfairgroundworker(rdram, ctx);
        goto after_0;
    // 0x80800118: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080011C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80800120:
    // 0x80800120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: jal         0x8008A1A0
    // 0x80800128: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x80800128: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void _gcmapsects_lagoontop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FE8: syscall     663
    recomp_syscall_handler(rdram, ctx, 0x80087FE8);
    return;
    // 0x80087FEC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void ncbasuck_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: jr          $ra
    // 0x80800090: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800090: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chquicksandbaddy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F68: syscall     482
    recomp_syscall_handler(rdram, ctx, 0x80086F68);
    return;
    // 0x80086F6C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808007C8_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007D0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808007D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007D8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808007DC: bnel        $t7, $at, L_80800820
    if (ctx->r15 != ctx->r1) {
        // 0x808007E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800820;
    }
    goto skip_0;
    // 0x808007E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808007E4: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x808007E8: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x808007EC: bgezl       $t0, L_80800820
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808007F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800820;
    }
    goto skip_1;
    // 0x808007F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808007F4: jal         0x800D8FF8
    // 0x808007F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808007F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800804: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800808: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8080080C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800810: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800814: jal         0x80103110
    // 0x80800818: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800818: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800820:
    // 0x80800820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

;}
RECOMP_FUNC void func_80800F88_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800F8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F90: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F94: lbu         $t6, 0x165($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X165);
    // 0x80800F98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F9C: beql        $t6, $zero, L_80800FFC
    if (ctx->r14 == 0) {
        // 0x80800FA0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800FFC;
    }
    goto skip_0;
    // 0x80800FA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800FA4: jal         0x8009BB5C
    // 0x80800FA8: nop

    func_8009BB5C(rdram, ctx);
        goto after_0;
    // 0x80800FA8: nop

    after_0:
    // 0x80800FAC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB4: jal         0x8009C128
    // 0x80800FB8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800FB8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800FBC: lbu         $a0, 0x165($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X165);
    // 0x80800FC0: jal         0x800C35E8
    // 0x80800FC4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C35E8(rdram, ctx);
        goto after_2;
    // 0x80800FC4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800FC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D00) << 16);
    // 0x80800FCC: lwc1        $f4, 0x1D00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D00));
    // 0x80800FD0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800FD4: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80800FD8: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800FDC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800FE0: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x80800FE4: jal         0x800F10B4
    // 0x80800FE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800FE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800FEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800FF0: jal         0x800C31DC
    // 0x80800FF4: lbu         $a0, 0x165($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X165);
    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x80800FF4: lbu         $a0, 0x165($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X165);
    after_4:
    // 0x80800FF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FFC:
    // 0x80800FFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801000: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801004: jr          $ra
    // 0x80801008: nop

    return;
    // 0x80801008: nop

;}
