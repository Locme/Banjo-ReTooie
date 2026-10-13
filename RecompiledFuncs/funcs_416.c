#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8009C2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2A0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009C2A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C2A8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8009C2AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C2B0: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8009C2B4: jal         0x800DBEFC
    // 0x8009C2B8: lh          $a1, 0x7F02($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7F02);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x8009C2B8: lh          $a1, 0x7F02($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X7F02);
    after_0:
    // 0x8009C2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C2C4: jr          $ra
    // 0x8009C2C8: nop

    return;
    // 0x8009C2C8: nop

    // 0x8009C2CC: nop

;}
RECOMP_FUNC void func_800F9488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9488: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F948C: lbu         $v0, 0x5520($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5520);
    // 0x800F9490: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800F9494: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F9498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F949C: beq         $v0, $at, L_800F94D0
    if (ctx->r2 == ctx->r1) {
        // 0x800F94A0: sw          $a0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r4;
            goto L_800F94D0;
    }
    // 0x800F94A0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800F94A4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800F94A8: beq         $v0, $at, L_800F9514
    if (ctx->r2 == ctx->r1) {
        // 0x800F94AC: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_800F9514;
    }
    // 0x800F94AC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800F94B0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800F94B4: beq         $v0, $at, L_800F9558
    if (ctx->r2 == ctx->r1) {
        // 0x800F94B8: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_800F9558;
    }
    // 0x800F94B8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800F94BC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800F94C0: beq         $v0, $at, L_800F9598
    if (ctx->r2 == ctx->r1) {
        // 0x800F94C4: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_800F9598;
    }
    // 0x800F94C4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800F94C8: b           L_800F95B8
    // 0x800F94CC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
        goto L_800F95B8;
    // 0x800F94CC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_800F94D0:
    // 0x800F94D0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800F94D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F94D8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F94DC: bne         $t6, $at, L_800F95B4
    if (ctx->r14 != ctx->r1) {
        // 0x800F94E0: addiu       $a1, $sp, 0x5C
        ctx->r5 = ADD32(ctx->r29, 0X5C);
            goto L_800F95B4;
    }
    // 0x800F94E0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F94E4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800F94E8: jal         0x800F92CC
    // 0x800F94EC: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    func_800F92CC(rdram, ctx);
        goto after_0;
    // 0x800F94EC: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x800F94F0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F94F4: jal         0x800F82D4
    // 0x800F94F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x800F94F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800F94FC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F9504: jal         0x800F8268
    // 0x800F9508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_2;
    // 0x800F9508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800F950C: b           L_800F95B8
    // 0x800F9510: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
        goto L_800F95B8;
    // 0x800F9510: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_800F9514:
    // 0x800F9514: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F9518: bne         $t7, $at, L_800F95B4
    if (ctx->r15 != ctx->r1) {
        // 0x800F951C: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_800F95B4;
    }
    // 0x800F951C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F9520: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F9524: jal         0x800F9354
    // 0x800F9528: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800F9354(rdram, ctx);
        goto after_3;
    // 0x800F9528: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x800F952C: jal         0x800F8EBC
    // 0x800F9530: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F8EBC(rdram, ctx);
        goto after_4;
    // 0x800F9530: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x800F9534: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F953C: jal         0x800F8268
    // 0x800F9540: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_5;
    // 0x800F9540: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800F9544: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9548: jal         0x800F82D4
    // 0x800F954C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_6;
    // 0x800F954C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800F9550: b           L_800F95B8
    // 0x800F9554: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
        goto L_800F95B8;
    // 0x800F9554: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_800F9558:
    // 0x800F9558: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F955C: bne         $t8, $at, L_800F95B4
    if (ctx->r24 != ctx->r1) {
        // 0x800F9560: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_800F95B4;
    }
    // 0x800F9560: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F9564: jal         0x800F93C4
    // 0x800F9568: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F93C4(rdram, ctx);
        goto after_7;
    // 0x800F9568: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_7:
    // 0x800F956C: jal         0x800F8EBC
    // 0x800F9570: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F8EBC(rdram, ctx);
        goto after_8;
    // 0x800F9570: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_8:
    // 0x800F9574: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F957C: jal         0x800F8268
    // 0x800F9580: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_9;
    // 0x800F9580: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800F9584: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9588: jal         0x800F82D4
    // 0x800F958C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x800F958C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800F9590: b           L_800F95B8
    // 0x800F9594: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
        goto L_800F95B8;
    // 0x800F9594: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_800F9598:
    // 0x800F9598: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F959C: bne         $t9, $at, L_800F95B4
    if (ctx->r25 != ctx->r1) {
        // 0x800F95A0: addiu       $a0, $sp, 0x58
        ctx->r4 = ADD32(ctx->r29, 0X58);
            goto L_800F95B4;
    }
    // 0x800F95A0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F95A4: jal         0x800F93C4
    // 0x800F95A8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F93C4(rdram, ctx);
        goto after_11;
    // 0x800F95A8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_11:
    // 0x800F95AC: jal         0x800F8E78
    // 0x800F95B0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800F8E78(rdram, ctx);
        goto after_12;
    // 0x800F95B0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_12:
L_800F95B4:
    // 0x800F95B4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_800F95B8:
    // 0x800F95B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F95BC: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800F95C0: addiu       $t2, $t1, -0x2
    ctx->r10 = ADD32(ctx->r9, -0X2);
    // 0x800F95C4: sb          $t0, 0x5520($at)
    MEM_B(0X5520, ctx->r1) = ctx->r8;
    // 0x800F95C8: sltiu       $at, $t2, 0x10
    ctx->r1 = ctx->r10 < 0X10 ? 1 : 0;
    // 0x800F95CC: beq         $at, $zero, L_800F99D8
    if (ctx->r1 == 0) {
        // 0x800F95D0: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_800F99D8;
    }
    // 0x800F95D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800F95D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F95D8: addu        $at, $at, $t2
    gpr jr_addend_800F95E0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800F95DC: lw          $t2, 0x6090($at)
    ctx->r10 = ADD32(ctx->r1, 0X6090);
    // 0x800F95E0: jr          $t2
    // 0x800F95E4: nop

    switch (jr_addend_800F95E0 >> 2) {
        case 0: goto L_800F95E8; break;
        case 1: goto L_800F9628; break;
        case 2: goto L_800F9664; break;
        case 3: goto L_800F9690; break;
        case 4: goto L_800F96F0; break;
        case 5: goto L_800F971C; break;
        case 6: goto L_800F9734; break;
        case 7: goto L_800F977C; break;
        case 8: goto L_800F97A4; break;
        case 9: goto L_800F97E4; break;
        case 10: goto L_800F99D8; break;
        case 11: goto L_800F9820; break;
        case 12: goto L_800F9848; break;
        case 13: goto L_800F9874; break;
        case 14: goto L_800F98D0; break;
        case 15: goto L_800F997C; break;
        default: switch_error(__func__, 0x800F95E0, 0x80126090);
    }
    // 0x800F95E4: nop

L_800F95E8:
    // 0x800F95E8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F95EC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F95F0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800F95F4: jal         0x800F92CC
    // 0x800F95F8: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    func_800F92CC(rdram, ctx);
        goto after_13;
    // 0x800F95F8: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_13:
    // 0x800F95FC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9600: jal         0x800F82D4
    // 0x800F9604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_14;
    // 0x800F9604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x800F9608: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F960C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800F9610: jal         0x800F8268
    // 0x800F9614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_15;
    // 0x800F9614: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x800F9618: jal         0x800F9444
    // 0x800F961C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800F9444(rdram, ctx);
        goto after_16;
    // 0x800F961C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_16:
    // 0x800F9620: b           L_800F99DC
    // 0x800F9624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9628:
    // 0x800F9628: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F962C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F9630: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800F9634: jal         0x800F92CC
    // 0x800F9638: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    func_800F92CC(rdram, ctx);
        goto after_17;
    // 0x800F9638: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_17:
    // 0x800F963C: jal         0x800F8128
    // 0x800F9640: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F8128(rdram, ctx);
        goto after_18;
    // 0x800F9640: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_18:
    // 0x800F9644: jal         0x800F8EE4
    // 0x800F9648: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F8EE4(rdram, ctx);
        goto after_19;
    // 0x800F9648: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_19:
    // 0x800F964C: jal         0x800F8EBC
    // 0x800F9650: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F8EBC(rdram, ctx);
        goto after_20;
    // 0x800F9650: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_20:
    // 0x800F9654: jal         0x800F9400
    // 0x800F9658: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800F9400(rdram, ctx);
        goto after_21;
    // 0x800F9658: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_21:
    // 0x800F965C: b           L_800F99DC
    // 0x800F9660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9664:
    // 0x800F9664: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F9668: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F966C: jal         0x800F9354
    // 0x800F9670: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800F9354(rdram, ctx);
        goto after_22;
    // 0x800F9670: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_22:
    // 0x800F9674: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9678: jal         0x800F82D4
    // 0x800F967C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_23;
    // 0x800F967C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x800F9680: jal         0x800F9444
    // 0x800F9684: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800F9444(rdram, ctx);
        goto after_24;
    // 0x800F9684: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_24:
    // 0x800F9688: b           L_800F99DC
    // 0x800F968C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F968C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9690:
    // 0x800F9690: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F9694: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F9698: jal         0x800F9354
    // 0x800F969C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800F9354(rdram, ctx);
        goto after_25;
    // 0x800F969C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_25:
    // 0x800F96A0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800F96A4: jal         0x800F9070
    // 0x800F96A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F9070(rdram, ctx);
        goto after_26;
    // 0x800F96A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x800F96AC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F96B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800F96B4: jal         0x800F8268
    // 0x800F96B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_27;
    // 0x800F96B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x800F96BC: jal         0x800F8EE4
    // 0x800F96C0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F8EE4(rdram, ctx);
        goto after_28;
    // 0x800F96C0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_28:
    // 0x800F96C4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800F96C8: jal         0x800F9070
    // 0x800F96CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F9070(rdram, ctx);
        goto after_29;
    // 0x800F96CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x800F96D0: jal         0x800F8A5C
    // 0x800F96D4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800F8A5C(rdram, ctx);
        goto after_30;
    // 0x800F96D4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_30:
    // 0x800F96D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F96DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800F96E0: jal         0x800A7990
    // 0x800F96E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A7990(rdram, ctx);
        goto after_31;
    // 0x800F96E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_31:
    // 0x800F96E8: b           L_800F99DC
    // 0x800F96EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F96EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F96F0:
    // 0x800F96F0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F96F4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800F96F8: jal         0x800F9354
    // 0x800F96FC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800F9354(rdram, ctx);
        goto after_32;
    // 0x800F96FC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_32:
    // 0x800F9700: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9704: jal         0x800F82D4
    // 0x800F9708: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_33;
    // 0x800F9708: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x800F970C: jal         0x800F9400
    // 0x800F9710: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800F9400(rdram, ctx);
        goto after_34;
    // 0x800F9710: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_34:
    // 0x800F9714: b           L_800F99DC
    // 0x800F9718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F971C:
    // 0x800F971C: jal         0x800F929C
    // 0x800F9720: nop

    func_800F929C(rdram, ctx);
        goto after_35;
    // 0x800F9720: nop

    after_35:
    // 0x800F9724: jal         0x800F9444
    // 0x800F9728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F9444(rdram, ctx);
        goto after_36;
    // 0x800F9728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
    // 0x800F972C: b           L_800F99DC
    // 0x800F9730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9734:
    // 0x800F9734: jal         0x800F929C
    // 0x800F9738: nop

    func_800F929C(rdram, ctx);
        goto after_37;
    // 0x800F9738: nop

    after_37:
    // 0x800F973C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800F9740: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F9744: jal         0x800F9070
    // 0x800F9748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F9070(rdram, ctx);
        goto after_38;
    // 0x800F9748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
    // 0x800F974C: jal         0x800DB9B0
    // 0x800F9750: nop

    func_800DB9B0(rdram, ctx);
        goto after_39;
    // 0x800F9750: nop

    after_39:
    // 0x800F9754: bnel        $v0, $zero, L_800F99DC
    if (ctx->r2 != 0) {
        // 0x800F9758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F99DC;
    }
    goto skip_0;
    // 0x800F9758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F975C: jal         0x800F8A5C
    // 0x800F9760: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800F8A5C(rdram, ctx);
        goto after_40;
    // 0x800F9760: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_40:
    // 0x800F9764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F9768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800F976C: jal         0x800A7990
    // 0x800F9770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A7990(rdram, ctx);
        goto after_41;
    // 0x800F9770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_41:
    // 0x800F9774: b           L_800F99DC
    // 0x800F9778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F977C:
    // 0x800F977C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F9780: jal         0x800F93C4
    // 0x800F9784: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F93C4(rdram, ctx);
        goto after_42;
    // 0x800F9784: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_42:
    // 0x800F9788: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F978C: jal         0x800F82D4
    // 0x800F9790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_43;
    // 0x800F9790: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_43:
    // 0x800F9794: jal         0x800F9400
    // 0x800F9798: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800F9400(rdram, ctx);
        goto after_44;
    // 0x800F9798: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_44:
    // 0x800F979C: b           L_800F99DC
    // 0x800F97A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F97A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F97A4:
    // 0x800F97A4: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F97A8: jal         0x800F93C4
    // 0x800F97AC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F93C4(rdram, ctx);
        goto after_45;
    // 0x800F97AC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_45:
    // 0x800F97B0: jal         0x800878A0
    // 0x800F97B4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_46;
    // 0x800F97B4: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_46:
    // 0x800F97B8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800F97BC: jal         0x800F8128
    // 0x800F97C0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F8128(rdram, ctx);
        goto after_47;
    // 0x800F97C0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_47:
    // 0x800F97C4: jal         0x800F759C
    // 0x800F97C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F759C(rdram, ctx);
        goto after_48;
    // 0x800F97C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_48:
    // 0x800F97CC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F97D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F97D4: jal         0x800F8268
    // 0x800F97D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_49;
    // 0x800F97D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_49:
    // 0x800F97DC: b           L_800F99DC
    // 0x800F97E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F97E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F97E4:
    // 0x800F97E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F97E8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800F97EC: lbu         $a0, 0x5522($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X5522);
    // 0x800F97F0: lbu         $t3, 0x5521($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X5521);
    // 0x800F97F4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800F97F8: jal         0x800F8128
    // 0x800F97FC: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    func_800F8128(rdram, ctx);
        goto after_50;
    // 0x800F97FC: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    after_50:
    // 0x800F9800: jal         0x800F759C
    // 0x800F9804: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F759C(rdram, ctx);
        goto after_51;
    // 0x800F9804: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_51:
    // 0x800F9808: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800F980C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F9810: jal         0x800F8268
    // 0x800F9814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_52;
    // 0x800F9814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_52:
    // 0x800F9818: b           L_800F99DC
    // 0x800F981C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F981C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9820:
    // 0x800F9820: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F9824: jal         0x800F93C4
    // 0x800F9828: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F93C4(rdram, ctx);
        goto after_53;
    // 0x800F9828: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_53:
    // 0x800F982C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F9830: jal         0x800F82D4
    // 0x800F9834: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_54;
    // 0x800F9834: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_54:
    // 0x800F9838: jal         0x800F9444
    // 0x800F983C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800F9444(rdram, ctx);
        goto after_55;
    // 0x800F983C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_55:
    // 0x800F9840: b           L_800F99DC
    // 0x800F9844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9848:
    // 0x800F9848: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800F984C: jal         0x800F9070
    // 0x800F9850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F9070(rdram, ctx);
        goto after_56;
    // 0x800F9850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_56:
    // 0x800F9854: jal         0x800F8A5C
    // 0x800F9858: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800F8A5C(rdram, ctx);
        goto after_57;
    // 0x800F9858: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_57:
    // 0x800F985C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F9860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800F9864: jal         0x800A7990
    // 0x800F9868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A7990(rdram, ctx);
        goto after_58;
    // 0x800F9868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_58:
    // 0x800F986C: b           L_800F99DC
    // 0x800F9870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9874:
    // 0x800F9874: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800F9878: jal         0x800F93C4
    // 0x800F987C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F93C4(rdram, ctx);
        goto after_59;
    // 0x800F987C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_59:
    // 0x800F9880: jal         0x800F6224
    // 0x800F9884: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F6224(rdram, ctx);
        goto after_60;
    // 0x800F9884: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_60:
    // 0x800F9888: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800F988C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F9890: jal         0x800F7E64
    // 0x800F9894: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800F7E64(rdram, ctx);
        goto after_61;
    // 0x800F9894: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_61:
    // 0x800F9898: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800F989C: jal         0x800F608C
    // 0x800F98A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_62;
    // 0x800F98A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x800F98A4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800F98A8: jal         0x800F9240
    // 0x800F98AC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800F9240(rdram, ctx);
        goto after_63;
    // 0x800F98AC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_63:
    // 0x800F98B0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800F98B4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800F98B8: jal         0x800F7CF4
    // 0x800F98BC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800F7CF4(rdram, ctx);
        goto after_64;
    // 0x800F98BC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_64:
    // 0x800F98C0: jal         0x800F9400
    // 0x800F98C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800F9400(rdram, ctx);
        goto after_65;
    // 0x800F98C4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_65:
    // 0x800F98C8: b           L_800F99DC
    // 0x800F98CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F98CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F98D0:
    // 0x800F98D0: jal         0x800878A0
    // 0x800F98D4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_66;
    // 0x800F98D4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_66:
    // 0x800F98D8: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x800F98DC: jal         0x800878A0
    // 0x800F98E0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_67;
    // 0x800F98E0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_67:
    // 0x800F98E4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800F98E8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F98EC: jal         0x800F5A00
    // 0x800F98F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_68;
    // 0x800F98F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_68:
    // 0x800F98F4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800F98F8: jal         0x800F5A00
    // 0x800F98FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_69;
    // 0x800F98FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_69:
    // 0x800F9900: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800F9904: jal         0x800EEB40
    // 0x800F9908: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EEB40(rdram, ctx);
        goto after_70;
    // 0x800F9908: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_70:
    // 0x800F990C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F9910: lwc1        $f4, 0x60D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X60D0);
    // 0x800F9914: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800F9918: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800F991C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F9920: nop

    // 0x800F9924: bc1f        L_800F993C
    if (!c1cs) {
        // 0x800F9928: nop
    
            goto L_800F993C;
    }
    // 0x800F9928: nop

    // 0x800F992C: jal         0x800EE7F8
    // 0x800F9930: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_71;
    // 0x800F9930: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_71:
    // 0x800F9934: b           L_800F9948
    // 0x800F9938: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
        goto L_800F9948;
    // 0x800F9938: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_800F993C:
    // 0x800F993C: jal         0x800F9240
    // 0x800F9940: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800F9240(rdram, ctx);
        goto after_72;
    // 0x800F9940: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_72:
    // 0x800F9944: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
L_800F9948:
    // 0x800F9948: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800F994C: jal         0x800F7CF4
    // 0x800F9950: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F7CF4(rdram, ctx);
        goto after_73;
    // 0x800F9950: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_73:
    // 0x800F9954: jal         0x800F8128
    // 0x800F9958: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F8128(rdram, ctx);
        goto after_74;
    // 0x800F9958: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_74:
    // 0x800F995C: jal         0x800F8EBC
    // 0x800F9960: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F8EBC(rdram, ctx);
        goto after_75;
    // 0x800F9960: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_75:
    // 0x800F9964: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800F9968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F996C: jal         0x800F8268
    // 0x800F9970: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_76;
    // 0x800F9970: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_76:
    // 0x800F9974: b           L_800F99DC
    // 0x800F9978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F99DC;
    // 0x800F9978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F997C:
    // 0x800F997C: jal         0x800878A0
    // 0x800F9980: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_77;
    // 0x800F9980: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_77:
    // 0x800F9984: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x800F9988: jal         0x800878A0
    // 0x800F998C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_78;
    // 0x800F998C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_78:
    // 0x800F9990: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800F9994: jal         0x800F759C
    // 0x800F9998: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F759C(rdram, ctx);
        goto after_79;
    // 0x800F9998: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_79:
    // 0x800F999C: jal         0x800D5234
    // 0x800F99A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D5234(rdram, ctx);
        goto after_80;
    // 0x800F99A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_80:
    // 0x800F99A4: jal         0x800A16BC
    // 0x800F99A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A16BC(rdram, ctx);
        goto after_81;
    // 0x800F99A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_81:
    // 0x800F99AC: jal         0x800F8128
    // 0x800F99B0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F8128(rdram, ctx);
        goto after_82;
    // 0x800F99B0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_82:
    // 0x800F99B4: jal         0x800F8EBC
    // 0x800F99B8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800F8EBC(rdram, ctx);
        goto after_83;
    // 0x800F99B8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_83:
    // 0x800F99BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800F99C0: jal         0x800F7B9C
    // 0x800F99C4: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    func_800F7B9C(rdram, ctx);
        goto after_84;
    // 0x800F99C4: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_84:
    // 0x800F99C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800F99CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F99D0: jal         0x800F8268
    // 0x800F99D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_85;
    // 0x800F99D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_85:
L_800F99D8:
    // 0x800F99D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F99DC:
    // 0x800F99DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800F99E0: jr          $ra
    // 0x800F99E4: nop

    return;
    // 0x800F99E4: nop

;}
RECOMP_FUNC void func_800EE5AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE5AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EE5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE5B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EE5B8: jal         0x8001BAFC
    // 0x800EE5BC: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    defrag(rdram, ctx);
        goto after_0;
    // 0x800EE5BC: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    after_0:
    // 0x800EE5C0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800EE5C4: sw          $v0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r2;
    // 0x800EE5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EE5CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EE5D0: jr          $ra
    // 0x800EE5D4: nop

    return;
    // 0x800EE5D4: nop

;}
RECOMP_FUNC void func_80802104_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080210C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802110: jal         0x80100094
    // 0x80802114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802118: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080211C: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80802120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802124: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80802128: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080212C: nop

    // 0x80802130: bc1tl       L_80802174
    if (c1cs) {
        // 0x80802134: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802174;
    }
    goto skip_0;
    // 0x80802134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802138: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080213C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80802140: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802144: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80802148: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x8080214C: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80802150: beq         $t6, $zero, L_80802168
    if (ctx->r14 == 0) {
        // 0x80802154: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80802168;
    }
    // 0x80802154: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80802158: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x8080215C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80802160: bgezl       $t9, L_80802174
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802164: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802174;
    }
    goto skip_1;
    // 0x80802164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80802168:
    // 0x80802168: jal         0x80018820
    // 0x8080216C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    func_80018820(rdram, ctx);
        goto after_1;
    // 0x8080216C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_1:
    // 0x80802170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802174:
    // 0x80802174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802178: jr          $ra
    // 0x8080217C: nop

    return;
    // 0x8080217C: nop

;}
RECOMP_FUNC void func_808016F8_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016F8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808016FC: sb          $a1, 0x90($a0)
    MEM_B(0X90, ctx->r4) = ctx->r5;
    // 0x80801700: swc1        $f12, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f12.u32l;
    // 0x80801704: swc1        $f12, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f12.u32l;
    // 0x80801708: jr          $ra
    // 0x8080170C: swc1        $f12, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8080170C: swc1        $f12, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_801085CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801085CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801085D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801085D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801085D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x801085DC: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x801085E0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_801085E4:
    // 0x801085E4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x801085E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801085EC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x801085F0: bne         $v0, $a0, L_801085E4
    if (ctx->r2 != ctx->r4) {
        // 0x801085F4: sw          $t6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r14;
            goto L_801085E4;
    }
    // 0x801085F4: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x801085F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801085FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80108600: jal         0x80108C90
    // 0x80108604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80108C90(rdram, ctx);
        goto after_0;
    // 0x80108604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80108608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010860C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80108610: jr          $ra
    // 0x80108614: nop

    return;
    // 0x80108614: nop

;}
RECOMP_FUNC void func_808006E4_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006F0: jal         0x80103EAC
    // 0x808006F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80103EAC(rdram, ctx);
        goto after_0;
    // 0x808006F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808006F8: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: jal         0x80103EAC
    // 0x80800704: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80103EAC(rdram, ctx);
        goto after_1;
    // 0x80800704: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800708: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080070C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800710: nop

    // 0x80800714: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800718: jal         0x800C8A98
    // 0x8080071C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x8080071C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800720: beq         $v0, $zero, L_8080074C
    if (ctx->r2 == 0) {
        // 0x80800724: sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
            goto L_8080074C;
    }
    // 0x80800724: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80800728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080072C: jal         0x800C8F64
    // 0x80800730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x80800730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800734: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80800738: jal         0x800C8D4C
    // 0x8080073C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C8D4C(rdram, ctx);
        goto after_4;
    // 0x8080073C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80800740: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80800744: jal         0x800C8FE0
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_5;
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_8080074C:
    // 0x8080074C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800750: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800754: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800758: jr          $ra
    // 0x8080075C: nop

    return;
    // 0x8080075C: nop

;}
RECOMP_FUNC void func_800EE904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE904: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE908: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800EE90C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800EE910: nop

    // 0x800EE914: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800EE918: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE91C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800EE920: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800EE924: nop

    // 0x800EE928: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800EE92C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE930: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800EE934: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800EE938: jr          $ra
    // 0x800EE93C: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    return;
    // 0x800EE93C: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void chfactorylinkgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2316, 0X250) << 16);
    // 0x8080011C: jr          $ra
    // 0x80800120: addiu       $v0, $v0, 0x250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2316, 0X250));
    return;
    // 0x80800120: addiu       $v0, $v0, 0x250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2316, 0X250));
;}
RECOMP_FUNC void chboilerid_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800650: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800654: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800658: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080065C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800660: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800664: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800668: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080066C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800670: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800674: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800678: jal         0x80106790
    // 0x8080067C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080067C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x80800680: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800684: jal         0x80100094
    // 0x80800688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080068C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800690: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800694: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800698: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
    // 0x8080069C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808006A0: beq         $at, $zero, L_808006E4
    if (ctx->r1 == 0) {
        // 0x808006A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006E4;
    }
L_808006A4:
    // 0x808006A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006AC: jal         0x80800700
    // 0x808006B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80800700_chboilerid(rdram, ctx);
        goto after_2;
    // 0x808006B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x808006B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006BC: jal         0x8080079C
    // 0x808006C0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8080079C_chboilerid(rdram, ctx);
        goto after_3;
    // 0x808006C0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x808006C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808006CC: jal         0x80800918
    // 0x808006D0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80800918_chboilerid(rdram, ctx);
        goto after_4;
    // 0x808006D0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x808006D4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808006D8: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808006DC: bne         $at, $zero, L_808006A4
    if (ctx->r1 != 0) {
        // 0x808006E0: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_808006A4;
    }
    // 0x808006E0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_808006E4:
    // 0x808006E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808006F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808006F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808006F8: jr          $ra
    // 0x808006FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808006FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800CA6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA6FC: jr          $ra
    // 0x800CA700: lwc1        $f0, 0xE8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE8);
    return;
    // 0x800CA700: lwc1        $f0, 0xE8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE8);
;}
RECOMP_FUNC void _chfactoryroofbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874B0: syscall     578
    recomp_syscall_handler(rdram, ctx, 0x800874B0);
    return;
    // 0x800874B4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80806B38_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806B38: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80806B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806B40: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80806B44: jal         0x80100094
    // 0x80806B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806B4C: lbu         $t6, 0x5F($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5F);
    // 0x80806B50: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80806B54: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80806B58: bne         $t6, $zero, L_80806B70
    if (ctx->r14 != 0) {
        // 0x80806B5C: lui         $at, 0x8081
        ctx->r1 = S32(RELOC_HI16(1480, 0X9BF0) << 16);
            goto L_80806B70;
    }
    // 0x80806B5C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9BF0) << 16);
    // 0x80806B60: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80806B64: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80806B68: beq         $t7, $zero, L_80806B80
    if (ctx->r15 == 0) {
        // 0x80806B6C: nop
    
            goto L_80806B80;
    }
    // 0x80806B6C: nop

L_80806B70:
    // 0x80806B70: sb          $t8, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r24;
    // 0x80806B74: lwc1        $f4, -0x6410($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9BF0));
    // 0x80806B78: b           L_80806BF8
    // 0x80806B7C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
        goto L_80806BF8;
    // 0x80806B7C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
L_80806B80:
    // 0x80806B80: jal         0x80802248
    // 0x80806B84: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80806B84: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80806B88: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80806B8C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80806B90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80806B94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80806B98: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80806B9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80806BA0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80806BA4: sb          $t9, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r25;
    // 0x80806BA8: jal         0x800F5A00
    // 0x80806BAC: swc1        $f6, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f6.u32l;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80806BAC: swc1        $f6, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f6.u32l;
    after_2:
    // 0x80806BB0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80806BB4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80806BB8: jal         0x800F1DF4
    // 0x80806BBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x80806BBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80806BC0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80806BC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80806BC8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80806BCC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80806BD0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80806BD4: jal         0x800EFA4C
    // 0x80806BD8: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80806BD8: nop

    after_4:
    // 0x80806BDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806BE0: jal         0x800F8444
    // 0x80806BE4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F8444(rdram, ctx);
        goto after_5;
    // 0x80806BE4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80806BE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806BEC: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80806BF0: jal         0x800F7C58
    // 0x80806BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7C58(rdram, ctx);
        goto after_6;
    // 0x80806BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
L_80806BF8:
    // 0x80806BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806BFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80806C00: jr          $ra
    // 0x80806C04: nop

    return;
    // 0x80806C04: nop

;}
RECOMP_FUNC void _glintrosyncDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885F8: syscall     695
    recomp_syscall_handler(rdram, ctx, 0x800885F8);
    return;
    // 0x800885FC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080372C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080372C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803734: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803738: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080373C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80803740: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80803744: jal         0x800F1DCC
    // 0x80803748: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x80803748: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8080374C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80803750: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80803754: lwc1        $f12, 0x48($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80803758: jal         0x800F1DCC
    // 0x8080375C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x8080375C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80803760: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80803764: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803768: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8080376C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80803770: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80803774: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80803778: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080377C: bc1fl       L_8080378C
    if (!c1cs) {
        // 0x80803780: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8080378C;
    }
    goto skip_0;
    // 0x80803780: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_0:
    // 0x80803784: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80803788: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8080378C:
    // 0x8080378C: nop

    // 0x80803790: bc1fl       L_808037A0
    if (!c1cs) {
        // 0x80803794: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_808037A0;
    }
    goto skip_1;
    // 0x80803794: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_1:
    // 0x80803798: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x8080379C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_808037A0:
    // 0x808037A0: nop

    // 0x808037A4: bc1fl       L_808037B8
    if (!c1cs) {
        // 0x808037A8: swc1        $f6, 0x54($v0)
        MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
            goto L_808037B8;
    }
    goto skip_2;
    // 0x808037A8: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
    skip_2:
    // 0x808037AC: b           L_808037B8
    // 0x808037B0: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
        goto L_808037B8;
    // 0x808037B0: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x808037B4: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
L_808037B8:
    // 0x808037B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808037BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808037C0: jr          $ra
    // 0x808037C4: nop

    return;
    // 0x808037C4: nop

;}
RECOMP_FUNC void ncbaspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808007F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800800: jal         0x80110840
    // 0x80800804: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80800804: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800808: jal         0x800F5C94
    // 0x8080080C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5C94(rdram, ctx);
        goto after_1;
    // 0x8080080C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800810: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800814: beql        $v0, $at, L_80800A08
    if (ctx->r2 == ctx->r1) {
        // 0x80800818: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A08;
    }
    goto skip_0;
    // 0x80800818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080081C: jal         0x800D542C
    // 0x80800820: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800D542C(rdram, ctx);
        goto after_2;
    // 0x80800820: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_2:
    // 0x80800824: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800828: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x8080082C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800830: lw          $v1, 0x28($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X28);
    // 0x80800834: beql        $v0, $v1, L_80800A08
    if (ctx->r2 == ctx->r3) {
        // 0x80800838: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A08;
    }
    goto skip_1;
    // 0x80800838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080083C: beq         $v1, $at, L_80800A04
    if (ctx->r3 == ctx->r1) {
        // 0x80800840: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A04;
    }
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800844: jal         0x801107B0
    // 0x80800848: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_801107B0(rdram, ctx);
        goto after_3;
    // 0x80800848: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_3:
    // 0x8080084C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800850: jal         0x800EE904
    // 0x80800854: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EE904(rdram, ctx);
        goto after_4;
    // 0x80800854: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80800858: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080085C: jal         0x800882E8
    // 0x80800860: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    _gccubesearch_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800860: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80800864: beq         $v0, $zero, L_80800A04
    if (ctx->r2 == 0) {
        // 0x80800868: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800A04;
    }
    // 0x80800868: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080086C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800870: jal         0x80088C00
    // 0x80800874: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800874: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x80800878: jal         0x80088C10
    // 0x8080087C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _gspropctrl_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x8080087C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800880: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800884: beq         $v0, $at, L_808008B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800888: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808008B0;
    }
    // 0x80800888: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080088C: beq         $v0, $at, L_808008C8
    if (ctx->r2 == ctx->r1) {
        // 0x80800890: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808008C8;
    }
    // 0x80800890: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800894: beql        $v0, $at, L_808008E4
    if (ctx->r2 == ctx->r1) {
        // 0x80800898: lw          $t6, 0x44($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X44);
            goto L_808008E4;
    }
    goto skip_2;
    // 0x80800898: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    skip_2:
    // 0x8080089C: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x808008A0: sb          $zero, 0x2E($t7)
    MEM_B(0X2E, ctx->r15) = 0;
    // 0x808008A4: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x808008A8: b           L_808008F8
    // 0x808008AC: sb          $zero, 0x2F($t8)
    MEM_B(0X2F, ctx->r24) = 0;
        goto L_808008F8;
    // 0x808008AC: sb          $zero, 0x2F($t8)
    MEM_B(0X2F, ctx->r24) = 0;
L_808008B0:
    // 0x808008B0: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x808008B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808008B8: sb          $t9, 0x2E($t0)
    MEM_B(0X2E, ctx->r8) = ctx->r25;
    // 0x808008BC: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x808008C0: b           L_808008F8
    // 0x808008C4: sb          $zero, 0x2F($t1)
    MEM_B(0X2F, ctx->r9) = 0;
        goto L_808008F8;
    // 0x808008C4: sb          $zero, 0x2F($t1)
    MEM_B(0X2F, ctx->r9) = 0;
L_808008C8:
    // 0x808008C8: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x808008CC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808008D0: sb          $zero, 0x2E($t2)
    MEM_B(0X2E, ctx->r10) = 0;
    // 0x808008D4: lw          $t4, 0x44($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X44);
    // 0x808008D8: b           L_808008F8
    // 0x808008DC: sb          $t3, 0x2F($t4)
    MEM_B(0X2F, ctx->r12) = ctx->r11;
        goto L_808008F8;
    // 0x808008DC: sb          $t3, 0x2F($t4)
    MEM_B(0X2F, ctx->r12) = ctx->r11;
    // 0x808008E0: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
L_808008E4:
    // 0x808008E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808008E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808008EC: sb          $t5, 0x2E($t6)
    MEM_B(0X2E, ctx->r14) = ctx->r13;
    // 0x808008F0: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x808008F4: sb          $t7, 0x2F($t8)
    MEM_B(0X2F, ctx->r24) = ctx->r15;
L_808008F8:
    // 0x808008F8: jal         0x801106A0
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801106A0(rdram, ctx);
        goto after_8;
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800900: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800908: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080090C: jal         0x801107F0
    // 0x80800910: sb          $v0, 0x2D($t9)
    MEM_B(0X2D, ctx->r25) = ctx->r2;
    func_801107F0(rdram, ctx);
        goto after_9;
    // 0x80800910: sb          $v0, 0x2D($t9)
    MEM_B(0X2D, ctx->r25) = ctx->r2;
    after_9:
    // 0x80800914: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x80800918: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080091C: jal         0x800EE7F8
    // 0x80800920: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800920: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_10:
    // 0x80800924: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800928: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x8080092C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800930: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x80800934: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x80800938: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8080093C: jal         0x80088498
    // 0x80800940: sw          $t1, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r9;
    _glsplinefind_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800940: sw          $t1, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r9;
    after_11:
    // 0x80800944: lw          $t3, 0x44($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X44);
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: jal         0x80800008
    // 0x80800950: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    func_80800008_ncbaspline(rdram, ctx);
        goto after_12;
    // 0x80800950: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    after_12:
    // 0x80800954: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800958: jal         0x800C82CC
    // 0x8080095C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800C82CC(rdram, ctx);
        goto after_13;
    // 0x8080095C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_13:
    // 0x80800960: lw          $t4, 0x44($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X44);
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: jal         0x80800008
    // 0x8080096C: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
    func_80800008_ncbaspline(rdram, ctx);
        goto after_14;
    // 0x8080096C: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
    after_14:
    // 0x80800970: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x80800974: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80800978: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x8080097C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800980: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800984: jal         0x800FB1EC
    // 0x80800988: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    func_800FB1EC(rdram, ctx);
        goto after_15;
    // 0x80800988: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    after_15:
    // 0x8080098C: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x80800990: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800998: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x8080099C: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x808009A0: jal         0x80800008
    // 0x808009A4: sb          $t7, 0x2C($t8)
    MEM_B(0X2C, ctx->r24) = ctx->r15;
    func_80800008_ncbaspline(rdram, ctx);
        goto after_16;
    // 0x808009A4: sb          $t7, 0x2C($t8)
    MEM_B(0X2C, ctx->r24) = ctx->r15;
    after_16:
    // 0x808009A8: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x808009AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009B0: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x808009B4: jal         0x800C7A68
    // 0x808009B8: addiu       $a2, $v1, 0x1C
    ctx->r6 = ADD32(ctx->r3, 0X1C);
    func_800C7A68(rdram, ctx);
        goto after_17;
    // 0x808009B8: addiu       $a2, $v1, 0x1C
    ctx->r6 = ADD32(ctx->r3, 0X1C);
    after_17:
    // 0x808009BC: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x808009C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C4: jal         0x80800318
    // 0x808009C8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_80800318_ncbaspline(rdram, ctx);
        goto after_18;
    // 0x808009C8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_18:
    // 0x808009CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009D0: bne         $v0, $at, L_808009FC
    if (ctx->r2 != ctx->r1) {
        // 0x808009D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009FC;
    }
    // 0x808009D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D8: jal         0x801106A8
    // 0x808009DC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_801106A8(rdram, ctx);
        goto after_19;
    // 0x808009DC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_19:
    // 0x808009E0: jal         0x80110840
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110840(rdram, ctx);
        goto after_20;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808009E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009EC: jal         0x800F7E9C
    // 0x808009F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7E9C(rdram, ctx);
        goto after_21;
    // 0x808009F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x808009F4: b           L_80800A08
    // 0x808009F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A08;
    // 0x808009F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009FC:
    // 0x808009FC: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80800A00: sw          $zero, 0x28($t9)
    MEM_W(0X28, ctx->r25) = 0;
L_80800A04:
    // 0x80800A04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A08:
    // 0x80800A08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800A10: jr          $ra
    // 0x80800A14: nop

    return;
    // 0x80800A14: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DC0: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DC0);
    return;
    // 0x80082DC4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bskazjump_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083468: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083468);
    return;
    // 0x8008346C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800CFA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFA90: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CFA94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CFA98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CFA9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CFAA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CFAA4: addiu       $a0, $zero, 0x6A0
    ctx->r4 = ADD32(0, 0X6A0);
    // 0x800CFAA8: jal         0x800DA9E4
    // 0x800CFAAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x800CFAAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800CFAB0: beq         $v0, $zero, L_800CFAC0
    if (ctx->r2 == 0) {
        // 0x800CFAB4: nop
    
            goto L_800CFAC0;
    }
    // 0x800CFAB4: nop

    // 0x800CFAB8: b           L_800CFBB0
    // 0x800CFABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CFBB0;
    // 0x800CFABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CFAC0:
    // 0x800CFAC0: jal         0x800DA298
    // 0x800CFAC4: addiu       $a0, $zero, 0x379
    ctx->r4 = ADD32(0, 0X379);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x800CFAC4: addiu       $a0, $zero, 0x379
    ctx->r4 = ADD32(0, 0X379);
    after_1:
    // 0x800CFAC8: bne         $v0, $zero, L_800CFB00
    if (ctx->r2 != 0) {
        // 0x800CFACC: addiu       $a0, $zero, 0x37A
        ctx->r4 = ADD32(0, 0X37A);
            goto L_800CFB00;
    }
    // 0x800CFACC: addiu       $a0, $zero, 0x37A
    ctx->r4 = ADD32(0, 0X37A);
    // 0x800CFAD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFAD4: jal         0x800DC128
    // 0x800CFAD8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x800CFAD8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_2:
    // 0x800CFADC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CFAE0: addiu       $a0, $zero, 0x37A
    ctx->r4 = ADD32(0, 0X37A);
    // 0x800CFAE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CFAE8: jal         0x800DA7A8
    // 0x800CFAEC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800DA7A8(rdram, ctx);
        goto after_3;
    // 0x800CFAEC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x800CFAF0: jal         0x800DA544
    // 0x800CFAF4: addiu       $a0, $zero, 0x379
    ctx->r4 = ADD32(0, 0X379);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x800CFAF4: addiu       $a0, $zero, 0x379
    ctx->r4 = ADD32(0, 0X379);
    after_4:
    // 0x800CFAF8: b           L_800CFB0C
    // 0x800CFAFC: nop

        goto L_800CFB0C;
    // 0x800CFAFC: nop

L_800CFB00:
    // 0x800CFB00: jal         0x800DA564
    // 0x800CFB04: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DA564(rdram, ctx);
        goto after_5;
    // 0x800CFB04: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x800CFB08: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800CFB0C:
    // 0x800CFB0C: jal         0x800DC330
    // 0x800CFB10: nop

    func_800DC330(rdram, ctx);
        goto after_6;
    // 0x800CFB10: nop

    after_6:
    // 0x800CFB14: jal         0x800DC324
    // 0x800CFB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DC324(rdram, ctx);
        goto after_7;
    // 0x800CFB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800CFB1C: addiu       $v0, $sp, 0x44
    ctx->r2 = ADD32(ctx->r29, 0X44);
    // 0x800CFB20: addiu       $v1, $sp, 0x68
    ctx->r3 = ADD32(ctx->r29, 0X68);
L_800CFB24:
    // 0x800CFB24: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800CFB28: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800CFB2C: bne         $at, $zero, L_800CFB24
    if (ctx->r1 != 0) {
        // 0x800CFB30: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800CFB24;
    }
    // 0x800CFB30: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800CFB34: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800CFB38: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800CFB3C: addiu       $s2, $s2, -0x5439
    ctx->r18 = ADD32(ctx->r18, -0X5439);
    // 0x800CFB40: addiu       $s1, $s1, -0x54C0
    ctx->r17 = ADD32(ctx->r17, -0X54C0);
    // 0x800CFB44: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
L_800CFB48:
    // 0x800CFB48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CFB4C: jal         0x800DC128
    // 0x800CFB50: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x800CFB50: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_8:
    // 0x800CFB54: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800CFB58: addu        $v1, $s0, $t6
    ctx->r3 = ADD32(ctx->r16, ctx->r14);
    // 0x800CFB5C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800CFB60: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CFB64: beql        $at, $zero, L_800CFB94
    if (ctx->r1 == 0) {
        // 0x800CFB68: addiu       $s1, $s1, 0x3
        ctx->r17 = ADD32(ctx->r17, 0X3);
            goto L_800CFB94;
    }
    goto skip_0;
    // 0x800CFB68: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    skip_0:
    // 0x800CFB6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CFB70:
    // 0x800CFB70: jal         0x800DC128
    // 0x800CFB74: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800DC128(rdram, ctx);
        goto after_9;
    // 0x800CFB74: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_9:
    // 0x800CFB78: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800CFB7C: addu        $v1, $s0, $t7
    ctx->r3 = ADD32(ctx->r16, ctx->r15);
    // 0x800CFB80: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800CFB84: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CFB88: bnel        $at, $zero, L_800CFB70
    if (ctx->r1 != 0) {
        // 0x800CFB8C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800CFB70;
    }
    goto skip_1;
    // 0x800CFB8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x800CFB90: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
L_800CFB94:
    // 0x800CFB94: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800CFB98: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CFB9C: bne         $s1, $s2, L_800CFB48
    if (ctx->r17 != ctx->r18) {
        // 0x800CFBA0: sb          $v0, -0x2($s1)
        MEM_B(-0X2, ctx->r17) = ctx->r2;
            goto L_800CFB48;
    }
    // 0x800CFBA0: sb          $v0, -0x2($s1)
    MEM_B(-0X2, ctx->r17) = ctx->r2;
    // 0x800CFBA4: jal         0x800DC354
    // 0x800CFBA8: nop

    func_800DC354(rdram, ctx);
        goto after_10;
    // 0x800CFBA8: nop

    after_10:
    // 0x800CFBAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CFBB0:
    // 0x800CFBB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CFBB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CFBB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CFBBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CFBC0: jr          $ra
    // 0x800CFBC4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800CFBC4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80017108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017108: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001710C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80017110: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80017114: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80017118: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8001711C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017120: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80017124: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017128: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001712C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80017130: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80017134: jr          $ra
    // 0x80017138: lh          $v0, -0x5DF4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5DF4);
    return;
    // 0x80017138: lh          $v0, -0x5DF4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5DF4);
;}
RECOMP_FUNC void func_800F293C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F293C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800F2940: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800F2944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F2948: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800F294C:
    // 0x800F294C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F2950: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F2954: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800F2958: swc1        $f4, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f4.u32l;
    // 0x800F295C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F2960: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800F2964: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800F2968: lwc1        $f8, -0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, -0X8);
    // 0x800F296C: swc1        $f8, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f8.u32l;
    // 0x800F2970: lwc1        $f10, -0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X4);
    // 0x800F2974: bne         $v0, $a0, L_800F294C
    if (ctx->r2 != ctx->r4) {
        // 0x800F2978: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800F294C;
    }
    // 0x800F2978: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800F297C: jr          $ra
    // 0x800F2980: nop

    return;
    // 0x800F2980: nop

;}
RECOMP_FUNC void baanim_playForDuration_onceStartingAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CE3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CE40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008CE44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CE48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008CE4C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008CE50: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008CE54: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CE58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008CE5C: jal         0x8008AF24
    // 0x8008CE60: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8008CE60: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CE64: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008CE68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008CE6C: jal         0x8008B1A0
    // 0x8008CE70: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x8008CE70: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8008CE74: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008CE78: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008CE7C: jal         0x8008AED4
    // 0x8008CE80: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8008CE80: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8008CE84: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008CE88: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008CE8C: jal         0x8008B1BC
    // 0x8008CE90: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8008CE90: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008CE94: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008CE98: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CE9C: jal         0x8008B24C
    // 0x8008CEA0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x8008CEA0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8008CEA4: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8008CEA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008CEAC: jal         0x8008B134
    // 0x8008CEB0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x8008CEB0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_5:
    // 0x8008CEB4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8008CEB8: jal         0x8008B064
    // 0x8008CEBC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x8008CEBC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_6:
    // 0x8008CEC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CEC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CEC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008CECC: jr          $ra
    // 0x8008CED0: nop

    return;
    // 0x8008CED0: nop

;}
RECOMP_FUNC void func_800E4628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4628: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E462C: addiu       $v0, $v0, -0x2AAC
    ctx->r2 = ADD32(ctx->r2, -0X2AAC);
    // 0x800E4630: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800E4634: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E4638: jr          $ra
    // 0x800E463C: sw          $zero, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = 0;
    return;
    // 0x800E463C: sw          $zero, -0x2AA8($at)
    MEM_W(-0X2AA8, ctx->r1) = 0;
;}
RECOMP_FUNC void __babackpack_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x80800018: jal         0x8008ADBC
    // 0x8080001C: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    func_8008ADBC(rdram, ctx);
        goto after_0;
    // 0x8080001C: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    after_0:
    // 0x80800020: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80800028: sw          $zero, 0x14($t9)
    MEM_W(0X14, ctx->r25) = 0;
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_800B9038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B903C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9040: jal         0x800B8FEC
    // 0x800B9044: nop

    func_800B8FEC(rdram, ctx);
        goto after_0;
    // 0x800B9044: nop

    after_0:
    // 0x800B9048: jal         0x8001ACCC
    // 0x800B904C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x800B904C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x800B9050: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B9054: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B9058: addiu       $a1, $a1, 0x7128
    ctx->r5 = ADD32(ctx->r5, 0X7128);
    // 0x800B905C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800B9060: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x800B9064: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800B9068: addiu       $a0, $zero, 0x960
    ctx->r4 = ADD32(0, 0X960);
    // 0x800B906C: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800B9070: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800B9074: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B9078: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x800B907C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800B9080: swc1        $f2, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f2.u32l;
    // 0x800B9084: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800B9088: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800B908C: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x800B9090: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B9094: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x800B9098: jal         0x8001ACCC
    // 0x800B909C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x800B909C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    after_2:
    // 0x800B90A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B90A4: addiu       $a1, $a1, 0x7128
    ctx->r5 = ADD32(ctx->r5, 0X7128);
    // 0x800B90A8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800B90AC: sw          $v0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r2;
    // 0x800B90B0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800B90B4: sb          $zero, 0x18($t1)
    MEM_B(0X18, ctx->r9) = 0;
    // 0x800B90B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B90BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B90C0: jr          $ra
    // 0x800B90C4: nop

    return;
    // 0x800B90C4: nop

;}
RECOMP_FUNC void func_800B3B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B3B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3B94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B3B98: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800B3B9C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800B3BA0: addu        $t8, $t6, $a3
    ctx->r24 = ADD32(ctx->r14, ctx->r7);
    // 0x800B3BA4: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x800B3BA8: jal         0x800B39D0
    // 0x800B3BAC: lh          $a1, 0x0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X0);
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B3BAC: lh          $a1, 0x0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X0);
    after_0:
    // 0x800B3BB0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3BB4: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800B3BB8: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x800B3BBC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800B3BC0: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x800B3BC4: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800B3BC8: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x800B3BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3BD4: jr          $ra
    // 0x800B3BD8: nop

    return;
    // 0x800B3BD8: nop

;}
RECOMP_FUNC void cothemedll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800460: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800468: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080046C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800470: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800474: sb          $t6, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r14;
    // 0x80800478: jal         0x800DA298
    // 0x8080047C: addiu       $a0, $zero, 0x674
    ctx->r4 = ADD32(0, 0X674);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080047C: addiu       $a0, $zero, 0x674
    ctx->r4 = ADD32(0, 0X674);
    after_0:
    // 0x80800480: bne         $v0, $zero, L_80800490
    if (ctx->r2 != 0) {
        // 0x80800484: nop
    
            goto L_80800490;
    }
    // 0x80800484: nop

    // 0x80800488: jal         0x800FDC28
    // 0x8080048C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x8080048C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_80800490:
    // 0x80800490: jal         0x80800388
    // 0x80800494: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80800388_cothemedll(rdram, ctx);
        goto after_2;
    // 0x80800494: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800498: jal         0x800FE890
    // 0x8080049C: nop

    func_800FE890(rdram, ctx);
        goto after_3;
    // 0x8080049C: nop

    after_3:
    // 0x808004A0: bnel        $v0, $zero, L_8080050C
    if (ctx->r2 != 0) {
        // 0x808004A4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8080050C;
    }
    goto skip_0;
    // 0x808004A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_0:
    // 0x808004A8: jal         0x80800000
    // 0x808004AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80800000_cothemedll(rdram, ctx);
        goto after_4;
    // 0x808004AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808004B0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x808004B4: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x808004B8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x808004BC: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2508, 0X732) << 16);
    // 0x808004C0: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x808004C4: lh          $v1, 0x732($v1)
    ctx->r3 = MEM_H(ctx->r3, (int16_t)RELOC_LO16(2508, 0X732));
    // 0x808004C8: lh          $t9, 0x8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X8);
    // 0x808004CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004D0: sra         $t8, $v1, 2
    ctx->r24 = S32(SIGNED(ctx->r3) >> 2);
    // 0x808004D4: bne         $t8, $t9, L_808004EC
    if (ctx->r24 != ctx->r25) {
        // 0x808004D8: nop
    
            goto L_808004EC;
    }
    // 0x808004D8: nop

    // 0x808004DC: lbu         $t0, 0x41($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X41);
    // 0x808004E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808004E4: beql        $t0, $zero, L_80800508
    if (ctx->r8 == 0) {
        // 0x808004E8: sb          $t1, 0xE($s0)
        MEM_B(0XE, ctx->r16) = ctx->r9;
            goto L_80800508;
    }
    goto skip_1;
    // 0x808004E8: sb          $t1, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r9;
    skip_1:
L_808004EC:
    // 0x808004EC: jal         0x800FC2C4
    // 0x808004F0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    func_800FC2C4(rdram, ctx);
        goto after_5;
    // 0x808004F0: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    after_5:
    // 0x808004F4: jal         0x800FE3EC
    // 0x808004F8: nop

    func_800FE3EC(rdram, ctx);
        goto after_6;
    // 0x808004F8: nop

    after_6:
    // 0x808004FC: b           L_8080050C
    // 0x80800500: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x80800500: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800504: sb          $t1, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r9;
L_80800508:
    // 0x80800508: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8080050C:
    // 0x8080050C: sb          $t2, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r10;
    // 0x80800510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080051C: jr          $ra
    // 0x80800520: nop

    return;
    // 0x80800520: nop

;}
RECOMP_FUNC void func_808005C0_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C8: jal         0x800F54E4
    // 0x808005CC: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808005CC: nop

    after_0:
    // 0x808005D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005D4: jal         0x80800360
    // 0x808005D8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    gcdialogcamera_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808005D8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x808005DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808005E0: jal         0x800856E8
    // 0x808005E4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _capod_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808005E4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005F0: jr          $ra
    // 0x808005F4: nop

    return;
    // 0x808005F4: nop

;}
RECOMP_FUNC void func_808006EC_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006FC: jal         0x8009E55C
    // 0x80800700: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    func_8009E55C(rdram, ctx);
        goto after_0;
    // 0x80800700: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    after_0:
    // 0x80800704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800708: jal         0x80095774
    // 0x8080070C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x8080070C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_1:
    // 0x80800710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800718: jr          $ra
    // 0x8080071C: nop

    return;
    // 0x8080071C: nop

;}
RECOMP_FUNC void func_80800694_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080069C: jal         0x8009E4AC
    // 0x808006A0: nop

    func_8009E4AC(rdram, ctx);
        goto after_0;
    // 0x808006A0: nop

    after_0:
    // 0x808006A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006AC: jr          $ra
    // 0x808006B0: nop

    return;
    // 0x808006B0: nop

;}
RECOMP_FUNC void gsworldDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x8001A2B0
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8001A2B0(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800018: jal         0x80082558
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gsmaker_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800020: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800028: jal         0x800825C8
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800030: bne         $v0, $zero, L_808000E4
    if (ctx->r2 != 0) {
        // 0x80800034: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000E4;
    }
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800038:
    // 0x80800038: jal         0x800825C8
    // 0x8080003C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x8080003C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800040: bne         $v0, $zero, L_808000D0
    if (ctx->r2 != 0) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x800825C8
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800050: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x80800054: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800068;
    }
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x800BDC68
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BDC68(rdram, ctx);
        goto after_5;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800060: b           L_808000D4
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000D4;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800068:
    // 0x80800068: jal         0x800825C8
    // 0x8080006C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_6;
    // 0x8080006C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800070: beq         $v0, $zero, L_80800088
    if (ctx->r2 == 0) {
        // 0x80800074: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800088;
    }
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x800C90F4
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C90F4(rdram, ctx);
        goto after_7;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800080: b           L_808000D4
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000D4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800088:
    // 0x80800088: jal         0x800825C8
    // 0x8080008C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_8;
    // 0x8080008C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x80800090: bne         $v0, $zero, L_808000D0
    if (ctx->r2 != 0) {
        // 0x80800094: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x800825C8
    // 0x8080009C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_9;
    // 0x8080009C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x808000A0: beq         $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B8;
    }
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x80085578
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _cadbio_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000B0: b           L_808000D4
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000D4;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000B8:
    // 0x808000B8: jal         0x800825C8
    // 0x808000BC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_11;
    // 0x808000BC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x808000C0: beql        $v0, $zero, L_808000D4
    if (ctx->r2 == 0) {
        // 0x808000C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000C8: jal         0x800BDC90
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BDC90(rdram, ctx);
        goto after_12;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808000D0:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D4:
    // 0x808000D4: jal         0x800825C8
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_13;
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x808000DC: beql        $v0, $zero, L_80800038
    if (ctx->r2 == 0) {
        // 0x808000E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800038;
    }
    goto skip_1;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_808000E4:
    // 0x808000E4: jal         0x80082548
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gsmaker_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_800DA268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA268: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DA26C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DA270: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800DA274: addiu       $t6, $t6, -0x3874
    ctx->r14 = ADD32(ctx->r14, -0X3874);
    // 0x800DA278: sb          $zero, -0x3874($at)
    MEM_B(-0X3874, ctx->r1) = 0;
    // 0x800DA27C: sb          $zero, -0x3873($at)
    MEM_B(-0X3873, ctx->r1) = 0;
    // 0x800DA280: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800DA284: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x800DA288: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x800DA28C: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800DA290: jr          $ra
    // 0x800DA294: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    return;
    // 0x800DA294: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
;}
RECOMP_FUNC void bsbee_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: jal         0x80084580
    // 0x808001D4: nop

    _babee_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808001D4: nop

    after_0:
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

    // 0x808001E8: nop

    // 0x808001EC: nop

;}
RECOMP_FUNC void func_800F7E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7E3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7E44: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800F7E48: jal         0x800F7C58
    // 0x800F7E4C: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    func_800F7C58(rdram, ctx);
        goto after_0;
    // 0x800F7E4C: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    after_0:
    // 0x800F7E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7E54: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x800F7E58: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800F7E5C: jr          $ra
    // 0x800F7E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F7E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800238_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080023C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800240: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800244: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800248: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080024C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800250: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800254: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800258: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080025C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800260: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800264: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800268: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x8080026C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80800270:
    // 0x80800270: jal         0x8080015C
    // 0x80800274: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080015C_chsilo(rdram, ctx);
        goto after_0;
    // 0x80800274: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80800278: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x8080027C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808002B8;
    }
    // 0x8080027C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800280: addiu       $a2, $s0, 0x9
    ctx->r6 = ADD32(ctx->r16, 0X9);
    // 0x80800284: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1820, 0X12EC) << 16);
    // 0x80800288: addiu       $t9, $t9, 0x12EC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1820, 0X12EC));
    // 0x8080028C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80800290: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x80800294: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x80800298: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8080029C: jal         0x80087CF8
    // 0x808002A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808002A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x808002A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808002A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808002AC: jal         0x80087D90
    // 0x808002B0: lh          $a2, -0x2($s2)
    ctx->r6 = MEM_H(ctx->r18, -0X2);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x808002B0: lh          $a2, -0x2($s2)
    ctx->r6 = MEM_H(ctx->r18, -0X2);
    after_2:
    // 0x808002B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808002B8:
    // 0x808002B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808002BC: bnel        $s0, $s5, L_80800270
    if (ctx->r16 != ctx->r21) {
        // 0x808002C0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800270;
    }
    goto skip_0;
    // 0x808002C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x808002C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808002D8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808002DC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808002E0: jr          $ra
    // 0x808002E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808002E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80805FCC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805FD4: beq         $a1, $zero, L_80806000
    if (ctx->r5 == 0) {
        // 0x80805FD8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80806000;
    }
    // 0x80805FD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80805FDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805FE0: beq         $a1, $at, L_80806018
    if (ctx->r5 == ctx->r1) {
        // 0x80805FE4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80806018;
    }
    // 0x80805FE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805FE8: beq         $a1, $at, L_80806030
    if (ctx->r5 == ctx->r1) {
        // 0x80805FEC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80806030;
    }
    // 0x80805FEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805FF0: beq         $a1, $at, L_80806048
    if (ctx->r5 == ctx->r1) {
        // 0x80805FF4: nop
    
            goto L_80806048;
    }
    // 0x80805FF4: nop

    // 0x80805FF8: b           L_8080605C
    // 0x80805FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080605C;
    // 0x80805FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806000:
    // 0x80806000: jal         0x80088350
    // 0x80806004: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80806004: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80806008: jal         0x80088348
    // 0x8080600C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x8080600C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80806010: b           L_8080605C
    // 0x80806014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080605C;
    // 0x80806014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806018:
    // 0x80806018: jal         0x80088350
    // 0x8080601C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080601C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x80806020: jal         0x80088348
    // 0x80806024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80806024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80806028: b           L_8080605C
    // 0x8080602C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080605C;
    // 0x8080602C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806030:
    // 0x80806030: jal         0x80088350
    // 0x80806034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80806034: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80806038: jal         0x80088348
    // 0x8080603C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x8080603C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x80806040: b           L_8080605C
    // 0x80806044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080605C;
    // 0x80806044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806048:
    // 0x80806048: jal         0x80088350
    // 0x8080604C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcstatusDll_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x8080604C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80806050: jal         0x80088348
    // 0x80806054: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _gcstatusDll_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80806054: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x80806058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080605C:
    // 0x8080605C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806060: jr          $ra
    // 0x80806064: nop

    return;
    // 0x80806064: nop

;}
RECOMP_FUNC void bafly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: jal         0x8008E078
    // 0x808000BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    player_isStable(rdram, ctx);
        goto after_0;
    // 0x808000BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C0: bne         $v0, $zero, L_808000D0
    if (ctx->r2 != 0) {
        // 0x808000C4: nop
    
            goto L_808000D0;
    }
    // 0x808000C4: nop

    // 0x808000C8: b           L_808000EC
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000EC;
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D0:
    // 0x808000D0: jal         0x80096628
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80096628(rdram, ctx);
        goto after_1;
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000D8: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x808000DC: bgez        $t6, L_808000EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808000E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808000EC;
    }
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000E4: b           L_808000EC
    // 0x808000E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000EC;
    // 0x808000E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000EC:
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void func_80801CDC_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CE4: jal         0x800D8FF8
    // 0x80801CE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80801CE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801CEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801CF0: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x80801CF4: beql        $t6, $zero, L_80801D50
    if (ctx->r14 == 0) {
        // 0x80801CF8: lh          $v0, 0x2A($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X2A);
            goto L_80801D50;
    }
    goto skip_0;
    // 0x80801CF8: lh          $v0, 0x2A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2A);
    skip_0:
    // 0x80801CFC: lh          $v0, 0x2A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2A);
    // 0x80801D00: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80801D04: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80801D08: beq         $at, $zero, L_80801D38
    if (ctx->r1 == 0) {
        // 0x80801D0C: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80801D38;
    }
    // 0x80801D0C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801D10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801D14: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80801D18: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801D1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801D20: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80801D24: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801D28: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80801D2C: nop

    // 0x80801D30: sh          $t8, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r24;
    // 0x80801D34: lh          $v0, 0x2A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2A);
L_80801D38:
    // 0x80801D38: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80801D3C: bnel        $at, $zero, L_80801D94
    if (ctx->r1 != 0) {
        // 0x80801D40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801D94;
    }
    goto skip_1;
    // 0x80801D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801D44: b           L_80801D90
    // 0x80801D48: sh          $t9, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r25;
        goto L_80801D90;
    // 0x80801D48: sh          $t9, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r25;
    // 0x80801D4C: lh          $v0, 0x2A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2A);
L_80801D50:
    // 0x80801D50: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801D54: blez        $v0, L_80801D84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801D58: nop
    
            goto L_80801D84;
    }
    // 0x80801D58: nop

    // 0x80801D5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801D60: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80801D64: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801D68: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801D6C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80801D70: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801D74: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80801D78: nop

    // 0x80801D7C: sh          $t1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r9;
    // 0x80801D80: lh          $v0, 0x2A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2A);
L_80801D84:
    // 0x80801D84: bgezl       $v0, L_80801D94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80801D88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801D94;
    }
    goto skip_2;
    // 0x80801D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80801D8C: sh          $zero, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = 0;
L_80801D90:
    // 0x80801D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801D94:
    // 0x80801D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D98: jr          $ra
    // 0x80801D9C: nop

    return;
    // 0x80801D9C: nop

;}
RECOMP_FUNC void func_80800000_bskazow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800845D0
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: jal         0x800832E8
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_80013B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013B90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80013B94: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    // 0x80013B98: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x80013B9C: bc1fl       L_80013BC8
    if (!c1cs) {
        // 0x80013BA0: c.eq.s      $f10, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl == ctx->f14.fl;
            goto L_80013BC8;
    }
    goto skip_0;
    // 0x80013BA0: c.eq.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl == ctx->f14.fl;
    skip_0:
    // 0x80013BA4: c.ole.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl <= ctx->f14.fl;
    // 0x80013BA8: bc1t        L_80013BBC
    if (c1cs) {
        // 0x80013BAC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80013BBC;
    }
    // 0x80013BAC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80013BB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013BB4: jr          $ra
    // 0x80013BB8: nop

    return;
    // 0x80013BB8: nop

L_80013BBC:
    // 0x80013BBC: jr          $ra
    // 0x80013BC0: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    return;
    // 0x80013BC0: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    // 0x80013BC4: c.eq.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl == ctx->f14.fl;
L_80013BC8:
    // 0x80013BC8: bc1fl       L_80013BFC
    if (!c1cs) {
        // 0x80013BCC: lui         $at, 0x3E34
        ctx->r1 = S32(0X3E34 << 16);
            goto L_80013BFC;
    }
    goto skip_1;
    // 0x80013BCC: lui         $at, 0x3E34
    ctx->r1 = S32(0X3E34 << 16);
    skip_1:
    // 0x80013BD0: c.olt.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80013BD4: bc1t        L_80013BE8
    if (c1cs) {
        // 0x80013BD8: lui         $at, 0x4387
        ctx->r1 = S32(0X4387 << 16);
            goto L_80013BE8;
    }
    // 0x80013BD8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80013BDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013BE0: jr          $ra
    // 0x80013BE4: nop

    return;
    // 0x80013BE4: nop

L_80013BE8:
    // 0x80013BE8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80013BEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013BF0: jr          $ra
    // 0x80013BF4: nop

    return;
    // 0x80013BF4: nop

    // 0x80013BF8: lui         $at, 0x3E34
    ctx->r1 = S32(0X3E34 << 16);
L_80013BFC:
    // 0x80013BFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80013C00: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
    // 0x80013C04: jal         0x80013ABC
    // 0x80013C08: div.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    func_80013ABC(rdram, ctx);
        goto after_0;
    // 0x80013C08: div.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    after_0:
    // 0x80013C0C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80013C10: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x80013C14: bc1f        L_80013C28
    if (!c1cs) {
        // 0x80013C18: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80013C28;
    }
    // 0x80013C18: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80013C1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80013C20: nop

    // 0x80013C24: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
L_80013C28:
    // 0x80013C28: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80013C2C: bc1f        L_80013C40
    if (!c1cs) {
        // 0x80013C30: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80013C40;
    }
    // 0x80013C30: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80013C34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80013C38: jr          $ra
    // 0x80013C3C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    return;
    // 0x80013C3C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
L_80013C40:
    // 0x80013C40: jr          $ra
    // 0x80013C44: nop

    return;
    // 0x80013C44: nop

;}
RECOMP_FUNC void static_13_80031178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031178: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003117C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80031180: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80031184: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80031188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003118C: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80031190: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x80031194: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80031198: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003119C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800311A0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800311A4: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800311A8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800311AC: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800311B0: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800311B4: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800311B8: bne         $at, $zero, L_800311E4
    if (ctx->r1 != 0) {
        // 0x800311BC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800311E4;
    }
    // 0x800311BC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800311C0: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x800311C4: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800311C8: beq         $at, $zero, L_800317DC
    if (ctx->r1 == 0) {
        // 0x800311CC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800317DC;
    }
    // 0x800311CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800311D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800311D4: addu        $at, $at, $t7
    gpr jr_addend_800311DC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800311D8: lw          $t7, 0x1E64($at)
    ctx->r15 = ADD32(ctx->r1, 0X1E64);
    // 0x800311DC: jr          $t7
    // 0x800311E0: nop

    switch (jr_addend_800311DC >> 2) {
        case 0: goto L_800314F8; break;
        case 1: goto L_800317DC; break;
        case 2: goto L_800314F8; break;
        case 3: goto L_800317DC; break;
        case 4: goto L_800317DC; break;
        case 5: goto L_800317DC; break;
        case 6: goto L_800317DC; break;
        case 7: goto L_800317DC; break;
        case 8: goto L_800317DC; break;
        case 9: goto L_800317DC; break;
        case 10: goto L_800317DC; break;
        case 11: goto L_800317DC; break;
        case 12: goto L_800317DC; break;
        case 13: goto L_800317DC; break;
        case 14: goto L_800317DC; break;
        case 15: goto L_800317DC; break;
        case 16: goto L_800317DC; break;
        case 17: goto L_800317DC; break;
        case 18: goto L_800317DC; break;
        case 19: goto L_800313A4; break;
        case 20: goto L_800317DC; break;
        case 21: goto L_800317DC; break;
        case 22: goto L_800317DC; break;
        case 23: goto L_800317DC; break;
        case 24: goto L_800317DC; break;
        case 25: goto L_800317DC; break;
        case 26: goto L_800317DC; break;
        case 27: goto L_800317DC; break;
        case 28: goto L_800317DC; break;
        case 29: goto L_800317DC; break;
        case 30: goto L_800311F8; break;
        case 31: goto L_80031230; break;
        case 32: goto L_800314F8; break;
        case 33: goto L_800314F8; break;
        case 34: goto L_800314F8; break;
        case 35: goto L_800317DC; break;
        case 36: goto L_80031230; break;
        case 37: goto L_800317DC; break;
        case 38: goto L_800317DC; break;
        case 39: goto L_800317DC; break;
        case 40: goto L_800317DC; break;
        case 41: goto L_80031660; break;
        case 42: goto L_800313A4; break;
        case 43: goto L_80031730; break;
        case 44: goto L_800317DC; break;
        case 45: goto L_800317DC; break;
        case 46: goto L_80031778; break;
        case 47: goto L_800317DC; break;
        case 48: goto L_800313A4; break;
        case 49: goto L_800317DC; break;
        case 50: goto L_800317DC; break;
        case 51: goto L_800313A4; break;
        default: switch_error(__func__, 0x800311DC, 0x80041E64);
    }
    // 0x800311E0: nop

L_800311E4:
    // 0x800311E4: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800311E8: beql        $v1, $at, L_800317C0
    if (ctx->r3 == ctx->r1) {
        // 0x800311EC: lw          $t6, 0xC($s1)
        ctx->r14 = MEM_W(ctx->r17, 0XC);
            goto L_800317C0;
    }
    goto skip_0;
    // 0x800311EC: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    skip_0:
    // 0x800311F0: b           L_800317E0
    // 0x800311F4: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
        goto L_800317E0;
    // 0x800311F4: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
L_800311F8:
    // 0x800311F8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800311FC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031200: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80031204: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80031208: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8003120C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80031210: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x80031214: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80031218: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x8003121C: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x80031220: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x80031224: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80031228: b           L_800317F4
    // 0x8003122C: sw          $t7, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r15;
        goto L_800317F4;
    // 0x8003122C: sw          $t7, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r15;
L_80031230:
    // 0x80031230: lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X34);
    // 0x80031234: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80031238: bnel        $v0, $at, L_80031270
    if (ctx->r2 != ctx->r1) {
        // 0x8003123C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80031270;
    }
    goto skip_1;
    // 0x8003123C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x80031240: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80031244: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031248: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x8003124C: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80031250: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x80031254: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80031258: lw          $t4, -0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, -0X4);
    // 0x8003125C: sra         $t6, $t4, 31
    ctx->r14 = S32(SIGNED(ctx->r12) >> 31);
    // 0x80031260: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80031264: b           L_800312CC
    // 0x80031268: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
        goto L_800312CC;
    // 0x80031268: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x8003126C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80031270:
    // 0x80031270: bnel        $v0, $at, L_800312A8
    if (ctx->r2 != ctx->r1) {
        // 0x80031274: lw          $t1, 0x0($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X0);
            goto L_800312A8;
    }
    goto skip_2;
    // 0x80031274: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80031278: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8003127C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80031280: addiu       $t5, $t3, 0x7
    ctx->r13 = ADD32(ctx->r11, 0X7);
    // 0x80031284: and         $t8, $t5, $at
    ctx->r24 = ctx->r13 & ctx->r1;
    // 0x80031288: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8003128C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80031290: lw          $t3, -0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, -0X4);
    // 0x80031294: lw          $t2, -0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, -0X8);
    // 0x80031298: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x8003129C: b           L_800312CC
    // 0x800312A0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
        goto L_800312CC;
    // 0x800312A0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800312A4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
L_800312A8:
    // 0x800312A8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800312AC: addiu       $t4, $t1, 0x3
    ctx->r12 = ADD32(ctx->r9, 0X3);
    // 0x800312B0: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x800312B4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800312B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800312BC: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x800312C0: sra         $t0, $t8, 31
    ctx->r8 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800312C4: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800312C8: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
L_800312CC:
    // 0x800312CC: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x800312D0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800312D4: bnel        $t9, $at, L_800312F8
    if (ctx->r25 != ctx->r1) {
        // 0x800312D8: lw          $t0, 0x0($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X0);
            goto L_800312F8;
    }
    goto skip_3;
    // 0x800312D8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x800312DC: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800312E0: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x800312E4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800312E8: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800312EC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800312F0: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800312F4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
L_800312F8:
    // 0x800312F8: bgtzl       $t0, L_80031334
    if (SIGNED(ctx->r8) > 0) {
        // 0x800312FC: lw          $v0, 0x30($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X30);
            goto L_80031334;
    }
    goto skip_4;
    // 0x800312FC: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    skip_4:
    // 0x80031300: bltzl       $t0, L_80031314
    if (SIGNED(ctx->r8) < 0) {
        // 0x80031304: lw          $t2, 0xC($s1)
        ctx->r10 = MEM_W(ctx->r17, 0XC);
            goto L_80031314;
    }
    goto skip_5;
    // 0x80031304: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
    skip_5:
    // 0x80031308: b           L_80031334
    // 0x8003130C: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
        goto L_80031334;
    // 0x8003130C: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x80031310: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
L_80031314:
    // 0x80031314: addiu       $t5, $zero, 0x2D
    ctx->r13 = ADD32(0, 0X2D);
    // 0x80031318: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x8003131C: sb          $t5, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r13;
    // 0x80031320: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x80031324: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80031328: b           L_80031384
    // 0x8003132C: sw          $t6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r14;
        goto L_80031384;
    // 0x8003132C: sw          $t6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r14;
    // 0x80031330: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
L_80031334:
    // 0x80031334: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80031338: beq         $t7, $zero, L_80031360
    if (ctx->r15 == 0) {
        // 0x8003133C: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_80031360;
    }
    // 0x8003133C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80031340: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80031344: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x80031348: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x8003134C: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x80031350: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x80031354: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80031358: b           L_80031384
    // 0x8003135C: sw          $t2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r10;
        goto L_80031384;
    // 0x8003135C: sw          $t2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r10;
L_80031360:
    // 0x80031360: beql        $t5, $zero, L_80031388
    if (ctx->r13 == 0) {
        // 0x80031364: lw          $t8, 0xC($s1)
        ctx->r24 = MEM_W(ctx->r17, 0XC);
            goto L_80031388;
    }
    goto skip_6;
    // 0x80031364: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    skip_6:
    // 0x80031368: lw          $t4, 0xC($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XC);
    // 0x8003136C: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80031370: addu        $t6, $a3, $t4
    ctx->r14 = ADD32(ctx->r7, ctx->r12);
    // 0x80031374: sb          $t3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r11;
    // 0x80031378: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x8003137C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80031380: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
L_80031384:
    // 0x80031384: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
L_80031388:
    // 0x80031388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003138C: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x80031390: addu        $t0, $t8, $a3
    ctx->r8 = ADD32(ctx->r24, ctx->r7);
    // 0x80031394: jal         0x80035F40
    // 0x80031398: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x80031398: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    after_0:
    // 0x8003139C: b           L_800317F8
    // 0x800313A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800317F8;
    // 0x800313A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800313A4:
    // 0x800313A4: lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X34);
    // 0x800313A8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800313AC: bnel        $v0, $at, L_800313E4
    if (ctx->r2 != ctx->r1) {
        // 0x800313B0: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800313E4;
    }
    goto skip_7;
    // 0x800313B0: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x800313B4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800313B8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800313BC: addiu       $t2, $t1, 0x3
    ctx->r10 = ADD32(ctx->r9, 0X3);
    // 0x800313C0: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x800313C4: addiu       $t4, $t5, 0x4
    ctx->r12 = ADD32(ctx->r13, 0X4);
    // 0x800313C8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800313CC: lw          $t6, -0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, -0X4);
    // 0x800313D0: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800313D4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800313D8: b           L_80031440
    // 0x800313DC: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
        goto L_80031440;
    // 0x800313DC: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x800313E0: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800313E4:
    // 0x800313E4: bnel        $v0, $at, L_8003141C
    if (ctx->r2 != ctx->r1) {
        // 0x800313E8: lw          $t3, 0x0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X0);
            goto L_8003141C;
    }
    goto skip_8;
    // 0x800313E8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x800313EC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800313F0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800313F4: addiu       $t0, $t7, 0x7
    ctx->r8 = ADD32(ctx->r15, 0X7);
    // 0x800313F8: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800313FC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80031400: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80031404: lw          $t5, -0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, -0X4);
    // 0x80031408: lw          $t4, -0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X8);
    // 0x8003140C: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    // 0x80031410: b           L_80031440
    // 0x80031414: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
        goto L_80031440;
    // 0x80031414: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80031418: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
L_8003141C:
    // 0x8003141C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031420: addiu       $t6, $t3, 0x3
    ctx->r14 = ADD32(ctx->r11, 0X3);
    // 0x80031424: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80031428: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8003142C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80031430: lw          $t0, -0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X4);
    // 0x80031434: sra         $t2, $t0, 31
    ctx->r10 = S32(SIGNED(ctx->r8) >> 31);
    // 0x80031438: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8003143C: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
L_80031440:
    // 0x80031440: lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X34);
    // 0x80031444: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80031448: bne         $v0, $at, L_80031468
    if (ctx->r2 != ctx->r1) {
        // 0x8003144C: nop
    
            goto L_80031468;
    }
    // 0x8003144C: nop

    // 0x80031450: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x80031454: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80031458: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8003145C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80031460: b           L_80031480
    // 0x80031464: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
        goto L_80031480;
    // 0x80031464: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
L_80031468:
    // 0x80031468: bnel        $v0, $zero, L_80031484
    if (ctx->r2 != 0) {
        // 0x8003146C: lw          $t4, 0x30($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X30);
            goto L_80031484;
    }
    goto skip_9;
    // 0x8003146C: lw          $t4, 0x30($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X30);
    skip_9:
    // 0x80031470: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x80031474: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x80031478: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8003147C: sw          $t1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r9;
L_80031480:
    // 0x80031480: lw          $t4, 0x30($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X30);
L_80031484:
    // 0x80031484: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x80031488: beql        $t5, $zero, L_800314DC
    if (ctx->r13 == 0) {
        // 0x8003148C: lw          $t5, 0xC($s1)
        ctx->r13 = MEM_W(ctx->r17, 0XC);
            goto L_800314DC;
    }
    goto skip_10;
    // 0x8003148C: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    skip_10:
    // 0x80031490: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x80031494: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80031498: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8003149C: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800314A0: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800314A4: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x800314A8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800314AC: beq         $v1, $at, L_800314C0
    if (ctx->r3 == ctx->r1) {
        // 0x800314B0: sw          $t1, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r9;
            goto L_800314C0;
    }
    // 0x800314B0: sw          $t1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r9;
    // 0x800314B4: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x800314B8: bnel        $v1, $at, L_800314DC
    if (ctx->r3 != ctx->r1) {
        // 0x800314BC: lw          $t5, 0xC($s1)
        ctx->r13 = MEM_W(ctx->r17, 0XC);
            goto L_800314DC;
    }
    goto skip_11;
    // 0x800314BC: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    skip_11:
L_800314C0:
    // 0x800314C0: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x800314C4: addu        $t2, $a3, $t7
    ctx->r10 = ADD32(ctx->r7, ctx->r15);
    // 0x800314C8: sb          $a2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r6;
    // 0x800314CC: lw          $t3, 0xC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC);
    // 0x800314D0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800314D4: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    // 0x800314D8: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
L_800314DC:
    // 0x800314DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800314E0: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x800314E4: addu        $t8, $t5, $a3
    ctx->r24 = ADD32(ctx->r13, ctx->r7);
    // 0x800314E8: jal         0x80035F40
    // 0x800314EC: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x800314EC: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    after_1:
    // 0x800314F0: b           L_800317F8
    // 0x800314F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800317F8;
    // 0x800314F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800314F8:
    // 0x800314F8: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x800314FC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80031500: bnel        $t6, $at, L_80031568
    if (ctx->r14 != ctx->r1) {
        // 0x80031504: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80031568;
    }
    goto skip_12;
    // 0x80031504: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_12:
    // 0x80031508: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003150C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80031510: beq         $t9, $zero, L_80031528
    if (ctx->r25 == 0) {
        // 0x80031514: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80031528;
    }
    // 0x80031514: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80031518: addiu       $t0, $v1, 0x7
    ctx->r8 = ADD32(ctx->r3, 0X7);
    // 0x8003151C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80031520: b           L_80031558
    // 0x80031524: addiu       $v0, $t0, -0x16
    ctx->r2 = ADD32(ctx->r8, -0X16);
        goto L_80031558;
    // 0x80031524: addiu       $v0, $t0, -0x16
    ctx->r2 = ADD32(ctx->r8, -0X16);
L_80031528:
    // 0x80031528: andi        $t1, $v1, 0x2
    ctx->r9 = ctx->r3 & 0X2;
    // 0x8003152C: beq         $t1, $zero, L_80031544
    if (ctx->r9 == 0) {
        // 0x80031530: addiu       $t2, $v0, 0x7
        ctx->r10 = ADD32(ctx->r2, 0X7);
            goto L_80031544;
    }
    // 0x80031530: addiu       $t2, $v0, 0x7
    ctx->r10 = ADD32(ctx->r2, 0X7);
    // 0x80031534: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x80031538: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003153C: b           L_80031554
    // 0x80031540: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_80031554;
    // 0x80031540: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_80031544:
    // 0x80031544: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80031548: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8003154C: addiu       $a0, $t3, 0x8
    ctx->r4 = ADD32(ctx->r11, 0X8);
    // 0x80031550: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
L_80031554:
    // 0x80031554: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80031558:
    // 0x80031558: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x8003155C: b           L_800315BC
    // 0x80031560: sdc1        $f4, 0x0($s1)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r17);
        goto L_800315BC;
    // 0x80031560: sdc1        $f4, 0x0($s1)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r17);
    // 0x80031564: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80031568:
    // 0x80031568: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8003156C: beq         $t5, $zero, L_80031584
    if (ctx->r13 == 0) {
        // 0x80031570: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80031584;
    }
    // 0x80031570: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80031574: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x80031578: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003157C: b           L_800315B4
    // 0x80031580: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800315B4;
    // 0x80031580: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_80031584:
    // 0x80031584: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x80031588: beq         $t6, $zero, L_800315A0
    if (ctx->r14 == 0) {
        // 0x8003158C: addiu       $t0, $v0, 0x7
        ctx->r8 = ADD32(ctx->r2, 0X7);
            goto L_800315A0;
    }
    // 0x8003158C: addiu       $t0, $v0, 0x7
    ctx->r8 = ADD32(ctx->r2, 0X7);
    // 0x80031590: addiu       $t9, $v1, 0xA
    ctx->r25 = ADD32(ctx->r3, 0XA);
    // 0x80031594: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80031598: b           L_800315B0
    // 0x8003159C: addiu       $a0, $t9, -0x28
    ctx->r4 = ADD32(ctx->r25, -0X28);
        goto L_800315B0;
    // 0x8003159C: addiu       $a0, $t9, -0x28
    ctx->r4 = ADD32(ctx->r25, -0X28);
L_800315A0:
    // 0x800315A0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800315A4: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800315A8: addiu       $a0, $t1, 0x8
    ctx->r4 = ADD32(ctx->r9, 0X8);
    // 0x800315AC: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
L_800315B0:
    // 0x800315B0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800315B4:
    // 0x800315B4: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x800315B8: sdc1        $f6, 0x0($s1)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r17);
L_800315BC:
    // 0x800315BC: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800315C0: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800315C4: beql        $t3, $zero, L_800315F0
    if (ctx->r11 == 0) {
        // 0x800315C8: lw          $v0, 0x30($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X30);
            goto L_800315F0;
    }
    goto skip_13;
    // 0x800315C8: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    skip_13:
    // 0x800315CC: lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XC);
    // 0x800315D0: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x800315D4: addu        $t8, $a3, $t5
    ctx->r24 = ADD32(ctx->r7, ctx->r13);
    // 0x800315D8: sb          $t4, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r12;
    // 0x800315DC: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x800315E0: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800315E4: b           L_80031640
    // 0x800315E8: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
        goto L_80031640;
    // 0x800315E8: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
    // 0x800315EC: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
L_800315F0:
    // 0x800315F0: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x800315F4: beq         $t0, $zero, L_8003161C
    if (ctx->r8 == 0) {
        // 0x800315F8: andi        $t4, $v0, 0x1
        ctx->r12 = ctx->r2 & 0X1;
            goto L_8003161C;
    }
    // 0x800315F8: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x800315FC: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x80031600: addiu       $t1, $zero, 0x2B
    ctx->r9 = ADD32(0, 0X2B);
    // 0x80031604: addu        $t2, $a3, $t7
    ctx->r10 = ADD32(ctx->r7, ctx->r15);
    // 0x80031608: sb          $t1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r9;
    // 0x8003160C: lw          $t3, 0xC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC);
    // 0x80031610: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80031614: b           L_80031640
    // 0x80031618: sw          $t5, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r13;
        goto L_80031640;
    // 0x80031618: sw          $t5, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r13;
L_8003161C:
    // 0x8003161C: beql        $t4, $zero, L_80031644
    if (ctx->r12 == 0) {
        // 0x80031620: lw          $t1, 0xC($s1)
        ctx->r9 = MEM_W(ctx->r17, 0XC);
            goto L_80031644;
    }
    goto skip_14;
    // 0x80031620: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    skip_14:
    // 0x80031624: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x80031628: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8003162C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80031630: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80031634: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x80031638: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x8003163C: sw          $t7, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r15;
L_80031640:
    // 0x80031640: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
L_80031644:
    // 0x80031644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80031648: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x8003164C: addu        $t2, $t1, $a3
    ctx->r10 = ADD32(ctx->r9, ctx->r7);
    // 0x80031650: jal         0x800361E0
    // 0x80031654: sw          $t2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r10;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x80031654: sw          $t2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r10;
    after_2:
    // 0x80031658: b           L_800317F8
    // 0x8003165C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800317F8;
    // 0x8003165C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031660:
    // 0x80031660: lbu         $v0, 0x34($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X34);
    // 0x80031664: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80031668: bnel        $v0, $at, L_8003169C
    if (ctx->r2 != ctx->r1) {
        // 0x8003166C: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_8003169C;
    }
    goto skip_15;
    // 0x8003166C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x80031670: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80031674: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031678: addiu       $t5, $t3, 0x3
    ctx->r13 = ADD32(ctx->r11, 0X3);
    // 0x8003167C: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x80031680: addiu       $t6, $t4, 0x4
    ctx->r14 = ADD32(ctx->r12, 0X4);
    // 0x80031684: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80031688: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x8003168C: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x80031690: b           L_800317F4
    // 0x80031694: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
        goto L_800317F4;
    // 0x80031694: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x80031698: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_8003169C:
    // 0x8003169C: bnel        $v0, $at, L_800316D0
    if (ctx->r2 != ctx->r1) {
        // 0x800316A0: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800316D0;
    }
    goto skip_16;
    // 0x800316A0: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x800316A4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800316A8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800316AC: addiu       $t7, $t0, 0x3
    ctx->r15 = ADD32(ctx->r8, 0X3);
    // 0x800316B0: and         $t1, $t7, $at
    ctx->r9 = ctx->r15 & ctx->r1;
    // 0x800316B4: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x800316B8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800316BC: lw          $t5, -0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, -0X4);
    // 0x800316C0: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x800316C4: b           L_800317F4
    // 0x800316C8: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
        goto L_800317F4;
    // 0x800316C8: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800316CC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800316D0:
    // 0x800316D0: bnel        $v0, $at, L_8003170C
    if (ctx->r2 != ctx->r1) {
        // 0x800316D4: lw          $t1, 0x0($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X0);
            goto L_8003170C;
    }
    goto skip_17;
    // 0x800316D4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x800316D8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800316DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800316E0: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x800316E4: addiu       $t6, $t4, 0x3
    ctx->r14 = ADD32(ctx->r12, 0X3);
    // 0x800316E8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800316EC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800316F0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800316F4: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800316F8: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x800316FC: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80031700: b           L_800317F4
    // 0x80031704: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
        goto L_800317F4;
    // 0x80031704: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x80031708: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
L_8003170C:
    // 0x8003170C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031710: addiu       $t5, $t1, 0x3
    ctx->r13 = ADD32(ctx->r9, 0X3);
    // 0x80031714: and         $t4, $t5, $at
    ctx->r12 = ctx->r13 & ctx->r1;
    // 0x80031718: addiu       $t6, $t4, 0x4
    ctx->r14 = ADD32(ctx->r12, 0X4);
    // 0x8003171C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80031720: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x80031724: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x80031728: b           L_800317F4
    // 0x8003172C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_800317F4;
    // 0x8003172C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_80031730:
    // 0x80031730: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80031734: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031738: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003173C: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x80031740: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x80031744: addiu       $t7, $t3, 0x4
    ctx->r15 = ADD32(ctx->r11, 0X4);
    // 0x80031748: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003174C: lw          $t5, -0x4($t7)
    ctx->r13 = MEM_W(ctx->r15, -0X4);
    // 0x80031750: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x80031754: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80031758: sra         $t4, $t5, 31
    ctx->r12 = S32(SIGNED(ctx->r13) >> 31);
    // 0x8003175C: addu        $t8, $t6, $a3
    ctx->r24 = ADD32(ctx->r14, ctx->r7);
    // 0x80031760: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80031764: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x80031768: jal         0x80035F40
    // 0x8003176C: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x8003176C: sw          $t5, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r13;
    after_3:
    // 0x80031770: b           L_800317F8
    // 0x80031774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800317F8;
    // 0x80031774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031778:
    // 0x80031778: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8003177C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031780: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x80031784: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80031788: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8003178C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80031790: lw          $a0, -0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, -0X4);
    // 0x80031794: jal         0x80032AB0
    // 0x80031798: sw          $a0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x80031798: sw          $a0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r4;
    after_4:
    // 0x8003179C: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x800317A0: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x800317A4: bltz        $v1, L_800317F4
    if (SIGNED(ctx->r3) < 0) {
        // 0x800317A8: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800317F4;
    }
    // 0x800317A8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800317AC: beql        $at, $zero, L_800317F8
    if (ctx->r1 == 0) {
        // 0x800317B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800317F8;
    }
    goto skip_18;
    // 0x800317B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x800317B4: b           L_800317F4
    // 0x800317B8: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
        goto L_800317F4;
    // 0x800317B8: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x800317BC: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
L_800317C0:
    // 0x800317C0: addiu       $t5, $zero, 0x25
    ctx->r13 = ADD32(0, 0X25);
    // 0x800317C4: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800317C8: sb          $t5, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r13;
    // 0x800317CC: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800317D0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800317D4: b           L_800317F4
    // 0x800317D8: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
        goto L_800317F4;
    // 0x800317D8: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
L_800317DC:
    // 0x800317DC: lw          $t2, 0xC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XC);
L_800317E0:
    // 0x800317E0: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x800317E4: sb          $a2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r6;
    // 0x800317E8: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x800317EC: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x800317F0: sw          $t1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r9;
L_800317F4:
    // 0x800317F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800317F8:
    // 0x800317F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800317FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80031800: jr          $ra
    // 0x80031804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80031804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031808: nop

    // 0x8003180C: nop

;}
RECOMP_FUNC void static_13_80036670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036670: lhu         $a2, 0x0($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X0);
    // 0x80036674: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x80036678: andi        $v1, $a2, 0x7FF0
    ctx->r3 = ctx->r6 & 0X7FF0;
    // 0x8003667C: sra         $t6, $v1, 4
    ctx->r14 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80036680: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80036684: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80036688: bne         $v1, $at, L_800366EC
    if (ctx->r3 != ctx->r1) {
        // 0x8003668C: nop
    
            goto L_800366EC;
    }
    // 0x8003668C: nop

    // 0x80036690: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80036694: lhu         $t9, 0x0($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X0);
    // 0x80036698: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8003669C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800366A0: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800366A4: bne         $t0, $zero, L_800366D0
    if (ctx->r8 != 0) {
        // 0x800366A8: sra         $t4, $v0, 16
        ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800366D0;
    }
    // 0x800366A8: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800366AC: lhu         $t1, 0x2($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X2);
    // 0x800366B0: bne         $t1, $zero, L_800366D0
    if (ctx->r9 != 0) {
        // 0x800366B4: nop
    
            goto L_800366D0;
    }
    // 0x800366B4: nop

    // 0x800366B8: lhu         $t2, 0x4($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X4);
    // 0x800366BC: bne         $t2, $zero, L_800366D0
    if (ctx->r10 != 0) {
        // 0x800366C0: nop
    
            goto L_800366D0;
    }
    // 0x800366C0: nop

    // 0x800366C4: lhu         $t3, 0x6($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X6);
    // 0x800366C8: beql        $t3, $zero, L_800366DC
    if (ctx->r11 == 0) {
        // 0x800366CC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800366DC;
    }
    goto skip_0;
    // 0x800366CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
L_800366D0:
    // 0x800366D0: jr          $ra
    // 0x800366D4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    return;
    // 0x800366D4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800366D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800366DC:
    // 0x800366DC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800366E0: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800366E4: jr          $ra
    // 0x800366E8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    return;
    // 0x800366E8: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800366EC:
    // 0x800366EC: blez        $v1, L_8003670C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800366F0: andi        $t5, $a2, 0x800F
        ctx->r13 = ctx->r6 & 0X800F;
            goto L_8003670C;
    }
    // 0x800366F0: andi        $t5, $a2, 0x800F
    ctx->r13 = ctx->r6 & 0X800F;
    // 0x800366F4: ori         $t6, $t5, 0x3FF0
    ctx->r14 = ctx->r13 | 0X3FF0;
    // 0x800366F8: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800366FC: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x80036700: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80036704: jr          $ra
    // 0x80036708: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80036708: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8003670C:
    // 0x8003670C: bgez        $v1, L_8003671C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80036710: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003671C;
    }
    // 0x80036710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036714: jr          $ra
    // 0x80036718: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80036718: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8003671C:
    // 0x8003671C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80036720: jr          $ra
    // 0x80036724: nop

    return;
    // 0x80036724: nop

;}
RECOMP_FUNC void static_13_80036728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003672C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80036730: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80036734: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036738: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003673C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80036740: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80036744: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80036748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003674C: bgtz        $a3, L_80036760
    if (SIGNED(ctx->r7) > 0) {
        // 0x80036750: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80036760;
    }
    // 0x80036750: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80036754: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80036758: addiu       $s1, $s1, 0x2000
    ctx->r17 = ADD32(ctx->r17, 0X2000);
    // 0x8003675C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80036760:
    // 0x80036760: lbu         $v1, 0x27($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X27);
    // 0x80036764: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x80036768: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x8003676C: beql        $v0, $v1, L_800367A8
    if (ctx->r2 == ctx->r3) {
        // 0x80036770: lh          $t0, 0x32($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X32);
            goto L_800367A8;
    }
    goto skip_0;
    // 0x80036770: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    skip_0:
    // 0x80036774: beq         $a0, $v1, L_80036784
    if (ctx->r4 == ctx->r3) {
        // 0x80036778: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80036784;
    }
    // 0x80036778: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x8003677C: bne         $v1, $at, L_80036A14
    if (ctx->r3 != ctx->r1) {
        // 0x80036780: nop
    
            goto L_80036A14;
    }
    // 0x80036780: nop

L_80036784:
    // 0x80036784: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x80036788: slti        $at, $t0, -0x4
    ctx->r1 = SIGNED(ctx->r8) < -0X4 ? 1 : 0;
    // 0x8003678C: bne         $at, $zero, L_80036A14
    if (ctx->r1 != 0) {
        // 0x80036790: nop
    
            goto L_80036A14;
    }
    // 0x80036790: nop

    // 0x80036794: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80036798: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003679C: beq         $at, $zero, L_80036A14
    if (ctx->r1 == 0) {
        // 0x800367A0: nop
    
            goto L_80036A14;
    }
    // 0x800367A0: nop

    // 0x800367A4: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
L_800367A8:
    // 0x800367A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800367AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800367B0: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x800367B4: beq         $v0, $v1, L_800367F0
    if (ctx->r2 == ctx->r3) {
        // 0x800367B8: sra         $t0, $t9, 16
        ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800367F0;
    }
    // 0x800367B8: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800367BC: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x800367C0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800367C4: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x800367C8: bne         $t3, $zero, L_800367E0
    if (ctx->r11 != 0) {
        // 0x800367CC: slt         $at, $a3, $v0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800367E0;
    }
    // 0x800367CC: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800367D0: beql        $at, $zero, L_800367E4
    if (ctx->r1 == 0) {
        // 0x800367D4: subu        $t4, $v0, $t0
        ctx->r12 = SUB32(ctx->r2, ctx->r8);
            goto L_800367E4;
    }
    goto skip_1;
    // 0x800367D4: subu        $t4, $v0, $t0
    ctx->r12 = SUB32(ctx->r2, ctx->r8);
    skip_1:
    // 0x800367D8: sw          $a3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r7;
    // 0x800367DC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800367E0:
    // 0x800367E0: subu        $t4, $v0, $t0
    ctx->r12 = SUB32(ctx->r2, ctx->r8);
L_800367E4:
    // 0x800367E4: bgez        $t4, L_800367F0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800367E8: sw          $t4, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r12;
            goto L_800367F0;
    }
    // 0x800367E8: sw          $t4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r12;
    // 0x800367EC: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800367F0:
    // 0x800367F0: bgtz        $t0, L_800368C4
    if (SIGNED(ctx->r8) > 0) {
        // 0x800367F4: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800368C4;
    }
    // 0x800367F4: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800367F8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800367FC: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036800: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80036804: negu        $v1, $t0
    ctx->r3 = SUB32(0, ctx->r8);
    // 0x80036808: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003680C: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80036810: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80036814: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036818: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8003681C: bgtz        $v0, L_80036834
    if (SIGNED(ctx->r2) > 0) {
        // 0x80036820: sw          $t2, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r10;
            goto L_80036834;
    }
    // 0x80036820: sw          $t2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r10;
    // 0x80036824: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x80036828: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x8003682C: beql        $t4, $zero, L_8003685C
    if (ctx->r12 == 0) {
        // 0x80036830: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8003685C;
    }
    goto skip_2;
    // 0x80036830: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_2:
L_80036834:
    // 0x80036834: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80036838: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8003683C: addiu       $t5, $zero, 0x2E
    ctx->r13 = ADD32(0, 0X2E);
    // 0x80036840: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80036844: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x80036848: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x8003684C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036850: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80036854: sw          $t1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r9;
    // 0x80036858: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8003685C:
    // 0x8003685C: beql        $at, $zero, L_80036878
    if (ctx->r1 == 0) {
        // 0x80036860: addu        $t4, $v0, $t0
        ctx->r12 = ADD32(ctx->r2, ctx->r8);
            goto L_80036878;
    }
    goto skip_3;
    // 0x80036860: addu        $t4, $v0, $t0
    ctx->r12 = ADD32(ctx->r2, ctx->r8);
    skip_3:
    // 0x80036864: negu        $t0, $v0
    ctx->r8 = SUB32(0, ctx->r2);
    // 0x80036868: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x8003686C: sra         $t0, $t2, 16
    ctx->r8 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80036870: negu        $v1, $t0
    ctx->r3 = SUB32(0, ctx->r8);
    // 0x80036874: addu        $t4, $v0, $t0
    ctx->r12 = ADD32(ctx->r2, ctx->r8);
L_80036878:
    // 0x80036878: slt         $at, $t4, $a3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003687C: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x80036880: beq         $at, $zero, L_80036894
    if (ctx->r1 == 0) {
        // 0x80036884: sw          $t4, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r12;
            goto L_80036894;
    }
    // 0x80036884: sw          $t4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r12;
    // 0x80036888: sll         $a3, $t4, 16
    ctx->r7 = S32(ctx->r12 << 16);
    // 0x8003688C: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80036890: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
L_80036894:
    // 0x80036894: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80036898: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x8003689C: sw          $a3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r7;
    // 0x800368A0: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    // 0x800368A4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800368A8: jal         0x80032AD8
    // 0x800368AC: addu        $a0, $t8, $t5
    ctx->r4 = ADD32(ctx->r24, ctx->r13);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800368AC: addu        $a0, $t8, $t5
    ctx->r4 = ADD32(ctx->r24, ctx->r13);
    after_0:
    // 0x800368B0: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x800368B4: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x800368B8: subu        $t9, $t6, $a3
    ctx->r25 = SUB32(ctx->r14, ctx->r7);
    // 0x800368BC: b           L_80036C90
    // 0x800368C0: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
        goto L_80036C90;
    // 0x800368C0: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
L_800368C4:
    // 0x800368C4: beq         $at, $zero, L_8003694C
    if (ctx->r1 == 0) {
        // 0x800368C8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8003694C;
    }
    // 0x800368C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800368CC: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800368D0: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x800368D4: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x800368D8: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    // 0x800368DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800368E0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800368E4: jal         0x80032AD8
    // 0x800368E8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800368E8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800368EC: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x800368F0: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x800368F4: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x800368F8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800368FC: subu        $t7, $t0, $a3
    ctx->r15 = SUB32(ctx->r8, ctx->r7);
    // 0x80036900: addu        $t4, $t3, $a3
    ctx->r12 = ADD32(ctx->r11, ctx->r7);
    // 0x80036904: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
    // 0x80036908: bgtz        $v0, L_80036920
    if (SIGNED(ctx->r2) > 0) {
        // 0x8003690C: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_80036920;
    }
    // 0x8003690C: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80036910: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80036914: andi        $t5, $t8, 0x8
    ctx->r13 = ctx->r24 & 0X8;
    // 0x80036918: beq         $t5, $zero, L_80036944
    if (ctx->r13 == 0) {
        // 0x8003691C: nop
    
            goto L_80036944;
    }
    // 0x8003691C: nop

L_80036920:
    // 0x80036920: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80036924: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80036928: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x8003692C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80036930: sb          $t6, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r14;
    // 0x80036934: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    // 0x80036938: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8003693C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80036940: sw          $t4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r12;
L_80036944:
    // 0x80036944: b           L_80036C90
    // 0x80036948: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_80036C90;
    // 0x80036948: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_8003694C:
    // 0x8003694C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80036950: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036954: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x80036958: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    // 0x8003695C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80036960: jal         0x80032AD8
    // 0x80036964: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x80036964: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80036968: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x8003696C: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x80036970: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x80036974: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036978: subu        $a3, $a3, $t0
    ctx->r7 = SUB32(ctx->r7, ctx->r8);
    // 0x8003697C: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x80036980: addu        $t9, $t5, $t0
    ctx->r25 = ADD32(ctx->r13, ctx->r8);
    // 0x80036984: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x80036988: bgtz        $v0, L_800369A0
    if (SIGNED(ctx->r2) > 0) {
        // 0x8003698C: sra         $a3, $t1, 16
        ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
            goto L_800369A0;
    }
    // 0x8003698C: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80036990: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x80036994: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80036998: beql        $t3, $zero, L_800369C8
    if (ctx->r11 == 0) {
        // 0x8003699C: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800369C8;
    }
    goto skip_4;
    // 0x8003699C: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    skip_4:
L_800369A0:
    // 0x800369A0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800369A4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800369A8: addiu       $t4, $zero, 0x2E
    ctx->r12 = ADD32(0, 0X2E);
    // 0x800369AC: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x800369B0: sb          $t4, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r12;
    // 0x800369B4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800369B8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800369BC: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800369C0: sw          $t1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r9;
    // 0x800369C4: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
L_800369C8:
    // 0x800369C8: beq         $at, $zero, L_800369DC
    if (ctx->r1 == 0) {
        // 0x800369CC: addu        $a1, $t0, $s1
        ctx->r5 = ADD32(ctx->r8, ctx->r17);
            goto L_800369DC;
    }
    // 0x800369CC: addu        $a1, $t0, $s1
    ctx->r5 = ADD32(ctx->r8, ctx->r17);
    // 0x800369D0: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x800369D4: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800369D8: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800369DC:
    // 0x800369DC: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x800369E0: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x800369E4: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    // 0x800369E8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800369EC: jal         0x80032AD8
    // 0x800369F0: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800369F0: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x800369F4: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x800369F8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800369FC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80036A00: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80036A04: subu        $t5, $t4, $a3
    ctx->r13 = SUB32(ctx->r12, ctx->r7);
    // 0x80036A08: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x80036A0C: b           L_80036C90
    // 0x80036A10: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_80036C90;
    // 0x80036A10: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_80036A14:
    // 0x80036A14: beq         $a0, $v1, L_80036A28
    if (ctx->r4 == ctx->r3) {
        // 0x80036A18: lh          $t0, 0x32($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X32);
            goto L_80036A28;
    }
    // 0x80036A18: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x80036A1C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80036A20: bnel        $v1, $at, L_80036A70
    if (ctx->r3 != ctx->r1) {
        // 0x80036A24: lw          $t7, 0x8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X8);
            goto L_80036A70;
    }
    goto skip_5;
    // 0x80036A24: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    skip_5:
L_80036A28:
    // 0x80036A28: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036A2C: addiu       $t6, $zero, 0x65
    ctx->r14 = ADD32(0, 0X65);
    // 0x80036A30: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80036A34: beql        $at, $zero, L_80036A48
    if (ctx->r1 == 0) {
        // 0x80036A38: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80036A48;
    }
    goto skip_6;
    // 0x80036A38: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    skip_6:
    // 0x80036A3C: sw          $a3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r7;
    // 0x80036A40: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80036A44: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_80036A48:
    // 0x80036A48: bgez        $t9, L_80036A54
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80036A4C: sw          $t9, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r25;
            goto L_80036A54;
    }
    // 0x80036A4C: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
    // 0x80036A50: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80036A54:
    // 0x80036A54: bnel        $a0, $v1, L_80036A68
    if (ctx->r4 != ctx->r3) {
        // 0x80036A58: addiu       $t2, $zero, 0x45
        ctx->r10 = ADD32(0, 0X45);
            goto L_80036A68;
    }
    goto skip_7;
    // 0x80036A58: addiu       $t2, $zero, 0x45
    ctx->r10 = ADD32(0, 0X45);
    skip_7:
    // 0x80036A5C: b           L_80036A6C
    // 0x80036A60: sb          $t6, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r14;
        goto L_80036A6C;
    // 0x80036A60: sb          $t6, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r14;
    // 0x80036A64: addiu       $t2, $zero, 0x45
    ctx->r10 = ADD32(0, 0X45);
L_80036A68:
    // 0x80036A68: sb          $t2, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r10;
L_80036A6C:
    // 0x80036A6C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
L_80036A70:
    // 0x80036A70: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036A74: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x80036A78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80036A7C: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x80036A80: sb          $t3, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r11;
    // 0x80036A84: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x80036A88: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036A8C: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80036A90: bgtz        $v0, L_80036AA8
    if (SIGNED(ctx->r2) > 0) {
        // 0x80036A94: sw          $t9, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r25;
            goto L_80036AA8;
    }
    // 0x80036A94: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x80036A98: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x80036A9C: andi        $t6, $t1, 0x8
    ctx->r14 = ctx->r9 & 0X8;
    // 0x80036AA0: beq         $t6, $zero, L_80036ACC
    if (ctx->r14 == 0) {
        // 0x80036AA4: nop
    
            goto L_80036ACC;
    }
    // 0x80036AA4: nop

L_80036AA8:
    // 0x80036AA8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80036AAC: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036AB0: addiu       $t2, $zero, 0x2E
    ctx->r10 = ADD32(0, 0X2E);
    // 0x80036AB4: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x80036AB8: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x80036ABC: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80036AC0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036AC4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80036AC8: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
L_80036ACC:
    // 0x80036ACC: blezl       $v0, L_80036B38
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036AD0: lw          $t9, 0x8($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X8);
            goto L_80036B38;
    }
    goto skip_8;
    // 0x80036AD0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    skip_8:
    // 0x80036AD4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80036AD8: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80036ADC: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036AE0: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80036AE4: beq         $at, $zero, L_80036AF8
    if (ctx->r1 == 0) {
        // 0x80036AE8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80036AF8;
    }
    // 0x80036AE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80036AEC: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80036AF0: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80036AF4: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_80036AF8:
    // 0x80036AF8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80036AFC: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036B00: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x80036B04: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    // 0x80036B08: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80036B0C: jal         0x80032AD8
    // 0x80036B10: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x80036B10: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80036B14: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x80036B18: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x80036B1C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80036B20: lh          $t0, 0x32($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X32);
    // 0x80036B24: addu        $t3, $t2, $a3
    ctx->r11 = ADD32(ctx->r10, ctx->r7);
    // 0x80036B28: subu        $t5, $t4, $a3
    ctx->r13 = SUB32(ctx->r12, ctx->r7);
    // 0x80036B2C: sw          $t3, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r11;
    // 0x80036B30: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
    // 0x80036B34: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
L_80036B38:
    // 0x80036B38: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80036B3C: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x80036B40: addu        $s1, $t9, $t1
    ctx->r17 = ADD32(ctx->r25, ctx->r9);
    // 0x80036B44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80036B48: bltz        $t0, L_80036B60
    if (SIGNED(ctx->r8) < 0) {
        // 0x80036B4C: sb          $t6, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r14;
            goto L_80036B60;
    }
    // 0x80036B4C: sb          $t6, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r14;
    // 0x80036B50: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x80036B54: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x80036B58: b           L_80036B7C
    // 0x80036B5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80036B7C;
    // 0x80036B5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80036B60:
    // 0x80036B60: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x80036B64: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x80036B68: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80036B6C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80036B70: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80036B74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80036B78: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
L_80036B7C:
    // 0x80036B7C: slti        $at, $t0, 0x64
    ctx->r1 = SIGNED(ctx->r8) < 0X64 ? 1 : 0;
    // 0x80036B80: bnel        $at, $zero, L_80036C2C
    if (ctx->r1 != 0) {
        // 0x80036B84: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80036C2C;
    }
    goto skip_9;
    // 0x80036B84: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_9:
    // 0x80036B88: slti        $at, $t0, 0x3E8
    ctx->r1 = SIGNED(ctx->r8) < 0X3E8 ? 1 : 0;
    // 0x80036B8C: bne         $at, $zero, L_80036BDC
    if (ctx->r1 != 0) {
        // 0x80036B90: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_80036BDC;
    }
    // 0x80036B90: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80036B94: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x80036B98: bne         $v0, $zero, L_80036BA4
    if (ctx->r2 != 0) {
        // 0x80036B9C: nop
    
            goto L_80036BA4;
    }
    // 0x80036B9C: nop

    // 0x80036BA0: break       7
    do_break(2147707808);
L_80036BA4:
    // 0x80036BA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80036BA8: bne         $v0, $at, L_80036BBC
    if (ctx->r2 != ctx->r1) {
        // 0x80036BAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80036BBC;
    }
    // 0x80036BAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80036BB0: bne         $t0, $at, L_80036BBC
    if (ctx->r8 != ctx->r1) {
        // 0x80036BB4: nop
    
            goto L_80036BBC;
    }
    // 0x80036BB4: nop

    // 0x80036BB8: break       6
    do_break(2147707832);
L_80036BBC:
    // 0x80036BBC: mfhi        $t0
    ctx->r8 = hi;
    // 0x80036BC0: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x80036BC4: mflo        $t4
    ctx->r12 = lo;
    // 0x80036BC8: addiu       $t5, $t4, 0x30
    ctx->r13 = ADD32(ctx->r12, 0X30);
    // 0x80036BCC: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036BD0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80036BD4: sb          $t5, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r13;
    // 0x80036BD8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80036BDC:
    // 0x80036BDC: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80036BE0: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x80036BE4: bne         $v0, $zero, L_80036BF0
    if (ctx->r2 != 0) {
        // 0x80036BE8: nop
    
            goto L_80036BF0;
    }
    // 0x80036BE8: nop

    // 0x80036BEC: break       7
    do_break(2147707884);
L_80036BF0:
    // 0x80036BF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80036BF4: bne         $v0, $at, L_80036C08
    if (ctx->r2 != ctx->r1) {
        // 0x80036BF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80036C08;
    }
    // 0x80036BF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80036BFC: bne         $t0, $at, L_80036C08
    if (ctx->r8 != ctx->r1) {
        // 0x80036C00: nop
    
            goto L_80036C08;
    }
    // 0x80036C00: nop

    // 0x80036C04: break       6
    do_break(2147707908);
L_80036C08:
    // 0x80036C08: mfhi        $t0
    ctx->r8 = hi;
    // 0x80036C0C: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x80036C10: mflo        $t6
    ctx->r14 = lo;
    // 0x80036C14: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x80036C18: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80036C1C: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80036C20: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x80036C24: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80036C28: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80036C2C:
    // 0x80036C2C: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x80036C30: bne         $v0, $zero, L_80036C3C
    if (ctx->r2 != 0) {
        // 0x80036C34: nop
    
            goto L_80036C3C;
    }
    // 0x80036C34: nop

    // 0x80036C38: break       7
    do_break(2147707960);
L_80036C3C:
    // 0x80036C3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80036C40: bne         $v0, $at, L_80036C54
    if (ctx->r2 != ctx->r1) {
        // 0x80036C44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80036C54;
    }
    // 0x80036C44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80036C48: bne         $t0, $at, L_80036C54
    if (ctx->r8 != ctx->r1) {
        // 0x80036C4C: nop
    
            goto L_80036C54;
    }
    // 0x80036C4C: nop

    // 0x80036C50: break       6
    do_break(2147707984);
L_80036C54:
    // 0x80036C54: mfhi        $t0
    ctx->r8 = hi;
    // 0x80036C58: sll         $t5, $t0, 16
    ctx->r13 = S32(ctx->r8 << 16);
    // 0x80036C5C: sra         $t9, $t5, 16
    ctx->r25 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80036C60: mflo        $t3
    ctx->r11 = lo;
    // 0x80036C64: addiu       $t4, $t3, 0x30
    ctx->r12 = ADD32(ctx->r11, 0X30);
    // 0x80036C68: addiu       $t1, $t9, 0x30
    ctx->r9 = ADD32(ctx->r25, 0X30);
    // 0x80036C6C: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
    // 0x80036C70: sb          $t1, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r9;
    // 0x80036C74: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80036C78: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036C7C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80036C80: subu        $t7, $s1, $t6
    ctx->r15 = SUB32(ctx->r17, ctx->r14);
    // 0x80036C84: subu        $t2, $t7, $t8
    ctx->r10 = SUB32(ctx->r15, ctx->r24);
    // 0x80036C88: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x80036C8C: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
L_80036C90:
    // 0x80036C90: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x80036C94: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80036C98: andi        $t4, $t3, 0x14
    ctx->r12 = ctx->r11 & 0X14;
    // 0x80036C9C: bnel        $t4, $at, L_80036CE0
    if (ctx->r12 != ctx->r1) {
        // 0x80036CA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80036CE0;
    }
    goto skip_10;
    // 0x80036CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80036CA4: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80036CA8: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80036CAC: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80036CB0: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    // 0x80036CB4: lw          $t3, 0x20($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X20);
    // 0x80036CB8: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x80036CBC: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x80036CC0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80036CC4: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x80036CC8: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80036CCC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80036CD0: beq         $at, $zero, L_80036CDC
    if (ctx->r1 == 0) {
        // 0x80036CD4: subu        $t4, $v1, $v0
        ctx->r12 = SUB32(ctx->r3, ctx->r2);
            goto L_80036CDC;
    }
    // 0x80036CD4: subu        $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x80036CD8: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
L_80036CDC:
    // 0x80036CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80036CE0:
    // 0x80036CE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80036CE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80036CE8: jr          $ra
    // 0x80036CEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80036CEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void static_16_800979D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800979D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800979DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800979E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800979E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800979E8: jal         0x800919F4
    // 0x800979EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    bakey_held(rdram, ctx);
        goto after_0;
    // 0x800979EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800979F0: beq         $v0, $zero, L_80097A2C
    if (ctx->r2 == 0) {
        // 0x800979F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80097A2C;
    }
    // 0x800979F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800979F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800979FC: jal         0x80098024
    // 0x80097A00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    bainput_isEnabled(rdram, ctx);
        goto after_1;
    // 0x80097A00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80097A04: bne         $v0, $zero, L_80097A18
    if (ctx->r2 != 0) {
        // 0x80097A08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80097A18;
    }
    // 0x80097A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097A0C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80097A10: jal         0x80097990
    // 0x80097A14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    static_16_80097990(rdram, ctx);
        goto after_2;
    // 0x80097A14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80097A18:
    // 0x80097A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097A1C: jal         0x80097978
    // 0x80097A20: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    static_16_80097978(rdram, ctx);
        goto after_3;
    // 0x80097A20: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80097A24: b           L_80097A40
    // 0x80097A28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80097A40;
    // 0x80097A28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80097A2C:
    // 0x80097A2C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80097A30: jal         0x80097990
    // 0x80097A34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    static_16_80097990(rdram, ctx);
        goto after_4;
    // 0x80097A34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80097A38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80097A40:
    // 0x80097A40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80097A44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80097A48: jr          $ra
    // 0x80097A4C: nop

    return;
    // 0x80097A4C: nop

;}
RECOMP_FUNC void static_16_800BCCC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCCC0: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800BCCC4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800BCCC8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800BCCCC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800BCCD0: jr          $ra
    // 0x800BCCD4: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    return;
    // 0x800BCCD4: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
;}
RECOMP_FUNC void static_16_800BCCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCCD8: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x800BCCDC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BCCE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800BCCE4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800BCCE8: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800BCCEC: jr          $ra
    // 0x800BCCF0: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    return;
    // 0x800BCCF0: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
;}
RECOMP_FUNC void static_16_80097990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097990: beql        $a2, $zero, L_800979B8
    if (ctx->r6 == 0) {
        // 0x80097994: lw          $v0, 0xA4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XA4);
            goto L_800979B8;
    }
    goto skip_0;
    // 0x80097994: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    skip_0:
    // 0x80097998: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
    // 0x8009799C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800979A0: sllv        $t8, $t7, $a1
    ctx->r24 = S32(ctx->r15 << (ctx->r5 & 31));
    // 0x800979A4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800979A8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800979AC: jr          $ra
    // 0x800979B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    return;
    // 0x800979B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800979B4: lw          $v0, 0xA4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA4);
L_800979B8:
    // 0x800979B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800979BC: sllv        $t2, $t1, $a1
    ctx->r10 = S32(ctx->r9 << (ctx->r5 & 31));
    // 0x800979C0: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800979C4: nor         $t3, $t2, $zero
    ctx->r11 = ~(ctx->r10 | 0);
    // 0x800979C8: and         $t4, $t0, $t3
    ctx->r12 = ctx->r8 & ctx->r11;
    // 0x800979CC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800979D0: jr          $ra
    // 0x800979D4: nop

    return;
    // 0x800979D4: nop

;}
RECOMP_FUNC void static_16_80097978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097978: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x8009797C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80097980: sllv        $t9, $t8, $a1
    ctx->r25 = S32(ctx->r24 << (ctx->r5 & 31));
    // 0x80097984: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80097988: jr          $ra
    // 0x8009798C: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    return;
    // 0x8009798C: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
;}
RECOMP_FUNC void static_304_80800324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void static_344_80800000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
