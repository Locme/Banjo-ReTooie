#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800000_cothemedll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2508, 0XD34) << 16);
    // 0x80800004: lh          $t6, 0xD34($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2508, 0XD34));
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080001C: beq         $t6, $zero, L_80800060
    if (ctx->r14 == 0) {
        // 0x80800020: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800060;
    }
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800024: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2508, 0XD34) << 16);
    // 0x80800028: addiu       $s0, $t7, 0xD34
    ctx->r16 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2508, 0XD34));
    // 0x8080002C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_80800030:
    // 0x80800030: bnel        $s1, $v0, L_80800050
    if (ctx->r17 != ctx->r2) {
        // 0x80800034: lh          $v0, 0x6($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X6);
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800034: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    skip_0:
    // 0x80800038: jal         0x800DA298
    // 0x8080003C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080003C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_0:
    // 0x80800040: beql        $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x80800044: lh          $v0, 0x6($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X6);
            goto L_80800050;
    }
    goto skip_1;
    // 0x80800044: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    skip_1:
    // 0x80800048: lh          $s1, 0x2($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X2);
    // 0x8080004C: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
L_80800050:
    // 0x80800050: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80800054: bne         $v0, $zero, L_80800030
    if (ctx->r2 != 0) {
        // 0x80800058: nop
    
            goto L_80800030;
    }
    // 0x80800058: nop

    // 0x8080005C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800060:
    // 0x80800060: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2508, 0X730) << 16);
    // 0x80800064: lh          $t8, 0x730($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(2508, 0X730));
    // 0x80800068: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2508, 0X730) << 16);
    // 0x8080006C: addiu       $v0, $t9, 0x730
    ctx->r2 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2508, 0X730));
    // 0x80800070: beq         $t8, $zero, L_808000A0
    if (ctx->r24 == 0) {
        // 0x80800074: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A0;
    }
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800078: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_8080007C:
    // 0x8080007C: bnel        $s1, $v1, L_80800090
    if (ctx->r17 != ctx->r3) {
        // 0x80800080: lh          $v1, 0x6($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X6);
            goto L_80800090;
    }
    goto skip_2;
    // 0x80800080: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    skip_2:
    // 0x80800084: b           L_808000A4
    // 0x80800088: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_808000A4;
    // 0x80800088: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8080008C: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
L_80800090:
    // 0x80800090: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800094: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80800098: bne         $v1, $zero, L_8080007C
    if (ctx->r3 != 0) {
        // 0x8080009C: nop
    
            goto L_8080007C;
    }
    // 0x8080009C: nop

L_808000A0:
    // 0x808000A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000A4:
    // 0x808000A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80012134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001213C: jal         0x80087890
    // 0x80012140: nop

    _cosection_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80012140: nop

    after_0:
    // 0x80012144: jal         0x8001253C
    // 0x80012148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8001253C(rdram, ctx);
        goto after_1;
    // 0x80012148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8001214C: jal         0x80012520
    // 0x80012150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80012520(rdram, ctx);
        goto after_2;
    // 0x80012150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80012154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001215C: jr          $ra
    // 0x80012160: nop

    return;
    // 0x80012160: nop

;}
RECOMP_FUNC void func_8002A6A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A6A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002A6A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A6AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002A6B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002A6B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002A6B8: lw          $t7, 0x50($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X50);
    // 0x8002A6BC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8002A6C0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002A6C4: beq         $t8, $zero, L_8002A7C8
    if (ctx->r24 == 0) {
        // 0x8002A6C8: nop
    
            goto L_8002A7C8;
    }
    // 0x8002A6C8: nop

L_8002A6CC:
    // 0x8002A6CC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002A6D0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8002A6D4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8002A6D8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002A6DC: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x8002A6E0: sh          $t2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r10;
    // 0x8002A6E4: lh          $t3, 0x1E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X1E);
    // 0x8002A6E8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002A6EC: beq         $t3, $at, L_8002A700
    if (ctx->r11 == ctx->r1) {
        // 0x8002A6F0: nop
    
            goto L_8002A700;
    }
    // 0x8002A6F0: nop

    // 0x8002A6F4: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8002A6F8: bne         $t3, $at, L_8002A7B4
    if (ctx->r11 != ctx->r1) {
        // 0x8002A6FC: nop
    
            goto L_8002A7B4;
    }
    // 0x8002A6FC: nop

L_8002A700:
    // 0x8002A700: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8002A704: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A708: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8002A70C: bne         $t5, $t6, L_8002A7B4
    if (ctx->r13 != ctx->r14) {
        // 0x8002A710: nop
    
            goto L_8002A7B4;
    }
    // 0x8002A710: nop

    // 0x8002A714: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002A718: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002A71C: lw          $t9, 0x78($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X78);
    // 0x8002A720: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x8002A724: jalr        $t9
    // 0x8002A728: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002A728: nop

    after_0:
    // 0x8002A72C: jal         0x80020E74
    // 0x8002A730: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x8002A730: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8002A734: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002A738: beq         $t0, $zero, L_8002A758
    if (ctx->r8 == 0) {
        // 0x8002A73C: nop
    
            goto L_8002A758;
    }
    // 0x8002A73C: nop

    // 0x8002A740: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002A744: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002A748: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8002A74C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8002A750: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8002A754: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
L_8002A758:
    // 0x8002A758: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8002A75C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002A760: jal         0x80020E40
    // 0x8002A764: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    func_80020E40(rdram, ctx);
        goto after_2;
    // 0x8002A764: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_2:
    // 0x8002A768: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8002A76C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002A770: bne         $t6, $at, L_8002A78C
    if (ctx->r14 != ctx->r1) {
        // 0x8002A774: nop
    
            goto L_8002A78C;
    }
    // 0x8002A774: nop

    // 0x8002A778: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A77C: lbu         $t8, 0x3B($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3B);
    // 0x8002A780: andi        $t9, $t8, 0xFE
    ctx->r25 = ctx->r24 & 0XFE;
    // 0x8002A784: b           L_8002A79C
    // 0x8002A788: sb          $t9, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r25;
        goto L_8002A79C;
    // 0x8002A788: sb          $t9, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r25;
L_8002A78C:
    // 0x8002A78C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A790: lbu         $t3, 0x3B($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X3B);
    // 0x8002A794: andi        $t2, $t3, 0xFD
    ctx->r10 = ctx->r11 & 0XFD;
    // 0x8002A798: sb          $t2, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = ctx->r10;
L_8002A79C:
    // 0x8002A79C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A7A0: lbu         $t5, 0x3B($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X3B);
    // 0x8002A7A4: bne         $t5, $zero, L_8002A7B4
    if (ctx->r13 != 0) {
        // 0x8002A7A8: nop
    
            goto L_8002A7B4;
    }
    // 0x8002A7A8: nop

    // 0x8002A7AC: b           L_8002A7D0
    // 0x8002A7B0: nop

        goto L_8002A7D0;
    // 0x8002A7B0: nop

L_8002A7B4:
    // 0x8002A7B4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002A7B8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8002A7BC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002A7C0: bne         $t6, $zero, L_8002A6CC
    if (ctx->r14 != 0) {
        // 0x8002A7C4: nop
    
            goto L_8002A6CC;
    }
    // 0x8002A7C4: nop

L_8002A7C8:
    // 0x8002A7C8: b           L_8002A7D0
    // 0x8002A7CC: nop

        goto L_8002A7D0;
    // 0x8002A7CC: nop

L_8002A7D0:
    // 0x8002A7D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A7D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002A7D8: jr          $ra
    // 0x8002A7DC: nop

    return;
    // 0x8002A7DC: nop

;}
RECOMP_FUNC void func_800B237C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B237C: lh          $t6, 0xC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC);
    // 0x800B2380: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B2384: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B2388: nop

    // 0x800B238C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2390: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800B2394: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800B2398: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B239C: nop

    // 0x800B23A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B23A4: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800B23A8: lh          $t8, 0x10($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X10);
    // 0x800B23AC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B23B0: nop

    // 0x800B23B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B23B8: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    // 0x800B23BC: lhu         $t9, 0x12($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X12);
    // 0x800B23C0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800B23C4: bgez        $t9, L_800B23D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B23C8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B23D8;
    }
    // 0x800B23C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B23CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B23D0: nop

    // 0x800B23D4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B23D8:
    // 0x800B23D8: jr          $ra
    // 0x800B23DC: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x800B23DC: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void gcfrontend_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080000C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800010: jal         0x800D3970
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D3970(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800018: jal         0x808001A4
    // 0x8080001C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    gcfrontend_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080001C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80800020: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800024: jal         0x80800188
    // 0x80800028: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    gcfrontend_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800028: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8080002C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800030: blez        $v0, L_80800054
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800034: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800054;
    }
    // 0x80800034: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800038: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
L_8080003C:
    // 0x8080003C: jal         0x8080034C
    // 0x80800040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcfrontend_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800048: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8080004C: bne         $at, $zero, L_8080003C
    if (ctx->r1 != 0) {
        // 0x80800050: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080003C;
    }
    // 0x80800050: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800054:
    // 0x80800054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800060: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800064: jr          $ra
    // 0x80800068: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800068: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808011F4_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011FC: jal         0x8080102C
    // 0x80801200: nop

    func_8080102C_chbanjoctrl(rdram, ctx);
        goto after_0;
    // 0x80801200: nop

    after_0:
    // 0x80801204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080120C: jr          $ra
    // 0x80801210: nop

    return;
    // 0x80801210: nop

    // 0x80801214: nop

    // 0x80801218: nop

    // 0x8080121C: nop

;}
RECOMP_FUNC void idflame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: jr          $ra
    // 0x808001D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808001D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808038F8_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_808038F8_chweldarboss");
    // 0x808038F8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x808038FC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80803900: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80803904: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80803908: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x8080390C: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80803910: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80803914: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80803918: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8080391C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80803920: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80803924: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80803928: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8080392C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80803930: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80803934: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80803938: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080393C: jal         0x80100094
    // 0x80803940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803944: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80803948: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8080394C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80803950: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80803954: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X455C) << 16);
    // 0x80803958: lwc1        $f26, 0x455C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X455C));
    // 0x8080395C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80803960: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80803964: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80803968: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080396C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80803970: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80803974: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80803978: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080397C: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x80803980: addiu       $s3, $sp, 0x6C
    ctx->r19 = ADD32(ctx->r29, 0X6C);
    // 0x80803984: addiu       $s2, $zero, 0x320
    ctx->r18 = ADD32(0, 0X320);
    // 0x80803988: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
L_8080398C:
    // 0x8080398C: jal         0x800F6438
    // 0x80803990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80803990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80803994: beql        $v0, $zero, L_80803AF8
    if (ctx->r2 == 0) {
        // 0x80803998: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80803AF8;
    }
    goto skip_0;
    // 0x80803998: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8080399C: jal         0x80803B48
    // 0x808039A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803B48_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x808039A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808039A4: beql        $v0, $zero, L_80803AF8
    if (ctx->r2 == 0) {
        // 0x808039A8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80803AF8;
    }
    goto skip_1;
    // 0x808039A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x808039AC: jal         0x800F6AA4
    // 0x808039B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6AA4(rdram, ctx);
        goto after_3;
    // 0x808039B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808039B4: bne         $v0, $zero, L_80803AF4
    if (ctx->r2 != 0) {
        // 0x808039B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803AF4;
    }
    // 0x808039B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039BC: jal         0x800F5A00
    // 0x808039C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x808039C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808039C4: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x808039C8: lwc1        $f14, 0x98($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X98);
    // 0x808039CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039D0: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x808039D4: nop

    // 0x808039D8: bc1fl       L_808039F8
    if (!c1cs) {
        // 0x808039DC: div.s       $f8, $f12, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f20.fl);
            goto L_808039F8;
    }
    goto skip_2;
    // 0x808039DC: div.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f20.fl);
    skip_2:
    // 0x808039E0: div.s       $f4, $f12, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f20.fl);
    // 0x808039E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808039E8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x808039EC: b           L_80803A0C
    // 0x808039F0: c.lt.s      $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f22.fl < ctx->f14.fl;
        goto L_80803A0C;
    // 0x808039F0: c.lt.s      $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f22.fl < ctx->f14.fl;
    // 0x808039F4: div.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f20.fl);
L_808039F8:
    // 0x808039F8: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x808039FC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80803A00: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80803A04: nop

    // 0x80803A08: c.lt.s      $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f22.fl < ctx->f14.fl;
L_80803A0C:
    // 0x80803A0C: nop

    // 0x80803A10: bc1fl       L_80803A30
    if (!c1cs) {
        // 0x80803A14: div.s       $f6, $f14, $f20
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f20.fl);
            goto L_80803A30;
    }
    goto skip_3;
    // 0x80803A14: div.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f20.fl);
    skip_3:
    // 0x80803A18: div.s       $f18, $f14, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80803A1C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80803A20: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80803A24: b           L_80803A44
    // 0x80803A28: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
        goto L_80803A44;
    // 0x80803A28: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80803A2C: div.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f20.fl);
L_80803A30:
    // 0x80803A30: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x80803A34: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80803A38: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80803A3C: nop

    // 0x80803A40: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
L_80803A44:
    // 0x80803A44: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80803A48: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80803A4C: mflo        $t2
    ctx->r10 = lo;
    // 0x80803A50: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80803A54: nop

    // 0x80803A58: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80803A5C: sub.s       $f2, $f12, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80803A60: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x80803A64: nop

    // 0x80803A68: bc1t        L_80803AB8
    if (c1cs) {
        // 0x80803A6C: nop
    
            goto L_80803AB8;
    }
    // 0x80803A6C: nop

    // 0x80803A70: c.lt.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl < ctx->f2.fl;
    // 0x80803A74: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80803A78: bc1t        L_80803AB8
    if (c1cs) {
        // 0x80803A7C: nop
    
            goto L_80803AB8;
    }
    // 0x80803A7C: nop

    // 0x80803A80: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80803A84: mflo        $t4
    ctx->r12 = lo;
    // 0x80803A88: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80803A8C: nop

    // 0x80803A90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80803A94: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80803A98: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80803A9C: nop

    // 0x80803AA0: bc1t        L_80803AB8
    if (c1cs) {
        // 0x80803AA4: nop
    
            goto L_80803AB8;
    }
    // 0x80803AA4: nop

    // 0x80803AA8: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x80803AAC: nop

    // 0x80803AB0: bc1fl       L_80803AF8
    if (!c1cs) {
        // 0x80803AB4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80803AF8;
    }
    goto skip_4;
    // 0x80803AB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
L_80803AB8:
    // 0x80803AB8: jal         0x800F796C
    // 0x80803ABC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_800F796C(rdram, ctx);
        goto after_5;
    // 0x80803ABC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_5:
    // 0x80803AC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803AC4: jal         0x800EE7F8
    // 0x80803AC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80803AC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80803ACC: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80803AD0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80803AD4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80803AD8: add.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x80803ADC: jal         0x800862B8
    // 0x80803AE0: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80803AE0: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80803AE4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80803AE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803AEC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80803AF0: swc1        $f16, 0xA4($s6)
    MEM_W(0XA4, ctx->r22) = ctx->f16.u32l;
L_80803AF4:
    // 0x80803AF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80803AF8:
    // 0x80803AF8: bne         $s0, $s7, L_8080398C
    if (ctx->r16 != ctx->r23) {
        // 0x80803AFC: nop
    
            goto L_8080398C;
    }
    // 0x80803AFC: nop

    // 0x80803B00: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80803B04: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80803B08: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80803B0C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80803B10: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80803B14: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80803B18: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80803B1C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80803B20: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80803B24: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80803B28: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80803B2C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80803B30: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80803B34: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80803B38: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x80803B3C: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x80803B40: jr          $ra
    // 0x80803B44: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80803B44: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80800754_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080075C: jal         0x8080055C
    // 0x80800760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800764: jal         0x80082FE0
    // 0x80800768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080076C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800774: jr          $ra
    // 0x80800778: nop

    return;
    // 0x80800778: nop

;}
RECOMP_FUNC void func_80800D68_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800D74: jal         0x800839E8
    // 0x80800D78: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800D78: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800D7C: beq         $v0, $zero, L_80800D88
    if (ctx->r2 == 0) {
        // 0x80800D80: addiu       $t6, $zero, 0x136
        ctx->r14 = ADD32(0, 0X136);
            goto L_80800D88;
    }
    // 0x80800D80: addiu       $t6, $zero, 0x136
    ctx->r14 = ADD32(0, 0X136);
    // 0x80800D84: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800D88:
    // 0x80800D88: jal         0x80800694
    // 0x80800D8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800D8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800D90: jal         0x80084488
    // 0x80800D94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bababykaz_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800D94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800D98: beq         $v0, $zero, L_80800DA4
    if (ctx->r2 == 0) {
        // 0x80800D9C: addiu       $t7, $zero, 0x94
        ctx->r15 = ADD32(0, 0X94);
            goto L_80800DA4;
    }
    // 0x80800D9C: addiu       $t7, $zero, 0x94
    ctx->r15 = ADD32(0, 0X94);
    // 0x80800DA0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80800DA4:
    // 0x80800DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DA8: jal         0x8009E5C8
    // 0x80800DAC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80800DAC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DB8: jr          $ra
    // 0x80800DBC: nop

    return;
    // 0x80800DBC: nop

;}
RECOMP_FUNC void func_80808B40_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808B40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808B44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808B48: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80808B4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80808B50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80808B54: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80808B58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80808B5C: jal         0x80100094
    // 0x80808B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808B64: lw          $t6, 0xAC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XAC);
    // 0x80808B68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80808B6C: beql        $s0, $t6, L_80808BD0
    if (ctx->r16 == ctx->r14) {
        // 0x80808B70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80808BD0;
    }
    goto skip_0;
    // 0x80808B70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80808B74: beq         $s0, $zero, L_80808B9C
    if (ctx->r16 == 0) {
        // 0x80808B78: sw          $s0, 0xAC($v0)
        MEM_W(0XAC, ctx->r2) = ctx->r16;
            goto L_80808B9C;
    }
    // 0x80808B78: sw          $s0, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r16;
    // 0x80808B7C: lw          $t7, 0xB0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB0);
    // 0x80808B80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80808B84: bnel        $t7, $zero, L_80808BD0
    if (ctx->r15 != 0) {
        // 0x80808B88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80808BD0;
    }
    goto skip_1;
    // 0x80808B88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80808B8C: jal         0x80108B04
    // 0x80808B90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x80808B90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80808B94: b           L_80808BD0
    // 0x80808B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80808BD0;
    // 0x80808B98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80808B9C:
    // 0x80808B9C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80808BA0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80808BA4: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_80808BA8:
    // 0x80808BA8: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x80808BAC: beql        $a0, $zero, L_80808BC4
    if (ctx->r4 == 0) {
        // 0x80808BB0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80808BC4;
    }
    goto skip_2;
    // 0x80808BB0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_2:
    // 0x80808BB4: jal         0x800FFA88
    // 0x80808BB8: nop

    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80808BB8: nop

    after_2:
    // 0x80808BBC: sw          $zero, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = 0;
    // 0x80808BC0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80808BC4:
    // 0x80808BC4: bne         $s1, $s2, L_80808BA8
    if (ctx->r17 != ctx->r18) {
        // 0x80808BC8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80808BA8;
    }
    // 0x80808BC8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80808BCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80808BD0:
    // 0x80808BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808BD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80808BD8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80808BDC: jr          $ra
    // 0x80808BE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80808BE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80802020_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080202C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802030: jal         0x80100094
    // 0x80802034: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802034: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802038: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080203C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802040: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80802044: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80802048: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8080204C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802050: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80802054: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802058: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8080205C: lw          $t8, 0x568($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X568);
    // 0x80802060: addiu       $a3, $a1, 0x568
    ctx->r7 = ADD32(ctx->r5, 0X568);
    // 0x80802064: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80802068: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8080206C: blez        $t9, L_808020C8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80802070: sw          $t9, 0x568($a1)
        MEM_W(0X568, ctx->r5) = ctx->r25;
            goto L_808020C8;
    }
    // 0x80802070: sw          $t9, 0x568($a1)
    MEM_W(0X568, ctx->r5) = ctx->r25;
    // 0x80802074: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80802078: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
L_8080207C:
    // 0x8080207C: bnel        $a2, $t1, L_808020B4
    if (ctx->r6 != ctx->r9) {
        // 0x80802080: lw          $t0, 0x0($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X0);
            goto L_808020B4;
    }
    goto skip_0;
    // 0x80802080: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80802084: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80802088: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8080208C: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80802090: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80802094: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80802098: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8080209C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808020A0: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x808020A4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x808020A8: b           L_808020C8
    // 0x808020AC: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
        goto L_808020C8;
    // 0x808020AC: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x808020B0: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
L_808020B4:
    // 0x808020B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808020B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x808020BC: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808020C0: bnel        $at, $zero, L_8080207C
    if (ctx->r1 != 0) {
        // 0x808020C4: lw          $t1, 0x4($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X4);
            goto L_8080207C;
    }
    goto skip_1;
    // 0x808020C4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    skip_1:
L_808020C8:
    // 0x808020C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808020CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808020D0: jr          $ra
    // 0x808020D4: nop

    return;
    // 0x808020D4: nop

    // 0x808020D8: nop

    // 0x808020DC: nop

;}
RECOMP_FUNC void func_80800258_chhellterskeltermouth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080025C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800260: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800264: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800268: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080026C: bne         $a1, $at, L_808002C8
    if (ctx->r5 != ctx->r1) {
        // 0x80800270: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808002C8;
    }
    // 0x80800270: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800274: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080027C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80800280: jal         0x80085708
    // 0x80800284: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80800284: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_0:
    // 0x80800288: jal         0x8010A590
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x80103110
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x80102FE8
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102FE8(rdram, ctx);
        goto after_3;
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80101FDC
    // 0x808002B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808002B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x808002B4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808002B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002C0: b           L_808002D0
    // 0x808002C4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808002D0;
    // 0x808002C4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808002C8:
    // 0x808002C8: b           L_808002D0
    // 0x808002CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002D0;
    // 0x808002CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002D0:
    // 0x808002D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

;}
RECOMP_FUNC void baeggfire_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080055C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800564: jal         0x808000B8
    // 0x80800568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000B8_baeggfire(rdram, ctx);
        goto after_0;
    // 0x80800568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080056C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800570: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800574: lw          $a0, 0x6C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X6C);
    // 0x80800578: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8080057C: beq         $v0, $at, L_808005A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800580: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005A4;
    }
    // 0x80800580: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800584: beq         $v0, $at, L_808005C0
    if (ctx->r2 == ctx->r1) {
        // 0x80800588: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808005C0;
    }
    // 0x80800588: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080058C: beq         $v0, $at, L_808005E4
    if (ctx->r2 == ctx->r1) {
        // 0x80800590: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808005E4;
    }
    // 0x80800590: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800594: beq         $v0, $at, L_80800628
    if (ctx->r2 == ctx->r1) {
        // 0x80800598: nop
    
            goto L_80800628;
    }
    // 0x80800598: nop

    // 0x8080059C: b           L_80800648
    // 0x808005A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800648;
    // 0x808005A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005A4:
    // 0x808005A4: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x808005A8: beql        $t6, $zero, L_80800648
    if (ctx->r14 == 0) {
        // 0x808005AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800648;
    }
    goto skip_0;
    // 0x808005AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005B0: jal         0x80800250
    // 0x808005B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800250_baeggfire(rdram, ctx);
        goto after_1;
    // 0x808005B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x808005B8: b           L_80800648
    // 0x808005BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800648;
    // 0x808005BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005C0:
    // 0x808005C0: jal         0x800D9078
    // 0x808005C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x808005C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x808005C8: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x808005CC: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800644;
    }
    // 0x808005CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808005D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005D4: jal         0x80800180
    // 0x808005D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800180_baeggfire(rdram, ctx);
        goto after_3;
    // 0x808005D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808005DC: b           L_80800648
    // 0x808005E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800648;
    // 0x808005E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005E4:
    // 0x808005E4: jal         0x800D9078
    // 0x808005E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x808005E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_4:
    // 0x808005EC: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x808005F0: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800608;
    }
    // 0x808005F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808005F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005FC: jal         0x80800180
    // 0x80800600: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80800180_baeggfire(rdram, ctx);
        goto after_5;
    // 0x80800600: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_5:
    // 0x80800604: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80800608:
    // 0x80800608: lw          $t7, 0x6C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X6C);
    // 0x8080060C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80800610: beql        $t8, $zero, L_80800648
    if (ctx->r24 == 0) {
        // 0x80800614: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800648;
    }
    goto skip_1;
    // 0x80800614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800618: jal         0x80800250
    // 0x8080061C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800250_baeggfire(rdram, ctx);
        goto after_6;
    // 0x8080061C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x80800620: b           L_80800648
    // 0x80800624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800648;
    // 0x80800624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800628:
    // 0x80800628: jal         0x800D9078
    // 0x8080062C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x8080062C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_7:
    // 0x80800630: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x80800634: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800644;
    }
    // 0x80800634: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800638: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080063C: jal         0x80800180
    // 0x80800640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800180_baeggfire(rdram, ctx);
        goto after_8;
    // 0x80800640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80800644:
    // 0x80800644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800648:
    // 0x80800648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080064C: jr          $ra
    // 0x80800650: nop

    return;
    // 0x80800650: nop

;}
RECOMP_FUNC void func_80018820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018820: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80018824: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80018828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001882C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018830: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80018834: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80018838: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8001883C: jal         0x800187B4
    // 0x80018840: nop

    func_800187B4(rdram, ctx);
        goto after_0;
    // 0x80018840: nop

    after_0:
    // 0x80018844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001884C: jr          $ra
    // 0x80018850: nop

    return;
    // 0x80018850: nop

;}
RECOMP_FUNC void _badrone_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848A0: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848A0);
    return;
    // 0x800848A4: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void bssub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800F60: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X1890) << 16);
    // 0x80800F64: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800F68: jr          $ra
    // 0x80800F6C: lw          $v0, 0x1890($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X1890));
    return;
    // 0x80800F6C: lw          $v0, 0x1890($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X1890));
;}
RECOMP_FUNC void func_808002AC_chjamjarsdummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B4: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x808002B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002BC: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x808002C0: bne         $t7, $at, L_808002D8
    if (ctx->r15 != ctx->r1) {
        // 0x808002C4: nop
    
            goto L_808002D8;
    }
    // 0x808002C4: nop

    // 0x808002C8: lbu         $t9, 0x7E($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X7E);
    // 0x808002CC: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x808002D0: b           L_808002E0
    // 0x808002D4: sb          $t0, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r8;
        goto L_808002E0;
    // 0x808002D4: sb          $t0, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r8;
L_808002D8:
    // 0x808002D8: jal         0x80101870
    // 0x808002DC: nop

    func_80101870(rdram, ctx);
        goto after_0;
    // 0x808002DC: nop

    after_0:
L_808002E0:
    // 0x808002E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_800A3EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3ED0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x800A3ED4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A3ED8: lbu         $t6, 0x7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7);
    // 0x800A3EDC: beql        $a1, $t6, L_800A3F08
    if (ctx->r5 == ctx->r14) {
        // 0x800A3EE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3F08;
    }
    goto skip_0;
    // 0x800A3EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A3EE4: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
    // 0x800A3EE8: jal         0x800A4CA8
    // 0x800A3EEC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x800A3EEC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A3EF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A3EF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A3EF8: lw          $t7, 0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X38);
    // 0x800A3EFC: jal         0x80110D08
    // 0x800A3F00: lbu         $a1, 0x7($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X7);
    func_80110D08(rdram, ctx);
        goto after_1;
    // 0x800A3F00: lbu         $a1, 0x7($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X7);
    after_1:
    // 0x800A3F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3F08:
    // 0x800A3F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3F0C: jr          $ra
    // 0x800A3F10: nop

    return;
    // 0x800A3F10: nop

;}
RECOMP_FUNC void func_800C0808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C080C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0810: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0814: jal         0x80087E68
    // 0x800C0818: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogexec_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x800C0818: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_0:
    // 0x800C081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0824: jr          $ra
    // 0x800C0828: nop

    return;
    // 0x800C0828: nop

;}
RECOMP_FUNC void _chjiggygamenew_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B38: syscall     197
    recomp_syscall_handler(rdram, ctx, 0x80085B38);
    return;
    // 0x80085B3C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800294_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800298: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080029C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002A0: jal         0x800D8FF8
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002A8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808002AC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002B0: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808002B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808002B8: lui         $a3, 0x463B
    ctx->r7 = S32(0X463B << 16);
    // 0x808002BC: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x808002C0: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808002C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X18E4) << 16);
    // 0x808002CC: bc1tl       L_80800338
    if (c1cs) {
        // 0x808002D0: lwc1        $f4, 0x24($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80800338;
    }
    goto skip_0;
    // 0x808002D0: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x808002D4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808002D8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808002DC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x808002E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002E4: bc1f        L_80800304
    if (!c1cs) {
        // 0x808002E8: swc1        $f8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
            goto L_80800304;
    }
    // 0x808002E8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x808002EC: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808002F0: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808002F4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808002F8: nop

    // 0x808002FC: bc1tl       L_80800330
    if (c1cs) {
        // 0x80800300: swc1        $f0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
            goto L_80800330;
    }
    goto skip_1;
    // 0x80800300: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    skip_1:
L_80800304:
    // 0x80800304: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80800308: nop

    // 0x8080030C: bc1fl       L_80800338
    if (!c1cs) {
        // 0x80800310: lwc1        $f4, 0x24($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80800338;
    }
    goto skip_2;
    // 0x80800310: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x80800314: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800318: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080031C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800320: nop

    // 0x80800324: bc1fl       L_80800338
    if (!c1cs) {
        // 0x80800328: lwc1        $f4, 0x24($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80800338;
    }
    goto skip_3;
    // 0x80800328: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    skip_3:
    // 0x8080032C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80800330:
    // 0x80800330: swc1        $f14, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f14.u32l;
    // 0x80800334: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
L_80800338:
    // 0x80800338: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8080033C: nop

    // 0x80800340: bc1tl       L_80800404
    if (c1cs) {
        // 0x80800344: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800404;
    }
    goto skip_4;
    // 0x80800344: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_4:
    // 0x80800348: lwc1        $f6, 0x18E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X18E4));
    // 0x8080034C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800350: jal         0x800F10B4
    // 0x80800354: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800354: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800358: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080035C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800360: jal         0x800C4B70
    // 0x80800364: nop

    func_800C4B70(rdram, ctx);
        goto after_2;
    // 0x80800364: nop

    after_2:
    // 0x80800368: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(748, 0X1990) << 16);
    // 0x8080036C: addiu       $a3, $a3, 0x1990
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(748, 0X1990));
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800378: jal         0x80089D50
    // 0x8080037C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080037C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80800380: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800384: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800388: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x8080038C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800390: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80800394: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800398: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080039C: bc1fl       L_808003FC
    if (!c1cs) {
        // 0x808003A0: sub.s       $f4, $f0, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_808003FC;
    }
    goto skip_5;
    // 0x808003A0: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    skip_5:
    // 0x808003A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003A8: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808003AC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003B4: jal         0x800F10B4
    // 0x808003B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808003B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x808003BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003C0: addiu       $a0, $zero, 0x67A
    ctx->r4 = ADD32(0, 0X67A);
    // 0x808003C4: jal         0x800C3FC0
    // 0x808003C8: addiu       $a2, $zero, 0x4650
    ctx->r6 = ADD32(0, 0X4650);
    func_800C3FC0(rdram, ctx);
        goto after_5;
    // 0x808003C8: addiu       $a2, $zero, 0x4650
    ctx->r6 = ADD32(0, 0X4650);
    after_5:
    // 0x808003CC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808003D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003D4: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808003D8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003DC: lui         $a3, 0x3F73
    ctx->r7 = S32(0X3F73 << 16);
    // 0x808003E0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808003E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003E8: jal         0x800F10B4
    // 0x808003EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x808003EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x808003F0: b           L_80800400
    // 0x808003F4: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
        goto L_80800400;
    // 0x808003F4: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x808003F8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
L_808003FC:
    // 0x808003FC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_80800400:
    // 0x80800400: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800404:
    // 0x80800404: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800408: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x8080040C: beq         $t7, $at, L_80800424
    if (ctx->r15 == ctx->r1) {
        // 0x80800410: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800424;
    }
    // 0x80800410: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800414: beq         $t7, $at, L_8080046C
    if (ctx->r15 == ctx->r1) {
        // 0x80800418: nop
    
            goto L_8080046C;
    }
    // 0x80800418: nop

    // 0x8080041C: b           L_808004A4
    // 0x80800420: nop

        goto L_808004A4;
    // 0x80800420: nop

L_80800424:
    // 0x80800424: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80800428: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: srl         $t9, $t8, 4
    ctx->r25 = S32(U32(ctx->r24) >> 4);
    // 0x80800434: bne         $t9, $at, L_8080044C
    if (ctx->r25 != ctx->r1) {
        // 0x80800438: nop
    
            goto L_8080044C;
    }
    // 0x80800438: nop

    // 0x8080043C: jal         0x8080000C
    // 0x80800440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080000C_chlagoonufoint(rdram, ctx);
        goto after_7;
    // 0x80800440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80800444: b           L_808004A4
    // 0x80800448: nop

        goto L_808004A4;
    // 0x80800448: nop

L_8080044C:
    // 0x8080044C: jal         0x800CEAD0
    // 0x80800450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_8;
    // 0x80800450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80800454: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x8080000C
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080000C_chlagoonufoint(rdram, ctx);
        goto after_9;
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800464: b           L_808004A4
    // 0x80800468: nop

        goto L_808004A4;
    // 0x80800468: nop

L_8080046C:
    // 0x8080046C: jal         0x800D8FF8
    // 0x80800470: nop

    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x80800470: nop

    after_10:
    // 0x80800474: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800478: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800480: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800484: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800488: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080048C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800490: nop

    // 0x80800494: bc1f        L_808004A4
    if (!c1cs) {
        // 0x80800498: nop
    
            goto L_808004A4;
    }
    // 0x80800498: nop

    // 0x8080049C: jal         0x8080000C
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080000C_chlagoonufoint(rdram, ctx);
        goto after_11;
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
L_808004A4:
    // 0x808004A4: jal         0x800BEA88
    // 0x808004A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_12;
    // 0x808004A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x808004AC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808004B0: addiu       $a2, $a2, 0x5A60
    ctx->r6 = ADD32(ctx->r6, 0X5A60);
    // 0x808004B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004B8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x808004BC: jal         0x80088660
    // 0x808004C0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x808004C0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x808004C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808004D0: jr          $ra
    // 0x808004D4: nop

    return;
    // 0x808004D4: nop

;}
RECOMP_FUNC void bsstatue_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080053C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X15A0) << 16);
    // 0x80800540: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800544: jr          $ra
    // 0x80800548: lw          $v0, 0x15A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15A0));
    return;
    // 0x80800548: lw          $v0, 0x15A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15A0));
;}
RECOMP_FUNC void _bsbansack_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826E0: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826E0);
    return;
    // 0x800826E4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_8080242C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080242C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802434: jal         0x800EA05C
    // 0x80802438: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80802438: nop

    after_0:
    // 0x8080243C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x80802440: addiu       $a0, $a0, 0x38A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x80802444: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80802448: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8080244C:
    // 0x8080244C: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80802450: bnel        $v0, $t6, L_80802464
    if (ctx->r2 != ctx->r14) {
        // 0x80802454: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80802464;
    }
    goto skip_0;
    // 0x80802454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80802458: b           L_80802470
    // 0x8080245C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80802470;
    // 0x8080245C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80802460: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80802464:
    // 0x80802464: bne         $v1, $a1, L_8080244C
    if (ctx->r3 != ctx->r5) {
        // 0x80802468: addiu       $a0, $a0, 0x84
        ctx->r4 = ADD32(ctx->r4, 0X84);
            goto L_8080244C;
    }
    // 0x80802468: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x8080246C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80802470:
    // 0x80802470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802478: jr          $ra
    // 0x8080247C: nop

    return;
    // 0x8080247C: nop

;}
RECOMP_FUNC void func_800E4D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4D28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E4D2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E4D30: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800E4D34: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800E4D38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E4D3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E4D40: lw          $s1, 0x10($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X10);
    // 0x800E4D44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E4D48: lw          $s3, 0xC($a0)
    ctx->r19 = MEM_W(ctx->r4, 0XC);
    // 0x800E4D4C: bnel        $s1, $zero, L_800E4DB0
    if (ctx->r17 != 0) {
        // 0x800E4D50: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800E4DB0;
    }
    goto skip_0;
    // 0x800E4D50: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x800E4D54: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
L_800E4D58:
    // 0x800E4D58: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4D5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E4D60: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E4D64: bnel        $at, $zero, L_800E4D90
    if (ctx->r1 != 0) {
        // 0x800E4D68: addu        $t8, $s2, $v0
        ctx->r24 = ADD32(ctx->r18, ctx->r2);
            goto L_800E4D90;
    }
    goto skip_1;
    // 0x800E4D68: addu        $t8, $s2, $v0
    ctx->r24 = ADD32(ctx->r18, ctx->r2);
    skip_1:
    // 0x800E4D6C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E4D70: jal         0x8001311C
    // 0x800E4D74: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_0;
    // 0x800E4D74: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_0:
    // 0x800E4D78: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800E4D7C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4D80: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x800E4D84: addiu       $t7, $t6, 0x1800
    ctx->r15 = ADD32(ctx->r14, 0X1800);
    // 0x800E4D88: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x800E4D8C: addu        $t8, $s2, $v0
    ctx->r24 = ADD32(ctx->r18, ctx->r2);
L_800E4D90:
    // 0x800E4D90: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800E4D94: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x800E4D98: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800E4D9C: sllv        $t0, $t9, $s1
    ctx->r8 = S32(ctx->r25 << (ctx->r17 & 31));
    // 0x800E4DA0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800E4DA4: beq         $s1, $zero, L_800E4D58
    if (ctx->r17 == 0) {
        // 0x800E4DA8: or          $s3, $s3, $t0
        ctx->r19 = ctx->r19 | ctx->r8;
            goto L_800E4D58;
    }
    // 0x800E4DA8: or          $s3, $s3, $t0
    ctx->r19 = ctx->r19 | ctx->r8;
    // 0x800E4DAC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800E4DB0:
    // 0x800E4DB0: andi        $t2, $s3, 0x1
    ctx->r10 = ctx->r19 & 0X1;
    // 0x800E4DB4: srl         $t3, $s3, 1
    ctx->r11 = S32(U32(ctx->r19) >> 1);
    // 0x800E4DB8: sltiu       $at, $s1, 0x2
    ctx->r1 = ctx->r17 < 0X2 ? 1 : 0;
    // 0x800E4DBC: sb          $t2, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r10;
    // 0x800E4DC0: beq         $at, $zero, L_800E4E24
    if (ctx->r1 == 0) {
        // 0x800E4DC4: or          $s3, $t3, $zero
        ctx->r19 = ctx->r11 | 0;
            goto L_800E4E24;
    }
    // 0x800E4DC4: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x800E4DC8: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
L_800E4DCC:
    // 0x800E4DCC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4DD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E4DD4: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E4DD8: bnel        $at, $zero, L_800E4E04
    if (ctx->r1 != 0) {
        // 0x800E4DDC: addu        $t6, $s2, $v0
        ctx->r14 = ADD32(ctx->r18, ctx->r2);
            goto L_800E4E04;
    }
    goto skip_2;
    // 0x800E4DDC: addu        $t6, $s2, $v0
    ctx->r14 = ADD32(ctx->r18, ctx->r2);
    skip_2:
    // 0x800E4DE0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E4DE4: jal         0x8001311C
    // 0x800E4DE8: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_1;
    // 0x800E4DE8: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_1:
    // 0x800E4DEC: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x800E4DF0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4DF4: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x800E4DF8: addiu       $t5, $t4, 0x1800
    ctx->r13 = ADD32(ctx->r12, 0X1800);
    // 0x800E4DFC: sw          $t5, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r13;
    // 0x800E4E00: addu        $t6, $s2, $v0
    ctx->r14 = ADD32(ctx->r18, ctx->r2);
L_800E4E04:
    // 0x800E4E04: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800E4E08: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800E4E0C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800E4E10: sllv        $t8, $t7, $s1
    ctx->r24 = S32(ctx->r15 << (ctx->r17 & 31));
    // 0x800E4E14: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800E4E18: sltiu       $at, $s1, 0x2
    ctx->r1 = ctx->r17 < 0X2 ? 1 : 0;
    // 0x800E4E1C: bne         $at, $zero, L_800E4DCC
    if (ctx->r1 != 0) {
        // 0x800E4E20: or          $s3, $s3, $t8
        ctx->r19 = ctx->r19 | ctx->r24;
            goto L_800E4DCC;
    }
    // 0x800E4E20: or          $s3, $s3, $t8
    ctx->r19 = ctx->r19 | ctx->r24;
L_800E4E24:
    // 0x800E4E24: srl         $t0, $s3, 2
    ctx->r8 = S32(U32(ctx->r19) >> 2);
    // 0x800E4E28: addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
    // 0x800E4E2C: sw          $t0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r8;
    // 0x800E4E30: sw          $s1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r17;
    // 0x800E4E34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E4E38: andi        $v0, $s3, 0x3
    ctx->r2 = ctx->r19 & 0X3;
    // 0x800E4E3C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800E4E40: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4E44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E4E48: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E4E4C: jr          $ra
    // 0x800E4E50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E4E50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void vpmodule_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808002C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808002CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808002D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D8: lw          $t6, 0x2C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C);
    // 0x808002DC: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x808002E0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808002E4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808002E8: addu        $s3, $t7, $a0
    ctx->r19 = ADD32(ctx->r15, ctx->r4);
    // 0x808002EC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x808002F0: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808002F4: beq         $at, $zero, L_80800344
    if (ctx->r1 == 0) {
        // 0x808002F8: addiu       $s2, $zero, 0x14
        ctx->r18 = ADD32(0, 0X14);
            goto L_80800344;
    }
    // 0x808002F8: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x808002FC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3002, 0X8C0) << 16);
    // 0x80800300: addiu       $s1, $s1, 0x8C0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3002, 0X8C0));
    // 0x80800304: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
L_80800308:
    // 0x80800308: beql        $t8, $zero, L_80800338
    if (ctx->r24 == 0) {
        // 0x8080030C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80800338;
    }
    goto skip_0;
    // 0x8080030C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x80800310: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80800314: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80800318: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080031C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800320: mflo        $t0
    ctx->r8 = lo;
    // 0x80800324: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x80800328: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x8080032C: jalr        $t9
    // 0x80800330: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80800330: nop

    after_0:
    // 0x80800334: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80800338:
    // 0x80800338: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8080033C: bnel        $at, $zero, L_80800308
    if (ctx->r1 != 0) {
        // 0x80800340: lbu         $t8, 0x1($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X1);
            goto L_80800308;
    }
    goto skip_1;
    // 0x80800340: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    skip_1:
L_80800344:
    // 0x80800344: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080034C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800350: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800354: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800358: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080035C: jr          $ra
    // 0x80800360: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800360: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsmum_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083810: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083810);
    return;
    // 0x80083814: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D50: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D50);
    return;
    // 0x80082D54: addi        $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
;}
RECOMP_FUNC void cheggclockwork_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800574: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800578: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8080057C: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800580: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800584: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800588: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080058C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800590: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800594: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800598: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8080059C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005A4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808005A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808005AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808005B0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x808005B4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x808005B8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x808005BC: jal         0x80087348
    // 0x808005C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _cheggsplode_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808005C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x808005C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005CC: jr          $ra
    // 0x808005D0: nop

    return;
    // 0x808005D0: nop

;}
RECOMP_FUNC void func_808000AC_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808000B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: jal         0x80100094
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000C8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808000CC: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x80100094
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000DC: beq         $v0, $zero, L_808000FC
    if (ctx->r2 == 0) {
        // 0x808000E0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808000FC;
    }
    // 0x808000E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E4: jal         0x80100094
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808000F4: jal         0x800897D8
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_808000FC:
    // 0x808000FC: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800100: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800104: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800108: sltiu       $at, $t9, 0xF
    ctx->r1 = ctx->r25 < 0XF ? 1 : 0;
    // 0x8080010C: beq         $at, $zero, L_808004A4
    if (ctx->r1 == 0) {
        // 0x80800110: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808004A4;
    }
    // 0x80800110: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800114: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1540, 0X1030) << 16);
    // 0x80800118: addu        $at, $at, $t9
    gpr jr_addend_80800120 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8080011C: lw          $t9, 0x1030($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1540, 0X1030));
    // 0x80800120: jr          $t9
    // 0x80800124: nop

    switch (jr_addend_80800120 >> 2) {
        case 0: goto L_80800128; break;
        case 1: goto L_808004A4; break;
        case 2: goto L_808004A4; break;
        case 3: goto L_808004A4; break;
        case 4: goto L_808001B0; break;
        case 5: goto L_8080020C; break;
        case 6: goto L_808004A4; break;
        case 7: goto L_808004A4; break;
        case 8: goto L_80800294; break;
        case 9: goto L_8080029C; break;
        case 10: goto L_80800300; break;
        case 11: goto L_8080034C; break;
        case 12: goto L_808003C4; break;
        case 13: goto L_808003F0; break;
        case 14: goto L_80800430; break;
        default: switch_error(__func__, 0x80800120, 0x80801030);
    }
    // 0x80800124: nop

L_80800128:
    // 0x80800128: jal         0x800DA298
    // 0x8080012C: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x8080012C: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_4:
    // 0x80800130: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x80800134: nop
    
            goto L_80800184;
    }
    // 0x80800134: nop

    // 0x80800138: jal         0x800DA298
    // 0x8080013C: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x8080013C: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_5:
    // 0x80800140: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x80800144: nop
    
            goto L_80800158;
    }
    // 0x80800144: nop

    // 0x80800148: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x8080014C: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x80800150: b           L_80800184
    // 0x80800154: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
        goto L_80800184;
    // 0x80800154: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
L_80800158:
    // 0x80800158: jal         0x80800FE0
    // 0x8080015C: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    func_80800FE0_chboggyfatboy(rdram, ctx);
        goto after_6;
    // 0x8080015C: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    after_6:
    // 0x80800160: beq         $v0, $zero, L_80800184
    if (ctx->r2 == 0) {
        // 0x80800164: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800184;
    }
    // 0x80800164: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800168: jal         0x8010CAC0
    // 0x8080016C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010CAC0(rdram, ctx);
        goto after_7;
    // 0x8080016C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_7:
    // 0x80800170: bne         $v0, $zero, L_80800184
    if (ctx->r2 != 0) {
        // 0x80800174: nop
    
            goto L_80800184;
    }
    // 0x80800174: nop

    // 0x80800178: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x8080017C: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x80800180: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
L_80800184:
    // 0x80800184: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X1224) << 16);
    // 0x80800188: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1540, 0X1128) << 16);
    // 0x8080018C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80800190: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800194: addiu       $a3, $a3, 0x1128
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1540, 0X1128));
    // 0x80800198: addiu       $a2, $a2, 0x1224
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X1224));
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x8008A1F0
    // 0x808001A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x808001A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x808001A8: b           L_808004A8
    // 0x808001AC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004A8;
    // 0x808001AC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808001B0:
    // 0x808001B0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808001B4: jal         0x800EE88C
    // 0x808001B8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EE88C(rdram, ctx);
        goto after_9;
    // 0x808001B8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_9:
    // 0x808001BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001C4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808001C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808001D4: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x808001D8: jal         0x801028C4
    // 0x808001DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_801028C4(rdram, ctx);
        goto after_10;
    // 0x808001DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x808001E0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808001E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808001F0: nop

    // 0x808001F4: bc1fl       L_808004A8
    if (!c1cs) {
        // 0x808001F8: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808004A8;
    }
    goto skip_0;
    // 0x808001F8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x808001FC: jal         0x80102424
    // 0x80800200: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800200: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x80800204: b           L_808004A8
    // 0x80800208: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004A8;
    // 0x80800208: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_8080020C:
    // 0x8080020C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800210: jal         0x800EE88C
    // 0x80800214: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EE88C(rdram, ctx);
        goto after_12;
    // 0x80800214: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_12:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80102D78
    // 0x80800220: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80102D78(rdram, ctx);
        goto after_13;
    // 0x80800220: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_13:
    // 0x80800224: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800228: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080022C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80800238: jal         0x80102BF8
    // 0x8080023C: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_14;
    // 0x8080023C: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_14:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x8010B990
    // 0x80800248: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    func_8010B990(rdram, ctx);
        goto after_15;
    // 0x80800248: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    after_15:
    // 0x8080024C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800250: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800254: jal         0x800F0064
    // 0x80800258: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800F0064(rdram, ctx);
        goto after_16;
    // 0x80800258: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_16:
    // 0x8080025C: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80800268: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x8080026C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800270: jal         0x801058C4
    // 0x80800274: lh          $a1, 0x6($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X6);
    func_801058C4(rdram, ctx);
        goto after_17;
    // 0x80800274: lh          $a1, 0x6($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X6);
    after_17:
    // 0x80800278: jal         0x80105BAC
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_18;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x80102424
    // 0x80800288: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x80800288: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_19:
    // 0x8080028C: b           L_808004A8
    // 0x80800290: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004A8;
    // 0x80800290: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800294:
    // 0x80800294: b           L_808004A4
    // 0x80800298: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
        goto L_808004A4;
    // 0x80800298: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8080029C:
    // 0x8080029C: jal         0x80106790
    // 0x808002A0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_20;
    // 0x808002A0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_20:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x80102D78
    // 0x808002AC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_80102D78(rdram, ctx);
        goto after_21;
    // 0x808002AC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_21:
    // 0x808002B0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808002B4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808002B8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x808002C4: jal         0x80102BF8
    // 0x808002C8: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_22;
    // 0x808002C8: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_22:
    // 0x808002CC: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: jal         0x8008A500
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_1(rdram, ctx);
        goto after_23;
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x808002DC: beql        $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x808002E0: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808004A8;
    }
    goto skip_1;
    // 0x808002E0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x808002E4: jal         0x800DA544
    // 0x808002E8: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x808002E8: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    after_24:
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x80102424
    // 0x808002F4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80102424(rdram, ctx);
        goto after_25;
    // 0x808002F4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_25:
    // 0x808002F8: b           L_808004A8
    // 0x808002FC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004A8;
    // 0x808002FC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800300:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x8008A550
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_11(rdram, ctx);
        goto after_26;
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x8080030C: beq         $v0, $zero, L_80800338
    if (ctx->r2 == 0) {
        // 0x80800310: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800338;
    }
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x8008A520
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_5(rdram, ctx);
        goto after_27;
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x8080031C: beq         $v0, $zero, L_80800338
    if (ctx->r2 == 0) {
        // 0x80800320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800338;
    }
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x8008A568
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_14(rdram, ctx);
        goto after_28;
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: jal         0x80102424
    // 0x80800334: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x80800334: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_29:
L_80800338:
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: jal         0x8008A558
    // 0x80800340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_12(rdram, ctx);
        goto after_30;
    // 0x80800340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800344: b           L_808004A4
    // 0x80800348: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_808004A4;
    // 0x80800348: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_8080034C:
    // 0x8080034C: jal         0x80106790
    // 0x80800350: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_31;
    // 0x80800350: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_31:
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80102D78
    // 0x8080035C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_80102D78(rdram, ctx);
        goto after_32;
    // 0x8080035C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_32:
    // 0x80800360: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800364: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800368: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80800374: jal         0x80102BF8
    // 0x80800378: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_33;
    // 0x80800378: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_33:
    // 0x8080037C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800380: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800384: bltzl       $t9, L_808004A8
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800388: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808004A8;
    }
    goto skip_2;
    // 0x80800388: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x8080038C: jal         0x80106790
    // 0x80800390: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_34;
    // 0x80800390: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_34:
    // 0x80800394: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x80800398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080039C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x808003A0: sll         $t0, $a2, 11
    ctx->r8 = S32(ctx->r6 << 11);
    // 0x808003A4: jal         0x8010108C
    // 0x808003A8: srl         $a2, $t0, 20
    ctx->r6 = S32(U32(ctx->r8) >> 20);
    func_8010108C(rdram, ctx);
        goto after_35;
    // 0x808003A8: srl         $a2, $t0, 20
    ctx->r6 = S32(U32(ctx->r8) >> 20);
    after_35:
    // 0x808003AC: blezl       $v0, L_808004A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808003B0: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808004A8;
    }
    goto skip_3;
    // 0x808003B0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_3:
    // 0x808003B4: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808003B8: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x808003BC: b           L_808004A4
    // 0x808003C0: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
        goto L_808004A4;
    // 0x808003C0: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_808003C4:
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x8008A570
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_15(rdram, ctx);
        goto after_36;
    // 0x808003CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x808003D0: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x808003D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x80102424
    // 0x808003DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_37;
    // 0x808003DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x808003E0: jal         0x8010A590
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_38;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808003E8: b           L_808004A8
    // 0x808003EC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004A8;
    // 0x808003EC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808003F0:
    // 0x808003F0: jal         0x80800D84
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D84_chboggyfatboy(rdram, ctx);
        goto after_39;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x808003F8: jal         0x80101DDC
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_40;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800400: beql        $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x80800404: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808004A8;
    }
    goto skip_4;
    // 0x80800404: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_4:
    // 0x80800408: jal         0x80800998
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800998_chboggyfatboy(rdram, ctx);
        goto after_41;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: jal         0x80102424
    // 0x80800418: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_42;
    // 0x80800418: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_42:
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x8008A4B0
    // 0x80800424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_43;
    // 0x80800424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_43:
    // 0x80800428: b           L_808004A8
    // 0x8080042C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004A8;
    // 0x8080042C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800430:
    // 0x80800430: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080043C: jal         0x80089FE8
    // 0x80800440: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_44;
    // 0x80800440: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    after_44:
    // 0x80800444: beql        $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x80800448: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808004A8;
    }
    goto skip_5;
    // 0x80800448: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_5:
    // 0x8080044C: jal         0x800F54E4
    // 0x80800450: nop

    func_800F54E4(rdram, ctx);
        goto after_45;
    // 0x80800450: nop

    after_45:
    // 0x80800454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800458: jal         0x800F64A4
    // 0x8080045C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800F64A4(rdram, ctx);
        goto after_46;
    // 0x8080045C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_46:
    // 0x80800460: beq         $v0, $zero, L_80800470
    if (ctx->r2 == 0) {
        // 0x80800464: addiu       $a0, $zero, 0xBB
        ctx->r4 = ADD32(0, 0XBB);
            goto L_80800470;
    }
    // 0x80800464: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    // 0x80800468: b           L_80800474
    // 0x8080046C: addiu       $a1, $zero, 0x1111
    ctx->r5 = ADD32(0, 0X1111);
        goto L_80800474;
    // 0x8080046C: addiu       $a1, $zero, 0x1111
    ctx->r5 = ADD32(0, 0X1111);
L_80800470:
    // 0x80800470: addiu       $a1, $zero, 0x1095
    ctx->r5 = ADD32(0, 0X1095);
L_80800474:
    // 0x80800474: jal         0x800DA544
    // 0x80800478: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DA544(rdram, ctx);
        goto after_47;
    // 0x80800478: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_47:
    // 0x8080047C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800480: addiu       $t5, $zero, 0x3B
    ctx->r13 = ADD32(0, 0X3B);
    // 0x80800484: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800488: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080048C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800490: jal         0x8008A208
    // 0x80800494: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_48;
    // 0x80800494: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_48:
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x80102424
    // 0x808004A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_49;
    // 0x808004A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_49:
L_808004A4:
    // 0x808004A4: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808004A8:
    // 0x808004A8: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x808004AC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x808004B0: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x808004B4: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x808004B8: beq         $t7, $zero, L_808004E0
    if (ctx->r15 == 0) {
        // 0x808004BC: nop
    
            goto L_808004E0;
    }
    // 0x808004BC: nop

    // 0x808004C0: jal         0x800D9154
    // 0x808004C4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_800D9154(rdram, ctx);
        goto after_50;
    // 0x808004C4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_50:
    // 0x808004C8: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X1148) << 16);
    // 0x808004D4: addiu       $a2, $a2, 0x1148
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X1148));
    // 0x808004D8: jal         0x80089D18
    // 0x808004DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_51;
    // 0x808004DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_51:
L_808004E0:
    // 0x808004E0: jal         0x80800E80
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E80_chboggyfatboy(rdram, ctx);
        goto after_52;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x8008A540
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_9(rdram, ctx);
        goto after_53;
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_53:
    // 0x808004F4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x808004F8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004FC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800500: beq         $t8, $zero, L_80800518
    if (ctx->r24 == 0) {
        // 0x80800504: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80800518;
    }
    // 0x80800504: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800508: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8080050C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800510: jal         0x80089F20
    // 0x80800514: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_54;
    // 0x80800514: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_54:
L_80800518:
    // 0x80800518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080051C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800520: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801000: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(68, 0X1780) << 16);
    // 0x80801008: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080100C: jr          $ra
    // 0x80801010: lw          $v0, 0x1780($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1780));
    return;
    // 0x80801010: lw          $v0, 0x1780($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1780));
;}
RECOMP_FUNC void bsmumstill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808003EC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(328, 0X414) << 16);
    // 0x808003F0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003F4: jr          $ra
    // 0x808003F8: lw          $v0, 0x414($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(328, 0X414));
    return;
    // 0x808003F8: lw          $v0, 0x414($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(328, 0X414));
;}
RECOMP_FUNC void _fxgenlist_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B00: syscall     723
    recomp_syscall_handler(rdram, ctx, 0x80088B00);
    return;
    // 0x80088B04: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802418_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802418: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080241C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802420: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80802424: lbu         $t6, 0x9B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9B);
    // 0x80802428: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080242C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80802430: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80802434: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80802438: bgez        $t6, L_8080244C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080243C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8080244C;
    }
    // 0x8080243C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80802440: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802444: nop

    // 0x80802448: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8080244C:
    // 0x8080244C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F00) << 16);
    // 0x80802450: lwc1        $f4, 0x4F00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F00));
    // 0x80802454: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802458: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080245C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80802460: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80802464: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80802468: nop

    // 0x8080246C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80802470: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80802474: nop

    // 0x80802478: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8080247C: beql        $t8, $zero, L_808024CC
    if (ctx->r24 == 0) {
        // 0x80802480: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_808024CC;
    }
    goto skip_0;
    // 0x80802480: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80802484: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802488: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080248C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80802490: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80802494: nop

    // 0x80802498: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8080249C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808024A0: nop

    // 0x808024A4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x808024A8: bne         $t8, $zero, L_808024C0
    if (ctx->r24 != 0) {
        // 0x808024AC: nop
    
            goto L_808024C0;
    }
    // 0x808024AC: nop

    // 0x808024B0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x808024B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808024B8: b           L_808024D8
    // 0x808024BC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_808024D8;
    // 0x808024BC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_808024C0:
    // 0x808024C0: b           L_808024D8
    // 0x808024C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_808024D8;
    // 0x808024C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808024C8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_808024CC:
    // 0x808024CC: nop

    // 0x808024D0: bltz        $t8, L_808024C0
    if (SIGNED(ctx->r24) < 0) {
        // 0x808024D4: nop
    
            goto L_808024C0;
    }
    // 0x808024D4: nop

L_808024D8:
    // 0x808024D8: sb          $t8, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r24;
    // 0x808024DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F04) << 16);
    // 0x808024E0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808024E4: lwc1        $f18, 0x4F04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F04));
    // 0x808024E8: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x808024EC: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x808024F0: jr          $ra
    // 0x808024F4: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x808024F4: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void _mlspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890E8: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x800890E8);
    return;
    // 0x800890EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void sudeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800008: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x8080000C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800010: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800014: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800018: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8080001C: addiu       $s1, $s1, 0x1020
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x80800020: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800024: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800028: andi        $t7, $a3, 0x18
    ctx->r15 = ctx->r7 & 0X18;
    // 0x8080002C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800030: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800038: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080003C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80800040: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800044: beq         $t7, $zero, L_80800058
    if (ctx->r15 == 0) {
        // 0x80800048: sw          $zero, 0x24($s1)
        MEM_W(0X24, ctx->r17) = 0;
            goto L_80800058;
    }
    // 0x80800048: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8080004C: jal         0x800BE3F8
    // 0x80800050: nop

    func_800BE3F8(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80800058:
    // 0x80800058: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8080005C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800060: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x80800064: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80800068: beql        $t9, $zero, L_808000CC
    if (ctx->r25 == 0) {
        // 0x8080006C: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_808000CC;
    }
    goto skip_0;
    // 0x8080006C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_80800070:
    // 0x80800070: jal         0x800F6438
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800078: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x8080007C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000BC;
    }
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800084: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800088: jal         0x800F4F34
    // 0x8080008C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800F4F34(rdram, ctx);
        goto after_2;
    // 0x8080008C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80800090: beql        $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x80800094: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808000C0;
    }
    goto skip_1;
    // 0x80800094: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80800098: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x8080009C: ori         $t5, $s2, 0x2
    ctx->r13 = ctx->r18 | 0X2;
    // 0x808000A0: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x808000A4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808000A8: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x808000AC: sw          $s0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r16;
    // 0x808000B0: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x808000B4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x808000B8: sw          $t4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r12;
L_808000BC:
    // 0x808000BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808000C0:
    // 0x808000C0: bne         $s0, $s3, L_80800070
    if (ctx->r16 != ctx->r19) {
        // 0x808000C4: nop
    
            goto L_80800070;
    }
    // 0x808000C4: nop

    // 0x808000C8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_808000CC:
    // 0x808000CC: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x808000D0: beql        $t7, $zero, L_808000EC
    if (ctx->r15 == 0) {
        // 0x808000D4: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_808000EC;
    }
    goto skip_2;
    // 0x808000D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    skip_2:
    // 0x808000D8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808000DC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808000E0: jal         0x800A52E0
    // 0x808000E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800A52E0(rdram, ctx);
        goto after_3;
    // 0x808000E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x808000E8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_808000EC:
    // 0x808000EC: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x808000F0: beql        $t9, $zero, L_80800118
    if (ctx->r25 == 0) {
        // 0x808000F4: lw          $t1, 0x4C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X4C);
            goto L_80800118;
    }
    goto skip_3;
    // 0x808000F4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    skip_3:
    // 0x808000F8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808000FC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800100: jal         0x808006A4
    // 0x80800104: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808006A4_sudeflect(rdram, ctx);
        goto after_4;
    // 0x80800104: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80800108: beq         $v0, $zero, L_80800114
    if (ctx->r2 == 0) {
        // 0x8080010C: ori         $t0, $s2, 0x8
        ctx->r8 = ctx->r18 | 0X8;
            goto L_80800114;
    }
    // 0x8080010C: ori         $t0, $s2, 0x8
    ctx->r8 = ctx->r18 | 0X8;
    // 0x80800110: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_80800114:
    // 0x80800114: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
L_80800118:
    // 0x80800118: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8080011C: beql        $t2, $zero, L_80800144
    if (ctx->r10 == 0) {
        // 0x80800120: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800144;
    }
    goto skip_4;
    // 0x80800120: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x80800124: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800128: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8080012C: jal         0x80800940
    // 0x80800130: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80800940_sudeflect(rdram, ctx);
        goto after_5;
    // 0x80800130: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x80800134: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x80800138: ori         $t3, $s2, 0x10
        ctx->r11 = ctx->r18 | 0X10;
            goto L_80800140;
    }
    // 0x80800138: ori         $t3, $s2, 0x10
    ctx->r11 = ctx->r18 | 0X10;
    // 0x8080013C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
L_80800140:
    // 0x80800140: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800144:
    // 0x80800144: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80800148: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8080014C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800150: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800154: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800158: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080015C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800160: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800164: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800168: jr          $ra
    // 0x8080016C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080016C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chhotwaterpoolbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1268, 0X9C0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x9C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0X9C0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x9C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1268, 0X9C0));
;}
RECOMP_FUNC void _subaddietaxi_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A518: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A518);
    return;
    // 0x8008A51C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D10: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084D10);
    return;
    // 0x80084D14: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80800030_glgamestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: jr          $ra
    // 0x80800034: sll         $v0, $a0, 7
    ctx->r2 = S32(ctx->r4 << 7);
    return;
    // 0x80800034: sll         $v0, $a0, 7
    ctx->r2 = S32(ctx->r4 << 7);
;}
RECOMP_FUNC void chfantasysafeswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2480, 0X288) << 16);
    // 0x80800250: jr          $ra
    // 0x80800254: addiu       $v0, $v0, 0x288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2480, 0X288));
    return;
    // 0x80800254: addiu       $v0, $v0, 0x288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2480, 0X288));
    // 0x80800258: nop

    // 0x8080025C: nop

;}
RECOMP_FUNC void func_80800008_babee(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800018: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8080001C: jal         0x800EFA98
    // 0x80800020: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EFA98(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800024: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800028: jal         0x800EF04C
    // 0x8080002C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800030: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(459, 0X390) << 16);
    // 0x80800034: addiu       $t6, $t6, 0x390
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(459, 0X390));
    // 0x80800038: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080003C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800044: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800048: jal         0x800BBCB8
    // 0x8080004C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x8080004C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800054: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void func_8001C324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C324: addiu       $sp, $sp, -0xA90
    ctx->r29 = ADD32(ctx->r29, -0XA90);
    // 0x8001C328: sw          $s0, 0xA48($sp)
    MEM_W(0XA48, ctx->r29) = ctx->r16;
    // 0x8001C32C: sw          $s1, 0xA4C($sp)
    MEM_W(0XA4C, ctx->r29) = ctx->r17;
    // 0x8001C330: sw          $s2, 0xA50($sp)
    MEM_W(0XA50, ctx->r29) = ctx->r18;
    // 0x8001C334: sw          $s3, 0xA54($sp)
    MEM_W(0XA54, ctx->r29) = ctx->r19;
    // 0x8001C338: sw          $s4, 0xA58($sp)
    MEM_W(0XA58, ctx->r29) = ctx->r20;
    // 0x8001C33C: sw          $s5, 0xA5C($sp)
    MEM_W(0XA5C, ctx->r29) = ctx->r21;
    // 0x8001C340: sw          $s6, 0xA60($sp)
    MEM_W(0XA60, ctx->r29) = ctx->r22;
    // 0x8001C344: sw          $s7, 0xA64($sp)
    MEM_W(0XA64, ctx->r29) = ctx->r23;
    // 0x8001C348: sw          $fp, 0xA78($sp)
    MEM_W(0XA78, ctx->r29) = ctx->r30;
    // 0x8001C34C: sw          $gp, 0xA7C($sp)
    MEM_W(0XA7C, ctx->r29) = ctx->r28;
    // 0x8001C350: sw          $ra, 0xA80($sp)
    MEM_W(0XA80, ctx->r29) = ctx->r31;
    // 0x8001C354: sw          $zero, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = 0;
    // 0x8001C358: sw          $zero, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = 0;
    // 0x8001C35C: addiu       $s7, $a0, 0x2
    ctx->r23 = ADD32(ctx->r4, 0X2);
    // 0x8001C360: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x8001C364: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8001C368: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8001C36C: lui         $t2, 0x7000
    ctx->r10 = S32(0X7000 << 16);
    // 0x8001C370: subu        $t0, $a0, $a1
    ctx->r8 = SUB32(ctx->r4, ctx->r5);
    // 0x8001C374: bgtzl       $t0, L_8001C37C
    if (SIGNED(ctx->r8) > 0) {
        // 0x8001C378: or          $t2, $t0, $zero
        ctx->r10 = ctx->r8 | 0;
            goto L_8001C37C;
    }
    goto skip_0;
    // 0x8001C378: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    skip_0:
L_8001C37C:
    // 0x8001C37C: subu        $t0, $a2, $a1
    ctx->r8 = SUB32(ctx->r6, ctx->r5);
    // 0x8001C380: bltz        $t0, L_8001C394
    if (SIGNED(ctx->r8) < 0) {
        // 0x8001C384: slt         $at, $t0, $t2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8001C394;
    }
    // 0x8001C384: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001C388: beq         $at, $zero, L_8001C394
    if (ctx->r1 == 0) {
        // 0x8001C38C: nop
    
            goto L_8001C394;
    }
    // 0x8001C38C: nop

    // 0x8001C390: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_8001C394:
    // 0x8001C394: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8001C398: jal         0x8001C3FC
    // 0x8001C39C: nop

    inflate_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C39C: nop

    after_0:
    // 0x8001C3A0: bne         $v0, $zero, L_8001C3F4
    if (ctx->r2 != 0) {
        // 0x8001C3A4: mfc1        $v0, $f17
        ctx->r2 = (int32_t)ctx->f_odd[(17 - 1) * 2];
            goto L_8001C3F4;
    }
    // 0x8001C3A4: mfc1        $v0, $f17
    ctx->r2 = (int32_t)ctx->f_odd[(17 - 1) * 2];
L_8001C3A8:
    // 0x8001C3A8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8001C3AC: addiu       $t0, $t0, -0x8A0
    ctx->r8 = ADD32(ctx->r8, -0X8A0);
    // 0x8001C3B0: lw          $t1, 0xA84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA84);
    // 0x8001C3B4: lw          $t2, 0xA88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA88);
    // 0x8001C3B8: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8001C3BC: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8001C3C0: lw          $s0, 0xA48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA48);
    // 0x8001C3C4: lw          $s1, 0xA4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4C);
    // 0x8001C3C8: lw          $s2, 0xA50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA50);
    // 0x8001C3CC: lw          $s3, 0xA54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA54);
    // 0x8001C3D0: lw          $s4, 0xA58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA58);
    // 0x8001C3D4: lw          $s5, 0xA5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA5C);
    // 0x8001C3D8: lw          $s6, 0xA60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA60);
    // 0x8001C3DC: lw          $s7, 0xA64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XA64);
    // 0x8001C3E0: lw          $fp, 0xA78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XA78);
    // 0x8001C3E4: lw          $gp, 0xA7C($sp)
    ctx->r28 = MEM_W(ctx->r29, 0XA7C);
    // 0x8001C3E8: lw          $ra, 0xA80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA80);
    // 0x8001C3EC: jr          $ra
    // 0x8001C3F0: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
    return;
    // 0x8001C3F0: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
L_8001C3F4:
    // 0x8001C3F4: j           L_8001C3A8
    // 0x8001C3F8: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_8001C3A8;
    // 0x8001C3F8: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddiejoy_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BF8: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BF8);
    return;
    // 0x80089BFC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800630_chfantasysafe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800634: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080063C: beq         $a1, $at, L_808007BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800640: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_808007BC;
    }
    // 0x80800640: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800644: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800648: bne         $a1, $at, L_80800918
    if (ctx->r5 != ctx->r1) {
        // 0x8080064C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800918;
    }
    // 0x8080064C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800650: addiu       $v1, $a2, -0x51
    ctx->r3 = ADD32(ctx->r6, -0X51);
    // 0x80800654: jal         0x800DB9B0
    // 0x80800658: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80800658: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8080065C: beq         $v0, $zero, L_8080066C
    if (ctx->r2 == 0) {
        // 0x80800660: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8080066C;
    }
    // 0x80800660: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800664: b           L_80800670
    // 0x80800668: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
        goto L_80800670;
    // 0x80800668: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
L_8080066C:
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800670:
    // 0x80800670: ori         $t6, $a1, 0x810
    ctx->r14 = ctx->r5 | 0X810;
    // 0x80800674: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80800678: beq         $at, $zero, L_808007B4
    if (ctx->r1 == 0) {
        // 0x8080067C: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_808007B4;
    }
    // 0x8080067C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80800680: bltz        $v1, L_808007B4
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800684: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808007B4;
    }
    // 0x80800684: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800688: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080068C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800690: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800694: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80800698: jal         0x80101FDC
    // 0x8080069C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x8080069C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x808006A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808006A4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808006A8: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2380, 0X998) << 16);
    // 0x808006AC: lhu         $t9, 0x6E($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X6E);
    // 0x808006B0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808006B4: addiu       $t3, $t3, 0x998
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2380, 0X998));
    // 0x808006B8: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808006BC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808006C0: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x808006C4: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x808006C8: sh          $t1, 0x6E($a1)
    MEM_H(0X6E, ctx->r5) = ctx->r9;
    // 0x808006CC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808006D0: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    // 0x808006D4: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
    // 0x808006D8: swc1        $f0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
    // 0x808006DC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808006E0: jal         0x800DA298
    // 0x808006E4: swc1        $f6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f6.u32l;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808006E4: swc1        $f6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f6.u32l;
    after_2:
    // 0x808006E8: beq         $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x808006EC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_808006F8;
    }
    // 0x808006EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808006F0: b           L_808006FC
    // 0x808006F4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
        goto L_808006FC;
    // 0x808006F4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_808006F8:
    // 0x808006F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_808006FC:
    // 0x808006FC: jal         0x800DA298
    // 0x80800700: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800700: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    after_3:
    // 0x80800704: beq         $v0, $zero, L_80800714
    if (ctx->r2 == 0) {
        // 0x80800708: addiu       $a0, $zero, 0x389
        ctx->r4 = ADD32(0, 0X389);
            goto L_80800714;
    }
    // 0x80800708: addiu       $a0, $zero, 0x389
    ctx->r4 = ADD32(0, 0X389);
    // 0x8080070C: b           L_80800718
    // 0x80800710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80800718;
    // 0x80800710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800714:
    // 0x80800714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80800718:
    // 0x80800718: jal         0x800DA298
    // 0x8080071C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x8080071C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80800720: beq         $v0, $zero, L_80800730
    if (ctx->r2 == 0) {
        // 0x80800724: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800730;
    }
    // 0x80800724: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800728: b           L_80800734
    // 0x8080072C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800734;
    // 0x8080072C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800730:
    // 0x80800730: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800734:
    // 0x80800734: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
    // 0x80800738: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8080073C: jal         0x800DA298
    // 0x80800740: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800740: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x80800744: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800748: beq         $v0, $zero, L_80800758
    if (ctx->r2 == 0) {
        // 0x8080074C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800758;
    }
    // 0x8080074C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800750: b           L_8080075C
    // 0x80800754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080075C;
    // 0x80800754: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800758:
    // 0x80800758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8080075C:
    // 0x8080075C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800760: addu        $t5, $a1, $v1
    ctx->r13 = ADD32(ctx->r5, ctx->r3);
    // 0x80800764: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x80800768: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8080076C: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80800770: bne         $at, $zero, L_80800798
    if (ctx->r1 != 0) {
        // 0x80800774: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_80800798;
    }
    // 0x80800774: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800778: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8080077C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800784: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800788: jal         0x80085708
    // 0x8080078C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x8080078C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_6:
    // 0x80800790: b           L_80800918
    // 0x80800794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800918;
    // 0x80800794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800798:
    // 0x80800798: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808007A4: jal         0x80085708
    // 0x808007A8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x808007A8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x808007AC: b           L_80800918
    // 0x808007B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800918;
    // 0x808007B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007B4:
    // 0x808007B4: b           L_80800918
    // 0x808007B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800918;
    // 0x808007B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007BC:
    // 0x808007BC: jal         0x801015D0
    // 0x808007C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_801015D0(rdram, ctx);
        goto after_8;
    // 0x808007C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x808007C4: jal         0x80088848
    // 0x808007C8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_9;
    // 0x808007C8: nop

    after_9:
    // 0x808007CC: beq         $v0, $zero, L_8080088C
    if (ctx->r2 == 0) {
        // 0x808007D0: nop
    
            goto L_8080088C;
    }
    // 0x808007D0: nop

    // 0x808007D4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x808007D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007DC: lbu         $t2, 0x79($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X79);
    // 0x808007E0: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x808007E4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x808007E8: beq         $t4, $zero, L_808007F8
    if (ctx->r12 == 0) {
        // 0x808007EC: nop
    
            goto L_808007F8;
    }
    // 0x808007EC: nop

    // 0x808007F0: b           L_808007F8
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808007F8;
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808007F8:
    // 0x808007F8: jal         0x800DF744
    // 0x808007FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x808007FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800800: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800808: lbu         $t6, 0x79($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X79);
    // 0x8080080C: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800810: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x80800814: beq         $t9, $zero, L_80800824
    if (ctx->r25 == 0) {
        // 0x80800818: nop
    
            goto L_80800824;
    }
    // 0x80800818: nop

    // 0x8080081C: b           L_80800824
    // 0x80800820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800824;
    // 0x80800820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800824:
    // 0x80800824: jal         0x800DF744
    // 0x80800828: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_11;
    // 0x80800828: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x8080082C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800834: lbu         $t0, 0x79($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X79);
    // 0x80800838: srl         $t1, $t0, 4
    ctx->r9 = S32(U32(ctx->r8) >> 4);
    // 0x8080083C: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x80800840: beq         $t2, $zero, L_80800850
    if (ctx->r10 == 0) {
        // 0x80800844: nop
    
            goto L_80800850;
    }
    // 0x80800844: nop

    // 0x80800848: b           L_80800850
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800850;
    // 0x8080084C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800850:
    // 0x80800850: jal         0x800DF744
    // 0x80800854: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_12;
    // 0x80800854: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x80800858: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800860: lbu         $t4, 0x79($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X79);
    // 0x80800864: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80800868: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x8080086C: beq         $t6, $zero, L_8080087C
    if (ctx->r14 == 0) {
        // 0x80800870: nop
    
            goto L_8080087C;
    }
    // 0x80800870: nop

    // 0x80800874: b           L_8080087C
    // 0x80800878: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080087C;
    // 0x80800878: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080087C:
    // 0x8080087C: jal         0x800DF744
    // 0x80800880: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_13;
    // 0x80800880: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_13:
    // 0x80800884: b           L_80800918
    // 0x80800888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800918;
    // 0x80800888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080088C:
    // 0x8080088C: jal         0x800DA298
    // 0x80800890: addiu       $a0, $zero, 0x389
    ctx->r4 = ADD32(0, 0X389);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800890: addiu       $a0, $zero, 0x389
    ctx->r4 = ADD32(0, 0X389);
    after_14:
    // 0x80800894: beql        $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x80800898: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808008A8;
    }
    goto skip_0;
    // 0x80800898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x8080089C: b           L_808008A8
    // 0x808008A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808008A8;
    // 0x808008A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808008A8:
    // 0x808008A8: jal         0x800DF744
    // 0x808008AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x808008AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x808008B0: jal         0x800DA298
    // 0x808008B4: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x808008B4: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    after_16:
    // 0x808008B8: beq         $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x808008BC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808008C8;
    }
    // 0x808008BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008C0: b           L_808008C8
    // 0x808008C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808008C8;
    // 0x808008C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808008C8:
    // 0x808008C8: jal         0x800DF744
    // 0x808008CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_17;
    // 0x808008CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_17:
    // 0x808008D0: jal         0x800DA298
    // 0x808008D4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_800DA298(rdram, ctx);
        goto after_18;
    // 0x808008D4: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_18:
    // 0x808008D8: beq         $v0, $zero, L_808008E8
    if (ctx->r2 == 0) {
        // 0x808008DC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808008E8;
    }
    // 0x808008DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008E0: b           L_808008E8
    // 0x808008E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808008E8;
    // 0x808008E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808008E8:
    // 0x808008E8: jal         0x800DF744
    // 0x808008EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x808008EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_19:
    // 0x808008F0: jal         0x800DA298
    // 0x808008F4: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
    func_800DA298(rdram, ctx);
        goto after_20;
    // 0x808008F4: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
    after_20:
    // 0x808008F8: beq         $v0, $zero, L_80800908
    if (ctx->r2 == 0) {
        // 0x808008FC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800908;
    }
    // 0x808008FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800900: b           L_80800908
    // 0x80800904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800908;
    // 0x80800904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800908:
    // 0x80800908: jal         0x800DF744
    // 0x8080090C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_21;
    // 0x8080090C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_21:
    // 0x80800910: b           L_80800918
    // 0x80800914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800918;
    // 0x80800914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800918:
    // 0x80800918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080091C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800920: jr          $ra
    // 0x80800924: nop

    return;
    // 0x80800924: nop

;}
RECOMP_FUNC void func_8001A4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A4B8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001A4BC: addiu       $v0, $v0, -0x4126
    ctx->r2 = ADD32(ctx->r2, -0X4126);
    // 0x8001A4C0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A4C4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001A4C8: addiu       $v1, $v1, -0x4318
    ctx->r3 = ADD32(ctx->r3, -0X4318);
    // 0x8001A4CC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8001A4D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001A4D4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8001A4D8: beq         $t9, $zero, L_8001A4F8
    if (ctx->r25 == 0) {
        // 0x8001A4DC: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_8001A4F8;
    }
    // 0x8001A4DC: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8001A4E0: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8001A4E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001A4E8: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8001A4EC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001A4F0: b           L_8001A510
    // 0x8001A4F4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
        goto L_8001A510;
    // 0x8001A4F4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_8001A4F8:
    // 0x8001A4F8: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8001A4FC: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001A500: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8001A504: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8001A508: lw          $t7, -0x4330($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4330);
    // 0x8001A50C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8001A510:
    // 0x8001A510: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A514: addiu       $v1, $v1, -0x4310
    ctx->r3 = ADD32(ctx->r3, -0X4310);
    // 0x8001A518: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001A51C: beql        $t6, $zero, L_8001A540
    if (ctx->r14 == 0) {
        // 0x8001A520: lh          $t2, 0x0($v0)
        ctx->r10 = MEM_H(ctx->r2, 0X0);
            goto L_8001A540;
    }
    goto skip_0;
    // 0x8001A520: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    skip_0:
    // 0x8001A524: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8001A528: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001A52C: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x8001A530: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8001A534: b           L_8001A554
    // 0x8001A538: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
        goto L_8001A554;
    // 0x8001A538: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8001A53C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
L_8001A540:
    // 0x8001A540: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8001A544: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001A548: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001A54C: lw          $t4, -0x4328($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4328);
    // 0x8001A550: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
L_8001A554:
    // 0x8001A554: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8001A558: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001A55C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8001A560: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A564: lw          $t6, -0x4320($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4320);
    // 0x8001A568: jr          $ra
    // 0x8001A56C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    return;
    // 0x8001A56C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800D8588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8588: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D858C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D8590: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D8594: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D8598: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D859C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D85A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D85A4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800D85A8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800D85AC: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800D85B0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800D85B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D85B8: jal         0x80105494
    // 0x800D85BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x800D85BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x800D85C0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D85C4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800D85C8: addiu       $s0, $s0, -0x4190
    ctx->r16 = ADD32(ctx->r16, -0X4190);
    // 0x800D85CC: sw          $zero, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = 0;
L_800D85D0:
    // 0x800D85D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D85D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800D85D8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D85DC: jal         0x800D8070
    // 0x800D85E0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_800D8070(rdram, ctx);
        goto after_1;
    // 0x800D85E0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x800D85E4: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x800D85E8: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x800D85EC: bnel        $t6, $zero, L_800D85D0
    if (ctx->r14 != 0) {
        // 0x800D85F0: sw          $zero, 0x18C($s0)
        MEM_W(0X18C, ctx->r16) = 0;
            goto L_800D85D0;
    }
    goto skip_0;
    // 0x800D85F0: sw          $zero, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = 0;
    skip_0:
    // 0x800D85F4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800D85F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D85FC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D8600: beq         $t8, $zero, L_800D8610
    if (ctx->r24 == 0) {
        // 0x800D8604: nop
    
            goto L_800D8610;
    }
    // 0x800D8604: nop

    // 0x800D8608: jal         0x80088468
    // 0x800D860C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _glsplinecs_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800D860C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
L_800D8610:
    // 0x800D8610: beq         $s1, $zero, L_800D8620
    if (ctx->r17 == 0) {
        // 0x800D8614: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_800D8620;
    }
    // 0x800D8614: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D8618: b           L_800D8624
    // 0x800D861C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D8624;
    // 0x800D861C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D8620:
    // 0x800D8620: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D8624:
    // 0x800D8624: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D8628: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D862C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D8630: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D8634: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800D8638: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800D863C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D8640: jr          $ra
    // 0x800D8644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D8644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _bafly_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C00: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C00);
    return;
    // 0x80084C04: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C28: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C28);
    return;
    // 0x80083C2C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
