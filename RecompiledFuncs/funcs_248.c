#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _batimer_isZero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085330: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x80085330);
    return;
    // 0x80085334: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80801F90_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F90: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80801F94: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80801F98: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2204, 0X27BC) << 16);
    // 0x80801F9C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801FA0: addiu       $a2, $a2, 0x27BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2204, 0X27BC));
    // 0x80801FA4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801FA8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80801FAC: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80801FB0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80801FB4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80801FB8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80801FBC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80801FC0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80801FC4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80801FC8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801FCC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801FD0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801FD4: bne         $a1, $at, L_80801FE4
    if (ctx->r5 != ctx->r1) {
        // 0x80801FD8: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_80801FE4;
    }
    // 0x80801FD8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801FDC: b           L_80801FE8
    // 0x80801FE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80801FE8;
    // 0x80801FE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80801FE4:
    // 0x80801FE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80801FE8:
    // 0x80801FE8: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80801FEC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801FF0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80801FF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801FF8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80801FFC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80802000: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80802004: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80802008: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8080200C: addu        $s0, $a2, $t6
    ctx->r16 = ADD32(ctx->r6, ctx->r14);
    // 0x80802010: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80802014: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80802018: addiu       $s5, $s0, 0x30
    ctx->r21 = ADD32(ctx->r16, 0X30);
    // 0x8080201C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80802020: addiu       $s6, $zero, 0x5
    ctx->r22 = ADD32(0, 0X5);
    // 0x80802024: addiu       $s3, $sp, 0x80
    ctx->r19 = ADD32(ctx->r29, 0X80);
    // 0x80802028: lwc1        $f20, 0x48($t7)
    ctx->f20.u32l = MEM_W(ctx->r15, 0X48);
L_8080202C:
    // 0x8080202C: addiu       $a0, $zero, 0x2C3
    ctx->r4 = ADD32(0, 0X2C3);
    // 0x80802030: jal         0x801084B0
    // 0x80802034: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80802034: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x80802038: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8080203C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80802040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802044: lw          $t8, 0x98($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X98);
    // 0x80802048: addiu       $v1, $v1, 0x98
    ctx->r3 = ADD32(ctx->r3, 0X98);
    // 0x8080204C: sw          $t8, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r24;
    // 0x80802050: jal         0x80101FDC
    // 0x80802054: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80802054: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80802058: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8080205C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802060: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x80802064: jal         0x80103140
    // 0x80802068: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_80103140(rdram, ctx);
        goto after_2;
    // 0x80802068: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_2:
    // 0x8080206C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80802070: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80802074: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80802078: swc1        $f4, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f4.u32l;
    // 0x8080207C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80802080: jal         0x800DC178
    // 0x80802084: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80802084: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    after_3:
    // 0x80802088: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8080208C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802090: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x80802094: swc1        $f8, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f8.u32l;
    // 0x80802098: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8080209C: jal         0x800EEB9C
    // 0x808020A0: lw          $a1, 0x48($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x808020A0: lw          $a1, 0x48($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X48);
    after_4:
    // 0x808020A4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808020A8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808020AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808020B0: jal         0x800EF04C
    // 0x808020B4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808020B4: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x808020B8: swc1        $f28, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f28.u32l;
    // 0x808020BC: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808020C0: jal         0x800DC178
    // 0x808020C4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808020C4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    after_6:
    // 0x808020C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808020CC: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x808020D0: jal         0x800EFA98
    // 0x808020D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EFA98(rdram, ctx);
        goto after_7;
    // 0x808020D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x808020D8: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808020DC: jal         0x800DC178
    // 0x808020E0: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808020E0: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    after_8:
    // 0x808020E4: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x808020E8: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808020EC: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808020F0: jal         0x800DC178
    // 0x808020F4: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808020F4: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    after_9:
    // 0x808020F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808020FC: bne         $s2, $s6, L_8080202C
    if (ctx->r18 != ctx->r22) {
        // 0x80802100: swc1        $f0, 0x50($s1)
        MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
            goto L_8080202C;
    }
    // 0x80802100: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x80802104: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80802108: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080210C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80802110: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80802114: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80802118: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8080211C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80802120: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80802124: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80802128: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8080212C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80802130: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80802134: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80802138: jr          $ra
    // 0x8080213C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8080213C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8010A430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A438: jal         0x80102F74
    // 0x8010A43C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_80102F74(rdram, ctx);
        goto after_0;
    // 0x8010A43C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_0:
    // 0x8010A440: beq         $v0, $zero, L_8010A450
    if (ctx->r2 == 0) {
        // 0x8010A444: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8010A450;
    }
    // 0x8010A444: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8010A448: b           L_8010A560
    // 0x8010A44C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010A560;
    // 0x8010A44C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010A450:
    // 0x8010A450: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x8010A454: addiu       $t7, $t6, -0xF
    ctx->r15 = ADD32(ctx->r14, -0XF);
    // 0x8010A458: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x8010A45C: beq         $at, $zero, L_8010A55C
    if (ctx->r1 == 0) {
        // 0x8010A460: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8010A55C;
    }
    // 0x8010A460: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8010A464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A468: addu        $at, $at, $t7
    gpr jr_addend_8010A470 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8010A46C: lw          $t7, 0x64B8($at)
    ctx->r15 = ADD32(ctx->r1, 0X64B8);
    // 0x8010A470: jr          $t7
    // 0x8010A474: nop

    switch (jr_addend_8010A470 >> 2) {
        case 0: goto L_8010A4A4; break;
        case 1: goto L_8010A490; break;
        case 2: goto L_8010A55C; break;
        case 3: goto L_8010A4B8; break;
        case 4: goto L_8010A478; break;
        case 5: goto L_8010A4CC; break;
        case 6: goto L_8010A4E0; break;
        case 7: goto L_8010A4F8; break;
        case 8: goto L_8010A50C; break;
        case 9: goto L_8010A520; break;
        case 10: goto L_8010A534; break;
        case 11: goto L_8010A548; break;
        default: switch_error(__func__, 0x8010A470, 0x801264B8);
    }
    // 0x8010A474: nop

L_8010A478:
    // 0x8010A478: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010A47C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010A480: jal         0x800DC298
    // 0x8010A484: nop

    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x8010A484: nop

    after_1:
    // 0x8010A488: b           L_8010A564
    // 0x8010A48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A490:
    // 0x8010A490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A494: jal         0x800DC298
    // 0x8010A498: lwc1        $f12, 0x64E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64E8);
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x8010A498: lwc1        $f12, 0x64E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64E8);
    after_2:
    // 0x8010A49C: b           L_8010A564
    // 0x8010A4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A4A4:
    // 0x8010A4A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A4A8: jal         0x800DC298
    // 0x8010A4AC: lwc1        $f12, 0x64EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64EC);
    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x8010A4AC: lwc1        $f12, 0x64EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64EC);
    after_3:
    // 0x8010A4B0: b           L_8010A564
    // 0x8010A4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A4B8:
    // 0x8010A4B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A4BC: jal         0x800DC298
    // 0x8010A4C0: lwc1        $f12, 0x64F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64F0);
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x8010A4C0: lwc1        $f12, 0x64F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64F0);
    after_4:
    // 0x8010A4C4: b           L_8010A564
    // 0x8010A4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A4CC:
    // 0x8010A4CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A4D0: jal         0x800DC298
    // 0x8010A4D4: lwc1        $f12, 0x64F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64F4);
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x8010A4D4: lwc1        $f12, 0x64F4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64F4);
    after_5:
    // 0x8010A4D8: b           L_8010A564
    // 0x8010A4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A4E0:
    // 0x8010A4E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010A4E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010A4E8: jal         0x800DC298
    // 0x8010A4EC: nop

    func_800DC298(rdram, ctx);
        goto after_6;
    // 0x8010A4EC: nop

    after_6:
    // 0x8010A4F0: b           L_8010A564
    // 0x8010A4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A4F8:
    // 0x8010A4F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A4FC: jal         0x800DC298
    // 0x8010A500: lwc1        $f12, 0x64F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64F8);
    func_800DC298(rdram, ctx);
        goto after_7;
    // 0x8010A500: lwc1        $f12, 0x64F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64F8);
    after_7:
    // 0x8010A504: b           L_8010A564
    // 0x8010A508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A50C:
    // 0x8010A50C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A510: jal         0x800DC298
    // 0x8010A514: lwc1        $f12, 0x64FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64FC);
    func_800DC298(rdram, ctx);
        goto after_8;
    // 0x8010A514: lwc1        $f12, 0x64FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X64FC);
    after_8:
    // 0x8010A518: b           L_8010A564
    // 0x8010A51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A520:
    // 0x8010A520: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A524: jal         0x800DC298
    // 0x8010A528: lwc1        $f12, 0x6500($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6500);
    func_800DC298(rdram, ctx);
        goto after_9;
    // 0x8010A528: lwc1        $f12, 0x6500($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6500);
    after_9:
    // 0x8010A52C: b           L_8010A564
    // 0x8010A530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A534:
    // 0x8010A534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A538: jal         0x800DC298
    // 0x8010A53C: lwc1        $f12, 0x6504($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6504);
    func_800DC298(rdram, ctx);
        goto after_10;
    // 0x8010A53C: lwc1        $f12, 0x6504($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6504);
    after_10:
    // 0x8010A540: b           L_8010A564
    // 0x8010A544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A548:
    // 0x8010A548: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A54C: jal         0x800DC298
    // 0x8010A550: lwc1        $f12, 0x6508($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6508);
    func_800DC298(rdram, ctx);
        goto after_11;
    // 0x8010A550: lwc1        $f12, 0x6508($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6508);
    after_11:
    // 0x8010A554: b           L_8010A564
    // 0x8010A558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A564;
    // 0x8010A558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A55C:
    // 0x8010A55C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010A560:
    // 0x8010A560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A564:
    // 0x8010A564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A568: jr          $ra
    // 0x8010A56C: nop

    return;
    // 0x8010A56C: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084488: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x80084488);
    return;
    // 0x8008448C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808012C8_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C8: jr          $ra
    // 0x808012CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808012CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _sueggmove_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A450: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A450);
    return;
    // 0x8008A454: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800130_chfactoryflypad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800134: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080013C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800140: beq         $a1, $at, L_8080020C
    if (ctx->r5 == ctx->r1) {
        // 0x80800144: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080020C;
    }
    // 0x80800144: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800148: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080014C: beq         $a1, $at, L_80800174
    if (ctx->r5 == ctx->r1) {
        // 0x80800150: addiu       $a0, $zero, 0x234
        ctx->r4 = ADD32(0, 0X234);
            goto L_80800174;
    }
    // 0x80800150: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    // 0x80800154: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800158: beq         $a1, $at, L_808001B0
    if (ctx->r5 == ctx->r1) {
        // 0x8080015C: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_808001B0;
    }
    // 0x8080015C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800164: beq         $a1, $at, L_80800220
    if (ctx->r5 == ctx->r1) {
        // 0x80800168: nop
    
            goto L_80800220;
    }
    // 0x80800168: nop

    // 0x8080016C: b           L_8080023C
    // 0x80800170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080023C;
    // 0x80800170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800174:
    // 0x80800174: jal         0x801084B0
    // 0x80800178: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8080017C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800180: jal         0x80088840
    // 0x80800184: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800184: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_1:
    // 0x80800188: beq         $v0, $zero, L_808001A0
    if (ctx->r2 == 0) {
        // 0x8080018C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808001A0;
    }
    // 0x8080018C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800190: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80800194: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800198: jal         0x800862D8
    // 0x8080019C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080019C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
L_808001A0:
    // 0x808001A0: jal         0x800FFAB0
    // 0x808001A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x808001A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808001A8: b           L_8080023C
    // 0x808001AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x808001AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001B0:
    // 0x808001B0: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x808001B4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808001B8: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808001BC: bne         $t8, $at, L_80800204
    if (ctx->r24 != ctx->r1) {
        // 0x808001C0: nop
    
            goto L_80800204;
    }
    // 0x808001C0: nop

    // 0x808001C4: jal         0x80088840
    // 0x808001C8: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x808001C8: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_4:
    // 0x808001CC: beq         $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800204;
    }
    // 0x808001D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: addiu       $a1, $zero, 0x42F
    ctx->r5 = ADD32(0, 0X42F);
    // 0x808001D8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808001DC: jal         0x80089C28
    // 0x808001E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808001E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x808001E4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808001E8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808001EC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808001F0: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    // 0x808001F4: jal         0x80085708
    // 0x808001F8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808001F8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_6:
    // 0x808001FC: b           L_8080023C
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800204:
    // 0x80800204: b           L_8080023C
    // 0x80800208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080023C;
    // 0x80800208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080020C:
    // 0x8080020C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: jal         0x80108B04
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800218: b           L_8080023C
    // 0x8080021C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080023C;
    // 0x8080021C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800220:
    // 0x80800220: jal         0x80800088
    // 0x80800224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800088_chfactoryflypad(rdram, ctx);
        goto after_8;
    // 0x80800224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80800228: b           L_8080023C
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080023C;
    // 0x8080022C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800230: b           L_8080023C
    // 0x80800234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080023C;
    // 0x80800234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080023C:
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

    // 0x8080024C: nop

;}
RECOMP_FUNC void _bamovethrust_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084ED8: syscall     141
    recomp_syscall_handler(rdram, ctx, 0x80084ED8);
    return;
    // 0x80084EDC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800A64_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A74: jal         0x80100094
    // 0x80800A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A80: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800A84: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80800A88: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800A8C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80800A90: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A94: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80800A98: sb          $t8, 0x2D0($t0)
    MEM_B(0X2D0, ctx->r8) = ctx->r24;
    // 0x80800A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AA4: jr          $ra
    // 0x80800AA8: nop

    return;
    // 0x80800AA8: nop

;}
RECOMP_FUNC void func_800EB70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB70C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EB710: addiu       $a0, $a0, 0x2E80
    ctx->r4 = ADD32(ctx->r4, 0X2E80);
    // 0x800EB714: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800EB718: sh          $t6, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r14;
    // 0x800EB71C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EB720: sw          $zero, 0x2E80($at)
    MEM_W(0X2E80, ctx->r1) = 0;
    // 0x800EB724: sw          $zero, 0x2E84($at)
    MEM_W(0X2E84, ctx->r1) = 0;
    // 0x800EB728: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EB72C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EB730: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800EB734: sw          $zero, 0x2E88($at)
    MEM_W(0X2E88, ctx->r1) = 0;
    // 0x800EB738: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
    // 0x800EB73C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800EB740: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800EB744: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800EB748: jr          $ra
    // 0x800EB74C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    return;
    // 0x800EB74C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
;}
RECOMP_FUNC void func_800F70EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F70EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F70F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F70F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F70F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F70FC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7100: jal         0x8009BD44
    // 0x800F7104: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009BD44(rdram, ctx);
        goto after_0;
    // 0x800F7104: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F7108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F710C: xori        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 ^ 0X3;
    // 0x800F7110: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
    // 0x800F7114: jr          $ra
    // 0x800F7118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F7118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void idscroll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x80800004: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800008: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800010: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80800014: beq         $at, $zero, L_8080003C
    if (ctx->r1 == 0) {
        // 0x80800018: lh          $v0, 0x4($t6)
        ctx->r2 = MEM_H(ctx->r14, 0X4);
            goto L_8080003C;
    }
    // 0x80800018: lh          $v0, 0x4($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4);
L_8080001C:
    // 0x8080001C: lh          $t8, 0xA($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XA);
    // 0x80800020: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800024: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80800028: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    // 0x8080002C: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, -0X2000);
    // 0x80800030: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800034: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x80800038: sh          $a0, -0x6($a2)
        MEM_H(-0X6, ctx->r6) = ctx->r4;
            goto L_8080001C;
    }
    // 0x80800038: sh          $a0, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r4;
L_8080003C:
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808017A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808017B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808017B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017B8: lbu         $t8, 0x77($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X77);
    // 0x808017BC: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x808017C0: lbu         $t7, 0x7D($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7D);
    // 0x808017C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808017C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808017CC: sb          $t6, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r14;
    // 0x808017D0: blez        $t8, L_80801870
    if (SIGNED(ctx->r24) <= 0) {
        // 0x808017D4: sb          $t7, 0x7E($a0)
        MEM_B(0X7E, ctx->r4) = ctx->r15;
            goto L_80801870;
    }
    // 0x808017D4: sb          $t7, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r15;
    // 0x808017D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808017DC: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
L_808017E0:
    // 0x808017E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808017E4: addu        $v0, $t9, $s0
    ctx->r2 = ADD32(ctx->r25, ctx->r16);
    // 0x808017E8: lbu         $t0, 0x4C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4C);
    // 0x808017EC: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x808017F0: sb          $t1, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r9;
    // 0x808017F4: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x808017F8: addu        $v0, $t2, $s0
    ctx->r2 = ADD32(ctx->r10, ctx->r16);
    // 0x808017FC: lbu         $t3, 0x4C($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801800: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x80801804: sb          $t4, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r12;
    // 0x80801808: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x8080180C: addu        $v0, $t5, $s0
    ctx->r2 = ADD32(ctx->r13, ctx->r16);
    // 0x80801810: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x80801814: lbu         $t1, 0x4C($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801818: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080181C: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80801820: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80801824: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x80801828: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x8080182C: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80801830: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x80801834: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80801838: lbu         $t6, 0x83($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X83);
    // 0x8080183C: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x80801840: lbu         $t9, 0x4C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801844: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80801848: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x8080184C: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80801850: or          $t0, $t8, $t1
    ctx->r8 = ctx->r24 | ctx->r9;
    // 0x80801854: sb          $t0, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r8;
    // 0x80801858: lbu         $t2, 0x77($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X77);
    // 0x8080185C: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80801860: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80801864: bnel        $at, $zero, L_808017E0
    if (ctx->r1 != 0) {
        // 0x80801868: lw          $t9, 0x68($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X68);
            goto L_808017E0;
    }
    goto skip_0;
    // 0x80801868: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    skip_0:
    // 0x8080186C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80801870:
    // 0x80801870: lbu         $v0, 0x7F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7F);
    // 0x80801874: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80801878: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080187C: beq         $v0, $s0, L_80801894
    if (ctx->r2 == ctx->r16) {
        // 0x80801880: nop
    
            goto L_80801894;
    }
    // 0x80801880: nop

    // 0x80801884: beq         $v0, $at, L_808018B4
    if (ctx->r2 == ctx->r1) {
        // 0x80801888: nop
    
            goto L_808018B4;
    }
    // 0x80801888: nop

    // 0x8080188C: b           L_808018D0
    // 0x80801890: nop

        goto L_808018D0;
    // 0x80801890: nop

L_80801894:
    // 0x80801894: jal         0x800DB9B0
    // 0x80801898: nop

    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80801898: nop

    after_0:
    // 0x8080189C: beq         $v0, $zero, L_808018AC
    if (ctx->r2 == 0) {
        // 0x808018A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808018AC;
    }
    // 0x808018A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808018A4: jal         0x80801724
    // 0x808018A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801724_gcmapsects(rdram, ctx);
        goto after_1;
    // 0x808018A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_808018AC:
    // 0x808018AC: b           L_808018D0
    // 0x808018B0: lbu         $v0, 0x7F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7F);
        goto L_808018D0;
    // 0x808018B0: lbu         $v0, 0x7F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7F);
L_808018B4:
    // 0x808018B4: jal         0x800DB9B0
    // 0x808018B8: nop

    func_800DB9B0(rdram, ctx);
        goto after_2;
    // 0x808018B8: nop

    after_2:
    // 0x808018BC: bne         $v0, $zero, L_808018CC
    if (ctx->r2 != 0) {
        // 0x808018C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808018CC;
    }
    // 0x808018C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808018C4: jal         0x80801724
    // 0x808018C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801724_gcmapsects(rdram, ctx);
        goto after_3;
    // 0x808018C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
L_808018CC:
    // 0x808018CC: lbu         $v0, 0x7F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X7F);
L_808018D0:
    // 0x808018D0: beq         $v0, $s0, L_808018E8
    if (ctx->r2 == ctx->r16) {
        // 0x808018D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808018E8;
    }
    // 0x808018D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808018D8: beql        $v0, $at, L_80801904
    if (ctx->r2 == ctx->r1) {
        // 0x808018DC: sb          $zero, 0x78($s1)
        MEM_B(0X78, ctx->r17) = 0;
            goto L_80801904;
    }
    goto skip_1;
    // 0x808018DC: sb          $zero, 0x78($s1)
    MEM_B(0X78, ctx->r17) = 0;
    skip_1:
    // 0x808018E0: b           L_80801908
    // 0x808018E4: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
        goto L_80801908;
    // 0x808018E4: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
L_808018E8:
    // 0x808018E8: jal         0x80801554
    // 0x808018EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801554_gcmapsects(rdram, ctx);
        goto after_4;
    // 0x808018EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x808018F0: jal         0x80801640
    // 0x808018F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801640_gcmapsects(rdram, ctx);
        goto after_5;
    // 0x808018F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x808018F8: b           L_80801908
    // 0x808018FC: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
        goto L_80801908;
    // 0x808018FC: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
    // 0x80801900: sb          $zero, 0x78($s1)
    MEM_B(0X78, ctx->r17) = 0;
L_80801904:
    // 0x80801904: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
L_80801908:
    // 0x80801908: beql        $v0, $zero, L_8080191C
    if (ctx->r2 == 0) {
        // 0x8080190C: lbu         $v1, 0x77($s1)
        ctx->r3 = MEM_BU(ctx->r17, 0X77);
            goto L_8080191C;
    }
    goto skip_2;
    // 0x8080190C: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
    skip_2:
    // 0x80801910: jalr        $v0
    // 0x80801914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80801914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80801918: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
L_8080191C:
    // 0x8080191C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801920: blezl       $v1, L_80801968
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80801924: lbu         $t9, 0x78($s1)
        ctx->r25 = MEM_BU(ctx->r17, 0X78);
            goto L_80801968;
    }
    goto skip_3;
    // 0x80801924: lbu         $t9, 0x78($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X78);
    skip_3:
L_80801928:
    // 0x80801928: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x8080192C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801930: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80801934: lw          $t5, 0x4C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4C);
    // 0x80801938: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8080193C: bltzl       $t7, L_80801954
    if (SIGNED(ctx->r15) < 0) {
        // 0x80801940: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80801954;
    }
    goto skip_4;
    // 0x80801940: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x80801944: jal         0x808003F4
    // 0x80801948: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808003F4_gcmapsects(rdram, ctx);
        goto after_7;
    // 0x80801948: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x8080194C: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
    // 0x80801950: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80801954:
    // 0x80801954: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80801958: bne         $at, $zero, L_80801928
    if (ctx->r1 != 0) {
        // 0x8080195C: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80801928;
    }
    // 0x8080195C: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80801960: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801964: lbu         $t9, 0x78($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X78);
L_80801968:
    // 0x80801968: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080196C: bne         $t9, $zero, L_80801984
    if (ctx->r25 != 0) {
        // 0x80801970: nop
    
            goto L_80801984;
    }
    // 0x80801970: nop

    // 0x80801974: jal         0x80800A08
    // 0x80801978: lbu         $a1, 0x83($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X83);
    func_80800A08_gcmapsects(rdram, ctx);
        goto after_8;
    // 0x80801978: lbu         $a1, 0x83($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X83);
    after_8:
    // 0x8080197C: b           L_80801990
    // 0x80801980: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
        goto L_80801990;
    // 0x80801980: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
L_80801984:
    // 0x80801984: jal         0x80800B58
    // 0x80801988: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800B58_gcmapsects(rdram, ctx);
        goto after_9;
    // 0x80801988: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8080198C: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
L_80801990:
    // 0x80801990: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801994: blezl       $v1, L_808019E4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80801998: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808019E4;
    }
    goto skip_5;
    // 0x80801998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
L_8080199C:
    // 0x8080199C: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x808019A0: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x808019A4: lw          $t1, 0x4C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4C);
    // 0x808019A8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808019AC: bgezl       $t2, L_808019D4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808019B0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_808019D4;
    }
    goto skip_6;
    // 0x808019B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x808019B4: jal         0x800D6B0C
    // 0x808019B8: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    func_800D6B0C(rdram, ctx);
        goto after_10;
    // 0x808019B8: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    after_10:
    // 0x808019BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808019C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808019C4: jal         0x808005D0
    // 0x808019C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_808005D0_gcmapsects(rdram, ctx);
        goto after_11;
    // 0x808019C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_11:
    // 0x808019CC: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
    // 0x808019D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808019D4:
    // 0x808019D4: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808019D8: bne         $at, $zero, L_8080199C
    if (ctx->r1 != 0) {
        // 0x808019DC: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_8080199C;
    }
    // 0x808019DC: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x808019E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808019E4:
    // 0x808019E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808019EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808019F0: jr          $ra
    // 0x808019F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808019F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bapackctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800130: jal         0x8009EADC
    // 0x80800134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8009EADC(rdram, ctx);
        goto after_0;
    // 0x80800134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800138: jal         0x80800008
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800008_bapackctrl(rdram, ctx);
        goto after_1;
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C18: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C18);
    return;
    // 0x80087C1C: addi        $t0, $zero, 0x9C
    ctx->r8 = ADD32(0, 0X9C);
;}
RECOMP_FUNC void func_8080633C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080633C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80806340: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806344: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80806348: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080634C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806350: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80806354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80806358: jal         0x80802458
    // 0x8080635C: lw          $s1, 0x188($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X188);
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080635C: lw          $s1, 0x188($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X188);
    after_0:
    // 0x80806360: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80806364: jal         0x80809938
    // 0x80806368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809938_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080636C: jal         0x800F2100
    // 0x80806370: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80806370: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80806374: lwc1        $f6, 0x30($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80806378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080637C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80806380: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80806384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806388: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8080638C: jal         0x80809938
    // 0x80806390: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_80809938_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80806390: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80806394: jal         0x800F2100
    // 0x80806398: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80806398: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x8080639C: lwc1        $f18, 0x40($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X40);
    // 0x808063A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808063A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808063A8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808063AC: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x808063B0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x808063B4: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    // 0x808063B8: lwc1        $f14, 0x28($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X28);
    // 0x808063BC: jal         0x800F122C
    // 0x808063C0: lwc1        $f12, 0x148($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X148);
    func_800F122C(rdram, ctx);
        goto after_5;
    // 0x808063C0: lwc1        $f12, 0x148($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X148);
    after_5:
    // 0x808063C4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808063C8: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808063CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808063D0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808063D4: nop

    // 0x808063D8: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808063DC: jal         0x8009C984
    // 0x808063E0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    yaw_get(rdram, ctx);
        goto after_6;
    // 0x808063E0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x808063E4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808063E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808063EC: jal         0x8009B9B0
    // 0x808063F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x808063F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x808063F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808063F8: jal         0x8009B9C0
    // 0x808063FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_8;
    // 0x808063FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80806400: addiu       $v0, $s1, 0x12C
    ctx->r2 = ADD32(ctx->r17, 0X12C);
    // 0x80806404: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80806408: lwc1        $f6, 0x34($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X34);
    // 0x8080640C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80806410: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80806414: swc1        $f8, 0x1CC($s1)
    MEM_W(0X1CC, ctx->r17) = ctx->f8.u32l;
    // 0x80806418: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080641C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80806420: lwc1        $f6, 0x1CC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1CC);
    // 0x80806424: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80806428: nop

    // 0x8080642C: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80806430: swc1        $f4, 0x1CC($s1)
    MEM_W(0X1CC, ctx->r17) = ctx->f4.u32l;
    // 0x80806434: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80806438: beq         $t6, $zero, L_8080647C
    if (ctx->r14 == 0) {
        // 0x8080643C: nop
    
            goto L_8080647C;
    }
    // 0x8080643C: nop

    // 0x80806440: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80806444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80806448: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080644C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80806450: nop

    // 0x80806454: bc1fl       L_80806468
    if (!c1cs) {
        // 0x80806458: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80806468;
    }
    goto skip_0;
    // 0x80806458: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8080645C: b           L_8080646C
    // 0x80806460: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8080646C;
    // 0x80806460: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80806464: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80806468:
    // 0x80806468: nop

L_8080646C:
    // 0x8080646C: lwc1        $f10, 0x38($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80806470: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80806474: b           L_80806484
    // 0x80806478: swc1        $f18, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->f18.u32l;
        goto L_80806484;
    // 0x80806478: swc1        $f18, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->f18.u32l;
L_8080647C:
    // 0x8080647C: lwc1        $f6, 0x3C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x80806480: swc1        $f6, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->f6.u32l;
L_80806484:
    // 0x80806484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80806488: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080648C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80806490: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80806494: jr          $ra
    // 0x80806498: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80806498: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8008AF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AF04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008AF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008AF0C: jal         0x8008C1DC
    // 0x8008AF10: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C1DC(rdram, ctx);
        goto after_0;
    // 0x8008AF10: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008AF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AF18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AF1C: jr          $ra
    // 0x8008AF20: nop

    return;
    // 0x8008AF20: nop

;}
RECOMP_FUNC void bastick_getZonePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EF1C: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009EF20: jr          $ra
    // 0x8009EF24: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    return;
    // 0x8009EF24: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
;}
RECOMP_FUNC void _bsrest_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839E8: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839E8);
    return;
    // 0x800839EC: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_800FA708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA708: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800FA70C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA710: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800FA714: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800FA718: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FA71C: addiu       $t8, $t8, 0x3880
    ctx->r24 = ADD32(ctx->r24, 0X3880);
    // 0x800FA720: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800FA724: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800FA728: lb          $t0, 0xE($s0)
    ctx->r8 = MEM_B(ctx->r16, 0XE);
    // 0x800FA72C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FA734: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FA738: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800FA73C: bne         $a2, $t0, L_800FA750
    if (ctx->r6 != ctx->r8) {
        // 0x800FA740: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800FA750;
    }
    // 0x800FA740: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800FA744: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x800FA748: beql        $a3, $t2, L_800FA79C
    if (ctx->r7 == ctx->r10) {
        // 0x800FA74C: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_800FA79C;
    }
    goto skip_0;
    // 0x800FA74C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_0:
L_800FA750:
    // 0x800FA750: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x800FA754: beql        $a0, $zero, L_800FA778
    if (ctx->r4 == 0) {
        // 0x800FA758: lw          $a0, 0x18($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X18);
            goto L_800FA778;
    }
    goto skip_1;
    // 0x800FA758: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x800FA75C: jal         0x8008A638
    // 0x800FA760: nop

    _scinfobar_entrypoint_23(rdram, ctx);
        goto after_0;
    // 0x800FA760: nop

    after_0:
    // 0x800FA764: beql        $v0, $zero, L_800FA778
    if (ctx->r2 == 0) {
        // 0x800FA768: lw          $a0, 0x18($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X18);
            goto L_800FA778;
    }
    goto skip_2;
    // 0x800FA768: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    skip_2:
    // 0x800FA76C: b           L_800FA804
    // 0x800FA770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FA804;
    // 0x800FA770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FA774: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
L_800FA778:
    // 0x800FA778: beql        $a0, $zero, L_800FA79C
    if (ctx->r4 == 0) {
        // 0x800FA77C: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_800FA79C;
    }
    goto skip_3;
    // 0x800FA77C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x800FA780: jal         0x8008A5B8
    // 0x800FA784: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _scinfobar_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800FA784: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800FA788: bnel        $v0, $zero, L_800FA79C
    if (ctx->r2 != 0) {
        // 0x800FA78C: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_800FA79C;
    }
    goto skip_4;
    // 0x800FA78C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x800FA790: b           L_800FA804
    // 0x800FA794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FA804;
    // 0x800FA794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FA798: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800FA79C:
    // 0x800FA79C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800FA7A0: sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // 0x800FA7A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800FA7A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800FA7AC: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
    // 0x800FA7B0: jal         0x800FA240
    // 0x800FA7B4: sb          $t4, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r12;
    func_800FA240(rdram, ctx);
        goto after_2;
    // 0x800FA7B4: sb          $t4, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r12;
    after_2:
    // 0x800FA7B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FA7BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FA7C0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x800FA7C4: jal         0x8008A600
    // 0x800FA7C8: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    _scinfobar_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x800FA7C8: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x800FA7CC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800FA7D0: beql        $v0, $t5, L_800FA7F4
    if (ctx->r2 == ctx->r13) {
        // 0x800FA7D4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_800FA7F4;
    }
    goto skip_5;
    // 0x800FA7D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800FA7D8: jal         0x8008A630
    // 0x800FA7DC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    _scinfobar_entrypoint_22(rdram, ctx);
        goto after_4;
    // 0x800FA7DC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x800FA7E0: beq         $v0, $zero, L_800FA7F0
    if (ctx->r2 == 0) {
        // 0x800FA7E4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800FA7F0;
    }
    // 0x800FA7E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FA7E8: jal         0x8008A5B0
    // 0x800FA7EC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    _scinfobar_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x800FA7EC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_5:
L_800FA7F0:
    // 0x800FA7F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_800FA7F4:
    // 0x800FA7F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800FA7F8: jal         0x800FA6B8
    // 0x800FA7FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800FA6B8(rdram, ctx);
        goto after_6;
    // 0x800FA7FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x800FA800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FA804:
    // 0x800FA804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA808: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FA80C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FA810: jr          $ra
    // 0x800FA814: nop

    return;
    // 0x800FA814: nop

;}
RECOMP_FUNC void func_808012F8_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012F8: jr          $ra
    // 0x808012FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808012FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800E24D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E24D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E24DC: jr          $ra
    // 0x800E24E0: sb          $a0, -0x2B6F($at)
    MEM_B(-0X2B6F, ctx->r1) = ctx->r4;
    return;
    // 0x800E24E0: sb          $a0, -0x2B6F($at)
    MEM_B(-0X2B6F, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void idtwinklea_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: jr          $ra
    // 0x8080001C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080001C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _sumole_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A30: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A30);
    return;
    // 0x80089A34: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void chfantasyeyeball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2400, 0X2008) << 16);
    // 0x80801CB8: jr          $ra
    // 0x80801CBC: addiu       $v0, $v0, 0x2008
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2400, 0X2008));
    return;
    // 0x80801CBC: addiu       $v0, $v0, 0x2008
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2400, 0X2008));
;}
RECOMP_FUNC void func_80800000_cheggice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800004: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8080000C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800010: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80800018: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8080001C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800020: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800024: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: jal         0x800D8FF8
    // 0x80800034: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x80800038: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8080003C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2120, 0X3D0) << 16);
    // 0x80800040: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800044: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800048: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080004C: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x80800050: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x80800054: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x80800058: lwc1        $f8, 0x3D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2120, 0X3D0));
    // 0x8080005C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800060: jal         0x800F10B4
    // 0x80800064: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800064: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800068: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8080006C: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800070: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800074: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x80800078: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x8080007C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800080: bc1fl       L_808000F0
    if (!c1cs) {
        // 0x80800084: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808000F0;
    }
    goto skip_0;
    // 0x80800084: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80800088: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080008C: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x80800090: add.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f22.fl;
L_80800094:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080009C: jal         0x800EE7F8
    // 0x808000A0: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808000A0: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    after_3:
    // 0x808000A4: jal         0x800DC0C0
    // 0x808000A8: nop

    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x808000A8: nop

    after_4:
    // 0x808000AC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: bc1f        L_808000D0
    if (!c1cs) {
        // 0x808000B8: nop
    
            goto L_808000D0;
    }
    // 0x808000B8: nop

    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x80088A70
    // 0x808000C4: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    _fxegg_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808000C4: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    after_5:
    // 0x808000C8: b           L_808000DC
    // 0x808000CC: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
        goto L_808000DC;
    // 0x808000CC: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
L_808000D0:
    // 0x808000D0: jal         0x80088A68
    // 0x808000D4: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    _fxegg_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808000D4: lw          $a1, 0x38($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X38);
    after_6:
    // 0x808000D8: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
L_808000DC:
    // 0x808000DC: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x808000E0: nop

    // 0x808000E4: bc1tl       L_80800094
    if (c1cs) {
        // 0x808000E8: add.s       $f10, $f2, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f22.fl;
            goto L_80800094;
    }
    goto skip_1;
    // 0x808000E8: add.s       $f10, $f2, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f22.fl;
    skip_1:
    // 0x808000EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808000F0:
    // 0x808000F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808000F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808000F8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808000FC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80800100: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80800104: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80800108: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8080010C: jr          $ra
    // 0x80800110: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800110: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800804_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800804: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800808: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080080C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800810: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800814: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80800818: addiu       $t6, $zero, 0x184E
    ctx->r14 = ADD32(0, 0X184E);
    // 0x8080081C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800820: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800824: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800828: addiu       $a3, $a3, 0x7DB0
    ctx->r7 = ADD32(ctx->r7, 0X7DB0);
    // 0x8080082C: addiu       $a2, $a2, 0x7D18
    ctx->r6 = ADD32(ctx->r6, 0X7D18);
    // 0x80800830: jal         0x80087CB8
    // 0x80800834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800838: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080083C: jal         0x80100094
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800844: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800848: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080084C: jal         0x80087CD8
    // 0x80800850: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800850: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800858: jal         0x80087CE0
    // 0x8080085C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x8080085C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: jal         0x80087CE8
    // 0x80800868: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800868: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080086C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800870: jal         0x808004E8
    // 0x80800874: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808004E8_chdumbwaiterlift(rdram, ctx);
        goto after_5;
    // 0x80800874: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800878: jal         0x80087CF0
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800880: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800884: jal         0x80101FDC
    // 0x80800888: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800888: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x8080088C: jal         0x80800A8C
    // 0x80800890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800A8C_chdumbwaiterlift(rdram, ctx);
        goto after_8;
    // 0x80800890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800894: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800898: jal         0x8010A828
    // 0x8080089C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8010A828(rdram, ctx);
        goto after_9;
    // 0x8080089C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_9:
    // 0x808008A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008A4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808008A8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808008AC: jr          $ra
    // 0x808008B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808008B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _glidmake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088880: syscall     707
    recomp_syscall_handler(rdram, ctx, 0x80088880);
    return;
    // 0x80088884: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800B2464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B246C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B2470: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B2474: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800B2478: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B247C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B2480: bnel        $v0, $t6, L_800B24A4
    if (ctx->r2 != ctx->r14) {
        // 0x800B2484: lhu         $t9, 0x16($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X16);
            goto L_800B24A4;
    }
    goto skip_0;
    // 0x800B2484: lhu         $t9, 0x16($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X16);
    skip_0:
    // 0x800B2488: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800B248C: bnel        $v0, $t7, L_800B24A4
    if (ctx->r2 != ctx->r15) {
        // 0x800B2490: lhu         $t9, 0x16($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X16);
            goto L_800B24A4;
    }
    goto skip_1;
    // 0x800B2490: lhu         $t9, 0x16($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X16);
    skip_1:
    // 0x800B2494: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800B2498: beql        $v0, $t8, L_800B2530
    if (ctx->r2 == ctx->r24) {
        // 0x800B249C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B2530;
    }
    goto skip_2;
    // 0x800B249C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800B24A0: lhu         $t9, 0x16($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X16);
L_800B24A4:
    // 0x800B24A4: addiu       $s1, $a0, 0x18
    ctx->r17 = ADD32(ctx->r4, 0X18);
    // 0x800B24A8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800B24AC: srl         $t2, $t9, 1
    ctx->r10 = S32(U32(ctx->r25) >> 1);
    // 0x800B24B0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800B24B4: addu        $t1, $t3, $a0
    ctx->r9 = ADD32(ctx->r11, ctx->r4);
    // 0x800B24B8: addiu       $t1, $t1, 0x18
    ctx->r9 = ADD32(ctx->r9, 0X18);
    // 0x800B24BC: sltu        $at, $s1, $t1
    ctx->r1 = ctx->r17 < ctx->r9 ? 1 : 0;
    // 0x800B24C0: beq         $at, $zero, L_800B2518
    if (ctx->r1 == 0) {
        // 0x800B24C4: addiu       $t0, $a2, 0x18
        ctx->r8 = ADD32(ctx->r6, 0X18);
            goto L_800B2518;
    }
    // 0x800B24C4: addiu       $t0, $a2, 0x18
    ctx->r8 = ADD32(ctx->r6, 0X18);
    // 0x800B24C8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_800B24CC:
    // 0x800B24CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B24D0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x800B24D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B24D8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800B24DC:
    // 0x800B24DC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800B24E0: lbu         $t5, 0xC($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XC);
    // 0x800B24E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B24E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B24EC: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B24F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B24F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B24F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800B24FC: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800B2500: bne         $v0, $a2, L_800B24DC
    if (ctx->r2 != ctx->r6) {
        // 0x800B2504: sb          $t7, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r15;
            goto L_800B24DC;
    }
    // 0x800B2504: sb          $t7, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r15;
    // 0x800B2508: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800B250C: sltu        $at, $a3, $t1
    ctx->r1 = ctx->r7 < ctx->r9 ? 1 : 0;
    // 0x800B2510: bne         $at, $zero, L_800B24CC
    if (ctx->r1 != 0) {
        // 0x800B2514: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800B24CC;
    }
    // 0x800B2514: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_800B2518:
    // 0x800B2518: subu        $a1, $t1, $s1
    ctx->r5 = SUB32(ctx->r9, ctx->r17);
    // 0x800B251C: sra         $t8, $a1, 4
    ctx->r24 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800B2520: sll         $a1, $t8, 4
    ctx->r5 = S32(ctx->r24 << 4);
    // 0x800B2524: jal         0x8002E660
    // 0x800B2528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x800B2528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800B252C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B2530:
    // 0x800B2530: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B2534: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B2538: jr          $ra
    // 0x800B253C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B253C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808002B0_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B8: jal         0x80082830
    // 0x808002BC: nop

    _bsbee_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808002BC: nop

    after_0:
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void _cadbmgrDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085560: syscall     167
    recomp_syscall_handler(rdram, ctx, 0x80085560);
    return;
    // 0x80085564: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chjadestatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087358: syscall     553
    recomp_syscall_handler(rdram, ctx, 0x80087358);
    return;
    // 0x8008735C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A9010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9010: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A9014: lbu         $t6, 0x76D4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X76D4);
    // 0x800A9018: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A901C: bne         $t6, $zero, L_800A902C
    if (ctx->r14 != 0) {
        // 0x800A9020: nop
    
            goto L_800A902C;
    }
    // 0x800A9020: nop

    // 0x800A9024: jr          $ra
    // 0x800A9028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800A9028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A902C:
    // 0x800A902C: lbu         $t7, 0x76D5($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X76D5);
    // 0x800A9030: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A9034: bne         $t7, $zero, L_800A9044
    if (ctx->r15 != 0) {
        // 0x800A9038: nop
    
            goto L_800A9044;
    }
    // 0x800A9038: nop

    // 0x800A903C: jr          $ra
    // 0x800A9040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800A9040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A9044:
    // 0x800A9044: lbu         $t8, 0x76D6($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X76D6);
    // 0x800A9048: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A904C: bne         $t8, $zero, L_800A905C
    if (ctx->r24 != 0) {
        // 0x800A9050: nop
    
            goto L_800A905C;
    }
    // 0x800A9050: nop

    // 0x800A9054: jr          $ra
    // 0x800A9058: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800A9058: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800A905C:
    // 0x800A905C: lbu         $t9, 0x76D7($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X76D7);
    // 0x800A9060: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A9064: bne         $t9, $zero, L_800A9074
    if (ctx->r25 != 0) {
        // 0x800A9068: nop
    
            goto L_800A9074;
    }
    // 0x800A9068: nop

    // 0x800A906C: jr          $ra
    // 0x800A9070: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800A9070: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800A9074:
    // 0x800A9074: jr          $ra
    // 0x800A9078: nop

    return;
    // 0x800A9078: nop

;}
RECOMP_FUNC void vplight_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080059C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x808005A0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x808005A4: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x808005A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808005AC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x808005B0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x808005B4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x808005B8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808005BC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808005C0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808005C4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808005C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005CC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808005D0: addu        $s6, $a0, $t6
    ctx->r22 = ADD32(ctx->r4, ctx->r14);
    // 0x808005D4: lbu         $t7, 0x1($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X1);
    // 0x808005D8: sll         $t8, $a3, 4
    ctx->r24 = S32(ctx->r7 << 4);
    // 0x808005DC: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x808005E0: beq         $t7, $zero, L_808007C0
    if (ctx->r15 == 0) {
        // 0x808005E4: addu        $fp, $t8, $a2
        ctx->r30 = ADD32(ctx->r24, ctx->r6);
            goto L_808007C0;
    }
    // 0x808005E4: addu        $fp, $t8, $a2
    ctx->r30 = ADD32(ctx->r24, ctx->r6);
    // 0x808005E8: or          $s4, $fp, $zero
    ctx->r20 = ctx->r30 | 0;
    // 0x808005EC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808005F0: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x808005F4: addu        $t9, $s6, $s5
    ctx->r25 = ADD32(ctx->r22, ctx->r21);
L_808005F8:
    // 0x808005F8: lbu         $t0, 0x2($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2);
    // 0x808005FC: bnel        $t0, $zero, L_80800614
    if (ctx->r8 != 0) {
        // 0x80800600: slti        $at, $s5, 0xE
        ctx->r1 = SIGNED(ctx->r21) < 0XE ? 1 : 0;
            goto L_80800614;
    }
    goto skip_0;
    // 0x80800600: slti        $at, $s5, 0xE
    ctx->r1 = SIGNED(ctx->r21) < 0XE ? 1 : 0;
    skip_0:
    // 0x80800604: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80800608: bnel        $s5, $v0, L_808005F8
    if (ctx->r21 != ctx->r2) {
        // 0x8080060C: addu        $t9, $s6, $s5
        ctx->r25 = ADD32(ctx->r22, ctx->r21);
            goto L_808005F8;
    }
    goto skip_1;
    // 0x8080060C: addu        $t9, $s6, $s5
    ctx->r25 = ADD32(ctx->r22, ctx->r21);
    skip_1:
    // 0x80800610: slti        $at, $s5, 0xE
    ctx->r1 = SIGNED(ctx->r21) < 0XE ? 1 : 0;
L_80800614:
    // 0x80800614: beq         $at, $zero, L_808007C0
    if (ctx->r1 == 0) {
        // 0x80800618: lui         $s3, 0x1
        ctx->r19 = S32(0X1 << 16);
            goto L_808007C0;
    }
    // 0x80800618: lui         $s3, 0x1
    ctx->r19 = S32(0X1 << 16);
    // 0x8080061C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80800620: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800624: addiu       $s2, $zero, 0x4000
    ctx->r18 = ADD32(0, 0X4000);
    // 0x80800628: addu        $s1, $s6, $s5
    ctx->r17 = ADD32(ctx->r22, ctx->r21);
L_8080062C:
    // 0x8080062C: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80800630: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80800634: beq         $v0, $zero, L_808007B0
    if (ctx->r2 == 0) {
        // 0x80800638: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808007B0;
    }
    // 0x80800638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080063C: jal         0x808004B0
    // 0x80800640: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
    func_808004B0_vplight(rdram, ctx);
        goto after_0;
    // 0x80800640: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
    after_0:
    // 0x80800644: lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X2);
    // 0x80800648: jal         0x80800518
    // 0x8080064C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_80800518_vplight(rdram, ctx);
        goto after_1;
    // 0x8080064C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_1:
    // 0x80800650: lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X2);
    // 0x80800654: jal         0x800C8900
    // 0x80800658: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800C8900(rdram, ctx);
        goto after_2;
    // 0x80800658: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_2:
    // 0x8080065C: sltu        $at, $s7, $fp
    ctx->r1 = ctx->r23 < ctx->r30 ? 1 : 0;
    // 0x80800660: beql        $at, $zero, L_808007B4
    if (ctx->r1 == 0) {
        // 0x80800664: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_808007B4;
    }
    goto skip_2;
    // 0x80800664: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_2:
    // 0x80800668: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
L_8080066C:
    // 0x8080066C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80800670: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80800674: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80800678: subu        $v0, $t1, $t2
    ctx->r2 = SUB32(ctx->r9, ctx->r10);
    // 0x8080067C: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800680: subu        $v1, $t3, $t4
    ctx->r3 = SUB32(ctx->r11, ctx->r12);
    // 0x80800684: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x80800688: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8080068C: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x80800690: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x80800694: mflo        $t7
    ctx->r15 = lo;
    // 0x80800698: nop

    // 0x8080069C: nop

    // 0x808006A0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808006A4: mflo        $t8
    ctx->r24 = lo;
    // 0x808006A8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x808006AC: nop

    // 0x808006B0: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808006B4: mflo        $t0
    ctx->r8 = lo;
    // 0x808006B8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x808006BC: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808006C0: beq         $at, $zero, L_808007A0
    if (ctx->r1 == 0) {
        // 0x808006C4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_808007A0;
    }
    // 0x808006C4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808006C8: beql        $a1, $zero, L_808006F0
    if (ctx->r5 == 0) {
        // 0x808006CC: lw          $t3, 0x8C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X8C);
            goto L_808006F0;
    }
    goto skip_3;
    // 0x808006CC: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    skip_3:
    // 0x808006D0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x808006D4: jal         0x8002DCA0
    // 0x808006D8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x808006D8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_3:
    // 0x808006DC: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808006E0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808006E4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808006E8: nop

    // 0x808006EC: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
L_808006F0:
    // 0x808006F0: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x808006F4: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x808006F8: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808006FC: beq         $at, $zero, L_80800720
    if (ctx->r1 == 0) {
        // 0x80800700: lw          $t8, 0x80($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X80);
            goto L_80800720;
    }
    // 0x80800700: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80800704: subu        $t5, $a2, $t3
    ctx->r13 = SUB32(ctx->r6, ctx->r11);
    // 0x80800708: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080070C: mflo        $t6
    ctx->r14 = lo;
    // 0x80800710: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80800714: subu        $v0, $s2, $t7
    ctx->r2 = SUB32(ctx->r18, ctx->r15);
    // 0x80800718: b           L_80800720
    // 0x8080071C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_80800720;
    // 0x8080071C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_80800720:
    // 0x80800720: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800724: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x80800728: mflo        $t9
    ctx->r25 = lo;
    // 0x8080072C: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800730: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80800734: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800738: bnel        $at, $zero, L_80800748
    if (ctx->r1 != 0) {
        // 0x8080073C: sb          $v0, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r2;
            goto L_80800748;
    }
    goto skip_4;
    // 0x8080073C: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    skip_4:
    // 0x80800740: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80800744: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
L_80800748:
    // 0x80800748: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8080074C: lbu         $t5, 0xD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XD);
    // 0x80800750: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800754: mflo        $t3
    ctx->r11 = lo;
    // 0x80800758: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8080075C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80800760: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800764: bnel        $at, $zero, L_80800774
    if (ctx->r1 != 0) {
        // 0x80800768: sb          $v0, 0xD($s0)
        MEM_B(0XD, ctx->r16) = ctx->r2;
            goto L_80800774;
    }
    goto skip_5;
    // 0x80800768: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    skip_5:
    // 0x8080076C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80800770: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
L_80800774:
    // 0x80800774: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80800778: lbu         $t9, 0xE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XE);
    // 0x8080077C: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800780: mflo        $t7
    ctx->r15 = lo;
    // 0x80800784: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800788: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8080078C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800790: bnel        $at, $zero, L_808007A0
    if (ctx->r1 != 0) {
        // 0x80800794: sb          $v0, 0xE($s0)
        MEM_B(0XE, ctx->r16) = ctx->r2;
            goto L_808007A0;
    }
    goto skip_6;
    // 0x80800794: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    skip_6:
    // 0x80800798: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8080079C: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
L_808007A0:
    // 0x808007A0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808007A4: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x808007A8: bnel        $at, $zero, L_8080066C
    if (ctx->r1 != 0) {
        // 0x808007AC: lw          $t1, 0x98($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X98);
            goto L_8080066C;
    }
    goto skip_7;
    // 0x808007AC: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    skip_7:
L_808007B0:
    // 0x808007B0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_808007B4:
    // 0x808007B4: slti        $at, $s5, 0xE
    ctx->r1 = SIGNED(ctx->r21) < 0XE ? 1 : 0;
    // 0x808007B8: bnel        $at, $zero, L_8080062C
    if (ctx->r1 != 0) {
        // 0x808007BC: addu        $s1, $s6, $s5
        ctx->r17 = ADD32(ctx->r22, ctx->r21);
            goto L_8080062C;
    }
    goto skip_8;
    // 0x808007BC: addu        $s1, $s6, $s5
    ctx->r17 = ADD32(ctx->r22, ctx->r21);
    skip_8:
L_808007C0:
    // 0x808007C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x808007C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808007C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808007D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808007D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808007D8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808007DC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808007E0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808007E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x808007E8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x808007EC: jr          $ra
    // 0x808007F0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x808007F0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_800B7CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7CAC: jal         0x800B9038
    // 0x800B7CB0: nop

    func_800B9038(rdram, ctx);
        goto after_0;
    // 0x800B7CB0: nop

    after_0:
    // 0x800B7CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7CBC: jr          $ra
    // 0x800B7CC0: nop

    return;
    // 0x800B7CC0: nop

;}
RECOMP_FUNC void subaddieitem_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808000A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808000AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808000B0: jal         0x800D8FF8
    // 0x808000B4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x808000B8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808000BC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x808000C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000C4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808000C8: beq         $v0, $at, L_808000F0
    if (ctx->r2 == ctx->r1) {
        // 0x808000CC: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_808000F0;
    }
    // 0x808000CC: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x808000D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D4: beq         $v0, $at, L_80800180
    if (ctx->r2 == ctx->r1) {
        // 0x808000D8: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80800180;
    }
    // 0x808000D8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x808000DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E0: beql        $v0, $at, L_808001E8
    if (ctx->r2 == ctx->r1) {
        // 0x808000E4: lbu         $t5, 0x3($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X3);
            goto L_808001E8;
    }
    goto skip_0;
    // 0x808000E4: lbu         $t5, 0x3($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X3);
    skip_0:
    // 0x808000E8: b           L_80800214
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800214;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x808000F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808000F8: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    // 0x808000FC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80800100: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80800104: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800108: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080010C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800110: jal         0x800902E4
    // 0x80800114: nop

    func_800902E4(rdram, ctx);
        goto after_1;
    // 0x80800114: nop

    after_1:
    // 0x80800118: beql        $v0, $zero, L_80800214
    if (ctx->r2 == 0) {
        // 0x8080011C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800214;
    }
    goto skip_1;
    // 0x8080011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800120: jal         0x8008FE14
    // 0x80800124: nop

    func_8008FE14(rdram, ctx);
        goto after_2;
    // 0x80800124: nop

    after_2:
    // 0x80800128: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8080012C: bnel        $v0, $t7, L_80800214
    if (ctx->r2 != ctx->r15) {
        // 0x80800130: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800214;
    }
    goto skip_2;
    // 0x80800130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800134: jal         0x80090818
    // 0x80800138: nop

    func_80090818(rdram, ctx);
        goto after_3;
    // 0x80800138: nop

    after_3:
    // 0x8080013C: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x80800140: lw          $t8, 0x44($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X44);
            goto L_80800210;
    }
    // 0x80800140: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800144: bne         $t8, $zero, L_80800158
    if (ctx->r24 != 0) {
        // 0x80800148: addiu       $a1, $sp, 0x30
        ctx->r5 = ADD32(ctx->r29, 0X30);
            goto L_80800158;
    }
    // 0x80800148: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080014C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800150: jal         0x80103DFC
    // 0x80800154: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80103DFC(rdram, ctx);
        goto after_4;
    // 0x80800154: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
L_80800158:
    // 0x80800158: jal         0x8008FDEC
    // 0x8080015C: nop

    func_8008FDEC(rdram, ctx);
        goto after_5;
    // 0x8080015C: nop

    after_5:
    // 0x80800160: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800164: jal         0x8008A028
    // 0x80800168: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800168: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8080016C: jal         0x80090768
    // 0x80800170: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80090768(rdram, ctx);
        goto after_7;
    // 0x80800170: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x80800174: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800178: b           L_80800210
    // 0x8080017C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
        goto L_80800210;
    // 0x8080017C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_80800180:
    // 0x80800180: jal         0x8008A030
    // 0x80800184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddielink_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_8:
    // 0x80800188: bne         $v0, $zero, L_808001A8
    if (ctx->r2 != 0) {
        // 0x8080018C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001A8;
    }
    // 0x8080018C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800190: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800198: jal         0x80800224
    // 0x8080019C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800224_subaddieitem(rdram, ctx);
        goto after_9;
    // 0x8080019C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808001A0: b           L_80800214
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800214;
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001A8:
    // 0x808001A8: jal         0x8008A040
    // 0x808001AC: nop

    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808001AC: nop

    after_10:
    // 0x808001B0: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x808001B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808001B8: sll         $t2, $t0, 9
    ctx->r10 = S32(ctx->r8 << 9);
    // 0x808001BC: bltzl       $t2, L_80800214
    if (SIGNED(ctx->r10) < 0) {
        // 0x808001C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800214;
    }
    goto skip_3;
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808001C4: lb          $t4, 0x65($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X65);
    // 0x808001C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001CC: bltzl       $t4, L_80800214
    if (SIGNED(ctx->r12) < 0) {
        // 0x808001D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800214;
    }
    goto skip_4;
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808001D4: jal         0x80800224
    // 0x808001D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800224_subaddieitem(rdram, ctx);
        goto after_11;
    // 0x808001D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x808001DC: b           L_80800214
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800214;
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E4: lbu         $t5, 0x3($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X3);
L_808001E8:
    // 0x808001E8: beq         $t5, $zero, L_808001FC
    if (ctx->r13 == 0) {
        // 0x808001EC: nop
    
            goto L_808001FC;
    }
    // 0x808001EC: nop

    // 0x808001F0: jal         0x80090658
    // 0x808001F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_12;
    // 0x808001F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x808001F8: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
L_808001FC:
    // 0x808001FC: jal         0x8008A020
    // 0x80800200: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80800200: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_13:
    // 0x80800204: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80800208: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080020C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80800210:
    // 0x80800210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800214:
    // 0x80800214: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80800218: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080021C: jr          $ra
    // 0x80800220: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800220: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chlavaentrydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2000, 0X1A4) << 16);
    // 0x8080013C: jr          $ra
    // 0x80800140: addiu       $v0, $v0, 0x1A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2000, 0X1A4));
    return;
    // 0x80800140: addiu       $v0, $v0, 0x1A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2000, 0X1A4));
;}
RECOMP_FUNC void gcboundDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80800004: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80800008: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8080000C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80800010: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80800014: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080001C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800020: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800028:
    // 0x80800028: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080002C: sb          $a1, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r5;
    // 0x80800030: sb          $a1, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r5;
    // 0x80800034: sb          $a1, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r5;
    // 0x80800038: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080003C: bne         $v0, $a2, L_80800028
    if (ctx->r2 != ctx->r6) {
        // 0x80800040: sb          $a1, 0x14($v1)
        MEM_B(0X14, ctx->r3) = ctx->r5;
            goto L_80800028;
    }
    // 0x80800040: sb          $a1, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r5;
    // 0x80800044: jr          $ra
    // 0x80800048: sw          $zero, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = 0;
    return;
    // 0x80800048: sw          $zero, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80800E04_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E14: jal         0x80106790
    // 0x80800E18: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800E18: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80800E1C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800E20: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800E24: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800E28: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x80800E2C: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    // 0x80800E30: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800E34: jal         0x8008A0E0
    // 0x80800E38: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800E38: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800E3C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1776, 0X17C4) << 16);
    // 0x80800E40: addiu       $a2, $a2, 0x17C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X17C4));
    // 0x80800E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E48: jal         0x80089D18
    // 0x80800E4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800E4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800E50: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E54: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80800E58: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x80800E5C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80800E60: lwc1        $f6, 0x4C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x80800E64: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80800E68: lwc1        $f8, 0x44($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80800E6C: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x80800E70: jal         0x800F1DF4
    // 0x80800E74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x80800E74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800E78: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E7C: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x80800E80: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800E84: jal         0x800EFCD8
    // 0x80800E88: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EFCD8(rdram, ctx);
        goto after_4;
    // 0x80800E88: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_4:
    // 0x80800E8C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800E90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800E94: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800E98: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x80800E9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800EA0: andi        $t7, $a1, 0x1FF
    ctx->r15 = ctx->r5 & 0X1FF;
    // 0x80800EA4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800EA8: addiu       $a1, $t7, 0x73A
    ctx->r5 = ADD32(ctx->r15, 0X73A);
    // 0x80800EAC: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x80800EB0: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80800EB4: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x80800EB8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC0: jal         0x80103140
    // 0x80800EC4: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_80103140(rdram, ctx);
        goto after_5;
    // 0x80800EC4: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_5:
    // 0x80800EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800ED0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800ED4: jr          $ra
    // 0x80800ED8: nop

    return;
    // 0x80800ED8: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088138: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088138);
    return;
    // 0x8008813C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F4D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4D74: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F4D78: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F4D7C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F4D80: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800F4D84: lw          $t8, 0x5490($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5490);
    // 0x800F4D88: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800F4D8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F4D90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F4D94: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800F4D98: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800F4D9C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800F4DA0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F4DA4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F4DA8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800F4DAC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F4DB0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F4DB4: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800F4DB8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F4DBC: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800F4DC0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800F4DC4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F4DC8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800F4DCC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800F4DD0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800F4DD4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800F4DD8: jal         0x800EFA4C
    // 0x800F4DDC: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800F4DDC: nop

    after_0:
    // 0x800F4DE0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F4DE4: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F4DE8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F4DEC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800F4DF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F4DF4: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800F4DF8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F4DFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F4E00: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800F4E04: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F4E08: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F4E0C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800F4E10: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800F4E14: jal         0x800EFA4C
    // 0x800F4E18: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800F4E18: nop

    after_1:
    // 0x800F4E1C: jal         0x800A3048
    // 0x800F4E20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800A3048(rdram, ctx);
        goto after_2;
    // 0x800F4E20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800F4E24: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800F4E28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F4E2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800F4E30: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800F4E34: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F4E38: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800F4E3C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800F4E40: jal         0x8009F678
    // 0x800F4E44: nop

    func_8009F678(rdram, ctx);
        goto after_3;
    // 0x800F4E44: nop

    after_3:
    // 0x800F4E48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4E4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F4E50: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800F4E54: jr          $ra
    // 0x800F4E58: nop

    return;
    // 0x800F4E58: nop

;}
RECOMP_FUNC void func_8080003C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800048: jal         0x80100094
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800050: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800054: addiu       $a0, $zero, 0xA34
    ctx->r4 = ADD32(0, 0XA34);
    // 0x80800058: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080005C: jal         0x800DA7A8
    // 0x80800060: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80800064: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800068: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080006C: sb          $t6, 0x26($t7)
    MEM_B(0X26, ctx->r15) = ctx->r14;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void _fxtwinkle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AB8: syscall     720
    recomp_syscall_handler(rdram, ctx, 0x80088AB8);
    return;
    // 0x80088ABC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8008E530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E530: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008E534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008E53C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008E540: lhu         $t7, 0x18($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X18);
    // 0x8008E544: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8008E548: beql        $t8, $zero, L_8008E590
    if (ctx->r24 == 0) {
        // 0x8008E54C: lw          $t5, 0x20($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X20);
            goto L_8008E590;
    }
    goto skip_0;
    // 0x8008E54C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8008E550: jal         0x80106790
    // 0x8008E554: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8008E554: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8008E558: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x8008E55C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008E560: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x8008E564: bltzl       $t1, L_8008E60C
    if (SIGNED(ctx->r9) < 0) {
        // 0x8008E568: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008E60C;
    }
    goto skip_1;
    // 0x8008E568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8008E56C: lw          $t2, 0x78($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X78);
    // 0x8008E570: sll         $t4, $t2, 28
    ctx->r12 = S32(ctx->r10 << 28);
    // 0x8008E574: bgezl       $t4, L_8008E590
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8008E578: lw          $t5, 0x20($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X20);
            goto L_8008E590;
    }
    goto skip_2;
    // 0x8008E578: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x8008E57C: jal         0x80085918
    // 0x8008E580: nop

    _chbounce_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8008E580: nop

    after_1:
    // 0x8008E584: bnel        $v0, $zero, L_8008E60C
    if (ctx->r2 != 0) {
        // 0x8008E588: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008E60C;
    }
    goto skip_3;
    // 0x8008E588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8008E58C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
L_8008E590:
    // 0x8008E590: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008E594: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x8008E598: jal         0x80088628
    // 0x8008E59C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _glhittableDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8008E59C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x8008E5A0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8008E5A4: jal         0x800F424C
    // 0x8008E5A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F424C(rdram, ctx);
        goto after_3;
    // 0x8008E5A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8008E5AC: bnel        $v0, $zero, L_8008E5D8
    if (ctx->r2 != 0) {
        // 0x8008E5B0: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_8008E5D8;
    }
    goto skip_4;
    // 0x8008E5B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_4:
    // 0x8008E5B4: jal         0x80088618
    // 0x8008E5B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _glhittableDll_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8008E5B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8008E5BC: beql        $v0, $zero, L_8008E5D8
    if (ctx->r2 == 0) {
        // 0x8008E5C0: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_8008E5D8;
    }
    goto skip_5;
    // 0x8008E5C0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_5:
    // 0x8008E5C4: jal         0x80088648
    // 0x8008E5C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _glhittableDll_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x8008E5C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8008E5CC: bnel        $v0, $zero, L_8008E60C
    if (ctx->r2 != 0) {
        // 0x8008E5D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008E60C;
    }
    goto skip_6;
    // 0x8008E5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8008E5D4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_8008E5D8:
    // 0x8008E5D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008E5DC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8008E5E0: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x8008E5E4: jal         0x80088620
    // 0x8008E5E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _glhittableDll_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x8008E5E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_6:
    // 0x8008E5EC: bne         $v0, $zero, L_8008E608
    if (ctx->r2 != 0) {
        // 0x8008E5F0: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_8008E608;
    }
    // 0x8008E5F0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008E5F4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8008E5F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8008E5FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008E600: jal         0x800EB210
    // 0x8008E604: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    func_800EB210(rdram, ctx);
        goto after_7;
    // 0x8008E604: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_7:
L_8008E608:
    // 0x8008E608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E60C:
    // 0x8008E60C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008E610: jr          $ra
    // 0x8008E614: nop

    return;
    // 0x8008E614: nop

;}
RECOMP_FUNC void func_80095534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80095538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009553C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80095540: jal         0x8009C128
    // 0x80095544: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80095544: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80095548: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009554C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80095550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095554: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80095558: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8009555C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80095560: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095564: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80095568: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8009556C: nop

    // 0x80095570: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80095574: jr          $ra
    // 0x80095578: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    return;
    // 0x80095578: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
;}
RECOMP_FUNC void func_800A4CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4CB0: jal         0x800A4C88
    // 0x800A4CB4: nop

    func_800A4C88(rdram, ctx);
        goto after_0;
    // 0x800A4CB4: nop

    after_0:
    // 0x800A4CB8: beq         $v0, $zero, L_800A4CD0
    if (ctx->r2 == 0) {
        // 0x800A4CBC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A4CD0;
    }
    // 0x800A4CBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A4CC0: jal         0x80110014
    // 0x800A4CC4: nop

    func_80110014(rdram, ctx);
        goto after_1;
    // 0x800A4CC4: nop

    after_1:
    // 0x800A4CC8: b           L_800A4CD4
    // 0x800A4CCC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800A4CD4;
    // 0x800A4CCC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800A4CD0:
    // 0x800A4CD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A4CD4:
    // 0x800A4CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4CD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4CDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A4CE0: jr          $ra
    // 0x800A4CE4: nop

    return;
    // 0x800A4CE4: nop

;}
RECOMP_FUNC void subaddiejoy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000B8: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x808000BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808000C0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x808000C4: jal         0x80016A74
    // 0x808000C8: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    func_80016A74(rdram, ctx);
        goto after_0;
    // 0x808000C8: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    after_0:
    // 0x808000CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000D0: bne         $v0, $at, L_808000E0
    if (ctx->r2 != ctx->r1) {
        // 0x808000D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808000E0;
    }
    // 0x808000D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000D8: b           L_80800100
    // 0x808000DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80800100;
    // 0x808000DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_808000E0:
    // 0x808000E0: jal         0x800E3A80
    // 0x808000E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800E3A80(rdram, ctx);
        goto after_1;
    // 0x808000E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x808000E8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808000EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x808000F4: nop

    // 0x808000F8: addu        $v1, $t9, $v1
    ctx->r3 = ADD32(ctx->r25, ctx->r3);
    // 0x808000FC: addiu       $v1, $v1, 0x5A
    ctx->r3 = ADD32(ctx->r3, 0X5A);
L_80800100:
    // 0x80800100: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80800104: jal         0x800136E4
    // 0x80800108: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800108: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_2:
    // 0x8080010C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800118: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_800E39A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E39A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E39AC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800E39B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E39B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E39B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E39BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E39C0: jal         0x800CA8B4
    // 0x800E39C4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA8B4(rdram, ctx);
        goto after_0;
    // 0x800E39C4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E39C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E39CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E39D0: jr          $ra
    // 0x800E39D4: nop

    return;
    // 0x800E39D4: nop

;}
RECOMP_FUNC void func_80801208_subaddiedialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801208: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080120C: andi        $t7, $a3, 0x20
    ctx->r15 = ctx->r7 & 0X20;
    // 0x80801210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801214: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801218: beq         $t7, $zero, L_80801228
    if (ctx->r15 == 0) {
        // 0x8080121C: sw          $a2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r6;
            goto L_80801228;
    }
    // 0x8080121C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80801220: ori         $t8, $a2, 0x1
    ctx->r24 = ctx->r6 | 0X1;
    // 0x80801224: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80801228:
    // 0x80801228: jal         0x80800000
    // 0x8080122C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x8080122C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80801230: bne         $v0, $zero, L_80801240
    if (ctx->r2 != 0) {
        // 0x80801234: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801240;
    }
    // 0x80801234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801238: b           L_80801274
    // 0x8080123C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801274;
    // 0x8080123C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801240:
    // 0x80801240: jal         0x80016B30
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_1;
    // 0x80801244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801248: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080124C: beq         $v0, $at, L_8080125C
    if (ctx->r2 == ctx->r1) {
        // 0x80801250: nop
    
            goto L_8080125C;
    }
    // 0x80801250: nop

    // 0x80801254: b           L_80801274
    // 0x80801258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801274;
    // 0x80801258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080125C:
    // 0x8080125C: jal         0x800F54E4
    // 0x80801260: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801260: nop

    after_2:
    // 0x80801264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801268: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080126C: jal         0x800F4BB8
    // 0x80801270: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800F4BB8(rdram, ctx);
        goto after_3;
    // 0x80801270: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80801274:
    // 0x80801274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801278: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080127C: jr          $ra
    // 0x80801280: nop

    return;
    // 0x80801280: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005CC: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x808005D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005D4: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x808005D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005E0: beq         $at, $zero, L_80800634
    if (ctx->r1 == 0) {
        // 0x808005E4: swc1        $f4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
            goto L_80800634;
    }
    // 0x808005E4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x808005E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808005EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(504, 0X818) << 16);
    // 0x808005F0: addu        $at, $at, $t6
    gpr jr_addend_808005F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808005F4: lw          $t6, 0x818($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(504, 0X818));
    // 0x808005F8: jr          $t6
    // 0x808005FC: nop

    switch (jr_addend_808005F8 >> 2) {
        case 0: goto L_80800600; break;
        case 1: goto L_80800608; break;
        case 2: goto L_80800610; break;
        case 3: goto L_80800618; break;
        case 4: goto L_80800620; break;
        case 5: goto L_80800628; break;
        case 6: goto L_80800630; break;
        default: switch_error(__func__, 0x808005F8, 0x80800818);
    }
    // 0x808005FC: nop

L_80800600:
    // 0x80800600: b           L_80800634
    // 0x80800604: addiu       $a2, $zero, 0x443E
    ctx->r6 = ADD32(0, 0X443E);
        goto L_80800634;
    // 0x80800604: addiu       $a2, $zero, 0x443E
    ctx->r6 = ADD32(0, 0X443E);
L_80800608:
    // 0x80800608: b           L_80800634
    // 0x8080060C: addiu       $a2, $zero, 0x4590
    ctx->r6 = ADD32(0, 0X4590);
        goto L_80800634;
    // 0x8080060C: addiu       $a2, $zero, 0x4590
    ctx->r6 = ADD32(0, 0X4590);
L_80800610:
    // 0x80800610: b           L_80800634
    // 0x80800614: addiu       $a2, $zero, 0x4597
    ctx->r6 = ADD32(0, 0X4597);
        goto L_80800634;
    // 0x80800614: addiu       $a2, $zero, 0x4597
    ctx->r6 = ADD32(0, 0X4597);
L_80800618:
    // 0x80800618: b           L_80800634
    // 0x8080061C: addiu       $a2, $zero, 0x4591
    ctx->r6 = ADD32(0, 0X4591);
        goto L_80800634;
    // 0x8080061C: addiu       $a2, $zero, 0x4591
    ctx->r6 = ADD32(0, 0X4591);
L_80800620:
    // 0x80800620: b           L_80800634
    // 0x80800624: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
        goto L_80800634;
    // 0x80800624: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
L_80800628:
    // 0x80800628: b           L_80800634
    // 0x8080062C: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
        goto L_80800634;
    // 0x8080062C: addiu       $a2, $zero, 0x458F
    ctx->r6 = ADD32(0, 0X458F);
L_80800630:
    // 0x80800630: addiu       $a2, $zero, 0x443E
    ctx->r6 = ADD32(0, 0X443E);
L_80800634:
    // 0x80800634: beq         $a2, $zero, L_80800680
    if (ctx->r6 == 0) {
        // 0x80800638: sw          $a2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r6;
            goto L_80800680;
    }
    // 0x80800638: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8080063C: jal         0x8009C128
    // 0x80800640: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800640: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800644: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800648: jal         0x8009DAAC
    // 0x8080064C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009DAAC(rdram, ctx);
        goto after_1;
    // 0x8080064C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800650: jal         0x800C4B64
    // 0x80800654: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_800C4B64(rdram, ctx);
        goto after_2;
    // 0x80800654: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800658: jal         0x800C4B70
    // 0x8080065C: addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    func_800C4B70(rdram, ctx);
        goto after_3;
    // 0x8080065C: addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    after_3:
    // 0x80800660: jal         0x800C4B7C
    // 0x80800664: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800C4B7C(rdram, ctx);
        goto after_4;
    // 0x80800664: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800668: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(504, 0X860) << 16);
    // 0x8080066C: addiu       $a3, $a3, 0x860
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(504, 0X860));
    // 0x80800670: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80800674: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800678: jal         0x8010D930
    // 0x8080067C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_8010D930(rdram, ctx);
        goto after_5;
    // 0x8080067C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_5:
L_80800680:
    // 0x80800680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800684: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800688: jr          $ra
    // 0x8080068C: nop

    return;
    // 0x8080068C: nop

;}
