#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void boot_osStartThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80800070_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: jal         0x80800040
    // 0x8080007C: nop

    func_80800040_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x8080007C: nop

    after_0:
    // 0x80800080: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_80801804_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80801804_chstatueboss");
    // 0x80801804: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80801808: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8080180C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80801810: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x80801814: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801818: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8080181C: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80801820: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80801824: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80801828: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8080182C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80801830: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80801834: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80801838: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8080183C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801840: jal         0x80100094
    // 0x80801844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801848: lh          $t6, 0x84($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X84);
    // 0x8080184C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80801850: jal         0x800F54E4
    // 0x80801854: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80801854: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80801858: jal         0x800F6438
    // 0x8080185C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_2;
    // 0x8080185C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801860: beql        $v0, $zero, L_80801A38
    if (ctx->r2 == 0) {
        // 0x80801864: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80801A38;
    }
    goto skip_0;
    // 0x80801864: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80801868: jal         0x8010CD28
    // 0x8080186C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8010CD28(rdram, ctx);
        goto after_3;
    // 0x8080186C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80801870: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X2560) << 16);
    // 0x80801874: lwc1        $f26, 0x2560($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X2560));
    // 0x80801878: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8080187C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801880: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X2564) << 16);
    // 0x80801884: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801888: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8080188C: lwc1        $f22, 0x2564($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X2564));
    // 0x80801890: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801894: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80801898: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8080189C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_808018A0:
    // 0x808018A0: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
    // 0x808018A4: beq         $v0, $s6, L_808018BC
    if (ctx->r2 == ctx->r22) {
        // 0x808018A8: nop
    
            goto L_808018BC;
    }
    // 0x808018A8: nop

    // 0x808018AC: beq         $v0, $s3, L_808018F4
    if (ctx->r2 == ctx->r19) {
        // 0x808018B0: nop
    
            goto L_808018F4;
    }
    // 0x808018B0: nop

    // 0x808018B4: b           L_80801928
    // 0x808018B8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
        goto L_80801928;
    // 0x808018B8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_808018BC:
    // 0x808018BC: jal         0x800D90A4
    // 0x808018C0: addiu       $a0, $s0, 0xA4
    ctx->r4 = ADD32(ctx->r16, 0XA4);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x808018C0: addiu       $a0, $s0, 0xA4
    ctx->r4 = ADD32(ctx->r16, 0XA4);
    after_4:
    // 0x808018C4: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x808018C8: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x808018CC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808018D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808018D4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808018D8: jal         0x800F10B4
    // 0x808018DC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808018DC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_5:
    // 0x808018E0: beq         $s1, $zero, L_80801924
    if (ctx->r17 == 0) {
        // 0x808018E4: swc1        $f0, 0xA8($s0)
        MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
            goto L_80801924;
    }
    // 0x808018E4: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    // 0x808018E8: sw          $s3, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r19;
    // 0x808018EC: b           L_80801924
    // 0x808018F0: swc1        $f22, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f22.u32l;
        goto L_80801924;
    // 0x808018F0: swc1        $f22, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f22.u32l;
L_808018F4:
    // 0x808018F4: jal         0x800D90A4
    // 0x808018F8: addiu       $a0, $s0, 0xA4
    ctx->r4 = ADD32(ctx->r16, 0XA4);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x808018F8: addiu       $a0, $s0, 0xA4
    ctx->r4 = ADD32(ctx->r16, 0XA4);
    after_6:
    // 0x808018FC: lwc1        $f12, 0xA4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80801900: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801904: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801908: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080190C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80801910: jal         0x800F10B4
    // 0x80801914: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80801914: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_7:
    // 0x80801918: beq         $s1, $zero, L_80801924
    if (ctx->r17 == 0) {
        // 0x8080191C: swc1        $f0, 0xA8($s0)
        MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
            goto L_80801924;
    }
    // 0x8080191C: swc1        $f0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f0.u32l;
    // 0x80801920: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
L_80801924:
    // 0x80801924: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_80801928:
    // 0x80801928: slti        $at, $s2, 0x48
    ctx->r1 = SIGNED(ctx->r18) < 0X48 ? 1 : 0;
    // 0x8080192C: bne         $at, $zero, L_808018A0
    if (ctx->r1 != 0) {
        // 0x80801930: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808018A0;
    }
    // 0x80801930: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80801934: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80801938: beql        $t7, $zero, L_80801A38
    if (ctx->r15 == 0) {
        // 0x8080193C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80801A38;
    }
    goto skip_1;
    // 0x8080193C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x80801940: jal         0x8010D248
    // 0x80801944: nop

    func_8010D248(rdram, ctx);
        goto after_8;
    // 0x80801944: nop

    after_8:
    // 0x80801948: beql        $v0, $zero, L_80801A38
    if (ctx->r2 == 0) {
        // 0x8080194C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80801A38;
    }
    goto skip_2;
    // 0x8080194C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x80801950: jal         0x8008FE68
    // 0x80801954: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_8008FE68(rdram, ctx);
        goto after_9;
    // 0x80801954: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_9:
    // 0x80801958: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    // 0x8080195C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1312, 0X25FC) << 16);
    // 0x80801960: addiu       $t9, $t9, 0x25FC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1312, 0X25FC));
    // 0x80801964: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x80801968: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8080196C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80801970: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801974: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x80801978: beq         $t1, $at, L_80801A34
    if (ctx->r9 == ctx->r1) {
        // 0x8080197C: addu        $s2, $t2, $t9
        ctx->r18 = ADD32(ctx->r10, ctx->r25);
            goto L_80801A34;
    }
    // 0x8080197C: addu        $s2, $t2, $t9
    ctx->r18 = ADD32(ctx->r10, ctx->r25);
    // 0x80801980: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80801984: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801988: lh          $v1, 0x0($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X0);
    // 0x8080198C: addiu       $s3, $sp, 0x90
    ctx->r19 = ADD32(ctx->r29, 0X90);
    // 0x80801990: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
L_80801994:
    // 0x80801994: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80801998: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8080199C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808019A0: addu        $s0, $s5, $t3
    ctx->r16 = ADD32(ctx->r21, ctx->r11);
    // 0x808019A4: jal         0x800D9078
    // 0x808019A8: addiu       $a0, $s0, 0xA4
    ctx->r4 = ADD32(ctx->r16, 0XA4);
    func_800D9078(rdram, ctx);
        goto after_10;
    // 0x808019A8: addiu       $a0, $s0, 0xA4
    ctx->r4 = ADD32(ctx->r16, 0XA4);
    after_10:
    // 0x808019AC: lw          $t4, 0xA0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XA0);
    // 0x808019B0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808019B4: bnel        $t4, $zero, L_80801A24
    if (ctx->r12 != 0) {
        // 0x808019B8: lh          $v1, 0x2($s2)
        ctx->r3 = MEM_H(ctx->r18, 0X2);
            goto L_80801A24;
    }
    goto skip_3;
    // 0x808019B8: lh          $v1, 0x2($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X2);
    skip_3:
    // 0x808019BC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x808019C0: jal         0x8008A0E0
    // 0x808019C4: lh          $a1, 0x0($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808019C4: lh          $a1, 0x0($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X0);
    after_11:
    // 0x808019C8: beq         $v0, $zero, L_80801A20
    if (ctx->r2 == 0) {
        // 0x808019CC: addiu       $a0, $s4, 0x4
        ctx->r4 = ADD32(ctx->r20, 0X4);
            goto L_80801A20;
    }
    // 0x808019CC: addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    // 0x808019D0: jal         0x800F1DF4
    // 0x808019D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_12;
    // 0x808019D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x808019D8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808019DC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808019E0: jal         0x800F20BC
    // 0x808019E4: lwc1        $f14, 0x8C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X8C);
    func_800F20BC(rdram, ctx);
        goto after_13;
    // 0x808019E4: lwc1        $f14, 0x8C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X8C);
    after_13:
    // 0x808019E8: beq         $v0, $zero, L_80801A20
    if (ctx->r2 == 0) {
        // 0x808019EC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80801A20;
    }
    // 0x808019EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808019F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808019F4: jal         0x80108B04
    // 0x808019F8: addiu       $s1, $s5, 0x90
    ctx->r17 = ADD32(ctx->r21, 0X90);
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x808019F8: addiu       $s1, $s5, 0x90
    ctx->r17 = ADD32(ctx->r21, 0X90);
    after_14:
    // 0x808019FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801A00: jal         0x800EE7F8
    // 0x80801A04: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80801A04: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x80801A08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801A0C: jal         0x800F1DF4
    // 0x80801A10: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800F1DF4(rdram, ctx);
        goto after_16;
    // 0x80801A10: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_16:
    // 0x80801A14: swc1        $f0, 0x9C($s5)
    MEM_W(0X9C, ctx->r21) = ctx->f0.u32l;
    // 0x80801A18: swc1        $f26, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f26.u32l;
    // 0x80801A1C: sw          $s6, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r22;
L_80801A20:
    // 0x80801A20: lh          $v1, 0x2($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X2);
L_80801A24:
    // 0x80801A24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801A28: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80801A2C: bnel        $v1, $at, L_80801994
    if (ctx->r3 != ctx->r1) {
        // 0x80801A30: addiu       $v0, $v1, -0x4
        ctx->r2 = ADD32(ctx->r3, -0X4);
            goto L_80801994;
    }
    goto skip_4;
    // 0x80801A30: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    skip_4:
L_80801A34:
    // 0x80801A34: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80801A38:
    // 0x80801A38: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801A3C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801A40: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80801A44: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80801A48: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80801A4C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80801A50: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80801A54: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80801A58: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80801A5C: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80801A60: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80801A64: jr          $ra
    // 0x80801A68: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80801A68: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800A5EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5EC4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A5EC8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800A5ECC: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800A5ED0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A5ED4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800A5ED8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800A5EDC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800A5EE0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A5EE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A5EE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A5EEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A5EF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A5EF4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800A5EF8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800A5EFC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800A5F00: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800A5F04: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A5F08: beq         $fp, $zero, L_800A61A4
    if (ctx->r30 == 0) {
        // 0x800A5F0C: or          $t6, $a0, $zero
        ctx->r14 = ctx->r4 | 0;
            goto L_800A61A4;
    }
    // 0x800A5F0C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800A5F10: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x800A5F14: addiu       $fp, $fp, 0xF
    ctx->r30 = ADD32(ctx->r30, 0XF);
    // 0x800A5F18: andi        $t7, $fp, 0xFFF0
    ctx->r15 = ctx->r30 & 0XFFF0;
    // 0x800A5F1C: beq         $a2, $zero, L_800A61A4
    if (ctx->r6 == 0) {
        // 0x800A5F20: or          $fp, $t7, $zero
        ctx->r30 = ctx->r15 | 0;
            goto L_800A61A4;
    }
    // 0x800A5F20: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800A5F24: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x800A5F28: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x800A5F2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A5F30: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A5F34: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800A5F38: lui         $t6, 0x12
    ctx->r14 = S32(0X12 << 16);
    // 0x800A5F3C: addiu       $t6, $t6, -0x5D08
    ctx->r14 = ADD32(ctx->r14, -0X5D08);
    // 0x800A5F40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A5F44: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800A5F48: bne         $fp, $zero, L_800A5F54
    if (ctx->r30 != 0) {
        // 0x800A5F4C: nop
    
            goto L_800A5F54;
    }
    // 0x800A5F4C: nop

    // 0x800A5F50: break       7
    do_break(2148163408);
L_800A5F54:
    // 0x800A5F54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A5F58: bne         $fp, $at, L_800A5F6C
    if (ctx->r30 != ctx->r1) {
        // 0x800A5F5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A5F6C;
    }
    // 0x800A5F5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5F60: bne         $t8, $at, L_800A5F6C
    if (ctx->r24 != ctx->r1) {
        // 0x800A5F64: nop
    
            goto L_800A5F6C;
    }
    // 0x800A5F64: nop

    // 0x800A5F68: break       6
    do_break(2148163432);
L_800A5F6C:
    // 0x800A5F6C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A5F70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A5F74: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A5F78: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x800A5F7C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A5F80: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800A5F84: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A5F88: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A5F8C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800A5F90: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800A5F94: mflo        $t1
    ctx->r9 = lo;
    // 0x800A5F98: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800A5F9C: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x800A5FA0: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800A5FA4: mflo        $t8
    ctx->r24 = lo;
    // 0x800A5FA8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800A5FAC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A5FB0: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x800A5FB4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800A5FB8: ori         $t6, $t6, 0x12F
    ctx->r14 = ctx->r14 | 0X12F;
    // 0x800A5FBC: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x800A5FC0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800A5FC4: addu        $s1, $s0, $a2
    ctx->r17 = ADD32(ctx->r16, ctx->r6);
    // 0x800A5FC8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A5FCC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x800A5FD0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800A5FD4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800A5FD8: jal         0x8002E330
    // 0x800A5FDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800A5FDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800A5FE0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800A5FE4: addiu       $a1, $fp, 0x7
    ctx->r5 = ADD32(ctx->r30, 0X7);
    // 0x800A5FE8: sra         $t7, $a1, 3
    ctx->r15 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800A5FEC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800A5FF0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800A5FF4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800A5FF8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A5FFC: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x800A6000: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x800A6004: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800A6008: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x800A600C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800A6010: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800A6014: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A6018: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800A601C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800A6020: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800A6024: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800A6028: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A602C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800A6030: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800A6034: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800A6038: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800A603C: beq         $at, $zero, L_800A6180
    if (ctx->r1 == 0) {
        // 0x800A6040: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800A6180;
    }
    // 0x800A6040: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A6044: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800A6048: addu        $a0, $a3, $fp
    ctx->r4 = ADD32(ctx->r7, ctx->r30);
    // 0x800A604C: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x800A6050: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x800A6054: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800A6058: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800A605C: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x800A6060: or          $s1, $t6, $at
    ctx->r17 = ctx->r14 | ctx->r1;
    // 0x800A6064: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800A6068: sll         $s4, $t8, 12
    ctx->r20 = S32(ctx->r24 << 12);
    // 0x800A606C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800A6070: or          $s2, $s4, $at
    ctx->r18 = ctx->r20 | ctx->r1;
    // 0x800A6074: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x800A6078: or          $s3, $t6, $at
    ctx->r19 = ctx->r14 | ctx->r1;
    // 0x800A607C: sll         $s5, $a0, 2
    ctx->r21 = S32(ctx->r4 << 2);
    // 0x800A6080: andi        $t6, $s5, 0xFFF
    ctx->r14 = ctx->r21 & 0XFFF;
    // 0x800A6084: sll         $s6, $a3, 2
    ctx->r22 = S32(ctx->r7 << 2);
    // 0x800A6088: andi        $t9, $s6, 0xFFF
    ctx->r25 = ctx->r22 & 0XFFF;
    // 0x800A608C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800A6090: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800A6094: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800A6098: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x800A609C: or          $s5, $t7, $at
    ctx->r21 = ctx->r15 | ctx->r1;
    // 0x800A60A0: sll         $s6, $t9, 12
    ctx->r22 = S32(ctx->r25 << 12);
    // 0x800A60A4: sll         $s7, $a3, 21
    ctx->r23 = S32(ctx->r7 << 21);
    // 0x800A60A8: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x800A60AC: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x800A60B0: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
L_800A60B4:
    // 0x800A60B4: subu        $v0, $t2, $s0
    ctx->r2 = SUB32(ctx->r10, ctx->r16);
    // 0x800A60B8: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A60BC: beq         $at, $zero, L_800A60C8
    if (ctx->r1 == 0) {
        // 0x800A60C0: sll         $a1, $s0, 2
        ctx->r5 = S32(ctx->r16 << 2);
            goto L_800A60C8;
    }
    // 0x800A60C0: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x800A60C4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_800A60C8:
    // 0x800A60C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A60CC: addu        $t0, $s0, $t1
    ctx->r8 = ADD32(ctx->r16, ctx->r9);
    // 0x800A60D0: addiu       $a2, $t0, -0x1
    ctx->r6 = ADD32(ctx->r8, -0X1);
    // 0x800A60D4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A60D8: andi        $t9, $a1, 0xFFF
    ctx->r25 = ctx->r5 & 0XFFF;
    // 0x800A60DC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800A60E0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800A60E4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800A60E8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800A60EC: or          $t6, $s1, $t9
    ctx->r14 = ctx->r17 | ctx->r25;
    // 0x800A60F0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800A60F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A60F8: or          $t9, $s2, $t8
    ctx->r25 = ctx->r18 | ctx->r24;
    // 0x800A60FC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A6100: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800A6104: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800A6108: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A610C: or          $t7, $s4, $t8
    ctx->r15 = ctx->r20 | ctx->r24;
    // 0x800A6110: or          $t6, $s3, $a1
    ctx->r14 = ctx->r19 | ctx->r5;
    // 0x800A6114: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800A6118: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800A611C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A6120: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800A6124: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800A6128: or          $t6, $s5, $t9
    ctx->r14 = ctx->r21 | ctx->r25;
    // 0x800A612C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A6130: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800A6134: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A6138: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A613C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800A6140: or          $t9, $s6, $t8
    ctx->r25 = ctx->r22 | ctx->r24;
    // 0x800A6144: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800A6148: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x800A614C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A6150: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800A6154: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A6158: or          $t8, $s7, $t7
    ctx->r24 = ctx->r23 | ctx->r15;
    // 0x800A615C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800A6160: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A6164: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800A6168: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A616C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800A6170: sw          $ra, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r31;
    // 0x800A6174: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800A6178: bne         $at, $zero, L_800A60B4
    if (ctx->r1 != 0) {
        // 0x800A617C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800A60B4;
    }
    // 0x800A617C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800A6180:
    // 0x800A6180: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A6184: lui         $t6, 0x12
    ctx->r14 = S32(0X12 << 16);
    // 0x800A6188: addiu       $t6, $t6, -0x5CB0
    ctx->r14 = ADD32(ctx->r14, -0X5CB0);
    // 0x800A618C: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800A6190: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A6194: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A6198: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A619C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800A61A0: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
L_800A61A4:
    // 0x800A61A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A61A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A61AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A61B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A61B4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A61B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A61BC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800A61C0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800A61C4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800A61C8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800A61CC: jr          $ra
    // 0x800A61D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A61D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80801758_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080175C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801760: jal         0x80100094
    // 0x80801764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801768: jal         0x80089998
    // 0x8080176C: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    _sumultiscore_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080176C: addiu       $a0, $v0, 0x14
    ctx->r4 = ADD32(ctx->r2, 0X14);
    after_1:
    // 0x80801770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801778: jr          $ra
    // 0x8080177C: nop

    return;
    // 0x8080177C: nop

;}
RECOMP_FUNC void func_80098634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098634: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x80098638: jr          $ra
    // 0x8009863C: lbu         $v0, 0x2F($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2F);
    return;
    // 0x8009863C: lbu         $v0, 0x2F($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2F);
;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835E0: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835E0);
    return;
    // 0x800835E4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chbouncycastle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1000, 0X978) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X978));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X978));
;}
RECOMP_FUNC void func_80800078_chbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80800084: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800088: bltzl       $t8, L_808000C0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080008C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800090: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
    // 0x80800094: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800098: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8080009C: beq         $a1, $at, L_808000B4
    if (ctx->r5 == ctx->r1) {
        // 0x808000A0: nop
    
            goto L_808000B4;
    }
    // 0x808000A0: nop

    // 0x808000A4: jal         0x80089F40
    // 0x808000A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiesect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808000A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000AC: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x808000B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000BC;
    }
    // 0x808000B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808000B4:
    // 0x808000B4: jal         0x80800180
    // 0x808000B8: nop

    func_80800180_chbeehive(rdram, ctx);
        goto after_1;
    // 0x808000B8: nop

    after_1:
L_808000BC:
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C0:
    // 0x808000C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_800F911C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F911C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9120: addiu       $v0, $v0, 0x54F8
    ctx->r2 = ADD32(ctx->r2, 0X54F8);
    // 0x800F9124: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800F9128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F912C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F9130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9134: bne         $t6, $at, L_800F914C
    if (ctx->r14 != ctx->r1) {
        // 0x800F9138: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800F914C;
    }
    // 0x800F9138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F913C: jal         0x800CF840
    // 0x800F9140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CF840(rdram, ctx);
        goto after_0;
    // 0x800F9140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800F9144: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9148: addiu       $v0, $v0, 0x54F8
    ctx->r2 = ADD32(ctx->r2, 0X54F8);
L_800F914C:
    // 0x800F914C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800F9150: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F9154: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800F9158: bne         $t8, $at, L_800F9168
    if (ctx->r24 != ctx->r1) {
        // 0x800F915C: sb          $t7, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r15;
            goto L_800F9168;
    }
    // 0x800F915C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x800F9160: jal         0x800CF840
    // 0x800F9164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CF840(rdram, ctx);
        goto after_1;
    // 0x800F9164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_800F9168:
    // 0x800F9168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F916C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9170: jr          $ra
    // 0x800F9174: nop

    return;
    // 0x800F9174: nop

;}
RECOMP_FUNC void func_808002A4_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: jal         0x80083800
    // 0x808002B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsmum_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808002B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002B8: jal         0x8080011C
    // 0x808002BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080011C_bsmumstill(rdram, ctx);
        goto after_1;
    // 0x808002BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void func_808000F0_gcsectionDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2666, 0X216) << 16);
    // 0x808000F4: lh          $t7, 0x216($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(2666, 0X216));
    // 0x808000F8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2666, 0X216) << 16);
    // 0x808000FC: addiu       $t6, $t6, 0x216
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2666, 0X216));
    // 0x80800100: beq         $t7, $zero, L_8080012C
    if (ctx->r15 == 0) {
        // 0x80800104: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8080012C;
    }
    // 0x80800104: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80800108: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
L_8080010C:
    // 0x8080010C: bnel        $a0, $v0, L_80800120
    if (ctx->r4 != ctx->r2) {
        // 0x80800110: lh          $v0, 0x6($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X6);
            goto L_80800120;
    }
    goto skip_0;
    // 0x80800110: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    skip_0:
    // 0x80800114: jr          $ra
    // 0x80800118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080011C: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
L_80800120:
    // 0x80800120: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80800124: bne         $v0, $zero, L_8080010C
    if (ctx->r2 != 0) {
        // 0x80800128: nop
    
            goto L_8080010C;
    }
    // 0x80800128: nop

L_8080012C:
    // 0x8080012C: beq         $a1, $zero, L_8080013C
    if (ctx->r5 == 0) {
        // 0x80800130: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080013C;
    }
    // 0x80800130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800134: jr          $ra
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080013C:
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_800BC3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC3B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC3BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC3C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BC3C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BC3C8: jal         0x800BC358
    // 0x800BC3CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800BC358(rdram, ctx);
        goto after_0;
    // 0x800BC3CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x800BC3D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BC3D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC3D8: jal         0x800BC358
    // 0x800BC3DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BC358(rdram, ctx);
        goto after_1;
    // 0x800BC3DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800BC3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC3E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BC3E8: jr          $ra
    // 0x800BC3EC: nop

    return;
    // 0x800BC3EC: nop

;}
RECOMP_FUNC void func_800C5B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5B8C: jal         0x800C5A10
    // 0x800C5B90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C5A10(rdram, ctx);
        goto after_0;
    // 0x800C5B90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800C5B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C5B9C: jr          $ra
    // 0x800C5BA0: nop

    return;
    // 0x800C5BA0: nop

;}
RECOMP_FUNC void func_80800000_chping(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800004: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8080000C: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80800010: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800014: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800018: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8080001C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80800020: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80800024: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80800028: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8080002C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800030: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800034: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800038: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8080003C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800040: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800044: jal         0x80100094
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080004C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800050: jal         0x801039E4
    // 0x80800054: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x80800054: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_1:
    // 0x80800058: addiu       $s6, $sp, 0x84
    ctx->r22 = ADD32(ctx->r29, 0X84);
    // 0x8080005C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800060: jal         0x800E3A58
    // 0x80800064: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E3A58(rdram, ctx);
        goto after_2;
    // 0x80800064: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x80800068: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080006C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800070: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2144, 0X400) << 16);
    // 0x80800074: lwc1        $f28, 0x400($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2144, 0X400));
    // 0x80800078: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080007C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800080: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800084: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800088: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8080008C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_80800090:
    // 0x80800090: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800094: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800098: mul.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8080009C: sub.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x808000A0: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    // 0x808000A4: nop

    // 0x808000A8: bc1tl       L_80800170
    if (c1cs) {
        // 0x808000AC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800170;
    }
    goto skip_0;
    // 0x808000AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808000B0: c.lt.s      $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f24.fl < ctx->f12.fl;
    // 0x808000B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000B8: addiu       $s1, $s4, 0x4
    ctx->r17 = ADD32(ctx->r20, 0X4);
    // 0x808000BC: bc1tl       L_80800170
    if (c1cs) {
        // 0x808000C0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800170;
    }
    goto skip_1;
    // 0x808000C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x808000C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000C8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808000CC: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x808000D0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x808000D4: jal         0x800F10B4
    // 0x808000D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808000D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x808000DC: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x808000E0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808000E4: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x808000E8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x808000EC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x808000F0: jal         0x800F10B4
    // 0x808000F4: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808000F4: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_4:
    // 0x808000F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800100: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800104: jal         0x800F0F9C
    // 0x80800108: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    func_800F0F9C(rdram, ctx);
        goto after_5;
    // 0x80800108: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    after_5:
    // 0x8080010C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800110: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800114: nop

    // 0x80800118: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080011C: jal         0x80013970
    // 0x80800120: nop

    func_80013970(rdram, ctx);
        goto after_6;
    // 0x80800120: nop

    after_6:
    // 0x80800124: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800128: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8080012C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800130: nop

    // 0x80800134: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80800138: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080013C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800140: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80800144: jal         0x800DF410
    // 0x80800148: nop

    func_800DF410(rdram, ctx);
        goto after_7;
    // 0x80800148: nop

    after_7:
    // 0x8080014C: jal         0x800DF830
    // 0x80800150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_8;
    // 0x80800150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80800154: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80800158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080015C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800160: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800164: jal         0x800DE448
    // 0x80800168: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_800DE448(rdram, ctx);
        goto after_9;
    // 0x80800168: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_9:
    // 0x8080016C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800170:
    // 0x80800170: bnel        $s0, $s3, L_80800090
    if (ctx->r16 != ctx->r19) {
        // 0x80800174: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_80800090;
    }
    goto skip_2;
    // 0x80800174: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_2:
    // 0x80800178: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8080017C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800180: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800184: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800188: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8080018C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80800190: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80800194: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800198: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8080019C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x808001A0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x808001A4: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x808001A8: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x808001AC: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x808001B0: jr          $ra
    // 0x808001B4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808001B4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void ncfixposrot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: jal         0x8001B084
    // 0x8080004C: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x8080004C: nop

    after_0:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void func_8008D568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D570: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D574: jal         0x800C6E38
    // 0x8008D578: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D578: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_0:
    // 0x8008D57C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D580: beq         $t6, $zero, L_8008D5B4
    if (ctx->r14 == 0) {
        // 0x8008D584: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D5B4;
    }
    // 0x8008D584: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D588: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D58C: jal         0x80095748
    // 0x8008D590: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_isFalse(rdram, ctx);
        goto after_1;
    // 0x8008D590: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x8008D594: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D598: beq         $t7, $zero, L_8008D5B4
    if (ctx->r15 == 0) {
        // 0x8008D59C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008D5B4;
    }
    // 0x8008D59C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008D5A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D5A4: jal         0x80095748
    // 0x8008D5A8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_isFalse(rdram, ctx);
        goto after_2;
    // 0x8008D5A8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_2:
    // 0x8008D5AC: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D5B0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8008D5B4:
    // 0x8008D5B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D5B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D5BC: jr          $ra
    // 0x8008D5C0: nop

    return;
    // 0x8008D5C0: nop

;}
RECOMP_FUNC void func_8080613C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080613C: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80806140: jr          $ra
    // 0x80806144: lwc1        $f0, 0x1C4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C4);
    return;
    // 0x80806144: lwc1        $f0, 0x1C4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C4);
;}
RECOMP_FUNC void func_8010DEFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DEFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010DF00: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010DF04: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010DF08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010DF0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010DF10: addiu       $s1, $zero, 0xB
    ctx->r17 = ADD32(0, 0XB);
L_8010DF14:
    // 0x8010DF14: jal         0x80104148
    // 0x8010DF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104148(rdram, ctx);
        goto after_0;
    // 0x8010DF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010DF1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8010DF20: bne         $s0, $s1, L_8010DF14
    if (ctx->r16 != ctx->r17) {
        // 0x8010DF24: sb          $zero, 0x5($v0)
        MEM_B(0X5, ctx->r2) = 0;
            goto L_8010DF14;
    }
    // 0x8010DF24: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8010DF28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010DF2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010DF30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010DF34: jr          $ra
    // 0x8010DF38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010DF38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800024_chgoldsnakehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800028: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800038: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080003C: jal         0x80088280
    // 0x80800040: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    after_0:
    // 0x80800044: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800048: jal         0x800DA298
    // 0x8080004C: addiu       $a0, $zero, 0x18B
    ctx->r4 = ADD32(0, 0X18B);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a0, $zero, 0x18B
    ctx->r4 = ADD32(0, 0X18B);
    after_1:
    // 0x80800050: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x80800054: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800068;
    }
    // 0x80800054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800058: jal         0x800FFAB0
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800060: b           L_8080014C
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080014C;
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800068:
    // 0x80800068: jal         0x80088C00
    // 0x8080006C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080006C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800070: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800074: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800078: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x8080007C: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    // 0x80800080: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800084: nop

    // 0x80800088: bc1fl       L_808000FC
    if (!c1cs) {
        // 0x8080008C: lhu         $t0, 0x76($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X76);
            goto L_808000FC;
    }
    goto skip_0;
    // 0x8080008C: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80800090: jal         0x80089C30
    // 0x80800094: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800094: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800098: beql        $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x8080009C: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_808000D8;
    }
    goto skip_1;
    // 0x8080009C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x808000A0: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
L_808000A4:
    // 0x808000A4: lhu         $t8, 0x76($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X76);
    // 0x808000A8: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    // 0x808000AC: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000B0: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808000B4: bne         $t7, $t9, L_808000C4
    if (ctx->r15 != ctx->r25) {
        // 0x808000B8: nop
    
            goto L_808000C4;
    }
    // 0x808000B8: nop

    // 0x808000BC: bnel        $v0, $s0, L_808000D8
    if (ctx->r2 != ctx->r16) {
        // 0x808000C0: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_808000D8;
    }
    goto skip_2;
    // 0x808000C0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_2:
L_808000C4:
    // 0x808000C4: jal         0x80089C38
    // 0x808000C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808000C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808000CC: bnel        $v0, $zero, L_808000A4
    if (ctx->r2 != 0) {
        // 0x808000D0: lhu         $t6, 0x76($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X76);
            goto L_808000A4;
    }
    goto skip_3;
    // 0x808000D0: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    skip_3:
    // 0x808000D4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
L_808000D8:
    // 0x808000D8: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x808000DC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808000E0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x808000E4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000E8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808000EC: add.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x808000F0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808000F4: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x808000F8: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
L_808000FC:
    // 0x808000FC: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800100: slti        $at, $t1, 0x33
    ctx->r1 = SIGNED(ctx->r9) < 0X33 ? 1 : 0;
    // 0x80800104: bnel        $at, $zero, L_80800124
    if (ctx->r1 != 0) {
        // 0x80800108: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80800124;
    }
    goto skip_4;
    // 0x80800108: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x8080010C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800110: lbu         $t3, 0x2A($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800114: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80800118: b           L_80800130
    // 0x8080011C: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
        goto L_80800130;
    // 0x8080011C: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80800120: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80800124:
    // 0x80800124: lbu         $t5, 0x2A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800128: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x8080012C: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
L_80800130:
    // 0x80800130: jal         0x80103014
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_6;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800138: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800140: jal         0x800DA7A8
    // 0x80800144: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_7;
    // 0x80800144: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080014C:
    // 0x8080014C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800158: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800BA610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA61C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BA620: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BA624: lh          $a2, 0x1E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X1E);
    // 0x800BA628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BA62C: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x800BA630: jal         0x800EFA6C
    // 0x800BA634: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800EFA6C(rdram, ctx);
        goto after_0;
    // 0x800BA634: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800BA638: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BA63C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BA640: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x800BA644: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BA648: jal         0x800EFA6C
    // 0x800BA64C: addiu       $a0, $a0, 0x3A
    ctx->r4 = ADD32(ctx->r4, 0X3A);
    func_800EFA6C(rdram, ctx);
        goto after_1;
    // 0x800BA64C: addiu       $a0, $a0, 0x3A
    ctx->r4 = ADD32(ctx->r4, 0X3A);
    after_1:
    // 0x800BA650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA658: jr          $ra
    // 0x800BA65C: nop

    return;
    // 0x800BA65C: nop

;}
RECOMP_FUNC void dbshift_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8080008C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80800090: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80800094: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8080009C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x808000A0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x808000A4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x808000A8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x808000AC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808000B0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808000B4: bltz        $a2, L_80800208
    if (SIGNED(ctx->r6) < 0) {
        // 0x808000B8: sdc1        $f20, 0x20($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
            goto L_80800208;
    }
    // 0x808000B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808000BC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808000C0: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x808000C4: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808000C8: beql        $at, $zero, L_8080020C
    if (ctx->r1 == 0) {
        // 0x808000CC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8080020C;
    }
    goto skip_0;
    // 0x808000CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x808000D0: blez        $a2, L_80800150
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808000D4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800150;
    }
    // 0x808000D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808000D8: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x808000DC: beq         $v1, $zero, L_80800104
    if (ctx->r3 == 0) {
        // 0x808000E0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800104;
    }
    // 0x808000E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808000E4:
    // 0x808000E4: lh          $t7, 0x1A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A);
    // 0x808000E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808000EC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x808000F0: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x808000F4: bne         $v0, $s2, L_808000E4
    if (ctx->r2 != ctx->r18) {
        // 0x808000F8: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_808000E4;
    }
    // 0x808000F8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x808000FC: beql        $s2, $a2, L_80800150
    if (ctx->r18 == ctx->r6) {
        // 0x80800100: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800150;
    }
    goto skip_1;
    // 0x80800100: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    skip_1:
L_80800104:
    // 0x80800104: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x80800108: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8080010C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80800110: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x80800114: lh          $t1, 0x36($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X36);
    // 0x80800118: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8080011C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80800120: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
    // 0x80800124: lh          $t3, 0x36($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X36);
    // 0x80800128: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8080012C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80800130: addu        $s0, $s0, $t4
    ctx->r16 = ADD32(ctx->r16, ctx->r12);
    // 0x80800134: lh          $t5, 0x36($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X36);
    // 0x80800138: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8080013C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80800140: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x80800144: bne         $s2, $a2, L_80800104
    if (ctx->r18 != ctx->r6) {
        // 0x80800148: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80800104;
    }
    // 0x80800148: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8080014C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800150:
    // 0x80800150: jal         0x800B2190
    // 0x80800154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B2190(rdram, ctx);
        goto after_0;
    // 0x80800154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800158: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8080015C: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x80800160: addiu       $s3, $s0, 0x1C
    ctx->r19 = ADD32(ctx->r16, 0X1C);
    // 0x80800164: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800168: blez        $t9, L_80800208
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8080016C: addu        $s1, $v0, $t8
        ctx->r17 = ADD32(ctx->r2, ctx->r24);
            goto L_80800208;
    }
    // 0x8080016C: addu        $s1, $v0, $t8
    ctx->r17 = ADD32(ctx->r2, ctx->r24);
    // 0x80800170: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80800174: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800178: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080017C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800180: addiu       $s4, $s0, 0x8
    ctx->r20 = ADD32(ctx->r16, 0X8);
    // 0x80800184: addiu       $s5, $sp, 0x58
    ctx->r21 = ADD32(ctx->r29, 0X58);
    // 0x80800188: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8080018C:
    // 0x8080018C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800190: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800194: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80800198: jal         0x80800000
    // 0x8080019C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_80800000_dbshift(rdram, ctx);
        goto after_1;
    // 0x8080019C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_1:
    // 0x808001A0: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808001A4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808001A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808001AC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x808001B0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x808001B4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808001B8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808001BC: sub.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x808001C0: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x808001C4: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808001C8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x808001CC: nop

    // 0x808001D0: sh          $t1, -0x8($s1)
    MEM_H(-0X8, ctx->r17) = ctx->r9;
    // 0x808001D4: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808001D8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808001DC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808001E0: sub.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x808001E4: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x808001E8: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808001EC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x808001F0: nop

    // 0x808001F4: sh          $t3, -0x6($s1)
    MEM_H(-0X6, ctx->r17) = ctx->r11;
    // 0x808001F8: lh          $t4, 0x1A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A);
    // 0x808001FC: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800200: bnel        $at, $zero, L_8080018C
    if (ctx->r1 != 0) {
        // 0x80800204: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080018C;
    }
    goto skip_2;
    // 0x80800204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
L_80800208:
    // 0x80800208: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8080020C:
    // 0x8080020C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800210: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800214: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800218: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8080021C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800220: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800224: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800228: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8080022C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80800230: jr          $ra
    // 0x80800234: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800234: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800238: nop

    // 0x8080023C: nop

;}
RECOMP_FUNC void func_80104E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104E78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80104E7C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80104E80: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80104E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104E88: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80104E8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80104E90: jal         0x800EE7F8
    // 0x80104E94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80104E94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80104E98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80104E9C: jal         0x800EE7F8
    // 0x80104EA0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80104EA0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80104EA4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80104EA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80104EAC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80104EB0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80104EB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80104EB8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80104EBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80104EC0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80104EC4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80104EC8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80104ECC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80104ED0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80104ED4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80104ED8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80104EDC: jal         0x800BEF00
    // 0x80104EE0: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80104EE0: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x80104EE4: beq         $v0, $zero, L_80104F08
    if (ctx->r2 == 0) {
        // 0x80104EE8: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80104F08;
    }
    // 0x80104EE8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80104EEC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80104EF0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80104EF4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80104EF8: jal         0x801045AC
    // 0x80104EFC: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    func_801045AC(rdram, ctx);
        goto after_3;
    // 0x80104EFC: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x80104F00: b           L_80104F1C
    // 0x80104F04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80104F1C;
    // 0x80104F04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80104F08:
    // 0x80104F08: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80104F0C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80104F10: jal         0x80089CF0
    // 0x80104F14: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x80104F14: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x80104F18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80104F1C:
    // 0x80104F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104F20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80104F24: jr          $ra
    // 0x80104F28: nop

    return;
    // 0x80104F28: nop

;}
RECOMP_FUNC void func_80801518_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801518: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080151C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801520: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801524: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801528: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080152C: jal         0x80100094
    // 0x80801530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801534: lh          $a2, 0x84($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X84);
    // 0x80801538: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1312, 0X25C0) << 16);
    // 0x8080153C: addiu       $t7, $t7, 0x25C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1312, 0X25C0));
    // 0x80801540: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80801544: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80801548: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080154C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80801550: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80801554: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080155C: beq         $a0, $t9, L_8080162C
    if (ctx->r4 == ctx->r25) {
        // 0x80801560: lh          $a1, 0x86($v0)
        ctx->r5 = MEM_H(ctx->r2, 0X86);
            goto L_8080162C;
    }
    // 0x80801560: lh          $a1, 0x86($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X86);
    // 0x80801564: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80801568: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8080156C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80801570: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x80801574: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_80801578:
    // 0x80801578: bne         $a1, $v1, L_8080161C
    if (ctx->r5 != ctx->r3) {
        // 0x8080157C: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_8080161C;
    }
    // 0x8080157C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80801580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801584: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80801588: addu        $t2, $s0, $a1
    ctx->r10 = ADD32(ctx->r16, ctx->r5);
    // 0x8080158C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80801590: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x80801594: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80801598: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x8080159C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808015A0: jal         0x800FC660
    // 0x808015A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_1;
    // 0x808015A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x808015A8: lh          $t5, 0x8A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8A);
    // 0x808015AC: addiu       $a1, $s0, 0xE8
    ctx->r5 = ADD32(ctx->r16, 0XE8);
    // 0x808015B0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x808015B4: sh          $t6, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r14;
    // 0x808015B8: jal         0x800EC398
    // 0x808015BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800EC398(rdram, ctx);
        goto after_2;
    // 0x808015BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x808015C0: lh          $t8, 0x88($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X88);
    // 0x808015C4: addiu       $a0, $zero, 0x681
    ctx->r4 = ADD32(0, 0X681);
    // 0x808015C8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808015CC: jal         0x800DA298
    // 0x808015D0: sh          $t9, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r25;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808015D0: sh          $t9, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r25;
    after_3:
    // 0x808015D4: bne         $v0, $zero, L_808015F0
    if (ctx->r2 != 0) {
        // 0x808015D8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808015F0;
    }
    // 0x808015D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808015DC: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x808015E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1312, 0X2644) << 16);
    // 0x808015E4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x808015E8: b           L_808015F4
    // 0x808015EC: lh          $v0, 0x2644($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1312, 0X2644));
        goto L_808015F4;
    // 0x808015EC: lh          $v0, 0x2644($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1312, 0X2644));
L_808015F0:
    // 0x808015F0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_808015F4:
    // 0x808015F4: lh          $t7, 0x88($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X88);
    // 0x808015F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808015FC: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x80801600: bne         $v0, $t7, L_8080162C
    if (ctx->r2 != ctx->r15) {
        // 0x80801604: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1312, 0X27E0) << 16);
            goto L_8080162C;
    }
    // 0x80801604: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1312, 0X27E0) << 16);
    // 0x80801608: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8080160C: jal         0x80800DA8
    // 0x80801610: lh          $a1, 0x27E0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1312, 0X27E0));
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_4;
    // 0x80801610: lh          $a1, 0x27E0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1312, 0X27E0));
    after_4:
    // 0x80801614: b           L_80801630
    // 0x80801618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801630;
    // 0x80801618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080161C:
    // 0x8080161C: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80801620: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80801624: bne         $a0, $v1, L_80801578
    if (ctx->r4 != ctx->r3) {
        // 0x80801628: nop
    
            goto L_80801578;
    }
    // 0x80801628: nop

L_8080162C:
    // 0x8080162C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801630:
    // 0x80801630: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801634: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801638: jr          $ra
    // 0x8080163C: nop

    return;
    // 0x8080163C: nop

;}
RECOMP_FUNC void func_80800F6C_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F74: jal         0x8080081C
    // 0x80800F78: nop

    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800F78: nop

    after_0:
    // 0x80800F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F84: jr          $ra
    // 0x80800F88: nop

    return;
    // 0x80800F88: nop

;}
RECOMP_FUNC void ncbastring_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080029C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A8: jal         0x8080007C
    // 0x808002AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_8080007C_ncbastring(rdram, ctx);
        goto after_0;
    // 0x808002AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x801107F0
    // 0x808002B8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x808002B8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x808002BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808002C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808002C4: jal         0x800EFB24
    // 0x808002C8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808002C8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x808002CC: jal         0x800EEF94
    // 0x808002D0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x808002D0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x808002D4: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808002E0: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x808002E4: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x808002E8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808002EC: jal         0x80115444
    // 0x808002F0: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    func_80115444(rdram, ctx);
        goto after_4;
    // 0x808002F0: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    after_4:
    // 0x808002F4: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x808002F8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808002FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800300: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800304: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800308: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080030C: nop

    // 0x80800310: bc1fl       L_80800330
    if (!c1cs) {
        // 0x80800314: lwc1        $f16, 0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80800330;
    }
    goto skip_0;
    // 0x80800314: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80800318: sb          $t8, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r24;
    // 0x8080031C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80800320: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800324: b           L_8080035C
    // 0x80800328: swc1        $f8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f8.u32l;
        goto L_8080035C;
    // 0x80800328: swc1        $f8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f8.u32l;
    // 0x8080032C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
L_80800330:
    // 0x80800330: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800334: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800338: nop

    // 0x8080033C: bc1fl       L_8080035C
    if (!c1cs) {
        // 0x80800340: sb          $zero, 0x8($v0)
        MEM_B(0X8, ctx->r2) = 0;
            goto L_8080035C;
    }
    goto skip_1;
    // 0x80800340: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    skip_1:
    // 0x80800344: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x80800348: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x8080034C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800350: b           L_8080035C
    // 0x80800354: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
        goto L_8080035C;
    // 0x80800354: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x80800358: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
L_8080035C:
    // 0x8080035C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800360: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800364: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800368: jr          $ra
    // 0x8080036C: nop

    return;
    // 0x8080036C: nop

;}
RECOMP_FUNC void func_8080065C_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800664: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XE04) << 16);
    // 0x80800668: lwc1        $f6, 0xE04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XE04));
    // 0x8080066C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800670: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800674: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800678: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080067C: jal         0x80102FDC
    // 0x80800680: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800680: nop

    after_0:
    // 0x80800684: jal         0x800DC0C0
    // 0x80800688: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800688: nop

    after_1:
    // 0x8080068C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800690: jal         0x80101EE4
    // 0x80800694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101EE4(rdram, ctx);
        goto after_2;
    // 0x80800694: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080069C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006A0: jr          $ra
    // 0x808006A4: nop

    return;
    // 0x808006A4: nop

;}
RECOMP_FUNC void bskazstill_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800748: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(288, 0X8B4) << 16);
    // 0x8080074C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800750: jr          $ra
    // 0x80800754: lw          $v0, 0x8B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8B4));
    return;
    // 0x80800754: lw          $v0, 0x8B4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(288, 0X8B4));
;}
RECOMP_FUNC void func_8008DAA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DAA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DAAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DAB0: jal         0x800F65D0
    // 0x8008DAB4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F65D0(rdram, ctx);
        goto after_0;
    // 0x8008DAB4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x8008DAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DAC0: jr          $ra
    // 0x8008DAC4: nop

    return;
    // 0x8008DAC4: nop

;}
RECOMP_FUNC void func_80001590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001590: addiu       $sp, $sp, -0xA90
    ctx->r29 = ADD32(ctx->r29, -0XA90);
    // 0x80001594: sw          $s0, 0xA48($sp)
    MEM_W(0XA48, ctx->r29) = ctx->r16;
    // 0x80001598: sw          $s1, 0xA4C($sp)
    MEM_W(0XA4C, ctx->r29) = ctx->r17;
    // 0x8000159C: sw          $s2, 0xA50($sp)
    MEM_W(0XA50, ctx->r29) = ctx->r18;
    // 0x800015A0: sw          $s3, 0xA54($sp)
    MEM_W(0XA54, ctx->r29) = ctx->r19;
    // 0x800015A4: sw          $s4, 0xA58($sp)
    MEM_W(0XA58, ctx->r29) = ctx->r20;
    // 0x800015A8: sw          $s5, 0xA5C($sp)
    MEM_W(0XA5C, ctx->r29) = ctx->r21;
    // 0x800015AC: sw          $s6, 0xA60($sp)
    MEM_W(0XA60, ctx->r29) = ctx->r22;
    // 0x800015B0: sw          $s7, 0xA64($sp)
    MEM_W(0XA64, ctx->r29) = ctx->r23;
    // 0x800015B4: sw          $ra, 0xA80($sp)
    MEM_W(0XA80, ctx->r29) = ctx->r31;
    // 0x800015B8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800015BC: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x800015C0: addiu       $s6, $s6, 0x6500
    ctx->r22 = ADD32(ctx->r22, 0X6500);
    // 0x800015C4: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x800015C8: addiu       $t2, $sp, 0x548
    ctx->r10 = ADD32(ctx->r29, 0X548);
    // 0x800015CC: addiu       $t1, $t2, 0x240
    ctx->r9 = ADD32(ctx->r10, 0X240);
L_800015D0:
    // 0x800015D0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800015D4: bne         $t2, $t1, L_800015D0
    if (ctx->r10 != ctx->r9) {
        // 0x800015D8: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_800015D0;
    }
    // 0x800015D8: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x800015DC: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800015E0: addiu       $t1, $t2, 0x1C0
    ctx->r9 = ADD32(ctx->r10, 0X1C0);
L_800015E4:
    // 0x800015E4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800015E8: bne         $t2, $t1, L_800015E4
    if (ctx->r10 != ctx->r9) {
        // 0x800015EC: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_800015E4;
    }
    // 0x800015EC: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x800015F0: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800015F4: addiu       $t1, $t2, 0x60
    ctx->r9 = ADD32(ctx->r10, 0X60);
L_800015F8:
    // 0x800015F8: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800015FC: bne         $t2, $t1, L_800015F8
    if (ctx->r10 != ctx->r9) {
        // 0x80001600: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_800015F8;
    }
    // 0x80001600: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x80001604: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80001608: addiu       $t1, $t2, 0x20
    ctx->r9 = ADD32(ctx->r10, 0X20);
L_8000160C:
    // 0x8000160C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80001610: bne         $t2, $t1, L_8000160C
    if (ctx->r10 != ctx->r9) {
        // 0x80001614: sw          $t0, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r8;
            goto L_8000160C;
    }
    // 0x80001614: sw          $t0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r8;
    // 0x80001618: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8000161C: sw          $t0, 0x9CC($sp)
    MEM_W(0X9CC, ctx->r29) = ctx->r8;
    // 0x80001620: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x80001624: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x80001628: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x8000162C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80001630: addiu       $a3, $a3, 0x4322
    ctx->r7 = ADD32(ctx->r7, 0X4322);
    // 0x80001634: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80001638: addiu       $t7, $t7, 0x43AF
    ctx->r15 = ADD32(ctx->r15, 0X43AF);
    // 0x8000163C: addiu       $t8, $sp, 0x9C8
    ctx->r24 = ADD32(ctx->r29, 0X9C8);
    // 0x80001640: jal         0x80000E1C
    // 0x80001644: addiu       $t9, $sp, 0x9CC
    ctx->r25 = ADD32(ctx->r29, 0X9CC);
    boot_huft_build(rdram, ctx);
        goto after_0;
    // 0x80001644: addiu       $t9, $sp, 0x9CC
    ctx->r25 = ADD32(ctx->r29, 0X9CC);
    after_0:
    // 0x80001648: addiu       $t0, $sp, 0x548
    ctx->r8 = ADD32(ctx->r29, 0X548);
    // 0x8000164C: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80001650: addiu       $t2, $t0, 0x78
    ctx->r10 = ADD32(ctx->r8, 0X78);
L_80001654:
    // 0x80001654: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80001658: bne         $t0, $t2, L_80001654
    if (ctx->r8 != ctx->r10) {
        // 0x8000165C: sw          $t1, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r9;
            goto L_80001654;
    }
    // 0x8000165C: sw          $t1, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r9;
    // 0x80001660: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80001664: sw          $t0, 0x9D4($sp)
    MEM_W(0X9D4, ctx->r29) = ctx->r8;
    // 0x80001668: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x8000166C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80001670: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80001674: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80001678: addiu       $a3, $a3, 0x4360
    ctx->r7 = ADD32(ctx->r7, 0X4360);
    // 0x8000167C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80001680: addiu       $t7, $t7, 0x43CE
    ctx->r15 = ADD32(ctx->r15, 0X43CE);
    // 0x80001684: addiu       $t8, $sp, 0x9D0
    ctx->r24 = ADD32(ctx->r29, 0X9D0);
    // 0x80001688: jal         0x80000E1C
    // 0x8000168C: addiu       $t9, $sp, 0x9D4
    ctx->r25 = ADD32(ctx->r29, 0X9D4);
    boot_huft_build(rdram, ctx);
        goto after_1;
    // 0x8000168C: addiu       $t9, $sp, 0x9D4
    ctx->r25 = ADD32(ctx->r29, 0X9D4);
    after_1:
    // 0x80001690: lw          $s0, 0xA48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA48);
    // 0x80001694: lw          $s1, 0xA4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4C);
    // 0x80001698: lw          $s2, 0xA50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA50);
    // 0x8000169C: lw          $s3, 0xA54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA54);
    // 0x800016A0: lw          $s4, 0xA58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA58);
    // 0x800016A4: lw          $s5, 0xA5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA5C);
    // 0x800016A8: lw          $s6, 0xA60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA60);
    // 0x800016AC: lw          $s7, 0xA64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XA64);
    // 0x800016B0: lw          $ra, 0xA80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA80);
    // 0x800016B4: jr          $ra
    // 0x800016B8: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
    return;
    // 0x800016B8: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
;}
RECOMP_FUNC void func_800F2C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2C1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F2C20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F2C24: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F2C28: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F2C2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F2C30: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800F2C34: jal         0x800F2100
    // 0x800F2C38: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    mlAbsF(rdram, ctx);
        goto after_0;
    // 0x800F2C38: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    after_0:
    // 0x800F2C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F2C40: lwc1        $f4, 0x5EF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EF0);
    // 0x800F2C44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F2C48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F2C4C: nop

    // 0x800F2C50: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800F2C54: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800F2C58: nop

    // 0x800F2C5C: bc1fl       L_800F2C8C
    if (!c1cs) {
        // 0x800F2C60: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_800F2C8C;
    }
    goto skip_0;
    // 0x800F2C60: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x800F2C64: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800F2C68: jal         0x80013AAC
    // 0x800F2C6C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80013AAC(rdram, ctx);
        goto after_1;
    // 0x800F2C6C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x800F2C70: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x800F2C74: jal         0x800138D0
    // 0x800F2C78: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800138D0(rdram, ctx);
        goto after_2;
    // 0x800F2C78: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x800F2C7C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800F2C80: b           L_800F2CC4
    // 0x800F2C84: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800F2CC4;
    // 0x800F2C84: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800F2C88: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_800F2C8C:
    // 0x800F2C8C: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800F2C90: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x800F2C94: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x800F2C98: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x800F2C9C: nop

    // 0x800F2CA0: bc1fl       L_800F2CBC
    if (!c1cs) {
        // 0x800F2CA4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_800F2CBC;
    }
    goto skip_1;
    // 0x800F2CA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x800F2CA8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800F2CAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F2CB0: b           L_800F2CC4
    // 0x800F2CB4: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
        goto L_800F2CC4;
    // 0x800F2CB4: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x800F2CB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_800F2CBC:
    // 0x800F2CBC: nop

    // 0x800F2CC0: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
L_800F2CC4:
    // 0x800F2CC4: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x800F2CC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F2CCC: bc1t        L_800F2D0C
    if (c1cs) {
        // 0x800F2CD0: nop
    
            goto L_800F2D0C;
    }
    // 0x800F2CD0: nop

    // 0x800F2CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F2CD8: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800F2CDC: div.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F2CE0: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F2CE4: jal         0x80013AAC
    // 0x800F2CE8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80013AAC(rdram, ctx);
        goto after_3;
    // 0x800F2CE8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x800F2CEC: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2CF0: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800F2CF4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F2CF8: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F2CFC: jal         0x80013AAC
    // 0x800F2D00: nop

    func_80013AAC(rdram, ctx);
        goto after_4;
    // 0x800F2D00: nop

    after_4:
    // 0x800F2D04: b           L_800F2D20
    // 0x800F2D08: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
        goto L_800F2D20;
    // 0x800F2D08: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_800F2D0C:
    // 0x800F2D0C: jal         0x80013A7C
    // 0x800F2D10: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80013A7C(rdram, ctx);
        goto after_5;
    // 0x800F2D10: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x800F2D14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800F2D18: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800F2D1C: swc1        $f14, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f14.u32l;
L_800F2D20:
    // 0x800F2D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F2D24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F2D28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F2D2C: jr          $ra
    // 0x800F2D30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F2D30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800A40_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A40: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800A44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A48: jr          $ra
    // 0x80800A4C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800A4C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800DBFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBFF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DBFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC000: jal         0x8001ACCC
    // 0x800DC004: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800DC004: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_0:
    // 0x800DC008: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800DC00C: jal         0x800DBEB0
    // 0x800DC010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DBEB0(rdram, ctx);
        goto after_1;
    // 0x800DC010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800DC014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC018: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800DC01C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DC020: jr          $ra
    // 0x800DC024: nop

    return;
    // 0x800DC024: nop

;}
RECOMP_FUNC void func_800DBB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBB9C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DBBA0: lw          $a2, -0x3820($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3820);
    // 0x800DBBA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBBA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBBAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DBBB0: beq         $a2, $zero, L_800DBBE8
    if (ctx->r6 == 0) {
        // 0x800DBBB4: andi        $a3, $a0, 0xFF
        ctx->r7 = ctx->r4 & 0XFF;
            goto L_800DBBE8;
    }
    // 0x800DBBB4: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800DBBB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800DBBBC: jal         0x800B32C0
    // 0x800DBBC0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    freelist_erase(rdram, ctx);
        goto after_0;
    // 0x800DBBC0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800DBBC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DBBC8: jal         0x800B3204
    // 0x800DBBCC: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    freelist_used_count(rdram, ctx);
        goto after_1;
    // 0x800DBBCC: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    after_1:
    // 0x800DBBD0: bne         $v0, $zero, L_800DBBE8
    if (ctx->r2 != 0) {
        // 0x800DBBD4: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DBBE8;
    }
    // 0x800DBBD4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DBBD8: jal         0x800B3248
    // 0x800DBBDC: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    freelist_free(rdram, ctx);
        goto after_2;
    // 0x800DBBDC: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    after_2:
    // 0x800DBBE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DBBE4: sw          $zero, -0x3820($at)
    MEM_W(-0X3820, ctx->r1) = 0;
L_800DBBE8:
    // 0x800DBBE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBBEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBBF0: jr          $ra
    // 0x800DBBF4: nop

    return;
    // 0x800DBBF4: nop

;}
RECOMP_FUNC void func_80800664_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800668: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080066C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800670: jal         0x800D8FF8
    // 0x80800674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800678: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8080067C: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800680: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800684: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800688: jal         0x800136E4
    // 0x8080068C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x8080068C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_1:
    // 0x80800690: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800694: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800698: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080069C: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808006A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808006A4: jal         0x800136E4
    // 0x808006A8: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x808006A8: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_2:
    // 0x808006AC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808006B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006B4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x808006B8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808006BC: bne         $t7, $at, L_80800858
    if (ctx->r15 != ctx->r1) {
        // 0x808006C0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800858;
    }
    // 0x808006C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808006C4: jal         0x800BFA1C
    // 0x808006C8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800BFA1C(rdram, ctx);
        goto after_3;
    // 0x808006C8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_3:
    // 0x808006CC: bne         $v0, $zero, L_80800700
    if (ctx->r2 != 0) {
        // 0x808006D0: lwc1        $f10, 0x44($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80800700;
    }
    // 0x808006D0: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808006D4: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808006D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808006DC: nop

    // 0x808006E0: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x808006E4: nop

    // 0x808006E8: bc1fl       L_80800704
    if (!c1cs) {
        // 0x808006EC: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80800704;
    }
    goto skip_0;
    // 0x808006EC: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    skip_0:
    // 0x808006F0: jal         0x800FFAB0
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808006F8: b           L_8080085C
    // 0x808006FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080085C;
    // 0x808006FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800700:
    // 0x80800700: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_80800704:
    // 0x80800704: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800708: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800714: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80800718: jal         0x80800914
    // 0x8080071C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    func_80800914_chvolcanobits(rdram, ctx);
        goto after_5;
    // 0x8080071C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x80800720: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800724: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x80800728: jal         0x8010B990
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_6;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800730: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x80800734: bnel        $t8, $zero, L_80800760
    if (ctx->r24 != 0) {
        // 0x80800738: lw          $a0, 0x18($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X18);
            goto L_80800760;
    }
    goto skip_1;
    // 0x80800738: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x8080073C: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800740: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80800744: bgez        $t1, L_80800820
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800748: nop
    
            goto L_80800820;
    }
    // 0x80800748: nop

    // 0x8080074C: jal         0x800D9078
    // 0x80800750: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80800750: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_7:
    // 0x80800754: beq         $v0, $zero, L_80800820
    if (ctx->r2 == 0) {
        // 0x80800758: nop
    
            goto L_80800820;
    }
    // 0x80800758: nop

    // 0x8080075C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
L_80800760:
    // 0x80800760: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80800764: jal         0x800C8E54
    // 0x80800768: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    func_800C8E54(rdram, ctx);
        goto after_8;
    // 0x80800768: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_8:
    // 0x8080076C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1264, 0X1100) << 16);
    // 0x80800770: addiu       $a1, $a1, 0x1100
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1264, 0X1100));
    // 0x80800774: jal         0x800C8E84
    // 0x80800778: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_800C8E84(rdram, ctx);
        goto after_9;
    // 0x80800778: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_9:
    // 0x8080077C: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x80800780: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800784: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80800788: jal         0x800863E8
    // 0x8080078C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x8080078C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x80800790: jal         0x80088B00
    // 0x80800794: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    _fxgenlist_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800794: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_11:
    // 0x80800798: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808007A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808007A8: jal         0x800BBCB8
    // 0x808007AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BBCB8(rdram, ctx);
        goto after_12;
    // 0x808007AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
    // 0x808007B0: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x808007B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1264, 0X1288) << 16);
    // 0x808007B8: addiu       $a2, $a2, 0x1288
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1264, 0X1288));
    // 0x808007BC: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x808007C0: bgez        $t4, L_808007D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808007C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007D4;
    }
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1264, 0X129C) << 16);
    // 0x808007CC: b           L_808007D4
    // 0x808007D0: addiu       $a2, $a2, 0x129C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1264, 0X129C));
        goto L_808007D4;
    // 0x808007D0: addiu       $a2, $a2, 0x129C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1264, 0X129C));
L_808007D4:
    // 0x808007D4: jal         0x80089D18
    // 0x808007D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x808007D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x808007DC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808007E0: jal         0x800EE7F8
    // 0x808007E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x808007E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_14:
    // 0x808007E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808007EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007F0: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808007F4: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007FC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800800: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800804: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80800808: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8080080C: jal         0x80086670
    // 0x80800810: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800810: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800818: jal         0x80101FDC
    // 0x8080081C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x8080081C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
L_80800820:
    // 0x80800820: jal         0x8001210C
    // 0x80800824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_17;
    // 0x80800824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x80800828: bnel        $v0, $zero, L_8080085C
    if (ctx->r2 != 0) {
        // 0x8080082C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080085C;
    }
    goto skip_2;
    // 0x8080082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800830: jal         0x800B5BE4
    // 0x80800834: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800B5BE4(rdram, ctx);
        goto after_18;
    // 0x80800834: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_18:
    // 0x80800838: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1264, 0X12AC) << 16);
    // 0x8080083C: addiu       $t5, $t5, 0x12AC
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1264, 0X12AC));
    // 0x80800840: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800844: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800848: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080084C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800850: jal         0x800BABB8
    // 0x80800854: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_19;
    // 0x80800854: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_19:
L_80800858:
    // 0x80800858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080085C:
    // 0x8080085C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800860: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void _bamovespline_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EC8: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084EC8);
    return;
    // 0x80084ECC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800D035C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D035C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D0360: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D0364: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D0368: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800D036C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D0370: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D0374: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D0378: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D037C: bne         $a0, $at, L_800D0404
    if (ctx->r4 != ctx->r1) {
        // 0x800D0380: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800D0404;
    }
    // 0x800D0380: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D0384: jal         0x800D0820
    // 0x800D0388: nop

    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800D0388: nop

    after_0:
    // 0x800D038C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D0390: jal         0x800D0894
    // 0x800D0394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800D0394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800D0398: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D039C: bne         $at, $zero, L_800D044C
    if (ctx->r1 != 0) {
        // 0x800D03A0: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_800D044C;
    }
    // 0x800D03A0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800D03A4: addiu       $s3, $s3, -0x52F8
    ctx->r19 = ADD32(ctx->r19, -0X52F8);
    // 0x800D03A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D03AC:
    // 0x800D03AC: jal         0x800D0B68
    // 0x800D03B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x800D03B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D03B4: beq         $v0, $zero, L_800D03E4
    if (ctx->r2 == 0) {
        // 0x800D03B8: sll         $t6, $s0, 1
        ctx->r14 = S32(ctx->r16 << 1);
            goto L_800D03E4;
    }
    // 0x800D03B8: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x800D03BC: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x800D03C0: lbu         $t8, -0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1);
    // 0x800D03C4: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    // 0x800D03C8: beq         $t8, $zero, L_800D03D8
    if (ctx->r24 == 0) {
        // 0x800D03CC: nop
    
            goto L_800D03D8;
    }
    // 0x800D03CC: nop

    // 0x800D03D0: b           L_800D03D8
    // 0x800D03D4: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
        goto L_800D03D8;
    // 0x800D03D4: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
L_800D03D8:
    // 0x800D03D8: jal         0x80085AD8
    // 0x800D03DC: nop

    _chnests_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x800D03DC: nop

    after_3:
    // 0x800D03E0: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_800D03E4:
    // 0x800D03E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D03E8: jal         0x800D0894
    // 0x800D03EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_4;
    // 0x800D03EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800D03F0: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D03F4: beql        $at, $zero, L_800D03AC
    if (ctx->r1 == 0) {
        // 0x800D03F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D03AC;
    }
    goto skip_0;
    // 0x800D03F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800D03FC: b           L_800D0450
    // 0x800D0400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800D0450;
    // 0x800D0400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D0404:
    // 0x800D0404: jal         0x800D0820
    // 0x800D0408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_5;
    // 0x800D0408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800D040C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D0410: jal         0x800D0894
    // 0x800D0414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_6;
    // 0x800D0414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800D0418: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D041C: bne         $at, $zero, L_800D044C
    if (ctx->r1 != 0) {
        // 0x800D0420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D044C;
    }
    // 0x800D0420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D0424:
    // 0x800D0424: jal         0x800D0B68
    // 0x800D0428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_7;
    // 0x800D0428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800D042C: beq         $v0, $zero, L_800D0438
    if (ctx->r2 == 0) {
        // 0x800D0430: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D0438;
    }
    // 0x800D0430: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D0434: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D0438:
    // 0x800D0438: jal         0x800D0894
    // 0x800D043C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_8;
    // 0x800D043C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x800D0440: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0444: beql        $at, $zero, L_800D0424
    if (ctx->r1 == 0) {
        // 0x800D0448: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0424;
    }
    goto skip_1;
    // 0x800D0448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_800D044C:
    // 0x800D044C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D0450:
    // 0x800D0450: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800D0454: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0458: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D045C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D0460: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D0464: jr          $ra
    // 0x800D0468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D0468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080000C_charea51gate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x8080001C: jal         0x80104004
    // 0x80800020: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    func_80104004(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080002C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800030: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80800034: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800038: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080003C: jal         0x8010A800
    // 0x80800040: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    func_8010A800(rdram, ctx);
        goto after_1;
    // 0x80800040: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    after_1:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void func_80800750_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800750: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800754: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800758: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080075C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800760: jal         0x8008CABC
    // 0x80800764: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800764: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800768: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080076C: jal         0x8009E710
    // 0x80800770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800774: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80800778: bne         $v0, $at, L_8080078C
    if (ctx->r2 != ctx->r1) {
        // 0x8080077C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080078C;
    }
    // 0x8080077C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800780: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(332, 0XB24) << 16);
    // 0x80800784: b           L_80800794
    // 0x80800788: lwc1        $f0, 0xB24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(332, 0XB24));
        goto L_80800794;
    // 0x80800788: lwc1        $f0, 0xB24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(332, 0XB24));
L_8080078C:
    // 0x8080078C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(332, 0XB28) << 16);
    // 0x80800790: lwc1        $f0, 0xB28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(332, 0XB28));
L_80800794:
    // 0x80800794: jal         0x80800114
    // 0x80800798: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80800114_bsmumswim(rdram, ctx);
        goto after_2;
    // 0x80800798: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8080079C: jal         0x8008AF24
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007A4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007B0: jal         0x8008B1C8
    // 0x808007B4: nop

    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x808007B4: nop

    after_4:
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: jal         0x8008AED4
    // 0x808007C0: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x808007C0: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    after_5:
    // 0x808007C4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808007C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808007CC: jal         0x8008B24C
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: jal         0x8008B134
    // 0x808007DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x808007DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808007E0: jal         0x8008B064
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808007E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007EC: jal         0x8008CA4C
    // 0x808007F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_9;
    // 0x808007F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808007F4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808007F8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808007FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800800: jal         0x8008C9BC
    // 0x80800804: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_10;
    // 0x80800804: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_10:
    // 0x80800808: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080080C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800814: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800818: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x8080081C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800820: jal         0x8008C9F0
    // 0x80800824: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_11;
    // 0x80800824: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80800828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080082C: jal         0x8009C908
    // 0x80800830: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_12;
    // 0x80800830: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80800834: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800838: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x8080083C: jal         0x8009C99C
    // 0x80800840: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_13;
    // 0x80800840: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_13:
    // 0x80800844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800848: jal         0x8009D2D8
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_14;
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800854: jal         0x8009B800
    // 0x80800858: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_15;
    // 0x80800858: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x8080085C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800860: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800864: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800868: jr          $ra
    // 0x8080086C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080086C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800704_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080070C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800710: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800718: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080071C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80800720: bne         $t8, $zero, L_80800748
    if (ctx->r24 != 0) {
        // 0x80800724: nop
    
            goto L_80800748;
    }
    // 0x80800724: nop

    // 0x80800728: jal         0x8009E674
    // 0x8080072C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x8080072C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800730: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(532, 0X10A0) << 16);
    // 0x80800734: addiu       $a3, $a3, 0x10A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(532, 0X10A0));
    // 0x80800738: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8080073C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800740: jal         0x8010D930
    // 0x80800744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x80800744: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80800748:
    // 0x80800748: jal         0x800A4CA8
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_2;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800750: jal         0x80110BF0
    // 0x80800754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110BF0(rdram, ctx);
        goto after_3;
    // 0x80800754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: jal         0x808005FC
    // 0x80800760: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_808005FC_bafpctrl(rdram, ctx);
        goto after_4;
    // 0x80800760: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_4:
    // 0x80800764: jal         0x800A4CA8
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_5;
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080076C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800770: jal         0x800893F8
    // 0x80800774: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80800774: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080077C: jal         0x80095738
    // 0x80800780: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    baflag_isTrue(rdram, ctx);
        goto after_7;
    // 0x80800780: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_7:
    // 0x80800784: beq         $v0, $zero, L_808007BC
    if (ctx->r2 == 0) {
        // 0x80800788: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007BC;
    }
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: jal         0x80099A7C
    // 0x80800794: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80099A7C(rdram, ctx);
        goto after_8;
    // 0x80800794: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080079C: jal         0x800848F0
    // 0x808007A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _badrone_entrypoint_33(rdram, ctx);
        goto after_9;
    // 0x808007A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x808007A4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808007A8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808007AC: jal         0x800A516C
    // 0x808007B0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800A516C(rdram, ctx);
        goto after_10;
    // 0x808007B0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x808007B4: b           L_808007E4
    // 0x808007B8: nop

        goto L_808007E4;
    // 0x808007B8: nop

L_808007BC:
    // 0x808007BC: jal         0x800F3E84
    // 0x808007C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F3E84(rdram, ctx);
        goto after_11;
    // 0x808007C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_11:
    // 0x808007C4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808007C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007CC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808007D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808007D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808007D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808007DC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808007E0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_808007E4:
    // 0x808007E4: jal         0x800A4CA8
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_12;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808007EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007F0: jal         0x80089400
    // 0x808007F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x808007F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_13:
    // 0x808007F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808007FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800800: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080080C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800810: jal         0x8009C914
    // 0x80800814: nop

    yaw_setIdeal(rdram, ctx);
        goto after_14;
    // 0x80800814: nop

    after_14:
    // 0x80800818: lw          $t9, 0x90($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X90);
    // 0x8080081C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800820: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80800824: beql        $t1, $zero, L_80800850
    if (ctx->r9 == 0) {
        // 0x80800828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    goto skip_0;
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080082C: jal         0x8009C974
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_15;
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800834: jal         0x800A4CA8
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_16;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080083C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80800840: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800844: jal         0x80089428
    // 0x80800848: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_12(rdram, ctx);
        goto after_17;
    // 0x80800848: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800850:
    // 0x80800850: jal         0x80095760
    // 0x80800854: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    baflag_set(rdram, ctx);
        goto after_18;
    // 0x80800854: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_18:
    // 0x80800858: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800864: jal         0x80800424
    // 0x80800868: sb          $zero, 0x14($t2)
    MEM_B(0X14, ctx->r10) = 0;
    func_80800424_bafpctrl(rdram, ctx);
        goto after_19;
    // 0x80800868: sb          $zero, 0x14($t2)
    MEM_B(0X14, ctx->r10) = 0;
    after_19:
    // 0x8080086C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800874: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800878: jr          $ra
    // 0x8080087C: nop

    return;
    // 0x8080087C: nop

;}
RECOMP_FUNC void _fxdialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B48: syscall     725
    recomp_syscall_handler(rdram, ctx, 0x80088B48);
    return;
    // 0x80088B4C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80015430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015430: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015434: addiu       $v0, $v0, -0x70A0
    ctx->r2 = ADD32(ctx->r2, -0X70A0);
    // 0x80015438: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8001543C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80015440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015444: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015448: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001544C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015450: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80015454: jal         0x8002FDE0
    // 0x80015458: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80015458: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    after_0:
    // 0x8001545C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015464: jr          $ra
    // 0x80015468: nop

    return;
    // 0x80015468: nop

;}
RECOMP_FUNC void func_8080091C_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080091C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800924: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080092C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80800930: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80800934: jal         0x800EFD24
    // 0x80800938: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800938: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x8080093C: jal         0x800F54E4
    // 0x80800940: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800940: nop

    after_1:
    // 0x80800944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800948: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8080094C: jal         0x800F586C
    // 0x80800950: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F586C(rdram, ctx);
        goto after_2;
    // 0x80800950: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80800954: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800958: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080095C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800960: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800964: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800968: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8080096C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800970: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800974: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800978: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080097C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80800980: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80800984: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80800988: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080098C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800990: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x80800994: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800998: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080099C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x808009A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808009A4: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x808009A8: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808009AC: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x808009B0: nop

    // 0x808009B4: bc1fl       L_808009C8
    if (!c1cs) {
        // 0x808009B8: lwc1        $f0, 0x18($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
            goto L_808009C8;
    }
    goto skip_0;
    // 0x808009B8: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x808009BC: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x808009C0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x808009C4: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
L_808009C8:
    // 0x808009C8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808009CC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808009D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808009D4: nop

    // 0x808009D8: bc1fl       L_808009F4
    if (!c1cs) {
        // 0x808009DC: c.lt.s      $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
            goto L_808009F4;
    }
    goto skip_1;
    // 0x808009DC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    skip_1:
    // 0x808009E0: jal         0x808008D8
    // 0x808009E4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    func_808008D8_chbanjoctrl(rdram, ctx);
        goto after_3;
    // 0x808009E4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x808009E8: b           L_80800A14
    // 0x808009EC: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
        goto L_80800A14;
    // 0x808009EC: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808009F0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
L_808009F4:
    // 0x808009F4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808009F8: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x808009FC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800A00: bc1fl       L_80800A14
    if (!c1cs) {
        // 0x80800A04: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80800A14;
    }
    goto skip_2;
    // 0x80800A04: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_2:
    // 0x80800A08: jal         0x808008D8
    // 0x80800A0C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    func_808008D8_chbanjoctrl(rdram, ctx);
        goto after_4;
    // 0x80800A0C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x80800A10: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
L_80800A14:
    // 0x80800A14: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800A18: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800A1C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800A20: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800A24: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800A28: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800A2C: bc1fl       L_80800A48
    if (!c1cs) {
        // 0x80800A30: c.lt.s      $f10, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
            goto L_80800A48;
    }
    goto skip_3;
    // 0x80800A30: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    skip_3:
    // 0x80800A34: jal         0x808008D8
    // 0x80800A38: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    func_808008D8_chbanjoctrl(rdram, ctx);
        goto after_5;
    // 0x80800A38: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x80800A3C: b           L_80800A64
    // 0x80800A40: nop

        goto L_80800A64;
    // 0x80800A40: nop

    // 0x80800A44: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
L_80800A48:
    // 0x80800A48: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800A4C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800A50: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800A54: bc1f        L_80800A64
    if (!c1cs) {
        // 0x80800A58: nop
    
            goto L_80800A64;
    }
    // 0x80800A58: nop

    // 0x80800A5C: jal         0x808008D8
    // 0x80800A60: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    func_808008D8_chbanjoctrl(rdram, ctx);
        goto after_6;
    // 0x80800A60: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    after_6:
L_80800A64:
    // 0x80800A64: jal         0x800EEF24
    // 0x80800A68: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EEF24(rdram, ctx);
        goto after_7;
    // 0x80800A68: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_7:
    // 0x80800A6C: beq         $v0, $zero, L_80800AB0
    if (ctx->r2 == 0) {
        // 0x80800A70: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800AB0;
    }
    // 0x80800A70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800A74: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80800A78: jal         0x800F6720
    // 0x80800A7C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_800F6720(rdram, ctx);
        goto after_8;
    // 0x80800A7C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_8:
    // 0x80800A80: beq         $v0, $zero, L_80800AB0
    if (ctx->r2 == 0) {
        // 0x80800A84: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_80800AB0;
    }
    // 0x80800A84: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800A88: jal         0x800EF368
    // 0x80800A8C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_9;
    // 0x80800A8C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_9:
    // 0x80800A90: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800A94: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800A98: jal         0x800EFB24
    // 0x80800A9C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800EFB24(rdram, ctx);
        goto after_10;
    // 0x80800A9C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_10:
    // 0x80800AA0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800AA4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800AA8: jal         0x800F7700
    // 0x80800AAC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800F7700(rdram, ctx);
        goto after_11;
    // 0x80800AAC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_11:
L_80800AB0:
    // 0x80800AB0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800AB4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800AB8: beql        $t8, $zero, L_80800ACC
    if (ctx->r24 == 0) {
        // 0x80800ABC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800ACC;
    }
    goto skip_4;
    // 0x80800ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800AC0: jal         0x800F8418
    // 0x80800AC4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800F8418(rdram, ctx);
        goto after_12;
    // 0x80800AC4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_12:
    // 0x80800AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800ACC:
    // 0x80800ACC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800AD4: jr          $ra
    // 0x80800AD8: nop

    return;
    // 0x80800AD8: nop

;}
RECOMP_FUNC void chjiggytemple_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800470: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(784, 0X974) << 16);
    // 0x80800474: jr          $ra
    // 0x80800478: addiu       $v0, $v0, 0x974
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(784, 0X974));
    return;
    // 0x80800478: addiu       $v0, $v0, 0x974
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(784, 0X974));
;}
RECOMP_FUNC void chcastleshockpadswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1432, 0X170) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1432, 0X170));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1432, 0X170));
;}
RECOMP_FUNC void _bskazstilt_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836E0: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836E0);
    return;
    // 0x800836E4: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80803CC4_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803CC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803CCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80803CD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80803CD4: jal         0x800B53A4
    // 0x80803CD8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80803CD8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80803CDC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80803CE0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1692, 0X46DC) << 16);
    // 0x80803CE4: addiu       $t6, $t6, 0x46DC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1692, 0X46DC));
    // 0x80803CE8: lui         $a3, 0x3FB3
    ctx->r7 = S32(0X3FB3 << 16);
    // 0x80803CEC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80803CF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80803CF4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80803CF8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80803CFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80803D00: jal         0x800BABB8
    // 0x80803D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80803D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80803D08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80803D0C: jal         0x800BA3FC
    // 0x80803D10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x80803D10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80803D14: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80803D18: jal         0x800BA22C
    // 0x80803D1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80803D1C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80803D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803D28: jr          $ra
    // 0x80803D2C: nop

    return;
    // 0x80803D2C: nop

;}
RECOMP_FUNC void func_80800D50_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D54: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D5C: bne         $a1, $at, L_80800D84
    if (ctx->r5 != ctx->r1) {
        // 0x80800D60: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800D84;
    }
    // 0x80800D60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800D64: lw          $t7, 0x24($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X24);
    // 0x80800D68: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80800D6C: bnel        $t8, $zero, L_80800D90
    if (ctx->r24 != 0) {
        // 0x80800D70: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D90;
    }
    goto skip_0;
    // 0x80800D70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800D74: jal         0x80102424
    // 0x80800D78: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800D78: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800D7C: b           L_80800D90
    // 0x80800D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D90;
    // 0x80800D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D84:
    // 0x80800D84: b           L_80800D90
    // 0x80800D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D90;
    // 0x80800D88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D90:
    // 0x80800D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D98: jr          $ra
    // 0x80800D9C: nop

    return;
    // 0x80800D9C: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895A8: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800895A8);
    return;
    // 0x800895AC: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void chmricecube_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1224, 0X928) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x928
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1224, 0X928));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x928
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1224, 0X928));
;}
