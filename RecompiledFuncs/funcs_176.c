#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80016A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A04: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80016A08: lw          $t6, -0xA10($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XA10);
    // 0x80016A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016A14: bne         $t6, $zero, L_80016A24
    if (ctx->r14 != 0) {
        // 0x80016A18: nop
    
            goto L_80016A24;
    }
    // 0x80016A18: nop

    // 0x80016A1C: jal         0x800169B4
    // 0x80016A20: nop

    func_800169B4(rdram, ctx);
        goto after_0;
    // 0x80016A20: nop

    after_0:
L_80016A24:
    // 0x80016A24: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016A28: addiu       $a0, $a0, -0x6090
    ctx->r4 = ADD32(ctx->r4, -0X6090);
    // 0x80016A2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016A30: jal         0x8002E1F0
    // 0x80016A34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80016A34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80016A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016A40: jr          $ra
    // 0x80016A44: nop

    return;
    // 0x80016A44: nop

;}
RECOMP_FUNC void func_8080000C_chbigfoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x8008A0F8
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

    // 0x8080002C: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808019FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A00: jal         0x800BF704
    // 0x80801A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80801A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A08: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801A0C: beq         $a1, $zero, L_80801A3C
    if (ctx->r5 == 0) {
        // 0x80801A10: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_80801A3C;
    }
    // 0x80801A10: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80801A14: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801A18: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80801A1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801A20: sb          $a1, 0x76($v0)
    MEM_B(0X76, ctx->r2) = ctx->r5;
    // 0x80801A24: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80801A28: sll         $a0, $t6, 3
    ctx->r4 = S32(ctx->r14 << 3);
    // 0x80801A2C: jal         0x8001ACCC
    // 0x80801A30: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x80801A30: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801A34: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A38: sw          $v0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r2;
L_80801A3C:
    // 0x80801A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801A44: jr          $ra
    // 0x80801A48: nop

    return;
    // 0x80801A48: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AB0: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082AB0);
    return;
    // 0x80082AB4: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void capod_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: jal         0x8008FFE8
    // 0x808004B4: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808004B4: nop

    after_0:
    // 0x808004B8: beq         $v0, $zero, L_808004D0
    if (ctx->r2 == 0) {
        // 0x808004BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808004D0;
    }
    // 0x808004BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004C0: jal         0x800895B0
    // 0x808004C4: nop

    _ncpod_entrypoint_30(rdram, ctx);
        goto after_1;
    // 0x808004C4: nop

    after_1:
    // 0x808004C8: b           L_808004DC
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004DC;
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004D0:
    // 0x808004D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808004D4: nop

    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004DC:
    // 0x808004DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E0: jr          $ra
    // 0x808004E4: nop

    return;
    // 0x808004E4: nop

;}
RECOMP_FUNC void func_800F1800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1808: jal         0x80013AAC
    // 0x800F180C: nop

    func_80013AAC(rdram, ctx);
        goto after_0;
    // 0x800F180C: nop

    after_0:
    // 0x800F1810: jal         0x800F2100
    // 0x800F1814: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800F1814: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800F1818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F181C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1820: jr          $ra
    // 0x800F1824: nop

    return;
    // 0x800F1824: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800AF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800AF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800AFC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800B00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B04: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800B08: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800B0C: jal         0x800CB4D0
    // 0x80800B10: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800CB4D0(rdram, ctx);
        goto after_0;
    // 0x80800B10: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80800B14: beq         $v0, $zero, L_80800B50
    if (ctx->r2 == 0) {
        // 0x80800B18: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80800B50;
    }
    // 0x80800B18: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800B1C: jal         0x800EA05C
    // 0x80800B20: nop

    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80800B20: nop

    after_1:
    // 0x80800B24: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800B28: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800B30: lhu         $t6, 0x76($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X76);
    // 0x80800B34: lw          $a2, 0x48($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X48);
    // 0x80800B38: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80800B3C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800B40: jal         0x800CB764
    // 0x80800B44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800CB764(rdram, ctx);
        goto after_2;
    // 0x80800B44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x80800B48: jal         0x800CB70C
    // 0x80800B4C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800CB70C(rdram, ctx);
        goto after_3;
    // 0x80800B4C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
L_80800B50:
    // 0x80800B50: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800B54: lui         $t8, 0x42
    ctx->r24 = S32(0X42 << 16);
    // 0x80800B58: ori         $t8, $t8, 0x21
    ctx->r24 = ctx->r24 | 0X21;
    // 0x80800B5C: sw          $t8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r24;
    // 0x80800B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B64: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800B68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B6C: jr          $ra
    // 0x80800B70: nop

    return;
    // 0x80800B70: nop

;}
RECOMP_FUNC void _chjinjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B80: syscall     425
    recomp_syscall_handler(rdram, ctx, 0x80086B80);
    return;
    // 0x80086B84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800B8148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B814C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B8150: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800B8154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8158: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B815C: lbu         $a0, -0x7D3A($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7D3A);
    // 0x800B8160: jal         0x800D35D0
    // 0x800B8164: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    func_800D35D0(rdram, ctx);
        goto after_0;
    // 0x800B8164: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    after_0:
    // 0x800B8168: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B816C: bne         $v0, $at, L_800B817C
    if (ctx->r2 != ctx->r1) {
        // 0x800B8170: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_800B817C;
    }
    // 0x800B8170: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B8174: b           L_800B81BC
    // 0x800B8178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B81BC;
    // 0x800B8178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B817C:
    // 0x800B817C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8180: jal         0x800D3524
    // 0x800B8184: lbu         $a0, -0x7D3A($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7D3A);
    func_800D3524(rdram, ctx);
        goto after_1;
    // 0x800B8184: lbu         $a0, -0x7D3A($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X7D3A);
    after_1:
    // 0x800B8188: bne         $v0, $zero, L_800B8198
    if (ctx->r2 != 0) {
        // 0x800B818C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800B8198;
    }
    // 0x800B818C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B8190: b           L_800B81BC
    // 0x800B8194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B81BC;
    // 0x800B8194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B8198:
    // 0x800B8198: jal         0x800B0D58
    // 0x800B819C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800B0D58(rdram, ctx);
        goto after_2;
    // 0x800B819C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x800B81A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B81A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800B81A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800B81AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B81B0: sw          $v0, -0x7D30($at)
    MEM_W(-0X7D30, ctx->r1) = ctx->r2;
    // 0x800B81B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B81B8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
L_800B81BC:
    // 0x800B81BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B81C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B81C4: jr          $ra
    // 0x800B81C8: nop

    return;
    // 0x800B81C8: nop

;}
RECOMP_FUNC void func_808001F8_chwaterfallfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x808001FC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800200: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800204: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800208: addiu       $s2, $sp, 0xA4
    ctx->r18 = ADD32(ctx->r29, 0XA4);
    // 0x8080020C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800210: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80800214: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80800218: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8080021C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80800220: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80800224: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80800228: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8080022C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800230: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800234: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800238: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8080023C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800240: jal         0x800E3980
    // 0x80800244: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80800244: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80800248: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800250: jal         0x800EEB40
    // 0x80800254: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x80800254: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80800258: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1524, 0X404) << 16);
    // 0x8080025C: lwc1        $f4, 0x404($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1524, 0X404));
    // 0x80800260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800264: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800268: nop

    // 0x8080026C: bc1fl       L_808003BC
    if (!c1cs) {
        // 0x80800270: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_808003BC;
    }
    goto skip_0;
    // 0x80800270: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x80800274: jal         0x800E3E8C
    // 0x80800278: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_800E3E8C(rdram, ctx);
        goto after_2;
    // 0x80800278: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x8080027C: beql        $v0, $zero, L_808003BC
    if (ctx->r2 == 0) {
        // 0x80800280: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_808003BC;
    }
    goto skip_1;
    // 0x80800280: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_1:
    // 0x80800284: jal         0x800B5BE4
    // 0x80800288: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_800B5BE4(rdram, ctx);
        goto after_3;
    // 0x80800288: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_3:
    // 0x8080028C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800290: jal         0x800D8FF8
    // 0x80800294: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800294: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    after_4:
    // 0x80800298: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8080029C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002A4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808002A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808002AC: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(1524, 0X478) << 16);
    // 0x808002B0: addiu       $s7, $s7, 0x478
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(1524, 0X478));
    // 0x808002B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1524, 0X408) << 16);
    // 0x808002B8: addiu       $s5, $s0, 0x28
    ctx->r21 = ADD32(ctx->r16, 0X28);
    // 0x808002BC: addiu       $s6, $s0, 0x18
    ctx->r22 = ADD32(ctx->r16, 0X18);
    // 0x808002C0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x808002C4: addiu       $s2, $sp, 0x8C
    ctx->r18 = ADD32(ctx->r29, 0X8C);
    // 0x808002C8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x808002CC: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002D0: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x808002D4: nop

    // 0x808002D8: bc1f        L_80800300
    if (!c1cs) {
        // 0x808002DC: nop
    
            goto L_80800300;
    }
    // 0x808002DC: nop

    // 0x808002E0: sub.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f20.fl;
L_808002E4:
    // 0x808002E4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808002E8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x808002EC: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002F0: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x808002F4: nop

    // 0x808002F8: bc1tl       L_808002E4
    if (c1cs) {
        // 0x808002FC: sub.s       $f18, $f2, $f20
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f20.fl;
            goto L_808002E4;
    }
    goto skip_2;
    // 0x808002FC: sub.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f20.fl;
    skip_2:
L_80800300:
    // 0x80800300: blez        $s4, L_808003B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80800304: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_808003B8;
    }
    // 0x80800304: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800308: lwc1        $f28, 0x408($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1524, 0X408));
    // 0x8080030C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800310: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800314: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800318: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080031C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800320: addiu       $s1, $sp, 0x80
    ctx->r17 = ADD32(ctx->r29, 0X80);
    // 0x80800324: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_80800328:
    // 0x80800328: jal         0x800DC178
    // 0x8080032C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x8080032C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_5:
    // 0x80800330: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800334: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800338: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8080033C: jal         0x800EFE50
    // 0x80800340: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800EFE50(rdram, ctx);
        goto after_6;
    // 0x80800340: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_6:
    // 0x80800344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800348: jal         0x800EE7F8
    // 0x8080034C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080034C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80800350: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800354: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800358: jal         0x800EF1B8
    // 0x8080035C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x8080035C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_8:
    // 0x80800360: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80800364: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080036C: add.s       $f8, $f4, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x80800370: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800374: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x80800378: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080037C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x80800380: mul.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x80800384: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800388: jal         0x800BABB8
    // 0x8080038C: nop

    func_800BABB8(rdram, ctx);
        goto after_9;
    // 0x8080038C: nop

    after_9:
    // 0x80800390: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x80800394: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80800398: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8080039C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808003A0: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808003A4: bne         $at, $zero, L_808003B0
    if (ctx->r1 != 0) {
        // 0x808003A8: sw          $t7, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r15;
            goto L_808003B0;
    }
    // 0x808003A8: sw          $t7, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r15;
    // 0x808003AC: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
L_808003B0:
    // 0x808003B0: bnel        $s3, $s4, L_80800328
    if (ctx->r19 != ctx->r20) {
        // 0x808003B4: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_80800328;
    }
    goto skip_3;
    // 0x808003B4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_3:
L_808003B8:
    // 0x808003B8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_808003BC:
    // 0x808003BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808003C0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808003C4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808003C8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x808003CC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x808003D0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808003D4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x808003D8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x808003DC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x808003E0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x808003E4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x808003E8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x808003EC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x808003F0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x808003F4: jr          $ra
    // 0x808003F8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x808003F8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x808003FC: nop

;}
RECOMP_FUNC void func_800A759C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A759C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A75A0: lh          $v0, 0x7632($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7632);
    // 0x800A75A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A75A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A75AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A75B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A75B4: bne         $v0, $at, L_800A75C4
    if (ctx->r2 != ctx->r1) {
        // 0x800A75B8: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_800A75C4;
    }
    // 0x800A75B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800A75BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A75C0: bne         $a0, $at, L_800A75D8
    if (ctx->r4 != ctx->r1) {
        // 0x800A75C4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A75D8;
    }
L_800A75C4:
    // 0x800A75C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A75C8: bne         $v0, $at, L_800A75EC
    if (ctx->r2 != ctx->r1) {
        // 0x800A75CC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A75EC;
    }
    // 0x800A75CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A75D0: beql        $a0, $at, L_800A75F0
    if (ctx->r4 == ctx->r1) {
        // 0x800A75D4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A75F0;
    }
    goto skip_0;
    // 0x800A75D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_0:
L_800A75D8:
    // 0x800A75D8: jal         0x800C9B84
    // 0x800A75DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800C9B84(rdram, ctx);
        goto after_0;
    // 0x800A75DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A75E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A75E4: lh          $v0, 0x7632($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7632);
    // 0x800A75E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800A75EC:
    // 0x800A75EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800A75F0:
    // 0x800A75F0: bne         $v0, $at, L_800A7614
    if (ctx->r2 != ctx->r1) {
        // 0x800A75F4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A7614;
    }
    // 0x800A75F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A75F8: beql        $a0, $at, L_800A7618
    if (ctx->r4 == ctx->r1) {
        // 0x800A75FC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A7618;
    }
    goto skip_1;
    // 0x800A75FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_1:
    // 0x800A7600: jal         0x800C0920
    // 0x800A7604: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800C0920(rdram, ctx);
        goto after_1;
    // 0x800A7604: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x800A7608: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A760C: lh          $v0, 0x7632($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7632);
    // 0x800A7610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800A7614:
    // 0x800A7614: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_800A7618:
    // 0x800A7618: bne         $v0, $at, L_800A762C
    if (ctx->r2 != ctx->r1) {
        // 0x800A761C: nop
    
            goto L_800A762C;
    }
    // 0x800A761C: nop

    // 0x800A7620: jal         0x800A9AF8
    // 0x800A7624: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A9AF8(rdram, ctx);
        goto after_2;
    // 0x800A7624: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x800A7628: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800A762C:
    // 0x800A762C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7630: sh          $a0, 0x7632($at)
    MEM_H(0X7632, ctx->r1) = ctx->r4;
    // 0x800A7634: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7638: lh          $v0, 0x7632($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7632);
    // 0x800A763C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A7640: beq         $v0, $at, L_800A7668
    if (ctx->r2 == ctx->r1) {
        // 0x800A7644: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A7668;
    }
    // 0x800A7644: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A7648: beq         $v0, $at, L_800A7680
    if (ctx->r2 == ctx->r1) {
        // 0x800A764C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A7680;
    }
    // 0x800A764C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A7650: beq         $v0, $at, L_800A76CC
    if (ctx->r2 == ctx->r1) {
        // 0x800A7654: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A76CC;
    }
    // 0x800A7654: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A7658: beq         $v0, $at, L_800A7678
    if (ctx->r2 == ctx->r1) {
        // 0x800A765C: nop
    
            goto L_800A7678;
    }
    // 0x800A765C: nop

    // 0x800A7660: b           L_800A76E8
    // 0x800A7664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76E8;
    // 0x800A7664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7668:
    // 0x800A7668: jal         0x800EA148
    // 0x800A766C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800EA148(rdram, ctx);
        goto after_3;
    // 0x800A766C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x800A7670: b           L_800A76E8
    // 0x800A7674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76E8;
    // 0x800A7674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7678:
    // 0x800A7678: jal         0x800A9998
    // 0x800A767C: nop

    func_800A9998(rdram, ctx);
        goto after_4;
    // 0x800A767C: nop

    after_4:
L_800A7680:
    // 0x800A7680: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7684: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A7688: beql        $t6, $at, L_800A769C
    if (ctx->r14 == ctx->r1) {
        // 0x800A768C: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_800A769C;
    }
    goto skip_2;
    // 0x800A768C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800A7690: jal         0x800EA148
    // 0x800A7694: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800EA148(rdram, ctx);
        goto after_5;
    // 0x800A7694: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x800A7698: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_800A769C:
    // 0x800A769C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A76A0: beql        $t7, $zero, L_800A76C0
    if (ctx->r15 == 0) {
        // 0x800A76A4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800A76C0;
    }
    goto skip_3;
    // 0x800A76A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_3:
    // 0x800A76A8: lbu         $t8, 0x7647($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7647);
    // 0x800A76AC: bnel        $t8, $zero, L_800A76C0
    if (ctx->r24 != 0) {
        // 0x800A76B0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800A76C0;
    }
    goto skip_4;
    // 0x800A76B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_4:
    // 0x800A76B4: jal         0x800C9598
    // 0x800A76B8: nop

    func_800C9598(rdram, ctx);
        goto after_6;
    // 0x800A76B8: nop

    after_6:
    // 0x800A76BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800A76C0:
    // 0x800A76C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A76C4: b           L_800A76E4
    // 0x800A76C8: swc1        $f4, 0x763C($at)
    MEM_W(0X763C, ctx->r1) = ctx->f4.u32l;
        goto L_800A76E4;
    // 0x800A76C8: swc1        $f4, 0x763C($at)
    MEM_W(0X763C, ctx->r1) = ctx->f4.u32l;
L_800A76CC:
    // 0x800A76CC: jal         0x800EA334
    // 0x800A76D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800EA334(rdram, ctx);
        goto after_7;
    // 0x800A76D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A76D4: jal         0x8001608C
    // 0x800A76D8: nop

    func_8001608C(rdram, ctx);
        goto after_8;
    // 0x800A76D8: nop

    after_8:
    // 0x800A76DC: jal         0x800C08F8
    // 0x800A76E0: nop

    func_800C08F8(rdram, ctx);
        goto after_9;
    // 0x800A76E0: nop

    after_9:
L_800A76E4:
    // 0x800A76E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A76E8:
    // 0x800A76E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A76EC: jr          $ra
    // 0x800A76F0: nop

    return;
    // 0x800A76F0: nop

;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083768: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083768);
    return;
    // 0x8008376C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80111410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111410: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80111414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111418: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8011141C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80111420: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80111424: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80111428: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8011142C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80111430: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80111434: jal         0x80013728
    // 0x80111438: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_0;
    // 0x80111438: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8011143C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80111440: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80111444: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80111448: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8011144C: jal         0x80013728
    // 0x80111450: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x80111450: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_1:
    // 0x80111454: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80111458: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8011145C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80111460: lwc1        $f18, 0x8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80111464: jal         0x80013728
    // 0x80111468: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    func_80013728(rdram, ctx);
        goto after_2;
    // 0x80111468: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_2:
    // 0x8011146C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80111470: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80111474: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80111478: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8011147C: nop

    // 0x80111480: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80111484: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80111488: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8011148C: jal         0x8002DCA0
    // 0x80111490: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80111490: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_3:
    // 0x80111494: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80111498: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x8011149C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x801114A0: nop

    // 0x801114A4: bc1tl       L_80111580
    if (c1cs) {
        // 0x801114A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80111580;
    }
    goto skip_0;
    // 0x801114A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801114AC: jal         0x800D8FF8
    // 0x801114B0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x801114B0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x801114B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801114B8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801114BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801114C0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x801114C4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801114C8: div.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801114CC: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x801114D0: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801114D4: mul.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x801114D8: nop

    // 0x801114DC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801114E0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801114E4: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801114E8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801114EC: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x801114F0: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801114F4: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x801114F8: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801114FC: nop

    // 0x80111500: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80111504: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80111508: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8011150C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80111510: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80111514: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80111518: nop

    // 0x8011151C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80111520: jal         0x800F212C
    // 0x80111524: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800F212C(rdram, ctx);
        goto after_5;
    // 0x80111524: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80111528: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8011152C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80111530: jal         0x800F212C
    // 0x80111534: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    func_800F212C(rdram, ctx);
        goto after_6;
    // 0x80111534: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80111538: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8011153C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80111540: jal         0x800F212C
    // 0x80111544: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    func_800F212C(rdram, ctx);
        goto after_7;
    // 0x80111544: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80111548: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8011154C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80111550: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80111554: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80111558: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8011155C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80111560: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80111564: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80111568: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8011156C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80111570: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80111574: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80111578: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8011157C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80111580:
    // 0x80111580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80111584: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80111588: jr          $ra
    // 0x8011158C: nop

    return;
    // 0x8011158C: nop

;}
RECOMP_FUNC void _chmadamegrunty_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D40: syscall     234
    recomp_syscall_handler(rdram, ctx, 0x80085D40);
    return;
    // 0x80085D44: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _baswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085280: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x80085280);
    return;
    // 0x80085284: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void sufreezy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3174, 0X300) << 16);
    // 0x808000F0: addiu       $a2, $a2, 0x300
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3174, 0X300));
    // 0x808000F4: jal         0x80089D18
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_80800470_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800478: lbu         $t8, 0x1E7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1E7);
    // 0x8080047C: lbu         $t1, 0x1E5($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1E5);
    // 0x80800480: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80800484: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80800488: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8080048C: sb          $t9, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r25;
    // 0x80800490: sb          $t2, 0x1E5($a0)
    MEM_B(0X1E5, ctx->r4) = ctx->r10;
    // 0x80800494: lw          $t3, 0x1E4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1E4);
    // 0x80800498: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8080049C: sb          $t6, 0x171($a0)
    MEM_B(0X171, ctx->r4) = ctx->r14;
    // 0x808004A0: sll         $t5, $t3, 27
    ctx->r13 = S32(ctx->r11 << 27);
    // 0x808004A4: bgez        $t5, L_808004B8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808004A8: ori         $a1, $a1, 0xCCCD
        ctx->r5 = ctx->r5 | 0XCCCD;
            goto L_808004B8;
    }
    // 0x808004A8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004AC: jal         0x80800358
    // 0x808004B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800358_gczoombox(rdram, ctx);
        goto after_0;
    // 0x808004B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808004B8:
    // 0x808004B8: jal         0x80803430
    // 0x808004BC: sb          $zero, 0x170($a0)
    MEM_B(0X170, ctx->r4) = 0;
    gczoombox_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x808004BC: sb          $zero, 0x170($a0)
    MEM_B(0X170, ctx->r4) = 0;
    after_1:
    // 0x808004C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C8: jr          $ra
    // 0x808004CC: nop

    return;
    // 0x808004CC: nop

;}
RECOMP_FUNC void chaliendad_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1364, 0X2704) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x2704
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1364, 0X2704));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x2704
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1364, 0X2704));
;}
RECOMP_FUNC void gsmaker_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007B0: jal         0x8080051C
    // 0x808007B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x808007B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808007B8: bne         $v0, $zero, L_808007C8
    if (ctx->r2 != 0) {
        // 0x808007BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007C8;
    }
    // 0x808007BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007C0: b           L_808007D4
    // 0x808007C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808007D4;
    // 0x808007C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007C8:
    // 0x808007C8: jal         0x808004A8
    // 0x808007CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    gsmaker_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808007CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808007D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007D4:
    // 0x808007D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007DC: jr          $ra
    // 0x808007E0: nop

    return;
    // 0x808007E0: nop

;}
RECOMP_FUNC void _chfactoryworkerwear_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087330: syscall     551
    recomp_syscall_handler(rdram, ctx, 0x80087330);
    return;
    // 0x80087334: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chpowerhutwitchy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080032C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800330: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800334: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8080033C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800340: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800344: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80800348: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8080034C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800350: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800354: jal         0x80106790
    // 0x80800358: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800358: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8080035C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800360: beq         $s3, $at, L_80800390
    if (ctx->r19 == ctx->r1) {
        // 0x80800364: lwc1        $f20, 0x28($v0)
        ctx->f20.u32l = MEM_W(ctx->r2, 0X28);
            goto L_80800390;
    }
    // 0x80800364: lwc1        $f20, 0x28($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800368: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080036C: beq         $s3, $at, L_808003C0
    if (ctx->r19 == ctx->r1) {
        // 0x80800370: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003C0;
    }
    // 0x80800370: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800374: beq         $s3, $at, L_808003F8
    if (ctx->r19 == ctx->r1) {
        // 0x80800378: lui         $a3, 0x3E99
        ctx->r7 = S32(0X3E99 << 16);
            goto L_808003F8;
    }
    // 0x80800378: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x8080037C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800380: beq         $s3, $at, L_808004E4
    if (ctx->r19 == ctx->r1) {
        // 0x80800384: nop
    
            goto L_808004E4;
    }
    // 0x80800384: nop

    // 0x80800388: b           L_808005AC
    // 0x8080038C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808005AC;
    // 0x8080038C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800390:
    // 0x80800390: blezl       $s0, L_808005AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80800394: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808005AC;
    }
    goto skip_0;
    // 0x80800394: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_80800398:
    // 0x80800398: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080039C: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x808003A0: jal         0x800F2FD0
    // 0x808003A4: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    func_800F2FD0(rdram, ctx);
        goto after_1;
    // 0x808003A4: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    after_1:
    // 0x808003A8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808003AC: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x808003B0: bgtz        $s0, L_80800398
    if (SIGNED(ctx->r16) > 0) {
        // 0x808003B4: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800398;
    }
    // 0x808003B4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808003B8: b           L_808005AC
    // 0x808003BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808005AC;
    // 0x808003BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808003C0:
    // 0x808003C0: blez        $s0, L_808005A8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808003C4: lui         $s3, 0x8080
        ctx->r19 = S32(RELOC_HI16(1080, 0XC48) << 16);
            goto L_808005A8;
    }
    // 0x808003C4: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1080, 0XC48) << 16);
    // 0x808003C8: addiu       $s3, $s3, 0xC48
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1080, 0XC48));
L_808003CC:
    // 0x808003CC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808003D0: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x808003D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808003D8: jal         0x800F3320
    // 0x808003DC: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    func_800F3320(rdram, ctx);
        goto after_2;
    // 0x808003DC: addiu       $a2, $s2, 0xC
    ctx->r6 = ADD32(ctx->r18, 0XC);
    after_2:
    // 0x808003E0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808003E4: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x808003E8: bgtz        $s0, L_808003CC
    if (SIGNED(ctx->r16) > 0) {
        // 0x808003EC: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_808003CC;
    }
    // 0x808003EC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808003F0: b           L_808005AC
    // 0x808003F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808005AC;
    // 0x808003F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808003F8:
    // 0x808003F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800400: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800404: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800408: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080040C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800410: jal         0x800F10B4
    // 0x80800414: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800414: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800418: blezl       $s0, L_808005AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8080041C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808005AC;
    }
    goto skip_1;
    // 0x8080041C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
L_80800420:
    // 0x80800420: lbu         $t6, 0xF($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0XF);
    // 0x80800424: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80800428: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8080042C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800430: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800434: bgez        $t6, L_80800448
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800438: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800448;
    }
    // 0x80800438: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080043C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800440: nop

    // 0x80800444: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800448:
    // 0x80800448: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080044C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800450: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800454: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800458: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080045C: nop

    // 0x80800460: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800464: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800468: nop

    // 0x8080046C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80800470: beql        $t8, $zero, L_808004C0
    if (ctx->r24 == 0) {
        // 0x80800474: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_808004C0;
    }
    goto skip_2;
    // 0x80800474: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x80800478: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080047C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800480: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800484: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800488: nop

    // 0x8080048C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800490: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800494: nop

    // 0x80800498: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8080049C: bne         $t8, $zero, L_808004B4
    if (ctx->r24 != 0) {
        // 0x808004A0: nop
    
            goto L_808004B4;
    }
    // 0x808004A0: nop

    // 0x808004A4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x808004A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808004AC: b           L_808004CC
    // 0x808004B0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_808004CC;
    // 0x808004B0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_808004B4:
    // 0x808004B4: b           L_808004CC
    // 0x808004B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_808004CC;
    // 0x808004B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808004BC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_808004C0:
    // 0x808004C0: nop

    // 0x808004C4: bltz        $t8, L_808004B4
    if (SIGNED(ctx->r24) < 0) {
        // 0x808004C8: nop
    
            goto L_808004B4;
    }
    // 0x808004C8: nop

L_808004CC:
    // 0x808004CC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808004D0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808004D4: bgtz        $s0, L_80800420
    if (SIGNED(ctx->r16) > 0) {
        // 0x808004D8: sb          $t8, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r24;
            goto L_80800420;
    }
    // 0x808004D8: sb          $t8, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r24;
    // 0x808004DC: b           L_808005AC
    // 0x808004E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808005AC;
    // 0x808004E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808004E4:
    // 0x808004E4: blezl       $s0, L_808005AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808004E8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808005AC;
    }
    goto skip_3;
    // 0x808004E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
L_808004EC:
    // 0x808004EC: lbu         $t9, 0xF($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XF);
    // 0x808004F0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x808004F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x808004F8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x808004FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800500: bgez        $t9, L_80800514
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800504: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800514;
    }
    // 0x80800504: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800508: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080050C: nop

    // 0x80800510: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80800514:
    // 0x80800514: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800518: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080051C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800520: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800524: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800528: nop

    // 0x8080052C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800530: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800534: nop

    // 0x80800538: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8080053C: beql        $t1, $zero, L_8080058C
    if (ctx->r9 == 0) {
        // 0x80800540: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_8080058C;
    }
    goto skip_4;
    // 0x80800540: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x80800544: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800548: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080054C: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800550: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800554: nop

    // 0x80800558: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8080055C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800560: nop

    // 0x80800564: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80800568: bne         $t1, $zero, L_80800580
    if (ctx->r9 != 0) {
        // 0x8080056C: nop
    
            goto L_80800580;
    }
    // 0x8080056C: nop

    // 0x80800570: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800574: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800578: b           L_80800598
    // 0x8080057C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80800598;
    // 0x8080057C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80800580:
    // 0x80800580: b           L_80800598
    // 0x80800584: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80800598;
    // 0x80800584: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80800588: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_8080058C:
    // 0x8080058C: nop

    // 0x80800590: bltz        $t1, L_80800580
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800594: nop
    
            goto L_80800580;
    }
    // 0x80800594: nop

L_80800598:
    // 0x80800598: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8080059C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x808005A0: bgtz        $s0, L_808004EC
    if (SIGNED(ctx->r16) > 0) {
        // 0x808005A4: sb          $t1, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r9;
            goto L_808004EC;
    }
    // 0x808005A4: sb          $t1, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r9;
L_808005A8:
    // 0x808005A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808005AC:
    // 0x808005AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808005B0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808005B4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808005B8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x808005BC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x808005C0: jr          $ra
    // 0x808005C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808005C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800A9BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9BA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9BA4: addiu       $v0, $v0, 0x7760
    ctx->r2 = ADD32(ctx->r2, 0X7760);
    // 0x800A9BA8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800A9BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9BB4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800A9BB8: beq         $t6, $zero, L_800A9BC8
    if (ctx->r14 == 0) {
        // 0x800A9BBC: sb          $a0, 0x1($v0)
        MEM_B(0X1, ctx->r2) = ctx->r4;
            goto L_800A9BC8;
    }
    // 0x800A9BBC: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x800A9BC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A9BC4: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
L_800A9BC8:
    // 0x800A9BC8: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    // 0x800A9BCC: sh          $a2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r6;
    // 0x800A9BD0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800A9BD4: jal         0x800A79D4
    // 0x800A9BD8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800A79D4(rdram, ctx);
        goto after_0;
    // 0x800A9BD8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800A9BDC: jal         0x800A7A90
    // 0x800A9BE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A7A90(rdram, ctx);
        goto after_1;
    // 0x800A9BE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A9BE4: jal         0x800A7B18
    // 0x800A9BE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800A7B18(rdram, ctx);
        goto after_2;
    // 0x800A9BE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x800A9BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9BF4: jr          $ra
    // 0x800A9BF8: nop

    return;
    // 0x800A9BF8: nop

;}
RECOMP_FUNC void bscrouch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800710: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800714: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800718: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080071C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800720: jal         0x80091A30
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_0;
    // 0x80800724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800728: beq         $v0, $zero, L_8080077C
    if (ctx->r2 == 0) {
        // 0x8080072C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8080077C;
    }
    // 0x8080072C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800730: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: jal         0x80091A58
    // 0x8080073C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x8080073C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80800740: beq         $v0, $zero, L_80800754
    if (ctx->r2 == 0) {
        // 0x80800744: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800754;
    }
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: jal         0x800A055C
    // 0x8080074C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800A055C(rdram, ctx);
        goto after_2;
    // 0x8080074C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800750: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800754:
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80091A58
    // 0x8080075C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_3;
    // 0x8080075C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80800760: beq         $v0, $zero, L_80800774
    if (ctx->r2 == 0) {
        // 0x80800764: nop
    
            goto L_80800774;
    }
    // 0x80800764: nop

    // 0x80800768: jal         0x8009FE84
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_4;
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800770: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800774:
    // 0x80800774: b           L_80800950
    // 0x80800778: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80800950;
    // 0x80800778: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8080077C:
    // 0x8080077C: jal         0x8008E23C
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_5;
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800784: beq         $v0, $zero, L_808008A0
    if (ctx->r2 == 0) {
        // 0x80800788: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A0;
    }
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: jal         0x80091A58
    // 0x80800790: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x80800790: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_6:
    // 0x80800794: beql        $v0, $zero, L_808007B8
    if (ctx->r2 == 0) {
        // 0x80800798: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007B8;
    }
    goto skip_0;
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080079C: jal         0x800C6E38
    // 0x808007A0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_800C6E38(rdram, ctx);
        goto after_7;
    // 0x808007A0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_7:
    // 0x808007A4: beq         $v0, $zero, L_808007B4
    if (ctx->r2 == 0) {
        // 0x808007A8: addiu       $t7, $zero, 0x16A
        ctx->r15 = ADD32(0, 0X16A);
            goto L_808007B4;
    }
    // 0x808007A8: addiu       $t7, $zero, 0x16A
    ctx->r15 = ADD32(0, 0X16A);
    // 0x808007AC: b           L_80800880
    // 0x808007B0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80800880;
    // 0x808007B0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_808007B4:
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007B8:
    // 0x808007B8: jal         0x80091A58
    // 0x808007BC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    bakey_pressed(rdram, ctx);
        goto after_8;
    // 0x808007BC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_8:
    // 0x808007C0: beql        $v0, $zero, L_808007E4
    if (ctx->r2 == 0) {
        // 0x808007C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007E4;
    }
    goto skip_1;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808007C8: jal         0x800C6E38
    // 0x808007CC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C6E38(rdram, ctx);
        goto after_9;
    // 0x808007CC: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_9:
    // 0x808007D0: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x808007D4: addiu       $t8, $zero, 0x163
        ctx->r24 = ADD32(0, 0X163);
            goto L_808007E0;
    }
    // 0x808007D4: addiu       $t8, $zero, 0x163
    ctx->r24 = ADD32(0, 0X163);
    // 0x808007D8: b           L_80800880
    // 0x808007DC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_80800880;
    // 0x808007DC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_808007E0:
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007E4:
    // 0x808007E4: jal         0x80091A58
    // 0x808007E8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x808007E8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_10:
    // 0x808007EC: beql        $v0, $zero, L_80800810
    if (ctx->r2 == 0) {
        // 0x808007F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800810;
    }
    goto skip_2;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808007F4: jal         0x800C6E38
    // 0x808007F8: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_800C6E38(rdram, ctx);
        goto after_11;
    // 0x808007F8: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_11:
    // 0x808007FC: beq         $v0, $zero, L_8080080C
    if (ctx->r2 == 0) {
        // 0x80800800: addiu       $t9, $zero, 0x171
        ctx->r25 = ADD32(0, 0X171);
            goto L_8080080C;
    }
    // 0x80800800: addiu       $t9, $zero, 0x171
    ctx->r25 = ADD32(0, 0X171);
    // 0x80800804: b           L_80800880
    // 0x80800808: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80800880;
    // 0x80800808: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8080080C:
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800810:
    // 0x80800810: jal         0x80091A58
    // 0x80800814: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    bakey_pressed(rdram, ctx);
        goto after_12;
    // 0x80800814: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x80800818: beql        $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x8080081C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800884;
    }
    goto skip_3;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800820: jal         0x800C6E38
    // 0x80800824: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800C6E38(rdram, ctx);
        goto after_13;
    // 0x80800824: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_13:
    // 0x80800828: beql        $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x8080082C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800884;
    }
    goto skip_4;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800830: jal         0x8008E0C8
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0C8(rdram, ctx);
        goto after_14;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800838: bne         $v0, $zero, L_80800848
    if (ctx->r2 != 0) {
        // 0x8080083C: addiu       $t0, $zero, 0x122
        ctx->r8 = ADD32(0, 0X122);
            goto L_80800848;
    }
    // 0x8080083C: addiu       $t0, $zero, 0x122
    ctx->r8 = ADD32(0, 0X122);
    // 0x80800840: b           L_80800880
    // 0x80800844: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_80800880;
    // 0x80800844: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800848:
    // 0x80800848: jal         0x808006A4
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A4_bscrouch(rdram, ctx);
        goto after_15;
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800850: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x80800854: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800880;
    }
    // 0x80800854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800858: beq         $v0, $at, L_80800874
    if (ctx->r2 == ctx->r1) {
        // 0x8080085C: addiu       $t1, $zero, 0x129
        ctx->r9 = ADD32(0, 0X129);
            goto L_80800874;
    }
    // 0x8080085C: addiu       $t1, $zero, 0x129
    ctx->r9 = ADD32(0, 0X129);
    // 0x80800860: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800864: beq         $v0, $at, L_8080087C
    if (ctx->r2 == ctx->r1) {
        // 0x80800868: addiu       $t2, $zero, 0x128
        ctx->r10 = ADD32(0, 0X128);
            goto L_8080087C;
    }
    // 0x80800868: addiu       $t2, $zero, 0x128
    ctx->r10 = ADD32(0, 0X128);
    // 0x8080086C: b           L_80800884
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800884;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800874:
    // 0x80800874: b           L_80800880
    // 0x80800878: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_80800880;
    // 0x80800878: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8080087C:
    // 0x8080087C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80800880:
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800884:
    // 0x80800884: jal         0x80091A58
    // 0x80800888: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_16;
    // 0x80800888: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x8080088C: beq         $v0, $zero, L_80800898
    if (ctx->r2 == 0) {
        // 0x80800890: addiu       $t3, $zero, 0x6C
        ctx->r11 = ADD32(0, 0X6C);
            goto L_80800898;
    }
    // 0x80800890: addiu       $t3, $zero, 0x6C
    ctx->r11 = ADD32(0, 0X6C);
    // 0x80800894: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80800898:
    // 0x80800898: b           L_80800950
    // 0x8080089C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80800950;
    // 0x8080089C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_808008A0:
    // 0x808008A0: jal         0x800980DC
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_wonderwing(rdram, ctx);
        goto after_17;
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808008A8: beq         $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x808008AC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_808008C8;
    }
    // 0x808008AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808008B0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808008B4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808008B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808008BC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x808008C0: jal         0x8008A690
    // 0x808008C4: addiu       $a3, $zero, 0x47
    ctx->r7 = ADD32(0, 0X47);
    _suinv_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x808008C4: addiu       $a3, $zero, 0x47
    ctx->r7 = ADD32(0, 0X47);
    after_18:
L_808008C8:
    // 0x808008C8: jal         0x8009809C
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_trot(rdram, ctx);
        goto after_19;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808008D0: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808008D4: addiu       $t5, $zero, 0x14
        ctx->r13 = ADD32(0, 0X14);
            goto L_808008DC;
    }
    // 0x808008D4: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x808008D8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_808008DC:
    // 0x808008DC: jal         0x80097BFC
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_poop_egg(rdram, ctx);
        goto after_20;
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808008E4: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x808008E8: nop
    
            goto L_80800900;
    }
    // 0x808008E8: nop

    // 0x808008EC: jal         0x80094B14
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094B14(rdram, ctx);
        goto after_21;
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808008F4: beq         $v0, $zero, L_80800900
    if (ctx->r2 == 0) {
        // 0x808008F8: addiu       $t6, $zero, 0xA
        ctx->r14 = ADD32(0, 0XA);
            goto L_80800900;
    }
    // 0x808008F8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x808008FC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80800900:
    // 0x80800900: jal         0x80097C3C
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_shoot_egg(rdram, ctx);
        goto after_22;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800908: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x8080090C: nop
    
            goto L_80800924;
    }
    // 0x8080090C: nop

    // 0x80800910: jal         0x80094B14
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094B14(rdram, ctx);
        goto after_23;
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800918: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x8080091C: addiu       $t7, $zero, 0x9
        ctx->r15 = ADD32(0, 0X9);
            goto L_80800924;
    }
    // 0x8080091C: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80800920: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80800924:
    // 0x80800924: jal         0x80097E34
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_flap_flip(rdram, ctx);
        goto after_24;
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8080092C: beq         $v0, $zero, L_80800938
    if (ctx->r2 == 0) {
        // 0x80800930: addiu       $t8, $zero, 0x12
        ctx->r24 = ADD32(0, 0X12);
            goto L_80800938;
    }
    // 0x80800930: addiu       $t8, $zero, 0x12
    ctx->r24 = ADD32(0, 0X12);
    // 0x80800934: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80800938:
    // 0x80800938: jal         0x80097A50
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_barge(rdram, ctx);
        goto after_25;
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800940: beq         $v0, $zero, L_8080094C
    if (ctx->r2 == 0) {
        // 0x80800944: addiu       $t9, $zero, 0x13
        ctx->r25 = ADD32(0, 0X13);
            goto L_8080094C;
    }
    // 0x80800944: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x80800948: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8080094C:
    // 0x8080094C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80800950:
    // 0x80800950: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800954: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080095C: jr          $ra
    // 0x80800960: nop

    return;
    // 0x80800960: nop

    // 0x80800964: nop

    // 0x80800968: nop

    // 0x8080096C: nop

;}
RECOMP_FUNC void func_800D21B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D21B0: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800D21B4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D21B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D21BC: addiu       $t7, $t7, -0x4D70
    ctx->r15 = ADD32(ctx->r15, -0X4D70);
    // 0x800D21C0: jr          $ra
    // 0x800D21C4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    return;
    // 0x800D21C4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D21C8: nop

    // 0x800D21CC: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_47(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808029C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2F00) << 16);
    // 0x808029CC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808029D0: jr          $ra
    // 0x808029D4: lw          $v0, 0x2F00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2F00));
    return;
    // 0x808029D4: lw          $v0, 0x2F00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2F00));
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084028: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084028);
    return;
    // 0x8008402C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800910BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800910BC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x800910C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800910C4: lbu         $t6, 0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XE);
    // 0x800910C8: bne         $t6, $at, L_800910FC
    if (ctx->r14 != ctx->r1) {
        // 0x800910CC: nop
    
            goto L_800910FC;
    }
    // 0x800910CC: nop

    // 0x800910D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800910D4: nop

    // 0x800910D8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800910DC: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x800910E0: sb          $zero, 0xC($t7)
    MEM_B(0XC, ctx->r15) = 0;
    // 0x800910E4: lw          $t8, 0x30($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X30);
    // 0x800910E8: swc1        $f0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f0.u32l;
    // 0x800910EC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x800910F0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800910F4: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x800910F8: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
L_800910FC:
    // 0x800910FC: jr          $ra
    // 0x80091100: sb          $a1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r5;
    return;
    // 0x80091100: sb          $a1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void gcgoto_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800630: jal         0x8008FD48
    // 0x80800634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008FD48(rdram, ctx);
        goto after_0;
    // 0x80800634: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800638: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080063C: bne         $v0, $at, L_8080064C
    if (ctx->r2 != ctx->r1) {
        // 0x80800640: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080064C;
    }
    // 0x80800640: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800644: jal         0x808003D0
    // 0x80800648: ori         $a1, $zero, 0xBC02
    ctx->r5 = 0 | 0XBC02;
    func_808003D0_gcgoto(rdram, ctx);
        goto after_1;
    // 0x80800648: ori         $a1, $zero, 0xBC02
    ctx->r5 = 0 | 0XBC02;
    after_1:
L_8080064C:
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

;}
RECOMP_FUNC void func_80800000_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80096544
    // 0x8080000C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: beql        $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800014: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000A4;
    }
    goto skip_0;
    // 0x80800014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800018: jal         0x800DC0C0
    // 0x8080001C: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x8080001C: nop

    after_1:
    // 0x80800020: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800028: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080002C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800030: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800034: nop

    // 0x80800038: bc1f        L_80800050
    if (!c1cs) {
        // 0x8080003C: nop
    
            goto L_80800050;
    }
    // 0x8080003C: nop

    // 0x80800040: jal         0x80092C00
    // 0x80800044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80092C00(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800048: b           L_8080005C
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_8080005C;
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800050:
    // 0x80800050: jal         0x80092C24
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80092C24(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800058: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_8080005C:
    // 0x8080005C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800060: jal         0x8009FBB0
    // 0x80800064: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009FBB0(rdram, ctx);
        goto after_4;
    // 0x80800064: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_4:
    // 0x80800068: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8080006C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80800070: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800074: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800078: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080007C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800080: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x80800084: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x80800088: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    // 0x8080008C: jal         0x800BA930
    // 0x80800090: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BA930(rdram, ctx);
        goto after_5;
    // 0x80800090: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x80800094: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800098: jal         0x800BA22C
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A4:
    // 0x808000A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void ncbaglide_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808000A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A8: jal         0x80110840
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000B0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x8011607C
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8011607C(rdram, ctx);
        goto after_1;
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x801107F0
    // 0x808000C8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_2:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x8080007C
    // 0x808000D4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_8080007C_ncbaglide(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_3:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808000E0: jal         0x80115444
    // 0x808000E4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_80115444(rdram, ctx);
        goto after_4;
    // 0x808000E4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x808000E8: jal         0x800F5AE0
    // 0x808000EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F5AE0(rdram, ctx);
        goto after_5;
    // 0x808000EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x808000F0: jal         0x80013728
    // 0x808000F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_6;
    // 0x808000F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x808000F8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808000FC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800100: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800104: nop

    // 0x80800108: bc1f        L_80800144
    if (!c1cs) {
        // 0x8080010C: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_80800144;
    }
    // 0x8080010C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800110: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800114: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80800118: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080011C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800120: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x80800124: jal         0x800F10B4
    // 0x80800128: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800128: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8080012C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800130: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800134: jal         0x80115828
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115828(rdram, ctx);
        goto after_8;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080013C: b           L_80800158
    // 0x80800140: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
        goto L_80800158;
    // 0x80800140: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_80800144:
    // 0x80800144: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800148: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8080014C: jal         0x80115828
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115828(rdram, ctx);
        goto after_9;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800154: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_80800158:
    // 0x80800158: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8080015C: jal         0x800EFB24
    // 0x80800160: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EFB24(rdram, ctx);
        goto after_10;
    // 0x80800160: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_10:
    // 0x80800164: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800168: jal         0x800F1A88
    // 0x8080016C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F1A88(rdram, ctx);
        goto after_11;
    // 0x8080016C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_11:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x80115750
    // 0x80800178: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80115750(rdram, ctx);
        goto after_12;
    // 0x80800178: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x8080017C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800180: jal         0x801112B0
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801112B0(rdram, ctx);
        goto after_13;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800188: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080018C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800190: jal         0x800136E4
    // 0x80800194: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_14;
    // 0x80800194: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_14:
    // 0x80800198: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8080019C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001A0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808001A4: jal         0x800EEBF0
    // 0x808001A8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_800EEBF0(rdram, ctx);
        goto after_15;
    // 0x808001A8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_15:
    // 0x808001AC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808001B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808001B4: jal         0x800EE780
    // 0x808001B8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EE780(rdram, ctx);
        goto after_16;
    // 0x808001B8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_16:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80111CC8
    // 0x808001C4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80111CC8(rdram, ctx);
        goto after_17;
    // 0x808001C4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_17:
    // 0x808001C8: beql        $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001DC;
    }
    goto skip_0;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001D0: jal         0x801138F4
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_18;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001DC:
    // 0x808001DC: jal         0x80112524
    // 0x808001E0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80112524(rdram, ctx);
        goto after_19;
    // 0x808001E0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_19:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808001EC: jal         0x80110A68
    // 0x808001F0: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_80110A68(rdram, ctx);
        goto after_20;
    // 0x808001F0: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_20:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80110790
    // 0x808001FC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80110790(rdram, ctx);
        goto after_21;
    // 0x808001FC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_21:
    // 0x80800200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800204: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800208: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

    // 0x80800214: nop

    // 0x80800218: nop

    // 0x8080021C: nop

;}
RECOMP_FUNC void func_808021C4_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021C4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808021C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021CC: jal         0x800D8FF8
    // 0x808021D0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808021D0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x808021D4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x808021D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808021DC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x808021E0: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x808021E4: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x808021E8: lwc1        $f2, 0x54($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X54);
    // 0x808021EC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808021F0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808021F4: addiu       $a1, $a3, 0x28
    ctx->r5 = ADD32(ctx->r7, 0X28);
    // 0x808021F8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808021FC: swc1        $f10, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f10.u32l;
    // 0x80802200: lwc1        $f16, 0x2C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x80802204: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80802208: nop

    // 0x8080220C: bc1fl       L_8080221C
    if (!c1cs) {
        // 0x80802210: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8080221C;
    }
    goto skip_0;
    // 0x80802210: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    skip_0:
    // 0x80802214: swc1        $f2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
    // 0x80802218: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
L_8080221C:
    // 0x8080221C: jal         0x800EFA20
    // 0x80802220: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80802220: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_1:
    // 0x80802224: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80802228: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080222C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80802230: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80802234: jal         0x800EE780
    // 0x80802238: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80802238: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x8080223C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80802240: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802244: lui         $a3, 0x242
    ctx->r7 = S32(0X242 << 16);
    // 0x80802248: ori         $a3, $a3, 0xA1
    ctx->r7 = ctx->r7 | 0XA1;
    // 0x8080224C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802250: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80802254: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80802258: jal         0x800FAB50
    // 0x8080225C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800FAB50(rdram, ctx);
        goto after_3;
    // 0x8080225C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80802260: beq         $v0, $zero, L_80802278
    if (ctx->r2 == 0) {
        // 0x80802264: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80802278;
    }
    // 0x80802264: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80802268: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080226C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80802270: jal         0x800F059C
    // 0x80802274: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800F059C(rdram, ctx);
        goto after_4;
    // 0x80802274: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
L_80802278:
    // 0x80802278: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080227C: jal         0x800EE7F8
    // 0x80802280: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80802280: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80802284: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80802288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080228C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80802290: beq         $t6, $zero, L_808022A0
    if (ctx->r14 == 0) {
        // 0x80802294: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808022A0;
    }
    // 0x80802294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80802298: b           L_808022A0
    // 0x8080229C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808022A0;
    // 0x8080229C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808022A0:
    // 0x808022A0: jr          $ra
    // 0x808022A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808022A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void bsbshock_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006AC: jal         0x8008CABC
    // 0x808006B0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808006B0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808006B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808006B8: jal         0x800841D8
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: jal         0x8009BB24
    // 0x808006C8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_2;
    // 0x808006C8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x808006CC: lui         $a1, 0x3F43
    ctx->r5 = S32(0X3F43 << 16);
    // 0x808006D0: ori         $a1, $a1, 0x553
    ctx->r5 = ctx->r5 | 0X553;
    // 0x808006D4: jal         0x8008B348
    // 0x808006D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808006D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808006DC: beq         $v0, $zero, L_808006EC
    if (ctx->r2 == 0) {
        // 0x808006E0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808006EC;
    }
    // 0x808006E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808006E4: jal         0x8008B1BC
    // 0x808006E8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808006E8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_4:
L_808006EC:
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x80091A30
    // 0x808006F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_5;
    // 0x808006F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x808006F8: beq         $v0, $zero, L_80800720
    if (ctx->r2 == 0) {
        // 0x808006FC: lwc1        $f6, 0x2C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80800720;
    }
    // 0x808006FC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800700: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800704: nop

    // 0x80800708: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080070C: nop

    // 0x80800710: bc1fl       L_80800724
    if (!c1cs) {
        // 0x80800714: lw          $t6, 0x160($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X160);
            goto L_80800724;
    }
    goto skip_0;
    // 0x80800714: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    skip_0:
    // 0x80800718: jal         0x8009BC6C
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_6;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80800720:
    // 0x80800720: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
L_80800724:
    // 0x80800724: bne         $t6, $zero, L_80800754
    if (ctx->r14 != 0) {
        // 0x80800728: nop
    
            goto L_80800754;
    }
    // 0x80800728: nop

    // 0x8080072C: jal         0x8009FC80
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FC80(rdram, ctx);
        goto after_7;
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800734: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800738: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080073C: addiu       $t7, $zero, 0x2F
    ctx->r15 = ADD32(0, 0X2F);
    // 0x80800740: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800744: nop

    // 0x80800748: bc1f        L_80800754
    if (!c1cs) {
        // 0x8080074C: nop
    
            goto L_80800754;
    }
    // 0x8080074C: nop

    // 0x80800750: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800754:
    // 0x80800754: jal         0x8008E078
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_8;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080075C: bnel        $v0, $zero, L_808007B8
    if (ctx->r2 != 0) {
        // 0x80800760: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007B8;
    }
    goto skip_1;
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800764: jal         0x8008E260
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_9;
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080076C: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x80800770: addiu       $t8, $zero, 0x3D
        ctx->r24 = ADD32(0, 0X3D);
            goto L_80800778;
    }
    // 0x80800770: addiu       $t8, $zero, 0x3D
    ctx->r24 = ADD32(0, 0X3D);
    // 0x80800774: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800778:
    // 0x80800778: jal         0x80097DF4
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097DF4(rdram, ctx);
        goto after_10;
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800780: beq         $v0, $zero, L_8080078C
    if (ctx->r2 == 0) {
        // 0x80800784: addiu       $t9, $zero, 0x10
        ctx->r25 = ADD32(0, 0X10);
            goto L_8080078C;
    }
    // 0x80800784: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80800788: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8080078C:
    // 0x8080078C: jal         0x80097A90
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_11;
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800794: beq         $v0, $zero, L_808007A0
    if (ctx->r2 == 0) {
        // 0x80800798: addiu       $t0, $zero, 0xF
        ctx->r8 = ADD32(0, 0XF);
            goto L_808007A0;
    }
    // 0x80800798: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x8080079C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_808007A0:
    // 0x808007A0: jal         0x8008DA24
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_12;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808007A8: beq         $v0, $zero, L_808007B4
    if (ctx->r2 == 0) {
        // 0x808007AC: addiu       $t1, $zero, 0xA8
        ctx->r9 = ADD32(0, 0XA8);
            goto L_808007B4;
    }
    // 0x808007AC: addiu       $t1, $zero, 0xA8
    ctx->r9 = ADD32(0, 0XA8);
    // 0x808007B0: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_808007B4:
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007B8:
    // 0x808007B8: jal         0x8009E5C8
    // 0x808007BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808007BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x808007C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void _subaddiestore_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F10: syscall     815
    recomp_syscall_handler(rdram, ctx, 0x80089F10);
    return;
    // 0x80089F14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sucoasterhit_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A338: syscall     836
    recomp_syscall_handler(rdram, ctx, 0x8008A338);
    return;
    // 0x8008A33C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800AD0_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800AD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AE0: jal         0x80100094
    // 0x80800AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AE8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800AEC: lbu         $v1, 0x14($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X14);
    // 0x80800AF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AF4: beq         $v1, $at, L_80800B1C
    if (ctx->r3 == ctx->r1) {
        // 0x80800AF8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800B1C;
    }
    // 0x80800AF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AFC: beq         $v1, $at, L_80800B44
    if (ctx->r3 == ctx->r1) {
        // 0x80800B00: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800B44;
    }
    // 0x80800B00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B04: beq         $v1, $at, L_80800B80
    if (ctx->r3 == ctx->r1) {
        // 0x80800B08: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800B80;
    }
    // 0x80800B08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800B0C: beql        $v1, $at, L_80800BBC
    if (ctx->r3 == ctx->r1) {
        // 0x80800B10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BBC;
    }
    goto skip_0;
    // 0x80800B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B14: b           L_80800BBC
    // 0x80800B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BBC;
    // 0x80800B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B1C:
    // 0x80800B1C: jal         0x80800A1C
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A1C_chtntmineshoot(rdram, ctx);
        goto after_1;
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B24: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x80800B28: beq         $t6, $zero, L_80800BB8
    if (ctx->r14 == 0) {
        // 0x80800B2C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80800BB8;
    }
    // 0x80800B2C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B34: jal         0x80800830
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800830_chtntmineshoot(rdram, ctx);
        goto after_2;
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800B3C: b           L_80800BBC
    // 0x80800B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BBC;
    // 0x80800B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B44:
    // 0x80800B44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800B48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B4C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800B58: jal         0x80800A1C
    // 0x80800B5C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_80800A1C_chtntmineshoot(rdram, ctx);
        goto after_3;
    // 0x80800B5C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x80800B60: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x80800B64: beq         $t7, $zero, L_80800BB8
    if (ctx->r15 == 0) {
        // 0x80800B68: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80800BB8;
    }
    // 0x80800B68: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B70: jal         0x80800830
    // 0x80800B74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800830_chtntmineshoot(rdram, ctx);
        goto after_4;
    // 0x80800B74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800B78: b           L_80800BBC
    // 0x80800B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BBC;
    // 0x80800B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B80:
    // 0x80800B80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800B84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B88: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B90: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800B94: jal         0x80800A1C
    // 0x80800B98: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    func_80800A1C_chtntmineshoot(rdram, ctx);
        goto after_5;
    // 0x80800B98: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x80800B9C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800BA0: jal         0x80101DDC
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_6;
    // 0x80800BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800BA8: beq         $v0, $zero, L_80800BB8
    if (ctx->r2 == 0) {
        // 0x80800BAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BB8;
    }
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB0: jal         0x80800830
    // 0x80800BB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800830_chtntmineshoot(rdram, ctx);
        goto after_7;
    // 0x80800BB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
L_80800BB8:
    // 0x80800BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BBC:
    // 0x80800BBC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800BC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BC4: jr          $ra
    // 0x80800BC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800BC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800090_chmole_cuckoo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1848, 0XC0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1848, 0XC0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1848, 0XC0));
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829C8: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829C8);
    return;
    // 0x800829CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chclockworkmouse_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E20: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1564, 0X3E48) << 16);
    // 0x80801E24: jr          $ra
    // 0x80801E28: addiu       $v0, $v0, 0x3E48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1564, 0X3E48));
    return;
    // 0x80801E28: addiu       $v0, $v0, 0x3E48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1564, 0X3E48));
;}
RECOMP_FUNC void gcnewoption_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014A0: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x808014A4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x808014A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808014AC: jr          $ra
    // 0x808014B0: sh          $t6, 0xB0($t8)
    MEM_H(0XB0, ctx->r24) = ctx->r14;
    return;
    // 0x808014B0: sh          $t6, 0xB0($t8)
    MEM_H(0XB0, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_808022BC_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808022C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808022C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808022C8: jal         0x80101080
    // 0x808022CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x808022CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808022D0: jal         0x80106790
    // 0x808022D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808022D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808022D8: jal         0x80101080
    // 0x808022DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80101080(rdram, ctx);
        goto after_2;
    // 0x808022DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x808022E0: jal         0x80106790
    // 0x808022E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x808022E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808022E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808022EC: jal         0x800866B8
    // 0x808022F0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x808022F0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_4:
    // 0x808022F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808022F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808022FC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80802300: jal         0x808027E4
    // 0x80802304: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_5;
    // 0x80802304: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80802308: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080230C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2F60) << 16);
    // 0x80802310: addiu       $a2, $a2, 0x2F60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2F60));
    // 0x80802314: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80802318: jal         0x80089D18
    // 0x8080231C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x8080231C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80802320: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802324: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(932, 0X2EF8) << 16);
    // 0x80802328: addiu       $t7, $t7, 0x2EF8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(932, 0X2EF8));
    // 0x8080232C: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x80802330: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802338: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080233C: jal         0x800BABB8
    // 0x80802340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80802340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80802344: jal         0x800D395C
    // 0x80802348: nop

    func_800D395C(rdram, ctx);
        goto after_8;
    // 0x80802348: nop

    after_8:
    // 0x8080234C: bne         $v0, $zero, L_80802368
    if (ctx->r2 != 0) {
        // 0x80802350: addiu       $a0, $zero, 0xB
        ctx->r4 = ADD32(0, 0XB);
            goto L_80802368;
    }
    // 0x80802350: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80802354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802358: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080235C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80802360: jal         0x800D1000
    // 0x80802364: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_9;
    // 0x80802364: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
L_80802368:
    // 0x80802368: jal         0x800DA544
    // 0x8080236C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x8080236C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_10:
    // 0x80802370: jal         0x800DA524
    // 0x80802374: addiu       $a0, $zero, 0x670
    ctx->r4 = ADD32(0, 0X670);
    func_800DA524(rdram, ctx);
        goto after_11;
    // 0x80802374: addiu       $a0, $zero, 0x670
    ctx->r4 = ADD32(0, 0X670);
    after_11:
    // 0x80802378: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080237C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802384: jr          $ra
    // 0x80802388: nop

    return;
    // 0x80802388: nop

;}
RECOMP_FUNC void func_80800A24_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A34: jal         0x8008CABC
    // 0x80800A38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800A3C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800A40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A44: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A48: beq         $v1, $at, L_80800A60
    if (ctx->r3 == ctx->r1) {
        // 0x80800A4C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A60;
    }
    // 0x80800A4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A50: beq         $v1, $at, L_80800AC0
    if (ctx->r3 == ctx->r1) {
        // 0x80800A54: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800AC0;
    }
    // 0x80800A54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A58: b           L_80800AD8
    // 0x80800A5C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
        goto L_80800AD8;
    // 0x80800A5C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80800A60:
    // 0x80800A60: jal         0x8008AF24
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: jal         0x8008AED4
    // 0x80800A70: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800A70: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    after_2:
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: jal         0x8008B1BC
    // 0x80800A7C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800A7C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_3:
    // 0x80800A80: lui         $a2, 0x3F37
    ctx->r6 = S32(0X3F37 << 16);
    // 0x80800A84: ori         $a2, $a2, 0xA3D
    ctx->r6 = ctx->r6 | 0XA3D;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: jal         0x8008B1D4
    // 0x80800A90: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x80800A90: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: jal         0x8008B134
    // 0x80800A9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800A9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800AA0: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80800AA4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800AA8: jal         0x8008B24C
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800AB0: jal         0x8008B064
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AB8: b           L_80800AD4
    // 0x80800ABC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80800AD4;
    // 0x80800ABC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80800AC0:
    // 0x80800AC0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800AC4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800AC8: jal         0x8008CF1C
    // 0x80800ACC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_8;
    // 0x80800ACC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x80800AD0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80800AD4:
    // 0x80800AD4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80800AD8:
    // 0x80800AD8: sb          $v1, 0x15C($t6)
    MEM_B(0X15C, ctx->r14) = ctx->r3;
    // 0x80800ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AE8: jr          $ra
    // 0x80800AEC: nop

    return;
    // 0x80800AEC: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A728: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A728);
    return;
    // 0x8008A72C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _idtwinkle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DF8: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088DF8);
    return;
    // 0x80088DFC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801408_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080140C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801410: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801414: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801418: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080141C: jal         0x800A89F8
    // 0x80801420: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80801420: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801424: jal         0x800A9478
    // 0x80801428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_1;
    // 0x80801428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080142C: jal         0x800F5EF8
    // 0x80801430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x80801430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801434: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80801438: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080143C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801440: ori         $t7, $a3, 0x20
    ctx->r15 = ctx->r7 | 0X20;
    // 0x80801444: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80801448: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080144C: jal         0x80089560
    // 0x80801450: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    _ncpod_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80801450: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x80801454: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80801458: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8080145C: sb          $t8, 0x5C($t9)
    MEM_B(0X5C, ctx->r25) = ctx->r24;
    // 0x80801460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801468: jr          $ra
    // 0x8080146C: nop

    return;
    // 0x8080146C: nop

;}
RECOMP_FUNC void func_800F31EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F31EC: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x800F31F0: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x800F31F4: jr          $ra
    // 0x800F31F8: sb          $a3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r7;
    return;
    // 0x800F31F8: sb          $a3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_80808148_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808148: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x8080814C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80808150: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80808154: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80808158: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080815C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80808160: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80808164: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80808168: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080816C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80808170: addiu       $s1, $sp, 0xFC
    ctx->r17 = ADD32(ctx->r29, 0XFC);
    // 0x80808174: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80808178: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8080817C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80808180: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80808184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808188: jal         0x8009C128
    // 0x8080818C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080818C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80808190: jal         0x80096628
    // 0x80808194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096628(rdram, ctx);
        goto after_1;
    // 0x80808194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80808198: sll         $t6, $v0, 10
    ctx->r14 = S32(ctx->r2 << 10);
    // 0x8080819C: bltz        $t6, L_80808488
    if (SIGNED(ctx->r14) < 0) {
        // 0x808081A0: addiu       $s4, $sp, 0x50
        ctx->r20 = ADD32(ctx->r29, 0X50);
            goto L_80808488;
    }
    // 0x808081A0: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x808081A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808081A8: jal         0x80096604
    // 0x808081AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80096604(rdram, ctx);
        goto after_2;
    // 0x808081AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x808081B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808081B4: jal         0x800965E0
    // 0x808081B8: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    func_800965E0(rdram, ctx);
        goto after_3;
    // 0x808081B8: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    after_3:
    // 0x808081BC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808081C0: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x808081C4: addiu       $t0, $sp, 0x7C
    ctx->r8 = ADD32(ctx->r29, 0X7C);
    // 0x808081C8: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x808081CC: addiu       $t1, $sp, 0xAC
    ctx->r9 = ADD32(ctx->r29, 0XAC);
    // 0x808081D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_808081D4:
    // 0x808081D4: swc1        $f20, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f20.u32l;
    // 0x808081D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808081DC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x808081E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_808081E4:
    // 0x808081E4: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x808081E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808081EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808081F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808081F4: bne         $v0, $a1, L_808081E4
    if (ctx->r2 != ctx->r5) {
        // 0x808081F8: sw          $t7, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r15;
            goto L_808081E4;
    }
    // 0x808081F8: sw          $t7, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r15;
    // 0x808081FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80808200: sltu        $at, $a2, $t1
    ctx->r1 = ctx->r6 < ctx->r9 ? 1 : 0;
    // 0x80808204: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80808208: bne         $at, $zero, L_808081D4
    if (ctx->r1 != 0) {
        // 0x8080820C: addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
            goto L_808081D4;
    }
    // 0x8080820C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80808210: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x80808214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808218: jal         0x800F36D4
    // 0x8080821C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_800F36D4(rdram, ctx);
        goto after_4;
    // 0x8080821C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_4:
    // 0x80808220: beq         $v0, $zero, L_80808248
    if (ctx->r2 == 0) {
        // 0x80808224: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808248;
    }
    // 0x80808224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808228: jal         0x800F36D4
    // 0x8080822C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    func_800F36D4(rdram, ctx);
        goto after_5;
    // 0x8080822C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_5:
    // 0x80808230: beq         $v0, $zero, L_80808248
    if (ctx->r2 == 0) {
        // 0x80808234: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80808248;
    }
    // 0x80808234: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80808238: jal         0x800EE84C
    // 0x8080823C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE84C(rdram, ctx);
        goto after_6;
    // 0x8080823C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80808240: b           L_8080848C
    // 0x80808244: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8080848C;
    // 0x80808244: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80808248:
    // 0x80808248: swc1        $f20, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f20.u32l;
    // 0x8080824C: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x80808250: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80808254: jal         0x800EFB24
    // 0x80808258: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x80808258: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_7:
    // 0x8080825C: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x80808260: swc1        $f20, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f20.u32l;
    // 0x80808264: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80808268: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x8080826C: jal         0x800EFB24
    // 0x80808270: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80808270: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_8:
    // 0x80808274: addiu       $s1, $sp, 0xC4
    ctx->r17 = ADD32(ctx->r29, 0XC4);
    // 0x80808278: swc1        $f20, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f20.u32l;
    // 0x8080827C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80808280: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80808284: jal         0x800EFB24
    // 0x80808288: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x80808288: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x8080828C: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80808290: lwc1        $f0, 0xC4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80808294: swc1        $f20, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f20.u32l;
    // 0x80808298: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8080829C: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x808082A0: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x808082A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808082A8: jal         0x800EEAA4
    // 0x808082AC: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_10;
    // 0x808082AC: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x808082B0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x808082B4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808082B8: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x808082BC: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x808082C0: bc1f        L_808082D0
    if (!c1cs) {
        // 0x808082C4: lwc1        $f18, 0xBC($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
            goto L_808082D0;
    }
    // 0x808082C4: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x808082C8: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA574) << 16);
    // 0x808082CC: lwc1        $f2, -0x5A8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA574));
L_808082D0:
    // 0x808082D0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808082D4: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x808082D8: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x808082DC: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x808082E0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808082E4: lwc1        $f18, 0xC0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x808082E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808082EC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x808082F0: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x808082F4: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x808082F8: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808082FC: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80808300: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x80808304: lwc1        $f16, 0xF8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80808308: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8080830C: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80808310: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80808314: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80808318: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080831C: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80808320: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80808324: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80808328: jal         0x800EFA4C
    // 0x8080832C: nop

    func_800EFA4C(rdram, ctx);
        goto after_11;
    // 0x8080832C: nop

    after_11:
    // 0x80808330: addiu       $s2, $sp, 0xE4
    ctx->r18 = ADD32(ctx->r29, 0XE4);
    // 0x80808334: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80808338: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8080833C: jal         0x800EFB24
    // 0x80808340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x80808340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80808344: jal         0x800EEF94
    // 0x80808348: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EEF94(rdram, ctx);
        goto after_13;
    // 0x80808348: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x8080834C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80808350: jal         0x800EEF94
    // 0x80808354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEF94(rdram, ctx);
        goto after_14;
    // 0x80808354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80808358: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA578) << 16);
    // 0x8080835C: lwc1        $f4, -0x5A88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA578));
    // 0x80808360: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80808364: addiu       $v0, $sp, 0x7C
    ctx->r2 = ADD32(ctx->r29, 0X7C);
    // 0x80808368: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8080836C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80808370: div.s       $f2, $f20, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80808374: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80808378: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x8080837C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80808380: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80808384: beq         $at, $zero, L_808083C4
    if (ctx->r1 == 0) {
        // 0x80808388: subu        $t9, $t8, $a0
        ctx->r25 = SUB32(ctx->r24, ctx->r4);
            goto L_808083C4;
    }
    // 0x80808388: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
L_8080838C:
    // 0x8080838C: mtc1        $t9, $f20
    ctx->f20.u32l = ctx->r25;
    // 0x80808390: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80808394: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80808398: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8080839C: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x808083A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808083A4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808083A8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x808083AC: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x808083B0: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x808083B4: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x808083B8: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x808083BC: bne         $at, $zero, L_8080838C
    if (ctx->r1 != 0) {
        // 0x808083C0: subu        $t9, $t8, $a0
        ctx->r25 = SUB32(ctx->r24, ctx->r4);
            goto L_8080838C;
    }
    // 0x808083C0: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
L_808083C4:
    // 0x808083C4: mtc1        $t9, $f20
    ctx->f20.u32l = ctx->r25;
    // 0x808083C8: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x808083CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808083D0: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x808083D4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808083D8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x808083DC: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x808083E0: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x808083E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808083E8: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x808083EC: jal         0x800EFB24
    // 0x808083F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_15;
    // 0x808083F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_15:
    // 0x808083F4: jal         0x800EEF94
    // 0x808083F8: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    func_800EEF94(rdram, ctx);
        goto after_16;
    // 0x808083F8: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    after_16:
    // 0x808083FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80808400: jal         0x800EEF94
    // 0x80808404: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EEF94(rdram, ctx);
        goto after_17;
    // 0x80808404: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80808408: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080840C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80808410: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA57C) << 16);
    // 0x80808414: lwc1        $f6, -0x5A84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA57C));
    // 0x80808418: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x8080841C: addiu       $v0, $sp, 0x7C
    ctx->r2 = ADD32(ctx->r29, 0X7C);
    // 0x80808420: add.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80808424: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80808428: div.s       $f10, $f20, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8080842C: sub.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80808430: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80808434: beq         $v0, $a0, L_80808468
    if (ctx->r2 == ctx->r4) {
        // 0x80808438: lw          $t2, -0x4($v0)
        ctx->r10 = MEM_W(ctx->r2, -0X4);
            goto L_80808468;
    }
    // 0x80808438: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
L_8080843C:
    // 0x8080843C: mtc1        $t2, $f20
    ctx->f20.u32l = ctx->r10;
    // 0x80808440: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80808444: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80808448: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8080844C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80808450: sub.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x80808454: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80808458: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x8080845C: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80808460: bne         $v0, $a0, L_8080843C
    if (ctx->r2 != ctx->r4) {
        // 0x80808464: lw          $t2, -0x4($v0)
        ctx->r10 = MEM_W(ctx->r2, -0X4);
            goto L_8080843C;
    }
    // 0x80808464: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
L_80808468:
    // 0x80808468: mtc1        $t2, $f20
    ctx->f20.u32l = ctx->r10;
    // 0x8080846C: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80808470: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80808474: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80808478: sub.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x8080847C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80808480: add.s       $f18, $f20, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80808484: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
L_80808488:
    // 0x80808488: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080848C:
    // 0x8080848C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80808490: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80808494: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80808498: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080849C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808084A0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808084A4: jr          $ra
    // 0x808084A8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x808084A8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_808008D4_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008DC: jal         0x808015EC
    // 0x808008E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808015EC_chfpsgame(rdram, ctx);
        goto after_0;
    // 0x808008E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008E4: jal         0x80800FF4
    // 0x808008E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800FF4_chfpsgame(rdram, ctx);
        goto after_1;
    // 0x808008E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008EC: jal         0x80801758
    // 0x808008F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801758_chfpsgame(rdram, ctx);
        goto after_2;
    // 0x808008F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808008F4: jal         0x808018E0
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808018E0_chfpsgame(rdram, ctx);
        goto after_3;
    // 0x808008F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808008FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void func_80800000_vpmodule(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: bne         $a0, $zero, L_80800010
    if (ctx->r4 != 0) {
        // 0x80800004: slti        $at, $a0, 0x4B0
        ctx->r1 = SIGNED(ctx->r4) < 0X4B0 ? 1 : 0;
            goto L_80800010;
    }
    // 0x80800004: slti        $at, $a0, 0x4B0
    ctx->r1 = SIGNED(ctx->r4) < 0X4B0 ? 1 : 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080000C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800010:
    // 0x80800010: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x80800014: slti        $at, $a0, 0x6A4
        ctx->r1 = SIGNED(ctx->r4) < 0X6A4 ? 1 : 0;
            goto L_8080001C;
    }
    // 0x80800014: slti        $at, $a0, 0x6A4
    ctx->r1 = SIGNED(ctx->r4) < 0X6A4 ? 1 : 0;
    // 0x80800018: bne         $at, $zero, L_80800030
    if (ctx->r1 != 0) {
        // 0x8080001C: slti        $at, $a0, 0x834
        ctx->r1 = SIGNED(ctx->r4) < 0X834 ? 1 : 0;
            goto L_80800030;
    }
L_8080001C:
    // 0x8080001C: slti        $at, $a0, 0x834
    ctx->r1 = SIGNED(ctx->r4) < 0X834 ? 1 : 0;
    // 0x80800020: bne         $at, $zero, L_80800038
    if (ctx->r1 != 0) {
        // 0x80800024: slti        $at, $a0, 0x898
        ctx->r1 = SIGNED(ctx->r4) < 0X898 ? 1 : 0;
            goto L_80800038;
    }
    // 0x80800024: slti        $at, $a0, 0x898
    ctx->r1 = SIGNED(ctx->r4) < 0X898 ? 1 : 0;
    // 0x80800028: beql        $at, $zero, L_8080003C
    if (ctx->r1 == 0) {
        // 0x8080002C: slti        $at, $a0, 0xC8
        ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
            goto L_8080003C;
    }
    goto skip_0;
    // 0x8080002C: slti        $at, $a0, 0xC8
    ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
    skip_0:
L_80800030:
    // 0x80800030: jr          $ra
    // 0x80800034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800038:
    // 0x80800038: slti        $at, $a0, 0xC8
    ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
L_8080003C:
    // 0x8080003C: bne         $at, $zero, L_80800054
    if (ctx->r1 != 0) {
        // 0x80800040: slti        $at, $a0, 0x12C
        ctx->r1 = SIGNED(ctx->r4) < 0X12C ? 1 : 0;
            goto L_80800054;
    }
    // 0x80800040: slti        $at, $a0, 0x12C
    ctx->r1 = SIGNED(ctx->r4) < 0X12C ? 1 : 0;
    // 0x80800044: beql        $at, $zero, L_80800058
    if (ctx->r1 == 0) {
        // 0x80800048: slti        $at, $a0, 0x1F4
        ctx->r1 = SIGNED(ctx->r4) < 0X1F4 ? 1 : 0;
            goto L_80800058;
    }
    goto skip_1;
    // 0x80800048: slti        $at, $a0, 0x1F4
    ctx->r1 = SIGNED(ctx->r4) < 0X1F4 ? 1 : 0;
    skip_1:
    // 0x8080004C: jr          $ra
    // 0x80800050: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80800050: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800054:
    // 0x80800054: slti        $at, $a0, 0x1F4
    ctx->r1 = SIGNED(ctx->r4) < 0X1F4 ? 1 : 0;
L_80800058:
    // 0x80800058: bne         $at, $zero, L_80800070
    if (ctx->r1 != 0) {
        // 0x8080005C: slti        $at, $a0, 0x258
        ctx->r1 = SIGNED(ctx->r4) < 0X258 ? 1 : 0;
            goto L_80800070;
    }
    // 0x8080005C: slti        $at, $a0, 0x258
    ctx->r1 = SIGNED(ctx->r4) < 0X258 ? 1 : 0;
    // 0x80800060: beql        $at, $zero, L_80800074
    if (ctx->r1 == 0) {
        // 0x80800064: slti        $at, $a0, 0x64
        ctx->r1 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
            goto L_80800074;
    }
    goto skip_2;
    // 0x80800064: slti        $at, $a0, 0x64
    ctx->r1 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
    skip_2:
    // 0x80800068: jr          $ra
    // 0x8080006C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x8080006C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800070:
    // 0x80800070: slti        $at, $a0, 0x64
    ctx->r1 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
L_80800074:
    // 0x80800074: bne         $at, $zero, L_80800090
    if (ctx->r1 != 0) {
        // 0x80800078: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800090;
    }
    // 0x80800078: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080007C: slti        $at, $a0, 0xC8
    ctx->r1 = SIGNED(ctx->r4) < 0XC8 ? 1 : 0;
    // 0x80800080: beq         $at, $zero, L_80800090
    if (ctx->r1 == 0) {
        // 0x80800084: nop
    
            goto L_80800090;
    }
    // 0x80800084: nop

    // 0x80800088: jr          $ra
    // 0x8080008C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x8080008C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800090:
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_80807A70_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807A70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80807A74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807A78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807A7C: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80807A80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80807A84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80807A88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80807A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80807A90: beql        $t6, $at, L_80807AE8
    if (ctx->r14 == ctx->r1) {
        // 0x80807A94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80807AE8;
    }
    goto skip_0;
    // 0x80807A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80807A98: jal         0x800936CC
    // 0x80807A9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800936CC(rdram, ctx);
        goto after_0;
    // 0x80807A9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80807AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807AA4: jal         0x8009359C
    // 0x80807AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009359C(rdram, ctx);
        goto after_1;
    // 0x80807AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80807AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807AB0: jal         0x80093230
    // 0x80807AB4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80093230(rdram, ctx);
        goto after_2;
    // 0x80807AB4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80807AB8: jal         0x8008CFF0
    // 0x80807ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CFF0(rdram, ctx);
        goto after_3;
    // 0x80807ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807AC4: jal         0x80093370
    // 0x80807AC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093370(rdram, ctx);
        goto after_4;
    // 0x80807AC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80807ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807AD0: jal         0x8009337C
    // 0x80807AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_5;
    // 0x80807AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80807AD8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80807ADC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80807AE0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80807AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807AE8:
    // 0x80807AE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807AEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80807AF0: jr          $ra
    // 0x80807AF4: nop

    return;
    // 0x80807AF4: nop

;}
RECOMP_FUNC void func_8011490C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011490C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80114910: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80114914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80114918: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011491C: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80114920: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x80114924: jal         0x8010FF80
    // 0x80114928: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8010FF80(rdram, ctx);
        goto after_0;
    // 0x80114928: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8011492C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80114930: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80114934: jal         0x800BED18
    // 0x80114938: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800BED18(rdram, ctx);
        goto after_1;
    // 0x80114938: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x8011493C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80114940: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80114944: jal         0x800CA8F4
    // 0x80114948: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    func_800CA8F4(rdram, ctx);
        goto after_2;
    // 0x80114948: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_2:
    // 0x8011494C: jal         0x800BCC58
    // 0x80114950: nop

    func_800BCC58(rdram, ctx);
        goto after_3;
    // 0x80114950: nop

    after_3:
    // 0x80114954: beq         $v0, $zero, L_80114A64
    if (ctx->r2 == 0) {
        // 0x80114958: addiu       $a0, $sp, 0x5C
        ctx->r4 = ADD32(ctx->r29, 0X5C);
            goto L_80114A64;
    }
    // 0x80114958: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8011495C: jal         0x800EE84C
    // 0x80114960: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    func_800EE84C(rdram, ctx);
        goto after_4;
    // 0x80114960: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_4:
    // 0x80114964: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80114968: jal         0x800EE84C
    // 0x8011496C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800EE84C(rdram, ctx);
        goto after_5;
    // 0x8011496C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_5:
    // 0x80114970: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80114974: jal         0x800BCC28
    // 0x80114978: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BCC28(rdram, ctx);
        goto after_6;
    // 0x80114978: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_6:
    // 0x8011497C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80114980: jal         0x800BCC28
    // 0x80114984: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BCC28(rdram, ctx);
        goto after_7;
    // 0x80114984: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_7:
    // 0x80114988: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8011498C: addiu       $v0, $sp, 0x7C
    ctx->r2 = ADD32(ctx->r29, 0X7C);
    // 0x80114990: addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
    // 0x80114994: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80114998: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
L_8011499C:
    // 0x8011499C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801149A0: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801149A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x801149A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801149AC: nop

    // 0x801149B0: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801149B4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x801149B8: nop

    // 0x801149BC: bc1fl       L_801149E0
    if (!c1cs) {
        // 0x801149C0: lw          $t0, 0x0($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X0);
            goto L_801149E0;
    }
    goto skip_0;
    // 0x801149C0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x801149C4: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801149C8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801149CC: nop

    // 0x801149D0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801149D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801149D8: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801149DC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
L_801149E0:
    // 0x801149E0: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801149E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801149E8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801149EC: nop

    // 0x801149F0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801149F4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801149F8: nop

    // 0x801149FC: bc1fl       L_80114A20
    if (!c1cs) {
        // 0x80114A00: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80114A20;
    }
    goto skip_1;
    // 0x80114A00: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x80114A04: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80114A08: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80114A0C: nop

    // 0x80114A10: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80114A14: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80114A18: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80114A1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80114A20:
    // 0x80114A20: nop

    // 0x80114A24: bc1fl       L_80114A40
    if (!c1cs) {
        // 0x80114A28: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_80114A40;
    }
    goto skip_2;
    // 0x80114A28: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_2:
    // 0x80114A2C: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80114A30: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80114A34: nop

    // 0x80114A38: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80114A3C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_80114A40:
    // 0x80114A40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80114A44: bc1f        L_80114A5C
    if (!c1cs) {
        // 0x80114A48: nop
    
            goto L_80114A5C;
    }
    // 0x80114A48: nop

    // 0x80114A4C: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80114A50: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80114A54: nop

    // 0x80114A58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80114A5C:
    // 0x80114A5C: bne         $a0, $a2, L_8011499C
    if (ctx->r4 != ctx->r6) {
        // 0x80114A60: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8011499C;
    }
    // 0x80114A60: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80114A64:
    // 0x80114A64: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80114A68: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80114A6C: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80114A70: jal         0x800E36D0
    // 0x80114A74: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    func_800E36D0(rdram, ctx);
        goto after_8;
    // 0x80114A74: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_8:
    // 0x80114A78: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80114A7C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80114A80: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80114A84: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80114A88: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80114A8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80114A90: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x80114A94: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80114A98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80114A9C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80114AA0: bc1fl       L_80114AB8
    if (!c1cs) {
        // 0x80114AA4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80114AB8;
    }
    goto skip_3;
    // 0x80114AA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_3:
    // 0x80114AA8: swc1        $f2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f2.u32l;
    // 0x80114AAC: b           L_80114AD4
    // 0x80114AB0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
        goto L_80114AD4;
    // 0x80114AB0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80114AB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80114AB8:
    // 0x80114AB8: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80114ABC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80114AC0: nop

    // 0x80114AC4: bc1fl       L_80114AD8
    if (!c1cs) {
        // 0x80114AC8: lui         $at, 0x3C00
        ctx->r1 = S32(0X3C00 << 16);
            goto L_80114AD8;
    }
    goto skip_4;
    // 0x80114AC8: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    skip_4:
    // 0x80114ACC: swc1        $f2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f2.u32l;
    // 0x80114AD0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
L_80114AD4:
    // 0x80114AD4: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
L_80114AD8:
    // 0x80114AD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80114ADC: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80114AE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80114AE4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80114AE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80114AEC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80114AF0: nop

    // 0x80114AF4: bc1f        L_80114B04
    if (!c1cs) {
        // 0x80114AF8: swc1        $f4, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
            goto L_80114B04;
    }
    // 0x80114AF8: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80114AFC: b           L_80114B44
    // 0x80114B00: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
        goto L_80114B44;
    // 0x80114B00: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
L_80114B04:
    // 0x80114B04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80114B08: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80114B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80114B10: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80114B14: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80114B18: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    // 0x80114B1C: bc1f        L_80114B2C
    if (!c1cs) {
        // 0x80114B20: nop
    
            goto L_80114B2C;
    }
    // 0x80114B20: nop

    // 0x80114B24: b           L_80114B44
    // 0x80114B28: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
        goto L_80114B44;
    // 0x80114B28: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_80114B2C:
    // 0x80114B2C: jal         0x80114774
    // 0x80114B30: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    func_80114774(rdram, ctx);
        goto after_9;
    // 0x80114B30: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    after_9:
    // 0x80114B34: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80114B38: jal         0x800F13F0
    // 0x80114B3C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F13F0(rdram, ctx);
        goto after_10;
    // 0x80114B3C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_10:
    // 0x80114B40: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_80114B44:
    // 0x80114B44: jal         0x800A940C
    // 0x80114B48: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    func_800A940C(rdram, ctx);
        goto after_11;
    // 0x80114B48: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_11:
    // 0x80114B4C: jal         0x800C5190
    // 0x80114B50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C5190(rdram, ctx);
        goto after_12;
    // 0x80114B50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80114B54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80114B58: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80114B5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80114B60: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80114B64: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x80114B68: nop

    // 0x80114B6C: bc1tl       L_80114B94
    if (c1cs) {
        // 0x80114B70: lwc1        $f8, 0x8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80114B94;
    }
    goto skip_5;
    // 0x80114B70: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    skip_5:
    // 0x80114B74: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80114B78: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80114B7C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80114B80: nop

    // 0x80114B84: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80114B88: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80114B8C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80114B90: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
L_80114B94:
    // 0x80114B94: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80114B98: nop

    // 0x80114B9C: bc1fl       L_80114BC0
    if (!c1cs) {
        // 0x80114BA0: sb          $zero, 0x3($s0)
        MEM_B(0X3, ctx->r16) = 0;
            goto L_80114BC0;
    }
    goto skip_6;
    // 0x80114BA0: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    skip_6:
    // 0x80114BA4: lbu         $t8, 0x4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4);
    // 0x80114BA8: beql        $t8, $zero, L_80114BC0
    if (ctx->r24 == 0) {
        // 0x80114BAC: sb          $zero, 0x3($s0)
        MEM_B(0X3, ctx->r16) = 0;
            goto L_80114BC0;
    }
    goto skip_7;
    // 0x80114BAC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    skip_7:
    // 0x80114BB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80114BB4: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80114BB8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80114BBC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
L_80114BC0:
    // 0x80114BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80114BC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80114BC8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80114BCC: jr          $ra
    // 0x80114BD0: nop

    return;
    // 0x80114BD0: nop

;}
