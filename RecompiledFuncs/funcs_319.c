#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bskazegghead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083420: syscall     61
    recomp_syscall_handler(rdram, ctx, 0x80083420);
    return;
    // 0x80083424: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80115350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115350: jr          $ra
    // 0x80115354: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80115354: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808062A8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808062A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808062AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808062B0: jal         0x80088378
    // 0x808062B4: nop

    _gcstatusDll_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808062B4: nop

    after_0:
    // 0x808062B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808062BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808062C0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x808062C4: jr          $ra
    // 0x808062C8: nop

    return;
    // 0x808062C8: nop

;}
RECOMP_FUNC void func_808001D4_bsbreegullbash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: jal         0x80084508
    // 0x808001E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babackpack_get_state(rdram, ctx);
        goto after_0;
    // 0x808001E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001E8: beq         $v0, $at, L_80800218
    if (ctx->r2 == ctx->r1) {
        // 0x808001EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800218;
    }
    // 0x808001EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: jal         0x80084538
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_1;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800200: jal         0x8009E4E0
    // 0x80800204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009E4E0(rdram, ctx);
        goto after_2;
    // 0x80800204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080020C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800210: jal         0x8009E55C
    // 0x80800214: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_3;
    // 0x80800214: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
L_80800218:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void _gldbDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888B0: syscall     708
    recomp_syscall_handler(rdram, ctx, 0x800888B0);
    return;
    // 0x800888B4: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void subaddiefade_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x8080000C: sb          $a1, 0x9B($a0)
    MEM_B(0X9B, ctx->r4) = ctx->r5;
    // 0x80800010: andi        $t7, $t6, 0xFFFC
    ctx->r15 = ctx->r14 & 0XFFFC;
    // 0x80800014: jr          $ra
    // 0x80800018: sb          $t7, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r15;
    return;
    // 0x80800018: sb          $t7, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80801DC0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801DC8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80801DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801DD0: lw          $v1, 0xA8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XA8);
    // 0x80801DD4: beq         $v1, $at, L_80801DE4
    if (ctx->r3 == ctx->r1) {
        // 0x80801DD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801DE4;
    }
    // 0x80801DD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801DDC: bnel        $v1, $at, L_80801E0C
    if (ctx->r3 != ctx->r1) {
        // 0x80801DE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801E0C;
    }
    goto skip_0;
    // 0x80801DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80801DE4:
    // 0x80801DE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801DE8: jal         0x80801E18
    // 0x80801DEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80801E18_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801DEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801DF0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801DF8: jal         0x80801FD0
    // 0x80801DFC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    func_80801FD0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80801DFC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    after_1:
    // 0x80801E00: jal         0x808023A0
    // 0x80801E04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808023A0_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80801E04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801E0C:
    // 0x80801E0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801E10: jr          $ra
    // 0x80801E14: nop

    return;
    // 0x80801E14: nop

;}
RECOMP_FUNC void func_80800D58_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D60: jal         0x80800030
    // 0x80800D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800030_bsbswim(rdram, ctx);
        goto after_0;
    // 0x80800D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D68: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800D6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800D70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800D74: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800D78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D7C: addiu       $a1, $zero, 0xB9
    ctx->r5 = ADD32(0, 0XB9);
    // 0x80800D80: jal         0x80085150
    // 0x80800D84: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _baspin_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800D84: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D90: jr          $ra
    // 0x80800D94: nop

    return;
    // 0x80800D94: nop

;}
RECOMP_FUNC void _bskazeggass_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083330: syscall     55
    recomp_syscall_handler(rdram, ctx, 0x80083330);
    return;
    // 0x80083334: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: bne         $a1, $at, L_80800044
    if (ctx->r5 != ctx->r1) {
        // 0x80800010: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800044;
    }
    // 0x80800010: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800014: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80800018: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080001C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800020: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80800024: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800028: addiu       $a0, $zero, 0x386
    ctx->r4 = ADD32(0, 0X386);
    // 0x8080002C: addiu       $a2, $zero, -0x5A
    ctx->r6 = ADD32(0, -0X5A);
    // 0x80800030: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80800034: jal         0x80108474
    // 0x80800038: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x80800038: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8080003C: b           L_8080004C
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080004C;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: b           L_8080004C
    // 0x80800048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080004C;
    // 0x80800048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080004C:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_808029D8_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808029DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808029E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808029E4: jal         0x8009E710
    // 0x808029E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x808029E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808029EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808029F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808029F4: jal         0x8009CA70
    // 0x808029F8: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x808029F8: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_1:
    // 0x808029FC: bnel        $v0, $zero, L_80802A3C
    if (ctx->r2 != 0) {
        // 0x80802A00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802A3C;
    }
    goto skip_0;
    // 0x80802A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802A04: jal         0x80085098
    // 0x80802A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80802A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802A0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802A10: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
    // 0x80802A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A18: jal         0x80092880
    // 0x80802A1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092880(rdram, ctx);
        goto after_3;
    // 0x80802A1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80802A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A24: jal         0x800A2018
    // 0x80802A28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A2018(rdram, ctx);
        goto after_4;
    // 0x80802A28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80802A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A30: jal         0x800A4DA4
    // 0x80802A34: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_800A4DA4(rdram, ctx);
        goto after_5;
    // 0x80802A34: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_5:
    // 0x80802A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802A3C:
    // 0x80802A3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802A44: jr          $ra
    // 0x80802A48: nop

    return;
    // 0x80802A48: nop

;}
RECOMP_FUNC void _chtorpedo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872E0: syscall     548
    recomp_syscall_handler(rdram, ctx, 0x800872E0);
    return;
    // 0x800872E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _scinfobar_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5F8: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5F8);
    return;
    // 0x8008A5FC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _ncbadolly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089358: syscall     775
    recomp_syscall_handler(rdram, ctx, 0x80089358);
    return;
    // 0x8008935C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800E2568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2568: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E256C: addiu       $v0, $v0, -0x2B90
    ctx->r2 = ADD32(ctx->r2, -0X2B90);
    // 0x800E2570: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x800E2574: jr          $ra
    // 0x800E2578: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    return;
    // 0x800E2578: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void susplinet_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808001AC: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808001B0: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x808001B4: nop

    // 0x808001B8: bc1fl       L_80800204
    if (!c1cs) {
        // 0x808001BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808001C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001C4: jal         0x800D8FF8
    // 0x808001C8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001C8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808001CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808001D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001D8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808001DC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808001E0: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x808001E4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808001E8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x808001EC: nop

    // 0x808001F0: bc1fl       L_80800204
    if (!c1cs) {
        // 0x808001F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800204;
    }
    goto skip_1;
    // 0x808001F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808001F8: b           L_80800204
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800204:
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void func_80803700_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80803704: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803708: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080370C: jal         0x800D8FF8
    // 0x80803710: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80803710: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80803714: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80803718: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080371C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803720: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80803724: beq         $t6, $at, L_8080374C
    if (ctx->r14 == ctx->r1) {
        // 0x80803728: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080374C;
    }
    // 0x80803728: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080372C: beq         $t6, $at, L_8080376C
    if (ctx->r14 == ctx->r1) {
        // 0x80803730: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080376C;
    }
    // 0x80803730: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803734: beq         $t6, $at, L_80803828
    if (ctx->r14 == ctx->r1) {
        // 0x80803738: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80803828;
    }
    // 0x80803738: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080373C: beql        $t6, $at, L_8080384C
    if (ctx->r14 == ctx->r1) {
        // 0x80803740: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8080384C;
    }
    goto skip_0;
    // 0x80803740: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_0:
    // 0x80803744: b           L_80803908
    // 0x80803748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803908;
    // 0x80803748: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080374C:
    // 0x8080374C: jal         0x800DA298
    // 0x80803750: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80803750: addiu       $a0, $zero, 0xA33
    ctx->r4 = ADD32(0, 0XA33);
    after_1:
    // 0x80803754: beq         $v0, $zero, L_80803904
    if (ctx->r2 == 0) {
        // 0x80803758: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803904;
    }
    // 0x80803758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080375C: jal         0x8080362C
    // 0x80803760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080362C_chevilmumbo(rdram, ctx);
        goto after_2;
    // 0x80803760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80803764: b           L_80803908
    // 0x80803768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803908;
    // 0x80803768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080376C:
    // 0x8080376C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80803770: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803774: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803778: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080377C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80803780: nop

    // 0x80803784: bc1fl       L_808037E4
    if (!c1cs) {
        // 0x80803788: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_808037E4;
    }
    goto skip_1;
    // 0x80803788: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x8080378C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803790: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803794: jal         0x800F10B4
    // 0x80803798: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80803798: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8080379C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808037A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808037A4: jal         0x800EFA20
    // 0x808037A8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x808037A8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_4:
    // 0x808037AC: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808037B0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808037B4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4538) << 16);
    // 0x808037B8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X4234) << 16);
    // 0x808037BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808037C0: addiu       $a3, $a3, 0x4234
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X4234));
    // 0x808037C4: addiu       $a1, $a1, 0x4538
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4538));
    // 0x808037C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037CC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808037D0: jal         0x80089D50
    // 0x808037D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808037D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x808037D8: b           L_80803908
    // 0x808037DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803908;
    // 0x808037DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808037E0: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_808037E4:
    // 0x808037E4: lui         $a0, 0x6651
    ctx->r4 = S32(0X6651 << 16);
    // 0x808037E8: ori         $a0, $a0, 0x94CC
    ctx->r4 = ctx->r4 | 0X94CC;
    // 0x808037EC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x808037F0: bgez        $t9, L_80803814
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808037F4: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1676, 0X4538) << 16);
            goto L_80803814;
    }
    // 0x808037F4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4538) << 16);
    // 0x808037F8: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x808037FC: ori         $a2, $a2, 0x9C4
    ctx->r6 = ctx->r6 | 0X9C4;
    // 0x80803800: jal         0x800C4140
    // 0x80803804: addiu       $a1, $a1, 0x4538
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4538));
    func_800C4140(rdram, ctx);
        goto after_6;
    // 0x80803804: addiu       $a1, $a1, 0x4538
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4538));
    after_6:
    // 0x80803808: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080380C: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80803810: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80803814:
    // 0x80803814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803818: jal         0x8080362C
    // 0x8080381C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080362C_chevilmumbo(rdram, ctx);
        goto after_7;
    // 0x8080381C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80803820: b           L_80803908
    // 0x80803824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803908;
    // 0x80803824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803828:
    // 0x80803828: jal         0x800DA298
    // 0x8080382C: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x8080382C: addiu       $a0, $zero, 0xA32
    ctx->r4 = ADD32(0, 0XA32);
    after_8:
    // 0x80803830: beq         $v0, $zero, L_80803904
    if (ctx->r2 == 0) {
        // 0x80803834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803904;
    }
    // 0x80803834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803838: jal         0x8080362C
    // 0x8080383C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080362C_chevilmumbo(rdram, ctx);
        goto after_9;
    // 0x8080383C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80803840: b           L_80803908
    // 0x80803844: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803908;
    // 0x80803844: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803848: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8080384C:
    // 0x8080384C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803850: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803854: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803858: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8080385C: nop

    // 0x80803860: bc1fl       L_808038C8
    if (!c1cs) {
        // 0x80803864: lw          $t2, 0x64($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X64);
            goto L_808038C8;
    }
    goto skip_2;
    // 0x80803864: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x80803868: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080386C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803870: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803874: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80803878: jal         0x800F10B4
    // 0x8080387C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x8080387C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x80803880: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803884: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803888: jal         0x800EFA20
    // 0x8080388C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EFA20(rdram, ctx);
        goto after_11;
    // 0x8080388C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_11:
    // 0x80803890: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803894: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80803898: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4538) << 16);
    // 0x8080389C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X4234) << 16);
    // 0x808038A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808038A4: addiu       $a3, $a3, 0x4234
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X4234));
    // 0x808038A8: addiu       $a1, $a1, 0x4538
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4538));
    // 0x808038AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038B0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808038B4: jal         0x80089D50
    // 0x808038B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x808038B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x808038BC: b           L_80803908
    // 0x808038C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803908;
    // 0x808038C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808038C4: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
L_808038C8:
    // 0x808038C8: lui         $a0, 0x7FEB
    ctx->r4 = S32(0X7FEB << 16);
    // 0x808038CC: ori         $a0, $a0, 0xBCCC
    ctx->r4 = ctx->r4 | 0XBCCC;
    // 0x808038D0: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x808038D4: bgez        $t4, L_808038F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808038D8: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1676, 0X4538) << 16);
            goto L_808038F8;
    }
    // 0x808038D8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X4538) << 16);
    // 0x808038DC: lui         $a2, 0x1388
    ctx->r6 = S32(0X1388 << 16);
    // 0x808038E0: ori         $a2, $a2, 0x9C4
    ctx->r6 = ctx->r6 | 0X9C4;
    // 0x808038E4: jal         0x800C4140
    // 0x808038E8: addiu       $a1, $a1, 0x4538
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4538));
    func_800C4140(rdram, ctx);
        goto after_13;
    // 0x808038E8: addiu       $a1, $a1, 0x4538
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X4538));
    after_13:
    // 0x808038EC: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x808038F0: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x808038F4: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_808038F8:
    // 0x808038F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038FC: jal         0x8080362C
    // 0x80803900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080362C_chevilmumbo(rdram, ctx);
        goto after_14;
    // 0x80803900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_80803904:
    // 0x80803904: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803908:
    // 0x80803908: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080390C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80803910: jr          $ra
    // 0x80803914: nop

    return;
    // 0x80803914: nop

;}
RECOMP_FUNC void func_8011797C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011797C: andi        $t0, $s5, 0x7
    ctx->r8 = ctx->r21 & 0X7;
    // 0x80117980: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x80117984: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x80117988: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8011798C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80117990: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x80117994: beq         $at, $zero, L_801179A4
    if (ctx->r1 == 0) {
        // 0x80117998: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_801179A4;
    }
    // 0x80117998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011799C: jal         0x80116F30
    // 0x801179A0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_0;
    // 0x801179A0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_0:
L_801179A4:
    // 0x801179A4: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x801179A8: andi        $t1, $s6, 0xFFFF
    ctx->r9 = ctx->r22 & 0XFFFF;
    // 0x801179AC: sltu        $at, $s5, $t0
    ctx->r1 = ctx->r21 < ctx->r8 ? 1 : 0;
    // 0x801179B0: beq         $at, $zero, L_801179C0
    if (ctx->r1 == 0) {
        // 0x801179B4: srlv        $s6, $s6, $t0
        ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
            goto L_801179C0;
    }
    // 0x801179B4: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x801179B8: jal         0x80116F30
    // 0x801179BC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80116F30(rdram, ctx);
        goto after_1;
    // 0x801179BC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_1:
L_801179C0:
    // 0x801179C0: srlv        $s6, $s6, $t0
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r8 & 31));
    // 0x801179C4: sub         $s5, $s5, $t0
    ctx->r21 = SUB32(ctx->r21, ctx->r8);
    // 0x801179C8: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
L_801179CC:
    // 0x801179CC: sltu        $at, $s5, $t3
    ctx->r1 = ctx->r21 < ctx->r11 ? 1 : 0;
    // 0x801179D0: beql        $at, $zero, L_801179E4
    if (ctx->r1 == 0) {
        // 0x801179D4: sb          $s6, 0x0($s7)
        MEM_B(0X0, ctx->r23) = ctx->r22;
            goto L_801179E4;
    }
    goto skip_0;
    // 0x801179D4: sb          $s6, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r22;
    skip_0:
    // 0x801179D8: jal         0x80116F30
    // 0x801179DC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    func_80116F30(rdram, ctx);
        goto after_2;
    // 0x801179DC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_2:
    // 0x801179E0: sb          $s6, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r22;
L_801179E4:
    // 0x801179E4: addi        $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x801179E8: srlv        $s6, $s6, $t3
    ctx->r22 = S32(U32(ctx->r22) >> (ctx->r11 & 31));
    // 0x801179EC: sub         $s5, $s5, $t3
    ctx->r21 = SUB32(ctx->r21, ctx->r11);
    // 0x801179F0: bne         $t1, $zero, L_801179CC
    if (ctx->r9 != 0) {
        // 0x801179F4: addi        $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_801179CC;
    }
    // 0x801179F4: addi        $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x801179F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801179FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80117A00: jr          $ra
    // 0x80117A04: nop

    return;
    // 0x80117A04: nop

;}
RECOMP_FUNC void func_800C3EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3EB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3EBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3EC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C3EC4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800C3EC8: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    // 0x800C3ECC: jal         0x800C2840
    // 0x800C3ED0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C2840(rdram, ctx);
        goto after_0;
    // 0x800C3ED0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C3ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3EDC: jr          $ra
    // 0x800C3EE0: nop

    return;
    // 0x800C3EE0: nop

;}
RECOMP_FUNC void func_801021BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801021BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801021C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801021C4: jal         0x80102394
    // 0x801021C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80102394(rdram, ctx);
        goto after_0;
    // 0x801021C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801021CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801021D0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x801021D4: beq         $t6, $zero, L_801021F4
    if (ctx->r14 == 0) {
        // 0x801021D8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_801021F4;
    }
    // 0x801021D8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x801021DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801021E0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801021E4: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x801021E8: lhu         $v0, 0x4($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X4);
    // 0x801021EC: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x801021F0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_801021F4:
    // 0x801021F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801021F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801021FC: jr          $ra
    // 0x80102200: nop

    return;
    // 0x80102200: nop

;}
RECOMP_FUNC void func_80095C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095C18: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80095C1C: jal         0x800C5BA4
    // 0x80095C20: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C5BA4(rdram, ctx);
        goto after_0;
    // 0x80095C20: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80095C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095C2C: jr          $ra
    // 0x80095C30: nop

    return;
    // 0x80095C30: nop

;}
RECOMP_FUNC void func_800D21D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D21D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D21D4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800D21D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D21DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D21E0: addiu       $t8, $t8, -0x5050
    ctx->r24 = ADD32(ctx->r24, -0X5050);
    // 0x800D21E4: addiu       $t7, $t6, -0x900
    ctx->r15 = ADD32(ctx->r14, -0X900);
    // 0x800D21E8: jr          $ra
    // 0x800D21EC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x800D21EC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_800D2574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2574: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D2578: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800D257C: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x800D2580: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x800D2584: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x800D2588: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x800D258C: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x800D2590: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x800D2594: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x800D2598: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800D259C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x800D25A0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800D25A4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800D25A8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800D25AC: jal         0x800D8FF8
    // 0x800D25B0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800D25B0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800D25B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800D25B8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800D25BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D25C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800D25C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800D25C8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800D25CC: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800D25D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800D25D4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800D25D8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800D25DC: addiu       $s6, $s6, -0x4D40
    ctx->r22 = ADD32(ctx->r22, -0X4D40);
    // 0x800D25E0: addiu       $s1, $s1, -0x5050
    ctx->r17 = ADD32(ctx->r17, -0X5050);
    // 0x800D25E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D25E8: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x800D25EC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800D25F0: addiu       $s4, $zero, 0x5B
    ctx->r20 = ADD32(0, 0X5B);
L_800D25F4:
    // 0x800D25F4: addiu       $s3, $s2, 0xC0
    ctx->r19 = ADD32(ctx->r18, 0XC0);
    // 0x800D25F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D25FC: jal         0x800D21F0
    // 0x800D2600: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    func_800D21F0(rdram, ctx);
        goto after_1;
    // 0x800D2600: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    after_1:
    // 0x800D2604: bltz        $v0, L_800D26FC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D2608: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D26FC;
    }
    // 0x800D2608: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D260C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2610: jal         0x800FA8E8
    // 0x800D2614: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    func_800FA8E8(rdram, ctx);
        goto after_2;
    // 0x800D2614: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    after_2:
    // 0x800D2618: beq         $v0, $s5, L_800D2630
    if (ctx->r2 == ctx->r21) {
        // 0x800D261C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D2630;
    }
    // 0x800D261C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D2620: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x800D2624: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x800D2628: b           L_800D26FC
    // 0x800D262C: sh          $s7, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r23;
        goto L_800D26FC;
    // 0x800D262C: sh          $s7, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r23;
L_800D2630:
    // 0x800D2630: jal         0x800FA874
    // 0x800D2634: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    func_800FA874(rdram, ctx);
        goto after_3;
    // 0x800D2634: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    after_3:
    // 0x800D2638: beql        $v0, $zero, L_800D2700
    if (ctx->r2 == 0) {
        // 0x800D263C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800D2700;
    }
    goto skip_0;
    // 0x800D263C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800D2640: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800D2644: lh          $v0, 0x4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4);
    // 0x800D2648: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800D264C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800D2650: nop

    // 0x800D2654: beql        $v0, $t9, L_800D2700
    if (ctx->r2 == ctx->r25) {
        // 0x800D2658: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800D2700;
    }
    goto skip_1;
    // 0x800D2658: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800D265C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D2660: nop

    // 0x800D2664: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D2668: sub.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800D266C: c.le.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl <= ctx->f0.fl;
    // 0x800D2670: nop

    // 0x800D2674: bc1fl       L_800D2688
    if (!c1cs) {
        // 0x800D2678: mov.s       $f14, $f28
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
            goto L_800D2688;
    }
    goto skip_2;
    // 0x800D2678: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    skip_2:
    // 0x800D267C: b           L_800D2688
    // 0x800D2680: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
        goto L_800D2688;
    // 0x800D2680: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x800D2684: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
L_800D2688:
    // 0x800D2688: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800D268C: nop

    // 0x800D2690: bc1fl       L_800D26A4
    if (!c1cs) {
        // 0x800D2694: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800D26A4;
    }
    goto skip_3;
    // 0x800D2694: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_3:
    // 0x800D2698: b           L_800D26A4
    // 0x800D269C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
        goto L_800D26A4;
    // 0x800D269C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800D26A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800D26A4:
    // 0x800D26A4: mul.s       $f10, $f2, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800D26A8: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x800D26AC: nop

    // 0x800D26B0: bc1fl       L_800D26C4
    if (!c1cs) {
        // 0x800D26B4: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_800D26C4;
    }
    goto skip_4;
    // 0x800D26B4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_4:
    // 0x800D26B8: b           L_800D26E4
    // 0x800D26BC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
        goto L_800D26E4;
    // 0x800D26BC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x800D26C0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_800D26C4:
    // 0x800D26C4: nop

    // 0x800D26C8: bc1fl       L_800D26DC
    if (!c1cs) {
        // 0x800D26CC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800D26DC;
    }
    goto skip_5;
    // 0x800D26CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_5:
    // 0x800D26D0: b           L_800D26DC
    // 0x800D26D4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
        goto L_800D26DC;
    // 0x800D26D4: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800D26D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800D26DC:
    // 0x800D26DC: mul.s       $f0, $f2, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800D26E0: nop

L_800D26E4:
    // 0x800D26E4: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D26E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D26EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D26F0: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800D26F4: jal         0x800D22E0
    // 0x800D26F8: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    func_800D22E0(rdram, ctx);
        goto after_4;
    // 0x800D26F8: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
    after_4:
L_800D26FC:
    // 0x800D26FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D2700:
    // 0x800D2700: bne         $s2, $s4, L_800D25F4
    if (ctx->r18 != ctx->r20) {
        // 0x800D2704: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800D25F4;
    }
    // 0x800D2704: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800D2708: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800D270C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800D2710: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800D2714: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800D2718: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800D271C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x800D2720: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800D2724: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800D2728: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x800D272C: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x800D2730: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800D2734: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x800D2738: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x800D273C: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x800D2740: jr          $ra
    // 0x800D2744: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D2744: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_808001A8_chbigterrysbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: beq         $a1, $at, L_808001D0
    if (ctx->r5 == ctx->r1) {
        // 0x808001B8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808001D0;
    }
    // 0x808001B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001BC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808001C0: beq         $a1, $at, L_80800200
    if (ctx->r5 == ctx->r1) {
        // 0x808001C4: nop
    
            goto L_80800200;
    }
    // 0x808001C4: nop

    // 0x808001C8: b           L_8080021C
    // 0x808001CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080021C;
    // 0x808001CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001D0:
    // 0x808001D0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: jal         0x8008A4B8
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001DC: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800218;
    }
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E4: jal         0x80103110
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: jal         0x80101FDC
    // 0x808001F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808001F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808001F8: b           L_8080021C
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080021C;
    // 0x808001FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800200:
    // 0x80800200: jal         0x8080022C
    // 0x80800204: nop

    func_8080022C_chbigterrysbits(rdram, ctx);
        goto after_3;
    // 0x80800204: nop

    after_3:
    // 0x80800208: b           L_8080021C
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080021C;
    // 0x8080020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800210: b           L_8080021C
    // 0x80800214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080021C;
    // 0x80800214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800218:
    // 0x80800218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080021C:
    // 0x8080021C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

;}
RECOMP_FUNC void func_808000C4_chfantasydrillfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x808000C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x808000D0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808000D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808000D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000E0: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    // 0x808000E4: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x808000E8: jal         0x800882C0
    // 0x808000EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x808000EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x808000F0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x808000F4: blez        $v0, L_8080013C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000F8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8080013C;
    }
    // 0x808000F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808000FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2348, 0XA10) << 16);
    // 0x80800100: addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
    // 0x80800104: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80800108: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    // 0x8080010C: addiu       $a3, $a3, 0xA10
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2348, 0XA10));
    // 0x80800110: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_80800114:
    // 0x80800114: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80800118: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080011C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80800120: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80800124: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80800128: sw          $s3, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r19;
    // 0x8080012C: srl         $t3, $t9, 21
    ctx->r11 = S32(U32(ctx->r25) >> 21);
    // 0x80800130: bne         $at, $zero, L_80800114
    if (ctx->r1 != 0) {
        // 0x80800134: sw          $t3, -0x8($a3)
        MEM_W(-0X8, ctx->r7) = ctx->r11;
            goto L_80800114;
    }
    // 0x80800134: sw          $t3, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->r11;
    // 0x80800138: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8080013C:
    // 0x8080013C: blez        $v0, L_80800240
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800140: addiu       $s3, $zero, -0x1
        ctx->r19 = ADD32(0, -0X1);
            goto L_80800240;
    }
    // 0x80800140: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_80800144:
    // 0x80800144: blez        $v0, L_80800230
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800148: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80800230;
    }
    // 0x80800148: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8080014C: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2348, 0XA10) << 16);
    // 0x80800150: addiu       $t5, $t5, 0xA10
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2348, 0XA10));
    // 0x80800154: sll         $t4, $s2, 3
    ctx->r12 = S32(ctx->r18 << 3);
    // 0x80800158: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8080015C: beq         $v1, $zero, L_8080019C
    if (ctx->r3 == 0) {
        // 0x80800160: addu        $a3, $t4, $t5
        ctx->r7 = ADD32(ctx->r12, ctx->r13);
            goto L_8080019C;
    }
    // 0x80800160: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x80800164: sll         $t7, $zero, 3
    ctx->r15 = S32(0 << 3);
    // 0x80800168: addu        $a1, $t7, $t5
    ctx->r5 = ADD32(ctx->r15, ctx->r13);
    // 0x8080016C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80800170:
    // 0x80800170: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800174: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80800178: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8080017C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800180: beq         $at, $zero, L_80800190
    if (ctx->r1 == 0) {
        // 0x80800184: nop
    
            goto L_80800190;
    }
    // 0x80800184: nop

    // 0x80800188: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8080018C: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_80800190:
    // 0x80800190: bne         $t1, $t0, L_80800170
    if (ctx->r9 != ctx->r8) {
        // 0x80800194: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80800170;
    }
    // 0x80800194: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80800198: beq         $t0, $v0, L_80800230
    if (ctx->r8 == ctx->r2) {
        // 0x8080019C: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(2348, 0XA10) << 16);
            goto L_80800230;
    }
L_8080019C:
    // 0x8080019C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2348, 0XA10) << 16);
    // 0x808001A0: addiu       $t8, $t8, 0xA10
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2348, 0XA10));
    // 0x808001A4: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x808001A8: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x808001AC: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x808001B0: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x808001B4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_808001B8:
    // 0x808001B8: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x808001BC: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808001C0: beql        $at, $zero, L_808001D8
    if (ctx->r1 == 0) {
        // 0x808001C4: lw          $a2, 0x8($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X8);
            goto L_808001D8;
    }
    goto skip_0;
    // 0x808001C4: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x808001C8: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x808001CC: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x808001D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808001D4: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
L_808001D8:
    // 0x808001D8: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808001DC: beql        $at, $zero, L_808001F4
    if (ctx->r1 == 0) {
        // 0x808001E0: lw          $a2, 0x10($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X10);
            goto L_808001F4;
    }
    goto skip_1;
    // 0x808001E0: lw          $a2, 0x10($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X10);
    skip_1:
    // 0x808001E4: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // 0x808001E8: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x808001EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808001F0: lw          $a2, 0x10($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X10);
L_808001F4:
    // 0x808001F4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808001F8: beql        $at, $zero, L_80800210
    if (ctx->r1 == 0) {
        // 0x808001FC: lw          $a2, 0x18($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X18);
            goto L_80800210;
    }
    goto skip_2;
    // 0x808001FC: lw          $a2, 0x18($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X18);
    skip_2:
    // 0x80800200: sw          $a0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r4;
    // 0x80800204: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80800208: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080020C: lw          $a2, 0x18($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X18);
L_80800210:
    // 0x80800210: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800214: beql        $at, $zero, L_80800228
    if (ctx->r1 == 0) {
        // 0x80800218: addiu       $a1, $a1, 0x20
        ctx->r5 = ADD32(ctx->r5, 0X20);
            goto L_80800228;
    }
    goto skip_3;
    // 0x80800218: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    skip_3:
    // 0x8080021C: sw          $a0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r4;
    // 0x80800220: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80800224: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
L_80800228:
    // 0x80800228: bnel        $a1, $t1, L_808001B8
    if (ctx->r5 != ctx->r9) {
        // 0x8080022C: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_808001B8;
    }
    goto skip_4;
    // 0x8080022C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_4:
L_80800230:
    // 0x80800230: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800234: bne         $s2, $t2, L_80800144
    if (ctx->r18 != ctx->r10) {
        // 0x80800238: nop
    
            goto L_80800144;
    }
    // 0x80800238: nop

    // 0x8080023C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800240:
    // 0x80800240: jal         0x800DA298
    // 0x80800244: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800244: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    after_1:
    // 0x80800248: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x8080024C: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_80800290;
    }
    // 0x8080024C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80800250: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80800254: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080025C: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
L_80800260:
    // 0x80800260: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80800264: addiu       $a0, $s0, 0x1DD
    ctx->r4 = ADD32(ctx->r16, 0X1DD);
    // 0x80800268: jal         0x800DA298
    // 0x8080026C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080026C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800270: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80800274: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800278: or          $s1, $v0, $s1
    ctx->r17 = ctx->r2 | ctx->r17;
    // 0x8080027C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800280: bnel        $at, $zero, L_80800260
    if (ctx->r1 != 0) {
        // 0x80800284: sll         $t3, $s1, 1
        ctx->r11 = S32(ctx->r17 << 1);
            goto L_80800260;
    }
    goto skip_5;
    // 0x80800284: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    skip_5:
    // 0x80800288: b           L_808002DC
    // 0x8080028C: nop

        goto L_808002DC;
    // 0x8080028C: nop

L_80800290:
    // 0x80800290: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x80800294: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800298: jal         0x800DC128
    // 0x8080029C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x8080029C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x808002A0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002A8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
L_808002AC:
    // 0x808002AC: subu        $t5, $t7, $s0
    ctx->r13 = SUB32(ctx->r15, ctx->r16);
    // 0x808002B0: srav        $a1, $s1, $t5
    ctx->r5 = S32(SIGNED(ctx->r17) >> (ctx->r13 & 31));
    // 0x808002B4: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x808002B8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x808002BC: jal         0x800DA3B8
    // 0x808002C0: addiu       $a0, $s0, 0x1DD
    ctx->r4 = ADD32(ctx->r16, 0X1DD);
    func_800DA3B8(rdram, ctx);
        goto after_4;
    // 0x808002C0: addiu       $a0, $s0, 0x1DD
    ctx->r4 = ADD32(ctx->r16, 0X1DD);
    after_4:
    // 0x808002C4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x808002C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808002CC: bnel        $s0, $t9, L_808002AC
    if (ctx->r16 != ctx->r25) {
        // 0x808002D0: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_808002AC;
    }
    goto skip_6;
    // 0x808002D0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    skip_6:
    // 0x808002D4: jal         0x800DA544
    // 0x808002D8: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808002D8: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    after_5:
L_808002DC:
    // 0x808002DC: jal         0x800DC090
    // 0x808002E0: nop

    func_800DC090(rdram, ctx);
        goto after_6;
    // 0x808002E0: nop

    after_6:
    // 0x808002E4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x808002E8: jal         0x800DC324
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800DC324(rdram, ctx);
        goto after_7;
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x808002F0: jal         0x80800360
    // 0x808002F4: nop

    func_80800360_chfantasydrillfield(rdram, ctx);
        goto after_8;
    // 0x808002F4: nop

    after_8:
    // 0x808002F8: bne         $v0, $zero, L_8080033C
    if (ctx->r2 != 0) {
        // 0x808002FC: lui         $s0, 0x8080
        ctx->r16 = S32(RELOC_HI16(2348, 0XA10) << 16);
            goto L_8080033C;
    }
    // 0x808002FC: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2348, 0XA10) << 16);
    // 0x80800300: addiu       $s0, $s0, 0xA10
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2348, 0XA10));
    // 0x80800304: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800308:
    // 0x80800308: jal         0x800DC128
    // 0x8080030C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800DC128(rdram, ctx);
        goto after_9;
    // 0x8080030C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x80800310: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80800314: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x80800318: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8080031C: bne         $s3, $t3, L_8080032C
    if (ctx->r19 != ctx->r11) {
        // 0x80800320: nop
    
            goto L_8080032C;
    }
    // 0x80800320: nop

    // 0x80800324: sw          $s2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r18;
    // 0x80800328: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080032C:
    // 0x8080032C: jal         0x80800360
    // 0x80800330: nop

    func_80800360_chfantasydrillfield(rdram, ctx);
        goto after_10;
    // 0x80800330: nop

    after_10:
    // 0x80800334: beql        $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x80800338: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800308;
    }
    goto skip_7;
    // 0x80800338: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_7:
L_8080033C:
    // 0x8080033C: jal         0x800DC324
    // 0x80800340: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_800DC324(rdram, ctx);
        goto after_11;
    // 0x80800340: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_11:
    // 0x80800344: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800348: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800350: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800354: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800358: jr          $ra
    // 0x8080035C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8080035C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_808023D8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808023DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808023E0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808023E4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808023E8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808023EC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808023F0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808023F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808023F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808023FC: jal         0x80100094
    // 0x80802400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802404: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80802408: jal         0x80800200
    // 0x8080240C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80800200_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x8080240C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80802410: jal         0x80803E84
    // 0x80802414: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80803E84_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80802414: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x80802418: jal         0x808047A8
    // 0x8080241C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808047A8_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x8080241C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80802420: jal         0x80804D44
    // 0x80802424: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80804D44_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80802424: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80802428: jal         0x80808034
    // 0x8080242C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80808034_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x8080242C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x80802430: jal         0x808088CC
    // 0x80802434: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808088CC_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80802434: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x80802438: jal         0x80808CD0
    // 0x8080243C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80808CD0_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x8080243C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x80802440: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80802444: addiu       $s5, $s4, 0x4
    ctx->r21 = ADD32(ctx->r20, 0X4);
    // 0x80802448: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0X9F04) << 16);
    // 0x8080244C: addiu       $a3, $a3, -0x60FC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0X9F04));
    // 0x80802450: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80802454: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802458: jal         0x80089D50
    // 0x8080245C: lbu         $a2, 0x7($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X7);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x8080245C: lbu         $a2, 0x7($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X7);
    after_8:
    // 0x80802460: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80802464: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80802468: lbu         $t8, 0x7($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X7);
    // 0x8080246C: beq         $t8, $zero, L_8080247C
    if (ctx->r24 == 0) {
        // 0x80802470: nop
    
            goto L_8080247C;
    }
    // 0x80802470: nop

    // 0x80802474: jal         0x8008A4C8
    // 0x80802478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x80802478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
L_8080247C:
    // 0x8080247C: lui         $s2, 0x8081
    ctx->r18 = S32(RELOC_HI16(1480, 0X9F1C) << 16);
    // 0x80802480: lui         $s1, 0x8081
    ctx->r17 = S32(RELOC_HI16(1480, 0X9F10) << 16);
    // 0x80802484: addiu       $s1, $s1, -0x60F0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1480, 0X9F10));
    // 0x80802488: addiu       $s2, $s2, -0x60E4
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1480, 0X9F1C));
    // 0x8080248C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802490: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_80802494:
    // 0x80802494: jal         0x800F6438
    // 0x80802498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_10;
    // 0x80802498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080249C: beq         $v0, $zero, L_808024B8
    if (ctx->r2 == 0) {
        // 0x808024A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808024B8;
    }
    // 0x808024A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024A4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808024A8: addiu       $a2, $s4, 0x44
    ctx->r6 = ADD32(ctx->r20, 0X44);
    // 0x808024AC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808024B0: jal         0x800F4E5C
    // 0x808024B4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800F4E5C(rdram, ctx);
        goto after_11;
    // 0x808024B4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_11:
L_808024B8:
    // 0x808024B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808024BC: bne         $s0, $s3, L_80802494
    if (ctx->r16 != ctx->r19) {
        // 0x808024C0: nop
    
            goto L_80802494;
    }
    // 0x808024C0: nop

    // 0x808024C4: lw          $t9, 0x3C($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X3C);
    // 0x808024C8: beql        $t9, $zero, L_808024F4
    if (ctx->r25 == 0) {
        // 0x808024CC: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_808024F4;
    }
    goto skip_0;
    // 0x808024CC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x808024D0: jal         0x808026F8
    // 0x808024D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_808026F8_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x808024D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x808024D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808024DC: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808024E0: jal         0x800EE7F8
    // 0x808024E4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x808024E4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_13:
    // 0x808024E8: lwc1        $f4, 0x48($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X48);
    // 0x808024EC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x808024F0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808024F4:
    // 0x808024F4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x808024F8: beql        $a0, $zero, L_80802530
    if (ctx->r4 == 0) {
        // 0x808024FC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80802530;
    }
    goto skip_1;
    // 0x808024FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80802500: jal         0x80106790
    // 0x80802504: nop

    func_80106790(rdram, ctx);
        goto after_14;
    // 0x80802504: nop

    after_14:
    // 0x80802508: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080250C: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80802510: jal         0x800EE7F8
    // 0x80802514: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80802514: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_15:
    // 0x80802518: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080251C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802520: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80802524: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80802528: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8080252C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80802530:
    // 0x80802530: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80802534: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80802538: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080253C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80802540: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80802544: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80802548: jr          $ra
    // 0x8080254C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080254C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsbtrot_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A88: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801A8C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2EA0) << 16);
    // 0x80801A90: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801A94: jr          $ra
    // 0x80801A98: lw          $v0, 0x2EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EA0));
    return;
    // 0x80801A98: lw          $v0, 0x2EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EA0));
;}
RECOMP_FUNC void _bskazstill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083608: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083608);
    return;
    // 0x8008360C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_801075E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801075E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801075E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801075EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801075F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801075F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801075F8: jal         0x80100368
    // 0x801075FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x801075FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80107600: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80107604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107608: jal         0x8010754C
    // 0x8010760C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8010754C(rdram, ctx);
        goto after_1;
    // 0x8010760C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80107610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107614: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80107618: jal         0x801073F8
    // 0x8010761C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_801073F8(rdram, ctx);
        goto after_2;
    // 0x8010761C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80107620: bne         $v0, $zero, L_80107680
    if (ctx->r2 != 0) {
        // 0x80107624: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80107680;
    }
    // 0x80107624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80107628: jal         0x80089CA0
    // 0x8010762C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8010762C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80107630: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80107634: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80107638: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8010763C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80107640: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80107644: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80107648: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8010764C: nop

    // 0x80107650: bc1tl       L_8010766C
    if (c1cs) {
        // 0x80107654: lbu         $t2, 0x75($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X75);
            goto L_8010766C;
    }
    goto skip_0;
    // 0x80107654: lbu         $t2, 0x75($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X75);
    skip_0:
    // 0x80107658: lbu         $t0, 0x75($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X75);
    // 0x8010765C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80107660: b           L_80107674
    // 0x80107664: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
        goto L_80107674;
    // 0x80107664: sb          $t1, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r9;
    // 0x80107668: lbu         $t2, 0x75($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X75);
L_8010766C:
    // 0x8010766C: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80107670: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
L_80107674:
    // 0x80107674: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80107678: b           L_8010768C
    // 0x8010767C: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
        goto L_8010768C;
    // 0x8010767C: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_80107680:
    // 0x80107680: lwc1        $f10, 0x6474($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6474);
    // 0x80107684: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80107688: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
L_8010768C:
    // 0x8010768C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80107690: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x80107694: jal         0x80102FA0
    // 0x80107698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80102FA0(rdram, ctx);
        goto after_4;
    // 0x80107698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8010769C: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x801076A0: sll         $t8, $v0, 7
    ctx->r24 = S32(ctx->r2 << 7);
    // 0x801076A4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801076A8: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x801076AC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x801076B0: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
    // 0x801076B4: ori         $a1, $a1, 0x8
    ctx->r5 = ctx->r5 | 0X8;
    // 0x801076B8: jal         0x80102FA0
    // 0x801076BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80102FA0(rdram, ctx);
        goto after_5;
    // 0x801076BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801076C0: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
    // 0x801076C4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x801076C8: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x801076CC: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x801076D0: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x801076D4: andi        $t6, $t5, 0xFFBF
    ctx->r14 = ctx->r13 & 0XFFBF;
    // 0x801076D8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x801076DC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801076E0: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x801076E4: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    // 0x801076E8: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x801076EC: ori         $a1, $a1, 0x1000
    ctx->r5 = ctx->r5 | 0X1000;
    // 0x801076F0: jal         0x80102FA0
    // 0x801076F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80102FA0(rdram, ctx);
        goto after_6;
    // 0x801076F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x801076F8: lbu         $t2, 0x71($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X71);
    // 0x801076FC: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80107700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107704: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80107708: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x8010770C: sb          $t5, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r13;
    // 0x80107710: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80107714: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80107718: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8010771C: jal         0x801073F8
    // 0x80107720: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    func_801073F8(rdram, ctx);
        goto after_7;
    // 0x80107720: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    after_7:
    // 0x80107724: bne         $v0, $zero, L_8010773C
    if (ctx->r2 != 0) {
        // 0x80107728: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010773C;
    }
    // 0x80107728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010772C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80107730: addiu       $a2, $a2, 0x44FC
    ctx->r6 = ADD32(ctx->r6, 0X44FC);
    // 0x80107734: jal         0x80089D18
    // 0x80107738: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80107738: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
L_8010773C:
    // 0x8010773C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80107740: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80107744: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80107748: jr          $ra
    // 0x8010774C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010774C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80809DA0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809DA0: bne         $a1, $zero, L_80809DC0
    if (ctx->r5 != 0) {
        // 0x80809DA4: lw          $v0, 0x188($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X188);
            goto L_80809DC0;
    }
    // 0x80809DA4: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809DA8: lw          $t6, 0x254($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X254);
    // 0x80809DAC: bgez        $t6, L_80809DC8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80809DB0: nop
    
            goto L_80809DC8;
    }
    // 0x80809DB0: nop

    // 0x80809DB4: sw          $a1, 0x254($v0)
    MEM_W(0X254, ctx->r2) = ctx->r5;
    // 0x80809DB8: jr          $ra
    // 0x80809DBC: sw          $zero, 0x258($v0)
    MEM_W(0X258, ctx->r2) = 0;
    return;
    // 0x80809DBC: sw          $zero, 0x258($v0)
    MEM_W(0X258, ctx->r2) = 0;
L_80809DC0:
    // 0x80809DC0: sw          $a1, 0x254($v0)
    MEM_W(0X254, ctx->r2) = ctx->r5;
    // 0x80809DC4: sw          $zero, 0x258($v0)
    MEM_W(0X258, ctx->r2) = 0;
L_80809DC8:
    // 0x80809DC8: jr          $ra
    // 0x80809DCC: nop

    return;
    // 0x80809DCC: nop

;}
RECOMP_FUNC void func_808079C8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808079C8: jr          $ra
    // 0x808079CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808079CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808001C8_sucoasterhit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: jal         0x80106790
    // 0x808001D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808001D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001D8: lw          $t6, 0x78($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X78);
    // 0x808001DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001E0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808001E4: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808001E8: bltzl       $t8, L_808001FC
    if (SIGNED(ctx->r24) < 0) {
        // 0x808001EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001F0: jal         0x8008A140
    // 0x808001F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808001F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
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
RECOMP_FUNC void func_808002F4_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002F8: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x808002FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800300: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800304: bne         $at, $zero, L_80800340
    if (ctx->r1 != 0) {
        // 0x80800308: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800340;
    }
    // 0x80800308: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080030C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800310: beq         $a1, $at, L_808003AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800314: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1020, 0X1398) << 16);
            goto L_808003AC;
    }
    // 0x80800314: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1020, 0X1398) << 16);
    // 0x80800318: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x8080031C: beq         $a1, $at, L_808003C0
    if (ctx->r5 == ctx->r1) {
        // 0x80800320: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808003C0;
    }
    // 0x80800320: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800324: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800328: beq         $a1, $at, L_80800420
    if (ctx->r5 == ctx->r1) {
        // 0x8080032C: addiu       $at, $zero, 0xB8
        ctx->r1 = ADD32(0, 0XB8);
            goto L_80800420;
    }
    // 0x8080032C: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x80800330: beq         $a1, $at, L_80800428
    if (ctx->r5 == ctx->r1) {
        // 0x80800334: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80800428;
    }
    // 0x80800334: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800338: b           L_808004B4
    // 0x8080033C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004B4;
    // 0x8080033C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800340:
    // 0x80800340: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800344: beq         $a1, $at, L_808003E8
    if (ctx->r5 == ctx->r1) {
        // 0x80800348: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_808003E8;
    }
    // 0x80800348: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8080034C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800350: beq         $a1, $at, L_808004B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800354: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_808004B0;
    }
    // 0x80800354: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80800358: beq         $a1, $at, L_808004B0
    if (ctx->r5 == ctx->r1) {
        // 0x8080035C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_808004B0;
    }
    // 0x8080035C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800360: beq         $a1, $at, L_8080037C
    if (ctx->r5 == ctx->r1) {
        // 0x80800364: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_8080037C;
    }
    // 0x80800364: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800368: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x8080036C: beq         $a1, $at, L_80800394
    if (ctx->r5 == ctx->r1) {
        // 0x80800370: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_80800394;
    }
    // 0x80800370: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800374: b           L_808004B4
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004B4;
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080037C:
    // 0x8080037C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800380: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800384: jal         0x80800578
    // 0x80800388: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800578_chtiptup(rdram, ctx);
        goto after_0;
    // 0x80800388: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x8080038C: b           L_808004B4
    // 0x80800390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004B4;
    // 0x80800390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800394:
    // 0x80800394: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800398: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080039C: jal         0x80800534
    // 0x808003A0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800534_chtiptup(rdram, ctx);
        goto after_1;
    // 0x808003A0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x808003A4: b           L_808004B4
    // 0x808003A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004B4;
    // 0x808003A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003AC:
    // 0x808003AC: addiu       $a0, $a0, 0x1398
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1020, 0X1398));
    // 0x808003B0: jal         0x80088090
    // 0x808003B4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808003B4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x808003B8: b           L_808004B4
    // 0x808003BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004B4;
    // 0x808003BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C0:
    // 0x808003C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808003C4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808003C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808003CC: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x808003D0: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x808003D4: srl         $a2, $t7, 16
    ctx->r6 = S32(U32(ctx->r15) >> 16);
    // 0x808003D8: jal         0x80800774
    // 0x808003DC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80800774_chtiptup(rdram, ctx);
        goto after_3;
    // 0x808003DC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_3:
    // 0x808003E0: b           L_808004B8
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004B8;
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003E8:
    // 0x808003E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003EC: bne         $t9, $at, L_80800418
    if (ctx->r25 != ctx->r1) {
        // 0x808003F0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800418;
    }
    // 0x808003F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003F4: jal         0x808007CC
    // 0x808003F8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_808007CC_chtiptup(rdram, ctx);
        goto after_4;
    // 0x808003F8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_4:
    // 0x808003FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: jal         0x800FFA88
    // 0x80800404: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    func_800FFA88(rdram, ctx);
        goto after_5;
    // 0x80800404: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    after_5:
    // 0x80800408: jal         0x800FFAB0
    // 0x8080040C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x8080040C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800410: b           L_808004B4
    // 0x80800414: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808004B4;
    // 0x80800414: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800418:
    // 0x80800418: b           L_808004B4
    // 0x8080041C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808004B4;
    // 0x8080041C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800420:
    // 0x80800420: b           L_808004B0
    // 0x80800424: sb          $zero, 0x28($a3)
    MEM_B(0X28, ctx->r7) = 0;
        goto L_808004B0;
    // 0x80800424: sb          $zero, 0x28($a3)
    MEM_B(0X28, ctx->r7) = 0;
L_80800428:
    // 0x80800428: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x8080042C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80800430: jal         0x800DA298
    // 0x80800434: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800434: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    after_7:
    // 0x80800438: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080043C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800440: beq         $v1, $at, L_80800460
    if (ctx->r3 == ctx->r1) {
        // 0x80800444: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800460;
    }
    // 0x80800444: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800448: beq         $v1, $at, L_80800478
    if (ctx->r3 == ctx->r1) {
        // 0x8080044C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800478;
    }
    // 0x8080044C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800450: beq         $v1, $at, L_80800490
    if (ctx->r3 == ctx->r1) {
        // 0x80800454: nop
    
            goto L_80800490;
    }
    // 0x80800454: nop

    // 0x80800458: b           L_808004B4
    // 0x8080045C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004B4;
    // 0x8080045C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800460:
    // 0x80800460: beq         $v0, $zero, L_80800470
    if (ctx->r2 == 0) {
        // 0x80800464: addiu       $v1, $zero, 0xFF7
        ctx->r3 = ADD32(0, 0XFF7);
            goto L_80800470;
    }
    // 0x80800464: addiu       $v1, $zero, 0xFF7
    ctx->r3 = ADD32(0, 0XFF7);
    // 0x80800468: b           L_808004B4
    // 0x8080046C: addiu       $v0, $zero, 0xFF8
    ctx->r2 = ADD32(0, 0XFF8);
        goto L_808004B4;
    // 0x8080046C: addiu       $v0, $zero, 0xFF8
    ctx->r2 = ADD32(0, 0XFF8);
L_80800470:
    // 0x80800470: b           L_808004B4
    // 0x80800474: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004B4;
    // 0x80800474: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800478:
    // 0x80800478: beq         $v0, $zero, L_80800488
    if (ctx->r2 == 0) {
        // 0x8080047C: addiu       $v1, $zero, 0x104F
        ctx->r3 = ADD32(0, 0X104F);
            goto L_80800488;
    }
    // 0x8080047C: addiu       $v1, $zero, 0x104F
    ctx->r3 = ADD32(0, 0X104F);
    // 0x80800480: b           L_808004B4
    // 0x80800484: addiu       $v0, $zero, 0xFF8
    ctx->r2 = ADD32(0, 0XFF8);
        goto L_808004B4;
    // 0x80800484: addiu       $v0, $zero, 0xFF8
    ctx->r2 = ADD32(0, 0XFF8);
L_80800488:
    // 0x80800488: b           L_808004B4
    // 0x8080048C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004B4;
    // 0x8080048C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800490:
    // 0x80800490: beq         $v0, $zero, L_808004A0
    if (ctx->r2 == 0) {
        // 0x80800494: addiu       $v1, $zero, 0xFF7
        ctx->r3 = ADD32(0, 0XFF7);
            goto L_808004A0;
    }
    // 0x80800494: addiu       $v1, $zero, 0xFF7
    ctx->r3 = ADD32(0, 0XFF7);
    // 0x80800498: b           L_808004B4
    // 0x8080049C: addiu       $v0, $zero, 0xFF8
    ctx->r2 = ADD32(0, 0XFF8);
        goto L_808004B4;
    // 0x8080049C: addiu       $v0, $zero, 0xFF8
    ctx->r2 = ADD32(0, 0XFF8);
L_808004A0:
    // 0x808004A0: b           L_808004B4
    // 0x808004A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004B4;
    // 0x808004A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808004A8: b           L_808004B4
    // 0x808004AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004B4;
    // 0x808004AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004B0:
    // 0x808004B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B4:
    // 0x808004B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004B8:
    // 0x808004B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004BC: jr          $ra
    // 0x808004C0: nop

    return;
    // 0x808004C0: nop

;}
RECOMP_FUNC void func_80800FBC_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FC4: jal         0x800A89F8
    // 0x80800FC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80800FC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FCC: jal         0x800A9478
    // 0x80800FD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_1;
    // 0x80800FD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800FD4: jal         0x800F5EF8
    // 0x80800FD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x80800FD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800FDC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800FE0: jal         0x80089550
    // 0x80800FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpod_entrypoint_18(rdram, ctx);
        goto after_3;
    // 0x80800FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800FE8: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80800FEC: bne         $v0, $at, L_80800FFC
    if (ctx->r2 != ctx->r1) {
        // 0x80800FF0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800FFC;
    }
    // 0x80800FF0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FF4: jal         0x80089548
    // 0x80800FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80800FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80800FFC:
    // 0x80800FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801000: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801004: jr          $ra
    // 0x80801008: nop

    return;
    // 0x80801008: nop

;}
RECOMP_FUNC void _bsbabykaz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827E0: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827E0);
    return;
    // 0x800827E4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chjinjo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001A8: bne         $a0, $at, L_808001BC
    if (ctx->r4 != ctx->r1) {
        // 0x808001AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808001BC;
    }
    // 0x808001AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B0: jal         0x800EA05C
    // 0x808001B4: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808001B4: nop

    after_0:
    // 0x808001B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808001BC:
    // 0x808001BC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1672, 0X1300) << 16);
    // 0x808001C0: lh          $t6, 0x1300($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(1672, 0X1300));
    // 0x808001C4: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1672, 0X1304) << 16);
    // 0x808001C8: addiu       $v1, $v1, 0x1304
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1672, 0X1304));
    // 0x808001CC: bne         $a0, $t6, L_808001E0
    if (ctx->r4 != ctx->r14) {
        // 0x808001D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001E0;
    }
    // 0x808001D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1672, 0X1302) << 16);
    // 0x808001D8: b           L_80800248
    // 0x808001DC: lh          $v0, 0x1302($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1302));
        goto L_80800248;
    // 0x808001DC: lh          $v0, 0x1302($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1302));
L_808001E0:
    // 0x808001E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1672, 0X1324) << 16);
    // 0x808001E4: addiu       $v0, $v0, 0x1324
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1324));
    // 0x808001E8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_808001EC:
    // 0x808001EC: bnel        $a0, $t7, L_80800200
    if (ctx->r4 != ctx->r15) {
        // 0x808001F0: lh          $t8, 0x4($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X4);
            goto L_80800200;
    }
    goto skip_0;
    // 0x808001F0: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    skip_0:
    // 0x808001F4: b           L_80800248
    // 0x808001F8: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
        goto L_80800248;
    // 0x808001F8: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x808001FC: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
L_80800200:
    // 0x80800200: bnel        $a0, $t8, L_80800214
    if (ctx->r4 != ctx->r24) {
        // 0x80800204: lh          $t9, 0x8($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X8);
            goto L_80800214;
    }
    goto skip_1;
    // 0x80800204: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    skip_1:
    // 0x80800208: b           L_80800248
    // 0x8080020C: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
        goto L_80800248;
    // 0x8080020C: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x80800210: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
L_80800214:
    // 0x80800214: bnel        $a0, $t9, L_80800228
    if (ctx->r4 != ctx->r25) {
        // 0x80800218: lh          $t0, 0xC($v1)
        ctx->r8 = MEM_H(ctx->r3, 0XC);
            goto L_80800228;
    }
    goto skip_2;
    // 0x80800218: lh          $t0, 0xC($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XC);
    skip_2:
    // 0x8080021C: b           L_80800248
    // 0x80800220: lh          $v0, 0xA($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA);
        goto L_80800248;
    // 0x80800220: lh          $v0, 0xA($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA);
    // 0x80800224: lh          $t0, 0xC($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XC);
L_80800228:
    // 0x80800228: bnel        $a0, $t0, L_8080023C
    if (ctx->r4 != ctx->r8) {
        // 0x8080022C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8080023C;
    }
    goto skip_3;
    // 0x8080022C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_3:
    // 0x80800230: b           L_80800248
    // 0x80800234: lh          $v0, 0xE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XE);
        goto L_80800248;
    // 0x80800234: lh          $v0, 0xE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XE);
    // 0x80800238: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8080023C:
    // 0x8080023C: bnel        $v1, $v0, L_808001EC
    if (ctx->r3 != ctx->r2) {
        // 0x80800240: lh          $t7, 0x0($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X0);
            goto L_808001EC;
    }
    goto skip_4;
    // 0x80800240: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    skip_4:
    // 0x80800244: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800248:
    // 0x80800248: jr          $ra
    // 0x8080024C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080024C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801E18_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E20: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80801E24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801E28: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80801E2C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80801E30: jal         0x80801B0C
    // 0x80801E34: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80801B0C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801E34: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80801E38: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801E3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801E40: lw          $t6, 0xB0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XB0);
    // 0x80801E44: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80801E48: beq         $at, $zero, L_80801FC0
    if (ctx->r1 == 0) {
        // 0x80801E4C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801FC0;
    }
    // 0x80801E4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801E50: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA438) << 16);
    // 0x80801E54: addu        $at, $at, $t6
    gpr jr_addend_80801E5C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801E58: lw          $t6, -0x5BC8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(439, 0XA438));
    // 0x80801E5C: jr          $t6
    // 0x80801E60: nop

    switch (jr_addend_80801E5C >> 2) {
        case 0: goto L_80801E64; break;
        case 1: goto L_80801EB4; break;
        case 2: goto L_80801EFC; break;
        case 3: goto L_80801F38; break;
        case 4: goto L_80801F68; break;
        case 5: goto L_80801F98; break;
        default: switch_error(__func__, 0x80801E5C, 0x8080A438);
    }
    // 0x80801E60: nop

L_80801E64:
    // 0x80801E64: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80801E68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801E6C: beql        $t7, $zero, L_80801FC4
    if (ctx->r15 == 0) {
        // 0x80801E70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801FC4;
    }
    goto skip_0;
    // 0x80801E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801E74: sw          $t8, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r24;
    // 0x80801E78: lw          $a1, 0xB8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XB8);
    // 0x80801E7C: lw          $a2, 0xBC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XBC);
    // 0x80801E80: jal         0x80084B00
    // 0x80801E84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _baeggcursor_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80801E84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80801E88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801E8C: jal         0x80084AE8
    // 0x80801E90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80801E90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80801E94: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(439, 0XA630) << 16);
    // 0x80801E98: addiu       $a3, $a3, -0x59D0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(439, 0XA630));
    // 0x80801E9C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80801EA0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801EA4: jal         0x8010D930
    // 0x80801EA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010D930(rdram, ctx);
        goto after_3;
    // 0x80801EA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80801EAC: b           L_80801FC4
    // 0x80801EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801FC4;
    // 0x80801EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801EB4:
    // 0x80801EB4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80801EB8: jal         0x80084AF8
    // 0x80801EBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _baeggcursor_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80801EBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_4:
    // 0x80801EC0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801EC4: beq         $v0, $zero, L_80801EE4
    if (ctx->r2 == 0) {
        // 0x80801EC8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801EE4;
    }
    // 0x80801EC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801ECC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80801ED0: sw          $t9, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r25;
    // 0x80801ED4: jal         0x80802438
    // 0x80801ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802438_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80801ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801EDC: b           L_80801FC4
    // 0x80801EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801FC4;
    // 0x80801EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801EE4:
    // 0x80801EE4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80801EE8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80801EEC: bnel        $t0, $zero, L_80801FC4
    if (ctx->r8 != 0) {
        // 0x80801EF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801FC4;
    }
    goto skip_1;
    // 0x80801EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801EF4: b           L_80801FC0
    // 0x80801EF8: sw          $t1, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r9;
        goto L_80801FC0;
    // 0x80801EF8: sw          $t1, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r9;
L_80801EFC:
    // 0x80801EFC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80801F00: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80801F04: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801F08: bnel        $t2, $zero, L_80801FC4
    if (ctx->r10 != 0) {
        // 0x80801F0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801FC4;
    }
    goto skip_2;
    // 0x80801F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80801F10: jal         0x80084AE8
    // 0x80801F14: sw          $t3, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r11;
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80801F14: sw          $t3, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r11;
    after_6:
    // 0x80801F18: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(439, 0XA640) << 16);
    // 0x80801F1C: addiu       $a3, $a3, -0x59C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(439, 0XA640));
    // 0x80801F20: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80801F24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801F28: jal         0x8010D930
    // 0x80801F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010D930(rdram, ctx);
        goto after_7;
    // 0x80801F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80801F30: b           L_80801FC4
    // 0x80801F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801FC4;
    // 0x80801F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F38:
    // 0x80801F38: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80801F3C: jal         0x80084AF8
    // 0x80801F40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _baeggcursor_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x80801F40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_8:
    // 0x80801F44: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801F48: beq         $v0, $zero, L_80801FC0
    if (ctx->r2 == 0) {
        // 0x80801F4C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801FC0;
    }
    // 0x80801F4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801F50: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80801F54: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x80801F58: jal         0x80802438
    // 0x80801F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802438_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80801F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80801F60: b           L_80801FC4
    // 0x80801F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801FC4;
    // 0x80801F64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F68:
    // 0x80801F68: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80801F6C: sw          $t5, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r13;
    // 0x80801F70: jal         0x80084AE8
    // 0x80801F74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x80801F74: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x80801F78: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(439, 0XA640) << 16);
    // 0x80801F7C: addiu       $a3, $a3, -0x59C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(439, 0XA640));
    // 0x80801F80: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80801F84: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801F88: jal         0x8010D930
    // 0x80801F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010D930(rdram, ctx);
        goto after_11;
    // 0x80801F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80801F90: b           L_80801FC4
    // 0x80801F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801FC4;
    // 0x80801F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801F98:
    // 0x80801F98: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80801F9C: jal         0x80084AC0
    // 0x80801FA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _baeggcursor_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80801FA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_12:
    // 0x80801FA4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801FA8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801FAC: beq         $v0, $at, L_80801FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80801FB0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801FC0;
    }
    // 0x80801FB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801FB4: sw          $zero, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = 0;
    // 0x80801FB8: jal         0x80802438
    // 0x80801FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802438_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x80801FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_80801FC0:
    // 0x80801FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801FC4:
    // 0x80801FC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801FC8: jr          $ra
    // 0x80801FCC: nop

    return;
    // 0x80801FCC: nop

;}
RECOMP_FUNC void ncpod_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080055C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800568: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080056C: jal         0x800EE7F8
    // 0x80800570: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800570: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80800574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800578: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080057C: jal         0x800EE7F8
    // 0x80800580: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800580: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_1:
    // 0x80800584: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800588: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080058C: sb          $t6, 0x40($t7)
    MEM_B(0X40, ctx->r15) = ctx->r14;
    // 0x80800590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800598: jr          $ra
    // 0x8080059C: nop

    return;
    // 0x8080059C: nop

;}
RECOMP_FUNC void func_800E73DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E73DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E73E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E73E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E73E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E73EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800E73F0: jal         0x800E73D4
    // 0x800E73F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x800E73F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E73F8: or          $a2, $sp, $zero
    ctx->r6 = ctx->r29 | 0;
    // 0x800E73FC: addiu       $a2, $a2, 0x2B
    ctx->r6 = ADD32(ctx->r6, 0X2B);
    // 0x800E7400: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800E7404: and         $t6, $a2, $at
    ctx->r14 = ctx->r6 & ctx->r1;
    // 0x800E7408: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800E740C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E7410: jal         0x800E7480
    // 0x800E7414: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800E7480(rdram, ctx);
        goto after_1;
    // 0x800E7414: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800E7418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E741C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7420: jr          $ra
    // 0x800E7424: nop

    return;
    // 0x800E7424: nop

;}
RECOMP_FUNC void func_800A4D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4D1C: jal         0x800A4C48
    // 0x800A4D20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A4C48(rdram, ctx);
        goto after_0;
    // 0x800A4D20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A4D24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A4D28: jal         0x800CA9D8
    // 0x800A4D2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800CA9D8(rdram, ctx);
        goto after_1;
    // 0x800A4D2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A4D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4D38: jr          $ra
    // 0x800A4D3C: nop

    return;
    // 0x800A4D3C: nop

;}
RECOMP_FUNC void bababykaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void heap_resize_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B1C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B1CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B1D0: jal         0x8001B0C8
    // 0x8001B1D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    heap_resize_block_internal(rdram, ctx);
        goto after_0;
    // 0x8001B1D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B1D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001B1DC: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x8001B1E0: lbu         $t7, 0xF($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XF);
    // 0x8001B1E4: srl         $t8, $t7, 6
    ctx->r24 = S32(U32(ctx->r15) >> 6);
    // 0x8001B1E8: bnel        $t8, $zero, L_8001B1FC
    if (ctx->r24 != 0) {
        // 0x8001B1EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001B1FC;
    }
    goto skip_0;
    // 0x8001B1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001B1F0: jal         0x8001AF14
    // 0x8001B1F4: nop

    heap_merge_free_block(rdram, ctx);
        goto after_1;
    // 0x8001B1F4: nop

    after_1:
    // 0x8001B1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001B1FC:
    // 0x8001B1FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B200: jr          $ra
    // 0x8001B204: nop

    return;
    // 0x8001B204: nop

;}
RECOMP_FUNC void func_808000AC_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000B0: beq         $a0, $at, L_808000D0
    if (ctx->r4 == ctx->r1) {
        // 0x808000B4: addiu       $t6, $zero, 0xC5
        ctx->r14 = ADD32(0, 0XC5);
            goto L_808000D0;
    }
    // 0x808000B4: addiu       $t6, $zero, 0xC5
    ctx->r14 = ADD32(0, 0XC5);
    // 0x808000B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000BC: beq         $a0, $at, L_808000E4
    if (ctx->r4 == ctx->r1) {
        // 0x808000C0: addiu       $t8, $zero, 0x112
        ctx->r24 = ADD32(0, 0X112);
            goto L_808000E4;
    }
    // 0x808000C0: addiu       $t8, $zero, 0x112
    ctx->r24 = ADD32(0, 0X112);
    // 0x808000C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000C8: beq         $a0, $at, L_808000F8
    if (ctx->r4 == ctx->r1) {
        // 0x808000CC: addiu       $t0, $zero, 0x112
        ctx->r8 = ADD32(0, 0X112);
            goto L_808000F8;
    }
    // 0x808000CC: addiu       $t0, $zero, 0x112
    ctx->r8 = ADD32(0, 0X112);
L_808000D0:
    // 0x808000D0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x808000D4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x808000D8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x808000DC: jr          $ra
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000E4:
    // 0x808000E4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x808000E8: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x808000EC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x808000F0: jr          $ra
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000F8:
    // 0x808000F8: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x808000FC: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x80800100: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80800104: jr          $ra
    // 0x80800108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800108: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void gcnewoption_entrypoint_47(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F1C: lbu         $v0, 0x24($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X24);
    // 0x80802F20: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x80802F24: jr          $ra
    // 0x80802F28: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x80802F28: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void bschokedie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800264: jal         0x800951B4
    // 0x80800268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800951B4(rdram, ctx);
        goto after_0;
    // 0x80800268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080026C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800270: jal         0x8009BF5C
    // 0x80800274: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800274: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: jal         0x8009C4CC
    // 0x80800280: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800280: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800284: jal         0x800A4E30
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_3;
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void _chtntmineshoot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087398: syscall     559
    recomp_syscall_handler(rdram, ctx, 0x80087398);
    return;
    // 0x8008739C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80021928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002192C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021934: jal         0x800218C4
    // 0x80021938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800218C4(rdram, ctx);
        goto after_0;
    // 0x80021938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8002193C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80021940: b           L_80021950
    // 0x80021944: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
        goto L_80021950;
    // 0x80021944: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x80021948: b           L_80021950
    // 0x8002194C: nop

        goto L_80021950;
    // 0x8002194C: nop

L_80021950:
    // 0x80021950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80021958: jr          $ra
    // 0x8002195C: nop

    return;
    // 0x8002195C: nop

;}
RECOMP_FUNC void batimer_incrementBy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x8080000C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80800010: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800014: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x80800018: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080001C: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x80800020: lw          $t7, 0x13C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X13C);
    // 0x80800024: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80800028: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080002C: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80800030: jr          $ra
    // 0x80800034: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    return;
    // 0x80800034: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80800000_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a1, $zero, 0x504
    ctx->r5 = ADD32(0, 0X504);
    // 0x8080000C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800010: jal         0x8009DF94
    // 0x80800014: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DF94(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void ncbasuck_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800050: jal         0x80111B8C
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_0;
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_0:
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: jal         0x801124D0
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: jal         0x80115858
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800074: jal         0x80115870
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
