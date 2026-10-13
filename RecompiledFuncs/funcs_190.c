#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808029A4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808029A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808029AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808029B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808029B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808029B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808029BC: jal         0x80100094
    // 0x808029C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808029C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808029C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808029C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808029CC: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_808029D0:
    // 0x808029D0: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x808029D4: beql        $a0, $zero, L_808029E8
    if (ctx->r4 == 0) {
        // 0x808029D8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_808029E8;
    }
    goto skip_0;
    // 0x808029D8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x808029DC: jal         0x800857C0
    // 0x808029E0: nop

    _chblink_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808029E0: nop

    after_1:
    // 0x808029E4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_808029E8:
    // 0x808029E8: bne         $s0, $s2, L_808029D0
    if (ctx->r16 != ctx->r18) {
        // 0x808029EC: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_808029D0;
    }
    // 0x808029EC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x808029F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808029F4: jal         0x80100094
    // 0x808029F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808029F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808029FC: beq         $v0, $zero, L_80802A0C
    if (ctx->r2 == 0) {
        // 0x80802A00: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80802A0C;
    }
    // 0x80802A00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802A04: jal         0x800897C8
    // 0x80802A08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80802A08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80802A0C:
    // 0x80802A0C: jal         0x8080216C
    // 0x80802A10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080216C_chquiz(rdram, ctx);
        goto after_4;
    // 0x80802A10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80802A14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802A1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802A20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802A24: jr          $ra
    // 0x80802A28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80802A28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _idflashbaddie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DE0: syscall     741
    recomp_syscall_handler(rdram, ctx, 0x80088DE0);
    return;
    // 0x80088DE4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bashoes_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _bsdronebitten_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083020: syscall     39
    recomp_syscall_handler(rdram, ctx, 0x80083020);
    return;
    // 0x80083024: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80021960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021960: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80021964: lui         $t6, 0x7FFF
    ctx->r14 = S32(0X7FFF << 16);
    // 0x80021968: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8002196C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80021970: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80021974: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80021978: lw          $t7, 0x11F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X11F4);
    // 0x8002197C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80021980: beq         $t8, $zero, L_800219E4
    if (ctx->r24 == 0) {
        // 0x80021984: sw          $t8, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r24;
            goto L_800219E4;
    }
    // 0x80021984: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
L_80021988:
    // 0x80021988: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8002198C: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x80021990: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x80021994: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80021998: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x8002199C: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x800219A0: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x800219A4: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800219A8: beq         $at, $zero, L_800219D4
    if (ctx->r1 == 0) {
        // 0x800219AC: nop
    
            goto L_800219D4;
    }
    // 0x800219AC: nop

    // 0x800219B0: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800219B4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800219B8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800219BC: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x800219C0: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800219C4: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x800219C8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800219CC: subu        $t1, $t7, $t9
    ctx->r9 = SUB32(ctx->r15, ctx->r25);
    // 0x800219D0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
L_800219D4:
    // 0x800219D4: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x800219D8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800219DC: bne         $t2, $zero, L_80021988
    if (ctx->r10 != 0) {
        // 0x800219E0: sw          $t2, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r10;
            goto L_80021988;
    }
    // 0x800219E0: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
L_800219E4:
    // 0x800219E4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800219E8: b           L_800219F8
    // 0x800219EC: lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X10);
        goto L_800219F8;
    // 0x800219EC: lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X10);
    // 0x800219F0: b           L_800219F8
    // 0x800219F4: nop

        goto L_800219F8;
    // 0x800219F4: nop

L_800219F8:
    // 0x800219F8: jr          $ra
    // 0x800219FC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800219FC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800C8678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C867C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C8680: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C8684: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C8688: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C868C: addiu       $s1, $s1, -0x5500
    ctx->r17 = ADD32(ctx->r17, -0X5500);
    // 0x800C8690: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C8694: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C8698: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C869C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800C86A0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800C86A4: jal         0x800B28C4
    // 0x800C86A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800C86A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x800C86AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C86B0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800C86B4: jal         0x800B28CC
    // 0x800C86B8: addiu       $a1, $s0, -0x1
    ctx->r5 = ADD32(ctx->r16, -0X1);
    vector_at(rdram, ctx);
        goto after_1;
    // 0x800C86B8: addiu       $a1, $s0, -0x1
    ctx->r5 = ADD32(ctx->r16, -0X1);
    after_1:
    // 0x800C86BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C86C0: jal         0x800B296C
    // 0x800C86C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    vector_end(rdram, ctx);
        goto after_2;
    // 0x800C86C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x800C86C8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800C86CC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800C86D0: beq         $at, $zero, L_800C8740
    if (ctx->r1 == 0) {
        // 0x800C86D4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800C8740;
    }
    // 0x800C86D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800C86D8: lbu         $t6, 0x15($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15);
L_800C86DC:
    // 0x800C86DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C86E0: beql        $t6, $zero, L_800C8734
    if (ctx->r14 == 0) {
        // 0x800C86E4: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800C8734;
    }
    goto skip_0;
    // 0x800C86E4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x800C86E8: jalr        $s3
    // 0x800C86EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_3;
    // 0x800C86EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x800C86F0: beql        $v0, $zero, L_800C8734
    if (ctx->r2 == 0) {
        // 0x800C86F4: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800C8734;
    }
    goto skip_1;
    // 0x800C86F4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_1:
    // 0x800C86F8: lbu         $t7, 0x17($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X17);
    // 0x800C86FC: bnel        $t7, $zero, L_800C8714
    if (ctx->r15 != 0) {
        // 0x800C8700: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_800C8714;
    }
    goto skip_2;
    // 0x800C8700: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x800C8704: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    // 0x800C8708: beql        $t8, $zero, L_800C8734
    if (ctx->r24 == 0) {
        // 0x800C870C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800C8734;
    }
    goto skip_3;
    // 0x800C870C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_3:
    // 0x800C8710: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
L_800C8714:
    // 0x800C8714: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800C8718: subu        $v0, $s0, $t9
    ctx->r2 = SUB32(ctx->r16, ctx->r25);
    // 0x800C871C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800C8720: mflo        $t0
    ctx->r8 = lo;
    // 0x800C8724: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x800C8728: b           L_800C8748
    // 0x800C872C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8748;
    // 0x800C872C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C8730: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_800C8734:
    // 0x800C8734: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800C8738: bnel        $at, $zero, L_800C86DC
    if (ctx->r1 != 0) {
        // 0x800C873C: lbu         $t6, 0x15($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X15);
            goto L_800C86DC;
    }
    goto skip_4;
    // 0x800C873C: lbu         $t6, 0x15($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15);
    skip_4:
L_800C8740:
    // 0x800C8740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C8744: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8748:
    // 0x800C8748: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C874C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C8750: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8754: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C8758: jr          $ra
    // 0x800C875C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C875C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800F3A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3A78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F3A7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F3A80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F3A84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F3A88: jal         0x800F3930
    // 0x800F3A8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800F3930(rdram, ctx);
        goto after_0;
    // 0x800F3A8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F3A90: bne         $v0, $zero, L_800F3AA0
    if (ctx->r2 != 0) {
        // 0x800F3A94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F3AA0;
    }
    // 0x800F3A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F3A98: b           L_800F3B28
    // 0x800F3A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3B28;
    // 0x800F3A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3AA0:
    // 0x800F3AA0: jal         0x8009E674
    // 0x800F3AA4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_8009E674(rdram, ctx);
        goto after_1;
    // 0x800F3AA4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_1:
    // 0x800F3AA8: beq         $v0, $zero, L_800F3AB8
    if (ctx->r2 == 0) {
        // 0x800F3AAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F3AB8;
    }
    // 0x800F3AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F3AB0: b           L_800F3B28
    // 0x800F3AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3B28;
    // 0x800F3AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3AB8:
    // 0x800F3AB8: jal         0x800F38A8
    // 0x800F3ABC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800F38A8(rdram, ctx);
        goto after_2;
    // 0x800F3ABC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x800F3AC0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F3AC4: jal         0x8009EF04
    // 0x800F3AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_3;
    // 0x800F3AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800F3ACC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F3AD0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800F3AD4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F3AD8: nop

    // 0x800F3ADC: bc1t        L_800F3AF4
    if (c1cs) {
        // 0x800F3AE0: nop
    
            goto L_800F3AF4;
    }
    // 0x800F3AE0: nop

    // 0x800F3AE4: bne         $t6, $zero, L_800F3AF4
    if (ctx->r14 != 0) {
        // 0x800F3AE8: nop
    
            goto L_800F3AF4;
    }
    // 0x800F3AE8: nop

    // 0x800F3AEC: b           L_800F3B28
    // 0x800F3AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3B28;
    // 0x800F3AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3AF4:
    // 0x800F3AF4: jal         0x800F5FA8
    // 0x800F3AF8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F5FA8(rdram, ctx);
        goto after_4;
    // 0x800F3AF8: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_4:
    // 0x800F3AFC: bne         $v0, $zero, L_800F3B0C
    if (ctx->r2 != 0) {
        // 0x800F3B00: nop
    
            goto L_800F3B0C;
    }
    // 0x800F3B00: nop

    // 0x800F3B04: b           L_800F3B28
    // 0x800F3B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3B28;
    // 0x800F3B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3B0C:
    // 0x800F3B0C: jal         0x800A9C98
    // 0x800F3B10: nop

    func_800A9C98(rdram, ctx);
        goto after_5;
    // 0x800F3B10: nop

    after_5:
    // 0x800F3B14: beql        $v0, $zero, L_800F3B28
    if (ctx->r2 == 0) {
        // 0x800F3B18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F3B28;
    }
    goto skip_0;
    // 0x800F3B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800F3B1C: b           L_800F3B28
    // 0x800F3B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3B28;
    // 0x800F3B20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F3B24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F3B28:
    // 0x800F3B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3B2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F3B30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F3B34: jr          $ra
    // 0x800F3B38: nop

    return;
    // 0x800F3B38: nop

;}
RECOMP_FUNC void func_800F5ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5ECC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5ED4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5EDC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5EE0: jal         0x800A4C68
    // 0x800F5EE4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A4C68(rdram, ctx);
        goto after_0;
    // 0x800F5EE4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5EF0: jr          $ra
    // 0x800F5EF4: nop

    return;
    // 0x800F5EF4: nop

;}
RECOMP_FUNC void func_800B0ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0ECC: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800B0ED0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800B0ED4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800B0ED8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800B0EDC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800B0EE0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800B0EE4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800B0EE8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800B0EEC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800B0EF0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800B0EF4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800B0EF8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800B0EFC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800B0F00: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800B0F04: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B0F08: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800B0F0C: sw          $a2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r6;
    // 0x800B0F10: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B0F14: addiu       $s2, $a0, 0x8
    ctx->r18 = ADD32(ctx->r4, 0X8);
    // 0x800B0F18: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800B0F1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B0F20: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B0F24: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B0F28: addu        $s5, $t7, $a0
    ctx->r21 = ADD32(ctx->r15, ctx->r4);
    // 0x800B0F2C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800B0F30: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    // 0x800B0F34: beq         $at, $zero, L_800B10CC
    if (ctx->r1 == 0) {
        // 0x800B0F38: lwc1        $f24, 0xE0($sp)
        ctx->f24.u32l = MEM_W(ctx->r29, 0XE0);
            goto L_800B10CC;
    }
    // 0x800B0F38: lwc1        $f24, 0xE0($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800B0F3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B0F40: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800B0F44: lw          $fp, 0xDC($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XDC);
    // 0x800B0F48: lw          $s7, 0xD8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XD8);
    // 0x800B0F4C: lw          $s6, 0xE4($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XE4);
    // 0x800B0F50: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x800B0F54: addiu       $s3, $sp, 0xB8
    ctx->r19 = ADD32(ctx->r29, 0XB8);
    // 0x800B0F58: addiu       $s1, $sp, 0xAC
    ctx->r17 = ADD32(ctx->r29, 0XAC);
    // 0x800B0F5C: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x800B0F60: lbu         $v0, 0x15($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15);
L_800B0F64:
    // 0x800B0F64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B0F68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B0F6C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B0F70: sllv        $t9, $t8, $v0
    ctx->r25 = S32(ctx->r24 << (ctx->r2 & 31));
    // 0x800B0F74: and         $t0, $t9, $s6
    ctx->r8 = ctx->r25 & ctx->r22;
    // 0x800B0F78: bne         $t0, $zero, L_800B10BC
    if (ctx->r8 != 0) {
        // 0x800B0F7C: addiu       $a1, $s2, 0xC
        ctx->r5 = ADD32(ctx->r18, 0XC);
            goto L_800B10BC;
    }
    // 0x800B0F7C: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x800B0F80: div.s       $f20, $f24, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = DIV_S(ctx->f24.fl, ctx->f22.fl);
    // 0x800B0F84: jal         0x800EE88C
    // 0x800B0F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800B0F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_0:
    // 0x800B0F8C: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800B0F90: jal         0x800EE88C
    // 0x800B0F94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x800B0F94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800B0F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B0F9C: jal         0x800EE88C
    // 0x800B0FA0: addiu       $a1, $s2, 0x6
    ctx->r5 = ADD32(ctx->r18, 0X6);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x800B0FA0: addiu       $a1, $s2, 0x6
    ctx->r5 = ADD32(ctx->r18, 0X6);
    after_2:
    // 0x800B0FA4: lbu         $t1, 0x12($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X12);
    // 0x800B0FA8: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x800B0FAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B0FB0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800B0FB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B0FB8: bgez        $t1, L_800B0FCC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800B0FBC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B0FCC;
    }
    // 0x800B0FBC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B0FC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B0FC4: nop

    // 0x800B0FC8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B0FCC:
    // 0x800B0FCC: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x800B0FD0: lbu         $t2, 0x13($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X13);
    // 0x800B0FD4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B0FD8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800B0FDC: bgez        $t2, L_800B0FF0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B0FE0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800B0FF0;
    }
    // 0x800B0FE0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B0FE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B0FE8: nop

    // 0x800B0FEC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800B0FF0:
    // 0x800B0FF0: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x800B0FF4: lbu         $t3, 0x14($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X14);
    // 0x800B0FF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B0FFC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800B1000: bgez        $t3, L_800B1014
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B1004: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B1014;
    }
    // 0x800B1004: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1008: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B100C: nop

    // 0x800B1010: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800B1014:
    // 0x800B1014: jal         0x800EF334
    // 0x800B1018: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x800B1018: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800B101C: jal         0x80019CD4
    // 0x800B1020: nop

    func_80019CD4(rdram, ctx);
        goto after_4;
    // 0x800B1020: nop

    after_4:
    // 0x800B1024: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B1028: jal         0x80019A10
    // 0x800B102C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80019A10(rdram, ctx);
        goto after_5;
    // 0x800B102C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x800B1030: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800B1034: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    // 0x800B1038: lw          $a1, 0xD0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD0);
    // 0x800B103C: jal         0x8001980C
    // 0x800B1040: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    func_8001980C(rdram, ctx);
        goto after_6;
    // 0x800B1040: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_6:
    // 0x800B1044: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x800B1048: jal         0x800193C4
    // 0x800B104C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800193C4(rdram, ctx);
        goto after_7;
    // 0x800B104C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_7:
    // 0x800B1050: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B1054: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800B1058: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
L_800B105C:
    // 0x800B105C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B1060: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800B1064: addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // 0x800B1068: add.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800B106C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B1070: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800B1074: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x800B1078: nop

    // 0x800B107C: bc1tl       L_800B10AC
    if (c1cs) {
        // 0x800B1080: addiu       $t4, $sp, 0x8C
        ctx->r12 = ADD32(ctx->r29, 0X8C);
            goto L_800B10AC;
    }
    goto skip_0;
    // 0x800B1080: addiu       $t4, $sp, 0x8C
    ctx->r12 = ADD32(ctx->r29, 0X8C);
    skip_0:
    // 0x800B1084: sub.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800B1088: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B108C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B1090: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x800B1094: nop

    // 0x800B1098: bc1tl       L_800B10AC
    if (c1cs) {
        // 0x800B109C: addiu       $t4, $sp, 0x8C
        ctx->r12 = ADD32(ctx->r29, 0X8C);
            goto L_800B10AC;
    }
    goto skip_1;
    // 0x800B109C: addiu       $t4, $sp, 0x8C
    ctx->r12 = ADD32(ctx->r29, 0X8C);
    skip_1:
    // 0x800B10A0: bne         $v0, $s1, L_800B105C
    if (ctx->r2 != ctx->r17) {
        // 0x800B10A4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800B105C;
    }
    // 0x800B10A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B10A8: addiu       $t4, $sp, 0x8C
    ctx->r12 = ADD32(ctx->r29, 0X8C);
L_800B10AC:
    // 0x800B10AC: bnel        $a1, $t4, L_800B10C0
    if (ctx->r5 != ctx->r12) {
        // 0x800B10B0: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_800B10C0;
    }
    goto skip_2;
    // 0x800B10B0: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    skip_2:
    // 0x800B10B4: b           L_800B10D0
    // 0x800B10B8: lbu         $v0, 0x15($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15);
        goto L_800B10D0;
    // 0x800B10B8: lbu         $v0, 0x15($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15);
L_800B10BC:
    // 0x800B10BC: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_800B10C0:
    // 0x800B10C0: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    // 0x800B10C4: bnel        $at, $zero, L_800B0F64
    if (ctx->r1 != 0) {
        // 0x800B10C8: lbu         $v0, 0x15($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X15);
            goto L_800B0F64;
    }
    goto skip_3;
    // 0x800B10C8: lbu         $v0, 0x15($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X15);
    skip_3:
L_800B10CC:
    // 0x800B10CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B10D0:
    // 0x800B10D0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800B10D4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B10D8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800B10DC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800B10E0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800B10E4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800B10E8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800B10EC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800B10F0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800B10F4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800B10F8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800B10FC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800B1100: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800B1104: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800B1108: jr          $ra
    // 0x800B110C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800B110C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void _chtrashcompactor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861E8: syscall     288
    recomp_syscall_handler(rdram, ctx, 0x800861E8);
    return;
    // 0x800861EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800CF87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF87C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800CF880: jr          $ra
    // 0x800CF884: lw          $v0, -0x51A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A0);
    return;
    // 0x800CF884: lw          $v0, -0x51A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A0);
;}
RECOMP_FUNC void func_800C670C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C670C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C6710: lwc1        $f4, 0x58AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X58AC);
    // 0x800C6714: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800C6718: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800C671C: nop

    // 0x800C6720: bc1fl       L_800C6734
    if (!c1cs) {
        // 0x800C6724: lbu         $v0, 0x8F($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X8F);
            goto L_800C6734;
    }
    goto skip_0;
    // 0x800C6724: lbu         $v0, 0x8F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8F);
    skip_0:
    // 0x800C6728: jr          $ra
    // 0x800C672C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C672C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C6730: lbu         $v0, 0x8F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8F);
L_800C6734:
    // 0x800C6734: jr          $ra
    // 0x800C6738: nop

    return;
    // 0x800C6738: nop

;}
RECOMP_FUNC void func_80109F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109F08: lhu         $t6, 0x66($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X66);
    // 0x80109F0C: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80109F10: jr          $ra
    // 0x80109F14: sh          $t7, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r15;
    return;
    // 0x80109F14: sh          $t7, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void idglowa_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: jr          $ra
    // 0x808000E4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    return;
    // 0x808000E4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
;}
RECOMP_FUNC void _bareact_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F88: syscall     145
    recomp_syscall_handler(rdram, ctx, 0x80084F88);
    return;
    // 0x80084F8C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _sukickball_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B18: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089B18);
    return;
    // 0x80089B1C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_800A106C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A106C: lw          $v0, 0x150($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X150);
    // 0x800A1070: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A1074: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A1078: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A107C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800A1080: lw          $v0, 0x150($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X150);
    // 0x800A1084: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A1088: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800A108C: lw          $t6, 0x150($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X150);
    // 0x800A1090: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    // 0x800A1094: lw          $t7, 0x150($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X150);
    // 0x800A1098: jr          $ra
    // 0x800A109C: swc1        $f14, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x800A109C: swc1        $f14, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void _bsmumstill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838D0: syscall     80
    recomp_syscall_handler(rdram, ctx, 0x800838D0);
    return;
    // 0x800838D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808001FC_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800200: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800204: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080020C: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    // 0x80800210: addiu       $a1, $zero, 0x276
    ctx->r5 = ADD32(0, 0X276);
    // 0x80800214: jal         0x8008CCBC
    // 0x80800218: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800218: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_0:
    // 0x8080021C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800220: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080022C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800230: jal         0x8009FFD8
    // 0x80800234: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800234: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x8009B9B0
    // 0x80800240: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800240: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    // 0x8080024C: jal         0x8009DE38
    // 0x80800250: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_3;
    // 0x80800250: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080025C: jal         0x80098140
    // 0x80800260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_4;
    // 0x80800260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800268: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080026C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800270: jr          $ra
    // 0x80800274: nop

    return;
    // 0x80800274: nop

;}
RECOMP_FUNC void func_808001B8_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808001BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808001C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808001C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808001CC: jal         0x80800AD8
    // 0x808001D0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80800AD8_chfactorytoxiccloud(rdram, ctx);
        goto after_0;
    // 0x808001D0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_0:
    // 0x808001D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001D8: jal         0x808000F0
    // 0x808001DC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_808000F0_chfactorytoxiccloud(rdram, ctx);
        goto after_1;
    // 0x808001DC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x808001E0: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001E4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_808001F8;
    }
    // 0x808001E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808001E8: jal         0x80102424
    // 0x808001EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808001EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808001F0: b           L_80800220
    // 0x808001F4: lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X78);
        goto L_80800220;
    // 0x808001F4: lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X78);
L_808001F8:
    // 0x808001F8: lw          $t6, 0x64($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X64);
    // 0x808001FC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800200: bgezl       $t8, L_80800220
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800204: lw          $v1, 0x78($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X78);
            goto L_80800220;
    }
    goto skip_0;
    // 0x80800204: lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X78);
    skip_0:
    // 0x80800208: jal         0x800CF494
    // 0x8080020C: nop

    func_800CF494(rdram, ctx);
        goto after_3;
    // 0x8080020C: nop

    after_3:
    // 0x80800210: lbu         $t9, 0x65($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X65);
    // 0x80800214: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80800218: sb          $t0, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r8;
    // 0x8080021C: lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X78);
L_80800220:
    // 0x80800220: sll         $t1, $v1, 29
    ctx->r9 = S32(ctx->r3 << 29);
    // 0x80800224: srl         $v1, $t1, 31
    ctx->r3 = S32(U32(ctx->r9) >> 31);
    // 0x80800228: bnel        $v1, $zero, L_80800A24
    if (ctx->r3 != 0) {
        // 0x8080022C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A24;
    }
    goto skip_1;
    // 0x8080022C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800230: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
    // 0x80800234: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800238: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8080023C: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x80800240: beq         $at, $zero, L_80800968
    if (ctx->r1 == 0) {
        // 0x80800244: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80800968;
    }
    // 0x80800244: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80800248: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8080024C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X13E0) << 16);
    // 0x80800250: addu        $at, $at, $t4
    gpr jr_addend_80800258 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80800254: lw          $t4, 0x13E0($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2300, 0X13E0));
    // 0x80800258: jr          $t4
    // 0x8080025C: nop

    switch (jr_addend_80800258 >> 2) {
        case 0: goto L_80800260; break;
        case 1: goto L_808003C8; break;
        case 2: goto L_80800588; break;
        case 3: goto L_80800730; break;
        case 4: goto L_8080094C; break;
        default: switch_error(__func__, 0x80800258, 0x808013E0);
    }
    // 0x8080025C: nop

L_80800260:
    // 0x80800260: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800264: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800268: jal         0x800D91EC
    // 0x8080026C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D91EC(rdram, ctx);
        goto after_4;
    // 0x8080026C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_4:
    // 0x80800270: beq         $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x80800274: lui         $a2, 0x3E99
        ctx->r6 = S32(0X3E99 << 16);
            goto L_808002C4;
    }
    // 0x80800274: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080027C: jal         0x80089C98
    // 0x80800280: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800280: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_5:
    // 0x80800284: lw          $t5, 0x64($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X64);
    // 0x80800288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080028C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800290: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80800294: bgez        $t7, L_808002B0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800298: swc1        $f4, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->f4.u32l;
            goto L_808002B0;
    }
    // 0x80800298: swc1        $f4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f4.u32l;
    // 0x8080029C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A0: jal         0x80102424
    // 0x808002A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808002A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808002A8: b           L_808003BC
    // 0x808002AC: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
        goto L_808003BC;
    // 0x808002AC: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_808002B0:
    // 0x808002B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002B4: jal         0x80102424
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808002B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808002BC: b           L_808003BC
    // 0x808002C0: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
        goto L_808003BC;
    // 0x808002C0: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_808002C4:
    // 0x808002C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002D0: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x808002D4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808002D8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808002DC: jal         0x800F10B4
    // 0x808002E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808002E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x808002E4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808002E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002F0: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x808002F4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808002F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808002FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800300: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800304: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80800308: nop

    // 0x8080030C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800310: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80800314: nop

    // 0x80800318: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x8080031C: beql        $a1, $zero, L_8080036C
    if (ctx->r5 == 0) {
        // 0x80800320: mfc1        $a1, $f16
        ctx->r5 = (int32_t)ctx->f16.u32l;
            goto L_8080036C;
    }
    goto skip_2;
    // 0x80800320: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x80800324: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080032C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800330: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80800334: nop

    // 0x80800338: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8080033C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80800340: nop

    // 0x80800344: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80800348: bne         $a1, $zero, L_80800360
    if (ctx->r5 != 0) {
        // 0x8080034C: nop
    
            goto L_80800360;
    }
    // 0x8080034C: nop

    // 0x80800350: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800354: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800358: b           L_80800378
    // 0x8080035C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80800378;
    // 0x8080035C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80800360:
    // 0x80800360: b           L_80800378
    // 0x80800364: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80800378;
    // 0x80800364: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800368: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
L_8080036C:
    // 0x8080036C: nop

    // 0x80800370: bltz        $a1, L_80800360
    if (SIGNED(ctx->r5) < 0) {
        // 0x80800374: nop
    
            goto L_80800360;
    }
    // 0x80800374: nop

L_80800378:
    // 0x80800378: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080037C: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x80800380: jal         0x80089C98
    // 0x80800384: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800384: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_9:
    // 0x80800388: lbu         $t1, 0x65($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X65);
    // 0x8080038C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800394: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80800398: sb          $t2, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r10;
    // 0x8080039C: jal         0x8010A590
    // 0x808003A0: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
    func_8010A590(rdram, ctx);
        goto after_10;
    // 0x808003A0: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
    after_10:
    // 0x808003A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808003A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003AC: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808003B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808003B4: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x808003B8: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_808003BC:
    // 0x808003BC: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x808003C0: b           L_80800968
    // 0x808003C4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80800968;
    // 0x808003C4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_808003C8:
    // 0x808003C8: lw          $t4, 0x64($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X64);
    // 0x808003CC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x808003D0: bgez        $t6, L_808003E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808003D4: nop
    
            goto L_808003E8;
    }
    // 0x808003D4: nop

    // 0x808003D8: jal         0x808010B8
    // 0x808003DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808010B8_chfactorytoxiccloud(rdram, ctx);
        goto after_11;
    // 0x808003DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808003E0: b           L_80800520
    // 0x808003E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80800520;
    // 0x808003E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808003E8:
    // 0x808003E8: jal         0x800D8FF8
    // 0x808003EC: nop

    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x808003EC: nop

    after_12:
    // 0x808003F0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808003F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003F8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808003FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800400: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80800404: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800408: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080040C: jal         0x800F15F8
    // 0x80800410: nop

    func_800F15F8(rdram, ctx);
        goto after_13;
    // 0x80800410: nop

    after_13:
    // 0x80800414: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80800418: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x8080041C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800424: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80800428: jal         0x80102BAC
    // 0x8080042C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_80102BAC(rdram, ctx);
        goto after_14;
    // 0x8080042C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_14:
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800434: addiu       $a1, $zero, 0x125
    ctx->r5 = ADD32(0, 0X125);
    // 0x80800438: jal         0x80801164
    // 0x8080043C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80801164_chfactorytoxiccloud(rdram, ctx);
        goto after_15;
    // 0x8080043C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_15:
    // 0x80800440: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80800444: bne         $t7, $zero, L_8080046C
    if (ctx->r15 != 0) {
        // 0x80800448: nop
    
            goto L_8080046C;
    }
    // 0x80800448: nop

    // 0x8080044C: jal         0x800DC0C0
    // 0x80800450: nop

    func_800DC0C0(rdram, ctx);
        goto after_16;
    // 0x80800450: nop

    after_16:
    // 0x80800454: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2300, 0X13F4) << 16);
    // 0x80800458: lwc1        $f18, 0x13F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2300, 0X13F4));
    // 0x8080045C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800460: nop

    // 0x80800464: bc1fl       L_808004DC
    if (!c1cs) {
        // 0x80800468: lw          $v0, 0x70($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X70);
            goto L_808004DC;
    }
    goto skip_3;
    // 0x80800468: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    skip_3:
L_8080046C:
    // 0x8080046C: jal         0x800DC0C0
    // 0x80800470: nop

    func_800DC0C0(rdram, ctx);
        goto after_17;
    // 0x80800470: nop

    after_17:
    // 0x80800474: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080047C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800480: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800484: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800488: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x8080048C: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x80800490: nop

    // 0x80800494: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
L_80800498:
    // 0x80800498: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x8080049C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004A0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808004A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004A8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808004AC: jal         0x8008A4E8
    // 0x808004B0: nop

    _subaddieDll_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x808004B0: nop

    after_18:
    // 0x808004B4: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x808004B8: lw          $v1, 0x64($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X64);
            goto L_808004C8;
    }
    // 0x808004B8: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x808004BC: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808004C0: b           L_808004D8
    // 0x808004C4: swc1        $f16, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f16.u32l;
        goto L_808004D8;
    // 0x808004C4: swc1        $f16, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f16.u32l;
L_808004C8:
    // 0x808004C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808004CC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808004D0: bnel        $v1, $at, L_80800498
    if (ctx->r3 != ctx->r1) {
        // 0x808004D4: lwc1        $f8, 0x24($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
            goto L_80800498;
    }
    goto skip_4;
    // 0x808004D4: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    skip_4:
L_808004D8:
    // 0x808004D8: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
L_808004DC:
    // 0x808004DC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808004E0: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x808004E4: srl         $t0, $a2, 26
    ctx->r8 = S32(U32(ctx->r6) >> 26);
    // 0x808004E8: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x808004EC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x808004F0: jal         0x800CC338
    // 0x808004F4: addiu       $a2, $t0, -0x1
    ctx->r6 = ADD32(ctx->r8, -0X1);
    func_800CC338(rdram, ctx);
        goto after_19;
    // 0x808004F4: addiu       $a2, $t0, -0x1
    ctx->r6 = ADD32(ctx->r8, -0X1);
    after_19:
    // 0x808004F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808004FC: beql        $v0, $at, L_80800520
    if (ctx->r2 == ctx->r1) {
        // 0x80800500: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800520;
    }
    goto skip_5;
    // 0x80800500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
    // 0x80800504: jal         0x808012C4
    // 0x80800508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808012C4_chfactorytoxiccloud(rdram, ctx);
        goto after_20;
    // 0x80800508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x8080050C: beq         $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x80800510: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080051C;
    }
    // 0x80800510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800514: jal         0x80102424
    // 0x80800518: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_21;
    // 0x80800518: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_21:
L_8080051C:
    // 0x8080051C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800520:
    // 0x80800520: jal         0x80800FCC
    // 0x80800524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800FCC_chfactorytoxiccloud(rdram, ctx);
        goto after_22;
    // 0x80800524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80800528: jal         0x800D8FF8
    // 0x8080052C: nop

    func_800D8FF8(rdram, ctx);
        goto after_23;
    // 0x8080052C: nop

    after_23:
    // 0x80800530: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800534: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800538: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080053C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800540: lwc1        $f18, 0x34($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80800544: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800548: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080054C: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800550: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800554: jal         0x800F15F8
    // 0x80800558: nop

    func_800F15F8(rdram, ctx);
        goto after_24;
    // 0x80800558: nop

    after_24:
    // 0x8080055C: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800560: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x80800564: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800568: nop

    // 0x8080056C: bc1fl       L_8080057C
    if (!c1cs) {
        // 0x80800570: lhu         $v0, 0x72($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X72);
            goto L_8080057C;
    }
    goto skip_6;
    // 0x80800570: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
    skip_6:
    // 0x80800574: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x80800578: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_8080057C:
    // 0x8080057C: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x80800580: b           L_80800968
    // 0x80800584: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80800968;
    // 0x80800584: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80800588:
    // 0x80800588: lw          $t2, 0x64($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X64);
    // 0x8080058C: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x80800590: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80800594: bgez        $t4, L_808005AC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800598: nop
    
            goto L_808005AC;
    }
    // 0x80800598: nop

    // 0x8080059C: jal         0x808010B8
    // 0x808005A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808010B8_chfactorytoxiccloud(rdram, ctx);
        goto after_25;
    // 0x808005A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x808005A4: b           L_8080066C
    // 0x808005A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8080066C;
    // 0x808005A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808005AC:
    // 0x808005AC: jal         0x800F1DF4
    // 0x808005B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800F1DF4(rdram, ctx);
        goto after_26;
    // 0x808005B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_26:
    // 0x808005B4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808005B8: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x808005BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808005C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808005C8: jal         0x80102BAC
    // 0x808005CC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    func_80102BAC(rdram, ctx);
        goto after_27;
    // 0x808005CC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_27:
    // 0x808005D0: jal         0x800D8FF8
    // 0x808005D4: nop

    func_800D8FF8(rdram, ctx);
        goto after_28;
    // 0x808005D4: nop

    after_28:
    // 0x808005D8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808005DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005E0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808005E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005E8: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x808005EC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808005F0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808005F4: jal         0x800F15F8
    // 0x808005F8: nop

    func_800F15F8(rdram, ctx);
        goto after_29;
    // 0x808005F8: nop

    after_29:
    // 0x808005FC: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80800600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800604: addiu       $a1, $zero, 0x125
    ctx->r5 = ADD32(0, 0X125);
    // 0x80800608: jal         0x80801164
    // 0x8080060C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80801164_chfactorytoxiccloud(rdram, ctx);
        goto after_30;
    // 0x8080060C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_30:
    // 0x80800610: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x80800614: beq         $t5, $zero, L_80800624
    if (ctx->r13 == 0) {
        // 0x80800618: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800624;
    }
    // 0x80800618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080061C: jal         0x80102424
    // 0x80800620: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x80800620: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_31:
L_80800624:
    // 0x80800624: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    // 0x80800628: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8080062C: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80800630: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x80800634: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80800638: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8080063C: jal         0x800CC338
    // 0x80800640: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_32;
    // 0x80800640: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_32:
    // 0x80800644: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800648: beql        $v0, $at, L_80800660
    if (ctx->r2 == ctx->r1) {
        // 0x8080064C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800660;
    }
    goto skip_7;
    // 0x8080064C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_7:
    // 0x80800650: jal         0x808012C4
    // 0x80800654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808012C4_chfactorytoxiccloud(rdram, ctx);
        goto after_33;
    // 0x80800654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x80800658: bne         $v0, $zero, L_80800668
    if (ctx->r2 != 0) {
        // 0x8080065C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800668;
    }
    // 0x8080065C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800660:
    // 0x80800660: jal         0x80102424
    // 0x80800664: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_34;
    // 0x80800664: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
L_80800668:
    // 0x80800668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080066C:
    // 0x8080066C: jal         0x80800FCC
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800FCC_chfactorytoxiccloud(rdram, ctx);
        goto after_35;
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x80800674: lwc1        $f18, 0x34($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80800678: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8080067C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800680: nop

    // 0x80800684: bc1f        L_808006D0
    if (!c1cs) {
        // 0x80800688: nop
    
            goto L_808006D0;
    }
    // 0x80800688: nop

    // 0x8080068C: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800690: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800694: nop

    // 0x80800698: bc1f        L_808006D0
    if (!c1cs) {
        // 0x8080069C: nop
    
            goto L_808006D0;
    }
    // 0x8080069C: nop

    // 0x808006A0: jal         0x800D8FF8
    // 0x808006A4: nop

    func_800D8FF8(rdram, ctx);
        goto after_36;
    // 0x808006A4: nop

    after_36:
    // 0x808006A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808006AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006B0: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808006B4: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808006B8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808006BC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808006C0: jal         0x800F15F8
    // 0x808006C4: nop

    func_800F15F8(rdram, ctx);
        goto after_37;
    // 0x808006C4: nop

    after_37:
    // 0x808006C8: b           L_80800720
    // 0x808006CC: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
        goto L_80800720;
    // 0x808006CC: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_808006D0:
    // 0x808006D0: jal         0x800D8FF8
    // 0x808006D4: nop

    func_800D8FF8(rdram, ctx);
        goto after_38;
    // 0x808006D4: nop

    after_38:
    // 0x808006D8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808006DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808006E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808006E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006E8: lwc1        $f16, 0x34($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X34);
    // 0x808006EC: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808006F0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808006F4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808006F8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808006FC: jal         0x800F15F8
    // 0x80800700: nop

    func_800F15F8(rdram, ctx);
        goto after_39;
    // 0x80800700: nop

    after_39:
    // 0x80800704: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800708: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8080070C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800710: nop

    // 0x80800714: bc1fl       L_80800724
    if (!c1cs) {
        // 0x80800718: lhu         $v0, 0x72($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X72);
            goto L_80800724;
    }
    goto skip_8;
    // 0x80800718: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
    skip_8:
    // 0x8080071C: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
L_80800720:
    // 0x80800720: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_80800724:
    // 0x80800724: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800728: b           L_80800968
    // 0x8080072C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800968;
    // 0x8080072C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80800730:
    // 0x80800730: lw          $t8, 0x64($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X64);
    // 0x80800734: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800738: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x8080073C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80800740: bgez        $t0, L_80800758
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800744: nop
    
            goto L_80800758;
    }
    // 0x80800744: nop

    // 0x80800748: jal         0x808010B8
    // 0x8080074C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808010B8_chfactorytoxiccloud(rdram, ctx);
        goto after_40;
    // 0x8080074C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_40:
    // 0x80800750: b           L_80800858
    // 0x80800754: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80800858;
    // 0x80800754: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800758:
    // 0x80800758: jal         0x800EEAD4
    // 0x8080075C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_41;
    // 0x8080075C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_41:
    // 0x80800760: jal         0x800D8FF8
    // 0x80800764: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_42;
    // 0x80800764: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_42:
    // 0x80800768: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080076C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800770: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800774: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080077C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80800780: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800784: jal         0x800EFB8C
    // 0x80800788: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    func_800EFB8C(rdram, ctx);
        goto after_43;
    // 0x80800788: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    after_43:
    // 0x8080078C: jal         0x800D8FF8
    // 0x80800790: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_44;
    // 0x80800790: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_44:
    // 0x80800794: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800798: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080079C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808007A0: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808007A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007AC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808007B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808007B4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808007B8: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    // 0x808007BC: bc1fl       L_808007CC
    if (!c1cs) {
        // 0x808007C0: lwc1        $f8, 0x5C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_808007CC;
    }
    goto skip_9;
    // 0x808007C0: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    skip_9:
    // 0x808007C4: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x808007C8: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
L_808007CC:
    // 0x808007CC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808007D0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808007D4: nop

    // 0x808007D8: bc1fl       L_80800820
    if (!c1cs) {
        // 0x808007DC: swc1        $f4, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
            goto L_80800820;
    }
    goto skip_10;
    // 0x808007DC: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    skip_10:
    // 0x808007E0: jal         0x800EFB24
    // 0x808007E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFB24(rdram, ctx);
        goto after_45;
    // 0x808007E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_45:
    // 0x808007E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007F0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808007F4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808007F8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808007FC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800800: jal         0x800EF334
    // 0x80800804: nop

    func_800EF334(rdram, ctx);
        goto after_46;
    // 0x80800804: nop

    after_46:
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x800EF04C
    // 0x80800810: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EF04C(rdram, ctx);
        goto after_47;
    // 0x80800810: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_47:
    // 0x80800814: b           L_80800828
    // 0x80800818: nop

        goto L_80800828;
    // 0x80800818: nop

    // 0x8080081C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_80800820:
    // 0x80800820: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800824: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
L_80800828:
    // 0x80800828: jal         0x800F54E4
    // 0x8080082C: nop

    func_800F54E4(rdram, ctx);
        goto after_48;
    // 0x8080082C: nop

    after_48:
    // 0x80800830: jal         0x800F5F24
    // 0x80800834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5F24(rdram, ctx);
        goto after_49;
    // 0x80800834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_49:
    // 0x80800838: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8080083C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x80800840: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800848: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080084C: jal         0x80102BAC
    // 0x80800850: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    func_80102BAC(rdram, ctx);
        goto after_50;
    // 0x80800850: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_50:
    // 0x80800854: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800858:
    // 0x80800858: jal         0x80102424
    // 0x8080085C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_51;
    // 0x8080085C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_51:
    // 0x80800860: lw          $t1, 0x64($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X64);
    // 0x80800864: sll         $t3, $t1, 12
    ctx->r11 = S32(ctx->r9 << 12);
    // 0x80800868: bltzl       $t3, L_80800888
    if (SIGNED(ctx->r11) < 0) {
        // 0x8080086C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800888;
    }
    goto skip_11;
    // 0x8080086C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_11:
    // 0x80800870: jal         0x800CF2D4
    // 0x80800874: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800CF2D4(rdram, ctx);
        goto after_52;
    // 0x80800874: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_52:
    // 0x80800878: lbu         $t5, 0x65($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X65);
    // 0x8080087C: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x80800880: sb          $t6, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r14;
    // 0x80800884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800888:
    // 0x80800888: jal         0x80800FCC
    // 0x8080088C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800FCC_chfactorytoxiccloud(rdram, ctx);
        goto after_53;
    // 0x8080088C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_53:
    // 0x80800890: lwc1        $f8, 0x34($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80800894: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80800898: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080089C: nop

    // 0x808008A0: bc1f        L_808008EC
    if (!c1cs) {
        // 0x808008A4: nop
    
            goto L_808008EC;
    }
    // 0x808008A4: nop

    // 0x808008A8: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808008AC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808008B0: nop

    // 0x808008B4: bc1f        L_808008EC
    if (!c1cs) {
        // 0x808008B8: nop
    
            goto L_808008EC;
    }
    // 0x808008B8: nop

    // 0x808008BC: jal         0x800D8FF8
    // 0x808008C0: nop

    func_800D8FF8(rdram, ctx);
        goto after_54;
    // 0x808008C0: nop

    after_54:
    // 0x808008C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808008C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008CC: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808008D0: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808008D4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808008D8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808008DC: jal         0x800F15F8
    // 0x808008E0: nop

    func_800F15F8(rdram, ctx);
        goto after_55;
    // 0x808008E0: nop

    after_55:
    // 0x808008E4: b           L_8080093C
    // 0x808008E8: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
        goto L_8080093C;
    // 0x808008E8: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
L_808008EC:
    // 0x808008EC: jal         0x800D8FF8
    // 0x808008F0: nop

    func_800D8FF8(rdram, ctx);
        goto after_56;
    // 0x808008F0: nop

    after_56:
    // 0x808008F4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808008F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800900: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800904: lwc1        $f6, 0x34($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80800908: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8080090C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800910: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800914: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800918: jal         0x800F15F8
    // 0x8080091C: nop

    func_800F15F8(rdram, ctx);
        goto after_57;
    // 0x8080091C: nop

    after_57:
    // 0x80800920: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800924: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x80800928: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8080092C: nop

    // 0x80800930: bc1fl       L_80800940
    if (!c1cs) {
        // 0x80800934: lhu         $v0, 0x72($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X72);
            goto L_80800940;
    }
    goto skip_12;
    // 0x80800934: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
    skip_12:
    // 0x80800938: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
L_8080093C:
    // 0x8080093C: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_80800940:
    // 0x80800940: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800944: b           L_80800968
    // 0x80800948: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80800968;
    // 0x80800948: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8080094C:
    // 0x8080094C: bne         $v1, $zero, L_80800968
    if (ctx->r3 != 0) {
        // 0x80800950: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800968;
    }
    // 0x80800950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800954: jal         0x80102424
    // 0x80800958: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_58;
    // 0x80800958: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_58:
    // 0x8080095C: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
    // 0x80800960: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80800964: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80800968:
    // 0x80800968: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080096C: beql        $v0, $at, L_80800A24
    if (ctx->r2 == ctx->r1) {
        // 0x80800970: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A24;
    }
    goto skip_13;
    // 0x80800970: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x80800974: lw          $t9, 0x7C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X7C);
    // 0x80800978: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080097C: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80800980: bgezl       $t1, L_80800A24
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800984: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A24;
    }
    goto skip_14;
    // 0x80800984: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_14:
    // 0x80800988: jal         0x80100094
    // 0x8080098C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_59;
    // 0x8080098C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_59:
    // 0x80800990: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800994: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800998: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8080099C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808009A0:
    // 0x808009A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808009A4: jal         0x800D91EC
    // 0x808009A8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800D91EC(rdram, ctx);
        goto after_60;
    // 0x808009A8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_60:
    // 0x808009AC: beql        $v0, $zero, L_80800A00
    if (ctx->r2 == 0) {
        // 0x808009B0: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_80800A00;
    }
    goto skip_15;
    // 0x808009B0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x808009B4: jal         0x800DC0C0
    // 0x808009B8: nop

    func_800DC0C0(rdram, ctx);
        goto after_61;
    // 0x808009B8: nop

    after_61:
    // 0x808009BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808009C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808009C4: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2300, 0X148C) << 16);
    // 0x808009C8: addiu       $t2, $t2, 0x148C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2300, 0X148C));
    // 0x808009CC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808009D0: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808009DC: bc1fl       L_808009F4
    if (!c1cs) {
        // 0x808009E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808009F4;
    }
    goto skip_16;
    // 0x808009E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_16:
    // 0x808009E4: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x808009E8: jal         0x800BBCB8
    // 0x808009EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800BBCB8(rdram, ctx);
        goto after_62;
    // 0x808009EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_62:
    // 0x808009F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808009F4:
    // 0x808009F4: jal         0x80800A34
    // 0x808009F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800A34_chfactorytoxiccloud(rdram, ctx);
        goto after_63;
    // 0x808009F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_63:
    // 0x808009FC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800A00:
    // 0x80800A00: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800A04: addiu       $at, $zero, 0x144
    ctx->r1 = ADD32(0, 0X144);
    // 0x80800A08: addiu       $t4, $t3, 0x24
    ctx->r12 = ADD32(ctx->r11, 0X24);
    // 0x80800A0C: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    // 0x80800A10: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800A14: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80800A18: bne         $v0, $at, L_808009A0
    if (ctx->r2 != ctx->r1) {
        // 0x80800A1C: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_808009A0;
    }
    // 0x80800A1C: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x80800A20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A24:
    // 0x80800A24: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A28: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800A2C: jr          $ra
    // 0x80800A30: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800A30: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void boot___osEnqueueThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800A79D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A79D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A79D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A79DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A79E0: jal         0x800FE4E4
    // 0x800A79E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800FE4E4(rdram, ctx);
        goto after_0;
    // 0x800A79E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A79E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A79EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A79F0: addiu       $v0, $v0, 0x7630
    ctx->r2 = ADD32(ctx->r2, 0X7630);
    // 0x800A79F4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800A79F8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A79FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A7A00: sb          $t6, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r14;
    // 0x800A7A04: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x800A7A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7A0C: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x800A7A10: jr          $ra
    // 0x800A7A14: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
    return;
    // 0x800A7A14: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void _basub_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851E8: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851E8);
    return;
    // 0x800851EC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_801013A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801013A8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801013AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801013B0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x801013B4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x801013B8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x801013BC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x801013C0: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x801013C4: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x801013C8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x801013CC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x801013D0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801013D4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801013D8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801013DC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801013E0: jal         0x800BE3F8
    // 0x801013E4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    func_800BE3F8(rdram, ctx);
        goto after_0;
    // 0x801013E4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x801013E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801013EC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x801013F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801013F4: beq         $t6, $zero, L_80101488
    if (ctx->r14 == 0) {
        // 0x801013F8: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80101488;
    }
    // 0x801013F8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x801013FC: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
L_80101400:
    // 0x80101400: jal         0x800E9E88
    // 0x80101404: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x80101404: nop

    after_1:
    // 0x80101408: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010140C: jal         0x800E9EB4
    // 0x80101410: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x80101410: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_2:
    // 0x80101414: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80101418: beq         $at, $zero, L_80101474
    if (ctx->r1 == 0) {
        // 0x8010141C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80101474;
    }
    // 0x8010141C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80101420: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
L_80101424:
    // 0x80101424: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80101428: beql        $t8, $zero, L_80101468
    if (ctx->r24 == 0) {
        // 0x8010142C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80101468;
    }
    goto skip_0;
    // 0x8010142C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x80101430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80101434: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80101438: lhu         $t9, 0x18($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X18);
    // 0x8010143C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80101440: beql        $t0, $zero, L_80101468
    if (ctx->r8 == 0) {
        // 0x80101444: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80101468;
    }
    goto skip_1;
    // 0x80101444: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x80101448: jal         0x8010114C
    // 0x8010144C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8010114C(rdram, ctx);
        goto after_3;
    // 0x8010144C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x80101450: blez        $v0, L_80101464
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80101454: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80101464;
    }
    // 0x80101454: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80101458: bnel        $s2, $zero, L_80101468
    if (ctx->r18 != 0) {
        // 0x8010145C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80101468;
    }
    goto skip_2;
    // 0x8010145C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x80101460: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80101464:
    // 0x80101464: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80101468:
    // 0x80101468: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8010146C: bnel        $at, $zero, L_80101424
    if (ctx->r1 != 0) {
        // 0x80101470: lw          $t7, 0x8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X8);
            goto L_80101424;
    }
    goto skip_3;
    // 0x80101470: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    skip_3:
L_80101474:
    // 0x80101474: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
    // 0x80101478: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8010147C: bne         $a0, $zero, L_80101400
    if (ctx->r4 != 0) {
        // 0x80101480: nop
    
            goto L_80101400;
    }
    // 0x80101480: nop

    // 0x80101484: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
L_80101488:
    // 0x80101488: jal         0x800BDC44
    // 0x8010148C: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    func_800BDC44(rdram, ctx);
        goto after_4;
    // 0x8010148C: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x80101490: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80101494: jal         0x800E9E88
    // 0x80101498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E9E88(rdram, ctx);
        goto after_5;
    // 0x80101498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8010149C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801014A0: jal         0x800E9EB4
    // 0x801014A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_6;
    // 0x801014A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x801014A8: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x801014AC: beq         $at, $zero, L_80101574
    if (ctx->r1 == 0) {
        // 0x801014B0: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_80101574;
    }
    // 0x801014B0: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x801014B4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801014B8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801014BC: nop

    // 0x801014C0: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
L_801014C4:
    // 0x801014C4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x801014C8: beql        $t2, $zero, L_80101568
    if (ctx->r10 == 0) {
        // 0x801014CC: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80101568;
    }
    goto skip_4;
    // 0x801014CC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_4:
    // 0x801014D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801014D4: lhu         $t3, 0x18($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X18);
    // 0x801014D8: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x801014DC: beql        $t4, $zero, L_80101568
    if (ctx->r12 == 0) {
        // 0x801014E0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80101568;
    }
    goto skip_5;
    // 0x801014E0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_5:
    // 0x801014E4: jal         0x80106790
    // 0x801014E8: nop

    func_80106790(rdram, ctx);
        goto after_7;
    // 0x801014E8: nop

    after_7:
    // 0x801014EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801014F0: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x801014F4: jal         0x800EEB40
    // 0x801014F8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800EEB40(rdram, ctx);
        goto after_8;
    // 0x801014F8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_8:
    // 0x801014FC: jal         0x800BDC5C
    // 0x80101500: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800BDC5C(rdram, ctx);
        goto after_9;
    // 0x80101500: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_9:
    // 0x80101504: jal         0x800BDC5C
    // 0x80101508: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    func_800BDC5C(rdram, ctx);
        goto after_10;
    // 0x80101508: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    after_10:
    // 0x8010150C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80101510: mtc1        $s6, $f10
    ctx->f10.u32l = ctx->r22;
    // 0x80101514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80101518: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010151C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80101520: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80101524: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80101528: nop

    // 0x8010152C: mul.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80101530: nop

    // 0x80101534: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80101538: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x8010153C: nop

    // 0x80101540: bc1f        L_80101564
    if (!c1cs) {
        // 0x80101544: nop
    
            goto L_80101564;
    }
    // 0x80101544: nop

    // 0x80101548: jal         0x8010108C
    // 0x8010154C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_8010108C(rdram, ctx);
        goto after_11;
    // 0x8010154C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_11:
    // 0x80101550: blezl       $s3, L_80101568
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80101554: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80101568;
    }
    goto skip_6;
    // 0x80101554: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_6:
    // 0x80101558: bnel        $s2, $zero, L_80101568
    if (ctx->r18 != 0) {
        // 0x8010155C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80101568;
    }
    goto skip_7;
    // 0x8010155C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_7:
    // 0x80101560: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_80101564:
    // 0x80101564: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80101568:
    // 0x80101568: sltu        $at, $s0, $s7
    ctx->r1 = ctx->r16 < ctx->r23 ? 1 : 0;
    // 0x8010156C: bnel        $at, $zero, L_801014C4
    if (ctx->r1 != 0) {
        // 0x80101570: lw          $t1, 0x8($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X8);
            goto L_801014C4;
    }
    goto skip_8;
    // 0x80101570: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    skip_8:
L_80101574:
    // 0x80101574: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80101578: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8010157C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80101580: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80101584: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80101588: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8010158C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80101590: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80101594: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80101598: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8010159C: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x801015A0: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x801015A4: jr          $ra
    // 0x801015A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801015A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801015AC: nop

;}
RECOMP_FUNC void _chlavaarchgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087040: syscall     497
    recomp_syscall_handler(rdram, ctx, 0x80087040);
    return;
    // 0x80087044: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800965E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800965E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800965E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800965E8: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800965EC: jal         0x800C67F8
    // 0x800965F0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C67F8(rdram, ctx);
        goto after_0;
    // 0x800965F0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800965F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800965F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800965FC: jr          $ra
    // 0x80096600: nop

    return;
    // 0x80096600: nop

;}
RECOMP_FUNC void func_80800D8C_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800DA0: jal         0x80800898
    // 0x80800DA4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_80800898_chnests(rdram, ctx);
        goto after_0;
    // 0x80800DA4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_0:
    // 0x80800DA8: beql        $v0, $zero, L_80800EC8
    if (ctx->r2 == 0) {
        // 0x80800DAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EC8;
    }
    goto skip_0;
    // 0x80800DAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800DB0: jal         0x800DF3E0
    // 0x80800DB4: nop

    func_800DF3E0(rdram, ctx);
        goto after_1;
    // 0x80800DB4: nop

    after_1:
    // 0x80800DB8: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x80800DBC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(752, 0X1124) << 16);
    // 0x80800DC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DC4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800DC8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800DCC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800DD0: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80800DD4: jal         0x800DF744
    // 0x80800DD8: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800DD8: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    after_2:
    // 0x80800DDC: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80800DE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE8: bne         $t8, $at, L_80800EBC
    if (ctx->r24 != ctx->r1) {
        // 0x80800DEC: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80800EBC;
    }
    // 0x80800DEC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800DF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DF4: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800DF8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800DFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800E00: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800E04: lbu         $t0, 0x7A($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E0C: andi        $t1, $t0, 0xFF3F
    ctx->r9 = ctx->r8 & 0XFF3F;
    // 0x80800E10: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80800E14: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
    // 0x80800E18: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800E1C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800E20: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800E24: jal         0x80089C98
    // 0x80800E28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800E28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E30: jal         0x801018A4
    // 0x80800E34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_801018A4(rdram, ctx);
        goto after_4;
    // 0x80800E34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800E38: jal         0x800DF3E0
    // 0x80800E3C: nop

    func_800DF3E0(rdram, ctx);
        goto after_5;
    // 0x80800E3C: nop

    after_5:
    // 0x80800E40: lw          $t3, 0x6C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X6C);
    // 0x80800E44: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(752, 0X1124) << 16);
    // 0x80800E48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E4C: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80800E50: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80800E54: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80800E58: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80800E5C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80800E60: jal         0x800DF744
    // 0x80800E64: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x80800E64: lbu         $a0, 0x1124($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(752, 0X1124));
    after_6:
    // 0x80800E68: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800E6C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E74: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x80800E78: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80800E7C: sb          $t8, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r24;
    // 0x80800E80: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800E84: jal         0x80089C98
    // 0x80800E88: subu        $a1, $t0, $t9
    ctx->r5 = SUB32(ctx->r8, ctx->r25);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800E88: subu        $a1, $t0, $t9
    ctx->r5 = SUB32(ctx->r8, ctx->r25);
    after_7:
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E90: jal         0x801018A4
    // 0x80800E94: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_801018A4(rdram, ctx);
        goto after_8;
    // 0x80800E94: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800E98: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800EA4: andi        $t2, $t1, 0xFF3F
    ctx->r10 = ctx->r9 & 0XFF3F;
    // 0x80800EA8: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x80800EAC: jal         0x80089C98
    // 0x80800EB0: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800EB0: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
    after_9:
    // 0x80800EB4: b           L_80800EC8
    // 0x80800EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EC8;
    // 0x80800EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EBC:
    // 0x80800EBC: jal         0x801018A4
    // 0x80800EC0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_801018A4(rdram, ctx);
        goto after_10;
    // 0x80800EC0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80800EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EC8:
    // 0x80800EC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800ECC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800ED0: jr          $ra
    // 0x80800ED4: nop

    return;
    // 0x80800ED4: nop

;}
RECOMP_FUNC void func_80800000_chcrackarchwall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800008: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: beq         $a1, $at, L_8080005C
    if (ctx->r5 == ctx->r1) {
        // 0x80800018: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8080005C;
    }
    // 0x80800018: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080001C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800020: beq         $a1, $at, L_80800084
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(1888, 0XF0) << 16);
            goto L_80800084;
    }
    // 0x80800024: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1888, 0XF0) << 16);
    // 0x80800028: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080002C: bne         $a1, $at, L_808000BC
    if (ctx->r5 != ctx->r1) {
        // 0x80800030: nop
    
            goto L_808000BC;
    }
    // 0x80800030: nop

    // 0x80800034: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x80800038: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800040: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800044: beql        $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x80800048: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808000C8;
    }
    goto skip_0;
    // 0x80800048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080004C: jal         0x800FFAB0
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800054: b           L_808000C8
    // 0x80800058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x80800058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080005C:
    // 0x8080005C: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800060: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x80800064: jal         0x800DA544
    // 0x80800068: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800068: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800074: jal         0x80086670
    // 0x80800078: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800078: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_3:
    // 0x8080007C: b           L_808000C8
    // 0x80800080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x80800080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800084:
    // 0x80800084: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800088: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8080008C: addiu       $t8, $t8, 0xF0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1888, 0XF0));
    // 0x80800090: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800094: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800098: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080009C: jal         0x800BABB8
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808000A4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1888, 0X130) << 16);
    // 0x808000A8: addiu       $a1, $a1, 0x130
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1888, 0X130));
    // 0x808000AC: jal         0x800C4AF0
    // 0x808000B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800C4AF0(rdram, ctx);
        goto after_5;
    // 0x808000B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808000B4: b           L_808000C8
    // 0x808000B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x808000B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000BC:
    // 0x808000BC: b           L_808000C8
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C8;
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C8:
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_801158B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801158B0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801158B4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x801158B8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801158BC: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    // 0x801158C0: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x801158C4: jr          $ra
    // 0x801158C8: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x801158C8: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_808002A0_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x808002A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002B0: jal         0x80100094
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002B8: jal         0x800D8FF8
    // 0x808002BC: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808002BC: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808002C4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x808002C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808002CC: jal         0x8010C9B0
    // 0x808002D0: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010C9B0(rdram, ctx);
        goto after_2;
    // 0x808002D0: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_2:
    // 0x808002D4: bnel        $v0, $zero, L_80800304
    if (ctx->r2 != 0) {
        // 0x808002D8: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_80800304;
    }
    goto skip_0;
    // 0x808002D8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x808002DC: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808002E0: beql        $a0, $zero, L_80800304
    if (ctx->r4 == 0) {
        // 0x808002E4: lw          $a0, 0x3C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X3C);
            goto L_80800304;
    }
    goto skip_1;
    // 0x808002E4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    skip_1:
    // 0x808002E8: jal         0x800C2FDC
    // 0x808002EC: nop

    func_800C2FDC(rdram, ctx);
        goto after_3;
    // 0x808002EC: nop

    after_3:
    // 0x808002F0: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
    // 0x808002F4: addiu       $a0, $zero, 0x6A8
    ctx->r4 = ADD32(0, 0X6A8);
    // 0x808002F8: jal         0x800DA3B8
    // 0x808002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_4;
    // 0x808002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800300: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_80800304:
    // 0x80800304: beql        $a0, $zero, L_80800354
    if (ctx->r4 == 0) {
        // 0x80800308: addiu       $a0, $sp, 0x98
        ctx->r4 = ADD32(ctx->r29, 0X98);
            goto L_80800354;
    }
    goto skip_2;
    // 0x80800308: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    skip_2:
    // 0x8080030C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80800310: addiu       $at, $zero, 0x22F
    ctx->r1 = ADD32(0, 0X22F);
    // 0x80800314: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800318: bnel        $t7, $at, L_80800354
    if (ctx->r15 != ctx->r1) {
        // 0x8080031C: addiu       $a0, $sp, 0x98
        ctx->r4 = ADD32(ctx->r29, 0X98);
            goto L_80800354;
    }
    goto skip_3;
    // 0x8080031C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    skip_3:
    // 0x80800320: jal         0x80106790
    // 0x80800324: nop

    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800324: nop

    after_5:
    // 0x80800328: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8080032C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800330: jal         0x800EE7F8
    // 0x80800334: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800334: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x80800338: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x8080033C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800344: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80800348: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080034C: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x80800350: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
L_80800354:
    // 0x80800354: jal         0x800EE7F8
    // 0x80800358: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800358: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x8080035C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800360: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800364: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80800368: jal         0x800EFA20
    // 0x8080036C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    func_800EFA20(rdram, ctx);
        goto after_8;
    // 0x8080036C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    after_8:
    // 0x80800370: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80800374: jal         0x800EF04C
    // 0x80800378: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80800378: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x8080037C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800380: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800384: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x80800388: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x8080038C: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x80800390: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    // 0x80800394: jal         0x800BF0E0
    // 0x80800398: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BF0E0(rdram, ctx);
        goto after_10;
    // 0x80800398: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
    // 0x8080039C: beql        $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003A0: lw          $a3, 0x24($s0)
        ctx->r7 = MEM_W(ctx->r16, 0X24);
            goto L_80800420;
    }
    goto skip_4;
    // 0x808003A0: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    skip_4:
    // 0x808003A4: jal         0x800EF2A0
    // 0x808003A8: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_800EF2A0(rdram, ctx);
        goto after_11;
    // 0x808003A8: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_11:
    // 0x808003AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808003B0: jal         0x800EEAA4
    // 0x808003B4: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800EEAA4(rdram, ctx);
        goto after_12;
    // 0x808003B4: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_12:
    // 0x808003B8: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x808003BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808003C4: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x808003C8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808003CC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808003D0: jal         0x800EFA20
    // 0x808003D4: nop

    func_800EFA20(rdram, ctx);
        goto after_13;
    // 0x808003D4: nop

    after_13:
    // 0x808003D8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808003DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808003E0: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x808003E4: jal         0x800EFA20
    // 0x808003E8: lui         $a2, 0x4216
    ctx->r6 = S32(0X4216 << 16);
    func_800EFA20(rdram, ctx);
        goto after_14;
    // 0x808003E8: lui         $a2, 0x4216
    ctx->r6 = S32(0X4216 << 16);
    after_14:
    // 0x808003EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808003F0: jal         0x800EF04C
    // 0x808003F4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800EF04C(rdram, ctx);
        goto after_15;
    // 0x808003F4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_15:
    // 0x808003F8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808003FC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800400: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80800404: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x80800408: beq         $t0, $at, L_8080041C
    if (ctx->r8 == ctx->r1) {
        // 0x8080040C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080041C;
    }
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: sb          $t0, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r8;
    // 0x80800414: jal         0x80800218
    // 0x80800418: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800218_chpiranha(rdram, ctx);
        goto after_16;
    // 0x80800418: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_16:
L_8080041C:
    // 0x8080041C: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
L_80800420:
    // 0x80800420: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800424: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800428: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080042C: addiu       $t2, $sp, 0xA4
    ctx->r10 = ADD32(ctx->r29, 0XA4);
    // 0x80800430: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80800434: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800438: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8080043C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800440: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800444: jal         0x80801250
    // 0x80800448: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80801250_chpiranha(rdram, ctx);
        goto after_17;
    // 0x80800448: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x8080044C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800450: jal         0x8008FE94
    // 0x80800454: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_8008FE94(rdram, ctx);
        goto after_18;
    // 0x80800454: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_18:
    // 0x80800458: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080045C: jal         0x800EFC7C
    // 0x80800460: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EFC7C(rdram, ctx);
        goto after_19;
    // 0x80800460: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x80800464: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80800468: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
    // 0x8080046C: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x80800470: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80800474: sltiu       $at, $t5, 0x7
    ctx->r1 = ctx->r13 < 0X7 ? 1 : 0;
    // 0x80800478: beq         $at, $zero, L_80800C64
    if (ctx->r1 == 0) {
        // 0x8080047C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80800C64;
    }
    // 0x8080047C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800480: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1A98) << 16);
    // 0x80800484: addu        $at, $at, $t5
    gpr jr_addend_8080048C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80800488: lw          $t5, 0x1A98($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1A98));
    // 0x8080048C: jr          $t5
    // 0x80800490: nop

    switch (jr_addend_8080048C >> 2) {
        case 0: goto L_80800568; break;
        case 1: goto L_808005F0; break;
        case 2: goto L_80800628; break;
        case 3: goto L_808008E8; break;
        case 4: goto L_80800B94; break;
        case 5: goto L_80800C40; break;
        case 6: goto L_80800494; break;
        default: switch_error(__func__, 0x8080048C, 0x80801A98);
    }
    // 0x80800490: nop

L_80800494:
    // 0x80800494: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800498: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x8080049C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808004A0: beql        $a0, $zero, L_80800548
    if (ctx->r4 == 0) {
        // 0x808004A4: lwc1        $f16, 0x8($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
            goto L_80800548;
    }
    goto skip_5;
    // 0x808004A4: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    skip_5:
    // 0x808004A8: jal         0x80106790
    // 0x808004AC: nop

    func_80106790(rdram, ctx);
        goto after_20;
    // 0x808004AC: nop

    after_20:
    // 0x808004B0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808004B4: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x808004B8: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x808004BC: addiu       $at, $zero, 0x22F
    ctx->r1 = ADD32(0, 0X22F);
    // 0x808004C0: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x808004C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808004C8: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x808004CC: bnel        $t8, $at, L_808004F0
    if (ctx->r24 != ctx->r1) {
        // 0x808004D0: lw          $t9, 0x5C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X5C);
            goto L_808004F0;
    }
    goto skip_6;
    // 0x808004D0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    skip_6:
    // 0x808004D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004D8: jal         0x800EE7F8
    // 0x808004DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_21;
    // 0x808004DC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_21:
    // 0x808004E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808004E4: jal         0x800EE7F8
    // 0x808004E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x808004E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_22:
    // 0x808004EC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
L_808004F0:
    // 0x808004F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004F4: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x808004F8: lhu         $t0, 0x72($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X72);
    // 0x808004FC: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80800500: bne         $t1, $at, L_80800C64
    if (ctx->r9 != ctx->r1) {
        // 0x80800504: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_80800C64;
    }
    // 0x80800504: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800508: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080050C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800518: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080051C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800520: jal         0x80800EFC
    // 0x80800524: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_23;
    // 0x80800524: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    after_23:
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x80800218
    // 0x80800530: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800218_chpiranha(rdram, ctx);
        goto after_24;
    // 0x80800530: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80800534: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800538: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8080053C: b           L_80800C64
    // 0x80800540: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800C64;
    // 0x80800540: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80800544: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
L_80800548:
    // 0x80800548: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800554: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800558: jal         0x80800218
    // 0x8080055C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    func_80800218_chpiranha(rdram, ctx);
        goto after_25;
    // 0x8080055C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_25:
    // 0x80800560: b           L_80800C68
    // 0x80800564: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x80800564: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_80800568:
    // 0x80800568: jal         0x80801638
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801638_chpiranha(rdram, ctx);
        goto after_26;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800570: beq         $v0, $zero, L_80800580
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800580;
    }
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x80800218
    // 0x8080057C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800218_chpiranha(rdram, ctx);
        goto after_27;
    // 0x8080057C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_27:
L_80800580:
    // 0x80800580: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800584: beq         $a0, $zero, L_808005BC
    if (ctx->r4 == 0) {
        // 0x80800588: nop
    
            goto L_808005BC;
    }
    // 0x80800588: nop

    // 0x8080058C: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x80800590: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80800594: addiu       $at, $zero, 0x22F
    ctx->r1 = ADD32(0, 0X22F);
    // 0x80800598: srl         $t3, $t2, 22
    ctx->r11 = S32(U32(ctx->r10) >> 22);
    // 0x8080059C: bne         $t3, $at, L_808005BC
    if (ctx->r11 != ctx->r1) {
        // 0x808005A0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_808005BC;
    }
    // 0x808005A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808005A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005A8: jal         0x800EE7F8
    // 0x808005AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_28;
    // 0x808005AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_28:
    // 0x808005B0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808005B4: jal         0x800EE7F8
    // 0x808005B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_29;
    // 0x808005B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_29:
L_808005BC:
    // 0x808005BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AB4) << 16);
    // 0x808005C0: lwc1        $f8, 0x1AB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AB4));
    // 0x808005C4: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808005C8: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808005D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808005D8: bc1fl       L_80800C68
    if (!c1cs) {
        // 0x808005DC: lw          $t3, 0x7C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X7C);
            goto L_80800C68;
    }
    goto skip_7;
    // 0x808005DC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    skip_7:
    // 0x808005E0: jal         0x80800EFC
    // 0x808005E4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_30;
    // 0x808005E4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_30:
    // 0x808005E8: b           L_80800C68
    // 0x808005EC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x808005EC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_808005F0:
    // 0x808005F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AB8) << 16);
    // 0x808005F4: lwc1        $f10, 0x1AB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AB8));
    // 0x808005F8: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800604: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800608: bc1f        L_80800618
    if (!c1cs) {
        // 0x8080060C: nop
    
            goto L_80800618;
    }
    // 0x8080060C: nop

    // 0x80800610: jal         0x80800EFC
    // 0x80800614: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_31;
    // 0x80800614: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_31:
L_80800618:
    // 0x80800618: jal         0x80801508
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801508_chpiranha(rdram, ctx);
        goto after_32;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800620: b           L_80800C68
    // 0x80800624: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x80800624: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_80800628:
    // 0x80800628: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080062C: jal         0x800EE7F8
    // 0x80800630: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800EE7F8(rdram, ctx);
        goto after_33;
    // 0x80800630: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_33:
    // 0x80800634: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800638: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080063C: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800640: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80800644: addiu       $at, $zero, 0x2C2
    ctx->r1 = ADD32(0, 0X2C2);
    // 0x80800648: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080064C: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80800650: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x80800654: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800658: srl         $t6, $t5, 22
    ctx->r14 = S32(U32(ctx->r13) >> 22);
    // 0x8080065C: bnel        $t6, $at, L_80800854
    if (ctx->r14 != ctx->r1) {
        // 0x80800660: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80800854;
    }
    goto skip_8;
    // 0x80800660: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_8:
    // 0x80800664: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800668: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1ABC) << 16);
    // 0x8080066C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800670: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80800674: lwc1        $f18, 0x1ABC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1ABC));
    // 0x80800678: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080067C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800680: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800684: nop

    // 0x80800688: bc1f        L_80800730
    if (!c1cs) {
        // 0x8080068C: nop
    
            goto L_80800730;
    }
    // 0x8080068C: nop

    // 0x80800690: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800694: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800698: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080069C: nop

    // 0x808006A0: bc1f        L_80800730
    if (!c1cs) {
        // 0x808006A4: nop
    
            goto L_80800730;
    }
    // 0x808006A4: nop

    // 0x808006A8: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x808006AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808006B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808006B4: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808006B8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x808006BC: bgez        $t8, L_808006D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808006C0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808006D0;
    }
    // 0x808006C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808006C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808006C8: nop

    // 0x808006CC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_808006D0:
    // 0x808006D0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x808006D4: nop

    // 0x808006D8: bc1f        L_80800730
    if (!c1cs) {
        // 0x808006DC: nop
    
            goto L_80800730;
    }
    // 0x808006DC: nop

    // 0x808006E0: jal         0x8010D284
    // 0x808006E4: nop

    func_8010D284(rdram, ctx);
        goto after_34;
    // 0x808006E4: nop

    after_34:
    // 0x808006E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006EC: beq         $v0, $at, L_80800730
    if (ctx->r2 == ctx->r1) {
        // 0x808006F0: nop
    
            goto L_80800730;
    }
    // 0x808006F0: nop

    // 0x808006F4: jal         0x80800CAC
    // 0x808006F8: nop

    func_80800CAC_chpiranha(rdram, ctx);
        goto after_35;
    // 0x808006F8: nop

    after_35:
    // 0x808006FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AC0) << 16);
    // 0x80800700: lwc1        $f4, 0x1AC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AC0));
    // 0x80800704: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800708: nop

    // 0x8080070C: bc1f        L_80800730
    if (!c1cs) {
        // 0x80800710: nop
    
            goto L_80800730;
    }
    // 0x80800710: nop

    // 0x80800714: jal         0x80090434
    // 0x80800718: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80090434(rdram, ctx);
        goto after_36;
    // 0x80800718: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_36:
    // 0x8080071C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800724: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800728: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8080072C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80800730:
    // 0x80800730: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AC4) << 16);
    // 0x80800734: lwc1        $f8, 0x1AC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AC4));
    // 0x80800738: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080073C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80800740: nop

    // 0x80800744: bc1f        L_808007A0
    if (!c1cs) {
        // 0x80800748: nop
    
            goto L_808007A0;
    }
    // 0x80800748: nop

    // 0x8080074C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800750: jal         0x80090010
    // 0x80800754: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    func_80090010(rdram, ctx);
        goto after_37;
    // 0x80800754: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    after_37:
    // 0x80800758: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080075C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800760: jal         0x800EFCD8
    // 0x80800764: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_38;
    // 0x80800764: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_38:
    // 0x80800768: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080076C: jal         0x800EF04C
    // 0x80800770: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EF04C(rdram, ctx);
        goto after_39;
    // 0x80800770: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_39:
    // 0x80800774: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800778: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080077C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800780: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AC8) << 16);
    // 0x80800784: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800788: nop

    // 0x8080078C: bc1f        L_808007A0
    if (!c1cs) {
        // 0x80800790: nop
    
            goto L_808007A0;
    }
    // 0x80800790: nop

    // 0x80800794: lwc1        $f10, 0x1AC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AC8));
    // 0x80800798: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080079C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_808007A0:
    // 0x808007A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1ACC) << 16);
    // 0x808007A4: lwc1        $f8, 0x1ACC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1ACC));
    // 0x808007A8: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808007AC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B4: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x808007B8: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x808007BC: bc1f        L_80800818
    if (!c1cs) {
        // 0x808007C0: nop
    
            goto L_80800818;
    }
    // 0x808007C0: nop

    // 0x808007C4: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808007C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808007D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808007D4: nop

    // 0x808007D8: bc1fl       L_808007F8
    if (!c1cs) {
        // 0x808007DC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_808007F8;
    }
    goto skip_9;
    // 0x808007DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_9:
    // 0x808007E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AD0) << 16);
    // 0x808007E4: lwc1        $f6, 0x1AD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AD0));
    // 0x808007E8: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808007EC: b           L_80800818
    // 0x808007F0: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
        goto L_80800818;
    // 0x808007F0: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x808007F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_808007F8:
    // 0x808007F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AD4) << 16);
    // 0x808007FC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800800: nop

    // 0x80800804: bc1f        L_80800818
    if (!c1cs) {
        // 0x80800808: nop
    
            goto L_80800818;
    }
    // 0x80800808: nop

    // 0x8080080C: lwc1        $f8, 0x1AD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AD4));
    // 0x80800810: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800814: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
L_80800818:
    // 0x80800818: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AD8) << 16);
    // 0x8080081C: lwc1        $f6, 0x1AD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AD8));
    // 0x80800820: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800824: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800828: nop

    // 0x8080082C: bc1f        L_808008D8
    if (!c1cs) {
        // 0x80800830: nop
    
            goto L_808008D8;
    }
    // 0x80800830: nop

    // 0x80800834: jal         0x80800EFC
    // 0x80800838: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_40;
    // 0x80800838: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_40:
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800840: jal         0x80800218
    // 0x80800844: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800218_chpiranha(rdram, ctx);
        goto after_41;
    // 0x80800844: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_41:
    // 0x80800848: b           L_808008D8
    // 0x8080084C: nop

        goto L_808008D8;
    // 0x8080084C: nop

    // 0x80800850: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80800854:
    // 0x80800854: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800858: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080085C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800868: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8080086C: bc1fl       L_8080088C
    if (!c1cs) {
        // 0x80800870: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8080088C;
    }
    goto skip_10;
    // 0x80800870: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_10:
    // 0x80800874: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800878: nop

    // 0x8080087C: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800880: b           L_808008A8
    // 0x80800884: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
        goto L_808008A8;
    // 0x80800884: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80800888: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8080088C:
    // 0x8080088C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800890: bc1f        L_808008A8
    if (!c1cs) {
        // 0x80800894: nop
    
            goto L_808008A8;
    }
    // 0x80800894: nop

    // 0x80800898: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080089C: nop

    // 0x808008A0: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x808008A4: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
L_808008A8:
    // 0x808008A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1ADC) << 16);
    // 0x808008AC: lwc1        $f6, 0x1ADC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1ADC));
    // 0x808008B0: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808008B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808008B8: nop

    // 0x808008BC: bc1f        L_808008D8
    if (!c1cs) {
        // 0x808008C0: nop
    
            goto L_808008D8;
    }
    // 0x808008C0: nop

    // 0x808008C4: jal         0x80800EFC
    // 0x808008C8: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_42;
    // 0x808008C8: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_42:
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D0: jal         0x80800218
    // 0x808008D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800218_chpiranha(rdram, ctx);
        goto after_43;
    // 0x808008D4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_43:
L_808008D8:
    // 0x808008D8: jal         0x8080154C
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080154C_chpiranha(rdram, ctx);
        goto after_44;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x808008E0: b           L_80800C68
    // 0x808008E4: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x808008E4: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_808008E8:
    // 0x808008E8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808008EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008F0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808008F4: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808008F8: addiu       $at, $zero, 0x2C2
    ctx->r1 = ADD32(0, 0X2C2);
    // 0x808008FC: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800900: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x80800904: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800908: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8080090C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80800910: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80800914: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x80800918: srl         $t1, $t0, 22
    ctx->r9 = S32(U32(ctx->r8) >> 22);
    // 0x8080091C: bne         $t1, $at, L_808009C8
    if (ctx->r9 != ctx->r1) {
        // 0x80800920: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808009C8;
    }
    // 0x80800920: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800924: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800928: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080092C: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80800930: nop

    // 0x80800934: bc1f        L_80800A4C
    if (!c1cs) {
        // 0x80800938: nop
    
            goto L_80800A4C;
    }
    // 0x80800938: nop

    // 0x8080093C: lw          $t2, 0x6C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X6C);
    // 0x80800940: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800944: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800948: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x8080094C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80800950: bgez        $t3, L_80800964
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800954: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80800964;
    }
    // 0x80800954: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800958: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080095C: nop

    // 0x80800960: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800964:
    // 0x80800964: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x80800968: nop

    // 0x8080096C: bc1f        L_80800A4C
    if (!c1cs) {
        // 0x80800970: nop
    
            goto L_80800A4C;
    }
    // 0x80800970: nop

    // 0x80800974: jal         0x8010D284
    // 0x80800978: nop

    func_8010D284(rdram, ctx);
        goto after_45;
    // 0x80800978: nop

    after_45:
    // 0x8080097C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800980: beq         $v0, $at, L_80800A4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800984: nop
    
            goto L_80800A4C;
    }
    // 0x80800984: nop

    // 0x80800988: jal         0x80800CAC
    // 0x8080098C: nop

    func_80800CAC_chpiranha(rdram, ctx);
        goto after_46;
    // 0x8080098C: nop

    after_46:
    // 0x80800990: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AE0) << 16);
    // 0x80800994: lwc1        $f10, 0x1AE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AE0));
    // 0x80800998: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080099C: nop

    // 0x808009A0: bc1f        L_80800A4C
    if (!c1cs) {
        // 0x808009A4: nop
    
            goto L_80800A4C;
    }
    // 0x808009A4: nop

    // 0x808009A8: jal         0x80090434
    // 0x808009AC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80090434(rdram, ctx);
        goto after_47;
    // 0x808009AC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_47:
    // 0x808009B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808009B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808009B8: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808009BC: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x808009C0: b           L_80800A4C
    // 0x808009C4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800A4C;
    // 0x808009C4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808009C8:
    // 0x808009C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808009CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009D0: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808009D4: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x808009D8: nop

    // 0x808009DC: bc1f        L_80800A4C
    if (!c1cs) {
        // 0x808009E0: nop
    
            goto L_80800A4C;
    }
    // 0x808009E0: nop

    // 0x808009E4: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x808009E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808009EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808009F0: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x808009F4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x808009F8: bgez        $t5, L_80800A0C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808009FC: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800A0C;
    }
    // 0x808009FC: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800A00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A04: nop

    // 0x80800A08: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80800A0C:
    // 0x80800A0C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800A10: nop

    // 0x80800A14: bc1f        L_80800A4C
    if (!c1cs) {
        // 0x80800A18: nop
    
            goto L_80800A4C;
    }
    // 0x80800A18: nop

    // 0x80800A1C: jal         0x8010D284
    // 0x80800A20: nop

    func_8010D284(rdram, ctx);
        goto after_48;
    // 0x80800A20: nop

    after_48:
    // 0x80800A24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A28: beq         $v0, $at, L_80800A4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800A2C: nop
    
            goto L_80800A4C;
    }
    // 0x80800A2C: nop

    // 0x80800A30: jal         0x80090434
    // 0x80800A34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80090434(rdram, ctx);
        goto after_49;
    // 0x80800A34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_49:
    // 0x80800A38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A40: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800A44: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80800A48: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80800A4C:
    // 0x80800A4C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AE4) << 16);
    // 0x80800A50: lwc1        $f6, 0x1AE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AE4));
    // 0x80800A54: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800A58: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80800A5C: nop

    // 0x80800A60: bc1fl       L_80800AF8
    if (!c1cs) {
        // 0x80800A64: lw          $t6, 0x6C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X6C);
            goto L_80800AF8;
    }
    goto skip_11;
    // 0x80800A64: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    skip_11:
    // 0x80800A68: jal         0x8010D284
    // 0x80800A6C: nop

    func_8010D284(rdram, ctx);
        goto after_50;
    // 0x80800A6C: nop

    after_50:
    // 0x80800A70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A74: bnel        $v0, $at, L_80800AF8
    if (ctx->r2 != ctx->r1) {
        // 0x80800A78: lw          $t6, 0x6C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X6C);
            goto L_80800AF8;
    }
    goto skip_12;
    // 0x80800A78: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    skip_12:
    // 0x80800A7C: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800A80: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800A84: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800A88: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800A8C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800A90: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800A94: sltiu       $v1, $t6, 0x1
    ctx->r3 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800A98: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800A9C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800AA0: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80800AA4: beq         $v1, $zero, L_80800AF4
    if (ctx->r3 == 0) {
        // 0x80800AA8: sh          $t1, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r9;
            goto L_80800AF4;
    }
    // 0x80800AA8: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x80800AAC: lw          $t3, 0x6C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X6C);
    // 0x80800AB0: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80800AB4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800AB8: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80800ABC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800AC0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80800AC4: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80800AC8: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    // 0x80800ACC: jal         0x800EE780
    // 0x80800AD0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_800EE780(rdram, ctx);
        goto after_51;
    // 0x80800AD0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_51:
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x80801690
    // 0x80800ADC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80801690_chpiranha(rdram, ctx);
        goto after_52;
    // 0x80800ADC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_52:
    // 0x80800AE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AE8) << 16);
    // 0x80800AE4: lwc1        $f8, 0x1AE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AE8));
    // 0x80800AE8: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800AEC: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80800AF0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800AF4:
    // 0x80800AF4: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
L_80800AF8:
    // 0x80800AF8: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800AFC: bne         $t7, $zero, L_80800B0C
    if (ctx->r15 != 0) {
        // 0x80800B00: nop
    
            goto L_80800B0C;
    }
    // 0x80800B00: nop

    // 0x80800B04: jal         0x800FFA88
    // 0x80800B08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_53;
    // 0x80800B08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_53:
L_80800B0C:
    // 0x80800B0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AEC) << 16);
    // 0x80800B10: lwc1        $f6, 0x1AEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AEC));
    // 0x80800B14: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80800B20: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80800B24: nop

    // 0x80800B28: bc1f        L_80800B38
    if (!c1cs) {
        // 0x80800B2C: nop
    
            goto L_80800B38;
    }
    // 0x80800B2C: nop

    // 0x80800B30: jal         0x80800EFC
    // 0x80800B34: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_80800EFC_chpiranha(rdram, ctx);
        goto after_54;
    // 0x80800B34: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_54:
L_80800B38:
    // 0x80800B38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AF0) << 16);
    // 0x80800B3C: lwc1        $f10, 0x1AF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AF0));
    // 0x80800B40: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800B44: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800B48: nop

    // 0x80800B4C: bc1tl       L_80800B74
    if (c1cs) {
        // 0x80800B50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B74;
    }
    goto skip_13;
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_13:
    // 0x80800B54: jal         0x80800CAC
    // 0x80800B58: nop

    func_80800CAC_chpiranha(rdram, ctx);
        goto after_55;
    // 0x80800B58: nop

    after_55:
    // 0x80800B5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800B60: nop

    // 0x80800B64: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800B68: nop

    // 0x80800B6C: bc1f        L_80800B84
    if (!c1cs) {
        // 0x80800B70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B84;
    }
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B74:
    // 0x80800B74: jal         0x80800218
    // 0x80800B78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800218_chpiranha(rdram, ctx);
        goto after_56;
    // 0x80800B78: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_56:
    // 0x80800B7C: b           L_80800C68
    // 0x80800B80: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x80800B80: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_80800B84:
    // 0x80800B84: jal         0x8080154C
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080154C_chpiranha(rdram, ctx);
        goto after_57;
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80800B8C: b           L_80800C68
    // 0x80800B90: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x80800B90: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_80800B94:
    // 0x80800B94: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80800B98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B9C: jal         0x800EE7F8
    // 0x80800BA0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_58;
    // 0x80800BA0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_58:
    // 0x80800BA4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800BA8: addiu       $at, $zero, 0x2C2
    ctx->r1 = ADD32(0, 0X2C2);
    // 0x80800BAC: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800BB0: lw          $t8, 0x24($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X24);
    // 0x80800BB4: srl         $t0, $t8, 22
    ctx->r8 = S32(U32(ctx->r24) >> 22);
    // 0x80800BB8: beq         $t0, $at, L_80800BF0
    if (ctx->r8 == ctx->r1) {
        // 0x80800BBC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1804, 0X1AF4) << 16);
            goto L_80800BF0;
    }
    // 0x80800BBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AF4) << 16);
    // 0x80800BC0: lwc1        $f18, 0x1AF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AF4));
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80800BCC: nop

    // 0x80800BD0: bc1f        L_80800BE0
    if (!c1cs) {
        // 0x80800BD4: nop
    
            goto L_80800BE0;
    }
    // 0x80800BD4: nop

    // 0x80800BD8: jal         0x80800218
    // 0x80800BDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800218_chpiranha(rdram, ctx);
        goto after_59;
    // 0x80800BDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_59:
L_80800BE0:
    // 0x80800BE0: jal         0x80801508
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801508_chpiranha(rdram, ctx);
        goto after_60;
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80800BE8: b           L_80800C68
    // 0x80800BEC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x80800BEC: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_80800BF0:
    // 0x80800BF0: jal         0x80800CAC
    // 0x80800BF4: nop

    func_80800CAC_chpiranha(rdram, ctx);
        goto after_61;
    // 0x80800BF4: nop

    after_61:
    // 0x80800BF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AF8) << 16);
    // 0x80800BFC: lwc1        $f6, 0x1AF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AF8));
    // 0x80800C00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1AFC) << 16);
    // 0x80800C04: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800C08: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800C0C: nop

    // 0x80800C10: bc1fl       L_80800C68
    if (!c1cs) {
        // 0x80800C14: lw          $t3, 0x7C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X7C);
            goto L_80800C68;
    }
    goto skip_14;
    // 0x80800C14: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    skip_14:
    // 0x80800C18: lwc1        $f16, 0x1AFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1AFC));
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C20: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800C24: nop

    // 0x80800C28: bc1fl       L_80800C68
    if (!c1cs) {
        // 0x80800C2C: lw          $t3, 0x7C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X7C);
            goto L_80800C68;
    }
    goto skip_15;
    // 0x80800C2C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    skip_15:
    // 0x80800C30: jal         0x80800218
    // 0x80800C34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800218_chpiranha(rdram, ctx);
        goto after_62;
    // 0x80800C34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_62:
    // 0x80800C38: b           L_80800C68
    // 0x80800C3C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
        goto L_80800C68;
    // 0x80800C3C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_80800C40:
    // 0x80800C40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1804, 0X1B00) << 16);
    // 0x80800C44: lwc1        $f8, 0x1B00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1804, 0X1B00));
    // 0x80800C48: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80800C4C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800C50: nop

    // 0x80800C54: bc1f        L_80800C64
    if (!c1cs) {
        // 0x80800C58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C64;
    }
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C5C: jal         0x80800218
    // 0x80800C60: lbu         $a1, 0x2($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X2);
    func_80800218_chpiranha(rdram, ctx);
        goto after_63;
    // 0x80800C60: lbu         $a1, 0x2($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X2);
    after_63:
L_80800C64:
    // 0x80800C64: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
L_80800C68:
    // 0x80800C68: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80800C6C: beql        $t4, $zero, L_80800C94
    if (ctx->r12 == 0) {
        // 0x80800C70: lw          $t6, 0x7C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X7C);
            goto L_80800C94;
    }
    goto skip_16;
    // 0x80800C70: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    skip_16:
    // 0x80800C74: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x80800C78: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800C7C: srl         $t5, $t2, 10
    ctx->r13 = S32(U32(ctx->r10) >> 10);
    // 0x80800C80: beql        $t5, $at, L_80800C94
    if (ctx->r13 == ctx->r1) {
        // 0x80800C84: lw          $t6, 0x7C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X7C);
            goto L_80800C94;
    }
    goto skip_17;
    // 0x80800C84: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    skip_17:
    // 0x80800C88: jal         0x80801420
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801420_chpiranha(rdram, ctx);
        goto after_64;
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x80800C90: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
L_80800C94:
    // 0x80800C94: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x80800C98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C9C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800CA0: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80800CA4: jr          $ra
    // 0x80800CA8: nop

    return;
    // 0x80800CA8: nop

;}
RECOMP_FUNC void func_808002A4_chlagoonufoext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002B4: jal         0x80101FDC
    // 0x808002B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808002B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808002BC: jal         0x80101D4C
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101D4C(rdram, ctx);
        goto after_1;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002C4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002D0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808002D4: jal         0x800D1000
    // 0x808002D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_2;
    // 0x808002D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80100094
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002F0: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x808002F4: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x808002F8: jal         0x8008A2D0
    // 0x808002FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808002FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80800300: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800304: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800308: addiu       $a1, $zero, 0x1047
    ctx->r5 = ADD32(0, 0X1047);
    // 0x8080030C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80800310: jal         0x8008A208
    // 0x80800314: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800314: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080031C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800320: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void _chnicecavemen_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086110: syscall     279
    recomp_syscall_handler(rdram, ctx, 0x80086110);
    return;
    // 0x80086114: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gldbDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808002B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808002BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808002C0: jal         0x800D5DB8
    // 0x808002C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800D5DB8(rdram, ctx);
        goto after_0;
    // 0x808002C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002C8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x808002CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808002D0: beq         $t6, $zero, L_808002DC
    if (ctx->r14 == 0) {
        // 0x808002D4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808002DC;
    }
    // 0x808002D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002D8: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
L_808002DC:
    // 0x808002DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808002E0: jal         0x8001ACCC
    // 0x808002E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x808002E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x808002E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002EC: jal         0x800D5A6C
    // 0x808002F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800D5A6C(rdram, ctx);
        goto after_2;
    // 0x808002F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808002F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808002F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002FC: jal         0x80012F78
    // 0x80800300: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    rom_dma_read(rdram, ctx);
        goto after_3;
    // 0x80800300: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80800304: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080030C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800310: jal         0x808000E8
    // 0x80800314: addiu       $a1, $a1, -0x955
    ctx->r5 = ADD32(ctx->r5, -0X955);
    func_808000E8_gldbDll(rdram, ctx);
        goto after_4;
    // 0x80800314: addiu       $a1, $a1, -0x955
    ctx->r5 = ADD32(ctx->r5, -0X955);
    after_4:
    // 0x80800318: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8080031C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800320: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80800324: sll         $a0, $t7, 4
    ctx->r4 = S32(ctx->r15 << 4);
    // 0x80800328: jal         0x8001ACCC
    // 0x8080032C: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    heap_alloc(rdram, ctx);
        goto after_5;
    // 0x8080032C: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    after_5:
    // 0x80800330: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800338: jal         0x8001C2AC
    // 0x8080033C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001C2AC(rdram, ctx);
        goto after_6;
    // 0x8080033C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80800340: jal         0x8001B084
    // 0x80800344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    heap_free(rdram, ctx);
        goto after_7;
    // 0x80800344: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080034C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800350: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: jr          $ra
    // 0x8080035C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080035C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _baduo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084948: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084948);
    return;
    // 0x8008494C: xori        $t0, $zero, 0x18
    ctx->r8 = 0 ^ 0X18;
;}
RECOMP_FUNC void gspropctrl_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x808000A0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x808000A4: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x808000A8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x808000AC: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x808000B0: jr          $ra
    // 0x808000B4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    return;
    // 0x808000B4: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void func_808025D8_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808025DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808025E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808025E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808025E8: jal         0x8008CABC
    // 0x808025EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808025EC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808025F0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808025F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808025F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808025FC: beq         $v1, $at, L_8080262C
    if (ctx->r3 == ctx->r1) {
        // 0x80802600: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080262C;
    }
    // 0x80802600: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802604: beq         $v1, $at, L_8080275C
    if (ctx->r3 == ctx->r1) {
        // 0x80802608: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080275C;
    }
    // 0x80802608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080260C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802610: beq         $v1, $at, L_80802774
    if (ctx->r3 == ctx->r1) {
        // 0x80802614: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802774;
    }
    // 0x80802614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802618: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080261C: beq         $v1, $at, L_80802790
    if (ctx->r3 == ctx->r1) {
        // 0x80802620: nop
    
            goto L_80802790;
    }
    // 0x80802620: nop

    // 0x80802624: b           L_808027AC
    // 0x80802628: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
        goto L_808027AC;
    // 0x80802628: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
L_8080262C:
    // 0x8080262C: jal         0x8008AF24
    // 0x80802630: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80802630: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x80802634: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802638: jal         0x8008AED4
    // 0x8080263C: addiu       $a1, $zero, 0x11F
    ctx->r5 = ADD32(0, 0X11F);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8080263C: addiu       $a1, $zero, 0x11F
    ctx->r5 = ADD32(0, 0X11F);
    after_2:
    // 0x80802640: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80802644: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80802648: jal         0x8008B1BC
    // 0x8080264C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8080264C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80802650: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80802654: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802658: jal         0x8008B1C8
    // 0x8080265C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x8080265C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80802660: lui         $a1, 0x3E31
    ctx->r5 = S32(0X3E31 << 16);
    // 0x80802664: ori         $a1, $a1, 0x8FC5
    ctx->r5 = ctx->r5 | 0X8FC5;
    // 0x80802668: jal         0x8008B24C
    // 0x8080266C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x8080266C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80802670: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80802674: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802678: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080267C: jal         0x8008B1D4
    // 0x80802680: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80802680: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80802684: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802688: jal         0x8008B134
    // 0x8080268C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x8080268C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80802690: jal         0x8008B064
    // 0x80802694: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x80802694: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80802698: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8080269C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808026A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808026A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808026AC: jal         0x8009FFD8
    // 0x808026B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x808026B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x808026B4: jal         0x8009EF04
    // 0x808026B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_10;
    // 0x808026B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808026BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808026C0: nop

    // 0x808026C4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808026C8: nop

    // 0x808026CC: bc1t        L_808026E8
    if (c1cs) {
        // 0x808026D0: nop
    
            goto L_808026E8;
    }
    // 0x808026D0: nop

    // 0x808026D4: jal         0x8009EEB8
    // 0x808026D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_11;
    // 0x808026D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808026DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808026E0: jal         0x8009C914
    // 0x808026E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x808026E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808026E8:
    // 0x808026E8: jal         0x8009C990
    // 0x808026EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x808026EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808026F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808026F4: jal         0x8009B9C0
    // 0x808026F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x808026F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808026FC: jal         0x80800438
    // 0x80802700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_15;
    // 0x80802700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80802704: jal         0x8009C990
    // 0x80802708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x80802708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080270C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80802710: jal         0x8009BB00
    // 0x80802714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80802714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80802718: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080271C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802720: jal         0x8009BA68
    // 0x80802724: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80802724: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80802728: lui         $a1, 0x442D
    ctx->r5 = S32(0X442D << 16);
    // 0x8080272C: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x80802730: jal         0x8009BA58
    // 0x80802734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x80802734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80802738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080273C: jal         0x8009BCB4
    // 0x80802740: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x80802740: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_20:
    // 0x80802744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802748: addiu       $a1, $zero, 0x4432
    ctx->r5 = ADD32(0, 0X4432);
    // 0x8080274C: jal         0x8009DE38
    // 0x80802750: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_21;
    // 0x80802750: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_21:
    // 0x80802754: b           L_808027A8
    // 0x80802758: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
        goto L_808027A8;
    // 0x80802758: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_8080275C:
    // 0x8080275C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80802760: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80802764: jal         0x8008CF1C
    // 0x80802768: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_22;
    // 0x80802768: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_22:
    // 0x8080276C: b           L_808027A8
    // 0x80802770: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
        goto L_808027A8;
    // 0x80802770: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_80802774:
    // 0x80802774: lui         $a1, 0x3F45
    ctx->r5 = S32(0X3F45 << 16);
    // 0x80802778: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080277C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80802780: jal         0x8008CF1C
    // 0x80802784: ori         $a1, $a1, 0xFD8B
    ctx->r5 = ctx->r5 | 0XFD8B;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_23;
    // 0x80802784: ori         $a1, $a1, 0xFD8B
    ctx->r5 = ctx->r5 | 0XFD8B;
    after_23:
    // 0x80802788: b           L_808027A8
    // 0x8080278C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
        goto L_808027A8;
    // 0x8080278C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_80802790:
    // 0x80802790: jal         0x8009FE58
    // 0x80802794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_24;
    // 0x80802794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80802798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080279C: jal         0x8008CED4
    // 0x808027A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_25;
    // 0x808027A0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_25:
    // 0x808027A4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_808027A8:
    // 0x808027A8: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
L_808027AC:
    // 0x808027AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808027B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808027B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808027B8: jr          $ra
    // 0x808027BC: nop

    return;
    // 0x808027BC: nop

;}
RECOMP_FUNC void chweldarbossdoors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1372, 0X2B8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1372, 0X2B8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1372, 0X2B8));
;}
RECOMP_FUNC void func_8080000C_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800024: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x80800028: addiu       $t7, $v0, 0x17A
    ctx->r15 = ADD32(ctx->r2, 0X17A);
    // 0x8080002C: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80800030: jal         0x80088848
    // 0x80800034: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800034: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    after_0:
    // 0x80800038: beq         $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x8080003C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800050;
    }
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x80102424
    // 0x80800044: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800044: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80800048: b           L_808000D0
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000D0;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800050:
    // 0x80800050: jal         0x800DA298
    // 0x80800054: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_2:
    // 0x80800058: beq         $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x8080005C: addiu       $a0, $zero, 0x17A
        ctx->r4 = ADD32(0, 0X17A);
            goto L_808000AC;
    }
    // 0x8080005C: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    // 0x80800060: jal         0x800DA564
    // 0x80800064: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DA564(rdram, ctx);
        goto after_3;
    // 0x80800064: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80800068: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x8080006C: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x80800070: bne         $v0, $t8, L_8080009C
    if (ctx->r2 != ctx->r24) {
        // 0x80800074: nop
    
            goto L_8080009C;
    }
    // 0x80800074: nop

    // 0x80800078: jal         0x800D0B68
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_4;
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800080: bne         $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x80800084: addiu       $a0, $zero, 0x31
        ctx->r4 = ADD32(0, 0X31);
            goto L_8080009C;
    }
    // 0x80800084: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080008C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800090: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800094: jal         0x800D1000
    // 0x80800098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_5;
    // 0x80800098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
L_8080009C:
    // 0x8080009C: jal         0x800FFAB0
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000A4: b           L_808000DC
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808000DC;
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000AC:
    // 0x808000AC: jal         0x800DA298
    // 0x808000B0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808000B0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_7:
    // 0x808000B4: beql        $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000BC: jal         0x800FFAB0
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000C4: b           L_808000DC
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808000DC;
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000D0:
    // 0x808000D0: jal         0x8010B990
    // 0x808000D4: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_8010B990(rdram, ctx);
        goto after_9;
    // 0x808000D4: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_9:
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000DC:
    // 0x808000DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void func_80800050_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080005C: jal         0x800CEA84
    // 0x80800060: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CEA84(rdram, ctx);
        goto after_0;
    // 0x80800060: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x80800074: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_808012B4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012B4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808012B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808012C0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808012C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012C8: jal         0x80100094
    // 0x808012CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808012CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808012D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808012D4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808012D8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808012DC: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x808012E0: sltiu       $at, $t8, 0x15
    ctx->r1 = ctx->r24 < 0X15 ? 1 : 0;
    // 0x808012E4: beq         $at, $zero, L_80801374
    if (ctx->r1 == 0) {
        // 0x808012E8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801374;
    }
    // 0x808012E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808012EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X504C) << 16);
    // 0x808012F0: addu        $at, $at, $t8
    gpr jr_addend_808012F8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808012F4: lw          $t8, 0x504C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X504C));
    // 0x808012F8: jr          $t8
    // 0x808012FC: nop

    switch (jr_addend_808012F8 >> 2) {
        case 0: goto L_80801300; break;
        case 1: goto L_80801300; break;
        case 2: goto L_80801310; break;
        case 3: goto L_80801328; break;
        case 4: goto L_80801374; break;
        case 5: goto L_80801374; break;
        case 6: goto L_80801374; break;
        case 7: goto L_80801374; break;
        case 8: goto L_80801374; break;
        case 9: goto L_80801374; break;
        case 10: goto L_80801374; break;
        case 11: goto L_80801374; break;
        case 12: goto L_80801368; break;
        case 13: goto L_80801370; break;
        case 14: goto L_80801370; break;
        case 15: goto L_80801374; break;
        case 16: goto L_80801374; break;
        case 17: goto L_80801368; break;
        case 18: goto L_80801368; break;
        case 19: goto L_80801374; break;
        case 20: goto L_80801358; break;
        default: switch_error(__func__, 0x808012F8, 0x8080504C);
    }
    // 0x808012FC: nop

L_80801300:
    // 0x80801300: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80801304: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80801308: b           L_80801374
    // 0x8080130C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_80801374;
    // 0x8080130C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80801310:
    // 0x80801310: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801318: jal         0x80800B9C
    // 0x8080131C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_1;
    // 0x8080131C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80801320: b           L_80801378
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801378;
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801328:
    // 0x80801328: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080132C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801330: jal         0x80800B9C
    // 0x80801334: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x80801334: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80801338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080133C: jal         0x80800000
    // 0x80801340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80801340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801344: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80801348: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080134C: sb          $zero, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = 0;
    // 0x80801350: b           L_80801374
    // 0x80801354: sb          $t3, 0x59($t2)
    MEM_B(0X59, ctx->r10) = ctx->r11;
        goto L_80801374;
    // 0x80801354: sb          $t3, 0x59($t2)
    MEM_B(0X59, ctx->r10) = ctx->r11;
L_80801358:
    // 0x80801358: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x8080135C: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80801360: b           L_80801374
    // 0x80801364: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_80801374;
    // 0x80801364: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80801368:
    // 0x80801368: b           L_80801374
    // 0x8080136C: sb          $zero, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = 0;
        goto L_80801374;
    // 0x8080136C: sb          $zero, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = 0;
L_80801370:
    // 0x80801370: sb          $zero, 0x54($v0)
    MEM_B(0X54, ctx->r2) = 0;
L_80801374:
    // 0x80801374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801378:
    // 0x80801378: jal         0x80102424
    // 0x8080137C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x8080137C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x80801380: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801384: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801388: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x8080138C: sltiu       $at, $t8, 0x16
    ctx->r1 = ctx->r24 < 0X16 ? 1 : 0;
    // 0x80801390: beq         $at, $zero, L_80801828
    if (ctx->r1 == 0) {
        // 0x80801394: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801828;
    }
    // 0x80801394: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801398: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X50A0) << 16);
    // 0x8080139C: addu        $at, $at, $t8
    gpr jr_addend_808013A4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808013A0: lw          $t8, 0x50A0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X50A0));
    // 0x808013A4: jr          $t8
    // 0x808013A8: nop

    switch (jr_addend_808013A4 >> 2) {
        case 0: goto L_8080181C; break;
        case 1: goto L_80801828; break;
        case 2: goto L_80801828; break;
        case 3: goto L_808013AC; break;
        case 4: goto L_80801428; break;
        case 5: goto L_80801828; break;
        case 6: goto L_80801470; break;
        case 7: goto L_80801490; break;
        case 8: goto L_808014BC; break;
        case 9: goto L_808014EC; break;
        case 10: goto L_80801564; break;
        case 11: goto L_80801828; break;
        case 12: goto L_80801580; break;
        case 13: goto L_80801768; break;
        case 14: goto L_808015FC; break;
        case 15: goto L_80801628; break;
        case 16: goto L_80801828; break;
        case 17: goto L_808016B8; break;
        case 18: goto L_80801754; break;
        case 19: goto L_80801768; break;
        case 20: goto L_80801778; break;
        case 21: goto L_808017A8; break;
        default: switch_error(__func__, 0x808013A4, 0x808050A0);
    }
    // 0x808013A8: nop

L_808013AC:
    // 0x808013AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808013B4: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x808013B8: jal         0x80800A80
    // 0x808013BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_5;
    // 0x808013BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x808013C0: jal         0x800FDC28
    // 0x808013C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_6;
    // 0x808013C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x808013C8: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x808013CC: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x808013D0: beq         $t0, $zero, L_80801400
    if (ctx->r8 == 0) {
        // 0x808013D4: nop
    
            goto L_80801400;
    }
    // 0x808013D4: nop

    // 0x808013D8: jal         0x800DA298
    // 0x808013DC: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808013DC: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    after_7:
    // 0x808013E0: bne         $v0, $zero, L_80801828
    if (ctx->r2 != 0) {
        // 0x808013E4: addiu       $a0, $zero, 0x18B9
        ctx->r4 = ADD32(0, 0X18B9);
            goto L_80801828;
    }
    // 0x808013E4: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x808013E8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808013EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808013F0: jal         0x800861A0
    // 0x808013F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x808013F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x808013F8: b           L_8080182C
    // 0x808013FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080182C;
    // 0x808013FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801400:
    // 0x80801400: jal         0x800DA298
    // 0x80801404: addiu       $a0, $zero, 0x1D4
    ctx->r4 = ADD32(0, 0X1D4);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80801404: addiu       $a0, $zero, 0x1D4
    ctx->r4 = ADD32(0, 0X1D4);
    after_9:
    // 0x80801408: bne         $v0, $zero, L_80801828
    if (ctx->r2 != 0) {
        // 0x8080140C: addiu       $a0, $zero, 0x18B9
        ctx->r4 = ADD32(0, 0X18B9);
            goto L_80801828;
    }
    // 0x8080140C: addiu       $a0, $zero, 0x18B9
    ctx->r4 = ADD32(0, 0X18B9);
    // 0x80801410: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801418: jal         0x800861A0
    // 0x8080141C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x8080141C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80801420: b           L_8080182C
    // 0x80801424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080182C;
    // 0x80801424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801428:
    // 0x80801428: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x8080142C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80801430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801434: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801438: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x8080143C: jal         0x80800A80
    // 0x80801440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_11;
    // 0x80801440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80801444: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801448: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080144C: jal         0x80800B9C
    // 0x80801450: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_12;
    // 0x80801450: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80801454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801458: jal         0x80101EE4
    // 0x8080145C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101EE4(rdram, ctx);
        goto after_13;
    // 0x8080145C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_13:
    // 0x80801460: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80801464: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801468: b           L_80801828
    // 0x8080146C: sb          $t3, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r11;
        goto L_80801828;
    // 0x8080146C: sb          $t3, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r11;
L_80801470:
    // 0x80801470: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80801474: srl         $t4, $v0, 4
    ctx->r12 = S32(U32(ctx->r2) >> 4);
    // 0x80801478: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8080147C: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80801480: andi        $t8, $v0, 0xFF0F
    ctx->r24 = ctx->r2 & 0XFF0F;
    // 0x80801484: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80801488: b           L_80801828
    // 0x8080148C: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
        goto L_80801828;
    // 0x8080148C: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
L_80801490:
    // 0x80801490: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80801494: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801498: sll         $t3, $t0, 12
    ctx->r11 = S32(ctx->r8 << 12);
    // 0x8080149C: bgezl       $t3, L_808014B4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808014A0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808014B4;
    }
    goto skip_0;
    // 0x808014A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x808014A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808014A8: b           L_80801828
    // 0x808014AC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80801828;
    // 0x808014AC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808014B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808014B4:
    // 0x808014B4: b           L_80801828
    // 0x808014B8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80801828;
    // 0x808014B8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808014BC:
    // 0x808014BC: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x808014C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808014C4: sll         $t5, $t2, 12
    ctx->r13 = S32(ctx->r10 << 12);
    // 0x808014C8: bgezl       $t5, L_808014E4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808014CC: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_808014E4;
    }
    goto skip_1;
    // 0x808014CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x808014D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808014D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808014D8: b           L_80801828
    // 0x808014DC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80801828;
    // 0x808014DC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808014E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_808014E4:
    // 0x808014E4: b           L_80801828
    // 0x808014E8: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80801828;
    // 0x808014E8: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_808014EC:
    // 0x808014EC: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
    // 0x808014F0: addiu       $a0, $zero, 0x407
    ctx->r4 = ADD32(0, 0X407);
    // 0x808014F4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808014F8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808014FC: beq         $t7, $zero, L_8080150C
    if (ctx->r15 == 0) {
        // 0x80801500: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8080150C;
    }
    // 0x80801500: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801504: b           L_8080150C
    // 0x80801508: addiu       $a0, $zero, 0x406
    ctx->r4 = ADD32(0, 0X406);
        goto L_8080150C;
    // 0x80801508: addiu       $a0, $zero, 0x406
    ctx->r4 = ADD32(0, 0X406);
L_8080150C:
    // 0x8080150C: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801510: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80801514: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80801518: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8080151C: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80801520: bgez        $t2, L_80801538
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801524: sh          $t0, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r8;
            goto L_80801538;
    }
    // 0x80801524: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x80801528: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080152C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801530: b           L_80801544
    // 0x80801534: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_80801544;
    // 0x80801534: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80801538:
    // 0x80801538: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080153C: nop

    // 0x80801540: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80801544:
    // 0x80801544: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80801548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080154C: jal         0x800DA9E4
    // 0x80801550: sb          $t4, 0x5D($t5)
    MEM_B(0X5D, ctx->r13) = ctx->r12;
    func_800DA9E4(rdram, ctx);
        goto after_14;
    // 0x80801550: sb          $t4, 0x5D($t5)
    MEM_B(0X5D, ctx->r13) = ctx->r12;
    after_14:
    // 0x80801554: bne         $v0, $zero, L_80801564
    if (ctx->r2 != 0) {
        // 0x80801558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801564;
    }
    // 0x80801558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080155C: jal         0x80800D98
    // 0x80801560: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_15;
    // 0x80801560: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_15:
L_80801564:
    // 0x80801564: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X5558) << 16);
    // 0x80801568: addiu       $a2, $a2, 0x5558
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X5558));
    // 0x8080156C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801570: jal         0x80089D18
    // 0x80801574: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80801574: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_16:
    // 0x80801578: b           L_8080182C
    // 0x8080157C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080182C;
    // 0x8080157C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801580:
    // 0x80801580: jal         0x8010A570
    // 0x80801584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_17;
    // 0x80801584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080158C: jal         0x80800000
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_chdragonbrothers(rdram, ctx);
        goto after_18;
    // 0x80801590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80801594: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801598: addiu       $a3, $zero, 0x405
    ctx->r7 = ADD32(0, 0X405);
    // 0x8080159C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808015A0: beq         $t7, $zero, L_808015B0
    if (ctx->r15 == 0) {
        // 0x808015A4: nop
    
            goto L_808015B0;
    }
    // 0x808015A4: nop

    // 0x808015A8: b           L_808015B0
    // 0x808015AC: addiu       $a3, $zero, 0x404
    ctx->r7 = ADD32(0, 0X404);
        goto L_808015B0;
    // 0x808015AC: addiu       $a3, $zero, 0x404
    ctx->r7 = ADD32(0, 0X404);
L_808015B0:
    // 0x808015B0: jal         0x800DA298
    // 0x808015B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x808015B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_19:
    // 0x808015B8: bne         $v0, $zero, L_808015E0
    if (ctx->r2 != 0) {
        // 0x808015BC: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_808015E0;
    }
    // 0x808015BC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808015C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808015C4: jal         0x80800B9C
    // 0x808015C8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_20;
    // 0x808015C8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_20:
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808015D4: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x808015D8: jal         0x80800A80
    // 0x808015DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_21;
    // 0x808015DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
L_808015E0:
    // 0x808015E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015E4: jal         0x808011C0
    // 0x808015E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808011C0_chdragonbrothers(rdram, ctx);
        goto after_22;
    // 0x808015E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808015EC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808015F0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808015F4: b           L_80801828
    // 0x808015F8: sb          $zero, 0x5E($t8)
    MEM_B(0X5E, ctx->r24) = 0;
        goto L_80801828;
    // 0x808015F8: sb          $zero, 0x5E($t8)
    MEM_B(0X5E, ctx->r24) = 0;
L_808015FC:
    // 0x808015FC: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801604: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80801608: jal         0x8010A590
    // 0x8080160C: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    func_8010A590(rdram, ctx);
        goto after_23;
    // 0x8080160C: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    after_23:
    // 0x80801610: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801614: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801618: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x8080161C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80801620: b           L_80801828
    // 0x80801624: sb          $t1, 0x54($t3)
    MEM_B(0X54, ctx->r11) = ctx->r9;
        goto L_80801828;
    // 0x80801624: sb          $t1, 0x54($t3)
    MEM_B(0X54, ctx->r11) = ctx->r9;
L_80801628:
    // 0x80801628: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x8080162C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801630: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801634: sll         $t5, $t2, 12
    ctx->r13 = S32(ctx->r10 << 12);
    // 0x80801638: bgezl       $t5, L_80801654
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8080163C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80801654;
    }
    goto skip_2;
    // 0x8080163C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x80801640: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80801644: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801648: b           L_8080165C
    // 0x8080164C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
        goto L_8080165C;
    // 0x8080164C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x80801650: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80801654:
    // 0x80801654: nop

    // 0x80801658: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_8080165C:
    // 0x8080165C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x80801660: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801664: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801668: jal         0x800F1DCC
    // 0x8080166C: lwc1        $f14, 0x18($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X18);
    func_800F1DCC(rdram, ctx);
        goto after_24;
    // 0x8080166C: lwc1        $f14, 0x18($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X18);
    after_24:
    // 0x80801670: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80801674: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80801678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080167C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80801680: nop

    // 0x80801684: bc1f        L_8080169C
    if (!c1cs) {
        // 0x80801688: nop
    
            goto L_8080169C;
    }
    // 0x80801688: nop

    // 0x8080168C: jal         0x80800D98
    // 0x80801690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_25;
    // 0x80801690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80801694: b           L_808016A8
    // 0x80801698: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_808016A8;
    // 0x80801698: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_8080169C:
    // 0x8080169C: jal         0x80800D98
    // 0x808016A0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_26;
    // 0x808016A0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_26:
    // 0x808016A4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_808016A8:
    // 0x808016A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808016AC: sb          $zero, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = 0;
    // 0x808016B0: b           L_80801828
    // 0x808016B4: sb          $t7, 0x54($v0)
    MEM_B(0X54, ctx->r2) = ctx->r15;
        goto L_80801828;
    // 0x808016B4: sb          $t7, 0x54($v0)
    MEM_B(0X54, ctx->r2) = ctx->r15;
L_808016B8:
    // 0x808016B8: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x808016BC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x808016C0: jal         0x8010A570
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_27;
    // 0x808016C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808016C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X53B0) << 16);
    // 0x808016CC: addiu       $a2, $a2, 0x53B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X53B0));
    // 0x808016D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016D4: jal         0x80089D18
    // 0x808016D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_28;
    // 0x808016D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_28:
    // 0x808016DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808016E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808016E4: jal         0x80800B9C
    // 0x808016E8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_29;
    // 0x808016E8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_29:
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016F0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808016F4: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x808016F8: jal         0x80800A80
    // 0x808016FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_30;
    // 0x808016FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_30:
    // 0x80801700: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801704: addiu       $a3, $zero, 0x1D6
    ctx->r7 = ADD32(0, 0X1D6);
    // 0x80801708: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8080170C: beq         $t0, $zero, L_8080171C
    if (ctx->r8 == 0) {
        // 0x80801710: nop
    
            goto L_8080171C;
    }
    // 0x80801710: nop

    // 0x80801714: b           L_8080171C
    // 0x80801718: addiu       $a3, $zero, 0x1D5
    ctx->r7 = ADD32(0, 0X1D5);
        goto L_8080171C;
    // 0x80801718: addiu       $a3, $zero, 0x1D5
    ctx->r7 = ADD32(0, 0X1D5);
L_8080171C:
    // 0x8080171C: jal         0x800DA544
    // 0x80801720: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800DA544(rdram, ctx);
        goto after_31;
    // 0x80801720: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_31:
    // 0x80801724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801728: jal         0x80800000
    // 0x8080172C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_chdragonbrothers(rdram, ctx);
        goto after_32;
    // 0x8080172C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x80801730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801734: jal         0x808011C0
    // 0x80801738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808011C0_chdragonbrothers(rdram, ctx);
        goto after_33;
    // 0x80801738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x8080173C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80801740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801744: jal         0x80800D98
    // 0x80801748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_34;
    // 0x80801748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_34:
    // 0x8080174C: b           L_8080182C
    // 0x80801750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080182C;
    // 0x80801750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801754:
    // 0x80801754: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80801758: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080175C: sb          $zero, 0x59($v0)
    MEM_B(0X59, ctx->r2) = 0;
    // 0x80801760: b           L_80801828
    // 0x80801764: sb          $t1, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r9;
        goto L_80801828;
    // 0x80801764: sb          $t1, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r9;
L_80801768:
    // 0x80801768: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8080176C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801770: b           L_80801828
    // 0x80801774: sb          $t3, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r11;
        goto L_80801828;
    // 0x80801774: sb          $t3, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r11;
L_80801778:
    // 0x80801778: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x8080177C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801784: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x80801788: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x8080178C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80801790: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x80801794: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801798: jal         0x80800A80
    // 0x8080179C: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_35;
    // 0x8080179C: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    after_35:
    // 0x808017A0: b           L_8080182C
    // 0x808017A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080182C;
    // 0x808017A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017A8:
    // 0x808017A8: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x808017AC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x808017B0: lbu         $t8, 0x7A($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7A);
    // 0x808017B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808017BC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x808017C0: beq         $t9, $zero, L_808017D0
    if (ctx->r25 == 0) {
        // 0x808017C4: addiu       $a3, $zero, 0x12CB
        ctx->r7 = ADD32(0, 0X12CB);
            goto L_808017D0;
    }
    // 0x808017C4: addiu       $a3, $zero, 0x12CB
    ctx->r7 = ADD32(0, 0X12CB);
    // 0x808017C8: b           L_808017D0
    // 0x808017CC: addiu       $a3, $zero, 0x12CA
    ctx->r7 = ADD32(0, 0X12CA);
        goto L_808017D0;
    // 0x808017CC: addiu       $a3, $zero, 0x12CA
    ctx->r7 = ADD32(0, 0X12CA);
L_808017D0:
    // 0x808017D0: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x808017D4: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808017D8: jal         0x80800D20
    // 0x808017DC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_36;
    // 0x808017DC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_36:
    // 0x808017E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X50F8) << 16);
    // 0x808017E4: lwc1        $f4, 0x50F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X50F8));
    // 0x808017E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808017EC: lui         $a2, 0xC416
    ctx->r6 = S32(0XC416 << 16);
    // 0x808017F0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x808017F4: jal         0x800EFCD8
    // 0x808017F8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EFCD8(rdram, ctx);
        goto after_37;
    // 0x808017F8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_37:
    // 0x808017FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801800: jal         0x800EF04C
    // 0x80801804: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_38;
    // 0x80801804: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_38:
    // 0x80801808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080180C: jal         0x80800D98
    // 0x80801810: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_39;
    // 0x80801810: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_39:
    // 0x80801814: b           L_8080182C
    // 0x80801818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080182C;
    // 0x80801818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080181C:
    // 0x8080181C: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80801820: andi        $t3, $t1, 0xFFFE
    ctx->r11 = ctx->r9 & 0XFFFE;
    // 0x80801824: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80801828:
    // 0x80801828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080182C:
    // 0x8080182C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801830: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801834: jr          $ra
    // 0x80801838: nop

    return;
    // 0x80801838: nop

;}
RECOMP_FUNC void func_80800A20_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A28: jal         0x808006F0
    // 0x80800A2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800A2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A38: jal         0x80800934
    // 0x80800A3C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80800934_bstrexlarge(rdram, ctx);
        goto after_1;
    // 0x80800A3C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A48: jr          $ra
    // 0x80800A4C: nop

    return;
    // 0x80800A4C: nop

;}
RECOMP_FUNC void func_8080135C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080135C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801364: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801368: jal         0x800839E8
    // 0x8080136C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080136C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801370: beq         $v0, $zero, L_80801384
    if (ctx->r2 == 0) {
        // 0x80801374: nop
    
            goto L_80801384;
    }
    // 0x80801374: nop

    // 0x80801378: jal         0x800839B0
    // 0x8080137C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080137C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801380: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80801384:
    // 0x80801384: jal         0x808003BC
    // 0x80801388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bsvan_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080138C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801390: jal         0x8009E5C8
    // 0x80801394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080139C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013A0: jr          $ra
    // 0x808013A4: nop

    return;
    // 0x808013A4: nop

;}
RECOMP_FUNC void func_808002E8_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002F4: jal         0x800C4B64
    // 0x808002F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C4B64(rdram, ctx);
        goto after_0;
    // 0x808002F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800300: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X1978) << 16);
    // 0x80800304: addiu       $a2, $a2, 0x1978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X1978));
    // 0x80800308: jal         0x80089D18
    // 0x8080030C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080030C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void func_8080008C_chwaterfallgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800090: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800094: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800098: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080009C: jal         0x800DA298
    // 0x808000A0: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    after_0:
    // 0x808000A4: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x808000A8: nop
    
            goto L_808000BC;
    }
    // 0x808000A8: nop

    // 0x808000AC: jal         0x800DA544
    // 0x808000B0: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808000B0: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    after_1:
    // 0x808000B4: b           L_808000F0
    // 0x808000B8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
        goto L_808000F0;
    // 0x808000B8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_808000BC:
    // 0x808000BC: jal         0x800CEAA8
    // 0x808000C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_2;
    // 0x808000C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808000C4: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000C8: nop
    
            goto L_808000E4;
    }
    // 0x808000C8: nop

    // 0x808000CC: jal         0x800CE95C
    // 0x808000D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CE95C(rdram, ctx);
        goto after_3;
    // 0x808000D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808000D4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x808000D8: addiu       $t6, $t6, 0x7018
    ctx->r14 = ADD32(ctx->r14, 0X7018);
    // 0x808000DC: beql        $v0, $t6, L_808000F0
    if (ctx->r2 == ctx->r14) {
        // 0x808000E0: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_808000F0;
    }
    goto skip_0;
    // 0x808000E0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    skip_0:
L_808000E4:
    // 0x808000E4: jal         0x800DA524
    // 0x808000E8: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x808000E8: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    after_4:
    // 0x808000EC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_808000F0:
    // 0x808000F0: jal         0x800EE7F8
    // 0x808000F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808000F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808000F8: addiu       $t7, $zero, 0x408A
    ctx->r15 = ADD32(0, 0X408A);
    // 0x808000FC: addiu       $t8, $zero, 0x9F2
    ctx->r24 = ADD32(0, 0X9F2);
    // 0x80800100: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800104: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800110: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800114: jal         0x80086898
    // 0x80800118: lui         $a3, 0x43DC
    ctx->r7 = S32(0X43DC << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800118: lui         $a3, 0x43DC
    ctx->r7 = S32(0X43DC << 16);
    after_6:
    // 0x8080011C: beq         $v0, $zero, L_808001A4
    if (ctx->r2 == 0) {
        // 0x80800120: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A4;
    }
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x800868C0
    // 0x80800128: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800128: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x800868A8
    // 0x80800134: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800134: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    after_8:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800144: jal         0x800868C8
    // 0x80800148: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x80800148: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_9:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800154: jal         0x800868D0
    // 0x80800158: addiu       $a2, $zero, 0x501
    ctx->r6 = ADD32(0, 0X501);
    _chdoormake_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x80800158: addiu       $a2, $zero, 0x501
    ctx->r6 = ADD32(0, 0X501);
    after_10:
    // 0x8080015C: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800160: ori         $a2, $a2, 0x3300
    ctx->r6 = ctx->r6 | 0X3300;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x800868D8
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _chdoormake_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800178: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080017C: jal         0x800868C8
    // 0x80800180: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800180: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_12:
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080018C: jal         0x800868D0
    // 0x80800190: addiu       $a2, $zero, 0x502
    ctx->r6 = ADD32(0, 0X502);
    _chdoormake_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x80800190: addiu       $a2, $zero, 0x502
    ctx->r6 = ADD32(0, 0X502);
    after_13:
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080019C: jal         0x800868D8
    // 0x808001A0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _chdoormake_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x808001A0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_14:
L_808001A4:
    // 0x808001A4: jal         0x800DA298
    // 0x808001A8: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808001A8: addiu       $a0, $zero, 0x503
    ctx->r4 = ADD32(0, 0X503);
    after_15:
    // 0x808001AC: bnel        $v0, $zero, L_808001C4
    if (ctx->r2 != 0) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001C4;
    }
    goto skip_1;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808001B4: jal         0x800DA298
    // 0x808001B8: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x808001B8: addiu       $a0, $zero, 0x9F2
    ctx->r4 = ADD32(0, 0X9F2);
    after_16:
    // 0x808001BC: bne         $v0, $zero, L_808001CC
    if (ctx->r2 != 0) {
        // 0x808001C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001C4:
    // 0x808001C4: jal         0x80103110
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_17;
    // 0x808001C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
L_808001CC:
    // 0x808001CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082548: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082548);
    return;
    // 0x8008254C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800238_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080023C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800240: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800244: jal         0x80082838
    // 0x80800248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080024C: lui         $a2, 0x3EC2
    ctx->r6 = S32(0X3EC2 << 16);
    // 0x80800250: ori         $a2, $a2, 0x8F5C
    ctx->r6 = ctx->r6 | 0X8F5C;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: jal         0x8008CB3C
    // 0x8080025C: addiu       $a1, $zero, 0x1DD
    ctx->r5 = ADD32(0, 0X1DD);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080025C: addiu       $a1, $zero, 0x1DD
    ctx->r5 = ADD32(0, 0X1DD);
    after_1:
    // 0x80800260: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800264: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800270: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800274: jal         0x8009FFD8
    // 0x80800278: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800278: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8080027C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(80, 0X1250) << 16);
    // 0x80800280: lwc1        $f4, 0x1250($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(80, 0X1250));
    // 0x80800284: lui         $a2, 0x43BB
    ctx->r6 = S32(0X43BB << 16);
    // 0x80800288: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x8080028C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800290: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8080029C: jal         0x8008C9F0
    // 0x808002A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_3;
    // 0x808002A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808002A4: jal         0x800909CC
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002B8: jr          $ra
    // 0x808002BC: nop

    return;
    // 0x808002BC: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801050: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X1AD4) << 16);
    // 0x80801054: jr          $ra
    // 0x80801058: addiu       $v0, $v0, 0x1AD4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1AD4));
    return;
    // 0x80801058: addiu       $v0, $v0, 0x1AD4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1AD4));
;}
RECOMP_FUNC void _chfactoryworkerdirty_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087328: syscall     550
    recomp_syscall_handler(rdram, ctx, 0x80087328);
    return;
    // 0x8008732C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chdoormake_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800724: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080072C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800730: jal         0x80100094
    // 0x80800734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800738: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8080073C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1544, 0X9A0) << 16);
    // 0x80800740: addiu       $t8, $t8, 0x9A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1544, 0X9A0));
    // 0x80800744: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800748: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8080074C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800750: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800754: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80800758: addiu       $a0, $v0, 0x2E
    ctx->r4 = ADD32(ctx->r2, 0X2E);
    // 0x8080075C: jal         0x8001BBA0
    // 0x80800760: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x80800760: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80800764: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800768: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080076C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1544, 0XA0C) << 16);
    // 0x80800770: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80800774: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80800778: sll         $v0, $t9, 1
    ctx->r2 = S32(ctx->r25 << 1);
    // 0x8080077C: addiu       $t0, $t0, 0xA0C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1544, 0XA0C));
    // 0x80800780: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    // 0x80800784: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800788: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8080078C: jal         0x8001BBA0
    // 0x80800790: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    rare_memcpy(rdram, ctx);
        goto after_2;
    // 0x80800790: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_2:
    // 0x80800794: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800798: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080079C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1544, 0XAC0) << 16);
    // 0x808007A0: addiu       $t1, $t1, 0xAC0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1544, 0XAC0));
    // 0x808007A4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x808007A8: addu        $a1, $v0, $t1
    ctx->r5 = ADD32(ctx->r2, ctx->r9);
    // 0x808007AC: jal         0x8001BBA0
    // 0x808007B0: addiu       $a0, $a0, 0x3E
    ctx->r4 = ADD32(ctx->r4, 0X3E);
    rare_memcpy(rdram, ctx);
        goto after_3;
    // 0x808007B0: addiu       $a0, $a0, 0x3E
    ctx->r4 = ADD32(ctx->r4, 0X3E);
    after_3:
    // 0x808007B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

;}
RECOMP_FUNC void func_808013F8_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013FC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80801400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801404: beq         $a1, $at, L_80801434
    if (ctx->r5 == ctx->r1) {
        // 0x80801408: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801434;
    }
    // 0x80801408: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080140C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80801410: beq         $a1, $at, L_80801448
    if (ctx->r5 == ctx->r1) {
        // 0x80801414: lh          $a2, 0x22($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X22);
            goto L_80801448;
    }
    // 0x80801414: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x80801418: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080141C: beq         $a1, $at, L_80801458
    if (ctx->r5 == ctx->r1) {
        // 0x80801420: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80801458;
    }
    // 0x80801420: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801424: beq         $a1, $at, L_80801468
    if (ctx->r5 == ctx->r1) {
        // 0x80801428: nop
    
            goto L_80801468;
    }
    // 0x80801428: nop

    // 0x8080142C: b           L_80801484
    // 0x80801430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801484;
    // 0x80801430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801434:
    // 0x80801434: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80801438: jal         0x80801494
    // 0x8080143C: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80801494_chhoopswoop(rdram, ctx);
        goto after_0;
    // 0x8080143C: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x80801440: b           L_80801484
    // 0x80801444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801484;
    // 0x80801444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801448:
    // 0x80801448: jal         0x80801500
    // 0x8080144C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    func_80801500_chhoopswoop(rdram, ctx);
        goto after_1;
    // 0x8080144C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    after_1:
    // 0x80801450: b           L_80801488
    // 0x80801454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801488;
    // 0x80801454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801458:
    // 0x80801458: jal         0x80800D28
    // 0x8080145C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80800D28_chhoopswoop(rdram, ctx);
        goto after_2;
    // 0x8080145C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x80801460: b           L_80801484
    // 0x80801464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801484;
    // 0x80801464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801468:
    // 0x80801468: jal         0x8080153C
    // 0x8080146C: nop

    func_8080153C_chhoopswoop(rdram, ctx);
        goto after_3;
    // 0x8080146C: nop

    after_3:
    // 0x80801470: b           L_80801484
    // 0x80801474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801484;
    // 0x80801474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801478: b           L_80801484
    // 0x8080147C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801484;
    // 0x8080147C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801484:
    // 0x80801484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801488:
    // 0x80801488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080148C: jr          $ra
    // 0x80801490: nop

    return;
    // 0x80801490: nop

;}
