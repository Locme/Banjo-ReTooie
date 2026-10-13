#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void mlMtxGet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018AD0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80018AD4: addiu       $v1, $v1, -0x4350
    ctx->r3 = ADD32(ctx->r3, -0X4350);
    // 0x80018AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018ADC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80018AE0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80018AE4: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80018AE8: beq         $v0, $a1, L_80018B4C
    if (ctx->r2 == ctx->r5) {
        // 0x80018AEC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80018B4C;
    }
    // 0x80018AEC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80018AF0:
    // 0x80018AF0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80018AF4: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80018AF8: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x80018AFC: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x80018B00: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80018B04: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80018B08: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80018B0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018B10: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80018B14: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80018B18: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80018B1C: swc1        $f18, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f18.u32l;
    // 0x80018B20: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80018B24: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80018B28: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80018B2C: swc1        $f18, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80018B30: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80018B34: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80018B38: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80018B3C: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80018B40: swc1        $f18, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80018B44: bne         $v0, $a1, L_80018AF0
    if (ctx->r2 != ctx->r5) {
        // 0x80018B48: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80018AF0;
    }
    // 0x80018B48: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80018B4C:
    // 0x80018B4C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80018B50: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80018B54: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x80018B58: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x80018B5C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80018B60: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80018B64: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80018B68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80018B6C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80018B70: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80018B74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018B78: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80018B7C: swc1        $f18, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f18.u32l;
    // 0x80018B80: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80018B84: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80018B88: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80018B8C: swc1        $f18, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80018B90: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80018B94: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80018B98: lwc1        $f18, 0xC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80018B9C: swc1        $f18, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80018BA0: jr          $ra
    // 0x80018BA4: nop

    return;
    // 0x80018BA4: nop

;}
RECOMP_FUNC void func_80800018_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080001C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800024: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800028: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800030: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800034: jal         0x80100094
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080003C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(792, 0X1590) << 16);
    // 0x80800040: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800044: addiu       $a1, $a1, 0x1590
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(792, 0X1590));
    // 0x80800048: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    // 0x8080004C: jal         0x800882C0
    // 0x80800050: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_1:
    // 0x80800054: sw          $v0, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r2;
    // 0x80800058: blez        $v0, L_80800090
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080005C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800090;
    }
    // 0x8080005C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800060: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(792, 0X1590) << 16);
    // 0x80800064: addiu       $s1, $s1, 0x1590
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(792, 0X1590));
    // 0x80800068: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
L_8080006C:
    // 0x8080006C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800070: jal         0x80088C00
    // 0x80800074: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800074: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80800078: lw          $t6, 0x30($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X30);
    // 0x8080007C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800080: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800084: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800088: bne         $at, $zero, L_8080006C
    if (ctx->r1 != 0) {
        // 0x8080008C: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_8080006C;
    }
    // 0x8080008C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_80800090:
    // 0x80800090: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800094: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080009C: jal         0x8008A2A0
    // 0x808000A0: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808000A0: addiu       $a1, $a1, 0x30C
    ctx->r5 = ADD32(ctx->r5, 0X30C);
    after_3:
    // 0x808000A4: jal         0x8008A2F8
    // 0x808000A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808000A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808000AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000C0: jr          $ra
    // 0x808000C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808000C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bainput_getStructSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097970: jr          $ra
    // 0x80097974: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80097974: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bswalk_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B54: jal         0x8080016C
    // 0x80800B58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8080016C_bswalk(rdram, ctx);
        goto after_0;
    // 0x80800B58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800B5C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800B60: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B68: jal         0x800A2CE8
    // 0x80800B6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x80800B6C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80800B70: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800B74: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x800A2CE8
    // 0x80800B80: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x80800B80: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800B84: jal         0x808001E4
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_bswalk(rdram, ctx);
        goto after_3;
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B8C: jal         0x80800000
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bswalk(rdram, ctx);
        goto after_4;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800B94: jal         0x8009EF10
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_5;
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800B9C: beq         $v0, $zero, L_80800BC4
    if (ctx->r2 == 0) {
        // 0x80800BA0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800BC4;
    }
    // 0x80800BA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BA4: beq         $v0, $at, L_80800BC4
    if (ctx->r2 == ctx->r1) {
        // 0x80800BA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800BC4;
    }
    // 0x80800BA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BAC: beq         $v0, $at, L_80800BC4
    if (ctx->r2 == ctx->r1) {
        // 0x80800BB0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800BC4;
    }
    // 0x80800BB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800BB4: beq         $v0, $at, L_80800BF0
    if (ctx->r2 == ctx->r1) {
        // 0x80800BB8: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_80800BF0;
    }
    // 0x80800BB8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80800BBC: b           L_80800BF4
    // 0x80800BC0: nop

        goto L_80800BF4;
    // 0x80800BC0: nop

L_80800BC4:
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: jal         0x8009BCD4
    // 0x80800BCC: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_6;
    // 0x80800BCC: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    after_6:
    // 0x80800BD0: beq         $v0, $zero, L_80800BF4
    if (ctx->r2 == 0) {
        // 0x80800BD4: nop
    
            goto L_80800BF4;
    }
    // 0x80800BD4: nop

    // 0x80800BD8: jal         0x80800220
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800220_bswalk(rdram, ctx);
        goto after_7;
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800BE0: beq         $v0, $zero, L_80800BF4
    if (ctx->r2 == 0) {
        // 0x80800BE4: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80800BF4;
    }
    // 0x80800BE4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800BE8: b           L_80800BF4
    // 0x80800BEC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800BF4;
    // 0x80800BEC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800BF0:
    // 0x80800BF0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800BF4:
    // 0x80800BF4: jal         0x8008DE24
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_8;
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800BFC: beq         $v0, $zero, L_80800C08
    if (ctx->r2 == 0) {
        // 0x80800C00: addiu       $t8, $zero, 0x7A
        ctx->r24 = ADD32(0, 0X7A);
            goto L_80800C08;
    }
    // 0x80800C00: addiu       $t8, $zero, 0x7A
    ctx->r24 = ADD32(0, 0X7A);
    // 0x80800C04: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800C08:
    // 0x80800C08: jal         0x8008E300
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E300(rdram, ctx);
        goto after_9;
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800C10: beq         $v0, $zero, L_80800C40
    if (ctx->r2 == 0) {
        // 0x80800C14: nop
    
            goto L_80800C40;
    }
    // 0x80800C14: nop

    // 0x80800C18: jal         0x8009BB5C
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_10;
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800C20: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80800C24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C28: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80800C2C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C30: nop

    // 0x80800C34: bc1f        L_80800C40
    if (!c1cs) {
        // 0x80800C38: nop
    
            goto L_80800C40;
    }
    // 0x80800C38: nop

    // 0x80800C3C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800C40:
    // 0x80800C40: jal         0x80097AD0
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_11;
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800C48: beq         $v0, $zero, L_80800C5C
    if (ctx->r2 == 0) {
        // 0x80800C4C: nop
    
            goto L_80800C5C;
    }
    // 0x80800C4C: nop

    // 0x80800C50: jal         0x800848A8
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_12;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800C58: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800C5C:
    // 0x80800C5C: jal         0x8008DD04
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_13;
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800C64: beq         $v0, $zero, L_80800C74
    if (ctx->r2 == 0) {
        // 0x80800C68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C74;
    }
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C6C: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x80800C70: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800C74:
    // 0x80800C74: jal         0x800919F4
    // 0x80800C78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_14;
    // 0x80800C78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800C7C: beq         $v0, $zero, L_80800C8C
    if (ctx->r2 == 0) {
        // 0x80800C80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C8C;
    }
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C84: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80800C88: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800C8C:
    // 0x80800C8C: jal         0x80800248
    // 0x80800C90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800248_bswalk(rdram, ctx);
        goto after_15;
    // 0x80800C90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80800C94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C9C: jal         0x80091A58
    // 0x80800CA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_16;
    // 0x80800CA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x80800CA4: beq         $v0, $zero, L_80800D10
    if (ctx->r2 == 0) {
        // 0x80800CA8: nop
    
            goto L_80800D10;
    }
    // 0x80800CA8: nop

    // 0x80800CAC: jal         0x8009FE84
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_17;
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800CB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800CB8: jal         0x8009BB00
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800CC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800CC4: nop

    // 0x80800CC8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800CCC: nop

    // 0x80800CD0: bc1f        L_80800D10
    if (!c1cs) {
        // 0x80800CD4: nop
    
            goto L_80800D10;
    }
    // 0x80800CD4: nop

    // 0x80800CD8: jal         0x8008D714
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D714(rdram, ctx);
        goto after_19;
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800CE0: beq         $v0, $zero, L_80800CF0
    if (ctx->r2 == 0) {
        // 0x80800CE4: addiu       $t2, $zero, 0xB8
        ctx->r10 = ADD32(0, 0XB8);
            goto L_80800CF0;
    }
    // 0x80800CE4: addiu       $t2, $zero, 0xB8
    ctx->r10 = ADD32(0, 0XB8);
    // 0x80800CE8: b           L_80800D10
    // 0x80800CEC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
        goto L_80800D10;
    // 0x80800CEC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80800CF0:
    // 0x80800CF0: jal         0x8008D790
    // 0x80800CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_20;
    // 0x80800CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800CF8: beq         $v0, $zero, L_80800D10
    if (ctx->r2 == 0) {
        // 0x80800CFC: nop
    
            goto L_80800D10;
    }
    // 0x80800CFC: nop

    // 0x80800D00: jal         0x80084978
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_21;
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800D08: b           L_80800D5C
    // 0x80800D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D5C;
    // 0x80800D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D10:
    // 0x80800D10: jal         0x8008E148
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_22;
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800D18: beq         $v0, $zero, L_80800D2C
    if (ctx->r2 == 0) {
        // 0x80800D1C: nop
    
            goto L_80800D2C;
    }
    // 0x80800D1C: nop

    // 0x80800D20: jal         0x800848B0
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_23;
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800D28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800D2C:
    // 0x80800D2C: jal         0x8008E35C
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_24;
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800D34: beq         $v0, $zero, L_80800D44
    if (ctx->r2 == 0) {
        // 0x80800D38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D44;
    }
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D3C: addiu       $t3, $zero, 0x2D
    ctx->r11 = ADD32(0, 0X2D);
    // 0x80800D40: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80800D44:
    // 0x80800D44: jal         0x800A02DC
    // 0x80800D48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A02DC(rdram, ctx);
        goto after_25;
    // 0x80800D48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_25:
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D50: jal         0x8009E5C8
    // 0x80800D54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_26;
    // 0x80800D54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_26:
    // 0x80800D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D5C:
    // 0x80800D5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800D64: jr          $ra
    // 0x80800D68: nop

    return;
    // 0x80800D68: nop

;}
RECOMP_FUNC void func_80800088_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800094: jal         0x80100094
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080009C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x808000A8: lhu         $v1, 0x72($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X72);
    // 0x808000AC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808000B0: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808000B4: beq         $t6, $at, L_808000CC
    if (ctx->r14 == ctx->r1) {
        // 0x808000B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000CC;
    }
    // 0x808000B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000BC: beq         $t6, $at, L_808000DC
    if (ctx->r14 == ctx->r1) {
        // 0x808000C0: nop
    
            goto L_808000DC;
    }
    // 0x808000C0: nop

    // 0x808000C4: b           L_808000E8
    // 0x808000C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000E8;
    // 0x808000C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000CC:
    // 0x808000CC: jal         0x808005BC
    // 0x808000D0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    func_808005BC_chclinker(rdram, ctx);
        goto after_1;
    // 0x808000D0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x808000D4: b           L_808000E8
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000E8;
    // 0x808000D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000DC:
    // 0x808000DC: jal         0x808000F4
    // 0x808000E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808000F4_chclinker(rdram, ctx);
        goto after_2;
    // 0x808000E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E8:
    // 0x808000E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void baswim_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002A4: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x808002A8: jr          $ra
    // 0x808002AC: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808002AC: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chpickups_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085850: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085850);
    return;
    // 0x80085854: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800C5C_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C68: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800C6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C70: jal         0x80102FDC
    // 0x80800C74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800C74: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x80800C78: jal         0x800CB3E0
    // 0x80800C7C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800CB3E0(rdram, ctx);
        goto after_1;
    // 0x80800C7C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80800C80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C84: beq         $v0, $at, L_80800CB8
    if (ctx->r2 == ctx->r1) {
        // 0x80800C88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CB8;
    }
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C90: beq         $v0, $at, L_80800CD0
    if (ctx->r2 == ctx->r1) {
        // 0x80800C94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CD0;
    }
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800C9C: beq         $v0, $at, L_80800CE4
    if (ctx->r2 == ctx->r1) {
        // 0x80800CA0: addiu       $a0, $zero, 0x13F
        ctx->r4 = ADD32(0, 0X13F);
            goto L_80800CE4;
    }
    // 0x80800CA0: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80800CA4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800CA8: beq         $v0, $at, L_80800D48
    if (ctx->r2 == ctx->r1) {
        // 0x80800CAC: addiu       $a0, $zero, 0x13F
        ctx->r4 = ADD32(0, 0X13F);
            goto L_80800D48;
    }
    // 0x80800CAC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80800CB0: b           L_80800D74
    // 0x80800CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D74;
    // 0x80800CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CB8:
    // 0x80800CB8: jal         0x80102424
    // 0x80800CBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800CBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800CC0: jal         0x8010A590
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_3;
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800CC8: b           L_80800D74
    // 0x80800CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D74;
    // 0x80800CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CD0:
    // 0x80800CD0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800CD4: jal         0x8008A548
    // 0x80800CD8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800CD8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_4:
    // 0x80800CDC: b           L_80800D74
    // 0x80800CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D74;
    // 0x80800CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CE4:
    // 0x80800CE4: jal         0x80089C30
    // 0x80800CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800CE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800CEC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800CF0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800CF4: jal         0x800EE7F8
    // 0x80800CF8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800CF8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_6:
    // 0x80800CFC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800D00: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800D04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D08: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80800D0C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800D10: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80800D14: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800D18: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800D1C: jal         0x800EF1B8
    // 0x80800D20: nop

    func_800EF1B8(rdram, ctx);
        goto after_7;
    // 0x80800D20: nop

    after_7:
    // 0x80800D24: jal         0x8010A570
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D30: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D34: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800D38: jal         0x8008A4F8
    // 0x80800D3C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _subaddietaxi_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800D3C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_9:
    // 0x80800D40: b           L_80800D74
    // 0x80800D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D74;
    // 0x80800D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D48:
    // 0x80800D48: jal         0x80089C30
    // 0x80800D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D54: jal         0x80102424
    // 0x80800D58: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800D58: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_11:
    // 0x80800D5C: jal         0x8010A570
    // 0x80800D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_12;
    // 0x80800D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D64: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D68: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800D6C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800D70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D74:
    // 0x80800D74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D7C: jr          $ra
    // 0x80800D80: nop

    return;
    // 0x80800D80: nop

;}
RECOMP_FUNC void func_80800D78_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800D88: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x80800D8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D94: beq         $v0, $at, L_80800DC0
    if (ctx->r2 == ctx->r1) {
        // 0x80800D98: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800DC0;
    }
    // 0x80800D98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D9C: beq         $v0, $at, L_80800E08
    if (ctx->r2 == ctx->r1) {
        // 0x80800DA0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800E08;
    }
    // 0x80800DA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DA4: beq         $v0, $at, L_80800DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800DA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DE0;
    }
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800DB0: beq         $v0, $at, L_80800DF8
    if (ctx->r2 == ctx->r1) {
        // 0x80800DB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DF8;
    }
    // 0x80800DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB8: b           L_80800E0C
    // 0x80800DBC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800E0C;
    // 0x80800DBC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800DC0:
    // 0x80800DC0: jal         0x8008E0E8
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_0;
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800DC8: bne         $v0, $zero, L_80800E08
    if (ctx->r2 != 0) {
        // 0x80800DCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E08;
    }
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD0: jal         0x80084788
    // 0x80800DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800DD8: b           L_80800E0C
    // 0x80800DDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800E0C;
    // 0x80800DDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800DE0:
    // 0x80800DE0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800DE4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800DE8: jal         0x800A0D14
    // 0x80800DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0D14(rdram, ctx);
        goto after_2;
    // 0x80800DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800DF0: b           L_80800E0C
    // 0x80800DF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800E0C;
    // 0x80800DF4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800DF8:
    // 0x80800DF8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800DFC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800E00: jal         0x800A0D14
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0D14(rdram, ctx);
        goto after_3;
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80800E08:
    // 0x80800E08: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800E0C:
    // 0x80800E0C: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
    // 0x80800E10: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800E14: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800E18: beq         $at, $zero, L_80800ECC
    if (ctx->r1 == 0) {
        // 0x80800E1C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800ECC;
    }
    // 0x80800E1C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800E20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(304, 0X1320) << 16);
    // 0x80800E24: addu        $at, $at, $t7
    gpr jr_addend_80800E2C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800E28: lw          $t7, 0x1320($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(304, 0X1320));
    // 0x80800E2C: jr          $t7
    // 0x80800E30: nop

    switch (jr_addend_80800E2C >> 2) {
        case 0: goto L_80800ECC; break;
        case 1: goto L_80800E34; break;
        case 2: goto L_80800E74; break;
        case 3: goto L_80800E8C; break;
        case 4: goto L_80800EB0; break;
        default: switch_error(__func__, 0x80800E2C, 0x80801320);
    }
    // 0x80800E30: nop

L_80800E34:
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E38: jal         0x800A0CF4
    // 0x80800E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x80800E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800E40: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800E44: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E4C: jal         0x8008CCBC
    // 0x80800E50: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_5;
    // 0x80800E50: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    after_5:
    // 0x80800E54: jal         0x8008E0E8
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_6;
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E5C: bne         $v0, $zero, L_80800ECC
    if (ctx->r2 != 0) {
        // 0x80800E60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ECC;
    }
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E64: jal         0x80084788
    // 0x80800E68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800E68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x80800E6C: b           L_80800ED0
    // 0x80800E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ED0;
    // 0x80800E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E74:
    // 0x80800E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E78: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x80800E7C: jal         0x8008CCBC
    // 0x80800E80: lui         $a2, 0x4090
    ctx->r6 = S32(0X4090 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_8;
    // 0x80800E80: lui         $a2, 0x4090
    ctx->r6 = S32(0X4090 << 16);
    after_8:
    // 0x80800E84: b           L_80800ED0
    // 0x80800E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ED0;
    // 0x80800E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E8C:
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E90: jal         0x800A0CF4
    // 0x80800E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_9;
    // 0x80800E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E9C: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x80800EA0: jal         0x8008CCBC
    // 0x80800EA4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_10;
    // 0x80800EA4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_10:
    // 0x80800EA8: b           L_80800ED0
    // 0x80800EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800ED0;
    // 0x80800EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EB0:
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB4: jal         0x800A0CF4
    // 0x80800EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_11;
    // 0x80800EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC0: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x80800EC4: jal         0x8008CCBC
    // 0x80800EC8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_12;
    // 0x80800EC8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_12:
L_80800ECC:
    // 0x80800ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800ED0:
    // 0x80800ED0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800ED8: jr          $ra
    // 0x80800EDC: nop

    return;
    // 0x80800EDC: nop

;}
RECOMP_FUNC void func_800C9C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9C34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9C38: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C9C3C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9C40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C9C44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9C48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9C4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800C9C50: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C9C54: addiu       $a1, $a1, -0x666C
    ctx->r5 = ADD32(ctx->r5, -0X666C);
    // 0x800C9C58: jal         0x800C9E64
    // 0x800C9C5C: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    func_800C9E64(rdram, ctx);
        goto after_0;
    // 0x800C9C5C: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9C64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C9C68: jr          $ra
    // 0x800C9C6C: nop

    return;
    // 0x800C9C6C: nop

;}
RECOMP_FUNC void func_80802120_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802120: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802128: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080212C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802130: jal         0x80100094
    // 0x80802134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802138: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X44D0) << 16);
    // 0x8080213C: lwc1        $f4, 0x44D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X44D0));
    // 0x80802140: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80802144: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80802148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080214C: jal         0x800D0A9C
    // 0x80802150: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80802150: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80802154: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80802158: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8080215C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80802160: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80802164: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80802168: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080216C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80802170: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80802174: sb          $zero, 0x8F4($v1)
    MEM_B(0X8F4, ctx->r3) = 0;
    // 0x80802178: jal         0x80088848
    // 0x8080217C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x8080217C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    after_2:
    // 0x80802180: beq         $v0, $zero, L_808021AC
    if (ctx->r2 == 0) {
        // 0x80802184: nop
    
            goto L_808021AC;
    }
    // 0x80802184: nop

    // 0x80802188: jal         0x800EA05C
    // 0x8080218C: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x8080218C: nop

    after_3:
    // 0x80802190: addiu       $at, $zero, 0xC7
    ctx->r1 = ADD32(0, 0XC7);
    // 0x80802194: bne         $v0, $at, L_80802380
    if (ctx->r2 != ctx->r1) {
        // 0x80802198: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802380;
    }
    // 0x80802198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080219C: jal         0x80108B04
    // 0x808021A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x808021A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808021A4: b           L_80802384
    // 0x808021A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802384;
    // 0x808021A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808021AC:
    // 0x808021AC: jal         0x800DA298
    // 0x808021B0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808021B0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_5:
    // 0x808021B4: beq         $v0, $zero, L_808021CC
    if (ctx->r2 == 0) {
        // 0x808021B8: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_808021CC;
    }
    // 0x808021B8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808021BC: jal         0x800D0A9C
    // 0x808021C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_6;
    // 0x808021C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808021C4: beq         $v0, $zero, L_808021E8
    if (ctx->r2 == 0) {
        // 0x808021C8: nop
    
            goto L_808021E8;
    }
    // 0x808021C8: nop

L_808021CC:
    // 0x808021CC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x808021D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808021D4: addiu       $a1, $zero, 0x68B
    ctx->r5 = ADD32(0, 0X68B);
    // 0x808021D8: jal         0x80103140
    // 0x808021DC: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    func_80103140(rdram, ctx);
        goto after_7;
    // 0x808021DC: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    after_7:
    // 0x808021E0: b           L_80802384
    // 0x808021E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802384;
    // 0x808021E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808021E8:
    // 0x808021E8: jal         0x80800000
    // 0x808021EC: nop

    func_80800000_chhandcart(rdram, ctx);
        goto after_8;
    // 0x808021EC: nop

    after_8:
    // 0x808021F0: beq         $v0, $zero, L_80802210
    if (ctx->r2 == 0) {
        // 0x808021F4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80802210;
    }
    // 0x808021F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808021F8: beq         $v0, $at, L_80802254
    if (ctx->r2 == ctx->r1) {
        // 0x808021FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802254;
    }
    // 0x808021FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802200: beql        $v0, $at, L_808022F0
    if (ctx->r2 == ctx->r1) {
        // 0x80802204: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_808022F0;
    }
    goto skip_0;
    // 0x80802204: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80802208: b           L_80802378
    // 0x8080220C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802378;
    // 0x8080220C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802210:
    // 0x80802210: jal         0x800DA298
    // 0x80802214: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80802214: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    after_9:
    // 0x80802218: bne         $v0, $zero, L_80802230
    if (ctx->r2 != 0) {
        // 0x8080221C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802230;
    }
    // 0x8080221C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802220: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80802224: addiu       $a1, $zero, 0x68B
    ctx->r5 = ADD32(0, 0X68B);
    // 0x80802228: jal         0x80103140
    // 0x8080222C: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    func_80103140(rdram, ctx);
        goto after_10;
    // 0x8080222C: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    after_10:
L_80802230:
    // 0x80802230: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80802234: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080223C: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x80802240: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80802244: jal         0x80802068
    // 0x80802248: subu        $a1, $t7, $t6
    ctx->r5 = SUB32(ctx->r15, ctx->r14);
    func_80802068_chhandcart(rdram, ctx);
        goto after_11;
    // 0x80802248: subu        $a1, $t7, $t6
    ctx->r5 = SUB32(ctx->r15, ctx->r14);
    after_11:
    // 0x8080224C: b           L_80802378
    // 0x80802250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802378;
    // 0x80802250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802254:
    // 0x80802254: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80802258: addiu       $a0, $zero, 0x313
    ctx->r4 = ADD32(0, 0X313);
    // 0x8080225C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802260: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x80802264: bgez        $t0, L_80802298
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80802268: nop
    
            goto L_80802298;
    }
    // 0x80802268: nop

    // 0x8080226C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802270: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802274: jal         0x80088480
    // 0x80802278: addiu       $a0, $zero, 0x314
    ctx->r4 = ADD32(0, 0X314);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80802278: addiu       $a0, $zero, 0x314
    ctx->r4 = ADD32(0, 0X314);
    after_12:
    // 0x8080227C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80802280: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80802284: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80802288: jal         0x80088280
    // 0x8080228C: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x8080228C: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_13:
    // 0x80802290: b           L_808022B8
    // 0x80802294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_808022B8;
    // 0x80802294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80802298:
    // 0x80802298: jal         0x80088480
    // 0x8080229C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080229C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_14:
    // 0x808022A0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x808022A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808022A8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x808022AC: jal         0x80088280
    // 0x808022B0: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x808022B0: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
    after_15:
    // 0x808022B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808022B8:
    // 0x808022B8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x808022BC: jal         0x800EE88C
    // 0x808022C0: addiu       $a0, $v0, 0x928
    ctx->r4 = ADD32(ctx->r2, 0X928);
    func_800EE88C(rdram, ctx);
        goto after_16;
    // 0x808022C0: addiu       $a0, $v0, 0x928
    ctx->r4 = ADD32(ctx->r2, 0X928);
    after_16:
    // 0x808022C4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x808022C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022CC: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x808022D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808022D4: jal         0x801058C4
    // 0x808022D8: lh          $a1, 0x0($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X0);
    func_801058C4(rdram, ctx);
        goto after_17;
    // 0x808022D8: lh          $a1, 0x0($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X0);
    after_17:
    // 0x808022DC: jal         0x80801BA4
    // 0x808022E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801BA4_chhandcart(rdram, ctx);
        goto after_18;
    // 0x808022E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808022E4: b           L_80802378
    // 0x808022E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802378;
    // 0x808022E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022EC: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_808022F0:
    // 0x808022F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808022F4: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    // 0x808022F8: sll         $t7, $t4, 12
    ctx->r15 = S32(ctx->r12 << 12);
    // 0x808022FC: bgez        $t7, L_80802314
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80802300: nop
    
            goto L_80802314;
    }
    // 0x80802300: nop

    // 0x80802304: jal         0x80088278
    // 0x80802308: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x80802308: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    after_19:
    // 0x8080230C: b           L_80802320
    // 0x80802310: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80802320;
    // 0x80802310: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80802314:
    // 0x80802314: jal         0x80088278
    // 0x80802318: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80802318: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_20:
    // 0x8080231C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80802320:
    // 0x80802320: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802324: jal         0x800EE88C
    // 0x80802328: addiu       $a0, $a0, 0x90C
    ctx->r4 = ADD32(ctx->r4, 0X90C);
    func_800EE88C(rdram, ctx);
        goto after_21;
    // 0x80802328: addiu       $a0, $a0, 0x90C
    ctx->r4 = ADD32(ctx->r4, 0X90C);
    after_21:
    // 0x8080232C: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80802330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802334: sll         $t6, $a1, 12
    ctx->r14 = S32(ctx->r5 << 12);
    // 0x80802338: jal         0x80802068
    // 0x8080233C: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
    func_80802068_chhandcart(rdram, ctx);
        goto after_22;
    // 0x8080233C: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
    after_22:
    // 0x80802340: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80802344: sll         $t1, $t8, 12
    ctx->r9 = S32(ctx->r24 << 12);
    // 0x80802348: bgezl       $t1, L_80802378
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080234C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802378;
    }
    goto skip_1;
    // 0x8080234C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80802350: jal         0x80800090
    // 0x80802354: nop

    func_80800090_chhandcart(rdram, ctx);
        goto after_23;
    // 0x80802354: nop

    after_23:
    // 0x80802358: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080235C: bne         $v0, $at, L_80802374
    if (ctx->r2 != ctx->r1) {
        // 0x80802360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802374;
    }
    // 0x80802360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802364: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80802368: addiu       $a1, $zero, 0x68B
    ctx->r5 = ADD32(0, 0X68B);
    // 0x8080236C: jal         0x80103140
    // 0x80802370: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    func_80103140(rdram, ctx);
        goto after_24;
    // 0x80802370: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    after_24:
L_80802374:
    // 0x80802374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802378:
    // 0x80802378: jal         0x80108B04
    // 0x8080237C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_25;
    // 0x8080237C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
L_80802380:
    // 0x80802380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802384:
    // 0x80802384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802388: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080238C: jr          $ra
    // 0x80802390: nop

    return;
    // 0x80802390: nop

;}
RECOMP_FUNC void func_80800988_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800988: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080098C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800990: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800994: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800998: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8080099C: addiu       $t6, $zero, 0x184A
    ctx->r14 = ADD32(0, 0X184A);
    // 0x808009A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808009A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009AC: addiu       $a2, $a2, 0x6A38
    ctx->r6 = ADD32(ctx->r6, 0X6A38);
    // 0x808009B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009B4: jal         0x80087CB8
    // 0x808009B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808009B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x808009BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009C0: jal         0x80100094
    // 0x808009C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808009C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808009C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009D0: jal         0x80087CD8
    // 0x808009D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808009D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: jal         0x80087CE0
    // 0x808009E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808009E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: jal         0x80087CE8
    // 0x808009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808009F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808009F8: jal         0x808008E4
    // 0x808009FC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_808008E4_chmole_training(rdram, ctx);
        goto after_5;
    // 0x808009FC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800A00: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800A04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800A14: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800A18: jal         0x80087D08
    // 0x80800A1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x80800A1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800A20: jal         0x80087CF0
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A2C: jal         0x80101FDC
    // 0x80800A30: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800A30: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x80800A34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A40: jr          $ra
    // 0x80800A44: nop

    return;
    // 0x80800A44: nop

;}
RECOMP_FUNC void idbounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808002E0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x808002E4: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x808002E8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x808002EC: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x808002F0: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x808002F4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x808002F8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x808002FC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80800300: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80800304: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80800308: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8080030C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800310: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800314: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800318: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8080031C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800320: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800324: addu        $s5, $t6, $a2
    ctx->r21 = ADD32(ctx->r14, ctx->r6);
    // 0x80800328: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8080032C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800330: sltu        $at, $a2, $s5
    ctx->r1 = ctx->r6 < ctx->r21 ? 1 : 0;
    // 0x80800334: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800338: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8080033C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80800340: lwc1        $f26, 0x20($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800344: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800348: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x8080034C: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800350: lwc1        $f30, 0x60($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800354: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80800358: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8080035C: beq         $at, $zero, L_8080052C
    if (ctx->r1 == 0) {
        // 0x80800360: lwc1        $f28, 0x1C($s0)
        ctx->f28.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_8080052C;
    }
    // 0x80800360: lwc1        $f28, 0x1C($s0)
    ctx->f28.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800364: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800368: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8080036C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800370: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800374: addiu       $s2, $s2, 0x5480
    ctx->r18 = ADD32(ctx->r18, 0X5480);
L_80800378:
    // 0x80800378: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x8080037C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80800380: beql        $t7, $zero, L_8080041C
    if (ctx->r15 == 0) {
        // 0x80800384: lh          $t0, 0x2($s3)
        ctx->r8 = MEM_H(ctx->r19, 0X2);
            goto L_8080041C;
    }
    goto skip_0;
    // 0x80800384: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    skip_0:
    // 0x80800388: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x8080038C: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x80800390: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800394: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800398: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8080039C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808003A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808003A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808003A8: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808003AC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x808003B0: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x808003B4: nop

    // 0x808003B8: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x808003BC: jal         0x8002DCA0
    // 0x808003C0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x808003C0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x808003C4: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808003C8: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x808003CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808003D0: nop

    // 0x808003D4: bc1fl       L_808003E8
    if (!c1cs) {
        // 0x808003D8: lwc1        $f4, 0x38($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
            goto L_808003E8;
    }
    goto skip_1;
    // 0x808003D8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x808003DC: b           L_80800418
    // 0x808003E0: sub.s       $f20, $f22, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f26.fl;
        goto L_80800418;
    // 0x808003E0: sub.s       $f20, $f22, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x808003E4: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
L_808003E8:
    // 0x808003E8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003EC: nop

    // 0x808003F0: bc1fl       L_8080041C
    if (!c1cs) {
        // 0x808003F4: lh          $t0, 0x2($s3)
        ctx->r8 = MEM_H(ctx->r19, 0X2);
            goto L_8080041C;
    }
    goto skip_2;
    // 0x808003F4: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
    skip_2:
    // 0x808003F8: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808003FC: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80800400: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800404: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800408: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080040C: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80800410: mul.s       $f4, $f26, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f18.fl);
    // 0x80800414: sub.s       $f20, $f22, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f4.fl;
L_80800418:
    // 0x80800418: lh          $t0, 0x2($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X2);
L_8080041C:
    // 0x8080041C: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x80800420: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80800424: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800428: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8080042C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800430: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800434: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800438: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080043C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80800440: nop

    // 0x80800444: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800448: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8080044C: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x80800450: mul.s       $f8, $f20, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80800454: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800458: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8080045C: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80800460: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x80800464: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80800468: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8080046C: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x80800470: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800474: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80800478: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080047C: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80800480: nop

    // 0x80800484: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
    // 0x80800488: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x8080048C: beq         $t7, $zero, L_808004FC
    if (ctx->r15 == 0) {
        // 0x80800490: nop
    
            goto L_808004FC;
    }
    // 0x80800490: nop

    // 0x80800494: lbu         $v0, 0x2($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X2);
    // 0x80800498: bnel        $v0, $zero, L_80800500
    if (ctx->r2 != 0) {
        // 0x8080049C: lh          $t9, 0x2($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X2);
            goto L_80800500;
    }
    goto skip_3;
    // 0x8080049C: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    skip_3:
    // 0x808004A0: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808004A4: c.lt.s      $f30, $f18
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f30.fl < ctx->f18.fl;
    // 0x808004A8: nop

    // 0x808004AC: bc1fl       L_80800500
    if (!c1cs) {
        // 0x808004B0: lh          $t9, 0x2($s1)
        ctx->r25 = MEM_H(ctx->r17, 0X2);
            goto L_80800500;
    }
    goto skip_4;
    // 0x808004B0: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    skip_4:
    // 0x808004B4: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x808004B8: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x808004BC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x808004C0: nop

    // 0x808004C4: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808004C8: bne         $v0, $zero, L_808004FC
    if (ctx->r2 != 0) {
        // 0x808004CC: div.s       $f20, $f0, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
            goto L_808004FC;
    }
    // 0x808004CC: div.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808004D0: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x808004D4: nop

    // 0x808004D8: bc1f        L_808004E4
    if (!c1cs) {
        // 0x808004DC: nop
    
            goto L_808004E4;
    }
    // 0x808004DC: nop

    // 0x808004E0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_808004E4:
    // 0x808004E4: jal         0x800F54E4
    // 0x808004E8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808004E8: nop

    after_1:
    // 0x808004EC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808004F0: jal         0x800F83E4
    // 0x808004F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F83E4(rdram, ctx);
        goto after_2;
    // 0x808004F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808004F8: sb          $s4, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r20;
L_808004FC:
    // 0x808004FC: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
L_80800500:
    // 0x80800500: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x80800504: bgezl       $t9, L_80800514
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800508: lw          $t0, 0x28($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X28);
            goto L_80800514;
    }
    goto skip_5;
    // 0x80800508: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    skip_5:
    // 0x8080050C: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80800510: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
L_80800514:
    // 0x80800514: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80800518: sltu        $at, $s1, $s5
    ctx->r1 = ctx->r17 < ctx->r21 ? 1 : 0;
    // 0x8080051C: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x80800520: bne         $at, $zero, L_80800378
    if (ctx->r1 != 0) {
        // 0x80800524: sw          $t1, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r9;
            goto L_80800378;
    }
    // 0x80800524: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x80800528: swc1        $f30, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f30.u32l;
L_8080052C:
    // 0x8080052C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800530: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800534: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800538: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8080053C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800540: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80800544: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80800548: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8080054C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80800550: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80800554: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80800558: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8080055C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80800560: jr          $ra
    // 0x80800564: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800564: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void chbilldrillboulder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1908, 0X540) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x540
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X540));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x540
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1908, 0X540));
;}
RECOMP_FUNC void _chdiggerboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867C8: syscall     377
    recomp_syscall_handler(rdram, ctx, 0x800867C8);
    return;
    // 0x800867CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chwaspstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080050C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800514: jal         0x80106790
    // 0x80800518: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800518: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080051C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800520: jal         0x80800134
    // 0x80800524: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800134_chwaspstatue(rdram, ctx);
        goto after_1;
    // 0x80800524: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080052C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800530: jr          $ra
    // 0x80800534: nop

    return;
    // 0x80800534: nop

;}
RECOMP_FUNC void func_80801130_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801130: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801134: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801138: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8080113C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80801140: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80801144: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80801148: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080114C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80801150: jal         0x800E3980
    // 0x80801154: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80801154: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x80801158: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080115C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801160: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801164: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801168: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080116C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801170: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80801174: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80801178: bc1f        L_80801188
    if (!c1cs) {
        // 0x8080117C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80801188;
    }
    // 0x8080117C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801180: b           L_8080118C
    // 0x80801184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080118C;
    // 0x80801184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801188:
    // 0x80801188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080118C:
    // 0x8080118C: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801190: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80801194: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80801198: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2304, 0X21BC) << 16);
    // 0x8080119C: addiu       $t8, $t8, 0x21BC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2304, 0X21BC));
    // 0x808011A0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x808011A4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2304, 0X221C) << 16);
    // 0x808011A8: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2304, 0X2228) << 16);
    // 0x808011AC: addiu       $t0, $t0, 0x2228
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2304, 0X2228));
    // 0x808011B0: addiu       $t7, $t7, 0x221C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2304, 0X221C));
    // 0x808011B4: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x808011B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808011BC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x808011C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808011C4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x808011C8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808011CC: jal         0x80089870
    // 0x808011D0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808011D0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x808011D4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2304, 0X21D4) << 16);
    // 0x808011D8: addiu       $t3, $t3, 0x21D4
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2304, 0X21D4));
    // 0x808011DC: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2304, 0X221C) << 16);
    // 0x808011E0: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2304, 0X2228) << 16);
    // 0x808011E4: addiu       $t5, $t5, 0x2228
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2304, 0X2228));
    // 0x808011E8: addiu       $t2, $t2, 0x221C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2304, 0X221C));
    // 0x808011EC: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x808011F0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808011F4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x808011F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808011FC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80801200: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80801204: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80801208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080120C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80801210: jal         0x80089870
    // 0x80801214: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80801214: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_2:
    // 0x80801218: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2304, 0X21EC) << 16);
    // 0x8080121C: addiu       $t8, $t8, 0x21EC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2304, 0X21EC));
    // 0x80801220: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2304, 0X221C) << 16);
    // 0x80801224: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2304, 0X2234) << 16);
    // 0x80801228: addiu       $t0, $t0, 0x2234
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2304, 0X2234));
    // 0x8080122C: addiu       $t7, $t7, 0x221C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2304, 0X221C));
    // 0x80801230: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80801234: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801238: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8080123C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801240: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80801244: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801248: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8080124C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801250: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80801254: jal         0x80089870
    // 0x80801258: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80801258: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_3:
    // 0x8080125C: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2304, 0X2204) << 16);
    // 0x80801260: addiu       $t3, $t3, 0x2204
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2304, 0X2204));
    // 0x80801264: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2304, 0X221C) << 16);
    // 0x80801268: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2304, 0X2234) << 16);
    // 0x8080126C: addiu       $t5, $t5, 0x2234
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2304, 0X2234));
    // 0x80801270: addiu       $t2, $t2, 0x221C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2304, 0X221C));
    // 0x80801274: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80801278: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080127C: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x80801280: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801284: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80801288: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8080128C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80801290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801294: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80801298: jal         0x80089870
    // 0x8080129C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    _sumumbofx_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8080129C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_4:
    // 0x808012A0: jal         0x800898B0
    // 0x808012A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x808012A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x808012A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808012AC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808012B0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x808012B4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x808012B8: jr          $ra
    // 0x808012BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808012BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bsclimb_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082ED8: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082ED8);
    return;
    // 0x80082EDC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80802760_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802768: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8080276C: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x80802770: bgez        $t7, L_80802788
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80802774: nop
    
            goto L_80802788;
    }
    // 0x80802774: nop

    // 0x80802778: jal         0x800F54E4
    // 0x8080277C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080277C: nop

    after_0:
    // 0x80802780: b           L_8080279C
    // 0x80802784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080279C;
    // 0x80802784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802788:
    // 0x80802788: jal         0x8008A240
    // 0x8080278C: srl         $a0, $v0, 28
    ctx->r4 = S32(U32(ctx->r2) >> 28);
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080278C: srl         $a0, $v0, 28
    ctx->r4 = S32(U32(ctx->r2) >> 28);
    after_1:
    // 0x80802790: jal         0x8010D290
    // 0x80802794: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    func_8010D290(rdram, ctx);
        goto after_2;
    // 0x80802794: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    after_2:
    // 0x80802798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080279C:
    // 0x8080279C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808027A0: jr          $ra
    // 0x808027A4: nop

    return;
    // 0x808027A4: nop

    // 0x808027A8: nop

    // 0x808027AC: nop

;}
RECOMP_FUNC void boot___osPiRelAccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void chconga_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(948, 0X6A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x6A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(948, 0X6A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x6A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(948, 0X6A0));
;}
RECOMP_FUNC void _badrone_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084810: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084810);
    return;
    // 0x80084814: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bafly_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C70: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C70);
    return;
    // 0x80084C74: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void _chbeehive_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B60: syscall     423
    recomp_syscall_handler(rdram, ctx, 0x80086B60);
    return;
    // 0x80086B64: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8009F678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F678: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009F67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F680: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8009F684: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8009F688: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009F68C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8009F690: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8009F694: jal         0x800A30B4
    // 0x8009F698: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800A30B4(rdram, ctx);
        goto after_0;
    // 0x8009F698: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8009F69C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8009F6A0: jal         0x800F4200
    // 0x8009F6A4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F4200(rdram, ctx);
        goto after_1;
    // 0x8009F6A4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x8009F6A8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8009F6AC: jal         0x800EF04C
    // 0x8009F6B0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x8009F6B0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x8009F6B4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8009F6B8: jal         0x800EF04C
    // 0x8009F6BC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x8009F6BC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x8009F6C0: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x8009F6C4: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009F6C8: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x8009F6CC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009F6D0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009F6D4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8009F6D8: nop

    // 0x8009F6DC: bc1t        L_8009F6F8
    if (c1cs) {
        // 0x8009F6E0: nop
    
            goto L_8009F6F8;
    }
    // 0x8009F6E0: nop

    // 0x8009F6E4: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8009F6E8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8009F6EC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8009F6F0: bc1fl       L_8009F704
    if (!c1cs) {
        // 0x8009F6F4: lwc1        $f6, 0x0($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8009F704;
    }
    goto skip_0;
    // 0x8009F6F4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
L_8009F6F8:
    // 0x8009F6F8: b           L_8009F850
    // 0x8009F6FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F850;
    // 0x8009F6FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F700: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
L_8009F704:
    // 0x8009F704: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F708: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8009F70C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009F710: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009F714: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8009F718: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8009F71C: bc1t        L_8009F734
    if (c1cs) {
        // 0x8009F720: nop
    
            goto L_8009F734;
    }
    // 0x8009F720: nop

    // 0x8009F724: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8009F728: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009F72C: bc1fl       L_8009F740
    if (!c1cs) {
        // 0x8009F730: neg.s       $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
            goto L_8009F740;
    }
    goto skip_1;
    // 0x8009F730: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    skip_1:
L_8009F734:
    // 0x8009F734: b           L_8009F850
    // 0x8009F738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F850;
    // 0x8009F738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F73C: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
L_8009F740:
    // 0x8009F740: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8009F744: nop

    // 0x8009F748: bc1fl       L_8009F75C
    if (!c1cs) {
        // 0x8009F74C: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_8009F75C;
    }
    goto skip_2;
    // 0x8009F74C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x8009F750: b           L_8009F75C
    // 0x8009F754: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8009F75C;
    // 0x8009F754: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8009F758: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_8009F75C:
    // 0x8009F75C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009F760: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009F764: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8009F768: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009F76C: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8009F770: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8009F774: nop

    // 0x8009F778: bc1t        L_8009F790
    if (c1cs) {
        // 0x8009F77C: nop
    
            goto L_8009F790;
    }
    // 0x8009F77C: nop

    // 0x8009F780: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8009F784: nop

    // 0x8009F788: bc1fl       L_8009F79C
    if (!c1cs) {
        // 0x8009F78C: neg.s       $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
            goto L_8009F79C;
    }
    goto skip_3;
    // 0x8009F78C: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    skip_3:
L_8009F790:
    // 0x8009F790: b           L_8009F850
    // 0x8009F794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F850;
    // 0x8009F794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009F798: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
L_8009F79C:
    // 0x8009F79C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8009F7A0: nop

    // 0x8009F7A4: bc1fl       L_8009F7B8
    if (!c1cs) {
        // 0x8009F7A8: swc1        $f2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
            goto L_8009F7B8;
    }
    goto skip_4;
    // 0x8009F7A8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    skip_4:
    // 0x8009F7AC: b           L_8009F7B8
    // 0x8009F7B0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_8009F7B8;
    // 0x8009F7B0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8009F7B4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
L_8009F7B8:
    // 0x8009F7B8: jal         0x800D8FF8
    // 0x8009F7BC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x8009F7BC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x8009F7C0: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8009F7C4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009F7C8: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009F7CC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8009F7D0: jal         0x800F1660
    // 0x8009F7D4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800F1660(rdram, ctx);
        goto after_5;
    // 0x8009F7D4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8009F7D8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009F7DC: beq         $v0, $zero, L_8009F810
    if (ctx->r2 == 0) {
        // 0x8009F7E0: lwc1        $f14, 0x24($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8009F810;
    }
    // 0x8009F7E0: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009F7E4: jal         0x800F0DC0
    // 0x8009F7E8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    func_800F0DC0(rdram, ctx);
        goto after_6;
    // 0x8009F7E8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x8009F7EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F7F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009F7F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8009F7F8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8009F7FC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8009F800: jal         0x800EFA4C
    // 0x8009F804: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x8009F804: nop

    after_7:
    // 0x8009F808: b           L_8009F838
    // 0x8009F80C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
        goto L_8009F838;
    // 0x8009F80C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
L_8009F810:
    // 0x8009F810: jal         0x800F0DC0
    // 0x8009F814: nop

    func_800F0DC0(rdram, ctx);
        goto after_8;
    // 0x8009F814: nop

    after_8:
    // 0x8009F818: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F81C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009F820: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8009F824: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8009F828: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8009F82C: jal         0x800EFA4C
    // 0x8009F830: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x8009F830: nop

    after_9:
    // 0x8009F834: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
L_8009F838:
    // 0x8009F838: jal         0x800EF04C
    // 0x8009F83C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x8009F83C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x8009F840: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8009F844: jal         0x800F4648
    // 0x8009F848: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F4648(rdram, ctx);
        goto after_11;
    // 0x8009F848: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_11:
    // 0x8009F84C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009F850:
    // 0x8009F850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F854: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8009F858: jr          $ra
    // 0x8009F85C: nop

    return;
    // 0x8009F85C: nop

;}
RECOMP_FUNC void _badata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084668: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084668);
    return;
    // 0x8008466C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _baeggcursor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AC0: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AC0);
    return;
    // 0x80084AC4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808006A8_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B0: jal         0x800A587C
    // 0x808006B4: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x808006B4: nop

    after_0:
    // 0x808006B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808006BC: beq         $v0, $at, L_808006DC
    if (ctx->r2 == ctx->r1) {
        // 0x808006C0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808006DC;
    }
    // 0x808006C0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808006C4: beq         $v0, $at, L_808006EC
    if (ctx->r2 == ctx->r1) {
        // 0x808006C8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808006EC;
    }
    // 0x808006C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808006CC: beq         $v0, $at, L_808006FC
    if (ctx->r2 == ctx->r1) {
        // 0x808006D0: nop
    
            goto L_808006FC;
    }
    // 0x808006D0: nop

    // 0x808006D4: b           L_8080070C
    // 0x808006D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080070C;
    // 0x808006D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006DC:
    // 0x808006DC: jal         0x800A586C
    // 0x808006E0: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x808006E0: nop

    after_1:
    // 0x808006E4: b           L_8080070C
    // 0x808006E8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
        goto L_8080070C;
    // 0x808006E8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_808006EC:
    // 0x808006EC: jal         0x800A586C
    // 0x808006F0: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x808006F0: nop

    after_2:
    // 0x808006F4: b           L_8080070C
    // 0x808006F8: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
        goto L_8080070C;
    // 0x808006F8: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_808006FC:
    // 0x808006FC: jal         0x800A586C
    // 0x80800700: nop

    func_800A586C(rdram, ctx);
        goto after_3;
    // 0x80800700: nop

    after_3:
    // 0x80800704: b           L_8080070C
    // 0x80800708: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
        goto L_8080070C;
    // 0x80800708: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_8080070C:
    // 0x8080070C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800714: jr          $ra
    // 0x80800718: nop

    return;
    // 0x80800718: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A10: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A14: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B28) << 16);
    // 0x80800A18: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: lw          $v0, 0x1B28($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B28));
    return;
    // 0x80800A20: lw          $v0, 0x1B28($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B28));
;}
RECOMP_FUNC void func_800C68A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C68A4: jr          $ra
    // 0x800C68A8: swc1        $f12, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800C68A8: swc1        $f12, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800830_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800838: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080083C: lui         $a1, 0xC1C8
    ctx->r5 = S32(0XC1C8 << 16);
    // 0x80800840: jal         0x8008FB58
    // 0x80800844: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_8008FB58(rdram, ctx);
        goto after_0;
    // 0x80800844: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80800848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080084C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800850: jr          $ra
    // 0x80800854: nop

    return;
    // 0x80800854: nop

;}
RECOMP_FUNC void fxkern_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080035C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800360: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800364: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800368: jal         0x80800084
    // 0x8080036C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800084_fxkern(rdram, ctx);
        goto after_0;
    // 0x8080036C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800370: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x80800374: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800378: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2854, 0X488) << 16);
    // 0x8080037C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800380: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800384: lwc1        $f6, 0x488($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2854, 0X488));
    // 0x80800388: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080038C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800390: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800398: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8080039C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808003A0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808003A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808003A8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808003AC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808003B0: jal         0x80800224
    // 0x808003B4: nop

    func_80800224_fxkern(rdram, ctx);
        goto after_1;
    // 0x808003B4: nop

    after_1:
    // 0x808003B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void func_8010BA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BA80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010BA84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010BA88: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8010BA8C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8010BA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010BA94: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8010BA98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8010BA9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010BAA0: jal         0x800EE7F8
    // 0x8010BAA4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010BAA4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8010BAA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8010BAAC: jal         0x8010B990
    // 0x8010BAB0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x8010BAB0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8010BAB4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8010BAB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010BABC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010BAC0: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x8010BAC4: beq         $t7, $zero, L_8010BAD8
    if (ctx->r15 == 0) {
        // 0x8010BAC8: addiu       $a1, $sp, 0x20
        ctx->r5 = ADD32(ctx->r29, 0X20);
            goto L_8010BAD8;
    }
    // 0x8010BAC8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8010BACC: jal         0x800EE7F8
    // 0x8010BAD0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010BAD0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8010BAD4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_8010BAD8:
    // 0x8010BAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010BADC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010BAE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010BAE4: jr          $ra
    // 0x8010BAE8: nop

    return;
    // 0x8010BAE8: nop

;}
RECOMP_FUNC void func_8008BC2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BC30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BC34: jal         0x8008BBF0
    // 0x8008BC38: lbu         $a1, 0x8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X8);
    func_8008BBF0(rdram, ctx);
        goto after_0;
    // 0x8008BC38: lbu         $a1, 0x8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X8);
    after_0:
    // 0x8008BC3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BC40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BC44: jr          $ra
    // 0x8008BC48: nop

    return;
    // 0x8008BC48: nop

;}
RECOMP_FUNC void chhoney_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F54: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1668, 0X1090) << 16);
    // 0x80800F58: jr          $ra
    // 0x80800F5C: addiu       $v0, $v0, 0x1090
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1668, 0X1090));
    return;
    // 0x80800F5C: addiu       $v0, $v0, 0x1090
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1668, 0X1090));
;}
RECOMP_FUNC void func_8080031C_chappearfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800324: jal         0x80100094
    // 0x80800328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080032C: lbu         $t6, 0xD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XD);
    // 0x80800330: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800334: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800338: beq         $t6, $zero, L_80800350
    if (ctx->r14 == 0) {
        // 0x8080033C: addiu       $a2, $zero, 0x1F4
        ctx->r6 = ADD32(0, 0X1F4);
            goto L_80800350;
    }
    // 0x8080033C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800340: jal         0x800FCAE0
    // 0x80800344: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    func_800FCAE0(rdram, ctx);
        goto after_1;
    // 0x80800344: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    after_1:
    // 0x80800348: jal         0x800FCA90
    // 0x8080034C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_2;
    // 0x8080034C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
L_80800350:
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void bsbflip_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003DC: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x808003E0: jal         0x80800064
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800064_bsbflip(rdram, ctx);
        goto after_0;
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808003E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003F0: jr          $ra
    // 0x808003F4: nop

    return;
    // 0x808003F4: nop

;}
RECOMP_FUNC void chrainbow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F40: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2360, 0X1010) << 16);
    // 0x80800F44: jr          $ra
    // 0x80800F48: addiu       $v0, $v0, 0x1010
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2360, 0X1010));
    return;
    // 0x80800F48: addiu       $v0, $v0, 0x1010
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2360, 0X1010));
    // 0x80800F4C: nop

;}
RECOMP_FUNC void func_8080227C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080227C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802280: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802284: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80802288: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080228C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80802290: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80802294: jal         0x80100094
    // 0x80802298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080229C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x808022A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808022A4: addiu       $a0, $zero, 0x468
    ctx->r4 = ADD32(0, 0X468);
    // 0x808022A8: beq         $a2, $zero, L_808022D0
    if (ctx->r6 == 0) {
        // 0x808022AC: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_808022D0;
    }
    // 0x808022AC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808022B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808022B4: beq         $a2, $at, L_80802304
    if (ctx->r6 == ctx->r1) {
        // 0x808022B8: addiu       $a0, $zero, 0x124
        ctx->r4 = ADD32(0, 0X124);
            goto L_80802304;
    }
    // 0x808022B8: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    // 0x808022BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808022C0: beq         $a2, $at, L_80802340
    if (ctx->r6 == ctx->r1) {
        // 0x808022C4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802340;
    }
    // 0x808022C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808022C8: b           L_808023AC
    // 0x808022CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808023AC;
    // 0x808022CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808022D0:
    // 0x808022D0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808022D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808022D8: jal         0x80108528
    // 0x808022DC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_1;
    // 0x808022DC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x808022E0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808022E4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808022E8: jal         0x8008A028
    // 0x808022EC: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808022EC: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_2:
    // 0x808022F0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808022F4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808022F8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808022FC: b           L_808023A8
    // 0x80802300: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
        goto L_808023A8;
    // 0x80802300: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
L_80802304:
    // 0x80802304: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80802308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080230C: jal         0x80108528
    // 0x80802310: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_3;
    // 0x80802310: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80802314: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80802318: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080231C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802320: lh          $a0, 0x78($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X78);
    // 0x80802324: jal         0x8010D09C
    // 0x80802328: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_8010D09C(rdram, ctx);
        goto after_4;
    // 0x80802328: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_4:
    // 0x8080232C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80802330: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80802334: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80802338: b           L_808023A8
    // 0x8080233C: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
        goto L_808023A8;
    // 0x8080233C: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
L_80802340:
    // 0x80802340: jal         0x800DC128
    // 0x80802344: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x80802344: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80802348: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8080234C: addiu       $a0, $v0, 0x43E
    ctx->r4 = ADD32(ctx->r2, 0X43E);
    // 0x80802350: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80802354: lwc1        $f4, 0x48($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X48);
    // 0x80802358: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x8080235C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80802360: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80802364: jal         0x80108528
    // 0x80802368: nop

    func_80108528(rdram, ctx);
        goto after_6;
    // 0x80802368: nop

    after_6:
    // 0x8080236C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802370: jal         0x80100120
    // 0x80802374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80100120(rdram, ctx);
        goto after_7;
    // 0x80802374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80802378: lh          $a0, 0x78($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X78);
    // 0x8080237C: jal         0x800F5A00
    // 0x80802380: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_8;
    // 0x80802380: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x80802384: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80802388: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080238C: jal         0x80101010
    // 0x80802390: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_80101010(rdram, ctx);
        goto after_9;
    // 0x80802390: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80802394: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80802398: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080239C: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    // 0x808023A0: jal         0x8010108C
    // 0x808023A4: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    func_8010108C(rdram, ctx);
        goto after_10;
    // 0x808023A4: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    after_10:
L_808023A8:
    // 0x808023A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808023AC:
    // 0x808023AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808023B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808023B4: jr          $ra
    // 0x808023B8: nop

    return;
    // 0x808023B8: nop

;}
RECOMP_FUNC void func_80808F44_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808F44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808F4C: jal         0x801065A4
    // 0x80808F50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_801065A4(rdram, ctx);
        goto after_0;
    // 0x80808F50: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80808F54: beq         $v0, $zero, L_80808F94
    if (ctx->r2 == 0) {
        // 0x80808F58: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80808F94;
    }
    // 0x80808F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80808F5C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80808F60: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80808F64: addiu       $a2, $a2, 0x67D8
    ctx->r6 = ADD32(ctx->r6, 0X67D8);
    // 0x80808F68: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80808F6C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80808F70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80808F74: jal         0x80088660
    // 0x80808F78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80808F78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80808F7C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80808F80: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80808F84: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80808F88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80808F8C: jal         0x80088660
    // 0x80808F90: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80808F90: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_2:
L_80808F94:
    // 0x80808F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808F98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808F9C: jr          $ra
    // 0x80808FA0: nop

    return;
    // 0x80808FA0: nop

;}
RECOMP_FUNC void bahold_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080015C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800160: lw          $v0, 0x9C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C);
    // 0x80800164: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80800168: beql        $t6, $zero, L_808001A4
    if (ctx->r14 == 0) {
        // 0x8080016C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800170: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x80800174: bne         $t7, $zero, L_8080018C
    if (ctx->r15 != 0) {
        // 0x80800178: nop
    
            goto L_8080018C;
    }
    // 0x80800178: nop

    // 0x8080017C: jal         0x80800008
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800008_bahold(rdram, ctx);
        goto after_0;
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800184: b           L_808001A4
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001A4;
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080018C:
    // 0x8080018C: jal         0x808000E0
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000E0_bahold(rdram, ctx);
        goto after_1;
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800198: lw          $t8, 0x9C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C);
    // 0x8080019C: sb          $zero, 0xC($t8)
    MEM_B(0XC, ctx->r24) = 0;
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A4:
    // 0x808001A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_808013D0_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808013D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808013E0: jal         0x80088078
    // 0x808013E4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808013E4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808013E8: beq         $v0, $zero, L_80801414
    if (ctx->r2 == 0) {
        // 0x808013EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801414;
    }
    // 0x808013EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808013F0: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x808013F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808013F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808013FC: beq         $t6, $at, L_8080140C
    if (ctx->r14 == ctx->r1) {
        // 0x80801400: nop
    
            goto L_8080140C;
    }
    // 0x80801400: nop

    // 0x80801404: jal         0x80801464
    // 0x80801408: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801464_chnicecavemen(rdram, ctx);
        goto after_1;
    // 0x80801408: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_8080140C:
    // 0x8080140C: b           L_80801418
    // 0x80801410: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80801418;
    // 0x80801410: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80801414:
    // 0x80801414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801418:
    // 0x80801418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080141C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801420: jr          $ra
    // 0x80801424: nop

    return;
    // 0x80801424: nop

;}
RECOMP_FUNC void func_8009664C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009664C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096654: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096658: jal         0x800C674C
    // 0x8009665C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C674C(rdram, ctx);
        goto after_0;
    // 0x8009665C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80096660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096668: jr          $ra
    // 0x8009666C: nop

    return;
    // 0x8009666C: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B78: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B78);
    return;
    // 0x80082B7C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800D58AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D58AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D58B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D58B4: jal         0x800D5688
    // 0x800D58B8: nop

    func_800D5688(rdram, ctx);
        goto after_0;
    // 0x800D58B8: nop

    after_0:
    // 0x800D58BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D58C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D58C4: jr          $ra
    // 0x800D58C8: nop

    return;
    // 0x800D58C8: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E0C: jal         0x80800C9C
    // 0x80800E10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800C9C_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800E10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E14: bne         $v0, $zero, L_80800E24
    if (ctx->r2 != 0) {
        // 0x80800E18: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800E24;
    }
    // 0x80800E18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800E1C: b           L_80800E34
    // 0x80800E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E34;
    // 0x80800E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E24:
    // 0x80800E24: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80800E28: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800E30: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80800E34:
    // 0x80800E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E3C: jr          $ra
    // 0x80800E40: nop

    return;
    // 0x80800E40: nop

;}
RECOMP_FUNC void _plsu_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878B0: syscall     638
    recomp_syscall_handler(rdram, ctx, 0x800878B0);
    return;
    // 0x800878B4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800C34_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C34: jr          $ra
    // 0x80800C38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800C38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800DD410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD410: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DD414: lw          $t6, -0x37BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X37BC);
    // 0x800DD418: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800DD41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD420: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800DD424: beq         $t6, $zero, L_800DD49C
    if (ctx->r14 == 0) {
        // 0x800DD428: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_800DD49C;
    }
    // 0x800DD428: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800DD42C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD430: lw          $a0, -0x3698($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3698);
    // 0x800DD434: beql        $a0, $zero, L_800DD478
    if (ctx->r4 == 0) {
        // 0x800DD438: lw          $a1, 0x34($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X34);
            goto L_800DD478;
    }
    goto skip_0;
    // 0x800DD438: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800DD43C: jal         0x800ADE2C
    // 0x800DD440: lh          $a1, 0xA($a1)
    ctx->r5 = MEM_H(ctx->r5, 0XA);
    func_800ADE2C(rdram, ctx);
        goto after_0;
    // 0x800DD440: lh          $a1, 0xA($a1)
    ctx->r5 = MEM_H(ctx->r5, 0XA);
    after_0:
    // 0x800DD444: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD448: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    // 0x800DD44C: jal         0x80019AA0
    // 0x800DD450: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_1;
    // 0x800DD450: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800DD454: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800DD458: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800DD45C: jal         0x800193C4
    // 0x800DD460: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800193C4(rdram, ctx);
        goto after_2;
    // 0x800DD460: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_2:
    // 0x800DD464: jal         0x80018DAC
    // 0x800DD468: nop

    mlMtxPop(rdram, ctx);
        goto after_3;
    // 0x800DD468: nop

    after_3:
    // 0x800DD46C: b           L_800DD488
    // 0x800DD470: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
        goto L_800DD488;
    // 0x800DD470: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800DD474: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_800DD478:
    // 0x800DD478: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800DD47C: jal         0x800193C4
    // 0x800DD480: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800193C4(rdram, ctx);
        goto after_4;
    // 0x800DD480: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_4:
    // 0x800DD484: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_800DD488:
    // 0x800DD488: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DD48C: lw          $a0, -0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37BC);
    // 0x800DD490: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800DD494: jal         0x800DC028
    // 0x800DD498: lh          $a1, 0x8($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X8);
    func_800DC028(rdram, ctx);
        goto after_5;
    // 0x800DD498: lh          $a1, 0x8($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X8);
    after_5:
L_800DD49C:
    // 0x800DD49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD4A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800DD4A4: jr          $ra
    // 0x800DD4A8: nop

    return;
    // 0x800DD4A8: nop

;}
RECOMP_FUNC void func_800A3644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3644: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A3648: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A364C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A3650: jal         0x800D8FF8
    // 0x800A3654: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800A3654: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A3658: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A365C: jal         0x800963E4
    // 0x800A3660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800963E4(rdram, ctx);
        goto after_1;
    // 0x800A3660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A3664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3668: jal         0x80096628
    // 0x800A366C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_80096628(rdram, ctx);
        goto after_2;
    // 0x800A366C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800A3670: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800A3674: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3678: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A367C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800A3680: lbu         $t6, 0x3D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3D);
    // 0x800A3684: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x800A3688: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x800A368C: beql        $t6, $zero, L_800A36D4
    if (ctx->r14 == 0) {
        // 0x800A3690: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_800A36D4;
    }
    goto skip_0;
    // 0x800A3690: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_0:
    // 0x800A3694: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800A3698: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A369C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A36A0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800A36A4: nop

    // 0x800A36A8: bc1fl       L_800A36C0
    if (!c1cs) {
        // 0x800A36AC: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_800A36C0;
    }
    goto skip_1;
    // 0x800A36AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x800A36B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A36B4: b           L_800A36C8
    // 0x800A36B8: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
        goto L_800A36C8;
    // 0x800A36B8: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x800A36BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_800A36C0:
    // 0x800A36C0: nop

    // 0x800A36C4: swc1        $f8, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f8.u32l;
L_800A36C8:
    // 0x800A36C8: b           L_800A37F4
    // 0x800A36CC: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
        goto L_800A37F4;
    // 0x800A36CC: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
    // 0x800A36D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_800A36D4:
    // 0x800A36D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A36D8: lwc1        $f10, 0x5564($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5564);
    // 0x800A36DC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x800A36E0: jal         0x800F10B4
    // 0x800A36E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x800A36E4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x800A36E8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800A36EC: jal         0x80096518
    // 0x800A36F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096518(rdram, ctx);
        goto after_4;
    // 0x800A36F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A36F4: bne         $v0, $zero, L_800A3734
    if (ctx->r2 != 0) {
        // 0x800A36F8: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_800A3734;
    }
    // 0x800A36F8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A36FC: andi        $t8, $t7, 0x50
    ctx->r24 = ctx->r15 & 0X50;
    // 0x800A3700: bnel        $t8, $zero, L_800A3738
    if (ctx->r24 != 0) {
        // 0x800A3704: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_800A3738;
    }
    goto skip_2;
    // 0x800A3704: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x800A3708: jal         0x80096434
    // 0x800A370C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096434(rdram, ctx);
        goto after_5;
    // 0x800A370C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A3710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3714: jal         0x8009650C
    // 0x800A3718: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8009650C(rdram, ctx);
        goto after_6;
    // 0x800A3718: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_6:
    // 0x800A371C: beq         $v0, $zero, L_800A3734
    if (ctx->r2 == 0) {
        // 0x800A3720: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_800A3734;
    }
    // 0x800A3720: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3724: andi        $t9, $v1, 0x50
    ctx->r25 = ctx->r3 & 0X50;
    // 0x800A3728: beql        $t9, $zero, L_800A3738
    if (ctx->r25 == 0) {
        // 0x800A372C: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_800A3738;
    }
    goto skip_3;
    // 0x800A372C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    skip_3:
    // 0x800A3730: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
L_800A3734:
    // 0x800A3734: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_800A3738:
    // 0x800A3738: andi        $t1, $t0, 0x50
    ctx->r9 = ctx->r8 & 0X50;
    // 0x800A373C: beql        $t1, $zero, L_800A3784
    if (ctx->r9 == 0) {
        // 0x800A3740: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_800A3784;
    }
    goto skip_4;
    // 0x800A3740: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_4:
    // 0x800A3744: jal         0x8008E35C
    // 0x800A3748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x800A3748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800A374C: bne         $v0, $zero, L_800A3780
    if (ctx->r2 != 0) {
        // 0x800A3750: lwc1        $f16, 0x34($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800A3780;
    }
    // 0x800A3750: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A3754: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A3758: lw          $t2, 0xA0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XA0);
    // 0x800A375C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A3760: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A3764: lwc1        $f6, 0x38($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X38);
    // 0x800A3768: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A376C: jal         0x800F13F0
    // 0x800A3770: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    func_800F13F0(rdram, ctx);
        goto after_8;
    // 0x800A3770: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_8:
    // 0x800A3774: lw          $t3, 0xA0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3778: b           L_800A378C
    // 0x800A377C: swc1        $f0, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f0.u32l;
        goto L_800A378C;
    // 0x800A377C: swc1        $f0, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f0.u32l;
L_800A3780:
    // 0x800A3780: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_800A3784:
    // 0x800A3784: lw          $t4, 0xA0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3788: swc1        $f8, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f8.u32l;
L_800A378C:
    // 0x800A378C: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3790: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A3794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A3798: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800A379C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800A37A0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800A37A4: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x800A37A8: bc1fl       L_800A37F8
    if (!c1cs) {
        // 0x800A37AC: sb          $zero, 0x3D($v1)
        MEM_B(0X3D, ctx->r3) = 0;
            goto L_800A37F8;
    }
    goto skip_5;
    // 0x800A37AC: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
    skip_5:
    // 0x800A37B0: beq         $t6, $zero, L_800A37D4
    if (ctx->r14 == 0) {
        // 0x800A37B4: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_800A37D4;
    }
    // 0x800A37B4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A37B8: lui         $a2, 0x3E38
    ctx->r6 = S32(0X3E38 << 16);
    // 0x800A37BC: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x800A37C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A37C4: jal         0x800917A8
    // 0x800A37C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bastatetimer_set(rdram, ctx);
        goto after_9;
    // 0x800A37C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x800A37CC: b           L_800A37F4
    // 0x800A37D0: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
        goto L_800A37F4;
    // 0x800A37D0: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
L_800A37D4:
    // 0x800A37D4: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x800A37D8: beq         $t8, $zero, L_800A37F4
    if (ctx->r24 == 0) {
        // 0x800A37DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A37F4;
    }
    // 0x800A37DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A37E0: lui         $a2, 0x3E38
    ctx->r6 = S32(0X3E38 << 16);
    // 0x800A37E4: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x800A37E8: jal         0x800917A8
    // 0x800A37EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    bastatetimer_set(rdram, ctx);
        goto after_10;
    // 0x800A37EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x800A37F0: lw          $v1, 0xA0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA0);
L_800A37F4:
    // 0x800A37F4: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
L_800A37F8:
    // 0x800A37F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A37FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A3800: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A3804: jr          $ra
    // 0x800A3808: nop

    return;
    // 0x800A3808: nop

;}
