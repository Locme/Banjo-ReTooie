#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bskazfly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083380: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x80083380);
    return;
    // 0x80083384: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800AE820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE820: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AE824: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800AE828: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800AE82C: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800AE830: sw          $ra, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r31;
    // 0x800AE834: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800AE838: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800AE83C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800AE840: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800AE844: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AE848: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AE84C: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x800AE850: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AE854: jal         0x800AE8A8
    // 0x800AE858: nop

    func_800AE8A8(rdram, ctx);
        goto after_0;
    // 0x800AE858: nop

    after_0:
    // 0x800AE85C: jal         0x800AEAA0
    // 0x800AE860: nop

    func_800AEAA0(rdram, ctx);
        goto after_1;
    // 0x800AE860: nop

    after_1:
    // 0x800AE864: jal         0x800AEBA8
    // 0x800AE868: nop

    func_800AEBA8(rdram, ctx);
        goto after_2;
    // 0x800AE868: nop

    after_2:
    // 0x800AE86C: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x800AE870: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800AE874: nor         $t1, $t1, $zero
    ctx->r9 = ~(ctx->r9 | 0);
    // 0x800AE878: and         $t0, $t0, $t1
    ctx->r8 = ctx->r8 & ctx->r9;
    // 0x800AE87C: mtc0        $t0, Status
    cop0_status_write(ctx, ctx->r8);    // 0x800AE880: lw          $ra, 0xC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XC);
    // 0x800AE884: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800AE888: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800AE88C: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x800AE890: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800AE894: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800AE898: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800AE89C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800AE8A0: jr          $ra
    // 0x800AE8A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AE8A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808029D8_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808029DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808029E0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808029E4: jal         0x80100094
    // 0x808029E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808029E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808029EC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808029F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808029F4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808029F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808029FC: jal         0x800DC178
    // 0x80802A00: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80802A00: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802A04: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80802A08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802A0C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80802A10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802A14: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80802A18: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80802A1C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80802A20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80802A24: jal         0x800F10B4
    // 0x80802A28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80802A28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80802A2C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80802A30: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80802A34: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80802A38: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80802A3C: jal         0x800EEB9C
    // 0x80802A40: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_3;
    // 0x80802A40: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_3:
    // 0x80802A44: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80802A48: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80802A4C: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x80802A50: jal         0x800EF04C
    // 0x80802A54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80802A54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80802A58: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1360, 0X49B4) << 16);
    // 0x80802A5C: addiu       $t7, $t7, 0x49B4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1360, 0X49B4));
    // 0x80802A60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802A64: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80802A68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802A6C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80802A70: jal         0x800BBCB8
    // 0x80802A74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80802A74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80802A78: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80802A7C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80802A80: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1360, 0X49DC) << 16);
    // 0x80802A84: lw          $t0, 0x70($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X70);
    // 0x80802A88: lbu         $a0, 0xB2($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0XB2);
    // 0x80802A8C: addiu       $a3, $a3, 0x49DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1360, 0X49DC));
    // 0x80802A90: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80802A94: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802A98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802A9C: jal         0x80089D68
    // 0x80802AA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80802AA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80802AA4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80802AA8: sb          $v0, 0xB2($t2)
    MEM_B(0XB2, ctx->r10) = ctx->r2;
    // 0x80802AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802AB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802AB4: jr          $ra
    // 0x80802AB8: nop

    return;
    // 0x80802AB8: nop

;}
RECOMP_FUNC void _ncbastring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089148: syscall     763
    recomp_syscall_handler(rdram, ctx, 0x80089148);
    return;
    // 0x8008914C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8080005C_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800060: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800068: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080006C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800070: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800074: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800078: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x8080007C: beq         $at, $zero, L_80800184
    if (ctx->r1 == 0) {
        // 0x80800080: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800184;
    }
    // 0x80800080: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800084: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(916, 0XAA0) << 16);
    // 0x80800088: addu        $at, $at, $t8
    gpr jr_addend_80800090 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080008C: lw          $t8, 0xAA0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(916, 0XAA0));
    // 0x80800090: jr          $t8
    // 0x80800094: nop

    switch (jr_addend_80800090 >> 2) {
        case 0: goto L_80800098; break;
        case 1: goto L_80800184; break;
        case 2: goto L_80800184; break;
        case 3: goto L_80800184; break;
        case 4: goto L_808000A8; break;
        case 5: goto L_808000DC; break;
        case 6: goto L_80800120; break;
        default: switch_error(__func__, 0x80800090, 0x80800AA0);
    }
    // 0x80800094: nop

L_80800098:
    // 0x80800098: jal         0x80800200
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800200_chmadamegrunty(rdram, ctx);
        goto after_0;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000A0: b           L_80800188
    // 0x808000A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800188;
    // 0x808000A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A8:
    // 0x808000A8: jal         0x808008D4
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D4_chmadamegrunty(rdram, ctx);
        goto after_1;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000B0: bnel        $v0, $zero, L_80800188
    if (ctx->r2 != 0) {
        // 0x808000B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800188;
    }
    goto skip_0;
    // 0x808000B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000B8: jal         0x800F54E4
    // 0x808000BC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808000BC: nop

    after_2:
    // 0x808000C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C4: jal         0x800F4924
    // 0x808000C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800F4924(rdram, ctx);
        goto after_3;
    // 0x808000C8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x808000CC: jal         0x808003B0
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003B0_chmadamegrunty(rdram, ctx);
        goto after_4;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000D4: b           L_80800188
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800188;
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000DC:
    // 0x808000DC: jal         0x800D9078
    // 0x808000E0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x808000E0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x808000E4: beql        $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x808000E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800188;
    }
    goto skip_1;
    // 0x808000E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808000EC: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F4: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808000F8: bgez        $t1, L_80800108
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808000FC: nop
    
            goto L_80800108;
    }
    // 0x808000FC: nop

    // 0x80800100: b           L_80800108
    // 0x80800104: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_80800108;
    // 0x80800104: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_80800108:
    // 0x80800108: jal         0x8080082C
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_6;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800110: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800114: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80800118: b           L_80800184
    // 0x8080011C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_80800184;
    // 0x8080011C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800120:
    // 0x80800120: jal         0x800D90A4
    // 0x80800124: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x80800124: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_7:
    // 0x80800128: beql        $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x8080012C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800188;
    }
    goto skip_2;
    // 0x8080012C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800130: jal         0x8008A230
    // 0x80800134: nop

    _subaddiedialog_entrypoint_16(rdram, ctx);
        goto after_8;
    // 0x80800134: nop

    after_8:
    // 0x80800138: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x8080013C: addiu       $a1, $zero, 0x10CB
        ctx->r5 = ADD32(0, 0X10CB);
            goto L_80800184;
    }
    // 0x8080013C: addiu       $a1, $zero, 0x10CB
    ctx->r5 = ADD32(0, 0X10CB);
    // 0x80800140: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800144: addiu       $t4, $zero, 0x43
    ctx->r12 = ADD32(0, 0X43);
    // 0x80800148: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080014C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800150: jal         0x8008A208
    // 0x80800154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80800158: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800184;
    }
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x8080082C
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_10;
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800168: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    // 0x8080016C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800170: jal         0x80101180
    // 0x80800174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_11;
    // 0x80800174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: jal         0x8008A4B0
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
L_80800184:
    // 0x80800184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800188:
    // 0x80800188: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080018C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804E08: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80804E0C: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB510) << 16);
    // 0x80804E10: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80804E14: jr          $ra
    // 0x80804E18: lw          $v0, -0x4AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB510));
    return;
    // 0x80804E18: lw          $v0, -0x4AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB510));
;}
RECOMP_FUNC void func_800C0948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0948: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C094C: lw          $a0, -0x7510($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7510);
    // 0x800C0950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0958: beq         $a0, $zero, L_800C0970
    if (ctx->r4 == 0) {
        // 0x800C095C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C0970;
    }
    // 0x800C095C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C0960: jal         0x80088208
    // 0x800C0964: nop

    _gcnewpause_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800C0964: nop

    after_0:
    // 0x800C0968: b           L_800C0970
    // 0x800C096C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C0970;
    // 0x800C096C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C0970:
    // 0x800C0970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0978: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C097C: jr          $ra
    // 0x800C0980: nop

    return;
    // 0x800C0980: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E4: beq         $a0, $zero, L_808004F8
    if (ctx->r4 == 0) {
        // 0x808004E8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808004F8;
    }
    // 0x808004E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808004EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004F0: jr          $ra
    // 0x808004F4: sb          $zero, 0x75F2($at)
    MEM_B(0X75F2, ctx->r1) = 0;
    return;
    // 0x808004F4: sb          $zero, 0x75F2($at)
    MEM_B(0X75F2, ctx->r1) = 0;
L_808004F8:
    // 0x808004F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004FC: sb          $t6, 0x75F2($at)
    MEM_B(0X75F2, ctx->r1) = ctx->r14;
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_8009EA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EA68: jr          $ra
    // 0x8009EA6C: lh          $v0, 0x707C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X707C);
    return;
    // 0x8009EA6C: lh          $v0, 0x707C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X707C);
;}
RECOMP_FUNC void func_800E692C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E692C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E6930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E6934: jal         0x8001ACCC
    // 0x800E6938: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800E6938: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x800E693C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E6940: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E6944: sw          $v0, -0x2A90($at)
    MEM_W(-0X2A90, ctx->r1) = ctx->r2;
    // 0x800E6948: jr          $ra
    // 0x800E694C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E694C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808003F8_chstarspinnerstar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003FC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800404: beq         $a1, $at, L_80800428
    if (ctx->r5 == ctx->r1) {
        // 0x80800408: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800428;
    }
    // 0x80800408: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080040C: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800410: bne         $a1, $at, L_80800438
    if (ctx->r5 != ctx->r1) {
        // 0x80800414: nop
    
            goto L_80800438;
    }
    // 0x80800414: nop

    // 0x80800418: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x8080041C: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800420: b           L_80800440
    // 0x80800424: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
        goto L_80800440;
    // 0x80800424: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
L_80800428:
    // 0x80800428: jal         0x808005F8
    // 0x8080042C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808005F8_chstarspinnerstar(rdram, ctx);
        goto after_0;
    // 0x8080042C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80800430: b           L_80800444
    // 0x80800434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800444;
    // 0x80800434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800438:
    // 0x80800438: b           L_80800444
    // 0x8080043C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800444;
    // 0x8080043C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800440:
    // 0x80800440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800444:
    // 0x80800444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080044C: jr          $ra
    // 0x80800450: nop

    return;
    // 0x80800450: nop

;}
RECOMP_FUNC void func_80099970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099974: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80099978: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8009997C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80099980: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80099984: lw          $v0, 0xC0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC0);
    // 0x80099988: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009998C: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
L_80099990:
    // 0x80099990: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x80099994: beq         $t6, $zero, L_80099A14
    if (ctx->r14 == 0) {
        // 0x80099998: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80099A14;
    }
    // 0x80099998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009999C: jal         0x8009ACF4
    // 0x800999A0: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    func_8009ACF4(rdram, ctx);
        goto after_0;
    // 0x800999A0: lw          $a1, 0x28($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X28);
    after_0:
    // 0x800999A4: lw          $t7, 0xC0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC0);
    // 0x800999A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800999AC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800999B0: jal         0x8009AD04
    // 0x800999B4: lw          $a1, 0x2C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X2C);
    func_8009AD04(rdram, ctx);
        goto after_1;
    // 0x800999B4: lw          $a1, 0x2C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X2C);
    after_1:
    // 0x800999B8: lw          $t9, 0xC0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC0);
    // 0x800999BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800999C0: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x800999C4: jal         0x8009AD14
    // 0x800999C8: lw          $a1, 0x3C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X3C);
    func_8009AD14(rdram, ctx);
        goto after_2;
    // 0x800999C8: lw          $a1, 0x3C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X3C);
    after_2:
    // 0x800999CC: lw          $t1, 0xC0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC0);
    // 0x800999D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800999D4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800999D8: jal         0x8009AD20
    // 0x800999DC: lw          $a1, 0x40($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X40);
    func_8009AD20(rdram, ctx);
        goto after_3;
    // 0x800999DC: lw          $a1, 0x40($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X40);
    after_3:
    // 0x800999E0: lw          $t3, 0xC0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC0);
    // 0x800999E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800999E8: addu        $a1, $t3, $s0
    ctx->r5 = ADD32(ctx->r11, ctx->r16);
    // 0x800999EC: jal         0x8009AD44
    // 0x800999F0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_8009AD44(rdram, ctx);
        goto after_4;
    // 0x800999F0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_4:
    // 0x800999F4: lw          $t4, 0xC0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC0);
    // 0x800999F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800999FC: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x80099A00: lw          $a1, 0x4C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4C);
    // 0x80099A04: jal         0x8009E7C8
    // 0x80099A08: sw          $zero, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = 0;
    func_8009E7C8(rdram, ctx);
        goto after_5;
    // 0x80099A08: sw          $zero, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = 0;
    after_5:
    // 0x80099A0C: b           L_80099A24
    // 0x80099A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80099A24;
    // 0x80099A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099A14:
    // 0x80099A14: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80099A18: bne         $s0, $v1, L_80099990
    if (ctx->r16 != ctx->r3) {
        // 0x80099A1C: addiu       $v0, $v0, 0x28
        ctx->r2 = ADD32(ctx->r2, 0X28);
            goto L_80099990;
    }
    // 0x80099A1C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x80099A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099A24:
    // 0x80099A24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80099A28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80099A2C: jr          $ra
    // 0x80099A30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80099A30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chmolehill_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086930: syscall     397
    recomp_syscall_handler(rdram, ctx, 0x80086930);
    return;
    // 0x80086934: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800EDB20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDB20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EDB24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EDB28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EDB2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EDB30: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EDB34: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800EDB38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EDB3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800EDB40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EDB44: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800EDB48: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800EDB4C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800EDB50: sb          $zero, 0x29($a0)
    MEM_B(0X29, ctx->r4) = 0;
    // 0x800EDB54: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x800EDB58: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x800EDB5C: sh          $zero, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = 0;
    // 0x800EDB60: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x800EDB64: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x800EDB68: swc1        $f0, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f0.u32l;
    // 0x800EDB6C: swc1        $f0, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f0.u32l;
    // 0x800EDB70: swc1        $f2, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f2.u32l;
    // 0x800EDB74: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x800EDB78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800EDB7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800EDB80: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    // 0x800EDB84: jal         0x80088888
    // 0x800EDB88: addiu       $a3, $s0, 0x1A
    ctx->r7 = ADD32(ctx->r16, 0X1A);
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800EDB88: addiu       $a3, $s0, 0x1A
    ctx->r7 = ADD32(ctx->r16, 0X1A);
    after_0:
    // 0x800EDB8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EDB90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EDB94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EDB98: jr          $ra
    // 0x800EDB9C: nop

    return;
    // 0x800EDB9C: nop

;}
RECOMP_FUNC void _gcsectionDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088270: syscall     677
    recomp_syscall_handler(rdram, ctx, 0x80088270);
    return;
    // 0x80088274: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855E8: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855E8);
    return;
    // 0x800855EC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void chlagoonufoint_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E74: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(748, 0X1B68) << 16);
    // 0x80800E78: jr          $ra
    // 0x80800E7C: addiu       $v0, $v0, 0x1B68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1B68));
    return;
    // 0x80800E7C: addiu       $v0, $v0, 0x1B68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1B68));
;}
RECOMP_FUNC void func_80801A74_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801A78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801A7C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801A88: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801A8C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80801A90: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(932, 0X2D88) << 16);
    // 0x80801A94: addiu       $t7, $t7, 0x2D88
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(932, 0X2D88));
    // 0x80801A98: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x80801A9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801AA0: jal         0x800BABB8
    // 0x80801AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80801AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80801AA8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80801AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801AB0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(932, 0X2DB0) << 16);
    // 0x80801AB4: beq         $t8, $zero, L_80801AC8
    if (ctx->r24 == 0) {
        // 0x80801AB8: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80801AC8;
    }
    // 0x80801AB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80801ABC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(932, 0X2DA4) << 16);
    // 0x80801AC0: b           L_80801ACC
    // 0x80801AC4: addiu       $v0, $v0, 0x2DA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2DA4));
        goto L_80801ACC;
    // 0x80801AC4: addiu       $v0, $v0, 0x2DA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2DA4));
L_80801AC8:
    // 0x80801AC8: addiu       $v0, $v0, 0x2DB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2DB0));
L_80801ACC:
    // 0x80801ACC: lw          $a3, 0x38($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X38);
    // 0x80801AD0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80801AD4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80801AD8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801ADC: jal         0x800BABB8
    // 0x80801AE0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80801AE0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80801AE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801AE8: jal         0x800BA22C
    // 0x80801AEC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80801AEC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80801AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801AF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801AF8: jr          $ra
    // 0x80801AFC: nop

    return;
    // 0x80801AFC: nop

;}
RECOMP_FUNC void _subaddiemulti_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A090: syscall     826
    recomp_syscall_handler(rdram, ctx, 0x8008A090);
    return;
    // 0x8008A094: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E1A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1A58: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800E1A5C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800E1A60: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800E1A64: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800E1A68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E1A6C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800E1A70: addiu       $s3, $sp, 0x80
    ctx->r19 = ADD32(ctx->r29, 0X80);
    // 0x800E1A74: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800E1A78: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800E1A7C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800E1A80: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800E1A84: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800E1A88: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800E1A8C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800E1A90: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800E1A94: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800E1A98: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800E1A9C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800E1AA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E1AA4: jal         0x800EE7F8
    // 0x800E1AA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800E1AA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800E1AAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E1AB0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E1AB4: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E1AB8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800E1ABC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800E1AC0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800E1AC4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800E1AC8: addiu       $s5, $s5, -0x2B98
    ctx->r21 = ADD32(ctx->r21, -0X2B98);
    // 0x800E1ACC: addiu       $s0, $s0, -0x3070
    ctx->r16 = ADD32(ctx->r16, -0X3070);
    // 0x800E1AD0: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x800E1AD4: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800E1AD8: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800E1ADC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800E1AE0: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
L_800E1AE4:
    // 0x800E1AE4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800E1AE8: beql        $s4, $t6, L_800E1BB4
    if (ctx->r20 == ctx->r14) {
        // 0x800E1AEC: addiu       $s0, $s0, 0x7C
        ctx->r16 = ADD32(ctx->r16, 0X7C);
            goto L_800E1BB4;
    }
    goto skip_0;
    // 0x800E1AEC: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    skip_0:
    // 0x800E1AF0: lbu         $t7, 0x76($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X76);
    // 0x800E1AF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E1AF8: beql        $t7, $zero, L_800E1B40
    if (ctx->r15 == 0) {
        // 0x800E1AFC: lbu         $v0, 0x74($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X74);
            goto L_800E1B40;
    }
    goto skip_1;
    // 0x800E1AFC: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    skip_1:
    // 0x800E1B00: jal         0x800EEAD4
    // 0x800E1B04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x800E1B04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800E1B08: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800E1B0C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800E1B10: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800E1B14: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800E1B18: jal         0x800F10B4
    // 0x800E1B1C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x800E1B1C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_2:
    // 0x800E1B20: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800E1B24: jal         0x800F0E00
    // 0x800E1B28: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    func_800F0E00(rdram, ctx);
        goto after_3;
    // 0x800E1B28: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    after_3:
    // 0x800E1B2C: c.eq.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl == ctx->f26.fl;
    // 0x800E1B30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800E1B34: bc1tl       L_800E1BB4
    if (c1cs) {
        // 0x800E1B38: addiu       $s0, $s0, 0x7C
        ctx->r16 = ADD32(ctx->r16, 0X7C);
            goto L_800E1BB4;
    }
    goto skip_2;
    // 0x800E1B38: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    skip_2:
    // 0x800E1B3C: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
L_800E1B40:
    // 0x800E1B40: beql        $v0, $s6, L_800E1B64
    if (ctx->r2 == ctx->r22) {
        // 0x800E1B44: lwc1        $f4, 0x28($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
            goto L_800E1B64;
    }
    goto skip_3;
    // 0x800E1B44: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    skip_3:
    // 0x800E1B48: beql        $v0, $s7, L_800E1B8C
    if (ctx->r2 == ctx->r23) {
        // 0x800E1B4C: lwc1        $f8, 0x28($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
            goto L_800E1B8C;
    }
    goto skip_4;
    // 0x800E1B4C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    skip_4:
    // 0x800E1B50: beql        $v0, $fp, L_800E1B8C
    if (ctx->r2 == ctx->r30) {
        // 0x800E1B54: lwc1        $f8, 0x28($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
            goto L_800E1B8C;
    }
    goto skip_5;
    // 0x800E1B54: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    skip_5:
    // 0x800E1B58: b           L_800E1BB4
    // 0x800E1B5C: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
        goto L_800E1BB4;
    // 0x800E1B5C: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // 0x800E1B60: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
L_800E1B64:
    // 0x800E1B64: lbu         $a0, 0x75($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X75);
    // 0x800E1B68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E1B6C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800E1B70: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800E1B74: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800E1B78: jal         0x800E1294
    // 0x800E1B7C: nop

    func_800E1294(rdram, ctx);
        goto after_4;
    // 0x800E1B7C: nop

    after_4:
    // 0x800E1B80: b           L_800E1BB4
    // 0x800E1B84: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
        goto L_800E1BB4;
    // 0x800E1B84: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // 0x800E1B88: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
L_800E1B8C:
    // 0x800E1B8C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800E1B90: lbu         $a0, 0x75($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X75);
    // 0x800E1B94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E1B98: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800E1B9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800E1BA0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800E1BA4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800E1BA8: jal         0x800E1294
    // 0x800E1BAC: nop

    func_800E1294(rdram, ctx);
        goto after_5;
    // 0x800E1BAC: nop

    after_5:
    // 0x800E1BB0: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
L_800E1BB4:
    // 0x800E1BB4: bnel        $s0, $s5, L_800E1AE4
    if (ctx->r16 != ctx->r21) {
        // 0x800E1BB8: lbu         $t6, 0x74($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X74);
            goto L_800E1AE4;
    }
    goto skip_6;
    // 0x800E1BB8: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    skip_6:
    // 0x800E1BBC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800E1BC0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800E1BC4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800E1BC8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800E1BCC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800E1BD0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800E1BD4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800E1BD8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800E1BDC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800E1BE0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800E1BE4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800E1BE8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800E1BEC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800E1BF0: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800E1BF4: jr          $ra
    // 0x800E1BF8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800E1BF8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800E1BFC: nop

;}
RECOMP_FUNC void _chegggrenade_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087220: syscall     537
    recomp_syscall_handler(rdram, ctx, 0x80087220);
    return;
    // 0x80087224: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bskazwingwhack_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(300, 0XAC8) << 16);
    // 0x808008E4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008E8: jr          $ra
    // 0x808008EC: lw          $v0, 0xAC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(300, 0XAC8));
    return;
    // 0x808008EC: lw          $v0, 0xAC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(300, 0XAC8));
;}
RECOMP_FUNC void func_80807DC0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807DC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80807DCC: jal         0x80100094
    // 0x80807DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807DD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80807DD8: sb          $t6, 0xA5($v0)
    MEM_B(0XA5, ctx->r2) = ctx->r14;
    // 0x80807DDC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80807DE0: sb          $t7, 0xA6($v0)
    MEM_B(0XA6, ctx->r2) = ctx->r15;
    // 0x80807DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807DEC: jr          $ra
    // 0x80807DF0: nop

    return;
    // 0x80807DF0: nop

;}
RECOMP_FUNC void func_80800028_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x80800034: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800038: jal         0x800DA544
    // 0x8080003C: addiu       $a0, $t6, 0x55D
    ctx->r4 = ADD32(ctx->r14, 0X55D);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x8080003C: addiu       $a0, $t6, 0x55D
    ctx->r4 = ADD32(ctx->r14, 0X55D);
    after_0:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void bsledge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080071C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(304, 0X1348) << 16);
    // 0x80800720: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800724: jr          $ra
    // 0x80800728: lw          $v0, 0x1348($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1348));
    return;
    // 0x80800728: lw          $v0, 0x1348($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1348));
;}
RECOMP_FUNC void func_800C36F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C36F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C36F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C36FC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3700: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3708: beq         $t6, $zero, L_800C3720
    if (ctx->r14 == 0) {
        // 0x800C370C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3720;
    }
    // 0x800C370C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3710: jal         0x800C1414
    // 0x800C3714: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3714: nop

    after_0:
    // 0x800C3718: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C371C: sb          $t7, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r15;
L_800C3720:
    // 0x800C3720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3728: jr          $ra
    // 0x800C372C: nop

    return;
    // 0x800C372C: nop

;}
RECOMP_FUNC void func_800D13E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D13E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D13EC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D13F0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D13F4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800D13F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800D13FC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800D1400: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D1404: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D1408: bne         $a0, $at, L_800D146C
    if (ctx->r4 != ctx->r1) {
        // 0x800D140C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800D146C;
    }
    // 0x800D140C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D1410: jal         0x800D0820
    // 0x800D1414: nop

    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800D1414: nop

    after_0:
    // 0x800D1418: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D141C: jal         0x800D0894
    // 0x800D1420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800D1420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800D1424: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800D1428: bne         $at, $zero, L_800D146C
    if (ctx->r1 != 0) {
        // 0x800D142C: sll         $t6, $s1, 1
        ctx->r14 = S32(ctx->r17 << 1);
            goto L_800D146C;
    }
    // 0x800D142C: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x800D1430: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D1434: addiu       $t7, $t7, -0x52F8
    ctx->r15 = ADD32(ctx->r15, -0X52F8);
    // 0x800D1438: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800D143C: lbu         $t8, -0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X2);
L_800D1440:
    // 0x800D1440: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800D1444: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D1448: bne         $s3, $t8, L_800D1458
    if (ctx->r19 != ctx->r24) {
        // 0x800D144C: nop
    
            goto L_800D1458;
    }
    // 0x800D144C: nop

    // 0x800D1450: b           L_800D1470
    // 0x800D1454: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
        goto L_800D1470;
    // 0x800D1454: addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
L_800D1458:
    // 0x800D1458: jal         0x800D0894
    // 0x800D145C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_800D0894(rdram, ctx);
        goto after_2;
    // 0x800D145C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_2:
    // 0x800D1460: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800D1464: beql        $at, $zero, L_800D1440
    if (ctx->r1 == 0) {
        // 0x800D1468: lbu         $t8, -0x2($s0)
        ctx->r24 = MEM_BU(ctx->r16, -0X2);
            goto L_800D1440;
    }
    goto skip_0;
    // 0x800D1468: lbu         $t8, -0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, -0X2);
    skip_0:
L_800D146C:
    // 0x800D146C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D1470:
    // 0x800D1470: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D1474: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D1478: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D147C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1480: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D1484: jr          $ra
    // 0x800D1488: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D1488: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D148C: nop

;}
RECOMP_FUNC void func_808006A4_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808006A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808006AC: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x808006B0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x808006B4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808006B8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808006BC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808006C0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808006C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808006C8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808006CC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808006D0: jal         0x80100094
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006D8: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x808006DC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808006E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808006E4: blez        $t6, L_80800788
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808006E8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800788;
    }
    // 0x808006E8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808006EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X12F8) << 16);
    // 0x808006F0: lwc1        $f22, 0x12F8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2208, 0X12F8));
    // 0x808006F4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808006F8: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(2208, 0X1534) << 16);
    // 0x808006FC: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(2208, 0X151C) << 16);
    // 0x80800700: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2208, 0X154C) << 16);
    // 0x80800704: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800708: addiu       $s3, $s3, 0x154C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2208, 0X154C));
    // 0x8080070C: addiu       $s5, $s5, 0x151C
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(2208, 0X151C));
    // 0x80800710: addiu       $s6, $s6, 0x1534
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(2208, 0X1534));
L_80800714:
    // 0x80800714: jal         0x80106790
    // 0x80800718: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800718: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    after_1:
    // 0x8080071C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800720: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800724: jal         0x80101E14
    // 0x80800728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x80800728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080072C: beq         $v0, $zero, L_80800748
    if (ctx->r2 == 0) {
        // 0x80800730: addu        $t7, $s3, $s1
        ctx->r15 = ADD32(ctx->r19, ctx->r17);
            goto L_80800748;
    }
    // 0x80800730: addu        $t7, $s3, $s1
    ctx->r15 = ADD32(ctx->r19, ctx->r17);
    // 0x80800734: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080073C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800740: jal         0x8010D930
    // 0x80800744: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_8010D930(rdram, ctx);
        goto after_3;
    // 0x80800744: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_3:
L_80800748:
    // 0x80800748: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8080074C: jal         0x80101E14
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800754: beq         $v0, $zero, L_80800770
    if (ctx->r2 == 0) {
        // 0x80800758: addu        $t8, $s3, $s1
        ctx->r24 = ADD32(ctx->r19, ctx->r17);
            goto L_80800770;
    }
    // 0x80800758: addu        $t8, $s3, $s1
    ctx->r24 = ADD32(ctx->r19, ctx->r17);
    // 0x8080075C: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80800760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800764: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800768: jal         0x8010D930
    // 0x8080076C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_8010D930(rdram, ctx);
        goto after_5;
    // 0x8080076C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
L_80800770:
    // 0x80800770: lw          $t9, 0x18($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X18);
    // 0x80800774: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800778: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8080077C: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800780: bne         $at, $zero, L_80800714
    if (ctx->r1 != 0) {
        // 0x80800784: nop
    
            goto L_80800714;
    }
    // 0x80800784: nop

L_80800788:
    // 0x80800788: sw          $zero, 0x18($s4)
    MEM_W(0X18, ctx->r20) = 0;
    // 0x8080078C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800790: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800794: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800798: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8080079C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808007A0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808007A4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808007A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808007AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808007B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808007B4: jr          $ra
    // 0x808007B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808007B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void glsplinecs_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x808003F0: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x808003F4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808003F8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808003FC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800400: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800404: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80800408: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8080040C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800410: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800414: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800418: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8080041C: jal         0x80105494
    // 0x80800420: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80800420: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800424: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800428: jal         0x800D674C
    // 0x8080042C: lw          $a0, 0x198($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X198);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x8080042C: lw          $a0, 0x198($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X198);
    after_1:
    // 0x80800430: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x80800434: lw          $t6, 0x19C($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X19C);
    // 0x80800438: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8080043C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800440: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80800444: lw          $t1, -0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, -0X4);
    // 0x80800448: sll         $t2, $v1, 8
    ctx->r10 = S32(ctx->r3 << 8);
    // 0x8080044C: srl         $t3, $t2, 19
    ctx->r11 = S32(U32(ctx->r10) >> 19);
    // 0x80800450: bne         $t3, $zero, L_80800470
    if (ctx->r11 != 0) {
        // 0x80800454: addu        $s5, $t1, $v0
        ctx->r21 = ADD32(ctx->r9, ctx->r2);
            goto L_80800470;
    }
    // 0x80800454: addu        $s5, $t1, $v0
    ctx->r21 = ADD32(ctx->r9, ctx->r2);
    // 0x80800458: srl         $t4, $v1, 11
    ctx->r12 = S32(U32(ctx->r3) >> 11);
    // 0x8080045C: xori        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 ^ 0X1;
    // 0x80800460: sll         $t7, $t5, 19
    ctx->r15 = S32(ctx->r13 << 19);
    // 0x80800464: srl         $t6, $t7, 8
    ctx->r14 = S32(U32(ctx->r15) >> 8);
    // 0x80800468: xor         $t8, $t6, $v1
    ctx->r24 = ctx->r14 ^ ctx->r3;
    // 0x8080046C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
L_80800470:
    // 0x80800470: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800474: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80800478: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080047C: nop

    // 0x80800480: bc1fl       L_808015B4
    if (!c1cs) {
        // 0x80800484: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808015B4;
    }
    goto skip_0;
    // 0x80800484: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80800488: lw          $t9, 0x24($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X24);
    // 0x8080048C: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80800490: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x80800494: bnel        $t2, $zero, L_808015B4
    if (ctx->r10 != 0) {
        // 0x80800498: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808015B4;
    }
    goto skip_1;
    // 0x80800498: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8080049C: lhu         $t3, 0x2A($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X2A);
    // 0x808004A0: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x808004A4: bnel        $t4, $zero, L_808015B4
    if (ctx->r12 != 0) {
        // 0x808004A8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808015B4;
    }
    goto skip_2;
    // 0x808004A8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x808004AC: lw          $t5, 0x28($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X28);
    // 0x808004B0: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x808004B4: srl         $t6, $t7, 24
    ctx->r14 = S32(U32(ctx->r15) >> 24);
    // 0x808004B8: bnel        $t6, $zero, L_808015B4
    if (ctx->r14 != 0) {
        // 0x808004BC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808015B4;
    }
    goto skip_3;
    // 0x808004BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x808004C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808004C4: lwc1        $f10, 0x2C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x808004C8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808004CC: nop

    // 0x808004D0: bc1tl       L_808015B4
    if (c1cs) {
        // 0x808004D4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808015B4;
    }
    goto skip_4;
    // 0x808004D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x808004D8: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x808004DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808004E0: nop

    // 0x808004E4: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x808004E8: nop

    // 0x808004EC: bc1tl       L_80800520
    if (c1cs) {
        // 0x808004F0: lw          $v1, 0x0($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X0);
            goto L_80800520;
    }
    goto skip_5;
    // 0x808004F0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x808004F4: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x808004F8: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
    // 0x808004FC: ori         $s7, $s7, 0x5
    ctx->r23 = ctx->r23 | 0X5;
    // 0x80800500: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800504: bnel        $s7, $t8, L_8080051C
    if (ctx->r23 != ctx->r24) {
        // 0x80800508: swc1        $f6, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
            goto L_8080051C;
    }
    goto skip_6;
    // 0x80800508: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
    skip_6:
    // 0x8080050C: lwc1        $f18, 0x190($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800510: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80800514: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x80800518: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
L_8080051C:
    // 0x8080051C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80800520:
    // 0x80800520: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
    // 0x80800524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800528: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x8080052C: srl         $t9, $a1, 19
    ctx->r25 = S32(U32(ctx->r5) >> 19);
    // 0x80800530: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800534: addu        $s1, $s5, $t1
    ctx->r17 = ADD32(ctx->r21, ctx->r9);
    // 0x80800538: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x8080053C: ori         $s7, $s7, 0x5
    ctx->r23 = ctx->r23 | 0X5;
    // 0x80800540: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80800544: beql        $t0, $at, L_8080157C
    if (ctx->r8 == ctx->r1) {
        // 0x80800548: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_7;
    // 0x80800548: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_7:
    // 0x8080054C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80800550: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80800554: ori         $at, $at, 0x6
    ctx->r1 = ctx->r1 | 0X6;
    // 0x80800558: bne         $s7, $v0, L_80800588
    if (ctx->r23 != ctx->r2) {
        // 0x8080055C: nop
    
            goto L_80800588;
    }
    // 0x8080055C: nop

    // 0x80800560: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80800564: lwc1        $f8, 0x190($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800568: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8080056C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80800570: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800574: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800578: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8080057C: nop

    // 0x80800580: bc1tl       L_808005C0
    if (c1cs) {
        // 0x80800584: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_808005C0;
    }
    goto skip_8;
    // 0x80800584: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_8:
L_80800588:
    // 0x80800588: bnel        $v0, $at, L_8080157C
    if (ctx->r2 != ctx->r1) {
        // 0x8080058C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_9;
    // 0x8080058C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_9:
    // 0x80800590: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80800594: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X15E8) << 16);
    // 0x80800598: lwc1        $f18, 0x15E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2698, 0X15E8));
    // 0x8080059C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x808005A0: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x808005A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808005A8: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x808005AC: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x808005B0: nop

    // 0x808005B4: bc1fl       L_8080157C
    if (!c1cs) {
        // 0x808005B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_10;
    // 0x808005B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_10:
    // 0x808005BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808005C0:
    // 0x808005C0: lwc1        $f8, 0x20($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X20);
    // 0x808005C4: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x808005C8: nop

    // 0x808005CC: bc1fl       L_8080157C
    if (!c1cs) {
        // 0x808005D0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_11;
    // 0x808005D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_11:
    // 0x808005D4: lw          $a2, 0x24($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X24);
    // 0x808005D8: sll         $t4, $a2, 19
    ctx->r12 = S32(ctx->r6 << 19);
    // 0x808005DC: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x808005E0: bnel        $t5, $zero, L_8080157C
    if (ctx->r13 != 0) {
        // 0x808005E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_12;
    // 0x808005E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_12:
    // 0x808005E8: lhu         $v0, 0x2A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2A);
    // 0x808005EC: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x808005F0: bnel        $t7, $zero, L_8080157C
    if (ctx->r15 != 0) {
        // 0x808005F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_13;
    // 0x808005F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_13:
    // 0x808005F8: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    // 0x808005FC: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x80800600: srl         $t8, $t6, 24
    ctx->r24 = S32(U32(ctx->r14) >> 24);
    // 0x80800604: bnel        $t8, $zero, L_8080157C
    if (ctx->r24 != 0) {
        // 0x80800608: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_14;
    // 0x80800608: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_14:
    // 0x8080060C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800610: lwc1        $f18, 0x2C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x80800614: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80800618: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8080061C: nop

    // 0x80800620: bc1t        L_80801578
    if (c1cs) {
        // 0x80800624: sra         $t9, $t0, 16
        ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
            goto L_80801578;
    }
    // 0x80800624: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
L_80800628:
    // 0x80800628: addiu       $t1, $t9, -0x7
    ctx->r9 = ADD32(ctx->r25, -0X7);
    // 0x8080062C: sltiu       $at, $t1, 0x32
    ctx->r1 = ctx->r9 < 0X32 ? 1 : 0;
    // 0x80800630: beq         $at, $zero, L_80801460
    if (ctx->r1 == 0) {
        // 0x80800634: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80801460;
    }
    // 0x80800634: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X15EC) << 16);
    // 0x8080063C: addu        $at, $at, $t1
    gpr jr_addend_80800644 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800640: lw          $t1, 0x15EC($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2698, 0X15EC));
    // 0x80800644: jr          $t1
    // 0x80800648: nop

    switch (jr_addend_80800644 >> 2) {
        case 0: goto L_8080066C; break;
        case 1: goto L_808006C0; break;
        case 2: goto L_8080064C; break;
        case 3: goto L_80800FC0; break;
        case 4: goto L_80801078; break;
        case 5: goto L_808012B4; break;
        case 6: goto L_808011CC; break;
        case 7: goto L_8080070C; break;
        case 8: goto L_808007F4; break;
        case 9: goto L_80800878; break;
        case 10: goto L_808008A0; break;
        case 11: goto L_808009CC; break;
        case 12: goto L_80800CFC; break;
        case 13: goto L_80800D48; break;
        case 14: goto L_808009FC; break;
        case 15: goto L_80801460; break;
        case 16: goto L_80801460; break;
        case 17: goto L_80801460; break;
        case 18: goto L_80801460; break;
        case 19: goto L_80801460; break;
        case 20: goto L_80800BC8; break;
        case 21: goto L_80800DAC; break;
        case 22: goto L_80800DFC; break;
        case 23: goto L_80800E4C; break;
        case 24: goto L_80800D94; break;
        case 25: goto L_80801208; break;
        case 26: goto L_80801290; break;
        case 27: goto L_80800C28; break;
        case 28: goto L_80800C60; break;
        case 29: goto L_80800CA0; break;
        case 30: goto L_80800EE4; break;
        case 31: goto L_80801348; break;
        case 32: goto L_808013C0; break;
        case 33: goto L_80800A80; break;
        case 34: goto L_80800B58; break;
        case 35: goto L_80800E68; break;
        case 36: goto L_80800F0C; break;
        case 37: goto L_80800F74; break;
        case 38: goto L_808012CC; break;
        case 39: goto L_8080132C; break;
        case 40: goto L_80801048; break;
        case 41: goto L_808008C8; break;
        case 42: goto L_80800B38; break;
        case 43: goto L_80801460; break;
        case 44: goto L_8080143C; break;
        case 45: goto L_808009B0; break;
        case 46: goto L_80800968; break;
        case 47: goto L_80800914; break;
        case 48: goto L_80800940; break;
        case 49: goto L_808008F4; break;
        default: switch_error(__func__, 0x80800644, 0x808015EC);
    }
    // 0x80800648: nop

L_8080064C:
    // 0x8080064C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800650: jal         0x800D7754
    // 0x80800654: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    func_800D7754(rdram, ctx);
        goto after_2;
    // 0x80800654: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    after_2:
    // 0x80800658: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8080065C: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800660: srl         $t2, $a1, 19
    ctx->r10 = S32(U32(ctx->r5) >> 19);
    // 0x80800664: b           L_80801460
    // 0x80800668: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
        goto L_80801460;
    // 0x80800668: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_8080066C:
    // 0x8080066C: sll         $t4, $a2, 18
    ctx->r12 = S32(ctx->r6 << 18);
    // 0x80800670: bltz        $t4, L_80801460
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800674: andi        $t5, $a0, 0x3F
        ctx->r13 = ctx->r4 & 0X3F;
            goto L_80801460;
    }
    // 0x80800674: andi        $t5, $a0, 0x3F
    ctx->r13 = ctx->r4 & 0X3F;
    // 0x80800678: bne         $t5, $zero, L_80801460
    if (ctx->r13 != 0) {
        // 0x8080067C: sll         $t7, $a2, 23
        ctx->r15 = S32(ctx->r6 << 23);
            goto L_80801460;
    }
    // 0x8080067C: sll         $t7, $a2, 23
    ctx->r15 = S32(ctx->r6 << 23);
    // 0x80800680: srl         $t6, $t7, 29
    ctx->r14 = S32(U32(ctx->r15) >> 29);
    // 0x80800684: bnel        $t6, $zero, L_80801464
    if (ctx->r14 != 0) {
        // 0x80800688: addiu       $t8, $a1, 0x2
        ctx->r24 = ADD32(ctx->r5, 0X2);
            goto L_80801464;
    }
    goto skip_15;
    // 0x80800688: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    skip_15:
    // 0x8080068C: lh          $t9, 0x26($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X26);
    // 0x80800690: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80800694: bgezl       $t9, L_80801464
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800698: addiu       $t8, $a1, 0x2
        ctx->r24 = ADD32(ctx->r5, 0X2);
            goto L_80801464;
    }
    goto skip_16;
    // 0x80800698: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    skip_16:
    // 0x8080069C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x808006A0: nop

    // 0x808006A4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808006A8: swc1        $f16, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f16.u32l;
    // 0x808006AC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808006B0: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808006B4: srl         $t2, $a1, 19
    ctx->r10 = S32(U32(ctx->r5) >> 19);
    // 0x808006B8: b           L_80801460
    // 0x808006BC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
        goto L_80801460;
    // 0x808006BC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_808006C0:
    // 0x808006C0: sll         $t4, $a2, 18
    ctx->r12 = S32(ctx->r6 << 18);
    // 0x808006C4: bltz        $t4, L_80801460
    if (SIGNED(ctx->r12) < 0) {
        // 0x808006C8: andi        $t5, $a0, 0x3F
        ctx->r13 = ctx->r4 & 0X3F;
            goto L_80801460;
    }
    // 0x808006C8: andi        $t5, $a0, 0x3F
    ctx->r13 = ctx->r4 & 0X3F;
    // 0x808006CC: bne         $t5, $zero, L_80801460
    if (ctx->r13 != 0) {
        // 0x808006D0: sll         $t7, $a2, 23
        ctx->r15 = S32(ctx->r6 << 23);
            goto L_80801460;
    }
    // 0x808006D0: sll         $t7, $a2, 23
    ctx->r15 = S32(ctx->r6 << 23);
    // 0x808006D4: srl         $t6, $t7, 29
    ctx->r14 = S32(U32(ctx->r15) >> 29);
    // 0x808006D8: bne         $t6, $zero, L_80801460
    if (ctx->r14 != 0) {
        // 0x808006DC: sll         $t9, $a2, 17
        ctx->r25 = S32(ctx->r6 << 17);
            goto L_80801460;
    }
    // 0x808006DC: sll         $t9, $a2, 17
    ctx->r25 = S32(ctx->r6 << 17);
    // 0x808006E0: bgez        $t9, L_80801460
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808006E4: andi        $t1, $t0, 0xFFFF
        ctx->r9 = ctx->r8 & 0XFFFF;
            goto L_80801460;
    }
    // 0x808006E4: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x808006E8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x808006EC: nop

    // 0x808006F0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808006F4: swc1        $f8, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f8.u32l;
    // 0x808006F8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808006FC: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800700: srl         $t2, $a1, 19
    ctx->r10 = S32(U32(ctx->r5) >> 19);
    // 0x80800704: b           L_80801460
    // 0x80800708: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
        goto L_80801460;
    // 0x80800708: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_8080070C:
    // 0x8080070C: jal         0x808003A8
    // 0x80800710: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808003A8_glsplinecs(rdram, ctx);
        goto after_3;
    // 0x80800710: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800714: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80800718: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X16B4) << 16);
    // 0x8080071C: lwc1        $f6, 0x16B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2698, 0X16B4));
    // 0x80800720: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80800724: srl         $t5, $t4, 19
    ctx->r13 = S32(U32(ctx->r12) >> 19);
    // 0x80800728: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8080072C: addu        $s1, $s5, $t7
    ctx->r17 = ADD32(ctx->r21, ctx->r15);
    // 0x80800730: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x80800734: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080073C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800740: nop

    // 0x80800744: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800748: div.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8080074C: swc1        $f16, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f16.u32l;
    // 0x80800750: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80800754: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x80800758: jal         0x8008A688
    // 0x8080075C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _seqdat_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080075C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_4:
    // 0x80800760: lhu         $t3, 0x24($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X24);
    // 0x80800764: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080076C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80800770: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800774: sh          $t5, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r13;
    // 0x80800778: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x8080077C: srl         $t7, $a1, 17
    ctx->r15 = S32(U32(ctx->r5) >> 17);
    // 0x80800780: jal         0x8008AED4
    // 0x80800784: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800784: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_5:
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: jal         0x8008B1BC
    // 0x80800790: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800790: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_6:
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: jal         0x8008B188
    // 0x8080079C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_7;
    // 0x8080079C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808007A0: jal         0x8008B064
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808007A8: lui         $a1, 0x3727
    ctx->r5 = S32(0X3727 << 16);
    // 0x808007AC: ori         $a1, $a1, 0xC5AC
    ctx->r5 = ctx->r5 | 0XC5AC;
    // 0x808007B0: jal         0x8008B10C
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B10C(rdram, ctx);
        goto after_9;
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808007B8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808007BC: sll         $t6, $v1, 8
    ctx->r14 = S32(ctx->r3 << 8);
    // 0x808007C0: srl         $t8, $t6, 19
    ctx->r24 = S32(U32(ctx->r14) >> 19);
    // 0x808007C4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808007C8: srl         $t1, $v1, 11
    ctx->r9 = S32(U32(ctx->r3) >> 11);
    // 0x808007CC: xor         $t3, $t9, $t1
    ctx->r11 = ctx->r25 ^ ctx->r9;
    // 0x808007D0: sll         $t2, $t3, 19
    ctx->r10 = S32(ctx->r11 << 19);
    // 0x808007D4: srl         $t4, $t2, 8
    ctx->r12 = S32(U32(ctx->r10) >> 8);
    // 0x808007D8: xor         $t5, $t4, $v1
    ctx->r13 = ctx->r12 ^ ctx->r3;
    // 0x808007DC: sll         $a1, $t5, 8
    ctx->r5 = S32(ctx->r13 << 8);
    // 0x808007E0: srl         $t7, $a1, 19
    ctx->r15 = S32(U32(ctx->r5) >> 19);
    // 0x808007E4: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x808007E8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x808007EC: b           L_80801460
    // 0x808007F0: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
        goto L_80801460;
    // 0x808007F0: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_808007F4:
    // 0x808007F4: jal         0x808003A8
    // 0x808007F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808003A8_glsplinecs(rdram, ctx);
        goto after_10;
    // 0x808007F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x808007FC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80800800: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X16B8) << 16);
    // 0x80800804: lwc1        $f10, 0x16B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2698, 0X16B8));
    // 0x80800808: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8080080C: srl         $t9, $t8, 19
    ctx->r25 = S32(U32(ctx->r24) >> 19);
    // 0x80800810: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800814: addu        $t3, $s5, $t1
    ctx->r11 = ADD32(ctx->r21, ctx->r9);
    // 0x80800818: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x8080081C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800820: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800824: nop

    // 0x80800828: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080082C: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800830: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800834: jal         0x8008B1C8
    // 0x80800838: nop

    func_8008B1C8(rdram, ctx);
        goto after_11;
    // 0x80800838: nop

    after_11:
    // 0x8080083C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800840: sll         $t4, $v1, 8
    ctx->r12 = S32(ctx->r3 << 8);
    // 0x80800844: srl         $t5, $t4, 19
    ctx->r13 = S32(U32(ctx->r12) >> 19);
    // 0x80800848: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8080084C: srl         $t6, $v1, 11
    ctx->r14 = S32(U32(ctx->r3) >> 11);
    // 0x80800850: xor         $t8, $t7, $t6
    ctx->r24 = ctx->r15 ^ ctx->r14;
    // 0x80800854: sll         $t9, $t8, 19
    ctx->r25 = S32(ctx->r24 << 19);
    // 0x80800858: srl         $t1, $t9, 8
    ctx->r9 = S32(U32(ctx->r25) >> 8);
    // 0x8080085C: xor         $t3, $t1, $v1
    ctx->r11 = ctx->r9 ^ ctx->r3;
    // 0x80800860: sll         $a1, $t3, 8
    ctx->r5 = S32(ctx->r11 << 8);
    // 0x80800864: srl         $t2, $a1, 19
    ctx->r10 = S32(U32(ctx->r5) >> 19);
    // 0x80800868: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8080086C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80800870: b           L_80801460
    // 0x80800874: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
        goto L_80801460;
    // 0x80800874: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_80800878:
    // 0x80800878: jal         0x808003A8
    // 0x8080087C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808003A8_glsplinecs(rdram, ctx);
        goto after_12;
    // 0x8080087C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x80800880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800884: jal         0x8008B134
    // 0x80800888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_13;
    // 0x80800888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8080088C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800890: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800894: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x80800898: b           L_80801460
    // 0x8080089C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80801460;
    // 0x8080089C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_808008A0:
    // 0x808008A0: jal         0x808003A8
    // 0x808008A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808003A8_glsplinecs(rdram, ctx);
        goto after_14;
    // 0x808008A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x808008A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008AC: jal         0x8008B134
    // 0x808008B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_15;
    // 0x808008B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x808008B4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808008B8: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808008BC: srl         $t5, $a1, 19
    ctx->r13 = S32(U32(ctx->r5) >> 19);
    // 0x808008C0: b           L_80801460
    // 0x808008C4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80801460;
    // 0x808008C4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_808008C8:
    // 0x808008C8: lbu         $t1, 0x65($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X65);
    // 0x808008CC: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x808008D0: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x808008D4: andi        $t3, $t1, 0xFFF7
    ctx->r11 = ctx->r9 & 0XFFF7;
    // 0x808008D8: or          $t2, $t9, $t3
    ctx->r10 = ctx->r25 | ctx->r11;
    // 0x808008DC: sb          $t2, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r10;
    // 0x808008E0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808008E4: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808008E8: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x808008EC: b           L_80801460
    // 0x808008F0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80801460;
    // 0x808008F0: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_808008F4:
    // 0x808008F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808008F8: jal         0x80105BE0
    // 0x808008FC: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    func_80105BE0(rdram, ctx);
        goto after_16;
    // 0x808008FC: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    after_16:
    // 0x80800900: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800904: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800908: srl         $t5, $a1, 19
    ctx->r13 = S32(U32(ctx->r5) >> 19);
    // 0x8080090C: b           L_80801460
    // 0x80800910: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80801460;
    // 0x80800910: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_80800914:
    // 0x80800914: lbu         $t9, 0x7A($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X7A);
    // 0x80800918: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x8080091C: andi        $t1, $t8, 0xE
    ctx->r9 = ctx->r24 & 0XE;
    // 0x80800920: andi        $t3, $t9, 0xFFF1
    ctx->r11 = ctx->r25 & 0XFFF1;
    // 0x80800924: or          $t2, $t1, $t3
    ctx->r10 = ctx->r9 | ctx->r11;
    // 0x80800928: sb          $t2, 0x7A($s3)
    MEM_B(0X7A, ctx->r19) = ctx->r10;
    // 0x8080092C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800930: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800934: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x80800938: b           L_80801460
    // 0x8080093C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80801460;
    // 0x8080093C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_80800940:
    // 0x80800940: lbu         $t8, 0x77($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X77);
    // 0x80800944: andi        $t6, $t0, 0xF
    ctx->r14 = ctx->r8 & 0XF;
    // 0x80800948: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x8080094C: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80800950: sb          $t1, 0x77($s3)
    MEM_B(0X77, ctx->r19) = ctx->r9;
    // 0x80800954: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800958: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x8080095C: srl         $t3, $a1, 19
    ctx->r11 = S32(U32(ctx->r5) >> 19);
    // 0x80800960: b           L_80801460
    // 0x80800964: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80801460;
    // 0x80800964: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_80800968:
    // 0x80800968: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080096C: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x80800970: beq         $t2, $zero, L_80800980
    if (ctx->r10 == 0) {
        // 0x80800974: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80800980;
    }
    // 0x80800974: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800978: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080097C: nop

L_80800980:
    // 0x80800980: jal         0x8008FFE8
    // 0x80800984: swc1        $f0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f0.u32l;
    func_8008FFE8(rdram, ctx);
        goto after_17;
    // 0x80800984: swc1        $f0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x80800988: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8080098C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800990: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800994: jal         0x8010FD38
    // 0x80800998: nop

    func_8010FD38(rdram, ctx);
        goto after_18;
    // 0x80800998: nop

    after_18:
    // 0x8080099C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808009A0: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808009A4: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x808009A8: b           L_80801460
    // 0x808009AC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80801460;
    // 0x808009AC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_808009B0:
    // 0x808009B0: jal         0x800DA544
    // 0x808009B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_19;
    // 0x808009B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x808009B8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808009BC: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808009C0: srl         $t5, $a1, 19
    ctx->r13 = S32(U32(ctx->r5) >> 19);
    // 0x808009C4: b           L_80801460
    // 0x808009C8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80801460;
    // 0x808009C8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_808009CC:
    // 0x808009CC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x808009D0: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x808009D4: andi        $a2, $t0, 0xFFFF
    ctx->r6 = ctx->r8 & 0XFFFF;
    // 0x808009D8: sll         $t7, $a0, 21
    ctx->r15 = S32(ctx->r4 << 21);
    // 0x808009DC: jal         0x800D7708
    // 0x808009E0: sra         $a0, $t7, 22
    ctx->r4 = S32(SIGNED(ctx->r15) >> 22);
    func_800D7708(rdram, ctx);
        goto after_20;
    // 0x808009E0: sra         $a0, $t7, 22
    ctx->r4 = S32(SIGNED(ctx->r15) >> 22);
    after_20:
    // 0x808009E4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808009E8: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x808009EC: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808009F0: srl         $t6, $a1, 19
    ctx->r14 = S32(U32(ctx->r5) >> 19);
    // 0x808009F4: b           L_80801460
    // 0x808009F8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
        goto L_80801460;
    // 0x808009F8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_808009FC:
    // 0x808009FC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80800A00: addiu       $t2, $sp, 0xC4
    ctx->r10 = ADD32(ctx->r29, 0XC4);
    // 0x80800A04: addiu       $t4, $sp, 0xC0
    ctx->r12 = ADD32(ctx->r29, 0XC0);
    // 0x80800A08: sll         $t1, $t9, 21
    ctx->r9 = S32(ctx->r25 << 21);
    // 0x80800A0C: sra         $t3, $t1, 22
    ctx->r11 = S32(SIGNED(ctx->r9) >> 22);
    // 0x80800A10: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800A14: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80800A18: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800A1C: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    // 0x80800A20: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x80800A24: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x80800A28: jal         0x80088470
    // 0x80800A2C: addiu       $a3, $sp, 0xC8
    ctx->r7 = ADD32(ctx->r29, 0XC8);
    _glsplinefuncs_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x80800A2C: addiu       $a3, $sp, 0xC8
    ctx->r7 = ADD32(ctx->r29, 0XC8);
    after_21:
    // 0x80800A30: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x80800A34: lh          $t1, 0x2($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X2);
    // 0x80800A38: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80800A3C: andi        $t9, $t6, 0x7FE
    ctx->r25 = ctx->r14 & 0X7FE;
    // 0x80800A40: andi        $t3, $t1, 0xF801
    ctx->r11 = ctx->r9 & 0XF801;
    // 0x80800A44: or          $t2, $t9, $t3
    ctx->r10 = ctx->r25 | ctx->r11;
    // 0x80800A48: sh          $t2, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r10;
    // 0x80800A4C: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80800A50: swc1        $f18, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f18.u32l;
    // 0x80800A54: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80800A58: swc1        $f6, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f6.u32l;
    // 0x80800A5C: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80800A60: swc1        $f16, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f16.u32l;
    // 0x80800A64: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80800A68: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
    // 0x80800A6C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800A70: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800A74: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x80800A78: b           L_80801460
    // 0x80800A7C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80801460;
    // 0x80800A7C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_80800A80:
    // 0x80800A80: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80800A84: andi        $t5, $v0, 0x8000
    ctx->r13 = ctx->r2 & 0X8000;
    // 0x80800A88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A8C: beq         $t5, $zero, L_80800AA0
    if (ctx->r13 == 0) {
        // 0x80800A90: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800AA0;
    }
    // 0x80800A90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800A94: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800A98: b           L_80800AA0
    // 0x80800A9C: or          $v1, $v0, $at
    ctx->r3 = ctx->r2 | ctx->r1;
        goto L_80800AA0;
    // 0x80800A9C: or          $v1, $v0, $at
    ctx->r3 = ctx->r2 | ctx->r1;
L_80800AA0:
    // 0x80800AA0: bltz        $v1, L_80800AB0
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800AA4: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_80800AB0;
    }
    // 0x80800AA4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80800AA8: b           L_80800AB0
    // 0x80800AAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800AB0;
    // 0x80800AAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800AB0:
    // 0x80800AB0: bgez        $v1, L_80800ACC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80800AB4: nop
    
            goto L_80800ACC;
    }
    // 0x80800AB4: nop

    // 0x80800AB8: lbu         $t7, 0x79($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X79);
    // 0x80800ABC: andi        $t8, $t7, 0xFFFC
    ctx->r24 = ctx->r15 & 0XFFFC;
    // 0x80800AC0: ori         $t6, $t8, 0x2
    ctx->r14 = ctx->r24 | 0X2;
    // 0x80800AC4: b           L_80800AF0
    // 0x80800AC8: sb          $t6, 0x79($s3)
    MEM_B(0X79, ctx->r19) = ctx->r14;
        goto L_80800AF0;
    // 0x80800AC8: sb          $t6, 0x79($s3)
    MEM_B(0X79, ctx->r19) = ctx->r14;
L_80800ACC:
    // 0x80800ACC: blez        $v1, L_80800ADC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800AD0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800ADC;
    }
    // 0x80800AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AD4: b           L_80800ADC
    // 0x80800AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800ADC;
    // 0x80800AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800ADC:
    // 0x80800ADC: lbu         $t3, 0x79($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X79);
    // 0x80800AE0: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x80800AE4: andi        $t2, $t3, 0xFFFC
    ctx->r10 = ctx->r11 & 0XFFFC;
    // 0x80800AE8: or          $t4, $t9, $t2
    ctx->r12 = ctx->r25 | ctx->r10;
    // 0x80800AEC: sb          $t4, 0x79($s3)
    MEM_B(0X79, ctx->r19) = ctx->r12;
L_80800AF0:
    // 0x80800AF0: beql        $v0, $zero, L_80800B18
    if (ctx->r2 == 0) {
        // 0x80800AF4: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80800B18;
    }
    goto skip_17;
    // 0x80800AF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_17:
    // 0x80800AF8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80800AFC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800B00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B04: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800B08: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800B0C: b           L_80800B20
    // 0x80800B10: swc1        $f6, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f6.u32l;
        goto L_80800B20;
    // 0x80800B10: swc1        $f6, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f6.u32l;
    // 0x80800B14: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80800B18:
    // 0x80800B18: nop

    // 0x80800B1C: swc1        $f16, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f16.u32l;
L_80800B20:
    // 0x80800B20: swc1        $f4, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f4.u32l;
    // 0x80800B24: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800B28: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800B2C: srl         $t5, $a1, 19
    ctx->r13 = S32(U32(ctx->r5) >> 19);
    // 0x80800B30: b           L_80801460
    // 0x80800B34: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80801460;
    // 0x80800B34: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_80800B38:
    // 0x80800B38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B3C: jal         0x80089C98
    // 0x80800B40: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x80800B40: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    after_22:
    // 0x80800B44: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800B48: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800B4C: srl         $t7, $a1, 19
    ctx->r15 = S32(U32(ctx->r5) >> 19);
    // 0x80800B50: b           L_80801460
    // 0x80800B54: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80801460;
    // 0x80800B54: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80800B58:
    // 0x80800B58: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80800B5C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80800B60: addiu       $t1, $t1, -0x7BA0
    ctx->r9 = ADD32(ctx->r9, -0X7BA0);
    // 0x80800B64: sra         $a1, $v0, 24
    ctx->r5 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80800B68: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80800B6C: andi        $t6, $a3, 0xF
    ctx->r14 = ctx->r7 & 0XF;
    // 0x80800B70: andi        $t8, $a1, 0x3F
    ctx->r24 = ctx->r5 & 0X3F;
    // 0x80800B74: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80800B78: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80800B7C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800B80: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    // 0x80800B84: jal         0x800C04C8
    // 0x80800B88: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    func_800C04C8(rdram, ctx);
        goto after_23;
    // 0x80800B88: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    after_23:
    // 0x80800B8C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800B90: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
    // 0x80800B94: srl         $t9, $t3, 19
    ctx->r25 = S32(U32(ctx->r11) >> 19);
    // 0x80800B98: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80800B9C: srl         $t4, $v1, 11
    ctx->r12 = S32(U32(ctx->r3) >> 11);
    // 0x80800BA0: xor         $t5, $t2, $t4
    ctx->r13 = ctx->r10 ^ ctx->r12;
    // 0x80800BA4: sll         $t7, $t5, 19
    ctx->r15 = S32(ctx->r13 << 19);
    // 0x80800BA8: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x80800BAC: xor         $t6, $t8, $v1
    ctx->r14 = ctx->r24 ^ ctx->r3;
    // 0x80800BB0: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x80800BB4: srl         $t1, $a1, 19
    ctx->r9 = S32(U32(ctx->r5) >> 19);
    // 0x80800BB8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80800BBC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80800BC0: b           L_80801460
    // 0x80800BC4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_80801460;
    // 0x80800BC4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80800BC8:
    // 0x80800BC8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80800BCC: andi        $t3, $a0, 0x3FFF
    ctx->r11 = ctx->r4 & 0X3FFF;
    // 0x80800BD0: jal         0x80082668
    // 0x80800BD4: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    _seqdefine_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x80800BD4: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_24:
    // 0x80800BD8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80800BDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BE4: sll         $t2, $t9, 8
    ctx->r10 = S32(ctx->r25 << 8);
    // 0x80800BE8: srl         $t4, $t2, 19
    ctx->r12 = S32(U32(ctx->r10) >> 19);
    // 0x80800BEC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800BF0: addu        $t7, $s5, $t5
    ctx->r15 = ADD32(ctx->r21, ctx->r13);
    // 0x80800BF4: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80800BF8: andi        $t1, $t6, 0x4000
    ctx->r9 = ctx->r14 & 0X4000;
    // 0x80800BFC: beq         $t1, $zero, L_80800C0C
    if (ctx->r9 == 0) {
        // 0x80800C00: nop
    
            goto L_80800C0C;
    }
    // 0x80800C00: nop

    // 0x80800C04: b           L_80800C0C
    // 0x80800C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800C0C;
    // 0x80800C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800C0C:
    // 0x80800C0C: jal         0x800DA3B8
    // 0x80800C10: nop

    func_800DA3B8(rdram, ctx);
        goto after_25;
    // 0x80800C10: nop

    after_25:
    // 0x80800C14: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800C18: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800C1C: srl         $t3, $a1, 19
    ctx->r11 = S32(U32(ctx->r5) >> 19);
    // 0x80800C20: b           L_80801460
    // 0x80800C24: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80801460;
    // 0x80800C24: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_80800C28:
    // 0x80800C28: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80800C2C: bne         $v0, $zero, L_80800C3C
    if (ctx->r2 != 0) {
        // 0x80800C30: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80800C3C;
    }
    // 0x80800C30: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80800C34: b           L_80800C44
    // 0x80800C38: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
        goto L_80800C44;
    // 0x80800C38: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
L_80800C3C:
    // 0x80800C3C: addu        $t2, $s4, $t9
    ctx->r10 = ADD32(ctx->r20, ctx->r25);
    // 0x80800C40: lw          $a1, 0x100($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X100);
L_80800C44:
    // 0x80800C44: jal         0x800FFA88
    // 0x80800C48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800FFA88(rdram, ctx);
        goto after_26;
    // 0x80800C48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_26:
    // 0x80800C4C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800C50: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800C54: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x80800C58: b           L_80801460
    // 0x80800C5C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80801460;
    // 0x80800C5C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_80800C60:
    // 0x80800C60: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80800C64: bne         $v0, $zero, L_80800C74
    if (ctx->r2 != 0) {
        // 0x80800C68: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80800C74;
    }
    // 0x80800C68: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80800C6C: b           L_80800C7C
    // 0x80800C70: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
        goto L_80800C7C;
    // 0x80800C70: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
L_80800C74:
    // 0x80800C74: addu        $t7, $s4, $t5
    ctx->r15 = ADD32(ctx->r20, ctx->r13);
    // 0x80800C78: lw          $a1, 0x100($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X100);
L_80800C7C:
    // 0x80800C7C: jal         0x800FFA88
    // 0x80800C80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800FFA88(rdram, ctx);
        goto after_27;
    // 0x80800C80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_27:
    // 0x80800C84: jal         0x800A50B0
    // 0x80800C88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800A50B0(rdram, ctx);
        goto after_28;
    // 0x80800C88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_28:
    // 0x80800C8C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800C90: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800C94: srl         $t8, $a1, 19
    ctx->r24 = S32(U32(ctx->r5) >> 19);
    // 0x80800C98: b           L_80801460
    // 0x80800C9C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_80801460;
    // 0x80800C9C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_80800CA0:
    // 0x80800CA0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80800CA4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80800CA8: addiu       $a0, $a0, -0x7B88
    ctx->r4 = ADD32(ctx->r4, -0X7B88);
    // 0x80800CAC: sll         $t6, $a3, 21
    ctx->r14 = S32(ctx->r7 << 21);
    // 0x80800CB0: sra         $a3, $t6, 22
    ctx->r7 = S32(SIGNED(ctx->r14) >> 22);
    // 0x80800CB4: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x80800CB8: jal         0x80086D40
    // 0x80800CBC: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    _chbaddiesetup_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x80800CBC: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    after_29:
    // 0x80800CC0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800CC4: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
    // 0x80800CC8: srl         $t9, $t3, 19
    ctx->r25 = S32(U32(ctx->r11) >> 19);
    // 0x80800CCC: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80800CD0: srl         $t4, $v1, 11
    ctx->r12 = S32(U32(ctx->r3) >> 11);
    // 0x80800CD4: xor         $t5, $t2, $t4
    ctx->r13 = ctx->r10 ^ ctx->r12;
    // 0x80800CD8: sll         $t7, $t5, 19
    ctx->r15 = S32(ctx->r13 << 19);
    // 0x80800CDC: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x80800CE0: xor         $t6, $t8, $v1
    ctx->r14 = ctx->r24 ^ ctx->r3;
    // 0x80800CE4: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x80800CE8: srl         $t1, $a1, 19
    ctx->r9 = S32(U32(ctx->r5) >> 19);
    // 0x80800CEC: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80800CF0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80800CF4: b           L_80801460
    // 0x80800CF8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_80801460;
    // 0x80800CF8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80800CFC:
    // 0x80800CFC: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x80800D00: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80800D04: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800D08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800D10: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800D14: swc1        $f6, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f6.u32l;
    // 0x80800D18: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80800D1C: bnel        $s7, $t9, L_80801464
    if (ctx->r23 != ctx->r25) {
        // 0x80800D20: addiu       $t8, $a1, 0x2
        ctx->r24 = ADD32(ctx->r5, 0X2);
            goto L_80801464;
    }
    goto skip_18;
    // 0x80800D20: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    skip_18:
    // 0x80800D24: lwc1        $f16, 0x190($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800D28: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800D2C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800D30: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80800D34: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800D38: srl         $t2, $a1, 19
    ctx->r10 = S32(U32(ctx->r5) >> 19);
    // 0x80800D3C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80800D40: b           L_80801460
    // 0x80800D44: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
        goto L_80801460;
    // 0x80800D44: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
L_80800D48:
    // 0x80800D48: lbu         $t1, 0x26($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X26);
    // 0x80800D4C: addiu       $t7, $t0, -0x69
    ctx->r15 = ADD32(ctx->r8, -0X69);
    // 0x80800D50: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800D54: andi        $t6, $t8, 0x1E
    ctx->r14 = ctx->r24 & 0X1E;
    // 0x80800D58: andi        $t3, $t1, 0xFFE1
    ctx->r11 = ctx->r9 & 0XFFE1;
    // 0x80800D5C: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x80800D60: sb          $t9, 0x26($s2)
    MEM_B(0X26, ctx->r18) = ctx->r25;
    // 0x80800D64: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80800D68: bnel        $s7, $t2, L_80801464
    if (ctx->r23 != ctx->r10) {
        // 0x80800D6C: addiu       $t8, $a1, 0x2
        ctx->r24 = ADD32(ctx->r5, 0X2);
            goto L_80801464;
    }
    goto skip_19;
    // 0x80800D6C: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    skip_19:
    // 0x80800D70: lwc1        $f10, 0x190($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800D74: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800D78: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800D7C: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80800D80: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800D84: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x80800D88: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80800D8C: b           L_80801460
    // 0x80800D90: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
        goto L_80801460;
    // 0x80800D90: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
L_80800D94:
    // 0x80800D94: andi        $t5, $t0, 0xFFFF
    ctx->r13 = ctx->r8 & 0XFFFF;
    // 0x80800D98: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80800D9C: nop

    // 0x80800DA0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800DA4: b           L_80801460
    // 0x80800DA8: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
        goto L_80801460;
    // 0x80800DA8: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
L_80800DAC:
    // 0x80800DAC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800DB0: sll         $t3, $t1, 7
    ctx->r11 = S32(ctx->r9 << 7);
    // 0x80800DB4: andi        $t9, $v0, 0x7F
    ctx->r25 = ctx->r2 & 0X7F;
    // 0x80800DB8: or          $t2, $t3, $t9
    ctx->r10 = ctx->r11 | ctx->r25;
    // 0x80800DBC: sh          $t2, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r10;
    // 0x80800DC0: lbu         $t4, 0x2B($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X2B);
    // 0x80800DC4: andi        $t5, $t4, 0xFFBF
    ctx->r13 = ctx->r12 & 0XFFBF;
    // 0x80800DC8: sb          $t5, 0x2B($s2)
    MEM_B(0X2B, ctx->r18) = ctx->r13;
    // 0x80800DCC: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80800DD0: bnel        $s7, $t7, L_80801464
    if (ctx->r23 != ctx->r15) {
        // 0x80800DD4: addiu       $t8, $a1, 0x2
        ctx->r24 = ADD32(ctx->r5, 0X2);
            goto L_80801464;
    }
    goto skip_20;
    // 0x80800DD4: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    skip_20:
    // 0x80800DD8: lwc1        $f8, 0x190($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800DDC: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800DE0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800DE4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800DE8: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800DEC: srl         $t8, $a1, 19
    ctx->r24 = S32(U32(ctx->r5) >> 19);
    // 0x80800DF0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80800DF4: b           L_80801460
    // 0x80800DF8: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
        goto L_80801460;
    // 0x80800DF8: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
L_80800DFC:
    // 0x80800DFC: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x80800E00: sll         $t2, $t3, 7
    ctx->r10 = S32(ctx->r11 << 7);
    // 0x80800E04: andi        $t4, $v0, 0x7F
    ctx->r12 = ctx->r2 & 0X7F;
    // 0x80800E08: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800E0C: sh          $t5, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r13;
    // 0x80800E10: lbu         $t8, 0x2B($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X2B);
    // 0x80800E14: ori         $t1, $t8, 0x40
    ctx->r9 = ctx->r24 | 0X40;
    // 0x80800E18: sb          $t1, 0x2B($s2)
    MEM_B(0X2B, ctx->r18) = ctx->r9;
    // 0x80800E1C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80800E20: bnel        $s7, $t6, L_80801464
    if (ctx->r23 != ctx->r14) {
        // 0x80800E24: addiu       $t8, $a1, 0x2
        ctx->r24 = ADD32(ctx->r5, 0X2);
            goto L_80801464;
    }
    goto skip_21;
    // 0x80800E24: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    skip_21:
    // 0x80800E28: lwc1        $f6, 0x190($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800E2C: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800E30: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800E34: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80800E38: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800E3C: srl         $t3, $a1, 19
    ctx->r11 = S32(U32(ctx->r5) >> 19);
    // 0x80800E40: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80800E44: b           L_80801460
    // 0x80800E48: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
        goto L_80801460;
    // 0x80800E48: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
L_80800E4C:
    // 0x80800E4C: jal         0x800DA544
    // 0x80800E50: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    func_800DA544(rdram, ctx);
        goto after_30;
    // 0x80800E50: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    after_30:
    // 0x80800E54: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800E58: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800E5C: srl         $t9, $a1, 19
    ctx->r25 = S32(U32(ctx->r5) >> 19);
    // 0x80800E60: b           L_80801460
    // 0x80800E64: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
        goto L_80801460;
    // 0x80800E64: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_80800E68:
    // 0x80800E68: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80800E6C: sra         $v1, $v0, 12
    ctx->r3 = S32(SIGNED(ctx->r2) >> 12);
    // 0x80800E70: andi        $t2, $v1, 0x3F
    ctx->r10 = ctx->r3 & 0X3F;
    // 0x80800E74: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80800E78: bne         $t2, $zero, L_80800E88
    if (ctx->r10 != 0) {
        // 0x80800E7C: andi        $s0, $v0, 0xFFF
        ctx->r16 = ctx->r2 & 0XFFF;
            goto L_80800E88;
    }
    // 0x80800E7C: andi        $s0, $v0, 0xFFF
    ctx->r16 = ctx->r2 & 0XFFF;
    // 0x80800E80: b           L_80800E9C
    // 0x80800E84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80800E9C;
    // 0x80800E84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800E88:
    // 0x80800E88: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80800E8C: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x80800E90: jal         0x80106790
    // 0x80800E94: lw          $a0, 0x100($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X100);
    func_80106790(rdram, ctx);
        goto after_31;
    // 0x80800E94: lw          $a0, 0x100($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X100);
    after_31:
    // 0x80800E98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800E9C:
    // 0x80800E9C: jal         0x80105494
    // 0x80800EA0: nop

    func_80105494(rdram, ctx);
        goto after_32;
    // 0x80800EA0: nop

    after_32:
    // 0x80800EA4: sb          $s0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r16;
    // 0x80800EA8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800EAC: lwc1        $f8, 0x190($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800EB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800EB4: srl         $t7, $a0, 11
    ctx->r15 = S32(U32(ctx->r4) >> 11);
    // 0x80800EB8: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x80800EBC: srl         $t1, $t8, 8
    ctx->r9 = S32(U32(ctx->r24) >> 8);
    // 0x80800EC0: xor         $t6, $t1, $a0
    ctx->r14 = ctx->r9 ^ ctx->r4;
    // 0x80800EC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80800EC8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80800ECC: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x80800ED0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800ED4: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800ED8: srl         $t3, $a1, 19
    ctx->r11 = S32(U32(ctx->r5) >> 19);
    // 0x80800EDC: b           L_80801460
    // 0x80800EE0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80801460;
    // 0x80800EE0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_80800EE4:
    // 0x80800EE4: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80800EE8: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x80800EEC: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80800EF0: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x80800EF4: sw          $t9, 0x100($t5)
    MEM_W(0X100, ctx->r13) = ctx->r25;
    // 0x80800EF8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800EFC: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800F00: srl         $t7, $a1, 19
    ctx->r15 = S32(U32(ctx->r5) >> 19);
    // 0x80800F04: b           L_80801460
    // 0x80800F08: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80801460;
    // 0x80800F08: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80800F0C:
    // 0x80800F0C: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80800F10: bne         $v0, $zero, L_80800F20
    if (ctx->r2 != 0) {
        // 0x80800F14: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80800F20;
    }
    // 0x80800F14: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800F18: b           L_80800F30
    // 0x80800F1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80800F30;
    // 0x80800F1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800F20:
    // 0x80800F20: addu        $t1, $s4, $t8
    ctx->r9 = ADD32(ctx->r20, ctx->r24);
    // 0x80800F24: jal         0x80106790
    // 0x80800F28: lw          $a0, 0x100($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X100);
    func_80106790(rdram, ctx);
        goto after_33;
    // 0x80800F28: lw          $a0, 0x100($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X100);
    after_33:
    // 0x80800F2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800F30:
    // 0x80800F30: jal         0x80105494
    // 0x80800F34: nop

    func_80105494(rdram, ctx);
        goto after_34;
    // 0x80800F34: nop

    after_34:
    // 0x80800F38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X16BC) << 16);
    // 0x80800F3C: lwc1        $f18, 0x16BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2698, 0X16BC));
    // 0x80800F40: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x80800F44: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80800F48: bnel        $s7, $t6, L_80800F64
    if (ctx->r23 != ctx->r14) {
        // 0x80800F4C: lw          $v1, 0x0($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X0);
            goto L_80800F64;
    }
    goto skip_22;
    // 0x80800F4C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    skip_22:
    // 0x80800F50: lwc1        $f6, 0x190($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80800F54: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800F58: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80800F5C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80800F60: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80800F64:
    // 0x80800F64: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800F68: srl         $t3, $a1, 19
    ctx->r11 = S32(U32(ctx->r5) >> 19);
    // 0x80800F6C: b           L_80801460
    // 0x80800F70: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80801460;
    // 0x80800F70: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_80800F74:
    // 0x80800F74: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x80800F78: bne         $v0, $zero, L_80800F88
    if (ctx->r2 != 0) {
        // 0x80800F7C: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80800F88;
    }
    // 0x80800F7C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80800F80: b           L_80800F98
    // 0x80800F84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80800F98;
    // 0x80800F84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800F88:
    // 0x80800F88: addu        $t4, $s4, $t2
    ctx->r12 = ADD32(ctx->r20, ctx->r10);
    // 0x80800F8C: jal         0x80106790
    // 0x80800F90: lw          $a0, 0x100($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X100);
    func_80106790(rdram, ctx);
        goto after_35;
    // 0x80800F90: lw          $a0, 0x100($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X100);
    after_35:
    // 0x80800F94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800F98:
    // 0x80800F98: jal         0x80105494
    // 0x80800F9C: nop

    func_80105494(rdram, ctx);
        goto after_36;
    // 0x80800F9C: nop

    after_36:
    // 0x80800FA0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800FA4: nop

    // 0x80800FA8: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80800FAC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80800FB0: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80800FB4: srl         $t9, $a1, 19
    ctx->r25 = S32(U32(ctx->r5) >> 19);
    // 0x80800FB8: b           L_80801460
    // 0x80800FBC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
        goto L_80801460;
    // 0x80800FBC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_80800FC0:
    // 0x80800FC0: sra         $s0, $t0, 6
    ctx->r16 = S32(SIGNED(ctx->r8) >> 6);
    // 0x80800FC4: andi        $t5, $s0, 0x3F
    ctx->r13 = ctx->r16 & 0X3F;
    // 0x80800FC8: andi        $v1, $t0, 0x3F
    ctx->r3 = ctx->r8 & 0X3F;
    // 0x80800FCC: bne         $v1, $zero, L_80800FDC
    if (ctx->r3 != 0) {
        // 0x80800FD0: or          $s0, $t5, $zero
        ctx->r16 = ctx->r13 | 0;
            goto L_80800FDC;
    }
    // 0x80800FD0: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    // 0x80800FD4: b           L_80800FF0
    // 0x80800FD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80800FF0;
    // 0x80800FD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800FDC:
    // 0x80800FDC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80800FE0: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x80800FE4: jal         0x80106790
    // 0x80800FE8: lw          $a0, 0x100($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X100);
    func_80106790(rdram, ctx);
        goto after_37;
    // 0x80800FE8: lw          $a0, 0x100($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X100);
    after_37:
    // 0x80800FEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800FF0:
    // 0x80800FF0: jal         0x80105494
    // 0x80800FF4: nop

    func_80105494(rdram, ctx);
        goto after_38;
    // 0x80800FF4: nop

    after_38:
    // 0x80800FF8: lhu         $t9, 0x26($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X26);
    // 0x80800FFC: lbu         $t3, 0x2B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2B);
    // 0x80801000: andi        $t6, $s0, 0x3F
    ctx->r14 = ctx->r16 & 0X3F;
    // 0x80801004: andi        $t5, $t9, 0xFE3F
    ctx->r13 = ctx->r25 & 0XFE3F;
    // 0x80801008: sh          $t5, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r13;
    // 0x8080100C: lbu         $t7, 0x26($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X26);
    // 0x80801010: andi        $t2, $t3, 0xFFC0
    ctx->r10 = ctx->r11 & 0XFFC0;
    // 0x80801014: or          $t4, $t6, $t2
    ctx->r12 = ctx->r14 | ctx->r10;
    // 0x80801018: andi        $t1, $t7, 0xFFDF
    ctx->r9 = ctx->r15 & 0XFFDF;
    // 0x8080101C: andi        $t6, $t1, 0x7F
    ctx->r14 = ctx->r9 & 0X7F;
    // 0x80801020: sb          $t1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r9;
    // 0x80801024: sb          $t6, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r14;
    // 0x80801028: andi        $t2, $t6, 0xBF
    ctx->r10 = ctx->r14 & 0XBF;
    // 0x8080102C: sb          $t4, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r12;
    // 0x80801030: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
    // 0x80801034: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801038: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x8080103C: srl         $t4, $a1, 19
    ctx->r12 = S32(U32(ctx->r5) >> 19);
    // 0x80801040: b           L_80801460
    // 0x80801044: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80801460;
    // 0x80801044: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_80801048:
    // 0x80801048: andi        $t9, $t0, 0xFFFF
    ctx->r25 = ctx->r8 & 0XFFFF;
    // 0x8080104C: beq         $t9, $zero, L_8080105C
    if (ctx->r25 == 0) {
        // 0x80801050: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8080105C;
    }
    // 0x80801050: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801054: b           L_8080105C
    // 0x80801058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8080105C;
    // 0x80801058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8080105C:
    // 0x8080105C: jal         0x80090708
    // 0x80801060: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80090708(rdram, ctx);
        goto after_39;
    // 0x80801060: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_39:
    // 0x80801064: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801068: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x8080106C: srl         $t5, $a1, 19
    ctx->r13 = S32(U32(ctx->r5) >> 19);
    // 0x80801070: b           L_80801460
    // 0x80801074: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80801460;
    // 0x80801074: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_80801078:
    // 0x80801078: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    // 0x8080107C: beq         $a0, $zero, L_80801184
    if (ctx->r4 == 0) {
        // 0x80801080: sll         $t2, $a2, 23
        ctx->r10 = S32(ctx->r6 << 23);
            goto L_80801184;
    }
    // 0x80801080: sll         $t2, $a2, 23
    ctx->r10 = S32(ctx->r6 << 23);
    // 0x80801084: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801088: jal         0x80089C80
    // 0x8080108C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    _subaddiefind_entrypoint_12(rdram, ctx);
        goto after_40;
    // 0x8080108C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    after_40:
    // 0x80801090: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80801094: bne         $v0, $zero, L_808010A8
    if (ctx->r2 != 0) {
        // 0x80801098: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808010A8;
    }
    // 0x80801098: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080109C: jal         0x80088300
    // 0x808010A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_17(rdram, ctx);
        goto after_41;
    // 0x808010A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x808010A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808010A8:
    // 0x808010A8: lbu         $t1, 0x26($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X26);
    // 0x808010AC: lbu         $t7, 0x2B($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X2B);
    // 0x808010B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808010B4: andi        $t6, $t1, 0xFFDF
    ctx->r14 = ctx->r9 & 0XFFDF;
    // 0x808010B8: andi        $t4, $t6, 0x7F
    ctx->r12 = ctx->r14 & 0X7F;
    // 0x808010BC: sb          $t6, 0x26($s2)
    MEM_B(0X26, ctx->r18) = ctx->r14;
    // 0x808010C0: sb          $t4, 0x26($s2)
    MEM_B(0X26, ctx->r18) = ctx->r12;
    // 0x808010C4: andi        $t9, $t4, 0xBF
    ctx->r25 = ctx->r12 & 0XBF;
    // 0x808010C8: andi        $t8, $t7, 0xFFC0
    ctx->r24 = ctx->r15 & 0XFFC0;
    // 0x808010CC: sb          $t8, 0x2B($s2)
    MEM_B(0X2B, ctx->r18) = ctx->r24;
    // 0x808010D0: sb          $t9, 0x26($s2)
    MEM_B(0X26, ctx->r18) = ctx->r25;
L_808010D4:
    // 0x808010D4: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808010D8: lw          $t5, 0x1A4($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X1A4);
    // 0x808010DC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x808010E0: mflo        $t7
    ctx->r15 = lo;
    // 0x808010E4: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    // 0x808010E8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808010EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x808010F0: sra         $t1, $t8, 31
    ctx->r9 = S32(SIGNED(ctx->r24) >> 31);
    // 0x808010F4: bnel        $t1, $zero, L_80801170
    if (ctx->r9 != 0) {
        // 0x808010F8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80801170;
    }
    goto skip_23;
    // 0x808010F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_23:
    // 0x808010FC: lhu         $t9, 0x26($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X26);
    // 0x80801100: sll         $t2, $t6, 6
    ctx->r10 = S32(ctx->r14 << 6);
    // 0x80801104: andi        $t4, $t2, 0x1C0
    ctx->r12 = ctx->r10 & 0X1C0;
    // 0x80801108: andi        $t5, $t9, 0xFE3F
    ctx->r13 = ctx->r25 & 0XFE3F;
    // 0x8080110C: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80801110: beq         $s1, $zero, L_8080113C
    if (ctx->r17 == 0) {
        // 0x80801114: sh          $t7, 0x26($s2)
        MEM_H(0X26, ctx->r18) = ctx->r15;
            goto L_8080113C;
    }
    // 0x80801114: sh          $t7, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r15;
    // 0x80801118: lb          $t1, 0x0($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X0);
    // 0x8080111C: ori         $t3, $t1, 0x80
    ctx->r11 = ctx->r9 | 0X80;
    // 0x80801120: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x80801124: lb          $t6, 0x0($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X0);
    // 0x80801128: andi        $t2, $t6, 0xFFBF
    ctx->r10 = ctx->r14 & 0XFFBF;
    // 0x8080112C: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x80801130: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80801134: b           L_80801168
    // 0x80801138: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
        goto L_80801168;
    // 0x80801138: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
L_8080113C:
    // 0x8080113C: beql        $s0, $zero, L_8080116C
    if (ctx->r16 == 0) {
        // 0x80801140: addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
            goto L_8080116C;
    }
    goto skip_24;
    // 0x80801140: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    skip_24:
    // 0x80801144: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080114C: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
    // 0x80801150: ori         $t7, $t5, 0x80
    ctx->r15 = ctx->r13 | 0X80;
    // 0x80801154: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80801158: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x8080115C: ori         $t3, $t1, 0x40
    ctx->r11 = ctx->r9 | 0X40;
    // 0x80801160: jal         0x80088BF8
    // 0x80801164: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    _gspropctrl_entrypoint_10(rdram, ctx);
        goto after_42;
    // 0x80801164: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    after_42:
L_80801168:
    // 0x80801168: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_8080116C:
    // 0x8080116C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801170:
    // 0x80801170: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x80801174: bne         $at, $zero, L_808010D4
    if (ctx->r1 != 0) {
        // 0x80801178: nop
    
            goto L_808010D4;
    }
    // 0x80801178: nop

    // 0x8080117C: b           L_808011BC
    // 0x80801180: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
        goto L_808011BC;
    // 0x80801180: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_80801184:
    // 0x80801184: srl         $t9, $t2, 29
    ctx->r25 = S32(U32(ctx->r10) >> 29);
    // 0x80801188: lw          $t6, 0x1A4($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X1A4);
    // 0x8080118C: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80801190: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x80801194: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80801198: addu        $v0, $t6, $t4
    ctx->r2 = ADD32(ctx->r14, ctx->r12);
    // 0x8080119C: lb          $t5, -0xC($v0)
    ctx->r13 = MEM_B(ctx->r2, -0XC);
    // 0x808011A0: addiu       $v0, $v0, -0xC
    ctx->r2 = ADD32(ctx->r2, -0XC);
    // 0x808011A4: andi        $t7, $t5, 0xFF7F
    ctx->r15 = ctx->r13 & 0XFF7F;
    // 0x808011A8: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x808011AC: lhu         $t8, 0x26($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X26);
    // 0x808011B0: andi        $t1, $t8, 0xFE3F
    ctx->r9 = ctx->r24 & 0XFE3F;
    // 0x808011B4: sh          $t1, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r9;
    // 0x808011B8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_808011BC:
    // 0x808011BC: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808011C0: srl         $t3, $a1, 19
    ctx->r11 = S32(U32(ctx->r5) >> 19);
    // 0x808011C4: b           L_80801460
    // 0x808011C8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
        goto L_80801460;
    // 0x808011C8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_808011CC:
    // 0x808011CC: andi        $t2, $t0, 0xFFFF
    ctx->r10 = ctx->r8 & 0XFFFF;
    // 0x808011D0: beql        $t2, $zero, L_808011EC
    if (ctx->r10 == 0) {
        // 0x808011D4: lbu         $t5, 0x65($s3)
        ctx->r13 = MEM_BU(ctx->r19, 0X65);
            goto L_808011EC;
    }
    goto skip_25;
    // 0x808011D4: lbu         $t5, 0x65($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X65);
    skip_25:
    // 0x808011D8: lbu         $t6, 0x65($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X65);
    // 0x808011DC: ori         $t4, $t6, 0x4
    ctx->r12 = ctx->r14 | 0X4;
    // 0x808011E0: b           L_808011F4
    // 0x808011E4: sb          $t4, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r12;
        goto L_808011F4;
    // 0x808011E4: sb          $t4, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r12;
    // 0x808011E8: lbu         $t5, 0x65($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X65);
L_808011EC:
    // 0x808011EC: andi        $t7, $t5, 0xFFFB
    ctx->r15 = ctx->r13 & 0XFFFB;
    // 0x808011F0: sb          $t7, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r15;
L_808011F4:
    // 0x808011F4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808011F8: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808011FC: srl         $t8, $a1, 19
    ctx->r24 = S32(U32(ctx->r5) >> 19);
    // 0x80801200: b           L_80801460
    // 0x80801204: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_80801460;
    // 0x80801204: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_80801208:
    // 0x80801208: andi        $v0, $t0, 0xFFFF
    ctx->r2 = ctx->r8 & 0XFFFF;
    // 0x8080120C: addu        $a0, $s4, $v0
    ctx->r4 = ADD32(ctx->r20, ctx->r2);
    // 0x80801210: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x80801214: beq         $a2, $zero, L_80801244
    if (ctx->r6 == 0) {
        // 0x80801218: addiu       $t1, $a2, -0x1
        ctx->r9 = ADD32(ctx->r6, -0X1);
            goto L_80801244;
    }
    // 0x80801218: addiu       $t1, $a2, -0x1
    ctx->r9 = ADD32(ctx->r6, -0X1);
    // 0x8080121C: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x80801220: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801224: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80801228: srl         $t3, $a1, 19
    ctx->r11 = S32(U32(ctx->r5) >> 19);
    // 0x8080122C: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80801230: addu        $t9, $s5, $t2
    ctx->r25 = ADD32(ctx->r21, ctx->r10);
    // 0x80801234: lw          $v0, 0x4($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X4);
    // 0x80801238: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8080123C: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x80801240: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80801244:
    // 0x80801244: lhu         $t1, 0x28($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X28);
    // 0x80801248: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8080124C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80801250: andi        $t8, $t7, 0x3FC
    ctx->r24 = ctx->r15 & 0X3FC;
    // 0x80801254: andi        $t3, $t1, 0xFC03
    ctx->r11 = ctx->r9 & 0XFC03;
    // 0x80801258: or          $t2, $t8, $t3
    ctx->r10 = ctx->r24 | ctx->r11;
    // 0x8080125C: sh          $t2, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r10;
    // 0x80801260: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80801264: bnel        $s7, $t9, L_80801464
    if (ctx->r23 != ctx->r25) {
        // 0x80801268: addiu       $t8, $a1, 0x2
        ctx->r24 = ADD32(ctx->r5, 0X2);
            goto L_80801464;
    }
    goto skip_26;
    // 0x80801268: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
    skip_26:
    // 0x8080126C: lwc1        $f10, 0x190($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X190);
    // 0x80801270: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80801274: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801278: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8080127C: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80801280: srl         $t6, $a1, 19
    ctx->r14 = S32(U32(ctx->r5) >> 19);
    // 0x80801284: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80801288: b           L_80801460
    // 0x8080128C: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
        goto L_80801460;
    // 0x8080128C: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
L_80801290:
    // 0x80801290: andi        $t4, $t0, 0xFFFF
    ctx->r12 = ctx->r8 & 0XFFFF;
    // 0x80801294: addu        $a0, $s4, $t4
    ctx->r4 = ADD32(ctx->r20, ctx->r12);
    // 0x80801298: lbu         $t5, 0x80($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X80);
    // 0x8080129C: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
    // 0x808012A0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x808012A4: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x808012A8: srl         $t7, $a1, 19
    ctx->r15 = S32(U32(ctx->r5) >> 19);
    // 0x808012AC: b           L_80801460
    // 0x808012B0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80801460;
    // 0x808012B0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_808012B4:
    // 0x808012B4: lbu         $t9, 0x28($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X28);
    // 0x808012B8: sll         $t2, $t0, 5
    ctx->r10 = S32(ctx->r8 << 5);
    // 0x808012BC: andi        $t6, $t9, 0xFF1F
    ctx->r14 = ctx->r25 & 0XFF1F;
    // 0x808012C0: or          $t4, $t2, $t6
    ctx->r12 = ctx->r10 | ctx->r14;
    // 0x808012C4: b           L_80801460
    // 0x808012C8: sb          $t4, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r12;
        goto L_80801460;
    // 0x808012C8: sb          $t4, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r12;
L_808012CC:
    // 0x808012CC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x808012D0: sll         $t5, $a0, 21
    ctx->r13 = S32(ctx->r4 << 21);
    // 0x808012D4: jal         0x800D7520
    // 0x808012D8: sra         $a0, $t5, 22
    ctx->r4 = S32(SIGNED(ctx->r13) >> 22);
    func_800D7520(rdram, ctx);
        goto after_43;
    // 0x808012D8: sra         $a0, $t5, 22
    ctx->r4 = S32(SIGNED(ctx->r13) >> 22);
    after_43:
    // 0x808012DC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x808012E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808012E8: sll         $t8, $t1, 8
    ctx->r24 = S32(ctx->r9 << 8);
    // 0x808012EC: srl         $t3, $t8, 19
    ctx->r11 = S32(U32(ctx->r24) >> 19);
    // 0x808012F0: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x808012F4: addu        $t2, $s5, $t9
    ctx->r10 = ADD32(ctx->r21, ctx->r25);
    // 0x808012F8: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x808012FC: andi        $t4, $t6, 0xFFFF
    ctx->r12 = ctx->r14 & 0XFFFF;
    // 0x80801300: beq         $t4, $zero, L_80801310
    if (ctx->r12 == 0) {
        // 0x80801304: nop
    
            goto L_80801310;
    }
    // 0x80801304: nop

    // 0x80801308: b           L_80801310
    // 0x8080130C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80801310;
    // 0x8080130C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801310:
    // 0x80801310: jal         0x800C84A4
    // 0x80801314: nop

    func_800C84A4(rdram, ctx);
        goto after_44;
    // 0x80801314: nop

    after_44:
    // 0x80801318: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8080131C: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80801320: srl         $t5, $a1, 19
    ctx->r13 = S32(U32(ctx->r5) >> 19);
    // 0x80801324: b           L_80801460
    // 0x80801328: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_80801460;
    // 0x80801328: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_8080132C:
    // 0x8080132C: jal         0x8009086C
    // 0x80801330: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    func_8009086C(rdram, ctx);
        goto after_45;
    // 0x80801330: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    after_45:
    // 0x80801334: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801338: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x8080133C: srl         $t7, $a1, 19
    ctx->r15 = S32(U32(ctx->r5) >> 19);
    // 0x80801340: b           L_80801460
    // 0x80801344: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80801460;
    // 0x80801344: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80801348:
    // 0x80801348: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8080134C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801350: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801354: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801358: jal         0x80800228
    // 0x8080135C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800228_glsplinecs(rdram, ctx);
        goto after_46;
    // 0x8080135C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_46:
    // 0x80801360: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80801364: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080136C: sll         $t8, $t1, 8
    ctx->r24 = S32(ctx->r9 << 8);
    // 0x80801370: srl         $t3, $t8, 19
    ctx->r11 = S32(U32(ctx->r24) >> 19);
    // 0x80801374: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80801378: addu        $t2, $s5, $t9
    ctx->r10 = ADD32(ctx->r21, ctx->r25);
    // 0x8080137C: jal         0x8080002C
    // 0x80801380: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    func_8080002C_glsplinecs(rdram, ctx);
        goto after_47;
    // 0x80801380: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    after_47:
    // 0x80801384: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801388: sll         $t6, $v1, 8
    ctx->r14 = S32(ctx->r3 << 8);
    // 0x8080138C: srl         $t4, $t6, 19
    ctx->r12 = S32(U32(ctx->r14) >> 19);
    // 0x80801390: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80801394: srl         $t7, $v1, 11
    ctx->r15 = S32(U32(ctx->r3) >> 11);
    // 0x80801398: xor         $t1, $t5, $t7
    ctx->r9 = ctx->r13 ^ ctx->r15;
    // 0x8080139C: sll         $t8, $t1, 19
    ctx->r24 = S32(ctx->r9 << 19);
    // 0x808013A0: srl         $t3, $t8, 8
    ctx->r11 = S32(U32(ctx->r24) >> 8);
    // 0x808013A4: xor         $t9, $t3, $v1
    ctx->r25 = ctx->r11 ^ ctx->r3;
    // 0x808013A8: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x808013AC: srl         $t2, $a1, 19
    ctx->r10 = S32(U32(ctx->r5) >> 19);
    // 0x808013B0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x808013B4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x808013B8: b           L_80801460
    // 0x808013BC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
        goto L_80801460;
    // 0x808013BC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_808013C0:
    // 0x808013C0: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x808013C4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808013C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808013CC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808013D0: jal         0x80800228
    // 0x808013D4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80800228_glsplinecs(rdram, ctx);
        goto after_48;
    // 0x808013D4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_48:
    // 0x808013D8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x808013DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808013E0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808013E4: sll         $t4, $t6, 8
    ctx->r12 = S32(ctx->r14 << 8);
    // 0x808013E8: srl         $t5, $t4, 19
    ctx->r13 = S32(U32(ctx->r12) >> 19);
    // 0x808013EC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x808013F0: addu        $s1, $s5, $t7
    ctx->r17 = ADD32(ctx->r21, ctx->r15);
    // 0x808013F4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x808013F8: jal         0x80800310
    // 0x808013FC: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    func_80800310_glsplinecs(rdram, ctx);
        goto after_49;
    // 0x808013FC: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    after_49:
    // 0x80801400: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801404: sll         $t1, $v1, 8
    ctx->r9 = S32(ctx->r3 << 8);
    // 0x80801408: srl         $t8, $t1, 19
    ctx->r24 = S32(U32(ctx->r9) >> 19);
    // 0x8080140C: addiu       $t3, $t8, 0x2
    ctx->r11 = ADD32(ctx->r24, 0X2);
    // 0x80801410: srl         $t9, $v1, 11
    ctx->r25 = S32(U32(ctx->r3) >> 11);
    // 0x80801414: xor         $t2, $t3, $t9
    ctx->r10 = ctx->r11 ^ ctx->r25;
    // 0x80801418: sll         $t6, $t2, 19
    ctx->r14 = S32(ctx->r10 << 19);
    // 0x8080141C: srl         $t4, $t6, 8
    ctx->r12 = S32(U32(ctx->r14) >> 8);
    // 0x80801420: xor         $t5, $t4, $v1
    ctx->r13 = ctx->r12 ^ ctx->r3;
    // 0x80801424: sll         $a1, $t5, 8
    ctx->r5 = S32(ctx->r13 << 8);
    // 0x80801428: srl         $t7, $a1, 19
    ctx->r15 = S32(U32(ctx->r5) >> 19);
    // 0x8080142C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80801430: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80801434: b           L_80801460
    // 0x80801438: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
        goto L_80801460;
    // 0x80801438: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_8080143C:
    // 0x8080143C: addiu       $a0, $zero, 0x18BC
    ctx->r4 = ADD32(0, 0X18BC);
    // 0x80801440: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x80801444: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801448: jal         0x800861A0
    // 0x8080144C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_50;
    // 0x8080144C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_50:
    // 0x80801450: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80801454: sll         $a1, $v1, 8
    ctx->r5 = S32(ctx->r3 << 8);
    // 0x80801458: srl         $t1, $a1, 19
    ctx->r9 = S32(U32(ctx->r5) >> 19);
    // 0x8080145C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
L_80801460:
    // 0x80801460: addiu       $t8, $a1, 0x2
    ctx->r24 = ADD32(ctx->r5, 0X2);
L_80801464:
    // 0x80801464: srl         $t3, $v1, 11
    ctx->r11 = S32(U32(ctx->r3) >> 11);
    // 0x80801468: xor         $t9, $t8, $t3
    ctx->r25 = ctx->r24 ^ ctx->r11;
    // 0x8080146C: sll         $t2, $t9, 19
    ctx->r10 = S32(ctx->r25 << 19);
    // 0x80801470: srl         $t6, $t2, 8
    ctx->r14 = S32(U32(ctx->r10) >> 8);
    // 0x80801474: xor         $t4, $t6, $v1
    ctx->r12 = ctx->r14 ^ ctx->r3;
    // 0x80801478: sll         $a1, $t4, 8
    ctx->r5 = S32(ctx->r12 << 8);
    // 0x8080147C: srl         $t5, $a1, 19
    ctx->r13 = S32(U32(ctx->r5) >> 19);
    // 0x80801480: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80801484: addu        $s1, $s5, $t7
    ctx->r17 = ADD32(ctx->r21, ctx->r15);
    // 0x80801488: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8080148C: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x80801490: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801494: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80801498: beq         $t0, $at, L_80801578
    if (ctx->r8 == ctx->r1) {
        // 0x8080149C: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_80801578;
    }
    // 0x8080149C: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x808014A0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x808014A4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x808014A8: ori         $at, $at, 0x6
    ctx->r1 = ctx->r1 | 0X6;
    // 0x808014AC: bne         $s7, $v0, L_808014DC
    if (ctx->r23 != ctx->r2) {
        // 0x808014B0: nop
    
            goto L_808014DC;
    }
    // 0x808014B0: nop

    // 0x808014B4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x808014B8: lwc1        $f16, 0x190($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X190);
    // 0x808014BC: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x808014C0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x808014C4: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x808014C8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808014CC: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x808014D0: nop

    // 0x808014D4: bc1tl       L_80801514
    if (c1cs) {
        // 0x808014D8: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80801514;
    }
    goto skip_27;
    // 0x808014D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_27:
L_808014DC:
    // 0x808014DC: bnel        $v0, $at, L_8080157C
    if (ctx->r2 != ctx->r1) {
        // 0x808014E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_28;
    // 0x808014E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_28:
    // 0x808014E4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x808014E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2698, 0X16C0) << 16);
    // 0x808014EC: lwc1        $f10, 0x16C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2698, 0X16C0));
    // 0x808014F0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808014F4: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x808014F8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808014FC: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80801500: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80801504: nop

    // 0x80801508: bc1fl       L_8080157C
    if (!c1cs) {
        // 0x8080150C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_29;
    // 0x8080150C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_29:
    // 0x80801510: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80801514:
    // 0x80801514: lwc1        $f16, 0x20($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80801518: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x8080151C: nop

    // 0x80801520: bc1fl       L_8080157C
    if (!c1cs) {
        // 0x80801524: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_30;
    // 0x80801524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_30:
    // 0x80801528: lw          $a2, 0x24($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X24);
    // 0x8080152C: sll         $t3, $a2, 19
    ctx->r11 = S32(ctx->r6 << 19);
    // 0x80801530: srl         $t9, $t3, 28
    ctx->r25 = S32(U32(ctx->r11) >> 28);
    // 0x80801534: bnel        $t9, $zero, L_8080157C
    if (ctx->r25 != 0) {
        // 0x80801538: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_31;
    // 0x80801538: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_31:
    // 0x8080153C: lhu         $v0, 0x2A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2A);
    // 0x80801540: srl         $t2, $v0, 7
    ctx->r10 = S32(U32(ctx->r2) >> 7);
    // 0x80801544: bnel        $t2, $zero, L_8080157C
    if (ctx->r10 != 0) {
        // 0x80801548: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_32;
    // 0x80801548: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_32:
    // 0x8080154C: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    // 0x80801550: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x80801554: srl         $t4, $t6, 24
    ctx->r12 = S32(U32(ctx->r14) >> 24);
    // 0x80801558: bnel        $t4, $zero, L_8080157C
    if (ctx->r12 != 0) {
        // 0x8080155C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080157C;
    }
    goto skip_33;
    // 0x8080155C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_33:
    // 0x80801560: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801564: lwc1        $f10, 0x2C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x80801568: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8080156C: nop

    // 0x80801570: bc1fl       L_80800628
    if (!c1cs) {
        // 0x80801574: sra         $t9, $t0, 16
        ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
            goto L_80800628;
    }
    goto skip_34;
    // 0x80801574: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    skip_34:
L_80801578:
    // 0x80801578: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8080157C:
    // 0x8080157C: bnel        $t0, $at, L_808015B4
    if (ctx->r8 != ctx->r1) {
        // 0x80801580: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808015B4;
    }
    goto skip_35;
    // 0x80801580: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_35:
    // 0x80801584: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x80801588: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8080158C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801590: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801594: srl         $t5, $v1, 11
    ctx->r13 = S32(U32(ctx->r3) >> 11);
    // 0x80801598: sll         $t7, $t5, 19
    ctx->r15 = S32(ctx->r13 << 19);
    // 0x8080159C: srl         $t1, $t7, 8
    ctx->r9 = S32(U32(ctx->r15) >> 8);
    // 0x808015A0: xor         $t8, $t1, $v1
    ctx->r24 = ctx->r9 ^ ctx->r3;
    // 0x808015A4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x808015A8: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x808015AC: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x808015B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808015B4:
    // 0x808015B4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808015B8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808015BC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x808015C0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x808015C4: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x808015C8: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x808015CC: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x808015D0: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x808015D4: jr          $ra
    // 0x808015D8: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x808015D8: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // 0x808015DC: nop

;}
RECOMP_FUNC void func_80800828_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800828: jr          $ra
    // 0x8080082C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080082C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _chsounder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BE0: syscall     428
    recomp_syscall_handler(rdram, ctx, 0x80086BE0);
    return;
    // 0x80086BE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800B70_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B80: jal         0x808004A8
    // 0x80800B84: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_808004A8_bsledge(rdram, ctx);
        goto after_0;
    // 0x80800B84: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800B88: jal         0x808004D8
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004D8_bsledge(rdram, ctx);
        goto after_1;
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B90: jal         0x80800AA0
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA0_bsledge(rdram, ctx);
        goto after_2;
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800B98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800B9C: jal         0x8008CABC
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800BA4: jal         0x8008B264
    // 0x80800BA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_4;
    // 0x80800BA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800BAC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800BB0: beq         $v0, $a1, L_80800BC0
    if (ctx->r2 == ctx->r5) {
        // 0x80800BB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BC0;
    }
    // 0x80800BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB8: jal         0x8008CB3C
    // 0x80800BBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_5;
    // 0x80800BBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
L_80800BC0:
    // 0x80800BC0: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800BC4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800BC8: jal         0x8008CB10
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800BD0: beq         $v0, $zero, L_80800BEC
    if (ctx->r2 == 0) {
        // 0x80800BD4: lui         $a2, 0x3F45
        ctx->r6 = S32(0X3F45 << 16);
            goto L_80800BEC;
    }
    // 0x80800BD4: lui         $a2, 0x3F45
    ctx->r6 = S32(0X3F45 << 16);
    // 0x80800BD8: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE0: addiu       $a1, $zero, 0x46E
    ctx->r5 = ADD32(0, 0X46E);
    // 0x80800BE4: jal         0x8009DF94
    // 0x80800BE8: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF94(rdram, ctx);
        goto after_7;
    // 0x80800BE8: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_7:
L_80800BEC:
    // 0x80800BEC: lui         $a1, 0x3E61
    ctx->r5 = S32(0X3E61 << 16);
    // 0x80800BF0: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x80800BF4: jal         0x8008CB10
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800BFC: beql        $v0, $zero, L_80800C10
    if (ctx->r2 == 0) {
        // 0x80800C00: lui         $a1, 0x3F26
        ctx->r5 = S32(0X3F26 << 16);
            goto L_80800C10;
    }
    goto skip_0;
    // 0x80800C00: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    skip_0:
    // 0x80800C04: jal         0x80800334
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800334_bsledge(rdram, ctx);
        goto after_9;
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800C0C: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
L_80800C10:
    // 0x80800C10: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800C14: jal         0x8008CB10
    // 0x80800C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x80800C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800C1C: beq         $v0, $zero, L_80800C38
    if (ctx->r2 == 0) {
        // 0x80800C20: lui         $a2, 0x3F5E
        ctx->r6 = S32(0X3F5E << 16);
            goto L_80800C38;
    }
    // 0x80800C20: lui         $a2, 0x3F5E
    ctx->r6 = S32(0X3F5E << 16);
    // 0x80800C24: ori         $a2, $a2, 0xB852
    ctx->r6 = ctx->r6 | 0XB852;
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C2C: addiu       $a1, $zero, 0x46E
    ctx->r5 = ADD32(0, 0X46E);
    // 0x80800C30: jal         0x8009DF94
    // 0x80800C34: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF94(rdram, ctx);
        goto after_11;
    // 0x80800C34: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_11:
L_80800C38:
    // 0x80800C38: lui         $a1, 0x3F38
    ctx->r5 = S32(0X3F38 << 16);
    // 0x80800C3C: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800C40: jal         0x8008CB10
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_12;
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800C48: beq         $v0, $zero, L_80800C58
    if (ctx->r2 == 0) {
        // 0x80800C4C: nop
    
            goto L_80800C58;
    }
    // 0x80800C4C: nop

    // 0x80800C50: jal         0x80800334
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800334_bsledge(rdram, ctx);
        goto after_13;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_80800C58:
    // 0x80800C58: jal         0x80800450
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800450_bsledge(rdram, ctx);
        goto after_14;
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800C60: bne         $v0, $zero, L_80800C6C
    if (ctx->r2 != 0) {
        // 0x80800C64: addiu       $t6, $zero, 0xA6
        ctx->r14 = ADD32(0, 0XA6);
            goto L_80800C6C;
    }
    // 0x80800C64: addiu       $t6, $zero, 0xA6
    ctx->r14 = ADD32(0, 0XA6);
    // 0x80800C68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800C6C:
    // 0x80800C6C: jal         0x808003D0
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D0_bsledge(rdram, ctx);
        goto after_15;
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800C74: beq         $v0, $zero, L_80800C80
    if (ctx->r2 == 0) {
        // 0x80800C78: addiu       $t7, $zero, 0xAA
        ctx->r15 = ADD32(0, 0XAA);
            goto L_80800C80;
    }
    // 0x80800C78: addiu       $t7, $zero, 0xAA
    ctx->r15 = ADD32(0, 0XAA);
    // 0x80800C7C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800C80:
    // 0x80800C80: jal         0x80800000
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsledge(rdram, ctx);
        goto after_16;
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800C88: beq         $v0, $zero, L_80800C98
    if (ctx->r2 == 0) {
        // 0x80800C8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C98;
    }
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C90: addiu       $t8, $zero, 0xA9
    ctx->r24 = ADD32(0, 0XA9);
    // 0x80800C94: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800C98:
    // 0x80800C98: jal         0x80091A58
    // 0x80800C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_17;
    // 0x80800C9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800CA0: beq         $v0, $zero, L_80800CAC
    if (ctx->r2 == 0) {
        // 0x80800CA4: addiu       $t9, $zero, 0x2F
        ctx->r25 = ADD32(0, 0X2F);
            goto L_80800CAC;
    }
    // 0x80800CA4: addiu       $t9, $zero, 0x2F
    ctx->r25 = ADD32(0, 0X2F);
    // 0x80800CA8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800CAC:
    // 0x80800CAC: jal         0x80800410
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800410_bsledge(rdram, ctx);
        goto after_18;
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800CB4: bne         $v0, $zero, L_80800CC4
    if (ctx->r2 != 0) {
        // 0x80800CB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CC4;
    }
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CBC: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x80800CC0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800CC4:
    // 0x80800CC4: jal         0x8009E5C8
    // 0x80800CC8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80800CC8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x80800CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CD8: jr          $ra
    // 0x80800CDC: nop

    return;
    // 0x80800CDC: nop

;}
RECOMP_FUNC void func_80800060_chklungoleave(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800064: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800070: bne         $a1, $at, L_808000D4
    if (ctx->r5 != ctx->r1) {
        // 0x80800074: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808000D4;
    }
    // 0x80800074: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800078: jal         0x80088840
    // 0x8080007C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x8080007C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_0:
    // 0x80800080: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x80800084: addiu       $a1, $zero, 0x162E
        ctx->r5 = ADD32(0, 0X162E);
            goto L_808000C4;
    }
    // 0x80800084: addiu       $a1, $zero, 0x162E
    ctx->r5 = ADD32(0, 0X162E);
    // 0x80800088: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8080008C: addiu       $t6, $zero, 0xAB
    ctx->r14 = ADD32(0, 0XAB);
    // 0x80800090: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800094: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800098: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080009C: jal         0x8008A208
    // 0x808000A0: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808000A0: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x808000A4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000AC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808000B0: addiu       $a3, $zero, 0x2911
    ctx->r7 = ADD32(0, 0X2911);
    // 0x808000B4: jal         0x80085708
    // 0x808000B8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808000B8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x808000BC: b           L_808000E0
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E0;
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C4:
    // 0x808000C4: jal         0x800FFAB0
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808000CC: b           L_808000E0
    // 0x808000D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000E0;
    // 0x808000D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000D4:
    // 0x808000D4: b           L_808000E0
    // 0x808000D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000E0;
    // 0x808000D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E0:
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80800630_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80800634: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800638: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080063C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800640: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800644: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800648: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080064C: addiu       $a0, $zero, 0x3EA
    ctx->r4 = ADD32(0, 0X3EA);
    // 0x80800650: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80800654: jal         0x80089C40
    // 0x80800658: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800658: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x8080065C: jal         0x80800458
    // 0x80800660: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_80800458_chtoxicroombits(rdram, ctx);
        goto after_1;
    // 0x80800660: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800664: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEF4) << 16);
    // 0x80800668: lwc1        $f20, 0xEF4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEF4));
    // 0x8080066C: lwc1        $f4, 0x34($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80800670: add.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80800674: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800678: nop

    // 0x8080067C: bc1f        L_8080068C
    if (!c1cs) {
        // 0x80800680: nop
    
            goto L_8080068C;
    }
    // 0x80800680: nop

    // 0x80800684: b           L_808006C0
    // 0x80800688: swc1        $f2, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f2.u32l;
        goto L_808006C0;
    // 0x80800688: swc1        $f2, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f2.u32l;
L_8080068C:
    // 0x8080068C: jal         0x80800458
    // 0x80800690: nop

    func_80800458_chtoxicroombits(rdram, ctx);
        goto after_2;
    // 0x80800690: nop

    after_2:
    // 0x80800694: lwc1        $f6, 0x34($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80800698: sub.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x8080069C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808006A0: nop

    // 0x808006A4: bc1f        L_808006B4
    if (!c1cs) {
        // 0x808006A8: nop
    
            goto L_808006B4;
    }
    // 0x808006A8: nop

    // 0x808006AC: b           L_808006C0
    // 0x808006B0: swc1        $f2, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f2.u32l;
        goto L_808006C0;
    // 0x808006B0: swc1        $f2, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f2.u32l;
L_808006B4:
    // 0x808006B4: jal         0x80800458
    // 0x808006B8: nop

    func_80800458_chtoxicroombits(rdram, ctx);
        goto after_3;
    // 0x808006B8: nop

    after_3:
    // 0x808006BC: swc1        $f0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f0.u32l;
L_808006C0:
    // 0x808006C0: jal         0x808004F0
    // 0x808006C4: nop

    func_808004F0_chtoxicroombits(rdram, ctx);
        goto after_4;
    // 0x808006C4: nop

    after_4:
    // 0x808006C8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808006CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEF8) << 16);
    // 0x808006D4: lwc1        $f10, 0xEF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEF8));
    // 0x808006D8: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x808006DC: lui         $a3, 0x3EE6
    ctx->r7 = S32(0X3EE6 << 16);
    // 0x808006E0: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808006E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808006E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808006EC: jal         0x800F10B4
    // 0x808006F0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808006F0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_5:
    // 0x808006F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006F8: jal         0x80089D30
    // 0x808006FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808006FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80800700: jal         0x800E3980
    // 0x80800704: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    func_800E3980(rdram, ctx);
        goto after_7;
    // 0x80800704: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_7:
    // 0x80800708: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8080070C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800710: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800714: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800718: nop

    // 0x8080071C: bc1fl       L_80800758
    if (!c1cs) {
        // 0x80800720: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800758;
    }
    goto skip_0;
    // 0x80800720: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80800724: jal         0x800DA298
    // 0x80800728: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800728: addiu       $a0, $zero, 0xA04
    ctx->r4 = ADD32(0, 0XA04);
    after_8:
    // 0x8080072C: bnel        $v0, $zero, L_80800758
    if (ctx->r2 != 0) {
        // 0x80800730: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800758;
    }
    goto skip_1;
    // 0x80800730: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x80800734: jal         0x800DA298
    // 0x80800738: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80800738: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_9:
    // 0x8080073C: beq         $v0, $zero, L_80800754
    if (ctx->r2 == 0) {
        // 0x80800740: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800754;
    }
    // 0x80800740: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800744: jal         0x80089D38
    // 0x80800748: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800748: addiu       $a1, $zero, 0x1F40
    ctx->r5 = ADD32(0, 0X1F40);
    after_10:
    // 0x8080074C: b           L_80800760
    // 0x80800750: nop

        goto L_80800760;
    // 0x80800750: nop

L_80800754:
    // 0x80800754: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800758:
    // 0x80800758: jal         0x80089D38
    // 0x8080075C: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x8080075C: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    after_11:
L_80800760:
    // 0x80800760: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2308, 0X1004) << 16);
    // 0x80800764: addiu       $a3, $a3, 0x1004
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2308, 0X1004));
    // 0x80800768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080076C: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80800770: jal         0x80089D50
    // 0x80800774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80800778: jal         0x800D91B8
    // 0x8080077C: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    func_800D91B8(rdram, ctx);
        goto after_13;
    // 0x8080077C: addiu       $a0, $s2, 0x58
    ctx->r4 = ADD32(ctx->r18, 0X58);
    after_13:
    // 0x80800780: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80800784: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800788: lwc1        $f4, 0x34($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X34);
    // 0x8080078C: div.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800790: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800794: nop

    // 0x80800798: bc1f        L_808007DC
    if (!c1cs) {
        // 0x8080079C: nop
    
            goto L_808007DC;
    }
    // 0x8080079C: nop

    // 0x808007A0: lbu         $v1, 0x79($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X79);
    // 0x808007A4: lwc1        $f6, 0x58($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X58);
    // 0x808007A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007AC: srl         $v0, $v1, 4
    ctx->r2 = S32(U32(ctx->r3) >> 4);
    // 0x808007B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x808007B4: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x808007B8: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x808007BC: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x808007C0: andi        $t9, $v1, 0xFF0F
    ctx->r25 = ctx->r3 & 0XFF0F;
    // 0x808007C4: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x808007C8: swc1        $f8, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f8.u32l;
    // 0x808007CC: bne         $t6, $zero, L_808007DC
    if (ctx->r14 != 0) {
        // 0x808007D0: sb          $t0, 0x79($s2)
        MEM_B(0X79, ctx->r18) = ctx->r8;
            goto L_808007DC;
    }
    // 0x808007D0: sb          $t0, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r8;
    // 0x808007D4: jal         0x80800960
    // 0x808007D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800960_chtoxicroombits(rdram, ctx);
        goto after_14;
    // 0x808007D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_808007DC:
    // 0x808007DC: jal         0x80800BE4
    // 0x808007E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800BE4_chtoxicroombits(rdram, ctx);
        goto after_15;
    // 0x808007E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_15:
    // 0x808007E4: jal         0x800D8FF8
    // 0x808007E8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_16;
    // 0x808007E8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_16:
    // 0x808007EC: lwc1        $f10, 0x34($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X34);
    // 0x808007F0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808007F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007F8: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x808007FC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80800800: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800804: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80800808: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080080C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800810: blez        $t1, L_808008B0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80800814: swc1        $f6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
            goto L_808008B0;
    }
    // 0x80800814: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x80800818: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8080081C:
    // 0x8080081C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800820: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80800824: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800828: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080082C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800830: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x80800834: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800838: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8080083C: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800840: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800844: nop

    // 0x80800848: bc1f        L_80800860
    if (!c1cs) {
        // 0x8080084C: nop
    
            goto L_80800860;
    }
    // 0x8080084C: nop

    // 0x80800850: jal         0x800FFAB0
    // 0x80800854: nop

    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x80800854: nop

    after_17:
    // 0x80800858: b           L_808008A0
    // 0x8080085C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
        goto L_808008A0;
    // 0x8080085C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
L_80800860:
    // 0x80800860: beql        $t2, $zero, L_808008A0
    if (ctx->r10 == 0) {
        // 0x80800864: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_808008A0;
    }
    goto skip_2;
    // 0x80800864: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x80800868: jal         0x80103EF4
    // 0x8080086C: nop

    func_80103EF4(rdram, ctx);
        goto after_18;
    // 0x8080086C: nop

    after_18:
    // 0x80800870: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800874: jal         0x80103EAC
    // 0x80800878: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80103EAC(rdram, ctx);
        goto after_19;
    // 0x80800878: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_19:
    // 0x8080087C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800880: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800884: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800888: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8080088C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800890: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800894: jal         0x80089F20
    // 0x80800898: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80800898: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_20:
    // 0x8080089C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
L_808008A0:
    // 0x808008A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808008A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808008A8: bnel        $s1, $t4, L_8080081C
    if (ctx->r17 != ctx->r12) {
        // 0x808008AC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8080081C;
    }
    goto skip_3;
    // 0x808008AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_808008B0:
    // 0x808008B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808008B4: lwc1        $f8, 0x18($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X18);
    // 0x808008B8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x808008BC: nop

    // 0x808008C0: bc1tl       L_80800948
    if (c1cs) {
        // 0x808008C4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800948;
    }
    goto skip_4;
    // 0x808008C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x808008C8: jal         0x800D90A4
    // 0x808008CC: addiu       $a0, $s2, 0x18
    ctx->r4 = ADD32(ctx->r18, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_21;
    // 0x808008CC: addiu       $a0, $s2, 0x18
    ctx->r4 = ADD32(ctx->r18, 0X18);
    after_21:
    // 0x808008D0: beql        $v0, $zero, L_80800948
    if (ctx->r2 == 0) {
        // 0x808008D4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800948;
    }
    goto skip_5;
    // 0x808008D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x808008D8: lw          $t5, 0x64($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X64);
    // 0x808008DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008E0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808008E4: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x808008E8: bgez        $t7, L_80800918
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808008EC: addiu       $a3, $zero, 0x90
        ctx->r7 = ADD32(0, 0X90);
            goto L_80800918;
    }
    // 0x808008EC: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x808008F0: jal         0x80085708
    // 0x808008F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_22;
    // 0x808008F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_22:
    // 0x808008F8: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x808008FC: jal         0x800D0634
    // 0x80800900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0634(rdram, ctx);
        goto after_23;
    // 0x80800900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800904: jal         0x80106790
    // 0x80800908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_24;
    // 0x80800908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x8080090C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800910: b           L_80800944
    // 0x80800914: swc1        $f10, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f10.u32l;
        goto L_80800944;
    // 0x80800914: swc1        $f10, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f10.u32l;
L_80800918:
    // 0x80800918: jal         0x800DA298
    // 0x8080091C: addiu       $a0, $zero, 0x1BE
    ctx->r4 = ADD32(0, 0X1BE);
    func_800DA298(rdram, ctx);
        goto after_25;
    // 0x8080091C: addiu       $a0, $zero, 0x1BE
    ctx->r4 = ADD32(0, 0X1BE);
    after_25:
    // 0x80800920: bnel        $v0, $zero, L_80800948
    if (ctx->r2 != 0) {
        // 0x80800924: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800948;
    }
    goto skip_6;
    // 0x80800924: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x80800928: jal         0x800DA544
    // 0x8080092C: addiu       $a0, $zero, 0x1BE
    ctx->r4 = ADD32(0, 0X1BE);
    func_800DA544(rdram, ctx);
        goto after_26;
    // 0x8080092C: addiu       $a0, $zero, 0x1BE
    ctx->r4 = ADD32(0, 0X1BE);
    after_26:
    // 0x80800930: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800938: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080093C: jal         0x80085708
    // 0x80800940: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_27;
    // 0x80800940: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_27:
L_80800944:
    // 0x80800944: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800948:
    // 0x80800948: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080094C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800950: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800954: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800958: jr          $ra
    // 0x8080095C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8080095C: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80802588_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080258C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802590: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802598: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080259C: jal         0x80100094
    // 0x808025A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808025A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808025A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808025A8: addiu       $a1, $v0, 0x88
    ctx->r5 = ADD32(ctx->r2, 0X88);
    // 0x808025AC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808025B0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808025B4: jal         0x8008A2C8
    // 0x808025B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808025B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x808025BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808025C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808025C4: jr          $ra
    // 0x808025C8: nop

    return;
    // 0x808025C8: nop

;}
RECOMP_FUNC void func_80800588_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080058C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800590: jal         0x808001E0
    // 0x80800594: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800594: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800598: jal         0x80082FE0
    // 0x8080059C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080059C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808005A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005A8: jr          $ra
    // 0x808005AC: nop

    return;
    // 0x808005AC: nop

;}
RECOMP_FUNC void func_800A0CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0CE8: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0CEC: jr          $ra
    // 0x800A0CF0: sb          $a1, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r5;
    return;
    // 0x800A0CF0: sb          $a1, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800668_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800668: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080066C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800670: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800674: jal         0x80800800
    // 0x80800678: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80800800_chcheatomenu(rdram, ctx);
        goto after_0;
    // 0x80800678: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080067C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800680: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80800684: addiu       $t6, $zero, 0x1848
    ctx->r14 = ADD32(0, 0X1848);
    // 0x80800688: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080068C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800690: addiu       $a3, $a3, 0x7DB0
    ctx->r7 = ADD32(ctx->r7, 0X7DB0);
    // 0x80800694: addiu       $a2, $a2, 0x7D10
    ctx->r6 = ADD32(ctx->r6, 0X7D10);
    // 0x80800698: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080069C: jal         0x80087CB8
    // 0x808006A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808006A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808006A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808006A8: jal         0x80100094
    // 0x808006AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808006AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808006B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808006B8: jal         0x800F1418
    // 0x808006BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F1418(rdram, ctx);
        goto after_3;
    // 0x808006BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x80087CD8
    // 0x808006C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808006C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D0: jal         0x80087CE0
    // 0x808006D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808006D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x80087CE8
    // 0x808006E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x808006E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808006E4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808006E8: jal         0x80800364
    // 0x808006EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800364_chcheatomenu(rdram, ctx);
        goto after_7;
    // 0x808006EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x808006F0: jal         0x80087CF0
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808006F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808006FC: jal         0x80101FDC
    // 0x80800700: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x80800700: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800704: jal         0x80090708
    // 0x80800708: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_10;
    // 0x80800708: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x8080070C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800710: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800714: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800718: jr          $ra
    // 0x8080071C: nop

    return;
    // 0x8080071C: nop

;}
RECOMP_FUNC void func_80800C08_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800C0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C18: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800C1C: jal         0x800E3A58
    // 0x80800C20: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800E3A58(rdram, ctx);
        goto after_0;
    // 0x80800C20: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80800C24: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800C28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C2C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800C30: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800C34: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800C38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800C3C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C44: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80800C48: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800C4C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800C50: nop

    // 0x80800C54: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800C58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800C5C: nop

    // 0x80800C60: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800C64: beql        $t7, $zero, L_80800CB4
    if (ctx->r15 == 0) {
        // 0x80800C68: mfc1        $t7, $f16
        ctx->r15 = (int32_t)ctx->f16.u32l;
            goto L_80800CB4;
    }
    goto skip_0;
    // 0x80800C68: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80800C6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800C74: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800C78: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800C7C: nop

    // 0x80800C80: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800C84: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800C88: nop

    // 0x80800C8C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800C90: bne         $t7, $zero, L_80800CA8
    if (ctx->r15 != 0) {
        // 0x80800C94: nop
    
            goto L_80800CA8;
    }
    // 0x80800C94: nop

    // 0x80800C98: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80800C9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800CA0: b           L_80800CC0
    // 0x80800CA4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800CC0;
    // 0x80800CA4: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800CA8:
    // 0x80800CA8: b           L_80800CC0
    // 0x80800CAC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800CC0;
    // 0x80800CAC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800CB0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
L_80800CB4:
    // 0x80800CB4: nop

    // 0x80800CB8: bltz        $t7, L_80800CA8
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800CBC: nop
    
            goto L_80800CA8;
    }
    // 0x80800CBC: nop

L_80800CC0:
    // 0x80800CC0: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800CC4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800CC8: sb          $t7, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r15;
    // 0x80800CCC: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80800CD0: bgezl       $t0, L_80800CE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800CD4: lwc1        $f0, 0x1C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_80800CE4;
    }
    goto skip_1;
    // 0x80800CD4: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x80800CD8: jal         0x80101870
    // 0x80800CDC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800CDC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x80800CE0: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
L_80800CE4:
    // 0x80800CE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800CE8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800CEC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800CF0: nop

    // 0x80800CF4: bc1fl       L_80800D20
    if (!c1cs) {
        // 0x80800CF8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80800D20;
    }
    goto skip_2;
    // 0x80800CF8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x80800CFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D00: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X1790) << 16);
    // 0x80800D04: addiu       $a1, $a1, 0x1790
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X1790));
    // 0x80800D08: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800D0C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800D10: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800D14: jal         0x8008A8F0
    // 0x80800D18: nop

    _sufade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800D18: nop

    after_2:
    // 0x80800D1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80800D20:
    // 0x80800D20: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800D24: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800D28: nop

    // 0x80800D2C: bc1fl       L_80800DCC
    if (!c1cs) {
        // 0x80800D30: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800DCC;
    }
    goto skip_3;
    // 0x80800D30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800D34: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800D38: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80800D3C: bgezl       $t4, L_80800DCC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800D40: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800DCC;
    }
    goto skip_4;
    // 0x80800D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800D44: jal         0x800E3980
    // 0x80800D48: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x80800D48: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800D4C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800D50: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800D54: jal         0x800F1E6C
    // 0x80800D58: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F1E6C(rdram, ctx);
        goto after_4;
    // 0x80800D58: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x80800D5C: beq         $v0, $zero, L_80800DC8
    if (ctx->r2 == 0) {
        // 0x80800D60: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80800DC8;
    }
    // 0x80800D60: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800D64: jal         0x800F1DCC
    // 0x80800D68: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80800D68: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x80800D6C: jal         0x800F2100
    // 0x80800D70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x80800D70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80800D74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D78: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D7C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800D80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D84: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800D88: div.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800D8C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80800D90: nop

    // 0x80800D94: bc1fl       L_80800DCC
    if (!c1cs) {
        // 0x80800D98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800DCC;
    }
    goto skip_5;
    // 0x80800D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800D9C: sub.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80800DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DA4: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800DA8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X1790) << 16);
    // 0x80800DAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800DB0: addiu       $a1, $a1, 0x1790
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X1790));
    // 0x80800DB4: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80800DB8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800DBC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80800DC0: jal         0x8008A8F0
    // 0x80800DC4: nop

    _sufade_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800DC4: nop

    after_7:
L_80800DC8:
    // 0x80800DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DCC:
    // 0x80800DCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800DD4: jr          $ra
    // 0x80800DD8: nop

    return;
    // 0x80800DD8: nop

;}
RECOMP_FUNC void func_808000D8_sulights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: lwc1        $f6, 0x38($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38);
    // 0x808000E4: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x808000E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000EC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x808000F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000F4: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x808000F8: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800100: beq         $v0, $a0, L_80800144
    if (ctx->r2 == ctx->r4) {
        // 0x80800104: lw          $t6, 0x10($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X10);
            goto L_80800144;
    }
    // 0x80800104: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
L_80800108:
    // 0x80800108: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8080010C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80800110: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800114: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800118: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8080011C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800120: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800124: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800128: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8080012C: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800130: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80800134: nop

    // 0x80800138: sw          $t9, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r25;
    // 0x8080013C: bne         $v0, $a0, L_80800108
    if (ctx->r2 != ctx->r4) {
        // 0x80800140: lw          $t6, 0x10($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X10);
            goto L_80800108;
    }
    // 0x80800140: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
L_80800144:
    // 0x80800144: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80800148: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8080014C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800150: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800154: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800158: nop

    // 0x8080015C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800160: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800164: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800168: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080016C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80800170: nop

    // 0x80800174: sw          $t9, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r25;
    // 0x80800178: lbu         $a0, 0x1($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X1);
    // 0x8080017C: jal         0x800C8E84
    // 0x80800180: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C8E84(rdram, ctx);
        goto after_0;
    // 0x80800180: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800188: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_80801190_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801198: jal         0x80085250
    // 0x8080119C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x8080119C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011A0: jal         0x80800F94
    // 0x808011A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808011A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808011A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011B0: jr          $ra
    // 0x808011B4: nop

    return;
    // 0x808011B4: nop

;}
RECOMP_FUNC void func_80800008_basquash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: beq         $a1, $at, L_80800038
    if (ctx->r5 == ctx->r1) {
        // 0x80800018: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800038;
    }
    // 0x80800018: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080001C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800020: beq         $a1, $at, L_80800070
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800070;
    }
    // 0x80800024: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800028: beq         $a1, $at, L_808000B8
    if (ctx->r5 == ctx->r1) {
        // 0x8080002C: nop
    
            goto L_808000B8;
    }
    // 0x8080002C: nop

    // 0x80800030: b           L_808000CC
    // 0x80800034: lw          $t2, 0x11C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X11C);
        goto L_808000CC;
    // 0x80800034: lw          $t2, 0x11C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X11C);
L_80800038:
    // 0x80800038: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080003C: lw          $t6, 0x11C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X11C);
    // 0x80800040: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800044: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800048: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x8080004C: lw          $t7, 0x11C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X11C);
    // 0x80800050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800054: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x80800058: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8080005C: jal         0x8009ADF0
    // 0x80800060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80800060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: b           L_808000C8
    // 0x8080006C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C8;
    // 0x8080006C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800070:
    // 0x80800070: lw          $t8, 0x11C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X11C);
    // 0x80800074: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800078: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080007C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80800080: lw          $t9, 0x11C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X11C);
    // 0x80800084: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800088: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080008C: swc1        $f8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f8.u32l;
    // 0x80800090: lw          $t0, 0x11C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X11C);
    // 0x80800094: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080009C: swc1        $f10, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f10.u32l;
    // 0x808000A0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808000A4: jal         0x8009ADF0
    // 0x808000A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009ADF0(rdram, ctx);
        goto after_1;
    // 0x808000A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: b           L_808000C8
    // 0x808000B4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C8;
    // 0x808000B4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808000B8:
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X630) << 16);
    // 0x808000BC: lwc1        $f16, 0x630($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(600, 0X630));
    // 0x808000C0: lw          $t1, 0x11C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X11C);
    // 0x808000C4: swc1        $f16, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f16.u32l;
L_808000C8:
    // 0x808000C8: lw          $t2, 0x11C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X11C);
L_808000CC:
    // 0x808000CC: sb          $a3, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r7;
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_80801470_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080147C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801480: lbu         $t7, 0x5C($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X5C);
    // 0x80801484: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801488: bnel        $t7, $at, L_808014EC
    if (ctx->r15 != ctx->r1) {
        // 0x8080148C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808014EC;
    }
    goto skip_0;
    // 0x8080148C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801490: jal         0x800F54E4
    // 0x80801494: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801494: nop

    after_0:
    // 0x80801498: jal         0x800F5EF8
    // 0x8080149C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_1;
    // 0x8080149C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808014A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808014A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014A8: addiu       $a1, $v1, 0x38
    ctx->r5 = ADD32(ctx->r3, 0X38);
    // 0x808014AC: jal         0x8010FFB0
    // 0x808014B0: addiu       $a2, $v1, 0x44
    ctx->r6 = ADD32(ctx->r3, 0X44);
    func_8010FFB0(rdram, ctx);
        goto after_2;
    // 0x808014B0: addiu       $a2, $v1, 0x44
    ctx->r6 = ADD32(ctx->r3, 0X44);
    after_2:
    // 0x808014B4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808014B8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808014BC: jal         0x800A89F8
    // 0x808014C0: sb          $t8, 0x5C($t9)
    MEM_B(0X5C, ctx->r25) = ctx->r24;
    func_800A89F8(rdram, ctx);
        goto after_3;
    // 0x808014C0: sb          $t8, 0x5C($t9)
    MEM_B(0X5C, ctx->r25) = ctx->r24;
    after_3:
    // 0x808014C4: jal         0x800A9478
    // 0x808014C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_4;
    // 0x808014C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808014CC: jal         0x800F5EF8
    // 0x808014D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_5;
    // 0x808014D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808014D4: jal         0x80110024
    // 0x808014D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_6;
    // 0x808014D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808014DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014E0: jal         0x80089520
    // 0x808014E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x808014E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808014E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014EC:
    // 0x808014EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014F0: jr          $ra
    // 0x808014F4: nop

    return;
    // 0x808014F4: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF4: jr          $ra
    // 0x80800CF8: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    return;
    // 0x80800CF8: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800D5240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5240: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5244: jr          $ra
    // 0x800D5248: lw          $v0, -0x4BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BE0);
    return;
    // 0x800D5248: lw          $v0, -0x4BE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BE0);
    // 0x800D524C: nop

;}
RECOMP_FUNC void func_80800094_bskazflamethrower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800098: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A4: jal         0x8008CABC
    // 0x808000A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808000A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000AC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B4: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x808000B8: beq         $at, $zero, L_808001C4
    if (ctx->r1 == 0) {
        // 0x808000BC: sw          $v1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r3;
            goto L_808001C4;
    }
    // 0x808000BC: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
    // 0x808000C0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(232, 0X390) << 16);
    // 0x808000C8: addu        $at, $at, $t6
    gpr jr_addend_808000D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000CC: lw          $t6, 0x390($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(232, 0X390));
    // 0x808000D0: jr          $t6
    // 0x808000D4: nop

    switch (jr_addend_808000D0 >> 2) {
        case 0: goto L_808001BC; break;
        case 1: goto L_808000D8; break;
        case 2: goto L_8080013C; break;
        case 3: goto L_8080017C; break;
        case 4: goto L_808001A0; break;
        default: switch_error(__func__, 0x808000D0, 0x80800390);
    }
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x808000E0: jal         0x8008CCBC
    // 0x808000E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808000E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x808000E8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808000EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808000FC: jal         0x8009FFD8
    // 0x80800100: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800100: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x80800104: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x80800108: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x8009C99C
    // 0x80800114: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800114: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_3:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x8009B9B0
    // 0x80800120: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800120: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800124: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800128: addiu       $a1, $a1, 0x3348
    ctx->r5 = ADD32(ctx->r5, 0X3348);
    // 0x8080012C: jal         0x80084BA8
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800134: b           L_808001C8
    // 0x80800138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001C8;
    // 0x80800138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080013C:
    // 0x8080013C: lui         $a1, 0x3EC0
    ctx->r5 = S32(0X3EC0 << 16);
    // 0x80800140: lui         $a2, 0x3F10
    ctx->r6 = S32(0X3F10 << 16);
    // 0x80800144: jal         0x8008B1D4
    // 0x80800148: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800148: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_6:
    // 0x8080014C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800150: jal         0x8008B134
    // 0x80800154: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800154: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80800158: lui         $a2, 0x3E0F
    ctx->r6 = S32(0X3E0F << 16);
    // 0x8080015C: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: jal         0x80085338
    // 0x80800168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x80800168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8080016C: jal         0x80084BB0
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800174: b           L_808001C8
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001C8;
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080017C:
    // 0x8080017C: jal         0x80084BB8
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800184: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80800188: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x80085338
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_11;
    // 0x80800194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800198: b           L_808001C8
    // 0x8080019C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001C8;
    // 0x8080019C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001A0:
    // 0x808001A0: jal         0x8008B134
    // 0x808001A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x808001A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x8008CED4
    // 0x808001B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_13;
    // 0x808001B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x808001B4: b           L_808001C8
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001C8;
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001BC:
    // 0x808001BC: jal         0x80084BA0
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808001C4:
    // 0x808001C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C8:
    // 0x808001C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void func_800F45B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F45B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F45B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F45B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F45BC: jal         0x8009CCFC
    // 0x800F45C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8009CCFC(rdram, ctx);
        goto after_0;
    // 0x800F45C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F45C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800F45C8: jal         0x8009CD70
    // 0x800F45CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8009CD70(rdram, ctx);
        goto after_1;
    // 0x800F45CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800F45D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F45D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F45D8: jr          $ra
    // 0x800F45DC: nop

    return;
    // 0x800F45DC: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895C0: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800895C0);
    return;
    // 0x800895C4: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void func_80800D34_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D3C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800D40: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X1168) << 16);
    // 0x80800D44: addiu       $a2, $a2, 0x1168
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X1168));
    // 0x80800D48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800D50: jal         0x80089D20
    // 0x80800D54: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800D54: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_0:
    // 0x80800D58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(892, 0XF10) << 16);
    // 0x80800D5C: jal         0x800DC298
    // 0x80800D60: lwc1        $f12, 0xF10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(892, 0XF10));
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80800D60: lwc1        $f12, 0xF10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(892, 0XF10));
    after_1:
    // 0x80800D64: beq         $v0, $zero, L_80800D7C
    if (ctx->r2 == 0) {
        // 0x80800D68: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800D7C;
    }
    // 0x80800D68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D6C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X1178) << 16);
    // 0x80800D70: addiu       $a2, $a2, 0x1178
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X1178));
    // 0x80800D74: jal         0x80089D18
    // 0x80800D78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800D78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80800D7C:
    // 0x80800D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D84: jr          $ra
    // 0x80800D88: nop

    return;
    // 0x80800D88: nop

;}
RECOMP_FUNC void _chcollballcontrol_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E98: syscall     467
    recomp_syscall_handler(rdram, ctx, 0x80086E98);
    return;
    // 0x80086E9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
