#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chconga_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DE0: syscall     242
    recomp_syscall_handler(rdram, ctx, 0x80085DE0);
    return;
    // 0x80085DE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8002AD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD60: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002AD64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002AD68: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002AD6C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8002AD70: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8002AD74: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8002AD78: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8002AD7C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8002AD80: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8002AD84: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8002AD88: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8002AD8C: sh          $zero, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = 0;
    // 0x8002AD90: addiu       $t9, $zero, 0xB8
    ctx->r25 = ADD32(0, 0XB8);
    // 0x8002AD94: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8002AD98: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x8002AD9C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002ADA0: lw          $t1, 0x7C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X7C);
    // 0x8002ADA4: beq         $t1, $zero, L_8002B620
    if (ctx->r9 == 0) {
        // 0x8002ADA8: nop
    
            goto L_8002B620;
    }
    // 0x8002ADA8: nop

L_8002ADAC:
    // 0x8002ADAC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002ADB0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8002ADB4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002ADB8: lw          $t4, 0x7C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X7C);
    // 0x8002ADBC: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8002ADC0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8002ADC4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002ADC8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8002ADCC: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002ADD0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8002ADD4: addiu       $t9, $t8, 0xB7
    ctx->r25 = ADD32(ctx->r24, 0XB7);
    // 0x8002ADD8: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8002ADDC: mflo        $t0
    ctx->r8 = lo;
    // 0x8002ADE0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002ADE4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8002ADE8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002ADEC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8002ADF0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002ADF4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8002ADF8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002ADFC: bne         $t2, $zero, L_8002AE0C
    if (ctx->r10 != 0) {
        // 0x8002AE00: nop
    
            goto L_8002AE0C;
    }
    // 0x8002AE00: nop

    // 0x8002AE04: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8002AE08: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_8002AE0C:
    // 0x8002AE0C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002AE10: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002AE14: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002AE18: beq         $at, $zero, L_8002AE28
    if (ctx->r1 == 0) {
        // 0x8002AE1C: nop
    
            goto L_8002AE28;
    }
    // 0x8002AE1C: nop

    // 0x8002AE20: b           L_8002B620
    // 0x8002AE24: nop

        goto L_8002B620;
    // 0x8002AE24: nop

L_8002AE28:
    // 0x8002AE28: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE2C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8002AE30: lhu         $t8, 0x8($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8);
    // 0x8002AE34: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x8002AE38: beq         $at, $zero, L_8002B570
    if (ctx->r1 == 0) {
        // 0x8002AE3C: nop
    
            goto L_8002B570;
    }
    // 0x8002AE3C: nop

    // 0x8002AE40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002AE44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002AE48: addu        $at, $at, $t8
    gpr jr_addend_8002AE50 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002AE4C: lw          $t8, 0x1D40($at)
    ctx->r24 = ADD32(ctx->r1, 0X1D40);
    // 0x8002AE50: jr          $t8
    // 0x8002AE54: nop

    switch (jr_addend_8002AE50 >> 2) {
        case 0: goto L_8002B498; break;
        case 1: goto L_8002B570; break;
        case 2: goto L_8002B570; break;
        case 3: goto L_8002B570; break;
        case 4: goto L_8002B570; break;
        case 5: goto L_8002B530; break;
        case 6: goto L_8002B570; break;
        case 7: goto L_8002B4C4; break;
        case 8: goto L_8002B4FC; break;
        case 9: goto L_8002B570; break;
        case 10: goto L_8002B570; break;
        case 11: goto L_8002B0CC; break;
        case 12: goto L_8002B0CC; break;
        case 13: goto L_8002AE58; break;
        case 14: goto L_8002B410; break;
        case 15: goto L_8002B460; break;
        case 16: goto L_8002B0CC; break;
        default: switch_error(__func__, 0x8002AE50, 0x80041D40);
    }
    // 0x8002AE54: nop

L_8002AE58:
    // 0x8002AE58: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE5C: lw          $t0, 0x7C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X7C);
    // 0x8002AE60: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8002AE64: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AE68: lh          $t2, 0xA($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XA);
    // 0x8002AE6C: beq         $t2, $zero, L_8002AE80
    if (ctx->r10 == 0) {
        // 0x8002AE70: nop
    
            goto L_8002AE80;
    }
    // 0x8002AE70: nop

    // 0x8002AE74: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE78: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002AE7C: sw          $t3, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->r11;
L_8002AE80:
    // 0x8002AE80: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AE84: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE88: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002AE8C: jal         0x8002CC9C
    // 0x8002AE90: lw          $a2, 0x20($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X20);
    func_8002CC9C(rdram, ctx);
        goto after_0;
    // 0x8002AE90: lw          $a2, 0x20($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X20);
    after_0:
    // 0x8002AE94: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002AE98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002AE9C: sw          $t6, 0x84($t7)
    MEM_W(0X84, ctx->r15) = ctx->r14;
    // 0x8002AEA0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002AEA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002AEA8: sw          $t8, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->r24;
    // 0x8002AEAC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002AEB0: sw          $zero, 0x70($t0)
    MEM_W(0X70, ctx->r8) = 0;
    // 0x8002AEB4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AEB8: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002AEBC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AEC0: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x8002AEC4: addiu       $t3, $t2, 0xB7
    ctx->r11 = ADD32(ctx->r10, 0XB7);
    // 0x8002AEC8: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x8002AECC: mflo        $t4
    ctx->r12 = lo;
    // 0x8002AED0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002AED4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8002AED8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002AEDC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8002AEE0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002AEE4: sw          $t5, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r13;
    // 0x8002AEE8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AEEC: lh          $t8, 0x10($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X10);
    // 0x8002AEF0: addu        $t9, $t8, $t8
    ctx->r25 = ADD32(ctx->r24, ctx->r24);
    // 0x8002AEF4: bgez        $t9, L_8002AF04
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002AEF8: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8002AF04;
    }
    // 0x8002AEF8: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8002AEFC: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8002AF00: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8002AF04:
    // 0x8002AF04: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8002AF08: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002AF0C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF10: sh          $t1, 0x5A($t2)
    MEM_H(0X5A, ctx->r10) = ctx->r9;
    // 0x8002AF14: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF18: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF1C: lbu         $t4, 0x12($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X12);
    // 0x8002AF20: sh          $t4, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r12;
    // 0x8002AF24: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF28: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8002AF2C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF30: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8002AF34: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x8002AF38: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8002AF3C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002AF40: lh          $t0, 0x1290($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X1290);
    // 0x8002AF44: sra         $t2, $t7, 7
    ctx->r10 = S32(SIGNED(ctx->r15) >> 7);
    // 0x8002AF48: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x8002AF4C: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x8002AF50: sh          $t3, 0x60($t4)
    MEM_H(0X60, ctx->r12) = ctx->r11;
    // 0x8002AF54: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8002AF58: lbu         $t5, -0x15D0($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X15D0);
    // 0x8002AF5C: bne         $t5, $zero, L_8002AF74
    if (ctx->r13 != 0) {
        // 0x8002AF60: nop
    
            goto L_8002AF74;
    }
    // 0x8002AF60: nop

    // 0x8002AF64: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF68: lh          $t8, 0x60($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X60);
    // 0x8002AF6C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x8002AF70: sh          $t9, 0x60($t6)
    MEM_H(0X60, ctx->r14) = ctx->r25;
L_8002AF74:
    // 0x8002AF74: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF78: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002AF7C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002AF80: lbu         $t7, 0x13($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X13);
    // 0x8002AF84: andi        $t1, $t7, 0x7F
    ctx->r9 = ctx->r15 & 0X7F;
    // 0x8002AF88: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8002AF8C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002AF90: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002AF94: lh          $t4, 0x138E($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X138E);
    // 0x8002AF98: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x8002AF9C: sh          $t5, 0x62($t8)
    MEM_H(0X62, ctx->r24) = ctx->r13;
    // 0x8002AFA0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8002AFA4: lbu         $t9, -0x15CE($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X15CE);
    // 0x8002AFA8: beq         $t9, $zero, L_8002AFC8
    if (ctx->r25 == 0) {
        // 0x8002AFAC: nop
    
            goto L_8002AFC8;
    }
    // 0x8002AFAC: nop

    // 0x8002AFB0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002AFB4: lh          $t0, 0x58($t6)
    ctx->r8 = MEM_H(ctx->r14, 0X58);
    // 0x8002AFB8: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8002AFBC: addiu       $t1, $t7, 0x20
    ctx->r9 = ADD32(ctx->r15, 0X20);
    // 0x8002AFC0: b           L_8002AFE4
    // 0x8002AFC4: sh          $t1, 0x58($t6)
    MEM_H(0X58, ctx->r14) = ctx->r9;
        goto L_8002AFE4;
    // 0x8002AFC4: sh          $t1, 0x58($t6)
    MEM_H(0X58, ctx->r14) = ctx->r9;
L_8002AFC8:
    // 0x8002AFC8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8002AFCC: lbu         $t2, -0x15CF($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X15CF);
    // 0x8002AFD0: beq         $t2, $zero, L_8002AFE4
    if (ctx->r10 == 0) {
        // 0x8002AFD4: nop
    
            goto L_8002AFE4;
    }
    // 0x8002AFD4: nop

    // 0x8002AFD8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002AFDC: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x8002AFE0: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
L_8002AFE4:
    // 0x8002AFE4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AFE8: lw          $t8, 0x1C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1C);
    // 0x8002AFEC: beq         $t8, $zero, L_8002B010
    if (ctx->r24 == 0) {
        // 0x8002AFF0: nop
    
            goto L_8002B010;
    }
    // 0x8002AFF0: nop

    // 0x8002AFF4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002AFF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002AFFC: sh          $t9, 0x5C($t0)
    MEM_H(0X5C, ctx->r8) = ctx->r25;
    // 0x8002B000: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B004: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002B008: b           L_8002B06C
    // 0x8002B00C: sh          $t7, 0x5E($t1)
    MEM_H(0X5E, ctx->r9) = ctx->r15;
        goto L_8002B06C;
    // 0x8002B00C: sh          $t7, 0x5E($t1)
    MEM_H(0X5E, ctx->r9) = ctx->r15;
L_8002B010:
    // 0x8002B010: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B014: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002B018: lh          $t2, 0x58($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X58);
    // 0x8002B01C: lh          $t5, 0x5A($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X5A);
    // 0x8002B020: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002B024: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002B028: lh          $t4, 0x1290($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X1290);
    // 0x8002B02C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B030: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B034: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x8002B038: sh          $t9, 0x5C($t6)
    MEM_H(0X5C, ctx->r14) = ctx->r25;
    // 0x8002B03C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B040: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8002B044: lh          $t7, 0x58($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X58);
    // 0x8002B048: lh          $t4, 0x5A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X5A);
    // 0x8002B04C: negu        $t1, $t7
    ctx->r9 = SUB32(0, ctx->r15);
    // 0x8002B050: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002B054: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8002B058: lh          $t3, 0x138E($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X138E);
    // 0x8002B05C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B060: mflo        $t5
    ctx->r13 = lo;
    // 0x8002B064: sra         $t8, $t5, 15
    ctx->r24 = S32(SIGNED(ctx->r13) >> 15);
    // 0x8002B068: sh          $t8, 0x5E($t0)
    MEM_H(0X5E, ctx->r8) = ctx->r24;
L_8002B06C:
    // 0x8002B06C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B070: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B074: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8002B078: swc1        $f4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f4.u32l;
    // 0x8002B07C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B080: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B084: lbu         $t1, 0x15($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X15);
    // 0x8002B088: sh          $t1, 0x92($t2)
    MEM_H(0X92, ctx->r10) = ctx->r9;
    // 0x8002B08C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B090: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B094: lwc1        $f6, 0x18($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8002B098: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8002B09C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8002B0A0: nop

    // 0x8002B0A4: sh          $t5, 0x90($t8)
    MEM_H(0X90, ctx->r24) = ctx->r13;
    // 0x8002B0A8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002B0B0: sw          $t0, 0xB8($t9)
    MEM_W(0XB8, ctx->r25) = ctx->r8;
    // 0x8002B0B4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B0B8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0BC: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x8002B0C0: sb          $t7, 0x8C($t1)
    MEM_B(0X8C, ctx->r9) = ctx->r15;
    // 0x8002B0C4: b           L_8002B5B0
    // 0x8002B0C8: nop

        goto L_8002B5B0;
    // 0x8002B0C8: nop

L_8002B0CC:
    // 0x8002B0CC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8002B0D0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0D4: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B0D8: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B0DC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B0E0: jal         0x8002B7C8
    // 0x8002B0E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8002B7C8(rdram, ctx);
        goto after_1;
    // 0x8002B0E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x8002B0E8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B0EC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B0F0: lw          $t4, 0x70($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X70);
    // 0x8002B0F4: lw          $t5, 0x74($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X74);
    // 0x8002B0F8: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002B0FC: bne         $at, $zero, L_8002B188
    if (ctx->r1 != 0) {
        // 0x8002B100: nop
    
            goto L_8002B188;
    }
    // 0x8002B100: nop

    // 0x8002B104: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B108: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002B10C: lh          $t0, 0x58($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X58);
    // 0x8002B110: lh          $t7, 0x5A($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X5A);
    // 0x8002B114: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x8002B118: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B11C: lh          $t6, 0x1290($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1290);
    // 0x8002B120: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B124: mflo        $t1
    ctx->r9 = lo;
    // 0x8002B128: sra         $t2, $t1, 15
    ctx->r10 = S32(SIGNED(ctx->r9) >> 15);
    // 0x8002B12C: sh          $t2, 0x68($t8)
    MEM_H(0X68, ctx->r24) = ctx->r10;
    // 0x8002B130: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B134: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8002B138: lh          $t4, 0x58($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X58);
    // 0x8002B13C: lh          $t6, 0x5A($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X5A);
    // 0x8002B140: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8002B144: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x8002B148: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8002B14C: lh          $t9, 0x138E($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X138E);
    // 0x8002B150: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B154: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B158: sra         $t1, $t7, 15
    ctx->r9 = S32(SIGNED(ctx->r15) >> 15);
    // 0x8002B15C: sh          $t1, 0x6E($t3)
    MEM_H(0X6E, ctx->r11) = ctx->r9;
    // 0x8002B160: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B164: lw          $t8, 0x74($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X74);
    // 0x8002B168: sw          $t8, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->r24;
    // 0x8002B16C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B170: lh          $t5, 0x68($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X68);
    // 0x8002B174: sh          $t5, 0x5C($t4)
    MEM_H(0X5C, ctx->r12) = ctx->r13;
    // 0x8002B178: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B17C: lh          $t9, 0x6E($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6E);
    // 0x8002B180: b           L_8002B1C8
    // 0x8002B184: sh          $t9, 0x5E($t0)
    MEM_H(0X5E, ctx->r8) = ctx->r25;
        goto L_8002B1C8;
    // 0x8002B184: sh          $t9, 0x5E($t0)
    MEM_H(0X5E, ctx->r8) = ctx->r25;
L_8002B188:
    // 0x8002B188: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B18C: lh          $a0, 0x5C($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X5C);
    // 0x8002B190: lw          $a1, 0x70($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X70);
    // 0x8002B194: lh          $a2, 0x66($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X66);
    // 0x8002B198: jal         0x8002BCBC
    // 0x8002B19C: lhu         $a3, 0x64($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X64);
    func_8002BCBC(rdram, ctx);
        goto after_2;
    // 0x8002B19C: lhu         $a3, 0x64($t6)
    ctx->r7 = MEM_HU(ctx->r14, 0X64);
    after_2:
    // 0x8002B1A0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1A4: sh          $v0, 0x5C($t7)
    MEM_H(0X5C, ctx->r15) = ctx->r2;
    // 0x8002B1A8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1AC: lh          $a0, 0x5E($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X5E);
    // 0x8002B1B0: lw          $a1, 0x70($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X70);
    // 0x8002B1B4: lh          $a2, 0x6C($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X6C);
    // 0x8002B1B8: jal         0x8002BCBC
    // 0x8002B1BC: lhu         $a3, 0x6A($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X6A);
    func_8002BCBC(rdram, ctx);
        goto after_3;
    // 0x8002B1BC: lhu         $a3, 0x6A($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X6A);
    after_3:
    // 0x8002B1C0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1C4: sh          $v0, 0x5E($t3)
    MEM_H(0X5E, ctx->r11) = ctx->r2;
L_8002B1C8:
    // 0x8002B1C8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1CC: lh          $t2, 0x5C($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X5C);
    // 0x8002B1D0: bne         $t2, $zero, L_8002B1E4
    if (ctx->r10 != 0) {
        // 0x8002B1D4: nop
    
            goto L_8002B1E4;
    }
    // 0x8002B1D4: nop

    // 0x8002B1D8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002B1E0: sh          $t5, 0x5C($t4)
    MEM_H(0X5C, ctx->r12) = ctx->r13;
L_8002B1E4:
    // 0x8002B1E4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1E8: lh          $t0, 0x5E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X5E);
    // 0x8002B1EC: bne         $t0, $zero, L_8002B200
    if (ctx->r8 != 0) {
        // 0x8002B1F0: nop
    
            goto L_8002B200;
    }
    // 0x8002B1F0: nop

    // 0x8002B1F4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B1F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002B1FC: sh          $t6, 0x5E($t7)
    MEM_H(0X5E, ctx->r15) = ctx->r14;
L_8002B200:
    // 0x8002B200: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B204: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8002B208: lw          $t3, 0x7C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X7C);
    // 0x8002B20C: lh          $t8, 0x8($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X8);
    // 0x8002B210: bne         $t8, $at, L_8002B274
    if (ctx->r24 != ctx->r1) {
        // 0x8002B214: nop
    
            goto L_8002B274;
    }
    // 0x8002B214: nop

    // 0x8002B218: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8002B21C: lbu         $t2, -0x15CE($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X15CE);
    // 0x8002B220: beq         $t2, $zero, L_8002B244
    if (ctx->r10 == 0) {
        // 0x8002B224: nop
    
            goto L_8002B244;
    }
    // 0x8002B224: nop

    // 0x8002B228: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B22C: lw          $t4, 0x7C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X7C);
    // 0x8002B230: lh          $t9, 0xE($t4)
    ctx->r25 = MEM_H(ctx->r12, 0XE);
    // 0x8002B234: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8002B238: addiu       $t6, $t0, 0x20
    ctx->r14 = ADD32(ctx->r8, 0X20);
    // 0x8002B23C: b           L_8002B274
    // 0x8002B240: sh          $t6, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r14;
        goto L_8002B274;
    // 0x8002B240: sh          $t6, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r14;
L_8002B244:
    // 0x8002B244: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8002B248: lbu         $t7, -0x15CF($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X15CF);
    // 0x8002B24C: beq         $t7, $zero, L_8002B264
    if (ctx->r15 == 0) {
        // 0x8002B250: nop
    
            goto L_8002B264;
    }
    // 0x8002B250: nop

    // 0x8002B254: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B258: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8002B25C: b           L_8002B274
    // 0x8002B260: sh          $t1, 0x58($t3)
    MEM_H(0X58, ctx->r11) = ctx->r9;
        goto L_8002B274;
    // 0x8002B260: sh          $t1, 0x58($t3)
    MEM_H(0X58, ctx->r11) = ctx->r9;
L_8002B264:
    // 0x8002B264: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B268: lw          $t2, 0x7C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X7C);
    // 0x8002B26C: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x8002B270: sh          $t4, 0x58($t8)
    MEM_H(0X58, ctx->r24) = ctx->r12;
L_8002B274:
    // 0x8002B274: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B278: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8002B27C: lw          $t0, 0x7C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X7C);
    // 0x8002B280: lh          $t6, 0x8($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X8);
    // 0x8002B284: bne         $t6, $at, L_8002B300
    if (ctx->r14 != ctx->r1) {
        // 0x8002B288: nop
    
            goto L_8002B300;
    }
    // 0x8002B288: nop

    // 0x8002B28C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B290: sw          $zero, 0x70($t5)
    MEM_W(0X70, ctx->r13) = 0;
    // 0x8002B294: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B298: lw          $t1, 0x7C($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X7C);
    // 0x8002B29C: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x8002B2A0: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8002B2A4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002B2A8: addu        $t4, $t2, $t2
    ctx->r12 = ADD32(ctx->r10, ctx->r10);
    // 0x8002B2AC: bgez        $t4, L_8002B2BC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002B2B0: sra         $t8, $t4, 1
        ctx->r24 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8002B2BC;
    }
    // 0x8002B2B0: sra         $t8, $t4, 1
    ctx->r24 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8002B2B4: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8002B2B8: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8002B2BC:
    // 0x8002B2BC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8002B2C0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002B2C4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B2C8: sh          $t9, 0x5A($t0)
    MEM_H(0X5A, ctx->r8) = ctx->r25;
    // 0x8002B2CC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B2D0: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x8002B2D4: lw          $t5, 0x7C($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X7C);
    // 0x8002B2D8: lw          $t7, 0x10($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10);
    // 0x8002B2DC: addiu       $t1, $t7, 0xB7
    ctx->r9 = ADD32(ctx->r15, 0XB7);
    // 0x8002B2E0: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8002B2E4: mflo        $t3
    ctx->r11 = lo;
    // 0x8002B2E8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8002B2EC: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8002B2F0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002B2F4: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x8002B2F8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002B2FC: sw          $t2, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r10;
L_8002B300:
    // 0x8002B300: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B304: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8002B308: lw          $t8, 0x7C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X7C);
    // 0x8002B30C: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x8002B310: bne         $t9, $at, L_8002B3FC
    if (ctx->r25 != ctx->r1) {
        // 0x8002B314: nop
    
            goto L_8002B3FC;
    }
    // 0x8002B314: nop

    // 0x8002B318: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B31C: lw          $t2, 0x7C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X7C);
    // 0x8002B320: lh          $t5, 0x60($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X60);
    // 0x8002B324: lh          $t7, 0x62($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X62);
    // 0x8002B328: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x8002B32C: xor         $t1, $t5, $t7
    ctx->r9 = ctx->r13 ^ ctx->r15;
    // 0x8002B330: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8002B334: sra         $t8, $t4, 7
    ctx->r24 = S32(SIGNED(ctx->r12) >> 7);
    // 0x8002B338: andi        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 & 0X1;
    // 0x8002B33C: xor         $t9, $t3, $t8
    ctx->r25 = ctx->r11 ^ ctx->r24;
    // 0x8002B340: beq         $t9, $zero, L_8002B390
    if (ctx->r25 == 0) {
        // 0x8002B344: nop
    
            goto L_8002B390;
    }
    // 0x8002B344: nop

    // 0x8002B348: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8002B34C: lbu         $t5, -0x15D0($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X15D0);
    // 0x8002B350: beq         $t5, $zero, L_8002B390
    if (ctx->r13 == 0) {
        // 0x8002B354: nop
    
            goto L_8002B390;
    }
    // 0x8002B354: nop

    // 0x8002B358: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B35C: lh          $t1, 0x58($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X58);
    // 0x8002B360: slti        $at, $t1, 0x41
    ctx->r1 = SIGNED(ctx->r9) < 0X41 ? 1 : 0;
    // 0x8002B364: bne         $at, $zero, L_8002B380
    if (ctx->r1 != 0) {
        // 0x8002B368: nop
    
            goto L_8002B380;
    }
    // 0x8002B368: nop

    // 0x8002B36C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B370: lh          $t2, 0x60($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X60);
    // 0x8002B374: xori        $t6, $t2, 0x1
    ctx->r14 = ctx->r10 ^ 0X1;
    // 0x8002B378: b           L_8002B390
    // 0x8002B37C: sh          $t6, 0x60($t0)
    MEM_H(0X60, ctx->r8) = ctx->r14;
        goto L_8002B390;
    // 0x8002B37C: sh          $t6, 0x60($t0)
    MEM_H(0X60, ctx->r8) = ctx->r14;
L_8002B380:
    // 0x8002B380: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8002B384: lh          $t3, 0x62($t4)
    ctx->r11 = MEM_H(ctx->r12, 0X62);
    // 0x8002B388: xori        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 ^ 0X1;
    // 0x8002B38C: sh          $t8, 0x62($t4)
    MEM_H(0X62, ctx->r12) = ctx->r24;
L_8002B390:
    // 0x8002B390: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B394: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002B398: lw          $t5, 0x7C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X7C);
    // 0x8002B39C: lh          $t3, 0x60($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X60);
    // 0x8002B3A0: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x8002B3A4: andi        $t8, $t3, 0x1
    ctx->r24 = ctx->r11 & 0X1;
    // 0x8002B3A8: andi        $t1, $t7, 0x7F
    ctx->r9 = ctx->r15 & 0X7F;
    // 0x8002B3AC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002B3B0: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x8002B3B4: lh          $t6, 0x1290($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1290);
    // 0x8002B3B8: andi        $t0, $t6, 0xFFFE
    ctx->r8 = ctx->r14 & 0XFFFE;
    // 0x8002B3BC: or          $t4, $t0, $t8
    ctx->r12 = ctx->r8 | ctx->r24;
    // 0x8002B3C0: sh          $t4, 0x60($t9)
    MEM_H(0X60, ctx->r25) = ctx->r12;
    // 0x8002B3C4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B3C8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8002B3CC: lw          $t7, 0x7C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X7C);
    // 0x8002B3D0: lh          $t4, 0x62($t5)
    ctx->r12 = MEM_H(ctx->r13, 0X62);
    // 0x8002B3D4: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x8002B3D8: andi        $t9, $t4, 0x1
    ctx->r25 = ctx->r12 & 0X1;
    // 0x8002B3DC: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x8002B3E0: negu        $t6, $t2
    ctx->r14 = SUB32(0, ctx->r10);
    // 0x8002B3E4: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x8002B3E8: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8002B3EC: lh          $t0, 0x138E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X138E);
    // 0x8002B3F0: andi        $t8, $t0, 0xFFFE
    ctx->r24 = ctx->r8 & 0XFFFE;
    // 0x8002B3F4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8002B3F8: sh          $t7, 0x62($t5)
    MEM_H(0X62, ctx->r13) = ctx->r15;
L_8002B3FC:
    // 0x8002B3FC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B400: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002B404: sw          $t1, 0x78($t2)
    MEM_W(0X78, ctx->r10) = ctx->r9;
    // 0x8002B408: b           L_8002B5B0
    // 0x8002B40C: nop

        goto L_8002B5B0;
    // 0x8002B40C: nop

L_8002B410:
    // 0x8002B410: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B414: lw          $t3, 0x7C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X7C);
    // 0x8002B418: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8002B41C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002B420: lh          $t4, 0xA($t0)
    ctx->r12 = MEM_H(ctx->r8, 0XA);
    // 0x8002B424: beq         $t4, $zero, L_8002B438
    if (ctx->r12 == 0) {
        // 0x8002B428: nop
    
            goto L_8002B438;
    }
    // 0x8002B428: nop

    // 0x8002B42C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B430: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002B434: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
L_8002B438:
    // 0x8002B438: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002B43C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B440: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002B444: jal         0x8002CC9C
    // 0x8002B448: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    func_8002CC9C(rdram, ctx);
        goto after_4;
    // 0x8002B448: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    after_4:
    // 0x8002B44C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8002B450: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002B454: sw          $t5, 0x84($t1)
    MEM_W(0X84, ctx->r9) = ctx->r13;
    // 0x8002B458: b           L_8002B5B0
    // 0x8002B45C: nop

        goto L_8002B5B0;
    // 0x8002B45C: nop

L_8002B460:
    // 0x8002B460: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8002B464: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B468: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B46C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B470: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B474: jal         0x8002B7C8
    // 0x8002B478: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8002B7C8(rdram, ctx);
        goto after_5;
    // 0x8002B478: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_5:
    // 0x8002B47C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B480: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B484: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002B488: jal         0x8002B684
    // 0x8002B48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8002B684(rdram, ctx);
        goto after_6;
    // 0x8002B48C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8002B490: b           L_8002B5B0
    // 0x8002B494: nop

        goto L_8002B5B0;
    // 0x8002B494: nop

L_8002B498:
    // 0x8002B498: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B49C: lw          $t3, 0x7C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X7C);
    // 0x8002B4A0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8002B4A4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002B4A8: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x8002B4AC: sw          $zero, 0x88($t4)
    MEM_W(0X88, ctx->r12) = 0;
    // 0x8002B4B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002B4B4: jal         0x80021884
    // 0x8002B4B8: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    func_80021884(rdram, ctx);
        goto after_7;
    // 0x8002B4B8: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    after_7:
    // 0x8002B4BC: b           L_8002B5B0
    // 0x8002B4C0: nop

        goto L_8002B5B0;
    // 0x8002B4C0: nop

L_8002B4C4:
    // 0x8002B4C4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8002B4C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B4CC: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B4D0: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B4D4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B4D8: jal         0x8002B7C8
    // 0x8002B4DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8002B7C8(rdram, ctx);
        goto after_8;
    // 0x8002B4DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x8002B4E0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B4E4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8002B4E8: lw          $t5, 0x7C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X7C);
    // 0x8002B4EC: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8002B4F0: swc1        $f10, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f10.u32l;
    // 0x8002B4F4: b           L_8002B5B0
    // 0x8002B4F8: nop

        goto L_8002B5B0;
    // 0x8002B4F8: nop

L_8002B4FC:
    // 0x8002B4FC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8002B500: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B504: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B508: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B50C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B510: jal         0x8002B7C8
    // 0x8002B514: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8002B7C8(rdram, ctx);
        goto after_9;
    // 0x8002B514: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_9:
    // 0x8002B518: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B51C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8002B520: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002B524: sw          $t2, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r10;
    // 0x8002B528: b           L_8002B5B0
    // 0x8002B52C: nop

        goto L_8002B5B0;
    // 0x8002B52C: nop

L_8002B530:
    // 0x8002B530: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8002B534: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B538: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B53C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B540: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B544: jal         0x8002B7C8
    // 0x8002B548: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8002B7C8(rdram, ctx);
        goto after_10;
    // 0x8002B548: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_10:
    // 0x8002B54C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B550: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B554: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8002B558: lw          $t4, 0x7C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X7C);
    // 0x8002B55C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8002B560: jal         0x8002CC9C
    // 0x8002B564: lw          $a2, 0xC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC);
    func_8002CC9C(rdram, ctx);
        goto after_11;
    // 0x8002B564: lw          $a2, 0xC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC);
    after_11:
    // 0x8002B568: b           L_8002B5B0
    // 0x8002B56C: nop

        goto L_8002B5B0;
    // 0x8002B56C: nop

L_8002B570:
    // 0x8002B570: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8002B574: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B578: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B57C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B580: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8002B584: jal         0x8002B7C8
    // 0x8002B588: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8002B7C8(rdram, ctx);
        goto after_12;
    // 0x8002B588: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_12:
    // 0x8002B58C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B590: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B594: lw          $t5, 0x7C($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X7C);
    // 0x8002B598: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8002B59C: lh          $a1, 0x8($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X8);
    // 0x8002B5A0: jal         0x8002B684
    // 0x8002B5A4: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    func_8002B684(rdram, ctx);
        goto after_13;
    // 0x8002B5A4: lw          $a2, 0xC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XC);
    after_13:
    // 0x8002B5A8: b           L_8002B5B0
    // 0x8002B5AC: nop

        goto L_8002B5B0;
    // 0x8002B5AC: nop

L_8002B5B0:
    // 0x8002B5B0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8002B5B4: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x8002B5B8: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8002B5BC: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8002B5C0: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8002B5C4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002B5C8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8002B5CC: subu        $t4, $t3, $t0
    ctx->r12 = SUB32(ctx->r11, ctx->r8);
    // 0x8002B5D0: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8002B5D4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002B5D8: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8002B5DC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8002B5E0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B5E4: lw          $t1, 0x7C($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X7C);
    // 0x8002B5E8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8002B5EC: sw          $t7, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->r15;
    // 0x8002B5F0: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8002B5F4: lw          $t6, 0x7C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X7C);
    // 0x8002B5F8: bne         $t6, $zero, L_8002B608
    if (ctx->r14 != 0) {
        // 0x8002B5FC: nop
    
            goto L_8002B608;
    }
    // 0x8002B5FC: nop

    // 0x8002B600: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8002B604: sw          $zero, 0x80($t3)
    MEM_W(0X80, ctx->r11) = 0;
L_8002B608:
    // 0x8002B608: jal         0x800217F4
    // 0x8002B60C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800217F4(rdram, ctx);
        goto after_14;
    // 0x8002B60C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_14:
    // 0x8002B610: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8002B614: lw          $t4, 0x7C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X7C);
    // 0x8002B618: bne         $t4, $zero, L_8002ADAC
    if (ctx->r12 != 0) {
        // 0x8002B61C: nop
    
            goto L_8002ADAC;
    }
    // 0x8002B61C: nop

L_8002B620:
    // 0x8002B620: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8002B624: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002B628: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    // 0x8002B62C: addiu       $a2, $sp, 0x3E
    ctx->r6 = ADD32(ctx->r29, 0X3E);
    // 0x8002B630: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8002B634: jal         0x8002B7C8
    // 0x8002B638: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8002B7C8(rdram, ctx);
        goto after_15;
    // 0x8002B638: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_15:
    // 0x8002B63C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8002B640: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8002B644: lw          $t1, 0x70($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X70);
    // 0x8002B648: lw          $t7, 0x74($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X74);
    // 0x8002B64C: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002B650: beq         $at, $zero, L_8002B664
    if (ctx->r1 == 0) {
        // 0x8002B654: nop
    
            goto L_8002B664;
    }
    // 0x8002B654: nop

    // 0x8002B658: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8002B65C: lw          $t2, 0x74($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X74);
    // 0x8002B660: sw          $t2, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->r10;
L_8002B664:
    // 0x8002B664: b           L_8002B674
    // 0x8002B668: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
        goto L_8002B674;
    // 0x8002B668: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8002B66C: b           L_8002B674
    // 0x8002B670: nop

        goto L_8002B674;
    // 0x8002B670: nop

L_8002B674:
    // 0x8002B674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B678: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8002B67C: jr          $ra
    // 0x8002B680: nop

    return;
    // 0x8002B680: nop

;}
RECOMP_FUNC void bsledge_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801258: jal         0x800839B8
    // 0x8080125C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080125C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801260: jal         0x808001A8
    // 0x80801264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001A8_bsledge(rdram, ctx);
        goto after_1;
    // 0x80801264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080126C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801270: jr          $ra
    // 0x80801274: nop

    return;
    // 0x80801274: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842F8: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842F8);
    return;
    // 0x800842FC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80800FC8_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FD0: jal         0x808006F0
    // 0x80800FD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800FD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FDC: jal         0x800845D8
    // 0x80800FE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800FE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800FE4: lui         $a2, 0x3F30
    ctx->r6 = S32(0X3F30 << 16);
    // 0x80800FE8: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80800FEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FF0: jal         0x800845E0
    // 0x80800FF4: addiu       $a1, $zero, 0x147
    ctx->r5 = ADD32(0, 0X147);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800FF4: addiu       $a1, $zero, 0x147
    ctx->r5 = ADD32(0, 0X147);
    after_2:
    // 0x80800FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801000: jr          $ra
    // 0x80801004: nop

    return;
    // 0x80801004: nop

;}
RECOMP_FUNC void func_80800718_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080071C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800724: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800728: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080072C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800730: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800734: beq         $t6, $at, L_8080074C
    if (ctx->r14 == ctx->r1) {
        // 0x80800738: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080074C;
    }
    // 0x80800738: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080073C: beq         $t6, $at, L_8080083C
    if (ctx->r14 == ctx->r1) {
        // 0x80800740: nop
    
            goto L_8080083C;
    }
    // 0x80800740: nop

    // 0x80800744: b           L_8080087C
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080087C;
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080074C:
    // 0x8080074C: jal         0x800F54E4
    // 0x80800750: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800750: nop

    after_0:
    // 0x80800754: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800758: jal         0x800F6A38
    // 0x8080075C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6A38(rdram, ctx);
        goto after_1;
    // 0x8080075C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800760: beq         $v0, $zero, L_808007FC
    if (ctx->r2 == 0) {
        // 0x80800764: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_808007FC;
    }
    // 0x80800764: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800768: jal         0x800F5C94
    // 0x8080076C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800F5C94(rdram, ctx);
        goto after_2;
    // 0x8080076C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x80800770: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800774: jal         0x800F5D18
    // 0x80800778: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800F5D18(rdram, ctx);
        goto after_3;
    // 0x80800778: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x8080077C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800780: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800784: jal         0x800F64A4
    // 0x80800788: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x80800788: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8080078C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800790: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800794: beq         $v1, $at, L_80800878
    if (ctx->r3 == ctx->r1) {
        // 0x80800798: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80800878;
    }
    // 0x80800798: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8080079C: beq         $v1, $at, L_80800878
    if (ctx->r3 == ctx->r1) {
        // 0x808007A0: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80800878;
    }
    // 0x808007A0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808007A4: bne         $t7, $zero, L_808007B4
    if (ctx->r15 != 0) {
        // 0x808007A8: nop
    
            goto L_808007B4;
    }
    // 0x808007A8: nop

    // 0x808007AC: beql        $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x808007B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080087C;
    }
    goto skip_0;
    // 0x808007B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_808007B4:
    // 0x808007B4: jal         0x800D9078
    // 0x808007B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x808007B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_5:
    // 0x808007BC: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x808007C0: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800878;
    }
    // 0x808007C0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808007C4: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x808007C8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808007CC: jal         0x800F7D90
    // 0x808007D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800F7D90(rdram, ctx);
        goto after_6;
    // 0x808007D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: jal         0x80101FDC
    // 0x808007DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808007DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: jal         0x8080088C
    // 0x808007E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    chhotwaterpoolbits_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x808007E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x808007EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007F4: b           L_80800878
    // 0x808007F8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800878;
    // 0x808007F8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808007FC:
    // 0x808007FC: jal         0x800F5A00
    // 0x80800800: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F5A00(rdram, ctx);
        goto after_9;
    // 0x80800800: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x80800804: jal         0x800F5628
    // 0x80800808: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800F5628(rdram, ctx);
        goto after_10;
    // 0x80800808: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_10:
    // 0x8080080C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800810: jal         0x800F55FC
    // 0x80800814: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800F55FC(rdram, ctx);
        goto after_11;
    // 0x80800814: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x80800818: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8080081C: bgez        $t8, L_8080082C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800820: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_8080082C;
    }
    // 0x80800820: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800824: jal         0x800EE7F8
    // 0x80800828: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x80800828: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_12:
L_8080082C:
    // 0x8080082C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1268, 0X920) << 16);
    // 0x80800830: lwc1        $f6, 0x920($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1268, 0X920));
    // 0x80800834: b           L_80800878
    // 0x80800838: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800878;
    // 0x80800838: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_8080083C:
    // 0x8080083C: jal         0x800D9078
    // 0x80800840: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_13;
    // 0x80800840: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_13:
    // 0x80800844: beql        $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x80800848: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080087C;
    }
    goto skip_1;
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080084C: jal         0x800F54E4
    // 0x80800850: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x80800850: nop

    after_14:
    // 0x80800854: jal         0x800F5578
    // 0x80800858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5578(rdram, ctx);
        goto after_15;
    // 0x80800858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x8080085C: blez        $v0, L_80800878
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800860: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800878;
    }
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: jal         0x80101FDC
    // 0x80800868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x80800868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8080086C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1268, 0X924) << 16);
    // 0x80800870: lwc1        $f8, 0x924($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1268, 0X924));
    // 0x80800874: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800878:
    // 0x80800878: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080087C:
    // 0x8080087C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800880: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void chdinoswitches_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1048, 0XCC0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xCC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XCC0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xCC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XCC0));
;}
RECOMP_FUNC void func_80801A60_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801A64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801A68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801A6C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80801A70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801A74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A78: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80801A7C: beq         $t6, $at, L_80801E4C
    if (ctx->r14 == ctx->r1) {
        // 0x80801A80: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801E4C;
    }
    // 0x80801A80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801A84: beq         $t6, $at, L_80801A9C
    if (ctx->r14 == ctx->r1) {
        // 0x80801A88: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801A9C;
    }
    // 0x80801A88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801A8C: beql        $t6, $at, L_80801DAC
    if (ctx->r14 == ctx->r1) {
        // 0x80801A90: lbu         $a0, 0x5F($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X5F);
            goto L_80801DAC;
    }
    goto skip_0;
    // 0x80801A90: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    skip_0:
    // 0x80801A94: b           L_80801E50
    // 0x80801A98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E50;
    // 0x80801A98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801A9C:
    // 0x80801A9C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801AA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AA8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80801AAC: nop

    // 0x80801AB0: bc1f        L_80801AC8
    if (!c1cs) {
        // 0x80801AB4: nop
    
            goto L_80801AC8;
    }
    // 0x80801AB4: nop

    // 0x80801AB8: jal         0x80801790
    // 0x80801ABC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801790_chlakemonster(rdram, ctx);
        goto after_0;
    // 0x80801ABC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80801AC0: b           L_80801E50
    // 0x80801AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E50;
    // 0x80801AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801AC8:
    // 0x80801AC8: jal         0x800D8FF8
    // 0x80801ACC: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801ACC: nop

    after_1:
    // 0x80801AD0: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801AD4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801AD8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801ADC: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80801AE0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801AE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801AE8: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80801AEC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801AF0: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80801AF4: jal         0x8001210C
    // 0x80801AF8: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    func_8001210C(rdram, ctx);
        goto after_2;
    // 0x80801AF8: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_2:
    // 0x80801AFC: beq         $v0, $zero, L_80801CDC
    if (ctx->r2 == 0) {
        // 0x80801B00: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1748, 0X1FB8) << 16);
            goto L_80801CDC;
    }
    // 0x80801B00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FB8) << 16);
    // 0x80801B04: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801B08: lwc1        $f8, 0x1FB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FB8));
    // 0x80801B0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801B10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801B14: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801B18: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80801B1C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801B20: jal         0x800DC128
    // 0x80801B24: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80801B24: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80801B28: beq         $v0, $zero, L_80801B50
    if (ctx->r2 == 0) {
        // 0x80801B2C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80801B50;
    }
    // 0x80801B2C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801B30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801B34: beq         $v0, $at, L_80801BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80801B38: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80801BB4;
    }
    // 0x80801B38: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801B3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801B40: beq         $v0, $at, L_80801C18
    if (ctx->r2 == ctx->r1) {
        // 0x80801B44: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80801C18;
    }
    // 0x80801B44: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801B48: b           L_80801C78
    // 0x80801B4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_80801C78;
    // 0x80801B4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80801B50:
    // 0x80801B50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801B54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FBC) << 16);
    // 0x80801B58: lwc1        $f4, 0x1FBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FBC));
    // 0x80801B5C: lui         $at, 0x43FC
    ctx->r1 = S32(0X43FC << 16);
    // 0x80801B60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801B64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FC0) << 16);
    // 0x80801B68: lwc1        $f8, 0x1FC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FC0));
    // 0x80801B6C: lui         $a3, 0xC53E
    ctx->r7 = S32(0XC53E << 16);
    // 0x80801B70: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80801B74: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801B78: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801B7C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80801B80: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80801B84: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80801B88: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80801B8C: jal         0x808018D8
    // 0x80801B90: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    chlakemonster_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80801B90: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80801B94: lui         $a3, 0xC53E
    ctx->r7 = S32(0XC53E << 16);
    // 0x80801B98: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80801B9C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801BA0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801BA4: jal         0x808019D4
    // 0x80801BA8: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    chlakemonster_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80801BA8: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_5:
    // 0x80801BAC: b           L_80801C78
    // 0x80801BB0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_80801C78;
    // 0x80801BB0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80801BB4:
    // 0x80801BB4: lui         $at, 0x43FC
    ctx->r1 = S32(0X43FC << 16);
    // 0x80801BB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801BBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FC4) << 16);
    // 0x80801BC0: lwc1        $f16, 0x1FC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FC4));
    // 0x80801BC4: lui         $at, 0xC342
    ctx->r1 = S32(0XC342 << 16);
    // 0x80801BC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801BCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FC8) << 16);
    // 0x80801BD0: lwc1        $f4, 0x1FC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FC8));
    // 0x80801BD4: lui         $a3, 0xC53E
    ctx->r7 = S32(0XC53E << 16);
    // 0x80801BD8: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80801BDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801BE0: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80801BE4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80801BE8: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80801BEC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80801BF0: jal         0x808018D8
    // 0x80801BF4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    chlakemonster_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80801BF4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80801BF8: lui         $a3, 0xC53E
    ctx->r7 = S32(0XC53E << 16);
    // 0x80801BFC: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80801C00: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801C04: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801C08: jal         0x808019D4
    // 0x80801C0C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    chlakemonster_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80801C0C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_7:
    // 0x80801C10: b           L_80801C78
    // 0x80801C14: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_80801C78;
    // 0x80801C14: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80801C18:
    // 0x80801C18: lui         $at, 0xC342
    ctx->r1 = S32(0XC342 << 16);
    // 0x80801C1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801C20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FCC) << 16);
    // 0x80801C24: lwc1        $f8, 0x1FCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FCC));
    // 0x80801C28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801C30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FD0) << 16);
    // 0x80801C34: lwc1        $f16, 0x1FD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FD0));
    // 0x80801C38: lui         $a3, 0xC53E
    ctx->r7 = S32(0XC53E << 16);
    // 0x80801C3C: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80801C40: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801C44: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80801C48: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80801C4C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80801C50: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80801C54: jal         0x808018D8
    // 0x80801C58: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    chlakemonster_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80801C58: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x80801C5C: lui         $a3, 0xC53E
    ctx->r7 = S32(0XC53E << 16);
    // 0x80801C60: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80801C64: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801C68: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801C6C: jal         0x808019D4
    // 0x80801C70: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    chlakemonster_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80801C70: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_9:
    // 0x80801C74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80801C78:
    // 0x80801C78: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C80: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801C84: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80801C88: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X20BC) << 16);
    // 0x80801C8C: bc1f        L_80801CC8
    if (!c1cs) {
        // 0x80801C90: nop
    
            goto L_80801CC8;
    }
    // 0x80801C90: nop

    // 0x80801C94: jal         0x80089D18
    // 0x80801C98: addiu       $a2, $a2, 0x20BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X20BC));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80801C98: addiu       $a2, $a2, 0x20BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X20BC));
    after_10:
    // 0x80801C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801CA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801CA4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801CA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801CAC: jal         0x800DC178
    // 0x80801CB0: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80801CB0: nop

    after_11:
    // 0x80801CB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FD4) << 16);
    // 0x80801CB8: lwc1        $f6, 0x1FD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FD4));
    // 0x80801CBC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801CC0: b           L_80801CDC
    // 0x80801CC4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80801CDC;
    // 0x80801CC4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80801CC8:
    // 0x80801CC8: jal         0x800D8FF8
    // 0x80801CCC: nop

    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x80801CCC: nop

    after_12:
    // 0x80801CD0: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801CD4: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80801CD8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80801CDC:
    // 0x80801CDC: lbu         $t7, 0x5F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801CE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801CE4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801CE8: bne         $t7, $zero, L_80801D04
    if (ctx->r15 != 0) {
        // 0x80801CEC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1748, 0X1FD8) << 16);
            goto L_80801D04;
    }
    // 0x80801CEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FD8) << 16);
    // 0x80801CF0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X22C8) << 16);
    // 0x80801CF4: jal         0x800C4350
    // 0x80801CF8: addiu       $a2, $a2, 0x22C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X22C8));
    func_800C4350(rdram, ctx);
        goto after_13;
    // 0x80801CF8: addiu       $a2, $a2, 0x22C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X22C8));
    after_13:
    // 0x80801CFC: b           L_80801E4C
    // 0x80801D00: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
        goto L_80801E4C;
    // 0x80801D00: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
L_80801D04:
    // 0x80801D04: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801D08: lwc1        $f18, 0x1FD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FD8));
    // 0x80801D0C: lui         $a2, 0xC454
    ctx->r6 = S32(0XC454 << 16);
    // 0x80801D10: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80801D14: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80801D18: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x80801D1C: bc1fl       L_80801D48
    if (!c1cs) {
        // 0x80801D20: lui         $at, 0xC47A
        ctx->r1 = S32(0XC47A << 16);
            goto L_80801D48;
    }
    goto skip_1;
    // 0x80801D20: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    skip_1:
    // 0x80801D24: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801D28: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x80801D2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801D30: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80801D34: jal         0x800F10B4
    // 0x80801D38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80801D38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80801D3C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80801D40: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801D44: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
L_80801D48:
    // 0x80801D48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801D4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801D50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801D54: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x80801D58: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801D5C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80801D60: jal         0x800F10B4
    // 0x80801D64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80801D64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80801D68: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801D6C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80801D70: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801D74: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801D78: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801D7C: jal         0x800C3058
    // 0x80801D80: nop

    func_800C3058(rdram, ctx);
        goto after_16;
    // 0x80801D80: nop

    after_16:
    // 0x80801D84: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801D88: jal         0x800C31DC
    // 0x80801D8C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    func_800C31DC(rdram, ctx);
        goto after_17;
    // 0x80801D8C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_17:
    // 0x80801D90: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801D94: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80801D98: jal         0x800C4350
    // 0x80801D9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_18;
    // 0x80801D9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x80801DA0: b           L_80801E50
    // 0x80801DA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E50;
    // 0x80801DA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801DA8: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
L_80801DAC:
    // 0x80801DAC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801DB0: beql        $a0, $zero, L_80801E50
    if (ctx->r4 == 0) {
        // 0x80801DB4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801E50;
    }
    goto skip_2;
    // 0x80801DB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80801DB8: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801DBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801DC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FDC) << 16);
    // 0x80801DC4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80801DC8: nop

    // 0x80801DCC: bc1f        L_80801E40
    if (!c1cs) {
        // 0x80801DD0: nop
    
            goto L_80801E40;
    }
    // 0x80801DD0: nop

    // 0x80801DD4: lwc1        $f12, 0x1FDC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FDC));
    // 0x80801DD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1FE0) << 16);
    // 0x80801DDC: lwc1        $f2, 0x54($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801DE0: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80801DE4: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x80801DE8: lwc1        $f4, 0x1FE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1FE0));
    // 0x80801DEC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80801DF0: nop

    // 0x80801DF4: bc1fl       L_80801E08
    if (!c1cs) {
        // 0x80801DF8: lwc1        $f8, 0x34($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
            goto L_80801E08;
    }
    goto skip_3;
    // 0x80801DF8: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    skip_3:
    // 0x80801DFC: mul.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80801E00: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80801E04: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
L_80801E08:
    // 0x80801E08: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801E0C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801E10: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801E14: jal         0x800C3058
    // 0x80801E18: nop

    func_800C3058(rdram, ctx);
        goto after_19;
    // 0x80801E18: nop

    after_19:
    // 0x80801E1C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801E20: jal         0x800C31DC
    // 0x80801E24: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    func_800C31DC(rdram, ctx);
        goto after_20;
    // 0x80801E24: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_20:
    // 0x80801E28: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80801E2C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80801E30: jal         0x800C4350
    // 0x80801E34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_21;
    // 0x80801E34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80801E38: b           L_80801E50
    // 0x80801E3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801E50;
    // 0x80801E3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E40:
    // 0x80801E40: jal         0x800C2FDC
    // 0x80801E44: nop

    func_800C2FDC(rdram, ctx);
        goto after_22;
    // 0x80801E44: nop

    after_22:
    // 0x80801E48: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
L_80801E4C:
    // 0x80801E4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E50:
    // 0x80801E50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801E54: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801E58: jr          $ra
    // 0x80801E5C: nop

    return;
    // 0x80801E5C: nop

;}
RECOMP_FUNC void _subaddiemulti_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0B8: syscall     826
    recomp_syscall_handler(rdram, ctx, 0x8008A0B8);
    return;
    // 0x8008A0BC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _chfactorytwinklies_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086508: syscall     333
    recomp_syscall_handler(rdram, ctx, 0x80086508);
    return;
    // 0x8008650C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800028_chdiggerbossdeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8080002C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800030: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800034: jr          $ra
    // 0x80800038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_80800650_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800654: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800658: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080065C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800660: jal         0x800EB854
    // 0x80800664: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EB854(rdram, ctx);
        goto after_0;
    // 0x80800664: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800668: beq         $v0, $zero, L_808006C8
    if (ctx->r2 == 0) {
        // 0x8080066C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006C8;
    }
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800670: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800674: beq         $v0, $at, L_8080068C
    if (ctx->r2 == ctx->r1) {
        // 0x80800678: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080068C;
    }
    // 0x80800678: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080067C: beq         $v0, $at, L_808006DC
    if (ctx->r2 == ctx->r1) {
        // 0x80800680: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006DC;
    }
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: b           L_808006E8
    // 0x80800688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006E8;
    // 0x80800688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080068C:
    // 0x8080068C: jal         0x800DF830
    // 0x80800690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_1;
    // 0x80800690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800694: jal         0x800DF410
    // 0x80800698: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DF410(rdram, ctx);
        goto after_2;
    // 0x80800698: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_2:
    // 0x8080069C: jal         0x800D674C
    // 0x808006A0: addiu       $a0, $zero, 0x959
    ctx->r4 = ADD32(0, 0X959);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x808006A0: addiu       $a0, $zero, 0x959
    ctx->r4 = ADD32(0, 0X959);
    after_3:
    // 0x808006A4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808006A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x808006AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808006B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808006B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808006B8: jal         0x800DE498
    // 0x808006BC: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    func_800DE498(rdram, ctx);
        goto after_4;
    // 0x808006BC: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x808006C0: b           L_808006E8
    // 0x808006C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006E8;
    // 0x808006C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006C8:
    // 0x808006C8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x808006CC: jal         0x80101808
    // 0x808006D0: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    func_80101808(rdram, ctx);
        goto after_5;
    // 0x808006D0: addiu       $a1, $a1, 0x17D0
    ctx->r5 = ADD32(ctx->r5, 0X17D0);
    after_5:
    // 0x808006D4: b           L_808006E8
    // 0x808006D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006E8;
    // 0x808006D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006DC:
    // 0x808006DC: jal         0x80804EFC
    // 0x808006E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80804EFC_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808006E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808006E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006E8:
    // 0x808006E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006F0: jr          $ra
    // 0x808006F4: nop

    return;
    // 0x808006F4: nop

;}
RECOMP_FUNC void func_8080002C_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: lui         $a1, 0x3FAC
    ctx->r5 = S32(0X3FAC << 16);
    // 0x80800038: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x8080003C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800040: jal         0x8009D7A4
    // 0x80800044: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_8009D7A4(rdram, ctx);
        goto after_0;
    // 0x80800044: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void _idtwinklea_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EB8: syscall     746
    recomp_syscall_handler(rdram, ctx, 0x80088EB8);
    return;
    // 0x80088EBC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gcsectionDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088258: syscall     677
    recomp_syscall_handler(rdram, ctx, 0x80088258);
    return;
    // 0x8008825C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808009C8_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808009D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808009D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009DC: jal         0x808004A8
    // 0x808009E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_808004A8_bsledge(rdram, ctx);
        goto after_0;
    // 0x808009E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808009E4: jal         0x808004D8
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004D8_bsledge(rdram, ctx);
        goto after_1;
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808009EC: jal         0x8008CAC8
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_2;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(304, 0X1318) << 16);
    // 0x808009F8: lwc1        $f4, 0x1318($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(304, 0X1318));
    // 0x808009FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800A00: nop

    // 0x80800A04: bc1f        L_80800A5C
    if (!c1cs) {
        // 0x80800A08: nop
    
            goto L_80800A5C;
    }
    // 0x80800A08: nop

    // 0x80800A0C: jal         0x808003D0
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D0_bsledge(rdram, ctx);
        goto after_3;
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A14: beq         $v0, $zero, L_80800A20
    if (ctx->r2 == 0) {
        // 0x80800A18: nop
    
            goto L_80800A20;
    }
    // 0x80800A18: nop

    // 0x80800A1C: addiu       $s1, $zero, 0xAA
    ctx->r17 = ADD32(0, 0XAA);
L_80800A20:
    // 0x80800A20: jal         0x80800450
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800450_bsledge(rdram, ctx);
        goto after_4;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A28: beq         $v0, $zero, L_80800A34
    if (ctx->r2 == 0) {
        // 0x80800A2C: nop
    
            goto L_80800A34;
    }
    // 0x80800A2C: nop

    // 0x80800A30: addiu       $s1, $zero, 0xA7
    ctx->r17 = ADD32(0, 0XA7);
L_80800A34:
    // 0x80800A34: jal         0x80800000
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsledge(rdram, ctx);
        goto after_5;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A3C: beq         $v0, $zero, L_80800A48
    if (ctx->r2 == 0) {
        // 0x80800A40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A48;
    }
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: addiu       $s1, $zero, 0xA9
    ctx->r17 = ADD32(0, 0XA9);
L_80800A48:
    // 0x80800A48: jal         0x80091A58
    // 0x80800A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x80800A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800A50: beq         $v0, $zero, L_80800A5C
    if (ctx->r2 == 0) {
        // 0x80800A54: nop
    
            goto L_80800A5C;
    }
    // 0x80800A54: nop

    // 0x80800A58: addiu       $s1, $zero, 0x2F
    ctx->r17 = ADD32(0, 0X2F);
L_80800A5C:
    // 0x80800A5C: jal         0x8008CAEC
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_7;
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A64: beq         $v0, $zero, L_80800A70
    if (ctx->r2 == 0) {
        // 0x80800A68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A70;
    }
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: addiu       $s1, $zero, 0xA6
    ctx->r17 = ADD32(0, 0XA6);
L_80800A70:
    // 0x80800A70: jal         0x8009E5C8
    // 0x80800A74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800A74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80800A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800A80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800A84: jr          $ra
    // 0x80800A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _mlspline_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089140: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089140);
    return;
    // 0x80089144: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_800905C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800905C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800905C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800905CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800905D0: jal         0x800F54E4
    // 0x800905D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800905D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800905D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800905DC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800905E0: jal         0x800F7DE8
    // 0x800905E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7DE8(rdram, ctx);
        goto after_1;
    // 0x800905E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800905E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800905EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800905F0: jr          $ra
    // 0x800905F4: nop

    return;
    // 0x800905F4: nop

;}
RECOMP_FUNC void func_800FC618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC61C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800FC624: jal         0x800FC508
    // 0x800FC628: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_800FC508(rdram, ctx);
        goto after_0;
    // 0x800FC628: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // 0x800FC62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC634: jr          $ra
    // 0x800FC638: nop

    return;
    // 0x800FC638: nop

;}
RECOMP_FUNC void func_80800000_chperspexbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800010: bne         $a1, $at, L_8080006C
    if (ctx->r5 != ctx->r1) {
        // 0x80800014: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8080006C;
    }
    // 0x80800014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800018: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080001C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2088, 0X90) << 16);
    // 0x80800020: addiu       $t7, $t7, 0x90
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2088, 0X90));
    // 0x80800024: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    // 0x80800028: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x8080002C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800030: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800034: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800038: jal         0x800BABB8
    // 0x8080003C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x8080003C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800040: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2088, 0X124) << 16);
    // 0x80800044: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800048: addiu       $a2, $a2, 0x124
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2088, 0X124));
    // 0x8080004C: jal         0x80089D18
    // 0x80800050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800054: jal         0x800FC6B0
    // 0x80800058: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800FC6B0(rdram, ctx);
        goto after_2;
    // 0x80800058: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x8080005C: jal         0x800FFAB0
    // 0x80800060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800060: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800064: b           L_80800070
    // 0x80800068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800070;
    // 0x80800068: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080006C:
    // 0x8080006C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800070:
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D80: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082D80);
    return;
    // 0x80082D84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _fxspgold_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AC8: syscall     721
    recomp_syscall_handler(rdram, ctx, 0x80088AC8);
    return;
    // 0x80088ACC: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void func_808000C0_chsecreteggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x808000CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808000D0: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    // 0x808000D4: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x808000D8: bgezl       $t8, L_8080010C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080010C;
    }
    goto skip_0;
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000E0: jal         0x800DA298
    // 0x808000E4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000E4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000E8: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000EC: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800100;
    }
    // 0x808000EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000F0: jal         0x800FFA88
    // 0x808000F4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x808000F4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_1:
    // 0x808000F8: b           L_8080010C
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080010C;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800100:
    // 0x80800100: jal         0x8010A570
    // 0x80800104: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800104: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080010C:
    // 0x8080010C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void baroll_getIdeal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C548: lw          $t6, 0xF4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C54C: jr          $ra
    // 0x8009C550: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x8009C550: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void chpotogoldbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007E4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808007E8: addiu       $a0, $zero, 0x408
    ctx->r4 = ADD32(0, 0X408);
    // 0x808007EC: jal         0x80101180
    // 0x808007F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808007F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808007F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007FC: jr          $ra
    // 0x80800800: nop

    return;
    // 0x80800800: nop

;}
RECOMP_FUNC void func_808005C8_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1080, 0XB14) << 16);
    // 0x808005D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005D8: jal         0x80086038
    // 0x808005DC: addiu       $a1, $a1, 0xB14
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB14));
    _chpowerhut_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808005DC: addiu       $a1, $a1, 0xB14
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1080, 0XB14));
    after_0:
    // 0x808005E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005E4: jal         0x80100094
    // 0x808005E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808005E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808005EC: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x808005F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005F4: jal         0x80100094
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808005FC: sb          $zero, 0x19($v0)
    MEM_B(0X19, ctx->r2) = 0;
    // 0x80800600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800608: jr          $ra
    // 0x8080060C: nop

    return;
    // 0x8080060C: nop

;}
RECOMP_FUNC void func_80801580_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801588: jal         0x800F54E4
    // 0x8080158C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080158C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801590: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801594: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801598: jal         0x800F64A4
    // 0x8080159C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x8080159C: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_1:
    // 0x808015A0: bne         $v0, $zero, L_808015B0
    if (ctx->r2 != 0) {
        // 0x808015A4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808015B0;
    }
    // 0x808015A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808015A8: b           L_808015F4
    // 0x808015AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015F4;
    // 0x808015AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808015B0:
    // 0x808015B0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808015B4: jal         0x8010CB84
    // 0x808015B8: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    func_8010CB84(rdram, ctx);
        goto after_2;
    // 0x808015B8: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_2:
    // 0x808015BC: bne         $v0, $zero, L_808015CC
    if (ctx->r2 != 0) {
        // 0x808015C0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808015CC;
    }
    // 0x808015C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808015C4: b           L_808015F4
    // 0x808015C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015F4;
    // 0x808015C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808015CC:
    // 0x808015CC: jal         0x800F640C
    // 0x808015D0: addiu       $a1, $zero, 0x3CA
    ctx->r5 = ADD32(0, 0X3CA);
    func_800F640C(rdram, ctx);
        goto after_3;
    // 0x808015D0: addiu       $a1, $zero, 0x3CA
    ctx->r5 = ADD32(0, 0X3CA);
    after_3:
    // 0x808015D4: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808015D8: bne         $t6, $zero, L_808015F4
    if (ctx->r14 != 0) {
        // 0x808015DC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808015F4;
    }
    // 0x808015DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808015E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808015E4: jal         0x800F640C
    // 0x808015E8: addiu       $a1, $zero, 0x3CB
    ctx->r5 = ADD32(0, 0X3CB);
    func_800F640C(rdram, ctx);
        goto after_4;
    // 0x808015E8: addiu       $a1, $zero, 0x3CB
    ctx->r5 = ADD32(0, 0X3CB);
    after_4:
    // 0x808015EC: slt         $t7, $zero, $v0
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808015F0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_808015F4:
    // 0x808015F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808015FC: jr          $ra
    // 0x80801600: nop

    return;
    // 0x80801600: nop

;}
RECOMP_FUNC void func_80800024_chmole_mine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x800899D0
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800040: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800044: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800048: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x8080004C: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800050: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80800054: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800058: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8080005C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800060: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800064: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x80800068: bgez        $t4, L_8080007C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080006C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080007C;
    }
    // 0x8080006C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800074: nop

    // 0x80800078: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080007C:
    // 0x8080007C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void _chcollballcontrol_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EC0: syscall     467
    recomp_syscall_handler(rdram, ctx, 0x80086EC0);
    return;
    // 0x80086EC4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80803828_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803828: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080382C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803830: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80803834: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803838: jal         0x8009E6EC
    // 0x8080383C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x8080383C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80803840: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80803844: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80803848: bne         $v0, $at, L_80803864
    if (ctx->r2 != ctx->r1) {
        // 0x8080384C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80803864;
    }
    // 0x8080384C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803850: lw          $t6, 0x114($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X114);
    // 0x80803854: beql        $t6, $zero, L_80803870
    if (ctx->r14 == 0) {
        // 0x80803858: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803870;
    }
    goto skip_0;
    // 0x80803858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080385C: b           L_8080386C
    // 0x80803860: sw          $zero, 0x114($v1)
    MEM_W(0X114, ctx->r3) = 0;
        goto L_8080386C;
    // 0x80803860: sw          $zero, 0x114($v1)
    MEM_W(0X114, ctx->r3) = 0;
L_80803864:
    // 0x80803864: jal         0x80805994
    // 0x80803868: nop

    bsfirstp_entrypoint_26(rdram, ctx);
        goto after_1;
    // 0x80803868: nop

    after_1:
L_8080386C:
    // 0x8080386C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803870:
    // 0x80803870: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803874: jr          $ra
    // 0x80803878: nop

    return;
    // 0x80803878: nop

;}
RECOMP_FUNC void bsbkflamethrower_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800238: jal         0x80800094
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800094_bsbkflamethrower(rdram, ctx);
        goto after_0;
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800248: jr          $ra
    // 0x8080024C: nop

    return;
    // 0x8080024C: nop

;}
RECOMP_FUNC void _gctransitionDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881E0: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881E0);
    return;
    // 0x800881E4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void glzone_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: blez        $a2, L_808001C8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800108: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001C8;
    }
    // 0x80800108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080010C: andi        $t0, $a2, 0x3
    ctx->r8 = ctx->r6 & 0X3;
    // 0x80800110: beq         $t0, $zero, L_80800148
    if (ctx->r8 == 0) {
        // 0x80800114: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_80800148;
    }
    // 0x80800114: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80800118: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8080011C:
    // 0x8080011C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80800120: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800124: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80800128: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x8080012C: beq         $t8, $zero, L_8080013C
    if (ctx->r24 == 0) {
        // 0x80800130: nop
    
            goto L_8080013C;
    }
    // 0x80800130: nop

    // 0x80800134: jr          $ra
    // 0x80800138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080013C:
    // 0x8080013C: bne         $a3, $v0, L_8080011C
    if (ctx->r7 != ctx->r2) {
        // 0x80800140: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8080011C;
    }
    // 0x80800140: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800144: beq         $v0, $a2, L_808001C8
    if (ctx->r2 == ctx->r6) {
        // 0x80800148: addu        $v1, $a1, $v0
        ctx->r3 = ADD32(ctx->r5, ctx->r2);
            goto L_808001C8;
    }
L_80800148:
    // 0x80800148: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
L_8080014C:
    // 0x8080014C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80800150: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800154: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x80800158: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x8080015C: beql        $t2, $zero, L_80800170
    if (ctx->r10 == 0) {
        // 0x80800160: lbu         $t3, 0x1($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X1);
            goto L_80800170;
    }
    goto skip_0;
    // 0x80800160: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x80800164: jr          $ra
    // 0x80800168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080016C: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
L_80800170:
    // 0x80800170: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x80800174: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x80800178: beql        $t5, $zero, L_8080018C
    if (ctx->r13 == 0) {
        // 0x8080017C: lbu         $t6, 0x2($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X2);
            goto L_8080018C;
    }
    goto skip_1;
    // 0x8080017C: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    skip_1:
    // 0x80800180: jr          $ra
    // 0x80800184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800188: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
L_8080018C:
    // 0x8080018C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80800190: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80800194: beql        $t8, $zero, L_808001A8
    if (ctx->r24 == 0) {
        // 0x80800198: lbu         $t9, 0x3($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X3);
            goto L_808001A8;
    }
    goto skip_2;
    // 0x80800198: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    skip_2:
    // 0x8080019C: jr          $ra
    // 0x808001A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808001A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001A4: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
L_808001A8:
    // 0x808001A8: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x808001AC: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x808001B0: beq         $t2, $zero, L_808001C0
    if (ctx->r10 == 0) {
        // 0x808001B4: nop
    
            goto L_808001C0;
    }
    // 0x808001B4: nop

    // 0x808001B8: jr          $ra
    // 0x808001BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808001BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001C0:
    // 0x808001C0: bne         $v0, $a2, L_8080014C
    if (ctx->r2 != ctx->r6) {
        // 0x808001C4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8080014C;
    }
    // 0x808001C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808001C8:
    // 0x808001C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

    // 0x808001D4: nop

    // 0x808001D8: nop

    // 0x808001DC: nop

;}
RECOMP_FUNC void func_80800098_chweldarbossfusebox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080009C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: beq         $a1, $at, L_808000C8
    if (ctx->r5 == ctx->r1) {
        // 0x808000B0: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_808000C8;
    }
    // 0x808000B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000B4: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808000B8: beq         $a1, $at, L_80800114
    if (ctx->r5 == ctx->r1) {
        // 0x808000BC: nop
    
            goto L_80800114;
    }
    // 0x808000BC: nop

    // 0x808000C0: b           L_80800130
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800130;
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000C8:
    // 0x808000C8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808000CC: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x808000D0: jal         0x800EE7F8
    // 0x808000D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000D8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808000E0: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    // 0x808000E4: jal         0x800EF1B8
    // 0x808000E8: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808000E8: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x808000EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808000F4: jal         0x80086670
    // 0x808000F8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000F8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x808000FC: addiu       $a0, $zero, 0x33D
    ctx->r4 = ADD32(0, 0X33D);
    // 0x80800100: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800104: jal         0x80101180
    // 0x80800108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80800108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8080010C: b           L_80800130
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800130;
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800114:
    // 0x80800114: jal         0x80800140
    // 0x80800118: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800140_chweldarbossfusebox(rdram, ctx);
        goto after_4;
    // 0x80800118: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x8080011C: b           L_80800130
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800130;
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800124: b           L_80800130
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800130;
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080012C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800130:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_8009E02C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E02C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E034: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8009E038: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8009E03C: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x8009E040: jal         0x8009DF18
    // 0x8009E044: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF18(rdram, ctx);
        goto after_0;
    // 0x8009E044: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_0:
    // 0x8009E048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E04C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E050: jr          $ra
    // 0x8009E054: nop

    return;
    // 0x8009E054: nop

;}
RECOMP_FUNC void func_80015F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015F84: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80015F88: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80015F8C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80015F90: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015F94: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80015F98: jr          $ra
    // 0x80015F9C: lw          $v0, -0x65EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X65EC);
    return;
    // 0x80015F9C: lw          $v0, -0x65EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X65EC);
;}
RECOMP_FUNC void func_80015B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015B34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80015B38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80015B3C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80015B40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80015B44: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80015B48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80015B4C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80015B50: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80015B54: jal         0x80015860
    // 0x80015B58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80015860(rdram, ctx);
        goto after_0;
    // 0x80015B58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80015B5C: jal         0x80015828
    // 0x80015B60: nop

    func_80015828(rdram, ctx);
        goto after_1;
    // 0x80015B60: nop

    after_1:
    // 0x80015B64: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80015B68: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80015B6C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80015B70: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80015B74: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80015B78: addu        $a3, $s0, $t6
    ctx->r7 = ADD32(ctx->r16, ctx->r14);
    // 0x80015B7C: bgez        $s0, L_80015B8C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80015B80: addu        $t0, $a2, $t7
        ctx->r8 = ADD32(ctx->r6, ctx->r15);
            goto L_80015B8C;
    }
    // 0x80015B80: addu        $t0, $a2, $t7
    ctx->r8 = ADD32(ctx->r6, ctx->r15);
    // 0x80015B84: b           L_80015B9C
    // 0x80015B88: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80015B9C;
    // 0x80015B88: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015B8C:
    // 0x80015B8C: slti        $at, $s0, 0x131
    ctx->r1 = SIGNED(ctx->r16) < 0X131 ? 1 : 0;
    // 0x80015B90: bne         $at, $zero, L_80015B9C
    if (ctx->r1 != 0) {
        // 0x80015B94: nop
    
            goto L_80015B9C;
    }
    // 0x80015B94: nop

    // 0x80015B98: addiu       $s0, $zero, 0x130
    ctx->r16 = ADD32(0, 0X130);
L_80015B9C:
    // 0x80015B9C: bgez        $a2, L_80015BAC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80015BA0: slti        $at, $a2, 0xE5
        ctx->r1 = SIGNED(ctx->r6) < 0XE5 ? 1 : 0;
            goto L_80015BAC;
    }
    // 0x80015BA0: slti        $at, $a2, 0xE5
    ctx->r1 = SIGNED(ctx->r6) < 0XE5 ? 1 : 0;
    // 0x80015BA4: b           L_80015BB8
    // 0x80015BA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80015BB8;
    // 0x80015BA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80015BAC:
    // 0x80015BAC: bne         $at, $zero, L_80015BB8
    if (ctx->r1 != 0) {
        // 0x80015BB0: nop
    
            goto L_80015BB8;
    }
    // 0x80015BB0: nop

    // 0x80015BB4: addiu       $a2, $zero, 0xE4
    ctx->r6 = ADD32(0, 0XE4);
L_80015BB8:
    // 0x80015BB8: bgez        $a3, L_80015BC8
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80015BBC: slti        $at, $a3, 0x131
        ctx->r1 = SIGNED(ctx->r7) < 0X131 ? 1 : 0;
            goto L_80015BC8;
    }
    // 0x80015BBC: slti        $at, $a3, 0x131
    ctx->r1 = SIGNED(ctx->r7) < 0X131 ? 1 : 0;
    // 0x80015BC0: b           L_80015BD4
    // 0x80015BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80015BD4;
    // 0x80015BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80015BC8:
    // 0x80015BC8: bne         $at, $zero, L_80015BD4
    if (ctx->r1 != 0) {
        // 0x80015BCC: nop
    
            goto L_80015BD4;
    }
    // 0x80015BCC: nop

    // 0x80015BD0: addiu       $a3, $zero, 0x130
    ctx->r7 = ADD32(0, 0X130);
L_80015BD4:
    // 0x80015BD4: bgez        $t0, L_80015BE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80015BD8: subu        $a0, $a3, $s0
        ctx->r4 = SUB32(ctx->r7, ctx->r16);
            goto L_80015BE4;
    }
    // 0x80015BD8: subu        $a0, $a3, $s0
    ctx->r4 = SUB32(ctx->r7, ctx->r16);
    // 0x80015BDC: b           L_80015BF4
    // 0x80015BE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80015BF4;
    // 0x80015BE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80015BE4:
    // 0x80015BE4: slti        $at, $t0, 0xE5
    ctx->r1 = SIGNED(ctx->r8) < 0XE5 ? 1 : 0;
    // 0x80015BE8: bnel        $at, $zero, L_80015BF8
    if (ctx->r1 != 0) {
        // 0x80015BEC: mtc1        $a0, $f8
        ctx->f8.u32l = ctx->r4;
            goto L_80015BF8;
    }
    goto skip_0;
    // 0x80015BEC: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    skip_0:
    // 0x80015BF0: addiu       $t0, $zero, 0xE4
    ctx->r8 = ADD32(0, 0XE4);
L_80015BF4:
    // 0x80015BF4: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
L_80015BF8:
    // 0x80015BF8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80015BFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015C00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80015C04: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80015C08: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80015C0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015C10: subu        $a1, $t0, $a2
    ctx->r5 = SUB32(ctx->r8, ctx->r6);
    // 0x80015C14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015C18: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80015C1C: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x80015C20: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80015C24: addiu       $t2, $t2, -0x6848
    ctx->r10 = ADD32(ctx->r10, -0X6848);
    // 0x80015C28: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80015C2C: sh          $a0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r4;
    // 0x80015C30: sh          $a1, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r5;
    // 0x80015C34: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80015C38: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x80015C3C: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x80015C40: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80015C44: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80015C48: sh          $s0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r16;
    // 0x80015C4C: sh          $a2, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r6;
    // 0x80015C50: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x80015C54: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x80015C58: addiu       $t1, $zero, 0x1FF
    ctx->r9 = ADD32(0, 0X1FF);
    // 0x80015C5C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80015C60: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x80015C64: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x80015C68: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x80015C6C: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x80015C70: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80015C74: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80015C78: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80015C7C: sh          $t1, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r9;
    // 0x80015C80: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80015C84: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x80015C88: addu        $a0, $t2, $t9
    ctx->r4 = ADD32(ctx->r10, ctx->r25);
    // 0x80015C8C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80015C90: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80015C94: sh          $t6, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r14;
    // 0x80015C98: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80015C9C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80015CA0: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80015CA4: jal         0x8002E660
    // 0x80015CA8: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x80015CA8: sh          $t8, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r24;
    after_2:
    // 0x80015CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80015CB0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80015CB4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80015CB8: jr          $ra
    // 0x80015CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80015CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void __osExceptionPreambleDuplicate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031FD0: lui         $k0, 0x8003
    ctx->r26 = S32(0X8003 << 16);
    // 0x80031FD4: addiu       $k0, $k0, 0x1FF0
    ctx->r26 = ADD32(ctx->r26, 0X1FF0);
    // 0x80031FD8: jr          $k0
    // 0x80031FDC: nop

    LOOKUP_FUNC(ctx->r26)(rdram, ctx);
    return;
    // 0x80031FDC: nop

;}
RECOMP_FUNC void func_800E14B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E14B8: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E14BC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E14C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800E14C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E14C8: addiu       $t7, $t7, -0x3070
    ctx->r15 = ADD32(ctx->r15, -0X3070);
    // 0x800E14CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E14D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E14D4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800E14D8: jal         0x800EE7F8
    // 0x800E14DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800E14DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E14E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E14E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E14E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E14EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E14F0: jr          $ra
    // 0x800E14F4: sb          $t8, 0x76($a0)
    MEM_B(0X76, ctx->r4) = ctx->r24;
    return;
    // 0x800E14F4: sb          $t8, 0x76($a0)
    MEM_B(0X76, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80802144_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802144: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802148: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080214C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80802150: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80802154: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80802158: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8080215C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80802160: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80802164: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80802168: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080216C: jal         0x80100094
    // 0x80802170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802174: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80802178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080217C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80802180: lhu         $v1, 0x72($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X72);
    // 0x80802184: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80802188: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080218C: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x80802190: beq         $t7, $at, L_808021B4
    if (ctx->r15 == ctx->r1) {
        // 0x80802194: addiu       $s3, $a0, 0x10C
        ctx->r19 = ADD32(ctx->r4, 0X10C);
            goto L_808021B4;
    }
    // 0x80802194: addiu       $s3, $a0, 0x10C
    ctx->r19 = ADD32(ctx->r4, 0X10C);
    // 0x80802198: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8080219C: beq         $t7, $at, L_808021BC
    if (ctx->r15 == ctx->r1) {
        // 0x808021A0: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_808021BC;
    }
    // 0x808021A0: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x808021A4: beql        $t7, $at, L_808021C8
    if (ctx->r15 == ctx->r1) {
        // 0x808021A8: addiu       $s5, $zero, 0x4
        ctx->r21 = ADD32(0, 0X4);
            goto L_808021C8;
    }
    goto skip_0;
    // 0x808021A8: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    skip_0:
    // 0x808021AC: b           L_808021C8
    // 0x808021B0: nop

        goto L_808021C8;
    // 0x808021B0: nop

L_808021B4:
    // 0x808021B4: b           L_808021C8
    // 0x808021B8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
        goto L_808021C8;
    // 0x808021B8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_808021BC:
    // 0x808021BC: b           L_808021C8
    // 0x808021C0: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
        goto L_808021C8;
    // 0x808021C0: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x808021C4: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
L_808021C8:
    // 0x808021C8: blez        $s5, L_80802240
    if (SIGNED(ctx->r21) <= 0) {
        // 0x808021CC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80802240;
    }
    // 0x808021CC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808021D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X25B8) << 16);
    // 0x808021D4: lwc1        $f20, 0x25B8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X25B8));
    // 0x808021D8: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
L_808021DC:
    // 0x808021DC: lwc1        $f4, 0x11C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x808021E0: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x808021E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808021E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808021EC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x808021F0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808021F4: jal         0x80108528
    // 0x808021F8: nop

    func_80108528(rdram, ctx);
        goto after_1;
    // 0x808021F8: nop

    after_1:
    // 0x808021FC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80802200: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802204: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802208: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8080220C: jal         0x800862D8
    // 0x80802210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80802210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80802214: jal         0x80100120
    // 0x80802218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100120(rdram, ctx);
        goto after_3;
    // 0x80802218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080221C: jal         0x8008A118
    // 0x80802220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80802220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802224: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x80802228: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8080222C: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x80802230: andi        $t0, $t9, 0xFFFD
    ctx->r8 = ctx->r25 & 0XFFFD;
    // 0x80802234: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x80802238: bne         $s2, $s5, L_808021DC
    if (ctx->r18 != ctx->r21) {
        // 0x8080223C: sb          $t0, 0x75($s0)
        MEM_B(0X75, ctx->r16) = ctx->r8;
            goto L_808021DC;
    }
    // 0x8080223C: sb          $t0, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r8;
L_80802240:
    // 0x80802240: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80802244: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80802248: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080224C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80802250: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80802254: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80802258: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8080225C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80802260: jr          $ra
    // 0x80802264: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80802264: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chegggolden_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2112, 0X3F0) << 16);
    // 0x80800290: jr          $ra
    // 0x80800294: addiu       $v0, $v0, 0x3F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2112, 0X3F0));
    return;
    // 0x80800294: addiu       $v0, $v0, 0x3F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2112, 0X3F0));
;}
RECOMP_FUNC void func_808004C8_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004CC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808004D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D4: bne         $a1, $at, L_808004EC
    if (ctx->r5 != ctx->r1) {
        // 0x808004D8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808004EC;
    }
    // 0x808004D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808004DC: jal         0x80800504
    // 0x808004E0: nop

    func_80800504_chdiggerbossshell(rdram, ctx);
        goto after_0;
    // 0x808004E0: nop

    after_0:
    // 0x808004E4: b           L_808004F4
    // 0x808004E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004F4;
    // 0x808004E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004EC:
    // 0x808004EC: b           L_808004F4
    // 0x808004F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004F4;
    // 0x808004F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004F4:
    // 0x808004F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004FC: jr          $ra
    // 0x80800500: nop

    return;
    // 0x80800500: nop

;}
RECOMP_FUNC void gctransitionDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C0: lbu         $v0, 0x1C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1C);
    // 0x808008C4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x808008C8: jr          $ra
    // 0x808008CC: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x808008CC: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_8009788C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009788C: lw          $t6, 0x98($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X98);
    // 0x80097890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80097894: sb          $v0, 0x24($t6)
    MEM_B(0X24, ctx->r14) = ctx->r2;
    // 0x80097898: lw          $t7, 0x98($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X98);
    // 0x8009789C: jr          $ra
    // 0x800978A0: sb          $v0, 0x26($t7)
    MEM_B(0X26, ctx->r15) = ctx->r2;
    return;
    // 0x800978A0: sb          $v0, 0x26($t7)
    MEM_B(0X26, ctx->r15) = ctx->r2;
;}
RECOMP_FUNC void func_80800D40_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D48: jal         0x8080055C
    // 0x80800D4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800D4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D50: jal         0x800839C8
    // 0x80800D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D60: jr          $ra
    // 0x80800D64: nop

    return;
    // 0x80800D64: nop

;}
RECOMP_FUNC void func_808006B4_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808006B8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808006BC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808006C0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808006C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x808006CC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808006D0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808006D4: jal         0x800EE7F8
    // 0x808006D8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808006D8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x808006DC: jal         0x800D8FF8
    // 0x808006E0: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808006E0: nop

    after_1:
    // 0x808006E4: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x808006E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006EC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808006F0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808006F4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808006F8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x808006FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800700: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800704: jal         0x800EF174
    // 0x80800708: nop

    func_800EF174(rdram, ctx);
        goto after_2;
    // 0x80800708: nop

    after_2:
    // 0x8080070C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800710: jal         0x800EE7F8
    // 0x80800714: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800714: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800718: jal         0x800D8FF8
    // 0x8080071C: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x8080071C: nop

    after_4:
    // 0x80800720: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800724: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800728: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080072C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800730: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800734: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800738: jal         0x800EF174
    // 0x8080073C: nop

    func_800EF174(rdram, ctx);
        goto after_5;
    // 0x8080073C: nop

    after_5:
    // 0x80800740: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800744: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800748: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8080074C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800750: jal         0x800C6A7C
    // 0x80800754: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_6;
    // 0x80800754: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_6:
    // 0x80800758: beq         $v0, $zero, L_8080080C
    if (ctx->r2 == 0) {
        // 0x8080075C: lw          $a1, 0x58($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X58);
            goto L_8080080C;
    }
    // 0x8080075C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800760: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800764: jal         0x800F1988
    // 0x80800768: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    func_800F1988(rdram, ctx);
        goto after_7;
    // 0x80800768: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x8080076C: beq         $v0, $zero, L_80800790
    if (ctx->r2 == 0) {
        // 0x80800770: lw          $t7, 0x58($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X58);
            goto L_80800790;
    }
    // 0x80800770: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800774: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800778: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8080077C: swc1        $f16, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f16.u32l;
    // 0x80800780: jal         0x800EE7F8
    // 0x80800784: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80800784: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x80800788: b           L_80800810
    // 0x8080078C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800810;
    // 0x8080078C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800790:
    // 0x80800790: jal         0x800F2100
    // 0x80800794: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    mlAbsF(rdram, ctx);
        goto after_9;
    // 0x80800794: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80800798: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC08) << 16);
    // 0x8080079C: lwc1        $f18, 0xC08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC08));
    // 0x808007A0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808007A4: nop

    // 0x808007A8: bc1fl       L_80800810
    if (!c1cs) {
        // 0x808007AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800810;
    }
    goto skip_0;
    // 0x808007AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808007B0: jal         0x800F2100
    // 0x808007B4: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    mlAbsF(rdram, ctx);
        goto after_10;
    // 0x808007B4: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x808007B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC0C) << 16);
    // 0x808007BC: lwc1        $f4, 0xC0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC0C));
    // 0x808007C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808007C4: nop

    // 0x808007C8: bc1fl       L_80800810
    if (!c1cs) {
        // 0x808007CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800810;
    }
    goto skip_1;
    // 0x808007CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808007D0: jal         0x800F2100
    // 0x808007D4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    mlAbsF(rdram, ctx);
        goto after_11;
    // 0x808007D4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x808007D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC10) << 16);
    // 0x808007DC: lwc1        $f6, 0xC10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC10));
    // 0x808007E0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808007E4: nop

    // 0x808007E8: bc1fl       L_80800810
    if (!c1cs) {
        // 0x808007EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800810;
    }
    goto skip_2;
    // 0x808007EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x808007F0: jal         0x800EFD24
    // 0x808007F4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800EFD24(rdram, ctx);
        goto after_12;
    // 0x808007F4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_12:
    // 0x808007F8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808007FC: jal         0x800EE7F8
    // 0x80800800: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80800800: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_13:
    // 0x80800804: b           L_80800810
    // 0x80800808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800810;
    // 0x80800808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080080C:
    // 0x8080080C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800810:
    // 0x80800810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800814: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800818: jr          $ra
    // 0x8080081C: nop

    return;
    // 0x8080081C: nop

;}
RECOMP_FUNC void func_8080096C_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080096C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800970: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800974: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800978: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x8080097C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800980: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800984: sll         $t6, $a2, 11
    ctx->r14 = S32(ctx->r6 << 11);
    // 0x80800988: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8080098C: sltu        $a2, $zero, $t7
    ctx->r6 = 0 < ctx->r15 ? 1 : 0;
    // 0x80800990: beq         $a2, $zero, L_808009B8
    if (ctx->r6 == 0) {
        // 0x80800994: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(768, 0X1740) << 16);
            goto L_808009B8;
    }
    // 0x80800994: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(768, 0X1740) << 16);
    // 0x80800998: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080099C: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x808009A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808009A8: nop

    // 0x808009AC: bc1fl       L_808009BC
    if (!c1cs) {
        // 0x808009B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009BC;
    }
    goto skip_0;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808009B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_808009B8:
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009BC:
    // 0x808009BC: addiu       $a3, $a3, 0x1740
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(768, 0X1740));
    // 0x808009C0: jal         0x80089D50
    // 0x808009C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808009C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808009C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(768, 0X158C) << 16);
    // 0x808009CC: lui         $a2, 0x464B
    ctx->r6 = S32(0X464B << 16);
    // 0x808009D0: ori         $a2, $a2, 0x2000
    ctx->r6 = ctx->r6 | 0X2000;
    // 0x808009D4: lwc1        $f14, 0x158C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(768, 0X158C));
    // 0x808009D8: jal         0x800F1214
    // 0x808009DC: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    func_800F1214(rdram, ctx);
        goto after_1;
    // 0x808009DC: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x808009E0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808009EC: jal         0x80089D38
    // 0x808009F0: nop

    _subaddieaudioloop_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808009F0: nop

    after_2:
    // 0x808009F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808009F8: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808009FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(768, 0X1750) << 16);
    // 0x80800A00: addiu       $a3, $a3, 0x1750
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(768, 0X1750));
    // 0x80800A04: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800A08: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    // 0x80800A0C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A14: bc1f        L_80800A20
    if (!c1cs) {
        // 0x80800A18: nop
    
            goto L_80800A20;
    }
    // 0x80800A18: nop

    // 0x80800A1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800A20:
    // 0x80800A20: jal         0x80089D68
    // 0x80800A24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800A24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80800A28: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    // 0x80800A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A38: jr          $ra
    // 0x80800A3C: nop

    return;
    // 0x80800A3C: nop

;}
RECOMP_FUNC void fxleaves_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800394: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800398: jal         0x800B2D28
    // 0x8080039C: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    vector_free(rdram, ctx);
        goto after_0;
    // 0x8080039C: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    after_0:
    // 0x808003A0: jal         0x8001B084
    // 0x808003A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x808003A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void boot___osExceptionPreambleDuplicate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void bsow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800044: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080004C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800050: jal         0x8008CB10
    // 0x80800054: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800054: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_0:
    // 0x80800058: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x8080005C: nop
    
            goto L_80800068;
    }
    // 0x8080005C: nop

    // 0x80800060: jal         0x800951B4
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80800068:
    // 0x80800068: jal         0x800845C8
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800070: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800074: nop
    
            goto L_80800080;
    }
    // 0x80800074: nop

    // 0x80800078: jal         0x800841D8
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800080:
    // 0x80800080: jal         0x80084600
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800088: beq         $v0, $zero, L_80800094
    if (ctx->r2 == 0) {
        // 0x8080008C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800094;
    }
    // 0x8080008C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800090: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800094:
    // 0x80800094: jal         0x800845C0
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080009C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000A0: bnel        $v0, $at, L_808000F4
    if (ctx->r2 != ctx->r1) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F4;
    }
    goto skip_0;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000A8: jal         0x8008E260
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_6;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000B0: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x808000B4: addiu       $t7, $zero, 0x3D
        ctx->r15 = ADD32(0, 0X3D);
            goto L_808000BC;
    }
    // 0x808000B4: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x808000B8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808000BC:
    // 0x808000BC: jal         0x8008E35C
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000C4: beql        $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F4;
    }
    goto skip_1;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808000CC: jal         0x8009BB50
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_8;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000D8: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x808000DC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x808000E0: nop

    // 0x808000E4: bc1fl       L_808000F4
    if (!c1cs) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F4;
    }
    goto skip_2;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808000EC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000F4:
    // 0x808000F4: jal         0x8009E5C8
    // 0x808000F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x808000F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
