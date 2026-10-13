#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080595C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080595C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80805960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80805964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80805968: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x8080596C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80805970: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80805974: beq         $v1, $zero, L_80805990
    if (ctx->r3 == 0) {
        // 0x80805978: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80805990;
    }
    // 0x80805978: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080597C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80805980: beql        $v1, $at, L_808059CC
    if (ctx->r3 == ctx->r1) {
        // 0x80805984: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808059CC;
    }
    goto skip_0;
    // 0x80805984: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_0:
    // 0x80805988: b           L_80805AB0
    // 0x8080598C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80805AB0;
    // 0x8080598C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80805990:
    // 0x80805990: jal         0x80087D30
    // 0x80805994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80805994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80805998: beq         $v0, $zero, L_808059B4
    if (ctx->r2 == 0) {
        // 0x8080599C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808059B4;
    }
    // 0x8080599C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808059A0: jal         0x80803C60
    // 0x808059A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80803C60_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808059A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x808059A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808059AC: b           L_80805AB0
    // 0x808059B0: addiu       $v0, $a2, 0x23
    ctx->r2 = ADD32(ctx->r6, 0X23);
        goto L_80805AB0;
    // 0x808059B0: addiu       $v0, $a2, 0x23
    ctx->r2 = ADD32(ctx->r6, 0X23);
L_808059B4:
    // 0x808059B4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808059B8: jal         0x80802CC0
    // 0x808059BC: lw          $a0, 0x30($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X30);
    func_80802CC0_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808059BC: lw          $a0, 0x30($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X30);
    after_2:
    // 0x808059C0: b           L_80805AB0
    // 0x808059C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80805AB0;
    // 0x808059C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x808059C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_808059CC:
    // 0x808059CC: beq         $a2, $at, L_808059E0
    if (ctx->r6 == ctx->r1) {
        // 0x808059D0: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_808059E0;
    }
    // 0x808059D0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808059D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808059D8: bnel        $a2, $at, L_80805A9C
    if (ctx->r6 != ctx->r1) {
        // 0x808059DC: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_80805A9C;
    }
    goto skip_1;
    // 0x808059DC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    skip_1:
L_808059E0:
    // 0x808059E0: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x808059E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808059E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808059EC: beq         $t9, $at, L_80805A40
    if (ctx->r25 == ctx->r1) {
        // 0x808059F0: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80805A40;
    }
    // 0x808059F0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808059F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808059F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808059FC: jal         0x80087D38
    // 0x80805A00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80805A00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80805A04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80805A08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80805A10: bne         $a2, $at, L_80805A28
    if (ctx->r6 != ctx->r1) {
        // 0x80805A14: nop
    
            goto L_80805A28;
    }
    // 0x80805A14: nop

    // 0x80805A18: jal         0x808069C8
    // 0x80805A1C: nop

    func_808069C8_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80805A1C: nop

    after_4:
    // 0x80805A20: b           L_80805A34
    // 0x80805A24: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
        goto L_80805A34;
    // 0x80805A24: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
L_80805A28:
    // 0x80805A28: jal         0x80806A88
    // 0x80805A2C: nop

    func_80806A88_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80805A2C: nop

    after_5:
    // 0x80805A30: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
L_80805A34:
    // 0x80805A34: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80805A38: b           L_80805A98
    // 0x80805A3C: sw          $t0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r8;
        goto L_80805A98;
    // 0x80805A3C: sw          $t0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r8;
L_80805A40:
    // 0x80805A40: jal         0x80087D30
    // 0x80805A44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x80805A44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x80805A48: beq         $v0, $zero, L_80805A60
    if (ctx->r2 == 0) {
        // 0x80805A4C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80805A60;
    }
    // 0x80805A4C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80805A50: jal         0x80803C60
    // 0x80805A54: nop

    func_80803C60_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80805A54: nop

    after_7:
    // 0x80805A58: b           L_80805AB0
    // 0x80805A5C: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
        goto L_80805AB0;
    // 0x80805A5C: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_80805A60:
    // 0x80805A60: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80805A64: lw          $a0, 0x30($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X30);
    // 0x80805A68: jal         0x80802C10
    // 0x80805A6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80802C10_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80805A6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x80805A70: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80805A74: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80805A78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805A7C: bne         $a2, $at, L_80805A8C
    if (ctx->r6 != ctx->r1) {
        // 0x80805A80: sw          $a2, 0x1C($t3)
        MEM_W(0X1C, ctx->r11) = ctx->r6;
            goto L_80805A8C;
    }
    // 0x80805A80: sw          $a2, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r6;
    // 0x80805A84: b           L_80805AB0
    // 0x80805A88: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_80805AB0;
    // 0x80805A88: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_80805A8C:
    // 0x80805A8C: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80805A90: b           L_80805AB0
    // 0x80805A94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80805AB0;
    // 0x80805A94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80805A98:
    // 0x80805A98: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
L_80805A9C:
    // 0x80805A9C: jal         0x80802CC0
    // 0x80805AA0: lw          $a0, 0x30($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X30);
    func_80802CC0_chgameselect(rdram, ctx);
        goto after_9;
    // 0x80805AA0: lw          $a0, 0x30($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X30);
    after_9:
    // 0x80805AA4: jal         0x80803C80
    // 0x80805AA8: nop

    func_80803C80_chgameselect(rdram, ctx);
        goto after_10;
    // 0x80805AA8: nop

    after_10:
    // 0x80805AAC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80805AB0:
    // 0x80805AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80805AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80805AB8: jr          $ra
    // 0x80805ABC: nop

    return;
    // 0x80805ABC: nop

;}
RECOMP_FUNC void _bssplitup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AA0: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AA0);
    return;
    // 0x80083AA4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bamovehover_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E50: syscall     138
    recomp_syscall_handler(rdram, ctx, 0x80084E50);
    return;
    // 0x80084E54: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _anseq_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082618: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082618);
    return;
    // 0x8008261C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsblongleg_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080142C: jal         0x80082FF0
    // 0x80801430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801434: jal         0x80800204
    // 0x80801438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800204_bsblongleg(rdram, ctx);
        goto after_1;
    // 0x80801438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080143C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801444: jr          $ra
    // 0x80801448: nop

    return;
    // 0x80801448: nop

;}
RECOMP_FUNC void func_800CD08C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD08C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CD090: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CD094: lw          $t7, -0x517C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X517C);
    // 0x800CD098: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CD09C: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800CD0A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CD0A4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800CD0A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CD0AC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CD0B0: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800CD0B4: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800CD0B8: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800CD0BC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800CD0C0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800CD0C4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800CD0C8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800CD0CC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800CD0D0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800CD0D4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800CD0D8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800CD0DC: lw          $s7, 0x0($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X0);
    // 0x800CD0E0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800CD0E4: srl         $t8, $s7, 9
    ctx->r24 = S32(U32(ctx->r23) >> 9);
    // 0x800CD0E8: jal         0x800CB8F0
    // 0x800CD0EC: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    func_800CB8F0(rdram, ctx);
        goto after_0;
    // 0x800CD0EC: or          $s7, $t8, $zero
    ctx->r23 = ctx->r24 | 0;
    after_0:
    // 0x800CD0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD0F4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800CD0F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CD0FC: lwc1        $f24, 0x5990($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5990);
    // 0x800CD100: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x800CD104: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
    // 0x800CD108: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x800CD10C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CD110:
    // 0x800CD110: jal         0x800DC128
    // 0x800CD114: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x800CD114: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_1:
    // 0x800CD118: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CD11C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CD120: mflo        $t9
    ctx->r25 = lo;
    // 0x800CD124: addu        $a1, $t9, $s2
    ctx->r5 = ADD32(ctx->r25, ctx->r18);
    // 0x800CD128: jal         0x800EE7F8
    // 0x800CD12C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800CD12C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    after_2:
    // 0x800CD130: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800CD134: jal         0x800DC178
    // 0x800CD138: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x800CD138: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_3:
    // 0x800CD13C: lh          $t0, 0xC($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XC);
    // 0x800CD140: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800CD144: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x800CD148: addiu       $t1, $t0, -0x5
    ctx->r9 = ADD32(ctx->r8, -0X5);
    // 0x800CD14C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800CD150: jal         0x800DC178
    // 0x800CD154: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x800CD154: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x800CD158: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800CD15C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800CD160: jal         0x800EF1B8
    // 0x800CD164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF1B8(rdram, ctx);
        goto after_5;
    // 0x800CD164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800CD168: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x800CD16C: subu        $t2, $s4, $v0
    ctx->r10 = SUB32(ctx->r20, ctx->r2);
    // 0x800CD170: addiu       $t3, $v0, -0x5
    ctx->r11 = ADD32(ctx->r2, -0X5);
    // 0x800CD174: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800CD178: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800CD17C: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CD180: jal         0x800DC178
    // 0x800CD184: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x800CD184: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_6:
    // 0x800CD188: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800CD18C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CD190: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800CD194: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800CD198: jal         0x800CC4D4
    // 0x800CD19C: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    func_800CC4D4(rdram, ctx);
        goto after_7;
    // 0x800CD19C: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    after_7:
    // 0x800CD1A0: bnel        $v0, $s5, L_800CD110
    if (ctx->r2 != ctx->r21) {
        // 0x800CD1A4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800CD110;
    }
    goto skip_0;
    // 0x800CD1A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x800CD1A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CD1AC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800CD1B0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800CD1B4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800CD1B8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD1BC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800CD1C0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800CD1C4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800CD1C8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800CD1CC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800CD1D0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800CD1D4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800CD1D8: jr          $ra
    // 0x800CD1DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800CD1DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void chexploder_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801A50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801A54: jal         0x80100094
    // 0x80801A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A5C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A60: sb          $t6, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r14;
    // 0x80801A64: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801A68: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80801A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A74: jr          $ra
    // 0x80801A78: nop

    return;
    // 0x80801A78: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804D04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80804D08: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB500) << 16);
    // 0x80804D0C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80804D10: jr          $ra
    // 0x80804D14: lw          $v0, -0x4B00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB500));
    return;
    // 0x80804D14: lw          $v0, -0x4B00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB500));
;}
RECOMP_FUNC void func_8080058C_chmolehill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080058C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800590: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800598: jal         0x80800000
    // 0x8080059C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800000_chmolehill(rdram, ctx);
        goto after_0;
    // 0x8080059C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808005A0: bnel        $v0, $zero, L_80800688
    if (ctx->r2 != 0) {
        // 0x808005A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800688;
    }
    goto skip_0;
    // 0x808005A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005A8: jal         0x8010D254
    // 0x808005AC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x808005AC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x808005B0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005B8: jal         0x800F1DF4
    // 0x808005BC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x808005BC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x808005C0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808005C4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808005C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005CC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808005D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808005D4: jal         0x800F1DCC
    // 0x808005D8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x808005D8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_3:
    // 0x808005DC: jal         0x80013728
    // 0x808005E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_4;
    // 0x808005E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x808005E4: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x808005E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808005F0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808005F4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808005F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005FC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800600: bc1fl       L_80800610
    if (!c1cs) {
        // 0x80800604: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80800610;
    }
    goto skip_1;
    // 0x80800604: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x80800608: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8080060C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80800610:
    // 0x80800610: nop

    // 0x80800614: bc1fl       L_80800624
    if (!c1cs) {
        // 0x80800618: sub.s       $f10, $f8, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
            goto L_80800624;
    }
    goto skip_2;
    // 0x80800618: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    skip_2:
    // 0x8080061C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800620: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
L_80800624:
    // 0x80800624: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800628: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080062C: jal         0x800EE7F8
    // 0x80800630: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800630: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80800634: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800638: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080063C: jal         0x800EF1B8
    // 0x80800640: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800640: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_6:
    // 0x80800644: jal         0x8008F8B0
    // 0x80800648: nop

    func_8008F8B0(rdram, ctx);
        goto after_7;
    // 0x80800648: nop

    after_7:
    // 0x8080064C: jal         0x8008F8D8
    // 0x80800650: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_8;
    // 0x80800650: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80800654: jal         0x8008F938
    // 0x80800658: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_9;
    // 0x80800658: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8080065C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800660: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800664: jal         0x8008F904
    // 0x80800668: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_10;
    // 0x80800668: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x8080066C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800670: jal         0x8008F990
    // 0x80800674: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_8008F990(rdram, ctx);
        goto after_11;
    // 0x80800674: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_11:
    // 0x80800678: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x8080067C: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800680: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800688:
    // 0x80800688: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080068C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800690: jr          $ra
    // 0x80800694: nop

    return;
    // 0x80800694: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F98: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F98);
    return;
    // 0x80087F9C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_800A5D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5D1C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5D20: lbu         $t6, 0x7114($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7114);
    // 0x800A5D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5D2C: beq         $t6, $zero, L_800A5D48
    if (ctx->r14 == 0) {
        // 0x800A5D30: nop
    
            goto L_800A5D48;
    }
    // 0x800A5D30: nop

    // 0x800A5D34: jal         0x8010D1E8
    // 0x800A5D38: nop

    func_8010D1E8(rdram, ctx);
        goto after_0;
    // 0x800A5D38: nop

    after_0:
    // 0x800A5D3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5D40: jal         0x80085938
    // 0x800A5D44: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    _chbaddieDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800A5D44: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    after_1:
L_800A5D48:
    // 0x800A5D48: jal         0x800FFB74
    // 0x800A5D4C: nop

    func_800FFB74(rdram, ctx);
        goto after_2;
    // 0x800A5D4C: nop

    after_2:
    // 0x800A5D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5D58: jr          $ra
    // 0x800A5D5C: nop

    return;
    // 0x800A5D5C: nop

;}
RECOMP_FUNC void func_80800760_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800768: jal         0x80082FF0
    // 0x8080076C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080076C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800770: jal         0x808000F0
    // 0x80800774: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800774: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080077C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800780: jr          $ra
    // 0x80800784: nop

    return;
    // 0x80800784: nop

;}
RECOMP_FUNC void func_800F23AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F23AC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F23B0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800F23B4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F23B8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800F23BC: jr          $ra
    // 0x800F23C0: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800F23C0: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800F23C4: nop

    // 0x800F23C8: nop

    // 0x800F23CC: nop

;}
RECOMP_FUNC void _suautobaddies_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FC0: syscall     820
    recomp_syscall_handler(rdram, ctx, 0x80089FC0);
    return;
    // 0x80089FC4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void anctrl_setDuration(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B1C0: jr          $ra
    // 0x8008B1C4: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8008B1C4: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chexploder_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086660: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086660);
    return;
    // 0x80086664: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _capod_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085748: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085748);
    return;
    // 0x8008574C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void _bsow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083930: syscall     82
    recomp_syscall_handler(rdram, ctx, 0x80083930);
    return;
    // 0x80083934: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80013D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80013D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013D1C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80013D20: addiu       $a0, $a0, -0x7C30
    ctx->r4 = ADD32(ctx->r4, -0X7C30);
    // 0x80013D24: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80013D28: jal         0x8002EAD0
    // 0x80013D2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80013D2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80013D30: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80013D34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80013D38: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80013D3C: bnel        $t6, $at, L_80013D88
    if (ctx->r14 != ctx->r1) {
        // 0x80013D40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013D88;
    }
    goto skip_0;
    // 0x80013D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80013D44: lw          $t8, -0xBD0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XBD0);
    // 0x80013D48: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80013D4C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013D50: beq         $t8, $zero, L_80013D68
    if (ctx->r24 == 0) {
        // 0x80013D54: sw          $t7, -0x70F4($at)
        MEM_W(-0X70F4, ctx->r1) = ctx->r15;
            goto L_80013D68;
    }
    // 0x80013D54: sw          $t7, -0x70F4($at)
    MEM_W(-0X70F4, ctx->r1) = ctx->r15;
    // 0x80013D58: jal         0x8002EF70
    // 0x80013D5C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x80013D5C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x80013D60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013D64: sw          $zero, -0xBD0($at)
    MEM_W(-0XBD0, ctx->r1) = 0;
L_80013D68:
    // 0x80013D68: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80013D6C: addiu       $a0, $a0, -0x7BC8
    ctx->r4 = ADD32(ctx->r4, -0X7BC8);
    // 0x80013D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80013D74: jal         0x8002E1F0
    // 0x80013D78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80013D78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80013D7C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013D80: sw          $zero, -0x70F4($at)
    MEM_W(-0X70F4, ctx->r1) = 0;
    // 0x80013D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80013D88:
    // 0x80013D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013D8C: jr          $ra
    // 0x80013D90: nop

    return;
    // 0x80013D90: nop

;}
RECOMP_FUNC void func_80800CC4_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CCC: jal         0x800F54E4
    // 0x80800CD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800CD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CD8: jal         0x800F64A4
    // 0x80800CDC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800CDC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x80800CE0: beq         $v0, $zero, L_80800CF0
    if (ctx->r2 == 0) {
        // 0x80800CE4: addiu       $a1, $zero, 0xFFB
        ctx->r5 = ADD32(0, 0XFFB);
            goto L_80800CF0;
    }
    // 0x80800CE4: addiu       $a1, $zero, 0xFFB
    ctx->r5 = ADD32(0, 0XFFB);
    // 0x80800CE8: b           L_80800CF0
    // 0x80800CEC: addiu       $a1, $zero, 0x1054
    ctx->r5 = ADD32(0, 0X1054);
        goto L_80800CF0;
    // 0x80800CEC: addiu       $a1, $zero, 0x1054
    ctx->r5 = ADD32(0, 0X1054);
L_80800CF0:
    // 0x80800CF0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800CF4: addiu       $t6, $zero, 0x56
    ctx->r14 = ADD32(0, 0X56);
    // 0x80800CF8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800CFC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800D00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800D04: jal         0x8008A208
    // 0x80800D08: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800D08: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x80800D0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D10: jal         0x80102424
    // 0x80800D14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800D14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800D18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D20: jr          $ra
    // 0x80800D24: nop

    return;
    // 0x80800D24: nop

;}
RECOMP_FUNC void _gleeprom_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088510: syscall     691
    recomp_syscall_handler(rdram, ctx, 0x80088510);
    return;
    // 0x80088514: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800668_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800668: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080066C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800670: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800674: jal         0x800E3980
    // 0x80800678: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80800678: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8080067C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800680: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800684: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800688: jal         0x800F18FC
    // 0x8080068C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F18FC(rdram, ctx);
        goto after_1;
    // 0x8080068C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800690: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800694: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800698: jal         0x800F1DCC
    // 0x8080069C: lwc1        $f12, 0x48($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x8080069C: lwc1        $f12, 0x48($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X48);
    after_2:
    // 0x808006A0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808006A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808006A8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x808006AC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x808006B0: jal         0x800F2100
    // 0x808006B4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x808006B4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x808006B8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808006BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006C0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808006C4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808006C8: nop

    // 0x808006CC: bc1fl       L_808006E4
    if (!c1cs) {
        // 0x808006D0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808006E4;
    }
    goto skip_0;
    // 0x808006D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x808006D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808006D8: b           L_80800718
    // 0x808006DC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
        goto L_80800718;
    // 0x808006DC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808006E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_808006E4:
    // 0x808006E4: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x808006E8: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x808006EC: nop

    // 0x808006F0: bc1fl       L_8080070C
    if (!c1cs) {
        // 0x808006F4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080070C;
    }
    goto skip_1;
    // 0x808006F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x808006F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808006FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800700: b           L_80800714
    // 0x80800704: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800714;
    // 0x80800704: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800708: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080070C:
    // 0x8080070C: nop

    // 0x80800710: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800714:
    // 0x80800714: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
L_80800718:
    // 0x80800718: jal         0x800F2100
    // 0x8080071C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x8080071C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80800720: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800724: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800728: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080072C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800730: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800734: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800738: bc1fl       L_80800750
    if (!c1cs) {
        // 0x8080073C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80800750;
    }
    goto skip_2;
    // 0x8080073C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_2:
    // 0x80800740: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800744: b           L_80800784
    // 0x80800748: lwc1        $f6, 0x48($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X48);
        goto L_80800784;
    // 0x80800748: lwc1        $f6, 0x48($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X48);
    // 0x8080074C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800750:
    // 0x80800750: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80800754: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800758: nop

    // 0x8080075C: bc1fl       L_80800778
    if (!c1cs) {
        // 0x80800760: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800778;
    }
    goto skip_3;
    // 0x80800760: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x80800764: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800768: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080076C: b           L_80800780
    // 0x80800770: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80800780;
    // 0x80800770: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800774: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800778:
    // 0x80800778: nop

    // 0x8080077C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80800780:
    // 0x80800780: lwc1        $f6, 0x48($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X48);
L_80800784:
    // 0x80800784: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x80800788: jal         0x800136E4
    // 0x8080078C: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x8080078C: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    after_5:
    // 0x80800790: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800794: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800798: jal         0x800136E4
    // 0x8080079C: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x8080079C: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
    after_6:
    // 0x808007A0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x808007A4: swc1        $f0, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f0.u32l;
    // 0x808007A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808007B0: jr          $ra
    // 0x808007B4: nop

    return;
    // 0x808007B4: nop

;}
RECOMP_FUNC void bsmum_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BB0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800BB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X1170) << 16);
    // 0x80800BB8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800BBC: jr          $ra
    // 0x80800BC0: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1170));
    return;
    // 0x80800BC0: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1170));
;}
RECOMP_FUNC void func_800AA16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA16C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800AA170: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA174: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800AA178: jr          $ra
    // 0x800AA17C: lh          $v0, 0x7784($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7784);
    return;
    // 0x800AA17C: lh          $v0, 0x7784($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7784);
;}
RECOMP_FUNC void anctrl_isAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B348: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B34C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008B358: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008B35C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8008B360: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8008B364: jal         0x8008C0C8
    // 0x8008B368: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8008C0C8(rdram, ctx);
        goto after_0;
    // 0x8008B368: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8008B36C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008B370: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008B374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B378: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8008B37C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8008B380: nop

    // 0x8008B384: bc1fl       L_8008B398
    if (!c1cs) {
        // 0x8008B388: lbu         $t6, 0x1B($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X1B);
            goto L_8008B398;
    }
    goto skip_0;
    // 0x8008B388: lbu         $t6, 0x1B($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1B);
    skip_0:
    // 0x8008B38C: b           L_8008B4A0
    // 0x8008B390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008B4A0;
    // 0x8008B390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B394: lbu         $t6, 0x1B($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1B);
L_8008B398:
    // 0x8008B398: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B39C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8008B3A0: bnel        $t7, $at, L_8008B42C
    if (ctx->r15 != ctx->r1) {
        // 0x8008B3A4: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8008B42C;
    }
    goto skip_1;
    // 0x8008B3A4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x8008B3A8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8008B3AC: nop

    // 0x8008B3B0: bc1fl       L_8008B3F4
    if (!c1cs) {
        // 0x8008B3B4: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_8008B3F4;
    }
    goto skip_2;
    // 0x8008B3B4: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_2:
    // 0x8008B3B8: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8008B3BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B3C0: bc1f        L_8008B3CC
    if (!c1cs) {
        // 0x8008B3C4: nop
    
            goto L_8008B3CC;
    }
    // 0x8008B3C4: nop

    // 0x8008B3C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008B3CC:
    // 0x8008B3CC: beq         $v0, $zero, L_8008B4A0
    if (ctx->r2 == 0) {
        // 0x8008B3D0: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B3D0: nop

    // 0x8008B3D4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8008B3D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B3DC: bc1f        L_8008B4A0
    if (!c1cs) {
        // 0x8008B3E0: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B3E0: nop

    // 0x8008B3E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008B3E8: b           L_8008B4A0
    // 0x8008B3EC: nop

        goto L_8008B4A0;
    // 0x8008B3EC: nop

    // 0x8008B3F0: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_8008B3F4:
    // 0x8008B3F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B3F8: bc1f        L_8008B404
    if (!c1cs) {
        // 0x8008B3FC: nop
    
            goto L_8008B404;
    }
    // 0x8008B3FC: nop

    // 0x8008B400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008B404:
    // 0x8008B404: bne         $v0, $zero, L_8008B4A0
    if (ctx->r2 != 0) {
        // 0x8008B408: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B408: nop

    // 0x8008B40C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8008B410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B414: bc1f        L_8008B4A0
    if (!c1cs) {
        // 0x8008B418: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B418: nop

    // 0x8008B41C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008B420: b           L_8008B4A0
    // 0x8008B424: nop

        goto L_8008B4A0;
    // 0x8008B424: nop

    // 0x8008B428: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8008B42C:
    // 0x8008B42C: nop

    // 0x8008B430: bc1fl       L_8008B474
    if (!c1cs) {
        // 0x8008B434: c.le.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
            goto L_8008B474;
    }
    goto skip_3;
    // 0x8008B434: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    skip_3:
    // 0x8008B438: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8008B43C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B440: bc1f        L_8008B44C
    if (!c1cs) {
        // 0x8008B444: nop
    
            goto L_8008B44C;
    }
    // 0x8008B444: nop

    // 0x8008B448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008B44C:
    // 0x8008B44C: beq         $v0, $zero, L_8008B4A0
    if (ctx->r2 == 0) {
        // 0x8008B450: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B450: nop

    // 0x8008B454: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8008B458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B45C: bc1f        L_8008B4A0
    if (!c1cs) {
        // 0x8008B460: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B460: nop

    // 0x8008B464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008B468: b           L_8008B4A0
    // 0x8008B46C: nop

        goto L_8008B4A0;
    // 0x8008B46C: nop

    // 0x8008B470: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
L_8008B474:
    // 0x8008B474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B478: bc1f        L_8008B484
    if (!c1cs) {
        // 0x8008B47C: nop
    
            goto L_8008B484;
    }
    // 0x8008B47C: nop

    // 0x8008B480: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008B484:
    // 0x8008B484: bne         $v0, $zero, L_8008B4A0
    if (ctx->r2 != 0) {
        // 0x8008B488: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B488: nop

    // 0x8008B48C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8008B490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B494: bc1f        L_8008B4A0
    if (!c1cs) {
        // 0x8008B498: nop
    
            goto L_8008B4A0;
    }
    // 0x8008B498: nop

    // 0x8008B49C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008B4A0:
    // 0x8008B4A0: jr          $ra
    // 0x8008B4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008B4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800218_chwandglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080021C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800224: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800228: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080022C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800230: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800234: beq         $t6, $at, L_80800264
    if (ctx->r14 == ctx->r1) {
        // 0x80800238: lui         $a2, 0x3ECC
        ctx->r6 = S32(0X3ECC << 16);
            goto L_80800264;
    }
    // 0x80800238: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8080023C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800240: beq         $t6, $at, L_808002A0
    if (ctx->r14 == ctx->r1) {
        // 0x80800244: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808002A0;
    }
    // 0x80800244: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800248: beq         $t6, $at, L_808002D4
    if (ctx->r14 == ctx->r1) {
        // 0x8080024C: lui         $a2, 0x3E99
        ctx->r6 = S32(0X3E99 << 16);
            goto L_808002D4;
    }
    // 0x8080024C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800250: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800254: beq         $t6, $at, L_80800318
    if (ctx->r14 == ctx->r1) {
        // 0x80800258: nop
    
            goto L_80800318;
    }
    // 0x80800258: nop

    // 0x8080025C: b           L_80800324
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800324;
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800264:
    // 0x80800264: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800268: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080026C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800270: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800274: jal         0x800F10B4
    // 0x80800278: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800278: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8080027C: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800280: jal         0x800D9078
    // 0x80800284: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800284: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x80800288: beq         $v0, $zero, L_80800320
    if (ctx->r2 == 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800320;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x8080011C
    // 0x80800294: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080011C_chwandglow(rdram, ctx);
        goto after_2;
    // 0x80800294: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800298: b           L_80800324
    // 0x8080029C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800324;
    // 0x8080029C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002A0:
    // 0x808002A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002A8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808002AC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808002B0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808002B4: nop

    // 0x808002B8: bc1f        L_808002CC
    if (!c1cs) {
        // 0x808002BC: nop
    
            goto L_808002CC;
    }
    // 0x808002BC: nop

    // 0x808002C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002C4: b           L_80800320
    // 0x808002C8: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
        goto L_80800320;
    // 0x808002C8: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
L_808002CC:
    // 0x808002CC: b           L_80800320
    // 0x808002D0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
        goto L_80800320;
    // 0x808002D0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_808002D4:
    // 0x808002D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002E0: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808002E4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808002E8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808002EC: jal         0x800F10B4
    // 0x808002F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808002F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808002F4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x808002F8: jal         0x800D9078
    // 0x808002FC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x808002FC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_4:
    // 0x80800300: beq         $v0, $zero, L_80800320
    if (ctx->r2 == 0) {
        // 0x80800304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800320;
    }
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x8080011C
    // 0x8080030C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080011C_chwandglow(rdram, ctx);
        goto after_5;
    // 0x8080030C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800310: b           L_80800324
    // 0x80800314: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800324;
    // 0x80800314: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800318:
    // 0x80800318: jal         0x800FFA88
    // 0x8080031C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_6;
    // 0x8080031C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
L_80800320:
    // 0x80800320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800324:
    // 0x80800324: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080032C: jr          $ra
    // 0x80800330: nop

    return;
    // 0x80800330: nop

;}
RECOMP_FUNC void func_800EDFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EDFC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EDFC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EDFC8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EDFCC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800EDFD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EDFD4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800EDFD8: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
    // 0x800EDFDC: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x800EDFE0: swc1        $f14, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f14.u32l;
    // 0x800EDFE4: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x800EDFE8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EDFEC: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x800EDFF0: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800EDFF4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800EDFF8: jal         0x800ED964
    // 0x800EDFFC: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    func_800ED964(rdram, ctx);
        goto after_0;
    // 0x800EDFFC: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    after_0:
    // 0x800EE000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EE004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EE008: jr          $ra
    // 0x800EE00C: nop

    return;
    // 0x800EE00C: nop

;}
RECOMP_FUNC void _bssnowball_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A68: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A68);
    return;
    // 0x80083A6C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_8080003C_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800040: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800044: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800048: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: bne         $a1, $at, L_808000A8
    if (ctx->r5 != ctx->r1) {
        // 0x80800054: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_808000A8;
    }
    // 0x80800054: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800058: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080005C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800060: jal         0x800EE7F8
    // 0x80800064: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800064: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800068: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080006C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800070: lui         $a2, 0xC316
    ctx->r6 = S32(0XC316 << 16);
    // 0x80800074: jal         0x800EF1B8
    // 0x80800078: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800078: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x8080007C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800080: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800084: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800088: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080008C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800090: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800094: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800098: jal         0x80086670
    // 0x8080009C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080009C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808000A0: b           L_808000C4
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C4;
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000A8:
    // 0x808000A8: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808000AC: bne         $a1, $at, L_808000C4
    if (ctx->r5 != ctx->r1) {
        // 0x808000B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000C4;
    }
    // 0x808000B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000B4: jal         0x808000D4
    // 0x808000B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808000D4_chfactoryroofbits(rdram, ctx);
        goto after_3;
    // 0x808000B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x808000BC: b           L_808000C4
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C4;
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C4:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void gcnewpause_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80087CA8
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _gcnewoption_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: jal         0x8001ACCC
    // 0x80800014: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x80800014: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    after_1:
    // 0x80800018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080001C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80800020: jal         0x8002D6E0
    // 0x80800024: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _bzero(rdram, ctx);
        goto after_2;
    // 0x80800024: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800028: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080002C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800034: jal         0x80800534
    // 0x80800038: sb          $t6, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r14;
    func_80800534_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x80800038: sb          $t6, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r14;
    after_3:
    // 0x8080003C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2658, 0X2124) << 16);
    // 0x80800044: lb          $t8, 0x2124($t8)
    ctx->r24 = MEM_B(ctx->r24, (int16_t)RELOC_LO16(2658, 0X2124));
    // 0x80800048: lb          $t7, 0x6($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X6);
    // 0x8080004C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2658, 0X2125) << 16);
    // 0x80800050: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2658, 0X2126) << 16);
    // 0x80800054: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80800058: sb          $t9, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r25;
    // 0x8080005C: lb          $t1, 0x2125($t1)
    ctx->r9 = MEM_B(ctx->r9, (int16_t)RELOC_LO16(2658, 0X2125));
    // 0x80800060: lb          $t0, 0x6($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X6);
    // 0x80800064: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2658, 0X212E) << 16);
    // 0x80800068: addiu       $v1, $v1, 0x212E
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2658, 0X212E));
    // 0x8080006C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800070: addiu       $v0, $v0, 0x2126
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2658, 0X2126));
    // 0x80800074: sb          $t2, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r10;
L_80800078:
    // 0x80800078: lb          $t3, 0x6($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X6);
    // 0x8080007C: lb          $t4, 0x0($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X0);
    // 0x80800080: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800084: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80800088: sb          $t5, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r13;
    // 0x8080008C: lb          $t6, 0x6($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X6);
    // 0x80800090: lb          $t7, -0x3($v0)
    ctx->r15 = MEM_B(ctx->r2, -0X3);
    // 0x80800094: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800098: sb          $t8, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r24;
    // 0x8080009C: lb          $t9, 0x6($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X6);
    // 0x808000A0: lb          $t0, -0x2($v0)
    ctx->r8 = MEM_B(ctx->r2, -0X2);
    // 0x808000A4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x808000A8: sb          $t1, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r9;
    // 0x808000AC: lb          $t2, 0x6($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X6);
    // 0x808000B0: lb          $t3, -0x1($v0)
    ctx->r11 = MEM_B(ctx->r2, -0X1);
    // 0x808000B4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x808000B8: bne         $v0, $v1, L_80800078
    if (ctx->r2 != ctx->r3) {
        // 0x808000BC: sb          $t4, 0x6($a2)
        MEM_B(0X6, ctx->r6) = ctx->r12;
            goto L_80800078;
    }
    // 0x808000BC: sb          $t4, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r12;
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void chanim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808000F0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000FC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800100: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800104: addiu       $a2, $a2, 0x5978
    ctx->r6 = ADD32(ctx->r6, 0X5978);
    // 0x80800108: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080010C: jal         0x80082628
    // 0x80800110: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800110: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_808040D4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808040D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808040DC: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x808040E0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x808040E4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x808040E8: bne         $t6, $at, L_808040F8
    if (ctx->r14 != ctx->r1) {
        // 0x808040EC: nop
    
            goto L_808040F8;
    }
    // 0x808040EC: nop

    // 0x808040F0: b           L_808040F8
    // 0x808040F4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
        goto L_808040F8;
    // 0x808040F4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_808040F8:
    // 0x808040F8: jal         0x80804170
    // 0x808040FC: nop

    func_80804170_chquiz(rdram, ctx);
        goto after_0;
    // 0x808040FC: nop

    after_0:
    // 0x80804100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804108: jr          $ra
    // 0x8080410C: nop

    return;
    // 0x8080410C: nop

;}
RECOMP_FUNC void func_80801800_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801808: jal         0x80800128
    // 0x8080180C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bskazfly(rdram, ctx);
        goto after_0;
    // 0x8080180C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801810: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80801814: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080181C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801820: jal         0x80084C30
    // 0x80801824: addiu       $a2, $zero, 0x11C
    ctx->r6 = ADD32(0, 0X11C);
    _bafly_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80801824: addiu       $a2, $zero, 0x11C
    ctx->r6 = ADD32(0, 0X11C);
    after_1:
    // 0x80801828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080182C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801830: jr          $ra
    // 0x80801834: nop

    return;
    // 0x80801834: nop

;}
RECOMP_FUNC void func_800E7D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7D4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800E7D50: lh          $t6, 0x7752($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X7752);
    // 0x800E7D54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7D58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E7D5C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E7D60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E7D64: lh          $a3, 0x7750($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7750);
    // 0x800E7D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E7D6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E7D70: jal         0x800E7A90
    // 0x800E7D74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800E7A90(rdram, ctx);
        goto after_0;
    // 0x800E7D74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800E7D78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800E7D7C: lh          $t7, 0x7752($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7752);
    // 0x800E7D80: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E7D84: lh          $a3, 0x7750($a3)
    ctx->r7 = MEM_H(ctx->r7, 0X7750);
    // 0x800E7D88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E7D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E7D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E7D94: jal         0x800BC580
    // 0x800E7D98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800BC580(rdram, ctx);
        goto after_1;
    // 0x800E7D98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x800E7D9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7DA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7DA4: jr          $ra
    // 0x800E7DA8: nop

    return;
    // 0x800E7DA8: nop

;}
RECOMP_FUNC void func_80801560_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801568: jal         0x80082FF0
    // 0x8080156C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080156C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801570: jal         0x80800238
    // 0x80801574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80801574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080157C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801580: jr          $ra
    // 0x80801584: nop

    return;
    // 0x80801584: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080081C: lbu         $v0, 0x15D($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15D);
    // 0x80800820: beq         $v0, $zero, L_8080082C
    if (ctx->r2 == 0) {
        // 0x80800824: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8080082C;
    }
    // 0x80800824: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800828: sb          $t6, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = ctx->r14;
L_8080082C:
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void _bsstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B90: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083B90);
    return;
    // 0x80083B94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void boot_osGetThreadPri(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void _basquash_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850C0: syscall     150
    recomp_syscall_handler(rdram, ctx, 0x800850C0);
    return;
    // 0x800850C4: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void func_808050B0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808050B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808050B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808050B8: jal         0x80082FF0
    // 0x808050BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808050BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808050C0: jal         0x80807C8C
    // 0x808050C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808050C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808050C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808050CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808050D0: jr          $ra
    // 0x808050D4: nop

    return;
    // 0x808050D4: nop

;}
RECOMP_FUNC void func_808018F4_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801900: jal         0x800A0CF4
    // 0x80801904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x80801904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801908: jal         0x80084C40
    // 0x8080190C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bafly_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x8080190C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801910: jal         0x80800188
    // 0x80801914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800188_bsbfly(rdram, ctx);
        goto after_2;
    // 0x80801914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080191C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801920: jr          $ra
    // 0x80801924: nop

    return;
    // 0x80801924: nop

;}
RECOMP_FUNC void func_80800BCC_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BCC: jr          $ra
    // 0x80800BD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800BD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void gldbDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808003F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808003FC: jal         0x80088500
    // 0x80800400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    _gleeprom_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800404: jal         0x80088458
    // 0x80800408: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    _glreflight_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800408: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_1:
    // 0x8080040C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80800410: lw          $t6, -0x60A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X60A4);
    // 0x80800414: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800418: or          $t7, $v0, $t6
    ctx->r15 = ctx->r2 | ctx->r14;
    // 0x8080041C: or          $s1, $t7, $s2
    ctx->r17 = ctx->r15 | ctx->r18;
    // 0x80800420: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80800424:
    // 0x80800424: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x80800428: and         $t0, $t9, $s1
    ctx->r8 = ctx->r25 & ctx->r17;
    // 0x8080042C: srlv        $a1, $t0, $s0
    ctx->r5 = S32(U32(ctx->r8) >> (ctx->r16 & 31));
    // 0x80800430: jal         0x800DA3B8
    // 0x80800434: addiu       $a0, $s0, 0x648
    ctx->r4 = ADD32(ctx->r16, 0X648);
    func_800DA3B8(rdram, ctx);
        goto after_2;
    // 0x80800434: addiu       $a0, $s0, 0x648
    ctx->r4 = ADD32(ctx->r16, 0X648);
    after_2:
    // 0x80800438: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080043C: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80800440: bnel        $at, $zero, L_80800424
    if (ctx->r1 != 0) {
        // 0x80800444: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80800424;
    }
    goto skip_0;
    // 0x80800444: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_0:
    // 0x80800448: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x8080044C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80800450:
    // 0x80800450: sllv        $t2, $t1, $s0
    ctx->r10 = S32(ctx->r9 << (ctx->r16 & 31));
    // 0x80800454: and         $t3, $t2, $s1
    ctx->r11 = ctx->r10 & ctx->r17;
    // 0x80800458: srlv        $a1, $t3, $s0
    ctx->r5 = S32(U32(ctx->r11) >> (ctx->r16 & 31));
    // 0x8080045C: jal         0x800DA3B8
    // 0x80800460: addiu       $a0, $s0, 0x658
    ctx->r4 = ADD32(ctx->r16, 0X658);
    func_800DA3B8(rdram, ctx);
        goto after_3;
    // 0x80800460: addiu       $a0, $s0, 0x658
    ctx->r4 = ADD32(ctx->r16, 0X658);
    after_3:
    // 0x80800464: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800468: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x8080046C: bnel        $at, $zero, L_80800450
    if (ctx->r1 != 0) {
        // 0x80800470: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80800450;
    }
    goto skip_1;
    // 0x80800470: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_1:
    // 0x80800474: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x80800478: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8080047C:
    // 0x8080047C: sllv        $t5, $t4, $s0
    ctx->r13 = S32(ctx->r12 << (ctx->r16 & 31));
    // 0x80800480: and         $t6, $t5, $s1
    ctx->r14 = ctx->r13 & ctx->r17;
    // 0x80800484: srlv        $a1, $t6, $s0
    ctx->r5 = S32(U32(ctx->r14) >> (ctx->r16 & 31));
    // 0x80800488: jal         0x800DA3B8
    // 0x8080048C: addiu       $a0, $s0, 0x670
    ctx->r4 = ADD32(ctx->r16, 0X670);
    func_800DA3B8(rdram, ctx);
        goto after_4;
    // 0x8080048C: addiu       $a0, $s0, 0x670
    ctx->r4 = ADD32(ctx->r16, 0X670);
    after_4:
    // 0x80800490: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800494: slti        $at, $s0, 0x18
    ctx->r1 = SIGNED(ctx->r16) < 0X18 ? 1 : 0;
    // 0x80800498: bnel        $at, $zero, L_8080047C
    if (ctx->r1 != 0) {
        // 0x8080049C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8080047C;
    }
    goto skip_2;
    // 0x8080049C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_2:
    // 0x808004A0: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x808004A4: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x808004A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_808004AC:
    // 0x808004AC: sllv        $t8, $t7, $s0
    ctx->r24 = S32(ctx->r15 << (ctx->r16 & 31));
    // 0x808004B0: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x808004B4: srlv        $a1, $t9, $s0
    ctx->r5 = S32(U32(ctx->r25) >> (ctx->r16 & 31));
    // 0x808004B8: jal         0x800DA3B8
    // 0x808004BC: addiu       $a0, $s0, 0x680
    ctx->r4 = ADD32(ctx->r16, 0X680);
    func_800DA3B8(rdram, ctx);
        goto after_5;
    // 0x808004BC: addiu       $a0, $s0, 0x680
    ctx->r4 = ADD32(ctx->r16, 0X680);
    after_5:
    // 0x808004C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004C4: bnel        $s0, $s2, L_808004AC
    if (ctx->r16 != ctx->r18) {
        // 0x808004C8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_808004AC;
    }
    goto skip_3;
    // 0x808004C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_3:
    // 0x808004CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808004D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808004DC: jr          $ra
    // 0x808004E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808004E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004E4: nop

    // 0x808004E8: nop

    // 0x808004EC: nop

;}
RECOMP_FUNC void func_80803470_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803470: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080347C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80803480: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803484: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803488: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080348C: beq         $t6, $at, L_80803574
    if (ctx->r14 == ctx->r1) {
        // 0x80803490: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80803574;
    }
    // 0x80803490: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803494: beq         $t6, $at, L_808034AC
    if (ctx->r14 == ctx->r1) {
        // 0x80803498: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808034AC;
    }
    // 0x80803498: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080349C: beq         $t6, $at, L_80803540
    if (ctx->r14 == ctx->r1) {
        // 0x808034A0: nop
    
            goto L_80803540;
    }
    // 0x808034A0: nop

    // 0x808034A4: b           L_80803578
    // 0x808034A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803578;
    // 0x808034A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808034AC:
    // 0x808034AC: jal         0x80101DDC
    // 0x808034B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x808034B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808034B4: beq         $v0, $zero, L_808034D8
    if (ctx->r2 == 0) {
        // 0x808034B8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808034D8;
    }
    // 0x808034B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808034BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808034C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808034C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808034C8: jal         0x80102424
    // 0x808034CC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808034CC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x808034D0: b           L_80803578
    // 0x808034D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803578;
    // 0x808034D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808034D8:
    // 0x808034D8: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808034DC: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x808034E0: jal         0x808000E0
    // 0x808034E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_808000E0_chquiz(rdram, ctx);
        goto after_2;
    // 0x808034E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x808034E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808034EC: jal         0x80101E14
    // 0x808034F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x808034F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808034F4: beql        $v0, $zero, L_80803578
    if (ctx->r2 == 0) {
        // 0x808034F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803578;
    }
    goto skip_0;
    // 0x808034F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808034FC: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80803500: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x80803504: bgezl       $t0, L_80803528
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80803508: lw          $a0, 0x24($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X24);
            goto L_80803528;
    }
    goto skip_1;
    // 0x80803508: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x8080350C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80803510: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80803514: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80803518: srl         $t1, $a1, 7
    ctx->r9 = S32(U32(ctx->r5) >> 7);
    // 0x8080351C: jal         0x8008A898
    // 0x80803520: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _suquiz_entrypoint_28(rdram, ctx);
        goto after_4;
    // 0x80803520: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_4:
    // 0x80803524: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_80803528:
    // 0x80803528: beql        $a0, $zero, L_80803578
    if (ctx->r4 == 0) {
        // 0x8080352C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803578;
    }
    goto skip_2;
    // 0x8080352C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80803530: jal         0x800C8FE0
    // 0x80803534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_5;
    // 0x80803534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80803538: b           L_80803578
    // 0x8080353C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803578;
    // 0x8080353C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803540:
    // 0x80803540: jal         0x800D90A4
    // 0x80803544: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x80803544: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x80803548: beql        $v0, $zero, L_80803578
    if (ctx->r2 == 0) {
        // 0x8080354C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803578;
    }
    goto skip_3;
    // 0x8080354C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80803550: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80803554: beql        $a0, $zero, L_8080356C
    if (ctx->r4 == 0) {
        // 0x80803558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080356C;
    }
    goto skip_4;
    // 0x80803558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8080355C: jal         0x800C8B84
    // 0x80803560: nop

    func_800C8B84(rdram, ctx);
        goto after_7;
    // 0x80803560: nop

    after_7:
    // 0x80803564: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80803568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080356C:
    // 0x8080356C: jal         0x80102424
    // 0x80803570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80803570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_80803574:
    // 0x80803574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803578:
    // 0x80803578: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080357C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803580: jr          $ra
    // 0x80803584: nop

    return;
    // 0x80803584: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029F8: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x808029FC: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80802A00: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80802A04: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(439, 0XAC02) << 16);
    // 0x80802A08: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80802A0C: lbu         $a1, -0x53FE($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(439, 0XAC02));
    // 0x80802A10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802A18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802A1C: jal         0x800A18C8
    // 0x80802A20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A18C8(rdram, ctx);
        goto after_0;
    // 0x80802A20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802A24: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80802A28: jal         0x800A1870
    // 0x80802A2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A1870(rdram, ctx);
        goto after_1;
    // 0x80802A2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80802A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802A34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802A38: jr          $ra
    // 0x80802A3C: nop

    return;
    // 0x80802A3C: nop

;}
RECOMP_FUNC void func_808023B0_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808023B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808023B8: jal         0x80100094
    // 0x808023BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808023BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808023C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D78) << 16);
    // 0x808023C4: lwc1        $f2, 0x2D78($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D78));
    // 0x808023C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(832, 0X2D7C) << 16);
    // 0x808023CC: lwc1        $f0, 0x2D7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2D7C));
    // 0x808023D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808023D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808023D8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808023DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_808023E0:
    // 0x808023E0: lbu         $t6, 0x487($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X487);
    // 0x808023E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808023E8: bnel        $a0, $t6, L_808023FC
    if (ctx->r4 != ctx->r14) {
        // 0x808023EC: lbu         $t7, 0x488($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X488);
            goto L_808023FC;
    }
    goto skip_0;
    // 0x808023EC: lbu         $t7, 0x488($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X488);
    skip_0:
    // 0x808023F0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808023F4: nop

    // 0x808023F8: lbu         $t7, 0x488($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X488);
L_808023FC:
    // 0x808023FC: bnel        $a0, $t7, L_80802410
    if (ctx->r4 != ctx->r15) {
        // 0x80802400: lbu         $t8, 0x489($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X489);
            goto L_80802410;
    }
    goto skip_1;
    // 0x80802400: lbu         $t8, 0x489($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X489);
    skip_1:
    // 0x80802404: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80802408: nop

    // 0x8080240C: lbu         $t8, 0x489($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X489);
L_80802410:
    // 0x80802410: bnel        $a0, $t8, L_80802424
    if (ctx->r4 != ctx->r24) {
        // 0x80802414: lbu         $t9, 0x48A($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X48A);
            goto L_80802424;
    }
    goto skip_2;
    // 0x80802414: lbu         $t9, 0x48A($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X48A);
    skip_2:
    // 0x80802418: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8080241C: nop

    // 0x80802420: lbu         $t9, 0x48A($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X48A);
L_80802424:
    // 0x80802424: bne         $a0, $t9, L_80802434
    if (ctx->r4 != ctx->r25) {
        // 0x80802428: nop
    
            goto L_80802434;
    }
    // 0x80802428: nop

    // 0x8080242C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80802430: nop

L_80802434:
    // 0x80802434: bne         $a1, $a2, L_808023E0
    if (ctx->r5 != ctx->r6) {
        // 0x80802438: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808023E0;
    }
    // 0x80802438: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080243C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802444: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80802448: jr          $ra
    // 0x8080244C: nop

    return;
    // 0x8080244C: nop

;}
RECOMP_FUNC void func_8010856C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010856C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80108570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80108574: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80108578: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8010857C: jal         0x800EE904
    // 0x80108580: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x80108580: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80108584: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80108588: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8010858C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80108590: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80108594: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80108598: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8010859C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801085A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801085A4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801085A8: jal         0x80108DC0
    // 0x801085AC: nop

    func_80108DC0(rdram, ctx);
        goto after_1;
    // 0x801085AC: nop

    after_1:
    // 0x801085B0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x801085B4: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801085B8: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x801085BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801085C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801085C4: jr          $ra
    // 0x801085C8: nop

    return;
    // 0x801085C8: nop

;}
RECOMP_FUNC void func_8009D9D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D9D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009D9D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D9DC: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009D9E0: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x8009D9E4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8009D9E8: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x8009D9EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009D9F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009D9F4: jal         0x800846C8
    // 0x8009D9F8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x8009D9F8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8009D9FC: bne         $v0, $zero, L_8009DA10
    if (ctx->r2 != 0) {
        // 0x8009DA00: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8009DA10;
    }
    // 0x8009DA00: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009DA04: lw          $t8, 0x104($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X104);
    // 0x8009DA08: b           L_8009DA20
    // 0x8009DA0C: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
        goto L_8009DA20;
    // 0x8009DA0C: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
L_8009DA10:
    // 0x8009DA10: lw          $v0, 0x104($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X104);
    // 0x8009DA14: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8009DA18: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8009DA1C: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_8009DA20:
    // 0x8009DA20: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8009DA24: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DA28: jal         0x8009D940
    // 0x8009DA2C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8009D940(rdram, ctx);
        goto after_1;
    // 0x8009DA2C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8009DA30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DA34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009DA38: jr          $ra
    // 0x8009DA3C: nop

    return;
    // 0x8009DA3C: nop

;}
RECOMP_FUNC void glcrc_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800170: addu        $a1, $a0, $a1
    ctx->r5 = ADD32(ctx->r4, ctx->r5);
    // 0x80800174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800178: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x8080017C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800180: jal         0x80800000
    // 0x80800184: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_80800000_glcrc(rdram, ctx);
        goto after_0;
    // 0x80800184: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80800188: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080018C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800194: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80800198: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080019C: lui         $v1, 0x6
    ctx->r3 = S32(0X6 << 16);
    // 0x808001A0: bne         $t6, $t7, L_808001B4
    if (ctx->r14 != ctx->r15) {
        // 0x808001A4: nop
    
            goto L_808001B4;
    }
    // 0x808001A4: nop

    // 0x808001A8: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x808001AC: beql        $t8, $t9, L_808001C0
    if (ctx->r24 == ctx->r25) {
        // 0x808001B0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808001C0;
    }
    goto skip_0;
    // 0x808001B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_0:
L_808001B4:
    // 0x808001B4: b           L_808001C0
    // 0x808001B8: ori         $v1, $v1, 0xE382
    ctx->r3 = ctx->r3 | 0XE382;
        goto L_808001C0;
    // 0x808001B8: ori         $v1, $v1, 0xE382
    ctx->r3 = ctx->r3 | 0XE382;
    // 0x808001BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808001C0:
    // 0x808001C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808001C4: jr          $ra
    // 0x808001C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_8080003C_chdinotraindoorswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800048: jal         0x80085808
    // 0x8080004C: addiu       $a1, $zero, 0x164
    ctx->r5 = ADD32(0, 0X164);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a1, $zero, 0x164
    ctx->r5 = ADD32(0, 0X164);
    after_0:
    // 0x80800050: jal         0x80085818
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800058: jal         0x80104E78
    // 0x8080005C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80104E78(rdram, ctx);
        goto after_2;
    // 0x8080005C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
