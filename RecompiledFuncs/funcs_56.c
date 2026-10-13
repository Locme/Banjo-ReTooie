#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808002C0_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002C4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x808002C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002CC: beq         $a1, $at, L_8080031C
    if (ctx->r5 == ctx->r1) {
        // 0x808002D0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080031C;
    }
    // 0x808002D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002D4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808002D8: beq         $a1, $at, L_808002F0
    if (ctx->r5 == ctx->r1) {
        // 0x808002DC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808002F0;
    }
    // 0x808002DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002E0: beq         $a1, $at, L_8080030C
    if (ctx->r5 == ctx->r1) {
        // 0x808002E4: nop
    
            goto L_8080030C;
    }
    // 0x808002E4: nop

    // 0x808002E8: b           L_8080034C
    // 0x808002EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080034C;
    // 0x808002EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F0:
    // 0x808002F0: jal         0x80800B40
    // 0x808002F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800B40_chdumbwaiterlift(rdram, ctx);
        goto after_0;
    // 0x808002F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002FC: jal         0x80101FDC
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800304: b           L_8080034C
    // 0x80800308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080034C;
    // 0x80800308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080030C:
    // 0x8080030C: jal         0x808003C4
    // 0x80800310: nop

    func_808003C4_chdumbwaiterlift(rdram, ctx);
        goto after_2;
    // 0x80800310: nop

    after_2:
    // 0x80800314: b           L_8080034C
    // 0x80800318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080034C;
    // 0x80800318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080031C:
    // 0x8080031C: jal         0x80101080
    // 0x80800320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_3;
    // 0x80800320: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080032C: lh          $a2, 0x20($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X20);
    // 0x80800330: jal         0x80800608
    // 0x80800334: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    func_80800608_chdumbwaiterlift(rdram, ctx);
        goto after_4;
    // 0x80800334: lh          $a3, 0x22($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X22);
    after_4:
    // 0x80800338: b           L_8080034C
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080034C;
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800340: b           L_8080034C
    // 0x80800344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080034C;
    // 0x80800344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080034C:
    // 0x8080034C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_8080069C_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808006A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808006AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006B0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808006B4: beq         $t6, $at, L_808006D8
    if (ctx->r14 == ctx->r1) {
        // 0x808006B8: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_808006D8;
    }
    // 0x808006B8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808006BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808006C0: beq         $t6, $at, L_808006D8
    if (ctx->r14 == ctx->r1) {
        // 0x808006C4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808006D8;
    }
    // 0x808006C4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808006C8: beq         $t6, $at, L_808006D8
    if (ctx->r14 == ctx->r1) {
        // 0x808006CC: nop
    
            goto L_808006D8;
    }
    // 0x808006CC: nop

    // 0x808006D0: b           L_808006D8
    // 0x808006D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_808006D8;
    // 0x808006D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_808006D8:
    // 0x808006D8: bne         $a2, $zero, L_808006F4
    if (ctx->r6 != 0) {
        // 0x808006DC: lui         $a3, 0x8080
        ctx->r7 = S32(RELOC_HI16(972, 0XF68) << 16);
            goto L_808006F4;
    }
    // 0x808006DC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(972, 0XF68) << 16);
    // 0x808006E0: bnel        $a2, $zero, L_80800700
    if (ctx->r6 != 0) {
        // 0x808006E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800700;
    }
    goto skip_0;
    // 0x808006E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006E8: lbu         $t7, 0x5F($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5F);
    // 0x808006EC: beql        $t7, $zero, L_80800700
    if (ctx->r15 == 0) {
        // 0x808006F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800700;
    }
    goto skip_1;
    // 0x808006F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_808006F4:
    // 0x808006F4: jal         0x80089D50
    // 0x808006F8: addiu       $a3, $a3, 0xF68
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(972, 0XF68));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808006F8: addiu       $a3, $a3, 0xF68
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(972, 0XF68));
    after_0:
    // 0x808006FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800700:
    // 0x80800700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800704: jr          $ra
    // 0x80800708: nop

    return;
    // 0x80800708: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E60: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E60);
    return;
    // 0x80089E64: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80801010_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801010: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080101C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801024: jal         0x80100094
    // 0x80801028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080102C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80801030: jal         0x80800030
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_chsabreman(rdram, ctx);
        goto after_1;
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801038: beql        $v0, $zero, L_8080111C
    if (ctx->r2 == 0) {
        // 0x8080103C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080111C;
    }
    goto skip_0;
    // 0x8080103C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801040: jal         0x800CB3E0
    // 0x80801044: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800CB3E0(rdram, ctx);
        goto after_2;
    // 0x80801044: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80801048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080104C: beq         $v0, $at, L_80801118
    if (ctx->r2 == ctx->r1) {
        // 0x80801050: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801118;
    }
    // 0x80801050: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801054: beq         $v0, $at, L_8080107C
    if (ctx->r2 == ctx->r1) {
        // 0x80801058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080107C;
    }
    // 0x80801058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080105C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801060: beq         $v0, $at, L_80801090
    if (ctx->r2 == ctx->r1) {
        // 0x80801064: addiu       $a0, $zero, 0x154
        ctx->r4 = ADD32(0, 0X154);
            goto L_80801090;
    }
    // 0x80801064: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    // 0x80801068: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080106C: beq         $v0, $at, L_80801108
    if (ctx->r2 == ctx->r1) {
        // 0x80801070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801108;
    }
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801074: b           L_8080111C
    // 0x80801078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080111C;
    // 0x80801078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080107C:
    // 0x8080107C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80801080: jal         0x8008A548
    // 0x80801084: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _subaddietaxi_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80801084: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_3:
    // 0x80801088: b           L_8080111C
    // 0x8080108C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080111C;
    // 0x8080108C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801090:
    // 0x80801090: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801094: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80801098: jal         0x800882F0
    // 0x8080109C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x8080109C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808010A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808010A4: jal         0x800EE88C
    // 0x808010A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_5;
    // 0x808010A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x808010AC: addiu       $a0, $zero, 0x347
    ctx->r4 = ADD32(0, 0X347);
    // 0x808010B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010B4: jal         0x800882F0
    // 0x808010B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _gccubesearch_entrypoint_15(rdram, ctx);
        goto after_6;
    // 0x808010B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808010BC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808010C0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808010C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808010C8: jal         0x800EE814
    // 0x808010CC: addiu       $a0, $a0, 0x81A
    ctx->r4 = ADD32(ctx->r4, 0X81A);
    func_800EE814(rdram, ctx);
        goto after_7;
    // 0x808010CC: addiu       $a0, $a0, 0x81A
    ctx->r4 = ADD32(ctx->r4, 0X81A);
    after_7:
    // 0x808010D0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808010D4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010DC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x808010E0: srl         $t8, $t7, 23
    ctx->r24 = S32(U32(ctx->r15) >> 23);
    // 0x808010E4: jal         0x8010A570
    // 0x808010E8: sh          $t8, 0x818($t9)
    MEM_H(0X818, ctx->r25) = ctx->r24;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x808010E8: sh          $t8, 0x818($t9)
    MEM_H(0X818, ctx->r25) = ctx->r24;
    after_8:
    // 0x808010EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808010F4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x808010F8: jal         0x8008A4F8
    // 0x808010FC: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    _subaddietaxi_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808010FC: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_9:
    // 0x80801100: b           L_8080111C
    // 0x80801104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080111C;
    // 0x80801104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801108:
    // 0x80801108: jal         0x808011F8
    // 0x8080110C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_10;
    // 0x8080110C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_10:
    // 0x80801110: jal         0x8010A570
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_11;
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80801118:
    // 0x80801118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080111C:
    // 0x8080111C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801120: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801124: jr          $ra
    // 0x80801128: nop

    return;
    // 0x80801128: nop

;}
RECOMP_FUNC void func_800ADF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADF98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ADF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ADFA0: jal         0x8001ACCC
    // 0x800ADFA4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800ADFA4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_0:
    // 0x800ADFA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800ADFAC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800ADFB0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800ADFB4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800ADFB8: jal         0x80019CD4
    // 0x800ADFBC: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    func_80019CD4(rdram, ctx);
        goto after_1;
    // 0x800ADFBC: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    after_1:
    // 0x800ADFC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADFC4: jal         0x80018AD0
    // 0x800ADFC8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    mlMtxGet(rdram, ctx);
        goto after_2;
    // 0x800ADFC8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_2:
    // 0x800ADFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ADFD0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADFD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ADFD8: jr          $ra
    // 0x800ADFDC: nop

    return;
    // 0x800ADFDC: nop

;}
RECOMP_FUNC void _suspline_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DF8: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DF8);
    return;
    // 0x80089DFC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D90: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084D90);
    return;
    // 0x80084D94: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chnests_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AD8: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AD8);
    return;
    // 0x80085ADC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void chdippy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1284, 0X1580) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1284, 0X1580));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1284, 0X1580));
;}
RECOMP_FUNC void baduo_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x808002CC: jr          $ra
    // 0x808002D0: sb          $a1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r5;
    return;
    // 0x808002D0: sb          $a1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800F1F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1F3C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800F1F40: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F1F44: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F1F48: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F1F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1F50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F1F54: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800F1F58: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F1F5C: bc1f        L_800F1F6C
    if (!c1cs) {
        // 0x800F1F60: nop
    
            goto L_800F1F6C;
    }
    // 0x800F1F60: nop

    // 0x800F1F64: b           L_800F1FE0
    // 0x800F1F68: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
        goto L_800F1FE0;
    // 0x800F1F68: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
L_800F1F6C:
    // 0x800F1F6C: jal         0x800F1DCC
    // 0x800F1F70: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x800F1F70: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800F1F74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F1F78: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F1F7C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800F1F80: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800F1F84: nop

    // 0x800F1F88: bc1fl       L_800F1FB8
    if (!c1cs) {
        // 0x800F1F8C: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_800F1FB8;
    }
    goto skip_0;
    // 0x800F1F8C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_0:
    // 0x800F1F90: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800F1F94: nop

    // 0x800F1F98: bc1fl       L_800F1FAC
    if (!c1cs) {
        // 0x800F1F9C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_800F1FAC;
    }
    goto skip_1;
    // 0x800F1F9C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_1:
    // 0x800F1FA0: b           L_800F1FD8
    // 0x800F1FA4: nop

        goto L_800F1FD8;
    // 0x800F1FA4: nop

    // 0x800F1FA8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800F1FAC:
    // 0x800F1FAC: b           L_800F1FD8
    // 0x800F1FB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800F1FD8;
    // 0x800F1FB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800F1FB4: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_800F1FB8:
    // 0x800F1FB8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800F1FBC: nop

    // 0x800F1FC0: bc1fl       L_800F1FD4
    if (!c1cs) {
        // 0x800F1FC4: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_800F1FD4;
    }
    goto skip_2;
    // 0x800F1FC4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_2:
    // 0x800F1FC8: b           L_800F1FD4
    // 0x800F1FCC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_800F1FD4;
    // 0x800F1FCC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F1FD0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_800F1FD4:
    // 0x800F1FD4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800F1FD8:
    // 0x800F1FD8: jal         0x800136E4
    // 0x800F1FDC: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x800F1FDC: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
    after_1:
L_800F1FE0:
    // 0x800F1FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1FE8: jr          $ra
    // 0x800F1FEC: nop

    return;
    // 0x800F1FEC: nop

;}
RECOMP_FUNC void func_800A877C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A877C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A8780: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A8784: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A8788: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A878C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800A8790: lw          $t7, 0x7688($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7688);
    // 0x800A8794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A879C: beq         $t7, $zero, L_800A87AC
    if (ctx->r15 == 0) {
        // 0x800A87A0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800A87AC;
    }
    // 0x800A87A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A87A4: b           L_800A87EC
    // 0x800A87A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A87EC;
    // 0x800A87A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A87AC:
    // 0x800A87AC: addiu       $v0, $v0, 0x7670
    ctx->r2 = ADD32(ctx->r2, 0X7670);
    // 0x800A87B0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A87B4: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800A87B8: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800A87BC: bne         $at, $zero, L_800A87D4
    if (ctx->r1 != 0) {
        // 0x800A87C0: nop
    
            goto L_800A87D4;
    }
    // 0x800A87C0: nop

    // 0x800A87C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A87C8: jal         0x800A85A8
    // 0x800A87CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A85A8(rdram, ctx);
        goto after_0;
    // 0x800A87CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A87D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_800A87D4:
    // 0x800A87D4: jal         0x800A8380
    // 0x800A87D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A8380(rdram, ctx);
        goto after_1;
    // 0x800A87D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800A87DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A87E0: jal         0x800A84EC
    // 0x800A87E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A84EC(rdram, ctx);
        goto after_2;
    // 0x800A87E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x800A87E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A87EC:
    // 0x800A87EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A87F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A87F4: jr          $ra
    // 0x800A87F8: nop

    return;
    // 0x800A87F8: nop

;}
RECOMP_FUNC void func_80112168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112168: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8011216C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112170: jal         0x80110840
    // 0x80112174: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80112174: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80112178: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8011217C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112180: jal         0x800F5BC4
    // 0x80112184: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800F5BC4(rdram, ctx);
        goto after_1;
    // 0x80112184: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80112188: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8011218C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80112190: jal         0x800F5A00
    // 0x80112194: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80112194: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80112198: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8011219C: jal         0x800EF04C
    // 0x801121A0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x801121A0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x801121A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801121A8: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801121AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801121B0: jr          $ra
    // 0x801121B4: nop

    return;
    // 0x801121B4: nop

;}
RECOMP_FUNC void _bsdronegoto_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830D8: syscall     43
    recomp_syscall_handler(rdram, ctx, 0x800830D8);
    return;
    // 0x800830DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800088_chfactoryflypad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800094: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800098: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x8080009C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808000A0: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808000A4: bne         $t8, $at, L_808000CC
    if (ctx->r24 != ctx->r1) {
        // 0x808000A8: nop
    
            goto L_808000CC;
    }
    // 0x808000A8: nop

    // 0x808000AC: jal         0x80088840
    // 0x808000B0: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x808000B0: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_0:
    // 0x808000B4: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000B8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000CC;
    }
    // 0x808000B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000BC: jal         0x80108B04
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808000C8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_808000CC:
    // 0x808000CC: jal         0x80088840
    // 0x808000D0: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x808000D0: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_2:
    // 0x808000D4: bnel        $v0, $zero, L_80800100
    if (ctx->r2 != 0) {
        // 0x808000D8: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_80800100;
    }
    goto skip_0;
    // 0x808000D8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000DC: jal         0x800DA298
    // 0x808000E0: addiu       $a0, $zero, 0x16B
    ctx->r4 = ADD32(0, 0X16B);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808000E0: addiu       $a0, $zero, 0x16B
    ctx->r4 = ADD32(0, 0X16B);
    after_3:
    // 0x808000E4: beq         $v0, $zero, L_808000FC
    if (ctx->r2 == 0) {
        // 0x808000E8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000FC;
    }
    // 0x808000E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808000F0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x808000F4: jal         0x80108B04
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_808000FC:
    // 0x808000FC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80800100:
    // 0x80800100: bnel        $t1, $zero, L_80800124
    if (ctx->r9 != 0) {
        // 0x80800104: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800124;
    }
    goto skip_1;
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800108: jal         0x80088840
    // 0x8080010C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x8080010C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_5:
    // 0x80800110: bnel        $v0, $zero, L_80800124
    if (ctx->r2 != 0) {
        // 0x80800114: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800124;
    }
    goto skip_2;
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800118: jal         0x800FFAB0
    // 0x8080011C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x8080011C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800124:
    // 0x80800124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void sulights_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080075C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800760: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800768: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080076C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800770: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800774: jal         0x80800000
    // 0x80800778: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80800000_sulights(rdram, ctx);
        goto after_0;
    // 0x80800778: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8080077C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3374, 0X9F0) << 16);
    // 0x80800780: lwc1        $f0, 0x9F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3374, 0X9F0));
    // 0x80800784: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800788: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080078C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800790: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800798: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080079C: bc1fl       L_808007B0
    if (!c1cs) {
        // 0x808007A0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_808007B0;
    }
    goto skip_0;
    // 0x808007A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x808007A4: b           L_808007BC
    // 0x808007A8: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
        goto L_808007BC;
    // 0x808007A8: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x808007AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_808007B0:
    // 0x808007B0: nop

    // 0x808007B4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x808007B8: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
L_808007BC:
    // 0x808007BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808007C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_808007C4:
    // 0x808007C4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808007C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808007CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808007D0: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x808007D4: lwc1        $f16, -0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X4);
    // 0x808007D8: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x808007DC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808007E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808007E4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808007E8: bne         $a1, $a3, L_808007C4
    if (ctx->r5 != ctx->r7) {
        // 0x808007EC: swc1        $f18, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
            goto L_808007C4;
    }
    // 0x808007EC: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x808007F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007F4: jal         0x800C8D4C
    // 0x808007F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C8D4C(rdram, ctx);
        goto after_1;
    // 0x808007F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808007FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800804: jr          $ra
    // 0x80800808: nop

    return;
    // 0x80800808: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CB0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CB0);
    return;
    // 0x80083CB4: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void bstaxi_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800154: jal         0x8009E77C
    // 0x80800158: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800158: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x8080015C: bnel        $v0, $zero, L_8080019C
    if (ctx->r2 != 0) {
        // 0x80800160: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080019C;
    }
    goto skip_0;
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800164: jal         0x8009EFA8
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_1;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080016C: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800170: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x8009F1C8
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_2;
    // 0x8080017C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800188: jal         0x8009F1C8
    // 0x8080018C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x8080018C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800190: jal         0x8009E4AC
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_4;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080019C:
    // 0x8080019C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void _badrone_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084838: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084838);
    return;
    // 0x8008483C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void gzreg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: jr          $ra
    // 0x80800594: lw          $v0, 0x11C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X11C);
    return;
    // 0x80800594: lw          $v0, 0x11C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X11C);
    // 0x80800598: nop

    // 0x8080059C: nop

;}
RECOMP_FUNC void func_800E8CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8CE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8CE8: jal         0x800E8CB0
    // 0x800E8CEC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    func_800E8CB0(rdram, ctx);
        goto after_0;
    // 0x800E8CEC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    after_0:
    // 0x800E8CF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E8CF4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800E8CF8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800E8CFC: jal         0x800E8D28
    // 0x800E8D00: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    func_800E8D28(rdram, ctx);
        goto after_1;
    // 0x800E8D00: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    after_1:
    // 0x800E8D04: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800E8D08: addiu       $a1, $a1, 0x3500
    ctx->r5 = ADD32(ctx->r5, 0X3500);
    // 0x800E8D0C: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x800E8D10: jal         0x800E8D5C
    // 0x800E8D14: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800E8D5C(rdram, ctx);
        goto after_2;
    // 0x800E8D14: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x800E8D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8D20: jr          $ra
    // 0x800E8D24: nop

    return;
    // 0x800E8D24: nop

;}
RECOMP_FUNC void func_80102424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102424: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80102428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010242C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80102430: jal         0x80102394
    // 0x80102434: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80102394(rdram, ctx);
        goto after_0;
    // 0x80102434: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80102438: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8010243C: jal         0x80104248
    // 0x80102440: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80104248(rdram, ctx);
        goto after_1;
    // 0x80102440: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80102444: beq         $v0, $zero, L_80102484
    if (ctx->r2 == 0) {
        // 0x80102448: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102484;
    }
    // 0x80102448: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010244C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80102450: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80102454: beq         $t6, $zero, L_80102484
    if (ctx->r14 == 0) {
        // 0x80102458: sll         $t8, $t7, 3
        ctx->r24 = S32(ctx->r15 << 3);
            goto L_80102484;
    }
    // 0x80102458: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8010245C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80102460: lhu         $v0, 0x6($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X6);
    // 0x80102464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80102468: andi        $t0, $v0, 0x200
    ctx->r8 = ctx->r2 & 0X200;
    // 0x8010246C: beq         $t0, $zero, L_8010247C
    if (ctx->r8 == 0) {
        // 0x80102470: nop
    
            goto L_8010247C;
    }
    // 0x80102470: nop

    // 0x80102474: b           L_8010247C
    // 0x80102478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8010247C;
    // 0x80102478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8010247C:
    // 0x8010247C: jal         0x8008B1A0
    // 0x80102480: nop

    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80102480: nop

    after_2:
L_80102484:
    // 0x80102484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80102488: jal         0x80101FDC
    // 0x8010248C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x8010248C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80102490: jal         0x80104248
    // 0x80102494: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80104248(rdram, ctx);
        goto after_4;
    // 0x80102494: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80102498: beq         $v0, $zero, L_8010261C
    if (ctx->r2 == 0) {
        // 0x8010249C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_8010261C;
    }
    // 0x8010249C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801024A0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x801024A4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x801024A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801024AC: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x801024B0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x801024B4: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x801024B8: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x801024BC: beq         $t7, $zero, L_801024F0
    if (ctx->r15 == 0) {
        // 0x801024C0: sw          $t5, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r13;
            goto L_801024F0;
    }
    // 0x801024C0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801024C4: jal         0x8008B134
    // 0x801024C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x801024C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x801024CC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801024D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801024D4: andi        $t8, $t6, 0x100
    ctx->r24 = ctx->r14 & 0X100;
    // 0x801024D8: beq         $t8, $zero, L_801024E8
    if (ctx->r24 == 0) {
        // 0x801024DC: nop
    
            goto L_801024E8;
    }
    // 0x801024DC: nop

    // 0x801024E0: b           L_801024E8
    // 0x801024E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_801024E8;
    // 0x801024E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801024E8:
    // 0x801024E8: jal         0x8008B4A8
    // 0x801024EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008B4A8(rdram, ctx);
        goto after_6;
    // 0x801024EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_801024F0:
    // 0x801024F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801024F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801024F8: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x801024FC: beql        $t0, $zero, L_80102510
    if (ctx->r8 == 0) {
        // 0x80102500: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_80102510;
    }
    goto skip_0;
    // 0x80102500: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80102504: jal         0x8008B134
    // 0x80102508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80102508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8010250C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_80102510:
    // 0x80102510: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80102514: andi        $t1, $t2, 0x4
    ctx->r9 = ctx->r10 & 0X4;
    // 0x80102518: beql        $t1, $zero, L_8010252C
    if (ctx->r9 == 0) {
        // 0x8010251C: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_8010252C;
    }
    goto skip_1;
    // 0x8010251C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80102520: jal         0x8008B134
    // 0x80102524: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80102524: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80102528: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_8010252C:
    // 0x8010252C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80102530: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x80102534: beql        $t4, $zero, L_80102548
    if (ctx->r12 == 0) {
        // 0x80102538: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_80102548;
    }
    goto skip_2;
    // 0x80102538: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    skip_2:
    // 0x8010253C: jal         0x8008B188
    // 0x80102540: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_9;
    // 0x80102540: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80102544: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
L_80102548:
    // 0x80102548: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8010254C: andi        $t7, $t5, 0x10
    ctx->r15 = ctx->r13 & 0X10;
    // 0x80102550: beql        $t7, $zero, L_80102564
    if (ctx->r15 == 0) {
        // 0x80102554: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80102564;
    }
    goto skip_3;
    // 0x80102554: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_3:
    // 0x80102558: jal         0x8008B188
    // 0x8010255C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_10;
    // 0x8010255C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80102560: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_80102564:
    // 0x80102564: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80102568: andi        $t8, $t6, 0x800
    ctx->r24 = ctx->r14 & 0X800;
    // 0x8010256C: beql        $t8, $zero, L_8010259C
    if (ctx->r24 == 0) {
        // 0x80102570: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8010259C;
    }
    goto skip_4;
    // 0x80102570: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_4:
    // 0x80102574: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80102578: jal         0x800DC298
    // 0x8010257C: nop

    func_800DC298(rdram, ctx);
        goto after_11;
    // 0x8010257C: nop

    after_11:
    // 0x80102580: beq         $v0, $zero, L_80102590
    if (ctx->r2 == 0) {
        // 0x80102584: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80102590;
    }
    // 0x80102584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80102588: b           L_80102590
    // 0x8010258C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80102590;
    // 0x8010258C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80102590:
    // 0x80102590: jal         0x8008B188
    // 0x80102594: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008B188(rdram, ctx);
        goto after_12;
    // 0x80102594: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x80102598: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_8010259C:
    // 0x8010259C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801025A0: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x801025A4: beql        $t0, $zero, L_801025B8
    if (ctx->r8 == 0) {
        // 0x801025A8: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_801025B8;
    }
    goto skip_5;
    // 0x801025A8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    skip_5:
    // 0x801025AC: jal         0x8008B10C
    // 0x801025B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8008B10C(rdram, ctx);
        goto after_13;
    // 0x801025B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x801025B4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_801025B8:
    // 0x801025B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801025BC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x801025C0: andi        $t1, $t2, 0x80
    ctx->r9 = ctx->r10 & 0X80;
    // 0x801025C4: beql        $t1, $zero, L_801025D8
    if (ctx->r9 == 0) {
        // 0x801025C8: lw          $t3, 0x18($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X18);
            goto L_801025D8;
    }
    goto skip_6;
    // 0x801025C8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    skip_6:
    // 0x801025CC: jal         0x8008B10C
    // 0x801025D0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_8008B10C(rdram, ctx);
        goto after_14;
    // 0x801025D0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_14:
    // 0x801025D4: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_801025D8:
    // 0x801025D8: andi        $t4, $t3, 0x400
    ctx->r12 = ctx->r11 & 0X400;
    // 0x801025DC: beql        $t4, $zero, L_801025FC
    if (ctx->r12 == 0) {
        // 0x801025E0: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_801025FC;
    }
    goto skip_7;
    // 0x801025E0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    skip_7:
    // 0x801025E4: jal         0x800DC0C0
    // 0x801025E8: nop

    func_800DC0C0(rdram, ctx);
        goto after_15;
    // 0x801025E8: nop

    after_15:
    // 0x801025EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801025F0: jal         0x8008B10C
    // 0x801025F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008B10C(rdram, ctx);
        goto after_16;
    // 0x801025F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x801025F8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
L_801025FC:
    // 0x801025FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80102600: andi        $t7, $t5, 0x20
    ctx->r15 = ctx->r13 & 0X20;
    // 0x80102604: beq         $t7, $zero, L_80102614
    if (ctx->r15 == 0) {
        // 0x80102608: nop
    
            goto L_80102614;
    }
    // 0x80102608: nop

    // 0x8010260C: b           L_80102614
    // 0x80102610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80102614;
    // 0x80102610: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80102614:
    // 0x80102614: jal         0x80102190
    // 0x80102618: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80102190(rdram, ctx);
        goto after_17;
    // 0x80102618: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_17:
L_8010261C:
    // 0x8010261C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102620: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80102624: jr          $ra
    // 0x80102628: nop

    return;
    // 0x80102628: nop

;}
RECOMP_FUNC void _babounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845C8: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845C8);
    return;
    // 0x800845CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800274_bsstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080027C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800280: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800284: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080028C: lui         $a1, 0x3E52
    ctx->r5 = S32(0X3E52 << 16);
    // 0x80800290: jal         0x8008B348
    // 0x80800294: ori         $a1, $a1, 0xA305
    ctx->r5 = ctx->r5 | 0XA305;
    anctrl_isAt(rdram, ctx);
        goto after_0;
    // 0x80800294: ori         $a1, $a1, 0xA305
    ctx->r5 = ctx->r5 | 0XA305;
    after_0:
    // 0x80800298: beq         $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x8080029C: lui         $a2, 0x3FE6
        ctx->r6 = S32(0X3FE6 << 16);
            goto L_808002CC;
    }
    // 0x8080029C: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808002A0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x808002AC: jal         0x8009DF94
    // 0x808002B0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_1;
    // 0x808002B0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_1:
    // 0x808002B4: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808002B8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x808002C4: jal         0x80085490
    // 0x808002C8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808002C8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_2:
L_808002CC:
    // 0x808002CC: lui         $a1, 0x3E52
    ctx->r5 = S32(0X3E52 << 16);
    // 0x808002D0: ori         $a1, $a1, 0xA305
    ctx->r5 = ctx->r5 | 0XA305;
    // 0x808002D4: jal         0x8008B348
    // 0x808002D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808002D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808002DC: beql        $v0, $zero, L_808002F0
    if (ctx->r2 == 0) {
        // 0x808002E0: lui         $a1, 0x3E82
        ctx->r5 = S32(0X3E82 << 16);
            goto L_808002F0;
    }
    goto skip_0;
    // 0x808002E0: lui         $a1, 0x3E82
    ctx->r5 = S32(0X3E82 << 16);
    skip_0:
    // 0x808002E4: jal         0x8009514C
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_4;
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002EC: lui         $a1, 0x3E82
    ctx->r5 = S32(0X3E82 << 16);
L_808002F0:
    // 0x808002F0: ori         $a1, $a1, 0xD0E5
    ctx->r5 = ctx->r5 | 0XD0E5;
    // 0x808002F4: jal         0x8008B348
    // 0x808002F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x808002F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808002FC: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x80800300: lui         $a2, 0x3FE6
        ctx->r6 = S32(0X3FE6 << 16);
            goto L_80800330;
    }
    // 0x80800300: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800304: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x80800310: jal         0x8009DF94
    // 0x80800314: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_6;
    // 0x80800314: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_6:
    // 0x80800318: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x8080031C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80800328: jal         0x80085490
    // 0x8080032C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x8080032C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_7:
L_80800330:
    // 0x80800330: lui         $a1, 0x3E94
    ctx->r5 = S32(0X3E94 << 16);
    // 0x80800334: ori         $a1, $a1, 0x4674
    ctx->r5 = ctx->r5 | 0X4674;
    // 0x80800338: jal         0x8008B348
    // 0x8080033C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x8080033C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800340: beq         $v0, $zero, L_80800374
    if (ctx->r2 == 0) {
        // 0x80800344: lui         $a2, 0x3FE6
        ctx->r6 = S32(0X3FE6 << 16);
            goto L_80800374;
    }
    // 0x80800344: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800348: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x80800354: jal         0x8009DF94
    // 0x80800358: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_9;
    // 0x80800358: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_9:
    // 0x8080035C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800360: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8080036C: jal         0x80085490
    // 0x80800370: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800370: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_10:
L_80800374:
    // 0x80800374: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800378: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080037C: jal         0x8008B348
    // 0x80800380: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x80800380: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80800384: beq         $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x80800388: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080039C;
    }
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: addiu       $a1, $zero, 0x445
    ctx->r5 = ADD32(0, 0X445);
    // 0x80800390: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800394: jal         0x8009DF94
    // 0x80800398: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF94(rdram, ctx);
        goto after_12;
    // 0x80800398: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_12:
L_8080039C:
    // 0x8080039C: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x808003A0: ori         $a1, $a1, 0xADAC
    ctx->r5 = ctx->r5 | 0XADAC;
    // 0x808003A4: jal         0x8008B348
    // 0x808003A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x808003A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808003AC: beql        $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808003B0: lui         $a1, 0x3ED6
        ctx->r5 = S32(0X3ED6 << 16);
            goto L_808003C0;
    }
    goto skip_1;
    // 0x808003B0: lui         $a1, 0x3ED6
    ctx->r5 = S32(0X3ED6 << 16);
    skip_1:
    // 0x808003B4: jal         0x800951B4
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_14;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003BC: lui         $a1, 0x3ED6
    ctx->r5 = S32(0X3ED6 << 16);
L_808003C0:
    // 0x808003C0: ori         $a1, $a1, 0x2B6B
    ctx->r5 = ctx->r5 | 0X2B6B;
    // 0x808003C4: jal         0x8008B348
    // 0x808003C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_15;
    // 0x808003C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x808003CC: beq         $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x808003D0: lui         $a2, 0x3FCC
        ctx->r6 = S32(0X3FCC << 16);
            goto L_808003E4;
    }
    // 0x808003D0: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x808003D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: jal         0x8009DF58
    // 0x808003E0: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    func_8009DF58(rdram, ctx);
        goto after_16;
    // 0x808003E0: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    after_16:
L_808003E4:
    // 0x808003E4: lui         $a1, 0x3EE8
    ctx->r5 = S32(0X3EE8 << 16);
    // 0x808003E8: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x808003EC: jal         0x8008B348
    // 0x808003F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_17;
    // 0x808003F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x808003F4: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x808003F8: lui         $a2, 0x3FB9
        ctx->r6 = S32(0X3FB9 << 16);
            goto L_8080040C;
    }
    // 0x808003F8: lui         $a2, 0x3FB9
    ctx->r6 = S32(0X3FB9 << 16);
    // 0x808003FC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x8009DF58
    // 0x80800408: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    func_8009DF58(rdram, ctx);
        goto after_18;
    // 0x80800408: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    after_18:
L_8080040C:
    // 0x8080040C: lui         $a1, 0x3EFA
    ctx->r5 = S32(0X3EFA << 16);
    // 0x80800410: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800414: jal         0x8008B348
    // 0x80800418: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_19;
    // 0x80800418: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x8080041C: beq         $v0, $zero, L_80800434
    if (ctx->r2 == 0) {
        // 0x80800420: lui         $a2, 0x3FB3
        ctx->r6 = S32(0X3FB3 << 16);
            goto L_80800434;
    }
    // 0x80800420: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800424: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: jal         0x8009DF58
    // 0x80800430: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    func_8009DF58(rdram, ctx);
        goto after_20;
    // 0x80800430: addiu       $a1, $zero, 0x43EF
    ctx->r5 = ADD32(0, 0X43EF);
    after_20:
L_80800434:
    // 0x80800434: lui         $a1, 0x3F0A
    ctx->r5 = S32(0X3F0A << 16);
    // 0x80800438: ori         $a1, $a1, 0x29C7
    ctx->r5 = ctx->r5 | 0X29C7;
    // 0x8080043C: jal         0x8008B348
    // 0x80800440: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_21;
    // 0x80800440: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x80800444: beql        $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x80800448: lui         $a1, 0x3F29
        ctx->r5 = S32(0X3F29 << 16);
            goto L_80800458;
    }
    goto skip_2;
    // 0x80800448: lui         $a1, 0x3F29
    ctx->r5 = S32(0X3F29 << 16);
    skip_2:
    // 0x8080044C: jal         0x800909EC
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909EC(rdram, ctx);
        goto after_22;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800454: lui         $a1, 0x3F29
    ctx->r5 = S32(0X3F29 << 16);
L_80800458:
    // 0x80800458: ori         $a1, $a1, 0x7247
    ctx->r5 = ctx->r5 | 0X7247;
    // 0x8080045C: jal         0x8008B348
    // 0x80800460: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_23;
    // 0x80800460: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_23:
    // 0x80800464: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x80800468: lui         $a2, 0x3FE6
        ctx->r6 = S32(0X3FE6 << 16);
            goto L_80800498;
    }
    // 0x80800468: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x8080046C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x80800478: jal         0x8009DF94
    // 0x8080047C: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_24;
    // 0x8080047C: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_24:
    // 0x80800480: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800484: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80800490: jal         0x80085490
    // 0x80800494: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x80800494: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_25:
L_80800498:
    // 0x80800498: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x8080049C: ori         $a1, $a1, 0x367A
    ctx->r5 = ctx->r5 | 0X367A;
    // 0x808004A0: jal         0x8008B348
    // 0x808004A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_26;
    // 0x808004A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_26:
    // 0x808004A8: beql        $v0, $zero, L_808004BC
    if (ctx->r2 == 0) {
        // 0x808004AC: lui         $a1, 0x3F32
        ctx->r5 = S32(0X3F32 << 16);
            goto L_808004BC;
    }
    goto skip_3;
    // 0x808004AC: lui         $a1, 0x3F32
    ctx->r5 = S32(0X3F32 << 16);
    skip_3:
    // 0x808004B0: jal         0x8009514C
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_27;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808004B8: lui         $a1, 0x3F32
    ctx->r5 = S32(0X3F32 << 16);
L_808004BC:
    // 0x808004BC: ori         $a1, $a1, 0x4745
    ctx->r5 = ctx->r5 | 0X4745;
    // 0x808004C0: jal         0x8008B348
    // 0x808004C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_28;
    // 0x808004C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_28:
    // 0x808004C8: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004CC: lui         $a2, 0x3FE6
        ctx->r6 = S32(0X3FE6 << 16);
            goto L_808004FC;
    }
    // 0x808004CC: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808004D0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D8: addiu       $a1, $zero, 0x418
    ctx->r5 = ADD32(0, 0X418);
    // 0x808004DC: jal         0x8009DF94
    // 0x808004E0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DF94(rdram, ctx);
        goto after_29;
    // 0x808004E0: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_29:
    // 0x808004E4: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808004E8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x808004F4: jal         0x80085490
    // 0x808004F8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_30;
    // 0x808004F8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_30:
L_808004FC:
    // 0x808004FC: lui         $a1, 0x3F46
    ctx->r5 = S32(0X3F46 << 16);
    // 0x80800500: ori         $a1, $a1, 0x52BD
    ctx->r5 = ctx->r5 | 0X52BD;
    // 0x80800504: jal         0x8008B348
    // 0x80800508: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_31;
    // 0x80800508: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_31:
    // 0x8080050C: beql        $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x80800510: lui         $a1, 0x3F48
        ctx->r5 = S32(0X3F48 << 16);
            goto L_80800520;
    }
    goto skip_4;
    // 0x80800510: lui         $a1, 0x3F48
    ctx->r5 = S32(0X3F48 << 16);
    skip_4:
    // 0x80800514: jal         0x800951B4
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_32;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x8080051C: lui         $a1, 0x3F48
    ctx->r5 = S32(0X3F48 << 16);
L_80800520:
    // 0x80800520: ori         $a1, $a1, 0x3E42
    ctx->r5 = ctx->r5 | 0X3E42;
    // 0x80800524: jal         0x8008B348
    // 0x80800528: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_33;
    // 0x80800528: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_33:
    // 0x8080052C: beq         $v0, $zero, L_80800544
    if (ctx->r2 == 0) {
        // 0x80800530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800544;
    }
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: addiu       $a1, $zero, 0x449
    ctx->r5 = ADD32(0, 0X449);
    // 0x80800538: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080053C: jal         0x8009DF94
    // 0x80800540: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF94(rdram, ctx);
        goto after_34;
    // 0x80800540: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_34:
L_80800544:
    // 0x80800544: lui         $a1, 0x3F55
    ctx->r5 = S32(0X3F55 << 16);
    // 0x80800548: ori         $a1, $a1, 0xB0F
    ctx->r5 = ctx->r5 | 0XB0F;
    // 0x8080054C: jal         0x8008B348
    // 0x80800550: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_35;
    // 0x80800550: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_35:
    // 0x80800554: beq         $v0, $zero, L_8080056C
    if (ctx->r2 == 0) {
        // 0x80800558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080056C;
    }
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: addiu       $a1, $zero, 0x449
    ctx->r5 = ADD32(0, 0X449);
    // 0x80800560: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800564: jal         0x8009DF94
    // 0x80800568: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF94(rdram, ctx);
        goto after_36;
    // 0x80800568: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_36:
L_8080056C:
    // 0x8080056C: lui         $a1, 0x3F5D
    ctx->r5 = S32(0X3F5D << 16);
    // 0x80800570: ori         $a1, $a1, 0xED29
    ctx->r5 = ctx->r5 | 0XED29;
    // 0x80800574: jal         0x8008B348
    // 0x80800578: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_37;
    // 0x80800578: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_37:
    // 0x8080057C: beq         $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x80800580: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800594;
    }
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: addiu       $a1, $zero, 0x449
    ctx->r5 = ADD32(0, 0X449);
    // 0x80800588: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080058C: jal         0x8009DF94
    // 0x80800590: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF94(rdram, ctx);
        goto after_38;
    // 0x80800590: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_38:
L_80800594:
    // 0x80800594: lui         $a1, 0x3F67
    ctx->r5 = S32(0X3F67 << 16);
    // 0x80800598: ori         $a1, $a1, 0xA0F9
    ctx->r5 = ctx->r5 | 0XA0F9;
    // 0x8080059C: jal         0x8008B348
    // 0x808005A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_39;
    // 0x808005A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_39:
    // 0x808005A4: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x808005A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: addiu       $a1, $zero, 0x449
    ctx->r5 = ADD32(0, 0X449);
    // 0x808005B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005B4: jal         0x8009DF94
    // 0x808005B8: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF94(rdram, ctx);
        goto after_40;
    // 0x808005B8: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_40:
L_808005BC:
    // 0x808005BC: lui         $a1, 0x3F77
    ctx->r5 = S32(0X3F77 << 16);
    // 0x808005C0: ori         $a1, $a1, 0x3B0
    ctx->r5 = ctx->r5 | 0X3B0;
    // 0x808005C4: jal         0x8008B348
    // 0x808005C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_41;
    // 0x808005C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_41:
    // 0x808005CC: beql        $v0, $zero, L_808005E0
    if (ctx->r2 == 0) {
        // 0x808005D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005E0;
    }
    goto skip_5;
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808005D4: jal         0x800909EC
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909EC(rdram, ctx);
        goto after_42;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x808005DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005E0:
    // 0x808005E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void func_8001253C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001253C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012540: jr          $ra
    // 0x80012544: sw          $a0, 0x59CC($at)
    MEM_W(0X59CC, ctx->r1) = ctx->r4;
    return;
    // 0x80012544: sw          $a0, 0x59CC($at)
    MEM_W(0X59CC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _bsbkflamethrower_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829B0: syscall     23
    recomp_syscall_handler(rdram, ctx, 0x800829B0);
    return;
    // 0x800829B4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8008E0E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E0E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E0EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E0F0: jal         0x8008E23C
    // 0x8008E0F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E23C(rdram, ctx);
        goto after_0;
    // 0x8008E0F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E0F8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008E0FC: beq         $t6, $zero, L_8008E114
    if (ctx->r14 == 0) {
        // 0x8008E100: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008E114;
    }
    // 0x8008E100: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008E104: jal         0x8008E0C8
    // 0x8008E108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E0C8(rdram, ctx);
        goto after_1;
    // 0x8008E108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008E10C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008E110: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008E114:
    // 0x8008E114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E11C: jr          $ra
    // 0x8008E120: nop

    return;
    // 0x8008E120: nop

;}
RECOMP_FUNC void bastatetimer_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009178C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091790: jal         0x800917A8
    // 0x80091794: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    bastatetimer_set(rdram, ctx);
        goto after_0;
    // 0x80091794: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x80091798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009179C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800917A0: jr          $ra
    // 0x800917A4: nop

    return;
    // 0x800917A4: nop

;}
RECOMP_FUNC void suexpression_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B3C: jr          $ra
    // 0x80800B40: sb          $a1, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r5;
    return;
    // 0x80800B40: sb          $a1, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bamoveledge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: jr          $ra
    // 0x80800014: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800014: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800A8278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8278: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A827C: addiu       $v0, $v0, -0x5C0C
    ctx->r2 = ADD32(ctx->r2, -0X5C0C);
    // 0x800A8280: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800A8284: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800A8288: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A828C: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x800A8290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8294: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800A8298: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800A829C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A82A0: jal         0x80015E80
    // 0x800A82A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015E80(rdram, ctx);
        goto after_0;
    // 0x800A82A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800A82A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A82AC: jal         0x80015F28
    // 0x800A82B0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80015F28(rdram, ctx);
        goto after_1;
    // 0x800A82B0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x800A82B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A82B8: jal         0x80015FFC
    // 0x800A82BC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80015FFC(rdram, ctx);
        goto after_2;
    // 0x800A82BC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x800A82C0: jal         0x80015F84
    // 0x800A82C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015F84(rdram, ctx);
        goto after_3;
    // 0x800A82C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800A82C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A82CC: addiu       $a2, $a2, -0x5BE8
    ctx->r6 = ADD32(ctx->r6, -0X5BE8);
    // 0x800A82D0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800A82D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A82D8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800A82DC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A82E0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800A82E4: lw          $a0, -0x5C08($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5C08);
    // 0x800A82E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A82EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A82F0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800A82F4: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x800A82F8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A82FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A8300: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8304: bne         $a1, $t1, L_800A8310
    if (ctx->r5 != ctx->r9) {
        // 0x800A8308: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_800A8310;
    }
    // 0x800A8308: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800A830C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
L_800A8310:
    // 0x800A8310: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_800A8314:
    // 0x800A8314: beq         $v0, $a0, L_800A8340
    if (ctx->r2 == ctx->r4) {
        // 0x800A8318: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_800A8340;
    }
    // 0x800A8318: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800A831C: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800A8320: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A8324: bne         $a1, $t5, L_800A8340
    if (ctx->r5 != ctx->r13) {
        // 0x800A8328: sll         $t7, $zero, 2
        ctx->r15 = S32(0 << 2);
            goto L_800A8340;
    }
    // 0x800A8328: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x800A832C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8330: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800A8334: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800A8338: b           L_800A8360
    // 0x800A833C: lw          $v0, -0x5C08($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C08);
        goto L_800A8360;
    // 0x800A833C: lw          $v0, -0x5C08($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C08);
L_800A8340:
    // 0x800A8340: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A8344: bne         $v0, $v1, L_800A8314
    if (ctx->r2 != ctx->r3) {
        // 0x800A8348: nop
    
            goto L_800A8314;
    }
    // 0x800A8348: nop

    // 0x800A834C: lw          $t8, -0x5BE8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5BE8);
    // 0x800A8350: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8354: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A8358: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800A835C: lw          $v0, -0x5C08($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C08);
L_800A8360:
    // 0x800A8360: bne         $v0, $at, L_800A836C
    if (ctx->r2 != ctx->r1) {
        // 0x800A8364: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800A836C;
    }
    // 0x800A8364: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8368: sw          $a1, -0x5C10($at)
    MEM_W(-0X5C10, ctx->r1) = ctx->r5;
L_800A836C:
    // 0x800A836C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A8374: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800A8378: jr          $ra
    // 0x800A837C: nop

    return;
    // 0x800A837C: nop

;}
RECOMP_FUNC void func_8001B864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B864: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B868: jr          $ra
    // 0x8001B86C: sw          $a0, -0x390C($at)
    MEM_W(-0X390C, ctx->r1) = ctx->r4;
    return;
    // 0x8001B86C: sw          $a0, -0x390C($at)
    MEM_W(-0X390C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8080000C_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80800830
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800830_chfactorylight(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x8010A800
    // 0x80800024: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_80800060_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: jal         0x8008FE14
    // 0x8080006C: nop

    func_8008FE14(rdram, ctx);
        goto after_0;
    // 0x8080006C: nop

    after_0:
    // 0x80800070: xori        $t6, $v0, 0x1D9
    ctx->r14 = ctx->r2 ^ 0X1D9;
    // 0x80800074: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800078: bnel        $v0, $zero, L_808000A0
    if (ctx->r2 != 0) {
        // 0x8080007C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800080: jal         0x800F54E4
    // 0x80800084: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800084: nop

    after_1:
    // 0x80800088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080008C: jal         0x800F640C
    // 0x80800090: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    func_800F640C(rdram, ctx);
        goto after_2;
    // 0x80800090: addiu       $a1, $zero, 0x1D9
    ctx->r5 = ADD32(0, 0X1D9);
    after_2:
    // 0x80800094: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800098: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A0:
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_80027AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027AF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80027AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027AF8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80027AFC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80027B00: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80027B04: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80027B08: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80027B0C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80027B10: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80027B14: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80027B18: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80027B1C: sra         $t0, $t9, 3
    ctx->r8 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80027B20: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80027B24: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80027B28: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80027B2C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80027B30: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80027B34: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80027B38: lbu         $t5, 0x8($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X8);
    // 0x80027B3C: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80027B40: bne         $at, $zero, L_80027B50
    if (ctx->r1 != 0) {
        // 0x80027B44: nop
    
            goto L_80027B50;
    }
    // 0x80027B44: nop

    // 0x80027B48: b           L_80028000
    // 0x80027B4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80028000;
    // 0x80027B4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027B50:
    // 0x80027B50: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80027B54: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80027B58: beq         $at, $zero, L_80027DB0
    if (ctx->r1 == 0) {
        // 0x80027B5C: nop
    
            goto L_80027DB0;
    }
    // 0x80027B5C: nop

    // 0x80027B60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80027B64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027B68: addu        $at, $at, $t6
    gpr jr_addend_80027B70 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80027B6C: lw          $t6, 0x1CE4($at)
    ctx->r14 = ADD32(ctx->r1, 0X1CE4);
    // 0x80027B70: jr          $t6
    // 0x80027B74: nop

    switch (jr_addend_80027B70 >> 2) {
        case 0: goto L_80027B78; break;
        case 1: goto L_80027BD4; break;
        case 2: goto L_80027C30; break;
        case 3: goto L_80027C5C; break;
        case 4: goto L_80027C88; break;
        case 5: goto L_80027CB4; break;
        case 6: goto L_80027D18; break;
        case 7: goto L_80027D34; break;
        default: switch_error(__func__, 0x80027B70, 0x80041CE4);
    }
    // 0x80027B74: nop

L_80027B78:
    // 0x80027B78: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80027B7C: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x80027B80: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80027B84: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80027B88: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x80027B8C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80027B90: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80027B94: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80027B98: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80027B9C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80027BA0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80027BA4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80027BA8: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x80027BAC: mflo        $t0
    ctx->r8 = lo;
    // 0x80027BB0: nop

    // 0x80027BB4: nop

    // 0x80027BB8: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80027BBC: mflo        $t1
    ctx->r9 = lo;
    // 0x80027BC0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80027BC4: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x80027BC8: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80027BCC: b           L_80027DB0
    // 0x80027BD0: nop

        goto L_80027DB0;
    // 0x80027BD0: nop

L_80027BD4:
    // 0x80027BD4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80027BD8: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80027BDC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80027BE0: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80027BE4: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x80027BE8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80027BEC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80027BF0: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80027BF4: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x80027BF8: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x80027BFC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x80027C00: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80027C04: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80027C08: mflo        $t1
    ctx->r9 = lo;
    // 0x80027C0C: nop

    // 0x80027C10: nop

    // 0x80027C14: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80027C18: mflo        $t4
    ctx->r12 = lo;
    // 0x80027C1C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80027C20: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80027C24: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x80027C28: b           L_80027DB0
    // 0x80027C2C: nop

        goto L_80027DB0;
    // 0x80027C2C: nop

L_80027C30:
    // 0x80027C30: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80027C34: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80027C38: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80027C3C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80027C40: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80027C44: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x80027C48: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80027C4C: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x80027C50: sh          $t7, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r15;
    // 0x80027C54: b           L_80027DB0
    // 0x80027C58: nop

        goto L_80027DB0;
    // 0x80027C58: nop

L_80027C5C:
    // 0x80027C5C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80027C60: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80027C64: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80027C68: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x80027C6C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80027C70: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80027C74: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80027C78: addu        $t4, $t5, $t0
    ctx->r12 = ADD32(ctx->r13, ctx->r8);
    // 0x80027C7C: sh          $t6, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r14;
    // 0x80027C80: b           L_80027DB0
    // 0x80027C84: nop

        goto L_80027DB0;
    // 0x80027C84: nop

L_80027C88:
    // 0x80027C88: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80027C8C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80027C90: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80027C94: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x80027C98: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x80027C9C: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x80027CA0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80027CA4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80027CA8: sh          $t1, 0xC($t9)
    MEM_H(0XC, ctx->r25) = ctx->r9;
    // 0x80027CAC: b           L_80027DB0
    // 0x80027CB0: nop

        goto L_80027DB0;
    // 0x80027CB0: nop

L_80027CB4:
    // 0x80027CB4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80027CB8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80027CBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027CC0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80027CC4: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80027CC8: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x80027CCC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80027CD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80027CD4: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x80027CD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027CDC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80027CE0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80027CE4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80027CE8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80027CEC: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x80027CF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80027CF4: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80027CF8: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80027CFC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80027D00: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80027D04: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80027D08: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80027D0C: swc1        $f8, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f8.u32l;
    // 0x80027D10: b           L_80027DB0
    // 0x80027D14: nop

        goto L_80027DB0;
    // 0x80027D14: nop

L_80027D18:
    // 0x80027D18: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80027D1C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80027D20: nop

    // 0x80027D24: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80027D28: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x80027D2C: b           L_80027DB0
    // 0x80027D30: nop

        goto L_80027DB0;
    // 0x80027D30: nop

L_80027D34:
    // 0x80027D34: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80027D38: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80027D3C: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80027D40: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80027D44: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80027D48: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80027D4C: addu        $t4, $t5, $t6
    ctx->r12 = ADD32(ctx->r13, ctx->r14);
    // 0x80027D50: lw          $t2, 0x20($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X20);
    // 0x80027D54: beq         $t2, $zero, L_80027DA8
    if (ctx->r10 == 0) {
        // 0x80027D58: nop
    
            goto L_80027DA8;
    }
    // 0x80027D58: nop

    // 0x80027D5C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80027D60: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80027D64: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80027D68: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80027D6C: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x80027D70: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80027D74: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80027D78: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80027D7C: lw          $t5, 0x20($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X20);
    // 0x80027D80: sh          $t3, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r11;
    // 0x80027D84: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80027D88: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80027D8C: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x80027D90: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80027D94: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80027D98: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80027D9C: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x80027DA0: jal         0x80028A24
    // 0x80027DA4: lw          $a0, 0x20($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X20);
    func_80028A24(rdram, ctx);
        goto after_0;
    // 0x80027DA4: lw          $a0, 0x20($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X20);
    after_0:
L_80027DA8:
    // 0x80027DA8: b           L_80027DB0
    // 0x80027DAC: nop

        goto L_80027DB0;
    // 0x80027DAC: nop

L_80027DB0:
    // 0x80027DB0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80027DB4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80027DB8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80027DBC: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80027DC0: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80027DC4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80027DC8: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x80027DCC: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x80027DD0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80027DD4: addiu       $t4, $t2, -0x10
    ctx->r12 = ADD32(ctx->r10, -0X10);
    // 0x80027DD8: sltu        $at, $t6, $t4
    ctx->r1 = ctx->r14 < ctx->r12 ? 1 : 0;
    // 0x80027DDC: bne         $at, $zero, L_80027E0C
    if (ctx->r1 != 0) {
        // 0x80027DE0: nop
    
            goto L_80027E0C;
    }
    // 0x80027DE0: nop

    // 0x80027DE4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80027DE8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80027DEC: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x80027DF0: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80027DF4: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80027DF8: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80027DFC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80027E00: addiu       $t0, $t1, -0x10
    ctx->r8 = ADD32(ctx->r9, -0X10);
    // 0x80027E04: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80027E08: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_80027E0C:
    // 0x80027E0C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80027E10: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80027E14: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x80027E18: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x80027E1C: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x80027E20: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80027E24: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80027E28: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80027E2C: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x80027E30: addiu       $t5, $t9, -0x8
    ctx->r13 = ADD32(ctx->r25, -0X8);
    // 0x80027E34: sltu        $at, $t3, $t5
    ctx->r1 = ctx->r11 < ctx->r13 ? 1 : 0;
    // 0x80027E38: bne         $at, $zero, L_80027E68
    if (ctx->r1 != 0) {
        // 0x80027E3C: nop
    
            goto L_80027E68;
    }
    // 0x80027E3C: nop

    // 0x80027E40: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80027E44: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80027E48: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80027E4C: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80027E50: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80027E54: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80027E58: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80027E5C: addiu       $t4, $t8, -0x8
    ctx->r12 = ADD32(ctx->r24, -0X8);
    // 0x80027E60: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80027E64: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_80027E68:
    // 0x80027E68: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80027E6C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80027E70: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x80027E74: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80027E78: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x80027E7C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80027E80: addu        $t0, $t3, $t8
    ctx->r8 = ADD32(ctx->r11, ctx->r24);
    // 0x80027E84: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80027E88: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80027E8C: sltu        $at, $t1, $t6
    ctx->r1 = ctx->r9 < ctx->r14 ? 1 : 0;
    // 0x80027E90: bne         $at, $zero, L_80027EC0
    if (ctx->r1 != 0) {
        // 0x80027E94: nop
    
            goto L_80027EC0;
    }
    // 0x80027E94: nop

    // 0x80027E98: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80027E9C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80027EA0: lw          $t4, 0x4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X4);
    // 0x80027EA4: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80027EA8: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80027EAC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80027EB0: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x80027EB4: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x80027EB8: addiu       $t8, $t3, 0x8
    ctx->r24 = ADD32(ctx->r11, 0X8);
    // 0x80027EBC: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
L_80027EC0:
    // 0x80027EC0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80027EC4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80027EC8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80027ECC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80027ED0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80027ED4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80027ED8: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80027EDC: lw          $t4, 0x24($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X24);
    // 0x80027EE0: beq         $t4, $zero, L_80027FF0
    if (ctx->r12 == 0) {
        // 0x80027EE4: nop
    
            goto L_80027FF0;
    }
    // 0x80027EE4: nop

    // 0x80027EE8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80027EEC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80027EF0: beq         $t9, $at, L_80027F94
    if (ctx->r25 == ctx->r1) {
        // 0x80027EF4: nop
    
            goto L_80027F94;
    }
    // 0x80027EF4: nop

    // 0x80027EF8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80027EFC: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80027F00: lw          $t8, 0x4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X4);
    // 0x80027F04: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80027F08: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x80027F0C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80027F10: addu        $t6, $t8, $t0
    ctx->r14 = ADD32(ctx->r24, ctx->r8);
    // 0x80027F14: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x80027F18: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80027F1C: subu        $t2, $t1, $t7
    ctx->r10 = SUB32(ctx->r9, ctx->r15);
    // 0x80027F20: beq         $t2, $zero, L_80027F88
    if (ctx->r10 == 0) {
        // 0x80027F24: nop
    
            goto L_80027F88;
    }
    // 0x80027F24: nop

    // 0x80027F28: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80027F2C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80027F30: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80027F34: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80027F38: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80027F3C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80027F40: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80027F44: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80027F48: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80027F4C: subu        $t1, $t0, $t6
    ctx->r9 = SUB32(ctx->r8, ctx->r14);
    // 0x80027F50: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80027F54: bgez        $t1, L_80027F6C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80027F58: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80027F6C;
    }
    // 0x80027F58: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80027F5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80027F60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80027F64: nop

    // 0x80027F68: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80027F6C:
    // 0x80027F6C: lwc1        $f8, 0x1C($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80027F70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027F74: lwc1        $f16, 0x1D04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1D04);
    // 0x80027F78: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80027F7C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80027F80: b           L_80027F94
    // 0x80027F84: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
        goto L_80027F94;
    // 0x80027F84: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
L_80027F88:
    // 0x80027F88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80027F8C: nop

    // 0x80027F90: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_80027F94:
    // 0x80027F94: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80027F98: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80027F9C: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x80027FA0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80027FA4: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x80027FA8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80027FAC: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x80027FB0: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x80027FB4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80027FB8: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x80027FBC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80027FC0: bgez        $t6, L_80027FD8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80027FC4: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80027FD8;
    }
    // 0x80027FC4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027FC8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80027FCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80027FD0: nop

    // 0x80027FD4: add.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f10.fl;
L_80027FD8:
    // 0x80027FD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027FDC: lwc1        $f4, 0x1D08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1D08);
    // 0x80027FE0: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80027FE4: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80027FE8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80027FEC: swc1        $f8, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f8.u32l;
L_80027FF0:
    // 0x80027FF0: b           L_80028000
    // 0x80027FF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80028000;
    // 0x80027FF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027FF8: b           L_80028000
    // 0x80027FFC: nop

        goto L_80028000;
    // 0x80027FFC: nop

L_80028000:
    // 0x80028000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028004: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80028008: jr          $ra
    // 0x8002800C: nop

    return;
    // 0x8002800C: nop

;}
RECOMP_FUNC void func_800A989C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A989C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A98A0: lw          $v0, 0x7754($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7754);
    // 0x800A98A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A98A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A98AC: beq         $v0, $zero, L_800A98BC
    if (ctx->r2 == 0) {
        // 0x800A98B0: nop
    
            goto L_800A98BC;
    }
    // 0x800A98B0: nop

    // 0x800A98B4: b           L_800A98C8
    // 0x800A98B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800A98C8;
    // 0x800A98B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800A98BC:
    // 0x800A98BC: jal         0x80014F00
    // 0x800A98C0: nop

    func_80014F00(rdram, ctx);
        goto after_0;
    // 0x800A98C0: nop

    after_0:
    // 0x800A98C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800A98C8:
    // 0x800A98C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A98CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A98D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800A98D4: jr          $ra
    // 0x800A98D8: nop

    return;
    // 0x800A98D8: nop

    // 0x800A98DC: nop

;}
RECOMP_FUNC void func_80029D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D54: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80029D58: lbu         $t6, 0x3A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3A);
    // 0x80029D5C: lbu         $t7, 0x37($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X37);
    // 0x80029D60: lbu         $t9, 0x34($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X34);
    // 0x80029D64: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029D68: mflo        $t8
    ctx->r24 = lo;
    // 0x80029D6C: nop

    // 0x80029D70: nop

    // 0x80029D74: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029D78: mflo        $t0
    ctx->r8 = lo;
    // 0x80029D7C: sra         $t1, $t0, 6
    ctx->r9 = S32(SIGNED(ctx->r8) >> 6);
    // 0x80029D80: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80029D84: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x80029D88: lh          $t9, 0x34($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X34);
    // 0x80029D8C: lbu         $t3, 0x35($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X35);
    // 0x80029D90: lbu         $t8, 0xD5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XD5);
    // 0x80029D94: lw          $t2, 0x60($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X60);
    // 0x80029D98: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80029D9C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029DA0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80029DA4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80029DA8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80029DAC: lbu         $t6, 0x5($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X5);
    // 0x80029DB0: mflo        $t0
    ctx->r8 = lo;
    // 0x80029DB4: nop

    // 0x80029DB8: nop

    // 0x80029DBC: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029DC0: mflo        $t1
    ctx->r9 = lo;
    // 0x80029DC4: sra         $t3, $t1, 14
    ctx->r11 = S32(SIGNED(ctx->r9) >> 14);
    // 0x80029DC8: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x80029DCC: lbu         $t4, 0x35($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X35);
    // 0x80029DD0: lw          $t2, 0x60($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X60);
    // 0x80029DD4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80029DD8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80029DDC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80029DE0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80029DE4: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x80029DE8: lbu         $t8, 0x9($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X9);
    // 0x80029DEC: beq         $t8, $at, L_80029E28
    if (ctx->r24 == ctx->r1) {
        // 0x80029DF0: nop
    
            goto L_80029E28;
    }
    // 0x80029DF0: nop

    // 0x80029DF4: lbu         $t6, 0x35($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X35);
    // 0x80029DF8: lw          $t9, 0x60($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X60);
    // 0x80029DFC: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80029E00: sll         $t0, $t6, 3
    ctx->r8 = S32(ctx->r14 << 3);
    // 0x80029E04: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80029E08: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80029E0C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80029E10: lbu         $t3, 0x9($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X9);
    // 0x80029E14: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029E18: mflo        $t2
    ctx->r10 = lo;
    // 0x80029E1C: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x80029E20: srl         $t7, $t5, 8
    ctx->r15 = S32(U32(ctx->r13) >> 8);
    // 0x80029E24: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
L_80029E28:
    // 0x80029E28: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80029E2C: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80029E30: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029E34: mflo        $t9
    ctx->r25 = lo;
    // 0x80029E38: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80029E3C: nop

    // 0x80029E40: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80029E44: srl         $t1, $t0, 15
    ctx->r9 = S32(U32(ctx->r8) >> 15);
    // 0x80029E48: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80029E4C: b           L_80029E5C
    // 0x80029E50: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
        goto L_80029E5C;
    // 0x80029E50: lh          $v0, 0x6($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X6);
    // 0x80029E54: b           L_80029E5C
    // 0x80029E58: nop

        goto L_80029E5C;
    // 0x80029E58: nop

L_80029E5C:
    // 0x80029E5C: jr          $ra
    // 0x80029E60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80029E60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80800000_chfloorbubbles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x80100094
    // 0x80800014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800018: jal         0x800DC0C0
    // 0x8080001C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x8080001C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1716, 0X260) << 16);
    // 0x80800024: lwc1        $f4, 0x260($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1716, 0X260));
    // 0x80800028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080002C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800030: nop

    // 0x80800034: bc1fl       L_808000FC
    if (!c1cs) {
        // 0x80800038: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000FC;
    }
    goto skip_0;
    // 0x80800038: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080003C: jal         0x800DC128
    // 0x80800040: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800040: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800044: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800048: jal         0x800B53A4
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800050: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800054: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800058: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080005C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1716, 0X270) << 16);
    // 0x80800060: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800064: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800068: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8080006C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800070: addiu       $t0, $t0, 0x270
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1716, 0X270));
    // 0x80800074: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080007C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800080: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800084: jal         0x800BABB8
    // 0x80800088: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800088: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_4:
    // 0x8080008C: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800090: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800094: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800098: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080009C: nop

    // 0x808000A0: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x808000A4: jal         0x800BA568
    // 0x808000A8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_800BA568(rdram, ctx);
        goto after_5;
    // 0x808000A8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_5:
    // 0x808000AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000B0: jal         0x800BA22C
    // 0x808000B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x808000B4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x808000B8: jal         0x800DC0C0
    // 0x808000BC: nop

    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x808000BC: nop

    after_7:
    // 0x808000C0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808000C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000CC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808000D0: nop

    // 0x808000D4: bc1fl       L_808000FC
    if (!c1cs) {
        // 0x808000D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000FC;
    }
    goto skip_1;
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808000DC: jal         0x800DC128
    // 0x808000E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x808000E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_8:
    // 0x808000E4: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x808000E8: andi        $t5, $v0, 0x1FF
    ctx->r13 = ctx->r2 & 0X1FF;
    // 0x808000EC: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x808000F0: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x808000F4: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x808000F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000FC:
    // 0x808000FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000C0: jal         0x800136E4
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: swc1        $f0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f0.u32l;
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void baattach_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80800070: jr          $ra
    // 0x80800074: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    return;
    // 0x80800074: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
;}
RECOMP_FUNC void func_80800000_chbosskogsdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080000C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800010: jal         0x800DA298
    // 0x80800014: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_8080006C
    if (ctx->r2 == 0) {
        // 0x8080001C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080006C;
    }
    // 0x8080001C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: lhu         $t6, 0x76($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X76);
    // 0x80800024: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800028: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080002C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800030: bgez        $t7, L_80800044
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800034: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800044;
    }
    // 0x80800034: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080003C: nop

    // 0x80800040: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800044:
    // 0x80800044: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800048: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080004C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800050: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800054: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800058: swc1        $f16, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f16.u32l;
    // 0x8080005C: jal         0x80101FDC
    // 0x80800060: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800060: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800064: b           L_80800078
    // 0x80800068: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
        goto L_80800078;
    // 0x80800068: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8080006C:
    // 0x8080006C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800070: nop

    // 0x80800074: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
L_80800078:
    // 0x80800078: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8080007C: swc1        $f4, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f4.u32l;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_80800000_chcanarymarycage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800004: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080000C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800010: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800014: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800018: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8080001C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800020: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800024: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800028: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080002C: jal         0x80101FDC
    // 0x80800030: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800030: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80800034: lhu         $v0, 0x72($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X72);
    // 0x80800038: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080003C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800040: beq         $t6, $at, L_8080015C
    if (ctx->r14 == ctx->r1) {
        // 0x80800044: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080015C;
    }
    // 0x80800044: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800048: beq         $t6, $at, L_80800064
    if (ctx->r14 == ctx->r1) {
        // 0x8080004C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800064;
    }
    // 0x8080004C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800050: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800054: beq         $t6, $at, L_8080014C
    if (ctx->r14 == ctx->r1) {
        // 0x80800058: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080014C;
    }
    // 0x80800058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080005C: b           L_80800160
    // 0x80800060: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80800160;
    // 0x80800060: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800064:
    // 0x80800064: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800068: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080006C: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x80800070: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(1572, 0X61C) << 16);
    // 0x80800074: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(1572, 0X610) << 16);
    // 0x80800078: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080007C: addiu       $s5, $s5, 0x610
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(1572, 0X610));
    // 0x80800080: addiu       $s6, $s6, 0x61C
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1572, 0X61C));
    // 0x80800084: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80800088: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
L_8080008C:
    // 0x8080008C: jal         0x800F6438
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800094: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x800F5A00
    // 0x808000A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808000A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x808000A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808000A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000AC: jal         0x800EFFB4
    // 0x808000B0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_3;
    // 0x808000B0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x808000B4: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x808000C0: jal         0x800F497C
    // 0x808000C4: addiu       $s1, $s1, -0x2A24
    ctx->r17 = ADD32(ctx->r17, -0X2A24);
    func_800F497C(rdram, ctx);
        goto after_4;
    // 0x808000C4: addiu       $s1, $s1, -0x2A24
    ctx->r17 = ADD32(ctx->r17, -0X2A24);
    after_4:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x800F49A8
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_5;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x800F4A00
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F4A00(rdram, ctx);
        goto after_6;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808000E8: jal         0x800F49D4
    // 0x808000EC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_7;
    // 0x808000EC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    after_7:
    // 0x808000F0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x800F4AC0
    // 0x808000FC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800F4AC0(rdram, ctx);
        goto after_8;
    // 0x808000FC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_8:
    // 0x80800100: lbu         $v0, 0x79($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X79);
    // 0x80800104: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x80800108: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8080010C: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x80800110: andi        $t1, $v0, 0xFF0F
    ctx->r9 = ctx->r2 & 0XFF0F;
    // 0x80800114: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800118: sb          $t2, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r10;
L_8080011C:
    // 0x8080011C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800120: bne         $s0, $s4, L_8080008C
    if (ctx->r16 != ctx->r20) {
        // 0x80800124: nop
    
            goto L_8080008C;
    }
    // 0x80800124: nop

    // 0x80800128: lbu         $t3, 0x79($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X79);
    // 0x8080012C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800130: srl         $t4, $t3, 4
    ctx->r12 = S32(U32(ctx->r11) >> 4);
    // 0x80800134: bnel        $t4, $zero, L_80800160
    if (ctx->r12 != 0) {
        // 0x80800138: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800160;
    }
    goto skip_0;
    // 0x80800138: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8080013C: jal         0x80800000
    // 0x80800140: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800000_chcanarymarycage(rdram, ctx);
        goto after_9;
    // 0x80800140: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800144: b           L_80800160
    // 0x80800148: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80800160;
    // 0x80800148: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8080014C:
    // 0x8080014C: jal         0x800DA3B8
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_10;
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800154: jal         0x8010A570
    // 0x80800158: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8010A570(rdram, ctx);
        goto after_11;
    // 0x80800158: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
L_8080015C:
    // 0x8080015C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800160:
    // 0x80800160: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800164: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800168: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080016C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800170: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800174: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800178: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8080017C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800180: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800184: jr          $ra
    // 0x80800188: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800188: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_808003F0_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F8: jal         0x8080055C
    // 0x808003FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808003FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800400: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800404: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800408: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080040C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800414: jal         0x8009FFD8
    // 0x80800418: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800418: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8080041C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800420: jal         0x8009B9B0
    // 0x80800424: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800424: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080042C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void chbouncycastle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1000, 0XA08) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0XA08));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0xA08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0XA08));
;}
RECOMP_FUNC void func_8010DAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DAE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010DAE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8010DAE8: addiu       $t7, $t7, 0x4740
    ctx->r15 = ADD32(ctx->r15, 0X4740);
    // 0x8010DAEC: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8010DAF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010DAF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010DAF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010DAFC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8010DB00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010DB04: lhu         $s1, 0x6($v0)
    ctx->r17 = MEM_HU(ctx->r2, 0X6);
    // 0x8010DB08: jal         0x8008AF24
    // 0x8010DB0C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8010DB0C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x8010DB10: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8010DB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DB18: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8010DB1C: srl         $t9, $a1, 18
    ctx->r25 = S32(U32(ctx->r5) >> 18);
    // 0x8010DB20: jal         0x8008AED4
    // 0x8010DB24: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8010DB24: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
    // 0x8010DB28: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8010DB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DB30: jal         0x8008B1BC
    // 0x8010DB34: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x8010DB34: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x8010DB38: andi        $t1, $s1, 0x1
    ctx->r9 = ctx->r17 & 0X1;
    // 0x8010DB3C: beq         $t1, $zero, L_8010DB68
    if (ctx->r9 == 0) {
        // 0x8010DB40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010DB68;
    }
    // 0x8010DB40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DB44: jal         0x8008B134
    // 0x8010DB48: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x8010DB48: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8010DB4C: andi        $t2, $s1, 0x100
    ctx->r10 = ctx->r17 & 0X100;
    // 0x8010DB50: beq         $t2, $zero, L_8010DB60
    if (ctx->r10 == 0) {
        // 0x8010DB54: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8010DB60;
    }
    // 0x8010DB54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8010DB58: b           L_8010DB60
    // 0x8010DB5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8010DB60;
    // 0x8010DB5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8010DB60:
    // 0x8010DB60: jal         0x8008B4A8
    // 0x8010DB64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B4A8(rdram, ctx);
        goto after_4;
    // 0x8010DB64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8010DB68:
    // 0x8010DB68: andi        $t3, $s1, 0x2
    ctx->r11 = ctx->r17 & 0X2;
    // 0x8010DB6C: beq         $t3, $zero, L_8010DB7C
    if (ctx->r11 == 0) {
        // 0x8010DB70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010DB7C;
    }
    // 0x8010DB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DB74: jal         0x8008B134
    // 0x8010DB78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x8010DB78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_8010DB7C:
    // 0x8010DB7C: andi        $t4, $s1, 0x4
    ctx->r12 = ctx->r17 & 0X4;
    // 0x8010DB80: beq         $t4, $zero, L_8010DB90
    if (ctx->r12 == 0) {
        // 0x8010DB84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010DB90;
    }
    // 0x8010DB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DB88: jal         0x8008B134
    // 0x8010DB8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x8010DB8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_8010DB90:
    // 0x8010DB90: andi        $t5, $s1, 0x8
    ctx->r13 = ctx->r17 & 0X8;
    // 0x8010DB94: beq         $t5, $zero, L_8010DBA4
    if (ctx->r13 == 0) {
        // 0x8010DB98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010DBA4;
    }
    // 0x8010DB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DB9C: jal         0x8008B188
    // 0x8010DBA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_7;
    // 0x8010DBA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_8010DBA4:
    // 0x8010DBA4: andi        $t6, $s1, 0x10
    ctx->r14 = ctx->r17 & 0X10;
    // 0x8010DBA8: beq         $t6, $zero, L_8010DBB8
    if (ctx->r14 == 0) {
        // 0x8010DBAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010DBB8;
    }
    // 0x8010DBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DBB0: jal         0x8008B188
    // 0x8010DBB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_8;
    // 0x8010DBB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_8010DBB8:
    // 0x8010DBB8: andi        $t7, $s1, 0x800
    ctx->r15 = ctx->r17 & 0X800;
    // 0x8010DBBC: beq         $t7, $zero, L_8010DBE8
    if (ctx->r15 == 0) {
        // 0x8010DBC0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8010DBE8;
    }
    // 0x8010DBC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010DBC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010DBC8: jal         0x800DC298
    // 0x8010DBCC: nop

    func_800DC298(rdram, ctx);
        goto after_9;
    // 0x8010DBCC: nop

    after_9:
    // 0x8010DBD0: beq         $v0, $zero, L_8010DBE0
    if (ctx->r2 == 0) {
        // 0x8010DBD4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8010DBE0;
    }
    // 0x8010DBD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010DBD8: b           L_8010DBE0
    // 0x8010DBDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010DBE0;
    // 0x8010DBDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010DBE0:
    // 0x8010DBE0: jal         0x8008B188
    // 0x8010DBE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B188(rdram, ctx);
        goto after_10;
    // 0x8010DBE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_8010DBE8:
    // 0x8010DBE8: andi        $t8, $s1, 0x40
    ctx->r24 = ctx->r17 & 0X40;
    // 0x8010DBEC: beq         $t8, $zero, L_8010DBFC
    if (ctx->r24 == 0) {
        // 0x8010DBF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010DBFC;
    }
    // 0x8010DBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DBF4: jal         0x8008B10C
    // 0x8010DBF8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8008B10C(rdram, ctx);
        goto after_11;
    // 0x8010DBF8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
L_8010DBFC:
    // 0x8010DBFC: andi        $t9, $s1, 0x80
    ctx->r25 = ctx->r17 & 0X80;
    // 0x8010DC00: beq         $t9, $zero, L_8010DC14
    if (ctx->r25 == 0) {
        // 0x8010DC04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010DC14;
    }
    // 0x8010DC04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010DC08: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8010DC0C: jal         0x8008B10C
    // 0x8010DC10: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_8008B10C(rdram, ctx);
        goto after_12;
    // 0x8010DC10: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_12:
L_8010DC14:
    // 0x8010DC14: andi        $t0, $s1, 0x400
    ctx->r8 = ctx->r17 & 0X400;
    // 0x8010DC18: beq         $t0, $zero, L_8010DC34
    if (ctx->r8 == 0) {
        // 0x8010DC1C: nop
    
            goto L_8010DC34;
    }
    // 0x8010DC1C: nop

    // 0x8010DC20: jal         0x800DC0C0
    // 0x8010DC24: nop

    func_800DC0C0(rdram, ctx);
        goto after_13;
    // 0x8010DC24: nop

    after_13:
    // 0x8010DC28: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8010DC2C: jal         0x8008B10C
    // 0x8010DC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B10C(rdram, ctx);
        goto after_14;
    // 0x8010DC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_8010DC34:
    // 0x8010DC34: jal         0x8008B064
    // 0x8010DC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_15;
    // 0x8010DC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8010DC3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010DC40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010DC44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010DC48: jr          $ra
    // 0x8010DC4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8010DC4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808010B0_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808010BC: jal         0x800839E8
    // 0x808010C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808010C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808010C4: beq         $v0, $zero, L_808010D8
    if (ctx->r2 == 0) {
        // 0x808010C8: nop
    
            goto L_808010D8;
    }
    // 0x808010C8: nop

    // 0x808010CC: jal         0x800839B0
    // 0x808010D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808010D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808010D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_808010D8:
    // 0x808010D8: jal         0x8080081C
    // 0x808010DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808010DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808010E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808010E4: jal         0x8009E5C8
    // 0x808010E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808010E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808010EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808010F4: jr          $ra
    // 0x808010F8: nop

    return;
    // 0x808010F8: nop

;}
RECOMP_FUNC void func_800CB3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB3E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CB3E4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CB3E8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800CB3EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CB3F0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800CB3F4: jr          $ra
    // 0x800CB3F8: lbu         $v0, -0x548F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X548F);
    return;
    // 0x800CB3F8: lbu         $v0, -0x548F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X548F);
;}
RECOMP_FUNC void func_80801038_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080103C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801040: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801044: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801048: jal         0x80100094
    // 0x8080104C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080104C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801050: lbu         $t6, 0x3C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3C);
    // 0x80801054: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801058: addiu       $a0, $zero, 0x65A
    ctx->r4 = ADD32(0, 0X65A);
    // 0x8080105C: beql        $t6, $zero, L_808010A8
    if (ctx->r14 == 0) {
        // 0x80801060: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808010A8;
    }
    goto skip_0;
    // 0x80801060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801064: jal         0x800DA3B8
    // 0x80801068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x80801068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080106C: lbu         $t7, 0x39($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X39);
    // 0x80801070: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801074: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801078: bne         $t7, $at, L_808010A4
    if (ctx->r15 != ctx->r1) {
        // 0x8080107C: addiu       $s1, $zero, 0x8
        ctx->r17 = ADD32(0, 0X8);
            goto L_808010A4;
    }
    // 0x8080107C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80801080:
    // 0x80801080: jal         0x800F6438
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_2;
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801088: beql        $v0, $zero, L_8080109C
    if (ctx->r2 == 0) {
        // 0x8080108C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080109C;
    }
    goto skip_1;
    // 0x8080108C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80801090: jal         0x800F4CC0
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_3;
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801098: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080109C:
    // 0x8080109C: bne         $s0, $s1, L_80801080
    if (ctx->r16 != ctx->r17) {
        // 0x808010A0: nop
    
            goto L_80801080;
    }
    // 0x808010A0: nop

L_808010A4:
    // 0x808010A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808010A8:
    // 0x808010A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808010AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808010B0: jr          $ra
    // 0x808010B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808010B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800D1824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D182C: jal         0x800D175C
    // 0x800D1830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D175C(rdram, ctx);
        goto after_0;
    // 0x800D1830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800D1834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D183C: jr          $ra
    // 0x800D1840: nop

    return;
    // 0x800D1840: nop

;}
RECOMP_FUNC void func_80094A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094A10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80094A14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80094A1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80094A20: jal         0x80094510
    // 0x80094A24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80094510(rdram, ctx);
        goto after_0;
    // 0x80094A24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80094A28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80094A2C: jal         0x800949BC
    // 0x80094A30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800949BC(rdram, ctx);
        goto after_1;
    // 0x80094A30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80094A34: beql        $v0, $zero, L_80094A48
    if (ctx->r2 == 0) {
        // 0x80094A38: lw          $v0, 0x64($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X64);
            goto L_80094A48;
    }
    goto skip_0;
    // 0x80094A38: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    skip_0:
    // 0x80094A3C: b           L_80094AA0
    // 0x80094A40: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80094AA0;
    // 0x80094A40: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80094A44: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
L_80094A48:
    // 0x80094A48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80094A4C: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80094A50: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80094A54: jal         0x80094510
    // 0x80094A58: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    func_80094510(rdram, ctx);
        goto after_2;
    // 0x80094A58: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_2:
    // 0x80094A5C: bne         $v0, $zero, L_80094A78
    if (ctx->r2 != 0) {
        // 0x80094A60: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80094A78;
    }
    // 0x80094A60: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80094A64: lw          $t8, 0x64($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X64);
    // 0x80094A68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80094A6C: jal         0x80094510
    // 0x80094A70: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    func_80094510(rdram, ctx);
        goto after_3;
    // 0x80094A70: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    after_3:
    // 0x80094A74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80094A78:
    // 0x80094A78: jal         0x800883E8
    // 0x80094A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcegg_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80094A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80094A80: beql        $v0, $zero, L_80094A48
    if (ctx->r2 == 0) {
        // 0x80094A84: lw          $v0, 0x64($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X64);
            goto L_80094A48;
    }
    goto skip_1;
    // 0x80094A84: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    skip_1:
    // 0x80094A88: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80094A8C: beql        $s0, $t9, L_80094AA0
    if (ctx->r16 == ctx->r25) {
        // 0x80094A90: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80094AA0;
    }
    goto skip_2;
    // 0x80094A90: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_2:
    // 0x80094A94: jal         0x80094E40
    // 0x80094A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094E40(rdram, ctx);
        goto after_5;
    // 0x80094A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80094A9C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80094AA0:
    // 0x80094AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80094AA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80094AA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80094AAC: jr          $ra
    // 0x80094AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80094AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
