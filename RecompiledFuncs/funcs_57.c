#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

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
RECOMP_FUNC void func_80807BB8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807BB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80807BBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807BC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807BC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80807BC8: jal         0x8009E77C
    // 0x80807BCC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80807BCC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80807BD0: bnel        $v0, $zero, L_80807C7C
    if (ctx->r2 != 0) {
        // 0x80807BD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80807C7C;
    }
    goto skip_0;
    // 0x80807BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80807BD8: jal         0x80800000
    // 0x80807BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80807BE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80807BE4: jal         0x80807AF8
    // 0x80807BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807AF8_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807BF0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80807BF4: jal         0x800947EC
    // 0x80807BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_3;
    // 0x80807BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80807BFC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80807C00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80807C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807C08: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80807C0C: jal         0x80801AC4
    // 0x80807C10: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    func_80801AC4_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80807C10: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    after_4:
    // 0x80807C14: jal         0x80805F48
    // 0x80807C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80805F48_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80807C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80807C1C: jal         0x80809CD8
    // 0x80807C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809CD8_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80807C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80807C24: jal         0x808067E8
    // 0x80807C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808067E8_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80807C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80807C2C: jal         0x8080995C
    // 0x80807C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080995C_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x80807C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80807C34: jal         0x80803A84
    // 0x80807C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803A84_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80807C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80807C3C: jal         0x808047EC
    // 0x80807C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808047EC_bsfirstp(rdram, ctx);
        goto after_10;
    // 0x80807C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80807C44: jal         0x80802BD8
    // 0x80807C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802BD8_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80807C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80807C4C: jal         0x80802F00
    // 0x80807C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802F00_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x80807C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80807C54: jal         0x80809C90
    // 0x80807C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809C90_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x80807C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80807C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807C60: jal         0x80084CE8
    // 0x80807C64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_14;
    // 0x80807C64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80807C68: jal         0x80800190
    // 0x80807C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800190_bsfirstp(rdram, ctx);
        goto after_15;
    // 0x80807C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80807C70: jal         0x80807F9C
    // 0x80807C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807F9C_bsfirstp(rdram, ctx);
        goto after_16;
    // 0x80807C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80807C78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807C7C:
    // 0x80807C7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807C80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80807C84: jr          $ra
    // 0x80807C88: nop

    return;
    // 0x80807C88: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085588: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085588);
    return;
    // 0x8008558C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801D80_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801D84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801D88: slti        $at, $a1, 0xCEC
    ctx->r1 = SIGNED(ctx->r5) < 0XCEC ? 1 : 0;
    // 0x80801D8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801D90: bne         $at, $zero, L_80801DBC
    if (ctx->r1 != 0) {
        // 0x80801D94: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80801DBC;
    }
    // 0x80801D94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801D98: addiu       $t6, $a1, -0xF97
    ctx->r14 = ADD32(ctx->r5, -0XF97);
    // 0x80801D9C: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80801DA0: beq         $at, $zero, L_80801EA0
    if (ctx->r1 == 0) {
        // 0x80801DA4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801EA0;
    }
    // 0x80801DA4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801DA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A80) << 16);
    // 0x80801DAC: addu        $at, $at, $t6
    gpr jr_addend_80801DB4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801DB0: lw          $t6, 0x2A80($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A80));
    // 0x80801DB4: jr          $t6
    // 0x80801DB8: nop

    switch (jr_addend_80801DB4 >> 2) {
        case 0: goto L_80801DD0; break;
        case 1: goto L_80801E04; break;
        case 2: goto L_80801DE0; break;
        case 3: goto L_80801DE0; break;
        case 4: goto L_80801DE0; break;
        case 5: goto L_80801EA0; break;
        case 6: goto L_80801EA0; break;
        case 7: goto L_80801DD0; break;
        default: switch_error(__func__, 0x80801DB4, 0x80802A80);
    }
    // 0x80801DB8: nop

L_80801DBC:
    // 0x80801DBC: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80801DC0: beq         $a1, $at, L_80801E80
    if (ctx->r5 == ctx->r1) {
        // 0x80801DC4: nop
    
            goto L_80801E80;
    }
    // 0x80801DC4: nop

    // 0x80801DC8: b           L_80801EA4
    // 0x80801DCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801EA4;
    // 0x80801DCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801DD0:
    // 0x80801DD0: jal         0x80802414
    // 0x80801DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802414_chboilerboss(rdram, ctx);
        goto after_0;
    // 0x80801DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801DD8: b           L_80801EA4
    // 0x80801DDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801EA4;
    // 0x80801DDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801DE0:
    // 0x80801DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DE4: jal         0x80109FE8
    // 0x80801DE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_1;
    // 0x80801DE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801DEC: jal         0x808026F0
    // 0x80801DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026F0_chboilerboss(rdram, ctx);
        goto after_2;
    // 0x80801DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801DF4: jal         0x808024DC
    // 0x80801DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808024DC_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x80801DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801DFC: b           L_80801EA4
    // 0x80801E00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801EA4;
    // 0x80801E00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E04:
    // 0x80801E04: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801E08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801E0C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801E10: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80801E14: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80801E18: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801E1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801E20: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80801E24: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80801E28: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80801E2C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80801E30: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801E34: lw          $t8, 0x48($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X48);
    // 0x80801E38: jal         0x80086D50
    // 0x80801E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80801E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x80801E40: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801E44: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    // 0x80801E48: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80801E4C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E54: addiu       $a1, $zero, 0x795
    ctx->r5 = ADD32(0, 0X795);
    // 0x80801E58: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801E5C: jal         0x80086680
    // 0x80801E60: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80801E60: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80801E64: jal         0x800FDC28
    // 0x80801E68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_6;
    // 0x80801E68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80801E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E70: jal         0x80800F34
    // 0x80801E74: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_7;
    // 0x80801E74: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_7:
    // 0x80801E78: b           L_80801EA4
    // 0x80801E7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801EA4;
    // 0x80801E7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E80:
    // 0x80801E80: blez        $a2, L_80801E98
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801E84: nop
    
            goto L_80801E98;
    }
    // 0x80801E84: nop

    // 0x80801E88: jal         0x80088188
    // 0x80801E8C: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80801E8C: nop

    after_8:
    // 0x80801E90: b           L_80801EA4
    // 0x80801E94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801EA4;
    // 0x80801E94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801E98:
    // 0x80801E98: jal         0x80088180
    // 0x80801E9C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x80801E9C: nop

    after_9:
L_80801EA0:
    // 0x80801EA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801EA4:
    // 0x80801EA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801EA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801EAC: jr          $ra
    // 0x80801EB0: nop

    return;
    // 0x80801EB0: nop

;}
RECOMP_FUNC void bsdronebubbled_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F8: jal         0x8009E6EC
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800100: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80800104: beq         $v0, $at, L_80800130
    if (ctx->r2 == ctx->r1) {
        // 0x80800108: addiu       $at, $zero, 0x6F
        ctx->r1 = ADD32(0, 0X6F);
            goto L_80800130;
    }
    // 0x80800108: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x8080010C: beq         $v0, $at, L_80800140
    if (ctx->r2 == ctx->r1) {
        // 0x80800110: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800140;
    }
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: addiu       $at, $zero, 0x70
    ctx->r1 = ADD32(0, 0X70);
    // 0x80800118: beq         $v0, $at, L_80800150
    if (ctx->r2 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0x7B
        ctx->r1 = ADD32(0, 0X7B);
            goto L_80800150;
    }
    // 0x8080011C: addiu       $at, $zero, 0x7B
    ctx->r1 = ADD32(0, 0X7B);
    // 0x80800120: beql        $v0, $at, L_80800170
    if (ctx->r2 == ctx->r1) {
        // 0x80800124: lw          $t6, 0x54($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X54);
            goto L_80800170;
    }
    goto skip_0;
    // 0x80800124: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    skip_0:
    // 0x80800128: b           L_80800198
    // 0x8080012C: nop

        goto L_80800198;
    // 0x8080012C: nop

L_80800130:
    // 0x80800130: jal         0x80099B94
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800138: b           L_808001A4
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001A4;
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800140:
    // 0x80800140: jal         0x8009E830
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800148: b           L_808001A4
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001A4;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800150:
    // 0x80800150: jal         0x80084750
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_34(rdram, ctx);
        goto after_3;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x8009E5C8
    // 0x80800160: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800160: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800164: b           L_808001A4
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001A4;
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080016C: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
L_80800170:
    // 0x80800170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800174: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800178: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(168, 0X2E0) << 16);
    // 0x8080017C: lwc1        $f6, 0x2E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(168, 0X2E0));
    // 0x80800180: lwc1        $f4, 0x40($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X40);
    // 0x80800184: jal         0x800F13F0
    // 0x80800188: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_800F13F0(rdram, ctx);
        goto after_5;
    // 0x80800188: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_5:
    // 0x8080018C: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x80800190: b           L_808001A0
    // 0x80800194: swc1        $f0, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f0.u32l;
        goto L_808001A0;
    // 0x80800194: swc1        $f0, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f0.u32l;
L_80800198:
    // 0x80800198: jal         0x80099B94
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_6;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_808001A0:
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001A4:
    // 0x808001A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_800CE864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE86C: jal         0x800CE3E0
    // 0x800CE870: nop

    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE870: nop

    after_0:
    // 0x800CE874: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CE878: sb          $t6, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r14;
    // 0x800CE87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE884: jr          $ra
    // 0x800CE888: nop

    return;
    // 0x800CE888: nop

;}
RECOMP_FUNC void func_80800648_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080064C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800650: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1900, 0X7C4) << 16);
    // 0x80800654: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1900, 0X7D0) << 16);
    // 0x80800658: addiu       $a3, $a3, 0x7D0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1900, 0X7D0));
    // 0x8080065C: addiu       $a2, $a2, 0x7C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1900, 0X7C4));
    // 0x80800660: jal         0x80089D28
    // 0x80800664: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800664: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080066C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800670: jr          $ra
    // 0x80800674: nop

    return;
    // 0x80800674: nop

    // 0x80800678: nop

    // 0x8080067C: nop

;}
RECOMP_FUNC void func_80800000_chboggyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x80800010: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800014: bnel        $t7, $zero, L_80800058
    if (ctx->r15 != 0) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080001C: jal         0x800F54E4
    // 0x80800020: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800020: nop

    after_0:
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800028: jal         0x800F6388
    // 0x8080002C: addiu       $a1, $zero, 0x4BA
    ctx->r5 = ADD32(0, 0X4BA);
    func_800F6388(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x4BA
    ctx->r5 = ADD32(0, 0X4BA);
    after_1:
    // 0x80800030: jal         0x800D1844
    // 0x80800034: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    func_800D1844(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_2:
    // 0x80800038: jal         0x800FC6B0
    // 0x8080003C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x8080003C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
    // 0x80800040: jal         0x800DA544
    // 0x80800044: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800044: addiu       $a0, $zero, 0x438
    ctx->r4 = ADD32(0, 0X438);
    after_4:
    // 0x80800048: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: jal         0x800FFA88
    // 0x80800050: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_5;
    // 0x80800050: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_5:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_808003F0_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003F8: jal         0x8009E6EC
    // 0x808003FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808003FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800400: addiu       $at, $zero, 0x8D
    ctx->r1 = ADD32(0, 0X8D);
    // 0x80800404: bne         $v0, $at, L_80800420
    if (ctx->r2 != ctx->r1) {
        // 0x80800408: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800420;
    }
    // 0x80800408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080040C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800410: jal         0x80800308
    // 0x80800414: sw          $t6, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->r14;
    func_80800308_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800414: sw          $t6, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->r14;
    after_1:
    // 0x80800418: b           L_8080042C
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080042C;
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800420:
    // 0x80800420: jal         0x80099B94
    // 0x80800424: nop

    func_80099B94(rdram, ctx);
        goto after_2;
    // 0x80800424: nop

    after_2:
    // 0x80800428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080042C:
    // 0x8080042C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800430: jr          $ra
    // 0x80800434: nop

    return;
    // 0x80800434: nop

;}
RECOMP_FUNC void func_80800000_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009EF1C
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800014: jal         0x8009EF10
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080001C: bne         $v0, $zero, L_80800038
    if (ctx->r2 != 0) {
        // 0x80800020: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800038;
    }
    // 0x80800020: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: jal         0x8009B9B0
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800030: b           L_80800058
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080003C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800040: jal         0x800F1214
    // 0x80800044: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800044: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    after_3:
    // 0x80800048: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void ncbastring_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: jr          $ra
    // 0x80800078: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800078: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8080077C_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800784: jal         0x8009BC6C
    // 0x80800788: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800788: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080078C: jal         0x80800238
    // 0x80800790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80800790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080079C: jr          $ra
    // 0x808007A0: nop

    return;
    // 0x808007A0: nop

;}
RECOMP_FUNC void _chweldarbossdoors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086620: syscall     349
    recomp_syscall_handler(rdram, ctx, 0x80086620);
    return;
    // 0x80086624: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800B3748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3748: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B374C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3750: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B3754: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800B3758: jal         0x800C8960
    // 0x800B375C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800C8960(rdram, ctx);
        goto after_0;
    // 0x800B375C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800B3760: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800B3764: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800B3768: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800B376C: jal         0x800B36C0
    // 0x800B3770: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    func_800B36C0(rdram, ctx);
        goto after_1;
    // 0x800B3770: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_1:
    // 0x800B3774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3778: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800B377C: jr          $ra
    // 0x800B3780: nop

    return;
    // 0x800B3780: nop

;}
RECOMP_FUNC void func_80800394_chtorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003A0: jal         0x80100094
    // 0x808003A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003A8: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x808003AC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: beql        $t6, $zero, L_808003D0
    if (ctx->r14 == 0) {
        // 0x808003B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003D0;
    }
    goto skip_0;
    // 0x808003B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003B8: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x808003BC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x808003C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808003C4: jalr        $t9
    // 0x808003C8: lw          $a2, 0x30($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X30);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x808003C8: lw          $a2, 0x30($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X30);
    after_1:
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D0:
    // 0x808003D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void func_800A3544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3544: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3548: jr          $ra
    // 0x800A354C: sb          $a1, 0x3F($t6)
    MEM_B(0X3F, ctx->r14) = ctx->r5;
    return;
    // 0x800A354C: sb          $a1, 0x3F($t6)
    MEM_B(0X3F, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800C0258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0258: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C025C: addiu       $v1, $v1, -0x7750
    ctx->r3 = ADD32(ctx->r3, -0X7750);
    // 0x800C0260: lhu         $t6, 0x15E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X15E);
    // 0x800C0264: srl         $t7, $t6, 15
    ctx->r15 = S32(U32(ctx->r14) >> 15);
    // 0x800C0268: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800C026C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800C0270: lh          $v0, 0x118($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X118);
    // 0x800C0274: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C0278: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x800C027C: jr          $ra
    // 0x800C0280: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    return;
    // 0x800C0280: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088298: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x80088298);
    return;
    // 0x8008829C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009EAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EAAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EAB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EAB4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8009EAB8: jal         0x800DA3B8
    // 0x8009EABC: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x8009EABC: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    after_0:
    // 0x8009EAC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EAC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EAC8: jr          $ra
    // 0x8009EACC: nop

    return;
    // 0x8009EACC: nop

;}
RECOMP_FUNC void func_808028F0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808028F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808028F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808028F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808028FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802900: jal         0x80100094
    // 0x80802904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802908: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080290C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80802910: jal         0x800D0A9C
    // 0x80802914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80802914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80802918: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x8080291C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80802920: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80802924: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80802928: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080292C: jal         0x80088848
    // 0x80802930: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80802930: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_2:
    // 0x80802934: beq         $v0, $zero, L_80802980
    if (ctx->r2 == 0) {
        // 0x80802938: nop
    
            goto L_80802980;
    }
    // 0x80802938: nop

    // 0x8080293C: jal         0x800EA05C
    // 0x80802940: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80802940: nop

    after_3:
    // 0x80802944: addiu       $at, $zero, 0xC7
    ctx->r1 = ADD32(0, 0XC7);
    // 0x80802948: bne         $v0, $at, L_80802970
    if (ctx->r2 != ctx->r1) {
        // 0x8080294C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802970;
    }
    // 0x8080294C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802954: jal         0x8080282C
    // 0x80802958: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080282C_chhandcart(rdram, ctx);
        goto after_4;
    // 0x80802958: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8080295C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802960: jal         0x808031D0
    // 0x80802964: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_5;
    // 0x80802964: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_5:
    // 0x80802968: b           L_80802B38
    // 0x8080296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802B38;
    // 0x8080296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802970:
    // 0x80802970: jal         0x800FFAB0
    // 0x80802974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x80802974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802978: b           L_80802B64
    // 0x8080297C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B64;
    // 0x8080297C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802980:
    // 0x80802980: jal         0x800DA298
    // 0x80802984: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80802984: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_7:
    // 0x80802988: beq         $v0, $zero, L_80802AF4
    if (ctx->r2 == 0) {
        // 0x8080298C: nop
    
            goto L_80802AF4;
    }
    // 0x8080298C: nop

    // 0x80802990: jal         0x800EA05C
    // 0x80802994: nop

    func_800EA05C(rdram, ctx);
        goto after_8;
    // 0x80802994: nop

    after_8:
    // 0x80802998: addiu       $at, $zero, 0xDB
    ctx->r1 = ADD32(0, 0XDB);
    // 0x8080299C: bne         $v0, $at, L_808029B4
    if (ctx->r2 != ctx->r1) {
        // 0x808029A0: nop
    
            goto L_808029B4;
    }
    // 0x808029A0: nop

    // 0x808029A4: jal         0x800FFAB0
    // 0x808029A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808029A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808029AC: b           L_80802B64
    // 0x808029B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B64;
    // 0x808029B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808029B4:
    // 0x808029B4: jal         0x80800194
    // 0x808029B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800194_chhandcart(rdram, ctx);
        goto after_10;
    // 0x808029B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808029BC: beq         $v0, $zero, L_808029E0
    if (ctx->r2 == 0) {
        // 0x808029C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808029E0;
    }
    // 0x808029C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808029C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808029C8: beq         $v0, $at, L_80802A04
    if (ctx->r2 == ctx->r1) {
        // 0x808029CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802A04;
    }
    // 0x808029CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808029D0: beql        $v0, $at, L_80802A60
    if (ctx->r2 == ctx->r1) {
        // 0x808029D4: lw          $a1, 0x64($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X64);
            goto L_80802A60;
    }
    goto skip_0;
    // 0x808029D4: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x808029D8: b           L_80802AAC
    // 0x808029DC: nop

        goto L_80802AAC;
    // 0x808029DC: nop

L_808029E0:
    // 0x808029E0: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x808029E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808029E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808029EC: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x808029F0: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x808029F4: jal         0x8080282C
    // 0x808029F8: subu        $a1, $t5, $t4
    ctx->r5 = SUB32(ctx->r13, ctx->r12);
    func_8080282C_chhandcart(rdram, ctx);
        goto after_11;
    // 0x808029F8: subu        $a1, $t5, $t4
    ctx->r5 = SUB32(ctx->r13, ctx->r12);
    after_11:
    // 0x808029FC: b           L_80802AAC
    // 0x80802A00: nop

        goto L_80802AAC;
    // 0x80802A00: nop

L_80802A04:
    // 0x80802A04: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80802A08: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80802A0C: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    // 0x80802A10: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80802A14: bgez        $t9, L_80802A30
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802A18: nop
    
            goto L_80802A30;
    }
    // 0x80802A18: nop

    // 0x80802A1C: jal         0x80088480
    // 0x80802A20: addiu       $a0, $zero, 0x385
    ctx->r4 = ADD32(0, 0X385);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80802A20: addiu       $a0, $zero, 0x385
    ctx->r4 = ADD32(0, 0X385);
    after_12:
    // 0x80802A24: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80802A28: b           L_80802A40
    // 0x80802A2C: sh          $v0, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r2;
        goto L_80802A40;
    // 0x80802A2C: sh          $v0, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r2;
L_80802A30:
    // 0x80802A30: jal         0x80088480
    // 0x80802A34: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80802A34: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_13:
    // 0x80802A38: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80802A3C: sh          $v0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r2;
L_80802A40:
    // 0x80802A40: jal         0x80800024
    // 0x80802A44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800024_chhandcart(rdram, ctx);
        goto after_14;
    // 0x80802A44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80802A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A4C: jal         0x808031D0
    // 0x80802A50: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_15;
    // 0x80802A50: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x80802A54: b           L_80802AAC
    // 0x80802A58: nop

        goto L_80802AAC;
    // 0x80802A58: nop

    // 0x80802A5C: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
L_80802A60:
    // 0x80802A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802A68: sll         $t1, $a1, 12
    ctx->r9 = S32(ctx->r5 << 12);
    // 0x80802A6C: jal         0x8080282C
    // 0x80802A70: srl         $a1, $t1, 31
    ctx->r5 = S32(U32(ctx->r9) >> 31);
    func_8080282C_chhandcart(rdram, ctx);
        goto after_16;
    // 0x80802A70: srl         $a1, $t1, 31
    ctx->r5 = S32(U32(ctx->r9) >> 31);
    after_16:
    // 0x80802A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A78: jal         0x808031D0
    // 0x80802A7C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_17;
    // 0x80802A7C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_17:
    // 0x80802A80: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80802A84: addiu       $a0, $zero, 0x389
    ctx->r4 = ADD32(0, 0X389);
    // 0x80802A88: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x80802A8C: bgez        $t4, L_80802AA4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80802A90: nop
    
            goto L_80802AA4;
    }
    // 0x80802A90: nop

    // 0x80802A94: jal         0x80088480
    // 0x80802A98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x80802A98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_18:
    // 0x80802A9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802AA0: sh          $v0, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r2;
L_80802AA4:
    // 0x80802AA4: jal         0x80800214
    // 0x80802AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800214_chhandcart(rdram, ctx);
        goto after_19;
    // 0x80802AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_80802AAC:
    // 0x80802AAC: jal         0x800DA298
    // 0x80802AB0: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    func_800DA298(rdram, ctx);
        goto after_20;
    // 0x80802AB0: addiu       $a0, $zero, 0x507
    ctx->r4 = ADD32(0, 0X507);
    after_20:
    // 0x80802AB4: bne         $v0, $zero, L_80802B34
    if (ctx->r2 != 0) {
        // 0x80802AB8: addiu       $a0, $zero, 0x388
        ctx->r4 = ADD32(0, 0X388);
            goto L_80802B34;
    }
    // 0x80802AB8: addiu       $a0, $zero, 0x388
    ctx->r4 = ADD32(0, 0X388);
    // 0x80802ABC: jal         0x80088480
    // 0x80802AC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x80802AC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x80802AC4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80802AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802ACC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802AD0: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    // 0x80802AD4: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80802AD8: jal         0x801058C4
    // 0x80802ADC: lh          $a1, 0xC($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XC);
    func_801058C4(rdram, ctx);
        goto after_22;
    // 0x80802ADC: lh          $a1, 0xC($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XC);
    after_22:
    // 0x80802AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802AE4: jal         0x808031D0
    // 0x80802AE8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_23;
    // 0x80802AE8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_23:
    // 0x80802AEC: b           L_80802B38
    // 0x80802AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802B38;
    // 0x80802AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802AF4:
    // 0x80802AF4: jal         0x800EA05C
    // 0x80802AF8: nop

    func_800EA05C(rdram, ctx);
        goto after_24;
    // 0x80802AF8: nop

    after_24:
    // 0x80802AFC: addiu       $at, $zero, 0xDB
    ctx->r1 = ADD32(0, 0XDB);
    // 0x80802B00: beq         $v0, $at, L_80802B18
    if (ctx->r2 == ctx->r1) {
        // 0x80802B04: addiu       $a0, $zero, 0x384
        ctx->r4 = ADD32(0, 0X384);
            goto L_80802B18;
    }
    // 0x80802B04: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    // 0x80802B08: jal         0x800FFAB0
    // 0x80802B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_25;
    // 0x80802B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80802B10: b           L_80802B64
    // 0x80802B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B64;
    // 0x80802B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802B18:
    // 0x80802B18: jal         0x80088480
    // 0x80802B1C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x80802B1C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_26:
    // 0x80802B20: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B28: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80802B2C: jal         0x80802CE8
    // 0x80802B30: sh          $v0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r2;
    func_80802CE8_chhandcart(rdram, ctx);
        goto after_27;
    // 0x80802B30: sh          $v0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r2;
    after_27:
L_80802B34:
    // 0x80802B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802B38:
    // 0x80802B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802B3C: jal         0x800897C0
    // 0x80802B40: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_28;
    // 0x80802B40: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    after_28:
    // 0x80802B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B48: jal         0x80100094
    // 0x80802B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_29;
    // 0x80802B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80802B50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B54: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80802B58: jal         0x800897E8
    // 0x80802B5C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_30;
    // 0x80802B5C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_30:
    // 0x80802B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802B64:
    // 0x80802B64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802B68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802B6C: jr          $ra
    // 0x80802B70: nop

    return;
    // 0x80802B70: nop

;}
RECOMP_FUNC void func_800151BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800151BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800151C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800151C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800151C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800151CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800151D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800151D4: jal         0x8002EC20
    // 0x800151D8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x800151D8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_0:
    // 0x800151DC: jal         0x80013500
    // 0x800151E0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_80013500(rdram, ctx);
        goto after_1;
    // 0x800151E0: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_1:
    // 0x800151E4: jal         0x80013488
    // 0x800151E8: nop

    func_80013488(rdram, ctx);
        goto after_2;
    // 0x800151E8: nop

    after_2:
    // 0x800151EC: beq         $s0, $zero, L_80015204
    if (ctx->r16 == 0) {
        // 0x800151F0: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80015204;
    }
    // 0x800151F0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800151F4: addiu       $a0, $a0, -0x6FF0
    ctx->r4 = ADD32(ctx->r4, -0X6FF0);
    // 0x800151F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800151FC: jal         0x8002E1F0
    // 0x80015200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80015200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_80015204:
    // 0x80015204: jal         0x80015184
    // 0x80015208: nop

    func_80015184(rdram, ctx);
        goto after_4;
    // 0x80015208: nop

    after_4:
    // 0x8001520C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80015210: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80015214: lw          $t8, -0x68FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X68FC);
    // 0x80015218: addiu       $t6, $t6, -0x6EC8
    ctx->r14 = ADD32(ctx->r14, -0X6EC8);
    // 0x8001521C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80015220: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x80015224: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80015228: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001522C: beq         $at, $zero, L_80015270
    if (ctx->r1 == 0) {
        // 0x80015230: addiu       $s1, $s1, -0x6FD0
        ctx->r17 = ADD32(ctx->r17, -0X6FD0);
            goto L_80015270;
    }
    // 0x80015230: addiu       $s1, $s1, -0x6FD0
    ctx->r17 = ADD32(ctx->r17, -0X6FD0);
    // 0x80015234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80015238:
    // 0x80015238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001523C: jal         0x8002E1F0
    // 0x80015240: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80015240: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80015244: jal         0x80015184
    // 0x80015248: nop

    func_80015184(rdram, ctx);
        goto after_6;
    // 0x80015248: nop

    after_6:
    // 0x8001524C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80015250: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80015254: lw          $t2, -0x68FC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X68FC);
    // 0x80015258: addiu       $t0, $t0, -0x6EC8
    ctx->r8 = ADD32(ctx->r8, -0X6EC8);
    // 0x8001525C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80015260: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80015264: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80015268: bnel        $at, $zero, L_80015238
    if (ctx->r1 != 0) {
        // 0x8001526C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80015238;
    }
    goto skip_0;
    // 0x8001526C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80015270:
    // 0x80015270: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80015274: addiu       $s1, $s1, -0x6FD0
    ctx->r17 = ADD32(ctx->r17, -0X6FD0);
    // 0x80015278: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    // 0x8001527C: beq         $t4, $zero, L_8001529C
    if (ctx->r12 == 0) {
        // 0x80015280: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8001529C;
    }
    // 0x80015280: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80015284:
    // 0x80015284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015288: jal         0x8002E1F0
    // 0x8001528C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x8001528C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80015290: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x80015294: bnel        $t5, $zero, L_80015284
    if (ctx->r13 != 0) {
        // 0x80015298: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80015284;
    }
    goto skip_1;
    // 0x80015298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
L_8001529C:
    // 0x8001529C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800152A0: addiu       $v0, $v0, -0x709E
    ctx->r2 = ADD32(ctx->r2, -0X709E);
    // 0x800152A4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800152A8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800152AC: addiu       $v1, $v1, -0x6900
    ctx->r3 = ADD32(ctx->r3, -0X6900);
    // 0x800152B0: bnel        $t6, $zero, L_80015384
    if (ctx->r14 != 0) {
        // 0x800152B4: sh          $zero, 0x0($v0)
        MEM_H(0X0, ctx->r2) = 0;
            goto L_80015384;
    }
    goto skip_2;
    // 0x800152B4: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    skip_2:
    // 0x800152B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800152BC: beq         $v0, $zero, L_800152D4
    if (ctx->r2 == 0) {
        // 0x800152C0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800152D4;
    }
    // 0x800152C0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800152C4: bne         $t8, $zero, L_800152D4
    if (ctx->r24 != 0) {
        // 0x800152C8: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_800152D4;
    }
    // 0x800152C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800152CC: jal         0x8002FBB0
    // 0x800152D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_8;
    // 0x800152D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
L_800152D4:
    // 0x800152D4: jal         0x80014F38
    // 0x800152D8: nop

    func_80014F38(rdram, ctx);
        goto after_9;
    // 0x800152D8: nop

    after_9:
    // 0x800152DC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800152E0: addiu       $v1, $v1, -0x70A0
    ctx->r3 = ADD32(ctx->r3, -0X70A0);
    // 0x800152E4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800152E8: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800152EC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800152F0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800152F4: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x800152F8: jal         0x8002FDE0
    // 0x800152FC: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_10;
    // 0x800152FC: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    after_10:
    // 0x80015300: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015304: jal         0x8002F240
    // 0x80015308: sw          $zero, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = 0;
    osDpGetStatus_recomp(rdram, ctx);
        goto after_11;
    // 0x80015308: sw          $zero, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = 0;
    after_11:
    // 0x8001530C: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x80015310: bne         $t2, $zero, L_80015384
    if (ctx->r10 != 0) {
        // 0x80015314: nop
    
            goto L_80015384;
    }
    // 0x80015314: nop

    // 0x80015318: jal         0x8002F250
    // 0x8001531C: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_12;
    // 0x8001531C: nop

    after_12:
    // 0x80015320: jal         0x8002FE30
    // 0x80015324: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_13;
    // 0x80015324: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_13:
    // 0x80015328: beq         $v0, $s0, L_80015384
    if (ctx->r2 == ctx->r16) {
        // 0x8001532C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80015384;
    }
    // 0x8001532C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80015330:
    // 0x80015330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015334: jal         0x8002E1F0
    // 0x80015338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80015338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x8001533C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80015340: lw          $t1, -0x68FC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X68FC);
    // 0x80015344: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015348: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8001534C: jal         0x8002F240
    // 0x80015350: sw          $t3, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r11;
    osDpGetStatus_recomp(rdram, ctx);
        goto after_15;
    // 0x80015350: sw          $t3, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r11;
    after_15:
    // 0x80015354: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x80015358: bne         $t4, $zero, L_80015384
    if (ctx->r12 != 0) {
        // 0x8001535C: nop
    
            goto L_80015384;
    }
    // 0x8001535C: nop

    // 0x80015360: jal         0x8002F250
    // 0x80015364: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_16;
    // 0x80015364: nop

    after_16:
    // 0x80015368: jal         0x8002FE30
    // 0x8001536C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_17;
    // 0x8001536C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_17:
    // 0x80015370: bnel        $v0, $s0, L_80015330
    if (ctx->r2 != ctx->r16) {
        // 0x80015374: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80015330;
    }
    goto skip_3;
    // 0x80015374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
    // 0x80015378: b           L_80015384
    // 0x8001537C: nop

        goto L_80015384;
    // 0x8001537C: nop

    // 0x80015380: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80015384:
    // 0x80015384: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80015388: addiu       $t5, $t5, -0x6EC8
    ctx->r13 = ADD32(ctx->r13, -0X6EC8);
    // 0x8001538C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80015390: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015394: sh          $t6, -0x709C($at)
    MEM_H(-0X709C, ctx->r1) = ctx->r14;
    // 0x80015398: jal         0x800134C4
    // 0x8001539C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    func_800134C4(rdram, ctx);
        goto after_18;
    // 0x8001539C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    after_18:
    // 0x800153A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800153A4: jal         0x8002EC20
    // 0x800153A8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_19;
    // 0x800153A8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_19:
    // 0x800153AC: jal         0x80013474
    // 0x800153B0: nop

    func_80013474(rdram, ctx);
        goto after_20;
    // 0x800153B0: nop

    after_20:
    // 0x800153B4: bne         $v0, $zero, L_800153F4
    if (ctx->r2 != 0) {
        // 0x800153B8: nop
    
            goto L_800153F4;
    }
    // 0x800153B8: nop

    // 0x800153BC: jal         0x80081D28
    // 0x800153C0: nop

    func_80081D28(rdram, ctx);
        goto after_21;
    // 0x800153C0: nop

    after_21:
    // 0x800153C4: beq         $v0, $zero, L_800153F4
    if (ctx->r2 == 0) {
        // 0x800153C8: nop
    
            goto L_800153F4;
    }
    // 0x800153C8: nop

L_800153CC:
    // 0x800153CC: jal         0x8002FE70
    // 0x800153D0: nop

    osYieldThread_recomp(rdram, ctx);
        goto after_22;
    // 0x800153D0: nop

    after_22:
    // 0x800153D4: jal         0x80013474
    // 0x800153D8: nop

    func_80013474(rdram, ctx);
        goto after_23;
    // 0x800153D8: nop

    after_23:
    // 0x800153DC: bne         $v0, $zero, L_800153F4
    if (ctx->r2 != 0) {
        // 0x800153E0: nop
    
            goto L_800153F4;
    }
    // 0x800153E0: nop

    // 0x800153E4: jal         0x80081D28
    // 0x800153E8: nop

    func_80081D28(rdram, ctx);
        goto after_24;
    // 0x800153E8: nop

    after_24:
    // 0x800153EC: bne         $v0, $zero, L_800153CC
    if (ctx->r2 != 0) {
        // 0x800153F0: nop
    
            goto L_800153CC;
    }
    // 0x800153F0: nop

L_800153F4:
    // 0x800153F4: jal         0x80013500
    // 0x800153F8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80013500(rdram, ctx);
        goto after_25;
    // 0x800153F8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_25:
    // 0x800153FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80015400: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80015404: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80015408: jr          $ra
    // 0x8001540C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001540C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800924_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800924: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080092C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800930: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800934: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2312, 0XD4C) << 16);
    // 0x80800938: addiu       $t7, $t7, 0xD4C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2312, 0XD4C));
    // 0x8080093C: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80800940: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800944: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080094C: jal         0x800BBCB8
    // 0x80800950: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800950: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080095C: jr          $ra
    // 0x80800960: nop

    return;
    // 0x80800960: nop

;}
RECOMP_FUNC void func_80800090_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800094: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080009C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808000A0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808000A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808000A8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808000AC: jal         0x800B53A4
    // 0x808000B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x808000B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x808000B4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F50) << 16);
    // 0x808000BC: lwc1        $f4, 0x1F50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F50));
    // 0x808000C0: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F54) << 16);
    // 0x808000C8: lwc1        $f8, 0x1F54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F54));
    // 0x808000CC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808000DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808000E0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808000E4: jal         0x800BA7C4
    // 0x808000E8: nop

    func_800BA7C4(rdram, ctx);
        goto after_1;
    // 0x808000E8: nop

    after_1:
    // 0x808000EC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808000F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F58) << 16);
    // 0x808000F4: lwc1        $f16, 0x1F58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F58));
    // 0x808000F8: lwc1        $f0, 0x38($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X38);
    // 0x808000FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F5C) << 16);
    // 0x80800100: lwc1        $f4, 0x1F5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F5C));
    // 0x80800104: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800110: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800114: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800118: jal         0x800BA7FC
    // 0x8080011C: nop

    func_800BA7FC(rdram, ctx);
        goto after_2;
    // 0x8080011C: nop

    after_2:
    // 0x80800120: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800124: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800128: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080012C: lwc1        $f0, 0x48($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X48);
    // 0x80800130: addiu       $t2, $zero, -0x19
    ctx->r10 = ADD32(0, -0X19);
    // 0x80800134: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x80800138: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8080013C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80800140: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800144: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: addiu       $a1, $zero, -0x2D
    ctx->r5 = ADD32(0, -0X2D);
    // 0x80800150: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800154: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x80800158: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080015C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800160: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80800164: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80800168: sra         $a2, $t0, 16
    ctx->r6 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8080016C: jal         0x800BA994
    // 0x80800170: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_800BA994(rdram, ctx);
        goto after_3;
    // 0x80800170: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_3:
    // 0x80800174: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800178: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1748, 0X20E0) << 16);
    // 0x8080017C: addiu       $t6, $t6, 0x20E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1748, 0X20E0));
    // 0x80800180: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080018C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800190: jal         0x800BABB8
    // 0x80800194: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800194: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808001A0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808001A4: jal         0x800BA1D0
    // 0x808001A8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_800BA1D0(rdram, ctx);
        goto after_5;
    // 0x808001A8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x808001AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001B0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808001B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001B8: jr          $ra
    // 0x808001BC: nop

    return;
    // 0x808001BC: nop

;}
RECOMP_FUNC void func_80802A4C_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802A58: jal         0x8009E704
    // 0x80802A5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x80802A5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802A68: jal         0x8009CA70
    // 0x80802A6C: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x80802A6C: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_1:
    // 0x80802A70: bnel        $v0, $zero, L_80802AA8
    if (ctx->r2 != 0) {
        // 0x80802A74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802AA8;
    }
    goto skip_0;
    // 0x80802A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802A78: jal         0x80085090
    // 0x80802A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80802A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802A80: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80802A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A88: jal         0x80092880
    // 0x80802A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092880(rdram, ctx);
        goto after_3;
    // 0x80802A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80802A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A94: jal         0x800A2018
    // 0x80802A98: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A2018(rdram, ctx);
        goto after_4;
    // 0x80802A98: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
    // 0x80802A9C: jal         0x800A4E30
    // 0x80802AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_5;
    // 0x80802AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802AA8:
    // 0x80802AA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802AAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802AB0: jr          $ra
    // 0x80802AB4: nop

    return;
    // 0x80802AB4: nop

;}
RECOMP_FUNC void func_800DF324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF324: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF328: jr          $ra
    // 0x800DF32C: lw          $v0, -0x37DC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X37DC);
    return;
    // 0x800DF32C: lw          $v0, -0x37DC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X37DC);
;}
RECOMP_FUNC void chjiggytemple_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(784, 0X8C8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x8C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(784, 0X8C8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x8C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(784, 0X8C8));
;}
RECOMP_FUNC void bsvan_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808007DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1C9C) << 16);
    // 0x808007E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808007E4: jr          $ra
    // 0x808007E8: lw          $v0, 0x1C9C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1C9C));
    return;
    // 0x808007E8: lw          $v0, 0x1C9C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1C9C));
;}
RECOMP_FUNC void func_80800AEC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800AF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800AFC: jal         0x80106790
    // 0x80800B00: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800B00: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800B04: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800B08: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B0C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800B10: slti        $at, $a3, 0xFE
    ctx->r1 = SIGNED(ctx->r7) < 0XFE ? 1 : 0;
    // 0x80800B14: bne         $at, $zero, L_80800B38
    if (ctx->r1 != 0) {
        // 0x80800B18: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800B38;
    }
    // 0x80800B18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B1C: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80800B20: beq         $a3, $at, L_80800C60
    if (ctx->r7 == ctx->r1) {
        // 0x80800B24: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_80800C60;
    }
    // 0x80800B24: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800B28: beql        $a3, $at, L_80800C2C
    if (ctx->r7 == ctx->r1) {
        // 0x80800B2C: lhu         $t0, 0x72($a0)
        ctx->r8 = MEM_HU(ctx->r4, 0X72);
            goto L_80800C2C;
    }
    goto skip_0;
    // 0x80800B2C: lhu         $t0, 0x72($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X72);
    skip_0:
    // 0x80800B30: b           L_80800C94
    // 0x80800B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B38:
    // 0x80800B38: slti        $at, $a3, 0xFD
    ctx->r1 = SIGNED(ctx->r7) < 0XFD ? 1 : 0;
    // 0x80800B3C: bne         $at, $zero, L_80800B54
    if (ctx->r1 != 0) {
        // 0x80800B40: addiu       $at, $zero, 0xFD
        ctx->r1 = ADD32(0, 0XFD);
            goto L_80800B54;
    }
    // 0x80800B40: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80800B44: beql        $a3, $at, L_80800C64
    if (ctx->r7 == ctx->r1) {
        // 0x80800B48: lhu         $t3, 0x72($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0X72);
            goto L_80800C64;
    }
    goto skip_1;
    // 0x80800B48: lhu         $t3, 0x72($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X72);
    skip_1:
    // 0x80800B4C: b           L_80800C94
    // 0x80800B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B54:
    // 0x80800B54: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x80800B58: bne         $at, $zero, L_80800B70
    if (ctx->r1 != 0) {
        // 0x80800B5C: addiu       $at, $zero, 0xFC
        ctx->r1 = ADD32(0, 0XFC);
            goto L_80800B70;
    }
    // 0x80800B5C: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x80800B60: beql        $a3, $at, L_80800C64
    if (ctx->r7 == ctx->r1) {
        // 0x80800B64: lhu         $t3, 0x72($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0X72);
            goto L_80800C64;
    }
    goto skip_2;
    // 0x80800B64: lhu         $t3, 0x72($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X72);
    skip_2:
    // 0x80800B68: b           L_80800C94
    // 0x80800B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B70:
    // 0x80800B70: sltiu       $at, $a3, 0x8
    ctx->r1 = ctx->r7 < 0X8 ? 1 : 0;
    // 0x80800B74: beq         $at, $zero, L_80800C90
    if (ctx->r1 == 0) {
        // 0x80800B78: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_80800C90;
    }
    // 0x80800B78: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80800B7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C68) << 16);
    // 0x80800B80: addu        $at, $at, $t6
    gpr jr_addend_80800B88 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800B84: lw          $t6, 0x7C68($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C68));
    // 0x80800B88: jr          $t6
    // 0x80800B8C: nop

    switch (jr_addend_80800B88 >> 2) {
        case 0: goto L_80800B90; break;
        case 1: goto L_80800C90; break;
        case 2: goto L_80800BD8; break;
        case 3: goto L_80800BC8; break;
        case 4: goto L_80800BE8; break;
        case 5: goto L_80800BF8; break;
        case 6: goto L_80800C08; break;
        case 7: goto L_80800C18; break;
        default: switch_error(__func__, 0x80800B88, 0x80807C68);
    }
    // 0x80800B8C: nop

L_80800B90:
    // 0x80800B90: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800B94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7DDC) << 16);
    // 0x80800B98: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800B9C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800BA0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80800BA4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800BA8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800BAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800BB0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800BB4: lw          $t9, 0x7DDC($at)
    ctx->r25 = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7DDC));
    // 0x80800BB8: jalr        $t9
    // 0x80800BBC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80800BBC: nop

    after_1:
    // 0x80800BC0: b           L_80800C94
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC8:
    // 0x80800BC8: jal         0x80800998
    // 0x80800BCC: nop

    func_80800998_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80800BCC: nop

    after_2:
    // 0x80800BD0: b           L_80800C94
    // 0x80800BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BD8:
    // 0x80800BD8: jal         0x808009EC
    // 0x80800BDC: nop

    func_808009EC_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80800BDC: nop

    after_3:
    // 0x80800BE0: b           L_80800C94
    // 0x80800BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BE8:
    // 0x80800BE8: jal         0x808008D0
    // 0x80800BEC: nop

    func_808008D0_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80800BEC: nop

    after_4:
    // 0x80800BF0: b           L_80800C94
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BF8:
    // 0x80800BF8: jal         0x80800944
    // 0x80800BFC: nop

    func_80800944_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80800BFC: nop

    after_5:
    // 0x80800C00: b           L_80800C94
    // 0x80800C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C08:
    // 0x80800C08: jal         0x80800A9C
    // 0x80800C0C: nop

    func_80800A9C_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80800C0C: nop

    after_6:
    // 0x80800C10: b           L_80800C94
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C18:
    // 0x80800C18: jal         0x80800A4C
    // 0x80800C1C: nop

    func_80800A4C_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80800C1C: nop

    after_7:
    // 0x80800C20: b           L_80800C94
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C28: lhu         $t0, 0x72($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X72);
L_80800C2C:
    // 0x80800C2C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(804, 0X7DF0) << 16);
    // 0x80800C30: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80800C34: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800C38: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80800C3C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800C40: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80800C44: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800C48: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80800C4C: lw          $t9, 0x7DF0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(804, 0X7DF0));
    // 0x80800C50: jalr        $t9
    // 0x80800C54: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x80800C54: nop

    after_8:
    // 0x80800C58: b           L_80800C94
    // 0x80800C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C94;
    // 0x80800C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C60:
    // 0x80800C60: lhu         $t3, 0x72($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X72);
L_80800C64:
    // 0x80800C64: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(804, 0X7DF4) << 16);
    // 0x80800C68: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x80800C6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800C70: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80800C74: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800C78: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80800C7C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80800C80: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80800C84: lw          $t9, 0x7DF4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(804, 0X7DF4));
    // 0x80800C88: jalr        $t9
    // 0x80800C8C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80800C8C: nop

    after_9:
L_80800C90:
    // 0x80800C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C94:
    // 0x80800C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C98: jr          $ra
    // 0x80800C9C: nop

    return;
    // 0x80800C9C: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836F0: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836F0);
    return;
    // 0x800836F4: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80801D08_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801D14: jal         0x80100094
    // 0x80801D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801D20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801D24: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x80801D28: sll         $t7, $t6, 22
    ctx->r15 = S32(ctx->r14 << 22);
    // 0x80801D2C: srl         $t8, $t7, 26
    ctx->r24 = S32(U32(ctx->r15) >> 26);
    // 0x80801D30: bne         $t8, $zero, L_80801D48
    if (ctx->r24 != 0) {
        // 0x80801D34: nop
    
            goto L_80801D48;
    }
    // 0x80801D34: nop

    // 0x80801D38: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x80801D3C: andi        $t0, $t9, 0xFC0F
    ctx->r8 = ctx->r25 & 0XFC0F;
    // 0x80801D40: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80801D44: sh          $t1, 0x72($a0)
    MEM_H(0X72, ctx->r4) = ctx->r9;
L_80801D48:
    // 0x80801D48: jal         0x800EA05C
    // 0x80801D4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80801D4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80801D50: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80801D54: bne         $v0, $at, L_80801D68
    if (ctx->r2 != ctx->r1) {
        // 0x80801D58: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D68;
    }
    // 0x80801D58: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D5C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801D60: b           L_80801D6C
    // 0x80801D64: sb          $t2, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r10;
        goto L_80801D6C;
    // 0x80801D64: sb          $t2, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r10;
L_80801D68:
    // 0x80801D68: sb          $zero, 0x12($v1)
    MEM_B(0X12, ctx->r3) = 0;
L_80801D6C:
    // 0x80801D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D74: jr          $ra
    // 0x80801D78: nop

    return;
    // 0x80801D78: nop

;}
RECOMP_FUNC void func_800E93CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E93CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E93D0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800E93D4: lui         $a1, 0x1A1
    ctx->r5 = S32(0X1A1 << 16);
    // 0x800E93D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E93DC: addiu       $a1, $a1, 0x4580
    ctx->r5 = ADD32(ctx->r5, 0X4580);
    // 0x800E93E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E93E4: addiu       $a0, $a0, 0x1CE0
    ctx->r4 = ADD32(ctx->r4, 0X1CE0);
    // 0x800E93E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E93EC: jal         0x800E8E70
    // 0x800E93F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800E8E70(rdram, ctx);
        goto after_0;
    // 0x800E93F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800E93F4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E93F8: lh          $t6, 0x1CE0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1CE0);
    // 0x800E93FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9400: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800E9404: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800E9408: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800E940C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800E9410: addiu       $t8, $t7, 0xB
    ctx->r24 = ADD32(ctx->r15, 0XB);
    // 0x800E9414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9418: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800E941C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800E9420: addiu       $v0, $v0, 0x3524
    ctx->r2 = ADD32(ctx->r2, 0X3524);
    // 0x800E9424: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800E9428: addu        $t1, $t9, $a1
    ctx->r9 = ADD32(ctx->r25, ctx->r5);
    // 0x800E942C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800E9430: jr          $ra
    // 0x800E9434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E9434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ncbadie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080006C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800078: jal         0x808000D4
    // 0x8080007C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    ncbadie_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080007C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_0:
    // 0x80800080: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800084: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80111B8C
    // 0x80800090: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x80800090: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_1:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80115858
    // 0x8080009C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x8080009C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: jal         0x80115870
    // 0x808000A8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x808000A8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_3:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x801124D0
    // 0x808000B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_801124D0(rdram, ctx);
        goto after_4;
    // 0x808000B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void _ncbajig_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892F0: syscall     772
    recomp_syscall_handler(rdram, ctx, 0x800892F0);
    return;
    // 0x800892F4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800C3B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3B94: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3B98: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3BA0: beq         $t6, $zero, L_800C3BCC
    if (ctx->r14 == 0) {
        // 0x800C3BA4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3BCC;
    }
    // 0x800C3BA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C3BA8: jal         0x800C1414
    // 0x800C3BAC: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3BAC: nop

    after_0:
    // 0x800C3BB0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3BB4: lbu         $t1, 0x7B($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X7B);
    // 0x800C3BB8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C3BBC: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x800C3BC0: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x800C3BC4: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x800C3BC8: sb          $t3, 0x7B($v0)
    MEM_B(0X7B, ctx->r2) = ctx->r11;
L_800C3BCC:
    // 0x800C3BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3BD4: jr          $ra
    // 0x800C3BD8: nop

    return;
    // 0x800C3BD8: nop

;}
RECOMP_FUNC void func_801107D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801107D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801107D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801107D8: jal         0x800F5B38
    // 0x801107DC: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    func_800F5B38(rdram, ctx);
        goto after_0;
    // 0x801107DC: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    after_0:
    // 0x801107E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801107E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801107E8: jr          $ra
    // 0x801107EC: nop

    return;
    // 0x801107EC: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A28: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A28);
    return;
    // 0x80088A2C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_8080019C_chscorepoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808001A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001A8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808001AC: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x808001B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B4: jal         0x800A89F8
    // 0x808001B8: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    after_0:
    // 0x808001BC: jal         0x800B8C50
    // 0x808001C0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    func_800B8C50(rdram, ctx);
        goto after_1;
    // 0x808001C0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001C4: jal         0x80089C90
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001CC: jal         0x800B8C8C
    // 0x808001D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B8C8C(rdram, ctx);
        goto after_3;
    // 0x808001D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808001D4: jal         0x800B8C98
    // 0x808001D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B8C98(rdram, ctx);
        goto after_4;
    // 0x808001D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x808001DC: jal         0x800B8CE0
    // 0x808001E0: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_800B8CE0(rdram, ctx);
        goto after_5;
    // 0x808001E0: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_5:
    // 0x808001E4: jal         0x800B7F14
    // 0x808001E8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800B7F14(rdram, ctx);
        goto after_6;
    // 0x808001E8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_6:
    // 0x808001EC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808001F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001F4: beql        $a0, $at, L_80800210
    if (ctx->r4 == ctx->r1) {
        // 0x808001F8: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_80800210;
    }
    goto skip_0;
    // 0x808001F8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    skip_0:
    // 0x808001FC: jal         0x800A940C
    // 0x80800200: nop

    func_800A940C(rdram, ctx);
        goto after_7;
    // 0x80800200: nop

    after_7:
    // 0x80800204: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800208: bne         $v0, $t7, L_80800280
    if (ctx->r2 != ctx->r15) {
        // 0x8080020C: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_80800280;
    }
    // 0x8080020C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_80800210:
    // 0x80800210: jal         0x800EE7F8
    // 0x80800214: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80800214: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800218: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080021C: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800220: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800224: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800228: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080022C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800230: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x80800234: jal         0x800C4C34
    // 0x80800238: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800C4C34(rdram, ctx);
        goto after_9;
    // 0x80800238: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8080023C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800240: beq         $t8, $zero, L_80800280
    if (ctx->r24 == 0) {
        // 0x80800244: nop
    
            goto L_80800280;
    }
    // 0x80800244: nop

    // 0x80800248: beq         $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x8080024C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800280;
    }
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x80100094
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800258: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080025C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800260: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800264: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800268: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080026C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800270: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800274: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800278: jal         0x800B8E28
    // 0x8080027C: nop

    func_800B8E28(rdram, ctx);
        goto after_11;
    // 0x8080027C: nop

    after_11:
L_80800280:
    // 0x80800280: jal         0x800B811C
    // 0x80800284: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800B811C(rdram, ctx);
        goto after_12;
    // 0x80800284: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_12:
    // 0x80800288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080028C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800290: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void func_80092BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092BF4: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092BF8: jr          $ra
    // 0x80092BFC: lwc1        $f0, 0x30($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X30);
    return;
    // 0x80092BFC: lwc1        $f0, 0x30($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X30);
;}
RECOMP_FUNC void func_80800018_chicestationbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: jal         0x80085808
    // 0x80800028: addiu       $a1, $zero, 0x1CF
    ctx->r5 = ADD32(0, 0X1CF);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $zero, 0x1CF
    ctx->r5 = ADD32(0, 0X1CF);
    after_0:
    // 0x8080002C: jal         0x80085818
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: jal         0x80085810
    // 0x8080003C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_80102CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102CD4: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80102CD8: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80102CDC: jal         0x800F20BC
    // 0x80102CE0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    func_800F20BC(rdram, ctx);
        goto after_0;
    // 0x80102CE0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_0:
    // 0x80102CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102CEC: jr          $ra
    // 0x80102CF0: nop

    return;
    // 0x80102CF0: nop

;}
RECOMP_FUNC void bsbpeck_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800478: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(108, 0X4A0) << 16);
    // 0x8080047C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800480: jr          $ra
    // 0x80800484: lw          $v0, 0x4A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(108, 0X4A0));
    return;
    // 0x80800484: lw          $v0, 0x4A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(108, 0X4A0));
    // 0x80800488: nop

    // 0x8080048C: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4D0: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4D0);
    return;
    // 0x8008A4D4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void glcutDll_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808006E8: addiu       $v0, $v0, 0x75E8
    ctx->r2 = ADD32(ctx->r2, 0X75E8);
    // 0x808006EC: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x808006F0: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x808006F4: lbu         $t8, 0xA($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XA);
    // 0x808006F8: lbu         $t9, 0xB($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XB);
    // 0x808006FC: lbu         $t0, 0x10($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X10);
    // 0x80800700: lbu         $t1, 0xF($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XF);
    // 0x80800704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800708: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080070C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800710: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800714: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800718: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8080071C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80800720: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80800724: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80800728: jal         0x80800330
    // 0x8080072C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    glcutDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080072C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x80800730: jal         0x808004D8
    // 0x80800734: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    glcutDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800734: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800738: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8080073C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800740: addiu       $v0, $v0, 0x75E8
    ctx->r2 = ADD32(ctx->r2, 0X75E8);
    // 0x80800744: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80800748: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8080074C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80800750: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80800754: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800758: sb          $t2, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r10;
    // 0x8080075C: sb          $t3, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r11;
    // 0x80800760: sb          $t4, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r12;
    // 0x80800764: bne         $a0, $at, L_8080077C
    if (ctx->r4 != ctx->r1) {
        // 0x80800768: sb          $t5, 0xF($v0)
        MEM_B(0XF, ctx->r2) = ctx->r13;
            goto L_8080077C;
    }
    // 0x80800768: sb          $t5, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r13;
    // 0x8080076C: jal         0x8080067C
    // 0x80800770: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    glcutDll_entrypoint_22(rdram, ctx);
        goto after_2;
    // 0x80800770: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800774: b           L_80800784
    // 0x80800778: nop

        goto L_80800784;
    // 0x80800778: nop

L_8080077C:
    // 0x8080077C: jal         0x8080067C
    // 0x80800780: nop

    glcutDll_entrypoint_22(rdram, ctx);
        goto after_3;
    // 0x80800780: nop

    after_3:
L_80800784:
    // 0x80800784: jal         0x808004A8
    // 0x80800788: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    glcutDll_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800788: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8080078C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800790: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800794: bne         $a0, $at, L_808007AC
    if (ctx->r4 != ctx->r1) {
        // 0x80800798: nop
    
            goto L_808007AC;
    }
    // 0x80800798: nop

    // 0x8080079C: jal         0x808004CC
    // 0x808007A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    glcutDll_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808007A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x808007A4: b           L_808007B4
    // 0x808007A8: nop

        goto L_808007B4;
    // 0x808007A8: nop

L_808007AC:
    // 0x808007AC: jal         0x808004CC
    // 0x808007B0: nop

    glcutDll_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x808007B0: nop

    after_6:
L_808007B4:
    // 0x808007B4: jal         0x80800544
    // 0x808007B8: nop

    glcutDll_entrypoint_16(rdram, ctx);
        goto after_7;
    // 0x808007B8: nop

    after_7:
    // 0x808007BC: jal         0x80800000
    // 0x808007C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800000_glcutDll(rdram, ctx);
        goto after_8;
    // 0x808007C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void func_80800024_chmole_maya(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void gcstatusDll_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800148: jr          $ra
    // 0x8080014C: lw          $v0, -0x4C00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C00);
    return;
    // 0x8080014C: lw          $v0, -0x4C00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C00);
;}
RECOMP_FUNC void gczoombox_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808036E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808036E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808036EC: beq         $a0, $zero, L_80803714
    if (ctx->r4 == 0) {
        // 0x808036F0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80803714;
    }
    // 0x808036F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808036F4: lbu         $v1, 0x171($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X171);
    // 0x808036F8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808036FC: beq         $v1, $zero, L_80803714
    if (ctx->r3 == 0) {
        // 0x80803700: nop
    
            goto L_80803714;
    }
    // 0x80803700: nop

    // 0x80803704: beq         $v1, $at, L_80803714
    if (ctx->r3 == ctx->r1) {
        // 0x80803708: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80803714;
    }
    // 0x80803708: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080370C: bne         $v1, $at, L_8080371C
    if (ctx->r3 != ctx->r1) {
        // 0x80803710: addiu       $a0, $s0, 0xC0
        ctx->r4 = ADD32(ctx->r16, 0XC0);
            goto L_8080371C;
    }
    // 0x80803710: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
L_80803714:
    // 0x80803714: b           L_80803800
    // 0x80803718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803800;
    // 0x80803718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080371C:
    // 0x8080371C: jal         0x808001D4
    // 0x80803720: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803720: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x80803724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803728: jal         0x808001D4
    // 0x8080372C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_1;
    // 0x8080372C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_1:
    // 0x80803730: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80803734: jal         0x808001D4
    // 0x80803738: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_2;
    // 0x80803738: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_2:
    // 0x8080373C: lbu         $t8, 0x1E5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1E5);
    // 0x80803740: lbu         $t1, 0x1E4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80803744: sll         $t7, $zero, 7
    ctx->r15 = S32(0 << 7);
    // 0x80803748: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x8080374C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80803750: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x80803754: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x80803758: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x8080375C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80803760: andi        $t7, $t3, 0xFB
    ctx->r15 = ctx->r11 & 0XFB;
    // 0x80803764: or          $t1, $t5, $t7
    ctx->r9 = ctx->r13 | ctx->r15;
    // 0x80803768: sb          $t0, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r8;
    // 0x8080376C: sll         $t9, $zero, 3
    ctx->r25 = S32(0 << 3);
    // 0x80803770: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80803774: andi        $t2, $t1, 0xF7
    ctx->r10 = ctx->r9 & 0XF7;
    // 0x80803778: or          $t5, $t0, $t2
    ctx->r13 = ctx->r8 | ctx->r10;
    // 0x8080377C: sll         $t4, $zero, 5
    ctx->r12 = S32(0 << 5);
    // 0x80803780: sb          $t3, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r11;
    // 0x80803784: sb          $t1, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r9;
    // 0x80803788: andi        $t6, $t4, 0x20
    ctx->r14 = ctx->r12 & 0X20;
    // 0x8080378C: andi        $t7, $t5, 0xDF
    ctx->r15 = ctx->r13 & 0XDF;
    // 0x80803790: lbu         $v1, 0x171($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X171);
    // 0x80803794: or          $t0, $t6, $t7
    ctx->r8 = ctx->r14 | ctx->r15;
    // 0x80803798: sll         $t9, $zero, 6
    ctx->r25 = S32(0 << 6);
    // 0x8080379C: andi        $t1, $t9, 0x40
    ctx->r9 = ctx->r25 & 0X40;
    // 0x808037A0: andi        $t2, $t0, 0xBF
    ctx->r10 = ctx->r8 & 0XBF;
    // 0x808037A4: sb          $t5, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r13;
    // 0x808037A8: sb          $t0, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r8;
    // 0x808037AC: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x808037B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808037B4: sb          $t3, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r11;
    // 0x808037B8: sb          $zero, 0x19D($s0)
    MEM_B(0X19D, ctx->r16) = 0;
    // 0x808037BC: beq         $v1, $at, L_808037E4
    if (ctx->r3 == ctx->r1) {
        // 0x808037C0: sw          $zero, 0x1A0($s0)
        MEM_W(0X1A0, ctx->r16) = 0;
            goto L_808037E4;
    }
    // 0x808037C0: sw          $zero, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = 0;
    // 0x808037C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808037C8: beq         $v1, $at, L_808037E4
    if (ctx->r3 == ctx->r1) {
        // 0x808037CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808037E4;
    }
    // 0x808037CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808037D0: beq         $v1, $at, L_808037E4
    if (ctx->r3 == ctx->r1) {
        // 0x808037D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808037E4;
    }
    // 0x808037D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808037D8: beq         $v1, $at, L_808037E4
    if (ctx->r3 == ctx->r1) {
        // 0x808037DC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808037E4;
    }
    // 0x808037DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808037E0: bne         $v1, $at, L_808037F4
    if (ctx->r3 != ctx->r1) {
        // 0x808037E4: addiu       $t4, $zero, 0xA
        ctx->r12 = ADD32(0, 0XA);
            goto L_808037F4;
    }
L_808037E4:
    // 0x808037E4: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x808037E8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x808037EC: sb          $t4, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r12;
    // 0x808037F0: sb          $t5, 0x170($s0)
    MEM_B(0X170, ctx->r16) = ctx->r13;
L_808037F4:
    // 0x808037F4: jal         0x808033D0
    // 0x808037F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gczoombox_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x808037F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808037FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803800:
    // 0x80803800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803804: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080380C: jr          $ra
    // 0x80803810: nop

    return;
    // 0x80803810: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804318: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080431C: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB4E0) << 16);
    // 0x80804320: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80804324: jr          $ra
    // 0x80804328: lw          $v0, -0x4B20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB4E0));
    return;
    // 0x80804328: lw          $v0, -0x4B20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB4E0));
;}
RECOMP_FUNC void chvandoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1168, 0X640) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1168, 0X640));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x640
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1168, 0X640));
;}
RECOMP_FUNC void func_80801880_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080188C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801890: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801894: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801898: jal         0x800D8FF8
    // 0x8080189C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080189C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808018A0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808018A4: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808018A8: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808018AC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808018B0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808018B4: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x808018B8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808018BC: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808018C0: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808018C4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x808018C8: jal         0x800138D0
    // 0x808018CC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_800138D0(rdram, ctx);
        goto after_1;
    // 0x808018CC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x808018D0: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808018D4: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808018D8: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808018DC: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808018E0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808018E4: nop

    // 0x808018E8: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808018EC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x808018F0: jal         0x800138D0
    // 0x808018F4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    func_800138D0(rdram, ctx);
        goto after_2;
    // 0x808018F4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x808018F8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808018FC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801900: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80801904: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801908: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080190C: nop

    // 0x80801910: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801914: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80801918: jal         0x80013970
    // 0x8080191C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    func_80013970(rdram, ctx);
        goto after_3;
    // 0x8080191C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80801920: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801924: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801928: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080192C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801930: nop

    // 0x80801934: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801938: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8080193C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80801940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801944: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801948: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080194C: jr          $ra
    // 0x80801950: nop

    return;
    // 0x80801950: nop

;}
RECOMP_FUNC void func_800D530C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D530C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D5310: jr          $ra
    // 0x800D5314: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800D5314: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
