#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801CD8_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801CE4: jal         0x8001210C
    // 0x80801CE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80801CE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80801CEC: bne         $v0, $zero, L_80801CFC
    if (ctx->r2 != 0) {
        // 0x80801CF0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801CFC;
    }
    // 0x80801CF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801CF4: jal         0x80108B04
    // 0x80801CF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x80801CF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_80801CFC:
    // 0x80801CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D04: jr          $ra
    // 0x80801D08: nop

    return;
    // 0x80801D08: nop

;}
RECOMP_FUNC void func_800A38F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A38F0: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A38F4: sb          $a1, 0x54($t6)
    MEM_B(0X54, ctx->r14) = ctx->r5;
    // 0x800A38F8: lw          $t7, 0xA0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XA0);
    // 0x800A38FC: jr          $ra
    // 0x800A3900: sb          $a2, 0x55($t7)
    MEM_B(0X55, ctx->r15) = ctx->r6;
    return;
    // 0x800A3900: sb          $a2, 0x55($t7)
    MEM_B(0X55, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void bsfirstp_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808078E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808078E4: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB5A0) << 16);
    // 0x808078E8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808078EC: jr          $ra
    // 0x808078F0: lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5A0));
    return;
    // 0x808078F0: lw          $v0, -0x4A60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5A0));
;}
RECOMP_FUNC void susubgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800044: jr          $ra
    // 0x80800048: sh          $a2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r6;
    return;
    // 0x80800048: sh          $a2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_8080069C_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A4: jal         0x8008C9D8
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C9D8(rdram, ctx);
        goto after_0;
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006B4: jr          $ra
    // 0x808006B8: nop

    return;
    // 0x808006B8: nop

;}
RECOMP_FUNC void func_80800000_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80085808
    // 0x8080000C: nop

    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089680: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089680);
    return;
    // 0x80089684: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chmole_prehist_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E90: syscall     466
    recomp_syscall_handler(rdram, ctx, 0x80086E90);
    return;
    // 0x80086E94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chdoormake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086888: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x80086888);
    return;
    // 0x8008688C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void badeathmatch_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D0: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x808004D4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x808004D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x808004DC: sh          $a2, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r6;
    // 0x808004E0: lw          $t8, 0x158($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X158);
    // 0x808004E4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x808004E8: jr          $ra
    // 0x808004EC: sh          $a3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r7;
    return;
    // 0x808004EC: sh          $a3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r7;
;}
RECOMP_FUNC void func_800A50DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A50DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A50E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A50E4: jal         0x8008FFE8
    // 0x800A50E8: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x800A50E8: nop

    after_0:
    // 0x800A50EC: jal         0x8010FAE4
    // 0x800A50F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FAE4(rdram, ctx);
        goto after_1;
    // 0x800A50F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A50F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A50F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A50FC: jr          $ra
    // 0x800A5100: nop

    return;
    // 0x800A5100: nop

;}
RECOMP_FUNC void _bsvan_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084160: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084160);
    return;
    // 0x80084164: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _gcmapsects_lagoonmid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FF8: syscall     664
    recomp_syscall_handler(rdram, ctx, 0x80087FF8);
    return;
    // 0x80087FFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080000C_chlagoonbilldrillcover(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x80800020: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800024: jal         0x800DA298
    // 0x80800028: addiu       $a0, $t6, 0x3C2
    ctx->r4 = ADD32(ctx->r14, 0X3C2);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $t6, 0x3C2
    ctx->r4 = ADD32(ctx->r14, 0X3C2);
    after_0:
    // 0x8080002C: beql        $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x80800030: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800034: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80800038: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x8080003C: slti        $at, $t8, 0x35
    ctx->r1 = SIGNED(ctx->r24) < 0X35 ? 1 : 0;
    // 0x80800040: bne         $at, $zero, L_80800078
    if (ctx->r1 != 0) {
        // 0x80800044: nop
    
            goto L_80800078;
    }
    // 0x80800044: nop

    // 0x80800048: jal         0x8010A570
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800050: jal         0x8010A624
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_2;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800058: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800064: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80800068: jal         0x80108B04
    // 0x8080006C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x8080006C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_3:
    // 0x80800070: b           L_80800084
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800084;
    // 0x80800074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800078:
    // 0x80800078: jal         0x800FFAB0
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800084:
    // 0x80800084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084338: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084338);
    return;
    // 0x8008433C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void _bskazshoesspringjump_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835B0: syscall     67
    recomp_syscall_handler(rdram, ctx, 0x800835B0);
    return;
    // 0x800835B4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_801040D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801040D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801040D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801040D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801040DC: addiu       $a0, $a0, 0x5AB0
    ctx->r4 = ADD32(ctx->r4, 0X5AB0);
    // 0x801040E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801040E4: addiu       $t6, $t6, 0x5AB8
    ctx->r14 = ADD32(ctx->r14, 0X5AB8);
    // 0x801040E8: addiu       $t7, $zero, 0x6D
    ctx->r15 = ADD32(0, 0X6D);
    // 0x801040EC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801040F0: jal         0x800DFAD0
    // 0x801040F4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    func_800DFAD0(rdram, ctx);
        goto after_0;
    // 0x801040F4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    after_0:
    // 0x801040F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801040FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104100: addiu       $v0, $a0, 0x5AB0
    ctx->r2 = ADD32(ctx->r4, 0X5AB0);
    // 0x80104104: jr          $ra
    // 0x80104108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_801107F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801107F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801107F4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801107F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801107FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80110800: jal         0x800EE7F8
    // 0x80110804: addiu       $a1, $a3, 0x74
    ctx->r5 = ADD32(ctx->r7, 0X74);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80110804: addiu       $a1, $a3, 0x74
    ctx->r5 = ADD32(ctx->r7, 0X74);
    after_0:
    // 0x80110808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011080C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110810: jr          $ra
    // 0x80110814: nop

    return;
    // 0x80110814: nop

;}
RECOMP_FUNC void func_80099A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A64: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x80099A68: jr          $ra
    // 0x80099A6C: lw          $v0, 0x1C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C);
    return;
    // 0x80099A6C: lw          $v0, 0x1C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1C);
;}
RECOMP_FUNC void _bawasher_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085400: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085400);
    return;
    // 0x80085404: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800310_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800318: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080031C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800320: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800324: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800328: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080032C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800330: jal         0x800A2CE8
    // 0x80800334: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_0;
    // 0x80800334: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80800338: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x8080033C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: jal         0x800A2CE8
    // 0x80800348: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x80800348: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8080034C: jal         0x80800128
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bscarry(rdram, ctx);
        goto after_2;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800354: jal         0x8009EF10
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_3;
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080035C: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x80800360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800378;
    }
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800368: beql        $v0, $at, L_80800394
    if (ctx->r2 == ctx->r1) {
        // 0x8080036C: addiu       $s1, $zero, 0x3B
        ctx->r17 = ADD32(0, 0X3B);
            goto L_80800394;
    }
    goto skip_0;
    // 0x8080036C: addiu       $s1, $zero, 0x3B
    ctx->r17 = ADD32(0, 0X3B);
    skip_0:
    // 0x80800370: b           L_80800394
    // 0x80800374: nop

        goto L_80800394;
    // 0x80800374: nop

L_80800378:
    // 0x80800378: jal         0x8009BCD4
    // 0x8080037C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_4;
    // 0x8080037C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800380: beq         $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x80800384: nop
    
            goto L_80800394;
    }
    // 0x80800384: nop

    // 0x80800388: b           L_80800394
    // 0x8080038C: addiu       $s1, $zero, 0x3A
    ctx->r17 = ADD32(0, 0X3A);
        goto L_80800394;
    // 0x8080038C: addiu       $s1, $zero, 0x3A
    ctx->r17 = ADD32(0, 0X3A);
    // 0x80800390: addiu       $s1, $zero, 0x3B
    ctx->r17 = ADD32(0, 0X3B);
L_80800394:
    // 0x80800394: jal         0x80084D40
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080039C: bne         $v0, $zero, L_808003A8
    if (ctx->r2 != 0) {
        // 0x808003A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A8;
    }
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_808003A8:
    // 0x808003A8: jal         0x8009E5C8
    // 0x808003AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808003AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808003B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808003B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808003BC: jr          $ra
    // 0x808003C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808003C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void subaddievolume_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x80800004: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80800008: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80800014: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80800018: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8080001C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80800020: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80800024: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80800028: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8080002C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80800030: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800034: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800038: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080003C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800040: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800044: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800048: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x8080004C: sw          $a2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r6;
    // 0x80800050: bne         $a0, $zero, L_80800060
    if (ctx->r4 != 0) {
        // 0x80800054: sw          $a3, 0x16C($sp)
        MEM_W(0X16C, ctx->r29) = ctx->r7;
            goto L_80800060;
    }
    // 0x80800054: sw          $a3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r7;
    // 0x80800058: b           L_808006DC
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006DC;
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800060:
    // 0x80800060: lw          $t6, 0x7C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X7C);
    // 0x80800064: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800068: bltz        $t8, L_80800078
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080006C: nop
    
            goto L_80800078;
    }
    // 0x8080006C: nop

    // 0x80800070: b           L_808006DC
    // 0x80800074: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808006DC;
    // 0x80800074: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800078:
    // 0x80800078: jal         0x80103D98
    // 0x8080007C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_80103D98(rdram, ctx);
        goto after_0;
    // 0x8080007C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x80800080: sw          $v0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r2;
    // 0x80800084: jal         0x801040A8
    // 0x80800088: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801040A8(rdram, ctx);
        goto after_1;
    // 0x80800088: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8080008C: beq         $v0, $zero, L_808000A0
    if (ctx->r2 == 0) {
        // 0x80800090: sw          $v0, 0x114($sp)
        MEM_W(0X114, ctx->r29) = ctx->r2;
            goto L_808000A0;
    }
    // 0x80800090: sw          $v0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r2;
    // 0x80800094: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x80800098: bnel        $a0, $zero, L_8080013C
    if (ctx->r4 != 0) {
        // 0x8080009C: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_8080013C;
    }
    goto skip_0;
    // 0x8080009C: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_0:
L_808000A0:
    // 0x808000A0: lw          $a0, 0x168($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X168);
    // 0x808000A4: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x808000A8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x808000AC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x808000B0: jal         0x800F1418
    // 0x808000B4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F1418(rdram, ctx);
        goto after_2;
    // 0x808000B4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x808000B8: addiu       $s0, $sp, 0xF0
    ctx->r16 = ADD32(ctx->r29, 0XF0);
    // 0x808000BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808000C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80103F38
    // 0x808000C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80103F38(rdram, ctx);
        goto after_3;
    // 0x808000C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x808000CC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x808000D0: blez        $s1, L_80800130
    if (SIGNED(ctx->r17) <= 0) {
        // 0x808000D4: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80800130;
    }
    // 0x808000D4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x808000D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3234, 0X730) << 16);
    // 0x808000DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808000E0: lwc1        $f24, 0x730($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3234, 0X730));
    // 0x808000E4: lw          $s3, 0x164($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X164);
L_808000E8:
    // 0x808000E8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808000EC: jal         0x800DC178
    // 0x808000F0: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808000F0: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_4:
    // 0x808000F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808000F8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808000FC: jal         0x800DC178
    // 0x80800100: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800100: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_5:
    // 0x80800104: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800108: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080010C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800110: jal         0x800EEC30
    // 0x80800114: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EEC30(rdram, ctx);
        goto after_6;
    // 0x80800114: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x80800118: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080011C: jal         0x800EF04C
    // 0x80800120: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800120: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800124: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80800128: bne         $fp, $s1, L_808000E8
    if (ctx->r30 != ctx->r17) {
        // 0x8080012C: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808000E8;
    }
    // 0x8080012C: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_80800130:
    // 0x80800130: b           L_808006DC
    // 0x80800134: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_808006DC;
    // 0x80800134: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800138: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8080013C:
    // 0x8080013C: lh          $v1, 0x2($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2);
    // 0x80800140: lw          $a3, 0x170($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X170);
    // 0x80800144: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80800148: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8080014C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80800150: addu        $a1, $t0, $a0
    ctx->r5 = ADD32(ctx->r8, ctx->r4);
    // 0x80800154: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80800158: sll         $t1, $v1, 4
    ctx->r9 = S32(ctx->r3 << 4);
    // 0x8080015C: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x80800160: sw          $t2, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r10;
    // 0x80800164: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x80800168: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8080016C: beq         $a3, $zero, L_80800180
    if (ctx->r7 == 0) {
        // 0x80800170: addu        $a2, $t3, $t4
        ctx->r6 = ADD32(ctx->r11, ctx->r12);
            goto L_80800180;
    }
    // 0x80800170: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x80800174: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80800178: b           L_80800184
    // 0x8080017C: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
        goto L_80800184;
    // 0x8080017C: sw          $t5, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r13;
L_80800180:
    // 0x80800180: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
L_80800184:
    // 0x80800184: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x80800188: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8080018C: bnel        $at, $zero, L_8080019C
    if (ctx->r1 != 0) {
        // 0x80800190: sw          $a1, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r5;
            goto L_8080019C;
    }
    goto skip_1;
    // 0x80800190: sw          $a1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r5;
    skip_1:
    // 0x80800194: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
    // 0x80800198: sw          $a1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r5;
L_8080019C:
    // 0x8080019C: jal         0x80019CD4
    // 0x808001A0: sw          $a2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r6;
    func_80019CD4(rdram, ctx);
        goto after_8;
    // 0x808001A0: sw          $a2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r6;
    after_8:
    // 0x808001A4: jal         0x801027F4
    // 0x808001A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801027F4(rdram, ctx);
        goto after_9;
    // 0x808001A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x808001AC: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x808001B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808001B4: lw          $a2, 0x38($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X38);
    // 0x808001B8: jal         0x80019750
    // 0x808001BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_10;
    // 0x808001BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x808001C0: jal         0x80018AD0
    // 0x808001C4: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    mlMtxGet(rdram, ctx);
        goto after_11;
    // 0x808001C4: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    after_11:
    // 0x808001C8: lw          $t7, 0x16C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X16C);
    // 0x808001CC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x808001D0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x808001D4: blez        $t7, L_808006D8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808001D8: addiu       $s7, $zero, 0x6
        ctx->r23 = ADD32(0, 0X6);
            goto L_808006D8;
    }
    // 0x808001D8: addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    // 0x808001DC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808001E0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001E4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808001E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001EC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808001F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3234, 0X734) << 16);
    // 0x808001F4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808001F8: lwc1        $f24, 0x734($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3234, 0X734));
    // 0x808001FC: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
L_80800200:
    // 0x80800200: lw          $t9, 0x100($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X100);
    // 0x80800204: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80800208: beq         $t8, $zero, L_80800214
    if (ctx->r24 == 0) {
        // 0x8080020C: addiu       $t0, $t9, 0x1
        ctx->r8 = ADD32(ctx->r25, 0X1);
            goto L_80800214;
    }
    // 0x8080020C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80800210: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
L_80800214:
    // 0x80800214: lw          $t1, 0x110($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X110);
    // 0x80800218: lw          $t2, 0x100($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X100);
    // 0x8080021C: lw          $t5, 0x110($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X110);
    // 0x80800220: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x80800224: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800228: beq         $at, $zero, L_80800410
    if (ctx->r1 == 0) {
        // 0x8080022C: subu        $t3, $v0, $t2
        ctx->r11 = SUB32(ctx->r2, ctx->r10);
            goto L_80800410;
    }
    // 0x8080022C: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80800230: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80800234: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x80800238: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8080023C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80800240: addu        $s4, $t4, $t1
    ctx->r20 = ADD32(ctx->r12, ctx->r9);
    // 0x80800244: blez        $t5, L_808006AC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80800248: addiu       $s4, $s4, -0x10
        ctx->r20 = ADD32(ctx->r20, -0X10);
            goto L_808006AC;
    }
    // 0x80800248: addiu       $s4, $s4, -0x10
    ctx->r20 = ADD32(ctx->r20, -0X10);
    // 0x8080024C: lw          $v0, 0x164($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X164);
    // 0x80800250: sll         $t6, $fp, 2
    ctx->r14 = S32(ctx->r30 << 2);
    // 0x80800254: sll         $t7, $fp, 2
    ctx->r15 = S32(ctx->r30 << 2);
    // 0x80800258: subu        $t7, $t7, $fp
    ctx->r15 = SUB32(ctx->r15, ctx->r30);
    // 0x8080025C: subu        $t6, $t6, $fp
    ctx->r14 = SUB32(ctx->r14, ctx->r30);
    // 0x80800260: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800264: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800268: addiu       $a1, $s4, 0xC
    ctx->r5 = ADD32(ctx->r20, 0XC);
    // 0x8080026C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80800270: addu        $s5, $v0, $t7
    ctx->r21 = ADD32(ctx->r2, ctx->r15);
    // 0x80800274: addu        $s3, $v0, $t6
    ctx->r19 = ADD32(ctx->r2, ctx->r14);
    // 0x80800278: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
L_8080027C:
    // 0x8080027C: jal         0x800EE88C
    // 0x80800280: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    func_800EE88C(rdram, ctx);
        goto after_12;
    // 0x80800280: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    after_12:
    // 0x80800284: lbu         $t9, 0x12($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X12);
    // 0x80800288: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080028C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800290: bgez        $t9, L_808002A4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800294: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808002A4;
    }
    // 0x80800294: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080029C: nop

    // 0x808002A0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_808002A4:
    // 0x808002A4: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808002A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002AC: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    // 0x808002B0: lbu         $t0, 0x13($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X13);
    // 0x808002B4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x808002B8: bgez        $t0, L_808002CC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808002BC: cvt.s.w     $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808002CC;
    }
    // 0x808002BC: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808002C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002C4: nop

    // 0x808002C8: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
L_808002CC:
    // 0x808002CC: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808002D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002D4: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
    // 0x808002D8: lbu         $t8, 0x14($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X14);
    // 0x808002DC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808002E0: bgez        $t8, L_808002F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808002E4: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808002F4;
    }
    // 0x808002E4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002EC: nop

    // 0x808002F0: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_808002F4:
    // 0x808002F4: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x808002F8: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x808002FC: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x80800300: jal         0x800ADE2C
    // 0x80800304: lb          $a1, 0x16($s4)
    ctx->r5 = MEM_B(ctx->r20, 0X16);
    func_800ADE2C(rdram, ctx);
        goto after_13;
    // 0x80800304: lb          $a1, 0x16($s4)
    ctx->r5 = MEM_B(ctx->r20, 0X16);
    after_13:
    // 0x80800308: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    // 0x8080030C: jal         0x80019AA0
    // 0x80800310: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_14;
    // 0x80800310: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x80800314: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x80800318: jal         0x80019994
    // 0x8080031C: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    func_80019994(rdram, ctx);
        goto after_15;
    // 0x8080031C: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    after_15:
    // 0x80800320: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800324: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80800328: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
L_8080032C:
    // 0x8080032C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80800330: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x80800334: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80800338: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8080033C: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800340: jal         0x800DC178
    // 0x80800344: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x80800344: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    after_16:
    // 0x80800348: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8080034C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800350: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800354: bne         $s1, $s7, L_8080032C
    if (ctx->r17 != ctx->r23) {
        // 0x80800358: swc1        $f0, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->f0.u32l;
            goto L_8080032C;
    }
    // 0x80800358: swc1        $f0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f0.u32l;
    // 0x8080035C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800360: jal         0x800DC128
    // 0x80800364: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_17;
    // 0x80800364: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80800368: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080036C: jal         0x800DC298
    // 0x80800370: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_800DC298(rdram, ctx);
        goto after_18;
    // 0x80800370: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_18:
    // 0x80800374: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800378: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808003A4;
    }
    // 0x80800378: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080037C: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x80800380: addu        $t1, $s4, $t4
    ctx->r9 = ADD32(ctx->r20, ctx->r12);
    // 0x80800384: lh          $t5, 0x0($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X0);
    // 0x80800388: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8080038C: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x80800390: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80800394: nop

    // 0x80800398: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080039C: b           L_808003C8
    // 0x808003A0: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
        goto L_808003C8;
    // 0x808003A0: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
L_808003A4:
    // 0x808003A4: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x808003A8: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x808003AC: lh          $t8, 0x6($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X6);
    // 0x808003B0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x808003B4: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x808003B8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x808003BC: nop

    // 0x808003C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808003C4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
L_808003C8:
    // 0x808003C8: jal         0x80019224
    // 0x808003CC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80019224(rdram, ctx);
        goto after_19;
    // 0x808003CC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_19:
    // 0x808003D0: lw          $t4, 0x16C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X16C);
    // 0x808003D4: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x808003D8: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x808003DC: slt         $at, $fp, $t4
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808003E0: bne         $at, $zero, L_808003F0
    if (ctx->r1 != 0) {
        // 0x808003E4: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_808003F0;
    }
    // 0x808003E4: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x808003E8: b           L_808006DC
    // 0x808003EC: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
        goto L_808006DC;
    // 0x808003EC: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
L_808003F0:
    // 0x808003F0: jal         0x80018DAC
    // 0x808003F4: nop

    mlMtxPop(rdram, ctx);
        goto after_20;
    // 0x808003F4: nop

    after_20:
    // 0x808003F8: lw          $t1, 0x168($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X168);
    // 0x808003FC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80800400: bnel        $s6, $t1, L_8080027C
    if (ctx->r22 != ctx->r9) {
        // 0x80800404: lw          $a1, 0x84($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X84);
            goto L_8080027C;
    }
    goto skip_2;
    // 0x80800404: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    skip_2:
    // 0x80800408: b           L_808006B0
    // 0x8080040C: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
        goto L_808006B0;
    // 0x8080040C: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
L_80800410:
    // 0x80800410: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x80800414: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x80800418: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x8080041C: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80800420: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800424: beq         $at, $zero, L_808005B4
    if (ctx->r1 == 0) {
        // 0x80800428: subu        $t9, $v1, $t7
        ctx->r25 = SUB32(ctx->r3, ctx->r15);
            goto L_808005B4;
    }
    // 0x80800428: subu        $t9, $v1, $t7
    ctx->r25 = SUB32(ctx->r3, ctx->r15);
    // 0x8080042C: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x80800430: lw          $t2, 0x108($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X108);
    // 0x80800434: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800438: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x8080043C: blez        $t3, L_808006AC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80800440: addu        $s0, $t8, $t2
        ctx->r16 = ADD32(ctx->r24, ctx->r10);
            goto L_808006AC;
    }
    // 0x80800440: addu        $s0, $t8, $t2
    ctx->r16 = ADD32(ctx->r24, ctx->r10);
    // 0x80800444: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x80800448: sll         $t1, $fp, 2
    ctx->r9 = S32(ctx->r30 << 2);
    // 0x8080044C: subu        $t1, $t1, $fp
    ctx->r9 = SUB32(ctx->r9, ctx->r30);
    // 0x80800450: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800454: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800458: addu        $s3, $t4, $t1
    ctx->r19 = ADD32(ctx->r12, ctx->r9);
    // 0x8080045C: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
L_80800460:
    // 0x80800460: jal         0x800EE88C
    // 0x80800464: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE88C(rdram, ctx);
        goto after_21;
    // 0x80800464: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_21:
    // 0x80800468: lbu         $t5, 0xA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA);
    // 0x8080046C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800470: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80800474: bgez        $t5, L_80800488
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800478: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800488;
    }
    // 0x80800478: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080047C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800480: nop

    // 0x80800484: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_80800488:
    // 0x80800488: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8080048C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800490: swc1        $f18, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f18.u32l;
    // 0x80800494: lbu         $t6, 0xB($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XB);
    // 0x80800498: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8080049C: bgez        $t6, L_808004B0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808004A0: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808004B0;
    }
    // 0x808004A0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808004A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004A8: nop

    // 0x808004AC: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_808004B0:
    // 0x808004B0: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808004B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808004B8: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x808004BC: lbu         $t7, 0xC($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC);
    // 0x808004C0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x808004C4: bgez        $t7, L_808004D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808004C8: cvt.s.w     $f12, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808004D8;
    }
    // 0x808004C8: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808004CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808004D0: nop

    // 0x808004D4: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
L_808004D8:
    // 0x808004D8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x808004DC: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x808004E0: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x808004E4: add.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x808004E8: swc1        $f18, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f18.u32l;
    // 0x808004EC: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    // 0x808004F0: jal         0x800ADE2C
    // 0x808004F4: lb          $a1, 0xE($s0)
    ctx->r5 = MEM_B(ctx->r16, 0XE);
    func_800ADE2C(rdram, ctx);
        goto after_22;
    // 0x808004F4: lb          $a1, 0xE($s0)
    ctx->r5 = MEM_B(ctx->r16, 0XE);
    after_22:
    // 0x808004F8: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    // 0x808004FC: jal         0x80019AA0
    // 0x80800500: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_23;
    // 0x80800500: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_23:
    // 0x80800504: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80800508: jal         0x800198D4
    // 0x8080050C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    func_800198D4(rdram, ctx);
        goto after_24;
    // 0x8080050C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    after_24:
    // 0x80800510: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800514: jal         0x800DC178
    // 0x80800518: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_25;
    // 0x80800518: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_25:
    // 0x8080051C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80800520: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800524: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800528: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8080052C: nop

    // 0x80800530: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800534: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800538: jal         0x800EEB9C
    // 0x8080053C: nop

    func_800EEB9C(rdram, ctx);
        goto after_26;
    // 0x8080053C: nop

    after_26:
    // 0x80800540: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80800544: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80800548: nop

    // 0x8080054C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800550: mul.s       $f12, $f0, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x80800554: nop

    // 0x80800558: mul.s       $f14, $f0, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8080055C: jal         0x800DC178
    // 0x80800560: nop

    func_800DC178(rdram, ctx);
        goto after_27;
    // 0x80800560: nop

    after_27:
    // 0x80800564: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x80800568: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080056C: jal         0x80019224
    // 0x80800570: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80019224(rdram, ctx);
        goto after_28;
    // 0x80800570: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_28:
    // 0x80800574: lw          $t8, 0x16C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X16C);
    // 0x80800578: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8080057C: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80800580: slt         $at, $fp, $t8
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800584: bne         $at, $zero, L_80800594
    if (ctx->r1 != 0) {
        // 0x80800588: nop
    
            goto L_80800594;
    }
    // 0x80800588: nop

    // 0x8080058C: b           L_808006DC
    // 0x80800590: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
        goto L_808006DC;
    // 0x80800590: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
L_80800594:
    // 0x80800594: jal         0x80018DAC
    // 0x80800598: nop

    mlMtxPop(rdram, ctx);
        goto after_29;
    // 0x80800598: nop

    after_29:
    // 0x8080059C: lw          $t2, 0x168($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X168);
    // 0x808005A0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x808005A4: bnel        $s6, $t2, L_80800460
    if (ctx->r22 != ctx->r10) {
        // 0x808005A8: addiu       $a0, $sp, 0xB8
        ctx->r4 = ADD32(ctx->r29, 0XB8);
            goto L_80800460;
    }
    goto skip_3;
    // 0x808005A8: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    skip_3:
    // 0x808005AC: b           L_808006B0
    // 0x808005B0: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
        goto L_808006B0;
    // 0x808005B0: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
L_808005B4:
    // 0x808005B4: blez        $t3, L_808006AC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x808005B8: lw          $t4, 0x164($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X164);
            goto L_808006AC;
    }
    // 0x808005B8: lw          $t4, 0x164($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X164);
    // 0x808005BC: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x808005C0: lw          $t6, 0x100($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X100);
    // 0x808005C4: lw          $t0, 0x104($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X104);
    // 0x808005C8: sll         $t1, $fp, 2
    ctx->r9 = S32(ctx->r30 << 2);
    // 0x808005CC: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x808005D0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808005D4: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x808005D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808005DC: subu        $t1, $t1, $fp
    ctx->r9 = SUB32(ctx->r9, ctx->r30);
    // 0x808005E0: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x808005E4: addiu       $s0, $s0, -0xC
    ctx->r16 = ADD32(ctx->r16, -0XC);
    // 0x808005E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808005EC: addu        $s3, $t4, $t1
    ctx->r19 = ADD32(ctx->r12, ctx->r9);
    // 0x808005F0: addiu       $s1, $s0, 0x2
    ctx->r17 = ADD32(ctx->r16, 0X2);
    // 0x808005F4: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
L_808005F8:
    // 0x808005F8: jal         0x800EE88C
    // 0x808005FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE88C(rdram, ctx);
        goto after_30;
    // 0x808005FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_30:
    // 0x80800600: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x80800604: jal         0x800ADE2C
    // 0x80800608: lb          $a1, 0x9($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X9);
    func_800ADE2C(rdram, ctx);
        goto after_31;
    // 0x80800608: lb          $a1, 0x9($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X9);
    after_31:
    // 0x8080060C: addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    // 0x80800610: jal         0x80019AA0
    // 0x80800614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_32;
    // 0x80800614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_32:
    // 0x80800618: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8080061C: lwc1        $f14, 0xA0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80800620: jal         0x80019C84
    // 0x80800624: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    mlMtxTranslate(rdram, ctx);
        goto after_33;
    // 0x80800624: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    after_33:
    // 0x80800628: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8080062C: jal         0x800DC178
    // 0x80800630: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_34;
    // 0x80800630: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_34:
    // 0x80800634: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800638: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8080063C: jal         0x800DC178
    // 0x80800640: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_35;
    // 0x80800640: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_35:
    // 0x80800644: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80800648: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080064C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800650: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80800654: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800658: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080065C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800660: jal         0x800EEC30
    // 0x80800664: nop

    func_800EEC30(rdram, ctx);
        goto after_36;
    // 0x80800664: nop

    after_36:
    // 0x80800668: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080066C: jal         0x80019224
    // 0x80800670: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80019224(rdram, ctx);
        goto after_37;
    // 0x80800670: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_37:
    // 0x80800674: lw          $t2, 0x16C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X16C);
    // 0x80800678: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8080067C: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80800680: slt         $at, $fp, $t2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80800684: bne         $at, $zero, L_80800694
    if (ctx->r1 != 0) {
        // 0x80800688: nop
    
            goto L_80800694;
    }
    // 0x80800688: nop

    // 0x8080068C: b           L_808006DC
    // 0x80800690: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
        goto L_808006DC;
    // 0x80800690: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
L_80800694:
    // 0x80800694: jal         0x80018DAC
    // 0x80800698: nop

    mlMtxPop(rdram, ctx);
        goto after_38;
    // 0x80800698: nop

    after_38:
    // 0x8080069C: lw          $t3, 0x168($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X168);
    // 0x808006A0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x808006A4: bnel        $s6, $t3, L_808005F8
    if (ctx->r22 != ctx->r11) {
        // 0x808006A8: addiu       $a0, $sp, 0x9C
        ctx->r4 = ADD32(ctx->r29, 0X9C);
            goto L_808005F8;
    }
    goto skip_4;
    // 0x808006A8: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    skip_4:
L_808006AC:
    // 0x808006AC: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
L_808006B0:
    // 0x808006B0: lw          $t5, 0xFC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XFC);
    // 0x808006B4: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x808006B8: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808006BC: bne         $at, $zero, L_808006C8
    if (ctx->r1 != 0) {
        // 0x808006C0: sw          $t1, 0x100($sp)
        MEM_W(0X100, ctx->r29) = ctx->r9;
            goto L_808006C8;
    }
    // 0x808006C0: sw          $t1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r9;
    // 0x808006C4: sw          $zero, 0x100($sp)
    MEM_W(0X100, ctx->r29) = 0;
L_808006C8:
    // 0x808006C8: lw          $t6, 0x16C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X16C);
    // 0x808006CC: slt         $at, $fp, $t6
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808006D0: bnel        $at, $zero, L_80800200
    if (ctx->r1 != 0) {
        // 0x808006D4: lw          $t8, 0x170($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X170);
            goto L_80800200;
    }
    goto skip_5;
    // 0x808006D4: lw          $t8, 0x170($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X170);
    skip_5:
L_808006D8:
    // 0x808006D8: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
L_808006DC:
    // 0x808006DC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x808006E0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808006E4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808006E8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808006EC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808006F0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808006F4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x808006F8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x808006FC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800700: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800704: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80800708: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8080070C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80800710: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800714: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80800718: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8080071C: jr          $ra
    // 0x80800720: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x80800720: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    // 0x80800724: nop

    // 0x80800728: nop

    // 0x8080072C: nop

;}
RECOMP_FUNC void _chegggolden_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087200: syscall     536
    recomp_syscall_handler(rdram, ctx, 0x80087200);
    return;
    // 0x80087204: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _suegg_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A410: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A410);
    return;
    // 0x8008A414: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_800DC84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC84C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800DC850: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DC854: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DC858: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DC85C: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800DC860: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DC864: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800DC868: beq         $t6, $zero, L_800DC944
    if (ctx->r14 == 0) {
        // 0x800DC86C: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_800DC944;
    }
    // 0x800DC86C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800DC870: jal         0x800DC5BC
    // 0x800DC874: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800DC5BC(rdram, ctx);
        goto after_0;
    // 0x800DC874: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_0:
    // 0x800DC878: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800DC87C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800DC880: jal         0x80018E1C
    // 0x800DC884: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    mlMtx_push_translation(rdram, ctx);
        goto after_1;
    // 0x800DC884: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800DC888: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC88C: jal         0x80018FE8
    // 0x800DC890: lwc1        $f12, -0x3154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3154);
    mlMtxRotYaw(rdram, ctx);
        goto after_2;
    // 0x800DC890: lwc1        $f12, -0x3154($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3154);
    after_2:
    // 0x800DC894: lh          $t7, 0xA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XA);
    // 0x800DC898: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC89C: bne         $t7, $zero, L_800DC8AC
    if (ctx->r15 != 0) {
        // 0x800DC8A0: nop
    
            goto L_800DC8AC;
    }
    // 0x800DC8A0: nop

    // 0x800DC8A4: jal         0x80018F50
    // 0x800DC8A8: lwc1        $f12, -0x3158($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3158);
    mlMtxRotPitch(rdram, ctx);
        goto after_3;
    // 0x800DC8A8: lwc1        $f12, -0x3158($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3158);
    after_3:
L_800DC8AC:
    // 0x800DC8AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC8B0: jal         0x80019148
    // 0x800DC8B4: lwc1        $f12, -0x36B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36B8);
    mlMtxScale(rdram, ctx);
        goto after_4;
    // 0x800DC8B4: lwc1        $f12, -0x36B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X36B8);
    after_4:
    // 0x800DC8B8: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800DC8BC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800DC8C0: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800DC8C4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800DC8C8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800DC8CC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800DC8D0: jal         0x80019C84
    // 0x800DC8D4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_5;
    // 0x800DC8D4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_5:
    // 0x800DC8D8: jal         0x80018C28
    // 0x800DC8DC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_6;
    // 0x800DC8DC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x800DC8E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DC8E4: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800DC8E8: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x800DC8EC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800DC8F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DC8F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800DC8F8: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800DC8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DC900: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800DC904: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800DC908: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x800DC90C: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800DC910: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x800DC914: jal         0x800DE2A4
    // 0x800DC918: addu        $a1, $s1, $t3
    ctx->r5 = ADD32(ctx->r17, ctx->r11);
    func_800DE2A4(rdram, ctx);
        goto after_7;
    // 0x800DC918: addu        $a1, $s1, $t3
    ctx->r5 = ADD32(ctx->r17, ctx->r11);
    after_7:
    // 0x800DC91C: jal         0x80018DAC
    // 0x800DC920: nop

    mlMtxPop(rdram, ctx);
        goto after_8;
    // 0x800DC920: nop

    after_8:
    // 0x800DC924: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DC928: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x800DC92C: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x800DC930: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800DC934: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800DC938: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x800DC93C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800DC940: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800DC944:
    // 0x800DC944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DC948: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DC94C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DC950: jr          $ra
    // 0x800DC954: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800DC954: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _sucoasterfly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EC8: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089EC8);
    return;
    // 0x80089ECC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F1274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1278: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F127C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F1280: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F1284: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F1288: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F128C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800F1290: jal         0x800F10B4
    // 0x800F1294: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x800F1294: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800F1298: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800F129C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F12A0: jalr        $t9
    // 0x800F12A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800F12A4: nop

    after_1:
    // 0x800F12A8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F12AC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800F12B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F12B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800F12B8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800F12BC: jal         0x800F10B4
    // 0x800F12C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x800F12C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800F12C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F12C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F12CC: jr          $ra
    // 0x800F12D0: nop

    return;
    // 0x800F12D0: nop

;}
RECOMP_FUNC void gspropprop_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800514: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800518: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8080051C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800520: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800524: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80800528: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080052C: jal         0x800EE88C
    // 0x80800530: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x80800530: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x80800534: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80800538: sll         $t8, $t6, 30
    ctx->r24 = S32(ctx->r14 << 30);
    // 0x8080053C: bgez        $t8, L_808005F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800540: nop
    
            goto L_808005F4;
    }
    // 0x80800540: nop

    // 0x80800544: jal         0x80088C88
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080054C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800550: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800554: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x80800558: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x8080055C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800560: bgez        $t9, L_80800574
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800564: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800574;
    }
    // 0x80800564: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800568: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080056C: nop

    // 0x80800570: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80800574:
    // 0x80800574: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800578: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080057C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80800580: lbu         $t0, 0x3($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3);
    // 0x80800584: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80800588: bgez        $t0, L_8080059C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8080058C: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080059C;
    }
    // 0x8080058C: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800590: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800594: nop

    // 0x80800598: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_8080059C:
    // 0x8080059C: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808005A0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808005A4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808005A8: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x808005AC: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x808005B0: lbu         $t1, 0xA($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XA);
    // 0x808005B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808005B8: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x808005BC: bgez        $t1, L_808005D0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808005C0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_808005D0;
    }
    // 0x808005C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808005C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005C8: nop

    // 0x808005CC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_808005D0:
    // 0x808005D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2874, 0X6A8) << 16);
    // 0x808005D4: lwc1        $f16, 0x6A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2874, 0X6A8));
    // 0x808005D8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808005DC: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808005E0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808005E4: jal         0x800BFAD0
    // 0x808005E8: nop

    func_800BFAD0(rdram, ctx);
        goto after_2;
    // 0x808005E8: nop

    after_2:
    // 0x808005EC: b           L_80800684
    // 0x808005F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80800684;
    // 0x808005F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808005F4:
    // 0x808005F4: jal         0x80088C90
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gsproplookup_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80800600: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800604: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800608: sll         $t2, $v1, 22
    ctx->r10 = S32(ctx->r3 << 22);
    // 0x8080060C: srl         $t3, $t2, 24
    ctx->r11 = S32(U32(ctx->r10) >> 24);
    // 0x80800610: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800614: sll         $t8, $v1, 19
    ctx->r24 = S32(ctx->r3 << 19);
    // 0x80800618: bgez        $t3, L_80800630
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080061C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800630;
    }
    // 0x8080061C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800620: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800624: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800628: nop

    // 0x8080062C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80800630:
    // 0x80800630: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
    // 0x80800634: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2874, 0X6AC) << 16);
    // 0x80800638: lwc1        $f8, 0x6AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2874, 0X6AC));
    // 0x8080063C: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x80800640: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800644: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x80800648: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080064C: sll         $t0, $v1, 30
    ctx->r8 = S32(ctx->r3 << 30);
    // 0x80800650: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80800654: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x80800658: srl         $t7, $t6, 13
    ctx->r15 = S32(U32(ctx->r14) >> 13);
    // 0x8080065C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800660: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80800664: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80800668: lhu         $t2, 0xA($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XA);
    // 0x8080066C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800670: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800674: srl         $t3, $t2, 11
    ctx->r11 = S32(U32(ctx->r10) >> 11);
    // 0x80800678: jal         0x800BFB58
    // 0x8080067C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    func_800BFB58(rdram, ctx);
        goto after_4;
    // 0x8080067C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    after_4:
    // 0x80800680: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800684:
    // 0x80800684: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800688: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080068C: jr          $ra
    // 0x80800690: nop

    return;
    // 0x80800690: nop

    // 0x80800694: nop

    // 0x80800698: nop

    // 0x8080069C: nop

;}
RECOMP_FUNC void func_800E42F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E42F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800E42F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E42F8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E42FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800E4300: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E4304: beq         $a1, $zero, L_800E4370
    if (ctx->r5 == 0) {
        // 0x800E4308: lw          $s0, 0x4($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X4);
            goto L_800E4370;
    }
    // 0x800E4308: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x800E430C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800E4310: lh          $t7, -0x6648($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6648);
    // 0x800E4314: lui         $a1, 0xC44A
    ctx->r5 = S32(0XC44A << 16);
    // 0x800E4318: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x800E431C: beq         $t7, $zero, L_800E4370
    if (ctx->r15 == 0) {
        // 0x800E4320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E4370;
    }
    // 0x800E4320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E4324: lui         $at, 0x43E4
    ctx->r1 = S32(0X43E4 << 16);
    // 0x800E4328: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E432C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800E4330: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E4334: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800E4338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E433C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E4340: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800E4344: lui         $a2, 0x444A
    ctx->r6 = S32(0X444A << 16);
    // 0x800E4348: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x800E434C: lui         $a3, 0xC3E4
    ctx->r7 = S32(0XC3E4 << 16);
    // 0x800E4350: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800E4354: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800E4358: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800E435C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800E4360: jal         0x8002DE04
    // 0x800E4364: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guOrtho(rdram, ctx);
        goto after_0;
    // 0x800E4364: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800E4368: b           L_800E43BC
    // 0x800E436C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
        goto L_800E43BC;
    // 0x800E436C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_800E4370:
    // 0x800E4370: lui         $at, 0x43E4
    ctx->r1 = S32(0X43E4 << 16);
    // 0x800E4374: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E4378: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800E437C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E4380: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800E4384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E4388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E438C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E4390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E4394: lui         $a1, 0xC418
    ctx->r5 = S32(0XC418 << 16);
    // 0x800E4398: lui         $a2, 0x4418
    ctx->r6 = S32(0X4418 << 16);
    // 0x800E439C: lui         $a3, 0xC3E4
    ctx->r7 = S32(0XC3E4 << 16);
    // 0x800E43A0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800E43A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800E43A8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800E43AC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800E43B0: jal         0x8002DE04
    // 0x800E43B4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    guOrtho(rdram, ctx);
        goto after_1;
    // 0x800E43B4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800E43B8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_800E43BC:
    // 0x800E43BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E43C0: addu        $t9, $s0, $at
    ctx->r25 = ADD32(ctx->r16, ctx->r1);
    // 0x800E43C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E43C8: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800E43CC: ori         $t8, $t8, 0x7
    ctx->r24 = ctx->r24 | 0X7;
    // 0x800E43D0: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x800E43D4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800E43D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800E43DC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E43E0: addiu       $t0, $s0, -0x40
    ctx->r8 = ADD32(ctx->r16, -0X40);
    // 0x800E43E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E43E8: sw          $t0, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r8;
    // 0x800E43EC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800E43F0: jal         0x8002EF3C
    // 0x800E43F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    guMtxIdent(rdram, ctx);
        goto after_2;
    // 0x800E43F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800E43F8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800E43FC: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x800E4400: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E4404: addu        $t2, $s0, $at
    ctx->r10 = ADD32(ctx->r16, ctx->r1);
    // 0x800E4408: ori         $t1, $t1, 0x3
    ctx->r9 = ctx->r9 | 0X3;
    // 0x800E440C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800E4410: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800E4414: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800E4418: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x800E441C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800E4420: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
    // 0x800E4424: sw          $s0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r16;
    // 0x800E4428: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E442C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E4430: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800E4434: jr          $ra
    // 0x800E4438: nop

    return;
    // 0x800E4438: nop

;}
RECOMP_FUNC void func_80802534_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080253C: jal         0x800A3280
    // 0x80802540: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802540: nop

    after_0:
    // 0x80802544: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80802548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080254C: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB02C) << 16);
    // 0x80802550: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802554: lh          $v0, -0x4FD4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(439, 0XB02C));
    // 0x80802558: jr          $ra
    // 0x8080255C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080255C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800A4E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4E9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A4EA0: jal         0x800A3F14
    // 0x800A4EA4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800A3F14(rdram, ctx);
        goto after_0;
    // 0x800A4EA4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x800A4EA8: jal         0x800A4CA8
    // 0x800A4EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4CA8(rdram, ctx);
        goto after_1;
    // 0x800A4EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A4EB0: jal         0x80110BF0
    // 0x800A4EB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110BF0(rdram, ctx);
        goto after_2;
    // 0x800A4EB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A4EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4EC0: jr          $ra
    // 0x800A4EC4: nop

    return;
    // 0x800A4EC4: nop

;}
RECOMP_FUNC void func_80800BCC_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BCC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800BD4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800BD8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800BDC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800BE0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800BE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800BE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800BEC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800BF0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800BF4: jal         0x80100094
    // 0x80800BF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800BF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BFC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800C00: jal         0x80088390
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800C08: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800C0C: bltz        $s1, L_80800C28
    if (SIGNED(ctx->r17) < 0) {
        // 0x80800C10: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_80800C28;
    }
    // 0x80800C10: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80800C14: jal         0x80088390
    // 0x80800C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _gcstatusDll_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80800C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800C1C: bnel        $v0, $s3, L_80800C2C
    if (ctx->r2 != ctx->r19) {
        // 0x80800C20: slti        $at, $s3, 0x4
        ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
            goto L_80800C2C;
    }
    goto skip_0;
    // 0x80800C20: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    skip_0:
    // 0x80800C24: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80800C28:
    // 0x80800C28: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
L_80800C2C:
    // 0x80800C2C: beq         $at, $zero, L_80800C6C
    if (ctx->r1 == 0) {
        // 0x80800C30: addiu       $s1, $s2, 0x14
        ctx->r17 = ADD32(ctx->r18, 0X14);
            goto L_80800C6C;
    }
    // 0x80800C30: addiu       $s1, $s2, 0x14
    ctx->r17 = ADD32(ctx->r18, 0X14);
    // 0x80800C34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800C40: jal         0x800899A0
    // 0x80800C44: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    _sumultiscore_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800C44: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_3:
    // 0x80800C48: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800C4C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C58: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800C5C: jal         0x800899C0
    // 0x80800C60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sumultiscore_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800C60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80800C64: b           L_80800CD8
    // 0x80800C68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80800CD8;
    // 0x80800C68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800C6C:
    // 0x80800C6C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80800C70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800C74: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800C78: blezl       $t6, L_80800CD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800C7C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800CD8;
    }
    goto skip_1;
    // 0x80800C7C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80800C80: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800C84: nop

L_80800C88:
    // 0x80800C88: jal         0x80088390
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_16(rdram, ctx);
        goto after_5;
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800C90: bne         $v0, $s3, L_80800CC0
    if (ctx->r2 != ctx->r19) {
        // 0x80800C94: addiu       $s1, $s2, 0x14
        ctx->r17 = ADD32(ctx->r18, 0X14);
            goto L_80800CC0;
    }
    // 0x80800C94: addiu       $s1, $s2, 0x14
    ctx->r17 = ADD32(ctx->r18, 0X14);
    // 0x80800C98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800CA0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800CA4: jal         0x800899A0
    // 0x80800CA8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    _sumultiscore_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800CA8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_6:
    // 0x80800CAC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800CB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800CB8: jal         0x800899C0
    // 0x80800CBC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sumultiscore_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800CBC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
L_80800CC0:
    // 0x80800CC0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80800CC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800CC8: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800CCC: bne         $at, $zero, L_80800C88
    if (ctx->r1 != 0) {
        // 0x80800CD0: nop
    
            goto L_80800C88;
    }
    // 0x80800CD0: nop

    // 0x80800CD4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800CD8:
    // 0x80800CD8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800CDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CE0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800CE4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800CE8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CEC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800CF0: jr          $ra
    // 0x80800CF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800CF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801740_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080174C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801750: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80801754: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801758: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8080175C: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80801760: beq         $t6, $zero, L_80801784
    if (ctx->r14 == 0) {
        // 0x80801764: addiu       $a1, $zero, 0x2A
        ctx->r5 = ADD32(0, 0X2A);
            goto L_80801784;
    }
    // 0x80801764: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80801768: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080176C: beq         $t6, $at, L_808017D4
    if (ctx->r14 == ctx->r1) {
        // 0x80801770: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808017D4;
    }
    // 0x80801770: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801774: beql        $t6, $at, L_80801798
    if (ctx->r14 == ctx->r1) {
        // 0x80801778: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80801798;
    }
    goto skip_0;
    // 0x80801778: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
    // 0x8080177C: b           L_808017E4
    // 0x80801780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808017E4;
    // 0x80801780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801784:
    // 0x80801784: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80801788: jal         0x800856B0
    // 0x8080178C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080178C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801790: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801794: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80801798:
    // 0x80801798: jal         0x800856E0
    // 0x8080179C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080179C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x808017A0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808017A4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x808017A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808017AC: lhu         $t7, 0x76($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X76);
    // 0x808017B0: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x808017B4: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x808017B8: sh          $t9, 0x76($a3)
    MEM_H(0X76, ctx->r7) = ctx->r25;
    // 0x808017BC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x808017C0: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x808017C4: jal         0x800880A8
    // 0x808017C8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808017C8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    after_2:
    // 0x808017CC: jal         0x800880B8
    // 0x808017D0: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808017D0: nop

    after_3:
L_808017D4:
    // 0x808017D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808017D8: jal         0x800856D8
    // 0x808017DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808017DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808017E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017E4:
    // 0x808017E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017E8: jr          $ra
    // 0x808017EC: nop

    return;
    // 0x808017EC: nop

;}
RECOMP_FUNC void func_800A04F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A04F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A04F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A04FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A0500: jal         0x8008E23C
    // 0x800A0504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E23C(rdram, ctx);
        goto after_0;
    // 0x800A0504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A0508: beq         $v0, $zero, L_800A0530
    if (ctx->r2 == 0) {
        // 0x800A050C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800A0530;
    }
    // 0x800A050C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A0510: jal         0x8008D568
    // 0x800A0514: nop

    func_8008D568(rdram, ctx);
        goto after_1;
    // 0x800A0514: nop

    after_1:
    // 0x800A0518: beq         $v0, $zero, L_800A0528
    if (ctx->r2 == 0) {
        // 0x800A051C: nop
    
            goto L_800A0528;
    }
    // 0x800A051C: nop

    // 0x800A0520: b           L_800A054C
    // 0x800A0524: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
        goto L_800A054C;
    // 0x800A0524: addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
L_800A0528:
    // 0x800A0528: b           L_800A054C
    // 0x800A052C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800A054C;
    // 0x800A052C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800A0530:
    // 0x800A0530: jal         0x8008D694
    // 0x800A0534: nop

    func_8008D694(rdram, ctx);
        goto after_2;
    // 0x800A0534: nop

    after_2:
    // 0x800A0538: beql        $v0, $zero, L_800A054C
    if (ctx->r2 == 0) {
        // 0x800A053C: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_800A054C;
    }
    goto skip_0;
    // 0x800A053C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A0540: b           L_800A054C
    // 0x800A0544: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
        goto L_800A054C;
    // 0x800A0544: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // 0x800A0548: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800A054C:
    // 0x800A054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A0554: jr          $ra
    // 0x800A0558: nop

    return;
    // 0x800A0558: nop

;}
RECOMP_FUNC void func_80800198_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080019C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808001A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A4: beq         $a1, $at, L_808001C0
    if (ctx->r5 == ctx->r1) {
        // 0x808001A8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808001C0;
    }
    // 0x808001A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001AC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808001B0: beq         $a1, $at, L_808001D4
    if (ctx->r5 == ctx->r1) {
        // 0x808001B4: nop
    
            goto L_808001D4;
    }
    // 0x808001B4: nop

    // 0x808001B8: b           L_808001F0
    // 0x808001BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001F0;
    // 0x808001BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001C0:
    // 0x808001C0: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x808001C4: jal         0x80800784
    // 0x808001C8: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800784_chmadamegrunty(rdram, ctx);
        goto after_0;
    // 0x808001C8: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x808001CC: b           L_808001F0
    // 0x808001D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F0;
    // 0x808001D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D4:
    // 0x808001D4: jal         0x80800460
    // 0x808001D8: nop

    func_80800460_chmadamegrunty(rdram, ctx);
        goto after_1;
    // 0x808001D8: nop

    after_1:
    // 0x808001DC: b           L_808001F0
    // 0x808001E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F0;
    // 0x808001E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001E4: b           L_808001F0
    // 0x808001E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001F0;
    // 0x808001E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F0:
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_80802C18_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802C24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802C28: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802C2C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80802C30: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80802C34: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80802C38: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80802C3C: beq         $v0, $zero, L_80802C60
    if (ctx->r2 == 0) {
        // 0x80802C40: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80802C60;
    }
    // 0x80802C40: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80802C44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802C48: beq         $v0, $at, L_80802C68
    if (ctx->r2 == ctx->r1) {
        // 0x80802C4C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802C68;
    }
    // 0x80802C4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802C50: beql        $v0, $at, L_80802C78
    if (ctx->r2 == ctx->r1) {
        // 0x80802C54: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80802C78;
    }
    goto skip_0;
    // 0x80802C54: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802C58: b           L_80802C88
    // 0x80802C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C88;
    // 0x80802C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802C60:
    // 0x80802C60: jal         0x800856B0
    // 0x80802C64: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80802C64: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
L_80802C68:
    // 0x80802C68: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80802C6C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80802C70: sw          $t8, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r24;
    // 0x80802C74: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80802C78:
    // 0x80802C78: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80802C7C: jal         0x800856D0
    // 0x80802C80: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80802C80: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80802C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802C88:
    // 0x80802C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C8C: jr          $ra
    // 0x80802C90: nop

    return;
    // 0x80802C90: nop

;}
RECOMP_FUNC void func_80801E48_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801E4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801E50: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801E54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801E58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801E5C: jal         0x80100094
    // 0x80801E60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801E64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801E68: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801E6C: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_80801E70:
    // 0x80801E70: jal         0x800C8B84
    // 0x80801E74: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x80801E74: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    after_1:
    // 0x80801E78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801E7C: bne         $s0, $s2, L_80801E70
    if (ctx->r16 != ctx->r18) {
        // 0x80801E80: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801E70;
    }
    // 0x80801E80: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801E84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801E88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801E8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801E94: jr          $ra
    // 0x80801E98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801E98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _glglobalsettings_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886F0: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886F0);
    return;
    // 0x800886F4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chterryegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1112, 0X1260) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X1260));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X1260));
;}
RECOMP_FUNC void func_8080047C_chlagoonufoext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800488: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080048C: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800490: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800494: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800498: beq         $t8, $at, L_808004B0
    if (ctx->r24 == ctx->r1) {
        // 0x8080049C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(744, 0X4F0) << 16);
            goto L_808004B0;
    }
    // 0x8080049C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(744, 0X4F0) << 16);
    // 0x808004A0: jal         0x800DF428
    // 0x808004A4: lwc1        $f12, 0x4F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(744, 0X4F0));
    func_800DF428(rdram, ctx);
        goto after_0;
    // 0x808004A4: lwc1        $f12, 0x4F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(744, 0X4F0));
    after_0:
    // 0x808004A8: b           L_808004B8
    // 0x808004AC: nop

        goto L_808004B8;
    // 0x808004AC: nop

L_808004B0:
    // 0x808004B0: jal         0x800DF440
    // 0x808004B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_1;
    // 0x808004B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_808004B8:
    // 0x808004B8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x808004BC: addiu       $a1, $a1, 0x15D0
    ctx->r5 = ADD32(ctx->r5, 0X15D0);
    // 0x808004C0: jal         0x80101808
    // 0x808004C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101808(rdram, ctx);
        goto after_2;
    // 0x808004C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808004C8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808004CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808004D0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x808004D4: jal         0x8008A0E8
    // 0x808004D8: addiu       $a2, $t9, 0x18
    ctx->r6 = ADD32(ctx->r25, 0X18);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808004D8: addiu       $a2, $t9, 0x18
    ctx->r6 = ADD32(ctx->r25, 0X18);
    after_3:
    // 0x808004DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E4: jr          $ra
    // 0x808004E8: nop

    return;
    // 0x808004E8: nop

    // 0x808004EC: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088810: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088810);
    return;
    // 0x80088814: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_800FFC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFC90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FFC94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FFC98: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x800FFC9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FFCA0: jal         0x801067C4
    // 0x800FFCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x800FFCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800FFCA8: beql        $v0, $zero, L_800FFD00
    if (ctx->r2 == 0) {
        // 0x800FFCAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FFD00;
    }
    goto skip_0;
    // 0x800FFCAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800FFCB0: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
L_800FFCB4:
    // 0x800FFCB4: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x800FFCB8: bgez        $t8, L_800FFCEC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800FFCBC: nop
    
            goto L_800FFCEC;
    }
    // 0x800FFCBC: nop

    // 0x800FFCC0: lbu         $t9, 0x70($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X70);
    // 0x800FFCC4: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800FFCC8: beq         $t0, $zero, L_800FFCEC
    if (ctx->r8 == 0) {
        // 0x800FFCCC: nop
    
            goto L_800FFCEC;
    }
    // 0x800FFCCC: nop

    // 0x800FFCD0: lbu         $v1, 0x71($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X71);
    // 0x800FFCD4: srl         $t1, $v1, 7
    ctx->r9 = S32(U32(ctx->r3) >> 7);
    // 0x800FFCD8: xori        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 ^ 0X1;
    // 0x800FFCDC: sll         $t5, $t3, 7
    ctx->r13 = S32(ctx->r11 << 7);
    // 0x800FFCE0: andi        $t6, $v1, 0xFF7F
    ctx->r14 = ctx->r3 & 0XFF7F;
    // 0x800FFCE4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800FFCE8: sb          $t7, 0x71($v0)
    MEM_B(0X71, ctx->r2) = ctx->r15;
L_800FFCEC:
    // 0x800FFCEC: jal         0x8010682C
    // 0x800FFCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x800FFCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800FFCF4: bnel        $v0, $zero, L_800FFCB4
    if (ctx->r2 != 0) {
        // 0x800FFCF8: lw          $t6, 0x7C($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X7C);
            goto L_800FFCB4;
    }
    goto skip_1;
    // 0x800FFCF8: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    skip_1:
    // 0x800FFCFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FFD00:
    // 0x800FFD00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FFD04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FFD08: jr          $ra
    // 0x800FFD0C: nop

    return;
    // 0x800FFD0C: nop

;}
RECOMP_FUNC void func_80800FFC_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FFC: jr          $ra
    // 0x80801000: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801000: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800E817C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E817C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E8180: lw          $t6, -0x2A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A0C);
    // 0x800E8184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E818C: beq         $t6, $zero, L_800E81C0
    if (ctx->r14 == 0) {
        // 0x800E8190: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800E81C0;
    }
    // 0x800E8190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8194: jal         0x800A9800
    // 0x800E8198: nop

    func_800A9800(rdram, ctx);
        goto after_0;
    // 0x800E8198: nop

    after_0:
    // 0x800E819C: jal         0x800E7C28
    // 0x800E81A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E7C28(rdram, ctx);
        goto after_1;
    // 0x800E81A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800E81A4: jal         0x800E7CF4
    // 0x800E81A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E7CF4(rdram, ctx);
        goto after_2;
    // 0x800E81A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800E81AC: jal         0x800E7D4C
    // 0x800E81B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E7D4C(rdram, ctx);
        goto after_3;
    // 0x800E81B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800E81B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E81B8: jal         0x800A8B24
    // 0x800E81BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A8B24(rdram, ctx);
        goto after_4;
    // 0x800E81BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_800E81C0:
    // 0x800E81C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E81C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E81C8: jr          $ra
    // 0x800E81CC: nop

    return;
    // 0x800E81CC: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A228: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A228);
    return;
    // 0x8008A22C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_800F8444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8444: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F844C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8450: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8454: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F8458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F845C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F8460: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x800F8464: jal         0x8009BF5C
    // 0x800F8468: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x800F8468: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F846C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800F8470: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8474: jal         0x8009C914
    // 0x800F8478: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    yaw_setIdeal(rdram, ctx);
        goto after_1;
    // 0x800F8478: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    after_1:
    // 0x800F847C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800F8480: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F8484: jal         0x8009C4CC
    // 0x800F8488: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x800F8488: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    after_2:
    // 0x800F848C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8490: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F8494: jr          $ra
    // 0x800F8498: nop

    return;
    // 0x800F8498: nop

;}
RECOMP_FUNC void func_800A81C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A81C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A81C8: lh          $a0, 0x7640($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7640);
    // 0x800A81CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A81D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A81D4: bne         $a0, $zero, L_800A81E4
    if (ctx->r4 != 0) {
        // 0x800A81D8: nop
    
            goto L_800A81E4;
    }
    // 0x800A81D8: nop

    // 0x800A81DC: b           L_800A8220
    // 0x800A81E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A8220;
    // 0x800A81E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A81E4:
    // 0x800A81E4: jal         0x80088268
    // 0x800A81E8: nop

    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800A81E8: nop

    after_0:
    // 0x800A81EC: jal         0x800EA05C
    // 0x800A81F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x800A81F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A81F4: jal         0x80088268
    // 0x800A81F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x800A81F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A81FC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8200: xor         $v0, $v0, $t6
    ctx->r2 = ctx->r2 ^ ctx->r14;
    // 0x800A8204: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A8208: beql        $v0, $zero, L_800A8224
    if (ctx->r2 == 0) {
        // 0x800A820C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A8224;
    }
    goto skip_0;
    // 0x800A820C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A8210: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8214: lh          $v0, 0x7636($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7636);
    // 0x800A8218: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800A821C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800A8220:
    // 0x800A8220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A8224:
    // 0x800A8224: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A8228: jr          $ra
    // 0x800A822C: nop

    return;
    // 0x800A822C: nop

;}
RECOMP_FUNC void _bschokedie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EA8: syscall     32
    recomp_syscall_handler(rdram, ctx, 0x80082EA8);
    return;
    // 0x80082EAC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800E9F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9F20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E9F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E9F28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E9F2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E9F30: jal         0x800A7180
    // 0x800E9F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800A7180(rdram, ctx);
        goto after_0;
    // 0x800E9F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E9F38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E9F3C: lh          $t6, 0x2DCC($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X2DCC);
    // 0x800E9F40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800E9F44: bne         $t6, $zero, L_800E9F5C
    if (ctx->r14 != 0) {
        // 0x800E9F48: nop
    
            goto L_800E9F5C;
    }
    // 0x800E9F48: nop

    // 0x800E9F4C: jal         0x800E44FC
    // 0x800E9F50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E44FC(rdram, ctx);
        goto after_1;
    // 0x800E9F50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800E9F54: b           L_800EA04C
    // 0x800E9F58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800EA04C;
    // 0x800E9F58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E9F5C:
    // 0x800E9F5C: jal         0x800BE9B0
    // 0x800E9F60: nop

    func_800BE9B0(rdram, ctx);
        goto after_2;
    // 0x800E9F60: nop

    after_2:
    // 0x800E9F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E9F68: jal         0x800BFD6C
    // 0x800E9F6C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800BFD6C(rdram, ctx);
        goto after_3;
    // 0x800E9F6C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x800E9F70: jal         0x800E44FC
    // 0x800E9F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E44FC(rdram, ctx);
        goto after_4;
    // 0x800E9F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800E9F78: jal         0x800D2A44
    // 0x800E9F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D2A44(rdram, ctx);
        goto after_5;
    // 0x800E9F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800E9F80: jal         0x800BC8F8
    // 0x800E9F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BC8F8(rdram, ctx);
        goto after_6;
    // 0x800E9F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800E9F88: jal         0x800BE9E4
    // 0x800E9F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BE9E4(rdram, ctx);
        goto after_7;
    // 0x800E9F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800E9F90: jal         0x800BD594
    // 0x800E9F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BD594(rdram, ctx);
        goto after_8;
    // 0x800E9F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800E9F98: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800E9F9C: jal         0x800EB51C
    // 0x800E9FA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EB51C(rdram, ctx);
        goto after_9;
    // 0x800E9FA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800E9FA4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800E9FA8: jal         0x800EB51C
    // 0x800E9FAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EB51C(rdram, ctx);
        goto after_10;
    // 0x800E9FAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800E9FB0: jal         0x800F5008
    // 0x800E9FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5008(rdram, ctx);
        goto after_11;
    // 0x800E9FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800E9FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E9FBC: jal         0x800EB51C
    // 0x800E9FC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EB51C(rdram, ctx);
        goto after_12;
    // 0x800E9FC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x800E9FC4: jal         0x800B525C
    // 0x800E9FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B525C(rdram, ctx);
        goto after_13;
    // 0x800E9FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800E9FCC: jal         0x800BF3E4
    // 0x800E9FD0: nop

    func_800BF3E4(rdram, ctx);
        goto after_14;
    // 0x800E9FD0: nop

    after_14:
    // 0x800E9FD4: beq         $v0, $zero, L_800E9FE4
    if (ctx->r2 == 0) {
        // 0x800E9FD8: nop
    
            goto L_800E9FE4;
    }
    // 0x800E9FD8: nop

    // 0x800E9FDC: jal         0x800BEA24
    // 0x800E9FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BEA24(rdram, ctx);
        goto after_15;
    // 0x800E9FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_800E9FE4:
    // 0x800E9FE4: jal         0x800B7BB0
    // 0x800E9FE8: nop

    func_800B7BB0(rdram, ctx);
        goto after_16;
    // 0x800E9FE8: nop

    after_16:
    // 0x800E9FEC: jal         0x800F50D0
    // 0x800E9FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F50D0(rdram, ctx);
        goto after_17;
    // 0x800E9FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800E9FF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800E9FF8: jal         0x800EB51C
    // 0x800E9FFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EB51C(rdram, ctx);
        goto after_18;
    // 0x800E9FFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x800EA000: jal         0x800B52EC
    // 0x800EA004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B52EC(rdram, ctx);
        goto after_19;
    // 0x800EA004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800EA008: jal         0x800BC948
    // 0x800EA00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BC948(rdram, ctx);
        goto after_20;
    // 0x800EA00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x800EA010: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800EA014: jal         0x800EB51C
    // 0x800EA018: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EB51C(rdram, ctx);
        goto after_21;
    // 0x800EA018: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_21:
    // 0x800EA01C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800EA020: lw          $t7, 0x7EF4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EF4);
    // 0x800EA024: beql        $t7, $zero, L_800EA038
    if (ctx->r15 == 0) {
        // 0x800EA028: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800EA038;
    }
    goto skip_0;
    // 0x800EA028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800EA02C: jal         0x8008A8F8
    // 0x800EA030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sufade_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x800EA030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x800EA034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800EA038:
    // 0x800EA038: jal         0x800A8EF0
    // 0x800EA03C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800A8EF0(rdram, ctx);
        goto after_23;
    // 0x800EA03C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_23:
    // 0x800EA040: jal         0x800F51CC
    // 0x800EA044: nop

    func_800F51CC(rdram, ctx);
        goto after_24;
    // 0x800EA044: nop

    after_24:
    // 0x800EA048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EA04C:
    // 0x800EA04C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EA050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EA054: jr          $ra
    // 0x800EA058: nop

    return;
    // 0x800EA058: nop

;}
RECOMP_FUNC void chcollballcontrol_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804AF8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1840, 0X50CC) << 16);
    // 0x80804AFC: jr          $ra
    // 0x80804B00: addiu       $v0, $v0, 0x50CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X50CC));
    return;
    // 0x80804B00: addiu       $v0, $v0, 0x50CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X50CC));
    // 0x80804B04: nop

    // 0x80804B08: nop

    // 0x80804B0C: nop

;}
