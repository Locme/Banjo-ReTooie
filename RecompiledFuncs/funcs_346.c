#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800FC0_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FC8: jal         0x80800AEC
    // 0x80800FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x80800FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FD0: jal         0x80800254
    // 0x80800FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800254_bssub(rdram, ctx);
        goto after_1;
    // 0x80800FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800FD8: jal         0x80082FE8
    // 0x80800FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800FDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void func_808012E0_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808012E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808012E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808012EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808012F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012F4: jal         0x80100094
    // 0x808012F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808012F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808012FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801300: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801304: jal         0x80102424
    // 0x80801308: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801308: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080130C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80801310: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80801314: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80801318: sltiu       $at, $t7, 0x1B
    ctx->r1 = ctx->r15 < 0X1B ? 1 : 0;
    // 0x8080131C: beq         $at, $zero, L_808015E0
    if (ctx->r1 == 0) {
        // 0x80801320: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808015E0;
    }
    // 0x80801320: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801324: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2C8C) << 16);
    // 0x80801328: addu        $at, $at, $t7
    gpr jr_addend_80801330 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080132C: lw          $t7, 0x2C8C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2C8C));
    // 0x80801330: jr          $t7
    // 0x80801334: nop

    switch (jr_addend_80801330 >> 2) {
        case 0: goto L_80801338; break;
        case 1: goto L_80801388; break;
        case 2: goto L_808015E0; break;
        case 3: goto L_808013AC; break;
        case 4: goto L_808013CC; break;
        case 5: goto L_80801434; break;
        case 6: goto L_8080146C; break;
        case 7: goto L_808015E0; break;
        case 8: goto L_808015E0; break;
        case 9: goto L_8080149C; break;
        case 10: goto L_808014D4; break;
        case 11: goto L_8080144C; break;
        case 12: goto L_808013CC; break;
        case 13: goto L_80801434; break;
        case 14: goto L_808015E0; break;
        case 15: goto L_808014F8; break;
        case 16: goto L_808015E0; break;
        case 17: goto L_80801508; break;
        case 18: goto L_80801528; break;
        case 19: goto L_808015E0; break;
        case 20: goto L_80801514; break;
        case 21: goto L_808015E0; break;
        case 22: goto L_80801548; break;
        case 23: goto L_80801584; break;
        case 24: goto L_808015A8; break;
        case 25: goto L_808015D4; break;
        case 26: goto L_808015D4; break;
        default: switch_error(__func__, 0x80801330, 0x80802C8C);
    }
    // 0x80801334: nop

L_80801338:
    // 0x80801338: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2DA0) << 16);
    // 0x8080133C: addiu       $a2, $a2, 0x2DA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2DA0));
    // 0x80801340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801344: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801348: jal         0x80089D18
    // 0x8080134C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080134C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80801350: jal         0x800FDC28
    // 0x80801354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_3;
    // 0x80801354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80801358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080135C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801360: jal         0x808021E4
    // 0x80801364: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_4;
    // 0x80801364: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_4:
    // 0x80801368: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8080136C: jal         0x80106790
    // 0x80801370: lw          $a0, 0x9C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X9C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80801370: lw          $a0, 0x9C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X9C);
    after_5:
    // 0x80801374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801378: jal         0x80102424
    // 0x8080137C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x8080137C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801380: b           L_808015E4
    // 0x80801384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801388:
    // 0x80801388: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x8080138C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801394: jal         0x800861A0
    // 0x80801398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80801398: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8080139C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808013A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808013A4: b           L_808015E0
    // 0x808013A8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808015E0;
    // 0x808013A8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808013AC:
    // 0x808013AC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808013B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808013B4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808013B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808013BC: jal         0x800DC178
    // 0x808013C0: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808013C0: nop

    after_8:
    // 0x808013C4: b           L_808015E0
    // 0x808013C8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x808013C8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808013CC:
    // 0x808013CC: lh          $t8, 0x90($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X90);
    // 0x808013D0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x808013D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808013D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808013DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808013E0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x808013E4: addu        $a1, $v1, $t9
    ctx->r5 = ADD32(ctx->r3, ctx->r25);
    // 0x808013E8: jal         0x800EEB40
    // 0x808013EC: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x808013EC: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    after_9:
    // 0x808013F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2CF8) << 16);
    // 0x808013F4: lwc1        $f6, 0x2CF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2CF8));
    // 0x808013F8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808013FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801400: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801404: nop

    // 0x80801408: bc1f        L_8080141C
    if (!c1cs) {
        // 0x8080140C: nop
    
            goto L_8080141C;
    }
    // 0x8080140C: nop

    // 0x80801410: lh          $t0, 0x90($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X90);
    // 0x80801414: xori        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 ^ 0X1;
    // 0x80801418: sh          $t1, 0x90($v1)
    MEM_H(0X90, ctx->r3) = ctx->r9;
L_8080141C:
    // 0x8080141C: jal         0x80109FE8
    // 0x80801420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_10;
    // 0x80801420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80801424: jal         0x808018E8
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018E8_changlerboss(rdram, ctx);
        goto after_11;
    // 0x80801428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080142C: b           L_808015E4
    // 0x80801430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801434:
    // 0x80801434: lh          $t2, 0x90($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X90);
    // 0x80801438: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080143C: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80801440: sh          $t3, 0x90($v1)
    MEM_H(0X90, ctx->r3) = ctx->r11;
    // 0x80801444: b           L_808015E0
    // 0x80801448: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
        goto L_808015E0;
    // 0x80801448: swc1        $f8, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f8.u32l;
L_8080144C:
    // 0x8080144C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801450: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801454: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801458: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080145C: jal         0x800DC178
    // 0x80801460: nop

    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80801460: nop

    after_12:
    // 0x80801464: b           L_808015E0
    // 0x80801468: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x80801468: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_8080146C:
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801470: jal         0x80801C50
    // 0x80801474: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80801C50_changlerboss(rdram, ctx);
        goto after_13;
    // 0x80801474: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_13:
    // 0x80801478: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8080147C: beq         $at, $zero, L_80801490
    if (ctx->r1 == 0) {
        // 0x80801480: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80801490;
    }
    // 0x80801480: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80801484: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80801488: b           L_808015E0
    // 0x8080148C: sh          $t4, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r12;
        goto L_808015E0;
    // 0x8080148C: sh          $t4, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r12;
L_80801490:
    // 0x80801490: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801494: b           L_808015E0
    // 0x80801498: sh          $t5, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r13;
        goto L_808015E0;
    // 0x80801498: sh          $t5, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r13;
L_8080149C:
    // 0x8080149C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808014A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A8: jal         0x808027F8
    // 0x808014AC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_808027F8_changlerboss(rdram, ctx);
        goto after_14;
    // 0x808014AC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_14:
    // 0x808014B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014B4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x808014B8: jal         0x808021E4
    // 0x808014BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_15;
    // 0x808014BC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_15:
    // 0x808014C0: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x808014C4: jal         0x800D2770
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2770(rdram, ctx);
        goto after_16;
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808014CC: b           L_808015E4
    // 0x808014D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x808014D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808014D4:
    // 0x808014D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808014D8: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x808014DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808014E0: addiu       $a1, $zero, 0x102B
    ctx->r5 = ADD32(0, 0X102B);
    // 0x808014E4: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x808014E8: jal         0x8008A208
    // 0x808014EC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x808014EC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x808014F0: b           L_808015E4
    // 0x808014F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x808014F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808014F8:
    // 0x808014F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808014FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801500: b           L_808015E0
    // 0x80801504: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_808015E0;
    // 0x80801504: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80801508:
    // 0x80801508: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080150C: b           L_808015E0
    // 0x80801510: sh          $t7, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r15;
        goto L_808015E0;
    // 0x80801510: sh          $t7, 0x94($v1)
    MEM_H(0X94, ctx->r3) = ctx->r15;
L_80801514:
    // 0x80801514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801518: jal         0x80109FE8
    // 0x8080151C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_18;
    // 0x8080151C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80801520: b           L_808015E4
    // 0x80801524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801528:
    // 0x80801528: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080152C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801530: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80801534: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801538: jal         0x800DC178
    // 0x8080153C: nop

    func_800DC178(rdram, ctx);
        goto after_19;
    // 0x8080153C: nop

    after_19:
    // 0x80801540: b           L_808015E0
    // 0x80801544: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x80801544: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80801548:
    // 0x80801548: jal         0x800FDC28
    // 0x8080154C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_20;
    // 0x8080154C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80801550: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1332, 0X2F80) << 16);
    // 0x80801554: addiu       $a2, $a2, 0x2F80
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1332, 0X2F80));
    // 0x80801558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080155C: jal         0x80089D18
    // 0x80801560: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80801560: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x80801564: jal         0x808027F8
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808027F8_changlerboss(rdram, ctx);
        goto after_22;
    // 0x80801568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080156C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801570: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80801574: jal         0x808021E4
    // 0x80801578: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_808021E4_changlerboss(rdram, ctx);
        goto after_23;
    // 0x80801578: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_23:
    // 0x8080157C: b           L_808015E4
    // 0x80801580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x80801580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801584:
    // 0x80801584: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801588: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8080158C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801590: addiu       $a1, $zero, 0x1029
    ctx->r5 = ADD32(0, 0X1029);
    // 0x80801594: addiu       $a2, $zero, 0x106
    ctx->r6 = ADD32(0, 0X106);
    // 0x80801598: jal         0x8008A208
    // 0x8080159C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x8080159C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_24:
    // 0x808015A0: b           L_808015E4
    // 0x808015A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808015E4;
    // 0x808015A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808015A8:
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015AC: jal         0x80109FE8
    // 0x808015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_25;
    // 0x808015B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808015B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808015B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808015BC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808015C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808015C4: jal         0x800DC178
    // 0x808015C8: nop

    func_800DC178(rdram, ctx);
        goto after_26;
    // 0x808015C8: nop

    after_26:
    // 0x808015CC: b           L_808015E0
    // 0x808015D0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808015E0;
    // 0x808015D0: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808015D4:
    // 0x808015D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D8: jal         0x80109FE8
    // 0x808015DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_27;
    // 0x808015DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
L_808015E0:
    // 0x808015E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808015E4:
    // 0x808015E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808015E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808015EC: jr          $ra
    // 0x808015F0: nop

    return;
    // 0x808015F0: nop

;}
RECOMP_FUNC void bsbanshack_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C9C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CA0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XD10) << 16);
    // 0x80800CA4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: lw          $v0, 0xD10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XD10));
    return;
    // 0x80800CAC: lw          $v0, 0xD10($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XD10));
;}
RECOMP_FUNC void _susplinet_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E88: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E88);
    return;
    // 0x80089E8C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800B20_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B28: jal         0x80082FE8
    // 0x80800B2C: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B2C: nop

    after_0:
    // 0x80800B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B38: jr          $ra
    // 0x80800B3C: nop

    return;
    // 0x80800B3C: nop

;}
RECOMP_FUNC void func_80800160_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800164: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800168: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080016C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800174: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800178: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080017C: lw          $a1, 0x28($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X28);
    // 0x80800180: sll         $t8, $a1, 18
    ctx->r24 = S32(ctx->r5 << 18);
    // 0x80800184: jal         0x800DF744
    // 0x80800188: srl         $a1, $t8, 31
    ctx->r5 = S32(U32(ctx->r24) >> 31);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800188: srl         $a1, $t8, 31
    ctx->r5 = S32(U32(ctx->r24) >> 31);
    after_0:
    // 0x8080018C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800190: jal         0x80101870
    // 0x80800194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void vpscroll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x808001C8: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x808001CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808001D0: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x808001D4: beq         $at, $zero, L_808001F4
    if (ctx->r1 == 0) {
        // 0x808001D8: lh          $v0, 0x4($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X4);
            goto L_808001F4;
    }
    // 0x808001D8: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
L_808001DC:
    // 0x808001DC: lh          $t7, 0xA($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA);
    // 0x808001E0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808001E4: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x808001E8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x808001EC: bne         $at, $zero, L_808001DC
    if (ctx->r1 != 0) {
        // 0x808001F0: sh          $t8, -0x6($a2)
        MEM_H(-0X6, ctx->r6) = ctx->r24;
            goto L_808001DC;
    }
    // 0x808001F0: sh          $t8, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r24;
L_808001F4:
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

    // 0x808001FC: nop

;}
RECOMP_FUNC void _idglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CD8: syscall     734
    recomp_syscall_handler(rdram, ctx, 0x80088CD8);
    return;
    // 0x80088CDC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808009EC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808009F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DEC) << 16);
    // 0x808009FC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A00: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800A04: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800A08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A0C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800A10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A14: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800A18: lw          $v0, 0x7DEC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DEC));
    // 0x80800A1C: beq         $v0, $zero, L_80800A34
    if (ctx->r2 == 0) {
        // 0x80800A20: nop
    
            goto L_80800A34;
    }
    // 0x80800A20: nop

    // 0x80800A24: jalr        $v0
    // 0x80800A28: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80800A28: nop

    after_0:
    // 0x80800A2C: b           L_80800A40
    // 0x80800A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A40;
    // 0x80800A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A34:
    // 0x80800A34: jal         0x80800478
    // 0x80800A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80800A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A40:
    // 0x80800A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A44: jr          $ra
    // 0x80800A48: nop

    return;
    // 0x80800A48: nop

;}
RECOMP_FUNC void func_80800A00_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800A0C: lw          $a2, 0x48($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X48);
    // 0x80800A10: jal         0x80800898
    // 0x80800A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800898_chnests(rdram, ctx);
        goto after_0;
    // 0x80800A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A18: beql        $v0, $zero, L_80800A60
    if (ctx->r2 == 0) {
        // 0x80800A1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A60;
    }
    goto skip_0;
    // 0x80800A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A20: jal         0x800DF3E0
    // 0x80800A24: nop

    func_800DF3E0(rdram, ctx);
        goto after_1;
    // 0x80800A24: nop

    after_1:
    // 0x80800A28: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800A2C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(752, 0X1124) << 16);
    // 0x80800A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A34: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80800A38: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800A3C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800A40: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80800A44: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80800A48: jal         0x800DF744
    // 0x80800A4C: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800A4C: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    after_2:
    // 0x80800A50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A54: jal         0x801018A4
    // 0x80800A58: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801018A4(rdram, ctx);
        goto after_3;
    // 0x80800A58: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A60:
    // 0x80800A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A64: jr          $ra
    // 0x80800A68: nop

    return;
    // 0x80800A68: nop

;}
RECOMP_FUNC void _baflameline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B70: syscall     130
    recomp_syscall_handler(rdram, ctx, 0x80084B70);
    return;
    // 0x80084B74: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080090C_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800910: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800918: beq         $a1, $at, L_80800960
    if (ctx->r5 == ctx->r1) {
        // 0x8080091C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800960;
    }
    // 0x8080091C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800920: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800924: beq         $a1, $at, L_808009DC
    if (ctx->r5 == ctx->r1) {
        // 0x80800928: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_808009DC;
    }
    // 0x80800928: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080092C: beq         $a1, $at, L_80800A30
    if (ctx->r5 == ctx->r1) {
        // 0x80800930: lw          $t5, 0x20($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X20);
            goto L_80800A30;
    }
    // 0x80800930: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80800934: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800938: beq         $a1, $at, L_8080099C
    if (ctx->r5 == ctx->r1) {
        // 0x8080093C: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_8080099C;
    }
    // 0x8080093C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800940: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80800944: beq         $a1, $at, L_8080098C
    if (ctx->r5 == ctx->r1) {
        // 0x80800948: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080098C;
    }
    // 0x80800948: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080094C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800950: beq         $a1, $at, L_80800A8C
    if (ctx->r5 == ctx->r1) {
        // 0x80800954: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800A8C;
    }
    // 0x80800954: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800958: b           L_80800B58
    // 0x8080095C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B58;
    // 0x8080095C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800960:
    // 0x80800960: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800964: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800968: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x8080096C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800970: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800974: beq         $t8, $at, L_80800984
    if (ctx->r24 == ctx->r1) {
        // 0x80800978: nop
    
            goto L_80800984;
    }
    // 0x80800978: nop

    // 0x8080097C: jal         0x808006AC
    // 0x80800980: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_0;
    // 0x80800980: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
L_80800984:
    // 0x80800984: b           L_80800B58
    // 0x80800988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080098C:
    // 0x8080098C: jal         0x8080007C
    // 0x80800990: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8080007C_chfloaty(rdram, ctx);
        goto after_1;
    // 0x80800990: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x80800994: b           L_80800B58
    // 0x80800998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080099C:
    // 0x8080099C: lhu         $a0, 0x76($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X76);
    // 0x808009A0: srl         $t0, $a0, 7
    ctx->r8 = S32(U32(ctx->r4) >> 7);
    // 0x808009A4: jal         0x800DA298
    // 0x808009A8: addiu       $a0, $t0, 0x320
    ctx->r4 = ADD32(ctx->r8, 0X320);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808009A8: addiu       $a0, $t0, 0x320
    ctx->r4 = ADD32(ctx->r8, 0X320);
    after_2:
    // 0x808009AC: beq         $v0, $zero, L_808009D4
    if (ctx->r2 == 0) {
        // 0x808009B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808009D4;
    }
    // 0x808009B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009B4: lhu         $a1, 0x76($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X76);
    // 0x808009B8: srl         $t2, $a1, 7
    ctx->r10 = S32(U32(ctx->r5) >> 7);
    // 0x808009BC: jal         0x8008A508
    // 0x808009C0: addiu       $a1, $t2, -0x25
    ctx->r5 = ADD32(ctx->r10, -0X25);
    _subaddietaxi_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808009C0: addiu       $a1, $t2, -0x25
    ctx->r5 = ADD32(ctx->r10, -0X25);
    after_3:
    // 0x808009C4: beq         $v0, $zero, L_808009D4
    if (ctx->r2 == 0) {
        // 0x808009C8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808009D4;
    }
    // 0x808009C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009CC: jal         0x808006AC
    // 0x808009D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_4;
    // 0x808009D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
L_808009D4:
    // 0x808009D4: b           L_80800B58
    // 0x808009D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x808009D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009DC:
    // 0x808009DC: jal         0x801015D0
    // 0x808009E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_801015D0(rdram, ctx);
        goto after_5;
    // 0x808009E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808009E4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x808009E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808009F0: lhu         $v0, 0x72($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X72);
    // 0x808009F4: srl         $t4, $v0, 10
    ctx->r12 = S32(U32(ctx->r2) >> 10);
    // 0x808009F8: beq         $t4, $at, L_80800A10
    if (ctx->r12 == ctx->r1) {
        // 0x808009FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A10;
    }
    // 0x808009FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A00: beq         $t4, $at, L_80800A20
    if (ctx->r12 == ctx->r1) {
        // 0x80800A04: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800A20;
    }
    // 0x80800A04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800A08: b           L_80800B58
    // 0x80800A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A10:
    // 0x80800A10: jal         0x800DF744
    // 0x80800A14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x80800A14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800A18: b           L_80800B58
    // 0x80800A1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800A1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A20:
    // 0x80800A20: jal         0x800DF744
    // 0x80800A24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x80800A24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800A28: b           L_80800B58
    // 0x80800A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A30:
    // 0x80800A30: lwc1        $f4, 0x48($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X48);
    // 0x80800A34: addiu       $a0, $zero, 0x486
    ctx->r4 = ADD32(0, 0X486);
    // 0x80800A38: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    // 0x80800A3C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800A40: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800A44: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800A48: jal         0x80108528
    // 0x80800A4C: nop

    func_80108528(rdram, ctx);
        goto after_8;
    // 0x80800A4C: nop

    after_8:
    // 0x80800A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A58: jal         0x808006AC
    // 0x80800A5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_808006AC_chfloaty(rdram, ctx);
        goto after_9;
    // 0x80800A5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_9:
    // 0x80800A60: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800A64: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A6C: lhu         $t6, 0x76($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X76);
    // 0x80800A70: lhu         $t2, 0x76($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X76);
    // 0x80800A74: srl         $t9, $t6, 7
    ctx->r25 = S32(U32(ctx->r14) >> 7);
    // 0x80800A78: sll         $t1, $t9, 7
    ctx->r9 = S32(ctx->r25 << 7);
    // 0x80800A7C: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x80800A80: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800A84: b           L_80800B58
    // 0x80800A88: sh          $t4, 0x76($v1)
    MEM_H(0X76, ctx->r3) = ctx->r12;
        goto L_80800B58;
    // 0x80800A88: sh          $t4, 0x76($v1)
    MEM_H(0X76, ctx->r3) = ctx->r12;
L_80800A8C:
    // 0x80800A8C: lhu         $a1, 0x76($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X76);
    // 0x80800A90: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800A94: addiu       $a2, $a2, 0x7718
    ctx->r6 = ADD32(ctx->r6, 0X7718);
    // 0x80800A98: srl         $t7, $a1, 7
    ctx->r15 = S32(U32(ctx->r5) >> 7);
    // 0x80800A9C: addiu       $a1, $t7, -0x25
    ctx->r5 = ADD32(ctx->r15, -0X25);
    // 0x80800AA0: jal         0x8008A560
    // 0x80800AA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x80800AA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80800AA8: beq         $v0, $zero, L_80800AFC
    if (ctx->r2 == 0) {
        // 0x80800AAC: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_80800AFC;
    }
    // 0x80800AAC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800AB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800AB4: jal         0x80102FDC
    // 0x80800AB8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_11;
    // 0x80800AB8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_11:
    // 0x80800ABC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800AC0: lhu         $a0, 0x76($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X76);
    // 0x80800AC4: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800AC8: jal         0x800DA298
    // 0x80800ACC: addiu       $a0, $t6, 0x320
    ctx->r4 = ADD32(ctx->r14, 0X320);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x80800ACC: addiu       $a0, $t6, 0x320
    ctx->r4 = ADD32(ctx->r14, 0X320);
    after_12:
    // 0x80800AD0: bne         $v0, $zero, L_80800AEC
    if (ctx->r2 != 0) {
        // 0x80800AD4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800AEC;
    }
    // 0x80800AD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800AD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800ADC: jal         0x808006AC
    // 0x80800AE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_13;
    // 0x80800AE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800AE4: b           L_80800B20
    // 0x80800AE8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_80800B20;
    // 0x80800AE8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_80800AEC:
    // 0x80800AEC: jal         0x808006AC
    // 0x80800AF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808006AC_chfloaty(rdram, ctx);
        goto after_14;
    // 0x80800AF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80800AF4: b           L_80800B20
    // 0x80800AF8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_80800B20;
    // 0x80800AF8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_80800AFC:
    // 0x80800AFC: lw          $t0, 0x78($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X78);
    // 0x80800B00: sll         $t1, $t0, 26
    ctx->r9 = S32(ctx->r8 << 26);
    // 0x80800B04: bgezl       $t1, L_80800B20
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800B08: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_80800B20;
    }
    goto skip_0;
    // 0x80800B08: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800B0C: jal         0x800FFA88
    // 0x80800B10: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_15;
    // 0x80800B10: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_15:
    // 0x80800B14: b           L_80800B58
    // 0x80800B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800B1C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_80800B20:
    // 0x80800B20: addiu       $at, $zero, 0x924
    ctx->r1 = ADD32(0, 0X924);
    // 0x80800B24: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80800B28: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80800B2C: lhu         $t5, 0x14($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X14);
    // 0x80800B30: bne         $t5, $at, L_80800B50
    if (ctx->r13 != ctx->r1) {
        // 0x80800B34: nop
    
            goto L_80800B50;
    }
    // 0x80800B34: nop

    // 0x80800B38: jal         0x8010A3E8
    // 0x80800B3C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_16;
    // 0x80800B3C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_16:
    // 0x80800B40: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800B44: addiu       $t7, $zero, -0x50
    ctx->r15 = ADD32(0, -0X50);
    // 0x80800B48: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80800B4C: sh          $t7, 0x20($t6)
    MEM_H(0X20, ctx->r14) = ctx->r15;
L_80800B50:
    // 0x80800B50: b           L_80800B58
    // 0x80800B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B58:
    // 0x80800B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B60: jr          $ra
    // 0x80800B64: nop

    return;
    // 0x80800B64: nop

;}
RECOMP_FUNC void chstinger_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005FC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800600: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800604: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800608: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080060C: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x80800610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800614: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800618: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8080061C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800620: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800624: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80800628: jal         0x800EFA98
    // 0x8080062C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EFA98(rdram, ctx);
        goto after_0;
    // 0x8080062C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800630: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800634: jal         0x800EF04C
    // 0x80800638: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80800638: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8080063C: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80800640: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8080064C: jal         0x800C6A7C
    // 0x80800650: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x80800650: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800654: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x80800658: addiu       $s1, $sp, 0x24
        ctx->r17 = ADD32(ctx->r29, 0X24);
            goto L_80800684;
    }
    // 0x80800658: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x8080065C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800660: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800664: jal         0x800EFB24
    // 0x80800668: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80800668: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x8080066C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800670: jal         0x800EF368
    // 0x80800674: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800EF368(rdram, ctx);
        goto after_4;
    // 0x80800674: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800678: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080067C: jal         0x800EF04C
    // 0x80800680: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800680: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
L_80800684:
    // 0x80800684: addiu       $a0, $zero, 0x16F
    ctx->r4 = ADD32(0, 0X16F);
    // 0x80800688: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8080068C: jal         0x80108474
    // 0x80800690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_6;
    // 0x80800690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800694: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080069C: jal         0x80100094
    // 0x808006A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808006A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808006A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808006A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808006AC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808006B0: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x808006B4: jal         0x800EE7F8
    // 0x808006B8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808006B8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_8:
    // 0x808006BC: jal         0x80800218
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800218_chstinger(rdram, ctx);
        goto after_9;
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808006C8: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x808006CC: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    // 0x808006D0: jal         0x800EE7F8
    // 0x808006D4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x808006D4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_10:
    // 0x808006D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: jal         0x8010A570
    // 0x808006E4: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    func_8010A570(rdram, ctx);
        goto after_11;
    // 0x808006E4: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    after_11:
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: jal         0x8008A768
    // 0x808006F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sumissilehome_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808006F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006FC: jal         0x8008A780
    // 0x80800700: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    _sumissilehome_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80800700: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_13:
    // 0x80800704: jal         0x800EA068
    // 0x80800708: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_14;
    // 0x80800708: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x8080070C: beq         $v0, $zero, L_8080072C
    if (ctx->r2 == 0) {
        // 0x80800710: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080072C;
    }
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080071C: jal         0x8008A788
    // 0x80800720: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sumissilehome_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800720: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80800724: b           L_8080073C
    // 0x80800728: lui         $a2, 0x458C
    ctx->r6 = S32(0X458C << 16);
        goto L_8080073C;
    // 0x80800728: lui         $a2, 0x458C
    ctx->r6 = S32(0X458C << 16);
L_8080072C:
    // 0x8080072C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800730: jal         0x8008A770
    // 0x80800734: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _sumissilehome_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x80800734: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_16:
    // 0x80800738: lui         $a2, 0x458C
    ctx->r6 = S32(0X458C << 16);
L_8080073C:
    // 0x8080073C: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800748: jal         0x8008A790
    // 0x8080074C: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    _sumissilehome_entrypoint_5(rdram, ctx);
        goto after_17;
    // 0x8080074C: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    after_17:
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: jal         0x8080015C
    // 0x80800758: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080015C_chstinger(rdram, ctx);
        goto after_18;
    // 0x80800758: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x8080075C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800760: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800764: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800768: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080076C: jr          $ra
    // 0x80800770: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800770: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void chfiregen_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C38: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X1924) << 16);
    // 0x80800C3C: jr          $ra
    // 0x80800C40: addiu       $v0, $v0, 0x1924
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1924));
    return;
    // 0x80800C40: addiu       $v0, $v0, 0x1924
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1924));
;}
RECOMP_FUNC void func_800F1E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1E30: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x800F1E34: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800F1E38: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800F1E3C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800F1E40: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800F1E44: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800F1E48: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800F1E4C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800F1E50: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F1E54: jal         0x80013B7C
    // 0x800F1E58: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80013B7C(rdram, ctx);
        goto after_0;
    // 0x800F1E58: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800F1E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1E64: jr          $ra
    // 0x800F1E68: nop

    return;
    // 0x800F1E68: nop

;}
RECOMP_FUNC void bstnt_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080192C: jal         0x8009E6EC
    // 0x80801930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80801930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801934: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80801938: bne         $v0, $at, L_80801968
    if (ctx->r2 != ctx->r1) {
        // 0x8080193C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801968;
    }
    // 0x8080193C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801940: jal         0x80099A4C
    // 0x80801944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80099A4C(rdram, ctx);
        goto after_1;
    // 0x80801944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80801948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080194C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801950: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801954: sw          $v0, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->r2;
    // 0x80801958: jal         0x8009E830
    // 0x8080195C: sb          $t6, 0x168($a0)
    MEM_B(0X168, ctx->r4) = ctx->r14;
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x8080195C: sb          $t6, 0x168($a0)
    MEM_B(0X168, ctx->r4) = ctx->r14;
    after_2:
    // 0x80801960: b           L_80801974
    // 0x80801964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801974;
    // 0x80801964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801968:
    // 0x80801968: jal         0x80099B94
    // 0x8080196C: nop

    func_80099B94(rdram, ctx);
        goto after_3;
    // 0x8080196C: nop

    after_3:
    // 0x80801970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801974:
    // 0x80801974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801978: jr          $ra
    // 0x8080197C: nop

    return;
    // 0x8080197C: nop

;}
RECOMP_FUNC void func_80803D60_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803D64: sltiu       $at, $a0, 0x8
    ctx->r1 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x80803D68: beq         $at, $zero, L_80803DB8
    if (ctx->r1 == 0) {
        // 0x80803D6C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80803DB8;
    }
    // 0x80803D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803D70: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80803D74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CE8) << 16);
    // 0x80803D78: addu        $at, $at, $t6
    gpr jr_addend_80803D80 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80803D7C: lw          $t6, 0x7CE8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CE8));
    // 0x80803D80: jr          $t6
    // 0x80803D84: nop

    switch (jr_addend_80803D80 >> 2) {
        case 0: goto L_80803D88; break;
        case 1: goto L_80803D88; break;
        case 2: goto L_80803D88; break;
        case 3: goto L_80803DB8; break;
        case 4: goto L_80803DB8; break;
        case 5: goto L_80803D98; break;
        case 6: goto L_80803DB8; break;
        case 7: goto L_80803DA8; break;
        default: switch_error(__func__, 0x80803D80, 0x80807CE8);
    }
    // 0x80803D84: nop

L_80803D88:
    // 0x80803D88: jal         0x808036F8
    // 0x80803D8C: nop

    func_808036F8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80803D8C: nop

    after_0:
    // 0x80803D90: b           L_80803DC0
    // 0x80803D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803DC0;
    // 0x80803D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803D98:
    // 0x80803D98: jal         0x80088138
    // 0x80803D9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80803D9C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80803DA0: b           L_80803DC0
    // 0x80803DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803DC0;
    // 0x80803DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803DA8:
    // 0x80803DA8: jal         0x80088140
    // 0x80803DAC: nop

    _gcfrontend_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80803DAC: nop

    after_2:
    // 0x80803DB0: b           L_80803DC0
    // 0x80803DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803DC0;
    // 0x80803DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803DB8:
    // 0x80803DB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803DC0:
    // 0x80803DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803DC4: jr          $ra
    // 0x80803DC8: nop

    return;
    // 0x80803DC8: nop

;}
RECOMP_FUNC void func_80800018_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x8080001C: lbu         $t1, 0x95($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X95);
    // 0x80800020: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800024: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800028: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8080002C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80800030: addiu       $t9, $t8, 0x320
    ctx->r25 = ADD32(ctx->r24, 0X320);
    // 0x80800034: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80800038: sh          $t9, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r25;
    // 0x8080003C: jr          $ra
    // 0x80800040: sb          $t2, 0x95($a0)
    MEM_B(0X95, ctx->r4) = ctx->r10;
    return;
    // 0x80800040: sb          $t2, 0x95($a0)
    MEM_B(0X95, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_8009B94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B954: beq         $a1, $zero, L_8009B970
    if (ctx->r5 == 0) {
        // 0x8009B958: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8009B970;
    }
    // 0x8009B958: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8009B95C: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B960: jal         0x800EE7F8
    // 0x8009B964: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009B964: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8009B968: b           L_8009B980
    // 0x8009B96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009B980;
    // 0x8009B96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009B970:
    // 0x8009B970: lw          $a0, 0xC8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC8);
    // 0x8009B974: jal         0x800EFD24
    // 0x8009B978: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009B978: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8009B97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009B980:
    // 0x8009B980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B984: jr          $ra
    // 0x8009B988: nop

    return;
    // 0x8009B988: nop

;}
RECOMP_FUNC void func_808005D4_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005D8: addiu       $at, $zero, 0x17E8
    ctx->r1 = ADD32(0, 0X17E8);
    // 0x808005DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E0: beq         $a1, $at, L_808005F0
    if (ctx->r5 == ctx->r1) {
        // 0x808005E4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808005F0;
    }
    // 0x808005E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808005E8: jal         0x80102424
    // 0x808005EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x808005EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_808005F0:
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void func_80801034_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801038: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080103C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801040: jal         0x808001A8
    // 0x80801044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080104C: addiu       $a1, $zero, 0x359
    ctx->r5 = ADD32(0, 0X359);
    // 0x80801050: jal         0x8008CB3C
    // 0x80801054: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801054: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80801058: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8080105C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801064: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801068: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080106C: jal         0x8009FFD8
    // 0x80801070: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801070: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801074: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801078: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080107C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801080: jal         0x8008C9BC
    // 0x80801084: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x80801084: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_3:
    // 0x80801088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D04) << 16);
    // 0x8080108C: lwc1        $f4, 0x1D04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D04));
    // 0x80801090: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80801094: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080109C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808010A0: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x808010A4: jal         0x8008C9F0
    // 0x808010A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x808010A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B0: jal         0x8008CA30
    // 0x808010B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_5;
    // 0x808010B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x808010B8: jal         0x808000BC
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bswasher(rdram, ctx);
        goto after_6;
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808010C0: jal         0x80800F54
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F54_bswasher(rdram, ctx);
        goto after_7;
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808010C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808010CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808010D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010D4: jr          $ra
    // 0x808010D8: nop

    return;
    // 0x808010D8: nop

;}
RECOMP_FUNC void bacough_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: jal         0x8080005C
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bacough_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_808020EC_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808020F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808020F8: jal         0x80100094
    // 0x808020FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808020FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802100: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802104: addiu       $a0, $zero, 0x44F
    ctx->r4 = ADD32(0, 0X44F);
    // 0x80802108: jal         0x801084B0
    // 0x8080210C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x8080210C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80802110: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80802114: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80802118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080211C: jal         0x80102FDC
    // 0x80802120: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x80802120: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_2:
    // 0x80802124: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80802128: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8080212C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80802130: sw          $t8, 0x8C($t9)
    MEM_W(0X8C, ctx->r25) = ctx->r24;
    // 0x80802134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080213C: jr          $ra
    // 0x80802140: nop

    return;
    // 0x80802140: nop

;}
RECOMP_FUNC void chklungospiral_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1468, 0X620) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x620
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1468, 0X620));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x620
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1468, 0X620));
;}
RECOMP_FUNC void gspropctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: jr          $ra
    // 0x80800044: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x80800044: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void func_80800000_chmumboskullfakearchpanellava(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800EA05C
    // 0x8080000C: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x80800014: bne         $v0, $at, L_80800024
    if (ctx->r2 != ctx->r1) {
        // 0x80800018: nop
    
            goto L_80800024;
    }
    // 0x80800018: nop

    // 0x8080001C: b           L_80800044
    // 0x80800020: addiu       $v0, $zero, 0x39C
    ctx->r2 = ADD32(0, 0X39C);
        goto L_80800044;
    // 0x80800020: addiu       $v0, $zero, 0x39C
    ctx->r2 = ADD32(0, 0X39C);
L_80800024:
    // 0x80800024: jal         0x800EA05C
    // 0x80800028: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800028: nop

    after_1:
    // 0x8080002C: addiu       $at, $zero, 0xEF
    ctx->r1 = ADD32(0, 0XEF);
    // 0x80800030: bnel        $v0, $at, L_80800044
    if (ctx->r2 != ctx->r1) {
        // 0x80800034: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800038: b           L_80800044
    // 0x8080003C: addiu       $v0, $zero, 0x39D
    ctx->r2 = ADD32(0, 0X39D);
        goto L_80800044;
    // 0x8080003C: addiu       $v0, $zero, 0x39D
    ctx->r2 = ADD32(0, 0X39D);
    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800044:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void chcrate_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1912, 0X4A0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x4A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1912, 0X4A0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x4A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1912, 0X4A0));
;}
RECOMP_FUNC void func_800FA8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA8E8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA8EC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA8F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FA8F4: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FA8F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA8FC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA900: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x800FA904: beq         $t8, $zero, L_800FA918
    if (ctx->r24 == 0) {
        // 0x800FA908: nop
    
            goto L_800FA918;
    }
    // 0x800FA908: nop

    // 0x800FA90C: lb          $t9, 0xE($v1)
    ctx->r25 = MEM_B(ctx->r3, 0XE);
    // 0x800FA910: beql        $a1, $t9, L_800FA924
    if (ctx->r5 == ctx->r25) {
        // 0x800FA914: lbu         $v0, 0xC($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XC);
            goto L_800FA924;
    }
    goto skip_0;
    // 0x800FA914: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    skip_0:
L_800FA918:
    // 0x800FA918: jr          $ra
    // 0x800FA91C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800FA91C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800FA920: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
L_800FA924:
    // 0x800FA924: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FA928: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800FA92C: jr          $ra
    // 0x800FA930: nop

    return;
    // 0x800FA930: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083968: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083968);
    return;
    // 0x8008396C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800EE4_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800EF0: jal         0x80101FDC
    // 0x80800EF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800EF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800EF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F00: beq         $a1, $at, L_80800F18
    if (ctx->r5 == ctx->r1) {
        // 0x80800F04: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800F18;
    }
    // 0x80800F04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F08: beql        $a1, $at, L_80800F40
    if (ctx->r5 == ctx->r1) {
        // 0x80800F0C: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80800F40;
    }
    goto skip_0;
    // 0x80800F0C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    skip_0:
    // 0x80800F10: b           L_80800F60
    // 0x80800F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F60;
    // 0x80800F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F18:
    // 0x80800F18: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x80800F1C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800F20: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80800F24: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F28: jal         0x800DC178
    // 0x80800F2C: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800F2C: nop

    after_1:
    // 0x80800F30: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800F34: b           L_80800F5C
    // 0x80800F38: swc1        $f0, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f0.u32l;
        goto L_80800F5C;
    // 0x80800F38: swc1        $f0, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f0.u32l;
    // 0x80800F3C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
L_80800F40:
    // 0x80800F40: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800F44: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x80800F48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F4C: jal         0x800DC178
    // 0x80800F50: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800F50: nop

    after_2:
    // 0x80800F54: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800F58: swc1        $f0, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f0.u32l;
L_80800F5C:
    // 0x80800F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F60:
    // 0x80800F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F64: jr          $ra
    // 0x80800F68: nop

    return;
    // 0x80800F68: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844C0: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844C0);
    return;
    // 0x800844C4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808007C4_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808007C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808007CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808007D8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808007DC: jal         0x80100094
    // 0x808007E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E4: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808007E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808007EC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808007F0: jal         0x8010A3E8
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007F8: jal         0x8010A590
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_2;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800800: addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    // 0x80800804: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800808: jal         0x800EE940
    // 0x8080080C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EE940(rdram, ctx);
        goto after_3;
    // 0x8080080C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800810: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800814: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800818: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080081C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800820: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800828: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8080082C: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x80800830: swc1        $f4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f4.u32l;
    // 0x80800834: jal         0x800EE7F8
    // 0x80800838: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800838: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    after_4:
    // 0x8080083C: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800840: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800844: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800848: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x8080084C: bgez        $t8, L_808008D4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800850: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008D4;
    }
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x80800858: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: jal         0x80105138
    // 0x80800864: lui         $a3, 0xC3FA
    ctx->r7 = S32(0XC3FA << 16);
    func_80105138(rdram, ctx);
        goto after_5;
    // 0x80800864: lui         $a3, 0xC3FA
    ctx->r7 = S32(0XC3FA << 16);
    after_5:
    // 0x80800868: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x8080086C: lwc1        $f8, 0x38($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80800880;
    }
    // 0x8080086C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800870: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800874: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800878: nop

    // 0x8080087C: sh          $t1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r9;
L_80800880:
    // 0x80800880: jal         0x8008A498
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    // 0x80800890: jal         0x80089F70
    // 0x80800894: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800894: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
    // 0x80800898: jal         0x80107200
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80107200(rdram, ctx);
        goto after_8;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: jal         0x80801160
    // 0x808008A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_9;
    // 0x808008A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808008AC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808008B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808008B4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808008B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008BC: jal         0x800DC178
    // 0x808008C0: nop

    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x808008C0: nop

    after_10:
    // 0x808008C4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808008C8: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x808008CC: b           L_80800908
    // 0x808008D0: sh          $t3, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r11;
        goto L_80800908;
    // 0x808008D0: sh          $t3, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r11;
L_808008D4:
    // 0x808008D4: jal         0x80801160
    // 0x808008D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_11;
    // 0x808008D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808008DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808008E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008E4: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808008E8: lbu         $t4, 0x64($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X64);
    // 0x808008EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808008F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008F8: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x808008FC: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    // 0x80800900: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80800904: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800908:
    // 0x80800908: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080090C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800910: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800914: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800918: jr          $ra
    // 0x8080091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void baflameline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800448: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8080044C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80800450: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80800454: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800458: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8080045C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800460: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800464: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800468: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080046C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80800470: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800474: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800478: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080047C: addiu       $s4, $sp, 0x74
    ctx->r20 = ADD32(ctx->r29, 0X74);
    // 0x80800480: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800484: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x80800488: nop

    // 0x8080048C: bc1fl       L_808004B4
    if (!c1cs) {
        // 0x80800490: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_808004B4;
    }
    goto skip_0;
    // 0x80800490: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80800494: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80800498: beql        $a0, $zero, L_8080069C
    if (ctx->r4 == 0) {
        // 0x8080049C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8080069C;
    }
    goto skip_1;
    // 0x8080049C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x808004A0: jal         0x800C8FE0
    // 0x808004A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_0;
    // 0x808004A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004A8: b           L_8080069C
    // 0x808004AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8080069C;
    // 0x808004AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x808004B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_808004B4:
    // 0x808004B4: jal         0x800EFA20
    // 0x808004B8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x808004B8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_1:
    // 0x808004BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808004C0: jal         0x800EF04C
    // 0x808004C4: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x808004C4: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    after_2:
    // 0x808004C8: lw          $t6, 0x84($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X84);
    // 0x808004CC: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x808004D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004D4: lui         $a3, 0x459C
    ctx->r7 = S32(0X459C << 16);
    // 0x808004D8: lwc1        $f12, 0x18($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X18);
    // 0x808004DC: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x808004E0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x808004E4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x808004E8: jal         0x800F10B4
    // 0x808004EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808004EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808004F0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808004F4: lw          $t7, 0x84($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X84);
    // 0x808004F8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808004FC: jal         0x800C3058
    // 0x80800500: lbu         $a0, 0x20($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X20);
    func_800C3058(rdram, ctx);
        goto after_4;
    // 0x80800500: lbu         $a0, 0x20($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X20);
    after_4:
    // 0x80800504: lw          $t9, 0x84($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X84);
    // 0x80800508: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080050C: jal         0x800C35E8
    // 0x80800510: lbu         $a0, 0x20($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X20);
    func_800C35E8(rdram, ctx);
        goto after_5;
    // 0x80800510: lbu         $a0, 0x20($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X20);
    after_5:
    // 0x80800514: lw          $t0, 0x84($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X84);
    // 0x80800518: jal         0x800C3BDC
    // 0x8080051C: lbu         $a0, 0x20($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X20);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x8080051C: lbu         $a0, 0x20($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X20);
    after_6:
    // 0x80800520: lw          $s0, 0x84($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X84);
    // 0x80800524: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x80800528: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080052C: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80800530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800534: beql        $t1, $zero, L_808005BC
    if (ctx->r9 == 0) {
        // 0x80800538: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808005BC;
    }
    goto skip_2;
    // 0x80800538: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_2:
    // 0x8080053C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800540: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800544: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800548: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080054C: mul.s       $f20, $f8, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x80800550: jal         0x800EFE50
    // 0x80800554: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800EFE50(rdram, ctx);
        goto after_7;
    // 0x80800554: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_7:
    // 0x80800558: lw          $t2, 0x84($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X84);
    // 0x8080055C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800560: jal         0x800C8FE0
    // 0x80800564: lw          $a0, 0x24($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X24);
    func_800C8FE0(rdram, ctx);
        goto after_8;
    // 0x80800564: lw          $a0, 0x24($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X24);
    after_8:
    // 0x80800568: lw          $t3, 0x84($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X84);
    // 0x8080056C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800570: jal         0x800C8CB8
    // 0x80800574: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_9;
    // 0x80800574: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    after_9:
    // 0x80800578: lw          $s0, 0x84($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X84);
    // 0x8080057C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800580: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80800584: jal         0x800C8E54
    // 0x80800588: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    func_800C8E54(rdram, ctx);
        goto after_10;
    // 0x80800588: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_10:
    // 0x8080058C: jal         0x8001210C
    // 0x80800590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_11;
    // 0x80800590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80800594: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80800598: lw          $t4, 0x84($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X84);
    // 0x8080059C: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x808005A0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(520, 0X798) << 16);
    // 0x808005A4: addiu       $t6, $t6, 0x798
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(520, 0X798));
    // 0x808005A8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x808005AC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x808005B0: jal         0x800C8E84
    // 0x808005B4: lw          $a0, 0x24($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X24);
    func_800C8E84(rdram, ctx);
        goto after_12;
    // 0x808005B4: lw          $a0, 0x24($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X24);
    after_12:
    // 0x808005B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808005BC:
    // 0x808005BC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808005C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(520, 0X6E8) << 16);
    // 0x808005C4: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x808005C8: lwc1        $f20, 0x6E8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X6E8));
    // 0x808005CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808005D0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_808005D4:
    // 0x808005D4: jal         0x800DC178
    // 0x808005D8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x808005D8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_13:
    // 0x808005DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808005E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005E4: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    // 0x808005E8: jal         0x800EFE50
    // 0x808005EC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFE50(rdram, ctx);
        goto after_14;
    // 0x808005EC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_14:
    // 0x808005F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808005F4: jal         0x80800184
    // 0x808005F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800184_baflameline(rdram, ctx);
        goto after_15;
    // 0x808005F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x808005FC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800600: jal         0x800DC178
    // 0x80800604: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x80800604: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_16:
    // 0x80800608: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080060C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800610: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    // 0x80800614: jal         0x800EFE50
    // 0x80800618: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFE50(rdram, ctx);
        goto after_17;
    // 0x80800618: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_17:
    // 0x8080061C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800620: jal         0x80800184
    // 0x80800624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800184_baflameline(rdram, ctx);
        goto after_18;
    // 0x80800624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x80800628: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080062C: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80800630: bnel        $at, $zero, L_808005D4
    if (ctx->r1 != 0) {
        // 0x80800634: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_808005D4;
    }
    goto skip_3;
    // 0x80800634: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_3:
    // 0x80800638: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8080063C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800640: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800644: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080064C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80800650: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
L_80800654:
    // 0x80800654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800658: lw          $a1, 0x84($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X84);
    // 0x8080065C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800660: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800664: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x80800668: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8080066C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800670: jal         0x800EFE50
    // 0x80800674: nop

    func_800EFE50(rdram, ctx);
        goto after_19;
    // 0x80800674: nop

    after_19:
    // 0x80800678: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8080067C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800680: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800684: jal         0x8008EEC4
    // 0x80800688: addiu       $a3, $zero, 0x26D
    ctx->r7 = ADD32(0, 0X26D);
    func_8008EEC4(rdram, ctx);
        goto after_20;
    // 0x80800688: addiu       $a3, $zero, 0x26D
    ctx->r7 = ADD32(0, 0X26D);
    after_20:
    // 0x8080068C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800690: bnel        $s0, $s3, L_80800654
    if (ctx->r16 != ctx->r19) {
        // 0x80800694: mtc1        $s0, $f10
        ctx->f10.u32l = ctx->r16;
            goto L_80800654;
    }
    goto skip_4;
    // 0x80800694: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    skip_4:
    // 0x80800698: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8080069C:
    // 0x8080069C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808006A0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808006A4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808006A8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808006AC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808006B0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808006B4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808006B8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808006BC: jr          $ra
    // 0x808006C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808006C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x808006C4: nop

    // 0x808006C8: nop

    // 0x808006CC: nop

;}
RECOMP_FUNC void bsbbilldrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080068C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800690: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800694: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800698: jal         0x8008CABC
    // 0x8080069C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080069C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808006A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006A4: jal         0x8008AF24
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: jal         0x8008B1A0
    // 0x808006B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808006B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: jal         0x8008AED4
    // 0x808006C0: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808006C0: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    after_3:
    // 0x808006C4: lui         $a1, 0x3F82
    ctx->r5 = S32(0X3F82 << 16);
    // 0x808006C8: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x808006CC: jal         0x8008B1BC
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006D4: lui         $a1, 0x3EBA
    ctx->r5 = S32(0X3EBA << 16);
    // 0x808006D8: ori         $a1, $a1, 0x36E3
    ctx->r5 = ctx->r5 | 0X36E3;
    // 0x808006DC: jal         0x8008B24C
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006E4: lui         $a2, 0x3EE8
    ctx->r6 = S32(0X3EE8 << 16);
    // 0x808006E8: ori         $a2, $a2, 0xC155
    ctx->r6 = ctx->r6 | 0XC155;
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x8008B1D4
    // 0x808006F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x808006F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006FC: jal         0x8008B134
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800704: jal         0x8008B064
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080070C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800710: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080071C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800720: jal         0x8009FFD8
    // 0x80800724: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800724: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80800728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080072C: jal         0x8009BCB4
    // 0x80800730: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_10;
    // 0x80800730: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800738: jal         0x8009B9B0
    // 0x8080073C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x8080073C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800740: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800744: jal         0x800A0CF4
    // 0x80800748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_12;
    // 0x80800748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8080074C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800750: jal         0x80095774
    // 0x80800754: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    baflag_clear(rdram, ctx);
        goto after_13;
    // 0x80800754: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_13:
    // 0x80800758: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080075C: jal         0x80095774
    // 0x80800760: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    baflag_clear(rdram, ctx);
        goto after_14;
    // 0x80800760: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_14:
    // 0x80800764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800768: jal         0x800931AC
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800931AC(rdram, ctx);
        goto after_15;
    // 0x8080076C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80800770: jal         0x8009E4AC
    // 0x80800774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_16;
    // 0x80800774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800778: sb          $zero, 0x164($s1)
    MEM_B(0X164, ctx->r17) = 0;
    // 0x8080077C: sb          $zero, 0x160($s1)
    MEM_B(0X160, ctx->r17) = 0;
    // 0x80800780: sb          $zero, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = 0;
    // 0x80800784: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800788: jal         0x808002DC
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808002DC_bsbbilldrill(rdram, ctx);
        goto after_17;
    // 0x8080078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800790: jal         0x80800000
    // 0x80800794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_bsbbilldrill(rdram, ctx);
        goto after_18;
    // 0x80800794: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080079C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808007A0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808007A4: jr          $ra
    // 0x808007A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808007A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80803CE0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803CE8: jal         0x800FC660
    // 0x80803CEC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x80803CEC: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_0:
    // 0x80803CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803CF8: jr          $ra
    // 0x80803CFC: nop

    return;
    // 0x80803CFC: nop

;}
RECOMP_FUNC void func_80802BD8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BD8: jr          $ra
    // 0x80802BDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80802BDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808001F0_bskazow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001FC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800204: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800208: jal         0x8008CB10
    // 0x8080020C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x8080020C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_0:
    // 0x80800210: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x80800214: nop
    
            goto L_80800220;
    }
    // 0x80800214: nop

    // 0x80800218: jal         0x800951B4
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80800220:
    // 0x80800220: jal         0x800845C8
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800228: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x8080022C: nop
    
            goto L_80800238;
    }
    // 0x8080022C: nop

    // 0x80800230: jal         0x800834B0
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800238:
    // 0x80800238: jal         0x80084600
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800240: beq         $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800244: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_8080024C;
    }
    // 0x80800244: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x80800248: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080024C:
    // 0x8080024C: jal         0x8008E35C
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_5;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800254: beql        $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    goto skip_0;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080025C: jal         0x8009BB50
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_6;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800264: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800268: addiu       $t7, $zero, 0x160
    ctx->r15 = ADD32(0, 0X160);
    // 0x8080026C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80800270: nop

    // 0x80800274: bc1fl       L_80800284
    if (!c1cs) {
        // 0x80800278: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    goto skip_1;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080027C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800284:
    // 0x80800284: jal         0x8009E5C8
    // 0x80800288: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80800288: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x8080028C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800290: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800294: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_80800650_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800658: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080065C: jal         0x80800874
    // 0x80800660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800874_cheggproximity(rdram, ctx);
        goto after_0;
    // 0x80800660: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800664: jal         0x80800AFC
    // 0x80800668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800AFC_cheggproximity(rdram, ctx);
        goto after_1;
    // 0x80800668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080066C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800670: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800674: slti        $at, $v0, 0x79
    ctx->r1 = SIGNED(ctx->r2) < 0X79 ? 1 : 0;
    // 0x80800678: beq         $at, $zero, L_80800690
    if (ctx->r1 == 0) {
        // 0x8080067C: addiu       $t6, $v0, -0x8
        ctx->r14 = ADD32(ctx->r2, -0X8);
            goto L_80800690;
    }
    // 0x8080067C: addiu       $t6, $v0, -0x8
    ctx->r14 = ADD32(ctx->r2, -0X8);
    // 0x80800680: jal         0x80800718
    // 0x80800684: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800718_cheggproximity(rdram, ctx);
        goto after_2;
    // 0x80800684: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80800688: b           L_80800698
    // 0x8080068C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800698;
    // 0x8080068C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800690:
    // 0x80800690: sb          $t6, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r14;
    // 0x80800694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800698:
    // 0x80800698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080069C: jr          $ra
    // 0x808006A0: nop

    return;
    // 0x808006A0: nop

;}
RECOMP_FUNC void _chjigsawdance_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858B0: syscall     179
    recomp_syscall_handler(rdram, ctx, 0x800858B0);
    return;
    // 0x800858B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800164_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080016C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800174: jal         0x8009E74C
    // 0x80800178: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80800178: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_0:
    // 0x8080017C: beq         $v0, $zero, L_808001A8
    if (ctx->r2 == 0) {
        // 0x80800180: nop
    
            goto L_808001A8;
    }
    // 0x80800180: nop

    // 0x80800184: jal         0x80084508
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_1;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080018C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800190: beq         $v0, $at, L_80800208
    if (ctx->r2 == ctx->r1) {
        // 0x80800194: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800208;
    }
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: jal         0x80084538
    // 0x8080019C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _babackpack_set_state(rdram, ctx);
        goto after_2;
    // 0x8080019C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x808001A0: b           L_8080020C
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080020C;
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001A8:
    // 0x808001A8: jal         0x80084508
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_get_state(rdram, ctx);
        goto after_3;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001B4: beq         $v0, $at, L_808001C4
    if (ctx->r2 == ctx->r1) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001C4;
    }
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x80084538
    // 0x808001C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_4;
    // 0x808001C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_808001C4:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x800A0CD0
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_5;
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001D0: jal         0x8009E6F8
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_6;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001D8: addiu       $at, $zero, 0x16B
    ctx->r1 = ADD32(0, 0X16B);
    // 0x808001DC: beq         $v0, $at, L_808001F8
    if (ctx->r2 == ctx->r1) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F8;
    }
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x808001E8: jal         0x8008CDB8
    // 0x808001EC: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_7;
    // 0x808001EC: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_7:
    // 0x808001F0: jal         0x8008CA98
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CA98(rdram, ctx);
        goto after_8;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_808001F8:
    // 0x808001F8: jal         0x80095A40
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_9;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800200: jal         0x8009EF60
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_10;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80800208:
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080020C:
    // 0x8080020C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800210: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void _sumissilehome_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A768: syscall     850
    recomp_syscall_handler(rdram, ctx, 0x8008A768);
    return;
    // 0x8008A76C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080041C_cheggsplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800420: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800424: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080042C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800430: jal         0x80100094
    // 0x80800434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800434: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800438: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080043C: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x80800440: jal         0x800F6BE4
    // 0x80800444: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x80800444: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800448: bnel        $v0, $zero, L_80800460
    if (ctx->r2 != 0) {
        // 0x8080044C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80800460;
    }
    goto skip_0;
    // 0x8080044C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80800450: jal         0x800F54E4
    // 0x80800454: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800454: nop

    after_2:
    // 0x80800458: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080045C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800460:
    // 0x80800460: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800464: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800468: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x8080046C: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x80800470: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80800474: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800478: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080047C: jal         0x800E1610
    // 0x80800480: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_800E1610(rdram, ctx);
        goto after_3;
    // 0x80800480: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_3:
    // 0x80800484: jal         0x800F54F0
    // 0x80800488: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F54F0(rdram, ctx);
        goto after_4;
    // 0x80800488: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8080048C: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800490: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x80800494: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80800498: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080049C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808004A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808004A4: jal         0x800187B4
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800187B4(rdram, ctx);
        goto after_5;
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808004AC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808004B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004B4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808004B8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2176, 0X8B0) << 16);
    // 0x808004BC: addiu       $t7, $t7, 0x8B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2176, 0X8B0));
    // 0x808004C0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808004C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808004D0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x808004D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808004D8: jal         0x800BABB8
    // 0x808004DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x808004DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808004E0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808004E4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808004E8: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x808004EC: beq         $t9, $at, L_808004FC
    if (ctx->r25 == ctx->r1) {
        // 0x808004F0: nop
    
            goto L_808004FC;
    }
    // 0x808004F0: nop

    // 0x808004F4: jal         0x808006F0
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006F0_cheggsplode(rdram, ctx);
        goto after_7;
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_808004FC:
    // 0x808004FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2176, 0X980) << 16);
    // 0x80800500: addiu       $a3, $a3, 0x980
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2176, 0X980));
    // 0x80800504: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800508: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080050C: jal         0x8010D930
    // 0x80800510: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_8010D930(rdram, ctx);
        goto after_8;
    // 0x80800510: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80800514: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080051C: jal         0x800F6BE4
    // 0x80800520: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    func_800F6BE4(rdram, ctx);
        goto after_9;
    // 0x80800520: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    after_9:
    // 0x80800524: beq         $v0, $zero, L_80800534
    if (ctx->r2 == 0) {
        // 0x80800528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800534;
    }
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x80800778
    // 0x80800530: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800778_cheggsplode(rdram, ctx);
        goto after_10;
    // 0x80800530: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
L_80800534:
    // 0x80800534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800538: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080053C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800540: jr          $ra
    // 0x80800544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80013488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001348C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013490: jal         0x80012530
    // 0x80013494: nop

    func_80012530(rdram, ctx);
        goto after_0;
    // 0x80013494: nop

    after_0:
    // 0x80013498: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001349C: bne         $v0, $at, L_800134B4
    if (ctx->r2 != ctx->r1) {
        // 0x800134A0: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_800134B4;
    }
    // 0x800134A0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800134A4: addiu       $a0, $a0, 0x69E0
    ctx->r4 = ADD32(ctx->r4, 0X69E0);
    // 0x800134A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800134AC: jal         0x8002EAD0
    // 0x800134B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800134B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_800134B4:
    // 0x800134B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800134B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800134BC: jr          $ra
    // 0x800134C0: nop

    return;
    // 0x800134C0: nop

;}
RECOMP_FUNC void func_801061D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801061D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801061DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801061E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801061E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801061E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801061EC: jal         0x801063C0
    // 0x801061F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_801063C0(rdram, ctx);
        goto after_0;
    // 0x801061F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x801061F4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801061F8: jal         0x80103AA0
    // 0x801061FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80103AA0(rdram, ctx);
        goto after_1;
    // 0x801061FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80106200: beq         $v0, $zero, L_801062E4
    if (ctx->r2 == 0) {
        // 0x80106204: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_801062E4;
    }
    // 0x80106204: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80106208: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8010620C: jal         0x800D62E4
    // 0x80106210: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x80106210: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_2:
    // 0x80106214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106218: jal         0x80103CDC
    // 0x8010621C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80103CDC(rdram, ctx);
        goto after_3;
    // 0x8010621C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80106220: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80106224: jal         0x80088688
    // 0x80106228: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _glid_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80106228: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8010622C: lbu         $t7, 0x70($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X70);
    // 0x80106230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106234: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80106238: beql        $t8, $zero, L_80106258
    if (ctx->r24 == 0) {
        // 0x8010623C: lw          $t9, 0x7C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X7C);
            goto L_80106258;
    }
    goto skip_0;
    // 0x8010623C: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x80106240: jal         0x80103D00
    // 0x80106244: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80103D00(rdram, ctx);
        goto after_5;
    // 0x80106244: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80106248: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8010624C: jal         0x80088690
    // 0x80106250: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _glid_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80106250: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80106254: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
L_80106258:
    // 0x80106258: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x8010625C: bgezl       $t1, L_80106300
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80106260: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80106300;
    }
    goto skip_1;
    // 0x80106260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80106264: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80106268: sll         $t4, $t2, 9
    ctx->r12 = S32(ctx->r10 << 9);
    // 0x8010626C: bltzl       $t4, L_80106300
    if (SIGNED(ctx->r12) < 0) {
        // 0x80106270: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80106300;
    }
    goto skip_2;
    // 0x80106270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80106274: jal         0x800B296C
    // 0x80106278: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    vector_end(rdram, ctx);
        goto after_7;
    // 0x80106278: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    after_7:
    // 0x8010627C: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x80106280: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106284: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80106288: sw          $t5, 0x6ED4($at)
    MEM_W(0X6ED4, ctx->r1) = ctx->r13;
    // 0x8010628C: jal         0x800B28C4
    // 0x80106290: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    vector_begin(rdram, ctx);
        goto after_8;
    // 0x80106290: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    after_8:
    // 0x80106294: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x80106298: beq         $at, $zero, L_801062FC
    if (ctx->r1 == 0) {
        // 0x8010629C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_801062FC;
    }
    // 0x8010629C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801062A0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x801062A4: addiu       $s2, $s2, 0x4440
    ctx->r18 = ADD32(ctx->r18, 0X4440);
    // 0x801062A8: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_801062AC:
    // 0x801062AC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801062B0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801062B4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801062B8: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801062BC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801062C0: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x801062C4: jalr        $t9
    // 0x801062C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x801062C8: nop

    after_9:
    // 0x801062CC: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    // 0x801062D0: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x801062D4: bnel        $at, $zero, L_801062AC
    if (ctx->r1 != 0) {
        // 0x801062D8: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_801062AC;
    }
    goto skip_3;
    // 0x801062D8: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_3:
    // 0x801062DC: b           L_80106300
    // 0x801062E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80106300;
    // 0x801062E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801062E4:
    // 0x801062E4: lw          $t0, 0x70($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X70);
    // 0x801062E8: sll         $t2, $t0, 28
    ctx->r10 = S32(ctx->r8 << 28);
    // 0x801062EC: bgezl       $t2, L_80106300
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801062F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80106300;
    }
    goto skip_4;
    // 0x801062F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x801062F4: jal         0x8010381C
    // 0x801062F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010381C(rdram, ctx);
        goto after_10;
    // 0x801062F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_801062FC:
    // 0x801062FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80106300:
    // 0x80106300: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80106304: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80106308: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010630C: jr          $ra
    // 0x80106310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80106310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gsmaker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800118: jal         0x80800058
    // 0x8080011C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    gsmaker_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080011C: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    after_0:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void _chtntbox_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F50: syscall     481
    recomp_syscall_handler(rdram, ctx, 0x80086F50);
    return;
    // 0x80086F54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8009C030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C030: jr          $ra
    // 0x8009C034: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x8009C034: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _subaddiepalette_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A060: syscall     825
    recomp_syscall_handler(rdram, ctx, 0x8008A060);
    return;
    // 0x8008A064: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CC8: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CC8);
    return;
    // 0x80089CCC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8010CE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CE28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CE2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010CE30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CE34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010CE38: addiu       $a1, $a1, 0x6F50
    ctx->r5 = ADD32(ctx->r5, 0X6F50);
    // 0x8010CE3C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8010CE40: jal         0x800F18FC
    // 0x8010CE44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F18FC(rdram, ctx);
        goto after_0;
    // 0x8010CE44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8010CE48: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CE4C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8010CE50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010CE54: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8010CE58: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010CE5C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8010CE60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CE64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CE68: jr          $ra
    // 0x8010CE6C: nop

    return;
    // 0x8010CE6C: nop

;}
