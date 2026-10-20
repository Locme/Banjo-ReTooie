#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chwaterfallfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086848: syscall     388
    recomp_syscall_handler(rdram, ctx, 0x80086848);
    return;
    // 0x8008684C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80803F94_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803F94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80803F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803FA0: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80803FA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803FA8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80803FAC: jal         0x80807D48
    // 0x80803FB0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80803FB0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80803FB4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80803FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803FBC: jal         0x80804848
    // 0x80803FC0: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    func_80804848_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80803FC0: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    after_1:
    // 0x80803FC4: jal         0x80801928
    // 0x80803FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801928_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80803FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80803FCC: jal         0x80801DC0
    // 0x80803FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DC0_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80803FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80803FD4: jal         0x80808EF0
    // 0x80803FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808EF0_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80803FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80803FDC: jal         0x80802F20
    // 0x80803FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802F20_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80803FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80803FE4: jal         0x80809198
    // 0x80803FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809198_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80803FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80803FEC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80803FF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803FF8: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    // 0x80803FFC: beq         $v0, $zero, L_8080401C
    if (ctx->r2 == 0) {
        // 0x80804000: nop
    
            goto L_8080401C;
    }
    // 0x80804000: nop

    // 0x80804004: beq         $v0, $at, L_80804064
    if (ctx->r2 == ctx->r1) {
        // 0x80804008: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804064;
    }
    // 0x80804008: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080400C: beq         $v0, $at, L_80804090
    if (ctx->r2 == ctx->r1) {
        // 0x80804010: nop
    
            goto L_80804090;
    }
    // 0x80804010: nop

    // 0x80804014: b           L_808040D4
    // 0x80804018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808040D4;
    // 0x80804018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080401C:
    // 0x8080401C: jal         0x8008DF8C
    // 0x80804020: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_7;
    // 0x80804020: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_7:
    // 0x80804024: beql        $v0, $zero, L_808040D4
    if (ctx->r2 == 0) {
        // 0x80804028: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808040D4;
    }
    goto skip_0;
    // 0x80804028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080402C: jal         0x8008CABC
    // 0x80804030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_8;
    // 0x80804030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80804034: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80804038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080403C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80804040: jal         0x8008B1D4
    // 0x80804044: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_9;
    // 0x80804044: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x80804048: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080404C: jal         0x8008B134
    // 0x80804050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_10;
    // 0x80804050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80804054: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80804058: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080405C: b           L_808040D0
    // 0x80804060: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
        goto L_808040D0;
    // 0x80804060: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_80804064:
    // 0x80804064: jal         0x8008E078
    // 0x80804068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_11;
    // 0x80804068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080406C: beq         $v0, $zero, L_808040D0
    if (ctx->r2 == 0) {
        // 0x80804070: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_808040D0;
    }
    // 0x80804070: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80804074: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80804078: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8080407C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80804080: jal         0x800F7F98
    // 0x80804084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_12;
    // 0x80804084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80804088: b           L_808040D4
    // 0x8080408C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808040D4;
    // 0x8080408C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804090:
    // 0x80804090: jal         0x80809D24
    // 0x80804094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x80804094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80804098: jal         0x8080682C
    // 0x8080409C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080682C_bsfirstp(rdram, ctx);
        goto after_14;
    // 0x8080409C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808040A0: jal         0x808099B4
    // 0x808040A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808099B4_bsfirstp(rdram, ctx);
        goto after_15;
    // 0x808040A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808040A8: jal         0x808094F4
    // 0x808040AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808094F4_bsfirstp(rdram, ctx);
        goto after_16;
    // 0x808040AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808040B0: addiu       $at, $zero, 0xCA
    ctx->r1 = ADD32(0, 0XCA);
    // 0x808040B4: bne         $v0, $at, L_808040D0
    if (ctx->r2 != ctx->r1) {
        // 0x808040B8: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_808040D0;
    }
    // 0x808040B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808040BC: jal         0x8008CAEC
    // 0x808040C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_17;
    // 0x808040C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808040C4: bnel        $v0, $zero, L_808040D4
    if (ctx->r2 != 0) {
        // 0x808040C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808040D4;
    }
    goto skip_1;
    // 0x808040C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808040CC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_808040D0:
    // 0x808040D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808040D4:
    // 0x808040D4: jal         0x8009E5C8
    // 0x808040D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x808040D8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x808040DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808040E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808040E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808040E8: jr          $ra
    // 0x808040EC: nop

    return;
    // 0x808040EC: nop

;}
RECOMP_FUNC void _chhagstraindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087068: syscall     501
    recomp_syscall_handler(rdram, ctx, 0x80087068);
    return;
    // 0x8008706C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80098E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098E64: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80098E68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098E6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80098E70: jal         0x800A3274
    // 0x80098E74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80098E74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80098E78: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80098E7C: bne         $v0, $at, L_80098EA4
    if (ctx->r2 != ctx->r1) {
        // 0x80098E80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80098EA4;
    }
    // 0x80098E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098E84: jal         0x80095738
    // 0x80098E88: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x80098E88: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80098E8C: beq         $v0, $zero, L_80098EA4
    if (ctx->r2 == 0) {
        // 0x80098E90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80098EA4;
    }
    // 0x80098E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098E94: jal         0x800A3410
    // 0x80098E98: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_800A3410(rdram, ctx);
        goto after_2;
    // 0x80098E98: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_2:
    // 0x80098E9C: jal         0x800F8EBC
    // 0x80098EA0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8EBC(rdram, ctx);
        goto after_3;
    // 0x80098EA0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_3:
L_80098EA4:
    // 0x80098EA4: jal         0x8009E6F8
    // 0x80098EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_4;
    // 0x80098EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80098EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098EB0: jal         0x8009CBDC
    // 0x80098EB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CBDC(rdram, ctx);
        goto after_5;
    // 0x80098EB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80098EB8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80098EBC: jal         0x8008DAA8
    // 0x80098EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DAA8(rdram, ctx);
        goto after_6;
    // 0x80098EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80098EC4: beql        $v0, $zero, L_80099024
    if (ctx->r2 == 0) {
        // 0x80098EC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099024;
    }
    goto skip_0;
    // 0x80098EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80098ECC: jal         0x8009E880
    // 0x80098ED0: nop

    func_8009E880(rdram, ctx);
        goto after_7;
    // 0x80098ED0: nop

    after_7:
    // 0x80098ED4: jal         0x800A81C4
    // 0x80098ED8: nop

    func_800A81C4(rdram, ctx);
        goto after_8;
    // 0x80098ED8: nop

    after_8:
    // 0x80098EDC: bnel        $v0, $zero, L_80098EF4
    if (ctx->r2 != 0) {
        // 0x80098EE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80098EF4;
    }
    goto skip_1;
    // 0x80098EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80098EE4: jal         0x800EA068
    // 0x80098EE8: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    func_800EA068(rdram, ctx);
        goto after_9;
    // 0x80098EE8: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_9:
    // 0x80098EEC: beq         $v0, $zero, L_80098EFC
    if (ctx->r2 == 0) {
        // 0x80098EF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80098EFC;
    }
    // 0x80098EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80098EF4:
    // 0x80098EF4: jal         0x80085008
    // 0x80098EF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80098EF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_80098EFC:
    // 0x80098EFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80098F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098F04: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80098F08: jal         0x8008E39C
    // 0x80098F0C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_8008E39C(rdram, ctx);
        goto after_11;
    // 0x80098F0C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80098F10: beq         $v0, $zero, L_80098F30
    if (ctx->r2 == 0) {
        // 0x80098F14: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80098F30;
    }
    // 0x80098F14: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80098F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098F1C: jal         0x80091538
    // 0x80098F20: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_get(rdram, ctx);
        goto after_12;
    // 0x80098F20: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80098F24: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80098F28: b           L_80098F4C
    // 0x80098F2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80098F4C;
    // 0x80098F2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80098F30:
    // 0x80098F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098F34: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80098F38: jal         0x8009E674
    // 0x80098F3C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_8009E674(rdram, ctx);
        goto after_13;
    // 0x80098F3C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_13:
    // 0x80098F40: beq         $v0, $zero, L_80098F4C
    if (ctx->r2 == 0) {
        // 0x80098F44: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80098F4C;
    }
    // 0x80098F44: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80098F48: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80098F4C:
    // 0x80098F4C: beq         $v1, $zero, L_80098F5C
    if (ctx->r3 == 0) {
        // 0x80098F50: nop
    
            goto L_80098F5C;
    }
    // 0x80098F50: nop

    // 0x80098F54: jal         0x8009EAD0
    // 0x80098F58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8009EAD0(rdram, ctx);
        goto after_14;
    // 0x80098F58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
L_80098F5C:
    // 0x80098F5C: jal         0x8009EB0C
    // 0x80098F60: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_8009EB0C(rdram, ctx);
        goto after_15;
    // 0x80098F60: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80098F64: jal         0x80084FE0
    // 0x80098F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x80098F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80098F6C: jal         0x8009EAF4
    // 0x80098F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8009EAF4(rdram, ctx);
        goto after_17;
    // 0x80098F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x80098F74: jal         0x800A3274
    // 0x80098F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_18;
    // 0x80098F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80098F7C: jal         0x8009E9D8
    // 0x80098F80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8009E9D8(rdram, ctx);
        goto after_19;
    // 0x80098F80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x80098F84: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80098F88: jal         0x8009E9FC
    // 0x80098F8C: nop

    func_8009E9FC(rdram, ctx);
        goto after_20;
    // 0x80098F8C: nop

    after_20:
    // 0x80098F90: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80098F94: addiu       $t7, $t6, -0x8
    ctx->r15 = ADD32(ctx->r14, -0X8);
    // 0x80098F98: sltiu       $at, $t7, 0xD
    ctx->r1 = ctx->r15 < 0XD ? 1 : 0;
    // 0x80098F9C: beq         $at, $zero, L_80099020
    if (ctx->r1 == 0) {
        // 0x80098FA0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80099020;
    }
    // 0x80098FA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80098FA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098FA8: addu        $at, $at, $t7
    gpr jr_addend_80098FB0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80098FAC: lw          $t7, 0x4E30($at)
    ctx->r15 = ADD32(ctx->r1, 0X4E30);
    // 0x80098FB0: jr          $t7
    // 0x80098FB4: nop

    switch (jr_addend_80098FB0 >> 2) {
        case 0: goto L_80098FB8; break;
        case 1: goto L_80098FD4; break;
        case 2: goto L_80099020; break;
        case 3: goto L_80099020; break;
        case 4: goto L_80099020; break;
        case 5: goto L_80099020; break;
        case 6: goto L_80099020; break;
        case 7: goto L_80099020; break;
        case 8: goto L_80099020; break;
        case 9: goto L_80099020; break;
        case 10: goto L_80098FF8; break;
        case 11: goto L_80099008; break;
        case 12: goto L_80099018; break;
        default: switch_error(__func__, 0x80098FB0, 0x80124E30);
    }
    // 0x80098FB4: nop

L_80098FB8:
    // 0x80098FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098FBC: jal         0x80091538
    // 0x80098FC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_get(rdram, ctx);
        goto after_21;
    // 0x80098FC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x80098FC4: jal         0x8009E9FC
    // 0x80098FC8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8009E9FC(rdram, ctx);
        goto after_22;
    // 0x80098FC8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_22:
    // 0x80098FCC: b           L_80099024
    // 0x80098FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80099024;
    // 0x80098FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80098FD4:
    // 0x80098FD4: jal         0x800A3274
    // 0x80098FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_23;
    // 0x80098FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80098FDC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80098FE0: bnel        $v0, $at, L_80099024
    if (ctx->r2 != ctx->r1) {
        // 0x80098FE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80099024;
    }
    goto skip_2;
    // 0x80098FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80098FE8: jal         0x8009EAD0
    // 0x80098FEC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8009EAD0(rdram, ctx);
        goto after_24;
    // 0x80098FEC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_24:
    // 0x80098FF0: b           L_80099024
    // 0x80098FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80099024;
    // 0x80098FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80098FF8:
    // 0x80098FF8: jal         0x8009EAD0
    // 0x80098FFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8009EAD0(rdram, ctx);
        goto after_25;
    // 0x80098FFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_25:
    // 0x80099000: b           L_80099024
    // 0x80099004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80099024;
    // 0x80099004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099008:
    // 0x80099008: jal         0x8009EAD0
    // 0x8009900C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8009EAD0(rdram, ctx);
        goto after_26;
    // 0x8009900C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_26:
    // 0x80099010: b           L_80099024
    // 0x80099014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80099024;
    // 0x80099014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099018:
    // 0x80099018: jal         0x8009EAD0
    // 0x8009901C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8009EAD0(rdram, ctx);
        goto after_27;
    // 0x8009901C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_27:
L_80099020:
    // 0x80099020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80099024:
    // 0x80099024: jal         0x8009E71C
    // 0x80099028: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8009E71C(rdram, ctx);
        goto after_28;
    // 0x80099028: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x8009902C: beq         $v0, $zero, L_8009903C
    if (ctx->r2 == 0) {
        // 0x80099030: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8009903C;
    }
    // 0x80099030: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80099034: b           L_80099040
    // 0x80099038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80099040;
    // 0x80099038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8009903C:
    // 0x8009903C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80099040:
    // 0x80099040: jal         0x800EA068
    // 0x80099044: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EA068(rdram, ctx);
        goto after_29;
    // 0x80099044: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_29:
    // 0x80099048: beq         $v0, $zero, L_80099058
    if (ctx->r2 == 0) {
        // 0x8009904C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80099058;
    }
    // 0x8009904C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80099050: b           L_8009905C
    // 0x80099054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009905C;
    // 0x80099054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80099058:
    // 0x80099058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009905C:
    // 0x8009905C: jal         0x8009EB18
    // 0x80099060: and         $a0, $a1, $v0
    ctx->r4 = ctx->r5 & ctx->r2;
    func_8009EB18(rdram, ctx);
        goto after_30;
    // 0x80099060: and         $a0, $a1, $v0
    ctx->r4 = ctx->r5 & ctx->r2;
    after_30:
    // 0x80099064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80099068: jal         0x8009E5C8
    // 0x8009906C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    bs_setState(rdram, ctx);
        goto after_31;
    // 0x8009906C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_31:
    // 0x80099070: jal         0x80084450
    // 0x80099074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baattach_entrypoint_3(rdram, ctx);
        goto after_32;
    // 0x80099074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80099078: jal         0x8008E6BC
    // 0x8009907C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E6BC(rdram, ctx);
        goto after_33;
    // 0x8009907C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80099080: jal         0x80091054
    // 0x80099084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091054(rdram, ctx);
        goto after_34;
    // 0x80099084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80099088: jal         0x80084478
    // 0x8009908C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_1(rdram, ctx);
        goto after_35;
    // 0x8009908C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80099090: jal         0x80091648
    // 0x80099094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastatetimerlist_free(rdram, ctx);
        goto after_36;
    // 0x80099094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80099098: jal         0x80084AD0
    // 0x8009909C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_4(rdram, ctx);
        goto after_37;
    // 0x8009909C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x800990A0: jal         0x80094538
    // 0x800990A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094538(rdram, ctx);
        goto after_38;
    // 0x800990A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x800990A8: jal         0x80092A1C
    // 0x800990AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092A1C(rdram, ctx);
        goto after_39;
    // 0x800990AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x800990B0: jal         0x800A22A8
    // 0x800990B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A22A8(rdram, ctx);
        goto after_40;
    // 0x800990B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x800990B8: jal         0x8008C864
    // 0x800990BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_free(rdram, ctx);
        goto after_41;
    // 0x800990BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x800990C0: jal         0x80095C10
    // 0x800990C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095C10(rdram, ctx);
        goto after_42;
    // 0x800990C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x800990C8: jal         0x80084D28
    // 0x800990CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bahold_entrypoint_2(rdram, ctx);
        goto after_43;
    // 0x800990CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x800990D0: jal         0x80084F10
    // 0x800990D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamum_entrypoint_1(rdram, ctx);
        goto after_44;
    // 0x800990D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x800990D8: jal         0x80084FB8
    // 0x800990DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basetup_entrypoint_3(rdram, ctx);
        goto after_45;
    // 0x800990DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x800990E0: jal         0x8009D5E0
    // 0x800990E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D5E0(rdram, ctx);
        goto after_46;
    // 0x800990E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x800990E8: jal         0x800A2058
    // 0x800990EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2058(rdram, ctx);
        goto after_47;
    // 0x800990EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x800990F0: jal         0x80084FF0
    // 0x800990F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_3(rdram, ctx);
        goto after_48;
    // 0x800990F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x800990F8: jal         0x800850B8
    // 0x800990FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basquash_entrypoint_1(rdram, ctx);
        goto after_49;
    // 0x800990FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80099100: jal         0x800A2D70
    // 0x80099104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2D70(rdram, ctx);
        goto after_50;
    // 0x80099104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80099108: jal         0x80085348
    // 0x8009910C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _batranslate_entrypoint_1(rdram, ctx);
        goto after_51;
    // 0x8009910C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80099110: jal         0x80085170
    // 0x80099114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bastatemem_entrypoint_2(rdram, ctx);
        goto after_52;
    // 0x80099114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80099118: jal         0x80084908
    // 0x8009911C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badronemem_entrypoint_2(rdram, ctx);
        goto after_53;
    // 0x8009911C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80099120: jal         0x80084770
    // 0x80099124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapackctrl_entrypoint_2(rdram, ctx);
        goto after_54;
    // 0x80099124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80099128: jal         0x80084940
    // 0x8009912C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_5(rdram, ctx);
        goto after_55;
    // 0x8009912C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80099130: jal         0x8009E388
    // 0x80099134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E388(rdram, ctx);
        goto after_56;
    // 0x80099134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80099138: jal         0x80084CB0
    // 0x8009913C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_7(rdram, ctx);
        goto after_57;
    // 0x8009913C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80099140: jal         0x80091E18
    // 0x80099144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091E18(rdram, ctx);
        goto after_58;
    // 0x80099144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80099148: jal         0x80091AB8
    // 0x8009914C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bakey_free(rdram, ctx);
        goto after_59;
    // 0x8009914C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80099150: jal         0x80084620
    // 0x80099154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bacough_entrypoint_2(rdram, ctx);
        goto after_60;
    // 0x80099154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80099158: jal         0x80085508
    // 0x8009915C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badeathmatch_entrypoint_2(rdram, ctx);
        goto after_61;
    // 0x8009915C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80099160: jal         0x80091EA8
    // 0x80099164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091EA8(rdram, ctx);
        goto after_62;
    // 0x80099164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80099168: jal         0x800854C8
    // 0x8009916C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bainvisible_entrypoint_4(rdram, ctx);
        goto after_63;
    // 0x8009916C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80099170: jal         0x8009AD88
    // 0x80099174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009AD88(rdram, ctx);
        goto after_64;
    // 0x80099174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x80099178: jal         0x800A4160
    // 0x8009917C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4160(rdram, ctx);
        goto after_65;
    // 0x8009917C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80099180: lw          $t8, 0xB8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB8);
    // 0x80099184: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x80099188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009918C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80099190: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80099194: jr          $ra
    // 0x80099198: nop

    return;
    // 0x80099198: nop

;}
RECOMP_FUNC void func_80109EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109EF4: lhu         $t6, 0x66($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X66);
    // 0x80109EF8: nor         $t7, $a1, $zero
    ctx->r15 = ~(ctx->r5 | 0);
    // 0x80109EFC: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80109F00: jr          $ra
    // 0x80109F04: sh          $t8, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r24;
    return;
    // 0x80109F04: sh          $t8, 0x66($a0)
    MEM_H(0X66, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80800170_chdiggerbossbattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800178: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080017C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800180: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800184: beq         $a1, $at, L_808002B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800188: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_808002B4;
    }
    // 0x80800188: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080018C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800190: beq         $a1, $at, L_808001B4
    if (ctx->r5 == ctx->r1) {
        // 0x80800194: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_808001B4;
    }
    // 0x80800194: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800198: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080019C: beq         $a1, $at, L_80800244
    if (ctx->r5 == ctx->r1) {
        // 0x808001A0: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800244;
    }
    // 0x808001A0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808001A4: beq         $a1, $at, L_8080028C
    if (ctx->r5 == ctx->r1) {
        // 0x808001A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080028C;
    }
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: b           L_808002DC
    // 0x808001B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002DC;
    // 0x808001B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001B4:
    // 0x808001B4: jal         0x800EE7F8
    // 0x808001B8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808001B8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_0:
    // 0x808001BC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001C0: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808001C4: jal         0x800EF1B8
    // 0x808001C8: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808001C8: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    after_1:
    // 0x808001CC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808001D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808001DC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x808001E0: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808001E4: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x808001E8: jal         0x800DA544
    // 0x808001EC: addiu       $a0, $t6, 0xA1D
    ctx->r4 = ADD32(ctx->r14, 0XA1D);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808001EC: addiu       $a0, $t6, 0xA1D
    ctx->r4 = ADD32(ctx->r14, 0XA1D);
    after_2:
    // 0x808001F0: jal         0x8010A624
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_3;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800200: jal         0x80086670
    // 0x80800204: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800204: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_4:
    // 0x80800208: jal         0x800FC660
    // 0x8080020C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x8080020C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_5:
    // 0x80800210: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080021C: sll         $t7, $a1, 11
    ctx->r15 = S32(ctx->r5 << 11);
    // 0x80800220: srl         $a1, $t7, 20
    ctx->r5 = S32(U32(ctx->r15) >> 20);
    // 0x80800224: jal         0x80089C28
    // 0x80800228: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800228: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8080022C: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808002D8;
    }
    // 0x80800230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800234: jal         0x8010A570
    // 0x80800238: nop

    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80800238: nop

    after_7:
    // 0x8080023C: b           L_808002DC
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002DC;
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800244:
    // 0x80800244: jal         0x80101080
    // 0x80800248: nop

    func_80101080(rdram, ctx);
        goto after_8;
    // 0x80800248: nop

    after_8:
    // 0x8080024C: jal         0x80106790
    // 0x80800250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_9;
    // 0x80800250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800254: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800260: jal         0x800866A0
    // 0x80800264: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80800264: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800270: jal         0x800866D0
    // 0x80800274: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_11;
    // 0x80800274: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x800866C0
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800284: b           L_808002DC
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002DC;
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080028C:
    // 0x8080028C: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x80800290: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1496, 0X2E8) << 16);
    // 0x80800294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800298: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x8080029C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x808002A0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x808002A4: jal         0x80103140
    // 0x808002A8: lhu         $a1, 0x2E8($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1496, 0X2E8));
    func_80103140(rdram, ctx);
        goto after_13;
    // 0x808002A8: lhu         $a1, 0x2E8($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1496, 0X2E8));
    after_13:
    // 0x808002AC: b           L_808002DC
    // 0x808002B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002DC;
    // 0x808002B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002B4:
    // 0x808002B4: jal         0x801015D0
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_14;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808002BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808002C0: jal         0x800DF744
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808002C8: b           L_808002DC
    // 0x808002CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002DC;
    // 0x808002CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002D0: b           L_808002DC
    // 0x808002D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002DC;
    // 0x808002D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002D8:
    // 0x808002D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002DC:
    // 0x808002DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_80109524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109524: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80109528: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8010952C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80109530: jr          $ra
    // 0x80109534: lh          $v0, 0x45A0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X45A0);
    return;
    // 0x80109534: lh          $v0, 0x45A0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X45A0);
;}
RECOMP_FUNC void func_80806648_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080664C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806650: jal         0x80100094
    // 0x80806654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806658: sb          $zero, 0x78($v0)
    MEM_B(0X78, ctx->r2) = 0;
    // 0x8080665C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806664: jr          $ra
    // 0x80806668: nop

    return;
    // 0x80806668: nop

;}
RECOMP_FUNC void func_801127A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801127A0: jr          $ra
    // 0x801127A4: addiu       $v0, $zero, 0x24
    ctx->r2 = ADD32(0, 0X24);
    return;
    // 0x801127A4: addiu       $v0, $zero, 0x24
    ctx->r2 = ADD32(0, 0X24);
;}
RECOMP_FUNC void subaddiefind_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800284: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800288: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080028C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800290: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x80800294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800298: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080029C: jal         0x801067C4
    // 0x808002A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x808002A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808002A4: beq         $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808002FC;
    }
    // 0x808002A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808002AC:
    // 0x808002AC: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x808002B0: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x808002B4: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808002B8: bne         $s0, $t8, L_808002EC
    if (ctx->r16 != ctx->r24) {
        // 0x808002BC: nop
    
            goto L_808002EC;
    }
    // 0x808002BC: nop

    // 0x808002C0: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x808002C4: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x808002C8: bltz        $t1, L_808002EC
    if (SIGNED(ctx->r9) < 0) {
        // 0x808002CC: nop
    
            goto L_808002EC;
    }
    // 0x808002CC: nop

    // 0x808002D0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808002D4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x808002D8: beq         $v0, $zero, L_808002E4
    if (ctx->r2 == 0) {
        // 0x808002DC: nop
    
            goto L_808002E4;
    }
    // 0x808002DC: nop

    // 0x808002E0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_808002E4:
    // 0x808002E4: b           L_80800300
    // 0x808002E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800300;
    // 0x808002E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808002EC:
    // 0x808002EC: jal         0x8010682C
    // 0x808002F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x808002F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808002F4: bne         $v0, $zero, L_808002AC
    if (ctx->r2 != 0) {
        // 0x808002F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808002AC;
    }
    // 0x808002F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808002FC:
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800300:
    // 0x80800300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800304: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800308: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080030C: jr          $ra
    // 0x80800310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8009337C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009337C: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093380: jr          $ra
    // 0x80093384: sb          $a1, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r5;
    return;
    // 0x80093384: sb          $a1, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808003B0_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003BC: jal         0x800F54E4
    // 0x808003C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808003C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003C8: jal         0x800F82D4
    // 0x808003CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x808003CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808003D0: jal         0x800F54E4
    // 0x808003D4: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808003D4: nop

    after_2:
    // 0x808003D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003DC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x808003E0: jal         0x800F7C0C
    // 0x808003E4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800F7C0C(rdram, ctx);
        goto after_3;
    // 0x808003E4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_3:
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: jal         0x8080082C
    // 0x808003F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_4;
    // 0x808003F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x808003F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808003F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003FC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800400: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800404: jal         0x800DC298
    // 0x80800408: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80800408: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x8080040C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800410: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80800414: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80800418: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8080041C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800420: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800424: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800428: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    // 0x8080042C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800430: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80800434: bgez        $t4, L_80800444
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800438: nop
    
            goto L_80800444;
    }
    // 0x80800438: nop

    // 0x8080043C: jal         0x80101180
    // 0x80800440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_80800444:
    // 0x80800444: jal         0x80085710
    // 0x80800448: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_7;
    // 0x80800448: nop

    after_7:
    // 0x8080044C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800450: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800454: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800458: jr          $ra
    // 0x8080045C: nop

    return;
    // 0x8080045C: nop

;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080018C: jal         0x80800110
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800110_bskazshoessuckspline(rdram, ctx);
        goto after_0;
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800194: jal         0x800832E8
    // 0x80800198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887D8: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887D8);
    return;
    // 0x800887DC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bsbansack_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808015D4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E70) << 16);
    // 0x808015D8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808015DC: jr          $ra
    // 0x808015E0: lw          $v0, 0x1E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E70));
    return;
    // 0x808015E0: lw          $v0, 0x1E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E70));
;}
RECOMP_FUNC void _gcnewoption_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D70: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D70);
    return;
    // 0x80087D74: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void _chwandglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087308: syscall     549
    recomp_syscall_handler(rdram, ctx, 0x80087308);
    return;
    // 0x8008730C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chfactorymagnet_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874C8: syscall     579
    recomp_syscall_handler(rdram, ctx, 0x800874C8);
    return;
    // 0x800874CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800048_ncbadie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: jal         0x80112524
    // 0x80800054: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800054: nop

    after_0:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void fxdialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808000A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808000AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808000B0: jal         0x801040D0
    // 0x808000B4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_801040D0(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x808000B8: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x808000BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2858, 0X280) << 16);
    // 0x808000C4: lwc1        $f8, 0x280($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2858, 0X280));
    // 0x808000C8: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808000CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2858, 0X2A4) << 16);
    // 0x808000D0: lwc1        $f16, 0x2A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2858, 0X2A4));
    // 0x808000D4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808000D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808000DC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x808000E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000F0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808000F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000FC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800100: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800104: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800108: jal         0x800EFA4C
    // 0x8080010C: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080010C: nop

    after_1:
    // 0x80800110: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800114: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80800118: jal         0x800DFFA0
    // 0x8080011C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800DFFA0(rdram, ctx);
        goto after_2;
    // 0x8080011C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800120: jal         0x800DF41C
    // 0x80800124: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800DF41C(rdram, ctx);
        goto after_3;
    // 0x80800124: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80800128: jal         0x800DF410
    // 0x8080012C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800DF410(rdram, ctx);
        goto after_4;
    // 0x8080012C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_4:
    // 0x80800130: jal         0x800D674C
    // 0x80800134: addiu       $a0, $zero, 0x9F1
    ctx->r4 = ADD32(0, 0X9F1);
    func_800D674C(rdram, ctx);
        goto after_5;
    // 0x80800134: addiu       $a0, $zero, 0x9F1
    ctx->r4 = ADD32(0, 0X9F1);
    after_5:
    // 0x80800138: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8080013C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800140: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800144: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80800148: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2858, 0X290) << 16);
    // 0x8080014C: addiu       $a1, $a1, 0x290
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2858, 0X290));
    // 0x80800150: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800154: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x80800158: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080015C: lw          $a3, 0x10($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X10);
    // 0x80800160: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800164: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800168: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080016C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800170: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800174: jal         0x800DF944
    // 0x80800178: nop

    func_800DF944(rdram, ctx);
        goto after_6;
    // 0x80800178: nop

    after_6:
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800180: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
RECOMP_FUNC void func_80800E78_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E80: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x80800E84: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800E88: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800E8C: addiu       $a0, $t6, -0x31
    ctx->r4 = ADD32(ctx->r14, -0X31);
    // 0x80800E90: jal         0x800D0A9C
    // 0x80800E94: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x80800E94: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E98: beq         $v0, $zero, L_80800EA8
    if (ctx->r2 == 0) {
        // 0x80800E9C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EA8;
    }
    // 0x80800E9C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EA0: b           L_80800EAC
    // 0x80800EA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EAC;
    // 0x80800EA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EA8:
    // 0x80800EA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80800EAC:
    // 0x80800EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EB4: jr          $ra
    // 0x80800EB8: nop

    return;
    // 0x80800EB8: nop

;}
RECOMP_FUNC void suquiz_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009AC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808009B0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808009B4: sltiu       $at, $a0, 0x6
    ctx->r1 = ctx->r4 < 0X6 ? 1 : 0;
    // 0x808009B8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808009BC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808009C0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808009C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808009C8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808009CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009D0: beq         $at, $zero, L_80800A58
    if (ctx->r1 == 0) {
        // 0x808009D4: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_80800A58;
    }
    // 0x808009D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808009D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF44) << 16);
    // 0x808009E0: addu        $at, $at, $t6
    gpr jr_addend_808009E8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808009E4: lw          $t6, 0xF44($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF44));
    // 0x808009E8: jr          $t6
    // 0x808009EC: nop

    switch (jr_addend_808009E8 >> 2) {
        case 0: goto L_808009F0; break;
        case 1: goto L_80800A18; break;
        case 2: goto L_808009F0; break;
        case 3: goto L_80800A58; break;
        case 4: goto L_80800A30; break;
        case 5: goto L_80800A58; break;
        default: switch_error(__func__, 0x808009E8, 0x80800F44);
    }
    // 0x808009EC: nop

L_808009F0:
    // 0x808009F0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x808009F4: addiu       $s3, $s3, 0x7614
    ctx->r19 = ADD32(ctx->r19, 0X7614);
    // 0x808009F8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x808009FC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800A00: sb          $v1, 0x26($t7)
    MEM_B(0X26, ctx->r15) = ctx->r3;
    // 0x80800A04: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80800A08: sb          $v1, 0x28($t8)
    MEM_B(0X28, ctx->r24) = ctx->r3;
    // 0x80800A0C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80800A10: b           L_80800A58
    // 0x80800A14: sb          $v1, 0x29($t9)
    MEM_B(0X29, ctx->r25) = ctx->r3;
        goto L_80800A58;
    // 0x80800A14: sb          $v1, 0x29($t9)
    MEM_B(0X29, ctx->r25) = ctx->r3;
L_80800A18:
    // 0x80800A18: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80800A1C: addiu       $s3, $s3, 0x7614
    ctx->r19 = ADD32(ctx->r19, 0X7614);
    // 0x80800A20: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80800A24: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800A28: b           L_80800A58
    // 0x80800A2C: sb          $v1, 0x26($t0)
    MEM_B(0X26, ctx->r8) = ctx->r3;
        goto L_80800A58;
    // 0x80800A2C: sb          $v1, 0x26($t0)
    MEM_B(0X26, ctx->r8) = ctx->r3;
L_80800A30:
    // 0x80800A30: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80800A34: addiu       $s3, $s3, 0x7614
    ctx->r19 = ADD32(ctx->r19, 0X7614);
    // 0x80800A38: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80800A3C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800A40: lb          $t1, 0x28($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X28);
    // 0x80800A44: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x80800A48: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80800A4C: sb          $v1, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r3;
    // 0x80800A50: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80800A54: sb          $v1, 0x28($t3)
    MEM_B(0X28, ctx->r11) = ctx->r3;
L_80800A58:
    // 0x80800A58: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80800A5C: beq         $s4, $zero, L_80800A88
    if (ctx->r20 == 0) {
        // 0x80800A60: addiu       $s3, $s3, 0x7614
        ctx->r19 = ADD32(ctx->r19, 0X7614);
            goto L_80800A88;
    }
    // 0x80800A60: addiu       $s3, $s3, 0x7614
    ctx->r19 = ADD32(ctx->r19, 0X7614);
    // 0x80800A64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A68: beq         $s4, $at, L_80800A88
    if (ctx->r20 == ctx->r1) {
        // 0x80800A6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A88;
    }
    // 0x80800A6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A70: beq         $s4, $at, L_80800A88
    if (ctx->r20 == ctx->r1) {
        // 0x80800A74: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800A88;
    }
    // 0x80800A74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A78: beq         $s4, $at, L_80800A88
    if (ctx->r20 == ctx->r1) {
        // 0x80800A7C: nop
    
            goto L_80800A88;
    }
    // 0x80800A7C: nop

    // 0x80800A80: b           L_80800BDC
    // 0x80800A84: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
        goto L_80800BDC;
    // 0x80800A84: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80800A88:
    // 0x80800A88: jal         0x800D3948
    // 0x80800A8C: nop

    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800A8C: nop

    after_0:
    // 0x80800A90: beq         $v0, $zero, L_80800AA4
    if (ctx->r2 == 0) {
        // 0x80800A94: addiu       $s2, $zero, 0x2
        ctx->r18 = ADD32(0, 0X2);
            goto L_80800AA4;
    }
    // 0x80800A94: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80800A98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800A9C: b           L_80800AA8
    // 0x80800AA0: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
        goto L_80800AA8;
    // 0x80800AA0: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
L_80800AA4:
    // 0x80800AA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AA8:
    // 0x80800AA8: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800AAC: bne         $at, $zero, L_80800BD8
    if (ctx->r1 != 0) {
        // 0x80800AB0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800BD8;
    }
    // 0x80800AB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800AB4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80800AB8:
    // 0x80800AB8: lb          $t5, 0x29($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X29);
    // 0x80800ABC: beql        $s0, $t5, L_80800BCC
    if (ctx->r16 == ctx->r13) {
        // 0x80800AC0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800BCC;
    }
    goto skip_0;
    // 0x80800AC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80800AC4: jal         0x808006C4
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    suquiz_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800ACC: bnel        $v0, $zero, L_80800BCC
    if (ctx->r2 != 0) {
        // 0x80800AD0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800BCC;
    }
    goto skip_1;
    // 0x80800AD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80800AD4: jal         0x8080074C
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    suquiz_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800ADC: bnel        $v0, $zero, L_80800BCC
    if (ctx->r2 != 0) {
        // 0x80800AE0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800BCC;
    }
    goto skip_2;
    // 0x80800AE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80800AE4: jal         0x80800000
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_suquiz(rdram, ctx);
        goto after_3;
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800AEC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800AF8: jal         0x80800074
    // 0x80800AFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80800074_suquiz(rdram, ctx);
        goto after_4;
    // 0x80800AFC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80800B00: jal         0x800DC0C0
    // 0x80800B04: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800B04: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x80800B08: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80800B0C: nop

    // 0x80800B10: bc1fl       L_80800BCC
    if (!c1cs) {
        // 0x80800B14: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800BCC;
    }
    goto skip_3;
    // 0x80800B14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x80800B18: jal         0x80800584
    // 0x80800B1C: nop

    suquiz_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800B1C: nop

    after_6:
    // 0x80800B20: jal         0x80800584
    // 0x80800B24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    suquiz_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800B24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_7:
    // 0x80800B28: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80800B2C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80800B30: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3370, 0XF90) << 16);
    // 0x80800B34: addiu       $a0, $a0, 0xF90
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3370, 0XF90));
    // 0x80800B38: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80800B3C: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80800B40: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x80800B44: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80800B48: sll         $v1, $s4, 3
    ctx->r3 = S32(ctx->r20 << 3);
    // 0x80800B4C: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80800B50: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80800B54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF5C) << 16);
    // 0x80800B58: lwc1        $f6, 0xF5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF5C));
    // 0x80800B5C: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80800B60: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800B64: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80800B68: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800B6C: jal         0x800DC178
    // 0x80800B70: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800B70: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_8:
    // 0x80800B74: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800B80: jal         0x8080009C
    // 0x80800B84: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8080009C_suquiz(rdram, ctx);
        goto after_9;
    // 0x80800B84: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x80800B88: jal         0x800DC0C0
    // 0x80800B8C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_10;
    // 0x80800B8C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80800B90: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80800B94: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80800B98: sb          $s0, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r16;
    // 0x80800B9C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80800BA0: swc1        $f20, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f20.u32l;
    // 0x80800BA4: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800BA8: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80800BAC: nop

    // 0x80800BB0: bc1fl       L_80800BC0
    if (!c1cs) {
        // 0x80800BB4: lw          $t5, 0x0($s3)
        ctx->r13 = MEM_W(ctx->r19, 0X0);
            goto L_80800BC0;
    }
    goto skip_4;
    // 0x80800BB4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    skip_4:
    // 0x80800BB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800BBC: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
L_80800BC0:
    // 0x80800BC0: b           L_80800BD8
    // 0x80800BC4: sb          $t4, 0x27($t5)
    MEM_B(0X27, ctx->r13) = ctx->r12;
        goto L_80800BD8;
    // 0x80800BC4: sb          $t4, 0x27($t5)
    MEM_B(0X27, ctx->r13) = ctx->r12;
    // 0x80800BC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800BCC:
    // 0x80800BCC: addiu       $t6, $s2, 0x1
    ctx->r14 = ADD32(ctx->r18, 0X1);
    // 0x80800BD0: bnel        $t6, $s0, L_80800AB8
    if (ctx->r14 != ctx->r16) {
        // 0x80800BD4: lw          $t4, 0x0($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X0);
            goto L_80800AB8;
    }
    goto skip_5;
    // 0x80800BD4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    skip_5:
L_80800BD8:
    // 0x80800BD8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80800BDC:
    // 0x80800BDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800BE0: nop

    // 0x80800BE4: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x80800BE8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80800BEC: sb          $s4, 0x25($t7)
    MEM_B(0X25, ctx->r15) = ctx->r20;
    // 0x80800BF0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800BF4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800BF8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BFC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800C00: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800C04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C08: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800C0C: jr          $ra
    // 0x80800C10: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800C10: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void suinv_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800018: jal         0x800D1C38
    // 0x8080001C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800D1C38(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80800020: bne         $v0, $zero, L_80800040
    if (ctx->r2 != 0) {
        // 0x80800024: nop
    
            goto L_80800040;
    }
    // 0x80800024: nop

    // 0x80800028: jal         0x800D1A04
    // 0x8080002C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D1A04(rdram, ctx);
        goto after_1;
    // 0x8080002C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800030: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800034: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x80800038: bgez        $t6, L_80800070
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080003C: nop
    
            goto L_80800070;
    }
    // 0x8080003C: nop

L_80800040:
    // 0x80800040: jal         0x800D1824
    // 0x80800044: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D1824(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800048: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8080004C: jal         0x800FC63C
    // 0x80800050: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    func_800FC63C(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    after_3:
    // 0x80800054: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080005C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800060: beql        $v0, $at, L_8080009C
    if (ctx->r2 == ctx->r1) {
        // 0x80800064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080009C;
    }
    goto skip_0;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800068: b           L_80800098
    // 0x8080006C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
        goto L_80800098;
    // 0x8080006C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
L_80800070:
    // 0x80800070: beq         $v1, $zero, L_80800080
    if (ctx->r3 == 0) {
        // 0x80800074: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800080;
    }
    // 0x80800074: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800078: jal         0x800D175C
    // 0x8080007C: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    func_800D175C(rdram, ctx);
        goto after_4;
    // 0x8080007C: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    after_4:
L_80800080:
    // 0x80800080: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800084: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800088: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: beql        $v0, $at, L_8080009C
    if (ctx->r2 == ctx->r1) {
        // 0x80800090: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080009C;
    }
    goto skip_1;
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800094: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
L_80800098:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void bsbanbflip_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080036C: jal         0x80800064
    // 0x80800370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    __bsbanbflip_set_substate(rdram, ctx);
        goto after_0;
    // 0x80800370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void _idbounce_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CD0: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088CD0);
    return;
    // 0x80088CD4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808000C0_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000CC: jal         0x80800000
    // 0x808000D0: addiu       $a1, $zero, 0xA1D
    ctx->r5 = ADD32(0, 0XA1D);
    func_80800000_chlavaarchgrill3switches(rdram, ctx);
        goto after_0;
    // 0x808000D0: addiu       $a1, $zero, 0xA1D
    ctx->r5 = ADD32(0, 0XA1D);
    after_0:
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: jal         0x80085810
    // 0x808000DC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808000DC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80802690_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080269C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808026A0: jal         0x80088078
    // 0x808026A4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808026A4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808026A8: beq         $v0, $zero, L_808026DC
    if (ctx->r2 == 0) {
        // 0x808026AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808026DC;
    }
    // 0x808026AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808026B0: jal         0x80100094
    // 0x808026B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808026B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808026B8: lbu         $t6, 0x59($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X59);
    // 0x808026BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808026C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808026C4: beq         $t6, $at, L_808026D4
    if (ctx->r14 == ctx->r1) {
        // 0x808026C8: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808026D4;
    }
    // 0x808026C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808026CC: jal         0x80802730
    // 0x808026D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802730_chboilerboss(rdram, ctx);
        goto after_2;
    // 0x808026D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_808026D4:
    // 0x808026D4: b           L_808026E0
    // 0x808026D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808026E0;
    // 0x808026D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808026DC:
    // 0x808026DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808026E0:
    // 0x808026E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808026E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808026E8: jr          $ra
    // 0x808026EC: nop

    return;
    // 0x808026EC: nop

;}
RECOMP_FUNC void func_80800810_chpotogoldbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800810: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800814: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800818: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080081C: jal         0x800EA090
    // 0x80800820: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800820: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800824: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800828: bne         $v0, $at, L_80800838
    if (ctx->r2 != ctx->r1) {
        // 0x8080082C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800838;
    }
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800830: jal         0x80101FDC
    // 0x80800834: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800834: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
L_80800838:
    // 0x80800838: lui         $at, 0x4354
    ctx->r1 = S32(0X4354 << 16);
    // 0x8080083C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800840: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800844: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800848: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080084C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800850: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800854: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800860: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800864: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800868: jal         0x80086898
    // 0x8080086C: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080086C: nop

    after_2:
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x800868A8
    // 0x80800878: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800878: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: jal         0x800868B8
    // 0x80800884: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _chdoormake_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800884: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: jal         0x800868C0
    // 0x80800890: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800890: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800894: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800898: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808008A4: bne         $t9, $at, L_808008B4
    if (ctx->r25 != ctx->r1) {
        // 0x808008A8: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_808008B4;
    }
    // 0x808008A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808008AC: jal         0x8010108C
    // 0x808008B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x808008B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_808008B4:
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008C0: jr          $ra
    // 0x808008C4: nop

    return;
    // 0x808008C4: nop

;}
RECOMP_FUNC void func_808016D0_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808016D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808016D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808016E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808016E4: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x808016E8: addiu       $a1, $zero, 0x211
    ctx->r5 = ADD32(0, 0X211);
    // 0x808016EC: jal         0x80089C20
    // 0x808016F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808016F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x808016F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808016F8: addiu       $a1, $zero, 0x199
    ctx->r5 = ADD32(0, 0X199);
    // 0x808016FC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80801700: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80801704: jal         0x80089C20
    // 0x80801708: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801708: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080170C: beq         $v0, $zero, L_80801720
    if (ctx->r2 == 0) {
        // 0x80801710: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80801720;
    }
    // 0x80801710: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80801714: bne         $v1, $zero, L_80801720
    if (ctx->r3 != 0) {
        // 0x80801718: nop
    
            goto L_80801720;
    }
    // 0x80801718: nop

    // 0x8080171C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80801720:
    // 0x80801720: beq         $v0, $zero, L_80801768
    if (ctx->r2 == 0) {
        // 0x80801724: addiu       $a1, $zero, 0x19A
        ctx->r5 = ADD32(0, 0X19A);
            goto L_80801768;
    }
    // 0x80801724: addiu       $a1, $zero, 0x19A
    ctx->r5 = ADD32(0, 0X19A);
    // 0x80801728: beq         $v1, $zero, L_80801768
    if (ctx->r3 == 0) {
        // 0x8080172C: lwc1        $f0, 0x20($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80801768;
    }
    // 0x8080172C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801730: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801734: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801738: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080173C: nop

    // 0x80801740: bc1tl       L_80801764
    if (c1cs) {
        // 0x80801744: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80801764;
    }
    goto skip_0;
    // 0x80801744: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_0:
    // 0x80801748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080174C: nop

    // 0x80801750: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80801754: nop

    // 0x80801758: bc1fl       L_8080176C
    if (!c1cs) {
        // 0x8080175C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080176C;
    }
    goto skip_1;
    // 0x8080175C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80801760: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80801764:
    // 0x80801764: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_80801768:
    // 0x80801768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080176C:
    // 0x8080176C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80801770: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80801774: jal         0x80089C20
    // 0x80801778: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80801778: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x8080177C: beq         $v0, $zero, L_80801790
    if (ctx->r2 == 0) {
        // 0x80801780: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80801790;
    }
    // 0x80801780: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80801784: bne         $v1, $zero, L_80801790
    if (ctx->r3 != 0) {
        // 0x80801788: nop
    
            goto L_80801790;
    }
    // 0x80801788: nop

    // 0x8080178C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80801790:
    // 0x80801790: beq         $v0, $zero, L_808017D8
    if (ctx->r2 == 0) {
        // 0x80801794: nop
    
            goto L_808017D8;
    }
    // 0x80801794: nop

    // 0x80801798: beq         $v1, $zero, L_808017D8
    if (ctx->r3 == 0) {
        // 0x8080179C: lwc1        $f0, 0x20($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
            goto L_808017D8;
    }
    // 0x8080179C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808017A0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808017A4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808017A8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808017AC: nop

    // 0x808017B0: bc1tl       L_808017D4
    if (c1cs) {
        // 0x808017B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808017D4;
    }
    goto skip_2;
    // 0x808017B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_2:
    // 0x808017B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808017BC: nop

    // 0x808017C0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x808017C4: nop

    // 0x808017C8: bc1f        L_808017D8
    if (!c1cs) {
        // 0x808017CC: nop
    
            goto L_808017D8;
    }
    // 0x808017CC: nop

    // 0x808017D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808017D4:
    // 0x808017D4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_808017D8:
    // 0x808017D8: beq         $v1, $zero, L_808017F0
    if (ctx->r3 == 0) {
        // 0x808017DC: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_808017F0;
    }
    // 0x808017DC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808017E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x808017E4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808017E8: b           L_808017F8
    // 0x808017EC: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
        goto L_808017F8;
    // 0x808017EC: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
L_808017F0:
    // 0x808017F0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808017F4: sw          $zero, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = 0;
L_808017F8:
    // 0x808017F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808017FC: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801800: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80801804: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80801808: nop

    // 0x8080180C: bc1fl       L_8080181C
    if (!c1cs) {
        // 0x80801810: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080181C;
    }
    goto skip_3;
    // 0x80801810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80801814: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
    // 0x80801818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080181C:
    // 0x8080181C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801820: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801824: jr          $ra
    // 0x80801828: nop

    return;
    // 0x80801828: nop

;}
RECOMP_FUNC void func_800F1B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1B78: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F1B7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F1B80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F1B84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F1B88: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800F1B8C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800F1B90: jal         0x800EFD24
    // 0x800F1B94: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800F1B94: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800F1B98: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800F1B9C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800F1BA0: jal         0x800F1988
    // 0x800F1BA4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F1988(rdram, ctx);
        goto after_1;
    // 0x800F1BA4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x800F1BA8: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F1BAC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800F1BB0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800F1BB4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800F1BB8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800F1BBC: beq         $v0, $zero, L_800F1C84
    if (ctx->r2 == 0) {
        // 0x800F1BC0: swc1        $f2, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
            goto L_800F1C84;
    }
    // 0x800F1BC0: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x800F1BC4: jal         0x800F1DCC
    // 0x800F1BC8: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x800F1BC8: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800F1BCC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800F1BD0: jal         0x800F2100
    // 0x800F1BD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x800F1BD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x800F1BD8: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F1BDC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800F1BE0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800F1BE4: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x800F1BE8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800F1BEC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800F1BF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F1BF4: jal         0x800F10B4
    // 0x800F1BF8: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x800F1BF8: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    after_4:
    // 0x800F1BFC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800F1C00: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F1C04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F1C08: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800F1C0C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F1C10: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800F1C14: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800F1C18: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x800F1C1C: bc1fl       L_800F1C48
    if (!c1cs) {
        // 0x800F1C20: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_800F1C48;
    }
    goto skip_0;
    // 0x800F1C20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x800F1C24: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800F1C28: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F1C2C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x800F1C30: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800F1C34: jal         0x800F10B4
    // 0x800F1C38: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x800F1C38: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800F1C3C: b           L_800F1C5C
    // 0x800F1C40: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_800F1C5C;
    // 0x800F1C40: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800F1C44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800F1C48:
    // 0x800F1C48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800F1C4C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800F1C50: jal         0x800F10B4
    // 0x800F1C54: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x800F1C54: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x800F1C58: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_800F1C5C:
    // 0x800F1C5C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F1C60: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800F1C64: nop

    // 0x800F1C68: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800F1C6C: nop

    // 0x800F1C70: bc1fl       L_800F1C88
    if (!c1cs) {
        // 0x800F1C74: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800F1C88;
    }
    goto skip_1;
    // 0x800F1C74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800F1C78: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F1C7C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800F1C80: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_800F1C84:
    // 0x800F1C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800F1C88:
    // 0x800F1C88: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800F1C8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F1C90: jr          $ra
    // 0x800F1C94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800F1C94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800524_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800528: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080052C: jal         0x8009EF04
    // 0x80800530: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    bastick_distance(rdram, ctx);
        goto after_0;
    // 0x80800530: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800534: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800538: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080053C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800540: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x80800544: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800548: bc1f        L_80800560
    if (!c1cs) {
        // 0x8080054C: nop
    
            goto L_80800560;
    }
    // 0x8080054C: nop

    // 0x80800550: jal         0x80084E50
    // 0x80800554: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _bamovehover_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800554: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80800558: b           L_808005AC
    // 0x8080055C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005AC;
    // 0x8080055C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800560:
    // 0x80800560: jal         0x8009EEB8
    // 0x80800564: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_2;
    // 0x80800564: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80800568: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080056C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800570: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800574: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800578: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080057C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800580: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800584: jal         0x800F10B4
    // 0x80800588: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800588: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8080058C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800590: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800594: jal         0x800EEB9C
    // 0x80800598: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EEB9C(rdram, ctx);
        goto after_4;
    // 0x80800598: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8080059C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808005A0: jal         0x80084E50
    // 0x808005A4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _bamovehover_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808005A4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x808005A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005AC:
    // 0x808005AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

;}
RECOMP_FUNC void func_80095588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009558C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095590: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80095594: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80095598: sb          $a1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r5;
    // 0x8009559C: lw          $t7, 0x7C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X7C);
    // 0x800955A0: lbu         $v0, 0xC($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0XC);
    // 0x800955A4: beq         $v0, $at, L_800955B4
    if (ctx->r2 == ctx->r1) {
        // 0x800955A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800955B4;
    }
    // 0x800955A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800955AC: bnel        $v0, $at, L_800955C0
    if (ctx->r2 != ctx->r1) {
        // 0x800955B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800955C0;
    }
    goto skip_0;
    // 0x800955B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800955B4:
    // 0x800955B4: jal         0x800956B8
    // 0x800955B8: nop

    func_800956B8(rdram, ctx);
        goto after_0;
    // 0x800955B8: nop

    after_0:
    // 0x800955BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800955C0:
    // 0x800955C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800955C4: jr          $ra
    // 0x800955C8: nop

    return;
    // 0x800955C8: nop

;}
RECOMP_FUNC void suegg_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080053C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800540: jal         0x80800558
    // 0x80800544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    suegg_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080054C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800550: jr          $ra
    // 0x80800554: nop

    return;
    // 0x80800554: nop

;}
RECOMP_FUNC void func_80098408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009840C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80098410: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80098414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80098418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009841C: jal         0x80098480
    // 0x80098420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80098480(rdram, ctx);
        goto after_0;
    // 0x80098420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80098424: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80098428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009842C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80098430: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80098434: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80098438: jal         0x80098494
    // 0x8009843C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80098494(rdram, ctx);
        goto after_1;
    // 0x8009843C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80098440: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80098444: addiu       $a1, $a1, 0x7E9C
    ctx->r5 = ADD32(ctx->r5, 0X7E9C);
    // 0x80098448: jal         0x800984F0
    // 0x8009844C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800984F0(rdram, ctx);
        goto after_2;
    // 0x8009844C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80098450: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80098454: addiu       $a1, $a1, 0x7E90
    ctx->r5 = ADD32(ctx->r5, 0X7E90);
    // 0x80098458: jal         0x800984CC
    // 0x8009845C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800984CC(rdram, ctx);
        goto after_3;
    // 0x8009845C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80098460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098464: jal         0x80098520
    // 0x80098468: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80098520(rdram, ctx);
        goto after_4;
    // 0x80098468: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x8009846C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80098470: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80098474: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80098478: jr          $ra
    // 0x8009847C: nop

    return;
    // 0x8009847C: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7C0: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7C0);
    return;
    // 0x8008A7C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_bapreload(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80800004: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800008: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: beq         $at, $zero, L_80800070
    if (ctx->r1 == 0) {
        // 0x80800014: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800070;
    }
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800018: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080001C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(572, 0X250) << 16);
    // 0x80800020: addu        $at, $at, $t6
    gpr jr_addend_80800028 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800024: lw          $t6, 0x250($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(572, 0X250));
    // 0x80800028: jr          $t6
    // 0x8080002C: nop

    switch (jr_addend_80800028 >> 2) {
        case 0: goto L_80800054; break;
        case 1: goto L_80800070; break;
        case 2: goto L_80800070; break;
        case 3: goto L_80800070; break;
        case 4: goto L_80800070; break;
        case 5: goto L_80800030; break;
        case 6: goto L_80800070; break;
        case 7: goto L_80800070; break;
        case 8: goto L_80800070; break;
        case 9: goto L_80800070; break;
        case 10: goto L_80800048; break;
        case 11: goto L_8080003C; break;
        case 12: goto L_80800070; break;
        case 13: goto L_80800070; break;
        case 14: goto L_80800070; break;
        case 15: goto L_80800070; break;
        case 16: goto L_80800060; break;
        default: switch_error(__func__, 0x80800028, 0x80800250);
    }
    // 0x8080002C: nop

L_80800030:
    // 0x80800030: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(572, 0X310) << 16);
    // 0x80800034: b           L_80800080
    // 0x80800038: addiu       $v1, $v1, 0x310
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X310));
        goto L_80800080;
    // 0x80800038: addiu       $v1, $v1, 0x310
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X310));
L_8080003C:
    // 0x8080003C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(572, 0X320) << 16);
    // 0x80800040: b           L_80800080
    // 0x80800044: addiu       $v1, $v1, 0x320
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X320));
        goto L_80800080;
    // 0x80800044: addiu       $v1, $v1, 0x320
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X320));
L_80800048:
    // 0x80800048: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(572, 0X300) << 16);
    // 0x8080004C: b           L_80800080
    // 0x80800050: addiu       $v1, $v1, 0x300
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X300));
        goto L_80800080;
    // 0x80800050: addiu       $v1, $v1, 0x300
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X300));
L_80800054:
    // 0x80800054: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(572, 0X2F0) << 16);
    // 0x80800058: b           L_80800080
    // 0x8080005C: addiu       $v1, $v1, 0x2F0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X2F0));
        goto L_80800080;
    // 0x8080005C: addiu       $v1, $v1, 0x2F0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(572, 0X2F0));
L_80800060:
    // 0x80800060: addiu       $t7, $zero, 0x60E
    ctx->r15 = ADD32(0, 0X60E);
    // 0x80800064: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80800068: b           L_808000EC
    // 0x8080006C: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
        goto L_808000EC;
    // 0x8080006C: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_80800070:
    // 0x80800070: addiu       $t8, $zero, 0x607
    ctx->r24 = ADD32(0, 0X607);
    // 0x80800074: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x80800078: b           L_808000EC
    // 0x8080007C: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
        goto L_808000EC;
    // 0x8080007C: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_80800080:
    // 0x80800080: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80800084: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80800088: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080008C: jal         0x800EA068
    // 0x80800090: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x80800090: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800094: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080009C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808000A0: beq         $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000A4: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_808000D0;
    }
    // 0x808000A4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808000A8: lw          $a0, 0x184($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X184);
    // 0x808000AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808000B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000B4: jal         0x800A940C
    // 0x808000B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800A940C(rdram, ctx);
        goto after_1;
    // 0x808000B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x808000BC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808000C4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808000C8: b           L_808000D4
    // 0x808000CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_808000D4;
    // 0x808000CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808000D0:
    // 0x808000D0: lw          $a0, 0x184($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X184);
L_808000D4:
    // 0x808000D4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x808000D8: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x808000DC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x808000E0: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x808000E4: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x808000E8: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
L_808000EC:
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void func_800FEF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEF94: beq         $a2, $zero, L_800FEFCC
    if (ctx->r6 == 0) {
        // 0x800FEF98: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800FEFCC;
    }
    // 0x800FEF98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800FEF9C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800FEFA0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800FEFA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FEFA8: addiu       $t7, $t7, 0x3E84
    ctx->r15 = ADD32(ctx->r15, 0X3E84);
    // 0x800FEFAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FEFB0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800FEFB4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800FEFB8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800FEFBC: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800FEFC0: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x800FEFC4: jr          $ra
    // 0x800FEFC8: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    return;
    // 0x800FEFC8: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
L_800FEFCC:
    // 0x800FEFCC: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800FEFD0: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x800FEFD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800FEFD8: addiu       $t2, $t2, 0x3E84
    ctx->r10 = ADD32(ctx->r10, 0X3E84);
    // 0x800FEFDC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800FEFE0: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800FEFE4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800FEFE8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800FEFEC: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800FEFF0: lh          $t4, 0x8($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X8);
    // 0x800FEFF4: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x800FEFF8: jr          $ra
    // 0x800FEFFC: nop

    return;
    // 0x800FEFFC: nop

;}
RECOMP_FUNC void func_80801EB4_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801EB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801EBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801EC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801EC4: jal         0x80100094
    // 0x80801EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801ECC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801ED4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80801ED8: jal         0x80105494
    // 0x80801EDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80105494(rdram, ctx);
        goto after_1;
    // 0x80801EDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801EE0: beq         $v0, $zero, L_80801F28
    if (ctx->r2 == 0) {
        // 0x80801EE4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80801F28;
    }
    // 0x80801EE4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801EE8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801EEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EF4: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    // 0x80801EF8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80801EFC: jal         0x80105A9C
    // 0x80801F00: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x80801F00: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    after_2:
    // 0x80801F04: jal         0x80801DD0
    // 0x80801F08: nop

    func_80801DD0_chaliendad(rdram, ctx);
        goto after_3;
    // 0x80801F08: nop

    after_3:
    // 0x80801F0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801F10: bnel        $v0, $at, L_80801F88
    if (ctx->r2 != ctx->r1) {
        // 0x80801F14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801F88;
    }
    goto skip_0;
    // 0x80801F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801F18: jal         0x800FFAB0
    // 0x80801F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80801F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801F20: b           L_80801F88
    // 0x80801F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F88;
    // 0x80801F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F28:
    // 0x80801F28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801F2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801F30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801F34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801F38: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801F3C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80801F40: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80801F44: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80801F48: jal         0x800EE7F8
    // 0x80801F4C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801F4C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x80801F50: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801F54: jal         0x800EE7F8
    // 0x80801F58: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80801F58: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_6:
    // 0x80801F5C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80801F60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F68: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801F6C: jal         0x80101FDC
    // 0x80801F70: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80801F70: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    after_7:
    // 0x80801F74: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801F78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801F7C: nop

    // 0x80801F80: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80801F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F88:
    // 0x80801F88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801F8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801F90: jr          $ra
    // 0x80801F94: nop

    return;
    // 0x80801F94: nop

;}
RECOMP_FUNC void sccustom_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080057C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800584: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800588: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080058C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800590: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800594: jal         0x808004C8
    // 0x80800598: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_808004C8_sccustom(rdram, ctx);
        goto after_0;
    // 0x80800598: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8080059C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808005A4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808005A8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808005AC: jal         0x80800000
    // 0x808005B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80800000_sccustom(rdram, ctx);
        goto after_1;
    // 0x808005B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x808005B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005BC: jr          $ra
    // 0x808005C0: nop

    return;
    // 0x808005C0: nop

;}
RECOMP_FUNC void func_80800DB4_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800DB4_chstoneballcontrol");
    // 0x80800DB4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800DB8: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800DBC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800DC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800DC4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800DC8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800DCC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800DD0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800DD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800DD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800DDC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800DE0: jal         0x80100094
    // 0x80800DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DE8: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x80800DEC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800DF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800DF4: blez        $t6, L_80800E94
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800DF8: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800E94;
    }
    // 0x80800DF8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800DFC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800E00: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x80800E04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800E08:
    // 0x80800E08: jal         0x80089AC8
    // 0x80800E0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800E0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800E10: beq         $v0, $zero, L_80800E4C
    if (ctx->r2 == 0) {
        // 0x80800E14: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800E4C;
    }
    // 0x80800E14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E1C: jal         0x800F5A00
    // 0x80800E20: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800E20: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80800E24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800E28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800E2C: jal         0x800F0064
    // 0x80800E30: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F0064(rdram, ctx);
        goto after_3;
    // 0x80800E30: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x80800E34: beq         $v0, $zero, L_80800E80
    if (ctx->r2 == 0) {
        // 0x80800E38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E80;
    }
    // 0x80800E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E3C: jal         0x800F7B9C
    // 0x80800E40: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    func_800F7B9C(rdram, ctx);
        goto after_4;
    // 0x80800E40: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_4:
    // 0x80800E44: b           L_80800E84
    // 0x80800E48: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
        goto L_80800E84;
    // 0x80800E48: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
L_80800E4C:
    // 0x80800E4C: jal         0x80089AD8
    // 0x80800E50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800E50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800E54: jal         0x80106790
    // 0x80800E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80800E58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800E5C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800E60: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800E64: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800E68: jal         0x800F0064
    // 0x80800E6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F0064(rdram, ctx);
        goto after_7;
    // 0x80800E6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_7:
    // 0x80800E70: beql        $v0, $zero, L_80800E84
    if (ctx->r2 == 0) {
        // 0x80800E74: lbu         $t7, 0x3A($s5)
        ctx->r15 = MEM_BU(ctx->r21, 0X3A);
            goto L_80800E84;
    }
    goto skip_0;
    // 0x80800E74: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
    skip_0:
    // 0x80800E78: jal         0x80800D20
    // 0x80800E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800D20_chstoneballcontrol(rdram, ctx);
        goto after_8;
    // 0x80800E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_80800E80:
    // 0x80800E80: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
L_80800E84:
    // 0x80800E84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800E88: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800E8C: bnel        $at, $zero, L_80800E08
    if (ctx->r1 != 0) {
        // 0x80800E90: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800E08;
    }
    goto skip_1;
    // 0x80800E90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
L_80800E94:
    // 0x80800E94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800E98: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800E9C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EA0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800EA4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800EA8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800EAC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EB0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800EB4: jr          $ra
    // 0x80800EB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800EB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8010FAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FAEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FAF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FAF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010FAF8: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x8010FAFC: beql        $t6, $zero, L_8010FB28
    if (ctx->r14 == 0) {
        // 0x8010FB00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010FB28;
    }
    goto skip_0;
    // 0x8010FB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010FB04: lw          $a0, 0x1C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1C);
    // 0x8010FB08: jal         0x800A9420
    // 0x8010FB0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A9420(rdram, ctx);
        goto after_0;
    // 0x8010FB0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010FB10: beq         $v0, $zero, L_8010FB24
    if (ctx->r2 == 0) {
        // 0x8010FB14: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8010FB24;
    }
    // 0x8010FB14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8010FB18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010FB1C: jal         0x80114FA4
    // 0x8010FB20: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    func_80114FA4(rdram, ctx);
        goto after_1;
    // 0x8010FB20: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    after_1:
L_8010FB24:
    // 0x8010FB24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010FB28:
    // 0x8010FB28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FB2C: jr          $ra
    // 0x8010FB30: nop

    return;
    // 0x8010FB30: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808014F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808014F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808014FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801500: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80801504: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801508: beq         $a1, $zero, L_80801520
    if (ctx->r5 == 0) {
        // 0x8080150C: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80801520;
    }
    // 0x8080150C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801510: lbu         $t6, 0x1D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1D);
    // 0x80801514: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x80801518: b           L_8080152C
    // 0x8080151C: sb          $t7, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r15;
        goto L_8080152C;
    // 0x8080151C: sb          $t7, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r15;
L_80801520:
    // 0x80801520: lbu         $t9, 0x1D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1D);
    // 0x80801524: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80801528: sb          $t0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r8;
L_8080152C:
    // 0x8080152C: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80801530: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801534: blez        $t1, L_8080158C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80801538: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080158C;
    }
    // 0x80801538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080153C:
    // 0x8080153C: jal         0x80800000
    // 0x80801540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80801540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80801544: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80801548: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x8080154C: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x80801550: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801554: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80801558: beq         $t4, $zero, L_80801578
    if (ctx->r12 == 0) {
        // 0x8080155C: addu        $t6, $s0, $t5
        ctx->r14 = ADD32(ctx->r16, ctx->r13);
            goto L_80801578;
    }
    // 0x8080155C: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80801560: beq         $s2, $zero, L_80801570
    if (ctx->r18 == 0) {
        // 0x80801564: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80801570;
    }
    // 0x80801564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801568: b           L_80801570
    // 0x8080156C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80801570;
    // 0x8080156C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80801570:
    // 0x80801570: jal         0x80087C40
    // 0x80801574: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    _gczoombox_entrypoint_44(rdram, ctx);
        goto after_1;
    // 0x80801574: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    after_1:
L_80801578:
    // 0x80801578: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x8080157C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801580: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80801584: bnel        $at, $zero, L_8080153C
    if (ctx->r1 != 0) {
        // 0x80801588: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080153C;
    }
    goto skip_0;
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_8080158C:
    // 0x8080158C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801590: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801594: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801598: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080159C: jr          $ra
    // 0x808015A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808015A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_801123D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801123D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801123D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801123DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801123E0: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x801123E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801123E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801123EC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801123F0: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x801123F4: beq         $at, $zero, L_8011246C
    if (ctx->r1 == 0) {
        // 0x801123F8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8011246C;
    }
    // 0x801123F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801123FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80112400: addu        $at, $at, $t8
    gpr jr_addend_80112408 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80112404: lw          $t8, 0x6560($at)
    ctx->r24 = ADD32(ctx->r1, 0X6560);
    // 0x80112408: jr          $t8
    // 0x8011240C: nop

    switch (jr_addend_80112408 >> 2) {
        case 0: goto L_80112410; break;
        case 1: goto L_8011244C; break;
        case 2: goto L_80112438; break;
        case 3: goto L_80112424; break;
        case 4: goto L_80112410; break;
        case 5: goto L_80112460; break;
        default: switch_error(__func__, 0x80112408, 0x80126560);
    }
    // 0x8011240C: nop

L_80112410:
    // 0x80112410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112414: jal         0x801121B8
    // 0x80112418: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_801121B8(rdram, ctx);
        goto after_0;
    // 0x80112418: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8011241C: b           L_8011246C
    // 0x80112420: nop

        goto L_8011246C;
    // 0x80112420: nop

L_80112424:
    // 0x80112424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112428: jal         0x801121D8
    // 0x8011242C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_801121D8(rdram, ctx);
        goto after_1;
    // 0x8011242C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80112430: b           L_8011246C
    // 0x80112434: nop

        goto L_8011246C;
    // 0x80112434: nop

L_80112438:
    // 0x80112438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011243C: jal         0x80112250
    // 0x80112440: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80112250(rdram, ctx);
        goto after_2;
    // 0x80112440: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80112444: b           L_8011246C
    // 0x80112448: nop

        goto L_8011246C;
    // 0x80112448: nop

L_8011244C:
    // 0x8011244C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112450: jal         0x80112204
    // 0x80112454: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80112204(rdram, ctx);
        goto after_3;
    // 0x80112454: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80112458: b           L_8011246C
    // 0x8011245C: nop

        goto L_8011246C;
    // 0x8011245C: nop

L_80112460:
    // 0x80112460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112464: jal         0x80112354
    // 0x80112468: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80112354(rdram, ctx);
        goto after_4;
    // 0x80112468: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
L_8011246C:
    // 0x8011246C: jal         0x80110898
    // 0x80112470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110898(rdram, ctx);
        goto after_5;
    // 0x80112470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80112474: jal         0x8010FFD0
    // 0x80112478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FFD0(rdram, ctx);
        goto after_6;
    // 0x80112478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8011247C: beql        $v0, $zero, L_801124A0
    if (ctx->r2 == 0) {
        // 0x80112480: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_801124A0;
    }
    goto skip_0;
    // 0x80112480: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x80112484: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80112488: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8011248C: jal         0x800EE7F8
    // 0x80112490: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80112490: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x80112494: b           L_801124C0
    // 0x80112498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801124C0;
    // 0x80112498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8011249C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_801124A0:
    // 0x801124A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801124A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801124A8: addiu       $t9, $v0, 0x14
    ctx->r25 = ADD32(ctx->r2, 0X14);
    // 0x801124AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801124B0: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x801124B4: jal         0x80111F70
    // 0x801124B8: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    func_80111F70(rdram, ctx);
        goto after_8;
    // 0x801124B8: addiu       $a3, $v0, 0x10
    ctx->r7 = ADD32(ctx->r2, 0X10);
    after_8:
    // 0x801124BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801124C0:
    // 0x801124C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801124C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801124C8: jr          $ra
    // 0x801124CC: nop

    return;
    // 0x801124CC: nop

;}
RECOMP_FUNC void func_800D1C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1C80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D1C84: jal         0x800D1490
    // 0x800D1C88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D1490(rdram, ctx);
        goto after_0;
    // 0x800D1C88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D1C8C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1C90: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800D1C94: srl         $t2, $v0, 1
    ctx->r10 = S32(U32(ctx->r2) >> 1);
    // 0x800D1C98: slti        $at, $t2, 0x16
    ctx->r1 = SIGNED(ctx->r10) < 0X16 ? 1 : 0;
    // 0x800D1C9C: bne         $at, $zero, L_800D1CA8
    if (ctx->r1 != 0) {
        // 0x800D1CA0: nop
    
            goto L_800D1CA8;
    }
    // 0x800D1CA0: nop

    // 0x800D1CA4: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
L_800D1CA8:
    // 0x800D1CA8: blez        $t2, L_800D1DEC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800D1CAC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800D1DEC;
    }
    // 0x800D1CAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D1CB0: andi        $v1, $t2, 0x3
    ctx->r3 = ctx->r10 & 0X3;
    // 0x800D1CB4: beq         $v1, $zero, L_800D1D20
    if (ctx->r3 == 0) {
        // 0x800D1CB8: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800D1D20;
    }
    // 0x800D1CB8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800D1CBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D1CC0: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
    // 0x800D1CC4: sll         $a1, $zero, 1
    ctx->r5 = S32(0 << 1);
    // 0x800D1CC8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800D1CCC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D1CD0: addiu       $a3, $a3, -0x4DB0
    ctx->r7 = ADD32(ctx->r7, -0X4DB0);
    // 0x800D1CD4: addiu       $t0, $t0, 0x1A04
    ctx->r8 = ADD32(ctx->r8, 0X1A04);
    // 0x800D1CD8: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x800D1CDC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_800D1CE0:
    // 0x800D1CE0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800D1CE4: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800D1CE8: addu        $t5, $t0, $a2
    ctx->r13 = ADD32(ctx->r8, ctx->r6);
    // 0x800D1CEC: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x800D1CF0: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800D1CF4: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x800D1CF8: or          $v1, $t8, $t4
    ctx->r3 = ctx->r24 | ctx->r12;
    // 0x800D1CFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D1D00: addu        $t8, $t9, $a1
    ctx->r24 = ADD32(ctx->r25, ctx->r5);
    // 0x800D1D04: xor         $t7, $t6, $v1
    ctx->r15 = ctx->r14 ^ ctx->r3;
    // 0x800D1D08: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800D1D0C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800D1D10: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800D1D14: bne         $t1, $a0, L_800D1CE0
    if (ctx->r9 != ctx->r4) {
        // 0x800D1D18: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_800D1CE0;
    }
    // 0x800D1D18: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800D1D1C: beq         $a0, $t2, L_800D1DEC
    if (ctx->r4 == ctx->r10) {
        // 0x800D1D20: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800D1DEC;
    }
L_800D1D20:
    // 0x800D1D20: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D1D24: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x800D1D28: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D1D2C: sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4 << 1);
    // 0x800D1D30: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800D1D34: addiu       $t0, $t0, 0x1A04
    ctx->r8 = ADD32(ctx->r8, 0X1A04);
    // 0x800D1D38: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x800D1D3C: addiu       $a3, $a3, -0x4DB0
    ctx->r7 = ADD32(ctx->r7, -0X4DB0);
    // 0x800D1D40: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800D1D44: sll         $t1, $t2, 3
    ctx->r9 = S32(ctx->r10 << 3);
L_800D1D48:
    // 0x800D1D48: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D1D4C: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x800D1D50: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // 0x800D1D54: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800D1D58: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800D1D5C: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x800D1D60: or          $v1, $t5, $t9
    ctx->r3 = ctx->r13 | ctx->r25;
    // 0x800D1D64: xor         $t8, $t7, $v1
    ctx->r24 = ctx->r15 ^ ctx->r3;
    // 0x800D1D68: addu        $t6, $t4, $a1
    ctx->r14 = ADD32(ctx->r12, ctx->r5);
    // 0x800D1D6C: sh          $t8, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r24;
    // 0x800D1D70: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x800D1D74: lbu         $t5, 0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3);
    // 0x800D1D78: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800D1D7C: lh          $t4, 0x8($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X8);
    // 0x800D1D80: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800D1D84: or          $v1, $t5, $t7
    ctx->r3 = ctx->r13 | ctx->r15;
    // 0x800D1D88: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x800D1D8C: xor         $t8, $t4, $v1
    ctx->r24 = ctx->r12 ^ ctx->r3;
    // 0x800D1D90: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x800D1D94: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800D1D98: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x800D1D9C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800D1DA0: lh          $t6, 0x10($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X10);
    // 0x800D1DA4: sll         $t4, $t7, 8
    ctx->r12 = S32(ctx->r15 << 8);
    // 0x800D1DA8: or          $v1, $t5, $t4
    ctx->r3 = ctx->r13 | ctx->r12;
    // 0x800D1DAC: addu        $t7, $t9, $a1
    ctx->r15 = ADD32(ctx->r25, ctx->r5);
    // 0x800D1DB0: xor         $t8, $t6, $v1
    ctx->r24 = ctx->r14 ^ ctx->r3;
    // 0x800D1DB4: sh          $t8, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r24;
    // 0x800D1DB8: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x800D1DBC: lbu         $t5, 0x7($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X7);
    // 0x800D1DC0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800D1DC4: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    // 0x800D1DC8: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800D1DCC: or          $v1, $t5, $t6
    ctx->r3 = ctx->r13 | ctx->r14;
    // 0x800D1DD0: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x800D1DD4: addu        $t4, $t7, $a1
    ctx->r12 = ADD32(ctx->r15, ctx->r5);
    // 0x800D1DD8: xor         $t8, $t9, $v1
    ctx->r24 = ctx->r25 ^ ctx->r3;
    // 0x800D1DDC: sh          $t8, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r24;
    // 0x800D1DE0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800D1DE4: bne         $a2, $t1, L_800D1D48
    if (ctx->r6 != ctx->r9) {
        // 0x800D1DE8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800D1D48;
    }
    // 0x800D1DE8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800D1DEC:
    // 0x800D1DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1DF4: jr          $ra
    // 0x800D1DF8: nop

    return;
    // 0x800D1DF8: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C58: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C58);
    return;
    // 0x80083C5C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_80800C48_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C50: jal         0x8010C964
    // 0x80800C54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010C964(rdram, ctx);
        goto after_0;
    // 0x80800C54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C58: jal         0x80801080
    // 0x80800C5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801080_chterryegg(rdram, ctx);
        goto after_1;
    // 0x80800C5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C68: jr          $ra
    // 0x80800C6C: nop

    return;
    // 0x80800C6C: nop

;}
RECOMP_FUNC void func_80803158_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080315C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803160: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803164: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80803168: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080316C: addiu       $t7, $zero, 0xAB
    ctx->r15 = ADD32(0, 0XAB);
    // 0x80803170: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803174: jal         0x8008A208
    // 0x80803178: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80803178: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x8080317C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803184: jr          $ra
    // 0x80803188: nop

    return;
    // 0x80803188: nop

;}
RECOMP_FUNC void chlagoonentrygate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1968, 0X150) << 16);
    // 0x80800140: jr          $ra
    // 0x80800144: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1968, 0X150));
    return;
    // 0x80800144: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1968, 0X150));
    // 0x80800148: nop

    // 0x8080014C: nop

;}
RECOMP_FUNC void _chdinofamilymother_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087728: syscall     613
    recomp_syscall_handler(rdram, ctx, 0x80087728);
    return;
    // 0x8008772C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800CD1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD1E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CD1EC: jal         0x800CD08C
    // 0x800CD1F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CD08C(rdram, ctx);
        goto after_0;
    // 0x800CD1F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CD1F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD1F8: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CD1FC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800CD200: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800CD204: nop

    // 0x800CD208: bc1fl       L_800CD218
    if (!c1cs) {
        // 0x800CD20C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CD218;
    }
    goto skip_0;
    // 0x800CD20C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CD210: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800CD214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CD218:
    // 0x800CD218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD21C: jr          $ra
    // 0x800CD220: nop

    return;
    // 0x800CD220: nop

    // 0x800CD224: nop

    // 0x800CD228: nop

    // 0x800CD22C: nop

;}
