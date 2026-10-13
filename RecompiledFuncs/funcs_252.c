#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _badata_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846F8: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846F8);
    return;
    // 0x800846FC: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_80014A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80014A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014A90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80014A94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80014A98:
    // 0x80014A98: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014A9C: addiu       $a0, $a0, -0x7C30
    ctx->r4 = ADD32(ctx->r4, -0X7C30);
    // 0x80014AA0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80014AA4: jal         0x8002E1F0
    // 0x80014AA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80014AA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80014AAC: jal         0x80014A54
    // 0x80014AB0: nop

    func_80014A54(rdram, ctx);
        goto after_1;
    // 0x80014AB0: nop

    after_1:
    // 0x80014AB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80014AB8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80014ABC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80014AC0: bnel        $t6, $at, L_80014ADC
    if (ctx->r14 != ctx->r1) {
        // 0x80014AC4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80014ADC;
    }
    goto skip_0;
    // 0x80014AC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_0:
    // 0x80014AC8: jal         0x80014258
    // 0x80014ACC: nop

    func_80014258(rdram, ctx);
        goto after_2;
    // 0x80014ACC: nop

    after_2:
    // 0x80014AD0: b           L_80014A98
    // 0x80014AD4: nop

        goto L_80014A98;
    // 0x80014AD4: nop

    // 0x80014AD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80014ADC:
    // 0x80014ADC: bne         $t7, $at, L_80014AF4
    if (ctx->r15 != ctx->r1) {
        // 0x80014AE0: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_80014AF4;
    }
    // 0x80014AE0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80014AE4: jal         0x8001443C
    // 0x80014AE8: nop

    func_8001443C(rdram, ctx);
        goto after_3;
    // 0x80014AE8: nop

    after_3:
    // 0x80014AEC: b           L_80014A98
    // 0x80014AF0: nop

        goto L_80014A98;
    // 0x80014AF0: nop

L_80014AF4:
    // 0x80014AF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80014AF8: bne         $t8, $at, L_80014B10
    if (ctx->r24 != ctx->r1) {
        // 0x80014AFC: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80014B10;
    }
    // 0x80014AFC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80014B00: jal         0x800142F0
    // 0x80014B04: nop

    func_800142F0(rdram, ctx);
        goto after_4;
    // 0x80014B04: nop

    after_4:
    // 0x80014B08: b           L_80014A98
    // 0x80014B0C: nop

        goto L_80014A98;
    // 0x80014B0C: nop

L_80014B10:
    // 0x80014B10: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80014B14: bne         $t9, $at, L_80014B2C
    if (ctx->r25 != ctx->r1) {
        // 0x80014B18: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80014B2C;
    }
    // 0x80014B18: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80014B1C: jal         0x800146D8
    // 0x80014B20: nop

    func_800146D8(rdram, ctx);
        goto after_5;
    // 0x80014B20: nop

    after_5:
    // 0x80014B24: b           L_80014A98
    // 0x80014B28: nop

        goto L_80014A98;
    // 0x80014B28: nop

L_80014B2C:
    // 0x80014B2C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80014B30: bne         $t0, $at, L_80014B48
    if (ctx->r8 != ctx->r1) {
        // 0x80014B34: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_80014B48;
    }
    // 0x80014B34: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80014B38: jal         0x800148C4
    // 0x80014B3C: nop

    func_800148C4(rdram, ctx);
        goto after_6;
    // 0x80014B3C: nop

    after_6:
    // 0x80014B40: b           L_80014A98
    // 0x80014B44: nop

        goto L_80014A98;
    // 0x80014B44: nop

L_80014B48:
    // 0x80014B48: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80014B4C: bne         $t1, $at, L_80014B64
    if (ctx->r9 != ctx->r1) {
        // 0x80014B50: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_80014B64;
    }
    // 0x80014B50: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80014B54: jal         0x8001E5DC
    // 0x80014B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001E5DC(rdram, ctx);
        goto after_7;
    // 0x80014B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80014B5C: b           L_80014A98
    // 0x80014B60: nop

        goto L_80014A98;
    // 0x80014B60: nop

L_80014B64:
    // 0x80014B64: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80014B68: bne         $t2, $at, L_80014B80
    if (ctx->r10 != ctx->r1) {
        // 0x80014B6C: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_80014B80;
    }
    // 0x80014B6C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80014B70: jal         0x800149BC
    // 0x80014B74: nop

    func_800149BC(rdram, ctx);
        goto after_8;
    // 0x80014B74: nop

    after_8:
    // 0x80014B78: b           L_80014A98
    // 0x80014B7C: nop

        goto L_80014A98;
    // 0x80014B7C: nop

L_80014B80:
    // 0x80014B80: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80014B84: beq         $t3, $at, L_80014A98
    if (ctx->r11 == ctx->r1) {
        // 0x80014B88: nop
    
            goto L_80014A98;
    }
    // 0x80014B88: nop

    // 0x80014B8C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80014B90: bne         $t3, $at, L_80014BA8
    if (ctx->r11 != ctx->r1) {
        // 0x80014B94: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_80014BA8;
    }
    // 0x80014B94: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80014B98: jal         0x80016810
    // 0x80014B9C: nop

    func_80016810(rdram, ctx);
        goto after_9;
    // 0x80014B9C: nop

    after_9:
    // 0x80014BA0: b           L_80014A98
    // 0x80014BA4: nop

        goto L_80014A98;
    // 0x80014BA4: nop

L_80014BA8:
    // 0x80014BA8: sltiu       $at, $t5, 0x64
    ctx->r1 = ctx->r13 < 0X64 ? 1 : 0;
    // 0x80014BAC: bne         $at, $zero, L_80014A98
    if (ctx->r1 != 0) {
        // 0x80014BB0: nop
    
            goto L_80014A98;
    }
    // 0x80014BB0: nop

    // 0x80014BB4: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x80014BB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014BBC: bne         $v0, $zero, L_80014BD4
    if (ctx->r2 != 0) {
        // 0x80014BC0: nop
    
            goto L_80014BD4;
    }
    // 0x80014BC0: nop

    // 0x80014BC4: jal         0x80014128
    // 0x80014BC8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80014128(rdram, ctx);
        goto after_10;
    // 0x80014BC8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_10:
    // 0x80014BCC: b           L_80014A98
    // 0x80014BD0: nop

        goto L_80014A98;
    // 0x80014BD0: nop

L_80014BD4:
    // 0x80014BD4: bnel        $v0, $at, L_80014BF0
    if (ctx->r2 != ctx->r1) {
        // 0x80014BD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80014BF0;
    }
    goto skip_1;
    // 0x80014BD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x80014BDC: jal         0x80014148
    // 0x80014BE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80014148(rdram, ctx);
        goto after_11;
    // 0x80014BE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_11:
    // 0x80014BE4: b           L_80014A98
    // 0x80014BE8: nop

        goto L_80014A98;
    // 0x80014BE8: nop

    // 0x80014BEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80014BF0:
    // 0x80014BF0: bnel        $v0, $at, L_80014C0C
    if (ctx->r2 != ctx->r1) {
        // 0x80014BF4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80014C0C;
    }
    goto skip_2;
    // 0x80014BF4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_2:
    // 0x80014BF8: jal         0x800141D0
    // 0x80014BFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800141D0(rdram, ctx);
        goto after_12;
    // 0x80014BFC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_12:
    // 0x80014C00: b           L_80014A98
    // 0x80014C04: nop

        goto L_80014A98;
    // 0x80014C04: nop

    // 0x80014C08: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_80014C0C:
    // 0x80014C0C: bne         $v0, $at, L_80014A98
    if (ctx->r2 != ctx->r1) {
        // 0x80014C10: nop
    
            goto L_80014A98;
    }
    // 0x80014C10: nop

    // 0x80014C14: jal         0x800148B0
    // 0x80014C18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800148B0(rdram, ctx);
        goto after_13;
    // 0x80014C18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_13:
    // 0x80014C1C: b           L_80014A98
    // 0x80014C20: nop

        goto L_80014A98;
    // 0x80014C20: nop

    // 0x80014C24: nop

    // 0x80014C28: nop

    // 0x80014C2C: nop

    // 0x80014C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014C34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80014C38: jr          $ra
    // 0x80014C3C: nop

    return;
    // 0x80014C3C: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BE0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BE0);
    return;
    // 0x80082BE4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsbeemain_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B54: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B58: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X12A0) << 16);
    // 0x80800B5C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B60: jr          $ra
    // 0x80800B64: lw          $v0, 0x12A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12A0));
    return;
    // 0x80800B64: lw          $v0, 0x12A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12A0));
;}
RECOMP_FUNC void _chjinjo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B98: syscall     425
    recomp_syscall_handler(rdram, ctx, 0x80086B98);
    return;
    // 0x80086B9C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800000_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8008E23C
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E23C(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800014: beq         $t6, $zero, L_80800030
    if (ctx->r14 == 0) {
        // 0x80800018: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800030;
    }
    // 0x80800018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x80091A58
    // 0x80800024: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80800028: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080002C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80800030:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void ovl_clear_bss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082380: lhu         $t4, 0x6($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X6);
    // 0x80082384: beq         $t4, $zero, L_80082420
    if (ctx->r12 == 0) {
        // 0x80082388: nop
    
            goto L_80082420;
    }
    // 0x80082388: nop

    // 0x8008238C: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x80082390: addiu       $t1, $a1, 0x38
    ctx->r9 = ADD32(ctx->r5, 0X38);
    // 0x80082394: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80082398: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8008239C: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x800823A0: lbu         $t2, 0xE($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XE);
    // 0x800823A4: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x800823A8: lh          $t3, 0x2($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X2);
    // 0x800823AC: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x800823B0: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x800823B4: and         $t2, $t1, $a2
    ctx->r10 = ctx->r9 & ctx->r6;
    // 0x800823B8: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x800823BC: lh          $t2, 0xA($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XA);
    // 0x800823C0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800823C4: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x800823C8: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x800823CC: and         $t2, $t1, $a2
    ctx->r10 = ctx->r9 & ctx->r6;
    // 0x800823D0: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x800823D4: lh          $t2, 0xC($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XC);
    // 0x800823D8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800823DC: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x800823E0: addu        $t1, $t1, $a3
    ctx->r9 = ADD32(ctx->r9, ctx->r7);
    // 0x800823E4: and         $t2, $t1, $a3
    ctx->r10 = ctx->r9 & ctx->r7;
    // 0x800823E8: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x800823EC: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x800823F0: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x800823F4: lh          $t3, 0x4($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X4);
    // 0x800823F8: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x800823FC: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80082400: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
L_80082404:
    // 0x80082404: addi        $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80082408: sd          $zero, 0x0($t1)
    SD(0, 0X0, ctx->r9);
    // 0x8008240C: sd          $zero, 0x8($t1)
    SD(0, 0X8, ctx->r9);
    // 0x80082410: bne         $t4, $zero, L_80082404
    if (ctx->r12 != 0) {
        // 0x80082414: addiu       $t1, $t1, 0x10
        ctx->r9 = ADD32(ctx->r9, 0X10);
            goto L_80082404;
    }
    // 0x80082414: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80082418: jr          $ra
    // 0x8008241C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8008241C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80082420:
    // 0x80082420: jr          $ra
    // 0x80082424: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x80082424: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801F04_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F0C: jal         0x80100094
    // 0x80801F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801F10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801F14: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80801F18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801F1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801F20: bne         $t6, $zero, L_80801F44
    if (ctx->r14 != 0) {
        // 0x80801F24: addiu       $a1, $v0, 0x20
        ctx->r5 = ADD32(ctx->r2, 0X20);
            goto L_80801F44;
    }
    // 0x80801F24: addiu       $a1, $v0, 0x20
    ctx->r5 = ADD32(ctx->r2, 0X20);
    // 0x80801F28: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X23DC) << 16);
    // 0x80801F2C: addiu       $a2, $a2, 0x23DC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X23DC));
    // 0x80801F30: jal         0x800C4350
    // 0x80801F34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x80801F34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801F38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F3C: b           L_80801F74
    // 0x80801F40: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
        goto L_80801F74;
    // 0x80801F40: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
L_80801F44:
    // 0x80801F44: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80801F48: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x80801F4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80801F50: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801F54: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801F58: jal         0x800C3058
    // 0x80801F5C: nop

    func_800C3058(rdram, ctx);
        goto after_2;
    // 0x80801F5C: nop

    after_2:
    // 0x80801F60: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801F68: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x80801F6C: jal         0x800C4350
    // 0x80801F70: addiu       $a1, $v1, 0x20
    ctx->r5 = ADD32(ctx->r3, 0X20);
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x80801F70: addiu       $a1, $v1, 0x20
    ctx->r5 = ADD32(ctx->r3, 0X20);
    after_3:
L_80801F74:
    // 0x80801F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801F7C: jr          $ra
    // 0x80801F80: nop

    return;
    // 0x80801F80: nop

;}
RECOMP_FUNC void susubgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x80800010: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80800014: sh          $a2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r6;
    // 0x80800018: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x8080001C: sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // 0x80800020: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800024: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3294, 0X970) << 16);
    // 0x80800028: jal         0x80800940
    // 0x8080002C: addiu       $a1, $a1, 0x970
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3294, 0X970));
    susubgame_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a1, $a1, 0x970
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3294, 0X970));
    after_0:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_800A34A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A34A0: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A34A4: jr          $ra
    // 0x800A34A8: sb          $a1, 0x2A($t6)
    MEM_B(0X2A, ctx->r14) = ctx->r5;
    return;
    // 0x800A34A8: sb          $a1, 0x2A($t6)
    MEM_B(0X2A, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void babackpack_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004DC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x808004E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004E8: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x808004EC: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004F4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x808004F8: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x808004FC: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x80800500: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80800504: sb          $zero, 0x9($t9)
    MEM_B(0X9, ctx->r25) = 0;
    // 0x80800508: lw          $t0, 0x14($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14);
    // 0x8080050C: sb          $zero, 0xA($t0)
    MEM_B(0XA, ctx->r8) = 0;
    // 0x80800510: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x80800514: swc1        $f4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f4.u32l;
    // 0x80800518: lw          $t2, 0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14);
    // 0x8080051C: sw          $zero, 0x14($t2)
    MEM_W(0X14, ctx->r10) = 0;
    // 0x80800520: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80800524: jal         0x8080053C
    // 0x80800528: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    babackpack_set_state(rdram, ctx);
        goto after_0;
    // 0x80800528: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    after_0:
    // 0x8080052C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800534: jr          $ra
    // 0x80800538: nop

    return;
    // 0x80800538: nop

;}
RECOMP_FUNC void func_80020EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EAC: jr          $ra
    // 0x80020EB0: nop

    return;
    // 0x80020EB0: nop

;}
RECOMP_FUNC void bswalk_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808007B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808007B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007BC: jal         0x8080016C
    // 0x808007C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8080016C_bswalk(rdram, ctx);
        goto after_0;
    // 0x808007C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808007C4: jal         0x8009EF04
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_1;
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808007D0: nop

    // 0x808007D4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808007D8: nop

    // 0x808007DC: bc1fl       L_808007FC
    if (!c1cs) {
        // 0x808007E0: lui         $a1, 0x3ECC
        ctx->r5 = S32(0X3ECC << 16);
            goto L_808007FC;
    }
    goto skip_0;
    // 0x808007E0: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    skip_0:
    // 0x808007E4: jal         0x8009C984
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808007F0: jal         0x8009C914
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_3;
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007F8: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
L_808007FC:
    // 0x808007FC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: jal         0x800A2CE8
    // 0x80800808: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x80800808: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8080080C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800810: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800818: jal         0x800A2CE8
    // 0x8080081C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_5;
    // 0x8080081C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x80800820: jal         0x80800000
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bswalk(rdram, ctx);
        goto after_6;
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800828: jal         0x8009EF10
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_7;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800830: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800834: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800858;
    }
    // 0x80800834: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800838: beq         $v0, $at, L_80800874
    if (ctx->r2 == ctx->r1) {
        // 0x8080083C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800874;
    }
    // 0x8080083C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800840: beq         $v0, $at, L_8080087C
    if (ctx->r2 == ctx->r1) {
        // 0x80800844: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080087C;
    }
    // 0x80800844: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800848: beql        $v0, $at, L_80800888
    if (ctx->r2 == ctx->r1) {
        // 0x8080084C: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80800888;
    }
    goto skip_1;
    // 0x8080084C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    skip_1:
    // 0x80800850: b           L_80800888
    // 0x80800854: nop

        goto L_80800888;
    // 0x80800854: nop

L_80800858:
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: jal         0x8009BCD4
    // 0x80800860: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_8;
    // 0x80800860: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_8:
    // 0x80800864: beq         $v0, $zero, L_80800888
    if (ctx->r2 == 0) {
        // 0x80800868: nop
    
            goto L_80800888;
    }
    // 0x80800868: nop

    // 0x8080086C: b           L_80800888
    // 0x80800870: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80800888;
    // 0x80800870: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80800874:
    // 0x80800874: b           L_80800888
    // 0x80800878: addiu       $s1, $zero, 0x1F
    ctx->r17 = ADD32(0, 0X1F);
        goto L_80800888;
    // 0x80800878: addiu       $s1, $zero, 0x1F
    ctx->r17 = ADD32(0, 0X1F);
L_8080087C:
    // 0x8080087C: b           L_80800888
    // 0x80800880: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
        goto L_80800888;
    // 0x80800880: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80800884: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80800888:
    // 0x80800888: jal         0x8008DE24
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_9;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800890: beq         $v0, $zero, L_8080089C
    if (ctx->r2 == 0) {
        // 0x80800894: nop
    
            goto L_8080089C;
    }
    // 0x80800894: nop

    // 0x80800898: addiu       $s1, $zero, 0x7A
    ctx->r17 = ADD32(0, 0X7A);
L_8080089C:
    // 0x8080089C: jal         0x80097AD0
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_10;
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808008A4: beq         $v0, $zero, L_808008B8
    if (ctx->r2 == 0) {
        // 0x808008A8: nop
    
            goto L_808008B8;
    }
    // 0x808008A8: nop

    // 0x808008AC: jal         0x800848A8
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_11;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808008B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_808008B8:
    // 0x808008B8: jal         0x8008DD04
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_12;
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808008C0: beq         $v0, $zero, L_808008CC
    if (ctx->r2 == 0) {
        // 0x808008C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008CC;
    }
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C8: addiu       $s1, $zero, 0x2F
    ctx->r17 = ADD32(0, 0X2F);
L_808008CC:
    // 0x808008CC: jal         0x800919F4
    // 0x808008D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_13;
    // 0x808008D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808008D4: beq         $v0, $zero, L_808008E0
    if (ctx->r2 == 0) {
        // 0x808008D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008E0;
    }
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008DC: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
L_808008E0:
    // 0x808008E0: jal         0x80800248
    // 0x808008E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800248_bswalk(rdram, ctx);
        goto after_14;
    // 0x808008E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x808008E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: jal         0x80091A58
    // 0x808008F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_15;
    // 0x808008F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
    // 0x808008F8: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x808008FC: nop
    
            goto L_80800964;
    }
    // 0x808008FC: nop

    // 0x80800900: jal         0x8009FE84
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_16;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800908: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080090C: jal         0x8009BB00
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800914: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800918: nop

    // 0x8080091C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800920: nop

    // 0x80800924: bc1f        L_80800964
    if (!c1cs) {
        // 0x80800928: nop
    
            goto L_80800964;
    }
    // 0x80800928: nop

    // 0x8080092C: jal         0x8008D714
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D714(rdram, ctx);
        goto after_18;
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800934: beq         $v0, $zero, L_80800944
    if (ctx->r2 == 0) {
        // 0x80800938: nop
    
            goto L_80800944;
    }
    // 0x80800938: nop

    // 0x8080093C: b           L_80800964
    // 0x80800940: addiu       $s1, $zero, 0xB8
    ctx->r17 = ADD32(0, 0XB8);
        goto L_80800964;
    // 0x80800940: addiu       $s1, $zero, 0xB8
    ctx->r17 = ADD32(0, 0XB8);
L_80800944:
    // 0x80800944: jal         0x8008D790
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_19;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080094C: beq         $v0, $zero, L_80800964
    if (ctx->r2 == 0) {
        // 0x80800950: nop
    
            goto L_80800964;
    }
    // 0x80800950: nop

    // 0x80800954: jal         0x80084978
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_20;
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080095C: b           L_808009AC
    // 0x80800960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009AC;
    // 0x80800960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800964:
    // 0x80800964: jal         0x8008E148
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_21;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080096C: beq         $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800970: nop
    
            goto L_80800980;
    }
    // 0x80800970: nop

    // 0x80800974: jal         0x800848B0
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_22;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080097C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800980:
    // 0x80800980: jal         0x8008E35C
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_23;
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800988: beq         $v0, $zero, L_80800994
    if (ctx->r2 == 0) {
        // 0x8080098C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800994;
    }
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800990: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_80800994:
    // 0x80800994: jal         0x800A02DC
    // 0x80800998: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_24;
    // 0x80800998: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_24:
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A0: jal         0x8009E5C8
    // 0x808009A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_25;
    // 0x808009A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_25:
    // 0x808009A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009AC:
    // 0x808009AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808009B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808009B4: jr          $ra
    // 0x808009B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808009B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800A3820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3824: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A3828: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A382C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3830: jal         0x800EFD24
    // 0x800A3834: lw          $a0, 0xA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA0);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800A3834: lw          $a0, 0xA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA0);
    after_0:
    // 0x800A3838: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    // 0x800A383C: jal         0x800EFD24
    // 0x800A3840: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x800A3840: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x800A3844: lw          $a1, 0xA0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A384C: jal         0x8009C128
    // 0x800A3850: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x800A3850: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_2:
    // 0x800A3854: lw          $t6, 0xA0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3858: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A385C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3860: sb          $zero, 0x3D($t6)
    MEM_B(0X3D, ctx->r14) = 0;
    // 0x800A3864: lw          $t7, 0xA0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3868: jal         0x800A380C
    // 0x800A386C: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    func_800A380C(rdram, ctx);
        goto after_3;
    // 0x800A386C: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    after_3:
    // 0x800A3870: lw          $t9, 0xA0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3874: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A3878: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A387C: sb          $t8, 0x3C($t9)
    MEM_B(0X3C, ctx->r25) = ctx->r24;
    // 0x800A3880: lw          $t0, 0xA0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3888: swc1        $f6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
    // 0x800A388C: lw          $t1, 0xA0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3890: jal         0x8009C150
    // 0x800A3894: sb          $zero, 0x50($t1)
    MEM_B(0X50, ctx->r9) = 0;
    func_8009C150(rdram, ctx);
        goto after_4;
    // 0x800A3894: sb          $zero, 0x50($t1)
    MEM_B(0X50, ctx->r9) = 0;
    after_4:
    // 0x800A3898: lw          $t2, 0xA0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XA0);
    // 0x800A389C: swc1        $f0, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f0.u32l;
    // 0x800A38A0: lw          $t3, 0xA0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XA0);
    // 0x800A38A4: swc1        $f0, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->f0.u32l;
    // 0x800A38A8: lw          $t4, 0xA0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XA0);
    // 0x800A38AC: jal         0x8009E958
    // 0x800A38B0: sb          $zero, 0x29($t4)
    MEM_B(0X29, ctx->r12) = 0;
    func_8009E958(rdram, ctx);
        goto after_5;
    // 0x800A38B0: sb          $zero, 0x29($t4)
    MEM_B(0X29, ctx->r12) = 0;
    after_5:
    // 0x800A38B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A38B8: jal         0x800A3410
    // 0x800A38BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A3410(rdram, ctx);
        goto after_6;
    // 0x800A38BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x800A38C0: lw          $t5, 0xA0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XA0);
    // 0x800A38C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A38C8: sb          $v0, 0x54($t5)
    MEM_B(0X54, ctx->r13) = ctx->r2;
    // 0x800A38CC: lw          $t6, 0xA0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XA0);
    // 0x800A38D0: sb          $v0, 0x55($t6)
    MEM_B(0X55, ctx->r14) = ctx->r2;
    // 0x800A38D4: lw          $t7, 0xA0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XA0);
    // 0x800A38D8: sb          $v0, 0x3E($t7)
    MEM_B(0X3E, ctx->r15) = ctx->r2;
    // 0x800A38DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A38E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A38E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A38E8: jr          $ra
    // 0x800A38EC: nop

    return;
    // 0x800A38EC: nop

;}
RECOMP_FUNC void bsbfly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801164: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801168: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1D68) << 16);
    // 0x8080116C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801170: jr          $ra
    // 0x80801174: lw          $v0, 0x1D68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D68));
    return;
    // 0x80801174: lw          $v0, 0x1D68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D68));
;}
RECOMP_FUNC void chfriesstand_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(940, 0XEC8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xEC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XEC8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xEC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XEC8));
;}
RECOMP_FUNC void _ncpoducam_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089688: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089688);
    return;
    // 0x8008968C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _chdoormake_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086890: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x80086890);
    return;
    // 0x80086894: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void badeathmatch_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: beql        $a2, $zero, L_80800510
    if (ctx->r6 == 0) {
        // 0x808004F4: lw          $v0, 0x158($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X158);
            goto L_80800510;
    }
    goto skip_0;
    // 0x808004F4: lw          $v0, 0x158($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X158);
    skip_0:
    // 0x808004F8: lw          $v0, 0x158($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X158);
    // 0x808004FC: lbu         $t6, 0x23($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X23);
    // 0x80800500: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80800504: jr          $ra
    // 0x80800508: sb          $t7, 0x23($v0)
    MEM_B(0X23, ctx->r2) = ctx->r15;
    return;
    // 0x80800508: sb          $t7, 0x23($v0)
    MEM_B(0X23, ctx->r2) = ctx->r15;
    // 0x8080050C: lw          $v0, 0x158($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X158);
L_80800510:
    // 0x80800510: nor         $t9, $a1, $zero
    ctx->r25 = ~(ctx->r5 | 0);
    // 0x80800514: lbu         $t8, 0x23($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X23);
    // 0x80800518: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8080051C: sb          $t0, 0x23($v0)
    MEM_B(0X23, ctx->r2) = ctx->r8;
    // 0x80800520: jr          $ra
    // 0x80800524: nop

    return;
    // 0x80800524: nop

    // 0x80800528: nop

    // 0x8080052C: nop

;}
RECOMP_FUNC void func_80800270_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800274: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80800278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080027C: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800288: beq         $at, $zero, L_80800420
    if (ctx->r1 == 0) {
        // 0x8080028C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800420;
    }
    // 0x8080028C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800290: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2360, 0XF84) << 16);
    // 0x80800298: addu        $at, $at, $t7
    gpr jr_addend_808002A0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080029C: lw          $t7, 0xF84($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2360, 0XF84));
    // 0x808002A0: jr          $t7
    // 0x808002A4: nop

    switch (jr_addend_808002A0 >> 2) {
        case 0: goto L_808002A8; break;
        case 1: goto L_808002D8; break;
        case 2: goto L_808002F0; break;
        case 3: goto L_80800320; break;
        case 4: goto L_80800420; break;
        case 5: goto L_80800420; break;
        case 6: goto L_80800420; break;
        case 7: goto L_80800348; break;
        case 8: goto L_80800420; break;
        case 9: goto L_80800420; break;
        case 10: goto L_80800420; break;
        case 11: goto L_80800384; break;
        case 12: goto L_808003AC; break;
        default: switch_error(__func__, 0x808002A0, 0x80800F84);
    }
    // 0x808002A4: nop

L_808002A8:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80103110
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002B4: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x808002B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808002BC: andi        $t0, $t8, 0xFFEF
    ctx->r8 = ctx->r24 & 0XFFEF;
    // 0x808002C0: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x808002C4: andi        $t1, $t0, 0xFE
    ctx->r9 = ctx->r8 & 0XFE;
    // 0x808002C8: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808002CC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808002D0: b           L_80800420
    // 0x808002D4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_80800420;
    // 0x808002D4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_808002D8:
    // 0x808002D8: jal         0x80800440
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800440_chrainbow(rdram, ctx);
        goto after_1;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002E0: jal         0x800DA524
    // 0x808002E4: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x808002E4: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_2:
    // 0x808002E8: b           L_80800424
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800424;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002F0:
    // 0x808002F0: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
    // 0x808002F4: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    // 0x808002F8: jal         0x80101180
    // 0x808002FC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x808002FC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_3:
    // 0x80800300: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800304: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80800308: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x8080030C: jal         0x80085708
    // 0x80800310: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800310: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x80800314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800318: b           L_80800420
    // 0x8080031C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800420;
    // 0x8080031C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800320:
    // 0x80800320: jal         0x800B7C54
    // 0x80800324: nop

    func_800B7C54(rdram, ctx);
        goto after_5;
    // 0x80800324: nop

    after_5:
    // 0x80800328: jal         0x80088918
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _fxrain_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800330: jal         0x80086AF0
    // 0x80800334: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80800334: nop

    after_7:
    // 0x80800338: jal         0x800DA544
    // 0x8080033C: addiu       $a0, $zero, 0x580
    ctx->r4 = ADD32(0, 0X580);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x8080033C: addiu       $a0, $zero, 0x580
    ctx->r4 = ADD32(0, 0X580);
    after_8:
    // 0x80800340: b           L_80800424
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800424;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800348:
    // 0x80800348: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x8080034C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800354: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800358: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8080035C: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x80800360: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800364: addiu       $a3, $zero, 0x4810
    ctx->r7 = ADD32(0, 0X4810);
    // 0x80800368: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8080036C: jal         0x80085708
    // 0x80800370: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800370: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_9:
    // 0x80800374: jal         0x8008A490
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080037C: b           L_80800424
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800424;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800384:
    // 0x80800384: lui         $at, 0x4194
    ctx->r1 = S32(0X4194 << 16);
    // 0x80800388: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080038C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800390: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x80800394: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    // 0x80800398: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x8080039C: jal         0x80085708
    // 0x808003A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x808003A0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_11:
    // 0x808003A4: b           L_80800424
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800424;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003AC:
    // 0x808003AC: jal         0x800B7C54
    // 0x808003B0: nop

    func_800B7C54(rdram, ctx);
        goto after_12;
    // 0x808003B0: nop

    after_12:
    // 0x808003B4: jal         0x80088920
    // 0x808003B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _fxrain_entrypoint_8(rdram, ctx);
        goto after_13;
    // 0x808003B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x808003BC: jal         0x800DA524
    // 0x808003C0: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_14;
    // 0x808003C0: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_14:
    // 0x808003C4: jal         0x800DA544
    // 0x808003C8: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x808003C8: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_15:
    // 0x808003CC: jal         0x800DA544
    // 0x808003D0: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    func_800DA544(rdram, ctx);
        goto after_16;
    // 0x808003D0: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    after_16:
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003DC: jal         0x80100074
    // 0x808003E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_17;
    // 0x808003E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x808003E4: jal         0x8008A490
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808003EC: jal         0x8010A63C
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_19;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808003F4: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x808003F8: lui         $at, 0x41A4
    ctx->r1 = S32(0X41A4 << 16);
    // 0x808003FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800404: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x80800408: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800414: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800418: jal         0x80103110
    // 0x8080041C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80103110(rdram, ctx);
        goto after_20;
    // 0x8080041C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_20:
L_80800420:
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800424:
    // 0x80800424: jal         0x80101FDC
    // 0x80800428: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101FDC(rdram, ctx);
        goto after_21;
    // 0x80800428: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800430: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void func_80800710_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80800714: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800718: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8080071C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80800720: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80800724: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80800728: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8080072C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80800730: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800734: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800738: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080073C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80800740: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80800744: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80800748: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x8080074C: sw          $a2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r6;
    // 0x80800750: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x80800754: jal         0x808006D4
    // 0x80800758: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    func_808006D4_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x80800758: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    after_0:
    // 0x8080075C: beql        $v0, $zero, L_808008CC
    if (ctx->r2 == 0) {
        // 0x80800760: addiu       $s1, $sp, 0xB0
        ctx->r17 = ADD32(ctx->r29, 0XB0);
            goto L_808008CC;
    }
    goto skip_0;
    // 0x80800760: addiu       $s1, $sp, 0xB0
    ctx->r17 = ADD32(ctx->r29, 0XB0);
    skip_0:
    // 0x80800764: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x80800768: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080076C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800770: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800774: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800778: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080077C: addiu       $fp, $sp, 0xBC
    ctx->r30 = ADD32(ctx->r29, 0XBC);
    // 0x80800780: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800784: addiu       $s3, $v0, 0x40
    ctx->r19 = ADD32(ctx->r2, 0X40);
    // 0x80800788: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080078C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800790: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800794: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x80800798: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080079C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x808007A0: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x808007A4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808007A8: swc1        $f2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f2.u32l;
    // 0x808007AC: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x808007B0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808007B4: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    // 0x808007B8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808007BC: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
    // 0x808007C0: lwc1        $f18, 0xC4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x808007C4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x808007C8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808007CC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808007D0: jal         0x800EF5A0
    // 0x808007D4: swc1        $f16, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_1;
    // 0x808007D4: swc1        $f16, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x808007D8: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x808007DC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808007E0: jal         0x800EF04C
    // 0x808007E4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x808007E4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_2:
    // 0x808007E8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x808007EC: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    // 0x808007F0: addiu       $s7, $sp, 0xA0
    ctx->r23 = ADD32(ctx->r29, 0XA0);
    // 0x808007F4: lw          $s6, 0xE0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XE0);
    // 0x808007F8: lw          $s5, 0xDC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XDC);
    // 0x808007FC: lw          $s4, 0xD8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD8);
    // 0x80800800: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80800804: addiu       $s1, $sp, 0xB0
    ctx->r17 = ADD32(ctx->r29, 0XB0);
L_80800808:
    // 0x80800808: lw          $v1, 0xAC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XAC);
    // 0x8080080C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800810: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x80800814: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80800818: nop

    // 0x8080081C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
L_80800820:
    // 0x80800820: lw          $v0, 0xA8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA8);
    // 0x80800824: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80800828: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8080082C: nop

    // 0x80800830: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800834: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
L_80800838:
    // 0x80800838: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8080083C: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80800840: mul.s       $f8, $f10, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80800844: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80800848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080084C: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800850: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800854: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800858: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080085C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800860: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80800864: jal         0x800EF5A0
    // 0x80800868: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_3;
    // 0x80800868: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8080086C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800870: jal         0x800EF04C
    // 0x80800874: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80800874: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_4:
    // 0x80800878: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080087C: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x80800880: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    // 0x80800884: lw          $a3, 0xD4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD4);
    // 0x80800888: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8080088C: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80800890: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80800894: jal         0x80800584
    // 0x80800898: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    func_80800584_ncpoddialog(rdram, ctx);
        goto after_5;
    // 0x80800898: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    after_5:
    // 0x8080089C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808008A0: bnel        $s0, $s2, L_80800838
    if (ctx->r16 != ctx->r18) {
        // 0x808008A4: lwc1        $f10, 0x94($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
            goto L_80800838;
    }
    goto skip_1;
    // 0x808008A4: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    skip_1:
    // 0x808008A8: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x808008AC: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x808008B0: bne         $t7, $s2, L_80800820
    if (ctx->r15 != ctx->r18) {
        // 0x808008B4: sw          $t7, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r15;
            goto L_80800820;
    }
    // 0x808008B4: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x808008B8: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x808008BC: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x808008C0: bne         $t9, $s2, L_80800808
    if (ctx->r25 != ctx->r18) {
        // 0x808008C4: sw          $t9, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r25;
            goto L_80800808;
    }
    // 0x808008C4: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x808008C8: addiu       $s1, $sp, 0xB0
    ctx->r17 = ADD32(ctx->r29, 0XB0);
L_808008CC:
    // 0x808008CC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x808008D0: lw          $s4, 0xD8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD8);
    // 0x808008D4: lw          $s5, 0xDC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XDC);
    // 0x808008D8: lw          $s6, 0xE0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XE0);
    // 0x808008DC: addiu       $s7, $sp, 0xA0
    ctx->r23 = ADD32(ctx->r29, 0XA0);
    // 0x808008E0: addiu       $fp, $sp, 0xBC
    ctx->r30 = ADD32(ctx->r29, 0XBC);
    // 0x808008E4: jal         0x80800698
    // 0x808008E8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    func_80800698_ncpoddialog(rdram, ctx);
        goto after_6;
    // 0x808008E8: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_6:
    // 0x808008EC: beql        $v0, $zero, L_80800A64
    if (ctx->r2 == 0) {
        // 0x808008F0: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80800A64;
    }
    goto skip_2;
    // 0x808008F0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x808008F4: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x808008F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808008FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800900: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800904: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800908: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080090C: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
    // 0x80800910: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800914: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800918: addiu       $a1, $v0, 0x4C
    ctx->r5 = ADD32(ctx->r2, 0X4C);
    // 0x8080091C: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800920: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80800924: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80800928: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8080092C: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x80800930: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800934: swc1        $f2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f2.u32l;
    // 0x80800938: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8080093C: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x80800940: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80800944: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
    // 0x80800948: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080094C: jal         0x800EE7F8
    // 0x80800950: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800950: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80800954: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800958: lwc1        $f16, 0xC4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8080095C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800960: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800964: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    // 0x80800968: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x8080096C: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x80800970: jal         0x800EF5A0
    // 0x80800974: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_8;
    // 0x80800974: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x80800978: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x8080097C: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: jal         0x800EE7F8
    // 0x80800988: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800988: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    after_9:
    // 0x8080098C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800990: jal         0x800EF04C
    // 0x80800994: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x80800994: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x80800998: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080099C: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
L_808009A0:
    // 0x808009A0: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x808009A4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808009A8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x808009AC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x808009B0: nop

    // 0x808009B4: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
L_808009B8:
    // 0x808009B8: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x808009BC: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x808009C0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x808009C4: nop

    // 0x808009C8: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808009CC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
L_808009D0:
    // 0x808009D0: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x808009D4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808009D8: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x808009DC: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808009E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009E4: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x808009E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808009EC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808009F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808009F4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x808009F8: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x808009FC: jal         0x800EF5A0
    // 0x80800A00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_11;
    // 0x80800A00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80800A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A08: jal         0x800EF04C
    // 0x80800A0C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80800A0C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_12:
    // 0x80800A10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A14: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x80800A18: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    // 0x80800A1C: lw          $a3, 0xD4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD4);
    // 0x80800A20: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800A24: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80800A28: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80800A2C: jal         0x80800584
    // 0x80800A30: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    func_80800584_ncpoddialog(rdram, ctx);
        goto after_13;
    // 0x80800A30: sw          $s6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r22;
    after_13:
    // 0x80800A34: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800A38: bnel        $s0, $s2, L_808009D0
    if (ctx->r16 != ctx->r18) {
        // 0x80800A3C: lwc1        $f6, 0x70($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
            goto L_808009D0;
    }
    goto skip_3;
    // 0x80800A3C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    skip_3:
    // 0x80800A40: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80800A44: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x80800A48: bne         $t5, $s2, L_808009B8
    if (ctx->r13 != ctx->r18) {
        // 0x80800A4C: sw          $t5, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r13;
            goto L_808009B8;
    }
    // 0x80800A4C: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x80800A50: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x80800A54: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80800A58: bne         $t7, $s2, L_808009A0
    if (ctx->r15 != ctx->r18) {
        // 0x80800A5C: sw          $t7, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r15;
            goto L_808009A0;
    }
    // 0x80800A5C: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x80800A60: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80800A64:
    // 0x80800A64: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80800A68: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80800A6C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800A70: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A74: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800A78: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800A7C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800A80: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800A84: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80800A88: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80800A8C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80800A90: jr          $ra
    // 0x80800A94: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80800A94: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_808001E8_chstarspinnerplanet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001F4: jal         0x800DA298
    // 0x808001F8: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001F8: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    after_0:
    // 0x808001FC: bne         $v0, $zero, L_80800214
    if (ctx->r2 != 0) {
        // 0x80800200: nop
    
            goto L_80800214;
    }
    // 0x80800200: nop

    // 0x80800204: jal         0x80088848
    // 0x80800208: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800208: nop

    after_1:
    // 0x8080020C: beq         $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x80800210: nop
    
            goto L_8080021C;
    }
    // 0x80800210: nop

L_80800214:
    // 0x80800214: jal         0x800DA544
    // 0x80800218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_8080021C:
    // 0x8080021C: jal         0x800EA05C
    // 0x80800220: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80800220: nop

    after_3:
    // 0x80800224: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x80800228: beql        $v0, $at, L_8080023C
    if (ctx->r2 == ctx->r1) {
        // 0x8080022C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080023C;
    }
    goto skip_0;
    // 0x8080022C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800230: jal         0x8010A624
    // 0x80800234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A624(rdram, ctx);
        goto after_4;
    // 0x80800234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800238: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080023C:
    // 0x8080023C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80800240: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80800244: jal         0x80089CF0
    // 0x80800248: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80800248: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_5:
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

    // 0x8080025C: nop

;}
RECOMP_FUNC void func_80801208_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080120C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801210: jal         0x808011A8
    // 0x80801214: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808011A8_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x80801214: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801218: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080121C: sb          $zero, 0x15E($t6)
    MEM_B(0X15E, ctx->r14) = 0;
    // 0x80801220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801228: jr          $ra
    // 0x8080122C: nop

    return;
    // 0x8080122C: nop

;}
RECOMP_FUNC void func_808000E0_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000EC: jal         0x8009B7C0
    // 0x808000F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_0;
    // 0x808000F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000F4: jal         0x8080009C
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_bsdronegoto(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000FC: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800100: beq         $v1, $zero, L_80800114
    if (ctx->r3 == 0) {
        // 0x80800104: nop
    
            goto L_80800114;
    }
    // 0x80800104: nop

    // 0x80800108: jal         0x8008E35C
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_2;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800110: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80800114:
    // 0x80800114: bnel        $v1, $zero, L_8080012C
    if (ctx->r3 != 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080012C;
    }
    goto skip_0;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080011C: jal         0x8008E078
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800124: beq         $v0, $zero, L_80800134
    if (ctx->r2 == 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800134;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080012C:
    // 0x8080012C: jal         0x80800000
    // 0x80800130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bsdronegoto(rdram, ctx);
        goto after_4;
    // 0x80800130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_80800134:
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void _bawasher_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085408: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085408);
    return;
    // 0x8008540C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chjiggypost_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B90: syscall     203
    recomp_syscall_handler(rdram, ctx, 0x80085B90);
    return;
    // 0x80085B94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801174_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801178: addiu       $at, $zero, 0x1348
    ctx->r1 = ADD32(0, 0X1348);
    // 0x8080117C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801180: bne         $a1, $at, L_8080119C
    if (ctx->r5 != ctx->r1) {
        // 0x80801184: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080119C;
    }
    // 0x80801184: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801188: jal         0x80100094
    // 0x8080118C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080118C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801190: lw          $v0, 0xA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XA0);
    // 0x80801194: b           L_808011A0
    // 0x80801198: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_808011A0;
    // 0x80801198: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8080119C:
    // 0x8080119C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011A0:
    // 0x808011A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011A8: jr          $ra
    // 0x808011AC: nop

    return;
    // 0x808011AC: nop

;}
RECOMP_FUNC void _suegg_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A408: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A408);
    return;
    // 0x8008A40C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void chinflatablebossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1420, 0X140) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1420, 0X140));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1420, 0X140));
;}
RECOMP_FUNC void _cadbfunc_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085640: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085640);
    return;
    // 0x80085644: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_80090298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800902A0: jal         0x8008FF18
    // 0x800902A4: nop

    func_8008FF18(rdram, ctx);
        goto after_0;
    // 0x800902A4: nop

    after_0:
    // 0x800902A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800902AC: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800902B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800902B4: jr          $ra
    // 0x800902B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800902B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800B9990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B9994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B9998: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B999C: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800B99A0: addiu       $t8, $t8, -0x5920
    ctx->r24 = ADD32(ctx->r24, -0X5920);
    // 0x800B99A4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B99A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B99AC: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800B99B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B99B4: jal         0x800D2CC4
    // 0x800B99B8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    func_800D2CC4(rdram, ctx);
        goto after_0;
    // 0x800B99B8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    after_0:
    // 0x800B99BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B99C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B99C4: jr          $ra
    // 0x800B99C8: nop

    return;
    // 0x800B99C8: nop

;}
RECOMP_FUNC void _sucoasterfly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089ED0: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089ED0);
    return;
    // 0x80089ED4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800024_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800034: jal         0x80100094
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080003C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800040: jal         0x800D1824
    // 0x80800044: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1824(rdram, ctx);
        goto after_1;
    // 0x80800044: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_1:
    // 0x80800048: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080004C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800050: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1012, 0X10B8) << 16);
    // 0x80800054: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800058: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080005C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800064: addiu       $a0, $a0, 0x10B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1012, 0X10B8));
    // 0x80800068: jal         0x80089F20
    // 0x8080006C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080006C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x80800070: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800074: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80800078: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080007C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800080: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800084: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800088: jal         0x80089F20
    // 0x8080008C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080008C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_3:
    // 0x80800090: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800094: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800098: jal         0x800897D8
    // 0x8080009C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x8080009C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808000A0: jal         0x801022E4
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_5;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000A8: addiu       $at, $zero, 0x115
    ctx->r1 = ADD32(0, 0X115);
    // 0x808000AC: bne         $v0, $at, L_808000D0
    if (ctx->r2 != ctx->r1) {
        // 0x808000B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x808000B8: lui         $a2, 0x3F7D
    ctx->r6 = S32(0X3F7D << 16);
    // 0x808000BC: ori         $a2, $a2, 0x70A4
    ctx->r6 = ctx->r6 | 0X70A4;
    // 0x808000C0: jal         0x80102320
    // 0x808000C4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80102320(rdram, ctx);
        goto after_6;
    // 0x808000C4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_6:
    // 0x808000C8: bnel        $v0, $zero, L_808000E0
    if (ctx->r2 != 0) {
        // 0x808000CC: lhu         $t8, 0x72($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X72);
            goto L_808000E0;
    }
    goto skip_0;
    // 0x808000CC: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    skip_0:
L_808000D0:
    // 0x808000D0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808000D4: jal         0x80089818
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_7;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808000DC: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
L_808000E0:
    // 0x808000E0: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808000E4: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x808000E8: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x808000EC: beq         $at, $zero, L_80800304
    if (ctx->r1 == 0) {
        // 0x808000F0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800304;
    }
    // 0x808000F0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1012, 0XEB0) << 16);
    // 0x808000F8: addu        $at, $at, $t0
    gpr jr_addend_80800100 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808000FC: lw          $t0, 0xEB0($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1012, 0XEB0));
    // 0x80800100: jr          $t0
    // 0x80800104: nop

    switch (jr_addend_80800100 >> 2) {
        case 0: goto L_80800108; break;
        case 1: goto L_80800260; break;
        case 2: goto L_80800220; break;
        case 3: goto L_80800198; break;
        case 4: goto L_80800150; break;
        case 5: goto L_808002C4; break;
        case 6: goto L_808001DC; break;
        default: switch_error(__func__, 0x80800100, 0x80800EB0);
    }
    // 0x80800104: nop

L_80800108:
    // 0x80800108: jal         0x80800694
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800694_chpawnbroker(rdram, ctx);
        goto after_8;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800110: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1012, 0X10A8) << 16);
    // 0x80800114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0XED0) << 16);
    // 0x80800118: addiu       $t1, $zero, 0x6A5
    ctx->r9 = ADD32(0, 0X6A5);
    // 0x8080011C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800120: addiu       $a2, $a2, 0xED0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0XED0));
    // 0x80800124: addiu       $a1, $a1, 0x10A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1012, 0X10A8));
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x808007BC
    // 0x80800130: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_808007BC_chpawnbroker(rdram, ctx);
        goto after_9;
    // 0x80800130: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_9:
    // 0x80800134: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800140: jal         0x80800AE4
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800AE4_chpawnbroker(rdram, ctx);
        goto after_10;
    // 0x80800144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80800148: b           L_80800310
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800310;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: jal         0x80800694
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800694_chpawnbroker(rdram, ctx);
        goto after_11;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800158: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1012, 0X10A8) << 16);
    // 0x8080015C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0XF08) << 16);
    // 0x80800160: addiu       $t2, $zero, 0x6A6
    ctx->r10 = ADD32(0, 0X6A6);
    // 0x80800164: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800168: addiu       $a2, $a2, 0xF08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0XF08));
    // 0x8080016C: addiu       $a1, $a1, 0x10A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1012, 0X10A8));
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x808007BC
    // 0x80800178: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_808007BC_chpawnbroker(rdram, ctx);
        goto after_12;
    // 0x80800178: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_12:
    // 0x8080017C: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800188: jal         0x80800AE4
    // 0x8080018C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800AE4_chpawnbroker(rdram, ctx);
        goto after_13;
    // 0x8080018C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800190: b           L_80800310
    // 0x80800194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800310;
    // 0x80800194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800198:
    // 0x80800198: jal         0x80800694
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800694_chpawnbroker(rdram, ctx);
        goto after_14;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001A0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1012, 0X10A8) << 16);
    // 0x808001A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0XF40) << 16);
    // 0x808001A8: addiu       $a2, $a2, 0xF40
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0XF40));
    // 0x808001AC: addiu       $a1, $a1, 0x10A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1012, 0X10A8));
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808001B8: jal         0x808007BC
    // 0x808001BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_808007BC_chpawnbroker(rdram, ctx);
        goto after_15;
    // 0x808001BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x808001C0: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001CC: jal         0x80800AE4
    // 0x808001D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800AE4_chpawnbroker(rdram, ctx);
        goto after_16;
    // 0x808001D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x808001D4: b           L_80800310
    // 0x808001D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800310;
    // 0x808001D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001DC:
    // 0x808001DC: jal         0x80800694
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800694_chpawnbroker(rdram, ctx);
        goto after_17;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1012, 0X10A8) << 16);
    // 0x808001E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0XF40) << 16);
    // 0x808001EC: addiu       $a2, $a2, 0xF40
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0XF40));
    // 0x808001F0: addiu       $a1, $a1, 0x10A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1012, 0X10A8));
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808001FC: jal         0x808007BC
    // 0x80800200: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_808007BC_chpawnbroker(rdram, ctx);
        goto after_18;
    // 0x80800200: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x80800204: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800208: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800210: jal         0x80800AE4
    // 0x80800214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800AE4_chpawnbroker(rdram, ctx);
        goto after_19;
    // 0x80800214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x80800218: b           L_80800310
    // 0x8080021C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800310;
    // 0x8080021C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800220:
    // 0x80800220: jal         0x80800664
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800664_chpawnbroker(rdram, ctx);
        goto after_20;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800228: jal         0x80101DDC
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_21;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800230: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800234: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: jal         0x80102424
    // 0x8080023C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x8080023C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_22:
    // 0x80800240: addiu       $a0, $zero, 0x353
    ctx->r4 = ADD32(0, 0X353);
    // 0x80800244: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800248: jal         0x80101180
    // 0x8080024C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_23;
    // 0x8080024C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80800250: jal         0x800DA544
    // 0x80800254: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_800DA544(rdram, ctx);
        goto after_24;
    // 0x80800254: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_24:
    // 0x80800258: b           L_80800310
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800310;
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800260:
    // 0x80800260: jal         0x80800694
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800694_chpawnbroker(rdram, ctx);
        goto after_25;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x80103DFC
    // 0x80800270: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80103DFC(rdram, ctx);
        goto after_26;
    // 0x80800270: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_26:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x80100094
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_27;
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800288: jal         0x80089FE8
    // 0x8080028C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x8080028C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_28:
    // 0x80800290: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800294: addiu       $a1, $zero, 0xFE8
        ctx->r5 = ADD32(0, 0XFE8);
            goto L_8080030C;
    }
    // 0x80800294: addiu       $a1, $zero, 0xFE8
    ctx->r5 = ADD32(0, 0XFE8);
    // 0x80800298: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080029C: addiu       $t3, $zero, 0x53
    ctx->r11 = ADD32(0, 0X53);
    // 0x808002A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808002A4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808002A8: jal         0x8008A208
    // 0x808002AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x808002AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_29:
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x80102424
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x808002BC: b           L_80800310
    // 0x808002C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800310;
    // 0x808002C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002C4:
    // 0x808002C4: jal         0x80800664
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800664_chpawnbroker(rdram, ctx);
        goto after_31;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808002CC: jal         0x80101DDC
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_32;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x808002D4: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x808002D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: jal         0x80102424
    // 0x808002E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_33;
    // 0x808002E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_33:
    // 0x808002E4: addiu       $a0, $zero, 0x353
    ctx->r4 = ADD32(0, 0X353);
    // 0x808002E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808002EC: jal         0x80101180
    // 0x808002F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_34;
    // 0x808002F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_34:
    // 0x808002F4: jal         0x800DA544
    // 0x808002F8: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    func_800DA544(rdram, ctx);
        goto after_35;
    // 0x808002F8: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    after_35:
    // 0x808002FC: b           L_80800310
    // 0x80800300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800310;
    // 0x80800300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800304:
    // 0x80800304: jal         0x80800694
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800694_chpawnbroker(rdram, ctx);
        goto after_36;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
L_8080030C:
    // 0x8080030C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800310:
    // 0x80800310: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800314: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void func_800FF390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FF394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FF398: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF39C: jal         0x801065E0
    // 0x800FF3A0: sw          $zero, 0x5A50($at)
    MEM_W(0X5A50, ctx->r1) = 0;
    func_801065E0(rdram, ctx);
        goto after_0;
    // 0x800FF3A0: sw          $zero, 0x5A50($at)
    MEM_W(0X5A50, ctx->r1) = 0;
    after_0:
    // 0x800FF3A4: jal         0x80104170
    // 0x800FF3A8: nop

    func_80104170(rdram, ctx);
        goto after_1;
    // 0x800FF3A8: nop

    after_1:
    // 0x800FF3AC: jal         0x80104350
    // 0x800FF3B0: nop

    func_80104350(rdram, ctx);
        goto after_2;
    // 0x800FF3B0: nop

    after_2:
    // 0x800FF3B4: jal         0x80105410
    // 0x800FF3B8: nop

    func_80105410(rdram, ctx);
        goto after_3;
    // 0x800FF3B8: nop

    after_3:
    // 0x800FF3BC: jal         0x80105C20
    // 0x800FF3C0: nop

    func_80105C20(rdram, ctx);
        goto after_4;
    // 0x800FF3C0: nop

    after_4:
    // 0x800FF3C4: jal         0x80106A20
    // 0x800FF3C8: nop

    func_80106A20(rdram, ctx);
        goto after_5;
    // 0x800FF3C8: nop

    after_5:
    // 0x800FF3CC: jal         0x80106DF0
    // 0x800FF3D0: nop

    func_80106DF0(rdram, ctx);
        goto after_6;
    // 0x800FF3D0: nop

    after_6:
    // 0x800FF3D4: jal         0x80107BB0
    // 0x800FF3D8: nop

    func_80107BB0(rdram, ctx);
        goto after_7;
    // 0x800FF3D8: nop

    after_7:
    // 0x800FF3DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FF3E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FF3E4: jr          $ra
    // 0x800FF3E8: nop

    return;
    // 0x800FF3E8: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084128: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084128);
    return;
    // 0x8008412C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800768_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800768: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080076C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800770: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800774: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080077C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800780: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800784: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800788: beq         $at, $zero, L_808009C4
    if (ctx->r1 == 0) {
        // 0x8080078C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808009C4;
    }
    // 0x8080078C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800790: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2408, 0XE40) << 16);
    // 0x80800794: addu        $at, $at, $t8
    gpr jr_addend_8080079C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800798: lw          $t8, 0xE40($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2408, 0XE40));
    // 0x8080079C: jr          $t8
    // 0x808007A0: nop

    switch (jr_addend_8080079C >> 2) {
        case 0: goto L_808007A4; break;
        case 1: goto L_808007E0; break;
        case 2: goto L_80800858; break;
        case 3: goto L_808008D0; break;
        case 4: goto L_8080093C; break;
        case 5: goto L_80800990; break;
        default: switch_error(__func__, 0x8080079C, 0x80800E40);
    }
    // 0x808007A0: nop

L_808007A4:
    // 0x808007A4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808007A8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808007AC: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x808007B0: jal         0x8008A1D0
    // 0x808007B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808007B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808007B8: beq         $v0, $zero, L_808009C4
    if (ctx->r2 == 0) {
        // 0x808007BC: addiu       $a1, $zero, 0x17C8
        ctx->r5 = ADD32(0, 0X17C8);
            goto L_808009C4;
    }
    // 0x808007BC: addiu       $a1, $zero, 0x17C8
    ctx->r5 = ADD32(0, 0X17C8);
    // 0x808007C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007C4: addiu       $t9, $zero, 0x39
    ctx->r25 = ADD32(0, 0X39);
    // 0x808007C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808007CC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808007D0: jal         0x8008A208
    // 0x808007D4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808007D4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808007D8: b           L_808009C8
    // 0x808007DC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
        goto L_808009C8;
    // 0x808007DC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
L_808007E0:
    // 0x808007E0: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2408, 0XF30) << 16);
    // 0x808007E4: addiu       $t1, $t1, 0xF30
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2408, 0XF30));
    // 0x808007E8: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808007EC: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x808007F0: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x808007F4: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x808007F8: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808007FC: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2408, 0XF3C) << 16);
    // 0x80800800: addiu       $t5, $t5, 0xF3C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2408, 0XF3C));
    // 0x80800804: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80800808: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x8080080C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80800810: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x80800814: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80800818: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8080081C: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800824: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80800828: jal         0x80101F24
    // 0x8080082C: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x8080082C: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    after_2:
    // 0x80800830: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800834: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800838: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8080083C: jal         0x800F3214
    // 0x80800840: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800F3214(rdram, ctx);
        goto after_3;
    // 0x80800840: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800844: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80800848: jal         0x800C8E84
    // 0x8080084C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x8080084C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80800850: b           L_808009C8
    // 0x80800854: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
        goto L_808009C8;
    // 0x80800854: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
L_80800858:
    // 0x80800858: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080085C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800860: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x80800864: jal         0x8008A1D0
    // 0x80800868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8080086C: beq         $v0, $zero, L_8080088C
    if (ctx->r2 == 0) {
        // 0x80800870: addiu       $a1, $zero, 0x17C9
        ctx->r5 = ADD32(0, 0X17C9);
            goto L_8080088C;
    }
    // 0x80800870: addiu       $a1, $zero, 0x17C9
    ctx->r5 = ADD32(0, 0X17C9);
    // 0x80800874: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800878: addiu       $t8, $zero, 0x39
    ctx->r24 = ADD32(0, 0X39);
    // 0x8080087C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800880: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800884: jal         0x8008A208
    // 0x80800888: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800888: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_6:
L_8080088C:
    // 0x8080088C: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80800890: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800894: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800898: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x8080089C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008A0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808008A4: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x808008A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808008AC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808008B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808008B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808008B8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808008BC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808008C0: jal         0x80089F20
    // 0x808008C4: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808008C4: nop

    after_7:
    // 0x808008C8: b           L_808009C8
    // 0x808008CC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
        goto L_808009C8;
    // 0x808008CC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
L_808008D0:
    // 0x808008D0: jal         0x80105A5C
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_8;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808008D8: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x808008DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800900;
    }
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    // 0x808008E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808008E8: jal         0x80088868
    // 0x808008EC: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_9;
    // 0x808008EC: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_9:
    // 0x808008F0: jal         0x800FFA88
    // 0x808008F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_10;
    // 0x808008F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x808008F8: b           L_808009C8
    // 0x808008FC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
        goto L_808009C8;
    // 0x808008FC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
L_80800900:
    // 0x80800900: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800904: jal         0x80105998
    // 0x80800908: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80105998(rdram, ctx);
        goto after_11;
    // 0x80800908: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_11:
    // 0x8080090C: beq         $v0, $zero, L_8080092C
    if (ctx->r2 == 0) {
        // 0x80800910: addiu       $a1, $zero, 0x180D
        ctx->r5 = ADD32(0, 0X180D);
            goto L_8080092C;
    }
    // 0x80800910: addiu       $a1, $zero, 0x180D
    ctx->r5 = ADD32(0, 0X180D);
    // 0x80800914: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800918: addiu       $t2, $zero, 0x39
    ctx->r10 = ADD32(0, 0X39);
    // 0x8080091C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800920: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800924: jal         0x8008A208
    // 0x80800928: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800928: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_12:
L_8080092C:
    // 0x8080092C: jal         0x80800A1C
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A1C_chdinofamilysick(rdram, ctx);
        goto after_13;
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800934: b           L_808009C8
    // 0x80800938: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
        goto L_808009C8;
    // 0x80800938: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
L_8080093C:
    // 0x8080093C: jal         0x80105A5C
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_14;
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800944: beq         $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800948: nop
    
            goto L_80800980;
    }
    // 0x80800948: nop

    // 0x8080094C: jal         0x800DA524
    // 0x80800950: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    func_800DA524(rdram, ctx);
        goto after_15;
    // 0x80800950: addiu       $a0, $zero, 0x189
    ctx->r4 = ADD32(0, 0X189);
    after_15:
    // 0x80800954: addiu       $a0, $zero, 0x290
    ctx->r4 = ADD32(0, 0X290);
    // 0x80800958: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x8080095C: jal         0x80101180
    // 0x80800960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_16;
    // 0x80800960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: jal         0x80102424
    // 0x8080096C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x8080096C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x80800970: lbu         $t0, 0x77($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X77);
    // 0x80800974: andi        $t1, $t0, 0xFFF0
    ctx->r9 = ctx->r8 & 0XFFF0;
    // 0x80800978: b           L_808009C4
    // 0x8080097C: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
        goto L_808009C4;
    // 0x8080097C: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
L_80800980:
    // 0x80800980: jal         0x80800A1C
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A1C_chdinofamilysick(rdram, ctx);
        goto after_18;
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800988: b           L_808009C8
    // 0x8080098C: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
        goto L_808009C8;
    // 0x8080098C: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
L_80800990:
    // 0x80800990: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800994: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800998: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x8080099C: jal         0x8008A1D0
    // 0x808009A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x808009A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x808009A4: beq         $v0, $zero, L_808009C4
    if (ctx->r2 == 0) {
        // 0x808009A8: addiu       $a1, $zero, 0x17CA
        ctx->r5 = ADD32(0, 0X17CA);
            goto L_808009C4;
    }
    // 0x808009A8: addiu       $a1, $zero, 0x17CA
    ctx->r5 = ADD32(0, 0X17CA);
    // 0x808009AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808009B0: addiu       $t3, $zero, 0x39
    ctx->r11 = ADD32(0, 0X39);
    // 0x808009B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808009B8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808009BC: jal         0x8008A208
    // 0x808009C0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_20;
    // 0x808009C0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_20:
L_808009C4:
    // 0x808009C4: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
L_808009C8:
    // 0x808009C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808009CC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808009D0: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x808009D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009D8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808009DC: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x808009E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009E4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808009E8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808009EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808009F0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808009F4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808009F8: jal         0x80089F20
    // 0x808009FC: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x808009FC: nop

    after_21:
    // 0x80800A00: jal         0x80087738
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_22;
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A10: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800A14: jr          $ra
    // 0x80800A18: nop

    return;
    // 0x80800A18: nop

;}
RECOMP_FUNC void func_800EA0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA0CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA0D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA0D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EA0D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EA0DC: jal         0x80087858
    // 0x800EA0E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _cothemedll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800EA0E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EA0E4: jal         0x800DBB5C
    // 0x800EA0E8: nop

    func_800DBB5C(rdram, ctx);
        goto after_1;
    // 0x800EA0E8: nop

    after_1:
    // 0x800EA0EC: jal         0x800BF8BC
    // 0x800EA0F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800BF8BC(rdram, ctx);
        goto after_2;
    // 0x800EA0F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800EA0F4: jal         0x800C0064
    // 0x800EA0F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C0064(rdram, ctx);
        goto after_3;
    // 0x800EA0F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800EA0FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EA100: addiu       $a0, $a0, 0x2DC0
    ctx->r4 = ADD32(ctx->r4, 0X2DC0);
    // 0x800EA104: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800EA108: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800EA10C: jal         0x80088B68
    // 0x800EA110: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _gsworldDll_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x800EA110: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800EA114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA11C: jr          $ra
    // 0x800EA120: nop

    return;
    // 0x800EA120: nop

;}
RECOMP_FUNC void func_808004F8_chloggo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800500: jal         0x80088848
    // 0x80800504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800508: beql        $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x8080050C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080051C;
    }
    goto skip_0;
    // 0x8080050C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800510: jal         0x800FFAB0
    // 0x80800514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080051C:
    // 0x8080051C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800520: jr          $ra
    // 0x80800524: nop

    return;
    // 0x80800524: nop

;}
RECOMP_FUNC void sccustom_big_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080039C: jal         0x80800000
    // 0x808003A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_sccustom_big(rdram, ctx);
        goto after_0;
    // 0x808003A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003A8: jal         0x80800314
    // 0x808003AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800314_sccustom_big(rdram, ctx);
        goto after_1;
    // 0x808003AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void babackpack_get_state(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80800438: jr          $ra
    // 0x8080043C: lw          $v0, 0xC($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XC);
    return;
    // 0x8080043C: lw          $v0, 0xC($t6)
    ctx->r2 = MEM_W(ctx->r14, 0XC);
;}
RECOMP_FUNC void func_800C6E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6E68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C6E6C: jal         0x800C70B0
    // 0x800C6E70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_0;
    // 0x800C6E70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800C6E74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C6E78: jal         0x800C70B0
    // 0x800C6E7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_1;
    // 0x800C6E7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800C6E80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800C6E84: jal         0x800C70B0
    // 0x800C6E88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_2;
    // 0x800C6E88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800C6E8C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800C6E90: jal         0x800C70B0
    // 0x800C6E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_3;
    // 0x800C6E94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800C6E98: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800C6E9C: jal         0x800C70B0
    // 0x800C6EA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_4;
    // 0x800C6EA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800C6EA4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800C6EA8: jal         0x800C70B0
    // 0x800C6EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_5;
    // 0x800C6EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800C6EB0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C6EB4: jal         0x800C70B0
    // 0x800C6EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_6;
    // 0x800C6EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x800C6EBC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800C6EC0: jal         0x800C70B0
    // 0x800C6EC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_7;
    // 0x800C6EC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x800C6EC8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800C6ECC: jal         0x800C70B0
    // 0x800C6ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_8;
    // 0x800C6ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x800C6ED4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800C6ED8: jal         0x800C70B0
    // 0x800C6EDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_9;
    // 0x800C6EDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x800C6EE0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800C6EE4: jal         0x800C70B0
    // 0x800C6EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_10;
    // 0x800C6EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x800C6EEC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x800C6EF0: jal         0x800C70B0
    // 0x800C6EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_11;
    // 0x800C6EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x800C6EF8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800C6EFC: jal         0x800C70B0
    // 0x800C6F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_12;
    // 0x800C6F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x800C6F04: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x800C6F08: jal         0x800C70B0
    // 0x800C6F0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_13;
    // 0x800C6F0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x800C6F10: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800C6F14: jal         0x800C70B0
    // 0x800C6F18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_14;
    // 0x800C6F18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x800C6F1C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800C6F20: jal         0x800C70B0
    // 0x800C6F24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_15;
    // 0x800C6F24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x800C6F28: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C6F2C: jal         0x800C70B0
    // 0x800C6F30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_16;
    // 0x800C6F30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x800C6F34: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x800C6F38: jal         0x800C70B0
    // 0x800C6F3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_17;
    // 0x800C6F3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x800C6F40: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800C6F44: jal         0x800C70B0
    // 0x800C6F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_18;
    // 0x800C6F48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x800C6F4C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x800C6F50: jal         0x800C70B0
    // 0x800C6F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_19;
    // 0x800C6F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x800C6F58: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x800C6F5C: jal         0x800C70B0
    // 0x800C6F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70B0(rdram, ctx);
        goto after_20;
    // 0x800C6F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x800C6F64: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800C6F68: jal         0x800C70D0
    // 0x800C6F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_21;
    // 0x800C6F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x800C6F70: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x800C6F74: jal         0x800C70D0
    // 0x800C6F78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_22;
    // 0x800C6F78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x800C6F7C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x800C6F80: jal         0x800C70D0
    // 0x800C6F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_23;
    // 0x800C6F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x800C6F88: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x800C6F8C: jal         0x800C70D0
    // 0x800C6F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_24;
    // 0x800C6F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x800C6F94: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800C6F98: jal         0x800C70D0
    // 0x800C6F9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_25;
    // 0x800C6F9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x800C6FA0: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x800C6FA4: jal         0x800C70D0
    // 0x800C6FA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_26;
    // 0x800C6FA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x800C6FAC: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x800C6FB0: jal         0x800C70D0
    // 0x800C6FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_27;
    // 0x800C6FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x800C6FB8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x800C6FBC: jal         0x800C70D0
    // 0x800C6FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_28;
    // 0x800C6FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x800C6FC4: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x800C6FC8: jal         0x800C70D0
    // 0x800C6FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_29;
    // 0x800C6FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x800C6FD0: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x800C6FD4: jal         0x800C70D0
    // 0x800C6FD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_30;
    // 0x800C6FD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x800C6FDC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x800C6FE0: jal         0x800C70D0
    // 0x800C6FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_31;
    // 0x800C6FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x800C6FE8: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x800C6FEC: jal         0x800C70D0
    // 0x800C6FF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_32;
    // 0x800C6FF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x800C6FF4: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x800C6FF8: jal         0x800C70D0
    // 0x800C6FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C70D0(rdram, ctx);
        goto after_33;
    // 0x800C6FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x800C7000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7008: jr          $ra
    // 0x800C700C: nop

    return;
    // 0x800C700C: nop

;}
RECOMP_FUNC void bakaztorpedo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x80800110: jr          $ra
    // 0x80800114: sb          $a1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r5;
    return;
    // 0x80800114: sb          $a1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _glsplinenode_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884F8: syscall     690
    recomp_syscall_handler(rdram, ctx, 0x800884F8);
    return;
    // 0x800884FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008D0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D0E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D0E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D0E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D0EC: jal         0x800C6E38
    // 0x8008D0F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D0F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8008D0F4: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D0F8: beq         $t6, $zero, L_8008D13C
    if (ctx->r14 == 0) {
        // 0x8008D0FC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D13C;
    }
    // 0x8008D0FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008D104: jal         0x80095748
    // 0x8008D108: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    baflag_isFalse(rdram, ctx);
        goto after_1;
    // 0x8008D108: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_1:
    // 0x8008D10C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D110: beq         $t7, $zero, L_8008D13C
    if (ctx->r15 == 0) {
        // 0x8008D114: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8008D13C;
    }
    // 0x8008D114: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8008D118: jal         0x800A3304
    // 0x8008D11C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_2;
    // 0x8008D11C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8008D120: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D124: bne         $t8, $zero, L_8008D13C
    if (ctx->r24 != 0) {
        // 0x8008D128: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8008D13C;
    }
    // 0x8008D128: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008D12C: jal         0x800A3274
    // 0x8008D130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3274(rdram, ctx);
        goto after_3;
    // 0x8008D130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8008D134: xori        $t9, $v0, 0xB
    ctx->r25 = ctx->r2 ^ 0XB;
    // 0x8008D138: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_8008D13C:
    // 0x8008D13C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D144: jr          $ra
    // 0x8008D148: nop

    return;
    // 0x8008D148: nop

;}
RECOMP_FUNC void func_800D3B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3B60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D3B64: jr          $ra
    // 0x800D3B68: lbu         $v0, -0x4C0D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0D);
    return;
    // 0x800D3B68: lbu         $v0, -0x4C0D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0D);
;}
RECOMP_FUNC void __bsbanbflip_set_substate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800068: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800074: jal         0x8008CABC
    // 0x80800078: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080007C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800080: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800084: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800088: beq         $v1, $zero, L_808000B0
    if (ctx->r3 == 0) {
        // 0x8080008C: nop
    
            goto L_808000B0;
    }
    // 0x8080008C: nop

    // 0x80800090: beq         $v1, $at, L_808000E4
    if (ctx->r3 == ctx->r1) {
        // 0x80800094: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000E4;
    }
    // 0x80800094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800098: beq         $v1, $at, L_8080019C
    if (ctx->r3 == ctx->r1) {
        // 0x8080009C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080019C;
    }
    // 0x8080009C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000A0: beq         $v1, $at, L_808002C0
    if (ctx->r3 == ctx->r1) {
        // 0x808000A4: nop
    
            goto L_808002C0;
    }
    // 0x808000A4: nop

    // 0x808000A8: b           L_80800350
    // 0x808000AC: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
        goto L_80800350;
    // 0x808000AC: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
L_808000B0:
    // 0x808000B0: jal         0x800C6DA0
    // 0x808000B4: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x808000B4: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    after_1:
    // 0x808000B8: jal         0x8009BC6C
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000C0: jal         0x8009BC90
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x800A0D44
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0D44(rdram, ctx);
        goto after_4;
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000D4: jal         0x8009F1E0
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_5;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000DC: b           L_8080034C
    // 0x808000E0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
        goto L_8080034C;
    // 0x808000E0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_808000E4:
    // 0x808000E4: jal         0x8008AF24
    // 0x808000E8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_reset(rdram, ctx);
        goto after_6;
    // 0x808000E8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x808000EC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808000F0: jal         0x8008B1A0
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_7;
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808000F8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808000FC: jal         0x8008AED4
    // 0x80800100: addiu       $a1, $zero, 0x27B
    ctx->r5 = ADD32(0, 0X27B);
    anctrl_setIndex(rdram, ctx);
        goto after_8;
    // 0x80800100: addiu       $a1, $zero, 0x27B
    ctx->r5 = ADD32(0, 0X27B);
    after_8:
    // 0x80800104: lui         $a1, 0x4013
    ctx->r5 = S32(0X4013 << 16);
    // 0x80800108: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080010C: jal         0x8008B1BC
    // 0x80800110: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_setDuration(rdram, ctx);
        goto after_9;
    // 0x80800110: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x80800114: lui         $a2, 0x3F49
    ctx->r6 = S32(0X3F49 << 16);
    // 0x80800118: ori         $a2, $a2, 0x5E9E
    ctx->r6 = ctx->r6 | 0X5E9E;
    // 0x8080011C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800120: jal         0x8008B1D4
    // 0x80800124: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_10;
    // 0x80800124: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800128: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8080012C: jal         0x8008B24C
    // 0x80800130: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setStart(rdram, ctx);
        goto after_11;
    // 0x80800130: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800134: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800138: jal         0x8008B134
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800140: jal         0x8008B064
    // 0x80800144: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x80800144: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_13:
    // 0x80800148: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8080014C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080015C: jal         0x8009FFD8
    // 0x80800160: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_14;
    // 0x80800160: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x80800164: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800168: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: jal         0x8009F1C8
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_15;
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800180: jal         0x8009F1C8
    // 0x80800184: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_16;
    // 0x80800184: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_16:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x800A0CF4
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_17;
    // 0x80800190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800194: b           L_8080034C
    // 0x80800198: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
        goto L_8080034C;
    // 0x80800198: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_8080019C:
    // 0x8080019C: jal         0x8009EF04
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_18;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808001B4: nop

    // 0x808001B8: bc1t        L_8080025C
    if (c1cs) {
        // 0x808001BC: nop
    
            goto L_8080025C;
    }
    // 0x808001BC: nop

    // 0x808001C0: jal         0x8009C908
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setUpdateType(rdram, ctx);
        goto after_19;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x8009D2D8
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_20;
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_20:
    // 0x808001D4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x808001D8: addiu       $t7, $t7, -0x10FC
    ctx->r15 = ADD32(ctx->r15, -0X10FC);
    // 0x808001DC: beql        $t7, $zero, L_808001FC
    if (ctx->r15 == 0) {
        // 0x808001E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001E4: jal         0x8009EEB8
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_21;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808001EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001F0: jal         0x8009C914
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_22;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001FC:
    // 0x808001FC: jal         0x8009C9C8
    // 0x80800200: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    yaw_rotateTimed(rdram, ctx);
        goto after_23;
    // 0x80800200: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_23:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x8009B800
    // 0x8080020C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_24;
    // 0x8080020C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_24:
    // 0x80800210: jal         0x8009C990
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_25;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800218: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080021C: jal         0x8009B9C0
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_26;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: jal         0x8009B9B0
    // 0x8080022C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_27;
    // 0x8080022C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_27:
    // 0x80800230: jal         0x8009C990
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_28;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800238: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080023C: jal         0x8009BB00
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_29;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800244: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x8009BA68
    // 0x80800250: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_30;
    // 0x80800250: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_30:
    // 0x80800254: b           L_80800274
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800274;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080025C:
    // 0x8080025C: jal         0x8009B800
    // 0x80800260: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_31;
    // 0x80800260: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_31:
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x8009B9B0
    // 0x8080026C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_32;
    // 0x8080026C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_32:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800274:
    // 0x80800274: jal         0x8009BA58
    // 0x80800278: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_33;
    // 0x80800278: lui         $a1, 0x4448
    ctx->r5 = S32(0X4448 << 16);
    after_33:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x8009BCB4
    // 0x80800284: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_34;
    // 0x80800284: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_34:
    // 0x80800288: lui         $a1, 0xC405
    ctx->r5 = S32(0XC405 << 16);
    // 0x8080028C: ori         $a1, $a1, 0x5333
    ctx->r5 = ctx->r5 | 0X5333;
    // 0x80800290: jal         0x8009BCC4
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_35;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800298: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x8080029C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808002A0: jal         0x8008B1BC
    // 0x808002A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_setDuration(rdram, ctx);
        goto after_36;
    // 0x808002A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_36:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: addiu       $a1, $zero, 0x5A6
    ctx->r5 = ADD32(0, 0X5A6);
    // 0x808002B0: jal         0x8009DE38
    // 0x808002B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_37;
    // 0x808002B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_37:
    // 0x808002B8: b           L_8080034C
    // 0x808002BC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
        goto L_8080034C;
    // 0x808002BC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_808002C0:
    // 0x808002C0: jal         0x8008AF24
    // 0x808002C4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_reset(rdram, ctx);
        goto after_38;
    // 0x808002C4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_38:
    // 0x808002C8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808002CC: jal         0x8008AED4
    // 0x808002D0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    anctrl_setIndex(rdram, ctx);
        goto after_39;
    // 0x808002D0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_39:
    // 0x808002D4: lui         $a1, 0x400C
    ctx->r5 = S32(0X400C << 16);
    // 0x808002D8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002DC: jal         0x8008B1BC
    // 0x808002E0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_setDuration(rdram, ctx);
        goto after_40;
    // 0x808002E0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_40:
    // 0x808002E4: lui         $a1, 0x3F5B
    ctx->r5 = S32(0X3F5B << 16);
    // 0x808002E8: ori         $a1, $a1, 0x4A23
    ctx->r5 = ctx->r5 | 0X4A23;
    // 0x808002EC: jal         0x8008B24C
    // 0x808002F0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_setStart(rdram, ctx);
        goto after_41;
    // 0x808002F0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_41:
    // 0x808002F4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808002F8: jal         0x8008B134
    // 0x808002FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_42;
    // 0x808002FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
    // 0x80800300: jal         0x8008B064
    // 0x80800304: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    anctrl_start(rdram, ctx);
        goto after_43;
    // 0x80800304: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_43:
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: jal         0x8009B800
    // 0x80800310: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_44;
    // 0x80800310: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_44:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x8009B9B0
    // 0x8080031C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_45;
    // 0x8080031C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_45:
    // 0x80800320: jal         0x800EFD24
    // 0x80800324: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EFD24(rdram, ctx);
        goto after_46;
    // 0x80800324: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_46:
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x8009BA9C
    // 0x80800330: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009BA9C(rdram, ctx);
        goto after_47;
    // 0x80800330: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_47:
    // 0x80800334: jal         0x8009FE58
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_48;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x800A0CF4
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_49;
    // 0x80800344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_49:
    // 0x80800348: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_8080034C:
    // 0x8080034C: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
L_80800350:
    // 0x80800350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800354: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800358: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080035C: jr          $ra
    // 0x80800360: nop

    return;
    // 0x80800360: nop

;}
RECOMP_FUNC void func_80802398_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802398: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080239C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808023A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808023A4: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x808023A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808023AC: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x808023B0: bgezl       $t8, L_808023C4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808023B4: lhu         $a2, 0x76($s0)
        ctx->r6 = MEM_HU(ctx->r16, 0X76);
            goto L_808023C4;
    }
    goto skip_0;
    // 0x808023B4: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x808023B8: b           L_8080245C
    // 0x808023BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080245C;
    // 0x808023BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808023C0: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
L_808023C4:
    // 0x808023C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023C8: addiu       $a1, $zero, 0x3BF
    ctx->r5 = ADD32(0, 0X3BF);
    // 0x808023CC: srl         $t9, $a2, 7
    ctx->r25 = S32(U32(ctx->r6) >> 7);
    // 0x808023D0: jal         0x80089C70
    // 0x808023D4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808023D4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_0:
    // 0x808023D8: bne         $v0, $zero, L_808023E8
    if (ctx->r2 != 0) {
        // 0x808023DC: nop
    
            goto L_808023E8;
    }
    // 0x808023DC: nop

    // 0x808023E0: b           L_8080245C
    // 0x808023E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080245C;
    // 0x808023E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808023E8:
    // 0x808023E8: jal         0x80106790
    // 0x808023EC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808023EC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x808023F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808023F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808023F8: jal         0x80100094
    // 0x808023FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808023FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802400: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80802404: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802408: lh          $t1, 0x7E($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X7E);
    // 0x8080240C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802410: bltzl       $t1, L_8080243C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80802414: lbu         $t6, 0x10($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X10);
            goto L_8080243C;
    }
    goto skip_1;
    // 0x80802414: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    skip_1:
    // 0x80802418: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080241C: jal         0x808025D4
    // 0x80802420: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_808025D4_chfactoryrobot(rdram, ctx);
        goto after_3;
    // 0x80802420: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x80802424: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80802428: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080242C: lbu         $t3, 0x7E($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X7E);
    // 0x80802430: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x80802434: sb          $t4, 0x7E($a2)
    MEM_B(0X7E, ctx->r6) = ctx->r12;
    // 0x80802438: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
L_8080243C:
    // 0x8080243C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80802440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802444: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80802448: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8080244C: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80802450: lbu         $t9, 0x10($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X10);
    // 0x80802454: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80802458: sb          $t0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r8;
L_8080245C:
    // 0x8080245C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802460: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802464: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802468: jr          $ra
    // 0x8080246C: nop

    return;
    // 0x8080246C: nop

;}
RECOMP_FUNC void _baeggfire_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B20: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B20);
    return;
    // 0x80084B24: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80804140_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804140: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80804144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804148: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080414C: jal         0x80100094
    // 0x80804150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804154: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80804158: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080415C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80804160: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80804164: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804168: lwc1        $f12, 0x24($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X24);
    // 0x8080416C: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x80804170: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80804174: jal         0x800F10B4
    // 0x80804178: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80804178: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080417C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804180: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80804184: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B60) << 16);
    // 0x80804188: lwc1        $f8, -0x64A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B60));
    // 0x8080418C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80804190: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804194: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x80804198: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8080419C: lwc1        $f12, 0x24($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X24);
    // 0x808041A0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808041A4: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x808041A8: jal         0x800F10B4
    // 0x808041AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808041AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808041B0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808041B4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808041B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808041BC: jal         0x800E8DB0
    // 0x808041C0: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    func_800E8DB0(rdram, ctx);
        goto after_3;
    // 0x808041C0: lbu         $a0, 0xA($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XA);
    after_3:
    // 0x808041C4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808041C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808041CC: jal         0x800E8D28
    // 0x808041D0: lbu         $a0, 0xA($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0XA);
    func_800E8D28(rdram, ctx);
        goto after_4;
    // 0x808041D0: lbu         $a0, 0xA($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0XA);
    after_4:
    // 0x808041D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808041D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808041DC: jr          $ra
    // 0x808041E0: nop

    return;
    // 0x808041E0: nop

;}
