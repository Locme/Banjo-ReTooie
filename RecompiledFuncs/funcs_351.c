#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bskazcrouch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080076C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800770: jal         0x800832E8
    // 0x80800774: nop

    _bskaz_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800774: nop

    after_0:
    // 0x80800778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080077C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800780: jr          $ra
    // 0x80800784: nop

    return;
    // 0x80800784: nop

;}
RECOMP_FUNC void func_800D7754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D775C: jal         0x80105494
    // 0x800D7760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x800D7760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D7764: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800D7768: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800D776C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x800D7770: beq         $at, $zero, L_800D78F0
    if (ctx->r1 == 0) {
        // 0x800D7774: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800D78F0;
    }
    // 0x800D7774: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D7778: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D777C: addu        $at, $at, $t7
    gpr jr_addend_800D7784 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D7780: lw          $t7, 0x5CD0($at)
    ctx->r15 = ADD32(ctx->r1, 0X5CD0);
    // 0x800D7784: jr          $t7
    // 0x800D7788: nop

    switch (jr_addend_800D7784 >> 2) {
        case 0: goto L_800D778C; break;
        case 1: goto L_800D77C4; break;
        case 2: goto L_800D77F4; break;
        case 3: goto L_800D7824; break;
        case 4: goto L_800D7854; break;
        case 5: goto L_800D7884; break;
        case 6: goto L_800D78BC; break;
        default: switch_error(__func__, 0x800D7784, 0x80125CD0);
    }
    // 0x800D7788: nop

L_800D778C:
    // 0x800D778C: lhu         $t0, 0x26($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X26);
    // 0x800D7790: lbu         $t8, 0x2B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2B);
    // 0x800D7794: andi        $t1, $t0, 0xFE3F
    ctx->r9 = ctx->r8 & 0XFE3F;
    // 0x800D7798: sh          $t1, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r9;
    // 0x800D779C: lbu         $t3, 0x26($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X26);
    // 0x800D77A0: andi        $t9, $t8, 0xFFC0
    ctx->r25 = ctx->r24 & 0XFFC0;
    // 0x800D77A4: sb          $t9, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r25;
    // 0x800D77A8: ori         $t6, $t3, 0x20
    ctx->r14 = ctx->r11 | 0X20;
    // 0x800D77AC: ori         $t9, $t6, 0x80
    ctx->r25 = ctx->r14 | 0X80;
    // 0x800D77B0: sb          $t6, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r14;
    // 0x800D77B4: sb          $t9, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r25;
    // 0x800D77B8: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x800D77BC: b           L_800D78F0
    // 0x800D77C0: sb          $t0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r8;
        goto L_800D78F0;
    // 0x800D77C0: sb          $t0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r8;
L_800D77C4:
    // 0x800D77C4: lhu         $t3, 0x26($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X26);
    // 0x800D77C8: lbu         $t1, 0x2B($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2B);
    // 0x800D77CC: andi        $t4, $t3, 0xFE3F
    ctx->r12 = ctx->r11 & 0XFE3F;
    // 0x800D77D0: sh          $t4, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r12;
    // 0x800D77D4: lbu         $t5, 0x26($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X26);
    // 0x800D77D8: andi        $t2, $t1, 0xFFC0
    ctx->r10 = ctx->r9 & 0XFFC0;
    // 0x800D77DC: sb          $t2, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r10;
    // 0x800D77E0: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x800D77E4: sb          $t7, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r15;
    // 0x800D77E8: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x800D77EC: b           L_800D78F0
    // 0x800D77F0: sb          $t8, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r24;
        goto L_800D78F0;
    // 0x800D77F0: sb          $t8, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r24;
L_800D77F4:
    // 0x800D77F4: lhu         $t1, 0x26($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X26);
    // 0x800D77F8: lbu         $t9, 0x2B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2B);
    // 0x800D77FC: andi        $t2, $t1, 0xFE3F
    ctx->r10 = ctx->r9 & 0XFE3F;
    // 0x800D7800: sh          $t2, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r10;
    // 0x800D7804: lbu         $t3, 0x26($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X26);
    // 0x800D7808: andi        $t0, $t9, 0xFFC0
    ctx->r8 = ctx->r25 & 0XFFC0;
    // 0x800D780C: sb          $t0, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r8;
    // 0x800D7810: andi        $t6, $t3, 0xFFDF
    ctx->r14 = ctx->r11 & 0XFFDF;
    // 0x800D7814: sb          $t6, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r14;
    // 0x800D7818: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800D781C: b           L_800D78F0
    // 0x800D7820: sb          $t7, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r15;
        goto L_800D78F0;
    // 0x800D7820: sb          $t7, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r15;
L_800D7824:
    // 0x800D7824: lhu         $t0, 0x26($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X26);
    // 0x800D7828: lbu         $t8, 0x2B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2B);
    // 0x800D782C: andi        $t1, $t0, 0xFE3F
    ctx->r9 = ctx->r8 & 0XFE3F;
    // 0x800D7830: sh          $t1, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r9;
    // 0x800D7834: lbu         $t2, 0x26($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X26);
    // 0x800D7838: andi        $t9, $t8, 0xFFC0
    ctx->r25 = ctx->r24 & 0XFFC0;
    // 0x800D783C: sb          $t9, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r25;
    // 0x800D7840: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x800D7844: sb          $t4, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r12;
    // 0x800D7848: andi        $t5, $t4, 0xBF
    ctx->r13 = ctx->r12 & 0XBF;
    // 0x800D784C: b           L_800D78F0
    // 0x800D7850: sb          $t5, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r13;
        goto L_800D78F0;
    // 0x800D7850: sb          $t5, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r13;
L_800D7854:
    // 0x800D7854: lhu         $t8, 0x26($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X26);
    // 0x800D7858: lbu         $t6, 0x2B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2B);
    // 0x800D785C: andi        $t9, $t8, 0xFE3F
    ctx->r25 = ctx->r24 & 0XFE3F;
    // 0x800D7860: sh          $t9, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r25;
    // 0x800D7864: lbu         $t0, 0x26($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X26);
    // 0x800D7868: andi        $t7, $t6, 0xFFC0
    ctx->r15 = ctx->r14 & 0XFFC0;
    // 0x800D786C: sb          $t7, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r15;
    // 0x800D7870: andi        $t3, $t0, 0xFFDF
    ctx->r11 = ctx->r8 & 0XFFDF;
    // 0x800D7874: sb          $t3, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r11;
    // 0x800D7878: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x800D787C: b           L_800D78F0
    // 0x800D7880: sb          $t4, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r12;
        goto L_800D78F0;
    // 0x800D7880: sb          $t4, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r12;
L_800D7884:
    // 0x800D7884: lhu         $t7, 0x26($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X26);
    // 0x800D7888: lbu         $t5, 0x2B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2B);
    // 0x800D788C: andi        $t8, $t7, 0xFE3F
    ctx->r24 = ctx->r15 & 0XFE3F;
    // 0x800D7890: sh          $t8, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r24;
    // 0x800D7894: lbu         $t9, 0x26($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X26);
    // 0x800D7898: andi        $t6, $t5, 0xFFC0
    ctx->r14 = ctx->r13 & 0XFFC0;
    // 0x800D789C: sb          $t6, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r14;
    // 0x800D78A0: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x800D78A4: andi        $t3, $t1, 0x7F
    ctx->r11 = ctx->r9 & 0X7F;
    // 0x800D78A8: sb          $t1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r9;
    // 0x800D78AC: sb          $t3, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r11;
    // 0x800D78B0: andi        $t4, $t3, 0xBF
    ctx->r12 = ctx->r11 & 0XBF;
    // 0x800D78B4: b           L_800D78F0
    // 0x800D78B8: sb          $t4, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r12;
        goto L_800D78F0;
    // 0x800D78B8: sb          $t4, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r12;
L_800D78BC:
    // 0x800D78BC: lhu         $t7, 0x26($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X26);
    // 0x800D78C0: lbu         $t5, 0x2B($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2B);
    // 0x800D78C4: andi        $t8, $t7, 0xFE3F
    ctx->r24 = ctx->r15 & 0XFE3F;
    // 0x800D78C8: sh          $t8, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r24;
    // 0x800D78CC: lbu         $t9, 0x26($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X26);
    // 0x800D78D0: andi        $t6, $t5, 0xFFC0
    ctx->r14 = ctx->r13 & 0XFFC0;
    // 0x800D78D4: sb          $t6, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r14;
    // 0x800D78D8: andi        $t2, $t9, 0xFFDF
    ctx->r10 = ctx->r25 & 0XFFDF;
    // 0x800D78DC: ori         $t5, $t2, 0x80
    ctx->r13 = ctx->r10 | 0X80;
    // 0x800D78E0: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
    // 0x800D78E4: sb          $t5, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r13;
    // 0x800D78E8: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x800D78EC: sb          $t6, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r14;
L_800D78F0:
    // 0x800D78F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D78F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D78F8: jr          $ra
    // 0x800D78FC: nop

    return;
    // 0x800D78FC: nop

;}
RECOMP_FUNC void func_800DF660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF668: bne         $a1, $zero, L_800DF680
    if (ctx->r5 != 0) {
        // 0x800DF66C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800DF680;
    }
    // 0x800DF66C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DF670: bne         $a2, $zero, L_800DF680
    if (ctx->r6 != 0) {
        // 0x800DF674: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800DF680;
    }
    // 0x800DF674: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF678: b           L_800DF6AC
    // 0x800DF67C: sw          $zero, -0x37C8($at)
    MEM_W(-0X37C8, ctx->r1) = 0;
        goto L_800DF6AC;
    // 0x800DF67C: sw          $zero, -0x37C8($at)
    MEM_W(-0X37C8, ctx->r1) = 0;
L_800DF680:
    // 0x800DF680: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF684: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DF688: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF68C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800DF690: addiu       $v0, $v0, -0x35F8
    ctx->r2 = ADD32(ctx->r2, -0X35F8);
    // 0x800DF694: sw          $t6, -0x37C8($at)
    MEM_W(-0X37C8, ctx->r1) = ctx->r14;
    // 0x800DF698: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x800DF69C: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x800DF6A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800DF6A4: jal         0x800DF410
    // 0x800DF6A8: sb          $t7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r15;
    func_800DF410(rdram, ctx);
        goto after_0;
    // 0x800DF6A8: sb          $t7, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r15;
    after_0:
L_800DF6AC:
    // 0x800DF6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF6B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF6B4: jr          $ra
    // 0x800DF6B8: nop

    return;
    // 0x800DF6B8: nop

;}
RECOMP_FUNC void func_80801134_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801144: beq         $a1, $at, L_80801160
    if (ctx->r5 == ctx->r1) {
        // 0x80801148: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80801160;
    }
    // 0x80801148: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080114C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801150: beq         $a1, $at, L_8080119C
    if (ctx->r5 == ctx->r1) {
        // 0x80801154: nop
    
            goto L_8080119C;
    }
    // 0x80801154: nop

    // 0x80801158: b           L_808011D4
    // 0x8080115C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_808011D4;
    // 0x8080115C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80801160:
    // 0x80801160: jal         0x800EA068
    // 0x80801164: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x80801164: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_0:
    // 0x80801168: beq         $v0, $zero, L_8080117C
    if (ctx->r2 == 0) {
        // 0x8080116C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080117C;
    }
    // 0x8080116C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801170: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(68, 0X1728) << 16);
    // 0x80801174: b           L_80801188
    // 0x80801178: lwc1        $f0, 0x1728($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(68, 0X1728));
        goto L_80801188;
    // 0x80801178: lwc1        $f0, 0x1728($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(68, 0X1728));
L_8080117C:
    // 0x8080117C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80801180: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801184: nop

L_80801188:
    // 0x80801188: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080118C: jal         0x80085338
    // 0x80801190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x80801190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801194: b           L_808011D4
    // 0x80801198: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_808011D4;
    // 0x80801198: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8080119C:
    // 0x8080119C: jal         0x800EA068
    // 0x808011A0: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    func_800EA068(rdram, ctx);
        goto after_2;
    // 0x808011A0: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_2:
    // 0x808011A4: beq         $v0, $zero, L_808011B8
    if (ctx->r2 == 0) {
        // 0x808011A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808011B8;
    }
    // 0x808011A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(68, 0X172C) << 16);
    // 0x808011B0: b           L_808011C4
    // 0x808011B4: lwc1        $f0, 0x172C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(68, 0X172C));
        goto L_808011C4;
    // 0x808011B4: lwc1        $f0, 0x172C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(68, 0X172C));
L_808011B8:
    // 0x808011B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808011BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808011C0: nop

L_808011C4:
    // 0x808011C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808011C8: jal         0x80085338
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_3;
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808011D0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_808011D4:
    // 0x808011D4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808011D8: sw          $t7, 0x15C($t8)
    MEM_W(0X15C, ctx->r24) = ctx->r15;
    // 0x808011DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011E4: jr          $ra
    // 0x808011E8: nop

    return;
    // 0x808011E8: nop

;}
RECOMP_FUNC void func_800EFD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD4C: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x800EFD50: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x800EFD54: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x800EFD58: jr          $ra
    // 0x800EFD5C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800EFD5C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800E4640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4640: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E4644: lw          $t6, -0x2AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AF8);
    // 0x800E4648: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x800E464C: beql        $t6, $zero, L_800E4678
    if (ctx->r14 == 0) {
        // 0x800E4650: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_800E4678;
    }
    goto skip_0;
    // 0x800E4650: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800E4654: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E4658: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x800E465C: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x800E4660: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E4664: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E4668: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800E466C: jr          $ra
    // 0x800E4670: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x800E4670: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E4674: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_800E4678:
    // 0x800E4678: ori         $t1, $t1, 0x7
    ctx->r9 = ctx->r9 | 0X7;
    // 0x800E467C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800E4680: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800E4684: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800E4688: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800E468C: lw          $t2, -0x2AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AA8);
    // 0x800E4690: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E4694: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800E4698: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800E469C: jr          $ra
    // 0x800E46A0: nop

    return;
    // 0x800E46A0: nop

;}
RECOMP_FUNC void func_80800970_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800978: jal         0x80100094
    // 0x8080097C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080097C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800980: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80800984: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800988: beql        $t6, $zero, L_808009A4
    if (ctx->r14 == 0) {
        // 0x8080098C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009A4;
    }
    goto skip_0;
    // 0x8080098C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800990: jal         0x800856B8
    // 0x80800994: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800994: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800998: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080099C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x808009A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009A4:
    // 0x808009A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009A8: jr          $ra
    // 0x808009AC: nop

    return;
    // 0x808009AC: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A30: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A30);
    return;
    // 0x80082A34: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80803CD4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803CD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803CDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803CE0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80803CE4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80803CE8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80803CEC: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80803CF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803CF4: jal         0x8009E6F8
    // 0x80803CF8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x80803CF8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x80803CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80803D04: jal         0x8009CA70
    // 0x80803D08: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x80803D08: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80803D0C: beq         $v0, $zero, L_80803D1C
    if (ctx->r2 == 0) {
        // 0x80803D10: nop
    
            goto L_80803D1C;
    }
    // 0x80803D10: nop

    // 0x80803D14: b           L_80803E70
    // 0x80803D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E70;
    // 0x80803D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803D1C:
    // 0x80803D1C: jal         0x8009BD44
    // 0x80803D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD44(rdram, ctx);
        goto after_2;
    // 0x80803D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80803D24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803D28: bne         $v0, $at, L_80803D38
    if (ctx->r2 != ctx->r1) {
        // 0x80803D2C: nop
    
            goto L_80803D38;
    }
    // 0x80803D2C: nop

    // 0x80803D30: b           L_80803E70
    // 0x80803D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803E70;
    // 0x80803D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803D38:
    // 0x80803D38: jal         0x800883B0
    // 0x80803D3C: nop

    _gcstatusDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80803D3C: nop

    after_3:
    // 0x80803D40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803D44: bne         $v0, $at, L_80803DB0
    if (ctx->r2 != ctx->r1) {
        // 0x80803D48: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_80803DB0;
    }
    // 0x80803D48: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80803D4C: jal         0x80088380
    // 0x80803D50: nop

    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80803D50: nop

    after_4:
    // 0x80803D54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80803D58: bne         $v0, $at, L_80803DA4
    if (ctx->r2 != ctx->r1) {
        // 0x80803D5C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80803DA4;
    }
    // 0x80803D5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80803D60: jal         0x80088388
    // 0x80803D64: nop

    _gcstatusDll_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x80803D64: nop

    after_5:
    // 0x80803D68: lw          $t7, 0x184($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X184);
    // 0x80803D6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80803D70: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80803D74: bne         $v0, $t7, L_80803D88
    if (ctx->r2 != ctx->r15) {
        // 0x80803D78: nop
    
            goto L_80803D88;
    }
    // 0x80803D78: nop

    // 0x80803D7C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80803D80: b           L_80803DDC
    // 0x80803D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803DDC;
    // 0x80803D84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803D88:
    // 0x80803D88: beq         $t8, $zero, L_80803D9C
    if (ctx->r24 == 0) {
        // 0x80803D8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80803D9C;
    }
    // 0x80803D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803D94: b           L_80803DDC
    // 0x80803D98: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80803DDC;
    // 0x80803D98: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80803D9C:
    // 0x80803D9C: b           L_80803DDC
    // 0x80803DA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80803DDC;
    // 0x80803DA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80803DA4:
    // 0x80803DA4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80803DA8: b           L_80803DDC
    // 0x80803DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803DDC;
    // 0x80803DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803DB0:
    // 0x80803DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803DB4: jal         0x800A17A8
    // 0x80803DB8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    func_800A17A8(rdram, ctx);
        goto after_6;
    // 0x80803DB8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_6:
    // 0x80803DBC: jal         0x800A1718
    // 0x80803DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_7;
    // 0x80803DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80803DC4: beq         $v0, $zero, L_80803DD8
    if (ctx->r2 == 0) {
        // 0x80803DC8: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80803DD8;
    }
    // 0x80803DC8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80803DCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803DD0: b           L_80803DDC
    // 0x80803DD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80803DDC;
    // 0x80803DD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80803DD8:
    // 0x80803DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803DDC:
    // 0x80803DDC: beq         $v0, $zero, L_80803E04
    if (ctx->r2 == 0) {
        // 0x80803DE0: addiu       $a0, $zero, 0x2C4
        ctx->r4 = ADD32(0, 0X2C4);
            goto L_80803E04;
    }
    // 0x80803DE0: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x80803DE4: lw          $t9, 0x184($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X184);
    // 0x80803DE8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80803DEC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80803DF0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80803DF4: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x80803DF8: jal         0x80101180
    // 0x80803DFC: or          $a2, $t0, $t1
    ctx->r6 = ctx->r8 | ctx->r9;
    func_80101180(rdram, ctx);
        goto after_8;
    // 0x80803DFC: or          $a2, $t0, $t1
    ctx->r6 = ctx->r8 | ctx->r9;
    after_8:
    // 0x80803E00: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_80803E04:
    // 0x80803E04: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80803E08: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA460) << 16);
    // 0x80803E0C: lwc1        $f6, -0x5BA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA460));
    // 0x80803E10: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80803E14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803E18: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80803E1C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80803E20: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80803E24: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80803E28: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80803E2C: jal         0x800F10B4
    // 0x80803E30: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80803E30: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_9:
    // 0x80803E34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80803E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803E3C: jal         0x80085488
    // 0x80803E40: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _bamotor_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80803E40: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_10:
    // 0x80803E44: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80803E48: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80803E4C: addiu       $a0, $v0, 0xF8
    ctx->r4 = ADD32(ctx->r2, 0XF8);
    // 0x80803E50: sw          $t3, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->r11;
    // 0x80803E54: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80803E58: sw          $t4, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r12;
    // 0x80803E5C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80803E60: sw          $t5, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r13;
    // 0x80803E64: jal         0x800EE7F8
    // 0x80803E68: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80803E68: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_11:
    // 0x80803E6C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80803E70:
    // 0x80803E70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803E74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803E78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803E7C: jr          $ra
    // 0x80803E80: nop

    return;
    // 0x80803E80: nop

;}
RECOMP_FUNC void _sudeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F18: syscall     816
    recomp_syscall_handler(rdram, ctx, 0x80089F18);
    return;
    // 0x80089F1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808003E0_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003EC: jal         0x800C6DA0
    // 0x808003F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800C6DA0(rdram, ctx);
        goto after_0;
    // 0x808003F0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_0:
    // 0x808003F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003F8: jal         0x800A0CF4
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800400: jal         0x800A4E30
    // 0x80800404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_2;
    // 0x80800404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void func_800DDF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDF14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800DDF18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DDF1C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DDF20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DDF24: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800DDF28: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800DDF2C: jal         0x800EE88C
    // 0x800DDF30: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800DDF30: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x800DDF34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DDF38: lw          $a1, -0x36B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36B8);
    // 0x800DDF3C: jal         0x800EF334
    // 0x800DDF40: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EF334(rdram, ctx);
        goto after_1;
    // 0x800DDF40: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x800DDF44: lh          $t6, 0xE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE);
    // 0x800DDF48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DDF4C: lwc1        $f8, -0x36B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X36B8);
    // 0x800DDF50: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800DDF54: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800DDF58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DDF5C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800DDF60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800DDF64: jal         0x800E3E8C
    // 0x800DDF68: nop

    func_800E3E8C(rdram, ctx);
        goto after_2;
    // 0x800DDF68: nop

    after_2:
    // 0x800DDF6C: beql        $v0, $zero, L_800DDF90
    if (ctx->r2 == 0) {
        // 0x800DDF70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDF90;
    }
    goto skip_0;
    // 0x800DDF70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800DDF74: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x800DDF78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DDF7C: beql        $v0, $zero, L_800DDF90
    if (ctx->r2 == 0) {
        // 0x800DDF80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDF90;
    }
    goto skip_1;
    // 0x800DDF80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800DDF84: jal         0x800DE2A4
    // 0x800DDF88: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_3;
    // 0x800DDF88: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_3:
    // 0x800DDF8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DDF90:
    // 0x800DDF90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DDF94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800DDF98: jr          $ra
    // 0x800DDF9C: nop

    return;
    // 0x800DDF9C: nop

;}
RECOMP_FUNC void capod_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_test_room_quiet()) { ctx->r2 = 0; return; }
    // 0x808005C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005CC: jal         0x8008FFE8
    // 0x808005D0: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808005D0: nop

    after_0:
    // 0x808005D4: beq         $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x808005D8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808005EC;
    }
    // 0x808005D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005DC: jal         0x80089598
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_27(rdram, ctx);
        goto after_1;
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808005E4: b           L_808005F4
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808005F4;
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005EC:
    // 0x808005EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005F4:
    // 0x808005F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void func_80800D38_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D40: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800D44: jal         0x80102FDC
    // 0x80800D48: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800D48: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_0:
    // 0x80800D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D54: jr          $ra
    // 0x80800D58: nop

    return;
    // 0x80800D58: nop

;}
RECOMP_FUNC void _chminegrill2switches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087148: syscall     522
    recomp_syscall_handler(rdram, ctx, 0x80087148);
    return;
    // 0x8008714C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D211C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D211C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2124: jal         0x800D1FC0
    // 0x800D2128: nop

    func_800D1FC0(rdram, ctx);
        goto after_0;
    // 0x800D2128: nop

    after_0:
    // 0x800D212C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2130: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800D2134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2138: jr          $ra
    // 0x800D213C: nop

    return;
    // 0x800D213C: nop

;}
RECOMP_FUNC void sukickball_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080110C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801110: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801114: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80801118: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080111C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801120: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80801124: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801128: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080112C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801130: jal         0x80100094
    // 0x80801134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801138: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080113C: blez        $s3, L_808011A8
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80801140: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808011A8;
    }
    // 0x80801140: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801144: lbu         $t6, 0x38($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X38);
L_80801148:
    // 0x80801148: addiu       $s1, $s0, 0xC3
    ctx->r17 = ADD32(ctx->r16, 0XC3);
    // 0x8080114C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801150: bne         $t6, $zero, L_80801170
    if (ctx->r14 != 0) {
        // 0x80801154: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80801170;
    }
    // 0x80801154: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80801158: addiu       $s1, $s0, 0xC3
    ctx->r17 = ADD32(ctx->r16, 0XC3);
    // 0x8080115C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801160: jal         0x800D2770
    // 0x80801164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2770(rdram, ctx);
        goto after_1;
    // 0x80801164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801168: b           L_80801180
    // 0x8080116C: nop

        goto L_80801180;
    // 0x8080116C: nop

L_80801170:
    // 0x80801170: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x80801174: lw          $a1, 0x20($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X20);
    // 0x80801178: jal         0x800D24E8
    // 0x8080117C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_2;
    // 0x8080117C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80801180:
    // 0x80801180: beq         $s4, $zero, L_8080119C
    if (ctx->r20 == 0) {
        // 0x80801184: addu        $t9, $s2, $s0
        ctx->r25 = ADD32(ctx->r18, ctx->r16);
            goto L_8080119C;
    }
    // 0x80801184: addu        $t9, $s2, $s0
    ctx->r25 = ADD32(ctx->r18, ctx->r16);
    // 0x80801188: lbu         $t0, 0x30($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X30);
    // 0x8080118C: beql        $t0, $zero, L_808011A0
    if (ctx->r8 == 0) {
        // 0x80801190: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808011A0;
    }
    goto skip_0;
    // 0x80801190: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801194: jal         0x800D28A0
    // 0x80801198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D28A0(rdram, ctx);
        goto after_3;
    // 0x80801198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_8080119C:
    // 0x8080119C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808011A0:
    // 0x808011A0: bnel        $s0, $s3, L_80801148
    if (ctx->r16 != ctx->r19) {
        // 0x808011A4: lbu         $t6, 0x38($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X38);
            goto L_80801148;
    }
    goto skip_1;
    // 0x808011A4: lbu         $t6, 0x38($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X38);
    skip_1:
L_808011A8:
    // 0x808011A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808011AC: sb          $t1, 0x38($s2)
    MEM_B(0X38, ctx->r18) = ctx->r9;
    // 0x808011B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808011B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808011B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808011BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808011C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808011C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011C8: jr          $ra
    // 0x808011CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808011CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80803078_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080307C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803080: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80803084: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80803088: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080308C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80803090: jal         0x80100094
    // 0x80803094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803098: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080309C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808030A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808030A4: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x808030A8: beq         $at, $zero, L_80803214
    if (ctx->r1 == 0) {
        // 0x808030AC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80803214;
    }
    // 0x808030AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808030B0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A58) << 16);
    // 0x808030B4: addu        $at, $at, $t6
    gpr jr_addend_808030BC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808030B8: lw          $t6, -0x65A8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A58));
    // 0x808030BC: jr          $t6
    // 0x808030C0: nop

    switch (jr_addend_808030BC >> 2) {
        case 0: goto L_808030C4; break;
        case 1: goto L_80803214; break;
        case 2: goto L_808030D4; break;
        case 3: goto L_80803190; break;
        case 4: goto L_808030F0; break;
        case 5: goto L_80803164; break;
        case 6: goto L_80803214; break;
        case 7: goto L_80803214; break;
        case 8: goto L_80803214; break;
        case 9: goto L_808031AC; break;
        case 10: goto L_808031F4; break;
        default: switch_error(__func__, 0x808030BC, 0x80809A58);
    }
    // 0x808030C0: nop

L_808030C4:
    // 0x808030C4: jal         0x80803338
    // 0x808030C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80803338_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808030C8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808030CC: b           L_80803218
    // 0x808030D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803218;
    // 0x808030D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808030D4:
    // 0x808030D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808030D8: jal         0x80803610
    // 0x808030DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80803610_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808030DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x808030E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808030E4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x808030E8: b           L_80803214
    // 0x808030EC: sb          $t7, 0x40($a1)
    MEM_B(0X40, ctx->r5) = ctx->r15;
        goto L_80803214;
    // 0x808030EC: sb          $t7, 0x40($a1)
    MEM_B(0X40, ctx->r5) = ctx->r15;
L_808030F0:
    // 0x808030F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808030F4: jal         0x80087CB0
    // 0x808030F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _gcnewoption_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808030F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x808030FC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80803100: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80803104: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80803108: xor         $v1, $v0, $t8
    ctx->r3 = ctx->r2 ^ ctx->r24;
    // 0x8080310C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80803110: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80803114: sb          $zero, 0x48($a1)
    MEM_B(0X48, ctx->r5) = 0;
    // 0x80803118: jal         0x80803610
    // 0x8080311C: sb          $v1, 0x41($a1)
    MEM_B(0X41, ctx->r5) = ctx->r3;
    func_80803610_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x8080311C: sb          $v1, 0x41($a1)
    MEM_B(0X41, ctx->r5) = ctx->r3;
    after_4:
    // 0x80803120: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80803124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803128: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080312C: beq         $t9, $zero, L_8080314C
    if (ctx->r25 == 0) {
        // 0x80803130: nop
    
            goto L_8080314C;
    }
    // 0x80803130: nop

    // 0x80803134: jal         0x80087DC8
    // 0x80803138: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gcnewoption_entrypoint_38(rdram, ctx);
        goto after_5;
    // 0x80803138: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x8080313C: jal         0x800FC660
    // 0x80803140: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x80803140: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_6:
    // 0x80803144: b           L_80803218
    // 0x80803148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803218;
    // 0x80803148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080314C:
    // 0x8080314C: jal         0x80087DC0
    // 0x80803150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_7;
    // 0x80803150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80803154: jal         0x800FC660
    // 0x80803158: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_8;
    // 0x80803158: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_8:
    // 0x8080315C: b           L_80803218
    // 0x80803160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803218;
    // 0x80803160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803164:
    // 0x80803164: sb          $zero, 0x41($a1)
    MEM_B(0X41, ctx->r5) = 0;
    // 0x80803168: sb          $zero, 0x48($a1)
    MEM_B(0X48, ctx->r5) = 0;
    // 0x8080316C: jal         0x80803610
    // 0x80803170: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80803610_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80803170: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_9:
    // 0x80803174: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80803178: jal         0x80087DC0
    // 0x8080317C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_10;
    // 0x8080317C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80803180: jal         0x800FC660
    // 0x80803184: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_11;
    // 0x80803184: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_11:
    // 0x80803188: b           L_80803218
    // 0x8080318C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803218;
    // 0x8080318C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803190:
    // 0x80803190: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80803194: jal         0x80803610
    // 0x80803198: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80803610_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x80803198: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_12:
    // 0x8080319C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808031A0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x808031A4: b           L_80803214
    // 0x808031A8: sb          $t0, 0x40($a1)
    MEM_B(0X40, ctx->r5) = ctx->r8;
        goto L_80803214;
    // 0x808031A8: sb          $t0, 0x40($a1)
    MEM_B(0X40, ctx->r5) = ctx->r8;
L_808031AC:
    // 0x808031AC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808031B0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x808031B4: jal         0x800CE8D8
    // 0x808031B8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800CE8D8(rdram, ctx);
        goto after_13;
    // 0x808031B8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_13:
    // 0x808031BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808031C0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808031C4: addiu       $a1, $a1, 0x67D0
    ctx->r5 = ADD32(ctx->r5, 0X67D0);
    // 0x808031C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808031CC: jal         0x800CE928
    // 0x808031D0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    func_800CE928(rdram, ctx);
        goto after_14;
    // 0x808031D0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    after_14:
    // 0x808031D4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808031D8: jal         0x800CEA38
    // 0x808031DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CEA38(rdram, ctx);
        goto after_15;
    // 0x808031DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808031E0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808031E4: jal         0x800CE88C
    // 0x808031E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_16;
    // 0x808031E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808031EC: b           L_80803218
    // 0x808031F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80803218;
    // 0x808031F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808031F4:
    // 0x808031F4: lbu         $t1, 0x48($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X48);
    // 0x808031F8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x808031FC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A84) << 16);
    // 0x80803200: bnel        $t1, $zero, L_80803218
    if (ctx->r9 != 0) {
        // 0x80803204: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803218;
    }
    goto skip_0;
    // 0x80803204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803208: sb          $t2, 0x40($v0)
    MEM_B(0X40, ctx->r2) = ctx->r10;
    // 0x8080320C: lwc1        $f4, -0x657C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A84));
    // 0x80803210: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
L_80803214:
    // 0x80803214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803218:
    // 0x80803218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080321C: jr          $ra
    // 0x80803220: nop

    return;
    // 0x80803220: nop

;}
RECOMP_FUNC void subaddiepalette_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800218: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080021C: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    // 0x80800220: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800224: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800228: beq         $v0, $zero, L_8080029C
    if (ctx->r2 == 0) {
        // 0x8080022C: nop
    
            goto L_8080029C;
    }
    // 0x8080022C: nop

    // 0x80800230: lh          $a0, 0x60($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X60);
    // 0x80800234: beq         $a0, $zero, L_80800274
    if (ctx->r4 == 0) {
        // 0x80800238: nop
    
            goto L_80800274;
    }
    // 0x80800238: nop

    // 0x8080023C: lbu         $t6, 0x7B($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X7B);
    // 0x80800240: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800244: srl         $t7, $t6, 6
    ctx->r15 = S32(U32(ctx->r14) >> 6);
    // 0x80800248: beq         $t7, $zero, L_80800274
    if (ctx->r15 == 0) {
        // 0x8080024C: nop
    
            goto L_80800274;
    }
    // 0x8080024C: nop

    // 0x80800250: jal         0x80100F0C
    // 0x80800254: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80100F0C(rdram, ctx);
        goto after_0;
    // 0x80800254: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800258: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080025C: jal         0x80100AC4
    // 0x80800260: lh          $a0, 0x60($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X60);
    func_80100AC4(rdram, ctx);
        goto after_1;
    // 0x80800260: lh          $a0, 0x60($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X60);
    after_1:
    // 0x80800264: jal         0x800DF720
    // 0x80800268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_2;
    // 0x80800268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080026C: b           L_8080029C
    // 0x80800270: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
        goto L_8080029C;
    // 0x80800270: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
L_80800274:
    // 0x80800274: jal         0x80103C94
    // 0x80800278: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80103C94(rdram, ctx);
        goto after_3;
    // 0x80800278: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8080027C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800280: jal         0x800B2840
    // 0x80800284: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800B2840(rdram, ctx);
        goto after_4;
    // 0x80800284: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80800288: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080028C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800290: jal         0x800B25D8
    // 0x80800294: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    func_800B25D8(rdram, ctx);
        goto after_5;
    // 0x80800294: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_5:
    // 0x80800298: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
L_8080029C:
    // 0x8080029C: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x808002A0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_808002A8;
    }
    // 0x808002A0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x808002A4: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_808002A8:
    // 0x808002A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002B4: jr          $ra
    // 0x808002B8: nop

    return;
    // 0x808002B8: nop

;}
RECOMP_FUNC void func_800947EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800947EC: beql        $a2, $zero, L_8009480C
    if (ctx->r6 == 0) {
        // 0x800947F0: lw          $v0, 0x64($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X64);
            goto L_8009480C;
    }
    goto skip_0;
    // 0x800947F0: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    skip_0:
    // 0x800947F4: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800947F8: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x800947FC: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80094800: jr          $ra
    // 0x80094804: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    return;
    // 0x80094804: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x80094808: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
L_8009480C:
    // 0x8009480C: nor         $t9, $a1, $zero
    ctx->r25 = ~(ctx->r5 | 0);
    // 0x80094810: lbu         $t8, 0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2);
    // 0x80094814: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80094818: sb          $t0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r8;
    // 0x8009481C: jr          $ra
    // 0x80094820: nop

    return;
    // 0x80094820: nop

;}
RECOMP_FUNC void func_80800000_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800004: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800008: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: addiu       $a0, $zero, 0x510
    ctx->r4 = ADD32(0, 0X510);
    // 0x80800024: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800028: jal         0x800882C0
    // 0x8080002C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80800030: beq         $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x80800034: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_808000AC;
    }
    // 0x80800034: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800038: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080003C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800040: jal         0x80100074
    // 0x80800044: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80800044: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    after_1:
    // 0x80800048: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8080004C: blez        $s3, L_80800078
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80800050: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800078;
    }
    // 0x80800050: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800054: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x80800058: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8080005C:
    // 0x8080005C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800060: jal         0x80088C00
    // 0x80800064: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800064: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800068: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8080006C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800070: bne         $s2, $s3, L_8080005C
    if (ctx->r18 != ctx->r19) {
        // 0x80800074: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8080005C;
    }
    // 0x80800074: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80800078:
    // 0x80800078: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x8080007C: beq         $at, $zero, L_808000AC
    if (ctx->r1 == 0) {
        // 0x80800080: sll         $s1, $s2, 2
        ctx->r17 = S32(ctx->r18 << 2);
            goto L_808000AC;
    }
    // 0x80800080: sll         $s1, $s2, 2
    ctx->r17 = S32(ctx->r18 << 2);
    // 0x80800084: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800088: subu        $s1, $s1, $s2
    ctx->r17 = SUB32(ctx->r17, ctx->r18);
    // 0x8080008C: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80800090: addu        $s0, $t6, $s1
    ctx->r16 = ADD32(ctx->r14, ctx->r17);
L_80800094:
    // 0x80800094: jal         0x800EFD24
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080009C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x808000A0: slti        $at, $s1, 0x24
    ctx->r1 = SIGNED(ctx->r17) < 0X24 ? 1 : 0;
    // 0x808000A4: bne         $at, $zero, L_80800094
    if (ctx->r1 != 0) {
        // 0x808000A8: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80800094;
    }
    // 0x808000A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_808000AC:
    // 0x808000AC: jal         0x8008A498
    // 0x808000B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x808000B4: bne         $v0, $zero, L_808000CC
    if (ctx->r2 != 0) {
        // 0x808000B8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1896, 0X1260) << 16);
            goto L_808000CC;
    }
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1896, 0X1260) << 16);
    // 0x808000BC: jal         0x800FFA88
    // 0x808000C0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_5;
    // 0x808000C0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_5:
    // 0x808000C4: b           L_80800124
    // 0x808000C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800124;
    // 0x808000C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808000CC:
    // 0x808000CC: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x808000D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808000D8: swc1        $f4, 0x34($s4)
    MEM_W(0X34, ctx->r20) = ctx->f4.u32l;
    // 0x808000DC: lwc1        $f6, 0x1260($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1896, 0X1260));
    // 0x808000E0: swc1        $f0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f0.u32l;
    // 0x808000E4: swc1        $f0, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f0.u32l;
    // 0x808000E8: jal         0x80800CC0
    // 0x808000EC: swc1        $f6, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->f6.u32l;
    func_80800CC0_chquicksandbaddy(rdram, ctx);
        goto after_6;
    // 0x808000EC: swc1        $f6, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->f6.u32l;
    after_6:
    // 0x808000F0: lwc1        $f8, 0x8($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X8);
    // 0x808000F4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808000F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000FC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800100: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800104: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800108: jal         0x800DC178
    // 0x8080010C: swc1        $f10, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f10.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080010C: swc1        $f10, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f10.u32l;
    after_7:
    // 0x80800110: lbu         $t7, 0x65($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X65);
    // 0x80800114: swc1        $f0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f0.u32l;
    // 0x80800118: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8080011C: sb          $t8, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r24;
    // 0x80800120: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800124:
    // 0x80800124: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800128: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080012C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800130: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800134: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800138: jr          $ra
    // 0x8080013C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080013C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _idflame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E40: syscall     743
    recomp_syscall_handler(rdram, ctx, 0x80088E40);
    return;
    // 0x80088E44: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bsjump_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083250: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083250);
    return;
    // 0x80083254: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800121D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800121D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800121D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800121D8: jal         0x80012194
    // 0x800121DC: nop

    func_80012194(rdram, ctx);
        goto after_0;
    // 0x800121DC: nop

    after_0:
    // 0x800121E0: jal         0x8001E830
    // 0x800121E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001E830(rdram, ctx);
        goto after_1;
    // 0x800121E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800121E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800121EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800121F0: addu        $v1, $v0, $a1
    ctx->r3 = ADD32(ctx->r2, ctx->r5);
    // 0x800121F4: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x800121F8: beq         $t6, $zero, L_8001220C
    if (ctx->r14 == 0) {
        // 0x800121FC: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8001220C;
    }
    // 0x800121FC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80012200:
    // 0x80012200: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x80012204: bnel        $t7, $zero, L_80012200
    if (ctx->r15 != 0) {
        // 0x80012208: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80012200;
    }
    goto skip_0;
    // 0x80012208: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
L_8001220C:
    // 0x8001220C: jr          $ra
    // 0x80012210: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80012210: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808009F8_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F8: jr          $ra
    // 0x808009FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808009FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bstimeout_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F28: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F28);
    return;
    // 0x80083F2C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808001D4_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001E0: jal         0x8009E69C
    // 0x808001E4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x808001E4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_0:
    // 0x808001E8: bnel        $v0, $zero, L_808001FC
    if (ctx->r2 != 0) {
        // 0x808001EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001F0: jal         0x8009EF60
    // 0x808001F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bastick_popZone(rdram, ctx);
        goto after_1;
    // 0x808001F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001FC:
    // 0x808001FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800200: jr          $ra
    // 0x80800204: nop

    return;
    // 0x80800204: nop

;}
RECOMP_FUNC void _mlwave_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FC8: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FC8);
    return;
    // 0x80088FCC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80801260_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80801260_chhumba");
    // 0x80801260: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801264: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1688, 0X26F0) << 16);
    // 0x80801268: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080126C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80801270: addiu       $t6, $t6, 0x26F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1688, 0X26F0));
    // 0x80801274: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801278: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080127C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80801280: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80801284: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80801288: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8080128C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80801290: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x80801294: jal         0x800EF334
    // 0x80801298: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_800EF334(rdram, ctx);
        goto after_0;
    // 0x80801298: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x8080129C: jal         0x8008FE68
    // 0x808012A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x808012A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x808012A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X24C0) << 16);
    // 0x808012A8: lwc1        $f20, 0x24C0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X24C0));
    // 0x808012AC: addiu       $v0, $sp, 0x34
    ctx->r2 = ADD32(ctx->r29, 0X34);
    // 0x808012B0: addiu       $v1, $sp, 0x44
    ctx->r3 = ADD32(ctx->r29, 0X44);
    // 0x808012B4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808012B8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808012BC: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808012C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808012C4: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x808012C8: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x808012CC: beql        $v1, $a0, L_80801300
    if (ctx->r3 == ctx->r4) {
        // 0x808012D0: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_80801300;
    }
    goto skip_0;
    // 0x808012D0: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_0:
    // 0x808012D4: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_808012D8:
    // 0x808012D8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808012DC: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808012E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808012E4: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x808012E8: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x808012EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808012F0: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x808012F4: bnel        $v1, $a0, L_808012D8
    if (ctx->r3 != ctx->r4) {
        // 0x808012F8: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_808012D8;
    }
    goto skip_1;
    // 0x808012F8: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_1:
    // 0x808012FC: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_80801300:
    // 0x80801300: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801304: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
    // 0x80801308: jal         0x800907C0
    // 0x8080130C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800907C0(rdram, ctx);
        goto after_2;
    // 0x8080130C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80801310: jal         0x8008FF40
    // 0x80801314: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008FF40(rdram, ctx);
        goto after_3;
    // 0x80801314: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80801318: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080131C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801320: jal         0x800F1DCC
    // 0x80801324: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x80801324: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80801328: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8080132C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801330: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801334: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801338: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080133C: jal         0x800F1DCC
    // 0x80801340: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80801340: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80801344: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80801348: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080134C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801350: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801354: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801358: jal         0x800F1DCC
    // 0x8080135C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x8080135C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80801360: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80801364: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801368: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080136C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80801370: jal         0x800906DC
    // 0x80801374: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_800906DC(rdram, ctx);
        goto after_7;
    // 0x80801374: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80801378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080137C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801380: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801384: jr          $ra
    // 0x80801388: nop

    return;
    // 0x80801388: nop

;}
RECOMP_FUNC void func_8080036C_glsavegame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080036C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800370: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800374: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800378: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080037C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800380: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800384:
    // 0x80800384: jal         0x800884C8
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _glgamestore_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8080038C: beq         $v0, $zero, L_808003A0
    if (ctx->r2 == 0) {
        // 0x80800390: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808003A0;
    }
    // 0x80800390: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800394: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800398: bne         $s0, $zero, L_80800384
    if (ctx->r16 != 0) {
        // 0x8080039C: nop
    
            goto L_80800384;
    }
    // 0x8080039C: nop

L_808003A0:
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808003A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808003AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B0: jr          $ra
    // 0x808003B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808003B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800DC330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC330: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DC334: lw          $t6, -0x3810($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3810);
    // 0x800DC338: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC33C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DC340: lw          $t7, -0x380C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X380C);
    // 0x800DC344: sw          $t6, -0x3808($at)
    MEM_W(-0X3808, ctx->r1) = ctx->r14;
    // 0x800DC348: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC34C: jr          $ra
    // 0x800DC350: sw          $t7, -0x3804($at)
    MEM_W(-0X3804, ctx->r1) = ctx->r15;
    return;
    // 0x800DC350: sw          $t7, -0x3804($at)
    MEM_W(-0X3804, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80800124_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800128: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080012C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800130: addiu       $t6, $zero, 0x60
    ctx->r14 = ADD32(0, 0X60);
    // 0x80800134: addiu       $t7, $zero, 0x167
    ctx->r15 = ADD32(0, 0X167);
    // 0x80800138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080013C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800140: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800144: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800148: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080014C: jal         0x80086898
    // 0x80800150: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800150: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_0:
    // 0x80800154: beq         $v0, $zero, L_80800194
    if (ctx->r2 == 0) {
        // 0x80800158: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800194;
    }
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x800868A8
    // 0x80800160: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800160: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_1:
    // 0x80800164: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800168: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080016C: jal         0x800868B0
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080017C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80800180: jal         0x800868C8
    // 0x80800184: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800184: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_3:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x800868C0
    // 0x80800190: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800190: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_4:
L_80800194:
    // 0x80800194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800198: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080019C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void _baboost_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845A8: syscall     115
    recomp_syscall_handler(rdram, ctx, 0x800845A8);
    return;
    // 0x800845AC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800AF8_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800AFC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800B00: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800B04: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800B08: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800B0C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800B10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B14: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800B18: jal         0x80100094
    // 0x80800B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B20: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800B24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800B28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800B2C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800B30: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x80800B34: addiu       $s3, $zero, 0x3000
    ctx->r19 = ADD32(0, 0X3000);
L_80800B38:
    // 0x80800B38: lhu         $t6, 0x4($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X4);
    // 0x80800B3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B40: addiu       $a1, $zero, 0x844
    ctx->r5 = ADD32(0, 0X844);
    // 0x80800B44: bnel        $s3, $t6, L_80800B5C
    if (ctx->r19 != ctx->r14) {
        // 0x80800B48: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800B5C;
    }
    goto skip_0;
    // 0x80800B48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80800B4C: jal         0x808007E4
    // 0x80800B50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_1;
    // 0x80800B50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80800B54: swc1        $f20, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f20.u32l;
    // 0x80800B58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800B5C:
    // 0x80800B5C: bne         $s0, $s4, L_80800B38
    if (ctx->r16 != ctx->r20) {
        // 0x80800B60: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_80800B38;
    }
    // 0x80800B60: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x80800B64: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800B68: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800B6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B70: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800B74: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800B78: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B7C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800B80: jr          $ra
    // 0x80800B84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800B84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void baanim_playForDuration_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CBB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CBB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008CBB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CBBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008CBC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008CBC4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CBC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008CBCC: jal         0x8008AF24
    // 0x8008CBD0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8008CBD0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CBD4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008CBD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CBDC: jal         0x8008B1A0
    // 0x8008CBE0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x8008CBE0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8008CBE4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008CBE8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008CBEC: jal         0x8008AED4
    // 0x8008CBF0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8008CBF0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8008CBF4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008CBF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008CBFC: jal         0x8008B1BC
    // 0x8008CC00: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8008CC00: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008CC04: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008CC08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8008CC0C: jal         0x8008B134
    // 0x8008CC10: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x8008CC10: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8008CC14: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8008CC18: jal         0x8008B064
    // 0x8008CC1C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x8008CC1C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_5:
    // 0x8008CC20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CC24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CC28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008CC2C: jr          $ra
    // 0x8008CC30: nop

    return;
    // 0x8008CC30: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083288: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083288);
    return;
    // 0x8008328C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void chswitch_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009D4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808009D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009E0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808009E4: beq         $t6, $at, L_80800ABC
    if (ctx->r14 == ctx->r1) {
        // 0x808009E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800ABC;
    }
    // 0x808009E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009EC: beq         $t6, $at, L_80800A0C
    if (ctx->r14 == ctx->r1) {
        // 0x808009F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800A0C;
    }
    // 0x808009F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808009F4: beq         $t6, $at, L_80800A54
    if (ctx->r14 == ctx->r1) {
        // 0x808009F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800A54;
    }
    // 0x808009F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808009FC: beq         $t6, $at, L_80800A88
    if (ctx->r14 == ctx->r1) {
        // 0x80800A00: nop
    
            goto L_80800A88;
    }
    // 0x80800A00: nop

    // 0x80800A04: b           L_80800AC0
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800AC0;
    // 0x80800A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A0C:
    // 0x80800A0C: jal         0x80101DDC
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800A14: beql        $v0, $zero, L_80800AC0
    if (ctx->r2 == 0) {
        // 0x80800A18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AC0;
    }
    goto skip_0;
    // 0x80800A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800A1C: jal         0x800DA544
    // 0x80800A20: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800A20: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A28: jal         0x80102424
    // 0x80800A2C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800A2C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800A30: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800A34: jal         0x800F7F98
    // 0x80800A38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_3;
    // 0x80800A38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A40: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800A44: jal         0x8010108C
    // 0x80800A48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x80800A48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800A4C: b           L_80800AC0
    // 0x80800A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800AC0;
    // 0x80800A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A54:
    // 0x80800A54: jal         0x800DA298
    // 0x80800A58: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800A58: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_5:
    // 0x80800A5C: beql        $v0, $zero, L_80800AC0
    if (ctx->r2 == 0) {
        // 0x80800A60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AC0;
    }
    goto skip_1;
    // 0x80800A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800A64: jal         0x800DA524
    // 0x80800A68: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA524(rdram, ctx);
        goto after_6;
    // 0x80800A68: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_6:
    // 0x80800A6C: jal         0x800880D0
    // 0x80800A70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800A70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: jal         0x80102424
    // 0x80800A7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800A7C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80800A80: b           L_80800AC0
    // 0x80800A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800AC0;
    // 0x80800A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A88:
    // 0x80800A88: jal         0x80101DDC
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_9;
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800A90: beql        $v0, $zero, L_80800AC0
    if (ctx->r2 == 0) {
        // 0x80800A94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AC0;
    }
    goto skip_2;
    // 0x80800A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800A98: jal         0x800DA524
    // 0x80800A9C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_800DA524(rdram, ctx);
        goto after_10;
    // 0x80800A9C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_10:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80102424
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800AB4: jal         0x8010108C
    // 0x80800AB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_12;
    // 0x80800AB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_80800ABC:
    // 0x80800ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AC0:
    // 0x80800AC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AC8: jr          $ra
    // 0x80800ACC: nop

    return;
    // 0x80800ACC: nop

;}
RECOMP_FUNC void func_808003D4_chjujubagfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808003E0: jal         0x80100094
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808003E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003EC: jal         0x80089880
    // 0x808003F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808003F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808003F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void func_80800618_chpotogoldbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080061C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800620: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80800624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800628: beq         $a1, $v0, L_80800654
    if (ctx->r5 == ctx->r2) {
        // 0x8080062C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800654;
    }
    // 0x8080062C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800630: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800634: beq         $a1, $at, L_808006B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800638: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_808006B0;
    }
    // 0x80800638: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080063C: beq         $a1, $at, L_80800754
    if (ctx->r5 == ctx->r1) {
        // 0x80800640: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_80800754;
    }
    // 0x80800640: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800644: beql        $a1, $at, L_80800710
    if (ctx->r5 == ctx->r1) {
        // 0x80800648: lhu         $t4, 0x72($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X72);
            goto L_80800710;
    }
    goto skip_0;
    // 0x80800648: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x8080064C: b           L_808007C0
    // 0x80800650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007C0;
    // 0x80800650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800654:
    // 0x80800654: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800658: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080065C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800660: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800664: beq         $t7, $at, L_808006A8
    if (ctx->r15 == ctx->r1) {
        // 0x80800668: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_808006A8;
    }
    // 0x80800668: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080066C: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
    // 0x80800670: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800674: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x80800678: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x8080067C: jal         0x80085708
    // 0x80800680: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
    _capod_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80800680: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
    after_0:
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x80103110
    // 0x8080068C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080068C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800690: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2344, 0X910) << 16);
    // 0x80800694: lwc1        $f4, 0x910($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2344, 0X910));
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808006A0: jal         0x80101FDC
    // 0x808006A4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808006A4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    after_2:
L_808006A8:
    // 0x808006A8: b           L_808007C0
    // 0x808006AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007C0;
    // 0x808006AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B0:
    // 0x808006B0: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808006B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006BC: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808006C0: bne         $t1, $at, L_80800704
    if (ctx->r9 != ctx->r1) {
        // 0x808006C4: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_80800704;
    }
    // 0x808006C4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808006C8: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808006CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006D0: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x808006D4: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x808006D8: jal         0x80085708
    // 0x808006DC: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808006DC: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    after_3:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x80103110
    // 0x808006E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x808006E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808006EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2344, 0X914) << 16);
    // 0x808006F0: lwc1        $f6, 0x914($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2344, 0X914));
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808006FC: jal         0x80101FDC
    // 0x80800700: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800700: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    after_5:
L_80800704:
    // 0x80800704: b           L_808007C0
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007C0;
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080070C: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
L_80800710:
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800714: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x80800718: bne         $v0, $t5, L_8080074C
    if (ctx->r2 != ctx->r13) {
        // 0x8080071C: nop
    
            goto L_8080074C;
    }
    // 0x8080071C: nop

    // 0x80800720: jal         0x80103110
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800728: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x8080072C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2344, 0X918) << 16);
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80800738: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x8080073C: lwc1        $f8, 0x918($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2344, 0X918));
    // 0x80800740: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800744: jal         0x80101FDC
    // 0x80800748: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800748: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    after_7:
L_8080074C:
    // 0x8080074C: b           L_808007C0
    // 0x80800750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007C0;
    // 0x80800750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800754:
    // 0x80800754: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800758: bne         $a2, $at, L_808007B8
    if (ctx->r6 != ctx->r1) {
        // 0x8080075C: nop
    
            goto L_808007B8;
    }
    // 0x8080075C: nop

    // 0x80800760: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x80800764: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800768: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080076C: srl         $t8, $v0, 7
    ctx->r24 = S32(U32(ctx->r2) >> 7);
    // 0x80800770: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800774: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800778: bgez        $t8, L_8080078C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080077C: cvt.s.w     $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8080078C;
    }
    // 0x8080077C: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800780: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800784: nop

    // 0x80800788: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8080078C:
    // 0x8080078C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800790: jal         0x800CE8D8
    // 0x80800794: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800CE8D8(rdram, ctx);
        goto after_8;
    // 0x80800794: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_8:
    // 0x80800798: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080079C: addiu       $a1, $a1, 0x75E0
    ctx->r5 = ADD32(ctx->r5, 0X75E0);
    // 0x808007A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007A4: jal         0x800CE928
    // 0x808007A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CE928(rdram, ctx);
        goto after_9;
    // 0x808007A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808007AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007B0: jal         0x800CE88C
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_10;
    // 0x808007B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_808007B8:
    // 0x808007B8: b           L_808007C0
    // 0x808007BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808007C0;
    // 0x808007BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808007C0:
    // 0x808007C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void func_80800A5C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A64: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800A68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800A6C: jal         0x808001A8
    // 0x80800A70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800A70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800A74: jal         0x8008CABC
    // 0x80800A78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800A78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800A7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A80: jal         0x8008AF24
    // 0x80800A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: jal         0x8008B1A0
    // 0x80800A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x80800A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: jal         0x8008AED4
    // 0x80800A9C: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800A9C: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    after_4:
    // 0x80800AA0: lui         $a2, 0x3EB7
    ctx->r6 = S32(0X3EB7 << 16);
    // 0x80800AA4: ori         $a2, $a2, 0xCED9
    ctx->r6 = ctx->r6 | 0XCED9;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: jal         0x8008B1D4
    // 0x80800AB0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x80800AB0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB8: jal         0x8008B1BC
    // 0x80800ABC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800ABC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80800AC0: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800AC4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800AC8: jal         0x8008B24C
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD4: jal         0x8008B134
    // 0x80800AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800ADC: jal         0x8008B064
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800AE4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800AE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AF4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800AF8: jal         0x8009FFD8
    // 0x80800AFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800AFC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80800B00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B04: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800B08: jal         0x8009C99C
    // 0x80800B0C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_11;
    // 0x80800B0C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_11:
    // 0x80800B10: jal         0x8009EF04
    // 0x80800B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_12;
    // 0x80800B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800B18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B1C: nop

    // 0x80800B20: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800B24: nop

    // 0x80800B28: bc1t        L_80800B44
    if (c1cs) {
        // 0x80800B2C: nop
    
            goto L_80800B44;
    }
    // 0x80800B2C: nop

    // 0x80800B30: jal         0x8009EEB8
    // 0x80800B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_13;
    // 0x80800B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800B38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800B3C: jal         0x8009C914
    // 0x80800B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_14;
    // 0x80800B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
L_80800B44:
    // 0x80800B44: jal         0x8009C990
    // 0x80800B48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_15;
    // 0x80800B48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800B4C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800B50: jal         0x8009B9C0
    // 0x80800B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_16;
    // 0x80800B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800B58: jal         0x80800000
    // 0x80800B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_bsvan(rdram, ctx);
        goto after_17;
    // 0x80800B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800B60: jal         0x8009C990
    // 0x80800B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_18;
    // 0x80800B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800B68: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800B6C: jal         0x8009BB00
    // 0x80800B70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800B70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80800B74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800B78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B7C: jal         0x8009BA68
    // 0x80800B80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x80800B80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800B84: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x80800B88: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x80800B8C: jal         0x8009BA58
    // 0x80800B90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_21;
    // 0x80800B90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80800B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B98: jal         0x8009BCB4
    // 0x80800B9C: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_22;
    // 0x80800B9C: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_22:
    // 0x80800BA0: lui         $a1, 0x3FAC
    ctx->r5 = S32(0X3FAC << 16);
    // 0x80800BA4: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x80800BA8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800BAC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800BB0: jal         0x8009D7A4
    // 0x80800BB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009D7A4(rdram, ctx);
        goto after_23;
    // 0x80800BB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x80800BB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BBC: jal         0x800853A0
    // 0x80800BC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _bavan_entrypoint_7(rdram, ctx);
        goto after_24;
    // 0x80800BC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_24:
    // 0x80800BC4: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800BC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BCC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800BD0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80098494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098494: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80098498: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009849C: lw          $t6, 0xAC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XAC);
    // 0x800984A0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800984A4: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x800984A8: lw          $t7, 0xAC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XAC);
    // 0x800984AC: swc1        $f14, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f14.u32l;
    // 0x800984B0: lw          $t8, 0xAC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XAC);
    // 0x800984B4: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800984B8: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x800984BC: lw          $t9, 0xAC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XAC);
    // 0x800984C0: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800984C4: jr          $ra
    // 0x800984C8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    return;
    // 0x800984C8: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_800EE814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE814: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800EE818: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800EE81C: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x800EE820: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x800EE824: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x800EE828: jr          $ra
    // 0x800EE82C: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x800EE82C: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void gcnewoption_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018A0: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x808018A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808018A8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x808018AC: jr          $ra
    // 0x808018B0: sh          $a2, 0x1DC($t9)
    MEM_H(0X1DC, ctx->r25) = ctx->r6;
    return;
    // 0x808018B0: sh          $a2, 0x1DC($t9)
    MEM_H(0X1DC, ctx->r25) = ctx->r6;
;}
RECOMP_FUNC void _cadbfunc_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085698: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085698);
    return;
    // 0x8008569C: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void func_80800AAC_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800AAC_chminisubgame");
    // 0x80800AAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800AB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800AB4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800AB8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800ABC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800AC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800AC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800AC8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800ACC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800AD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AD4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800AD8: jal         0x80100094
    // 0x80800ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AE0: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x80800AE4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800AE8: jal         0x8008FE68
    // 0x80800AEC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x80800AEC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x80800AF0: lw          $a1, 0x30($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X30);
    // 0x80800AF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800AF8: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800AFC: blez        $a1, L_80800B78
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80800B00: addiu       $s4, $zero, 0x2
        ctx->r20 = ADD32(0, 0X2);
            goto L_80800B78;
    }
    // 0x80800B00: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80800B04: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800B08: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_80800B0C:
    // 0x80800B0C: jal         0x800DC128
    // 0x80800B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800B14: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800B18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B1C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800B20: mflo        $t6
    ctx->r14 = lo;
    // 0x80800B24: addu        $a0, $s2, $t6
    ctx->r4 = ADD32(ctx->r18, ctx->r14);
    // 0x80800B28: jal         0x800EEAD4
    // 0x80800B2C: nop

    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x80800B2C: nop

    after_3:
    // 0x80800B30: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80800B34: addu        $v0, $s2, $s0
    ctx->r2 = ADD32(ctx->r18, ctx->r16);
    // 0x80800B38: bc1fl       L_80800B68
    if (!c1cs) {
        // 0x80800B3C: lw          $a1, 0x30($s5)
        ctx->r5 = MEM_W(ctx->r21, 0X30);
            goto L_80800B68;
    }
    goto skip_0;
    // 0x80800B3C: lw          $a1, 0x30($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X30);
    skip_0:
    // 0x80800B40: lbu         $v1, 0x2D0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2D0);
    // 0x80800B44: bne         $s4, $v1, L_80800B54
    if (ctx->r20 != ctx->r3) {
        // 0x80800B48: nop
    
            goto L_80800B54;
    }
    // 0x80800B48: nop

    // 0x80800B4C: b           L_80800B64
    // 0x80800B50: sb          $zero, 0x2D0($v0)
    MEM_B(0X2D0, ctx->r2) = 0;
        goto L_80800B64;
    // 0x80800B50: sb          $zero, 0x2D0($v0)
    MEM_B(0X2D0, ctx->r2) = 0;
L_80800B54:
    // 0x80800B54: bnel        $v1, $zero, L_80800B68
    if (ctx->r3 != 0) {
        // 0x80800B58: lw          $a1, 0x30($s5)
        ctx->r5 = MEM_W(ctx->r21, 0X30);
            goto L_80800B68;
    }
    goto skip_1;
    // 0x80800B58: lw          $a1, 0x30($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X30);
    skip_1:
    // 0x80800B5C: b           L_80800B7C
    // 0x80800B60: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80800B7C;
    // 0x80800B60: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80800B64:
    // 0x80800B64: lw          $a1, 0x30($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X30);
L_80800B68:
    // 0x80800B68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800B6C: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800B70: bne         $at, $zero, L_80800B0C
    if (ctx->r1 != 0) {
        // 0x80800B74: nop
    
            goto L_80800B0C;
    }
    // 0x80800B74: nop

L_80800B78:
    // 0x80800B78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800B7C:
    // 0x80800B7C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B80: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800B84: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B88: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800B8C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800B90: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B94: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800B98: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80800B9C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800BA4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _chcrusher_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AB0: syscall     413
    recomp_syscall_handler(rdram, ctx, 0x80086AB0);
    return;
    // 0x80086AB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088390: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088390);
    return;
    // 0x80088394: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void bsdie_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800688: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080068C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800690: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800694: jal         0x8008CABC
    // 0x80800698: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800698: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080069C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808006A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006AC: jal         0x8008AF24
    // 0x808006B0: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808006B0: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
    after_1:
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: jal         0x8008B1A0
    // 0x808006BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808006BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x8008AED4
    // 0x808006C8: addiu       $a1, $zero, 0xD7
    ctx->r5 = ADD32(0, 0XD7);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808006C8: addiu       $a1, $zero, 0xD7
    ctx->r5 = ADD32(0, 0XD7);
    after_3:
    // 0x808006CC: lui         $a2, 0x3DC8
    ctx->r6 = S32(0X3DC8 << 16);
    // 0x808006D0: ori         $a2, $a2, 0xE8A7
    ctx->r6 = ctx->r6 | 0XE8A7;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: jal         0x8008B1D4
    // 0x808006DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x808006DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808006E0: lui         $a1, 0x4073
    ctx->r5 = S32(0X4073 << 16);
    // 0x808006E4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808006E8: jal         0x8008B1BC
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: jal         0x8008B134
    // 0x808006F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808006F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808006FC: jal         0x8008B064
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800704: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800708: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080070C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(156, 0X950) << 16);
    // 0x80800710: lwc1        $f8, 0x950($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(156, 0X950));
    // 0x80800714: lw          $a1, 0x16C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X16C);
    // 0x80800718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080071C: lui         $a2, 0x43FF
    ctx->r6 = S32(0X43FF << 16);
    // 0x80800720: lui         $a3, 0xC4AF
    ctx->r7 = S32(0XC4AF << 16);
    // 0x80800724: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800728: jal         0x80085220
    // 0x8080072C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _basudie_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x8080072C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80800730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800734: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800738: jal         0x8009BFE4
    // 0x8080073C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_9;
    // 0x8080073C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_9:
    // 0x80800740: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800744: jal         0x8009D820
    // 0x80800748: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D820(rdram, ctx);
        goto after_10;
    // 0x80800748: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x8080074C: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800750: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800754: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800758: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080075C: jr          $ra
    // 0x80800760: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800760: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800DFEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFEA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DFEAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DFEB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DFEB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DFEB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DFEBC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800DFEC0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DFEC4: lw          $s1, 0x0($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X0);
    // 0x800DFEC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DFECC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800DFED0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800DFED4: addu        $s2, $t7, $s0
    ctx->r18 = ADD32(ctx->r15, ctx->r16);
    // 0x800DFED8: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800DFEDC: beq         $at, $zero, L_800DFF14
    if (ctx->r1 == 0) {
        // 0x800DFEE0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800DFF14;
    }
L_800DFEE0:
    // 0x800DFEE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DFEE4: jal         0x800D9600
    // 0x800DFEE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D9600(rdram, ctx);
        goto after_0;
    // 0x800DFEE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800DFEEC: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x800DFEF0: jal         0x800EE7F8
    // 0x800DFEF4: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800DFEF4: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    after_1:
    // 0x800DFEF8: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    // 0x800DFEFC: jal         0x800EE7F8
    // 0x800DFF00: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800DFF00: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    after_2:
    // 0x800DFF04: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x800DFF08: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800DFF0C: bne         $at, $zero, L_800DFEE0
    if (ctx->r1 != 0) {
        // 0x800DFF10: addiu       $s1, $s1, 0x28
        ctx->r17 = ADD32(ctx->r17, 0X28);
            goto L_800DFEE0;
    }
    // 0x800DFF10: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
L_800DFF14:
    // 0x800DFF14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DFF18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DFF1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DFF20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DFF24: jr          $ra
    // 0x800DFF28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800DFF28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800D9CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9CE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D9CEC: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800D9CF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D9CF4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D9CF8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800D9CFC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D9D00: bc1fl       L_800D9D18
    if (!c1cs) {
        // 0x800D9D04: lwc1        $f0, 0x4($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
            goto L_800D9D18;
    }
    goto skip_0;
    // 0x800D9D04: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800D9D08: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800D9D0C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800D9D10: nop

    // 0x800D9D14: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
L_800D9D18:
    // 0x800D9D18: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800D9D1C: lwc1        $f20, 0xC($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800D9D20: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D9D24: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D9D28: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800D9D2C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9D30: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800D9D34: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D9D38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D9D3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D9D40: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D9D44: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800D9D48: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800D9D4C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800D9D50: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D9D54: nop

    // 0x800D9D58: mul.s       $f14, $f12, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800D9D5C: nop

    // 0x800D9D60: mul.s       $f6, $f20, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800D9D64: nop

    // 0x800D9D68: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800D9D6C: nop

    // 0x800D9D70: mul.s       $f10, $f20, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x800D9D74: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800D9D78: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800D9D7C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9D80: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800D9D84: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800D9D88: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800D9D8C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800D9D90: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800D9D94: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800D9D98: mul.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800D9D9C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800D9DA0: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800D9DA4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800D9DA8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D9DAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800D9DB0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D9DB4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D9DB8: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800D9DBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D9DC0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D9DC4: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D9DC8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800D9DCC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9DD0: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D9DD4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D9DD8: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x800D9DDC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D9DE0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D9DE4: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800D9DE8: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x800D9DEC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9DF0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D9DF4: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800D9DF8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D9DFC: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800D9E00: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800D9E04: swc1        $f10, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f10.u32l;
    // 0x800D9E08: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800D9E0C: add.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800D9E10: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800D9E14: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    // 0x800D9E18: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800D9E1C: sub.s       $f4, $f14, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x800D9E20: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x800D9E24: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D9E28: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D9E2C: swc1        $f10, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f10.u32l;
    // 0x800D9E30: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9E34: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x800D9E38: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D9E3C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800D9E40: sub.s       $f4, $f14, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x800D9E44: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
    // 0x800D9E48: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800D9E4C: jr          $ra
    // 0x800D9E50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D9E50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800D9E54: nop

    // 0x800D9E58: nop

    // 0x800D9E5C: nop

;}
