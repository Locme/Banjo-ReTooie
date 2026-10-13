#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800044_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800054: jal         0x8009C128
    // 0x80800058: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800058: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x80096394
    // 0x80800064: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80096394(rdram, ctx);
        goto after_1;
    // 0x80800064: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80800068: jal         0x800962D4
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800962D4(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800070: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800074: jal         0x80096518
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096518(rdram, ctx);
        goto after_3;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080007C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800080: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800084: jal         0x8009BB50
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_4;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080008C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800090: jal         0x8009650C
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_5;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800098: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800128;
    }
    // 0x8080009C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808000A0: beq         $t7, $zero, L_80800128
    if (ctx->r15 == 0) {
        // 0x808000A4: lwc1        $f4, 0x4C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80800128;
    }
    // 0x808000A4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808000A8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808000AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000B4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000B8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000BC: nop

    // 0x808000C0: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x808000C4: sw          $zero, 0x164($s0)
        MEM_W(0X164, ctx->r16) = 0;
            goto L_8080012C;
    }
    goto skip_0;
    // 0x808000C4: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    skip_0:
    // 0x808000C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000CC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x808000D0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808000D4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808000D8: nop

    // 0x808000DC: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x808000E0: sw          $zero, 0x164($s0)
        MEM_W(0X164, ctx->r16) = 0;
            goto L_8080012C;
    }
    goto skip_1;
    // 0x808000E0: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    skip_1:
    // 0x808000E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000E8: nop

    // 0x808000EC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808000F0: nop

    // 0x808000F4: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x808000F8: sw          $zero, 0x164($s0)
        MEM_W(0X164, ctx->r16) = 0;
            goto L_8080012C;
    }
    goto skip_2;
    // 0x808000F8: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    skip_2:
    // 0x808000FC: lw          $t8, 0x164($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X164);
    // 0x80800100: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800104: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800108: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8080010C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800110: jal         0x800F13F0
    // 0x80800114: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F13F0(rdram, ctx);
        goto after_6;
    // 0x80800114: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_6:
    // 0x80800118: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080011C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80800120: b           L_8080012C
    // 0x80800124: sw          $t1, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r9;
        goto L_8080012C;
    // 0x80800124: sw          $t1, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r9;
L_80800128:
    // 0x80800128: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
L_8080012C:
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800130: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800134: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_808011CC_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808011D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808011DC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808011E0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808011E4: beql        $a1, $t7, L_8080122C
    if (ctx->r5 == ctx->r15) {
        // 0x808011E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080122C;
    }
    goto skip_0;
    // 0x808011E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808011EC: jal         0x80101FDC
    // 0x808011F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808011F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011F8: jal         0x80100094
    // 0x808011FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808011FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801200: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801204: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(880, 0X13E4) << 16);
    // 0x80801208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080120C: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80801210: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80801214: lwc1        $f6, 0x13E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X13E4));
    // 0x80801218: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x8080121C: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x80801220: jal         0x80018820
    // 0x80801224: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80801224: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080122C:
    // 0x8080122C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801230: jr          $ra
    // 0x80801234: nop

    return;
    // 0x80801234: nop

;}
RECOMP_FUNC void func_80106E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106E50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106E54: lw          $a0, 0x6F00($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F00);
    // 0x80106E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106E60: beql        $a0, $zero, L_80106E7C
    if (ctx->r4 == 0) {
        // 0x80106E64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106E7C;
    }
    goto skip_0;
    // 0x80106E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106E68: jal         0x800B32E4
    // 0x80106E6C: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x80106E6C: nop

    after_0:
    // 0x80106E70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106E74: sw          $v0, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->r2;
    // 0x80106E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106E7C:
    // 0x80106E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106E80: jr          $ra
    // 0x80106E84: nop

    return;
    // 0x80106E84: nop

;}
RECOMP_FUNC void func_800D7184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7184: beq         $a1, $zero, L_800D71C0
    if (ctx->r5 == 0) {
        // 0x800D7188: sll         $t3, $a0, 2
        ctx->r11 = S32(ctx->r4 << 2);
            goto L_800D71C0;
    }
    // 0x800D7188: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x800D718C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D7190: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800D7194: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D7198: addiu       $t7, $t7, -0x4800
    ctx->r15 = ADD32(ctx->r15, -0X4800);
    // 0x800D719C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D71A0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800D71A4: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x800D71A8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D71AC: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800D71B0: andi        $t1, $t8, 0xFFF0
    ctx->r9 = ctx->r24 & 0XFFF0;
    // 0x800D71B4: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x800D71B8: jr          $ra
    // 0x800D71BC: sb          $t2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r10;
    return;
    // 0x800D71BC: sb          $t2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r10;
L_800D71C0:
    // 0x800D71C0: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800D71C4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800D71C8: addiu       $t4, $t4, -0x4800
    ctx->r12 = ADD32(ctx->r12, -0X4800);
    // 0x800D71CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800D71D0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800D71D4: lbu         $t5, 0xA($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XA);
    // 0x800D71D8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800D71DC: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800D71E0: andi        $t8, $t5, 0xFFF0
    ctx->r24 = ctx->r13 & 0XFFF0;
    // 0x800D71E4: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D71E8: sb          $t9, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r25;
    // 0x800D71EC: jr          $ra
    // 0x800D71F0: nop

    return;
    // 0x800D71F0: nop

;}
RECOMP_FUNC void chdinofamilysick_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2408, 0XEA8) << 16);
    // 0x808005F0: jr          $ra
    // 0x808005F4: addiu       $v0, $v0, 0xEA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2408, 0XEA8));
    return;
    // 0x808005F4: addiu       $v0, $v0, 0xEA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2408, 0XEA8));
;}
RECOMP_FUNC void _chseaweedbaddy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F30: syscall     261
    recomp_syscall_handler(rdram, ctx, 0x80085F30);
    return;
    // 0x80085F34: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcnewoption_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801628: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080162C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80801630: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FD4) << 16);
    // 0x80801634: lwc1        $f22, 0x2FD4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FD4));
    // 0x80801638: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080163C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80801640: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80801644: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801648: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8080164C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80801650: jal         0x80802D94
    // 0x80801654: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    gcnewoption_entrypoint_42(rdram, ctx);
        goto after_0;
    // 0x80801654: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    after_0:
    // 0x80801658: lbu         $t7, 0x1D($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1D);
    // 0x8080165C: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x80801660: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80801664: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80801668: beq         $a0, $zero, L_80801688
    if (ctx->r4 == 0) {
        // 0x8080166C: sb          $t8, 0x1D($s2)
        MEM_B(0X1D, ctx->r18) = ctx->r24;
            goto L_80801688;
    }
    // 0x8080166C: sb          $t8, 0x1D($s2)
    MEM_B(0X1D, ctx->r18) = ctx->r24;
    // 0x80801670: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801674: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80801678: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8080167C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801680: jal         0x80087B80
    // 0x80801684: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80801684: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
L_80801688:
    // 0x80801688: lh          $v0, 0x2($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2);
    // 0x8080168C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801690: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801694: blezl       $v0, L_808016E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801698: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808016E4;
    }
    goto skip_0;
    // 0x80801698: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8080169C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808016A0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_808016A4:
    // 0x808016A4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808016A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808016AC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808016B0: beql        $a0, $zero, L_808016D4
    if (ctx->r4 == 0) {
        // 0x808016B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808016D4;
    }
    goto skip_1;
    // 0x808016B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x808016B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808016BC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x808016C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808016C4: jal         0x80087B80
    // 0x808016C8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808016C8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x808016CC: lh          $v0, 0x2($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2);
    // 0x808016D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808016D4:
    // 0x808016D4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808016D8: bne         $at, $zero, L_808016A4
    if (ctx->r1 != 0) {
        // 0x808016DC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808016A4;
    }
    // 0x808016DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808016E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808016E4:
    // 0x808016E4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x808016E8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x808016EC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808016F0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808016F4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808016F8: jr          $ra
    // 0x808016FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808016FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C48: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C48);
    return;
    // 0x80083C4C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void chwitchyentrygates_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2012, 0X1F0) << 16);
    // 0x808001E0: jr          $ra
    // 0x808001E4: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2012, 0X1F0));
    return;
    // 0x808001E4: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2012, 0X1F0));
;}
RECOMP_FUNC void func_80012520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012520: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80012524: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012528: jr          $ra
    // 0x8001252C: sw          $t6, 0x3384($at)
    MEM_W(0X3384, ctx->r1) = ctx->r14;
    return;
    // 0x8001252C: sw          $t6, 0x3384($at)
    MEM_W(0X3384, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_80800264_sccustom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800268: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8080026C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800270: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80800278: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080027C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800280: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80800284: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80800288: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8080028C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800290: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800294: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800298: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080029C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808002A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808002A4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x808002A8: jal         0x8008A5D8
    // 0x808002AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _scinfobar_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808002AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808002B0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002B4: jal         0x8008A610
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002BC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808002C0: jal         0x8008A5F8
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002C8: jal         0x800B8C50
    // 0x808002CC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_800B8C50(rdram, ctx);
        goto after_3;
    // 0x808002CC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_3:
    // 0x808002D0: jal         0x8008A608
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _scinfobar_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002D8: beq         $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808002FC;
    }
    // 0x808002DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002E0: beq         $v0, $at, L_80800304
    if (ctx->r2 == ctx->r1) {
        // 0x808002E4: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_80800304;
    }
    // 0x808002E4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x808002E8: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x808002EC: beq         $v0, $s4, L_80800318
    if (ctx->r2 == ctx->r20) {
        // 0x808002F0: nop
    
            goto L_80800318;
    }
    // 0x808002F0: nop

    // 0x808002F4: b           L_80800378
    // 0x808002F8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
        goto L_80800378;
    // 0x808002F8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_808002FC:
    // 0x808002FC: b           L_80800374
    // 0x80800300: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
        goto L_80800374;
    // 0x80800300: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_80800304:
    // 0x80800304: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80800308: jal         0x800B8CBC
    // 0x8080030C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_800B8CBC(rdram, ctx);
        goto after_5;
    // 0x8080030C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_5:
    // 0x80800310: b           L_80800374
    // 0x80800314: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
        goto L_80800374;
    // 0x80800314: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_80800318:
    // 0x80800318: jal         0x8001211C
    // 0x8080031C: nop

    func_8001211C(rdram, ctx);
        goto after_6;
    // 0x8080031C: nop

    after_6:
    // 0x80800320: sll         $a0, $v0, 5
    ctx->r4 = S32(ctx->r2 << 5);
    // 0x80800324: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800328: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8080032C: bne         $at, $zero, L_8080033C
    if (ctx->r1 != 0) {
        // 0x80800330: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8080033C;
    }
    // 0x80800330: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80800334: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x80800338: subu        $v1, $t7, $t6
    ctx->r3 = SUB32(ctx->r15, ctx->r14);
L_8080033C:
    // 0x8080033C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80800340: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800344: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800348: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080034C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800350: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800354: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80800358: nop

    // 0x8080035C: addiu       $a0, $v1, 0x7F
    ctx->r4 = ADD32(ctx->r3, 0X7F);
    // 0x80800360: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x80800364: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800368: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x8080036C: jal         0x800B8CBC
    // 0x80800370: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    func_800B8CBC(rdram, ctx);
        goto after_7;
    // 0x80800370: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    after_7:
L_80800374:
    // 0x80800374: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_80800378:
    // 0x80800378: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080037C: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x80800380: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800384: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80800388: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080038C: lw          $s1, 0x68($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X68);
    // 0x80800390: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x80800394: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800398: add.s       $f26, $f6, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080039C: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x808003A0: nop

    // 0x808003A4: bc1f        L_808003DC
    if (!c1cs) {
        // 0x808003A8: nop
    
            goto L_808003DC;
    }
    // 0x808003A8: nop

    // 0x808003AC: sub.s       $f16, $f26, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x808003B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003B8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808003BC: div.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f26.fl);
    // 0x808003C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003C4: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x808003C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003CC: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808003D0: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x808003D4: b           L_808003DC
    // 0x808003D8: nop

        goto L_808003DC;
    // 0x808003D8: nop

L_808003DC:
    // 0x808003DC: jal         0x800E7188
    // 0x808003E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E7188(rdram, ctx);
        goto after_8;
    // 0x808003E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x808003E4: addiu       $s2, $v0, -0x1
    ctx->r18 = ADD32(ctx->r2, -0X1);
    // 0x808003E8: jal         0x800B8C8C
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B8C8C(rdram, ctx);
        goto after_9;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003F0: jal         0x800B7F14
    // 0x808003F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800B7F14(rdram, ctx);
        goto after_10;
    // 0x808003F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x808003F8: bltz        $s2, L_80800488
    if (SIGNED(ctx->r18) < 0) {
        // 0x808003FC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_80800488;
    }
    // 0x808003FC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80800400: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80800404: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800408: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080040C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80800410: nop

    // 0x80800414: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800418: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
L_8080041C:
    // 0x8080041C: subu        $t2, $s2, $s0
    ctx->r10 = SUB32(ctx->r18, ctx->r16);
    // 0x80800420: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80800424: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800428: addu        $t4, $s1, $s0
    ctx->r12 = ADD32(ctx->r17, ctx->r16);
    // 0x8080042C: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x80800430: add.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f6.fl;
    // 0x80800434: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80800438: nop

    // 0x8080043C: bc1f        L_80800448
    if (!c1cs) {
        // 0x80800440: nop
    
            goto L_80800448;
    }
    // 0x80800440: nop

    // 0x80800444: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_80800448:
    // 0x80800448: bnel        $s3, $s4, L_80800460
    if (ctx->r19 != ctx->r20) {
        // 0x8080044C: lbu         $a3, 0x0($t4)
        ctx->r7 = MEM_BU(ctx->r12, 0X0);
            goto L_80800460;
    }
    goto skip_0;
    // 0x8080044C: lbu         $a3, 0x0($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X0);
    skip_0:
    // 0x80800450: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80800454: b           L_80800460
    // 0x80800458: lbu         $a3, 0x0($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X0);
        goto L_80800460;
    // 0x80800458: lbu         $a3, 0x0($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X0);
    // 0x8080045C: lbu         $a3, 0x0($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X0);
L_80800460:
    // 0x80800460: add.s       $f8, $f22, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x80800464: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800468: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8080046C: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800470: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800474: jal         0x800B8DEC
    // 0x80800478: nop

    func_800B8DEC(rdram, ctx);
        goto after_11;
    // 0x80800478: nop

    after_11:
    // 0x8080047C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800480: bgezl       $s0, L_8080041C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80800484: mtc1        $s0, $f18
        ctx->f18.u32l = ctx->r16;
            goto L_8080041C;
    }
    goto skip_1;
    // 0x80800484: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    skip_1:
L_80800488:
    // 0x80800488: jal         0x800B811C
    // 0x8080048C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800B811C(rdram, ctx);
        goto after_12;
    // 0x8080048C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x80800490: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800494: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800498: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080049C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808004A0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808004A4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808004A8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808004AC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x808004B0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x808004B4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x808004B8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x808004BC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x808004C0: jr          $ra
    // 0x808004C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808004C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _plcamera_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878C8: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878C8);
    return;
    // 0x800878CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808000B0_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808000C8: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808000CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808000D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808000D4: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x808000D8: beq         $t7, $zero, L_808000FC
    if (ctx->r15 == 0) {
        // 0x808000DC: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_808000FC;
    }
    // 0x808000DC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000E4: beq         $t7, $at, L_80800118
    if (ctx->r15 == ctx->r1) {
        // 0x808000E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800118;
    }
    // 0x808000E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000EC: beql        $t7, $at, L_80800108
    if (ctx->r15 == ctx->r1) {
        // 0x808000F0: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808000F4: b           L_8080012C
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080012C;
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000FC:
    // 0x808000FC: jal         0x800856B0
    // 0x80800100: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800100: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x80800104: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_80800108:
    // 0x80800108: lhu         $t0, 0x6E($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6E);
    // 0x8080010C: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800110: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80800114: sh          $t2, 0x6E($t9)
    MEM_H(0X6E, ctx->r25) = ctx->r10;
L_80800118:
    // 0x80800118: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080011C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800120: jal         0x800856D0
    // 0x80800124: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800124: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080012C:
    // 0x8080012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void func_80807D48_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807D50: jal         0x80802BE0
    // 0x80807D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802BE0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80807D58: jal         0x8080800C
    // 0x80807D5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080800C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807D5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80807D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807D68: jr          $ra
    // 0x80807D6C: nop

    return;
    // 0x80807D6C: nop

;}
RECOMP_FUNC void func_80801214_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801214: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1752, 0X4E18) << 16);
    // 0x80801218: addiu       $t6, $t6, 0x4E18
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1752, 0X4E18));
    // 0x8080121C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801220: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80801224: addiu       $v0, $sp, 0x0
    ctx->r2 = ADD32(ctx->r29, 0X0);
    // 0x80801228: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x8080122C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80801230: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80801234: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80801238: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8080123C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80801240: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x80801244: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80801248: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8080124C: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80801250: jr          $ra
    // 0x80801254: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80801254: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void gcfrontend_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800320: beq         $a1, $zero, L_80800330
    if (ctx->r5 == 0) {
        // 0x80800324: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800330;
    }
    // 0x80800324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800328: b           L_80800334
    // 0x8080032C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800334;
    // 0x8080032C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800330:
    // 0x80800330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800334:
    // 0x80800334: jal         0x808002DC
    // 0x80800338: nop

    func_808002DC_gcfrontend(rdram, ctx);
        goto after_0;
    // 0x80800338: nop

    after_0:
    // 0x8080033C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800344: jr          $ra
    // 0x80800348: nop

    return;
    // 0x80800348: nop

;}
RECOMP_FUNC void _ncbawaypoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089450: syscall     780
    recomp_syscall_handler(rdram, ctx, 0x80089450);
    return;
    // 0x80089454: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_808016B4_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808016C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808016C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808016C8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808016CC: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x808016D0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x808016D4: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x808016D8: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // 0x808016DC: beq         $v0, $zero, L_80801700
    if (ctx->r2 == 0) {
        // 0x808016E0: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80801700;
    }
    // 0x808016E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808016E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808016E8: beq         $v0, $at, L_80801710
    if (ctx->r2 == ctx->r1) {
        // 0x808016EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801710;
    }
    // 0x808016EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808016F0: beql        $v0, $at, L_80801724
    if (ctx->r2 == ctx->r1) {
        // 0x808016F4: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80801724;
    }
    goto skip_0;
    // 0x808016F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808016F8: b           L_80801734
    // 0x808016FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801734;
    // 0x808016FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801700:
    // 0x80801700: jal         0x800856B0
    // 0x80801704: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801704: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x80801708: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080170C: lhu         $v1, 0x76($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X76);
L_80801710:
    // 0x80801710: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80801714: andi        $t9, $v1, 0x7F
    ctx->r25 = ctx->r3 & 0X7F;
    // 0x80801718: ori         $t0, $t9, 0x100
    ctx->r8 = ctx->r25 | 0X100;
    // 0x8080171C: sh          $t0, 0x76($t1)
    MEM_H(0X76, ctx->r9) = ctx->r8;
    // 0x80801720: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80801724:
    // 0x80801724: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801728: jal         0x800856D0
    // 0x8080172C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080172C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80801730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801734:
    // 0x80801734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801738: jr          $ra
    // 0x8080173C: nop

    return;
    // 0x8080173C: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080067C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800684: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80800688: jal         0x80800590
    // 0x8080068C: addiu       $a3, $a3, -0x14C0
    ctx->r7 = ADD32(ctx->r7, -0X14C0);
    func_80800590_gccubesearch(rdram, ctx);
        goto after_0;
    // 0x8080068C: addiu       $a3, $a3, -0x14C0
    ctx->r7 = ADD32(ctx->r7, -0X14C0);
    after_0:
    // 0x80800690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800698: jr          $ra
    // 0x8080069C: nop

    return;
    // 0x8080069C: nop

;}
RECOMP_FUNC void chanemone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080088C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1032, 0X964) << 16);
    // 0x80800890: jr          $ra
    // 0x80800894: addiu       $v0, $v0, 0x964
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1032, 0X964));
    return;
    // 0x80800894: addiu       $v0, $v0, 0x964
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1032, 0X964));
    // 0x80800898: nop

    // 0x8080089C: nop

;}
RECOMP_FUNC void func_80110BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80110BFC: jal         0x800893F0
    // 0x80110C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _ncba1p_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80110C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80110C04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80110C08: jal         0x800893F8
    // 0x80110C0C: addiu       $a1, $a0, 0x74
    ctx->r5 = ADD32(ctx->r4, 0X74);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80110C0C: addiu       $a1, $a0, 0x74
    ctx->r5 = ADD32(ctx->r4, 0X74);
    after_1:
    // 0x80110C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80110C14: jal         0x80089400
    // 0x80110C18: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80110C18: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    after_2:
    // 0x80110C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110C24: jr          $ra
    // 0x80110C28: nop

    return;
    // 0x80110C28: nop

;}
RECOMP_FUNC void func_80103D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103D2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80103D30: jal         0x80103BF0
    // 0x80103D34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103BF0(rdram, ctx);
        goto after_0;
    // 0x80103D34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80103D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103D40: jr          $ra
    // 0x80103D44: nop

    return;
    // 0x80103D44: nop

;}
RECOMP_FUNC void func_80800144_chcaveofhorrorsdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: jal         0x80101080
    // 0x80800150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800154: jal         0x80106790
    // 0x80800158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800160: jal         0x800866B8
    // 0x80800164: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800164: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x80800168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080016C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(828, 0X208) << 16);
    // 0x80800170: addiu       $a1, $a1, 0x208
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(828, 0X208));
    // 0x80800174: jal         0x800C4AF0
    // 0x80800178: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800C4AF0(rdram, ctx);
        goto after_3;
    // 0x80800178: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x8080017C: jal         0x808001A4
    // 0x80800180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001A4_chcaveofhorrorsdoors(rdram, ctx);
        goto after_4;
    // 0x80800180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800184: jal         0x800DA544
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8080018C: jal         0x800FFAB0
    // 0x80800190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80800190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080019C: jr          $ra
    // 0x808001A0: nop

    return;
    // 0x808001A0: nop

;}
RECOMP_FUNC void func_808006F8_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800700: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800704: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80800708: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x8080070C: bltzl       $t8, L_80800734
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800710: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800734;
    }
    goto skip_0;
    // 0x80800710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800714: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x80800718: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080071C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800720: beql        $t0, $at, L_80800734
    if (ctx->r8 == ctx->r1) {
        // 0x80800724: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800734;
    }
    goto skip_1;
    // 0x80800724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800728: jal         0x80800680
    // 0x8080072C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800680_chonearmbandit(rdram, ctx);
        goto after_0;
    // 0x8080072C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x80800730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800734:
    // 0x80800734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800738: jr          $ra
    // 0x8080073C: nop

    return;
    // 0x8080073C: nop

;}
RECOMP_FUNC void chbaddieDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800004: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: sb          $t6, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r14;
    return;
    // 0x8080000C: sb          $t6, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800137D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800137D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800137D8: lwc1        $f14, 0x16CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16CC);
    // 0x800137DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800137E0: or          $a1, $ra, $zero
    ctx->r5 = ctx->r31 | 0;
    // 0x800137E4: jal         0x80013818
    // 0x800137E8: lwc1        $f16, 0x16D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16D0);
    func_80013818(rdram, ctx);
        goto after_0;
    // 0x800137E8: lwc1        $f16, 0x16D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16D0);
    after_0:
    // 0x800137EC: jr          $a1
    // 0x800137F0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
    return;
    // 0x800137F0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_800C3CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3CE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3CEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C3CF0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3CF4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3CF8: beq         $t6, $zero, L_800C3D68
    if (ctx->r14 == 0) {
        // 0x800C3CFC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C3D68;
    }
    // 0x800C3CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3D00: jal         0x800C1414
    // 0x800C3D04: sb          $t6, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r14;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3D04: sb          $t6, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C3D08: lw          $t7, 0x78($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X78);
    // 0x800C3D0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3D10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3D14: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x800C3D18: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800C3D1C: bnel        $t9, $at, L_800C3D6C
    if (ctx->r25 != ctx->r1) {
        // 0x800C3D20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C3D6C;
    }
    goto skip_0;
    // 0x800C3D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C3D24: jal         0x800C1860
    // 0x800C3D28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C1860(rdram, ctx);
        goto after_1;
    // 0x800C3D28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C3D2C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3D30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800C3D34: lw          $t0, 0x78($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X78);
    // 0x800C3D38: sll         $t2, $t0, 29
    ctx->r10 = S32(ctx->r8 << 29);
    // 0x800C3D3C: bgezl       $t2, L_800C3D54
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800C3D40: lw          $v0, 0x64($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X64);
            goto L_800C3D54;
    }
    goto skip_1;
    // 0x800C3D40: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    skip_1:
    // 0x800C3D44: jal         0x800FECB8
    // 0x800C3D48: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800FECB8(rdram, ctx);
        goto after_2;
    // 0x800C3D48: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x800C3D4C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3D50: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
L_800C3D54:
    // 0x800C3D54: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800C3D58: beql        $v0, $zero, L_800C3D6C
    if (ctx->r2 == 0) {
        // 0x800C3D5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C3D6C;
    }
    goto skip_2;
    // 0x800C3D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800C3D60: jalr        $v0
    // 0x800C3D64: lw          $a1, 0x68($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X68);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800C3D64: lw          $a1, 0x68($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X68);
    after_3:
L_800C3D68:
    // 0x800C3D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3D6C:
    // 0x800C3D6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3D70: jr          $ra
    // 0x800C3D74: nop

    return;
    // 0x800C3D74: nop

;}
RECOMP_FUNC void _chgruntylairexttowerwindow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087058: syscall     499
    recomp_syscall_handler(rdram, ctx, 0x80087058);
    return;
    // 0x8008705C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800B9C_chwumbawigwam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B9C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800BA0: addiu       $t7, $a1, -0x4
    ctx->r15 = ADD32(ctx->r5, -0X4);
    // 0x80800BA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BA8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80800BAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB4: beq         $at, $zero, L_80800DE4
    if (ctx->r1 == 0) {
        // 0x80800BB8: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_80800DE4;
    }
    // 0x80800BB8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800BBC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800BC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X10BC) << 16);
    // 0x80800BC4: addu        $at, $at, $t7
    gpr jr_addend_80800BCC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800BC8: lw          $t7, 0x10BC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2272, 0X10BC));
    // 0x80800BCC: jr          $t7
    // 0x80800BD0: nop

    switch (jr_addend_80800BCC >> 2) {
        case 0: goto L_80800BD4; break;
        case 1: goto L_80800C14; break;
        case 2: goto L_80800CE4; break;
        case 3: goto L_80800D04; break;
        case 4: goto L_80800D2C; break;
        case 5: goto L_80800D54; break;
        case 6: goto L_80800DB8; break;
        default: switch_error(__func__, 0x80800BCC, 0x808010BC);
    }
    // 0x80800BD0: nop

L_80800BD4:
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD8: jal         0x8008A4B0
    // 0x80800BDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800BDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800BE0: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800BE4: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BEC: andi        $t0, $t8, 0xFFEF
    ctx->r8 = ctx->r24 & 0XFFEF;
    // 0x80800BF0: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800BF4: andi        $t1, $t0, 0xF7
    ctx->r9 = ctx->r8 & 0XF7;
    // 0x80800BF8: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x80800BFC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800C00: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    // 0x80800C04: jal         0x8010A800
    // 0x80800C08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_1;
    // 0x80800C08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800C0C: b           L_80800DE8
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800DE8;
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C14:
    // 0x80800C14: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800C18: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80800C1C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80800C20: jal         0x80086C68
    // 0x80800C24: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800C24: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_2:
    // 0x80800C28: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800C2C: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800C30: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C3C: jal         0x80089840
    // 0x80800C40: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800C40: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_3:
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C48: jal         0x80100094
    // 0x80800C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800C4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800C50: jal         0x80089850
    // 0x80800C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C5C: jal         0x80100094
    // 0x80800C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x80800C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800C64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C68: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    // 0x80800C6C: jal         0x80089908
    // 0x80800C70: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_7;
    // 0x80800C70: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: jal         0x80100094
    // 0x80800C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x80800C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800C80: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800C84: jal         0x800DA298
    // 0x80800C88: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80800C88: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_9:
    // 0x80800C8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C90: jal         0x80089900
    // 0x80800C94: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_10;
    // 0x80800C94: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_10:
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C9C: jal         0x80100094
    // 0x80800CA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800CA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800CA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CA8: jal         0x800898B8
    // 0x80800CAC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_12;
    // 0x80800CAC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_12:
    // 0x80800CB0: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
    // 0x80800CB4: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    // 0x80800CB8: jal         0x80101180
    // 0x80800CBC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x80800CBC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_13:
    // 0x80800CC0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CC8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800CCC: jal         0x80085708
    // 0x80800CD0: addiu       $a3, $zero, 0x210
    ctx->r7 = ADD32(0, 0X210);
    _capod_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x80800CD0: addiu       $a3, $zero, 0x210
    ctx->r7 = ADD32(0, 0X210);
    after_14:
    // 0x80800CD4: jal         0x800DA544
    // 0x80800CD8: addiu       $a0, $zero, 0x57D
    ctx->r4 = ADD32(0, 0X57D);
    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x80800CD8: addiu       $a0, $zero, 0x57D
    ctx->r4 = ADD32(0, 0X57D);
    after_15:
    // 0x80800CDC: b           L_80800DE8
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800DE8;
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800CE4:
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE8: jal         0x80100094
    // 0x80800CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CF4: jal         0x800898D0
    // 0x80800CF8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_17;
    // 0x80800CF8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_17:
    // 0x80800CFC: b           L_80800DE8
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800DE8;
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D04:
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D08: jal         0x80100094
    // 0x80800D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_18;
    // 0x80800D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800D10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D14: jal         0x800898C8
    // 0x80800D18: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_19;
    // 0x80800D18: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_19:
    // 0x80800D1C: jal         0x800DA544
    // 0x80800D20: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    func_800DA544(rdram, ctx);
        goto after_20;
    // 0x80800D20: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_20:
    // 0x80800D24: b           L_80800DE8
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800DE8;
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D2C:
    // 0x80800D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D30: jal         0x80100094
    // 0x80800D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_21;
    // 0x80800D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80800D38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D3C: jal         0x800898C8
    // 0x80800D40: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_22;
    // 0x80800D40: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_22:
    // 0x80800D44: jal         0x800DA524
    // 0x80800D48: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    func_800DA524(rdram, ctx);
        goto after_23;
    // 0x80800D48: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_23:
    // 0x80800D4C: b           L_80800DE8
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800DE8;
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D54:
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D58: jal         0x80100094
    // 0x80800D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x80800D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80800D60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D64: jal         0x800898C0
    // 0x80800D68: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_25;
    // 0x80800D68: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_25:
    // 0x80800D6C: jal         0x800DA298
    // 0x80800D70: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    func_800DA298(rdram, ctx);
        goto after_26;
    // 0x80800D70: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_26:
    // 0x80800D74: beq         $v0, $zero, L_80800D94
    if (ctx->r2 == 0) {
        // 0x80800D78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800D94;
    }
    // 0x80800D78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X10D8) << 16);
    // 0x80800D80: lwc1        $f4, 0x10D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2272, 0X10D8));
    // 0x80800D84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800D8C: b           L_80800DA0
    // 0x80800D90: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_80800DA0;
    // 0x80800D90: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_80800D94:
    // 0x80800D94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800D98: nop

    // 0x80800D9C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_80800DA0:
    // 0x80800DA0: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800DA4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800DA8: jal         0x80086AF0
    // 0x80800DAC: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_27;
    // 0x80800DAC: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    after_27:
    // 0x80800DB0: b           L_80800DE8
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800DE8;
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800DB8:
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DBC: jal         0x80089848
    // 0x80800DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_28;
    // 0x80800DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC8: jal         0x8010A800
    // 0x80800DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_29;
    // 0x80800DCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80800DD0: jal         0x800DA544
    // 0x80800DD4: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_30;
    // 0x80800DD4: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_30:
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DDC: jal         0x8008A4B0
    // 0x80800DE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_31;
    // 0x80800DE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
L_80800DE4:
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800DE8:
    // 0x80800DE8: jal         0x80101FDC
    // 0x80800DEC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101FDC(rdram, ctx);
        goto after_32;
    // 0x80800DEC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_32:
    // 0x80800DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800DFC: jr          $ra
    // 0x80800E00: nop

    return;
    // 0x80800E00: nop

;}
RECOMP_FUNC void chdinoroargrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2064, 0X258) << 16);
    // 0x8080022C: jr          $ra
    // 0x80800230: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2064, 0X258));
    return;
    // 0x80800230: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2064, 0X258));
    // 0x80800234: nop

    // 0x80800238: nop

    // 0x8080023C: nop

;}
RECOMP_FUNC void func_80800620_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800628: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1900, 0X7A8) << 16);
    // 0x8080062C: addiu       $a2, $a2, 0x7A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1900, 0X7A8));
    // 0x80800630: jal         0x8008A1E8
    // 0x80800634: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800634: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080063C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800640: jr          $ra
    // 0x80800644: nop

    return;
    // 0x80800644: nop

;}
RECOMP_FUNC void func_80801164_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080116C: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80801170: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80801174: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80801178: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    // 0x8080117C: jal         0x8010BA80
    // 0x80801180: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8010BA80(rdram, ctx);
        goto after_0;
    // 0x80801180: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801184: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801188: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080118C: swc1        $f8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f8.u32l;
    // 0x80801190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801198: jr          $ra
    // 0x8080119C: nop

    return;
    // 0x8080119C: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CD0: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CD0);
    return;
    // 0x80084CD4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80803574_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803574: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080357C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803580: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80803584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803588: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080358C: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80803590: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x80803594: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80803598: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x8080359C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x808035A0: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x808035A4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808035A8: jal         0x800EE7F8
    // 0x808035AC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808035AC: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x808035B0: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x808035B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808035B8: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808035BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808035C0: jal         0x800EA05C
    // 0x808035C4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x808035C4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x808035C8: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x808035CC: bnel        $v0, $at, L_808035E8
    if (ctx->r2 != ctx->r1) {
        // 0x808035D0: lbu         $t6, 0x7A($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X7A);
            goto L_808035E8;
    }
    goto skip_0;
    // 0x808035D0: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
    skip_0:
    // 0x808035D4: lbu         $t3, 0x7A($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7A);
    // 0x808035D8: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808035DC: b           L_808035F0
    // 0x808035E0: sb          $t4, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r12;
        goto L_808035F0;
    // 0x808035E0: sb          $t4, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r12;
    // 0x808035E4: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
L_808035E8:
    // 0x808035E8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x808035EC: sb          $t7, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r15;
L_808035F0:
    // 0x808035F0: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x808035F4: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x808035F8: beq         $t8, $zero, L_8080361C
    if (ctx->r24 == 0) {
        // 0x808035FC: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8080361C;
    }
    // 0x808035FC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80803600: jal         0x800DA298
    // 0x80803604: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80803604: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    after_2:
    // 0x80803608: bne         $v0, $zero, L_80803634
    if (ctx->r2 != 0) {
        // 0x8080360C: nop
    
            goto L_80803634;
    }
    // 0x8080360C: nop

    // 0x80803610: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x80803614: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80803618: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8080361C:
    // 0x8080361C: bnel        $v0, $zero, L_80803648
    if (ctx->r2 != 0) {
        // 0x80803620: addiu       $a0, $zero, 0x377
        ctx->r4 = ADD32(0, 0X377);
            goto L_80803648;
    }
    goto skip_1;
    // 0x80803620: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    skip_1:
    // 0x80803624: jal         0x800DA298
    // 0x80803628: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80803628: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_3:
    // 0x8080362C: beql        $v0, $zero, L_80803648
    if (ctx->r2 == 0) {
        // 0x80803630: addiu       $a0, $zero, 0x377
        ctx->r4 = ADD32(0, 0X377);
            goto L_80803648;
    }
    goto skip_2;
    // 0x80803630: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    skip_2:
L_80803634:
    // 0x80803634: jal         0x800FFAB0
    // 0x80803638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80803638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080363C: b           L_808036D4
    // 0x80803640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808036D4;
    // 0x80803640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803644: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
L_80803648:
    // 0x80803648: jal         0x80089C30
    // 0x8080364C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080364C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80803650: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x80803654: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80803658: lui         $a2, 0x4528
    ctx->r6 = S32(0X4528 << 16);
    // 0x8080365C: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x80803660: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80803664: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80803668: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8080366C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80803670: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80803674: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80803678: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8080367C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80803680: sw          $t0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r8;
    // 0x80803684: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803688: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080368C: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80803690: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80803694: jal         0x800EFCD8
    // 0x80803698: nop

    func_800EFCD8(rdram, ctx);
        goto after_6;
    // 0x80803698: nop

    after_6:
    // 0x8080369C: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x808036A0: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x808036A4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x808036A8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x808036AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808036B0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x808036B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808036B8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x808036BC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x808036C0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x808036C4: nop

    // 0x808036C8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808036CC: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x808036D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808036D4:
    // 0x808036D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808036D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808036DC: jr          $ra
    // 0x808036E0: nop

    return;
    // 0x808036E0: nop

;}
RECOMP_FUNC void glhittableDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800290: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80800294: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80800298: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8080029C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2742, 0X530) << 16);
    // 0x808002A0: addiu       $t9, $t9, 0x530
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2742, 0X530));
    // 0x808002A4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808002A8: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x808002AC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x808002B0: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x808002B4: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x808002B8: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x808002BC: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x808002C0: srl         $t4, $t3, 12
    ctx->r12 = S32(U32(ctx->r11) >> 12);
    // 0x808002C4: srl         $t6, $t5, 12
    ctx->r14 = S32(U32(ctx->r13) >> 12);
    // 0x808002C8: jr          $ra
    // 0x808002CC: or          $v0, $t4, $t6
    ctx->r2 = ctx->r12 | ctx->r14;
    return;
    // 0x808002CC: or          $v0, $t4, $t6
    ctx->r2 = ctx->r12 | ctx->r14;
;}
RECOMP_FUNC void func_8080032C_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800330: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800334: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800338: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080033C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800344: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800348: jal         0x80100094
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800350: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80800354: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800358: srl         $t7, $t6, 26
    ctx->r15 = S32(U32(ctx->r14) >> 26);
    // 0x8080035C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800360: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800364: beq         $at, $zero, L_808004B0
    if (ctx->r1 == 0) {
        // 0x80800368: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808004B0;
    }
    // 0x80800368: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080036C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1148, 0X1530) << 16);
    // 0x80800370: addu        $at, $at, $t8
    gpr jr_addend_80800378 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800374: lw          $t8, 0x1530($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1148, 0X1530));
    // 0x80800378: jr          $t8
    // 0x8080037C: nop

    switch (jr_addend_80800378 >> 2) {
        case 0: goto L_80800380; break;
        case 1: goto L_808003BC; break;
        case 2: goto L_808003F0; break;
        case 3: goto L_8080042C; break;
        case 4: goto L_80800484; break;
        default: switch_error(__func__, 0x80800378, 0x80801530);
    }
    // 0x8080037C: nop

L_80800380:
    // 0x80800380: lh          $t9, 0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X10);
    // 0x80800384: lh          $t0, 0x12($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X12);
    // 0x80800388: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8080038C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800390: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800394: jal         0x800F1DCC
    // 0x80800398: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80800398: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x8080039C: lh          $t1, 0x12($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X12);
    // 0x808003A0: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808003A4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x808003A8: nop

    // 0x808003AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003B0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808003B4: b           L_808004B0
    // 0x808003B8: swc1        $f18, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f18.u32l;
        goto L_808004B0;
    // 0x808003B8: swc1        $f18, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f18.u32l;
L_808003BC:
    // 0x808003BC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808003C0: jal         0x800EE88C
    // 0x808003C4: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808003C4: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x808003C8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808003CC: jal         0x800EE88C
    // 0x808003D0: addiu       $a1, $s0, 0x16
    ctx->r5 = ADD32(ctx->r16, 0X16);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x808003D0: addiu       $a1, $s0, 0x16
    ctx->r5 = ADD32(ctx->r16, 0X16);
    after_3:
    // 0x808003D4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808003D8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808003DC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x808003E0: jal         0x800EFE50
    // 0x808003E4: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x808003E4: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_4:
    // 0x808003E8: b           L_808004B0
    // 0x808003EC: nop

        goto L_808004B0;
    // 0x808003EC: nop

L_808003F0:
    // 0x808003F0: lh          $t2, 0x10($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X10);
    // 0x808003F4: lh          $t3, 0x12($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X12);
    // 0x808003F8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x808003FC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80800400: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800404: jal         0x800F1DCC
    // 0x80800408: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80800408: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x8080040C: lh          $t4, 0x12($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X12);
    // 0x80800410: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800414: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800418: nop

    // 0x8080041C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800420: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800424: b           L_808004B0
    // 0x80800428: swc1        $f18, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f18.u32l;
        goto L_808004B0;
    // 0x80800428: swc1        $f18, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f18.u32l;
L_8080042C:
    // 0x8080042C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800430: jal         0x800EE88C
    // 0x80800434: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_800EE88C(rdram, ctx);
        goto after_6;
    // 0x80800434: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_6:
    // 0x80800438: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080043C: jal         0x800EE88C
    // 0x80800440: addiu       $a1, $s0, 0x16
    ctx->r5 = ADD32(ctx->r16, 0X16);
    func_800EE88C(rdram, ctx);
        goto after_7;
    // 0x80800440: addiu       $a1, $s0, 0x16
    ctx->r5 = ADD32(ctx->r16, 0X16);
    after_7:
    // 0x80800444: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800448: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8080044C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80800450: jal         0x800EFE50
    // 0x80800454: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800EFE50(rdram, ctx);
        goto after_8;
    // 0x80800454: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_8:
    // 0x80800458: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x8080045C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800460: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800464: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800468: nop

    // 0x8080046C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800470: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800474: nop

    // 0x80800478: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8080047C: b           L_808004B0
    // 0x80800480: swc1        $f16, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f16.u32l;
        goto L_808004B0;
    // 0x80800480: swc1        $f16, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f16.u32l;
L_80800484:
    // 0x80800484: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800488: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080048C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800490: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800494: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x80800498: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080049C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808004A0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808004A4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808004A8: jal         0x80089C98
    // 0x808004AC: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808004AC: nop

    after_9:
L_808004B0:
    // 0x808004B0: jal         0x80103014
    // 0x808004B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103014(rdram, ctx);
        goto after_10;
    // 0x808004B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808004B8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x808004BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004C0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808004C4: sll         $t8, $t7, 15
    ctx->r24 = S32(ctx->r15 << 15);
    // 0x808004C8: bgez        $t8, L_808004F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004CC: addiu       $a2, $sp, 0x38
        ctx->r6 = ADD32(ctx->r29, 0X38);
            goto L_808004F4;
    }
    // 0x808004CC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x808004D0: jal         0x80104004
    // 0x808004D4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    func_80104004(rdram, ctx);
        goto after_11;
    // 0x808004D4: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    after_11:
    // 0x808004D8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808004DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: addiu       $a1, $s1, 0x44
    ctx->r5 = ADD32(ctx->r17, 0X44);
    // 0x808004E8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808004EC: jal         0x80089F30
    // 0x808004F0: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    _sudeflect_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808004F0: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_12:
L_808004F4:
    // 0x808004F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808004F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808004FC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800500: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800504: jr          $ra
    // 0x80800508: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800508: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void bskazshock_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800484: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080048C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800490: jal         0x8008CABC
    // 0x80800494: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800494: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800498: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080049C: jal         0x800832E0
    // 0x808004A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808004A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808004A4: jal         0x8008AF24
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x8008B1A0
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: jal         0x8008AED4
    // 0x808004C0: addiu       $a1, $zero, 0x27A
    ctx->r5 = ADD32(0, 0X27A);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x808004C0: addiu       $a1, $zero, 0x27A
    ctx->r5 = ADD32(0, 0X27A);
    after_4:
    // 0x808004C4: lui         $a1, 0x3FCC
    ctx->r5 = S32(0X3FCC << 16);
    // 0x808004C8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004CC: jal         0x8008B1BC
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808004D4: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    // 0x808004D8: ori         $a1, $a1, 0xD6A1
    ctx->r5 = ctx->r5 | 0XD6A1;
    // 0x808004DC: jal         0x8008B24C
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808004EC: jal         0x8008B1D4
    // 0x808004F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_7;
    // 0x808004F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x8008B134
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800500: jal         0x8008B064
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800508: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8080050C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800518: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080051C: jal         0x8009FFD8
    // 0x80800520: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800520: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x80800524: jal         0x8009EF04
    // 0x80800528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_11;
    // 0x80800528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8080052C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800530: nop

    // 0x80800534: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800538: nop

    // 0x8080053C: bc1t        L_80800558
    if (c1cs) {
        // 0x80800540: nop
    
            goto L_80800558;
    }
    // 0x80800540: nop

    // 0x80800544: jal         0x8009EEB8
    // 0x80800548: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_12;
    // 0x80800548: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8080054C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800550: jal         0x8009C914
    // 0x80800554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_13;
    // 0x80800554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_80800558:
    // 0x80800558: jal         0x8009C990
    // 0x8080055C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x8080055C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800560: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800564: jal         0x8009B9C0
    // 0x80800568: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x80800568: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8080056C: jal         0x800834B0
    // 0x80800570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_16;
    // 0x80800570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800574: jal         0x8009C990
    // 0x80800578: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80800578: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x8080057C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800580: jal         0x8009BB00
    // 0x80800584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800588: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080058C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800590: jal         0x8009BA68
    // 0x80800594: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800594: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x80800598: lui         $a1, 0x44E3
    ctx->r5 = S32(0X44E3 << 16);
    // 0x8080059C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808005A0: jal         0x8009BA58
    // 0x808005A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x808005A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x808005A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005AC: jal         0x8009BCB4
    // 0x808005B0: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_21;
    // 0x808005B0: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_21:
    // 0x808005B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005B8: addiu       $a1, $zero, 0x408
    ctx->r5 = ADD32(0, 0X408);
    // 0x808005BC: jal         0x8009DBF0
    // 0x808005C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DBF0(rdram, ctx);
        goto after_22;
    // 0x808005C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_22:
    // 0x808005C4: jal         0x800C6DA0
    // 0x808005C8: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_800C6DA0(rdram, ctx);
        goto after_23;
    // 0x808005C8: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_23:
    // 0x808005CC: sw          $zero, 0x160($s1)
    MEM_W(0X160, ctx->r17) = 0;
    // 0x808005D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808005D8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808005DC: jr          $ra
    // 0x808005E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808005E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800808_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080080C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800810: jal         0x80800174
    // 0x80800814: nop

    func_80800174_bsvanswim(rdram, ctx);
        goto after_0;
    // 0x80800814: nop

    after_0:
    // 0x80800818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080081C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800820: jr          $ra
    // 0x80800824: nop

    return;
    // 0x80800824: nop

;}
RECOMP_FUNC void func_80800080_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080008C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800090: jal         0x80100094
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800098: lbu         $t6, 0x26($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26);
    // 0x8080009C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000A4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808000A8: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808000AC: beq         $at, $zero, L_8080012C
    if (ctx->r1 == 0) {
        // 0x808000B0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080012C;
    }
    // 0x808000B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E30) << 16);
    // 0x808000B8: addu        $at, $at, $t7
    gpr jr_addend_808000C0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000BC: lw          $t7, 0x3E30($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E30));
    // 0x808000C0: jr          $t7
    // 0x808000C4: nop

    switch (jr_addend_808000C0 >> 2) {
        case 0: goto L_808000C8; break;
        case 1: goto L_808000DC; break;
        case 2: goto L_808000F0; break;
        case 3: goto L_80800104; break;
        case 4: goto L_80800118; break;
        default: switch_error(__func__, 0x808000C0, 0x80803E30);
    }
    // 0x808000C4: nop

L_808000C8:
    // 0x808000C8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1692, 0X42D4) << 16);
    // 0x808000CC: addiu       $t8, $t8, 0x42D4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1692, 0X42D4));
    // 0x808000D0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x808000D4: b           L_8080012C
    // 0x808000D8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8080012C;
    // 0x808000D8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_808000DC:
    // 0x808000DC: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1692, 0X4324) << 16);
    // 0x808000E0: addiu       $t9, $t9, 0x4324
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1692, 0X4324));
    // 0x808000E4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x808000E8: b           L_8080012C
    // 0x808000EC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_8080012C;
    // 0x808000EC: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_808000F0:
    // 0x808000F0: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1692, 0X43BC) << 16);
    // 0x808000F4: addiu       $t0, $t0, 0x43BC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1692, 0X43BC));
    // 0x808000F8: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x808000FC: b           L_8080012C
    // 0x80800100: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_8080012C;
    // 0x80800100: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_80800104:
    // 0x80800104: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1692, 0X4474) << 16);
    // 0x80800108: addiu       $t1, $t1, 0x4474
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1692, 0X4474));
    // 0x8080010C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80800110: b           L_8080012C
    // 0x80800114: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_8080012C;
    // 0x80800114: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80800118:
    // 0x80800118: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1692, 0X4514) << 16);
    // 0x8080011C: addiu       $t2, $t2, 0x4514
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1692, 0X4514));
    // 0x80800120: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80800124: b           L_8080012C
    // 0x80800128: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_8080012C;
    // 0x80800128: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_8080012C:
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void func_80100C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100C74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80100C78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80100C7C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80100C80: addiu       $s1, $s1, 0x5A60
    ctx->r17 = ADD32(ctx->r17, 0X5A60);
    // 0x80100C84: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80100C88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80100C8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100C90: beq         $a0, $zero, L_80100D10
    if (ctx->r4 == 0) {
        // 0x80100C94: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_80100D10;
    }
    // 0x80100C94: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80100C98: jal         0x800B3034
    // 0x80100C9C: nop

    freelist_capacity(rdram, ctx);
        goto after_0;
    // 0x80100C9C: nop

    after_0:
    // 0x80100CA0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80100CA4: bnel        $at, $zero, L_80100D14
    if (ctx->r1 != 0) {
        // 0x80100CA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80100D14;
    }
    goto skip_0;
    // 0x80100CA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80100CAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80100CB0:
    // 0x80100CB0: jal         0x800B31B8
    // 0x80100CB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_1;
    // 0x80100CB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80100CB8: beq         $v0, $zero, L_80100CEC
    if (ctx->r2 == 0) {
        // 0x80100CBC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80100CEC;
    }
    // 0x80100CBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80100CC0: jal         0x800B301C
    // 0x80100CC4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    freelist_at(rdram, ctx);
        goto after_2;
    // 0x80100CC4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x80100CC8: lbu         $v1, 0xA($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XA);
    // 0x80100CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100CD0: beq         $v1, $zero, L_80100CEC
    if (ctx->r3 == 0) {
        // 0x80100CD4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80100CEC;
    }
    // 0x80100CD4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80100CD8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80100CDC: bne         $t7, $zero, L_80100CEC
    if (ctx->r15 != 0) {
        // 0x80100CE0: sb          $t6, 0xA($v0)
        MEM_B(0XA, ctx->r2) = ctx->r14;
            goto L_80100CEC;
    }
    // 0x80100CE0: sb          $t6, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r14;
    // 0x80100CE4: jal         0x801009C4
    // 0x80100CE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_801009C4(rdram, ctx);
        goto after_3;
    // 0x80100CE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
L_80100CEC:
    // 0x80100CEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80100CF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80100CF4: beql        $a0, $zero, L_80100D14
    if (ctx->r4 == 0) {
        // 0x80100CF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80100D14;
    }
    goto skip_1;
    // 0x80100CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80100CFC: jal         0x800B3034
    // 0x80100D00: nop

    freelist_capacity(rdram, ctx);
        goto after_4;
    // 0x80100D00: nop

    after_4:
    // 0x80100D04: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80100D08: bnel        $at, $zero, L_80100CB0
    if (ctx->r1 != 0) {
        // 0x80100D0C: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80100CB0;
    }
    goto skip_2;
    // 0x80100D0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_2:
L_80100D10:
    // 0x80100D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80100D14:
    // 0x80100D14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80100D18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80100D1C: jr          $ra
    // 0x80100D20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80100D20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800220_chboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80800224: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800228: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080022C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800234: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800238: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080023C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800240: jal         0x80089F18
    // 0x80800244: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800244: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_0:
    // 0x80800248: jal         0x80800554
    // 0x8080024C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800554_chboggy(rdram, ctx);
        goto after_1;
    // 0x8080024C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800250: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800254: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080025C: lhu         $v0, 0x72($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X72);
    // 0x80800260: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6A0) << 16);
    // 0x80800264: addiu       $a2, $a2, 0x6A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6A0));
    // 0x80800268: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x8080026C: beq         $t7, $at, L_80800294
    if (ctx->r15 == ctx->r1) {
        // 0x80800270: addiu       $a1, $a0, 0x28
        ctx->r5 = ADD32(ctx->r4, 0X28);
            goto L_80800294;
    }
    // 0x80800270: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    // 0x80800274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800278: beq         $t7, $at, L_808003E4
    if (ctx->r15 == ctx->r1) {
        // 0x8080027C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003E4;
    }
    // 0x8080027C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800280: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800284: beq         $t7, $at, L_8080049C
    if (ctx->r15 == ctx->r1) {
        // 0x80800288: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080049C;
    }
    // 0x80800288: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: b           L_808004F8
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004F8;
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800294:
    // 0x80800294: lui         $a3, 0x3E04
    ctx->r7 = S32(0X3E04 << 16);
    // 0x80800298: jal         0x80089D20
    // 0x8080029C: ori         $a3, $a3, 0xEA4B
    ctx->r7 = ctx->r7 | 0XEA4B;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080029C: ori         $a3, $a3, 0xEA4B
    ctx->r7 = ctx->r7 | 0XEA4B;
    after_2:
    // 0x808002A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X704) << 16);
    // 0x808002A8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2072, 0X740) << 16);
    // 0x808002AC: addiu       $a3, $a3, 0x740
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2072, 0X740));
    // 0x808002B0: addiu       $a2, $a2, 0x704
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X704));
    // 0x808002B4: jal         0x80089D28
    // 0x808002B8: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808002B8: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x808002BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X710) << 16);
    // 0x808002C4: lui         $a3, 0x3ED7
    ctx->r7 = S32(0X3ED7 << 16);
    // 0x808002C8: ori         $a3, $a3, 0xA3D
    ctx->r7 = ctx->r7 | 0XA3D;
    // 0x808002CC: addiu       $a2, $a2, 0x710
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X710));
    // 0x808002D0: jal         0x80089D20
    // 0x808002D4: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808002D4: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_4:
    // 0x808002D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6F8) << 16);
    // 0x808002E0: lui         $a3, 0x3F14
    ctx->r7 = S32(0X3F14 << 16);
    // 0x808002E4: ori         $a3, $a3, 0x7AE1
    ctx->r7 = ctx->r7 | 0X7AE1;
    // 0x808002E8: addiu       $a2, $a2, 0x6F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6F8));
    // 0x808002EC: jal         0x80089D20
    // 0x808002F0: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808002F0: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x808002F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6C8) << 16);
    // 0x808002FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2072, 0X74C) << 16);
    // 0x80800300: addiu       $a3, $a3, 0x74C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2072, 0X74C));
    // 0x80800304: addiu       $a2, $a2, 0x6C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6C8));
    // 0x80800308: jal         0x80089D28
    // 0x8080030C: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x8080030C: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x80800310: jal         0x800DA298
    // 0x80800314: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800314: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    after_7:
    // 0x80800318: beq         $v0, $zero, L_808003A0
    if (ctx->r2 == 0) {
        // 0x8080031C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003A0;
    }
    // 0x8080031C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800320: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800324: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80800328: addiu       $a2, $zero, 0x4D7
    ctx->r6 = ADD32(0, 0X4D7);
    // 0x8080032C: jal         0x800902E4
    // 0x80800330: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_800902E4(rdram, ctx);
        goto after_8;
    // 0x80800330: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_8:
    // 0x80800334: jal         0x800F54E4
    // 0x80800338: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800338: nop

    after_9:
    // 0x8080033C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800340: jal         0x800F640C
    // 0x80800344: addiu       $a1, $zero, 0x4D7
    ctx->r5 = ADD32(0, 0X4D7);
    func_800F640C(rdram, ctx);
        goto after_10;
    // 0x80800344: addiu       $a1, $zero, 0x4D7
    ctx->r5 = ADD32(0, 0X4D7);
    after_10:
    // 0x80800348: bne         $v0, $zero, L_80800364
    if (ctx->r2 != 0) {
        // 0x8080034C: nop
    
            goto L_80800364;
    }
    // 0x8080034C: nop

    // 0x80800350: jal         0x8008FE14
    // 0x80800354: nop

    func_8008FE14(rdram, ctx);
        goto after_11;
    // 0x80800354: nop

    after_11:
    // 0x80800358: addiu       $at, $zero, 0x4D7
    ctx->r1 = ADD32(0, 0X4D7);
    // 0x8080035C: bne         $v0, $at, L_808003A0
    if (ctx->r2 != ctx->r1) {
        // 0x80800360: nop
    
            goto L_808003A0;
    }
    // 0x80800360: nop

L_80800364:
    // 0x80800364: jal         0x80090818
    // 0x80800368: nop

    func_80090818(rdram, ctx);
        goto after_12;
    // 0x80800368: nop

    after_12:
    // 0x8080036C: beq         $v0, $zero, L_808003A0
    if (ctx->r2 == 0) {
        // 0x80800370: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003A0;
    }
    // 0x80800370: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800374: jal         0x80090768
    // 0x80800378: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_80090768(rdram, ctx);
        goto after_13;
    // 0x80800378: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_13:
    // 0x8080037C: jal         0x800D1824
    // 0x80800380: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    func_800D1824(rdram, ctx);
        goto after_14;
    // 0x80800380: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_14:
    // 0x80800384: jal         0x800F54E4
    // 0x80800388: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x80800388: nop

    after_15:
    // 0x8080038C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800390: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800394: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800398: jal         0x800F8300
    // 0x8080039C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800F8300(rdram, ctx);
        goto after_16;
    // 0x8080039C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_16:
L_808003A0:
    // 0x808003A0: jal         0x800DA298
    // 0x808003A4: addiu       $a0, $zero, 0x439
    ctx->r4 = ADD32(0, 0X439);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x808003A4: addiu       $a0, $zero, 0x439
    ctx->r4 = ADD32(0, 0X439);
    after_17:
    // 0x808003A8: beql        $v0, $zero, L_808003BC
    if (ctx->r2 == 0) {
        // 0x808003AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003BC;
    }
    goto skip_0;
    // 0x808003AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808003B0: jal         0x800DA544
    // 0x808003B4: addiu       $a0, $zero, 0x437
    ctx->r4 = ADD32(0, 0X437);
    func_800DA544(rdram, ctx);
        goto after_18;
    // 0x808003B4: addiu       $a0, $zero, 0x437
    ctx->r4 = ADD32(0, 0X437);
    after_18:
    // 0x808003B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808003BC:
    // 0x808003BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X800) << 16);
    // 0x808003C0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2072, 0X790) << 16);
    // 0x808003C4: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x808003C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808003CC: addiu       $a3, $a3, 0x790
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2072, 0X790));
    // 0x808003D0: addiu       $a2, $a2, 0x800
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X800));
    // 0x808003D4: jal         0x8008A1F0
    // 0x808003D8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_19;
    // 0x808003D8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_19:
    // 0x808003DC: b           L_808004F8
    // 0x808003E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004F8;
    // 0x808003E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003E4:
    // 0x808003E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6B0) << 16);
    // 0x808003E8: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x808003EC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003F0: addiu       $a2, $a2, 0x6B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6B0));
    // 0x808003F4: jal         0x80089D20
    // 0x808003F8: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x808003F8: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_20:
    // 0x808003FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6E8) << 16);
    // 0x80800404: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2072, 0X760) << 16);
    // 0x80800408: addiu       $a3, $a3, 0x760
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2072, 0X760));
    // 0x8080040C: addiu       $a2, $a2, 0x6E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6E8));
    // 0x80800410: jal         0x80089D28
    // 0x80800414: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800414: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_21:
    // 0x80800418: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080041C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6B8) << 16);
    // 0x80800420: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2072, 0X730) << 16);
    // 0x80800424: addiu       $a3, $a3, 0x730
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2072, 0X730));
    // 0x80800428: addiu       $a2, $a2, 0x6B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6B8));
    // 0x8080042C: jal         0x80089D28
    // 0x80800430: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x80800430: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_22:
    // 0x80800434: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800438: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080043C: jal         0x80101E14
    // 0x80800440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80800440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_23:
    // 0x80800444: beq         $v0, $zero, L_80800474
    if (ctx->r2 == 0) {
        // 0x80800448: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_80800474;
    }
    // 0x80800448: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8080044C: jal         0x800D0B68
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_24;
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80800454: bne         $v0, $zero, L_80800474
    if (ctx->r2 != 0) {
        // 0x80800458: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_80800474;
    }
    // 0x80800458: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8080045C: jal         0x800D0A9C
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_25;
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80800464: bne         $v0, $zero, L_80800474
    if (ctx->r2 != 0) {
        // 0x80800468: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800474;
    }
    // 0x80800468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: jal         0x80108B04
    // 0x80800470: addiu       $a1, $zero, 0x22B
    ctx->r5 = ADD32(0, 0X22B);
    func_80108B04(rdram, ctx);
        goto after_26;
    // 0x80800470: addiu       $a1, $zero, 0x22B
    ctx->r5 = ADD32(0, 0X22B);
    after_26:
L_80800474:
    // 0x80800474: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80800478: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x8080047C: jal         0x80101E14
    // 0x80800480: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x80800480: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_27:
    // 0x80800484: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x80800488: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808004F4;
    }
    // 0x80800488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080048C: jal         0x80101FDC
    // 0x80800490: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_28;
    // 0x80800490: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_28:
    // 0x80800494: b           L_808004F8
    // 0x80800498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004F8;
    // 0x80800498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080049C:
    // 0x8080049C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6D8) << 16);
    // 0x808004A0: lui         $a3, 0x3E61
    ctx->r7 = S32(0X3E61 << 16);
    // 0x808004A4: ori         $a3, $a3, 0x47AE
    ctx->r7 = ctx->r7 | 0X47AE;
    // 0x808004A8: addiu       $a2, $a2, 0x6D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6D8));
    // 0x808004AC: jal         0x80089D20
    // 0x808004B0: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x808004B0: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_29:
    // 0x808004B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X6B8) << 16);
    // 0x808004BC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2072, 0X720) << 16);
    // 0x808004C0: addiu       $a3, $a3, 0x720
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2072, 0X720));
    // 0x808004C4: addiu       $a2, $a2, 0x6B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X6B8));
    // 0x808004C8: jal         0x80089D28
    // 0x808004CC: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x808004CC: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_30:
    // 0x808004D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X810) << 16);
    // 0x808004D8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2072, 0X7C8) << 16);
    // 0x808004DC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x808004E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808004E4: addiu       $a3, $a3, 0x7C8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2072, 0X7C8));
    // 0x808004E8: addiu       $a2, $a2, 0x810
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X810));
    // 0x808004EC: jal         0x8008A1F0
    // 0x808004F0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_31;
    // 0x808004F0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_31:
L_808004F4:
    // 0x808004F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004F8:
    // 0x808004F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004FC: jr          $ra
    // 0x80800500: nop

    return;
    // 0x80800500: nop

;}
RECOMP_FUNC void func_800C0638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0638: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C063C: lh          $v0, -0x75EE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X75EE);
    // 0x800C0640: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800C0644: jr          $ra
    // 0x800C0648: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
    return;
    // 0x800C0648: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
;}
RECOMP_FUNC void func_80800104_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800108: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800110: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80800114: ori         $t9, $a2, 0x6
    ctx->r25 = ctx->r6 | 0X6;
    // 0x80800118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080011C: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80800120: bltz        $t8, L_80800148
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800124: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_80800148;
    }
    // 0x80800124: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80800128: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080012C: addiu       $t0, $zero, 0x6F
    ctx->r8 = ADD32(0, 0X6F);
    // 0x80800130: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800134: jal         0x8008A208
    // 0x80800138: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800138: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x8080013C: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x80800140: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x80800144: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
L_80800148:
    // 0x80800148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800150: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_800D3A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3A28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3A2C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800D3A30: addiu       $a1, $a1, -0x5ABC
    ctx->r5 = ADD32(ctx->r5, -0X5ABC);
    // 0x800D3A34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D3A38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D3A3C: jal         0x800D3B6C
    // 0x800D3A40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800D3B6C(rdram, ctx);
        goto after_0;
    // 0x800D3A40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800D3A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3A48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3A4C: jr          $ra
    // 0x800D3A50: nop

    return;
    // 0x800D3A50: nop

;}
RECOMP_FUNC void func_80800040_chdingpot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080004C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800058: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080005C: beq         $t6, $at, L_80800090
    if (ctx->r14 == ctx->r1) {
        // 0x80800060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800090;
    }
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800068: beq         $t6, $at, L_808000BC
    if (ctx->r14 == ctx->r1) {
        // 0x8080006C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000BC;
    }
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800074: beq         $t6, $at, L_808000D0
    if (ctx->r14 == ctx->r1) {
        // 0x80800078: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800080: beq         $t6, $at, L_808000FC
    if (ctx->r14 == ctx->r1) {
        // 0x80800084: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000FC;
    }
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: b           L_8080020C
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080020C;
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800090:
    // 0x80800090: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1176, 0X548) << 16);
    // 0x80800094: jal         0x808002B4
    // 0x80800098: addiu       $a1, $a1, 0x548
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1176, 0X548));
    func_808002B4_chdingpot(rdram, ctx);
        goto after_0;
    // 0x80800098: addiu       $a1, $a1, 0x548
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1176, 0X548));
    after_0:
    // 0x8080009C: jal         0x80800350
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800350_chdingpot(rdram, ctx);
        goto after_1;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000A4: bnel        $v0, $zero, L_8080020C
    if (ctx->r2 != 0) {
        // 0x808000A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080020C;
    }
    goto skip_0;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000AC: jal         0x80800388
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800388_chdingpot(rdram, ctx);
        goto after_2;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000B4: b           L_8080020C
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080020C;
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000BC:
    // 0x808000BC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1176, 0X548) << 16);
    // 0x808000C0: jal         0x808002B4
    // 0x808000C4: addiu       $a1, $a1, 0x548
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1176, 0X548));
    func_808002B4_chdingpot(rdram, ctx);
        goto after_3;
    // 0x808000C4: addiu       $a1, $a1, 0x548
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1176, 0X548));
    after_3:
    // 0x808000C8: b           L_8080020C
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080020C;
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000D0:
    // 0x808000D0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1176, 0X568) << 16);
    // 0x808000D4: jal         0x808002B4
    // 0x808000D8: addiu       $a1, $a1, 0x568
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1176, 0X568));
    func_808002B4_chdingpot(rdram, ctx);
        goto after_4;
    // 0x808000D8: addiu       $a1, $a1, 0x568
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1176, 0X568));
    after_4:
    // 0x808000DC: jal         0x80101DDC
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000E4: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800208;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x80102424
    // 0x808000F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808000F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808000F4: b           L_8080020C
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080020C;
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000FC:
    // 0x808000FC: lui         $a1, 0x3F18
    ctx->r5 = S32(0X3F18 << 16);
    // 0x80800100: jal         0x80101E14
    // 0x80800104: ori         $a1, $a1, 0x9375
    ctx->r5 = ctx->r5 | 0X9375;
    func_80101E14(rdram, ctx);
        goto after_7;
    // 0x80800104: ori         $a1, $a1, 0x9375
    ctx->r5 = ctx->r5 | 0X9375;
    after_7:
    // 0x80800108: beq         $v0, $zero, L_80800118
    if (ctx->r2 == 0) {
        // 0x8080010C: lui         $a0, 0x6CBF
        ctx->r4 = S32(0X6CBF << 16);
            goto L_80800118;
    }
    // 0x8080010C: lui         $a0, 0x6CBF
    ctx->r4 = S32(0X6CBF << 16);
    // 0x80800110: jal         0x800C3F48
    // 0x80800114: ori         $a0, $a0, 0x441E
    ctx->r4 = ctx->r4 | 0X441E;
    func_800C3F48(rdram, ctx);
        goto after_8;
    // 0x80800114: ori         $a0, $a0, 0x441E
    ctx->r4 = ctx->r4 | 0X441E;
    after_8:
L_80800118:
    // 0x80800118: lui         $a1, 0x3F21
    ctx->r5 = S32(0X3F21 << 16);
    // 0x8080011C: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x80800120: jal         0x80101E14
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_9;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800128: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x8080012C: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_808001E4;
    }
    // 0x8080012C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800130: jal         0x800EE7F8
    // 0x80800134: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800134: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80800138: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080013C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800140: jal         0x800EF1B8
    // 0x80800144: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_11;
    // 0x80800144: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_11:
    // 0x80800148: jal         0x800F54E4
    // 0x8080014C: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x8080014C: nop

    after_12:
    // 0x80800150: jal         0x800F4CC0
    // 0x80800154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_13;
    // 0x80800154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80800158: jal         0x800F54E4
    // 0x8080015C: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x8080015C: nop

    after_14:
    // 0x80800160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800164: jal         0x800F82D4
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_15;
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8080016C: jal         0x800F54E4
    // 0x80800170: nop

    func_800F54E4(rdram, ctx);
        goto after_16;
    // 0x80800170: nop

    after_16:
    // 0x80800174: lui         $a2, 0x44CA
    ctx->r6 = S32(0X44CA << 16);
    // 0x80800178: lui         $a3, 0xC580
    ctx->r7 = S32(0XC580 << 16);
    // 0x8080017C: ori         $a3, $a3, 0x2000
    ctx->r7 = ctx->r7 | 0X2000;
    // 0x80800180: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800188: jal         0x800F7844
    // 0x8080018C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F7844(rdram, ctx);
        goto after_17;
    // 0x8080018C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_17:
    // 0x80800190: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80800194: jal         0x800D175C
    // 0x80800198: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    func_800D175C(rdram, ctx);
        goto after_18;
    // 0x80800198: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    after_18:
    // 0x8080019C: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x808001A0: jal         0x800D175C
    // 0x808001A4: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    func_800D175C(rdram, ctx);
        goto after_19;
    // 0x808001A4: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    after_19:
    // 0x808001A8: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x808001AC: jal         0x800D175C
    // 0x808001B0: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    func_800D175C(rdram, ctx);
        goto after_20;
    // 0x808001B0: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    after_20:
    // 0x808001B4: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x808001B8: jal         0x800D175C
    // 0x808001BC: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    func_800D175C(rdram, ctx);
        goto after_21;
    // 0x808001BC: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    after_21:
    // 0x808001C0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x808001C4: jal         0x800D175C
    // 0x808001C8: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    func_800D175C(rdram, ctx);
        goto after_22;
    // 0x808001C8: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    after_22:
    // 0x808001CC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x808001D0: jal         0x800D175C
    // 0x808001D4: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    func_800D175C(rdram, ctx);
        goto after_23;
    // 0x808001D4: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    after_23:
    // 0x808001D8: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x808001DC: jal         0x800D175C
    // 0x808001E0: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    func_800D175C(rdram, ctx);
        goto after_24;
    // 0x808001E0: addiu       $a1, $zero, 0x270F
    ctx->r5 = ADD32(0, 0X270F);
    after_24:
L_808001E4:
    // 0x808001E4: jal         0x80101DDC
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_25;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808001EC: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x808001F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800208;
    }
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x80102424
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x808001F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: jal         0x8008A4B0
    // 0x80800204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80800204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
L_80800208:
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080020C:
    // 0x8080020C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800210: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void func_80800000_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800850F0
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _basnowball_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080001C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800020: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800024: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    // 0x80800028: jal         0x800F10B4
    // 0x8080002C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x8080002C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800030: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800034: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800038: jal         0x800F13C4
    // 0x8080003C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x8080003C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80800040: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800044: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800048: jal         0x8008C990
    // 0x8080004C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008C990(rdram, ctx);
        goto after_3;
    // 0x8080004C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800054: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void bskazmove_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800904: jal         0x8009BF5C
    // 0x80800908: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x80800908: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8080090C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800910: jal         0x8009C4CC
    // 0x80800914: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_1;
    // 0x80800914: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800918: jal         0x800832E8
    // 0x8080091C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080091C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800928: jr          $ra
    // 0x8080092C: nop

    return;
    // 0x8080092C: nop

;}
RECOMP_FUNC void func_800D07CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D07CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D07D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D07D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D07D8: bne         $a1, $at, L_800D0810
    if (ctx->r5 != ctx->r1) {
        // 0x800D07DC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800D0810;
    }
    // 0x800D07DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D07E0: jal         0x800CFC5C
    // 0x800D07E4: nop

    func_800CFC5C(rdram, ctx);
        goto after_0;
    // 0x800D07E4: nop

    after_0:
    // 0x800D07E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D07EC: beq         $v0, $at, L_800D0810
    if (ctx->r2 == ctx->r1) {
        // 0x800D07F0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800D0810;
    }
    // 0x800D07F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D07F4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D07F8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800D07FC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D0800: addiu       $t7, $t7, -0x4E80
    ctx->r15 = ADD32(ctx->r15, -0X4E80);
    // 0x800D0804: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D0808: jal         0x800EE7F8
    // 0x800D080C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800D080C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
L_800D0810:
    // 0x800D0810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0818: jr          $ra
    // 0x800D081C: nop

    return;
    // 0x800D081C: nop

;}
RECOMP_FUNC void func_8080011C_gcgoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800120: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800124: lbu         $t6, 0x75C0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X75C0);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800130: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800134: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800138: bne         $t6, $zero, L_80800188
    if (ctx->r14 != 0) {
        // 0x8080013C: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80800188;
    }
    // 0x8080013C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800140: addiu       $at, $zero, 0xCE
    ctx->r1 = ADD32(0, 0XCE);
    // 0x80800144: bne         $a0, $at, L_8080015C
    if (ctx->r4 != ctx->r1) {
        // 0x80800148: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080015C;
    }
    // 0x80800148: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080014C: bnel        $a1, $at, L_80800160
    if (ctx->r5 != ctx->r1) {
        // 0x80800150: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80800160;
    }
    goto skip_0;
    // 0x80800150: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    skip_0:
    // 0x80800154: jal         0x800DA544
    // 0x80800158: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800158: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    after_0:
L_8080015C:
    // 0x8080015C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_80800160:
    // 0x80800160: jal         0x80800048
    // 0x80800164: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    gcgoto_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800164: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080016C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800170: jal         0x800A7990
    // 0x80800174: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800A7990(rdram, ctx);
        goto after_2;
    // 0x80800174: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800178: jal         0x800EA334
    // 0x8080017C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EA334(rdram, ctx);
        goto after_3;
    // 0x8080017C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800180: jal         0x808006F8
    // 0x80800184: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcgoto_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80800184: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
L_80800188:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_800F9104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9104: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9108: jr          $ra
    // 0x800F910C: sb          $a0, 0x54FC($at)
    MEM_B(0X54FC, ctx->r1) = ctx->r4;
    return;
    // 0x800F910C: sb          $a0, 0x54FC($at)
    MEM_B(0X54FC, ctx->r1) = ctx->r4;
;}
